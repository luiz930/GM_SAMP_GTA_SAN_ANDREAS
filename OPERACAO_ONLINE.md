# Operacao online - Life Simulator BR

## Como iniciar

Use o arquivo abaixo para subir o servidor com backup automatico:

```bat
iniciar_servidor_online.bat
```

Ele faz duas coisas:

- inicia o backup automatico da pasta `scriptfiles/` em segundo plano a cada 30 minutos;
- inicia o `samp-server.exe`.

Quando o servidor for fechado, o processo de backup iniciado por esse launcher tambem e encerrado.

Os backups ficam em `backups/` no formato:

```text
scriptfiles_2026-04-26_21-30-00.zip
```

Por padrao, o sistema guarda os ultimos 48 backups.

## Backup manual

Para criar um backup na hora, use:

```bat
backup_agora.bat
```

O log fica em:

```text
backups/backup_log.txt
```

## Restaurar backup

1. Feche o servidor.
2. Faca uma copia da pasta `scriptfiles/` atual, se quiser preservar o estado atual.
3. Extraia o `.zip` escolhido da pasta `backups/`.
4. Substitua o conteudo de `scriptfiles/` pelo conteudo extraido.
5. Inicie o servidor novamente.

## Configuracao online

Antes de divulgar o IP:

- em teste local, confirme que `server.cfg` esta com `gamemode0 nova_gm 1`; o alias de release fica somente no pacote/FTP de sexta;
- depois de atualizar a GM, teste `/atualizacao` para validar a leitura do changelog em dialog;
- teste `/versao`, `/saudegm`, `/releasecheck`, `/debugplayer [id]` e `/zonaguerra` depois do restart;
- teste `/saldo`, `/pagarmultas` e `/boletos` com carteira menor que a divida e banco zerado; a GM deve bloquear. Com banco suficiente, a mensagem deve mostrar carteira + banco usados.
- teste emprestimo no gerente do banco: solicitar valor dentro do limite, conferir juros/parcelas no extrato, gerar/pagar parcela vencida e quitar antecipado.
- confirme a zona de guerra em Mulholland as 15:00 e 22:00 BRT, por 30 minutos, com area vermelha no mapa;
- mantenha uma senha RCON forte;
- abra/libere a porta `7777` no firewall e no roteador/VPS;
- use `iniciar_servidor_online.bat` para nao esquecer o backup;
- teste login, spawn, hospital, banco, veiculos, empregos, interiores, radares e salvamento;
- teste `/vip`, `/comprarvip`, `/ativarvip`, `/setvip`, kit VIP e o painel externo;
- use `/checkserver` como DONO antes de abrir o servidor;
- use `/statusserver` durante os testes para acompanhar players, bugs, contas, veiculos e uptime;
- use `/painelstaff` ou `/operacao` para ver evento ativo, maior devedor online, empresas paradas, casos, denuncias e alertas;
- use `/eventos` para conferir falta de estoque, blitz especial, surto hospitalar, operacao policial e bonus por horario;
- teste `/notificacoes`, `/passe`, `/rankingsemanal`, `/historico` e GovBR no celular para validar retencao e proximos passos;
- teste recompensas de login, sequencia diaria e recompensa semanal em conta comum;
- teste empresas com `/empresa`, `/contratarempresa`, `/aceitarcontrato`, estoque, falencia e `/recuperarempresa`;
- teste v0.6 com `/progressao`, `/trabalhar`, `/servico`, taxi, mecanico, frentista, medico e multa policial para validar XP, JOB_REWARD e anti-farm;
- teste v0.7 com `/jornada`, `/proximopasso`, GovBR no celular, documentos vencendo, conta bancaria, primeiro emprego, primeiro servico, veiculo, DETRAN, moradia e recompensa de novato;
- teste v0.8 com `/servicospublicos`, GovBR > Servicos publicos, Prefeitura > Servicos publicos, `/prender`, `/soltar`, `/justica`, `/vistoria`, `/leilao`, `/prontuario`, `/internacao`, `/impostos`, `/orcamento` e `/licitacao`;
- teste v0.9 com `/perf`, `/logsstaff`, `/painelstaff`, `/antiabuso`, `/saudegm`, `/selftestgm` e `/releasecheck` depois de alguns ciclos de HUD/Fuel/Radar;
- para liberar v1.0.0 Stable, rode no servidor: `/versao`, `/atualizacao`, `/saudegm`, `/selftestgm`, `/perf`, `/logsstaff`, `/painelstaff`, `/antiabuso`, `/debugplayer [seu_id]` e por ultimo `/releasecheck`; a linha v1.0 deve aparecer como `LIBERADO`;
- teste prefeitura viva com `/prefeitura`, `/orcamento` e `/licitacao`;
- use `/seguranca` para acompanhar bans, alertas anti-cheat, flood, punicoes e suspeitas recentes;
- use `/ban`, `/unban` e `/banidos` para punicoes persistentes em `scriptfiles/bans.txt`;
- use `/bugprio`, `/bugresponder` e `/bugresolver` para fazer triagem dos relatos enviados por `/bug`;
- use `/manutencao on` para fechar temporariamente a entrada de jogadores comuns;
- use `/whitelist on` e `scriptfiles/whitelist.txt` para Alpha fechado;
- use `/admins` para conferir a equipe online;
- use `/reloadbot` apos editar `scriptfiles/bot_messages.txt` ou `scriptfiles/bot_badwords.txt`.
- use `/reloadradio` apos editar `scriptfiles/music_playlists.txt`.
- use `/reloadjobveiculos` apos editar `scriptfiles/job_vehicles.txt`.
- use `/addjobveiculo [job] [modelo/atual] [cor1] [cor2] [fuel]` como DONO/RCON para adicionar frota de profissao pelo jogo.
- use `/deljobveiculo` como DONO/RCON para abrir dialog, remover um veiculo salvo e atualizar `scriptfiles/job_vehicles.txt`.
- use `/reloadobjetos` apos editar `scriptfiles/map_objects.txt`.
- use `/addobjeto` e `/addportao` como DONO/RCON para abrir dialogs e adicionar objetos/portoes pela posicao atual no jogo.
- use `/delobjeto` ou `/delportao` como DONO/RCON para abrir dialog, remover a linha salva e atualizar `scriptfiles/map_objects.txt`.
- teste portoes/cancelas dirigindo e apertando H/buzina; portoes com profissao exigem que o player esteja naquele emprego.
- use `/ajudaadmin` para ver as instrucoes de staff e exemplos de objetos/portoes por dialog.
- teste `/radio` e `/pararradio` em uma conta comum antes de divulgar o servidor.
- teste `/radioveiculo`, `/pararradioveiculo`, som ambiente em interiores e `/somlocal` em conta staff nivel 4+.
- teste `/veiculos`, `/selecionarveiculo`, `/garagem`, `/detran`, `/documentoveiculo`, `/transferirveiculo`, `/venderveiculo` e limite de slots.
- teste `/trancar`, `/destrancar`, `/emprestarchave`, `/removerchave` e tentativa de entrar/dirigir sem chave.
- teste `/consultarplaca` e `/apreenderveiculo` com conta policial/staff, incluindo liberacao no Patio Municipal.
- teste `/criarblitz`, ENTER perto da blitz, `/blitz`, multa por dialog, ordem de parada, checkpoint, cones/barreira e `/removerblitz`.
- teste `/veiculo`, `/guardarveiculo`, `/seguroveiculo`, `/ipva`, `/pagaripva`, `/vistoria`, `/leilao`, guincho, destruicao do veiculo e recuperacao por `/patio` no Patio Municipal.
- teste garagem residencial perto de cada casa/apartamento e garagem publica em local separado.
- teste GovBR no celular para multas, IPVA, CRLV, guincho NPC, notificacoes, passe, ranking, historico, noticias, orcamento e licitacao.

