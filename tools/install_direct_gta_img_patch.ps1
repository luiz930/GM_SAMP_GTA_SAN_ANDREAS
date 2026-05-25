$ErrorActionPreference = "Stop"

$ProjectRoot = "C:\Users\anony\Desktop\Nova GM SAMP"
$GtaRoot = "C:\Program Files (x86)\Rockstar Games\GTA San Andreas"
$ImgPath = Join-Path $GtaRoot "models\gta3.img"
$ReplacementDir = Join-Path $ProjectRoot "downloads\pack_veiculos_brasileiros_v1_extracted\Pack Carros Brasileiros\gta3.img"
$DataDir = Join-Path $ProjectRoot "downloads\pack_veiculos_brasileiros_v1_extracted\Pack Carros Brasileiros\data"
$TextDir = Join-Path $ProjectRoot "downloads\pack_veiculos_brasileiros_v1_extracted\Pack Carros Brasileiros\text"
$NodeExe = "C:\Users\anony\AppData\Local\OpenAI\Codex\bin\node.exe"
$PatchScript = Join-Path $ProjectRoot "tools\patch_img_v2.mjs"
$Stamp = Get-Date -Format "yyyyMMdd_HHmmss"
$BackupRoot = Join-Path $ProjectRoot "backups\gta3_direct_patch_$Stamp"
$LogFile = Join-Path $BackupRoot "install_direct_gta_img_patch.log"

New-Item -ItemType Directory -Path $BackupRoot -Force | Out-Null

function Log {
    param([string]$Message)
    $line = "$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss') $Message"
    Add-Content -LiteralPath $LogFile -Value $line
    Write-Host $line
}

Log "Fechando GTA/SA-MP se estiverem abertos."
Get-Process samp -ErrorAction SilentlyContinue | Stop-Process -Force
Get-Process gta_sa -ErrorAction SilentlyContinue | Stop-Process -Force

if (!(Test-Path -LiteralPath $ImgPath)) { throw "gta3.img nao encontrado: $ImgPath" }
if (!(Test-Path -LiteralPath $ReplacementDir)) { throw "Pasta de replacements nao encontrada: $ReplacementDir" }
if (!(Test-Path -LiteralPath $NodeExe)) { throw "Node nao encontrado: $NodeExe" }

Log "Fazendo backup do gta3.img original."
Copy-Item -LiteralPath $ImgPath -Destination (Join-Path $BackupRoot "gta3.img") -Force

foreach ($file in @("handling.cfg", "vehicles.ide", "carcols.dat")) {
    $target = Join-Path $GtaRoot "data\$file"
    if (Test-Path -LiteralPath $target) {
        Copy-Item -LiteralPath $target -Destination (Join-Path $BackupRoot $file) -Force
        Log "Backup data/$file"
    }
}

if (Test-Path -LiteralPath (Join-Path $GtaRoot "text\american.gxt")) {
    Copy-Item -LiteralPath (Join-Path $GtaRoot "text\american.gxt") -Destination (Join-Path $BackupRoot "american.gxt") -Force
}

Log "Aplicando replacements diretamente no models/gta3.img."
& $NodeExe $PatchScript $ImgPath $ReplacementDir
if ($LASTEXITCODE -ne 0) {
    throw "patch_img_v2 falhou com codigo $LASTEXITCODE"
}

foreach ($file in @("handling.cfg", "vehicles.ide", "carcols.dat")) {
    $source = Join-Path $DataDir $file
    if (Test-Path -LiteralPath $source) {
        Copy-Item -LiteralPath $source -Destination (Join-Path $GtaRoot "data\$file") -Force
        Log "Atualizado data/$file"
    }
}

if (Test-Path -LiteralPath (Join-Path $TextDir "nome_veiculos.fxt")) {
    New-Item -ItemType Directory -Path (Join-Path $GtaRoot "cleo\cleo_text") -Force | Out-Null
    Copy-Item -LiteralPath (Join-Path $TextDir "nome_veiculos.fxt") -Destination (Join-Path $GtaRoot "cleo\cleo_text\nome_veiculos.fxt") -Force
    Log "Copiado nome_veiculos.fxt para cleo/cleo_text"
}

$img = Get-Item -LiteralPath $ImgPath
Log "gta3.img final: $($img.Length) bytes"
Log "Instalacao direta concluida. Backup: $BackupRoot"
