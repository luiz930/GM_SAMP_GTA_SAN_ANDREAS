# Sprint de teste jogavel - v1.4.0

Data local: 2026-05-23
GM: v1.4.0 Stable
Alias: nova_gm_1003

## Validacao automatica

- [x] Compilar GM com `tools/build_deploy_check.ps1`.
- [x] Gerar pacote de deploy local sem FTP.
- [x] Rodar `tools/boot_test_server.ps1` por tempo controlado.
- [x] Conferir `server_log.txt` sem runtime error, crash ou falha de AMX.
- [x] Rodar `tools/check_post_restart.ps1`.
- [x] Rotacionar senha RCON local em `server.cfg`.
- [x] Entregador 2.0 base compilado: rotas curta/media/longa, prazo, falha por atraso, bonus e XP.
- [x] Entregador 2.0 completo compilado: pacote, coleta, endereco errado, avaliacao, estoque e ranking.
- [x] Boot test OK apos Entregador 2.0.
- [x] Blindagem 2026-05-22: `server_info.txt` sincronizado com `GM_VERSION` e `GM_TEXT`.
- [x] Blindagem 2026-05-22: `server.cfg` local alinhado para `gamemode0 nova_gm 1`.
- [x] Blindagem 2026-05-22: pacote preserva alias `gamemode0 nova_gm_1003 1`.
- [x] Blindagem 2026-05-22: `build_deploy_check.ps1` valida `game_config.txt`, `job_vehicles.txt`, `map_objects.txt`, `radares.txt`, `properties`, `bans`, `whitelist` e `command_hotfixes.txt`.
- [x] Boot test final 2026-05-22 OK com `gamemode0 nova_gm 1` e `maxnpc 8`.
- [x] Check pos-restart final 2026-05-22 OK.
- [x] Gate final 2026-05-22 18:22 BRT: `LIBERADO` com auditoria estatica, build, boot test, check pos-restart, hashes, `server.cfg`, `server_info.txt`, `crashinfo.txt` e `server_log.txt`.
- [x] Sistema criminal RP 2026-05-22 incluido no pacote: faccoes ficticias, itens ilegais abstratos, campo rural, laboratorio, venda de risco, roubo de ATM/banco/veiculo e ataque RP controlado com wanted, alerta policial, cooldown, limite por hora e log.
- [x] Sistema criminal RP 2026-05-22 ampliado: `/crimemissoes`, `/crimepontos`, `/crimeinfo`, `/comprarsementeilegal`, `/lavardinheiro`, `/denunciarcrime`, `/apreendercrime`, `/roubarloja` e `/roubarcarga`, com rank automatico por respeito.
- [x] Deploy FTP semanal marcado para sexta-feira as 19:00 BRT.
- [x] Deploy FTP 2026-05-22 19:27 BRT: `FTP deploy: OK`, AMX remoto conferido com 4253425 bytes e `check_post_restart.ps1 -Remote` OK.
- [x] Hotfix 2026-05-22 20:17 BRT: comandos policiais em rota direta protegida; `/revistar`, `/ficha`, `/prender`, `/crimes`, `/procurados`, `/crimeinfo` e `/apreendercrime` entraram em `critical_commands.txt`; FTP emergencial OK e `check_post_restart.ps1 -Remote` OK.
- [x] Revisao completa comandos 2026-05-22 20:28 BRT: auditoria agora bloqueia comando policial/criminal sem rota direta, exige comandos criticos no `/testarcomandos`, conferiu 693 handlers, 40 comandos policiais diretos, 21 criminais diretos e 262 comandos expostos em ajuda/menu.

## Pacote final 2026-05-22

- ZIP: `deploy/nova_gm_samp_v1.3.0_Stable_hosting_alias_2026-05-22_20-24-21.zip`
- AMX SHA256: `5CE04FDDB9841D30D843814C4936DCFCF1BAB03E8EF97DF46572DBC1066F30A8`
- ZIP SHA256: `8D5B051C6FF0A07FB8F1E4286E6CFDECB664AEA4C8ACF25A61F66334FB23E4EA`
- Manifesto: `deploy/nova_gm_samp_v1.3.0_Stable_hosting_alias_2026-05-22_20-24-21/deploy_manifest.txt`
- Rollback manifesto: `deploy/nova_gm_samp_v1.3.0_Stable_hosting_alias_2026-05-22_20-24-21/rollback_manifest.txt`
- Rollback: `tools/rollback_ultimo_deploy.ps1`
- `crashinfo.txt`: vazio apos boot final.

