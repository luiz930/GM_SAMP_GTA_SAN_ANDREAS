# Regras Pawn/Pawno do projeto

Este projeto usa a base classica do SA-MP 0.3 com o compilador local:

- Compilador: `pawno/pawncc.exe` 3.2.3664.
- Include principal: `pawno/include/a_samp.inc`.
- Callbacks oficiais: declaradas em `pawno/include/a_samp.inc`.
- Configuracao do Pawno: `pawno/settings.ini`, com `-r -w 203`.

## Padrao de arquivos

- Gamemodes ficam em `gamemodes/*.pwn`.
- O arquivo compilado deve ficar ao lado do `.pwn` como `gamemodes/*.amx`.
- Includes compartilhadas do projeto ficam em `include/core/*.inc`.
- Scriptfiles persistentes ficam em `scriptfiles/`.
- O changelog lido pelo comando `/atualizacao` fica em `scriptfiles/changelog.txt` e deve espelhar o `CHANGELOG.txt` da raiz.
- Textos principais do servidor ficam em `scriptfiles/server_info.txt`.
- Avisos automaticos do bot ficam em `scriptfiles/bot_messages.txt`.
- Termos bloqueados pelo bot ficam em `scriptfiles/bot_badwords.txt`.
- Radios e playlists ficam em `scriptfiles/music_playlists.txt`, uma por linha no formato `nome|url|categoria`.
- Objetos fixos e portoes do mapa ficam em `scriptfiles/map_objects.txt`.
- Relatos de bugs/problemas enviados pelos players ficam em `scriptfiles/bug_reports.txt`.
- Status, prioridade e resposta da staff sobre bugs ficam em `scriptfiles/bug_report_updates.txt`.
- Bans persistentes ficam em `scriptfiles/bans.txt`.
- Alertas de seguranca, flood e anti-cheat ficam em `scriptfiles/security_alerts.txt`.
- Controle de acesso fica em `scriptfiles/access_config.txt` e `scriptfiles/whitelist.txt`.
- Indice de contas criadas fica em `scriptfiles/account_index.txt`.
- Logs operacionais ficam em `scriptfiles/log_admin_actions.txt`, `scriptfiles/log_punishments.txt`, `scriptfiles/log_money_bank.txt`, `scriptfiles/log_deaths.txt`, `scriptfiles/log_bugs.txt`, `scriptfiles/log_chat_filter.txt` e `scriptfiles/log_vip.txt`.
- Contas locais ficam em `scriptfiles/contas/*.ini`.
- Backups automaticos da pasta `scriptfiles/` ficam em `backups/scriptfiles_*.zip`.
- Scripts de operacao ficam na raiz e em `tools/`, como `iniciar_servidor_online.bat` e `tools/backup_scriptfiles.ps1`.
- Nao usar plugins ou includes externos sem registrar a decisao aqui.
- A GM principal deve ficar pequena e orquestrar os callbacks. Sistemas ficam nos modulos core.

## Modulos core

