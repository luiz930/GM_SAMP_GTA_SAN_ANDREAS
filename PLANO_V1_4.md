# Plano v1.4 - Retencao e vida urbana 2.0

## Status de partida

- Base fechada: `v1.3.0 Stable`; ciclo atual: `v1.4.0 Stable`.
- Pacote local de referencia 1.3: `deploy/nova_gm_samp_v1.3.0_Stable_hosting_alias_2026-05-23_22-57-00.zip`.
- Pacote local atual 1.4: `deploy/nova_gm_samp_v1.4.0_Stable_hosting_alias_2026-05-23_23-53-05.zip`.
- Gate 1.4 atual: `LIBERADO` em 2026-05-23 23:53 BRT.
- Deploy remoto: pendente para janela autorizada de sexta-feira as 19:00 BRT.

## Objetivo do pacote

Fazer o jogador ter motivos claros para voltar todos os dias sem quebrar a base atual: jornada diaria, metas semanais, eventos urbanos leves e progresso visivel pelo celular/GovBR.

## Escopo recomendado

1. Jornada diaria 2.0
   - Lista curta de objetivos por perfil: trabalhador, empresario, policial, criminoso RP, servidor publico e novato.
   - Recompensa por concluir objetivos sem permitir farm repetitivo.
   - Resumo no celular/GovBR e comando rapido.
   - Status: iniciado com `/jornadadiaria`, perfil automatico e botao de acao reaproveitando missoes civis existentes.

2. Agenda semanal
   - Metas semanais por emprego principal.
   - Bonus leve por variar atividades em vez de repetir uma rota.
   - Ranking semanal reaproveitando os rankings ja existentes.
   - Status: iniciado com `/agendasemanal`, metas por categoria de ranking e botao de acao por perfil.

3. Eventos por bairro
   - Eventos de baixa manutencao: falta de energia, blitz, demanda de taxi, pico de entregas, chamado mecanico e campanha da prefeitura.
   - Usar arquivos existentes em `scriptfiles` para estado e logs.
   - Status: iniciado com `/bairros`, metas leves por regiao derivadas do evento urbano ativo, GPS de acao e GovBR/celular.

4. Progresso urbano
   - Tela de progresso com reputacao por area: trabalho, civico, seguranca, economia e comunidade.
   - Integrar com comandos atuais como `/progressao`, `/jornada`, `/proximopasso`, `/eventos` e GovBR.
   - Status: iniciado com `/progressourbano`, leitura por area em cima dos contadores existentes e botao de acao para o menor indicador.

## Fora do escopo inicial

- Nova economia paralela.
- Mudanca de alias remoto.
- Deploy FTP fora da janela autorizada.
- Sistemas grandes de faccao/territorio antes de estabilizar as rotinas diarias.

## Gates obrigatorios

- `powershell -NoProfile -ExecutionPolicy Bypass -File .\tools\static_gm_audit.ps1`
- `powershell -NoProfile -ExecutionPolicy Bypass -File .\tools\pre_deploy_gate.ps1`
- Boot local com `gamemode0 nova_gm 1`.
- `tools\check_post_restart.ps1` sem erro.

## Fechamento Stable local

- Status: v1.4.0 Stable fechado localmente, sem FTP.
- Escopo consolidado: Jornada diaria 2.0, Agenda semanal 2.0, Eventos por
  bairro 2.0 e Progresso urbano 2.0.
- Proxima etapa operacional: publicar na janela autorizada de sexta-feira as
  19:00 BRT, com manifesto e verificacao pos-restart remota.