## Fechamento local 2026-05-23

- [x] Gate final 2026-05-23 22:57 BRT: `LIBERADO` com auditoria estatica, build, deep audit, boot test, check pos-restart, hashes, `server.cfg`, `server_info.txt`, `crashinfo.txt` e `server_log.txt`.
- [x] AMX antigos da GM arquivados fora de `gamemodes`: `backups/obsolete_amx/nova_gm (1).amx` e `backups/obsolete_amx/nova_gm_1001.amx`.
- [x] Deep audit repetido apos limpeza: `DEEP_AUDIT_OK`, sem avisos de AMX antigo no diretorio ativo.

## Pacote final local 2026-05-23

- ZIP: `deploy/nova_gm_samp_v1.3.0_Stable_hosting_alias_2026-05-23_22-57-00.zip`
- AMX SHA256: `2077864F2D7B77D7AEDC9EBAA73F588C08BCE9F91D874775361BE08115ABCDA2`
- ZIP SHA256: `74FAC7B1B5EE168576230BB0F262753954E7776C288A081906950708D566ED88`
- Manifesto: `deploy/nova_gm_samp_v1.3.0_Stable_hosting_alias_2026-05-23_22-57-00/deploy_manifest.txt`
- Checklist final: `deploy/nova_gm_samp_v1.3.0_Stable_hosting_alias_2026-05-23_22-57-00/CHECKLIST_FINAL_PAINEL.txt`
- Deploy FTP: nao executado neste fechamento local; mantida a regra de sexta-feira as 19:00 BRT.

## Proximo pacote v1.4

- Tema recomendado: Retencao e vida urbana 2.0.
- Objetivo: transformar a base estavel do 1.3 em rotina diaria de jogador, com metas semanais, progresso visivel, eventos leves por bairro e integracao com GovBR/celular sem criar sistemas paralelos.
- Gate de entrada: qualquer mudanca do 1.4 deve passar por `tools/pre_deploy_gate.ps1` antes de virar pacote.
- [x] Inicio local 2026-05-23: `v1.4.0 Dev` com Jornada diaria 2.0 em `/jornadadiaria`, GovBR/celular e menus.
- [x] Gate 1.4 inicial 2026-05-23 23:08 BRT: `LIBERADO` com build, deep audit, boot test, check pos-restart, hashes e integridade.
- [x] Agenda semanal 2.0 iniciada: `/agendasemanal`, GovBR/celular, menus, metas por profissao e ligacao com `/rankingsemanal`.
- [x] Gate 1.4 com Agenda semanal 2026-05-23 23:17 BRT: `LIBERADO` com build, deep audit, boot test, check pos-restart, hashes e integridade.
- [x] Eventos por bairro 2.0 iniciado: `/bairros`, GovBR/celular, menus, meta leve por regiao, GPS e reuso dos eventos urbanos atuais.
- [x] Gate 1.4 com Eventos por bairro 2026-05-23 23:28 BRT: `LIBERADO` com build, deep audit, boot test, check pos-restart, hashes e integridade.
- [x] Progresso urbano 2.0 iniciado: `/progressourbano`, GovBR/celular, menus, reputacao por Trabalho, Economia, Seguranca, Civico e Comunidade.
- [x] Gate 1.4 com Progresso urbano 2026-05-23 23:47 BRT: `LIBERADO` com build, deep audit, boot test, check pos-restart, hashes e integridade.
- [x] Fechamento Stable local iniciado: `v1.4.0 Stable`, mantendo `LS RPG 1.4.0` e alias `nova_gm_1003`.
- [x] Gate final 1.4 Stable 2026-05-23 23:53 BRT: `LIBERADO` com auditoria estatica, build, deep audit, boot test, check pos-restart, hashes, `server.cfg`, `server_info.txt`, `crashinfo.txt` e `server_log.txt`.
- ZIP 1.4 atual: `deploy/nova_gm_samp_v1.4.0_Stable_hosting_alias_2026-05-23_23-53-05.zip`
- AMX SHA256: `8A6675986865B9C4F428CC7AA9D2B9577FA86CBCBC34BB3075EDFEFB66C4F9A2`
- ZIP SHA256: `12BE049F118BDF50961F18B9F044DC1BD89A1FEE2849406D077D39CD0741D76F`
- Manifesto: `deploy/nova_gm_samp_v1.4.0_Stable_hosting_alias_2026-05-23_23-53-05/deploy_manifest.txt`