- `include/core/utils.inc`: constantes, parsing de comandos, horario de Brasilia, server_info e helpers gerais.
- `include/core/world.inc`: banco de locais, spawn, classes e veiculos iniciais.
- `include/core/accounts.inc`: login, cadastro, conta, personagem e persistencia.
- `include/core/inventory.inc`: inventario simples por jogador e uso de itens.
- `include/core/fuel.inc`: combustivel, motor manual e suporte ao velocimetro.
- `include/core/hud.inc`: HUD por jogador e timer de atualizacao.
- `include/core/money.inc`: helpers oficiais de dinheiro e sincronizacao com HUD/salvamento.
- `include/core/bank.inc`: conta bancaria, transferencias, salario e multas.
- `include/core/properties.inc`: casas/apartamentos, compra, aluguel e spawn residencial.
- `include/core/modbot.inc`: bot de avisos, filtro de chat, mute e punicoes administrativas.
- `include/core/reports.inc`: relato de bugs/problemas por player, armazenamento em txt e leitura por staff.
- `include/core/ops.inc`: checkserver, status operacional, manutencao, whitelist, arquivos de operacao, logs staff e metricas pre-online/performance.
- `include/core/radio.inc`: radios/playlists por dialog, leitura de `music_playlists.txt`, radio veicular, som ambiente, som local staff e parada de audio.
- `include/core/security.inc`: anti-flood, bans persistentes, painel de seguranca e checagens anti-cheat basicas.
- `include/core/mapobjects.inc`: objetos fixos, portoes moveis, leitura de `map_objects.txt`, texto 3D e interacao por ENTER.
- `include/core/vip.inc`: VIP Bronze, Prata, Ouro e Diamante, expiracao, kits, beneficios, comandos admin e integracao com painel externo.
- `include/core/climate.inc`: clima randomico com perfil realista, temperatura, umidade, vento, HUD e controle staff.
- `include/core/phone.inc`: celular por dialog, apps de banco, governo, imoveis, delivery e corridas NPC.
- `include/core/chat.inc`: chat local, global, admin e anuncios.
- `include/core/jobs.inc`: empregos, selecao, rotas, veiculos de trabalho, servicos, progressao, anti-farm e recompensas rastreadas por JOB_REWARD.
- Recompensas de profissao devem passar por `Job_GiveReward` ou `Job_RegisterReward`, com motivo especifico, limite diario e log financeiro.
- Veiculos de profissoes devem ser configuraveis em `scriptfiles/job_vehicles.txt` no formato `job|model|x|y|z|angle|color1|color2|fuel|interior|virtualworld`.
- Objetos do mapa devem ser configuraveis em `scriptfiles/map_objects.txt` no formato `type|model|x|y|z|rx|ry|rz|open_x|open_y|open_z|open_rx|open_ry|open_rz|range|speed|interior|virtualworld|name|job`.
- `type=0` cria objeto fixo; `type=1` cria portao/cancela movel com texto 3D. Portoes/cancelas abrem pela buzina H em veiculo; `job=0` e publico e `job>0` exige a profissao correspondente.
- `include/core/police.inc`: ficha, procurado, multas, prisao, soltura, fianca e tempo de cela.
- `include/core/radar.inc`: radares fixos, manuais e moveis, fiscalizacao de velocidade e multas automaticas.
- Radares automaticos devem ignorar servidores publicos somente quando eles estiverem em expediente ativo; fora de expediente a multa normal continua.
- `include/core/cityhall.inc`: Prefeitura, documentos, nome RP e escolha de emprego.
- `include/core/dealership.inc`: Concessionaria, multi-veiculos, DETRAN, garagens, patio, IPVA, CRLV e guincho.
- `include/core/hospital.inc`: atendimento, morte e respawn hospitalar.
- `include/core/needs.inc`: fome, sede, avisos de sobrevivencia e conveniencias.
- `include/core/life_services.inc`: documentos, score cidadao, missoes, eventos, GovBR, primeira jornada, proximos passos, retencao, economia 2.0, servicos publicos e cidade viva.
- `include/core/admin.inc`: comandos player/admin/staff/dev, /releasecheck e checklist final da v1.0.

## Regra de compilacao

Compilar sempre depois de alterar um `.pwn`:

```powershell
.\pawno\pawncc.exe gamemodes\nova_gm.pwn -ipawno\include -iinclude -ogamemodes\nova_gm -w203
```

Uma alteracao so entra como pronta quando compila sem erros. Para teste local, `server.cfg` deve carregar `gamemode0 nova_gm 1`, que e o AMX gerado por esse comando.

## Backup e operacao online

- Para iniciar online em teste Alpha, usar `iniciar_servidor_online.bat`.
- O backup automatico deve copiar e compactar `scriptfiles/` a cada 30 minutos.
- O backup deve atualizar `scriptfiles/backup_status.txt` com nome, data e tamanho do ultimo zip.
- Manter os ultimos 48 backups por padrao, removendo arquivos antigos automaticamente.
- Para backup manual, usar `backup_agora.bat`.
- Antes de restaurar backup, fechar o `samp-server.exe`.
- Nao editar ou apagar `scriptfiles/contas/*.ini` com o servidor em uso.
- `server.cfg` deve manter `announce 1`, `chatlogging 1` e senha RCON forte.
- `/checkserver` deve ser exclusivo de admin nivel 5 e mostrar por dialog se arquivos essenciais, backups, versao e players estao ok.
- `/statusserver` deve ser liberado para staff e mostrar players, admins, bugs, contas, veiculos, radares, hora BR e uptime.
- `/painelstaff` e `/operacao` devem mostrar evento ativo, maior devedor online, empresas paradas, casos, denuncias e alertas de abuso.
- `/eventos` deve mostrar o evento dinamico ativo e os estoques baixos que afetam bonus de profissao.
- `/notificacoes`, `/passe`, `/rankingsemanal` e `/historico` devem expor retencao, objetivos ativos, rankings e conquistas pessoais pelo GovBR/celular.
- `/jornada` e `/proximopasso` devem usar a regra central da primeira jornada em `life_services.inc`, com a mesma experiencia no comando, no /central e no GovBR do celular.
- `/ajuda admin`, `/ajuda staff` e categorias de dono devem aparecer somente para quem tem permissao; comandos de dono so aparecem para DONO/RCON.
- `/ajuda profissoes` deve mostrar comandos comuns de trabalho e apenas os comandos especificos da profissao atual do jogador.
- `/manutencao on/off` deve ser exclusivo de admin nivel 5; quando ativo, apenas staff/RCON ou conta com admin salvo entra.
- `/whitelist on/off/add/rem/list` deve ser exclusivo de admin nivel 5 e usar `scriptfiles/whitelist.txt`; staff salva como admin passa mesmo fora da lista.
- Logs separados devem registrar admin actions, punicoes, dinheiro/banco, mortes, bugs e chat filtrado.

