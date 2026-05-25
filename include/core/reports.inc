#if defined _nova_reports_included
    #endinput
#endif
#define _nova_reports_included

new gPlayerBugReportLineIndex[MAX_PLAYERS][BUG_REPORT_MAX_DIALOG_ITEMS];
new gPlayerBugReportDialogCount[MAX_PLAYERS];
new gPlayerBugReportDetailBack[MAX_PLAYERS];

stock BugReport_HasMeaningfulText(text[])
{
    new index;
    new count;
    new length = strlen(text);

    while (index < length)
    {
        if (text[index] > ' ')
        {
            count++;
            if (count >= BUG_REPORT_MIN_TEXT)
            {
                return 1;
            }
        }
        index++;
    }
    return 0;
}

stock BugReport_SanitizeText(source[], output[], size)
{
    new index;
    new offset;
    new length = strlen(source);

    while (index < length && offset < (size - 1))
    {
        if (source[index] == '|' || source[index] == 9 || source[index] == 10 || source[index] == 13)
        {
            output[offset] = ' ';
        }
        else
        {
            output[offset] = source[index];
        }

        offset++;
        index++;
    }

    output[offset] = 0;
    return 1;
}

stock BugReport_GetField(line[], field, output[], size)
{
    new current;
    new start;
    new end;
    new length = strlen(line);

    while (current < field)
    {
        end = strfind(line, "|", false, start);
        if (end == -1)
        {
            output[0] = 0;
            return 0;
        }
        start = end + 1;
        current++;
    }

    end = strfind(line, "|", false, start);
    if (end == -1)
    {
        end = length;
    }

    strmid(output, line, start, end, size);
    return 1;
}

stock BugReport_FormatSummary(line[], output[], size)
{
    return BugReport_FormatSummaryEx(line, 0, output, size);
}

stock BugReport_FormatSummaryEx(line[], reportid, output[], size)
{
    new date[24];
    new playerName[MAX_PLAYER_NAME + 1];
    new reportText[BUG_REPORT_TEXT_SIZE];
    new shortText[72];
    new priority[16];
    new status[16];
    new note[BUG_REPORT_TEXT_SIZE];
    new staff[MAX_PLAYER_NAME + 1];

    if (!BugReport_GetField(line, 0, date, sizeof(date)) || !BugReport_GetField(line, 1, playerName, sizeof(playerName)) || !BugReport_GetField(line, 8, reportText, sizeof(reportText)))
    {
        return 0;
    }

    BugReport_GetMeta(reportid, status, sizeof(status), priority, sizeof(priority), staff, sizeof(staff), note, sizeof(note));

    if (strlen(reportText) > 58)
    {
        strmid(shortText, reportText, 0, 58, sizeof(shortText));
        strcat(shortText, "...", sizeof(shortText));
    }
    else
    {
        format(shortText, sizeof(shortText), "%s", reportText);
    }

    if (reportid > 0)
    {
        format(output, size, "#%d\t%s\t%s\t%s\n", reportid, status, priority, shortText);
    }
    else
    {
        format(output, size, "%s\t%s\t%s\n", date, playerName, shortText);
    }
    return 1;
}

