const http = require("http");
const fs = require("fs");
const path = require("path");
const crypto = require("crypto");
const querystring = require("querystring");

const ROOT = path.resolve(__dirname, "..");
const SCRIPTFILES = path.join(ROOT, "scriptfiles");
const GRANTS_DIR = path.join(SCRIPTFILES, "vip_grants");
const FORUM_DIR = path.join(SCRIPTFILES, "forum_site");
const ORDERS_FILE = path.join(SCRIPTFILES, "vip_orders.txt");
const PLANS_FILE = path.join(SCRIPTFILES, "vip_plans.txt");
const TOPICS_FILE = path.join(FORUM_DIR, "topics.json");
const USERS_FILE = path.join(FORUM_DIR, "users.json");
const PORT = Number(process.env.PORT || process.env.VIP_PANEL_PORT || 8088);
const HOST = process.env.VIP_PANEL_HOST || "0.0.0.0";
const TOKEN = process.env.VIP_PANEL_TOKEN || "troque-este-token";
const PIX_KEY = process.env.VIP_PIX_KEY || "configure-sua-chave-pix";
const SERVER_NAME = process.env.VIP_PANEL_SERVER || "Life Simulator BR";
const SERVER_IP = process.env.PUBLIC_SERVER_IP || "em breve";
const DISCORD_URL = process.env.PUBLIC_DISCORD_URL || "";
const SERVER_VERSION = process.env.PUBLIC_SERVER_VERSION || "v0.3.5 Alpha";
const SESSION_TTL_MS = 1000 * 60 * 60 * 24 * 7;
const sessions = new Map();

const plans = {
  1: { name: "Bronze", price: 15, days: 30, benefits: "+5% dinheiro, +5% XP, 1 vaga extra, kit simples" },
  2: { name: "Prata", price: 25, days: 30, benefits: "+8% dinheiro, +10% XP, 1 vaga extra, 8% desconto, kit melhor" },
  3: { name: "Ouro", price: 40, days: 30, benefits: "+12% dinheiro, +15% XP, 2 vagas extras, 12% desconto, ferramentas" },
  4: { name: "Diamante", price: 60, days: 30, benefits: "+15% dinheiro, +20% XP, 3 vagas extras, 15% desconto, kit maximo" },
};

function ensureStorage() {
  fs.mkdirSync(GRANTS_DIR, { recursive: true });
  fs.mkdirSync(FORUM_DIR, { recursive: true });
  if (!fs.existsSync(ORDERS_FILE)) {
    fs.writeFileSync(ORDERS_FILE, "# JSONL gerado pelo painel externo VIP.\r\n", "utf8");
  }
  if (!fs.existsSync(PLANS_FILE)) {
    const lines = ["# level|nome|valor_sugerido|dias|beneficios"];
    for (const [level, plan] of Object.entries(plans)) {
      lines.push(`${level}|${plan.name}|${plan.price}|${plan.days}|${plan.benefits}`);
    }
    fs.writeFileSync(PLANS_FILE, `${lines.join("\r\n")}\r\n`, "utf8");
  }
  if (!fs.existsSync(TOPICS_FILE)) {
    fs.writeFileSync(TOPICS_FILE, "[]\r\n", "utf8");
  }
  if (!fs.existsSync(USERS_FILE)) {
    fs.writeFileSync(USERS_FILE, "[]\r\n", "utf8");
  }
  const marker = path.join(GRANTS_DIR, ".keep");
  if (!fs.existsSync(marker)) fs.writeFileSync(marker, "", "utf8");
}

