# Checklist deploy 19h

## Antes das 19h

- Rodar o gate local:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\tools\pre_deploy_gate.ps1
```

- Confirmar que o resultado final foi `LIBERADO`.
- Conferir o manifesto do pacote mais recente em `deploy/`.
- Conferir o ZIP e o SHA256 no `deploy_manifest.txt` do pacote mais recente.
- Confirmar que `server.cfg` local esta em `gamemode0 nova_gm 1`.
- Confirmar que o pacote esta em `gamemode0 nova_gm_1003 1`.
- Confirmar que `crashinfo.txt` esta vazio ou sem crash novo.

## As 19h de sexta

- Rodar o deploy FTP:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\tools\build_deploy_check.ps1 -Deploy
```

- Automacao ativa: `Deploy FTP Nova GM sexta 19h`.
- Confirmar `FTP deploy: OK`.
- Guardar o caminho do `rollback_manifest.txt`.

## Depois do deploy

- Reiniciar o servidor na hospedagem.
- Rodar o check remoto:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\tools\check_post_restart.ps1 -Remote
```

- Entrar no jogo e testar: `/versao`, `/atualizacao`, `/saudegm`, `/selftestgm`, `/releasecheck`, `/statusserver`.
- Conferir `server_log.txt` remoto sem runtime error, crash ou falha de AMX.

## Rollback

- Usar o comando indicado em `rollback_manifest.txt`.
- Reiniciar o servidor.
- Rodar novamente:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\tools\check_post_restart.ps1 -Remote
```
