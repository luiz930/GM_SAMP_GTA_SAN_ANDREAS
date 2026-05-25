param(
    [string]$RootDir = "",
    [switch]$StrictOperationalWarnings
)

$ErrorActionPreference = "Stop"

if ([string]::IsNullOrWhiteSpace($RootDir)) {
    $RootDir = Resolve-Path (Join-Path $PSScriptRoot "..")
}
else {
    $RootDir = Resolve-Path $RootDir
}

$errors = New-Object System.Collections.Generic.List[string]
$warnings = New-Object System.Collections.Generic.List[string]

function Add-Error {
    param([string]$Message)
    $errors.Add($Message) | Out-Null
}

function Add-Warning {
    param([string]$Message)
    $warnings.Add($Message) | Out-Null
}

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

function Read-KeyValueFile {
    param([string]$Path)

    $data = [ordered]@{}
    if (-not (Test-Path -LiteralPath $Path)) {
        Add-Error "Arquivo chave=valor ausente: $Path"
        return $data
    }

    $lineNo = 0
    foreach ($line in Get-Content -LiteralPath $Path) {
        $lineNo++
        $trim = $line.Trim()
        if ([string]::IsNullOrWhiteSpace($trim) -or $trim.StartsWith("#")) {
            continue
        }
        $eq = $trim.IndexOf("=")
        if ($eq -le 0) {
            Add-Error "$Path linha ${lineNo}: esperado chave=valor."
            continue
        }
        $key = $trim.Substring(0, $eq).Trim()
        $value = $trim.Substring($eq + 1).Trim()
        if ($data.Contains($key)) {
            Add-Error "$Path linha ${lineNo}: chave duplicada '$key'."
        }
        $data[$key] = $value
    }
    return $data
}

function Test-ConflictMarkers {
    $paths = @()
    $paths += Get-ChildItem -LiteralPath (Join-Path $RootDir "gamemodes") -Filter "nova_gm.pwn" -File
    $paths += Get-ChildItem -LiteralPath (Join-Path $RootDir "include") -Recurse -Include *.inc -File
    $paths += Get-ChildItem -LiteralPath (Join-Path $RootDir "npcmodes") -Filter "ls_*.pwn" -File
    $paths += Get-ChildItem -LiteralPath (Join-Path $RootDir "tools") -Filter "*.ps1" -File
    $paths += Get-ChildItem -LiteralPath (Join-Path $RootDir "scriptfiles") -Recurse -Include *.txt,*.ini -File
    foreach ($name in @("server.cfg", "CHANGELOG.txt", "OPERACAO_ONLINE.md", "REGRAS_PAWNO.md", "CHECKLIST_DEPLOY_19H.md")) {
        $path = Join-Path $RootDir $name
        if (Test-Path -LiteralPath $path) {
            $paths += Get-Item -LiteralPath $path
        }
    }

    foreach ($file in $paths) {
        $lineNo = 0
        foreach ($line in Get-Content -LiteralPath $file.FullName) {
            $lineNo++
            if ($line -match "^(<<<<<<<|>>>>>>>)" -or $line -match "^=======$") {
                Add-Error "Marcador de merge em $($file.FullName):$lineNo"
            }
        }
    }
    Write-Host ("[DEEP] conflito merge: {0} arquivos conferidos" -f $paths.Count)
}

function Resolve-PawnInclude {
    param(
        [string]$IncludeName,
        [string]$SourceDir = ""
    )

    $candidates = New-Object System.Collections.Generic.List[string]
    $normalized = $IncludeName -replace "/", "\"
    if ([System.IO.Path]::GetExtension($normalized) -eq "") {
        $normalizedWithExt = $normalized + ".inc"
    }
    else {
        $normalizedWithExt = $normalized
    }

    if (-not [string]::IsNullOrWhiteSpace($SourceDir)) {
        $candidates.Add((Join-Path $SourceDir $normalizedWithExt)) | Out-Null
    }
    $candidates.Add((Join-Path (Join-Path $RootDir "include") $normalizedWithExt)) | Out-Null
    $candidates.Add((Join-Path (Join-Path $RootDir "pawno\include") $normalizedWithExt)) | Out-Null

    foreach ($candidate in $candidates) {
        if (Test-Path -LiteralPath $candidate) {
            return $candidate
        }
    }
    return ""
}