## Fluxo semanal de atualizacoes

Regra operacional a partir de agora: de segunda a quinta, toda alteracao fica local e deve gerar no maximo pacote de teste. O servidor local sempre carrega `gamemodes/nova_gm.amx`; o servidor remoto so recebe deploy na sexta-feira as 19:00 BRT, depois de revisar versao, changelog e pacote.

Durante a semana:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\tools\build_deploy_check.ps1
```

Esse comando compila a GM, compila os NPCs, copia `CHANGELOG.txt` para `scriptfiles/changelog.txt`, monta o pacote em `deploy/`, gera ZIP, SHA256 e manifesto, mas nao envia FTP.

Para rodar localmente, use `iniciar_servidor_online.bat`: ele compila `gamemodes/nova_gm.pwn`, garante `gamemode0 nova_gm 1` no `server.cfg` local e so entao inicia o servidor.

Na sexta-feira, antes de subir as 19:00 BRT:

1. Atualize a versao em `include/core/utils.inc`: `GM_TEXT`, `GM_VERSION` e `GM_DEPLOY_DATE`.
2. Atualize `scriptfiles/server_info.txt` com `server_version` e `gamemode_text`.
3. Coloque o resumo da release no topo de `CHANGELOG.txt`.
4. Rode o gate local e confira o resultado `LIBERADO`:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\tools\pre_deploy_gate.ps1
```

