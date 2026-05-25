#if defined _nova_modbot_included
    #endinput
#endif
#define _nova_modbot_included

new gBotMessages[BOT_MAX_MESSAGES][BOT_MESSAGE_SIZE];
new gBotMessageCount;
new gBotMessageIndex;
new gBotBadWords[BOT_MAX_BADWORDS][BOT_BADWORD_SIZE];
new gBotBadWordCount;
new gBotWarnings[MAX_PLAYERS];
new gBotTimer;

forward Bot_UpdateAll();

stock Bot_IsConfigLine(line[])
{
    new index = SkipSpaces(line, 0);

    if (line[index] == 0 || line[index] == '#')
    {
        return 0;
    }
    return 1;
}

stock Bot_CopyTrimmedLine(source[], output[], size = sizeof(output))
{
    new index = SkipSpaces(source, 0);
    format(output, size, "%s", source[index]);
    return 1;
}

stock Bot_CreateDefaultMessagesFile()
{
    new File:file = fopen(BOT_MESSAGES_FILE, io_write);

    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Uma mensagem por linha. Linhas com # sao ignoradas.\r\n");
    fwrite(file, "Use /menu para acessar os principais sistemas por dialog.\r\n");
    fwrite(file, "Use /admins para ver a equipe online em uma dialog.\r\n");
    fwrite(file, "Encontrou bug ou problema no servidor? Use /bug para enviar um relato para a staff.\r\n");
    fwrite(file, "Durante Alpha, a staff acompanha o servidor com /statusserver e /bugs.\r\n");
    fwrite(file, "Respeite o RP. Anti-RPG, ofensas e preconceito geram punicao.\r\n");
    fwrite(file, "Use /gps para marcar Prefeitura, Hospital, Banco, Postos e empregos.\r\n");
    fwrite(file, "Fome e sede caem com o tempo. Compre comida em lojas, restaurantes ou pelo celular.\r\n");
    fwrite(file, "Postos de gasolina vendem combustivel por NPC; use /abastecer perto da bomba.\r\n");
    fwrite(file, "Interiores publicos tem recepcao, balcao e pontos 3D para atendimento.\r\n");
    fwrite(file, "Prefeitura emite documentos, mostra empregos e organiza licencas.\r\n");
    fwrite(file, "Hospital atende ferimentos e recebe jogadores que morrerem.\r\n");
    fwrite(file, "Banco, caixas e celular permitem saldo, PIX, multas e servicos financeiros.\r\n");
    fwrite(file, "Radares aplicam multas automaticas; consulte pelo GovBR no celular.\r\n");
    fwrite(file, "Use /ajuda para ver comandos por categoria e /tutorial para aprender o servidor.\r\n");
    fclose(file);
    return 1;
}

stock Bot_CreateDefaultBadWordsFile()
{
    new File:file = fopen(BOT_BADWORDS_FILE, io_write);

    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Uma palavra/termo bloqueado por linha. Linhas com # sao ignoradas.\r\n");
    fwrite(file, "# Adicione aqui termos ofensivos, preconceituosos, racistas ou anti-RP do seu servidor.\r\n");
    fwrite(file, "fdp\r\n");
    fwrite(file, "merda\r\n");
    fwrite(file, "porra\r\n");
    fwrite(file, "caralho\r\n");
    fwrite(file, "puta\r\n");
    fwrite(file, "lixo\r\n");
    fclose(file);
    return 1;
}

stock Bot_LoadMessages()
{
    new line[160];
    new File:file;

    gBotMessageCount = 0;
    gBotMessageIndex = 0;

    if (!fexist(BOT_MESSAGES_FILE))
    {
        Bot_CreateDefaultMessagesFile();
    }

    file = fopen(BOT_MESSAGES_FILE, io_read);
    if (!file)
    {
        print("[Bot] Nao foi possivel abrir bot_messages.txt.");
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)) && gBotMessageCount < BOT_MAX_MESSAGES)
    {
        if (!Bot_IsConfigLine(line))
        {
            continue;
        }

        Bot_CopyTrimmedLine(line, gBotMessages[gBotMessageCount], BOT_MESSAGE_SIZE);
        gBotMessageCount++;
    }

    fclose(file);
    printf("[Bot] %d mensagens carregadas.", gBotMessageCount);
    return 1;
}

