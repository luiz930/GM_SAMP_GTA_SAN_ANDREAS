@echo off
setlocal
cd /d "%~dp0"

if not exist "backups" mkdir "backups"

powershell.exe -NoProfile -ExecutionPolicy Bypass -File "%~dp0tools\start_server_online.ps1" -IntervalMinutes 30 -Keep 48

echo Servidor finalizado.
pause
