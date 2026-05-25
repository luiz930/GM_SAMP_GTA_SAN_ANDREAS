$ErrorActionPreference = "Stop"

$ProjectRoot = "C:\Users\anony\Desktop\Nova GM SAMP"
$GtaRoot = "C:\Program Files (x86)\Rockstar Games\GTA San Andreas"
$ModloaderRoot = Join-Path $ProjectRoot "downloads\modloader_v0.3.7"
$AsiLoader = Join-Path $ProjectRoot "downloads\dinput8-Win32\dinput8.dll"
$PackRoot = Join-Path $ProjectRoot "downloads\pack_veiculos_brasileiros_v1_extracted\Pack Carros Brasileiros"
$Stamp = Get-Date -Format "yyyyMMdd_HHmmss"
$BackupRoot = Join-Path $ProjectRoot "backups\gta_original_modpack_$Stamp"
$LogFile = Join-Path $ProjectRoot "backups\install_original_gta_modpack_$Stamp.log"

New-Item -ItemType Directory -Path $BackupRoot -Force | Out-Null

function Write-InstallLog {
    param([string]$Message)
    $line = "$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss') $Message"
    Add-Content -LiteralPath $LogFile -Value $line
    Write-Host $line
}

function Copy-IfExists {
    param(
        [string]$Source,
        [string]$Destination
    )

    if (Test-Path -LiteralPath $Source) {
        Copy-Item -LiteralPath $Source -Destination $Destination -Force
        Write-InstallLog "Backup: $Source -> $Destination"
    }
}

Write-InstallLog "Iniciando instalacao do modpack na pasta original."
Write-InstallLog "GTA: $GtaRoot"

if (!(Test-Path -LiteralPath (Join-Path $GtaRoot "gta_sa.exe"))) {
    throw "gta_sa.exe nao encontrado em $GtaRoot"
}

if (!(Test-Path -LiteralPath $AsiLoader)) {
    throw "ASI loader nao encontrado em $AsiLoader"
}

if (!(Test-Path -LiteralPath (Join-Path $ModloaderRoot "modloader.asi"))) {
    throw "modloader.asi nao encontrado em $ModloaderRoot"
}

if (!(Test-Path -LiteralPath $PackRoot)) {
    throw "Pack de carros nao encontrado em $PackRoot"
}

Copy-IfExists (Join-Path $GtaRoot "DINPUT8.DLL") (Join-Path $BackupRoot "DINPUT8.DLL")
Copy-IfExists (Join-Path $GtaRoot "dinput8.dll") (Join-Path $BackupRoot "dinput8.dll")
Copy-IfExists (Join-Path $GtaRoot "modloader.asi") (Join-Path $BackupRoot "modloader.asi")
Copy-IfExists (Join-Path $GtaRoot "vorbisFile.dll") (Join-Path $BackupRoot "vorbisFile.dll")
Copy-IfExists (Join-Path $GtaRoot "vorbisFileHooked.dll") (Join-Path $BackupRoot "vorbisFileHooked.dll")

if (Test-Path -LiteralPath (Join-Path $GtaRoot "modloader")) {
    $modloaderBackup = Join-Path $BackupRoot "modloader"
    robocopy (Join-Path $GtaRoot "modloader") $modloaderBackup /E /NFL /NDL /NJH /NJS /NP | Out-Null
    if ($LASTEXITCODE -gt 7) {
        throw "Falha ao fazer backup da pasta modloader. Codigo robocopy: $LASTEXITCODE"
    }
    Write-InstallLog "Backup da pasta modloader salvo em $modloaderBackup"
}

if (Test-Path -LiteralPath (Join-Path $GtaRoot "vorbisFile.dll")) {
    Copy-Item -LiteralPath (Join-Path $GtaRoot "vorbisFile.dll") -Destination (Join-Path $GtaRoot "vorbisFileHooked.dll") -Force
}

Copy-Item -LiteralPath $AsiLoader -Destination (Join-Path $GtaRoot "dinput8.dll") -Force
Copy-Item -LiteralPath $AsiLoader -Destination (Join-Path $GtaRoot "vorbisFile.dll") -Force
Copy-Item -LiteralPath (Join-Path $ModloaderRoot "modloader.asi") -Destination (Join-Path $GtaRoot "modloader.asi") -Force
Copy-Item -LiteralPath (Join-Path $ModloaderRoot "modloader") -Destination $GtaRoot -Recurse -Force

$PackDest = Join-Path $GtaRoot "modloader\Pack Carros Brasileiros"
New-Item -ItemType Directory -Path $PackDest -Force | Out-Null
Copy-Item -LiteralPath (Join-Path $PackRoot "data") -Destination $PackDest -Recurse -Force
Copy-Item -LiteralPath (Join-Path $PackRoot "gta3.img") -Destination $PackDest -Recurse -Force
Copy-Item -LiteralPath (Join-Path $PackRoot "text") -Destination $PackDest -Recurse -Force

$RequiredFiles = @(
    "dinput8.dll",
    "vorbisFile.dll",
    "vorbisFileHooked.dll",
    "modloader.asi",
    "modloader\Pack Carros Brasileiros\gta3.img\blistac.dff",
    "modloader\Pack Carros Brasileiros\gta3.img\premier.dff",
    "modloader\Pack Carros Brasileiros\gta3.img\sultan.dff",
    "modloader\Pack Carros Brasileiros\data\vehicles.ide",
    "modloader\Pack Carros Brasileiros\text\nome_veiculos.fxt"
)

foreach ($file in $RequiredFiles) {
    $path = Join-Path $GtaRoot $file
    if (!(Test-Path -LiteralPath $path)) {
        throw "Arquivo obrigatorio nao instalado: $path"
    }
    $item = Get-Item -LiteralPath $path
    Write-InstallLog "OK $file $($item.Length) bytes"
}

Write-InstallLog "Instalacao concluida com sucesso."