stock Bot_LoadBadWords()
{
    new line[96];
    new File:file;

    gBotBadWordCount = 0;

    if (!fexist(BOT_BADWORDS_FILE))
    {
        Bot_CreateDefaultBadWordsFile();
    }

    file = fopen(BOT_BADWORDS_FILE, io_read);
    if (!file)
    {
        print("[Bot] Nao foi possivel abrir bot_badwords.txt.");
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)) && gBotBadWordCount < BOT_MAX_BADWORDS)
    {
        if (!Bot_IsConfigLine(line))
        {
            continue;
        }

        Bot_CopyTrimmedLine(line, gBotBadWords[gBotBadWordCount], BOT_BADWORD_SIZE);
        gBotBadWordCount++;
    }

    fclose(file);
    printf("[Bot] %d termos bloqueados carregados.", gBotBadWordCount);
    return 1;
}

stock Bot_Reload()
{
    Bot_LoadMessages();
    Bot_LoadBadWords();
    return 1;
}

stock Bot_Init()
{
    Bot_Reload();
    if (gBotTimer)
    {
        KillTimer(gBotTimer);
    }
    gBotTimer = SetTimer("Bot_UpdateAll", BOT_UPDATE_INTERVAL, 1);
    return 1;
}

stock Bot_Exit()
{
    if (gBotTimer)
    {
        KillTimer(gBotTimer);
        gBotTimer = 0;
    }
    return 1;
}

stock Bot_SendStaffAlert(text[])
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && PlayerInfo[playerid][pLogged] && HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
        {
            SendClientMessage(playerid, COLOR_ADMIN, text);
        }
    }
    return 1;
}

stock Bot_ResetPlayer(playerid)
{
    gBotWarnings[playerid] = 0;
    return 1;
}

stock Moderation_JailPlayer(adminid, targetid, seconds, reason[])
{
    new name[MAX_PLAYER_NAME + 1];
    new targetName[MAX_PLAYER_NAME + 1];
    new message[144];

    if (seconds < JAIL_MIN_SECONDS)
    {
        seconds = JAIL_MIN_SECONDS;
    }

    GetPlayerNameEx(targetid, targetName, sizeof(targetName));
    PlayerInfo[targetid][pJailTime] = seconds;
    PlayerInfo[targetid][pJailCrimeId] = 10;
    PlayerInfo[targetid][pAdminJail] = 1;
    World_SendPlayerToPoliceCell(targetid);
    SaveAccountNow(targetid, 0);

    if (adminid == INVALID_PLAYER_ID)
    {
        format(message, sizeof(message), "[BOT] %s foi punido por %d min. Motivo: %s", targetName, seconds / 60, reason);
    }
    else
    {
        GetPlayerNameEx(adminid, name, sizeof(name));
        format(message, sizeof(message), "[ADMIN] %s puniu %s por %d min. Motivo: %s", name, targetName, seconds / 60, reason);
    }
    SendClientMessageToAll(COLOR_ADMIN, message);
    WriteServerLog(LOG_PUNISH_FILE, "JAIL", message);
    return 1;
}

stock Moderation_UnjailPlayer(adminid, targetid)
{
    new name[MAX_PLAYER_NAME + 1];
    new targetName[MAX_PLAYER_NAME + 1];
    new message[144];

    GetPlayerNameEx(targetid, targetName, sizeof(targetName));
    PlayerInfo[targetid][pJailTime] = 0;
    PlayerInfo[targetid][pJailCrimeId] = 0;
    PlayerInfo[targetid][pAdminJail] = 0;
    World_ReleaseFromPoliceCell(targetid);
    SaveAccountNow(targetid, 0);

    if (adminid == INVALID_PLAYER_ID)
    {
        format(message, sizeof(message), "[BOT] %s foi liberado da punicao administrativa.", targetName);
    }
    else
    {
        GetPlayerNameEx(adminid, name, sizeof(name));
        format(message, sizeof(message), "[ADMIN] %s liberou %s da punicao administrativa.", name, targetName);
    }
    SendClientMessageToAll(COLOR_ADMIN, message);
    WriteServerLog(LOG_PUNISH_FILE, "UNJAIL", message);
    return 1;
}

stock Moderation_MutePlayer(adminid, targetid, seconds, reason[])
{
    new name[MAX_PLAYER_NAME + 1];
    new targetName[MAX_PLAYER_NAME + 1];
    new message[144];

    if (seconds < 60)
    {
        seconds = 60;
    }

    GetPlayerNameEx(targetid, targetName, sizeof(targetName));
    PlayerInfo[targetid][pMuteTime] = seconds;
    SaveAccountNow(targetid, 0);

    if (adminid == INVALID_PLAYER_ID)
    {
        format(message, sizeof(message), "[BOT] %s foi mutado por %d min. Motivo: %s", targetName, seconds / 60, reason);
    }
    else
    {
        GetPlayerNameEx(adminid, name, sizeof(name));
        format(message, sizeof(message), "[ADMIN] %s mutou %s por %d min. Motivo: %s", name, targetName, seconds / 60, reason);
    }
    SendClientMessageToAll(COLOR_ADMIN, message);
    WriteServerLog(LOG_PUNISH_FILE, "MUTE", message);
    return 1;
}

