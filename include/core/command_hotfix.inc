#if defined _nova_command_hotfix_included
    #endinput
#endif
#define _nova_command_hotfix_included

#define COMMAND_HOTFIX_FILE         "command_hotfixes.txt"
#define COMMAND_HOTFIX_PROMOTE_FILE "command_hotfix_promote.txt"
#define COMMAND_HOTFIX_MAX          (64)
#define COMMAND_HOTFIX_CMD_SIZE     (32)
#define COMMAND_HOTFIX_TARGET_SIZE  (96)

new gCommandHotfixFrom[COMMAND_HOTFIX_MAX][COMMAND_HOTFIX_CMD_SIZE];
new gCommandHotfixTo[COMMAND_HOTFIX_MAX][COMMAND_HOTFIX_TARGET_SIZE];
new gCommandHotfixCount;

stock CommandHotfix_CreateDefaultFile()
{
    new File:file = fopen(COMMAND_HOTFIX_FILE, io_write);

    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Hotfix de comandos sem recompilar a GM.\r\n");
    fwrite(file, "# Formato: /comando_quebrado=/comando_certo\r\n");
    fwrite(file, "# Exemplo: /trampo=/trabalhar\r\n");
    fwrite(file, "# Depois use /cmdfix reload dentro do servidor.\r\n");
    fclose(file);
    return 1;
}

stock CommandHotfix_Add(source[], target[])
{
    if (gCommandHotfixCount >= COMMAND_HOTFIX_MAX)
    {
        return 0;
    }
    if (source[0] != '/' || target[0] != '/')
    {
        return 0;
    }

    format(gCommandHotfixFrom[gCommandHotfixCount], COMMAND_HOTFIX_CMD_SIZE, "%s", source);
    format(gCommandHotfixTo[gCommandHotfixCount], COMMAND_HOTFIX_TARGET_SIZE, "%s", target);
    gCommandHotfixCount++;
    return 1;
}

stock CommandHotfix_Load()
{
    new File:file;
    new line[160];
    new source[COMMAND_HOTFIX_CMD_SIZE];
    new target[COMMAND_HOTFIX_TARGET_SIZE];
    new pos;
    new loaded;

    gCommandHotfixCount = 0;
    if (!fexist(COMMAND_HOTFIX_FILE))
    {
        CommandHotfix_CreateDefaultFile();
    }

    file = fopen(COMMAND_HOTFIX_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)) && gCommandHotfixCount < COMMAND_HOTFIX_MAX)
    {
        Cfg_Trim(line);
        if (line[0] == 0 || line[0] == '#')
        {
            continue;
        }

        pos = strfind(line, "=", false);
        if (pos <= 0)
        {
            continue;
        }

        strmid(source, line, 0, pos, sizeof(source));
        strmid(target, line, pos + 1, strlen(line), sizeof(target));
        Cfg_Trim(source);
        Cfg_Trim(target);

        if (CommandHotfix_Add(source, target))
        {
            loaded++;
        }
    }

    fclose(file);
    return loaded;
}

stock CommandHotfix_Init()
{
    new loaded = CommandHotfix_Load();
    new detail[80];

    format(detail, sizeof(detail), "loaded=%d file=%s", loaded, COMMAND_HOTFIX_FILE);
    WriteServerLog(LOG_ADMIN_FILE, "COMMAND_HOTFIX_INIT", detail);
    return 1;
}

stock CommandHotfix_Rewrite(playerid, cmdtext[], output[], size = sizeof(output))
{
    new command[COMMAND_HOTFIX_CMD_SIZE];
    new args[80];
    new index;
    new slot;
    new detail[160];

    index = GetCommandName(cmdtext, command, sizeof(command));
    for (slot = 0; slot < gCommandHotfixCount; slot++)
    {
        if (strcmp(command, gCommandHotfixFrom[slot], true) != 0)
        {
            continue;
        }

        if (GetRemainingText(cmdtext, index, args, sizeof(args)))
        {
            format(output, size, "%s %s", gCommandHotfixTo[slot], args);
        }
        else
        {
            format(output, size, "%s", gCommandHotfixTo[slot]);
        }

        format(detail, sizeof(detail), "from=%s to=%s", command, output);
        WritePlayerLog(LOG_COMMAND_AI_FILE, "COMMAND_HOTFIX", playerid, detail);
        return 1;
    }
    return 0;
}