function Test-PawnIncludes {
    $paths = @()
    $paths += Get-ChildItem -LiteralPath (Join-Path $RootDir "gamemodes") -Filter "nova_gm.pwn" -File
    $paths += Get-ChildItem -LiteralPath (Join-Path $RootDir "include") -Recurse -Include *.inc -File
    $paths += Get-ChildItem -LiteralPath (Join-Path $RootDir "npcmodes") -Filter "ls_*.pwn" -File
    $checked = 0

    foreach ($file in $paths) {
        foreach ($match in [regex]::Matches((Get-Content -Raw -LiteralPath $file.FullName), '#include\s+(?:<([^>]+)>|"([^"]+)")')) {
            $includeName = $match.Groups[1].Value
            if ([string]::IsNullOrWhiteSpace($includeName)) {
                $includeName = $match.Groups[2].Value
            }
            if ($includeName -match "^\.\.") {
                Add-Error "Include relativo subindo diretorio em $($file.FullName): $includeName"
                continue
            }
            $checked++
            if (-not (Resolve-PawnInclude -IncludeName $includeName -SourceDir $file.DirectoryName)) {
                Add-Error "Include nao encontrado em $($file.FullName): $includeName"
            }
        }
    }
    Write-Host ("[DEEP] includes Pawn: {0} referencias conferidas" -f $checked)
}

function Test-VersionSurfaces {
    $utilsPath = Join-Path $RootDir "include\core\utils.inc"
    $serverInfoPath = Join-Path $RootDir "scriptfiles\server_info.txt"
    $serverCfgPath = Join-Path $RootDir "server.cfg"
    $gmName = Get-DefineValue -Path $utilsPath -Name "GM_NAME"
    $gmVersion = Get-DefineValue -Path $utilsPath -Name "GM_VERSION"
    $gmText = Get-DefineValue -Path $utilsPath -Name "GM_TEXT"
    $releaseAmx = Get-DefineValue -Path $utilsPath -Name "GM_RELEASE_AMX"

    foreach ($item in @("GM_NAME", "GM_VERSION", "GM_TEXT", "GM_RELEASE_AMX")) {
        if (-not (Get-DefineValue -Path $utilsPath -Name $item)) {
            Add-Error "include\core\utils.inc sem define $item."
        }
    }

    $serverInfoLines = @()
    if (Test-Path -LiteralPath $serverInfoPath) {
        $serverInfoLines = @(Get-Content -LiteralPath $serverInfoPath | Where-Object { $_.Trim() -ne "" })
        if ($serverInfoLines.Count -ne 4) {
            Add-Error "scriptfiles\server_info.txt deve manter 4 linhas compactas; atual: $($serverInfoLines.Count)."
        }
    }
    $serverInfo = Read-KeyValueFile -Path $serverInfoPath
    $expected = [ordered]@{
        server_name = $gmName
        server_version = $gmVersion
        gamemode_text = $gmText
        server_language = "Portuguese"
    }
    foreach ($key in $expected.Keys) {
        if (-not $serverInfo.Contains($key)) {
            Add-Error "server_info.txt sem chave $key."
        }
        elseif ($serverInfo[$key] -ne $expected[$key]) {
            Add-Error "server_info.txt divergente em ${key}: atual='$($serverInfo[$key])' esperado='$($expected[$key])'."
        }
    }

    if ($releaseAmx -and $releaseAmx -notmatch "^nova_gm_[0-9]+\.amx$") {
        Add-Warning "GM_RELEASE_AMX fora do padrao nova_gm_####.amx: $releaseAmx"
    }

    $serverCfg = ""
    if (Test-Path -LiteralPath $serverCfgPath) {
        $serverCfg = Get-Content -Raw -LiteralPath $serverCfgPath
    }
    else {
        Add-Error "server.cfg ausente."
    }
    if ($serverCfg -and $serverCfg -notmatch "(?im)^gamemode0\s+nova_gm\s+1\s*$") {
        Add-Error "server.cfg local deve apontar para gamemode0 nova_gm 1."
    }
    if ($serverCfg -and $serverCfg -notmatch "(?im)^maxnpc\s+8\s*$") {
        Add-Error "server.cfg local deve manter maxnpc 8."
    }
    if ($serverCfg -and $gmVersion -and $serverCfg -notlike "*$gmVersion*") {
        Add-Warning "server.cfg hostname nao contem a versao atual $gmVersion."
    }
    Write-Host "[DEEP] versoes: utils/server_info/server.cfg conferidos"
}