stock Moderation_UnmutePlayer(adminid, targetid)
{
    new name[MAX_PLAYER_NAME + 1];
    new targetName[MAX_PLAYER_NAME + 1];
    new message[144];

    GetPlayerNameEx(targetid, targetName, sizeof(targetName));
    PlayerInfo[targetid][pMuteTime] = 0;
    SaveAccountNow(targetid, 0);

    if (adminid == INVALID_PLAYER_ID)
    {
        format(message, sizeof(message), "[BOT] %s foi desmutado.", targetName);
    }
    else
    {
        GetPlayerNameEx(adminid, name, sizeof(name));
        format(message, sizeof(message), "[ADMIN] %s desmutou %s.", name, targetName);
    }
    SendClientMessageToAll(COLOR_ADMIN, message);
    WriteServerLog(LOG_PUNISH_FILE, "UNMUTE", message);
    return 1;
}

stock Moderation_WarnPlayer(adminid, targetid, reason[])
{
    new name[MAX_PLAYER_NAME + 1];
    new targetName[MAX_PLAYER_NAME + 1];
    new message[144];

    GetPlayerNameEx(targetid, targetName, sizeof(targetName));

    if (adminid == INVALID_PLAYER_ID)
    {
        format(message, sizeof(message), "[BOT] Aviso para %s: %s", targetName, reason);
    }
    else
    {
        GetPlayerNameEx(adminid, name, sizeof(name));
        format(message, sizeof(message), "[ADMIN] %s avisou %s: %s", name, targetName, reason);
    }

    SendClientMessageToAll(COLOR_ADMIN, message);
    WriteServerLog(LOG_PUNISH_FILE, "WARN", message);
    SendClientMessage(targetid, COLOR_RED, "Aviso administrativo: respeite as regras do servidor.");
    return 1;
}

stock Bot_IsTextBlocked(text[], matched[], size = sizeof(matched))
{
    new index;

    for (index = 0; index < gBotBadWordCount; index++)
    {
        if (strlen(gBotBadWords[index]) < 2)
        {
            continue;
        }

        if (strfind(text, gBotBadWords[index], true) != -1)
        {
            format(matched, size, "%s", gBotBadWords[index]);
            return 1;
        }
    }

    matched[0] = 0;
    return 0;
}

stock Bot_CheckPlayerChat(playerid, text[])
{
    new matched[BOT_BADWORD_SIZE];
    new name[MAX_PLAYER_NAME + 1];
    new alert[144];

    if (HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return 1;
    }

    if (!Bot_IsTextBlocked(text, matched, sizeof(matched)))
    {
        return 1;
    }

    gBotWarnings[playerid]++;
    GetPlayerNameEx(playerid, name, sizeof(name));

    format(alert, sizeof(alert), "[BOT] Chat bloqueado de %s. Termo configurado detectado: %s", name, matched);
    Bot_SendStaffAlert(alert);
    WriteServerLog(LOG_CHAT_FILTER_FILE, "BLOCKED", alert);

    if (gBotWarnings[playerid] == 1)
    {
        SendClientMessage(playerid, COLOR_RED, "Mensagem bloqueada. Ofensas, preconceito e baixo calao nao sao permitidos.");
        SendClientMessage(playerid, COLOR_ORANGE, "Aviso 1/3. Na proxima voce podera ser mutado automaticamente.");
    }
    else if (gBotWarnings[playerid] == 2)
    {
        Moderation_MutePlayer(INVALID_PLAYER_ID, playerid, BOT_WARN_MUTE_SECONDS, "linguagem proibida no chat");
    }
    else
    {
        Moderation_JailPlayer(INVALID_PLAYER_ID, playerid, BOT_WARN_JAIL_SECONDS, "reincidencia em linguagem proibida");
        gBotWarnings[playerid] = 0;
    }

    return 0;
}

public Bot_UpdateAll()
{
    new message[160];

    if (gBotMessageCount <= 0)
    {
        return 1;
    }

    if (gBotMessageIndex >= gBotMessageCount)
    {
        gBotMessageIndex = 0;
    }

    format(message, sizeof(message), "[BOT] %s", gBotMessages[gBotMessageIndex]);
    SendClientMessageToAll(COLOR_YELLOW, message);
    gBotMessageIndex++;
    return 1;
}
