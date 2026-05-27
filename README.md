<div align="center">

# Life Simulator BR

### Gamemode SA-MP modular com economia viva, administracao avancada e integracao web

![SA-MP](https://img.shields.io/badge/SA--MP-0.3.7-blue?style=for-the-badge)
![Pawn](https://img.shields.io/badge/Pawn-Gamemode-orange?style=for-the-badge)
![Node.js](https://img.shields.io/badge/Node.js-Community%20Panel-339933?style=for-the-badge&logo=node.js&logoColor=white)
![PowerShell](https://img.shields.io/badge/PowerShell-Automation-5391FE?style=for-the-badge&logo=powershell&logoColor=white)
![Status](https://img.shields.io/badge/status-v1.5.0%20Stable-success?style=for-the-badge)
![Portfolio](https://img.shields.io/badge/type-Portfolio%20Project-111827?style=for-the-badge)

</div>

---

## Visao Geral

**Life Simulator BR** e um servidor/gamemode SA-MP desenvolvido em Pawn, com foco em roleplay brasileiro, simulacao urbana, economia persistente, administracao operacional e ferramentas de comunidade.

O projeto foi estruturado como uma base modular: o gamemode principal atua como orquestrador e os sistemas de jogo ficam separados em includes por dominio, facilitando manutencao, evolucao e auditoria. Alem do servidor SA-MP, o projeto inclui um painel web em Node.js para comunidade, forum, denuncias e fluxo VIP.

> Este repositorio e uma versao de portfolio. Arquivos sensiveis, dados reais de runtime, credenciais, backups e artefatos compilados devem permanecer fora do Git.

---

## Destaques Tecnicos

| Area | Descricao |
| --- | --- |
| Arquitetura modular | Gamemode principal em `gamemodes/nova_gm.pwn` com sistemas separados em `include/core/*.inc`. |
| Persistencia local | Dados operacionais em `scriptfiles/`, seguindo o padrao SA-MP de arquivos texto. |
| Economia viva | Banco, multas, boletos, empresas, salarios, impostos, credito, estoque e reputacao empresarial. |
| Profissoes e progressao | Mais de 50 rotas/carreiras com XP, cooldowns, requisitos, bonus e protecoes anti-farm. |
| Administracao | Staff tools, logs, manutencao, whitelist, bans, auditoria, self-heal e release checks. |
| Seguranca operacional | Gate de integridade, diagnosticos, comandos de saude da GM e scripts de pre-deploy. |
| Comunidade web | Painel externo com forum, denuncias, contas, administracao e pedidos VIP. |
| Automacao | Scripts PowerShell para build, auditoria, backup, empacotamento e verificacao pos-restart. |

---

## Features Principais

### Gameplay e RP

- Sistema de contas, login, cadastro e salvamento persistente.
- Economia com carteira, banco, transferencias, emprestimos, multas e boletos.
- Sistema de empregos com rotas, tarefas, XP, bonus e requisitos.
- Veiculos com garagem, documentos, IPVA, seguro, chaves, patio e leilao.
- Propriedades, casas, hoteis, empresas e interiores.
- Sistemas de fome, sede, hospital, plano de saude e respawn controlado.
- Celular/GovBR com servicos, notificacoes, ranking, historico e progresso urbano.
- Eventos de cidade, zona de guerra, clima, radio e interacoes urbanas.

### Administracao e Operacao

- Hierarquia administrativa com comandos por permissao.
- Painel staff in-game para saude do servidor, logs, economia e operacao.
- Sistema de bans, whitelist, manutencao, punicoes e alertas de seguranca.
- Relato de bugs, triagem, prioridade, resposta e resolucao.
- Diagnosticos como `/saudegm`, `/selftestgm`, `/integridade` e `/releasecheck`.
- Command router com hotfixes, rastreamento de comandos desconhecidos e auditoria.

### Sistemas Publicos e Cidade

- Policia, PRF, Policia Civil, Policia Federal, Policia Penal e DETRAN.
- Procurados, ficha criminal, abordagem, revista, blitz e fiscalizacao.
- Prefeitura, impostos, licitacoes, orcamento, politica e transparencia.
- Justica, BO, provas, mandados, audiencias e processos.
- Radar, pedagios, mapa dinamico, objetos, portoes e pontos de servico.

### Web e Comunidade

- Site/forum externo em Node.js.
- Cadastro/login de usuarios da comunidade.
- Denuncias Anti-RPG e moderacao por staff.
- Painel VIP com planos, pedidos e aprovacao manual.
- Hash de senhas com PBKDF2 no painel web.

---

## Tecnologias Utilizadas

| Tecnologia | Uso |
| --- | --- |
| Pawn | Gamemode SA-MP e sistemas de gameplay. |
| SA-MP Server | Runtime multiplayer do servidor. |
| Node.js | Painel web, forum, denuncias e VIP. |
| PowerShell | Automacao de build, auditoria, backup e deploy. |
| Arquivos `.txt`/`.ini` | Persistencia e configuracao no padrao SA-MP. |
| Git/GitHub | Versionamento e portfolio tecnico. |

---

## Estrutura do Projeto

```text
.
|-- gamemodes/
|   `-- nova_gm.pwn              # Gamemode principal
|-- include/
|   `-- core/                    # Modulos de gameplay e infraestrutura
|-- docs/
|   `-- MAPA_DO_SISTEMA.md       # Mapa tecnico da arquitetura e dos fluxos
|-- filterscripts/               # Filterscripts auxiliares e exemplos SA-MP
|-- npcmodes/                    # NPCs e gravacoes de rotas
|-- scriptfiles/                 # Dados e configuracoes de runtime
|-- tools/                       # Automacoes PowerShell e utilitarios
|-- vip_panel/                   # Painel web da comunidade em Node.js
|-- pawno/                       # Toolchain Pawn/SA-MP
|-- CHANGELOG.txt                # Historico tecnico das releases
|-- OPERACAO_ONLINE.md           # Procedimentos de operacao
|-- REGRAS_PAWNO.md              # Convencoes de desenvolvimento Pawn
`-- README.md
```

> Para publicacao em repositorio publico, mantenha fora do Git: `server.cfg` real, backups, builds, ZIPs, AMX compilado, credenciais, contas, logs e dados reais de `scriptfiles`.

---

## Mapa Tecnico

Para entender como a GM funciona por dentro, consulte o [Mapa do Sistema](docs/MAPA_DO_SISTEMA.md). Ele explica o fluxo de inicializacao, roteamento de comandos, persistencia, empregos, frota, objetos, economia, seguranca e deploy.

---

## Modulos Core

| Modulo | Responsabilidade |
| --- | --- |
| `accounts.inc` | Cadastro, login, dados do jogador e salvamento. |
| `admin.inc` | Comandos administrativos, roteamento e ferramentas staff. |
| `bank.inc` / `money.inc` | Banco, carteira, transacoes, credito e economia base. |
| `jobs.inc` | Profissoes, rotas, XP, recompensas e anti-farm. |
| `police.inc` / `crime.inc` | Sistema policial, crimes, procurados e operacoes. |
| `life_services.inc` | Servicos publicos, governo, justica, contratos e cidade viva. |
| `properties.inc` | Casas, hoteis, empresas, interiores e mercado imobiliario. |
| `dealership.inc` / `fuel.inc` | Veiculos, garagem, abastecimento e manutencao. |
| `security.inc` / `self_heal.inc` | Protecoes, auditoria, recuperacao e saude operacional. |
| `vip.inc` | Planos VIP, ativacoes e integracao com painel externo. |
| `ops.inc` | Checklists, status do servidor, logs e diagnosticos. |
| `command_hotfix.inc` | Hotfixes de comandos e fallback operacional. |

---

## Como Instalar

### Requisitos

- Windows ou ambiente compativel com SA-MP Server.
- SA-MP Server 0.3.7.
- Pawno/Pawn compiler.
- PowerShell 5+.
- Node.js 18+ para o painel web.

### Passos

```powershell
git clone https://github.com/luiz930/SAMP.git
cd SAMP
Copy-Item server.cfg.example server.cfg
```

Edite `server.cfg` e troque `rcon_password` por uma senha forte antes de abrir o servidor.

---

## Como Executar

### Servidor SA-MP

Compile o gamemode pelo Pawno ou pelo fluxo automatizado local:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\tools\static_gm_audit.ps1
```

Inicie o servidor:

```bat
iniciar_servidor_online.bat
```

Ou execute diretamente:

```powershell
.\samp-server.exe
```

### Painel Web da Comunidade

```powershell
cd vip_panel
$env:VIP_PANEL_TOKEN="troque-por-um-token-forte"
$env:VIP_PIX_KEY="sua-chave-pix"
$env:PUBLIC_SERVER_IP="seu-ip-ou-dominio:7777"
node server.js
```

Acesse:

```text
http://127.0.0.1:8088
```

---

## Screenshots

> Placeholders para portfolio. Substitua por imagens reais quando disponiveis.

| Tela | Preview |
| --- | --- |
| Login e spawn | `docs/screenshots/login-placeholder.png` |
| Painel staff | `docs/screenshots/staff-panel-placeholder.png` |
| GovBR/celular | `docs/screenshots/govbr-placeholder.png` |
| Painel web | `docs/screenshots/web-panel-placeholder.png` |

---

## Qualidade e Operacao

O projeto possui scripts dedicados para manter a GM auditavel antes de publicacao. Helpers com host/FTP real devem ficar fora do repositorio publico e rodar apenas no ambiente privado de operacao.

| Script | Objetivo |
| --- | --- |
| `tools/static_gm_audit.ps1` | Auditoria estatica de comandos, menus e consistencia. |
| `tools/deep_system_audit.ps1` | Varredura profunda de integridade, arquivos exigidos e artefatos. |
| `tools/pre_deploy_gate.ps1` | Gate local antes de release. |
| `tools/boot_test_server.ps1` | Teste de inicializacao local. |
| `tools/backup_scriptfiles.ps1` | Backup dos dados de runtime. |

---

## Status do Projeto

| Item | Status |
| --- | --- |
| Gamemode principal | Stable |
| Sistemas core | Em evolucao continua |
| Painel web | Funcional, com melhorias planejadas |
| Automacao de build | Ativa |
| Release atual | `v1.5.0 Stable` |
| Uso recomendado | Portfolio, estudo e base privada de servidor |

---

## Roadmap

- [ ] Adicionar screenshots reais em `docs/screenshots/`.
- [ ] Criar documentacao individual por modulo em `docs/`.
- [ ] Automatizar checks de README, lint e secrets antes do push.
- [ ] Evoluir painel web com webhook de pagamento.
- [ ] Criar painel administrativo web para metricas e logs.
- [ ] Melhorar cobertura de testes operacionais automatizados.
- [ ] Publicar releases limpas com artefatos separados do codigo fonte.

---

## Contribuicao

Contribuicoes sao bem-vindas para estudos, melhorias e revisoes tecnicas.

1. Faca um fork do projeto.
2. Crie uma branch com nome descritivo.
3. Mantenha credenciais, saves, logs e backups fora do commit.
4. Documente alteracoes relevantes no changelog.
5. Abra um Pull Request explicando contexto, impacto e validacoes feitas.

```powershell
git checkout -b feature/minha-melhoria
git commit -m "feat: adiciona melhoria no sistema"
git push origin feature/minha-melhoria
```

---

## Boas Praticas de Seguranca

- Nunca publique `server.cfg` real com `rcon_password`.
- Nao versione `scriptfiles/contas`, logs, bans, backups ou dumps.
- Use variaveis de ambiente para tokens do painel web.
- Gere pacotes de release em artefatos separados.
- Rode auditoria antes de qualquer publicacao publica.

---

## Licenca

Este projeto esta disponibilizado para fins de portfolio e estudo.

Caso deseje reutilizar partes do codigo, abra uma issue ou entre em contato para alinhar permissao, creditos e escopo de uso.

---

## Contato

**Desenvolvedor:** Luiz  
**GitHub:** [@luiz930](https://github.com/luiz930)  
**Repositorio:** [luiz930/SAMP](https://github.com/luiz930/SAMP)

---

<div align="center">

Desenvolvido para demonstrar arquitetura, automacao e sistemas de gameplay em um servidor SA-MP completo.

</div>
