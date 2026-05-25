# Site/forum externo da comunidade

Site web separado do servidor SA-MP. Ele pode ficar em uma VPS/site na internet e oferece:

- pagina inicial da comunidade;
- forum publico;
- login e criacao de contas de usuario;
- niveis administrativos do site iguais aos do servidor: 0 player comum, 1 a 5 staff/admin;
- formulario de denuncia Anti-RPG;
- informacoes do servidor;
- painel VIP;
- admin para moderar topicos e aprovar VIP.

## Como iniciar

```powershell
cd "C:\Users\anony\Desktop\Nova GM SAMP"
$env:VIP_PANEL_TOKEN="troque-por-uma-senha-forte"
$env:VIP_PIX_KEY="sua-chave-pix"
$env:PUBLIC_SERVER_IP="seu-ip-ou-dominio:7777"
$env:PUBLIC_DISCORD_URL="https://discord.gg/seuconvite"
$env:PUBLIC_SERVER_VERSION="v0.3.5 Alpha"
powershell -ExecutionPolicy Bypass -File .\vip_panel\start_vip_panel.ps1
```

Por padrao o site sobe na porta `8088` e escuta em `0.0.0.0`, pronto para expor por dominio, proxy reverso ou regra de firewall da VPS.

Site:

```text
http://127.0.0.1:8088/
```

Forum:

```text
http://127.0.0.1:8088/forum
```

Denuncia Anti-RPG:

```text
http://127.0.0.1:8088/denuncias/nova
```

Painel VIP:

```text
http://127.0.0.1:8088/vip
```

Admin:

```text
http://127.0.0.1:8088/admin?token=troque-por-uma-senha-forte
```

Conta de usuario:

```text
http://127.0.0.1:8088/register
http://127.0.0.1:8088/login
http://127.0.0.1:8088/perfil
```

## Fluxo do forum

1. O player cria conta em `/register` ou entra em `/login`.
2. O player abre `/forum` ou `/denuncias/nova`.
3. O site salva o topico em `scriptfiles/forum_site/topics.json`.
4. A staff acessa `/admin?token=...`.
5. A staff muda o status para aberto, em analise, resolvido ou recusado.
6. Se necessario, a staff remove topicos falsos, duplicados ou abusivos.

As contas ficam em `scriptfiles/forum_site/users.json`. As senhas sao salvas com hash PBKDF2, nao em texto puro.

## Niveis administrativos

```text
0 Player comum
1 Admin nivel 1
2 Admin nivel 2
3 Admin nivel 3
4 Admin nivel 4
5 Admin nivel 5
```

Contas criadas pelo cadastro publico entram como nivel `0`. A pagina `/admin` permite criar conta staff e alterar nivel de usuarios. Criar ou promover administradores exige o token principal ou uma conta nivel `5`.

## Fluxo VIP

1. O player abre `/vip`, informa o nick da conta e escolhe Bronze, Prata, Ouro ou Diamante.
2. O painel salva o pedido em `scriptfiles/vip_orders.txt`.
3. O admin confere o Pix e aprova pelo painel.
4. O painel grava `scriptfiles/vip_grants/Nick.txt`.
5. A GM aplica o VIP quando o player logar, usar `/ativarvip` ou quando o timer VIP encontrar a ativacao.

## Niveis

```text
1 Bronze   - R$15/30 dias - +5% dinheiro, +5% XP, 1 vaga extra e kit simples
2 Prata    - R$25/30 dias - +8% dinheiro, +10% XP, desconto 8% e kit melhor
3 Ouro     - R$40/30 dias - +12% dinheiro, +15% XP, 2 vagas extras e ferramentas
4 Diamante - R$60/30 dias - +15% dinheiro, +20% XP, 3 vagas extras e kit maximo
```

## Observacao de pagamento

Este painel ainda nao cobra automaticamente. Ele organiza o pedido e gera ativacao apos aprovacao manual. Para automatizar de verdade, o proximo passo e adicionar webhook de Mercado Pago, Asaas, Stripe ou outro provedor e chamar a mesma rotina de aprovacao usada em `/api/approve`.
