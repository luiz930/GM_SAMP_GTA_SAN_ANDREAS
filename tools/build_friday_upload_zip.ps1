param(
    [string]$OutputDir = "",
    [switch]$IncludeRules,
    [switch]$IncludeAccountMetadata,
    [switch]$SkipGate
)

$ErrorActionPreference = "Stop"

$RootDir = Resolve-Path (Join-Path $PSScriptRoot "..")
if (-not $OutputDir) {
    $OutputDir = Join-Path $RootDir "deploy"
}
$script:ReleaseAmx = ""

function Get-DefineValue {
    param(
        [string]$Path,
        [string]$Name
    )

    if (-not (Test-Path -LiteralPath $Path)) {
        return ""
    }

    $pattern = "^\s*#define\s+$([regex]::Escape($Name))\s+`"([^`"]+)`""
    foreach ($line in Get-Content -LiteralPath $Path) {
        if ($line -match $pattern) {
            return $Matches[1]
        }
    }
    return ""
}

function Test-ExcludedPath {
    param([string]$RelativePath)

    $normalized = ($RelativePath -replace "\\", "/").TrimStart("/")

    if ($normalized -match "(?i)^gamemodes/.*\.(amx|pwn)$") {
        if ($script:ReleaseAmx -and $normalized -ieq ("gamemodes/{0}" -f $script:ReleaseAmx)) {
            return $false
        }
        return $true
    }

    if ($normalized -match "(?i)(^|/)(REGRAS[^/]*|rules[^/]*)$" -and -not $IncludeRules) {
        return $true
    }

    if ($normalized -match "(?i)^scriptfiles/contas(/|$)") {
        return $true
    }

    if (-not $IncludeAccountMetadata) {
        if ($normalized -match "(?i)^scriptfiles/(account_index|account_aliases)\.txt$") {
            return $true
        }
    }

    return $false
}

function Copy-ServerFile {
    param(
        [string]$SourcePath,
        [string]$StageDir
    )

    $relative = $SourcePath.Substring($RootDir.Path.Length).TrimStart("\")
    if (Test-ExcludedPath -RelativePath $relative) {
        return
    }

    $destination = Join-Path $StageDir $relative
    $destinationDir = Split-Path -Parent $destination
    if (-not (Test-Path -LiteralPath $destinationDir)) {
        New-Item -ItemType Directory -Force -Path $destinationDir | Out-Null
    }
    Copy-Item -LiteralPath $SourcePath -Destination $destination -Force
}

function Assert-ZipEntry {
    param(
        [string[]]$Entries,
        [string]$Expected
    )

    if ($Entries -notcontains $Expected) {
        throw "Pacote incompleto: faltou $Expected."
    }
}

if (-not $SkipGate) {
    Write-Host "[GATE] pre_deploy_gate antes do ZIP de sexta..."
    & powershell -NoProfile -ExecutionPolicy Bypass -File (Join-Path $RootDir "tools\pre_deploy_gate.ps1")
    if ($LASTEXITCODE -ne 0) {
        throw "ZIP de sexta bloqueado: pre_deploy_gate.ps1 retornou codigo $LASTEXITCODE."
    }
    Write-Host "[GATE] pre_deploy_gate: OK"
}

New-Item -ItemType Directory -Force -Path $OutputDir | Out-Null

$releaseAmx = Get-DefineValue -Path (Join-Path $RootDir "include\core\utils.inc") -Name "GM_RELEASE_AMX"
if (-not $releaseAmx) {
    $releaseAmx = "nova_gm_1003.amx"
}
$script:ReleaseAmx = $releaseAmx

$stamp = Get-Date -Format "yyyy-MM-dd_HH-mm-ss"
$releaseName = [System.IO.Path]::GetFileNameWithoutExtension($releaseAmx)
$stageDir = Join-Path $OutputDir ("sexta_upload_sem_contas_{0}_{1}" -f $releaseName, $stamp)
$zipPath = "$stageDir.zip"

if (Test-Path -LiteralPath $stageDir) {
    Remove-Item -LiteralPath $stageDir -Recurse -Force
}
if (Test-Path -LiteralPath $zipPath) {
    Remove-Item -LiteralPath $zipPath -Force
}
New-Item -ItemType Directory -Force -Path $stageDir | Out-Null

$serverDirs = @(
    "filterscripts",
    "gamemodes",
    "npcmodes",
    "scriptfiles"
)

foreach ($dir in $serverDirs) {
    $sourceDir = Join-Path $RootDir $dir
    if (-not (Test-Path -LiteralPath $sourceDir)) {
        continue
    }

    Get-ChildItem -LiteralPath $sourceDir -Recurse -File | ForEach-Object {
        Copy-ServerFile -SourcePath $_.FullName -StageDir $stageDir
    }
}

$rootFiles = @(
    "announce.exe",
    "CHANGELOG.txt",
    "OPERACAO_ONLINE.md",
    "samp-license.txt",
    "samp-npc.exe",
    "samp-server.exe",
    "server-readme.txt",
    "server.cfg"
)

foreach ($file in $rootFiles) {
    $sourceFile = Join-Path $RootDir $file
    if (Test-Path -LiteralPath $sourceFile) {
        Copy-ServerFile -SourcePath $sourceFile -StageDir $stageDir
    }
}

$stageServerCfg = Join-Path $stageDir "server.cfg"
if (Test-Path -LiteralPath $stageServerCfg) {
    (Get-Content -LiteralPath $stageServerCfg) -replace "^\s*gamemode0\s+.*$", ("gamemode0 $releaseName 1") |
        Set-Content -LiteralPath $stageServerCfg -Encoding ASCII
}

Compress-Archive -Path (Join-Path $stageDir "*") -DestinationPath $zipPath -CompressionLevel Optimal -Force

Add-Type -AssemblyName System.IO.Compression.FileSystem
$archive = [System.IO.Compression.ZipFile]::OpenRead($zipPath)
try {
    $entries = $archive.Entries | ForEach-Object { $_.FullName -replace "\\", "/" }

    Assert-ZipEntry -Entries $entries -Expected "server.cfg"
    Assert-ZipEntry -Entries $entries -Expected ("gamemodes/{0}" -f $releaseAmx)
    Assert-ZipEntry -Entries $entries -Expected "scriptfiles/server_info.txt"
    Assert-ZipEntry -Entries $entries -Expected "scriptfiles/bot_messages.txt"
    Assert-ZipEntry -Entries $entries -Expected "scriptfiles/tolls.txt"
    Assert-ZipEntry -Entries $entries -Expected "scriptfiles/properties/houses.txt"

    $blocked = $entries | Where-Object {
        $_ -match "(?i)^scriptfiles/contas(/|$)" -or
        (-not $IncludeAccountMetadata -and $_ -match "(?i)^scriptfiles/(account_index|account_aliases)\.txt$") -or
        (-not $IncludeRules -and $_ -match "(?i)(^|/)(REGRAS[^/]*|rules[^/]*)$") -or
        ($_ -match "(?i)^gamemodes/.*\.(amx|pwn)$" -and $_ -ine ("gamemodes/{0}" -f $releaseAmx))
    }
    if ($blocked) {
        throw "Pacote contem arquivo bloqueado: $($blocked -join ', ')"
    }

    $serverCfgEntry = $archive.GetEntry("server.cfg")
    if (-not $serverCfgEntry) {
        throw "Pacote incompleto: faltou server.cfg."
    }
    $reader = New-Object System.IO.StreamReader($serverCfgEntry.Open())
    try {
        $serverCfgText = $reader.ReadToEnd()
    }
    finally {
        $reader.Close()
    }
    if ($serverCfgText -notmatch "(?im)^gamemode0\s+$([regex]::Escape($releaseName))\s+1\s*$") {
        throw "server.cfg do ZIP de sexta nao aponta para gamemode0 $releaseName 1."
    }
}
finally {
    $archive.Dispose()
}

$fileCount = (Get-ChildItem -LiteralPath $stageDir -Recurse -File).Count
$hash = Get-FileHash -LiteralPath $zipPath -Algorithm SHA256

Write-Host "Pacote de sexta OK"
Write-Host ("ZIP: {0}" -f $zipPath)
Write-Host ("Arquivos: {0}" -f $fileCount)
Write-Host ("SHA256: {0}" -f $hash.Hash)
Write-Host "Excluidos: scriptfiles/contas, account_index.txt/account_aliases.txt e regras."