## Estilo Pawn

- Usar `#include <a_samp>` no topo.
- Usar `#pragma tabsize 4`.
- Usar ponto e virgula em todas as instrucoes.
- Usar chaves em callbacks, funcoes e blocos condicionais.
- Manter callbacks com a assinatura exata de `a_samp.inc`.
- Retornar `1` quando o evento/comando foi tratado.
- Retornar `0` em `OnPlayerCommandText` quando o comando nao existe.
- Evitar codigo pesado em `OnPlayerUpdate`.

## Nomes

- Constantes e cores: `MAIUSCULO_COM_UNDERLINE`.
- Variaveis globais: prefixo `g`, exemplo `gPlayerSpawnCount`.
- Funcoes auxiliares: verbo + assunto, exemplo `SetupPlayerForSpawn`.
- Dados por jogador sempre indexados por `playerid` e limitados por `MAX_PLAYERS`.

## Jogadores

- Resetar dados do jogador em `OnPlayerConnect` e `OnPlayerDisconnect`.
- Sempre configurar interior, virtual world e camera ao controlar spawn/classe.
- Bloquear comandos e spawn enquanto o jogador nao estiver logado.
- Dados de conta ficam centralizados em `PlayerInfo[playerid]`.
- Salvar a conta ao desconectar, quando o jogador usar `/salvar` e no autosave global.
- Autosave roda a cada 10 minutos via `AutoSaveAccounts`.
- Validar ids recebidos por comando antes de usar.
- Usar `INVALID_PLAYER_ID` e `INVALID_VEHICLE_ID` quando aplicavel.

## Conta e personagem

- Conta guarda `password_hash` e `admin`.
- Personagem guarda `character_name`, dinheiro, banco, skin, posicao, kills, mortes, spawn, tempo online, nivel geral, XP geral, documentos, emprego, veiculos salvos, multas, procurado, ferimento, plano de saude, imovel, fome e sede.
- Veiculos salvos guardam `vehicle_count`, `vehicle_active_slot` e chaves por slot como `vehicle_0_model`, placa, cor, combustivel, vida, posicao, garagem, trava, seguro, vencimento de seguro, IPVA, vencimento de IPVA, registro DETRAN e status de patio.
- O veiculo antigo em chaves simples `vehicle_model`, `vehicle_plate` etc. deve continuar migrando automaticamente para o slot 1.
- XP geral deve subir 1 ponto a cada 7 minutos online; a cada 4 pontos o personagem ganha 1 nivel.
- Progresso profissional deve salvar `job_xp`, `job_level` do emprego atual e chaves por profissao como `job_1_xp` / `job_1_level`.
- Licencas profissionais devem salvar em conta: `license_cnh`, `license_heavy`, `license_medical`, `license_oab`, `license_public` e `license_police`.
- `character_name` deve usar formato RP `Nome_Sobrenome`, apenas letras, definido por dialog depois do login/cadastro quando necessario.
- Dinheiro deve ser alterado preferencialmente por `SetPlayerCash`, `GivePlayerCash` e `TakePlayerCash`.
- Arquivos antigos em formato linha por linha ainda devem carregar.
- Ao salvar, contas devem ser gravadas em formato `chave=valor`, por exemplo:

```text
format_version=3
password_hash=...
admin=0
character_name=Nome_Sobrenome
money=500
skin=0
```

## Textos e comandos

