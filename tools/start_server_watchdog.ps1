param(
    [int]$BackupIntervalMinutes = 30,
    [int]$RestartDelaySeconds = 10,
    [int]$MaxRestarts = 0,
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
$RuntimeBackupDir = Join-Path $RootDir "backups\runtime_crashes"
$WatchdogLog = Join-Path $RootDir "backups\watchdog.log"

function Write-WatchdogLog {
    param([string]$Message)

    $line = "[{0}] {1}" -f (Get-Date -Format "yyyy-MM-dd HH:mm:ss"), $Message
    Write-Host $line
    New-Item -ItemType Directory -Force -Path (Split-Path -Parent $WatchdogLog) | Out-Null
    Add-Content -LiteralPath $WatchdogLog -Value $line
}

function Archive-RuntimeLogs {
    param([string]$Reason)

    $stamp = Get-Date -Format "yyyy-MM-dd_HH-mm-ss"
    $targetDir = Join-Path $RuntimeBackupDir $stamp
    New-Item -ItemType Directory -Force -Path $targetDir | Out-Null

    foreach ($name in @("server_log.txt", "crashinfo.txt")) {
        $source = Join-Path $RootDir $name
        if (Test-Path -LiteralPath $source) {
            Copy-Item -LiteralPath $source -Destination (Join-Path $targetDir $name) -Force
        }
    }

    Set-Content -LiteralPath (Join-Path $targetDir "reason.txt") -Value $Reason -Encoding ASCII
    Write-WatchdogLog ("Logs arquivados em {0}" -f $targetDir)
}

if (-not (Test-Path -LiteralPath $BackupScript)) { throw "Script de backup nao encontrado: $BackupScript" }
if (-not (Test-Path -LiteralPath $ServerExe)) { throw "samp-server.exe nao encontrado: $ServerExe" }

Set-Location -LiteralPath $RootDir

if ($NoStart) {
    Write-WatchdogLog "Watchdog OK em modo validacao."
    exit 0
}

if (-not $SkipCompile) {
    if (-not (Test-Path -LiteralPath $PawnCompiler)) { throw "pawncc.exe nao encontrado: $PawnCompiler" }
    if (-not (Test-Path -LiteralPath $GameModeSource)) { throw "Gamemode fonte nao encontrado: $GameModeSource" }
    Write-WatchdogLog "Compilando GM antes de iniciar watchdog."
    & $PawnCompiler gamemodes\nova_gm.pwn -ipawno\include -iinclude -ogamemodes\nova_gm -w203
    if ($LASTEXITCODE -ne 0) {
        throw "Compilacao Pawn falhou com codigo $LASTEXITCODE."
    }
}

Write-WatchdogLog "Iniciando job de backup automatico."
$backupJob = Start-Job -ScriptBlock {
    param($ScriptPath, $Interval)
    & $ScriptPath -Loop -IntervalMinutes $Interval
} -ArgumentList $BackupScript, $BackupIntervalMinutes

$restartCount = 0
try {
    while ($true) {
        if ($MaxRestarts -gt 0 -and $restartCount -ge $MaxRestarts) {
            Write-WatchdogLog ("MaxRestarts atingido: {0}. Watchdog encerrado." -f $MaxRestarts)
            break
        }

        Write-WatchdogLog "Executando backup antes de iniciar servidor."
        & $BackupScript | Out-Host

        Write-WatchdogLog "Iniciando samp-server.exe."
        $proc = Start-Process -FilePath $ServerExe -WorkingDirectory $RootDir -PassThru -WindowStyle Hidden
        Wait-Process -Id $proc.Id
        $exitCode = $proc.ExitCode
        $restartCount++

        Archive-RuntimeLogs -Reason ("samp-server.exe saiu. ExitCode={0}; restart={1}" -f $exitCode, $restartCount)
        Write-WatchdogLog ("Servidor caiu/encerrou. ExitCode={0}. Reiniciando em {1}s." -f $exitCode, $RestartDelaySeconds)
        Start-Sleep -Seconds $RestartDelaySeconds
    }
}
finally {
    if ($backupJob) {
        Write-WatchdogLog "Encerrando job de backup automatico."
        Stop-Job -Job $backupJob -ErrorAction SilentlyContinue
        Receive-Job -Job $backupJob -ErrorAction SilentlyContinue
        Remove-Job -Job $backupJob -Force -ErrorAction SilentlyContinue
    }
}