function escapeHtml(value) {
  return String(value)
    .replace(/&/g, "&amp;")
    .replace(/</g, "&lt;")
    .replace(/>/g, "&gt;")
    .replace(/"/g, "&quot;");
}

function sanitizeAccount(value) {
  const account = String(value || "").trim();
  if (!/^[A-Za-z0-9_\[\]\(\)\.]{3,24}$/.test(account)) return "";
  return account;
}

function normalizeUsername(value) {
  return String(value || "").trim().toLowerCase();
}

function sanitizeText(value, max = 80) {
  return String(value || "")
    .replace(/[\r\n|]/g, " ")
    .trim()
    .slice(0, max);
}

function sanitizeLongText(value, max = 2000) {
  return String(value || "")
    .replace(/\r/g, "")
    .replace(/\|/g, " ")
    .trim()
    .slice(0, max);
}

function sanitizeCategory(value) {
  const category = String(value || "").trim().toLowerCase();
  if (["denuncia", "suporte", "duvida", "sugestao", "informacao"].includes(category)) return category;
  return "duvida";
}

function sanitizeAdminLevel(value) {
  const level = Number(value);
  if (!Number.isInteger(level)) return 0;
  return Math.max(0, Math.min(5, level));
}

function formatBrDate(value) {
  try {
    return new Intl.DateTimeFormat("pt-BR", {
      dateStyle: "short",
      timeStyle: "short",
      timeZone: "America/Sao_Paulo",
    }).format(new Date(value));
  } catch {
    return value || "";
  }
}

function categoryLabel(category) {
  return {
    denuncia: "Denuncia Anti-RPG",
    suporte: "Suporte",
    duvida: "Duvida",
    sugestao: "Sugestao",
    informacao: "Informacao",
  }[category] || "Topico";
}

function statusLabel(status) {
  return {
    open: "Aberto",
    staff: "Em analise",
    resolved: "Resolvido",
    rejected: "Recusado",
  }[status] || "Aberto";
}

function adminLevelLabel(level) {
  const safeLevel = sanitizeAdminLevel(level);
  if (safeLevel === 0) return "Player comum";
  return `Admin nivel ${safeLevel}`;
}

function adminBadge(level) {
  const safeLevel = sanitizeAdminLevel(level);
  if (safeLevel <= 0) return "";
  return `<span class="tag status-resolved">Admin ${safeLevel}</span>`;
}

function parseCookies(req) {
  return String(req.headers.cookie || "")
    .split(";")
    .map(item => item.trim())
    .filter(Boolean)
    .reduce((cookies, item) => {
      const index = item.indexOf("=");
      if (index > -1) cookies[item.slice(0, index)] = decodeURIComponent(item.slice(index + 1));
      return cookies;
    }, {});
}

function readUsers() {
  ensureStorage();
  try {
    const parsed = JSON.parse(fs.readFileSync(USERS_FILE, "utf8"));
    if (!Array.isArray(parsed)) return [];
    return parsed.map(user => ({
      ...user,
      adminLevel: user.adminLevel === undefined
        ? (user.role === "founder" ? 5 : 0)
        : sanitizeAdminLevel(user.adminLevel),
    }));
  } catch {
    return [];
  }
}

function saveUsers(users) {
  fs.writeFileSync(USERS_FILE, `${JSON.stringify(users, null, 2)}\r\n`, "utf8");
}

function hashPassword(password, salt = crypto.randomBytes(16).toString("hex")) {
  const hash = crypto.pbkdf2Sync(String(password || ""), salt, 120000, 32, "sha256").toString("hex");
  return `${salt}:${hash}`;
}

function verifyPassword(password, stored) {
  const [salt, expected] = String(stored || "").split(":");
  if (!salt || !expected) return false;
  const actual = hashPassword(password, salt).split(":")[1];
  if (actual.length !== expected.length) return false;
  return crypto.timingSafeEqual(Buffer.from(actual, "hex"), Buffer.from(expected, "hex"));
}

function createSession(username) {
  const token = crypto.randomBytes(24).toString("hex");
  sessions.set(token, { username, expiresAt: Date.now() + SESSION_TTL_MS });
  return token;
}

function getViewer(req) {
  const token = parseCookies(req).forum_session;
  const session = sessions.get(token);
  if (!session) return null;
  if (session.expiresAt < Date.now()) {
    sessions.delete(token);
    return null;
  }
  const user = readUsers().find(item => normalizeUsername(item.username) === normalizeUsername(session.username));
  return user ? { username: user.username, adminLevel: sanitizeAdminLevel(user.adminLevel) } : null;
}

function getUserAdminLevel(username, users = readUsers()) {
  const user = users.find(item => normalizeUsername(item.username) === normalizeUsername(username));
  return user ? sanitizeAdminLevel(user.adminLevel) : 0;
}

function setSessionCookie(res, token) {
  res.setHeader("Set-Cookie", `forum_session=${encodeURIComponent(token)}; HttpOnly; SameSite=Lax; Path=/; Max-Age=${Math.floor(SESSION_TTL_MS / 1000)}`);
}

function clearSessionCookie(res) {
  res.setHeader("Set-Cookie", "forum_session=; HttpOnly; SameSite=Lax; Path=/; Max-Age=0");
}

function readBody(req) {
  return new Promise((resolve, reject) => {
    let body = "";
    req.on("data", chunk => {
      body += chunk;
      if (body.length > 20_000) {
        req.destroy();
        reject(new Error("payload muito grande"));
      }
    });
    req.on("end", () => resolve(body));
    req.on("error", reject);
  });
}

function readOrders() {
  ensureStorage();
  return fs.readFileSync(ORDERS_FILE, "utf8")
    .split(/\r?\n/)
    .filter(line => line.trim() && !line.startsWith("#"))
    .map(line => {
      try {
        return JSON.parse(line);
      } catch {
        return null;
      }
    })
    .filter(Boolean);
}

function readTopics() {
  ensureStorage();
  try {
    const parsed = JSON.parse(fs.readFileSync(TOPICS_FILE, "utf8"));
    return Array.isArray(parsed) ? parsed : [];
  } catch {
    return [];
  }
}

function saveTopics(topics) {
  fs.writeFileSync(TOPICS_FILE, `${JSON.stringify(topics, null, 2)}\r\n`, "utf8");
}

function saveOrders(orders) {
  const body = [
    "# JSONL gerado pelo painel externo VIP.",
    ...orders.map(order => JSON.stringify(order)),
  ].join("\r\n");
  fs.writeFileSync(ORDERS_FILE, `${body}\r\n`, "utf8");
}

function appendOrder(order) {
  fs.appendFileSync(ORDERS_FILE, `${JSON.stringify(order)}\r\n`, "utf8");
}

function appendGrant(account, level, days, orderId) {
  const file = path.join(GRANTS_DIR, `${account}.txt`);
  fs.appendFileSync(file, `${level}|${days}|${orderId}|painel_vip\r\n`, "utf8");
}

function makeOrderId() {
  return `VIP-${Date.now().toString(36).toUpperCase()}-${crypto.randomBytes(3).toString("hex").toUpperCase()}`;
}

function makeTopicId() {
  return `TOP-${Date.now().toString(36).toUpperCase()}-${crypto.randomBytes(2).toString("hex").toUpperCase()}`;
}

function page(title, content, viewer = null) {
  return `<!doctype html>
<html lang="pt-BR">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>${escapeHtml(title)}</title>
  <style>
    :root { color-scheme: dark; --bg:#0b1116; --panel:#141c24; --panel2:#0f171f; --panel3:#19232d; --line:#263543; --text:#edf3f7; --muted:#9fb0bf; --accent:#2dd881; --accent2:#49a6ff; --warn:#ffb547; --bad:#ff6b6b; }
    * { box-sizing: border-box; }
    body { margin: 0; font: 15px/1.5 Arial, sans-serif; background: radial-gradient(circle at top left, #142234 0, #0b1116 320px); color: var(--text); }
    header { position:sticky; top:0; z-index:10; border-bottom:1px solid var(--line); background:rgba(9,14,19,.94); backdrop-filter: blur(10px); }
    nav { max-width: 1180px; margin:0 auto; padding: 12px 18px; display:flex; gap:8px; align-items:center; flex-wrap:wrap; }
    nav strong { margin-right:auto; letter-spacing:.2px; }
    nav a { color:var(--text); text-decoration:none; padding:8px 10px; border-radius:6px; }
    nav a:hover { background:var(--panel3); }
    main { max-width: 1180px; margin: 0 auto; padding: 30px 18px 52px; }
    h1 { margin: 0 0 8px; font-size: 34px; line-height:1.08; }
    h2 { margin: 30px 0 12px; font-size: 20px; }
    h3 { margin: 0 0 8px; font-size: 16px; }
    p { color: var(--muted); margin: 6px 0 16px; }
    a { color: var(--accent); }
    .grid { display:grid; grid-template-columns: repeat(auto-fit, minmax(230px,1fr)); gap: 14px; }
    .layout { display:grid; grid-template-columns: minmax(0,1fr) 320px; gap:18px; align-items:start; }
    .card, form, table, .panel { background: rgba(20,28,36,.96); border:1px solid var(--line); border-radius:8px; box-shadow: 0 10px 30px rgba(0,0,0,.18); }
    .card, .panel { padding: 16px; }
    .hero { display:grid; grid-template-columns: minmax(0,1.35fr) minmax(280px,.65fr); gap:18px; align-items:stretch; }
    .hero-main { padding:28px; border:1px solid var(--line); border-radius:8px; background:linear-gradient(135deg, rgba(20,32,44,.98), rgba(14,23,32,.98)); min-height:260px; display:flex; flex-direction:column; justify-content:center; }
    .hero-main p { font-size:16px; max-width:720px; }
    .actions { display:flex; flex-wrap:wrap; gap:10px; margin: 16px 0 4px; }
    .btn { display:inline-block; padding:10px 12px; border-radius:6px; background:var(--accent); color:#07110b; font-weight:700; text-decoration:none; }
    .btn.secondary { background:#253442; color:var(--text); }
    .btn.blue { background:var(--accent2); color:#06101a; }
    .price { font-size: 24px; color: var(--accent); font-weight: 700; }
    label { display:block; margin: 10px 0 5px; color: var(--muted); }
    input, select, textarea, button { width:100%; padding: 10px 11px; border-radius:6px; border:1px solid var(--line); background:#0b1219; color:var(--text); }
    textarea { min-height: 160px; resize: vertical; }
    button { cursor:pointer; background: var(--accent); border:0; color:#07110b; font-weight:700; margin-top: 12px; }
    .secondary { background:#26313a; color:var(--text); }
    form { padding: 14px; }
    table { width:100%; border-collapse: collapse; overflow:hidden; }
    th, td { padding: 9px 10px; border-bottom:1px solid var(--line); text-align:left; vertical-align: top; }
    th { color: var(--muted); font-weight: 600; }
    .status-pending { color: var(--warn); }
    .status-approved { color: var(--accent); }
    .status-open { color: var(--warn); }
    .status-staff { color: #74c0fc; }
    .status-resolved { color: var(--accent); }
    .status-rejected { color: var(--bad); }
    .tag { display:inline-block; padding:4px 8px; border:1px solid var(--line); border-radius:999px; color:var(--muted); font-size:12px; }
    .stat { display:grid; gap:4px; background:var(--panel2); border:1px solid var(--line); border-radius:8px; padding:12px; }
    .stat strong { font-size:24px; }
    .topic { display:grid; grid-template-columns: 1fr auto; gap: 8px 16px; background:var(--panel); border:1px solid var(--line); border-radius:8px; padding:14px; margin-bottom:10px; }
    .topic:hover { border-color:#38546a; }
    .topic-title { font-size:18px; color:var(--text); font-weight:700; text-decoration:none; }
    .topic-side { text-align:right; color:var(--muted); min-width:90px; }
    .post { white-space: pre-wrap; background:var(--panel2); border:1px solid var(--line); border-radius:8px; padding:12px; color:var(--text); }
    .meta { color:var(--muted); font-size:13px; }
    .muted { color:var(--muted); }
    .empty { background:var(--panel2); border:1px dashed var(--line); border-radius:8px; padding:18px; color:var(--muted); }
    .row { display:grid; grid-template-columns: 1fr 1fr; gap: 12px; }
    .notice { border-left: 3px solid var(--accent); padding: 10px 12px; background:#121a18; color:var(--muted); }
    @media (max-width: 820px) { .row, .hero, .layout, .topic { grid-template-columns: 1fr; } nav strong { width:100%; } .topic-side { text-align:left; } h1 { font-size:28px; } }
  </style>
</head>
<body>
  <header><nav>
    <strong>${escapeHtml(SERVER_NAME)}</strong>
    <a href="/">Inicio</a>
    <a href="/forum">Forum</a>
    <a href="/denuncias/nova">Denunciar Anti-RPG</a>
    <a href="/info">Info</a>
    <a href="/vip">VIP</a>
    <a href="/admin">Admin</a>
    ${viewer ? `<a href="/perfil">${escapeHtml(viewer.username)}</a><a href="/logout">Sair</a>` : `<a href="/login">Entrar</a><a href="/register">Criar conta</a>`}
  </nav></header>
  <main>${content}</main>
</body></html>`;
}

function renderPlans() {
  return `<div class="grid">${Object.entries(plans).map(([level, plan]) => `
    <section class="card">
      <h2>VIP ${escapeHtml(plan.name)}</h2>
      <div class="price">R$ ${plan.price}</div>
      <p>${plan.days} dias</p>
      <p>${escapeHtml(plan.benefits)}</p>
      <form method="post" action="/api/order">
        <input type="hidden" name="level" value="${level}">
        <label>Nick exato da conta SA-MP</label>
        <input name="account" maxlength="24" required placeholder="Exemplo: Lucas_Santos">
        <label>Dias</label>
        <input name="days" type="number" min="1" max="365" value="${plan.days}">
        <button>Gerar pedido</button>
      </form>
    </section>`).join("")}</div>`;
}

function renderOrdersTable(orders, token = "") {
  if (!orders.length) return "<p>Nenhum pedido registrado ainda.</p>";
  return `<table>
    <thead><tr><th>Pedido</th><th>Conta</th><th>Plano</th><th>Status</th><th>Data</th><th>Acao</th></tr></thead>
    <tbody>${orders.slice().reverse().map(order => {
      const plan = plans[order.level] || { name: `Nivel ${order.level}` };
      const approve = order.status === "pending" && token ? `
        <form method="post" action="/api/approve">
          <input type="hidden" name="token" value="${escapeHtml(token)}">
          <input type="hidden" name="id" value="${escapeHtml(order.id)}">
          <input name="paymentRef" placeholder="comprovante/ref">
          <button>Aprovar</button>
        </form>` : "";
      return `<tr>
        <td>${escapeHtml(order.id)}</td>
        <td>${escapeHtml(order.account)}</td>
        <td>${escapeHtml(plan.name)}<br>${order.days} dias</td>
        <td class="status-${escapeHtml(order.status)}">${escapeHtml(order.status)}</td>
        <td>${escapeHtml(order.createdAt)}</td>
        <td>${approve}</td>
      </tr>`;
    }).join("")}</tbody>
  </table>`;
}

function renderTopicList(topics) {
  if (!topics.length) return "<div class=\"empty\">Nenhum topico publicado ainda.</div>";
  const users = readUsers();
  return topics.map(topic => `
    <article class="topic">
      <div>
        <span class="tag">${escapeHtml(categoryLabel(topic.category))}</span>
        <span class="tag status-${escapeHtml(topic.status || "open")}">${escapeHtml(statusLabel(topic.status || "open"))}</span>
        ${adminBadge(getUserAdminLevel(topic.author, users))}
        <a class="topic-title" href="/forum/topico?id=${encodeURIComponent(topic.id)}">${escapeHtml(topic.title)}</a>
        <div class="meta">por ${escapeHtml(topic.author)} em ${escapeHtml(formatBrDate(topic.createdAt))}</div>
        <p>${escapeHtml(topic.body).slice(0, 220)}${topic.body.length > 220 ? "..." : ""}</p>
      </div>
      <div class="topic-side"><strong>${topic.replies?.length || 0}</strong><br>resposta(s)</div>
    </article>
  `).join("");
}

function forumStats() {
  const topics = readTopics();
  const users = readUsers();
  return {
    topics: topics.length,
    reports: topics.filter(topic => topic.category === "denuncia").length,
    solved: topics.filter(topic => topic.status === "resolved").length,
    users: users.length,
  };
}

function serverInfoCards() {
  return `
    <div class="grid">
      <section class="stat"><span class="muted">Endereco</span><strong>${escapeHtml(SERVER_IP)}</strong><span>SA-MP 0.3.7</span></section>
      <section class="stat"><span class="muted">Versao</span><strong>${escapeHtml(SERVER_VERSION)}</strong><span>Life Simulator BR</span></section>
      <section class="stat"><span class="muted">Forum</span><strong>24h</strong><span>Denuncias e suporte online</span></section>
    </div>
  `;
}

function forumHome(category = "", viewer = null) {
  let topics = readTopics().slice().reverse();
  if (category) topics = topics.filter(topic => topic.category === category);
  return page("Forum", `
    <div class="layout">
      <section>
        <h1>Forum da comunidade</h1>
        <p>Denuncias Anti-RPG, suporte, sugestoes, duvidas e comunicados do ${escapeHtml(SERVER_NAME)}.</p>
        <div class="actions">
          <a class="btn" href="/denuncias/nova">Nova denuncia Anti-RPG</a>
          <a class="btn secondary" href="/forum/new">Novo topico</a>
          <a class="btn secondary" href="/forum?categoria=suporte">Suporte</a>
          <a class="btn secondary" href="/forum?categoria=sugestao">Sugestoes</a>
        </div>
        ${renderTopicList(topics)}
      </section>
      <aside class="panel">
        <h3>Filtros</h3>
        <p><a href="/forum">Todos os topicos</a></p>
        <p><a href="/forum?categoria=denuncia">Denuncias Anti-RPG</a></p>
        <p><a href="/forum?categoria=suporte">Suporte</a></p>
        <p><a href="/forum?categoria=sugestao">Sugestoes</a></p>
        <h3>Conta</h3>
        <p>${viewer ? `Logado como <strong>${escapeHtml(viewer.username)}</strong>.` : `Entre na sua conta para criar topicos e responder.`}</p>
        ${viewer ? `<a class="btn secondary" href="/perfil">Meu perfil</a>` : `<a class="btn" href="/login">Entrar</a>`}
      </aside>
    </div>
  `, viewer);
}

function forumNew(category = "duvida", viewer = null) {
  const selected = sanitizeCategory(category);
  if (!viewer) return page("Entrar", `
    <h1>Entre para publicar</h1>
    <p>Voce precisa de uma conta do site para criar topicos, denunciar Anti-RPG e responder no forum.</p>
    <div class="actions"><a class="btn" href="/login">Entrar</a><a class="btn secondary" href="/register">Criar conta</a></div>
  `, viewer);
  return page(selected === "denuncia" ? "Nova denuncia" : "Novo topico", `
    <h1>${selected === "denuncia" ? "Denuncia Anti-RPG" : "Novo topico"}</h1>
    <p>Preencha com detalhes claros. Denuncias precisam de nick, data aproximada, local e provas quando possivel.</p>
    <form method="post" action="/api/forum-topic">
      <label>Categoria</label>
      <select name="category">
        ${["denuncia", "suporte", "duvida", "sugestao", "informacao"].map(cat => `<option value="${cat}"${cat === selected ? " selected" : ""}>${categoryLabel(cat)}</option>`).join("")}
      </select>
      <label>Titulo</label>
      <input name="title" maxlength="90" required placeholder="Resumo do assunto">
      <label>Nick denunciado ou envolvido</label>
      <input name="target" maxlength="24" placeholder="Opcional">
      <label>Provas / link de video ou imagem</label>
      <input name="evidence" maxlength="180" placeholder="https://...">
      <label>Descricao</label>
      <textarea name="body" maxlength="2000" required placeholder="Explique o que aconteceu, horario, local e testemunhas."></textarea>
      <button>Publicar</button>
    </form>
  `, viewer);
}

function forumTopic(id, viewer = null) {
  const topic = readTopics().find(item => item.id === id);
  if (!topic) return page("Topico nao encontrado", "<h1>Topico nao encontrado</h1><p>Esse topico nao existe ou foi removido.</p>", viewer);
  return page(topic.title, `
    <h1>${escapeHtml(topic.title)}</h1>
    <p>
      <span class="tag">${escapeHtml(categoryLabel(topic.category))}</span>
      <span class="tag status-${escapeHtml(topic.status || "open")}">${escapeHtml(statusLabel(topic.status || "open"))}</span>
    </p>
    <div class="meta">por ${escapeHtml(topic.author)} em ${escapeHtml(formatBrDate(topic.createdAt))}</div>
    ${topic.target ? `<p>Envolvido: <strong>${escapeHtml(topic.target)}</strong></p>` : ""}
    ${topic.evidence ? `<p>Provas: <a href="${escapeHtml(topic.evidence)}">${escapeHtml(topic.evidence)}</a></p>` : ""}
    <div class="post">${escapeHtml(topic.body)}</div>
    <h2>Respostas</h2>
    ${(topic.replies || []).map(reply => `
      <article class="topic">
        <div class="meta">${escapeHtml(reply.author)} em ${escapeHtml(formatBrDate(reply.createdAt))}</div>
        <div class="post">${escapeHtml(reply.body)}</div>
      </article>
    `).join("") || "<p>Nenhuma resposta ainda.</p>"}
    <h2>Responder</h2>
    ${viewer ? `<form method="post" action="/api/forum-reply">
      <input type="hidden" name="id" value="${escapeHtml(topic.id)}">
      <label>Resposta</label>
      <textarea name="body" maxlength="1200" required></textarea>
      <button>Enviar resposta</button>
    </form>` : `<div class="notice">Entre na sua conta para responder. <a href="/login">Fazer login</a></div>`}
    <p><a href="/forum">Voltar ao forum</a></p>
  `, viewer);
}

function infoPage(viewer = null) {
  return page("Informacoes do servidor", `
    <h1>Informacoes do servidor</h1>
    <div class="grid">
      <section class="card"><h3>Endereco</h3><p>IP: <strong>${escapeHtml(SERVER_IP)}</strong></p><p>Servidor: <strong>${escapeHtml(SERVER_NAME)}</strong></p></section>
      <section class="card"><h3>Versao</h3><p>${escapeHtml(SERVER_VERSION)}</p><p>GM Roleplay/RPG com economia, casas, veiculos, policia, VIP e sistemas persistentes.</p></section>
      <section class="card"><h3>Comunidade</h3><p>Use o forum para suporte, denuncias e sugestoes.</p>${DISCORD_URL ? `<p><a href="${escapeHtml(DISCORD_URL)}">Entrar no Discord</a></p>` : ""}</section>
    </div>
    <h2>Regras importantes</h2>
    <div class="card">
      <p>Proibido Anti-RPG, DM sem motivo, DB, abuso de bug, uso de programas ilegais, ofensas graves e falsa denuncia.</p>
      <p>Denuncias devem ter descricao clara e provas quando possivel. A staff pode marcar como em analise, resolvida ou recusada.</p>
    </div>
  `, viewer);
}

function siteHome(viewer = null) {
  const topics = readTopics().slice().reverse().slice(0, 4);
  const stats = forumStats();
  return page("Comunidade", `
    <section class="hero">
      <div class="hero-main">
        <h1>${escapeHtml(SERVER_NAME)}</h1>
        <p>Forum oficial para denuncias Anti-RPG, avisos da staff, suporte, sugestoes e informacoes do servidor. Crie sua conta, acompanhe topicos e fale com a administracao fora do jogo.</p>
        <div class="actions">
          <a class="btn" href="/denuncias/nova">Fazer denuncia Anti-RPG</a>
          <a class="btn blue" href="/register">Criar conta</a>
          <a class="btn secondary" href="/forum">Abrir forum</a>
        </div>
      </div>
      <aside class="card">
        <h3>Info rapida</h3>
        <p>IP: <strong>${escapeHtml(SERVER_IP)}</strong></p>
        <p>Versao: <strong>${escapeHtml(SERVER_VERSION)}</strong></p>
        <p>Contas no site: <strong>${stats.users}</strong></p>
        <p>Topicos: <strong>${stats.topics}</strong></p>
        ${DISCORD_URL ? `<p><a href="${escapeHtml(DISCORD_URL)}">Discord da comunidade</a></p>` : ""}
      </aside>
    </section>
    <h2>Informacoes do servidor</h2>
    ${serverInfoCards()}
    <h2>Areas principais</h2>
    <div class="grid">
      <section class="card"><h3>Denuncias Anti-RPG</h3><p>Use para reportar DM, DB, power gaming, abuso de bug, fuga irregular e atitudes contra as regras.</p><a href="/denuncias/nova">Criar denuncia</a></section>
      <section class="card"><h3>Suporte</h3><p>Abra pedidos sobre conta, perda de item, bugs e duvidas de acesso.</p><a href="/forum/new?categoria=suporte">Pedir suporte</a></section>
      <section class="card"><h3>Sugestoes</h3><p>Proponha melhorias para economia, empregos, policia, veiculos, casas e sistemas novos.</p><a href="/forum/new?categoria=sugestao">Enviar sugestao</a></section>
      <section class="card"><h3>Informacoes</h3><p>Veja IP, versao, regras importantes e links uteis para entrar no servidor.</p><a href="/info">Ver info</a></section>
    </div>
    <h2>Topicos recentes</h2>
    ${renderTopicList(topics)}
    <h2>Resumo do forum</h2>
    <div class="grid">
      <section class="stat"><span class="muted">Topicos</span><strong>${stats.topics}</strong><span>Publicados pela comunidade</span></section>
      <section class="stat"><span class="muted">Denuncias</span><strong>${stats.reports}</strong><span>Anti-RPG registradas</span></section>
      <section class="stat"><span class="muted">Resolvidos</span><strong>${stats.solved}</strong><span>Casos fechados pela staff</span></section>
    </div>
  `, viewer);
}

function vipHome(viewer = null) {
  const orders = readOrders();
  return page("Painel VIP", `
    <h1>${escapeHtml(SERVER_NAME)} - Painel VIP</h1>
    <p>Pedidos pagos precisam ser aprovados pela staff. A aprovacao cria um grant em <code>scriptfiles/vip_grants/</code>, e a GM ativa no login ou em /ativarvip.</p>
    <div class="notice">Chave Pix configurada: <strong>${escapeHtml(PIX_KEY)}</strong></div>
    <h2>Planos</h2>
    ${renderPlans()}
    <h2>Ultimos pedidos</h2>
    ${renderOrdersTable(orders)}
    <p><a href="/admin">Abrir admin</a></p>
  `, viewer);
}

function loginPage(viewer = null) {
  if (viewer) return page("Minha conta", `
    <h1>Voce ja esta logado</h1>
    <p>Conta atual: <strong>${escapeHtml(viewer.username)}</strong></p>
    <div class="actions"><a class="btn" href="/perfil">Meu perfil</a><a class="btn secondary" href="/logout">Sair</a></div>
  `, viewer);
  return page("Entrar", `
    <div class="row">
      <section>
        <h1>Entrar</h1>
        <p>Acesse sua conta do site para criar topicos, responder no forum e acompanhar denuncias.</p>
        <form method="post" action="/api/login">
          <label>Nick/usuario</label>
          <input name="username" maxlength="24" required placeholder="Exemplo: Lucas_Santos">
          <label>Senha</label>
          <input name="password" type="password" minlength="4" maxlength="80" required>
          <button>Entrar</button>
        </form>
      </section>
      <aside class="card">
        <h3>Ainda nao tem conta?</h3>
        <p>Crie uma conta para usar o forum externo da comunidade.</p>
        <a class="btn secondary" href="/register">Criar conta</a>
      </aside>
    </div>
  `, viewer);
}

function registerPage(viewer = null) {
  if (viewer) return loginPage(viewer);
  return page("Criar conta", `
    <div class="row">
      <section>
        <h1>Criar conta</h1>
        <p>Use preferencialmente o mesmo nick da sua conta SA-MP para facilitar atendimento pela staff.</p>
        <form method="post" action="/api/register">
          <label>Nick/usuario</label>
          <input name="username" maxlength="24" required placeholder="Exemplo: Lucas_Santos">
          <label>E-mail</label>
          <input name="email" type="email" maxlength="120" placeholder="Opcional">
          <label>Senha</label>
          <input name="password" type="password" minlength="4" maxlength="80" required>
          <button>Criar conta</button>
        </form>
      </section>
      <aside class="card">
        <h3>Para que serve?</h3>
        <p>Sua conta identifica topicos, respostas e denuncias no site. Isso evita denuncias anonimas e ajuda a staff a acompanhar cada caso.</p>
      </aside>
    </div>
  `, viewer);
}

function profilePage(viewer = null) {
  if (!viewer) return loginPage(viewer);
  const topics = readTopics().filter(topic => normalizeUsername(topic.author) === normalizeUsername(viewer.username)).slice().reverse();
  return page("Meu perfil", `
    <h1>Meu perfil</h1>
    <p>Conta: <strong>${escapeHtml(viewer.username)}</strong></p>
    <p>Nivel no site: <strong>${escapeHtml(adminLevelLabel(viewer.adminLevel))}</strong></p>
    <div class="actions"><a class="btn" href="/forum/new">Novo topico</a><a class="btn secondary" href="/denuncias/nova">Nova denuncia</a><a class="btn secondary" href="/logout">Sair</a></div>
    <h2>Meus topicos</h2>
    ${renderTopicList(topics)}
  `, viewer);
}

function admin(token, viewer = null) {
  const tokenAccess = token === TOKEN;
  const staffAccess = sanitizeAdminLevel(viewer?.adminLevel) >= 1;
  const canManageUsers = tokenAccess || sanitizeAdminLevel(viewer?.adminLevel) >= 5;
  if (!tokenAccess && !staffAccess) {
    return page("Admin VIP", `
      <h1>Admin VIP</h1>
      <p>Entre com uma conta staff ou use o token administrativo.</p>
      <form method="get" action="/admin">
        <label>Token admin</label>
        <input name="token" type="password" required>
        <button>Entrar</button>
      </form>
    `, viewer);
  }

  const topics = readTopics().slice().reverse();
  const users = readUsers().slice().sort((a, b) => sanitizeAdminLevel(b.adminLevel) - sanitizeAdminLevel(a.adminLevel) || a.username.localeCompare(b.username));
  return page("Admin VIP", `
    <h1>Admin do site</h1>
    <p>Modere o forum, crie contas de administradores do servidor e aprove pedidos VIP. Nivel 0 e player comum; niveis 1 a 5 seguem a hierarquia da GM.</p>
    ${viewer ? `<div class="notice">Conta logada: <strong>${escapeHtml(viewer.username)}</strong> - ${escapeHtml(adminLevelLabel(viewer.adminLevel))}</div>` : ""}
    <div class="row">
      ${canManageUsers ? `<section>
        <h2>Criar conta staff</h2>
        <form method="post" action="/api/admin-user-create">
          <input type="hidden" name="token" value="${escapeHtml(token)}">
          <label>Nick/usuario</label>
          <input name="username" maxlength="24" required placeholder="Exemplo: Admin_Master">
          <label>E-mail</label>
          <input name="email" type="email" maxlength="120" placeholder="Opcional">
          <label>Senha inicial</label>
          <input name="password" type="password" minlength="4" maxlength="80" required>
          <label>Nivel administrativo</label>
          <select name="adminLevel">
            ${[1, 2, 3, 4, 5].map(level => `<option value="${level}">Admin nivel ${level}</option>`).join("")}
          </select>
          <button>Criar administrador</button>
        </form>
      </section>` : `<section class="card"><h2>Contas staff</h2><p>Apenas admin nivel 5 ou acesso por token pode criar ou alterar niveis administrativos.</p></section>`}
      <section>
        <h2>Ativar VIP direto</h2>
        <form method="post" action="/api/direct-grant">
          <input type="hidden" name="token" value="${escapeHtml(token)}">
          <label>Conta SA-MP</label>
          <input name="account" maxlength="24" required>
          <label>Plano</label>
          <select name="level">${Object.entries(plans).map(([level, plan]) => `<option value="${level}">${plan.name}</option>`).join("")}</select>
          <label>Dias</label>
          <input name="days" type="number" min="1" max="365" value="30">
          <label>Observacao</label>
          <input name="note" maxlength="80" placeholder="manual, sorteio, reembolso...">
          <button>Gerar grant</button>
        </form>
      </section>
    </div>
    <h2>Usuarios do site</h2>
    ${users.length ? `<table>
      <thead><tr><th>Usuario</th><th>Nivel</th><th>Criado em</th><th>Acao</th></tr></thead>
      <tbody>${users.map(user => `
        <tr>
          <td>${escapeHtml(user.username)}<br><span class="meta">${escapeHtml(user.email || "sem e-mail")}</span></td>
          <td>${escapeHtml(adminLevelLabel(user.adminLevel))}</td>
          <td>${escapeHtml(formatBrDate(user.createdAt))}</td>
          <td>
            ${canManageUsers ? `<form method="post" action="/api/admin-user-level">
              <input type="hidden" name="token" value="${escapeHtml(token)}">
              <input type="hidden" name="username" value="${escapeHtml(user.username)}">
              <select name="adminLevel">
                ${[0, 1, 2, 3, 4, 5].map(level => `<option value="${level}"${sanitizeAdminLevel(user.adminLevel) === level ? " selected" : ""}>${adminLevelLabel(level)}</option>`).join("")}
              </select>
              <button>Salvar nivel</button>
            </form>` : `<span class="muted">Sem permissao para alterar</span>`}
          </td>
        </tr>
      `).join("")}</tbody>
    </table>` : "<p>Nenhum usuario criado ainda.</p>"}
    <div class="row">
      <section>
        <h2>Configuracao</h2>
        <div class="card">
          <p>Token atual vem de <code>VIP_PANEL_TOKEN</code>. Troque antes de expor em VPS.</p>
          <p>Porta: <code>${PORT}</code></p>
          <p>Pix: <code>${escapeHtml(PIX_KEY)}</code></p>
        </div>
      </section>
    </div>
    <h2>Moderacao do forum</h2>
    ${topics.length ? `<table>
      <thead><tr><th>Topico</th><th>Categoria</th><th>Status</th><th>Autor</th><th>Acao</th></tr></thead>
      <tbody>${topics.map(topic => `
        <tr>
          <td><a href="/forum/topico?id=${encodeURIComponent(topic.id)}">${escapeHtml(topic.title)}</a><br><span class="meta">${escapeHtml(formatBrDate(topic.createdAt))}</span></td>
          <td>${escapeHtml(categoryLabel(topic.category))}</td>
          <td class="status-${escapeHtml(topic.status || "open")}">${escapeHtml(statusLabel(topic.status || "open"))}</td>
          <td>${escapeHtml(topic.author)}</td>
          <td>
            <form method="post" action="/api/forum-status">
              <input type="hidden" name="token" value="${escapeHtml(token)}">
              <input type="hidden" name="id" value="${escapeHtml(topic.id)}">
              <select name="status">
                ${["open", "staff", "resolved", "rejected"].map(status => `<option value="${status}"${status === topic.status ? " selected" : ""}>${statusLabel(status)}</option>`).join("")}
              </select>
              <button>Atualizar</button>
            </form>
            <form method="post" action="/api/forum-delete">
              <input type="hidden" name="token" value="${escapeHtml(token)}">
              <input type="hidden" name="id" value="${escapeHtml(topic.id)}">
              <button class="secondary">Remover</button>
            </form>
          </td>
        </tr>
      `).join("")}</tbody>
    </table>` : "<p>Nenhum topico publicado ainda.</p>"}
    <h2>Pedidos</h2>
    ${renderOrdersTable(readOrders(), token)}
  `, viewer);
}

async function handlePost(req, res, pathname) {
  const body = querystring.parse(await readBody(req));
  const orders = readOrders();
  const viewer = getViewer(req);

  if (pathname === "/api/register") {
    const username = sanitizeAccount(body.username);
    const email = sanitizeText(body.email, 120);
    const password = String(body.password || "");
    if (!username || password.length < 4) return redirect(res, "/register?erro=dados");
    const users = readUsers();
    if (users.some(user => normalizeUsername(user.username) === normalizeUsername(username))) {
      return redirect(res, "/register?erro=existe");
    }
    const user = {
      username,
      email,
      passwordHash: hashPassword(password),
      adminLevel: 0,
      createdAt: new Date().toISOString(),
    };
    users.push(user);
    saveUsers(users);
    setSessionCookie(res, createSession(username));
    return redirect(res, "/perfil");
  }

  if (pathname === "/api/login") {
    const username = sanitizeAccount(body.username);
    const password = String(body.password || "");
    const user = readUsers().find(item => normalizeUsername(item.username) === normalizeUsername(username));
    if (!user || !verifyPassword(password, user.passwordHash)) return redirect(res, "/login?erro=login");
    setSessionCookie(res, createSession(user.username));
    return redirect(res, "/perfil");
  }

  if (pathname === "/api/forum-topic") {
    if (!viewer) return redirect(res, "/login?erro=auth");
    const author = viewer.username;
    const title = sanitizeText(body.title, 90);
    const category = sanitizeCategory(body.category);
    const target = sanitizeText(body.target, 24);
    const evidence = sanitizeText(body.evidence, 180);
    const text = sanitizeLongText(body.body, 2000);
    if (!author || title.length < 6 || text.length < 20) return redirect(res, `/forum/new?categoria=${encodeURIComponent(category)}&erro=dados`);

    const topics = readTopics();
    const topic = {
      id: makeTopicId(),
      category,
      status: "open",
      author,
      title,
      target,
      evidence,
      body: text,
      createdAt: new Date().toISOString(),
      updatedAt: new Date().toISOString(),
      replies: [],
    };
    topics.push(topic);
    saveTopics(topics);
    return redirect(res, `/forum/topico?id=${encodeURIComponent(topic.id)}`);
  }

  if (pathname === "/api/forum-reply") {
    if (!viewer) return redirect(res, "/login?erro=auth");
    const id = sanitizeText(body.id, 64);
    const author = viewer.username;
    const text = sanitizeLongText(body.body, 1200);
    const topics = readTopics();
    const topic = topics.find(item => item.id === id);
    if (!topic || !author || text.length < 3) return redirect(res, "/forum?erro=resposta");
    topic.replies = topic.replies || [];
    topic.replies.push({ author, body: text, createdAt: new Date().toISOString() });
    topic.updatedAt = new Date().toISOString();
    saveTopics(topics);
    return redirect(res, `/forum/topico?id=${encodeURIComponent(topic.id)}`);
  }

  if (pathname === "/api/order") {
    const account = sanitizeAccount(body.account);
    const level = Number(body.level);
    const days = Math.max(1, Math.min(365, Number(body.days || plans[level]?.days || 30)));
    if (!account || !plans[level]) return redirect(res, "/?erro=dados");

    const order = {
      id: makeOrderId(),
      account,
      level,
      days,
      amount: Math.ceil((plans[level].price * days) / plans[level].days),
      status: "pending",
      createdAt: new Date().toISOString(),
      paymentRef: "",
      note: "pedido_player",
    };
    appendOrder(order);
    return res.end(page("Pedido VIP", `
      <h1>Pedido criado</h1>
      <div class="card">
        <p>Pedido: <strong>${escapeHtml(order.id)}</strong></p>
        <p>Conta: <strong>${escapeHtml(order.account)}</strong></p>
        <p>Plano: <strong>${escapeHtml(plans[level].name)}</strong> por ${order.days} dias</p>
        <p>Valor: <strong>R$ ${order.amount}</strong></p>
        <p>Pix: <strong>${escapeHtml(PIX_KEY)}</strong></p>
        <p>Envie o comprovante para a staff. Depois de aprovado, use <code>/ativarvip</code> no servidor.</p>
      </div>
      <p><a href="/">Voltar</a></p>
    `));
  }

  const tokenAccess = body.token === TOKEN;
  const staffLevel = sanitizeAdminLevel(viewer?.adminLevel);
  const staffAccess = staffLevel >= 1;
  const canManageUsers = tokenAccess || staffLevel >= 5;
  const adminBack = suffix => {
    const extra = suffix ? suffix.replace(/^\?/, "&") : "";
    return tokenAccess ? `/admin?token=${encodeURIComponent(TOKEN)}${extra}` : `/admin${suffix || ""}`;
  };

  if (!tokenAccess && !staffAccess) return redirect(res, "/admin?erro=token");

  if (pathname === "/api/admin-user-create") {
    if (!canManageUsers) return redirect(res, adminBack("?erro=permissao"));
    const username = sanitizeAccount(body.username);
    const email = sanitizeText(body.email, 120);
    const password = String(body.password || "");
    const adminLevel = Math.max(1, sanitizeAdminLevel(body.adminLevel));
    if (!username || password.length < 4) return redirect(res, adminBack("?erro=usuario"));
    const users = readUsers();
    if (users.some(user => normalizeUsername(user.username) === normalizeUsername(username))) {
      return redirect(res, adminBack("?erro=existe"));
    }
    users.push({
      username,
      email,
      passwordHash: hashPassword(password),
      adminLevel,
      createdAt: new Date().toISOString(),
    });
    saveUsers(users);
    return redirect(res, adminBack("?ok=staff"));
  }

  if (pathname === "/api/admin-user-level") {
    if (!canManageUsers) return redirect(res, adminBack("?erro=permissao"));
    const username = sanitizeAccount(body.username);
    const adminLevel = sanitizeAdminLevel(body.adminLevel);
    const users = readUsers();
    const user = users.find(item => normalizeUsername(item.username) === normalizeUsername(username));
    if (!user) return redirect(res, adminBack("?erro=usuario"));
    user.adminLevel = adminLevel;
    saveUsers(users);
    return redirect(res, adminBack("?ok=nivel"));
  }

  if (pathname === "/api/forum-status") {
    const id = sanitizeText(body.id, 64);
    const status = ["open", "staff", "resolved", "rejected"].includes(String(body.status)) ? String(body.status) : "open";
    const topics = readTopics();
    const topic = topics.find(item => item.id === id);
    if (!topic) return redirect(res, adminBack("?erro=topico"));
    topic.status = status;
    topic.updatedAt = new Date().toISOString();
    saveTopics(topics);
    return redirect(res, adminBack("?ok=forum"));
  }

  if (pathname === "/api/forum-delete") {
    const id = sanitizeText(body.id, 64);
    const topics = readTopics();
    saveTopics(topics.filter(item => item.id !== id));
    return redirect(res, adminBack("?ok=removido"));
  }

  if (pathname === "/api/approve") {
    const id = sanitizeText(body.id, 64);
    const order = orders.find(item => item.id === id);
    if (!order || order.status !== "pending") return redirect(res, adminBack("?erro=pedido"));
    order.status = "approved";
    order.approvedAt = new Date().toISOString();
    order.paymentRef = sanitizeText(body.paymentRef, 80);
    appendGrant(order.account, order.level, order.days, order.id);
    saveOrders(orders);
    return redirect(res, adminBack("?ok=aprovado"));
  }

  if (pathname === "/api/direct-grant") {
    const account = sanitizeAccount(body.account);
    const level = Number(body.level);
    const days = Math.max(1, Math.min(365, Number(body.days || 30)));
    if (!account || !plans[level]) return redirect(res, adminBack("?erro=dados"));
    const order = {
      id: makeOrderId(),
      account,
      level,
      days,
      amount: 0,
      status: "approved",
      createdAt: new Date().toISOString(),
      approvedAt: new Date().toISOString(),
      paymentRef: sanitizeText(body.note, 80),
      note: "grant_direto",
    };
    appendOrder(order);
    appendGrant(account, level, days, order.id);
    return redirect(res, adminBack("?ok=grant"));
  }

  redirect(res, "/");
}

function redirect(res, location) {
  res.writeHead(303, { Location: location });
  res.end();
}

function send(res, status, body, contentType = "text/html; charset=utf-8") {
  res.writeHead(status, { "Content-Type": contentType });
  res.end(body);
}

ensureStorage();

const server = http.createServer(async (req, res) => {
  try {
    const url = new URL(req.url, `http://${req.headers.host || "localhost"}`);
    const viewer = getViewer(req);
    if (req.method === "GET" && url.pathname === "/") return send(res, 200, siteHome(viewer));
    if (req.method === "GET" && url.pathname === "/vip") return send(res, 200, vipHome(viewer));
    if (req.method === "GET" && url.pathname === "/forum") return send(res, 200, forumHome(url.searchParams.get("categoria") ? sanitizeCategory(url.searchParams.get("categoria")) : "", viewer));
    if (req.method === "GET" && url.pathname === "/forum/new") return send(res, 200, forumNew(url.searchParams.get("categoria") || "duvida", viewer));
    if (req.method === "GET" && url.pathname === "/denuncias/nova") return send(res, 200, forumNew("denuncia", viewer));
    if (req.method === "GET" && url.pathname === "/forum/topico") return send(res, 200, forumTopic(sanitizeText(url.searchParams.get("id"), 64), viewer));
    if (req.method === "GET" && url.pathname === "/info") return send(res, 200, infoPage(viewer));
    if (req.method === "GET" && url.pathname === "/login") return send(res, 200, loginPage(viewer));
    if (req.method === "GET" && url.pathname === "/register") return send(res, 200, registerPage(viewer));
    if (req.method === "GET" && url.pathname === "/perfil") return send(res, 200, profilePage(viewer));
    if (req.method === "GET" && url.pathname === "/logout") {
      clearSessionCookie(res);
      return redirect(res, "/");
    }
    if (req.method === "GET" && url.pathname === "/admin") return send(res, 200, admin(url.searchParams.get("token") || "", viewer));
    if (req.method === "POST") return handlePost(req, res, url.pathname);
    send(res, 404, page("Nao encontrado", "<h1>404</h1><p>Rota nao encontrada.</p>", viewer));
  } catch (error) {
    send(res, 500, page("Erro", `<h1>Erro</h1><p>${escapeHtml(error.message)}</p>`));
  }
});

server.listen(PORT, HOST, () => {
  console.log(`Site da comunidade rodando em http://${HOST === "0.0.0.0" ? "127.0.0.1" : HOST}:${PORT}`);
  console.log("Rotas: /forum, /denuncias/nova, /info, /vip e /admin");
  console.log("Defina VIP_PANEL_TOKEN, VIP_PIX_KEY e PUBLIC_SERVER_IP antes de usar em producao.");
});