- Comandos iniciais ficam em `OnPlayerCommandText`, sem dependencias externas.
- Mensagens devem ter cores definidas por `#define`.
- IDs de dialog devem ficar em uma faixa reservada do gamemode.
- HUD por jogador deve usar `PlayerTextDraw`, com criacao no login/spawn e destruicao no disconnect.
- Atualizacoes de HUD devem ficar em timer leve, nao em `OnPlayerUpdate`.
- Data/hora exibidas em HUD e hostname devem usar horario de Brasilia via `GetBrasiliaDateTime`.
- Nome do servidor, versao, modo e idioma devem vir de `scriptfiles/server_info.txt`.
- HUD deve mostrar nome do servidor, versao, dinheiro, data/hora, local, profissao atual, nivel, XP geral, fome e sede.
- Velocimetro deve ser exibido apenas em veiculo, com painel diferente para carro, moto e bicicleta; veiculos automotores mostram RPM.
- Comandos com argumentos usam os helpers `GetCommandName`, `GetNextParam` e `GetRemainingText`.
- Chat padrao deve ser local por distancia; chat global deve usar comando explicito.
- `/ajuda`, `/help` e `/comandos` devem abrir uma central em dialogs com todos os comandos separados por categoria, evitando listas longas no chat.
- `/atualizacao`, `/atualizacoes`, `/changelog` e `/novidades` devem abrir o changelog completo em dialog paginada, lendo `scriptfiles/changelog.txt`.
- `/versao` deve mostrar versao, AMX de release, data de deploy, server_info, changelog carregado e zona de guerra.
- `/saudegm` deve ser staff/helper e mostrar arquivos essenciais, economia, estoques, empresas, dividas e logs.
- `/releasecheck` deve ser staff/helper e mostrar os gates de v0.4, v0.5, v0.6, v0.7, v0.8, v0.9 e v1.0 com bloqueadores reais.
- `/selftestgm reparar` deve aplicar o corretor nos players online quando houver conta antiga com saldo, emprestimo, contrato, empresa, veiculo ou inventario inconsistente.
- `/antiabuso` deve misturar indicadores da sessao online com historico real de `log_money_bank.txt`, `log_contracts.txt` e `security_alerts.txt`.
- `/debugplayer [id]` deve ser admin e mostrar emprego, streak, passe, score, empresa, multas, dividas, justica e indicadores anti-abuso.
- `/menu` e `/painel` devem abrir o menu jogavel principal, permitindo executar acoes comuns por dialog sem decorar comandos.
- `/tutorial` deve abrir um tutorial guiado em dialogs e tambem aparecer uma vez no primeiro spawn da sessao.
- `/admins` deve abrir uma dialog com admins online, ID, nome e cargo, disponivel tambem pelo menu principal.
- `/radio`, `/radios` e `/musica` devem abrir uma lista por dialog com radios de `scriptfiles/music_playlists.txt`.
- `/vip`, `/comprarvip`, `/ativarvip`, `/kitvip` e `/vips` devem abrir dialogs e comandos do sistema VIP.
- `/clima` deve abrir dialog com clima atual; o HUD deve mostrar clima resumido.
- `/notificacoes`, `/passe`, `/rankingsemanal`, `/historico`, `/noticias`, `/contratarempresa`, `/aceitarcontrato`, `/recuperarempresa`, `/falencia`, `/prefeitura`, `/orcamento`, `/licitacao`, `/vistoria`, `/leilao`, `/mandado`, `/prova`, `/tornozeleira`, `/plantaomedico` e `/internacao` devem ficar documentados nas categorias certas da central de ajuda.
- `/economiacidade`, `/economiaempresas` e `/economia2` devem abrir o painel Economia 2.0 com empresas online, contratos, estoque, demanda de mercado e saude da empresa.
- Contratos empresariais devem validar limite economico, caixa/reserva, expiracao e impacto de estoque antes de pagar.
- `/jobveiculos` deve mostrar a quantidade carregada, `/addjobveiculo [job] [modelo/atual] [cor1] [cor2] [fuel]` deve criar e gravar veiculo de profissao, e `/reloadjobveiculos` deve recarregar `scriptfiles/job_vehicles.txt` sem recompilar.
- `/ajudaadmin` deve abrir uma dialog com instrucoes praticas de staff, incluindo criacao de objetos e portoes.
- `/objetosmapa` deve mostrar a quantidade carregada, `/addobjeto` deve abrir uma lista por dialog e criar objeto fixo na posicao atual do DONO/RCON, `/addportao` deve abrir uma lista por dialog, pedir a profissao dona e criar portao/cancela movel na posicao atual, `/reloadobjetos` deve recarregar `scriptfiles/map_objects.txt`, e a abertura normal deve acontecer pela buzina H no veiculo.
- Os comandos de criacao de mapa no staff nivel 5 devem capturar posicao, angulo, interior e virtual world automaticamente pelo player admin.
- `/pararradio` e `/pararmusica` devem parar o audio do jogador.
- `/radioveiculo` deve ligar uma radio para motorista e passageiros do veiculo atual; `/pararradioveiculo` deve desligar a radio do veiculo.
- `/veiculos` deve listar todos os veiculos do personagem e `/selecionarveiculo [slot]` deve trocar o veiculo ativo.
- `/garagem` deve abrir dialog de garagem publica/residencial quando o jogador estiver em ponto valido.
- `/detran` deve abrir atendimento presencial para registrar, trocar placa, pagar IPVA, transferir e emitir CRLV.
- `/documentoveiculo` ou `/crlv` deve mostrar o documento digital do veiculo ativo registrado.
- `/venderveiculo` deve vender o veiculo ativo como usado, aplicando percentual configurado.
- `/trancar` e `/destrancar` devem controlar a trava do veiculo salvo atual/proximo; sem chave, jogador nao entra nem dirige.
- `/emprestarchave [id]` e `/removerchave [id]` devem permitir chave temporaria para outro player online.
- `/consultarplaca [placa]` deve permitir que policial/staff consulte dono, modelo, CRLV, IPVA, seguro, multas e patio dos veiculos carregados.
- `/apreenderveiculo [motivo]` deve permitir que policial/staff guinche veiculo irregular ao Patio Municipal.
- `/criarblitz` deve montar cones, barreira, texto 3D e checkpoint para fiscalizacao policial em rua.
- `/blitz` deve abrir dialog de fiscalizacao perto do ponto, com consulta de placa, CNH/documentos, multa, ordem de parada e apreensao.
- `/removerblitz` deve desmontar a blitz criada pelo policial; staff nivel 2+ pode remover pelo menu se necessario.
- Som ambiente automatico deve usar `PlayAudioStreamForPlayer` posicional em boate, restaurante, loja, prefeitura, hospital e locais configurados.
- `/somlocal [id_radio] [raio]` e `/pararsomlocal` devem ser staff nivel 4+ para eventos RP com audio posicional por distancia.
- `/reloadradio` deve ser comando staff nivel 4+ para recarregar `music_playlists.txt` sem recompilar.
- Radios devem usar URL publica direta de audio/stream compativel com `PlayAudioStreamForPlayer`; Spotify, YouTube, Deezer e apps com login nao devem ser usados como link direto.
- `/bug`, `/problema`, `/relatarbug` e `/reportarbug` devem permitir que players registrem bugs/problemas por dialog ou texto direto.
- `/bugs`, `/bugreports` e `/relatos` devem permitir que staff leia os relatos salvos em `scriptfiles/bug_reports.txt` por dialog.
- `/checkserver`, `/statusserver`, `/manutencao` e `/whitelist` devem ficar documentados no painel de ajuda staff.
- `/seguranca` deve abrir painel staff com bans, alertas, punicoes, logs recentes e suspeitas online.
- `/ban`, `/unban` e `/banidos` devem salvar/ler `scriptfiles/bans.txt`, bloquear entrada em `OnPlayerConnect` e registrar em `log_punishments.txt`.
- Anti-flood deve bloquear spam de chat, spam de comandos e aplicar cooldown em comandos sensiveis como `/bug`, `/gps`, `/celular`, `/menu`, `/ajuda`, `/detran`, `/garagem` e dialogs utilitarios.
- Anti-cheat basico deve monitorar dinheiro fora dos helpers oficiais, armas nao permitidas, vida/colete anormal e teleportes bruscos fora de spawn, interior ou acao admin.
- Triagem de bugs deve permitir prioridade, resposta da staff, marcar como resolvido e reabrir relato por comandos staff.