5. Confira o manifesto gerado e siga `CHECKLIST_DEPLOY_19H.md`.
6. Se estiver liberado e for 19:00 BRT, rode o deploy:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\tools\build_deploy_check.ps1 -Deploy
```

O script bloqueia `-Deploy` fora da janela de sexta-feira as 19:00 BRT. `-ForceDeploy` existe apenas para emergencia consciente.

Depois do deploy:

1. Reinicie o servidor no painel da hospedagem.
2. Entre no jogo e rode `/versao`, `/atualizacao`, `/saudegm`, `/selftestgm`, `/perf` e `/releasecheck`.
3. Se algo falhar, nao faca novo deploy improvisado: corrija localmente, gere novo pacote e registre no changelog.

## Logs separados

Arquivos principais em `scriptfiles/`:

- `log_admin_actions.txt`
- `log_punishments.txt`
- `log_money_bank.txt`
- `log_deaths.txt`
- `log_bugs.txt`
- `log_chat_filter.txt`
- `security_alerts.txt`
- `bans.txt`
- `bug_report_updates.txt`
- `music_playlists.txt`
- `vip_orders.txt`
- `vip_plans.txt`
- `vip_grants/`
- `job_vehicles.txt`
- `map_objects.txt`

## Painel VIP

Para subir o painel VIP local:

```powershell
cd "C:\Users\anony\Desktop\Nova GM SAMP"
$env:VIP_PANEL_TOKEN="troque-por-uma-senha-forte"
$env:VIP_PIX_KEY="sua-chave-pix"
powershell -ExecutionPolicy Bypass -File .\vip_panel\start_vip_panel.ps1
```

Player:

```text
http://127.0.0.1:8088/
```

Admin:

```text
http://127.0.0.1:8088/admin?token=troque-por-uma-senha-forte
```

O painel atual registra pedido e libera VIP por aprovacao manual apos conferir o Pix. Integracao automatica com provedor de pagamento deve ser feita por webhook externo gravando a mesma ativacao em `scriptfiles/vip_grants/Nick.txt`.

## Versao atual recomendada

```text
v1.3.0 Stable
```

Essa versao ja pode ir para sprint jogavel fechado e revisao pre-deploy de sexta-feira.
Use `/releasecheck` como gate oficial antes de abrir para players: versao, saude, self-test, performance, logs, painel staff, antiabuso e checklist de release precisam aparecer OK.