stock CommandHotfix_ShowStatus(playerid)
{
    new message[128];

    format(message, sizeof(message), "CommandFix: %d hotfix(es) carregado(s). Arquivo: %s.", gCommandHotfixCount, COMMAND_HOTFIX_FILE);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(playerid, COLOR_GRAY, "Use /cmdfix reload ou /cmdfixadd /errado /certo.");
    return 1;
}

stock CommandHotfix_SaveAlias(source[], target[])
{
    new File:file = fopen(COMMAND_HOTFIX_FILE, io_append);
    new line[160];

    if (!file)
    {
        return 0;
    }

    format(line, sizeof(line), "%s=%s\r\n", source, target);
    fwrite(file, line);
    fclose(file);
    return 1;
}

stock CommandHotfix_SourceHasHandler(source[], route[], size = sizeof(route))
{
    route[0] = 0;
    Dispatch_GetCommandRoute(source, route, size);
    return (strcmp(route, "cadeia geral", true) != 0);
}

stock CommandHotfix_HandleCommands(playerid, cmdtext[])
{
    new command[32];
    new source[COMMAND_HOTFIX_CMD_SIZE];
    new target[COMMAND_HOTFIX_TARGET_SIZE];
    new route[48];
    new index;
    new loaded;
    new message[128];

    index = GetCommandName(cmdtext, command, sizeof(command));
    if (strcmp(command, "/cmdfix", true) != 0
        && strcmp(command, "/reloadcmdfix", true) != 0
        && strcmp(command, "/cmdfixadd", true) != 0)
    {
        return 0;
    }

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }

    if (strcmp(command, "/reloadcmdfix", true) == 0)
    {
        loaded = CommandHotfix_Load();
        format(message, sizeof(message), "CommandFix recarregado: %d hotfix(es).", loaded);
        SendClientMessage(playerid, COLOR_GREEN, message);
        return 1;
    }

    if (strcmp(command, "/cmdfixadd", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, source, sizeof(source))
            || !GetRemainingText(cmdtext, index, target, sizeof(target)))
        {
            return SendUsage(playerid, "/cmdfixadd [/comando_errado] [/comando_certo]");
        }
        if (source[0] != '/' || target[0] != '/')
        {
            return SendUsage(playerid, "/cmdfixadd [/comando_errado] [/comando_certo]");
        }
        if (CommandHotfix_SourceHasHandler(source, route, sizeof(route)))
        {
            format(message, sizeof(message), "Hotfix recusado: %s ja tem handler Pawn real (%s).", source, route);
            SendClientMessage(playerid, COLOR_ORANGE, message);
            WritePlayerLog(LOG_ADMIN_FILE, "COMMAND_HOTFIX_REJECT", playerid, message);
            return 1;
        }
        if (!CommandHotfix_SaveAlias(source, target))
        {
            SendClientMessage(playerid, COLOR_RED, "Nao foi possivel salvar command_hotfixes.txt.");
            return 1;
        }
        CommandHotfix_Load();
        SendClientMessage(playerid, COLOR_GREEN, "Hotfix de comando salvo e recarregado.");
        return 1;
    }

    GetNextParam(cmdtext, index, source, sizeof(source));
    if (strcmp(source, "reload", true) == 0)
    {
        loaded = CommandHotfix_Load();
        format(message, sizeof(message), "CommandFix recarregado: %d hotfix(es).", loaded);
        SendClientMessage(playerid, COLOR_GREEN, message);
        return 1;
    }

    return CommandHotfix_ShowStatus(playerid);
}