stock BugReport_ReadLineByIndex(reportLineIndex, output[], size)
{
    new File:file;
    new line[BUG_REPORT_LINE_SIZE];
    new currentReport;

    output[0] = 0;

    if (!fexist(BUG_REPORT_FILE))
    {
        return 0;
    }

    file = fopen(BUG_REPORT_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (line[0] == 0 || line[0] == '#')
        {
            continue;
        }

        currentReport++;

        if (currentReport == reportLineIndex)
        {
            format(output, size, "%s", line);
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

stock BugReport_GetMeta(reportid, status[], statusSize, priority[], prioritySize, staff[], staffSize, note[], noteSize)
{
    new File:file;
    new line[BUG_REPORT_LINE_SIZE];
    new idText[16];
    new value[BUG_REPORT_TEXT_SIZE];

    format(status, statusSize, "Aberto");
    format(priority, prioritySize, "Normal");
    staff[0] = 0;
    note[0] = 0;

    if (reportid <= 0 || !fexist(BUG_REPORT_UPDATES_FILE))
    {
        return 1;
    }

    file = fopen(BUG_REPORT_UPDATES_FILE, io_read);
    if (!file)
    {
        return 1;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (line[0] == 0 || line[0] == '#')
        {
            continue;
        }

        BugReport_GetField(line, 0, idText, sizeof(idText));
        if (!IsNumericString(idText) || strval(idText) != reportid)
        {
            continue;
        }

        BugReport_GetField(line, 2, value, sizeof(value));
        if (value[0] != 0)
        {
            format(status, statusSize, "%s", value);
        }

        BugReport_GetField(line, 3, value, sizeof(value));
        if (value[0] != 0)
        {
            format(priority, prioritySize, "%s", value);
        }

        BugReport_GetField(line, 4, value, sizeof(value));
        if (value[0] != 0)
        {
            format(staff, staffSize, "%s", value);
        }

        BugReport_GetField(line, 5, value, sizeof(value));
        if (value[0] != 0)
        {
            format(note, noteSize, "%s", value);
        }
    }

    fclose(file);
    return 1;
}

stock BugReport_NormalizePriority(input[], output[], size)
{
    if (strcmp(input, "baixa", true) == 0 || strcmp(input, "low", true) == 0)
    {
        format(output, size, "Baixa");
        return 1;
    }
    if (strcmp(input, "normal", true) == 0 || strcmp(input, "media", true) == 0)
    {
        format(output, size, "Normal");
        return 1;
    }
    if (strcmp(input, "alta", true) == 0 || strcmp(input, "high", true) == 0)
    {
        format(output, size, "Alta");
        return 1;
    }
    if (strcmp(input, "critica", true) == 0 || strcmp(input, "critico", true) == 0 || strcmp(input, "critical", true) == 0)
    {
        format(output, size, "Critica");
        return 1;
    }
    return 0;
}

stock BugReport_AppendMeta(playerid, reportid, status[], priority[], note[])
{
    new File:file;
    new staffName[MAX_PLAYER_NAME + 1];
    new cleanNote[BUG_REPORT_TEXT_SIZE];
    new line[BUG_REPORT_LINE_SIZE];
    new year;
    new month;
    new day;
    new hour;
    new minute;
    new second;

    if (!BugReport_ReadLineByIndex(reportid, line, sizeof(line)))
    {
        SendClientMessage(playerid, COLOR_RED, "ID de bug nao encontrado.");
        return 0;
    }

    file = fopen(BUG_REPORT_UPDATES_FILE, io_append);
    if (!file)
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel salvar a atualizacao do bug.");
        return 0;
    }

    BugReport_SanitizeText(note, cleanNote, sizeof(cleanNote));
    GetPlayerNameEx(playerid, staffName, sizeof(staffName));
    GetBrasiliaDateTime(year, month, day, hour, minute, second);

    format(line, sizeof(line), "%d|%04d-%02d-%02d %02d:%02d:%02d|%s|%s|%s|%s\r\n", reportid, year, month, day, hour, minute, second, status, priority, staffName, cleanNote);
    fwrite(file, line);
    fclose(file);
    WriteServerLog(LOG_BUG_FILE, "UPDATE", line);
    return 1;
}

stock BugReport_SendStaffAlert(playerid)
{
    new adminid;
    new name[MAX_PLAYER_NAME + 1];
    new message[128];
    new maxPlayers = GetMaxPlayers();

    GetPlayerNameEx(playerid, name, sizeof(name));
    format(message, sizeof(message), "[BUG] Novo relato de %s. Use /bugs para ler.", name);

    for (adminid = 0; adminid < maxPlayers; adminid++)
    {
        if (IsPlayerConnected(adminid) && PlayerInfo[adminid][pLogged] && HasAdminLevel(adminid, ADMIN_LEVEL_HELPER))
        {
            SendClientMessage(adminid, COLOR_ORANGE, message);
        }
    }
    return 1;
}

stock ShowBugReportInputDialog(playerid)
{
    ShowPlayerDialog(
        playerid,
        DIALOG_BUG_REPORT_INPUT,
        DIALOG_STYLE_INPUT,
        "Relatar bug ou problema",
        "Descreva o bug, erro, interior quebrado, comando com problema ou comportamento estranho.\n\nExemplo: Entrei no hospital e fiquei preso na saida.",
        "Enviar",
        "Cancelar"
    );
    return 1;
}

stock SaveBugReport(playerid, text[])
{
    new cleaned[BUG_REPORT_TEXT_SIZE];
    new playerName[MAX_PLAYER_NAME + 1];
    new line[BUG_REPORT_LINE_SIZE];
    new File:file;
    new year;
    new month;
    new day;
    new hour;
    new minute;
    new second;
    new Float:x;
    new Float:y;
    new Float:z;

    BugReport_SanitizeText(text, cleaned, sizeof(cleaned));

    if (!BugReport_HasMeaningfulText(cleaned))
    {
        SendClientMessage(playerid, COLOR_RED, "Descreva melhor o problema antes de enviar.");
        return ShowBugReportInputDialog(playerid);
    }

    file = fopen(BUG_REPORT_FILE, io_append);
    if (!file)
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel salvar o relato. Avise a staff.");
        return 1;
    }

    GetBrasiliaDateTime(year, month, day, hour, minute, second);
    GetPlayerNameEx(playerid, playerName, sizeof(playerName));
    GetPlayerPos(playerid, x, y, z);

    format(
        line,
        sizeof(line),
        "%04d-%02d-%02d %02d:%02d:%02d|%s|%s|%.2f|%.2f|%.2f|%d|%d|%s\r\n",
        year,
        month,
        day,
        hour,
        minute,
        second,
        playerName,
        PlayerInfo[playerid][pCharacterName],
        x,
        y,
        z,
        GetPlayerInterior(playerid),
        GetPlayerVirtualWorld(playerid),
        cleaned
    );
    fwrite(file, line);
    fclose(file);
    WriteServerLog(LOG_BUG_FILE, "REPORT", line);

    SendClientMessage(playerid, COLOR_GREEN, "Obrigado. Seu relato foi salvo e a staff foi avisada.");
    BugReport_SendStaffAlert(playerid);
    return 1;
}

stock ShowBugReportsDialog(playerid)
{
    new File:file;
    new rawLine[BUG_REPORT_LINE_SIZE];
    new summary[128];
    new summaries[BUG_REPORT_MAX_DIALOG_ITEMS][128];
    new reportIds[BUG_REPORT_MAX_DIALOG_ITEMS];
    new count;
    new index;
    new reportId;
    new displayIndex;
    new list[3072];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }

    gPlayerBugReportDialogCount[playerid] = 0;
    gPlayerBugReportDetailBack[playerid] = 0;

    if (!fexist(BUG_REPORT_FILE))
    {
        ShowPlayerDialog(playerid, DIALOG_BUG_REPORT_DETAIL, DIALOG_STYLE_MSGBOX, "Bugs reportados", "Nenhum relato encontrado ainda.", "Fechar", "");
        return 1;
    }

    file = fopen(BUG_REPORT_FILE, io_read);
    if (!file)
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel abrir bug_reports.txt.");
        return 1;
    }

    while (ReadFileLine(file, rawLine, sizeof(rawLine)))
    {
        if (rawLine[0] == 0 || rawLine[0] == '#')
        {
            continue;
        }

        reportId++;

        if (!BugReport_FormatSummaryEx(rawLine, reportId, summary, sizeof(summary)))
        {
            continue;
        }

        if (count >= BUG_REPORT_MAX_DIALOG_ITEMS)
        {
            for (index = 1; index < BUG_REPORT_MAX_DIALOG_ITEMS; index++)
            {
                format(summaries[index - 1], 128, "%s", summaries[index]);
                reportIds[index - 1] = reportIds[index];
            }
            count = BUG_REPORT_MAX_DIALOG_ITEMS - 1;
        }

        format(summaries[count], 128, "%s", summary);
        reportIds[count] = reportId;
        count++;
    }

    fclose(file);

    if (count <= 0)
    {
        ShowPlayerDialog(playerid, DIALOG_BUG_REPORT_DETAIL, DIALOG_STYLE_MSGBOX, "Bugs reportados", "Nenhum relato encontrado ainda.", "Fechar", "");
        return 1;
    }

    format(list, sizeof(list), "ID\tStatus\tPrioridade\tResumo\n");
    displayIndex = 0;

    for (index = count - 1; index >= 0; index--)
    {
        if (displayIndex >= BUG_REPORT_MAX_DIALOG_ITEMS)
        {
            break;
        }

        gPlayerBugReportLineIndex[playerid][displayIndex] = reportIds[index];
        strcat(list, summaries[index], sizeof(list));
        displayIndex++;
    }

    gPlayerBugReportDialogCount[playerid] = displayIndex;
    ShowPlayerDialog(playerid, DIALOG_BUG_REPORT_LIST, DIALOG_STYLE_TABLIST_HEADERS, "Bugs e problemas reportados", list, "Ler", "Fechar");
    return 1;
}