## Entrada no servidor

- [ ] Abrir SA-MP local em `127.0.0.1:7777`.
- [ ] Criar ou entrar em conta comum.
- [ ] Validar login, spawn e tutorial inicial.
- [ ] Confirmar HUD ativo sem textos sobrepostos.
- [ ] Rodar `/versao`.
- [ ] Rodar `/saudegm`.
- [ ] Rodar `/selftestgm`.
- [ ] Rodar `/releasecheck`.

## Fluxo de jogador comum

- [ ] Abrir `/menu`.
- [ ] Usar `/inicio` ou `/proximopasso`.
- [ ] Emitir documentos na Prefeitura.
- [ ] Criar conta bancaria.
- [ ] Conferir `/saldo`, `/extrato`, `/boletos` e `/pagarmultas`.
- [ ] Pegar primeiro emprego.
- [ ] Fazer pelo menos um servico pago.
- [ ] Conferir progresso em `/progressao`.
- [ ] Comprar ou usar veiculo inicial.
- [ ] Conferir combustivel, trava, garagem e DETRAN.
- [ ] Abrir GovBR pelo celular.
- [ ] Conferir notificacoes, jornada, documentos, multas e proximo passo.

## Empregos principais

- [ ] Entregador: iniciar rota, concluir entrega e receber recompensa.
- [ ] Entregador: conferir se a mensagem mostra rota curta/media/longa e prazo.
- [ ] Entregador: conferir tipo de pacote comum/fragil/refrigerado/urgente/documento.
- [ ] Entregador: confirmar primeira parada de coleta na Central.
- [ ] Entregador: testar rota cancelada/interrompida.
- [ ] Entregador: testar atraso ate o prazo expirar e confirmar perda da sequencia.
- [ ] Entregador: concluir entrega e conferir avaliacao do cliente.
- [ ] Entregador: abrir /rankingentregas depois de concluir pelo menos uma rota.
- [ ] Taxista: aceitar corrida, levar passageiro e receber.
- [ ] Taxista: conferir corrida curta/media/longa e tipo de passageiro.
- [ ] Taxista: conferir bonus de passageiro e avaliacao final.
- [ ] Taxista: testar falha por abandono/distancia.
- [ ] Taxista: testar cancelamento por batidas com passageiro apressado/alterado.
- [ ] Taxista: abrir /rankingtaxi depois de concluir pelo menos uma corrida.
- [ ] Mecanico: atender chamado, reparar veiculo e receber.
- [ ] Mecanico: conferir chamado curto/medio/longo, diagnostico e orcamento.
- [ ] Mecanico: conferir pecas usadas e avaliacao final.
- [ ] Mecanico: testar guincho/patio se aplicavel.
- [ ] Mecanico: abrir /rankingmecanico depois de concluir pelo menos um chamado.

## Moradia

- [ ] Comprar casa/apartamento disponivel.
- [ ] Testar aluguel.
- [ ] Testar spawn na residencia.
- [ ] Testar bau.
- [ ] Testar garagem residencial.
- [ ] Testar imposto mensal ou pendencia vinculada.

## Policia, justica e hospital

- [ ] Criar BO com descricao.
- [ ] Registrar prova/pericia quando aplicavel.
- [ ] Emitir mandado com lastro.
- [ ] Consultar ficha criminal.
- [ ] Testar prisao e soltura.
- [ ] Testar fianca ou audiencia se disponivel.
- [ ] Testar ferimento, atendimento hospitalar e prontuario.
- [ ] Testar chamado 190/192/193.

## Operacao final

- [ ] Conferir `server_log.txt` depois do teste manual.
- [x] Conferir `crashinfo.txt` vazio ou sem crash novo.
- [ ] Revisar bugs reportados em `/bugs`.
- [x] Atualizar `CHANGELOG.txt` se algum ajuste for feito.
- [x] Gerar novo pacote com `tools/build_deploy_check.ps1`.