## Locais e GPS

- Locais centrais ficam em `gServerLocations` dentro de `include/core/world.inc`.
- `/gps` abre lista de locais importantes e cria checkpoint.
- `/interagir` ou a tecla de interacao perto do local executa a acao do local.
- Icones do mapa devem ser criados por jogador com `SetupPlayerMapIcons`.
- Pontos interativos devem ter texto 3D global dizendo para apertar ENTER ou usar `/interagir`.
- O raio de interacao deve variar por categoria: publico, negocio, emprego e campo/producao.
- Locais de atendimento devem ter entrada automatica em interior ao aproximar da porta, saida automatica ao aproximar da saida e balcao interno com texto 3D.
- Raios de entrada e acao de interiores devem ficar curtos para evitar teleportar o jogador longe da porta.
- Servicos civis essenciais devem ser autonomos por NPC/dialog: restaurante, loja/conveniencia, hospital, prefeitura, concessionaria, banco/posto/oficina e recepcao da delegacia nao podem depender de player online.
- Postos de combustivel ficam como `LOCATION_POSTO_*`, aparecem no GPS/mapa com icone de combustivel e permitem abastecimento NPC por ENTER ou `/abastecer`.
- Transporte basico tambem deve ter alternativa NPC: `/taxinpc`, `/onibusnpc` ou `/transporte` em pontos de taxi/terminal; guincho NPC usa `/guincho` para resgatar veiculo salvo.
- Caixas eletronicos devem aparecer com icone de dinheiro no mapa e abrir atendimento bancario por ENTER, `/interagir` ou `/caixa`.
- DETRAN, Garagem Publica e Patio Municipal devem existir como pontos fisicos no mapa, com texto 3D e acesso por ENTER ou `/interagir`.
- Garagem publica/residencial deve guardar e retirar veiculos por dialog; limite depende de nivel e vagas do imovel comprado/alugado.
- Garagem residencial deve abrir apenas perto da casa/apartamento do morador ou inquilino, e veiculos guardados em casa devem lembrar o imovel de origem.
- Patio Municipal deve ter atendimento NPC para retirar veiculo apreendido/destruido mediante taxa, multas pendentes e IPVA pendente.
- Profissoes de player nesses locais devem servir para rotas, XP, bonus, RP avancado, estoque, chamados e atendimento especializado, nao para bloquear a sobrevivencia ou compras basicas.
- Interiores de servico devem usar perfis especificos por tipo de profissao/local, evitando uma sala generica para todos e evitando coordenadas conhecidas de casa quando o local for hospital, delegacia, prefeitura, restaurante ou atendimento publico.
- Ambientes internos podem ter pontos 3D extras como recepcao, estoque, garagem, cela, cozinha, triagem, guiche, arquivo e vestiario.
- Pontos internos devem ser acionaveis por ENTER ou `/interagir`; `world.inc` detecta o ponto e `jobs.inc` executa a acao quando ela depende de conta, profissao, dinheiro, XP ou saude.
- Pontos internos com pagamento/XP devem ter cooldown para evitar farm.
- Conveniencias devem vender itens de comida/bebida por dialog e guardar no inventario; restaurantes devem vender refeicoes por NPC e recuperar fome/sede na hora.
- Checkpoints de emprego podem bloquear o GPS ate a rota atual terminar ou ser cancelada.