function Test-AmxFreshness {
    $utilsPath = Join-Path $RootDir "include\core\utils.inc"
    $releaseAmx = Get-DefineValue -Path $utilsPath -Name "GM_RELEASE_AMX"
    $mainAmx = Join-Path $RootDir "gamemodes\nova_gm.amx"
    $releasePath = Join-Path $RootDir ("gamemodes\" + $releaseAmx)

    if (-not (Test-Path -LiteralPath $mainAmx)) {
        Add-Error "gamemodes\nova_gm.amx ausente."
        return
    }
    if (-not $releaseAmx -or -not (Test-Path -LiteralPath $releasePath)) {
        Add-Error "AMX de release ausente: $releaseAmx"
        return
    }

    $sourceFiles = @()
    $sourceFiles += Get-Item -LiteralPath (Join-Path $RootDir "gamemodes\nova_gm.pwn")
    $sourceFiles += Get-ChildItem -LiteralPath (Join-Path $RootDir "include") -Recurse -Include *.inc -File
    $latestSource = ($sourceFiles | Sort-Object LastWriteTimeUtc -Descending | Select-Object -First 1)
    if ((Get-Item -LiteralPath $mainAmx).LastWriteTimeUtc -lt $latestSource.LastWriteTimeUtc) {
        Add-Error "gamemodes\nova_gm.amx mais velho que $($latestSource.FullName)."
    }

    $mainHash = (Get-FileHash -LiteralPath $mainAmx -Algorithm SHA256).Hash
    $releaseHash = (Get-FileHash -LiteralPath $releasePath -Algorithm SHA256).Hash
    if ($mainHash -ne $releaseHash) {
        Add-Error "nova_gm.amx e $releaseAmx possuem hashes diferentes."
    }

    $staleAliases = @(Get-ChildItem -LiteralPath (Join-Path $RootDir "gamemodes") -File -Filter "nova_gm*.amx" |
        Where-Object { $_.Name -notin @("nova_gm.amx", $releaseAmx) })
    foreach ($item in $staleAliases) {
        Add-Warning "AMX antigo/extra em gamemodes: $($item.Name). O ZIP de sexta deve excluir isso."
    }
    Write-Host "[DEEP] AMX: principal, alias e hashes conferidos"
}

function Test-ScriptfilesMap {
    $required = @(
        "server_info.txt",
        "game_config.txt",
        "critical_commands.txt",
        "command_hotfixes.txt",
        "bot_messages.txt",
        "bot_badwords.txt",
        "job_vehicles.txt",
        "map_objects.txt",
        "radares.txt",
        "business_economy.txt",
        "justice_cases.txt",
        "justice_evidence.txt",
        "justice_warrants.txt",
        "crime_log.txt",
        "factions.txt",
        "crime_spots.txt",
        "access_config.txt",
        "whitelist.txt",
        "bans.txt",
        "backup_status.txt",
        "release_plan.txt",
        "changelog.txt"
    )

    foreach ($name in $required) {
        $path = Join-Path (Join-Path $RootDir "scriptfiles") $name
        if (-not (Test-Path -LiteralPath $path)) {
            Add-Error "scriptfiles obrigatorio ausente: $name"
            continue
        }
        if ((Get-Item -LiteralPath $path).Length -le 0) {
            Add-Error "scriptfiles obrigatorio vazio: $name"
        }
    }

    foreach ($name in @("banks.txt", "businesses.txt", "houses.txt", "interiors.txt", "police.txt")) {
        $path = Join-Path $RootDir ("scriptfiles\properties\" + $name)
        if (-not (Test-Path -LiteralPath $path)) {
            Add-Error "scriptfiles\properties obrigatorio ausente: $name"
        }
        elseif ((Get-Item -LiteralPath $path).Length -le 0) {
            Add-Error "scriptfiles\properties vazio: $name"
        }
    }

    $hotfixPath = Join-Path $RootDir "scriptfiles\command_hotfixes.txt"
    if (Test-Path -LiteralPath $hotfixPath) {
        $lineNo = 0
        foreach ($line in Get-Content -LiteralPath $hotfixPath) {
            $lineNo++
            $trim = $line.Trim()
            if (-not $trim -or $trim.StartsWith("#")) { continue }
            if ($trim -notmatch "^/[A-Za-z0-9_]+=/[A-Za-z0-9_]+$") {
                Add-Error "command_hotfixes.txt linha ${lineNo}: formato invalido."
            }
        }
    }

    $access = Read-KeyValueFile -Path (Join-Path $RootDir "scriptfiles\access_config.txt")
    foreach ($key in @("maintenance", "whitelist")) {
        if (-not $access.Contains($key)) {
            Add-Error "access_config.txt sem $key."
        }
        elseif ($access[$key] -notin @("0", "1")) {
            Add-Error "access_config.txt $key deve ser 0 ou 1."
        }
    }

    Write-Host ("[DEEP] scriptfiles: {0} arquivos obrigatorios conferidos" -f ($required.Count + 5))
}

function Test-LogsAndBackupStatus {
    $serverLogPath = Join-Path $RootDir "server_log.txt"
    if (Test-Path -LiteralPath $serverLogPath) {
        $serverLog = Get-Content -Raw -LiteralPath $serverLogPath
        if ($serverLog -notmatch "Life Simulator BR carregado") {
            Add-Error "server_log.txt nao mostra Life Simulator BR carregado."
        }
        if ($serverLog -match "(?i)runtime error|script\[gamemodes/.+\]: Run time error|crash|exception|amx.*failed|unable to load|failed to load") {
            Add-Error "server_log.txt contem erro critico."
        }
    }
    else {
        Add-Error "server_log.txt ausente."
    }

    $crashInfoPath = Join-Path $RootDir "crashinfo.txt"
    if (Test-Path -LiteralPath $crashInfoPath) {
        $crashText = Get-Content -Raw -LiteralPath $crashInfoPath
        if ($crashText -match "(?i)Exception At Address|Stack trace|Loaded Modules") {
            Add-Error "crashinfo.txt contem crash."
        }
    }

    $backupStatusPath = Join-Path $RootDir "scriptfiles\backup_status.txt"
    $backup = Read-KeyValueFile -Path $backupStatusPath
    if ($backup.Contains("last_backup")) {
        $backupPath = Join-Path (Join-Path $RootDir "backups") $backup["last_backup"]
        if (-not (Test-Path -LiteralPath $backupPath)) {
            Add-Error "backup_status.txt aponta para backup inexistente: $($backup["last_backup"])"
        }
    }
    if ($backup.Contains("last_backup_at")) {
        $backupDate = [datetime]::MinValue
        if ([datetime]::TryParse($backup["last_backup_at"], [ref]$backupDate)) {
            $ageHours = ((Get-Date) - $backupDate).TotalHours
            if ($ageHours -gt 48) {
                $message = "Backup de scriptfiles esta antigo: $([math]::Round($ageHours, 1)) horas."
                if ($StrictOperationalWarnings) { Add-Error $message } else { Add-Warning $message }
            }
        }
        else {
            Add-Error "backup_status.txt last_backup_at invalido."
        }
    }
    Write-Host "[DEEP] logs/backups: server_log, crashinfo e backup_status conferidos"
}

function Test-FridayPackageRules {
    $scriptPath = Join-Path $RootDir "tools\build_friday_upload_zip.ps1"
    if (-not (Test-Path -LiteralPath $scriptPath)) {
        Add-Error "build_friday_upload_zip.ps1 ausente."
        return
    }
    $script = Get-Content -Raw -LiteralPath $scriptPath
    if ($script -notlike "*pre_deploy_gate.ps1*") {
        Add-Error "ZIP de sexta nao chama pre_deploy_gate.ps1."
    }
    if ($script -notmatch "scriptfiles/contas") {
        Add-Error "ZIP de sexta nao bloqueia scriptfiles/contas."
    }
    if ($script -notmatch "account_index\|account_aliases") {
        Add-Error "ZIP de sexta nao bloqueia metadados de conta por padrao."
    }
    if ($script -notlike "*gamemode0 `$releaseName 1*") {
        Add-Warning "ZIP de sexta ainda precisa regravar server.cfg para o alias de release."
    }
    if ($script -notmatch "gamemodes/\.\*") {
        Add-Warning "ZIP de sexta ainda precisa bloquear AMX antigo/extra em gamemodes."
    }
    Write-Host "[DEEP] ZIP sexta: regras operacionais conferidas"
}

Test-ConflictMarkers
Test-PawnIncludes
Test-VersionSurfaces
Test-AmxFreshness
Test-ScriptfilesMap
Test-LogsAndBackupStatus
Test-FridayPackageRules

foreach ($warning in $warnings) {
    Write-Host ("[DEEP][WARN] {0}" -f $warning)
}

if ($errors.Count -gt 0) {
    Write-Host "DEEP_AUDIT_BLOQUEADO"
    foreach ($errorItem in $errors) {
        Write-Host (" - {0}" -f $errorItem)
    }
    exit 1
}

Write-Host "DEEP_AUDIT_OK"
exit 0
