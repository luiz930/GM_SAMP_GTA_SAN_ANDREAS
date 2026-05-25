param(
    [int]$Seconds = 90,
    [switch]$SkipCompile
)

$ErrorActionPreference = "Stop"

$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$RootDir = Split-Path -Parent $ScriptDir
$ServerExe = Join-Path $RootDir "samp-server.exe"
$ServerCfg = Join-Path $RootDir "server.cfg"
$PawnCompiler = Join-Path $RootDir "pawno\pawncc.exe"
$GameModeSource = Join-Path $RootDir "gamemodes\nova_gm.pwn"
$ServerLog = Join-Path $RootDir "server_log.txt"
$CrashInfo = Join-Path $RootDir "crashinfo.txt"
$BootLogDir = Join-Path $RootDir "backups\boot_tests"

function Get-CfgValue {
    param(
        [string[]]$Lines,
        [string]$Key
    )

    $line = $Lines | Where-Object { $_ -match ("^\s*" + [regex]::Escape($Key) + "\s+") } | Select-Object -First 1
    if (-not $line) {
        return ""
    }
    return (($line -replace "^\s*\S+\s+", "").Trim())
}

function Get-DefineValue {
    param(
        [string]$Path,
        [string]$Name
    )

    $line = Select-String -Path $Path -Pattern ("#define\s+" + [regex]::Escape($Name) + "\s+`"([^`"]+)`"") | Select-Object -First 1
    if (-not $line) {
        return ""
    }
    return $line.Matches[0].Groups[1].Value
}

function Save-BootArtifact {
    param(
        [string]$Path,
        [string]$Stamp
    )

    if (Test-Path -LiteralPath $Path) {
        New-Item -ItemType Directory -Force -Path $BootLogDir | Out-Null
        Copy-Item -LiteralPath $Path -Destination (Join-Path $BootLogDir ("{0}_{1}" -f $Stamp, (Split-Path -Leaf $Path))) -Force
    }
}

function Stop-SampNpcProcesses {
    Get-Process -ErrorAction SilentlyContinue |
        Where-Object { $_.ProcessName -eq "samp-npc" -and $_.Path -like (Join-Path $RootDir "*") } |
        ForEach-Object {
            try {
                Stop-Process -Id $_.Id -Force
            }
            catch {
                Write-Warning ("Nao foi possivel encerrar samp-npc {0}: {1}" -f $_.Id, $_.Exception.Message)
            }
        }
}

if ($Seconds -lt 30) {
    $Seconds = 30
}

if (-not (Test-Path -LiteralPath $ServerExe)) { throw "samp-server.exe nao encontrado: $ServerExe" }
if (-not (Test-Path -LiteralPath $ServerCfg)) { throw "server.cfg nao encontrado: $ServerCfg" }

Set-Location -LiteralPath $RootDir

$cfgLines = Get-Content -LiteralPath $ServerCfg
$gamemodeValue = Get-CfgValue -Lines $cfgLines -Key "gamemode0"
$maxNpcValue = Get-CfgValue -Lines $cfgLines -Key "maxnpc"
if (-not $gamemodeValue) { throw "server.cfg nao possui gamemode0." }
if (-not $maxNpcValue) { throw "server.cfg nao possui maxnpc." }

$gamemodeParts = $gamemodeValue -split "\s+"
$gamemodeAlias = $gamemodeParts[0]
if ($maxNpcValue -notmatch "^8(\s*)$") {
    throw "server.cfg deve estar com maxnpc 8 para o boot test. Valor atual: $maxNpcValue"
}

if (-not $SkipCompile) {
    if (-not (Test-Path -LiteralPath $PawnCompiler)) { throw "pawncc.exe nao encontrado: $PawnCompiler" }
    if (-not (Test-Path -LiteralPath $GameModeSource)) { throw "Gamemode fonte nao encontrado: $GameModeSource" }

    Write-Host "Compilando GM para boot test..."
    & $PawnCompiler gamemodes\nova_gm.pwn -ipawno\include -iinclude -ogamemodes\nova_gm -w203
    if ($LASTEXITCODE -ne 0) {
        throw "Compilacao Pawn falhou com codigo $LASTEXITCODE."
    }
}

$releaseAmx = Get-DefineValue -Path (Join-Path $RootDir "include\core\utils.inc") -Name "GM_RELEASE_AMX"
if ($gamemodeAlias -ne "nova_gm") {
    Copy-Item -LiteralPath (Join-Path $RootDir "gamemodes\nova_gm.amx") -Destination (Join-Path $RootDir ("gamemodes\" + $gamemodeAlias + ".amx")) -Force
}
elseif ($releaseAmx) {
    Copy-Item -LiteralPath (Join-Path $RootDir "gamemodes\nova_gm.amx") -Destination (Join-Path $RootDir ("gamemodes\" + $releaseAmx)) -Force
}

$stamp = Get-Date -Format "yyyy-MM-dd_HH-mm-ss"
Save-BootArtifact -Path $ServerLog -Stamp ("before_" + $stamp)
Save-BootArtifact -Path $CrashInfo -Stamp ("before_" + $stamp)
Set-Content -LiteralPath $ServerLog -Value "" -Encoding ASCII
if (Test-Path -LiteralPath $CrashInfo) {
    Set-Content -LiteralPath $CrashInfo -Value "" -Encoding ASCII
}

Write-Host ("Iniciando servidor local por {0}s para boot test..." -f $Seconds)
Stop-SampNpcProcesses
$proc = Start-Process -FilePath $ServerExe -WorkingDirectory $RootDir -PassThru -WindowStyle Hidden
Start-Sleep -Seconds $Seconds

if (-not $proc.HasExited) {
    Stop-Process -Id $proc.Id -Force
    Start-Sleep -Seconds 2
}
Stop-SampNpcProcesses

Save-BootArtifact -Path $ServerLog -Stamp ("after_" + $stamp)
Save-BootArtifact -Path $CrashInfo -Stamp ("after_" + $stamp)

$logText = ""
if (Test-Path -LiteralPath $ServerLog) {
    $logText = Get-Content -LiteralPath $ServerLog -Raw
}
$crashText = ""
if (Test-Path -LiteralPath $CrashInfo) {
    $crashText = Get-Content -LiteralPath $CrashInfo -Raw
}

$errors = New-Object System.Collections.Generic.List[string]
if ($logText -notmatch "Life Simulator BR carregado") { $errors.Add("GM nao carregou mensagem de sucesso no server_log.txt.") }
if ($gamemodeAlias -notmatch "^nova_gm") { $errors.Add("server.cfg esta apontando para gamemode inesperado: $gamemodeAlias.") }
if ($logText -match "(?i)runtime error|script\[gamemodes/.+\]: Run time error|crash|exception|amx.*failed|unable to load|failed to load") { $errors.Add("server_log.txt contem erro critico/runtime/crash.") }
if ($crashText -match "(?i)Exception At Address|Stack trace|Loaded Modules") { $errors.Add("crashinfo.txt contem crash recente.") }

if ($errors.Count -gt 0) {
    throw "Boot test falhou:`n - $($errors -join "`n - ")"
}

Write-Host "Boot test OK"
Write-Host ("Gamemode: {0}" -f $gamemodeAlias)
Write-Host ("Max NPC: {0}" -f $maxNpcValue)
Write-Host ("Log arquivado em: {0}" -f $BootLogDir)