## Fome e sede

- Fome e sede ficam em `PlayerInfo[playerid][pHunger]` e `PlayerInfo[playerid][pThirst]`, salvas como `hunger` e `thirst`.
- O timer `Needs_UpdateAll` reduz fome/sede enquanto o jogador esta logado.
- Abaixo do limite baixo, o jogador recebe aviso em tela e mensagem no chat.
- Em fome ou sede critica, a vida cai; se o jogador nao comer/beber, ele morre e renasce no hospital.

## Banco e celular

- Banco fisico fica no `LOCATION_BANCO`; abertura/fechamento de conta e emprestimos exigem atendimento do gerente no Banco Central.
- Conta bancaria salva `bank_account`, `bank_card`, `bank_loan` e `bank`.
- Jogadores sem conta bancaria podem pagar compras com dinheiro em maos, mas nao podem usar saldo bancario, PIX, salario ou emprestimo.
- Todo pagamento centralizado em `Bank_TakePayment` deve reconciliar carteira nativa do SA-MP com `PlayerInfo[pMoney]`, validar o total disponivel antes do debito e registrar quanto saiu da carteira e quanto saiu do banco.
- Emprestimos devem salvar contrato completo: valor original, saldo restante, parcela, quantidade de parcelas, parcelas pagas e proxima cobranca.
- Juros de emprestimo devem considerar score, emprego, historico e risco do valor solicitado; pagamento de parcela deve reduzir a divida real e quitar antecipado pode aplicar desconto se o contrato estiver em dia.
- Deposito e saque exigem caixa eletronico ou Banco Central; PIX pode ser usado pelo banco/celular quando a conta estiver aberta.
- Cartao virtual deve ser emitido pelo banco/caixa/app e salvo em conta.
- O celular abre por `/celular`, `/phone` ou `/app` e deve concentrar apps digitais: banco, GovBR, imoveis, delivery e Uber/99 NPC.
- O GovBR Online deve permitir consultar e pagar multas pendentes, incluindo multas aplicadas por radar.
- Multa, boleto, imposto, servico e compra nao podem registrar sucesso se carteira + banco disponivel for menor que o valor cobrado.
- O GovBR Online tambem deve permitir consultar/pagar IPVA, ver documento/situacao do veiculo e pedir guincho NPC.
- O GovBR Online tambem deve exibir notificacoes, passe da cidade, ranking semanal, historico pessoal, noticias automaticas, orcamento da prefeitura e licitacao publica.
- Delivery por celular pode entregar comida/bebida automaticamente, cobrando taxa e atualizando fome/sede/inventario.
- Uber/99 pelo celular deve cobrar corrida NPC e teleportar para locais importantes, bloqueando uso durante expediente ou dentro de veiculo.

## Retencao e economia 2.0

- Login deve aplicar recompensa diaria, recompensa semanal, sequencia de login, medalhas e avisos GovBR sem depender de comando manual.
- Passe da cidade deve ter objetivos por profissao, economia e servico publico; ao completar a rodada semanal, o jogador recebe recompensa e conquista.
- Ranking semanal deve considerar trabalhadores, empresas, policiais e cidadaos com pontuacao salva por jogador e reinicio por semana.
- Empresas devem ter estoque real, contratos, funcionarios, divida, pedido automatico quando paradas, falencia e recuperacao judicial.
- Precos de venda/servico devem variar conforme falta ou excesso de estoque, evitando uma economia fixa demais.
- Contratos entre empresas e jogadores devem registrar oferta, aceite, pagamento, estoque/contrato e score economico.

## Cidade viva

- DETRAN deve cobrir IPVA, seguro, vistoria, guincho, leilao e recuperacao de veiculo apreendido.
- Hospital/SAMU deve ter plantao, remedios, internacao leve e plano de saude.
- Policia/justica deve cobrir mandado, prova, pericia, prisao, fianca e tornozeleira.
- Prefeitura deve cobrir impostos, licitacoes, cargos publicos e orcamento visivel.
- Noticias automaticas devem avisar situacoes como mercado sem estoque, blitz ativa, hospital cheio, empresa em divida e bonus ativo.
- Zona de guerra em Mulholland deve abrir todos os dias as 15:00 e 22:00 BRT por 30 minutos, aparecer em vermelho no mapa e liberar kill sem prisao somente dentro da janela ativa; fora dela, kill no local prende automaticamente.