stock ShowBugReportDetail(playerid, reportLineIndex)
{
    new line[BUG_REPORT_LINE_SIZE];
    new date[24];
    new playerName[MAX_PLAYER_NAME + 1];
    new characterName[CHARACTER_NAME_SIZE];
    new posX[16];
    new posY[16];
    new posZ[16];
    new interior[8];
    new virtualWorld[8];
    new reportText[BUG_REPORT_TEXT_SIZE];
    new status[16];
    new priority[16];
    new staff[MAX_PLAYER_NAME + 1];
    new note[BUG_REPORT_TEXT_SIZE];
    new body[1536];

    if (!BugReport_ReadLineByIndex(reportLineIndex, line, sizeof(line)))
    {
        SendClientMessage(playerid, COLOR_RED, "Relato nao encontrado. Tente abrir /bugs novamente.");
        return ShowBugReportsDialog(playerid);
    }

    BugReport_GetField(line, 0, date, sizeof(date));
    BugReport_GetField(line, 1, playerName, sizeof(playerName));
    BugReport_GetField(line, 2, characterName, sizeof(characterName));
    BugReport_GetField(line, 3, posX, sizeof(posX));
    BugReport_GetField(line, 4, posY, sizeof(posY));
    BugReport_GetField(line, 5, posZ, sizeof(posZ));
    BugReport_GetField(line, 6, interior, sizeof(interior));
    BugReport_GetField(line, 7, virtualWorld, sizeof(virtualWorld));
    BugReport_GetField(line, 8, reportText, sizeof(reportText));
    BugReport_GetMeta(reportLineIndex, status, sizeof(status), priority, sizeof(priority), staff, sizeof(staff), note, sizeof(note));

    if (note[0] == 0)
    {
        format(staff, sizeof(staff), "Ninguem");
        format(note, sizeof(note), "Sem resposta ainda.");
    }

    format(
        body,
        sizeof(body),
        "ID: #%d\nStatus: %s\nPrioridade: %s\nUltima staff: %s\nResposta: %s\n\nData: %s\nPlayer: %s\nPersonagem: %s\nPosicao: %s, %s, %s\nInterior/VW: %s / %s\n\nRelato:\n%s\n\nAcoes:\n/bugprio %d [baixa/normal/alta/critica]\n/bugresponder %d [resposta]\n/bugresolver %d [resposta opcional]\n/bugabrir %d [motivo opcional]",
        reportLineIndex,
        status,
        priority,
        staff,
        note,
        date,
        playerName,
        characterName,
        posX,
        posY,
        posZ,
        interior,
        virtualWorld,
        reportText,
        reportLineIndex,
        reportLineIndex,
        reportLineIndex,
        reportLineIndex
    );

    gPlayerBugReportDetailBack[playerid] = 1;
    ShowPlayerDialog(playerid, DIALOG_BUG_REPORT_DETAIL, DIALOG_STYLE_MSGBOX, "Detalhe do bug", body, "Voltar", "Fechar");
    return 1;
}

