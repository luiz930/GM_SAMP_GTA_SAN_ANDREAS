import { createWriteStream } from "node:fs";
import { mkdir } from "node:fs/promises";
import { dirname } from "node:path";
import { createDecipheriv } from "node:crypto";
import { pipeline } from "node:stream/promises";

function base64UrlToBuffer(value) {
  let text = value.replace(/-/g, "+").replace(/_/g, "/").replace(/,/g, "");
  while (text.length % 4) text += "=";
  return Buffer.from(text, "base64");
}

function bufferToWords(buffer) {
  const words = [];
  for (let i = 0; i < buffer.length; i += 4) {
    words.push(buffer.readUInt32BE(i));
  }
  return words;
}

function wordsToBuffer(words) {
  const buffer = Buffer.alloc(words.length * 4);
  words.forEach((word, index) => buffer.writeUInt32BE(word >>> 0, index * 4));
  return buffer;
}

function parseMegaUrl(url) {
  const oldMatch = url.match(/mega\.nz\/#!([^!]+)!([^!]+)/i);
  if (oldMatch) return { handle: oldMatch[1], key: oldMatch[2] };

  const newMatch = url.match(/mega\.nz\/file\/([^#]+)#(.+)$/i);
  if (newMatch) return { handle: newMatch[1], key: newMatch[2] };

  throw new Error("URL MEGA invalida.");
}

async function getDownloadInfo(handle) {
  const response = await fetch(`https://g.api.mega.co.nz/cs?id=${Date.now()}`, {
    method: "POST",
    headers: { "content-type": "application/json" },
    body: JSON.stringify([{ a: "g", g: 1, p: handle }]),
  });

  if (!response.ok) {
    throw new Error(`MEGA API HTTP ${response.status}`);
  }

  const payload = await response.json();
  const info = payload[0];
  if (typeof info === "number") {
    throw new Error(`MEGA API error ${info}`);
  }
  if (!info?.g) {
    throw new Error("MEGA nao retornou URL de download.");
  }
  return info;
}

async function main() {
  const [, , url, output] = process.argv;
  if (!url || !output) {
    throw new Error("Uso: node tools/mega_download.mjs <mega-url> <arquivo-saida>");
  }

  const { handle, key } = parseMegaUrl(url);
  const keyWords = bufferToWords(base64UrlToBuffer(key));
  if (keyWords.length !== 8) {
    throw new Error("Chave MEGA inesperada.");
  }

  const aesKey = wordsToBuffer([
    keyWords[0] ^ keyWords[4],
    keyWords[1] ^ keyWords[5],
    keyWords[2] ^ keyWords[6],
    keyWords[3] ^ keyWords[7],
  ]);
  const iv = wordsToBuffer([keyWords[4], keyWords[5], 0, 0]);

  const info = await getDownloadInfo(handle);
  console.log(`Baixando ${info.s || "?"} bytes de MEGA...`);

  await mkdir(dirname(output), { recursive: true });
  const response = await fetch(info.g);
  if (!response.ok || !response.body) {
    throw new Error(`Download HTTP ${response.status}`);
  }

  const decipher = createDecipheriv("aes-128-ctr", aesKey, iv);
  const file = createWriteStream(output);
  await pipeline(response.body, decipher, file);
  console.log(`Arquivo salvo em ${output}`);
}

main().catch((error) => {
  console.error(error.stack || error.message);
  process.exit(1);
});
