$ErrorActionPreference = "Stop"

$ProjectRoot = "C:\Users\anony\Desktop\Nova GM SAMP"
$GtaRoot = "C:\Program Files (x86)\Rockstar Games\GTA San Andreas"
$DirectBackup = Join-Path $ProjectRoot "backups\gta3_direct_patch_20260517_184058"
$DllBackupFirst = Join-Path $ProjectRoot "backups\gta_original_modpack_20260517_183356"
$DllBackupVorbis = Join-Path $ProjectRoot "backups\gta_original_modpack_20260517_183730"
$Stamp = Get-Date -Format "yyyyMMdd_HHmmss"
$LogFile = Join-Path $ProjectRoot "backups\restore_gta_original_$Stamp.log"

function Log {
    param([string]$Message)
    $line = "$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss') $Message"
    Add-Content -LiteralPath $LogFile -Value $line
    Write-Host $line
}

Log "Fechando GTA/SA-MP."
Get-Process samp -ErrorAction SilentlyContinue | Stop-Process -Force
Get-Process gta_sa -ErrorAction SilentlyContinue | Stop-Process -Force

if (!(Test-Path -LiteralPath (Join-Path $DirectBackup "gta3.img"))) {
    throw "Backup gta3.img nao encontrado: $DirectBackup"
}

Log "Restaurando models/gta3.img original."
Copy-Item -LiteralPath (Join-Path $DirectBackup "gta3.img") -Destination (Join-Path $GtaRoot "models\gta3.img") -Force

foreach ($file in @("handling.cfg", "vehicles.ide", "carcols.dat")) {
    $source = Join-Path $DirectBackup $file
    if (Test-Path -LiteralPath $source) {
        Copy-Item -LiteralPath $source -Destination (Join-Path $GtaRoot "data\$file") -Force
        Log "Restaurado data/$file"
    }
}

if (Test-Path -LiteralPath (Join-Path $DirectBackup "american.gxt")) {
    Copy-Item -LiteralPath (Join-Path $DirectBackup "american.gxt") -Destination (Join-Path $GtaRoot "text\american.gxt") -Force
    Log "Restaurado text/american.gxt"
}

Log "Restaurando DLLs originais."
if (Test-Path -LiteralPath (Join-Path $DllBackupFirst "DINPUT8.DLL")) {
    Copy-Item -LiteralPath (Join-Path $DllBackupFirst "DINPUT8.DLL") -Destination (Join-Path $GtaRoot "DINPUT8.DLL") -Force
}
if (Test-Path -LiteralPath (Join-Path $DllBackupVorbis "vorbisFile.dll")) {
    Copy-Item -LiteralPath (Join-Path $DllBackupVorbis "vorbisFile.dll") -Destination (Join-Path $GtaRoot "vorbisFile.dll") -Force
}

foreach ($relative in @("modloader.asi", "vorbisFileHooked.dll", "cleo\cleo_text\nome_veiculos.fxt")) {
    $path = Join-Path $GtaRoot $relative
    if (Test-Path -LiteralPath $path) {
        Remove-Item -LiteralPath $path -Force
        Log "Removido $relative"
    }
}

$modloaderPath = Join-Path $GtaRoot "modloader"
if (Test-Path -LiteralPath $modloaderPath) {
    Remove-Item -LiteralPath $modloaderPath -Recurse -Force
    Log "Removida pasta modloader"
}

$expected = @(
    "models\gta3.img",
    "data\handling.cfg",
    "data\vehicles.ide",
    "data\carcols.dat",
    "DINPUT8.DLL",
    "vorbisFile.dll"
)
foreach ($relative in $expected) {
    $item = Get-Item -LiteralPath (Join-Path $GtaRoot $relative)
    Log "OK $relative $($item.Length) bytes"
}

Log "Restore concluido."