## Radares e multas

- Radares rodam em timer leve `Radar_UpdateAll`, nunca em `OnPlayerUpdate`.
- Radares fixos ficam em avenidas principais e têm limite definido pela via.
- Radares manuais sao criados por admin DONO com `/addradar [limite] [rua_id]`, usando a posicao atual do admin, e salvos em `scriptfiles/radares.txt`.
- Admin DONO pode usar `/ruasradar` para ver IDs de ruas e `/radares` para listar radares ativos.
- Radares moveis sao sorteados por algoritmo e reposicionados periodicamente; o algoritmo nao deve colocar mais de dois radares na mesma rua em raio de 500 metros.
- Multas de radar somam em `PlayerInfo[playerid][pFines]`, sao salvas na conta e podem ser pagas pelo banco, `/pagarmultas` ou GovBR no celular.
- Radares devem ignorar interiores, virtual worlds diferentes, passageiros e bicicletas; apenas motorista de veiculo motorizado pode ser multado.

## Empregos

- Empregos disponiveis ficam em `gJobs` dentro de `include/core/jobs.inc`.
- Todo emprego precisa ter nome, descricao, local, pagamento, bonus e rota de tarefas.
- A Prefeitura deve abrir a lista completa de empregos por dialog.
- O jogador precisa ter documentos emitidos para aceitar emprego.
- Empregos podem exigir licencas, aprovacao ou cargo publico antes de bater ponto.
- Tarefas devem dar XP, nivel deve aumentar pagamento e o nivel maximo atual e 10.
- Bater ponto deve aplicar uniforme e entregar equipamento quando a profissao exigir.
- Cancelar ou perder expediente em andamento pode aplicar penalidade financeira.
- Comandos principais: `/emprego`, `/trabalhar`, `/baterponto`, `/plantao`, `/servico`, `/cancelartrabalho` e `/demitir`.
- Servicos especializados atuais: `/curar`, `/saude`, `/plano`, `/repararcarro`, `/pintarcarro`, `/abastecer`, `/oficina`, `/taximetro`, `/multa`, `/multar`, `/prender` e `/soltar`.
- `/abastecer` deve funcionar como trabalho de frentista quando o player for frentista e como atendimento NPC pago quando for civil.
- `/oficina` deve reparar veiculo por atendimento NPC pago, enquanto mecanicos mantem `/repararcarro` e servicos de profissao.
- Comandos dev que teleportam ou alteram veiculo, como `/spawn` e `/reparar`, devem exigir staff/helper.
- Multas devem ser salvas em `fines` e pagas por `/pagarmultas`; nao devem depender do alvo ter dinheiro na carteira no momento da abordagem.
- `/prender` deve conduzir o suspeito para a cela interna da Delegacia; `/soltar` libera da custodia.
- Staff pode conceder licencas por `/aprovarprof [id] [cnh|pesada|medico|oab|publico|policial]`.
- Enquanto estiver em expediente, o jogador deve concluir ou cancelar o trabalho antes de usar outro GPS.

## Veiculos salvos

- `/veiculo` mostra modelo, placa, seguro, garagem, patio, combustivel, vida e IPVA.
- `/meuveiculo` spawna o veiculo salvo se ele nao estiver no patio.
- `/estacionar` salva a posicao atual do veiculo.
- `/guardarveiculo` guarda o veiculo na garagem, salva posicao/vida/combustivel e remove o veiculo do mundo.
- `/guincho` traz o veiculo salvo por atendimento NPC, mas nao recupera veiculo que esta no patio.
- `/patio` recupera veiculo destruido/apreendido mediante taxa; seguro reduz o custo.
- `/seguroveiculo` contrata seguro do veiculo.
- `/ipva` consulta imposto pendente e `/pagaripva` quita usando dinheiro/banco.
- IPVA quitado e seguro devem ter vencimento em dias configurados; CRLV fica irregular quando o veiculo nao esta registrado ou possui IPVA pendente.
- `/trancar` e `/destrancar` protegem o veiculo; `/emprestarchave` libera permissao temporaria para outro player online.
- `/consultarplaca` e `/apreenderveiculo` integram policia, blitz, patio, multas e documentos.
- Blitz policial deve usar objetos SA-MP simples, sem plugin externo, e deve ser acionavel por ENTER ou `/blitz`.
- Dialog de blitz deve permitir consulta de placa do veiculo proximo, CNH/documentos do motorista, multa por motivo e guincho ao Patio Municipal.
- Ao destruir um veiculo salvo, ele deve ir para o patio, salvar estado e exigir recuperacao.

## Administracao

