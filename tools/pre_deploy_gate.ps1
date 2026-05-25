param(
    [int]$BootSeconds = 90,
    [switch]$SkipBoot,
    [switch]$SkipCompile
)

$ErrorActionPreference = "Stop"

$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$RootDir = Split-Path -Parent $ScriptDir
Set-Location -LiteralPath $RootDir

function Get-DefineValue {
    param(
        [string]$Path,
        [string]$Name
    )

    $pattern = "^\s*#define\s+$([regex]::Escape($Name))\s+`"([^`"]+)`""
    foreach ($line in Get-Content -LiteralPath $Path) {
        if ($line -match $pattern) {
            return $Matches[1]
        }
    }
    return ""
}

function Invoke-GateStep {
    param(
        [string]$Name,
        [scriptblock]$Action
    )

    Write-Host ("[GATE] {0}..." -f $Name)
    & $Action
    Write-Host ("[GATE] {0}: OK" -f $Name)
}

function Read-Manifest {
    param([string]$Path)

    $data = @{}
    foreach ($line in Get-Content -LiteralPath $Path) {
        if (-not $line -or $line.Trim().StartsWith("#")) { continue }
        $eq = $line.IndexOf("=")
        if ($eq -le 0) { continue }
        $key = $line.Substring(0, $eq).Trim()
        $value = $line.Substring($eq + 1).Trim()
        $data[$key] = $value
    }
    return $data
}

$errors = New-Object System.Collections.Generic.List[string]
$manifestPath = ""

try {
    Invoke-GateStep -Name "static_gm_audit" -Action {
        & powershell -NoProfile -ExecutionPolicy Bypass -File ".\tools\static_gm_audit.ps1"
        if ($LASTEXITCODE -ne 0) { throw "static_gm_audit.ps1 retornou codigo $LASTEXITCODE." }
    }

    Invoke-GateStep -Name "build_deploy_check" -Action {
        $args = @("-NoProfile", "-ExecutionPolicy", "Bypass", "-File", ".\tools\build_deploy_check.ps1")
        if ($SkipCompile) { $args += "-SkipCompile" }
        $args += "-SkipAudit"
        $args += "-SkipBoot"
        & powershell @args
        if ($LASTEXITCODE -ne 0) { throw "build_deploy_check.ps1 retornou codigo $LASTEXITCODE." }
    }

    Invoke-GateStep -Name "deep_system_audit" -Action {
        & powershell -NoProfile -ExecutionPolicy Bypass -File ".\tools\deep_system_audit.ps1"
        if ($LASTEXITCODE -ne 0) { throw "deep_system_audit.ps1 retornou codigo $LASTEXITCODE." }
    }

    $deployStageRoot = Join-Path $RootDir "build\deploy_staging"
    $latestDeploy = Get-ChildItem -LiteralPath $deployStageRoot -Directory -Filter "nova_gm_samp_*" -ErrorAction SilentlyContinue |
        Sort-Object LastWriteTime -Descending |
        Select-Object -First 1
    if (-not $latestDeploy) { throw "Nenhum diretorio de staging de deploy encontrado." }

    $manifestPath = Join-Path $latestDeploy.FullName "deploy_manifest.txt"
    if (-not (Test-Path -LiteralPath $manifestPath)) { throw "Manifesto nao encontrado: $manifestPath" }
    $manifest = Read-Manifest -Path $manifestPath

    if (-not $SkipBoot) {
        Invoke-GateStep -Name "boot_test_server" -Action {
            & powershell -NoProfile -ExecutionPolicy Bypass -File ".\tools\boot_test_server.ps1" -Seconds $BootSeconds -SkipCompile
            if ($LASTEXITCODE -ne 0) { throw "boot_test_server.ps1 retornou codigo $LASTEXITCODE." }
        }
    }

    Invoke-GateStep -Name "check_post_restart" -Action {
        & powershell -NoProfile -ExecutionPolicy Bypass -File ".\tools\check_post_restart.ps1"
        if ($LASTEXITCODE -ne 0) { throw "check_post_restart.ps1 retornou codigo $LASTEXITCODE." }
    }

    Invoke-GateStep -Name "hashes" -Action {
        foreach ($key in @("amx", "zip", "amx_sha256", "zip_sha256")) {
            if (-not $manifest.ContainsKey($key) -or [string]::IsNullOrWhiteSpace($manifest[$key])) {
                throw "Manifesto sem $key."
            }
        }

        $amxHash = (Get-FileHash -LiteralPath $manifest["amx"] -Algorithm SHA256).Hash
        $zipHash = (Get-FileHash -LiteralPath $manifest["zip"] -Algorithm SHA256).Hash
        if ($amxHash -ne $manifest["amx_sha256"]) { throw "Hash AMX divergente." }
        if ($zipHash -ne $manifest["zip_sha256"]) { throw "Hash ZIP divergente." }
    }

    Invoke-GateStep -Name "server.cfg e server_info" -Action {
        $serverCfg = Get-Content -Raw -LiteralPath (Join-Path $RootDir "server.cfg")
        $packageServerCfg = Get-Content -Raw -LiteralPath (Join-Path $latestDeploy.FullName "server.cfg")
        $serverInfo = Get-Content -Raw -LiteralPath (Join-Path $RootDir "scriptfiles\server_info.txt")
        $packageAlias = if ($manifest.ContainsKey("alias")) { $manifest["alias"] } else { "nova_gm_1003" }
        $packageVersion = if ($manifest.ContainsKey("version")) { $manifest["version"] } else { "v1.3.0 Stable" }
        $gmText = Get-DefineValue -Path (Join-Path $RootDir "include\core\utils.inc") -Name "GM_TEXT"

        if ($serverCfg -notmatch "(?im)^gamemode0\s+nova_gm\s+1\s*$") { throw "server.cfg local nao esta em gamemode0 nova_gm 1." }
        if ($packageServerCfg -notmatch "(?im)^gamemode0\s+$([regex]::Escape($packageAlias))\s+1\s*$") { throw "server.cfg do pacote nao esta em gamemode0 $packageAlias 1." }
        if ($serverCfg -notmatch "(?im)^maxnpc\s+8\s*$") { throw "server.cfg local nao esta com maxnpc 8." }
        if ($packageServerCfg -notmatch "(?im)^maxnpc\s+8\s*$") { throw "server.cfg do pacote nao esta com maxnpc 8." }
        if ($serverInfo -notmatch "(?im)^server_version=$([regex]::Escape($packageVersion))\s*$") { throw "server_info.txt sem versao esperada." }
        if ($gmText -and $serverInfo -notmatch "(?im)^gamemode_text=$([regex]::Escape($gmText))\s*$") { throw "server_info.txt sem gamemode_text esperado: $gmText." }
    }

    Invoke-GateStep -Name "crashinfo e server_log" -Action {
        $crashPath = Join-Path $RootDir "crashinfo.txt"
        $crashText = ""
        if (Test-Path -LiteralPath $crashPath) { $crashText = Get-Content -Raw -LiteralPath $crashPath }
        if ($crashText -match "(?i)Exception At Address|Stack trace|Loaded Modules") { throw "crashinfo.txt contem crash." }

        $serverLog = Get-Content -Raw -LiteralPath (Join-Path $RootDir "server_log.txt")
        if ($serverLog -notmatch "Life Simulator BR carregado") { throw "server_log.txt nao mostra GM carregada." }
        if ($serverLog -match "(?i)runtime error|crash|exception|unable to load|failed to load|amx.*failed") { throw "server_log.txt contem erro critico." }
    }
}
catch {
    $errors.Add($_.Exception.Message)
}

if ($errors.Count -gt 0) {
    Write-Host "BLOQUEADO"
    foreach ($errorItem in $errors) {
        Write-Host (" - {0}" -f $errorItem)
    }
    exit 1
}

Write-Host "LIBERADO"
Write-Host ("Manifesto: {0}" -f $manifestPath)
exit 0
