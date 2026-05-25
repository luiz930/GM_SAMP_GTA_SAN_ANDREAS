param(
    [int]$IntervalMinutes = 30,
    [int]$Keep = 48,
    [switch]$SkipCompile,
    [switch]$NoStart
)

$ErrorActionPreference = "Stop"

$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$RootDir = Split-Path -Parent $ScriptDir
$BackupScript = Join-Path $ScriptDir "backup_scriptfiles.ps1"
$ServerExe = Join-Path $RootDir "samp-server.exe"
$PawnCompiler = Join-Path $RootDir "pawno\pawncc.exe"
$GameModeSource = Join-Path $RootDir "gamemodes\nova_gm.pwn"
$ServerCfg = Join-Path $RootDir "server.cfg"

if (!(Test-Path -LiteralPath $BackupScript)) {
    throw "Script de backup nao encontrado: $BackupScript"
}

if (!(Test-Path -LiteralPath $ServerExe)) {
    throw "samp-server.exe nao encontrado: $ServerExe"
}

if (!(Test-Path -LiteralPath $ServerCfg)) {
    throw "server.cfg nao encontrado: $ServerCfg"
}

if ($NoStart) {
    Write-Host "Launcher online OK."
    Write-Host ("Servidor: {0}" -f $ServerExe)
    Write-Host ("Backup: {0}" -f $BackupScript)
    exit 0
}

Set-Location -LiteralPath $RootDir

if (-not $SkipCompile) {
    if (!(Test-Path -LiteralPath $PawnCompiler)) {
        throw "pawncc.exe nao encontrado: $PawnCompiler"
    }
    if (!(Test-Path -LiteralPath $GameModeSource)) {
        throw "Gamemode fonte nao encontrado: $GameModeSource"
    }

    Write-Host "Compilando GM local gamemodes\nova_gm.pwn -> gamemodes\nova_gm.amx..."
    & $PawnCompiler gamemodes\nova_gm.pwn -ipawno\include -iinclude -ogamemodes\nova_gm -w203
    if ($LASTEXITCODE -ne 0) {
        throw "Compilacao Pawn falhou com codigo $LASTEXITCODE. Servidor local nao foi iniciado."
    }
}

$cfgText = Get-Content -LiteralPath $ServerCfg
$updatedCfg = $cfgText -replace "^gamemode0\s+.*$", "gamemode0 nova_gm 1"
if (($updatedCfg -join "`n") -ne ($cfgText -join "`n")) {
    Set-Content -LiteralPath $ServerCfg -Value $updatedCfg -Encoding ASCII
    Write-Host "server.cfg local ajustado para gamemode0 nova_gm 1."
}
if (-not ($updatedCfg -match "^gamemode0\s+nova_gm\s+1$")) {
    throw "server.cfg local nao possui linha gamemode0 nova_gm 1."
}

Write-Host "Iniciando backup automatico da pasta scriptfiles..."
$backupJob = Start-Job -ScriptBlock {
    param($ScriptPath, $Interval, $BackupKeep)
    & $ScriptPath -Loop -IntervalMinutes $Interval -Keep $BackupKeep
} -ArgumentList $BackupScript, $IntervalMinutes, $Keep

try {
    Write-Host "Iniciando samp-server.exe..."
    & $ServerExe
}
finally {
    if ($backupJob) {
        Write-Host "Encerrando backup automatico..."
        Stop-Job -Job $backupJob -ErrorAction SilentlyContinue
        Receive-Job -Job $backupJob -ErrorAction SilentlyContinue
        Remove-Job -Job $backupJob -Force -ErrorAction SilentlyContinue
    }
}