stock BugReport_UpdateMetaCommand(playerid, reportid, status[], priority[], note[], successMessage[])
{
    new message[144];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }

    if (!BugReport_AppendMeta(playerid, reportid, status, priority, note))
    {
        return 1;
    }

    format(message, sizeof(message), "%s #%d.", successMessage, reportid);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock BugReport_HandleAdminCommands(playerid, cmdtext[])
{
    new command[32];
    new param[16];
    new priorityParam[24];
    new priority[16];
    new status[16];
    new staff[MAX_PLAYER_NAME + 1];
    new note[BUG_REPORT_TEXT_SIZE];
    new currentNote[BUG_REPORT_TEXT_SIZE];
    new line[BUG_REPORT_LINE_SIZE];
    new reportid;
    new index;

    index = GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/bugprio", true) != 0 &&
        strcmp(command, "/bugprioridade", true) != 0 &&
        strcmp(command, "/bugresponder", true) != 0 &&
        strcmp(command, "/bugnota", true) != 0 &&
        strcmp(command, "/bugresolver", true) != 0 &&
        strcmp(command, "/bugabrir", true) != 0)
    {
        return 0;
    }

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }

    if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
    {
        if (strcmp(command, "/bugprio", true) == 0 || strcmp(command, "/bugprioridade", true) == 0)
        {
            return SendUsage(playerid, "/bugprio [id] [baixa/normal/alta/critica]");
        }
        if (strcmp(command, "/bugresponder", true) == 0 || strcmp(command, "/bugnota", true) == 0)
        {
            return SendUsage(playerid, "/bugresponder [id] [resposta]");
        }
        if (strcmp(command, "/bugresolver", true) == 0)
        {
            return SendUsage(playerid, "/bugresolver [id] [resposta opcional]");
        }
        return SendUsage(playerid, "/bugabrir [id] [motivo opcional]");
    }

    reportid = strval(param);
    if (reportid <= 0 || !BugReport_ReadLineByIndex(reportid, line, sizeof(line)))
    {
        SendClientMessage(playerid, COLOR_RED, "ID de bug nao encontrado.");
        return 1;
    }

    BugReport_GetMeta(reportid, status, sizeof(status), priority, sizeof(priority), staff, sizeof(staff), currentNote, sizeof(currentNote));

    if (strcmp(command, "/bugprio", true) == 0 || strcmp(command, "/bugprioridade", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, priorityParam, sizeof(priorityParam)) || !BugReport_NormalizePriority(priorityParam, priority, sizeof(priority)))
        {
            return SendUsage(playerid, "/bugprio [id] [baixa/normal/alta/critica]");
        }

        if (currentNote[0] == 0)
        {
            format(currentNote, sizeof(currentNote), "Prioridade ajustada.");
        }

        return BugReport_UpdateMetaCommand(playerid, reportid, status, priority, currentNote, "Prioridade atualizada no bug");
    }

    if (strcmp(command, "/bugresponder", true) == 0 || strcmp(command, "/bugnota", true) == 0)
    {
        if (!GetRemainingText(cmdtext, index, note, sizeof(note)))
        {
            return SendUsage(playerid, "/bugresponder [id] [resposta]");
        }

        return BugReport_UpdateMetaCommand(playerid, reportid, status, priority, note, "Resposta adicionada no bug");
    }

    if (strcmp(command, "/bugresolver", true) == 0)
    {
        if (!GetRemainingText(cmdtext, index, note, sizeof(note)))
        {
            format(note, sizeof(note), "Resolvido pela staff.");
        }

        return BugReport_UpdateMetaCommand(playerid, reportid, "Resolvido", priority, note, "Bug marcado como resolvido");
    }

    if (!GetRemainingText(cmdtext, index, note, sizeof(note)))
    {
        format(note, sizeof(note), "Reaberto pela staff.");
    }

    return BugReport_UpdateMetaCommand(playerid, reportid, "Aberto", priority, note, "Bug reaberto");
}

stock HandleBugReportInputDialog(playerid, response, inputtext[])
{
    if (!response)
    {
        return 1;
    }

    return SaveBugReport(playerid, inputtext);
}

stock HandleBugReportsListDialog(playerid, response, listitem)
{
    if (!response)
    {
        return 1;
    }

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }

    if (listitem < 0 || listitem >= gPlayerBugReportDialogCount[playerid])
    {
        return ShowBugReportsDialog(playerid);
    }

    return ShowBugReportDetail(playerid, gPlayerBugReportLineIndex[playerid][listitem]);
}

stock HandleBugReportDetailDialog(playerid, response)
{
    if (response && gPlayerBugReportDetailBack[playerid])
    {
        gPlayerBugReportDetailBack[playerid] = 0;
        return ShowBugReportsDialog(playerid);
    }

    gPlayerBugReportDetailBack[playerid] = 0;
    return 1;
}
