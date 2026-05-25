$env:VIP_PANEL_PORT = if ($env:VIP_PANEL_PORT) { $env:VIP_PANEL_PORT } else { "8088" }
$env:VIP_PANEL_HOST = if ($env:VIP_PANEL_HOST) { $env:VIP_PANEL_HOST } else { "0.0.0.0" }
$env:VIP_PANEL_TOKEN = if ($env:VIP_PANEL_TOKEN) { $env:VIP_PANEL_TOKEN } else { "troque-este-token" }
$env:VIP_PIX_KEY = if ($env:VIP_PIX_KEY) { $env:VIP_PIX_KEY } else { "configure-sua-chave-pix" }
$env:VIP_PANEL_SERVER = if ($env:VIP_PANEL_SERVER) { $env:VIP_PANEL_SERVER } else { "Life Simulator BR" }
$env:PUBLIC_SERVER_IP = if ($env:PUBLIC_SERVER_IP) { $env:PUBLIC_SERVER_IP } else { "em breve" }
$env:PUBLIC_SERVER_VERSION = if ($env:PUBLIC_SERVER_VERSION) { $env:PUBLIC_SERVER_VERSION } else { "v0.3.5 Alpha" }

Write-Host "Site:       http://127.0.0.1:$env:VIP_PANEL_PORT"
Write-Host "Forum:      http://127.0.0.1:$env:VIP_PANEL_PORT/forum"
Write-Host "Denuncias:  http://127.0.0.1:$env:VIP_PANEL_PORT/denuncias/nova"
Write-Host "VIP:        http://127.0.0.1:$env:VIP_PANEL_PORT/vip"
Write-Host "Admin:      http://127.0.0.1:$env:VIP_PANEL_PORT/admin?token=$env:VIP_PANEL_TOKEN"
Write-Host "Configure VIP_PANEL_TOKEN, VIP_PIX_KEY e PUBLIC_SERVER_IP antes de usar em producao."

$bundledNode = Join-Path $env:USERPROFILE ".cache\codex-runtimes\codex-primary-runtime\dependencies\node\bin\node.exe"
$nodeCmd = Get-Command node -ErrorAction SilentlyContinue

if (Test-Path $bundledNode) {
    & $bundledNode "$PSScriptRoot\server.js"
} elseif ($nodeCmd) {
    & $nodeCmd.Source "$PSScriptRoot\server.js"
} else {
    Write-Host ""
    Write-Host "Node.js nao foi encontrado."
    Write-Host "Instale o Node.js ou configure o caminho do node.exe no PATH para iniciar o site."
    exit 1
}
