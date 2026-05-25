import fs from "node:fs";
import path from "node:path";

const SECTOR_SIZE = 2048;

function usage() {
  console.error("Uso: node patch_img_v2.mjs <gta3.img> <pasta-replacements>");
  process.exit(2);
}

const [, , imgPath, replacementDir] = process.argv;
if (!imgPath || !replacementDir) usage();

if (!fs.existsSync(imgPath)) throw new Error(`IMG nao encontrado: ${imgPath}`);
if (!fs.existsSync(replacementDir)) throw new Error(`Pasta nao encontrada: ${replacementDir}`);

const fd = fs.openSync(imgPath, "r+");
try {
  const header = Buffer.alloc(8);
  fs.readSync(fd, header, 0, 8, 0);
  if (header.subarray(0, 4).toString("ascii") !== "VER2") {
    throw new Error("Arquivo IMG nao parece estar no formato VER2.");
  }

  const entryCount = header.readUInt32LE(4);
  const dirSize = entryCount * 32;
  const directory = Buffer.alloc(dirSize);
  fs.readSync(fd, directory, 0, dirSize, 8);

  const entries = new Map();
  for (let i = 0; i < entryCount; i++) {
    const offset = i * 32;
    const name = directory
      .subarray(offset + 8, offset + 32)
      .toString("ascii")
      .replace(/\0.*$/, "")
      .toLowerCase();
    if (name) entries.set(name, { index: i, offset });
  }

  const replacements = fs
    .readdirSync(replacementDir, { withFileTypes: true })
    .filter((item) => item.isFile())
    .map((item) => item.name)
    .filter((name) => /\.(dff|txd)$/i.test(name))
    .sort((a, b) => a.localeCompare(b));

  let patched = 0;
  let skipped = 0;
  let fileSize = fs.fstatSync(fd).size;
  let nextSector = Math.ceil(fileSize / SECTOR_SIZE);

  for (const fileName of replacements) {
    const key = fileName.toLowerCase();
    const entry = entries.get(key);
    if (!entry) {
      skipped++;
      continue;
    }

    const sourcePath = path.join(replacementDir, fileName);
    const source = fs.readFileSync(sourcePath);
    const sectorCount = Math.ceil(source.length / SECTOR_SIZE);
    if (sectorCount > 0xffff) {
      throw new Error(`Arquivo grande demais para entrada IMG: ${fileName}`);
    }

    const writeOffset = nextSector * SECTOR_SIZE;
    fs.writeSync(fd, source, 0, source.length, writeOffset);

    const paddedSize = sectorCount * SECTOR_SIZE;
    if (paddedSize > source.length) {
      fs.writeSync(fd, Buffer.alloc(paddedSize - source.length), 0, paddedSize - source.length, writeOffset + source.length);
    }

    directory.writeUInt32LE(nextSector, entry.offset);
    directory.writeUInt16LE(sectorCount, entry.offset + 4);
    directory.writeUInt16LE(0, entry.offset + 6);

    nextSector += sectorCount;
    patched++;
  }

  fs.writeSync(fd, directory, 0, dirSize, 8);
  fs.ftruncateSync(fd, nextSector * SECTOR_SIZE);

  console.log(`IMG atualizado: ${patched} arquivos substituidos, ${skipped} sem entrada correspondente.`);
  console.log(`Novo tamanho: ${nextSector * SECTOR_SIZE} bytes.`);
} finally {
  fs.closeSync(fd);
}
