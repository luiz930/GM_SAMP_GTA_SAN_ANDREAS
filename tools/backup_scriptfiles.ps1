param(
    [int]$IntervalMinutes = 30,
    [int]$Keep = 48,
    [switch]$Loop,
    [string]$Source = "",
    [string]$Destination = ""
)

$ErrorActionPreference = "Stop"

$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$RootDir = Split-Path -Parent $ScriptDir

if ([string]::IsNullOrWhiteSpace($Source)) {
    $Source = Join-Path $RootDir "scriptfiles"
}

if ([string]::IsNullOrWhiteSpace($Destination)) {
    $Destination = Join-Path $RootDir "backups"
}

function Write-BackupLog {
    param([string]$Message)

    $line = "[{0}] {1}" -f (Get-Date -Format "yyyy-MM-dd HH:mm:ss"), $Message
    Write-Host $line

    if (!(Test-Path -LiteralPath $Destination)) {
        New-Item -ItemType Directory -Path $Destination | Out-Null
    }

    Add-Content -LiteralPath (Join-Path $Destination "backup_log.txt") -Value $line
}

function Remove-OldBackups {
    if ($Keep -le 0) {
        return
    }

    $oldBackups = Get-ChildItem -LiteralPath $Destination -Filter "scriptfiles_*.zip" -File |
        Sort-Object LastWriteTime -Descending |
        Select-Object -Skip $Keep

    foreach ($backup in $oldBackups) {
        Remove-Item -LiteralPath $backup.FullName -Force
        Write-BackupLog ("Backup antigo removido: {0}" -f $backup.Name)
    }
}

function Remove-PathWithRetry {
    param([string]$Path)

    if (!(Test-Path -LiteralPath $Path)) {
        return
    }

    for ($attempt = 1; $attempt -le 10; $attempt++) {
        try {
            Remove-Item -LiteralPath $Path -Recurse -Force
            return
        }
        catch {
            if ($attempt -eq 10) {
                throw
            }
            Start-Sleep -Milliseconds 1000
        }
    }
}

function Compress-ArchiveWithRetry {
    param(
        [string]$Path,
        [string]$DestinationPath
    )

    for ($attempt = 1; $attempt -le 5; $attempt++) {
        try {
            if (Test-Path -LiteralPath $DestinationPath) {
                Remove-Item -LiteralPath $DestinationPath -Force
            }

            Start-Sleep -Milliseconds 500
            Compress-Archive -Path (Join-Path $Path "*") -DestinationPath $DestinationPath -Force
            return
        }
        catch {
            if ($attempt -eq 5) {
                throw
            }

            Write-BackupLog ("Tentando compactar novamente apos arquivo ocupado. Tentativa {0}/5" -f ($attempt + 1))
            Start-Sleep -Seconds 2
        }
    }
}

function Invoke-ScriptfilesBackup {
    if (!(Test-Path -LiteralPath $Source)) {
        throw "Pasta scriptfiles nao encontrada: $Source"
    }

    if (!(Test-Path -LiteralPath $Destination)) {
        New-Item -ItemType Directory -Path $Destination | Out-Null
    }

    $timestamp = Get-Date -Format "yyyy-MM-dd_HH-mm-ss"
    $zipPath = Join-Path $Destination ("scriptfiles_{0}.zip" -f $timestamp)
    $stagingRoot = Join-Path $Destination ".staging"
    $stagingDir = Join-Path $stagingRoot ("scriptfiles_{0}" -f $timestamp)

    Remove-PathWithRetry $stagingRoot

    New-Item -ItemType Directory -Path $stagingDir | Out-Null

    & robocopy.exe $Source $stagingDir /MIR /R:3 /W:1 /NFL /NDL /NJH /NJS /NP | Out-Null
    if ($LASTEXITCODE -ge 8) {
        throw "Falha ao copiar scriptfiles para staging. Codigo robocopy: $LASTEXITCODE"
    }

    Compress-ArchiveWithRetry -Path $stagingDir -DestinationPath $zipPath
    Remove-PathWithRetry $stagingRoot

    $statusPath = Join-Path $Source "backup_status.txt"
    $status = @(
        "# Ultimo backup automatico/manual da pasta scriptfiles."
        ("last_backup={0}" -f (Split-Path -Leaf $zipPath))
        ("last_backup_at={0}" -f (Get-Date -Format "yyyy-MM-dd HH:mm:ss"))
        ("last_backup_size={0}" -f ((Get-Item -LiteralPath $zipPath).Length))
    )
    Set-Content -LiteralPath $statusPath -Value $status -Encoding ASCII

    Write-BackupLog ("Backup criado: {0}" -f (Split-Path -Leaf $zipPath))
    Remove-OldBackups
}

if ($IntervalMinutes -lt 1) {
    $IntervalMinutes = 1
}

do {
    try {
        Invoke-ScriptfilesBackup
    }
    catch {
        Write-BackupLog ("ERRO: {0}" -f $_.Exception.Message)
    }

    if ($Loop) {
        Start-Sleep -Seconds ($IntervalMinutes * 60)
    }
} while ($Loop)