- RCON admin sempre passa na checagem de permissao.
- Admin salvo em conta usa `PlayerInfo[playerid][pAdminLevel]`.
- Niveis atuais: 1 Helper Nivel 1, 2 Helper Nivel 2, 3 Administrador Nivel 1, 4 Administrador Nivel 2, 5 DONO.
- `/setadmin` exige RCON ou nivel 5.
- `/admin` deve abrir o painel staff por dialog; nivel 5 DONO deve enxergar todas as acoes disponiveis.
- A central `/ajuda` nao deve vazar comandos de staff/dono para jogador comum; cada nivel enxerga somente comandos liberados para o proprio nivel.
- Comandos nivel 1: `/a`, `/admins`, `/bugs`, `/statusserver`, `/seguranca`, `/banidos`, `/avisar`, `/mutar`, `/desmutar`, `/kick`, `/spawn`, `/reparar`, `/savepos`.
- Comandos nivel 2: `/goto`, `/gethere`, `/setskin`, `/veh`, `/dv`, `/congelar`, `/descongelar`.
- Comandos nivel 3: `/punir`, `/despunir`, `/ban`, `/unban`, `/dargrana`, `/aprovarprof`, `/sethora`, `/setclima`.
- Comandos nivel 5 VIP: `/setvip`, `/tirarvip`, `/reloadvip`, alem do painel staff por dialog.
- Comandos nivel 4: `/setvida`, `/setcolete`, `/tapa`, `/limparchat`, `/reloadbot`, `/reloadradio`, `/somlocal`, `/pararsomlocal`.
- Comandos nivel 5 DONO: `/setadmin`, `/checkserver`, `/manutencao`, `/whitelist`, `/ruasradar`, `/radares`, `/addradar`, `/objetosmapa`, `/addobjeto`, `/addportao`, `/delobjeto`, `/delportao`, `/jobveiculos`, `/addjobveiculo`, `/deljobveiculo`, `/reloadobjetos`, `/reloadjobveiculos` e todos os comandos inferiores.
- Exclusoes de objetos, portoes e veiculos de profissao devem passar por dialog de confirmacao/lista e atualizar o respectivo TXT antes de recarregar o sistema.
- `/punir` prende em punicao administrativa sem fianca, para anti-RPG e condutas incompativeis com RP.
- O bot deve enviar um aviso configurado em `bot_messages.txt` a cada 2 minutos, cobrindo sistemas, locais, empregos, regras, /ajuda e /admins.
- O bot deve monitorar chat por termos em `bot_badwords.txt`, bloquear mensagens ruins, avisar staff e aplicar mute/punicao progressiva.

## Server.cfg

- O `server.cfg` local deve apontar para a GM recem-compilada:

```text
gamemode0 nova_gm 1
```

- O pacote de hospedagem pode sobrescrever a copia de `server.cfg` para o alias versionado, por exemplo `gamemode0 nova_gm_1001 1`, somente dentro de `deploy/` e no FTP de sexta-feira.

- Filterscripts ficam vazios enquanto a GM estiver sendo feita do zero.
- O hostname, modo e idioma sao sobrescritos pela GM usando os valores de `scriptfiles/server_info.txt`.
- Formato atual do arquivo:

```text
server_name=Life Simulator BR
server_version=v0.6.0 Alpha
gamemode_text=Life Simulator 0.6.0
server_language=Portuguese
```

## Deploy automatico

- `tools/build_deploy_check.ps1` deve compilar, copiar changelog, montar pacote com alias, gerar SHA256 e manifesto.
- Durante a semana, usar o script sem `-Deploy` para build local e pacote em `deploy/`; nao subir FTP fora da janela combinada. O script bloqueia `-Deploy` fora de sexta-feira, salvo `-ForceDeploy` em emergencia.
- Toda sexta-feira, antes do deploy remoto, atualizar `GM_TEXT`, `GM_VERSION`, `GM_DEPLOY_DATE`, `scriptfiles/server_info.txt` e o topo do `CHANGELOG.txt`.
- Quando chamado com `-Deploy`, deve usar FTP, fazer backup remoto local, enviar AMX/server.cfg/scriptfiles e verificar tamanho do AMX remoto, alias no `server.cfg`, versao no `server_info.txt`, changelog carregado e `release_plan.txt`.
- Credenciais FTP devem vir por parametros ou variaveis `SAMP_FTP_USER` e `SAMP_FTP_PASS`; nao gravar senha em arquivo versionado.

## Painel VIP externo

- O painel fica em `vip_panel/server.js` e nao usa dependencias npm.
- Para iniciar localmente, usar `vip_panel/start_vip_panel.ps1`.
- O token admin deve vir de `VIP_PANEL_TOKEN`; nao usar o valor padrao em producao.
- A chave Pix exibida ao player deve vir de `VIP_PIX_KEY`.
- Pedidos ficam em `scriptfiles/vip_orders.txt`.
- Ativacoes aprovadas ficam em `scriptfiles/vip_grants/Nick.txt` no formato `level|days|orderId|painel_vip`.
- A GM aplica ativacoes ao logar, ao usar `/ativarvip` ou pelo timer do sistema VIP.
