#if defined _nova_admin_included
    #endinput
#endif
#define _nova_admin_included

#define COMMAND_NOTFOUND_ALERT_MAX  (64)
#define DISPATCH_DEFER_VERSION      (1)
#define DISPATCH_DEFER_HEALTH       (2)
#define DISPATCH_DEFER_INTEGRITY    (3)
#define DISPATCH_DEFER_SELFTEST     (4)
#define DISPATCH_DEFER_RELEASE      (5)
#define DISPATCH_DEFER_DAILY        (6)
#define DISPATCH_DEFER_WEEKLY       (7)
#define DISPATCH_DEFER_DISTRICT     (8)
#define DISPATCH_DEFER_URBAN        (9)

new gCommandNotFoundAlertCount;
new gCommandNotFoundAlerted[COMMAND_NOTFOUND_ALERT_MAX][32];

forward Dispatch_RunDeferredCommand(playerid, actionid);

stock Dispatch_QueueDeferredCommand(playerid, command[], actionid, moduleText[])
{
    CommandAI_Record(playerid, command, moduleText, "OK", 0, "rota_direta_deferida");
    SetTimerEx("Dispatch_RunDeferredCommand", 1, false, "ii", playerid, actionid);
    return 1;
}

public Dispatch_RunDeferredCommand(playerid, actionid)
{
    if (!IsValidConnectedPlayer(playerid) || IsPlayerNPC(playerid) || !PlayerInfo[playerid][pLogged])
    {
        return 1;
    }

    switch (actionid)
    {
        case DISPATCH_DEFER_VERSION: return ShowGmVersionDialog(playerid);
        case DISPATCH_DEFER_HEALTH: return ShowGmHealthDialog(playerid);
        case DISPATCH_DEFER_INTEGRITY: return ShowGmIntegrityDialog(playerid);
        case DISPATCH_DEFER_SELFTEST: return ShowGmSelfTestDialog(playerid, 0);
        case DISPATCH_DEFER_RELEASE: return ShowGmReleaseCheckDialog(playerid);
        case DISPATCH_DEFER_DAILY: return Life_ShowDailyJourney(playerid);
        case DISPATCH_DEFER_WEEKLY: return Life_ShowWeeklyAgenda(playerid);
        case DISPATCH_DEFER_DISTRICT: return Life_ShowNeighborhoodEvents(playerid);
        case DISPATCH_DEFER_URBAN: return Life_ShowUrbanProgress(playerid);
    }
    return 1;
}

stock TeleportPlayerNearPlayer(playerid, targetid)
{
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:angle;

    GetPlayerPos(targetid, x, y, z);
    GetPlayerFacingAngle(targetid, angle);
    SetPlayerInterior(playerid, GetPlayerInterior(targetid));
    SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(targetid));
    SetPlayerPos(playerid, x + 1.5, y, z);
    SetPlayerFacingAngle(playerid, angle);
    Security_GrantTeleportGrace(playerid);
    SetCameraBehindPlayer(playerid);
    return 1;
}

stock CreateAdminVehicle(playerid, modelid, color1, color2)
{
    new vehicleid;
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:angle;

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, angle);
    vehicleid = CreateVehicle(modelid, x + 3.0, y, z, angle, color1, color2, -1);

    if (vehicleid == INVALID_VEHICLE_ID)
    {
        return 0;
    }

    LinkVehicleToInterior(vehicleid, GetPlayerInterior(playerid));
    SetVehicleVirtualWorld(vehicleid, GetPlayerVirtualWorld(playerid));
    PutPlayerInVehicle(playerid, vehicleid, 0);
    return 1;
}

stock SavePlayerPositionToFile(playerid, label[])
{
    new line[192];
    new name[MAX_PLAYER_NAME + 1];
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:angle;
    new File:file;

    GetPlayerNameEx(playerid, name, sizeof(name));
    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, angle);

    file = fopen("saved_positions.txt", io_append);
    if (!file)
    {
        return 0;
    }

    format(line, sizeof(line), "%s | %s | %.4f %.4f %.4f %.4f | int %d | vw %d\r\n", name, label, x, y, z, angle, GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid));
    fwrite(file, line);
    fclose(file);
    return 1;
}

stock SendAdminsList(playerid)
{
    new targetid;
    new found;
    new name[MAX_PLAYER_NAME + 1];
    new rankName[32];
    new list[2048];
    new line[128];
    new maxPlayers = GetMaxPlayers();

    format(list, sizeof(list), "ID\tNome\tCargo\n");

    for (targetid = 0; targetid < maxPlayers; targetid++)
    {
        if (IsPlayerConnected(targetid) && PlayerInfo[targetid][pLogged] && HasAdminLevel(targetid, ADMIN_LEVEL_HELPER))
        {
            GetPlayerNameEx(targetid, name, sizeof(name));
            GetPlayerAdminRankName(targetid, rankName, sizeof(rankName));
            format(line, sizeof(line), "%d\t%s\t%s (%d)\n", targetid, name, rankName, PlayerInfo[targetid][pAdminLevel]);
            strcat(list, line, sizeof(list));
            found = 1;
        }
    }

    if (!found)
    {
        strcat(list, "-\tNenhum admin online\t-\n", sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_ADMINS_ONLINE, DIALOG_STYLE_TABLIST_HEADERS, "Admins Online", list, "Fechar", "");
    return 1;
}

stock SendAdminLevelList(playerid)
{
    SendClientMessage(playerid, COLOR_ORANGE, "Niveis admin: 0 Jogador | 1 Helper Nivel 1 | 2 Helper Nivel 2");
    SendClientMessage(playerid, COLOR_ORANGE, "Niveis admin: 3 Administrador Nivel 1 | 4 Administrador Nivel 2 | 5 DONO");
    return 1;
}

stock Owner_HandlePersistentCommands(playerid, cmdtext[])
{
    new command[32];
    new message[128];

    GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/testarcomandos", true) == 0 || strcmp(command, "/testecmd", true) == 0 || strcmp(command, "/checkcomandos", true) == 0)
    {
        return Dispatch_ShowCommandTest(playerid);
    }
    if (strcmp(command, "/modoemergenciacmd", true) == 0 || strcmp(command, "/recuperarcomandos", true) == 0 || strcmp(command, "/corrigircomandos", true) == 0)
    {
        return Dispatch_ResetCommandRouter(playerid);
    }

    if (strcmp(command, "/debugmapa", true) == 0 || strcmp(command, "/checkmapa", true) == 0)
    {
        if (!IsAdminOwnerLevel(playerid))
        {
            return SendNoPermission(playerid);
        }

        format(message, sizeof(message), "Mapa: objetos carregados %d | linhas TXT %d | arquivo %s.", gMapObjCount, MapObj_CountDataLines(), MAP_OBJECTS_FILE);
        SendClientMessage(playerid, COLOR_YELLOW, message);
        format(message, sizeof(message), "Frota jobs: veiculos carregados %d | linhas TXT %d | arquivo %s.", gJobVehicleCount, JobVehicle_CountDataLines(), JOB_VEHICLES_FILE);
        SendClientMessage(playerid, COLOR_YELLOW, message);
        SendClientMessage(playerid, COLOR_GRAY, "Se TXT tiver linhas e carregados for 0, use /reloadobjetos ou /reloadjobveiculos.");
        return 1;
    }

    if (strcmp(command, "/objetosmapa", true) == 0 || strcmp(command, "/mapobjects", true) == 0 || strcmp(command, "/reloadobjetos", true) == 0 || strcmp(command, "/reloadmapobjects", true) == 0)
    {
        return MapObjects_HandleCommands(playerid, cmdtext);
    }

    if (strcmp(command, "/addobjeto", true) == 0 || strcmp(command, "/criarobjeto", true) == 0 || strcmp(command, "/salvarobjeto", true) == 0 || strcmp(command, "/addportao", true) == 0 || strcmp(command, "/criarportao", true) == 0 || strcmp(command, "/salvarportao", true) == 0)
    {
        return MapObjects_HandleCommands(playerid, cmdtext);
    }

    if (strcmp(command, "/objetomaisperto", true) == 0 || strcmp(command, "/portaomaisperto", true) == 0 || strcmp(command, "/removerobjeto", true) == 0 || strcmp(command, "/removerportao", true) == 0 || strcmp(command, "/irobjeto", true) == 0 || strcmp(command, "/irportao", true) == 0)
    {
        return MapObjects_HandleCommands(playerid, cmdtext);
    }

    if (strcmp(command, "/objetomaisperto", true) == 0 || strcmp(command, "/portaomaisperto", true) == 0 || strcmp(command, "/removerobjeto", true) == 0 || strcmp(command, "/removerportao", true) == 0 || strcmp(command, "/irobjeto", true) == 0 || strcmp(command, "/irportao", true) == 0)
    {
        return MapObjects_HandleCommands(playerid, cmdtext);
    }

    if (strcmp(command, "/jobveiculos", true) == 0 || strcmp(command, "/veiculostrabalho", true) == 0 || strcmp(command, "/reloadjobveiculos", true) == 0 || strcmp(command, "/recarregarjobveiculos", true) == 0)
    {
        return HandleJobCommands(playerid, cmdtext);
    }

    if (strcmp(command, "/addjobveiculo", true) == 0 || strcmp(command, "/criarjobveiculo", true) == 0 || strcmp(command, "/salvarjobveiculo", true) == 0 || strcmp(command, "/removerjobveiculo", true) == 0 || strcmp(command, "/removerveiculo", true) == 0 || strcmp(command, "/irveiculo", true) == 0 || strcmp(command, "/irjobveiculo", true) == 0)
    {
        return HandleJobCommands(playerid, cmdtext);
    }

    return 0;
}

#define HELP_MAX_CATEGORIES         (8)
#define HELP_CAT_PLAYER             (0)
#define HELP_CAT_BANK_PHONE         (1)
#define HELP_CAT_VEHICLES           (2)
#define HELP_CAT_JOBS               (3)
#define HELP_CAT_PUBLIC             (4)
#define HELP_CAT_PROPERTIES         (5)
#define HELP_CAT_STAFF              (6)
#define HELP_CAT_RADAR              (7)
#define HELP_MAX_COMMANDS           (48)
#define HELP_COMMAND_SIZE           (28)
#define HELP_COMMANDS_PER_PAGE      (10)
#define HELP_DIALOG_DELAY_MS        (150)
#define CHANGELOG_DIALOG_BODY_SIZE  (3000)
#define CHANGELOG_DIALOG_LINE_SIZE  (192)
#define CHANGELOG_MAX_VERSION_ITEMS (12)
#define CHANGELOG_VERSION_SIZE      (24)
#define UNSTUCK_COOLDOWN_MS         (120000)

new gPlayerHelpDialogCategories[MAX_PLAYERS][HELP_MAX_CATEGORIES];
new gPlayerHelpCategoryCount[MAX_PLAYERS];
new gPlayerHelpCurrentCategory[MAX_PLAYERS];
new gPlayerHelpCommandCount[MAX_PLAYERS];
new gPlayerHelpPage[MAX_PLAYERS];
new gPlayerHelpHasNext[MAX_PLAYERS];
new gPlayerHelpCommands[MAX_PLAYERS][HELP_MAX_COMMANDS][HELP_COMMAND_SIZE];
new gPlayerChangelogPage[MAX_PLAYERS];
new gPlayerChangelogHasNext[MAX_PLAYERS];
new gPlayerChangelogVersionCount[MAX_PLAYERS];
new gPlayerChangelogVersions[MAX_PLAYERS][CHANGELOG_MAX_VERSION_ITEMS][CHANGELOG_VERSION_SIZE];
new gPlayerUnstuckTick[MAX_PLAYERS];

forward Help_ShowMainDeferred(playerid);
forward Help_ShowCategoryDeferred(playerid, categoryid, page);

stock Changelog_CanAppend(body[], size, line[])
{
    return (strlen(body) + strlen(line) + 2 < size);
}

stock Changelog_AppendLine(body[], size, line[])
{
    if (!Changelog_CanAppend(body, size, line))
    {
        return 0;
    }

    strcat(body, line, size);
    strcat(body, "\n", size);
    return 1;
}

stock ShowChangelogDialog(playerid, page)
{
    new File:file;
    new body[CHANGELOG_DIALOG_BODY_SIZE];
    new line[CHANGELOG_DIALOG_LINE_SIZE];
    new title[72];
    new currentPage;
    new hasNext;

    if (page < 0)
    {
        page = 0;
    }

    file = fopen(CHANGELOG_FILE, io_read);
    if (!file)
    {
        ShowPlayerDialog(playerid, DIALOG_CHANGELOG, DIALOG_STYLE_MSGBOX, "Atualizacao - Changelog", "Changelog indisponivel. O arquivo scriptfiles/changelog.txt nao foi encontrado.", "Fechar", "");
        return 1;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (!Changelog_CanAppend(body, sizeof(body), line))
        {
            if (currentPage == page)
            {
                hasNext = 1;
                break;
            }

            currentPage++;
            body[0] = 0;
        }

        Changelog_AppendLine(body, sizeof(body), line);
    }
    fclose(file);

    if (body[0] == 0)
    {
        format(body, sizeof(body), "Nenhuma atualizacao registrada em %s.", CHANGELOG_FILE);
    }

    gPlayerChangelogPage[playerid] = currentPage;
    gPlayerChangelogHasNext[playerid] = hasNext;
    format(title, sizeof(title), "Atualizacao - Changelog (pag. %d)", currentPage + 1);

    if (hasNext)
    {
        ShowPlayerDialog(playerid, DIALOG_CHANGELOG, DIALOG_STYLE_MSGBOX, title, body, "Proxima", "Fechar");
    }
    else
    {
        ShowPlayerDialog(playerid, DIALOG_CHANGELOG, DIALOG_STYLE_MSGBOX, title, body, "Fechar", "");
    }
    return 1;
}

stock HandleChangelogDialog(playerid, response)
{
    if (response && gPlayerChangelogHasNext[playerid])
    {
        return ShowChangelogDialog(playerid, gPlayerChangelogPage[playerid] + 1);
    }
    return 1;
}

stock ShowChangelogVersionDialog(playerid, version[])
{
    new File:file;
    new body[CHANGELOG_DIALOG_BODY_SIZE];
    new line[CHANGELOG_DIALOG_LINE_SIZE];
    new versionText[CHANGELOG_VERSION_SIZE];
    new title[72];
    new found;

    file = fopen(CHANGELOG_FILE, io_read);
    if (!file)
    {
        ShowPlayerDialog(playerid, DIALOG_CHANGELOG, DIALOG_STYLE_MSGBOX, "Atualizacao - Changelog", "Changelog indisponivel.", "Fechar", "");
        return 1;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (strfind(line, "RESUMO DA VERSAO ", true) == 0)
        {
            if (found)
            {
                break;
            }
            strmid(versionText, line, 17, strlen(line), sizeof(versionText));
            if (strcmp(versionText, version, true) == 0)
            {
                found = 1;
                Changelog_AppendLine(body, sizeof(body), line);
            }
            continue;
        }

        if (found)
        {
            Changelog_AppendLine(body, sizeof(body), line);
        }
    }
    fclose(file);

    if (!found || body[0] == 0)
    {
        format(body, sizeof(body), "Versao %s nao encontrada no changelog.", version);
    }

    gPlayerChangelogHasNext[playerid] = 0;
    format(title, sizeof(title), "Atualizacao - %s", version);
    ShowPlayerDialog(playerid, DIALOG_CHANGELOG, DIALOG_STYLE_MSGBOX, title, body, "Fechar", "");
    return 1;
}

stock ShowChangelogMenuDialog(playerid)
{
    new File:file;
    new list[700];
    new line[CHANGELOG_DIALOG_LINE_SIZE];
    new versionText[CHANGELOG_VERSION_SIZE];
    new count;

    format(list, sizeof(list), "Ver tudo desde o inicio\n");
    gPlayerChangelogVersionCount[playerid] = 0;
    Gm_MarkReleaseChecklist(RELCHK_CHANGELOG);

    file = fopen(CHANGELOG_FILE, io_read);
    if (file)
    {
        while (ReadFileLine(file, line, sizeof(line)))
        {
            if (strfind(line, "RESUMO DA VERSAO ", true) == 0 && count < CHANGELOG_MAX_VERSION_ITEMS)
            {
                strmid(versionText, line, 17, strlen(line), sizeof(versionText));
                format(gPlayerChangelogVersions[playerid][count], CHANGELOG_VERSION_SIZE, "%s", versionText);
                strcat(list, versionText, sizeof(list));
                strcat(list, "\n", sizeof(list));
                count++;
            }
        }
        fclose(file);
    }

    gPlayerChangelogVersionCount[playerid] = count;
    ShowPlayerDialog(playerid, DIALOG_CHANGELOG_MENU, DIALOG_STYLE_LIST, "Atualizacao - escolher versao", list, "Abrir", "Fechar");
    return 1;
}

stock HandleChangelogMenuDialog(playerid, response, listitem)
{
    if (!response)
    {
        return 1;
    }
    if (listitem <= 0)
    {
        return ShowChangelogDialog(playerid, 0);
    }
    if (listitem - 1 >= 0 && listitem - 1 < gPlayerChangelogVersionCount[playerid])
    {
        return ShowChangelogVersionDialog(playerid, gPlayerChangelogVersions[playerid][listitem - 1]);
    }
    return ShowChangelogDialog(playerid, 0);
}

stock Gm_CountFileLines(fileName[])
{
    new File:file;
    new line[192];
    new count;

    if (!fexist(fileName))
    {
        return -1;
    }

    file = fopen(fileName, io_read);
    if (!file)
    {
        return -1;
    }
    while (ReadFileLine(file, line, sizeof(line)))
    {
        count++;
    }
    fclose(file);
    return count;
}

stock ShowGmVersionDialog(playerid)
{
    new body[900];
    new line[160];
    new warText[128];
    new changelogLines = Gm_CountFileLines(CHANGELOG_FILE);

    Gm_MarkReleaseChecklist(RELCHK_VERSION);
    Life_FormatWarZoneStatus(warText, sizeof(warText));
    format(body, sizeof(body), "Campo\tValor\n");
    format(line, sizeof(line), "Versao\t%s\n", GM_VERSION); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Gamemode\t%s\n", GM_TEXT); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "AMX release\t%s\n", GM_RELEASE_AMX); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Data deploy\t%s\n", GM_DEPLOY_DATE); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Changelog\t%s | %d linha(s)\n", fexist(CHANGELOG_FILE) ? ("carregado") : ("faltando"), changelogLines); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Server info\t%s | %s\n", fexist(SERVER_INFO_FILE) ? ("OK") : ("FALTA"), gServerVersion); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Checklist v1.0\t%d/%d comando(s)\n", Gm_CountReleaseChecklist(), RELCHK_REQUIRED_COUNT); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Zona guerra\t%s\n", warText); strcat(body, line, sizeof(body));
    ShowPlayerDialog(playerid, DIALOG_GM_VERSION, DIALOG_STYLE_TABLIST_HEADERS, "Versao do servidor", body, "Fechar", "");
    return 1;
}

stock ShowGmHealthDialog(playerid)
{
    new list[2800];
    new line[180];
    new detail[128];
    new index;
    new lowStock;
    new bankrupt;
    new debtCompanies;
    new highDebtPlayers;
    new workplaceExitProblems;
    new pendingSaves;
    new pid;
    new maxPlayers = GetMaxPlayers();

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }
    Gm_MarkReleaseChecklist(RELCHK_HEALTH);

    for (index = 0; index < LIFE_MARKET_ITEMS; index++)
    {
        if (gMarketStock[index] <= gCfgMarketLowStock)
        {
            lowStock++;
        }
    }
    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged])
        {
            continue;
        }
        if (PlayerInfo[pid][pBusinessBankrupt]) bankrupt++;
        if (PlayerInfo[pid][pBusinessDebt] > 0) debtCompanies++;
        if (Life_BillTotal(pid) >= 5000 || PlayerInfo[pid][pFines] >= 3000) highDebtPlayers++;
        if (gAccountSaveDirty[pid]) pendingSaves++;
    }
    workplaceExitProblems = World_CountJobExitProblems();
    Gm_FormatPlayerLastAction(playerid, detail, sizeof(detail));

    format(list, sizeof(list), "Item\tStatus\tDetalhe\n");
    format(line, sizeof(line), "server_info\t%s\t%s\n", fexist(SERVER_INFO_FILE) ? ("OK") : ("FALTA"), gServerVersion); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "game_config\t%s\tprecos, XP e regras\n", fexist(GAME_CONFIG_FILE) ? ("OK") : ("FALTA")); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "changelog\t%s\t%d linhas\n", fexist(CHANGELOG_FILE) ? ("OK") : ("FALTA"), Gm_CountFileLines(CHANGELOG_FILE)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "estoques\t%d baixo(s)\tmarket_stock.txt\n", lowStock); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "cofre publico\t$%d\tgastos $%d | government_revenue.txt\n", gGovernmentRevenue, gGovernmentExpense); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "empresas falidas\t%d\tonline agora\n", bankrupt); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "empresas com divida\t%d\tonline agora\n", debtCompanies); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "devedores altos\t%d\tonline agora\n", highDebtPlayers); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "central chamados\t%d ativo(s)\t%d aguardando | %d aceito(s)\n", Life_ServiceCall_Count(), Life_ServiceCall_Count(LIFE_CALL_STATUS_PENDING), Life_ServiceCall_Count(LIFE_CALL_STATUS_ACCEPTED)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "logs dinheiro\t%s\t%s\n", fexist(LOG_MONEY_FILE) ? ("OK") : ("FALTA"), LOG_MONEY_FILE); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "logs profissoes\t%d\tJOB_REWARD no dinheiro\n", Ops_CountLogMatches(LOG_MONEY_FILE, "JOB_REWARD")); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "logs punicao\t%s\t%s\n", fexist(LOG_PUNISH_FILE) ? ("OK") : ("FALTA"), LOG_PUNISH_FILE); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "anti-abuso\t%s\talertas em staff/log\n", fexist(LOG_ADMIN_FILE) ? ("OK") : ("FALTA")); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "ultimas acoes\t%s\t%s\n", fexist(LOG_LAST_ACTION_FILE) ? ("OK") : ("CRIANDO"), LOG_LAST_ACTION_FILE); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "saves pendentes\t%d\tautosave/dirty queue\n", pendingSaves); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "backup recente\t%s\t%s\n", fexist(BACKUP_STATUS_FILE) ? ("OK") : ("AVISO"), BACKUP_STATUS_FILE); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "sua ultima acao\tINFO\t%s\n", detail); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "saidas trabalho\t%s\t%d pendencia(s)\n", workplaceExitProblems == 0 ? ("OK") : ("ALERTA"), workplaceExitProblems); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "NPCs ambiente\t%d/%d\tpedestres com reacao\n", AmbientNpc_CountConnected(), AmbientNpc_CountConfigured()); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "timer HUD\t%dms max %dms\t%d player(s)\n", gGmTimerLastMs[GM_TIMER_HUD], gGmTimerMaxMs[GM_TIMER_HUD], gGmTimerScanned[GM_TIMER_HUD]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "timer Fuel\t%dms max %dms\t%d driver(s)\n", gGmTimerLastMs[GM_TIMER_FUEL], gGmTimerMaxMs[GM_TIMER_FUEL], gGmTimerScanned[GM_TIMER_FUEL]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "timer Radar\t%dms max %dms\t%d driver(s)\n", gGmTimerLastMs[GM_TIMER_RADAR], gGmTimerMaxMs[GM_TIMER_RADAR], gGmTimerScanned[GM_TIMER_RADAR]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "risco performance\t%d\t/perf para detalhes\n", Gm_CountTimerRisks()); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "releasecheck\t%s\t/releasecheck rumo a 1.0.0\n", fexist(RELEASE_PLAN_FILE) ? ("OK") : ("FALTA")); strcat(list, line, sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_GM_HEALTH, DIALOG_STYLE_TABLIST_HEADERS, "Saude da GM", list, "Fechar", "");
    return 1;
}

stock Gm_AddTestLine(list[], size, item[], status[], detail[])
{
    new line[180];

    format(line, sizeof(line), "%s\t%s\t%s\n", item, status, detail);
    strcat(list, line, size);
    return 1;
}

stock Gm_AddReleaseLine(list[], size, marco[], status[], detail[])
{
    new line[220];

    format(line, sizeof(line), "%s\t%s\t%s\n", marco, status, detail);
    strcat(list, line, size);
    return 1;
}

stock Gm_AddIntegrityReportLine(File:file, item[], status[], detail[])
{
    new line[220];

    format(line, sizeof(line), "%s\t%s\t%s\r\n", item, status, detail);
    fwrite(file, line);
    return 1;
}

stock Gm_WriteIntegrityReport()
{
    new File:file = fopen(INTEGRITY_REPORT_FILE, io_write);
    new detail[160];
    new year;
    new month;
    new day;
    new hour;
    new minute;
    new second;
    new requiredMissing;

    if (!file)
    {
        print("[Integridade] Nao foi possivel gravar scriptfiles/integrity_report.txt.");
        return 0;
    }

    GetBrasiliaDateTime(year, month, day, hour, minute, second);
    fwrite(file, "Modulo\tStatus\tDetalhe\r\n");

    format(detail, sizeof(detail), "%04d-%02d-%02d %02d:%02d:%02d BRT | %s | %s", year, month, day, hour, minute, second, GM_VERSION, GM_RELEASE_AMX);
    Gm_AddIntegrityReportLine(file, "boot", "OK", detail);

    format(detail, sizeof(detail), "server_info %s | runtime %s | esperado %s", fexist(SERVER_INFO_FILE) ? ("existe") : ("falta"), gServerVersion, GM_VERSION);
    Gm_AddIntegrityReportLine(file, "versao", (fexist(SERVER_INFO_FILE) && strcmp(gServerVersion, GM_VERSION, false) == 0 && strcmp(gServerModeText, GM_TEXT, false) == 0) ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "hud %dms | autosave %dms | fuel %dms | needs %dms", gCfgHudUpdateInterval, gCfgAutosaveInterval, gCfgFuelUpdateInterval, gCfgNeedsUpdateInterval);
    Gm_AddIntegrityReportLine(file, "game_config", (fexist(GAME_CONFIG_FILE) && gCfgHudUpdateInterval >= 500 && gCfgAutosaveInterval >= 60000 && gCfgFuelUpdateInterval >= 1000) ? ("OK") : ("ALERTA"), detail);

    if (!fexist(SERVER_INFO_FILE)) requiredMissing++;
    if (!fexist(GAME_CONFIG_FILE)) requiredMissing++;
    if (!fexist(CHANGELOG_FILE)) requiredMissing++;
    if (!fexist(RELEASE_PLAN_FILE)) requiredMissing++;
    if (!fexist(BOT_MESSAGES_FILE)) requiredMissing++;
    if (!fexist(BOT_BADWORDS_FILE)) requiredMissing++;
    if (!fexist(JOB_VEHICLES_FILE)) requiredMissing++;
    if (!fexist(MAP_OBJECTS_FILE)) requiredMissing++;
    if (!fexist(RADAR_MANUAL_FILE)) requiredMissing++;
    if (!fexist(COMMAND_HOTFIX_FILE)) requiredMissing++;
    if (!fexist(ACCESS_CONFIG_FILE)) requiredMissing++;
    if (!fexist(WHITELIST_FILE)) requiredMissing++;
    if (!fexist(BANS_FILE)) requiredMissing++;
    if (!fexist(BACKUP_STATUS_FILE)) requiredMissing++;

    format(detail, sizeof(detail), "faltando %d arquivo(s) essencial(is)", requiredMissing);
    Gm_AddIntegrityReportLine(file, "scriptfiles", requiredMissing == 0 ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "hud %d | save %d | needs %d | fuel %d | police %d | radar %d | war %d", gHudTimer, gAutoSaveTimer, gNeedsTimer, gFuelTimer, gPoliceTimer, gRadarTimer, gWarZoneTimer);
    Gm_AddIntegrityReportLine(file, "timers", (gHudTimer && gAutoSaveTimer && gNeedsTimer && gFuelTimer && gPoliceTimer && gRadarTimer && gWarZoneTimer) ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "objetos %d | linhas %d", MapObjects_Count(), MapObj_CountDataLines());
    Gm_AddIntegrityReportLine(file, "map_objects", MapObjects_Count() > 0 ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "veiculos %d | linhas %d", Work_CountConfigVehicles(), JobVehicle_CountDataLines());
    Gm_AddIntegrityReportLine(file, "job_vehicles", Work_CountConfigVehicles() > 0 ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "radares ativos %d | arquivo %s", gRadarCount, fexist(RADAR_MANUAL_FILE) ? ("OK") : ("FALTA"));
    Gm_AddIntegrityReportLine(file, "radares", (gRadarCount > 0 && fexist(RADAR_MANUAL_FILE)) ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "bot %d mensagem(ns) | %d termo(s) | radio %d", gBotMessageCount, gBotBadWordCount, gRadioCount);
    Gm_AddIntegrityReportLine(file, "bot_radio", (gBotMessageCount >= 5 && gBotBadWordCount > 0 && gRadioCount > 0) ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "NPCs configurados %d | conectados %d | procurados %d", AmbientNpc_CountConfigured(), AmbientNpc_CountConnected(), AmbientNpc_CountWanted());
    Gm_AddIntegrityReportLine(file, "ambient_npcs", AmbientNpc_CountConfigured() > 0 ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "admin %s | dinheiro %s | punicao %s | seguranca %s", fexist(LOG_ADMIN_FILE) ? ("OK") : ("FALTA"), fexist(LOG_MONEY_FILE) ? ("OK") : ("FALTA"), fexist(LOG_PUNISH_FILE) ? ("OK") : ("FALTA"), fexist(SECURITY_ALERT_FILE) ? ("OK") : ("FALTA"));
    Gm_AddIntegrityReportLine(file, "logs", (fexist(LOG_ADMIN_FILE) && fexist(LOG_MONEY_FILE) && fexist(LOG_PUNISH_FILE) && fexist(SECURITY_ALERT_FILE)) ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "hotfixes %d | arquivo %s", gCommandHotfixCount, fexist(COMMAND_HOTFIX_FILE) ? ("OK") : ("FALTA"));
    Gm_AddIntegrityReportLine(file, "command_router", fexist(COMMAND_HOTFIX_FILE) ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "backup %s | changelog %d linhas | release_plan %s", fexist(BACKUP_STATUS_FILE) ? ("OK") : ("FALTA"), Gm_CountFileLines(CHANGELOG_FILE), fexist(RELEASE_PLAN_FILE) ? ("OK") : ("FALTA"));
    Gm_AddIntegrityReportLine(file, "operacao", (fexist(BACKUP_STATUS_FILE) && fexist(CHANGELOG_FILE) && fexist(RELEASE_PLAN_FILE)) ? ("OK") : ("ALERTA"), detail);

    fclose(file);
    print("[Integridade] Relatorio gerado em scriptfiles/integrity_report.txt.");
    return 1;
}

stock ShowGmIntegrityDialog(playerid)
{
    new list[3600];
    new line[220];
    new File:file;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }

    if (!fexist(INTEGRITY_REPORT_FILE))
    {
        Gm_WriteIntegrityReport();
    }

    file = fopen(INTEGRITY_REPORT_FILE, io_read);
    if (!file)
    {
        SendClientMessage(playerid, COLOR_RED, "Relatorio de integridade indisponivel. Veja o server_log.txt.");
        return 1;
    }

    list[0] = 0;
    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (strlen(list) + strlen(line) + 2 >= sizeof(list))
        {
            strcat(list, "relatorio\tTRUNCADO\tabra scriptfiles/integrity_report.txt\r\n", sizeof(list));
            break;
        }
        strcat(list, line, sizeof(list));
        strcat(list, "\n", sizeof(list));
    }
    fclose(file);

    if (list[0] == 0)
    {
        format(list, sizeof(list), "Modulo\tStatus\tDetalhe\nrelatorio\tALERTA\tarquivo vazio");
    }

    ShowPlayerDialog(playerid, DIALOG_GM_INTEGRITY, DIALOG_STYLE_TABLIST_HEADERS, "Integridade da GM", list, "Fechar", "");
    return 1;
}

stock ShowGmReleaseCheckDialog(playerid)
{
    new list[3600];
    new detail[180];
    new checklistMissing[96];
    new repairReport[128];
    new pid;
    new index;
    new maxPlayers = GetMaxPlayers();
    new today = GetBrasiliaDayStamp();
    new onlinePlayers;
    new cashMismatch;
    new legacyRepairs;
    new loanIssues;
    new dirtySaves;
    new lowStock;
    new badMarketStock;
    new businessRisk;
    new contractRisk;
    new farmRisk;
    new onboardingPending;
    new documentWarnings;
    new govNotifications;
    new justiceOpen;
    new civicRisk;
    new publicRisk;
    new detranRisk;
    new healthRisk;
    new ankleMonitors;
    new serviceActions;
    new opsMissing;
    new timerRisk;
    new jobRewardLogs;
    new jobSecurityAlerts;
    new moneyReasonLogs;
    new contractLogs;
    new securityLogs;
    new checklistDone;
    new checklistOk;
    new timersOk;
    new v04Ok;
    new v05Ok;
    new v06Ok;
    new v07Ok;
    new v08Ok;
    new v09Ok;
    new v10Ok;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }

    for (index = 0; index < LIFE_MARKET_ITEMS; index++)
    {
        if (gMarketStock[index] <= gCfgMarketLowStock)
        {
            lowStock++;
        }
        if (gMarketStock[index] < 0 || gMarketStock[index] > gMarketDefaults[index] * 3)
        {
            badMarketStock++;
        }
    }

    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged])
        {
            continue;
        }

        onlinePlayers++;
        if (GetPlayerMoney(pid) != PlayerInfo[pid][pMoney])
        {
            cashMismatch++;
        }
        legacyRepairs += Account_RepairLegacyData(pid, 0, repairReport, sizeof(repairReport));
        if ((PlayerInfo[pid][pBankLoan] > 0 && PlayerInfo[pid][pBankLoanInstallments] <= 0) || PlayerInfo[pid][pLoanInstallmentsPaid] > PlayerInfo[pid][pBankLoanInstallments])
        {
            loanIssues++;
        }
        if (gAccountSaveDirty[pid])
        {
            dirtySaves++;
        }
        if (PlayerInfo[pid][pBusinessType] != LIFE_BUSINESS_NONE)
        {
            if (PlayerInfo[pid][pBusinessBalance] < 0 || PlayerInfo[pid][pBusinessStock] < 0 || PlayerInfo[pid][pBusinessStock] > LIFE_BUSINESS_MAX_STOCK || PlayerInfo[pid][pBusinessOrders] > 12 || (PlayerInfo[pid][pBusinessBankrupt] && PlayerInfo[pid][pBusinessDebt] <= 0))
            {
                businessRisk++;
            }
            if (PlayerInfo[pid][pContractsToday] > LIFE_CONTRACTS_DAILY_LIMIT || PlayerInfo[pid][pBusinessContracts] >= 20)
            {
                contractRisk++;
            }
        }
        if (gLifeMoneyGainToday[pid] >= LIFE_ANTI_ABUSE_MONEY_DAY / 2 || gLifeXpGainToday[pid] >= LIFE_ANTI_ABUSE_XP_DAY / 2)
        {
            farmRisk++;
        }
        if (Life_OnboardingDoneCount(pid) < LIFE_ONBOARDING_TARGET || !PlayerInfo[pid][pOnboardingRewarded])
        {
            onboardingPending++;
        }
        documentWarnings += Life_GetDocumentWarningCount(pid);
        govNotifications += Life_CountGovNotifications(pid);
        if (Life_HasOpenJusticeRisk(pid))
        {
            justiceOpen++;
        }
        if ((PlayerInfo[pid][pJailTime] > 0 && !gPlayerInPoliceCell[pid]) || (PlayerInfo[pid][pInjury] > 0 && GetPlayerInterior(pid) != gServerLocations[LOCATION_HOSPITAL][locInterior]))
        {
            civicRisk++;
        }
        publicRisk += Life_PublicSvcRisk(pid);
        if (PlayerInfo[pid][pVehicleModel] >= 400 && (PlayerInfo[pid][pVehicleImpounded] || PlayerInfo[pid][pVehicleTaxDue] > 0 || PlayerInfo[pid][pVehicleInspectionDay] <= today))
        {
            detranRisk++;
        }
        if (PlayerInfo[pid][pMedicalTreatmentDue] > 0 || PlayerInfo[pid][pInjury] > 0)
        {
            healthRisk++;
        }
        if (PlayerInfo[pid][pAnkleMonitor])
        {
            ankleMonitors++;
        }
        serviceActions += PlayerInfo[pid][pMedicalShifts] + PlayerInfo[pid][pPoliceWarrants] + PlayerInfo[pid][pPoliceEvidence];
    }

    if (!fexist(SERVER_INFO_FILE)) opsMissing++;
    if (!fexist(GAME_CONFIG_FILE)) opsMissing++;
    if (!fexist(CHANGELOG_FILE)) opsMissing++;
    if (!fexist(RELEASE_PLAN_FILE)) opsMissing++;
    if (!fexist(LOG_ADMIN_FILE)) opsMissing++;
    if (!fexist(LOG_PUNISH_FILE)) opsMissing++;
    if (!fexist(LOG_MONEY_FILE)) opsMissing++;
    if (!fexist(LOG_CONTRACT_FILE)) opsMissing++;
    if (!fexist(LOG_BUG_FILE)) opsMissing++;
    if (!fexist(SECURITY_ALERT_FILE)) opsMissing++;

    timerRisk = Gm_CountTimerRisks();
    jobRewardLogs = Ops_CountLogMatches(LOG_MONEY_FILE, "JOB_REWARD");
    jobSecurityAlerts = Ops_CountLogMatches(SECURITY_ALERT_FILE, "JOB_");
    moneyReasonLogs = Ops_CountLogMatches(LOG_MONEY_FILE, "reason=");
    contractLogs = Ops_CountConfigLines(LOG_CONTRACT_FILE);
    securityLogs = Ops_CountConfigLines(SECURITY_ALERT_FILE);
    checklistDone = Gm_CountReleaseChecklist();
    checklistOk = Gm_ReleaseChecklistReady();
    Gm_FormatReleaseMissing(checklistMissing, sizeof(checklistMissing));
    timersOk = (gHudTimer && gAutoSaveTimer && gFuelTimer && gRadarTimer && gWarZoneTimer);
    v04Ok = (cashMismatch == 0 && legacyRepairs == 0 && loanIssues == 0 && fexist(LOG_MONEY_FILE));
    v05Ok = (fexist(MARKET_STOCK_FILE) && fexist(LOG_CONTRACT_FILE) && businessRisk == 0 && badMarketStock == 0);
    v06Ok = (Work_CountConfigVehicles() > 0 && farmRisk == 0 && fexist(SECURITY_ALERT_FILE) && fexist(LOG_MONEY_FILE));
    v07Ok = (fexist(RELEASE_PLAN_FILE) && fexist(CHANGELOG_FILE));
    v08Ok = (gPoliceTimer && gRadarTimer && gRadarCount > 0 && civicRisk == 0 && fexist(LOG_PUNISH_FILE));
    v09Ok = (timersOk && dirtySaves == 0 && opsMissing == 0 && timerRisk == 0);
    v10Ok = (v04Ok && v05Ok && v06Ok && v07Ok && v08Ok && v09Ok && checklistOk && strcmp(gServerVersion, GM_VERSION, false) == 0);

    format(list, sizeof(list), "Marco\tStatus\tDetalhe\n");
    format(detail, sizeof(detail), "online %d | cash sync %d | reparos %d | emprestimos %d", onlinePlayers, cashMismatch, legacyRepairs, loanIssues);
    Gm_AddReleaseLine(list, sizeof(list), "v0.4 dinheiro/banco", v04Ok ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "estoque baixo %d | estoque invalido %d | empresa risco %d | contrato risco %d", lowStock, badMarketStock, businessRisk, contractRisk);
    Gm_AddReleaseLine(list, sizeof(list), "v0.5 economia", v05Ok ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "frota %d | farm %d | reward logs %d | job alertas %d", Work_CountConfigVehicles(), farmRisk, jobRewardLogs, jobSecurityAlerts);
    Gm_AddReleaseLine(list, sizeof(list), "v0.6 profissoes", v06Ok ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "jornada pendente %d | docs alerta %d | notif GovBR %d", onboardingPending, documentWarnings, govNotifications);
    Gm_AddReleaseLine(list, sizeof(list), "v0.7 GovBR/jornada", v07Ok ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "casos %d | fluxo risco %d | servicos %d | detran %d | saude %d | tornoz %d | acoes %d", justiceOpen, civicRisk, publicRisk, detranRisk, healthRisk, ankleMonitors, serviceActions);
    Gm_AddReleaseLine(list, sizeof(list), "v0.8 servicos publicos", v08Ok ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "timers %s | risco %d | saves %d | arquivos %d | logs $%d c%d s%d", timersOk ? ("OK") : ("ALERTA"), timerRisk, dirtySaves, opsMissing, moneyReasonLogs, contractLogs, securityLogs);
    Gm_AddReleaseLine(list, sizeof(list), "v0.9 beta operacional", v09Ok ? ("OK") : ("ALERTA"), detail);

    format(detail, sizeof(detail), "server_info %s | versao %s | checklist %d/%d falta %s", strcmp(gServerVersion, GM_VERSION, false) == 0 ? ("OK") : ("DIVERGENTE"), GM_VERSION, checklistDone, RELCHK_REQUIRED_COUNT, checklistMissing);
    Gm_AddReleaseLine(list, sizeof(list), "v1.0 release estavel", v10Ok ? ("LIBERADO") : ("BLOQUEADO"), detail);

    Gm_AddReleaseLine(list, sizeof(list), "Acao agora", v10Ok ? ("congelar escopo") : ("corrigir alertas"), v10Ok ? ("release estavel liberado no servidor") : ("/versao /atualizacao /saudegm /selftestgm /perf /logsstaff /painelstaff /antiabuso /debugplayer"));
    ShowPlayerDialog(playerid, DIALOG_GM_RELEASE, DIALOG_STYLE_TABLIST_HEADERS, "Releasecheck rumo a 1.0.0", list, "Fechar", "");
    return 1;
}

stock ShowGmSelfTestDialog(playerid, repair = 0)
{
    new list[2600];
    new detail[128];
    new repairReport[256];
    new pid;
    new vehicleid;
    new negativeMoney;
    new cashMismatch;
    new loanIssues;
    new stuckIssues;
    new dirtySaves;
    new badFuel;
    new lowStock;
    new accountRepairs;
    new repairedAccounts;
    new repairs;
    new maxPlayers = GetMaxPlayers();

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
    {
        return SendNoPermission(playerid);
    }
    Gm_MarkReleaseChecklist(RELCHK_SELFTEST);

    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged])
        {
            continue;
        }
        if (PlayerInfo[pid][pMoney] < 0 || PlayerInfo[pid][pBankMoney] < 0 || PlayerInfo[pid][pFines] < 0 || PlayerInfo[pid][pBankLoan] < 0)
        {
            negativeMoney++;
        }
        if (GetPlayerMoney(pid) != PlayerInfo[pid][pMoney])
        {
            cashMismatch++;
        }
        if ((PlayerInfo[pid][pBankLoan] > 0 && PlayerInfo[pid][pBankLoanInstallments] <= 0) || PlayerInfo[pid][pLoanInstallmentsPaid] > PlayerInfo[pid][pBankLoanInstallments])
        {
            loanIssues++;
        }
        if ((PlayerInfo[pid][pJailTime] > 0 && !gPlayerInPoliceCell[pid]) || (PlayerInfo[pid][pInjury] > 0 && GetPlayerInterior(pid) != gServerLocations[LOCATION_HOSPITAL][locInterior]))
        {
            stuckIssues++;
        }
        if (gAccountSaveDirty[pid])
        {
            dirtySaves++;
        }
        repairs = Account_RepairLegacyData(pid, repair, repairReport, sizeof(repairReport));
        if (repairs > 0)
        {
            accountRepairs += repairs;
            if (repair)
            {
                SetPlayerCashCore(pid, PlayerInfo[pid][pMoney], 0, "account_repair");
                SaveAccountNow(pid, 0);
                repairedAccounts++;
                format(detail, sizeof(detail), "selftest repaired=%d items=%s", repairs, repairReport);
                WritePlayerLog(LOG_ADMIN_FILE, "ACCOUNT_REPAIR", pid, detail);
            }
        }
    }

    for (vehicleid = 1; vehicleid < MAX_VEHICLES; vehicleid++)
    {
        if (Fuel_IsValidVehicle(vehicleid) && gVehicleFuelReady[vehicleid] && (gVehicleFuel[vehicleid] < 0 || gVehicleFuel[vehicleid] > FUEL_MAX_VALUE))
        {
            badFuel++;
        }
    }
    for (pid = 0; pid < LIFE_MARKET_ITEMS; pid++)
    {
        if (gMarketStock[pid] <= gCfgMarketLowStock)
        {
            lowStock++;
        }
    }

    format(list, sizeof(list), "Teste\tStatus\tDetalhe\n");
    Gm_AddTestLine(list, sizeof(list), "server_info", fexist(SERVER_INFO_FILE) ? ("OK") : ("FALHA"), SERVER_INFO_FILE);
    Gm_AddTestLine(list, sizeof(list), "game_config", fexist(GAME_CONFIG_FILE) ? ("OK") : ("FALHA"), GAME_CONFIG_FILE);
    Gm_AddTestLine(list, sizeof(list), "changelog", fexist(CHANGELOG_FILE) ? ("OK") : ("FALHA"), CHANGELOG_FILE);
    Gm_AddTestLine(list, sizeof(list), "log dinheiro", fexist(LOG_MONEY_FILE) ? ("OK") : ("FALHA"), LOG_MONEY_FILE);
    Gm_AddTestLine(list, sizeof(list), "log punicao", fexist(LOG_PUNISH_FILE) ? ("OK") : ("FALHA"), LOG_PUNISH_FILE);
    format(detail, sizeof(detail), "hud %d | save %d | fuel %d | radar %d | guerra %d", gHudTimer, gAutoSaveTimer, gFuelTimer, gRadarTimer, gWarZoneTimer);
    Gm_AddTestLine(list, sizeof(list), "timers principais", (gHudTimer && gAutoSaveTimer && gFuelTimer && gRadarTimer && gWarZoneTimer) ? ("OK") : ("ALERTA"), detail);
    format(detail, sizeof(detail), "%d divergencia(s) dinheiro SA-MP x conta", cashMismatch);
    Gm_AddTestLine(list, sizeof(list), "cash sync", cashMismatch == 0 ? ("OK") : ("ALERTA"), detail);
    format(detail, sizeof(detail), "%d registro(s) com valor negativo", negativeMoney);
    Gm_AddTestLine(list, sizeof(list), "saldos/dividas", negativeMoney == 0 ? ("OK") : ("ALERTA"), detail);
    format(detail, sizeof(detail), "%d emprestimo(s) com parcelas invalidas", loanIssues);
    Gm_AddTestLine(list, sizeof(list), "emprestimos", loanIssues == 0 ? ("OK") : ("ALERTA"), detail);
    format(detail, sizeof(detail), "%d reparo(s) | %d conta(s) salvas", accountRepairs, repairedAccounts);
    Gm_AddTestLine(list, sizeof(list), "corretor contas", accountRepairs == 0 ? ("OK") : (repair ? ("REPARADO") : ("ALERTA")), detail);
    format(detail, sizeof(detail), "%d possivel(is) prisao/hospital fora do lugar", stuckIssues);
    Gm_AddTestLine(list, sizeof(list), "fluxos presos", stuckIssues == 0 ? ("OK") : ("ALERTA"), detail);
    format(detail, sizeof(detail), "%d conta(s) aguardando autosave", dirtySaves);
    Gm_AddTestLine(list, sizeof(list), "fila save", "OK", detail);
    format(detail, sizeof(detail), "%d veiculo(s) com combustivel fora do range", badFuel);
    Gm_AddTestLine(list, sizeof(list), "combustivel", badFuel == 0 ? ("OK") : ("ALERTA"), detail);
    format(detail, sizeof(detail), "ativa %d | radares %d | mercados baixo %d", Life_IsWarZoneActive(), gRadarCount, lowStock);
    Gm_AddTestLine(list, sizeof(list), "cidade", "OK", detail);
    ShowPlayerDialog(playerid, DIALOG_GM_SELFTEST, DIALOG_STYLE_TABLIST_HEADERS, "Self-test GM", list, "Fechar", "");
    return 1;
}

stock UnstuckPlayerFlow(playerid)
{
    new tick = GetTickCount();
    new message[128];

    if (!PlayerInfo[playerid][pLogged])
    {
        return SendClientMessage(playerid, COLOR_RED, "Faca login antes de usar /desbugar.");
    }

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER) && gPlayerUnstuckTick[playerid] > 0 && (tick - gPlayerUnstuckTick[playerid]) < UNSTUCK_COOLDOWN_MS)
    {
        format(message, sizeof(message), "Aguarde %d segundos para usar /desbugar de novo.", (UNSTUCK_COOLDOWN_MS - (tick - gPlayerUnstuckTick[playerid])) / 1000);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        return 1;
    }

    gPlayerUnstuckTick[playerid] = tick;
    RemovePlayerFromVehicle(playerid);
    TogglePlayerControllable(playerid, 1);
    ClearAnimations(playerid);
    DisablePlayerCheckpoint(playerid);
    Work_Cancel(playerid, 0);

    if (PlayerInfo[playerid][pJailTime] > 0)
    {
        World_SendPlayerToPoliceCell(playerid);
        SendClientMessage(playerid, COLOR_ORANGE, "Desbug aplicado. Como voce esta preso, voltou para a cela.");
        WritePlayerLog(LOG_ADMIN_FILE, "UNSTUCK", playerid, "voltou para cela");
        return 1;
    }

    if (PlayerInfo[playerid][pInjury] > 0 || PlayerInfo[playerid][pMedicalTreatmentDue] > 0)
    {
        SetPlayerToLocation(playerid, LOCATION_HOSPITAL);
        SendClientMessage(playerid, COLOR_ORANGE, "Desbug aplicado. Como ha pendencia medica, voce voltou ao hospital.");
        WritePlayerLog(LOG_ADMIN_FILE, "UNSTUCK", playerid, "voltou para hospital");
        return 1;
    }

    SetPlayerToLocation(playerid, LOCATION_SPAWN);
    SendClientMessage(playerid, COLOR_GREEN, "Desbug aplicado. Checkpoints e estados temporarios foram limpos.");
    WritePlayerLog(LOG_ADMIN_FILE, "UNSTUCK", playerid, "voltou para spawn");
    return 1;
}

stock ShowDebugPlayerDialog(playerid, targetid)
{
    new list[1800];
    new line[180];
    new debugJobName[32];
    new businessName[32];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
    {
        return SendNoPermission(playerid);
    }
    if (!IsValidConnectedPlayer(targetid) || !PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador alvo invalido ou deslogado.");
        return 1;
    }
    Gm_MarkReleaseChecklist(RELCHK_DEBUG);

    GetJobName(PlayerInfo[targetid][pJob], debugJobName, sizeof(debugJobName));
    Life_GetBusinessName(PlayerInfo[targetid][pBusinessType], businessName, sizeof(businessName));
    format(list, sizeof(list), "Campo\tValor\n");
    format(line, sizeof(line), "Emprego\t%s (%d)\n", debugJobName, PlayerInfo[targetid][pJob]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Login streak\t%d | diaria %d | semanal %d\n", PlayerInfo[targetid][pLoginStreak], PlayerInfo[targetid][pDailyRewardDay], PlayerInfo[targetid][pWeeklyRewardWeek]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Passe\ttrab %d | econ %d | pub %d | resgatado %d\n", PlayerInfo[targetid][pCityPassJob], PlayerInfo[targetid][pCityPassEconomy], PlayerInfo[targetid][pCityPassPublic], PlayerInfo[targetid][pCityPassRewarded]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Score\t%d | bom %d | ruim %d\n", Life_GetBankScore(targetid), PlayerInfo[targetid][pBankGoodHistory], PlayerInfo[targetid][pBankBadHistory]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Empresa\t%s | caixa $%d | estoque %d | divida $%d | falida %d\n", businessName, PlayerInfo[targetid][pBusinessBalance], PlayerInfo[targetid][pBusinessStock], PlayerInfo[targetid][pBusinessDebt], PlayerInfo[targetid][pBusinessBankrupt]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Contratos\t%d total | %d/%d hoje\n", PlayerInfo[targetid][pBusinessContracts], PlayerInfo[targetid][pContractsToday], LIFE_CONTRACTS_DAILY_LIMIT); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Multas/dividas\tmultas $%d | pontos CNH %d | boletos $%d | wanted %d | jail %d\n", PlayerInfo[targetid][pFines], PlayerInfo[targetid][pTrafficPoints], Life_BillTotal(targetid), PlayerInfo[targetid][pWanted], PlayerInfo[targetid][pJailTime]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Emprestimo\tdivida $%d | parcela $%d | %d/%d | venc %d\n", PlayerInfo[targetid][pBankLoan], PlayerInfo[targetid][pBillLoanInstallmentDue], PlayerInfo[targetid][pLoanInstallmentsPaid], PlayerInfo[targetid][pBankLoanInstallments], PlayerInfo[targetid][pBankLoanNextDueDay]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Justica\tcasos %d | status %d | provas %d | mandados %d | sentenca $%d | tornozeleira %d\n", PlayerInfo[targetid][pJusticeCases], PlayerInfo[targetid][pJusticeStatus], PlayerInfo[targetid][pJusticeActiveEvidence], PlayerInfo[targetid][pJusticeActiveWarrants], PlayerInfo[targetid][pJusticeFineDue], PlayerInfo[targetid][pAnkleMonitor]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Zona guerra\tkills hoje %d | ativo %d\n", PlayerInfo[targetid][pWarZoneKillsToday], Life_IsWarZoneActive()); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Ganhos sessao\tcash monitor $%d | XP monitor %d\n", gLifeMoneyGainToday[targetid], gLifeXpGainToday[targetid]); strcat(list, line, sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_PLAYER_DEBUG, DIALOG_STYLE_TABLIST_HEADERS, "Debug player", list, "Fechar", "");
    return 1;
}

stock Help_AddCategory(playerid, categoryid, title[], description[], list[], size, &count)
{
    new line[128];

    if (count >= HELP_MAX_CATEGORIES)
    {
        return 0;
    }

    gPlayerHelpDialogCategories[playerid][count] = categoryid;
    count++;

    format(line, sizeof(line), "%s - %s\n", title, description);
    strcat(list, line, size);
    return 1;
}

stock Help_AddLine(body[], size, command[], description[])
{
    new line[160];

    format(line, sizeof(line), "%s - %s\n", command, description);
    if (strlen(body) + strlen(line) >= size - 1)
    {
        return 0;
    }
    strcat(body, line, size);
    return 1;
}

stock Help_CanViewStaff(playerid)
{
    return HasAdminLevel(playerid, ADMIN_LEVEL_HELPER);
}

stock Help_CanViewOwner(playerid)
{
    return HasAdminLevel(playerid, ADMIN_LEVEL_OWNER);
}

stock Help_IsStaffAlias(param[])
{
    return (strcmp(param, "admin", true) == 0
        || strcmp(param, "admins", true) == 0
        || strcmp(param, "adm", true) == 0
        || strcmp(param, "staff", true) == 0
        || strcmp(param, "dono", true) == 0
        || strcmp(param, "owner", true) == 0
        || strcmp(param, "comandosadmin", true) == 0
        || strcmp(param, "comandosadm", true) == 0
        || strcmp(param, "ajudaadmin", true) == 0
        || strcmp(param, "adminhelp", true) == 0);
}

stock Help_IsJobAlias(param[])
{
    return (strcmp(param, "profissoes", true) == 0
        || strcmp(param, "profissao", true) == 0
        || strcmp(param, "empregos", true) == 0);
}

stock Help_IsPublicAlias(param[])
{
    return (strcmp(param, "policia", true) == 0
        || strcmp(param, "policial", true) == 0
        || strcmp(param, "prf", true) == 0
        || strcmp(param, "blitz", true) == 0
        || strcmp(param, "barreira", true) == 0
        || strcmp(param, "saude", true) == 0
        || strcmp(param, "hospital", true) == 0);
}

stock Help_SendStaffOnly(playerid)
{
    new message[128];
    new rankName[32];

    GetPlayerAdminRankName(playerid, rankName, sizeof(rankName));
    format(message, sizeof(message), "Apenas staff pode abrir esta pagina. Seu cargo atual: %s.", rankName);
    SendClientMessage(playerid, COLOR_RED, message);
    return 1;
}

stock ShowHelpDialog(playerid)
{
    new list[768];
    new count;
    new i;

    list[0] = 0;
    gPlayerHelpCategoryCount[playerid] = 0;
    gPlayerHelpCurrentCategory[playerid] = HELP_CAT_PLAYER;
    for (i = 0; i < HELP_MAX_CATEGORIES; i++)
    {
        gPlayerHelpDialogCategories[playerid][i] = -1;
    }

    Help_AddCategory(playerid, HELP_CAT_PLAYER, "Player e RP", "comandos gerais, interacao e chat", list, sizeof(list), count);
    Help_AddCategory(playerid, HELP_CAT_BANK_PHONE, "Banco e celular", "conta bancaria, PIX, GovBR e apps", list, sizeof(list), count);
    Help_AddCategory(playerid, HELP_CAT_VEHICLES, "Veiculos", "DETRAN, garagem, IPVA, guincho e radios", list, sizeof(list), count);
    Help_AddCategory(playerid, HELP_CAT_JOBS, "Empregos", "expediente, servicos e comandos de profissao", list, sizeof(list), count);
    Help_AddCategory(playerid, HELP_CAT_PUBLIC, "Saude e policia", "hospital, ficha, fianca e abordagem", list, sizeof(list), count);
    Help_AddCategory(playerid, HELP_CAT_PROPERTIES, "Imoveis", "casas, aluguel e residencia", list, sizeof(list), count);

    if (Help_CanViewStaff(playerid))
    {
        Help_AddCategory(playerid, HELP_CAT_STAFF, "Staff e dev", "administracao, suporte e testes", list, sizeof(list), count);
    }

    if (Help_CanViewOwner(playerid))
    {
        Help_AddCategory(playerid, HELP_CAT_RADAR, "Radares DONO", "ruas, radares ativos e criacao manual", list, sizeof(list), count);
    }

    gPlayerHelpCategoryCount[playerid] = count;
    ShowPlayerDialog(playerid, DIALOG_HELP_MAIN, DIALOG_STYLE_LIST, "Ajuda - Central de comandos", list, "Abrir", "Fechar");
    return 1;
}

stock ShowHelpCategoryDialog(playerid, categoryid)
{
    new body[3600];
    new title[64];

    gPlayerHelpCurrentCategory[playerid] = categoryid;
    body[0] = 0;
    format(title, sizeof(title), "Ajuda - Comandos");

    switch (categoryid)
    {
        case HELP_CAT_PLAYER:
        {
            format(title, sizeof(title), "Ajuda - Player e RP");
            Help_AddLine(body, sizeof(body), "/apreendercrime [id]", "policia apreende ilicitos");
            Help_AddLine(body, sizeof(body), "/armas /lojarmas", "Ammu-Nation legalizada");
            Help_AddLine(body, sizeof(body), "/atacarunidade", "missao criminal RP controlada");
            Help_AddLine(body, sizeof(body), "/atualizacao", "changelog da GM");
            Help_AddLine(body, sizeof(body), "/bug [texto]", "relata problema");
            Help_AddLine(body, sizeof(body), "/central /menu", "abre sua central por nivel");
            Help_AddLine(body, sizeof(body), "/colher /plantar", "plantio ilegal RP em area rural");
            Help_AddLine(body, sizeof(body), "/comprarsementeilegal", "fornecedor rural da faccao");
            Help_AddLine(body, sizeof(body), "/crimeinfo /crimemissoes", "status e missoes criminais");
            Help_AddLine(body, sizeof(body), "/crimepontos", "pontos rurais e de risco");
            Help_AddLine(body, sizeof(body), "/denunciarcrime [id]", "denuncia civil para policia");
            Help_AddLine(body, sizeof(body), "/desbugar", "volta para local seguro");
            Help_AddLine(body, sizeof(body), "/entrarfaccao [id]", "entra em faccao ficticia");
            Help_AddLine(body, sizeof(body), "/faccaostatus /faccoes", "faccoes ficticias e status");
            Help_AddLine(body, sizeof(body), "/gps", "locais importantes");
            Help_AddLine(body, sizeof(body), "/interagir", "usa local/balcao proximo");
            Help_AddLine(body, sizeof(body), "/inv /inventario", "abre itens");
            Help_AddLine(body, sizeof(body), "/kitvip /vip", "painel e kit VIP");
            Help_AddLine(body, sizeof(body), "/lavardinheiro", "lavagem RP abstrata com risco");
            Help_AddLine(body, sizeof(body), "/ocupacoesilegais", "funcoes de faccao fora da prefeitura");
            Help_AddLine(body, sizeof(body), "/produzir", "producao ilegal RP abstrata");
            Help_AddLine(body, sizeof(body), "/radio /radios", "radios e playlists");
            Help_AddLine(body, sizeof(body), "/roubaratm /roubarbanco", "missoes criminais com fuga");
            Help_AddLine(body, sizeof(body), "/roubarcarga /roubarloja", "missoes criminais controladas");
            Help_AddLine(body, sizeof(body), "/roubarveiculo", "missao criminal de veiculo");
            Help_AddLine(body, sizeof(body), "/sairfaccao", "sai da faccao ficticia");
            Help_AddLine(body, sizeof(body), "/venderprodutoilegal", "venda de risco com denuncia");
            Help_AddLine(body, sizeof(body), "/versao", "versao e deploy");
        }
        case HELP_CAT_BANK_PHONE:
        {
            format(title, sizeof(title), "Ajuda - Banco e celular");
            Help_AddLine(body, sizeof(body), "/190 /192 /193", "chamados emergencia");
            Help_AddLine(body, sizeof(body), "/abrirchamado", "central de chamados");
            Help_AddLine(body, sizeof(body), "/abrirempresalocal", "abre CNPJ no local");
            Help_AddLine(body, sizeof(body), "/aceitarcarga", "aceita frete");
            Help_AddLine(body, sizeof(body), "/agendasemanal", "metas e ranking da semana");
            Help_AddLine(body, sizeof(body), "/app /celular", "abre celular");
            Help_AddLine(body, sizeof(body), "/bairros", "eventos por bairro 2.0");
            Help_AddLine(body, sizeof(body), "/banco", "banco digital");
            Help_AddLine(body, sizeof(body), "/boletos", "contas mensais");
            Help_AddLine(body, sizeof(body), "/cargaatual", "frete ativo");
            Help_AddLine(body, sizeof(body), "/cargaslogisticas", "fretes disponiveis");
            Help_AddLine(body, sizeof(body), "/carregarcarga", "carrega frete");
            Help_AddLine(body, sizeof(body), "/cartorio /cpf /rg", "documentos civis");
            Help_AddLine(body, sizeof(body), "/cnpj /empresa", "painel empresarial");
            Help_AddLine(body, sizeof(body), "/contratarempresa", "contrata player por profissao");
            Help_AddLine(body, sizeof(body), "/contratos", "contratos ativos");
            Help_AddLine(body, sizeof(body), "/creditoempresa", "credito empresarial");
            Help_AddLine(body, sizeof(body), "/depositar /sacar", "movimenta banco");
            Help_AddLine(body, sizeof(body), "/descarregarcarga", "entrega frete");
            Help_AddLine(body, sizeof(body), "/documentos", "documentos e vencimentos");
            Help_AddLine(body, sizeof(body), "/empresasauto", "empresas compraveis");
            Help_AddLine(body, sizeof(body), "/enderecoempresa", "GPS da empresa");
            Help_AddLine(body, sizeof(body), "/energia", "agua, luz e solar");
            Help_AddLine(body, sizeof(body), "/estoque /mercado", "mercado da cidade");
            Help_AddLine(body, sizeof(body), "/extrato /saldo", "saldo e dividas");
            Help_AddLine(body, sizeof(body), "/fechamentoempresa", "gera conta operacional");
            Help_AddLine(body, sizeof(body), "/fiscalizarempresa", "fiscaliza alvara");
            Help_AddLine(body, sizeof(body), "/gerarcarga", "pede frete empresarial");
            Help_AddLine(body, sizeof(body), "/impostos /taxas", "IPTU, IPVA e taxas");
            Help_AddLine(body, sizeof(body), "/instalarsolar", "instala energia solar");
            Help_AddLine(body, sizeof(body), "/jornadadiaria", "rotina diaria 2.0");
            Help_AddLine(body, sizeof(body), "/limparnome", "quita SPC/Serasa");
            Help_AddLine(body, sizeof(body), "/minhaempresa", "painel empresarial 2.0");
            Help_AddLine(body, sizeof(body), "/pagarcontaempresa", "quita conta da empresa");
            Help_AddLine(body, sizeof(body), "/pagarimpostos", "quita impostos");
            Help_AddLine(body, sizeof(body), "/pagarmultas", "paga multas");
            Help_AddLine(body, sizeof(body), "/pix [id] [valor]", "transfere dinheiro");
            Help_AddLine(body, sizeof(body), "/progressourbano", "reputacao por area");
            Help_AddLine(body, sizeof(body), "/regularizarempresa", "contador regulariza");
            Help_AddLine(body, sizeof(body), "/relatorioempresa", "auditoria v1.5");
            Help_AddLine(body, sizeof(body), "/resgatarlucro", "saca lucro");
        }
        case HELP_CAT_VEHICLES:
        {
            format(title, sizeof(title), "Ajuda - Veiculos");
            Help_AddLine(body, sizeof(body), "/abastecer", "abastece veiculo");
            Help_AddLine(body, sizeof(body), "/cambio /marcha", "status automatico");
            Help_AddLine(body, sizeof(body), "/combustivel /motor", "motor e fuel");
            Help_AddLine(body, sizeof(body), "/crlv /registrarveiculo", "registro e documento");
            Help_AddLine(body, sizeof(body), "/destrancar /trancar", "trava veiculo");
            Help_AddLine(body, sizeof(body), "/detran", "documentos e IPVA");
            Help_AddLine(body, sizeof(body), "/emprestarchave", "empresta chave");
            Help_AddLine(body, sizeof(body), "/estacionar", "salva posicao");
            Help_AddLine(body, sizeof(body), "/garagem", "abre garagem");
            Help_AddLine(body, sizeof(body), "/guardarveiculo", "guarda o veiculo");
            Help_AddLine(body, sizeof(body), "/guincho", "resgata veiculo");
            Help_AddLine(body, sizeof(body), "/meucarro /veiculo", "status do ativo");
            Help_AddLine(body, sizeof(body), "/meuveiculo", "spawna ativo");
            Help_AddLine(body, sizeof(body), "/patio /seguroveiculo", "seguro e recuperacao");
            Help_AddLine(body, sizeof(body), "/recarregar", "recarrega eletrico");
            Help_AddLine(body, sizeof(body), "/removerchave", "remove chave emprestada");
            Help_AddLine(body, sizeof(body), "/selecionarveiculo", "define veiculo ativo");
            Help_AddLine(body, sizeof(body), "/transferirveiculo", "transfere para player");
            Help_AddLine(body, sizeof(body), "/veiculos", "lista seus veiculos");
            Help_AddLine(body, sizeof(body), "/venderveiculo", "vende veiculo ativo");
        }
        case HELP_CAT_JOBS:
        {
            format(title, sizeof(title), "Ajuda - Empregos");
            Help_AddLine(body, sizeof(body), "/bico", "renda extra da profissao");
            Help_AddLine(body, sizeof(body), "/cancelartrabalho", "cancela expediente");
            Help_AddLine(body, sizeof(body), "/demitir", "sai da profissao");
            Help_AddLine(body, sizeof(body), "/emprego", "profissao atual");
            Help_AddLine(body, sizeof(body), "/missaopublica", "ocorrencia com NPC");
            Help_AddLine(body, sizeof(body), "/profissoes", "painel de setores, nivel e salario diario");
            Help_AddLine(body, sizeof(body), "/progresso", "nivel e desbloqueios");
            Help_AddLine(body, sizeof(body), "/servico", "acao do trabalho");
            Help_AddLine(body, sizeof(body), "/trabalhar", "inicia expediente");

            switch (PlayerInfo[playerid][pJob])
            {
                case JOB_MEDICO, JOB_MOTORISTA_AMBULANCIA:
                {
                    Help_AddLine(body, sizeof(body), "/curar [id]", "atende jogador");
                    Help_AddLine(body, sizeof(body), "/internacao", "internacao leve");
                    Help_AddLine(body, sizeof(body), "/plantaomedico", "plantao SAMU");
                }
                case JOB_BOMBEIRO:
                {
                    Help_AddLine(body, sizeof(body), "/cancelarmissaopublica", "cancela chamado");
                    Help_AddLine(body, sizeof(body), "/chamado /ocorrencia", "central 193");
                    Help_AddLine(body, sizeof(body), "/missaopublica", "fogo real aleatorio");
                }
                case JOB_MECANICO:
                {
                    Help_AddLine(body, sizeof(body), "/pintarcarro", "pinta veiculo");
                    Help_AddLine(body, sizeof(body), "/repararcarro", "repara veiculo");
                }
                case JOB_FRENTISTA:
                {
                    Help_AddLine(body, sizeof(body), "/abastecer", "abastece no posto");
                }
                case JOB_TAXISTA:
                {
                    Help_AddLine(body, sizeof(body), "/taximetro [id] [valor]", "cobra corrida");
                }
                case JOB_POLICIAL, JOB_PRF, JOB_POLICIA_FEDERAL, JOB_POLICIA_CIVIL, JOB_POLICIA_PENAL:
                {
                    Help_AddLine(body, sizeof(body), "/abordagem [id]", "painel completo de abordagem");
                    Help_AddLine(body, sizeof(body), "/abordar [id]", "aborda player ou NPC");
                    Help_AddLine(body, sizeof(body), "/algemar [id]", "imobiliza suspeito");
                    Help_AddLine(body, sizeof(body), "/apreenderfiscal", "apreende veiculo");
                    Help_AddLine(body, sizeof(body), "/arquivarcaso [id]", "arquiva investigacao");
                    Help_AddLine(body, sizeof(body), "/barreira /criarblitz", "monta blitz");
                    Help_AddLine(body, sizeof(body), "/barreiraprf /blitzprf", "barreira fiscal PRF");
                    Help_AddLine(body, sizeof(body), "/blitz", "opera blitz");
                    Help_AddLine(body, sizeof(body), "/centralpolicia", "painel operacional Policia/PRF");
                    Help_AddLine(body, sizeof(body), "/criarbarreiraprf", "alias PRF");
                    Help_AddLine(body, sizeof(body), "/crimes", "lista crimes e penas");
                    Help_AddLine(body, sizeof(body), "/desalgemar [id]", "remove algemas");
                    Help_AddLine(body, sizeof(body), "/fiscalizar", "consulta fiscal");
                    Help_AddLine(body, sizeof(body), "/fiscalizarcarga", "multa carga irregular");
                    Help_AddLine(body, sizeof(body), "/liberarfiscal [id]", "libera motorista");
                    Help_AddLine(body, sizeof(body), "/limparblitz", "limpa suas blitz");
                    Help_AddLine(body, sizeof(body), "/mandado [id] [motivo]", "registra mandado");
                    Help_AddLine(body, sizeof(body), "/multa [id] [numero]", "aplica multa CTB pronta");
                    Help_AddLine(body, sizeof(body), "/multar [id] [gravidade] [mult]", "multa manual");
                    Help_AddLine(body, sizeof(body), "/postofiscal", "postos/fiscalizacao PRF");
                    Help_AddLine(body, sizeof(body), "/prender [id] [crime_id]", "prende por artigo da lei");
                    Help_AddLine(body, sizeof(body), "/procurados", "lista players e NPCs com estrelas");
                    Help_AddLine(body, sizeof(body), "/prova [id] [desc]", "anexa prova/pericia");
                    Help_AddLine(body, sizeof(body), "/removerblitz", "remove blitz proxima");
                    Help_AddLine(body, sizeof(body), "/revistar [id]", "revista inventario, docs e armas");
                    Help_AddLine(body, sizeof(body), "/soltar [id]", "libera custodia");
                }
                case JOB_SEGURANCA:
                {
                    Help_AddLine(body, sizeof(body), "/abordagem [id]", "abordagem basica de seguranca");
                }
                case JOB_ADVOGADO:
                {
                    Help_AddLine(body, sizeof(body), "/advogado", "defesa judicial");
                    Help_AddLine(body, sizeof(body), "/justica", "casos e audiencias");
                }
                case JOB_JUIZ:
                {
                    Help_AddLine(body, sizeof(body), "/casos", "consulta casos");
                    Help_AddLine(body, sizeof(body), "/sentenciar [id] [valor]", "aplica sentenca");
                }
                default:
                {
                    if (PlayerInfo[playerid][pJob] == JOB_NONE)
                    {
                        Help_AddLine(body, sizeof(body), "/prefeitura", "caminhos publicos");
                    }
                    else
                    {
                        Help_AddLine(body, sizeof(body), "/venderproduto", "abastece mercado");
                    }
                }
            }
        }
        case HELP_CAT_PUBLIC:
        {
            format(title, sizeof(title), "Ajuda - Saude e policia");
            Help_AddLine(body, sizeof(body), "/abordagem [id]", "abordagem policial ou basica");
            Help_AddLine(body, sizeof(body), "/aceitarchamado [id]", "atende chamado");
            Help_AddLine(body, sizeof(body), "/apreenderfiscal", "guincha por irregularidade");
            Help_AddLine(body, sizeof(body), "/arquivarcaso", "encerra caso sem sentenca");
            Help_AddLine(body, sizeof(body), "/barreira /criarblitz", "policia monta blitz");
            Help_AddLine(body, sizeof(body), "/barreiraprf /blitzprf", "PRF monta barreira fiscal");
            Help_AddLine(body, sizeof(body), "/blitz", "menu da blitz");
            Help_AddLine(body, sizeof(body), "/boletim [descricao]", "abre BO com relato");
            Help_AddLine(body, sizeof(body), "/cancelarchamado", "devolve chamado");
            Help_AddLine(body, sizeof(body), "/cancelarmissaopublica", "cancela ocorrencia");
            Help_AddLine(body, sizeof(body), "/candidatar /politica", "politica e eleicao");
            Help_AddLine(body, sizeof(body), "/centralpolicia", "escala, blitz e casos policiais");
            Help_AddLine(body, sizeof(body), "/chamados", "lista chamados da profissao");
            Help_AddLine(body, sizeof(body), "/cirurgia /remedio", "tratamentos medicos");
            Help_AddLine(body, sizeof(body), "/constituicao /leis", "leis e direitos da cidade");
            Help_AddLine(body, sizeof(body), "/consultarfiscal /fiscalizar", "consulta em posto fiscal");
            Help_AddLine(body, sizeof(body), "/consultarplaca", "consulta placa");
            Help_AddLine(body, sizeof(body), "/crimes", "codigo penal e penas");
            Help_AddLine(body, sizeof(body), "/fianca", "paga fianca");
            Help_AddLine(body, sizeof(body), "/ficha [id]", "ficha criminal");
            Help_AddLine(body, sizeof(body), "/financiarobra", "financia obra publica");
            Help_AddLine(body, sizeof(body), "/fiscalizarcarga", "multa carga irregular");
            Help_AddLine(body, sizeof(body), "/fiscalprf /montarprf", "aliases da PRF");
            Help_AddLine(body, sizeof(body), "/forum /justica", "casos e audiencias");
            Help_AddLine(body, sizeof(body), "/liberarfiscal [id]", "libera motorista");
            Help_AddLine(body, sizeof(body), "/limparblitz /removerblitz", "desmonta barreiras");
            Help_AddLine(body, sizeof(body), "/mandado /prova", "investigacao com lastro");
            Help_AddLine(body, sizeof(body), "/missaopublica", "ocorrencia publica com NPC");
            Help_AddLine(body, sizeof(body), "/obras /obraspublicas", "obras e progresso");
            Help_AddLine(body, sizeof(body), "/orcamento /prefeitura", "painel municipal");
            Help_AddLine(body, sizeof(body), "/plano", "plano de saude");
            Help_AddLine(body, sizeof(body), "/postofiscal /postosfiscais", "postos fiscais PRF");
            Help_AddLine(body, sizeof(body), "/procurados", "suspeitos com estrelas");
            Help_AddLine(body, sizeof(body), "/prontuario", "prontuario medico");
            Help_AddLine(body, sizeof(body), "/revistar [id]", "revista policial completa");
            Help_AddLine(body, sizeof(body), "/saude", "ferimentos e tratamento");
            Help_AddLine(body, sizeof(body), "/servicospublicos", "central publica");
            Help_AddLine(body, sizeof(body), "/tornozeleira", "controle judicial");
            Help_AddLine(body, sizeof(body), "/transparencia", "cofre publico");
            Help_AddLine(body, sizeof(body), "/votar", "vota na eleicao");
        }
        case HELP_CAT_PROPERTIES:
        {
            format(title, sizeof(title), "Ajuda - Imoveis");
            Help_AddLine(body, sizeof(body), "/alugarcasa [id]", "aluga imovel");
            Help_AddLine(body, sizeof(body), "/anunciarcasa", "anuncia aluguel/venda");
            Help_AddLine(body, sizeof(body), "/bau", "bau da residencia");
            Help_AddLine(body, sizeof(body), "/cancelaraluguel", "cancela aluguel");
            Help_AddLine(body, sizeof(body), "/carrinho /fecharcompra", "mercado residencial");
            Help_AddLine(body, sizeof(body), "/casas /imoveis", "lista imoveis");
            Help_AddLine(body, sizeof(body), "/comprarcasa [id]", "compra imovel");
            Help_AddLine(body, sizeof(body), "/descanso /dormir", "sono e cansaco");
            Help_AddLine(body, sizeof(body), "/dispensa /supermercado", "compras da casa");
            Help_AddLine(body, sizeof(body), "/entrarcasa /entrarhotel", "entra no interior");
            Help_AddLine(body, sizeof(body), "/entrarlocal", "entra local criado");
            Help_AddLine(body, sizeof(body), "/gpshotel /hoteis", "hoteis e GPS");
            Help_AddLine(body, sizeof(body), "/minhacasa", "sua residencia");
            Help_AddLine(body, sizeof(body), "/pagarresidencia", "agua/luz/IPTU");
            Help_AddLine(body, sizeof(body), "/saircasa /sairlocal", "sai do interior");
            Help_AddLine(body, sizeof(body), "/vendercasa", "vende ao governo");
        }
        case HELP_CAT_STAFF:
        {
            if (!Help_CanViewStaff(playerid))
            {
                Help_SendStaffOnly(playerid);
                return ShowHelpDialog(playerid);
            }
            format(title, sizeof(title), "Ajuda - Staff e dev");
            Help_AddLine(body, sizeof(body), "/admin", "painel de staff");
            Help_AddLine(body, sizeof(body), "/ajudaadmin", "guia de staff");
            Help_AddLine(body, sizeof(body), "/integridade", "relatorio de boot da GM");
            Help_AddLine(body, sizeof(body), "/notfounds", "lista NOT_FOUND desde o ultimo boot");
            Help_AddLine(body, sizeof(body), "/notfoundshistorico", "historico dos contadores NOT_FOUND");
            Help_AddLine(body, sizeof(body), "/posdeploy", "resumo operacional pos-deploy");
            Help_AddLine(body, sizeof(body), "/cmdfixpromover", "sugere hotfix para handler Pawn");
            Help_AddLine(body, sizeof(body), "/cmdmodulos", "audita comandos por modulo");
            Help_AddLine(body, sizeof(body), "/balancegm", "painel de balanceamento da GM");
            Help_AddLine(body, sizeof(body), "/releasecheck", "checklist v1.0");
            Help_AddLine(body, sizeof(body), "/saudegm", "diagnostico da GM");
            Help_AddLine(body, sizeof(body), "/selftestgm", "self-test da GM");
            Help_AddLine(body, sizeof(body), "/statusserver", "status do servidor");
            Help_AddLine(body, sizeof(body), "/laggm /perf", "timers e lag");
            Help_AddLine(body, sizeof(body), "/antiabuso", "painel anti-abuso");
            Help_AddLine(body, sizeof(body), "/debugplayer [id]", "debug de jogador");
            Help_AddLine(body, sizeof(body), "Nivel 1", "/a, /kick, /reparar, /savepos, /spawn");
            if (HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
            {
                Help_AddLine(body, sizeof(body), "Nivel 2", "/dv, /gethere, /goto, /setskin, /veh");
            }
            if (HasAdminLevel(playerid, ADMIN_LEVEL_MANAGER))
            {
                Help_AddLine(body, sizeof(body), "Nivel 3", "/dargrana, /punir, /setclima, /sethora");
            }
            if (HasAdminLevel(playerid, ADMIN_LEVEL_ADMIN))
            {
                Help_AddLine(body, sizeof(body), "Nivel 4", "/limparchat, /setcolete, /setvida, /tapa");
            }
            if (Help_CanViewOwner(playerid))
            {
                Help_AddLine(body, sizeof(body), "Nivel 5 DONO", "/manutencao, /setadmin, /setvip, /whitelist");
                Help_AddLine(body, sizeof(body), "Editor DONO", "/editarmapa");
                Help_AddLine(body, sizeof(body), "Mapa DONO", "/addobjeto, /addportao, /irobjeto, /irportao, /removerobjeto [id]");
                Help_AddLine(body, sizeof(body), "Pedagios DONO", "/ajustarpedagio [id], /criarpedagio, /irpedagio, /removerpedagio [id]");
                Help_AddLine(body, sizeof(body), "Frota DONO", "/ajustarveiculo [id], /irjobveiculo, /irveiculo, /removerjobveiculo [id]");
                Help_AddLine(body, sizeof(body), "Debug DONO", "/debugcomando [cmd], /debugcomandos, /modoemergenciacmd, /resetcomandos, /testarcomandos");
            }
        }
        case HELP_CAT_RADAR:
        {
            format(title, sizeof(title), "Ajuda - Radares DONO");
            Help_AddLine(body, sizeof(body), "/addradar [limite] [rua_id]", "cria radar");
            Help_AddLine(body, sizeof(body), "/adicionarradar", "alias do addradar");
            Help_AddLine(body, sizeof(body), "/radares", "radares ativos");
            Help_AddLine(body, sizeof(body), "/ruasradar", "lista ruas");
        }
        default:
        {
            ShowHelpDialog(playerid);
            return 1;
        }
    }

    if (body[0] == 0)
    {
        format(body, sizeof(body), "Nenhum comando disponivel nesta categoria.");
    }
    ShowPlayerDialog(playerid, DIALOG_HELP_CATEGORY, DIALOG_STYLE_MSGBOX, title, body, "Voltar", "Fechar");
    return 1;
}

stock HandleHelpMainDialog(playerid, response, listitem)
{
    new categoryid;

    if (!response)
    {
        return 1;
    }

    if (listitem < 0 || listitem >= gPlayerHelpCategoryCount[playerid])
    {
        return ShowHelpDialog(playerid);
    }

    categoryid = gPlayerHelpDialogCategories[playerid][listitem];
    if (categoryid < HELP_CAT_PLAYER || categoryid > HELP_CAT_RADAR)
    {
        return ShowHelpDialog(playerid);
    }

    return ShowHelpCategoryDialog(playerid, categoryid);
}

stock HandleHelpCategoryDialog(playerid, response, listitem)
{
    #pragma unused listitem

    if (response)
    {
        return ShowHelpDialog(playerid);
    }

    return 1;
}

stock HandleAdminHelpDialog(playerid, response)
{
    if (response)
    {
        return ShowHelpCategoryDialog(playerid, HELP_CAT_STAFF);
    }
    return 1;
}

stock ShowEditMapDialog(playerid)
{
    new list[1800];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    format(list, sizeof(list), "Acao\tUso\n");
    strcat(list, "Pedagio mais perto\tMostra ID e posicao da cancela proxima\n", sizeof(list));
    strcat(list, "Ajustar pedagio mais perto\tSalva a cancela proxima na sua posicao/angulo\n", sizeof(list));
    strcat(list, "Criar pedagio\tCria nova cancela na sua posicao/angulo\n", sizeof(list));
    strcat(list, "Remover pedagio mais perto\tRemove a cancela proxima e salva o arquivo\n", sizeof(list));
    strcat(list, "Veiculo mais perto\tMostra ID do veiculo de frota proximo\n", sizeof(list));
    strcat(list, "Ajustar veiculo mais perto\tSalva a frota proxima na sua posicao/angulo\n", sizeof(list));
    strcat(list, "Salvar veiculo atual\tSalva onde esta o veiculo de frota que voce dirige\n", sizeof(list));
    strcat(list, "Remover veiculo mais perto\tRemove a frota proxima e salva o arquivo\n", sizeof(list));
    strcat(list, "Criar objeto fixo\tAbre criador de objetos na sua posicao\n", sizeof(list));
    strcat(list, "Criar portao\tAbre criador de portoes na sua posicao\n", sizeof(list));
    strcat(list, "Criar casa/apartamento\tSalva local com interior residencial aleatorio\n", sizeof(list));
    strcat(list, "Criar empresa privada\tEscolhe profissao privada e cria interior\n", sizeof(list));
    strcat(list, "Criar posto de abastecimento\tSalva bomba NPC para /abastecer\n", sizeof(list));
    strcat(list, "Objeto/portao mais perto\tMostra ID do objeto ou portao proximo\n", sizeof(list));
    strcat(list, "Remover objeto/portao mais perto\tRemove o item proximo e salva o arquivo\n", sizeof(list));
    strcat(list, "Recarregar locais do editor\tRecarrega scriptfiles/editor_locations.txt\n", sizeof(list));
    strcat(list, "Recarregar objetos\tRecarrega scriptfiles/map_objects.txt\n", sizeof(list));
    strcat(list, "Recarregar frota\tRecarrega scriptfiles/job_vehicles.txt\n", sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_EDIT_MAP_PANEL, DIALOG_STYLE_TABLIST_HEADERS, "Editor de mapa - Admin nivel 5", list, "Executar", "Fechar");
    return 1;
}

stock ShowTollCreateDialog(playerid)
{
    new list[900];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    format(list, sizeof(list), "Opcao\tUso\n");
    strcat(list, "Cancela funcional\tCria o pedagio que cobra/paga na sua posicao\n", sizeof(list));
    strcat(list, "Duas cancelas mesmo sentido\tCria 2 cancelas funcionais para pista larga\n", sizeof(list));
    strcat(list, "Pedagio base cancela\tCria base/suporte visual da cancela\n", sizeof(list));
    strcat(list, "KIT Pedagio pista dupla\tCria bases, guias e cones para pista dupla\n", sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_TOLL_CREATE_MENU, DIALOG_STYLE_TABLIST_HEADERS, "Criar pedagio", list, "Criar", "Voltar");
    return 1;
}

stock HandleTollCreateDialog(playerid, response, listitem)
{
    if (!response)
    {
        return ShowEditMapDialog(playerid);
    }
    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    if (listitem < 0 || listitem > 3)
    {
        SendClientMessage(playerid, COLOR_RED, "Opcao de pedagio expirada. Abra o editor novamente.");
        return ShowEditMapDialog(playerid);
    }

    switch (listitem)
    {
        case 0:
        {
            Tolls_CreateCommand(playerid);
        }
        case 1:
        {
            Tolls_CreateDualLaneCommand(playerid);
        }
        case 2:
        {
            MapObj_AddStatic(playerid, 966, "Pedagio base cancela");
        }
        case 3:
        {
            MapObj_AddTollDoubleLaneKit(playerid);
        }
    }
    return ShowEditMapDialog(playerid);
}

stock HandleEditMapDialog(playerid, response, listitem)
{
    new tollid;
    new vehicleSlot;
    new message[128];

    if (!response)
    {
        return 1;
    }
    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    if (listitem < 0 || listitem > 17)
    {
        SendClientMessage(playerid, COLOR_RED, "Opcao do editor expirada. Abra o menu novamente.");
        return ShowEditMapDialog(playerid);
    }

    switch (listitem)
    {
        case 0:
        {
            Tolls_SendNearest(playerid);
            return ShowEditMapDialog(playerid);
        }
        case 1:
        {
            tollid = Tolls_GetNearest(playerid, 80.0);
            if (tollid == -1)
            {
                SendClientMessage(playerid, COLOR_ORANGE, "Nenhum pedagio encontrado perto de voce.");
                return ShowEditMapDialog(playerid);
            }
            Tolls_AdjustCommand(playerid, tollid + 1);
            return ShowEditMapDialog(playerid);
        }
        case 2:
        {
            return ShowTollCreateDialog(playerid);
        }
        case 3:
        {
            tollid = Tolls_GetNearest(playerid, 80.0);
            if (tollid == -1)
            {
                SendClientMessage(playerid, COLOR_ORANGE, "Nenhum pedagio encontrado perto de voce.");
                return ShowEditMapDialog(playerid);
            }
            Tolls_RemoveCommand(playerid, tollid + 1);
            return ShowEditMapDialog(playerid);
        }
        case 4:
        {
            JobVehicle_SendNearest(playerid);
            return ShowEditMapDialog(playerid);
        }
        case 5:
        {
            vehicleSlot = JobVehicle_FindNearest(playerid, 35.0);
            if (vehicleSlot == -1)
            {
                SendClientMessage(playerid, COLOR_ORANGE, "Nenhum veiculo de frota encontrado perto de voce.");
                return ShowEditMapDialog(playerid);
            }
            JobVehicle_AdjustSlot(playerid, vehicleSlot, 0);
            return ShowEditMapDialog(playerid);
        }
        case 6:
        {
            if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
            {
                SendClientMessage(playerid, COLOR_RED, "Entre dirigindo um veiculo de frota antes de usar esta opcao.");
                return ShowEditMapDialog(playerid);
            }
            JobVehicle_AdjustSlot(playerid, 0, 1);
            return ShowEditMapDialog(playerid);
        }
        case 7:
        {
            vehicleSlot = JobVehicle_FindNearest(playerid, 35.0);
            if (vehicleSlot == -1)
            {
                SendClientMessage(playerid, COLOR_ORANGE, "Nenhum veiculo de frota encontrado perto de voce.");
                return ShowEditMapDialog(playerid);
            }
            JobVehicle_RemoveSlot(playerid, vehicleSlot);
            return ShowEditMapDialog(playerid);
        }
        case 8:
        {
            return MapObj_ShowStaticDialog(playerid);
        }
        case 9:
        {
            return MapObj_ShowGateDialog(playerid);
        }
        case 10:
        {
            return Prop_ShowEditHouseDlg(playerid);
        }
        case 11:
        {
            return Prop_ShowEditBizDlg(playerid);
        }
        case 12:
        {
            Property_EditorAddLocation(playerid, EDITOR_LOC_TYPE_FUEL, 0, EDITOR_LOC_PROFILE_GAS, "Posto criado");
            return ShowEditMapDialog(playerid);
        }
        case 13:
        {
            MapObj_SendNearest(playerid, -1);
            return ShowEditMapDialog(playerid);
        }
        case 14:
        {
            vehicleSlot = MapObj_FindNearest(playerid, 35.0, -1);
            if (vehicleSlot == -1)
            {
                SendClientMessage(playerid, COLOR_ORANGE, "Nenhum objeto/portao encontrado perto de voce.");
                return ShowEditMapDialog(playerid);
            }
            MapObj_RemoveSlot(playerid, vehicleSlot);
            return ShowEditMapDialog(playerid);
        }
        case 15:
        {
            Property_EditorLoadLocations();
            format(message, sizeof(message), "Locais do editor recarregados: %d.", gEditorLocCount);
            SendClientMessage(playerid, COLOR_GREEN, message);
            return ShowEditMapDialog(playerid);
        }
        case 16:
        {
            MapObj_LoadAll();
            format(message, sizeof(message), "Objetos do mapa recarregados: %d.", gMapObjCount);
            SendClientMessage(playerid, COLOR_GREEN, message);
            WritePlayerLog(LOG_ADMIN_FILE, "MAP_OBJECT_RELOAD", playerid, "edit map dialog reload");
            return ShowEditMapDialog(playerid);
        }
        case 17:
        {
            JobVehicle_LoadAll();
            format(message, sizeof(message), "Frota recarregada: %d veiculos.", gJobVehicleCount);
            SendClientMessage(playerid, COLOR_GREEN, message);
            return ShowEditMapDialog(playerid);
        }
    }
    return ShowEditMapDialog(playerid);
}

stock ShowAdminHelpDialog(playerid)
{
    new body[4096];

    if (!Help_CanViewStaff(playerid))
    {
        Help_SendStaffOnly(playerid);
        return 1;
    }

    strcat(body, "AJUDA ADMIN - USO RAPIDO\n\n", sizeof(body));
    strcat(body, "Comandos gerais:\n", sizeof(body));
    strcat(body, "/admin - abre o painel staff por dialog.\n", sizeof(body));
    strcat(body, "/statusserver - mostra players, contas, veiculos, radares, objetos, clima e uptime.\n", sizeof(body));
    strcat(body, "/checkserver - checklist pre-online exclusivo do DONO.\n", sizeof(body));
    strcat(body, "/debugmapa - mostra contadores do mapa/frota e linhas nos TXT.\n", sizeof(body));
    strcat(body, "/seguranca - painel de bans, alertas e logs.\n\n", sizeof(body));
    strcat(body, "Editor organizado - DONO nivel 5/RCON:\n", sizeof(body));
    strcat(body, "/editarmapa - abre menu para ajustar pedagios, frota, objetos e portoes.\n\n", sizeof(body));
    strcat(body, "Objetos e portoes do mapa - DONO nivel 5/RCON:\n", sizeof(body));
    strcat(body, "/objetosmapa - mostra quantos objetos/portoes foram carregados.\n", sizeof(body));
    strcat(body, "/addobjeto - abre lista de objetos e usa sua posicao atual.\n", sizeof(body));
    strcat(body, "/addportao - abre lista de portoes, profissao dona e usa sua posicao atual.\n", sizeof(body));
    strcat(body, "/criarcasaedit [popular/familiar/apartamento] - cria casa/apartamento com interior.\n", sizeof(body));
    strcat(body, "/criarempresaedit [jobid] - cria empresa privada com interior por profissao.\n", sizeof(body));
    strcat(body, "/criarpostoedit - cria posto de abastecimento NPC na posicao atual.\n", sizeof(body));
    strcat(body, "/objetomaisperto - mostra o ID do objeto/portao mais proximo.\n", sizeof(body));
    strcat(body, "/irobjeto ou /irportao - abre lista para teleportar ate objeto/portao.\n", sizeof(body));
    strcat(body, "/removerobjeto [id] ou /removerportao [id] - remove e salva map_objects.txt.\n", sizeof(body));
    strcat(body, "/reloadobjetos - recarrega scriptfiles/map_objects.txt sem recompilar.\n", sizeof(body));
    strcat(body, "/portao - informa o uso correto; abertura real e pela buzina H.\n\n", sizeof(body));
    strcat(body, "Pedagios - DONO nivel 5/RCON:\n", sizeof(body));
    strcat(body, "/pedagiomaisperto - mostra o ID da cancela mais proxima.\n", sizeof(body));
    strcat(body, "/irpedagio - abre lista para teleportar ate a cancela do pedagio.\n", sizeof(body));
    strcat(body, "/ajustarpedagio [id] - salva a cancela na sua posicao/angulo atual.\n", sizeof(body));
    strcat(body, "/criarpedagio - cria uma nova cancela na sua posicao/angulo atual.\n", sizeof(body));
    strcat(body, "/removerpedagio [id] - remove a cancela, reorganiza IDs e salva o arquivo.\n\n", sizeof(body));
    strcat(body, "Eleicoes e politica - DONO nivel 5/RCON:\n", sizeof(body));
    strcat(body, "/admeleicao [abrir/fechar/limpar/status] - gerencia eleicoes e cargos politicos.\n", sizeof(body));
    strcat(body, "/abrireleicao - abre votacao por 1 hora.\n", sizeof(body));
    strcat(body, "/fechareleicaoadm - fecha/apura a eleicao atual.\n", sizeof(body));
    strcat(body, "/limparpolitica - limpa cargos, reseta candidatos e coloca bots temporarios.\n\n", sizeof(body));
    strcat(body, "Politicos eleitos - fluxo seguro:\n", sizeof(body));
    strcat(body, "/painelpolitico, /pref ou /meucargo - mostra cargo, obrigacoes, comandos e regra anticorrupcao.\n", sizeof(body));
    strcat(body, "/propostapolitica [obra/orcamento/fiscalizar/contas/cpi] [valor/id] [categoria] [motivo] - cria proposta.\n", sizeof(body));
    strcat(body, "/votarproposta [id] - outro politico vota; aprovado executa pelo cofre com log.\n", sizeof(body));
    strcat(body, "/cancelarproposta [id] - admin nivel 5 cancela proposta irregular.\n\n", sizeof(body));
    strcat(body, "Veiculos de profissao - DONO nivel 5/RCON:\n", sizeof(body));
    strcat(body, "/jobveiculos - mostra frota carregada e arquivo usado.\n", sizeof(body));
    strcat(body, "/addjobveiculo [job] [modelo/atual] [cor1] [cor2] [fuel] - salva frota.\n", sizeof(body));
    strcat(body, "/veiculomaisperto - mostra o ID da frota mais proxima.\n", sizeof(body));
    strcat(body, "/irveiculo ou /irjobveiculo - abre lista para teleportar ate carro de frota.\n", sizeof(body));
    strcat(body, "/ajustarveiculo [id] - salva a frota na sua posicao/angulo atual.\n", sizeof(body));
    strcat(body, "/salvarveiculoatual - salva onde esta o veiculo de frota que voce dirige.\n", sizeof(body));
    strcat(body, "/removerjobveiculo [id] ou /removerveiculo [id] - remove e salva job_vehicles.txt.\n", sizeof(body));
    strcat(body, "/reloadjobveiculos - recarrega a frota sem recompilar.\n\n", sizeof(body));
    strcat(body, "Exemplos praticos:\n", sizeof(body));
    strcat(body, "/addobjeto\n", sizeof(body));
    strcat(body, "/addportao\n", sizeof(body));
    strcat(body, "Modo tecnico ainda aceito: /addportao [modelo] [dx] [dy] [dz] [raio] [nome]\n\n", sizeof(body));
    strcat(body, "Como posicionar:\n", sizeof(body));
    strcat(body, "1. Va ate o local exato onde o objeto deve nascer.\n", sizeof(body));
    strcat(body, "2. Fique olhando para a direcao correta; o sistema usa seu angulo atual.\n", sizeof(body));
    strcat(body, "3. Use /addobjeto para item fixo ou /addportao para portao.\n", sizeof(body));
    strcat(body, "4. Escolha o modelo e a profissao dona na dialog.\n", sizeof(body));
    strcat(body, "5. Teste dirigindo e apertando H/buzina perto do portao.\n", sizeof(body));
    strcat(body, "6. Para apagar, use /editarmapa ou os comandos de remover por ID.\n", sizeof(body));
    strcat(body, "7. Depois teste o local no mapa; o sistema ja salva e recarrega.\n\n", sizeof(body));
    strcat(body, "Arquivo:\n", sizeof(body));
    strcat(body, "scriptfiles/map_objects.txt\n", sizeof(body));
    strcat(body, "Formato: type|model|x|y|z|rx|ry|rz|open_x|open_y|open_z|open_rx|open_ry|open_rz|range|speed|interior|virtualworld|name|job\n", sizeof(body));
    strcat(body, "type 0 = objeto fixo. type 1 = portao movel.", sizeof(body));

    ShowPlayerDialog(playerid, DIALOG_ADMIN_HELP, DIALOG_STYLE_MSGBOX, "Ajuda Admin - Instrucoes", body, "Comandos", "Fechar");
    return 1;
}

#define MENU_MAX_CATEGORIES         (9)
#define MENU_CAT_PLAYER             (0)
#define MENU_CAT_GPS                (1)
#define MENU_CAT_BANK_PHONE         (2)
#define MENU_CAT_VEHICLES           (3)
#define MENU_CAT_JOBS               (4)
#define MENU_CAT_PROPERTIES         (5)
#define MENU_CAT_PUBLIC             (6)
#define MENU_CAT_TUTORIAL           (7)
#define MENU_CAT_STAFF              (8)

#define TUTORIAL_LAST_STEP          (12)
#define ADMIN_MENU_MAX_ACTIONS      (40)
#define ADMIN_ACTION_ADMINS         (1)
#define ADMIN_ACTION_WARN           (2)
#define ADMIN_ACTION_MUTE           (3)
#define ADMIN_ACTION_UNMUTE         (4)
#define ADMIN_ACTION_KICK           (5)
#define ADMIN_ACTION_SPAWN          (6)
#define ADMIN_ACTION_REPAIR         (7)
#define ADMIN_ACTION_SAVEPOS        (8)
#define ADMIN_ACTION_GOTO           (9)
#define ADMIN_ACTION_GETHERE        (10)
#define ADMIN_ACTION_SETSKIN        (11)
#define ADMIN_ACTION_VEH            (12)
#define ADMIN_ACTION_DV             (13)
#define ADMIN_ACTION_FREEZE         (14)
#define ADMIN_ACTION_UNFREEZE       (15)
#define ADMIN_ACTION_PUNISH         (16)
#define ADMIN_ACTION_UNPUNISH       (17)
#define ADMIN_ACTION_MONEY          (18)
#define ADMIN_ACTION_LICENSE        (19)
#define ADMIN_ACTION_TIME           (20)
#define ADMIN_ACTION_WEATHER        (21)
#define ADMIN_ACTION_HEALTH         (22)
#define ADMIN_ACTION_ARMOUR         (23)
#define ADMIN_ACTION_SLAP           (24)
#define ADMIN_ACTION_CLEARCHAT      (25)
#define ADMIN_ACTION_RELOADBOT      (26)
#define ADMIN_ACTION_SETADMIN       (27)
#define ADMIN_ACTION_STAFF_HELP     (28)
#define ADMIN_ACTION_RADAR_HELP     (29)
#define ADMIN_ACTION_BUG_REPORTS    (30)
#define ADMIN_ACTION_SETVIP         (31)
#define ADMIN_ACTION_REMOVEVIP      (32)
#define ADMIN_ACTION_RELOADVIP      (33)
#define ADMIN_ACTION_ADD_OBJECT     (34)
#define ADMIN_ACTION_ADD_GATE       (35)
#define ADMIN_ACTION_ANTI_ABUSE     (36)
#define ADMIN_ACTION_EDIT_MAP       (37)

new gPlayerMenuDialogCategories[MAX_PLAYERS][MENU_MAX_CATEGORIES];
new gPlayerMenuDialogCount[MAX_PLAYERS];
new gCommandUnknownAlertTick[MAX_PLAYERS];
new gCommandAiAlertTick[MAX_PLAYERS];
new gCommandDebugMode;
new gPlayerMenuCategory[MAX_PLAYERS];
new gPlayerTutorialStep[MAX_PLAYERS];
new gPlayerTutorialShown[MAX_PLAYERS];
new gPlayerAdminMenuActions[MAX_PLAYERS][ADMIN_MENU_MAX_ACTIONS];
new gPlayerAdminMenuActionCount[MAX_PLAYERS];
new gPlayerAdminInputAction[MAX_PLAYERS];

stock ResetPlayerMenuData(playerid)
{
    gPlayerMenuDialogCount[playerid] = 0;
    gPlayerMenuCategory[playerid] = MENU_CAT_PLAYER;
    gPlayerTutorialStep[playerid] = 0;
    gPlayerTutorialShown[playerid] = 0;
    gPlayerAdminMenuActionCount[playerid] = 0;
    gPlayerAdminInputAction[playerid] = 0;
    return 1;
}

stock AdminMenu_AddAction(playerid, actionid, title[], description[], list[], size, &count)
{
    new line[144];

    if (count >= ADMIN_MENU_MAX_ACTIONS)
    {
        return 0;
    }

    gPlayerAdminMenuActions[playerid][count] = actionid;
    count++;

    format(line, sizeof(line), "%s\t%s\n", title, description);
    strcat(list, line, size);
    return 1;
}

stock ShowAdminActionInput(playerid, actionid)
{
    new title[64];
    new body[256];

    gPlayerAdminInputAction[playerid] = actionid;

    switch (actionid)
    {
        case ADMIN_ACTION_WARN:
        {
            format(title, sizeof(title), "Admin - Avisar");
            format(body, sizeof(body), "Digite: ID motivo\n\nExemplo: 3 anti-rpg na abordagem");
        }
        case ADMIN_ACTION_MUTE:
        {
            format(title, sizeof(title), "Admin - Mutar");
            format(body, sizeof(body), "Digite: ID minutos motivo\n\nExemplo: 3 10 ofensa no chat");
        }
        case ADMIN_ACTION_UNMUTE:
        {
            format(title, sizeof(title), "Admin - Desmutar");
            format(body, sizeof(body), "Digite: ID");
        }
        case ADMIN_ACTION_KICK:
        {
            format(title, sizeof(title), "Admin - Kick");
            format(body, sizeof(body), "Digite: ID motivo");
        }
        case ADMIN_ACTION_GOTO:
        {
            format(title, sizeof(title), "Admin - Ir ate jogador");
            format(body, sizeof(body), "Digite: ID");
        }
        case ADMIN_ACTION_GETHERE:
        {
            format(title, sizeof(title), "Admin - Trazer jogador");
            format(body, sizeof(body), "Digite: ID");
        }
        case ADMIN_ACTION_SETSKIN:
        {
            format(title, sizeof(title), "Admin - Setar skin");
            format(body, sizeof(body), "Digite: ID skin\n\nExemplo: 3 29");
        }
        case ADMIN_ACTION_VEH:
        {
            format(title, sizeof(title), "Admin - Criar veiculo");
            format(body, sizeof(body), "Digite: modelo cor1 cor2\n\nExemplo: 411 1 1");
        }
        case ADMIN_ACTION_FREEZE:
        {
            format(title, sizeof(title), "Admin - Congelar");
            format(body, sizeof(body), "Digite: ID");
        }
        case ADMIN_ACTION_UNFREEZE:
        {
            format(title, sizeof(title), "Admin - Descongelar");
            format(body, sizeof(body), "Digite: ID");
        }
        case ADMIN_ACTION_PUNISH:
        {
            format(title, sizeof(title), "Admin - Punir");
            format(body, sizeof(body), "Digite: ID minutos motivo\n\nExemplo: 3 15 anti-rpg");
        }
        case ADMIN_ACTION_UNPUNISH:
        {
            format(title, sizeof(title), "Admin - Despunir");
            format(body, sizeof(body), "Digite: ID");
        }
        case ADMIN_ACTION_MONEY:
        {
            format(title, sizeof(title), "Admin - Dar grana");
            format(body, sizeof(body), "Digite: ID valor\n\nUse valor negativo para remover.");
        }
        case ADMIN_ACTION_LICENSE:
        {
            format(title, sizeof(title), "Admin - Aprovar profissao");
            format(body, sizeof(body), "Digite: ID tipo\n\nTipos: cnh, pesada, medico, oab, publico, policial");
        }
        case ADMIN_ACTION_TIME:
        {
            format(title, sizeof(title), "Admin - Setar hora");
            format(body, sizeof(body), "Digite: hora 0-23");
        }
        case ADMIN_ACTION_WEATHER:
        {
            format(title, sizeof(title), "Admin - Setar clima");
            format(body, sizeof(body), "Digite: clima 0-255 ou random");
        }
        case ADMIN_ACTION_HEALTH:
        {
            format(title, sizeof(title), "Admin - Setar vida");
            format(body, sizeof(body), "Digite: ID vida 0-100");
        }
        case ADMIN_ACTION_ARMOUR:
        {
            format(title, sizeof(title), "Admin - Setar colete");
            format(body, sizeof(body), "Digite: ID colete 0-100");
        }
        case ADMIN_ACTION_SLAP:
        {
            format(title, sizeof(title), "Admin - Tapa");
            format(body, sizeof(body), "Digite: ID altura\n\nExemplo: 3 5");
        }
        case ADMIN_ACTION_SETADMIN:
        {
            format(title, sizeof(title), "Admin - Setar cargo");
            format(body, sizeof(body), "Digite: ID nivel\n\n0 Jogador\n1 Helper Nivel 1\n2 Helper Nivel 2\n3 Administrador Nivel 1\n4 Administrador Nivel 2\n5 DONO");
        }
        case ADMIN_ACTION_SETVIP:
        {
            format(title, sizeof(title), "Admin - Setar VIP");
            format(body, sizeof(body), "Digite: ID nivel dias\n\nNiveis: 1 Bronze, 2 Prata, 3 Ouro, 4 Diamante\nExemplo: 3 2 30");
        }
        case ADMIN_ACTION_REMOVEVIP:
        {
            format(title, sizeof(title), "Admin - Remover VIP");
            format(body, sizeof(body), "Digite: ID");
        }
        default:
        {
            return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_STAFF);
        }
    }

    ShowPlayerDialog(playerid, DIALOG_ADMIN_ACTION_INPUT, DIALOG_STYLE_INPUT, title, body, "Executar", "Voltar");
    return 1;
}

stock Menu_AddCategory(playerid, categoryid, title[], description[], list[], size, &count)
{
    new line[128];

    if (count >= MENU_MAX_CATEGORIES)
    {
        return 0;
    }

    gPlayerMenuDialogCategories[playerid][count] = categoryid;
    count++;

    format(line, sizeof(line), "%s\t%s\n", title, description);
    strcat(list, line, size);
    return 1;
}

stock Central_GetTitle(playerid, output[], size = sizeof(output))
{
    new rankName[32];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        format(output, size, "Central do Jogador");
        return 1;
    }

    GetAdminLevelName(PlayerInfo[playerid][pAdminLevel], rankName, sizeof(rankName));
    format(output, size, "Central %s", rankName);
    return 1;
}

stock ShowPlayerMainMenu(playerid)
{
    new list[1024];
    new title[64];
    new count;
    new i;

    list[0] = 0;
    gPlayerMenuDialogCount[playerid] = 0;
    gPlayerAdminMenuActionCount[playerid] = 0;
    for (i = 0; i < MENU_MAX_CATEGORIES; i++)
    {
        gPlayerMenuDialogCategories[playerid][i] = -1;
    }

    Menu_AddCategory(playerid, MENU_CAT_PLAYER, "Personagem", "conta, stats, inventario e salvar", list, sizeof(list), count);
    Menu_AddCategory(playerid, MENU_CAT_GPS, "GPS e cidade", "locais, transporte NPC e pontos importantes", list, sizeof(list), count);
    Menu_AddCategory(playerid, MENU_CAT_BANK_PHONE, "Banco e celular", "LF Pay, GovBR, iFood e Uber/99", list, sizeof(list), count);
    Menu_AddCategory(playerid, MENU_CAT_VEHICLES, "Veiculos", "DETRAN, garagem, IPVA, motor e guincho", list, sizeof(list), count);
    Menu_AddCategory(playerid, MENU_CAT_JOBS, "Empregos", "profissao, expediente e servicos", list, sizeof(list), count);
    Menu_AddCategory(playerid, MENU_CAT_PROPERTIES, "Imoveis", "casas, aluguel e residencia", list, sizeof(list), count);
    Menu_AddCategory(playerid, MENU_CAT_PUBLIC, "Servicos publicos", "prefeitura, hospital, policia e multas", list, sizeof(list), count);
    Menu_AddCategory(playerid, MENU_CAT_TUTORIAL, "Tutorial", "aprenda o basico do servidor", list, sizeof(list), count);

    if (Help_CanViewStaff(playerid))
    {
        Menu_AddCategory(playerid, MENU_CAT_STAFF, "Staff", "suporte, dev tools e atalhos admin", list, sizeof(list), count);
    }

    gPlayerMenuDialogCount[playerid] = count;
    Central_GetTitle(playerid, title, sizeof(title));
    ShowPlayerDialog(playerid, DIALOG_MENU_MAIN, DIALOG_STYLE_TABLIST, title, list, "Abrir", "Fechar");
    return 1;
}

stock ShowPlayerMenuCategoryDialog(playerid, categoryid)
{
    new list[1024];
    new title[64];

    gPlayerMenuCategory[playerid] = categoryid;
    list[0] = 0;
    format(title, sizeof(title), "Menu");

    switch (categoryid)
    {
        case MENU_CAT_PLAYER:
        {
            format(title, sizeof(title), "Menu - Personagem");
            format(list, sizeof(list), "Ver stats\nVer minha conta\nAbrir inventario\nPainel VIP\nComprar VIP\nKit VIP diario\nSalvar conta agora\nAbrir tutorial\nAbrir ajuda de comandos\nVer admins online\nRelatar bug/problema\nTocar radio padrao\nParar radio\n");
        }
        case MENU_CAT_GPS:
        {
            format(title, sizeof(title), "Menu - GPS e cidade");
            format(list, sizeof(list), "Abrir GPS completo\nTransporte NPC\nGPS Prefeitura\nGPS Hospital\nGPS Delegacia\nGPS Banco Central\nGPS Posto Idlewood\nGPS Concessionaria\nGPS DETRAN\nGPS Garagem Publica\nGPS Patio Municipal\n");
        }
        case MENU_CAT_BANK_PHONE:
        {
            format(title, sizeof(title), "Menu - Banco e celular");
            format(list, sizeof(list), "Abrir celular\nCentral 190/192/193\nAbrir banco digital\nAbrir GovBR Online\nJornada diaria 2.0\nAgenda semanal 2.0\nEventos por bairro 2.0\nProgresso urbano 2.0\nPedir iFood / mercado\nChamar Uber / 99\nVer saldo e multas\nPagar multas\nScore cidadao\nDocumentos e vencimentos\nImpostos e taxas\nBoletos e SPC/Serasa\nContratos\nCartorio digital\nEmpresa / CNPJ\nMercado e estoque\n");
        }
        case MENU_CAT_VEHICLES:
        {
            format(title, sizeof(title), "Menu - Veiculos");
            list[0] = 0;
            strcat(list, "Status do veiculo\nListar meus veiculos\nAbrir garagem\nSpawnar veiculo ativo\nEstacionar veiculo\n", sizeof(list));
            strcat(list, "Guardar na garagem\nDETRAN\nContratar seguro\nConsultar IPVA\nPagar IPVA\nVender veiculo ativo\n", sizeof(list));
            strcat(list, "Chamar guincho NPC\nRecuperar no patio\nRadio do veiculo\nDesligar radio do veiculo\n", sizeof(list));
            strcat(list, "Ligar/desligar motor\nVer combustivel\nAbastecer no posto\nReparar na oficina NPC\n", sizeof(list));
            strcat(list, "Trancar veiculo\nDestrancar veiculo\nGPS Concessionaria\nGPS DETRAN\nGPS Patio Municipal\n", sizeof(list));
            strcat(list, "Recarregar eletrico\nStatus automatico\n", sizeof(list));
        }
        case MENU_CAT_JOBS:
        {
            format(title, sizeof(title), "Menu - Empregos");
            format(list, sizeof(list), "Ver profissao atual\nPainel da profissao\nEscolher emprego\nBater ponto / iniciar expediente\nExecutar servico do trabalho\nCancelar expediente\nPedir demissao\nGPS do trabalho atual\n");
        }
        case MENU_CAT_PROPERTIES:
        {
            format(title, sizeof(title), "Menu - Imoveis");
            format(list, sizeof(list), "Imoveis online\nLista de casas\nMinha casa\nGPS Banco para financiamento\nAbrir celular\n");
        }
        case MENU_CAT_PUBLIC:
        {
            format(title, sizeof(title), "Menu - Servicos publicos");
            format(list, sizeof(list), "Abrir GovBR Online\nJornada diaria 2.0\nAgenda semanal 2.0\nEventos por bairro 2.0\nProgresso urbano 2.0\nCentral 190/192/193\nVer chamados da profissao\nGPS Prefeitura\nGPS Hospital\nGPS Delegacia\nVer saude / ferimentos\nVer prontuario medico\nVer ficha criminal\nJustica / Forum\nPagar fianca\nPagar multas\nAbrir blitz proxima\nCriar barreira de blitz\nRemover blitz proxima\nCartorio digital\nBoletos publicos\nMissao publica com NPC\nConstituicao da cidade\n");
        }
        case MENU_CAT_TUTORIAL:
        {
            format(title, sizeof(title), "Menu - Tutorial");
            format(list, sizeof(list), "Iniciar tutorial guiado\nAbrir ajuda de comandos\nAbrir GPS\nAbrir celular\n");
        }
        case MENU_CAT_STAFF:
        {
            new count;
            new rankName[32];

            if (!Help_CanViewStaff(playerid))
            {
                gPlayerAdminMenuActionCount[playerid] = 0;
                SendClientMessage(playerid, COLOR_RED, "Apenas staff pode abrir os comandos de administracao.");
                return ShowPlayerMainMenu(playerid);
            }

            GetAdminLevelName(PlayerInfo[playerid][pAdminLevel], rankName, sizeof(rankName));
            format(title, sizeof(title), "Central %s", rankName);
            list[0] = 0;
            AdminMenu_AddAction(playerid, ADMIN_ACTION_ADMINS, "Admins online", "nivel 1", list, sizeof(list), count);
            AdminMenu_AddAction(playerid, ADMIN_ACTION_BUG_REPORTS, "Bugs reportados", "nivel 1", list, sizeof(list), count);
            AdminMenu_AddAction(playerid, ADMIN_ACTION_ANTI_ABUSE, "Painel anti-abuso", "nivel 1", list, sizeof(list), count);
            AdminMenu_AddAction(playerid, ADMIN_ACTION_WARN, "Avisar jogador", "nivel 1", list, sizeof(list), count);
            AdminMenu_AddAction(playerid, ADMIN_ACTION_MUTE, "Mutar jogador", "nivel 1", list, sizeof(list), count);
            AdminMenu_AddAction(playerid, ADMIN_ACTION_UNMUTE, "Desmutar jogador", "nivel 1", list, sizeof(list), count);
            AdminMenu_AddAction(playerid, ADMIN_ACTION_KICK, "Kickar jogador", "nivel 1", list, sizeof(list), count);
            AdminMenu_AddAction(playerid, ADMIN_ACTION_SPAWN, "Ir para spawn", "nivel 1", list, sizeof(list), count);
            AdminMenu_AddAction(playerid, ADMIN_ACTION_REPAIR, "Reparar veiculo atual", "nivel 1", list, sizeof(list), count);
            AdminMenu_AddAction(playerid, ADMIN_ACTION_SAVEPOS, "Salvar coordenada", "nivel 1", list, sizeof(list), count);

            if (HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
            {
                AdminMenu_AddAction(playerid, ADMIN_ACTION_GOTO, "Ir ate jogador", "nivel 2", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_GETHERE, "Trazer jogador", "nivel 2", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_SETSKIN, "Setar skin", "nivel 2", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_VEH, "Criar veiculo", "nivel 2", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_DV, "Deletar veiculo atual", "nivel 2", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_FREEZE, "Congelar jogador", "nivel 2", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_UNFREEZE, "Descongelar jogador", "nivel 2", list, sizeof(list), count);
            }

            if (HasAdminLevel(playerid, ADMIN_LEVEL_MANAGER))
            {
                AdminMenu_AddAction(playerid, ADMIN_ACTION_PUNISH, "Prender/punir admin", "nivel 3", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_UNPUNISH, "Soltar punicao admin", "nivel 3", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_MONEY, "Dar/remover grana", "nivel 3", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_LICENSE, "Aprovar licenca", "nivel 3", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_TIME, "Setar hora", "nivel 3", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_WEATHER, "Setar clima", "nivel 3", list, sizeof(list), count);
            }

            if (HasAdminLevel(playerid, ADMIN_LEVEL_ADMIN))
            {
                AdminMenu_AddAction(playerid, ADMIN_ACTION_HEALTH, "Setar vida", "nivel 4", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_ARMOUR, "Setar colete", "nivel 4", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_SLAP, "Dar tapa", "nivel 4", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_CLEARCHAT, "Limpar chat", "nivel 4", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_RELOADBOT, "Recarregar bot", "nivel 4", list, sizeof(list), count);
            }

            if (IsAdminOwnerLevel(playerid))
            {
                AdminMenu_AddAction(playerid, ADMIN_ACTION_EDIT_MAP, "Editor de mapa", "nivel 5 DONO", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_SETADMIN, "Setar cargo admin", "nivel 5 DONO", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_SETVIP, "Setar VIP", "nivel 5 DONO", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_REMOVEVIP, "Remover VIP", "nivel 5 DONO", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_RELOADVIP, "Recarregar VIP painel", "nivel 5 DONO", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_ADD_OBJECT, "Criar objeto mapa", "nivel 5 DONO", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_ADD_GATE, "Criar portao mapa", "nivel 5 DONO", list, sizeof(list), count);
                AdminMenu_AddAction(playerid, ADMIN_ACTION_RADAR_HELP, "Ajuda radares", "nivel 5 DONO", list, sizeof(list), count);
            }

            AdminMenu_AddAction(playerid, ADMIN_ACTION_STAFF_HELP, "Ajuda staff", "todos", list, sizeof(list), count);
            gPlayerAdminMenuActionCount[playerid] = count;
        }
        default:
        {
            return ShowPlayerMainMenu(playerid);
        }
    }

    ShowPlayerDialog(playerid, DIALOG_MENU_CATEGORY, DIALOG_STYLE_LIST, title, list, "Selecionar", "Voltar");
    return 1;
}

stock Menu_ShowVehicleFuel(playerid)
{
    return Fuel_SendPlayerVehicleStatus(playerid);
}

stock Menu_RefuelVehicle(playerid)
{
    if (PlayerInfo[playerid][pJob] == JOB_FRENTISTA && (Job_IsPlayerNearWorkplace(playerid, JOB_FRENTISTA) || World_IsPlayerAtGasStation(playerid)))
    {
        return Job_FuelCommand(playerid);
    }

    return NpcFuelRefuel(playerid);
}

stock Menu_GpsCurrentJob(playerid)
{
    new jobIndex = Job_GetIndex(PlayerInfo[playerid][pJob]);

    if (jobIndex == -1)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui emprego atual.");
        return 1;
    }

    SetPlayerGps(playerid, gJobs[jobIndex][jobLocation]);
    return 1;
}

stock Menu_StaffDeleteVehicle(playerid)
{
    new vehicleid;

    if (!IsPlayerInAnyVehicle(playerid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Entre no veiculo que deseja remover.");
        return 1;
    }

    vehicleid = GetPlayerVehicleID(playerid);
    RemovePlayerFromVehicle(playerid);
    DestroyVehicle(vehicleid);
    SendClientMessage(playerid, COLOR_ORANGE, "Veiculo removido.");
    return 1;
}

stock Admin_ClearChat(playerid)
{
    new line;
    new name[MAX_PLAYER_NAME + 1];
    new message[128];

    for (line = 0; line < 30; line++)
    {
        SendClientMessageToAll(COLOR_WHITE, " ");
    }

    GetPlayerNameEx(playerid, name, sizeof(name));
    format(message, sizeof(message), "[ADMIN] %s limpou o chat.", name);
    SendClientMessageToAll(COLOR_ORANGE, message);
    return 1;
}

stock Admin_GetActionLevel(actionid)
{
    switch (actionid)
    {
        case ADMIN_ACTION_ADMINS, ADMIN_ACTION_BUG_REPORTS, ADMIN_ACTION_WARN, ADMIN_ACTION_MUTE, ADMIN_ACTION_UNMUTE, ADMIN_ACTION_KICK, ADMIN_ACTION_SPAWN, ADMIN_ACTION_REPAIR, ADMIN_ACTION_SAVEPOS, ADMIN_ACTION_STAFF_HELP, ADMIN_ACTION_ANTI_ABUSE:
        {
            return ADMIN_LEVEL_HELPER;
        }
        case ADMIN_ACTION_GOTO, ADMIN_ACTION_GETHERE, ADMIN_ACTION_SETSKIN, ADMIN_ACTION_VEH, ADMIN_ACTION_DV, ADMIN_ACTION_FREEZE, ADMIN_ACTION_UNFREEZE:
        {
            return ADMIN_LEVEL_GAME;
        }
        case ADMIN_ACTION_PUNISH, ADMIN_ACTION_UNPUNISH, ADMIN_ACTION_MONEY, ADMIN_ACTION_LICENSE, ADMIN_ACTION_TIME, ADMIN_ACTION_WEATHER:
        {
            return ADMIN_LEVEL_MANAGER;
        }
        case ADMIN_ACTION_HEALTH, ADMIN_ACTION_ARMOUR, ADMIN_ACTION_SLAP, ADMIN_ACTION_CLEARCHAT, ADMIN_ACTION_RELOADBOT:
        {
            return ADMIN_LEVEL_ADMIN;
        }
        case ADMIN_ACTION_SETADMIN, ADMIN_ACTION_RADAR_HELP, ADMIN_ACTION_SETVIP, ADMIN_ACTION_REMOVEVIP, ADMIN_ACTION_RELOADVIP, ADMIN_ACTION_ADD_OBJECT, ADMIN_ACTION_ADD_GATE, ADMIN_ACTION_EDIT_MAP:
        {
            return ADMIN_LEVEL_OWNER;
        }
    }
    return ADMIN_LEVEL_OWNER;
}

stock Admin_ApplyLicense(playerid, targetid, type[])
{
    if (strcmp(type, "cnh", true) == 0)
    {
        PlayerInfo[targetid][pLicenseCNH] = 1;
    }
    else if (strcmp(type, "pesada", true) == 0)
    {
        PlayerInfo[targetid][pLicenseHeavy] = 1;
    }
    else if (strcmp(type, "medico", true) == 0)
    {
        PlayerInfo[targetid][pLicenseMedical] = 1;
    }
    else if (strcmp(type, "oab", true) == 0)
    {
        PlayerInfo[targetid][pLicenseOAB] = 1;
    }
    else if (strcmp(type, "publico", true) == 0)
    {
        PlayerInfo[targetid][pLicensePublic] = 1;
    }
    else if (strcmp(type, "policial", true) == 0 || strcmp(type, "porte", true) == 0 || strcmp(type, "arma", true) == 0)
    {
        PlayerInfo[targetid][pLicensePolice] = 1;
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "Tipo invalido. Use cnh, pesada, medico, oab, publico, policial ou porte.");
        return 0;
    }

    SaveAccountData(targetid, 0);
    SendClientMessage(targetid, COLOR_GREEN, "Voce recebeu uma licenca/aprovacao profissional da administracao.");
    return 1;
}

stock HandleAdminActionInput(playerid, response, inputtext[])
{
    new actionid = gPlayerAdminInputAction[playerid];
    new index;
    new param[64];
    new param2[64];
    new reason[96];
    new message[144];
    new targetid;
    new value;
    new value2;
    new color1;
    new color2;
    new Float:x;
    new Float:y;
    new Float:z;
    new rankName[32];

    if (!response)
    {
        return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_STAFF);
    }

    if (!HasAdminLevel(playerid, Admin_GetActionLevel(actionid)))
    {
        return SendNoPermission(playerid);
    }

    switch (actionid)
    {
        case ADMIN_ACTION_WARN:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param)) || !GetRemainingText(inputtext, index, reason, sizeof(reason)))
            {
                return SendUsage(playerid, "ID motivo");
            }
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            Moderation_WarnPlayer(playerid, targetid, reason);
        }
        case ADMIN_ACTION_MUTE:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param)) || !GetNextParam(inputtext, index, param2, sizeof(param2)) || !GetRemainingText(inputtext, index, reason, sizeof(reason)) || !IsNumericString(param2))
            {
                return SendUsage(playerid, "ID minutos motivo");
            }
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            Moderation_MutePlayer(playerid, targetid, strval(param2) * 60, reason);
        }
        case ADMIN_ACTION_UNMUTE:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param)))
            {
                return SendUsage(playerid, "ID");
            }
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            Moderation_UnmutePlayer(playerid, targetid);
        }
        case ADMIN_ACTION_KICK:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param)))
            {
                return SendUsage(playerid, "ID motivo");
            }
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            if (!GetRemainingText(inputtext, index, reason, sizeof(reason)))
            {
                format(reason, sizeof(reason), "Sem motivo");
            }
            format(message, sizeof(message), "[ADMIN] ID %d foi kickado. Motivo: %s", targetid, reason);
            SendClientMessageToAll(COLOR_ADMIN, message);
            Kick(targetid);
        }
        case ADMIN_ACTION_GOTO:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param))) return SendUsage(playerid, "ID");
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            TeleportPlayerNearPlayer(playerid, targetid);
            SendClientMessage(playerid, COLOR_ORANGE, "Voce foi teleportado.");
        }
        case ADMIN_ACTION_GETHERE:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param))) return SendUsage(playerid, "ID");
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            TeleportPlayerNearPlayer(targetid, playerid);
            SendClientMessage(playerid, COLOR_ORANGE, "Jogador trazido ate voce.");
            SendClientMessage(targetid, COLOR_ORANGE, "Voce foi trazido por um admin.");
        }
        case ADMIN_ACTION_SETSKIN:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param)) || !GetNextParam(inputtext, index, param2, sizeof(param2)) || !IsNumericString(param2))
            {
                return SendUsage(playerid, "ID skin");
            }
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            value = strval(param2);
            if (value < 0 || value > 311) return SendClientMessage(playerid, COLOR_RED, "Skin invalida. Use 0 a 311.");
            SetPlayerSkin(targetid, value);
            PlayerInfo[targetid][pSkin] = value;
            SaveAccountData(targetid);
            format(message, sizeof(message), "Skin do ID %d alterada para %d.", targetid, value);
            SendClientMessage(playerid, COLOR_ORANGE, message);
        }
        case ADMIN_ACTION_VEH:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param)) || !IsNumericString(param))
            {
                return SendUsage(playerid, "modelo cor1 cor2");
            }
            value = strval(param);
            if (value < 400 || value > 611) return SendClientMessage(playerid, COLOR_RED, "Modelo invalido. Use 400 a 611.");
            color1 = 1;
            color2 = 1;
            if (GetNextParam(inputtext, index, param2, sizeof(param2)) && IsNumericString(param2, 1)) color1 = strval(param2);
            if (GetNextParam(inputtext, index, param2, sizeof(param2)) && IsNumericString(param2, 1)) color2 = strval(param2);
            if (!CreateAdminVehicle(playerid, value, color1, color2)) return SendClientMessage(playerid, COLOR_RED, "Nao foi possivel criar o veiculo.");
            SendClientMessage(playerid, COLOR_ORANGE, "Veiculo criado.");
        }
        case ADMIN_ACTION_FREEZE:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param))) return SendUsage(playerid, "ID");
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            TogglePlayerControllable(targetid, 0);
            SendClientMessage(playerid, COLOR_ORANGE, "Jogador congelado.");
            SendClientMessage(targetid, COLOR_RED, "Voce foi congelado pela administracao.");
        }
        case ADMIN_ACTION_UNFREEZE:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param))) return SendUsage(playerid, "ID");
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            TogglePlayerControllable(targetid, 1);
            SendClientMessage(playerid, COLOR_ORANGE, "Jogador descongelado.");
            SendClientMessage(targetid, COLOR_GREEN, "Voce foi descongelado pela administracao.");
        }
        case ADMIN_ACTION_PUNISH:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param)) || !GetNextParam(inputtext, index, param2, sizeof(param2)) || !GetRemainingText(inputtext, index, reason, sizeof(reason)) || !IsNumericString(param2))
            {
                return SendUsage(playerid, "ID minutos motivo");
            }
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            Moderation_JailPlayer(playerid, targetid, strval(param2) * 60, reason);
        }
        case ADMIN_ACTION_UNPUNISH:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param))) return SendUsage(playerid, "ID");
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            Moderation_UnjailPlayer(playerid, targetid);
        }
        case ADMIN_ACTION_MONEY:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param)) || !GetNextParam(inputtext, index, param2, sizeof(param2)) || !IsNumericString(param2, 1))
            {
                return SendUsage(playerid, "ID valor");
            }
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            value = strval(param2);
            GivePlayerCashReason(targetid, value, 1, "admin_money_dialog");
            format(message, sizeof(message), "Voce alterou o dinheiro do ID %d em $%d.", targetid, value);
            SendClientMessage(playerid, COLOR_ORANGE, message);
            format(message, sizeof(message), "Seu dinheiro foi alterado em $%d por um admin.", value);
            SendClientMessage(targetid, COLOR_ORANGE, message);
            UpdatePlayerHud(targetid);
        }
        case ADMIN_ACTION_LICENSE:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param)) || !GetNextParam(inputtext, index, param2, sizeof(param2)))
            {
                return SendUsage(playerid, "ID tipo");
            }
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            if (Admin_ApplyLicense(playerid, targetid, param2))
            {
                format(message, sizeof(message), "Licenca/aprovacao '%s' concedida ao ID %d.", param2, targetid);
                SendClientMessage(playerid, COLOR_ORANGE, message);
            }
        }
        case ADMIN_ACTION_TIME:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param)) || !IsNumericString(param)) return SendUsage(playerid, "hora");
            value = strval(param);
            if (value < 0 || value > 23) return SendClientMessage(playerid, COLOR_RED, "Hora invalida. Use 0 a 23.");
            SetWorldTime(value);
            format(message, sizeof(message), "Hora do mundo alterada para %02d:00.", value);
            SendClientMessageToAll(COLOR_ORANGE, message);
        }
        case ADMIN_ACTION_WEATHER:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param))) return SendUsage(playerid, "clima");
            if (strcmp(param, "random", true) == 0 || strcmp(param, "aleatorio", true) == 0)
            {
                Climate_Randomize(1);
                return 1;
            }
            if (!IsNumericString(param)) return SendUsage(playerid, "clima");
            value = strval(param);
            if (value < 0 || value > 255) return SendClientMessage(playerid, COLOR_RED, "Clima invalido. Use 0 a 255.");
            Climate_SetManual(value, 1);
        }
        case ADMIN_ACTION_HEALTH:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param)) || !GetNextParam(inputtext, index, param2, sizeof(param2)) || !IsNumericString(param2)) return SendUsage(playerid, "ID vida");
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            value = strval(param2);
            if (value < 0) value = 0;
            if (value > 100) value = 100;
            SetPlayerHealth(targetid, float(value));
            SendClientMessage(playerid, COLOR_ORANGE, "Vida alterada.");
        }
        case ADMIN_ACTION_ARMOUR:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param)) || !GetNextParam(inputtext, index, param2, sizeof(param2)) || !IsNumericString(param2)) return SendUsage(playerid, "ID colete");
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            value = strval(param2);
            if (value < 0) value = 0;
            if (value > 100) value = 100;
            SetPlayerArmour(targetid, float(value));
            SendClientMessage(playerid, COLOR_ORANGE, "Colete alterado.");
        }
        case ADMIN_ACTION_SLAP:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param))) return SendUsage(playerid, "ID altura");
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            value = 5;
            if (GetNextParam(inputtext, index, param2, sizeof(param2)) && IsNumericString(param2)) value = strval(param2);
            if (value < 1) value = 1;
            if (value > 20) value = 20;
            GetPlayerPos(targetid, x, y, z);
            SetPlayerPos(targetid, x, y, z + float(value));
            SendClientMessage(playerid, COLOR_ORANGE, "Tapa aplicado.");
        }
        case ADMIN_ACTION_SETADMIN:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param)) || !GetNextParam(inputtext, index, param2, sizeof(param2)) || !IsNumericString(param2))
            {
                SendAdminLevelList(playerid);
                return SendUsage(playerid, "ID nivel");
            }
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            value = strval(param2);
            if (value < 0 || value > ADMIN_LEVEL_OWNER)
            {
                SendAdminLevelList(playerid);
                return SendClientMessage(playerid, COLOR_RED, "Nivel admin permitido: 0 a 5.");
            }
            PlayerInfo[targetid][pAdminLevel] = value;
            SaveAccountData(targetid);
            GetAdminLevelName(value, rankName, sizeof(rankName));
            format(message, sizeof(message), "Voce definiu o admin de ID %d para %s (%d).", targetid, rankName, value);
            SendClientMessage(playerid, COLOR_ORANGE, message);
            format(message, sizeof(message), "Seu nivel admin agora e %s (%d).", rankName, value);
            SendClientMessage(targetid, COLOR_ORANGE, message);
        }
        case ADMIN_ACTION_SETVIP:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param)) || !GetNextParam(inputtext, index, param2, sizeof(param2)) || !GetNextParam(inputtext, index, reason, sizeof(reason)) || !IsNumericString(param2) || !IsNumericString(reason))
            {
                return SendUsage(playerid, "ID nivel dias");
            }
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            value = strval(param2);
            value2 = strval(reason);
            if (value < VIP_BRONZE || value > VIP_DIAMANTE || value2 <= 0 || value2 > 365)
            {
                return SendClientMessage(playerid, COLOR_RED, "Use nivel 1 a 4 e dias entre 1 e 365.");
            }
            format(message, sizeof(message), "admin_dialog=%d", playerid);
            Vip_SetPlayer(targetid, value, value2, message, 1);
            SendClientMessage(playerid, COLOR_GREEN, "VIP definido.");
        }
        case ADMIN_ACTION_REMOVEVIP:
        {
            if (!GetNextParam(inputtext, index, param, sizeof(param)))
            {
                return SendUsage(playerid, "ID");
            }
            if (!ParseTargetPlayer(playerid, param, targetid)) return 1;
            format(message, sizeof(message), "admin_dialog=%d", playerid);
            Vip_SetPlayer(targetid, VIP_NONE, 0, message, 1);
            SendClientMessage(playerid, COLOR_GREEN, "VIP removido.");
        }
        case ADMIN_ACTION_RELOADVIP:
        {
            Vip_UpdateAll();
            SendClientMessage(playerid, COLOR_GREEN, "Ativacoes VIP do painel verificadas.");
        }
        case ADMIN_ACTION_EDIT_MAP:
        {
            return ShowEditMapDialog(playerid);
        }
        default:
        {
            return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_STAFF);
        }
    }

    format(message, sizeof(message), "dialog_action=%d input=%s", actionid, inputtext);
    WritePlayerLog(LOG_ADMIN_FILE, "DIALOG_ACTION", playerid, message);
    return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_STAFF);
}

stock HandlePlayerMenuMainDialog(playerid, response, listitem)
{
    new categoryid;

    if (!response)
    {
        return 1;
    }

    if (listitem < 0 || listitem >= gPlayerMenuDialogCount[playerid])
    {
        return ShowPlayerMainMenu(playerid);
    }

    categoryid = gPlayerMenuDialogCategories[playerid][listitem];
    if (categoryid == MENU_CAT_STAFF && !Help_CanViewStaff(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas staff pode abrir os comandos de administracao.");
        return ShowPlayerMainMenu(playerid);
    }

    return ShowPlayerMenuCategoryDialog(playerid, categoryid);
}

stock HandleMenuPlayerCategory(playerid, listitem)
{
    switch (listitem)
    {
        case 0: SendPlayerStatsMessage(playerid);
        case 1: SendPlayerAccountMessage(playerid);
        case 2: return ShowInventoryDialog(playerid);
        case 3: return ShowVipDialog(playerid);
        case 4: return ShowVipPurchaseInfo(playerid);
        case 5: return Vip_ClaimDailyKit(playerid);
        case 6:
        {
            if (SaveAccountData(playerid))
            {
                SendClientMessage(playerid, COLOR_GREEN, "Conta salva com sucesso.");
            }
        }
        case 7: return StartPlayerTutorial(playerid);
        case 8: return ShowHelpDialog(playerid);
        case 9: return SendAdminsList(playerid);
        case 10: return ShowBugReportInputDialog(playerid);
        case 11: return Radio_PlayDefaultStation(playerid, RADIO_SOURCE_PERSONAL);
        case 12: return Radio_Stop(playerid);
        default: return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_PLAYER);
    }

    return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_PLAYER);
}

stock HandleMenuGpsCategory(playerid, listitem)
{
    switch (listitem)
    {
        case 0:
        {
            if (Work_IsActive(playerid))
            {
                SendClientMessage(playerid, COLOR_ORANGE, "Conclua ou cancele seu expediente antes de usar o GPS.");
                return 1;
            }
            return ShowGpsDialog(playerid);
        }
        case 1: return ShowNpcTransportDialog(playerid);
        case 2: SetPlayerGps(playerid, LOCATION_PREFEITURA);
        case 3: SetPlayerGps(playerid, LOCATION_HOSPITAL);
        case 4: SetPlayerGps(playerid, LOCATION_DELEGACIA);
        case 5: SetPlayerGps(playerid, LOCATION_BANCO);
        case 6: SetPlayerGps(playerid, LOCATION_POSTO_IDLEWOOD);
        case 7: SetPlayerGps(playerid, LOCATION_CONCESSIONARIA);
        case 8: SetPlayerGps(playerid, LOCATION_DETRAN);
        case 9: SetPlayerGps(playerid, LOCATION_GARAGEM_PUBLICA);
        case 10: SetPlayerGps(playerid, LOCATION_PATIO_MUNICIPAL);
        default: return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_GPS);
    }
    return 1;
}

stock HandleMenuBankPhoneCategory(playerid, listitem)
{
    switch (listitem)
    {
        case 0: return ShowPhoneHomeDialog(playerid);
        case 1: return Life_ServiceCall_ShowCreate(playerid);
        case 2: return ShowBankDialog(playerid, BANK_ACCESS_PHONE);
        case 3: return ShowPhoneGovDialog(playerid);
        case 4: return Life_ShowDailyJourney(playerid);
        case 5: return Life_ShowWeeklyAgenda(playerid);
        case 6: return Life_ShowNeighborhoodEvents(playerid);
        case 7: return Life_ShowUrbanProgress(playerid);
        case 8: return ShowPhoneDeliveryDialog(playerid);
        case 9: return ShowPhoneRideDialog(playerid);
        case 10:
        {
            Bank_ShowStatus(playerid);
            return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_BANK_PHONE);
        }
        case 11:
        {
            Bank_PayFines(playerid);
            return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_BANK_PHONE);
        }
        case 12:
        {
            Life_ShowBankScore(playerid);
            return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_BANK_PHONE);
        }
        case 13: return Life_ShowDocumentsDialog(playerid);
        case 14: return Life_ShowTaxesDialog(playerid);
        case 15: return Life_ShowBillsDialog(playerid);
        case 16: return Life_ShowContractsDialog(playerid);
        case 17: return Life_ShowCartorioDialog(playerid);
        case 18: return Life_ShowBusinessDialog(playerid);
        case 19: return Life_ShowMarketDialog(playerid);
    }
    return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_BANK_PHONE);
}

stock HandleMenuVehicleCategory(playerid, listitem)
{
    switch (listitem)
    {
        case 0: Dealership_ShowVehicleInfo(playerid);
        case 1: Dealership_ShowAllVehicles(playerid);
        case 2: return Dealership_ShowGarageDialog(playerid);
        case 3: SpawnPlayerOwnedVehicle(playerid);
        case 4: ParkPlayerOwnedVehicle(playerid);
        case 5: GuardPlayerOwnedVehicle(playerid);
        case 6: return Dealership_ShowDetranDialog(playerid);
        case 7: Dealership_BuyInsurance(playerid);
        case 8: Dealership_ShowVehicleTax(playerid);
        case 9: Dealership_PayVehicleTax(playerid);
        case 10: Dealership_SellActiveVehicle(playerid);
        case 11: Dealership_TowPlayerVehicle(playerid);
        case 12: Dealership_RecoverImpound(playerid);
        case 13: return Radio_PlayDefaultStation(playerid, RADIO_SOURCE_VEHICLE);
        case 14:
        {
            if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
            {
                SendClientMessage(playerid, COLOR_GRAY, "Voce precisa estar dirigindo para desligar a radio do veiculo.");
                return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_VEHICLES);
            }
            Radio_StopVehicleStation(GetPlayerVehicleID(playerid), 1);
        }
        case 15: Fuel_TogglePlayerEngine(playerid);
        case 16: Menu_ShowVehicleFuel(playerid);
        case 17: Menu_RefuelVehicle(playerid);
        case 18: NpcWorkshopRepair(playerid);
        case 19: Dealership_SetVehicleLock(playerid, 1);
        case 20: Dealership_SetVehicleLock(playerid, 0);
        case 21:
        {
            SetPlayerGps(playerid, LOCATION_CONCESSIONARIA);
            return 1;
        }
        case 22:
        {
            SetPlayerGps(playerid, LOCATION_DETRAN);
            return 1;
        }
        case 23:
        {
            SetPlayerGps(playerid, LOCATION_PATIO_MUNICIPAL);
            return 1;
        }
        case 24: Fuel_ChargePlayerVehicle(playerid);
        case 25: Fuel_SendPlayerVehicleStatus(playerid);
        default: return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_VEHICLES);
    }
    return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_VEHICLES);
}

stock HandleMenuJobsCategory(playerid, listitem)
{
    switch (listitem)
    {
        case 0: Job_SendCurrentInfo(playerid);
        case 1: return ShowCityHallJobPanelDialog(playerid);
        case 2: return CityHall_AssignDeliveryJob(playerid);
        case 3: Work_Start(playerid);
        case 4: Job_GenericService(playerid);
        case 5:
        {
            if (!Work_Cancel(playerid))
            {
                SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta em expediente.");
            }
        }
        case 6:
        {
            Work_Cancel(playerid, 0);
            SetPlayerJob(playerid, JOB_NONE);
            SendClientMessage(playerid, COLOR_ORANGE, "Voce saiu do seu emprego atual.");
        }
        case 7:
        {
            Menu_GpsCurrentJob(playerid);
            return 1;
        }
        default: return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_JOBS);
    }
    return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_JOBS);
}

stock HandleMenuPropertiesCategory(playerid, listitem)
{
    switch (listitem)
    {
        case 0: return ShowPhonePropertiesDialog(playerid);
        case 1: return ShowPropertiesList(playerid);
        case 2:
        {
            Property_SendInfo(playerid);
            return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_PROPERTIES);
        }
        case 3:
        {
            SetPlayerGps(playerid, LOCATION_BANCO);
            return 1;
        }
        case 4: return ShowPhoneHomeDialog(playerid);
    }
    return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_PROPERTIES);
}

stock HandleMenuPublicCategory(playerid, listitem)
{
    switch (listitem)
    {
        case 0: return ShowPhoneGovDialog(playerid);
        case 1: return Life_ShowDailyJourney(playerid);
        case 2: return Life_ShowWeeklyAgenda(playerid);
        case 3: return Life_ShowNeighborhoodEvents(playerid);
        case 4: return Life_ShowUrbanProgress(playerid);
        case 5: return Life_ServiceCall_ShowCreate(playerid);
        case 6: return Life_ServiceCall_ShowList(playerid);
        case 7: SetPlayerGps(playerid, LOCATION_PREFEITURA);
        case 8: SetPlayerGps(playerid, LOCATION_HOSPITAL);
        case 9: SetPlayerGps(playerid, LOCATION_DELEGACIA);
        case 10:
        {
            Hospital_SendStatus(playerid);
            return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_PUBLIC);
        }
        case 11:
        {
            Life_ShowHealthDialog(playerid);
            return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_PUBLIC);
        }
        case 12:
        {
            Police_SendRecord(playerid, playerid);
            return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_PUBLIC);
        }
        case 13: return Life_ShowJusticeDialog(playerid);
        case 14:
        {
            Police_PayBail(playerid);
            return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_PUBLIC);
        }
        case 15:
        {
            Bank_PayFines(playerid);
            return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_PUBLIC);
        }
        case 16: return Police_ShowBlitzDialog(playerid);
        case 17:
        {
            Police_CreateBlitz(playerid);
            return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_PUBLIC);
        }
        case 18:
        {
            Police_DestroyNearestBlitz(playerid);
            return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_PUBLIC);
        }
        case 19: return Life_ShowCartorioDialog(playerid);
        case 20: return Life_ShowBillsDialog(playerid);
        case 21: return Life_PublicMission_Start(playerid);
        case 22: return Life_ShowConstitutionDialog(playerid);
        default: return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_PUBLIC);
    }
    return 1;
}

stock HandleMenuTutorialCategory(playerid, listitem)
{
    switch (listitem)
    {
        case 0: return StartPlayerTutorial(playerid);
        case 1: return ShowHelpDialog(playerid);
        case 2: return ShowGpsDialog(playerid);
        case 3: return ShowPhoneHomeDialog(playerid);
    }
    return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_TUTORIAL);
}

stock HandleMenuStaffCategory(playerid, listitem)
{
    new actionid;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas staff pode usar este painel.");
        return 1;
    }

    if (listitem < 0 || listitem >= gPlayerAdminMenuActionCount[playerid])
    {
        return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_STAFF);
    }

    actionid = gPlayerAdminMenuActions[playerid][listitem];

    switch (actionid)
    {
        case ADMIN_ACTION_ADMINS:
        {
            return SendAdminsList(playerid);
        }
        case ADMIN_ACTION_BUG_REPORTS:
        {
            return ShowBugReportsDialog(playerid);
        }
        case ADMIN_ACTION_ANTI_ABUSE:
        {
            return Ops_ShowAntiAbusePanel(playerid);
        }
        case ADMIN_ACTION_SPAWN:
        {
            SetPlayerToLocation(playerid, LOCATION_SPAWN);
        }
        case ADMIN_ACTION_REPAIR:
        {
            if (!IsPlayerInAnyVehicle(playerid))
            {
                SendClientMessage(playerid, COLOR_GRAY, "Entre em um veiculo.");
            }
            else
            {
                RepairVehicle(GetPlayerVehicleID(playerid));
                SendClientMessage(playerid, COLOR_GREEN, "Veiculo reparado.");
            }
        }
        case ADMIN_ACTION_SAVEPOS:
        {
            SavePlayerPositionToFile(playerid, "menu_staff");
            UpdatePlayerLiveData(playerid);
            SaveAccountData(playerid, 0);
            SendClientMessage(playerid, COLOR_GREEN, "Coordenada salva como menu_staff.");
        }
        case ADMIN_ACTION_DV:
        {
            Menu_StaffDeleteVehicle(playerid);
        }
        case ADMIN_ACTION_CLEARCHAT:
        {
            Admin_ClearChat(playerid);
        }
        case ADMIN_ACTION_RELOADBOT:
        {
            Bot_Reload();
            SendClientMessage(playerid, COLOR_GREEN, "Bot recarregado a partir dos arquivos txt.");
        }
        case ADMIN_ACTION_STAFF_HELP:
        {
            return ShowAdminHelpDialog(playerid);
        }
        case ADMIN_ACTION_RADAR_HELP:
        {
            return ShowHelpCategoryDialog(playerid, HELP_CAT_RADAR);
        }
        case ADMIN_ACTION_RELOADVIP:
        {
            Vip_UpdateAll();
            SendClientMessage(playerid, COLOR_GREEN, "Ativacoes VIP do painel verificadas.");
        }
        case ADMIN_ACTION_ADD_OBJECT:
        {
            return MapObj_ShowStaticDialog(playerid);
        }
        case ADMIN_ACTION_ADD_GATE:
        {
            return MapObj_ShowGateDialog(playerid);
        }
        case ADMIN_ACTION_WARN, ADMIN_ACTION_MUTE, ADMIN_ACTION_UNMUTE, ADMIN_ACTION_KICK, ADMIN_ACTION_GOTO, ADMIN_ACTION_GETHERE, ADMIN_ACTION_SETSKIN, ADMIN_ACTION_VEH, ADMIN_ACTION_FREEZE, ADMIN_ACTION_UNFREEZE, ADMIN_ACTION_PUNISH, ADMIN_ACTION_UNPUNISH, ADMIN_ACTION_MONEY, ADMIN_ACTION_LICENSE, ADMIN_ACTION_TIME, ADMIN_ACTION_WEATHER, ADMIN_ACTION_HEALTH, ADMIN_ACTION_ARMOUR, ADMIN_ACTION_SLAP, ADMIN_ACTION_SETADMIN, ADMIN_ACTION_SETVIP, ADMIN_ACTION_REMOVEVIP:
        {
            return ShowAdminActionInput(playerid, actionid);
        }
        default: return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_STAFF);
    }

    return ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_STAFF);
}

stock HandlePlayerMenuCategoryDialog(playerid, response, listitem)
{
    if (!response)
    {
        return ShowPlayerMainMenu(playerid);
    }

    switch (gPlayerMenuCategory[playerid])
    {
        case MENU_CAT_PLAYER: return HandleMenuPlayerCategory(playerid, listitem);
        case MENU_CAT_GPS: return HandleMenuGpsCategory(playerid, listitem);
        case MENU_CAT_BANK_PHONE: return HandleMenuBankPhoneCategory(playerid, listitem);
        case MENU_CAT_VEHICLES: return HandleMenuVehicleCategory(playerid, listitem);
        case MENU_CAT_JOBS: return HandleMenuJobsCategory(playerid, listitem);
        case MENU_CAT_PROPERTIES: return HandleMenuPropertiesCategory(playerid, listitem);
        case MENU_CAT_PUBLIC: return HandleMenuPublicCategory(playerid, listitem);
        case MENU_CAT_TUTORIAL: return HandleMenuTutorialCategory(playerid, listitem);
        case MENU_CAT_STAFF: return HandleMenuStaffCategory(playerid, listitem);
    }

    return ShowPlayerMainMenu(playerid);
}

stock ShowTutorialStep(playerid, step)
{
    new title[64];
    new body[1152];

    if (step < 0)
    {
        step = 0;
    }
    if (step > TUTORIAL_LAST_STEP)
    {
        step = TUTORIAL_LAST_STEP;
    }

    gPlayerTutorialStep[playerid] = step;
    format(title, sizeof(title), "Tutorial %d/%d", step + 1, TUTORIAL_LAST_STEP + 1);

    switch (step)
    {
        case 0:
        {
            format(body, sizeof(body), "Bem-vindo ao %s.\n\nAqui voce joga um Life Simulator/RP com identidade, documentos, profissao, dinheiro, banco, veiculos, imoveis, empresas, saude, justica, policia, eventos e NPCs.\n\nUse /menu como central principal.", gServerName);
        }
        case 1:
        {
            format(body, sizeof(body), "Identidade, HUD e conta\n\nUse nome RP no formato Nome_Sobrenome. O HUD mostra dinheiro, localizacao, clima, profissao, nivel, XP, fome, sede, prisao e veiculo.\n\nUse /minhaconta, /stats, /salvar e /ajuda.");
        }
        case 2:
        {
            format(body, sizeof(body), "GPS, menu e interacao\n\nUse /gps ou Menu > GPS para Prefeitura, hospital, delegacias, PRF, banco, DETRAN, garagem, concessionaria, empresas e empregos.\n\nAo chegar, procure o texto 3D e aperte ENTER ou use /interagir.");
        }
        case 3:
        {
            format(body, sizeof(body), "Documentos, GovBR e primeira jornada\n\nEmita documentos na Prefeitura, acompanhe vencimentos, multas, boletos, score, jornada diaria 2.0, agenda semanal 2.0, eventos por bairro 2.0 e proximos passos no GovBR/celular.\n\nUse /celular, /govbr, /jornadadiaria, /agendasemanal, /bairros, /documentos, /primeirajornada e /proximopasso.");
        }
        case 4:
        {
            format(body, sizeof(body), "Banco, dinheiro e dividas\n\nAbra conta no Banco Central, use caixa/celular para saldo, PIX, emprestimo, parcelas, multas, boletos, salario e cartao.\n\nFluxos de pagamento validam dinheiro real para evitar saldo bugado.");
        }
        case 5:
        {
            format(body, sizeof(body), "Profissoes e progressao\n\nEscolha emprego, receba salario diario, entre em expediente, conclua checkpoints e faca bicos para renda extra. Profissoes possuem nivel, XP, bonus, veiculos e permissao por cargo.\n\nUse /emprego, /trabalhar, /bico, /servico, /progresso e /objetivos.");
        }
        case 6:
        {
            format(body, sizeof(body), "Veiculos, DETRAN e radares\n\nCompre veiculo, registre no DETRAN, pague IPVA/seguro/vistoria, use garagem e guincho. Radares multam, mas servidor publico em servico nao recebe multa.\n\nUse /meuveiculo, /garagem, /detran, /motor e /abastecer.");
        }
        case 7:
        {
            format(body, sizeof(body), "Empresas, contratos e estoque\n\nEmpresas possuem estoque, caixa, funcionarios, pedidos, contratos, divida, falencia e recuperacao judicial. A economia muda por falta/excesso de produtos.\n\nUse /empresa, /contratos e GovBR.");
        }
        case 8:
        {
            format(body, sizeof(body), "Imoveis, VIP e inventario\n\nVoce pode comprar ou alugar casa, guardar itens, usar inventario, radios e beneficios VIP quando tiver permissao.\n\nUse /imoveis, /casas, /minhacasa, /inventario, /radio e /vip.");
        }
        case 9:
        {
            format(body, sizeof(body), "Saude, necessidades e hospital\n\nFome e sede caem com o tempo. Hospital/SAMU atendem ferimentos, plantao, remedios, internacao leve e plano de saude.\n\nUse /saude, /plano, /prontuario e compre comida/bebida em lojas.");
        }
        case 10:
        {
            format(body, sizeof(body), "Policia, justica e leis\n\nPolicia pode abordar, algemar, prender por crime/artigo e consultar ficha. Juiz atua em flagrante, trafico, pensao, recurso e sentenca.\n\nUse /leis ou /constituicao para conhecer direitos, crimes e penas.");
        }
        case 11:
        {
            format(body, sizeof(body), "Eventos, missoes e NPCs\n\nA cidade tem eventos dinamicos, bonus de profissao, metas leves por bairro, zona de guerra, NPCs, ocorrencias publicas e missoes no GovBR.\n\nUse /bairros, /eventos, /noticias, /missaopublica, /missoes e /atividades.");
        }
        default:
        {
            format(body, sizeof(body), "Regras, ajuda e conclusao\n\nRespeite RP, staff, leis, radares, abordagens e outros players. Use /ajuda, /menu, /proximopasso, /reportarbug e /admins quando precisar.\n\nAo concluir, este tutorial fica salvo na sua conta e nao abre sozinho de novo.");
        }
    }

    ShowPlayerDialog(playerid, DIALOG_TUTORIAL, DIALOG_STYLE_MSGBOX, title, body, step == TUTORIAL_LAST_STEP ? ("Concluir") : ("Proximo"), "Fechar");
    return 1;
}

stock StartPlayerTutorial(playerid, force = 1)
{
    gPlayerTutorialShown[playerid] = 1;
    if (!force && PlayerInfo[playerid][pIntroTutorialDone])
    {
        return 1;
    }
    return ShowTutorialStep(playerid, 0);
}

stock HandleTutorialDialog(playerid, response)
{
    if (!response)
    {
        return 1;
    }

    if (gPlayerTutorialStep[playerid] >= TUTORIAL_LAST_STEP)
    {
        if (!PlayerInfo[playerid][pIntroTutorialDone])
        {
            PlayerInfo[playerid][pIntroTutorialDone] = 1;
            SaveAccountData(playerid, 0);
            SendClientMessage(playerid, COLOR_GREEN, "Tutorial inicial concluido e salvo na sua conta.");
        }
        Onboarding_ShowNext(playerid);
        return ShowPlayerMainMenu(playerid);
    }

    return ShowTutorialStep(playerid, gPlayerTutorialStep[playerid] + 1);
}

stock Onboarding_ShowNext(playerid)
{
    return Life_ShowNextStepDialog(playerid);
}

stock Tutorial_OnPlayerSpawn(playerid)
{
    if (!PlayerInfo[playerid][pIntroTutorialDone] && !gPlayerTutorialShown[playerid])
    {
        return StartPlayerTutorial(playerid, 0);
    }
    return 1;
}

stock HandlePlayerCommands(playerid, cmdtext[])
{
    new command[32];
    new param[32];
    new message[128];
    new index;
    new helpIndex;

    index = GetCommandName(cmdtext, command, sizeof(command));
    Dispatch_CommandTrace(playerid, command, "cadeia-player", "entrada", "checking");

    if (strcmp(command, "/ajuda", true) == 0 || strcmp(command, "/help", true) == 0 || strcmp(command, "/comandos", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "ajuda", "handled");
        helpIndex = index;
        while (GetNextParam(cmdtext, helpIndex, param, sizeof(param)))
        {
            if (Help_IsJobAlias(param))
            {
                return ShowHelpCategoryDialog(playerid, HELP_CAT_JOBS);
            }
            if (Help_IsPublicAlias(param))
            {
                return ShowHelpCategoryDialog(playerid, HELP_CAT_PUBLIC);
            }
            if (Help_IsStaffAlias(param))
            {
                if (!Help_CanViewStaff(playerid))
                {
                    Help_SendStaffOnly(playerid);
                    return ShowHelpDialog(playerid);
                }
                return ShowHelpCategoryDialog(playerid, HELP_CAT_STAFF);
            }
        }
        ShowHelpDialog(playerid);
        return 1;
    }

    if (strcmp(command, "/atualizacao", true) == 0 || strcmp(command, "/atualizacoes", true) == 0 || strcmp(command, "/changelog", true) == 0 || strcmp(command, "/novidades", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "changelog", "handled");
        return ShowChangelogMenuDialog(playerid);
    }

    if (strcmp(command, "/versao", true) == 0 || strcmp(command, "/version", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "versao", "handled");
        return ShowGmVersionDialog(playerid);
    }

    if (strcmp(command, "/trocarsenha", true) == 0 || strcmp(command, "/mudarsenha", true) == 0 || strcmp(command, "/senha", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "trocar-senha", "handled");
        return Account_ShowPassCurrentDlg(playerid);
    }

    if (strcmp(command, "/trocarnome", true) == 0 || strcmp(command, "/mudarnick", true) == 0 || strcmp(command, "/mudarnome", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "trocar-nome", "handled");
        if (GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return Account_HandleRenameNameDlg(playerid, 1, param);
        }
        return Account_ShowRenameNameDlg(playerid);
    }

    if (strcmp(command, "/saudegm", true) == 0 || strcmp(command, "/healthgm", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "saude-gm", "handled");
        return ShowGmHealthDialog(playerid);
    }

    if (strcmp(command, "/integridade", true) == 0 || strcmp(command, "/integrity", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "integridade", "handled");
        return ShowGmIntegrityDialog(playerid);
    }

    if (strcmp(command, "/releasecheck", true) == 0 || strcmp(command, "/checkrelease", true) == 0 || strcmp(command, "/check1", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "releasecheck", "handled");
        return ShowGmReleaseCheckDialog(playerid);
    }

    if (strcmp(command, "/selftestgm", true) == 0 || strcmp(command, "/testegm", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "selftest-gm", "handled");
        if (GetNextParam(cmdtext, index, param, sizeof(param)) && (strcmp(param, "reparar", true) == 0 || strcmp(param, "corrigir", true) == 0))
        {
            return ShowGmSelfTestDialog(playerid, 1);
        }
        return ShowGmSelfTestDialog(playerid, 0);
    }

    if (strcmp(command, "/debugplayer", true) == 0 || strcmp(command, "/debugjogador", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "debug-player", "handled");
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/debugplayer [id]");
        }
        return ShowDebugPlayerDialog(playerid, strval(param));
    }

    if (strcmp(command, "/ajudaadmin", true) == 0 || strcmp(command, "/ajudaadm", true) == 0 || strcmp(command, "/adminhelp", true) == 0 || strcmp(command, "/comandosadmin", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "ajuda-admin", "handled");
        return ShowAdminHelpDialog(playerid);
    }
    if (strcmp(command, "/debugcomando", true) == 0 || strcmp(command, "/debugcmd", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "debug-comando", "handled");
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/debugcomando [comando]");
        }
        return Dispatch_DebugCommand(playerid, param);
    }
    if (strcmp(command, "/testarcomandos", true) == 0 || strcmp(command, "/testecmd", true) == 0 || strcmp(command, "/checkcomandos", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "teste-comandos", "handled");
        return Dispatch_ShowCommandTest(playerid);
    }

    if (strcmp(command, "/notfounds", true) == 0 || strcmp(command, "/notfoundcmd", true) == 0 || strcmp(command, "/falhascmd", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "notfounds", "handled");
        if (GetNextParam(cmdtext, index, param, sizeof(param)) && (strcmp(param, "aplicar", true) == 0 || strcmp(param, "add", true) == 0))
        {
            return Dispatch_ShowNotFoundApplyList(playerid);
        }
        return Dispatch_ShowNotFoundReport(playerid);
    }
    if (strcmp(command, "/notfoundshistorico", true) == 0 || strcmp(command, "/historiconotfounds", true) == 0 || strcmp(command, "/nfhistorico", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "notfounds-historico", "handled");
        return Dispatch_ShowNotFoundHistory(playerid);
    }
    if (strcmp(command, "/posdeploy", true) == 0 || strcmp(command, "/postdeploy", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "posdeploy", "handled");
        return Dispatch_ShowPostDeploy(playerid);
    }
    if (strcmp(command, "/cmdfixpromover", true) == 0 || strcmp(command, "/promovercmdfix", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "cmdfix-promover", "handled");
        return Dispatch_ShowCmdFixPromote(playerid);
    }
    if (strcmp(command, "/cmdmodulos", true) == 0 || strcmp(command, "/moduloscmd", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "cmdmodulos", "handled");
        return Dispatch_ShowCommandModules(playerid);
    }
    if (strcmp(command, "/balancegm", true) == 0 || strcmp(command, "/balancogm", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "balance-gm", "handled");
        if (GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return Dispatch_ShowBalanceGm(playerid, param);
        }
        return Dispatch_ShowBalanceGm(playerid);
    }

    if (strcmp(command, "/iacomandos", true) == 0 || strcmp(command, "/sentinelacmd", true) == 0)
    {
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
        {
            return SendNoPermission(playerid);
        }

        SendClientMessage(playerid, COLOR_GREEN, "IA de comandos ativa: registra todos os comandos e alerta falhas somente para admin nivel 5.");
        SendClientMessage(playerid, COLOR_YELLOW, "Log: scriptfiles/log_command_ai.txt | Falhas: HANDLER_RETURN_0, NOT_FOUND, BLOCKED.");
        return 1;
    }

    if (strcmp(command, "/desbugar", true) == 0 || strcmp(command, "/unstuck", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "unstuck", "handled");
        return UnstuckPlayerFlow(playerid);
    }

    if (strcmp(command, "/menu", true) == 0 || strcmp(command, "/painel", true) == 0 || strcmp(command, "/central", true) == 0 || strcmp(command, "/minhacentral", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "menu", "handled");
        ShowPlayerMainMenu(playerid);
        return 1;
    }

    if (strcmp(command, "/tutorial", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "tutorial", "handled");
        StartPlayerTutorial(playerid);
        return 1;
    }

    if (strcmp(command, "/inicio", true) == 0 || strcmp(command, "/proximopasso", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "onboarding", "handled");
        Onboarding_ShowNext(playerid);
        return 1;
    }

    if (strcmp(command, "/bug", true) == 0 || strcmp(command, "/problema", true) == 0 || strcmp(command, "/relatarbug", true) == 0 || strcmp(command, "/reportarbug", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "bug-report", "handled");
        if (!GetRemainingText(cmdtext, index, message, sizeof(message)))
        {
            return ShowBugReportInputDialog(playerid);
        }

        return SaveBugReport(playerid, message);
    }

    Dispatch_CommandTrace(playerid, command, "submodulo", "radio", "checking");
    if (Radio_HandleCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "radio", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "radio", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo", "vip", "checking");
    if (HandleVipCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "vip", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "vip", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo", "clima", "checking");
    if (Climate_HandleCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "clima", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "clima", "miss");

    if (strcmp(command, "/editarmapa", true) == 0 || strcmp(command, "/mapeditor", true) == 0 || strcmp(command, "/editmapa", true) == 0 || strcmp(command, "/editar", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "editarmapa", "handled");
        return ShowEditMapDialog(playerid);
    }

    Dispatch_CommandTrace(playerid, command, "submodulo", "mapa", "checking");
    if (MapObjects_HandleCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "mapa", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "mapa", "miss");

    if (strcmp(command, "/admin", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "painel-admin", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
        {
            SendClientMessage(playerid, COLOR_RED, "Apenas staff pode usar o painel admin.");
            return 1;
        }

        ShowPlayerMenuCategoryDialog(playerid, MENU_CAT_STAFF);
        return 1;
    }

    if (strcmp(command, "/stats", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "stats", "handled");
        SendPlayerStatsMessage(playerid);
        return 1;
    }

    if (strcmp(command, "/minhaconta", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "conta", "handled");
        SendPlayerAccountMessage(playerid);
        return 1;
    }

    if (strcmp(command, "/pos", true) == 0 || strcmp(command, "/coords", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "posicao", "handled");
        SendPlayerPositionMessage(playerid);
        return 1;
    }

    if (strcmp(command, "/gps", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "gps", "handled");
        if (Work_IsActive(playerid))
        {
            SendClientMessage(playerid, COLOR_ORANGE, "Conclua ou cancele seu expediente antes de usar o GPS.");
            return 1;
        }

        ShowGpsDialog(playerid);
        return 1;
    }

    if (strcmp(command, "/meuveiculo", true) == 0 || strcmp(command, "/carro", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "veiculo-pessoal", "handled");
        SpawnPlayerOwnedVehicle(playerid);
        return 1;
    }

    if (strcmp(command, "/estacionar", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "estacionar", "handled");
        ParkPlayerOwnedVehicle(playerid);
        return 1;
    }

    if (strcmp(command, "/cancelarentrega", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "cancelar-trabalho", "handled");
        if (!Work_Cancel(playerid))
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta em expediente.");
        }
        return 1;
    }

    if (strcmp(command, "/interagir", true) == 0 || strcmp(command, "/interact", true) == 0 || strcmp(command, "/entrar", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "interacao", "handled");
        HandleLocationInteraction(playerid);
        return 1;
    }

    if (strcmp(command, "/sair", true) == 0 || strcmp(command, "/exit", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "sair-interior", "handled");
        if (!World_ExitAutoInterior(playerid))
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta em um interior automatico.");
        }
        return 1;
    }

    if (strcmp(command, "/taxinpc", true) == 0 || strcmp(command, "/onibusnpc", true) == 0 || strcmp(command, "/transporte", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "npc-transporte", "handled");
        ShowNpcTransportDialog(playerid);
        return 1;
    }

    if (strcmp(command, "/comprar", true) == 0 || strcmp(command, "/loja", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "loja", "handled");
        if (World_IsPlayerAtWeaponShop(playerid))
        {
            ShowWeaponShopDialog(playerid);
            return 1;
        }

        if (World_IsPlayerAtRestaurant(playerid))
        {
            ShowRestaurantDialog(playerid);
            return 1;
        }

        if (!World_IsPlayerAtNpcStore(playerid))
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce precisa estar no balcao de uma loja, conveniencia ou restaurante.");
            return 1;
        }

        ShowConvenienceStoreDialog(playerid);
        return 1;
    }

    if (strcmp(command, "/armas", true) == 0 || strcmp(command, "/lojarmas", true) == 0 || strcmp(command, "/municao", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "loja-armas", "handled");
        ShowWeaponShopDialog(playerid);
        return 1;
    }

    if (strcmp(command, "/cardapio", true) == 0 || strcmp(command, "/restaurante", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "restaurante", "handled");
        if (!World_IsPlayerAtRestaurant(playerid))
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce precisa estar no salao de um restaurante.");
            return 1;
        }

        ShowRestaurantDialog(playerid);
        return 1;
    }

    Dispatch_CommandTrace(playerid, command, "submodulo", "inventario", "checking");
    if (HandleInventoryCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "inventario", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "inventario", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo", "combustivel", "checking");
    if (HandleFuelCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "combustivel", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "combustivel", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo", "banco", "checking");
    if (HandleBankCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "banco", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "banco", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo", "celular", "checking");
    if (HandlePhoneCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "celular", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "celular", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo", "config", "checking");
    if (Config_HandleCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "config", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "config", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo", "pedagio", "checking");
    if (Tolls_HandleCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "pedagio", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "pedagio", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo", "vida-politica", "checking");
    if (Life_HandleCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "vida-politica", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "vida-politica", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo", "imoveis", "checking");
    if (HandlePropertyCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "imoveis", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "imoveis", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo", "veiculos", "checking");
    if (HandleDealershipCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "veiculos", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "veiculos", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo", "crime", "checking");
    if (Crime_HandleCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "crime", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "crime", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo", "policia", "checking");
    if (HandlePoliceCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "policia", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "policia", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo", "hospital", "checking");
    if (HandleHospitalCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "hospital", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "hospital", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo", "empregos", "checking");
    if (HandleJobCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "empregos", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo", "empregos", "miss");

    if (strcmp(command, "/spawn", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "spawn", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
        {
            return SendNoPermission(playerid);
        }

        SpawnPlayer(playerid);
        return 1;
    }

    if (strcmp(command, "/salvar", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "salvar-conta", "handled");
        if (SaveAccountData(playerid))
        {
            SendClientMessage(playerid, COLOR_GREEN, "Conta salva com sucesso.");
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Nao foi possivel salvar sua conta.");
        }
        return 1;
    }

    if (strcmp(command, "/reparar", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "reparar", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
        {
            return SendNoPermission(playerid);
        }

        if (!IsPlayerInAnyVehicle(playerid))
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce precisa estar em um veiculo.");
            return 1;
        }

        RepairVehicle(GetPlayerVehicleID(playerid));
        SendClientMessage(playerid, COLOR_GREEN, "Veiculo reparado.");
        return 1;
    }

    if (strcmp(command, "/g", true) == 0 || strcmp(command, "/global", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "chat-global", "handled");
        if (!GetRemainingText(cmdtext, index, message, sizeof(message)))
        {
            return SendUsage(playerid, "/g [texto]");
        }

        SendGlobalChatMessage(playerid, message);
        return 1;
    }

    Dispatch_CommandTrace(playerid, command, "cadeia-player", "saida", "miss");
    return 0;
}

stock Admin_IsOperationalCommand(command[])
{
    if (strcmp(command, "/a", true) == 0 || strcmp(command, "/admins", true) == 0 || strcmp(command, "/bugs", true) == 0 || strcmp(command, "/bugreports", true) == 0 || strcmp(command, "/relatos", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/checkserver", true) == 0 || strcmp(command, "/statusserver", true) == 0 || strcmp(command, "/serverstatus", true) == 0 || strcmp(command, "/releasecheck", true) == 0 || strcmp(command, "/integridade", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/checkrelease", true) == 0 || strcmp(command, "/manutencao", true) == 0 || strcmp(command, "/maintenance", true) == 0 || strcmp(command, "/whitelist", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/seguranca", true) == 0 || strcmp(command, "/security", true) == 0 || strcmp(command, "/selfheal", true) == 0 || strcmp(command, "/autocurar", true) == 0 || strcmp(command, "/reparargm", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/cmdfix", true) == 0 || strcmp(command, "/reloadcmdfix", true) == 0 || strcmp(command, "/cmdfixadd", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/ban", true) == 0 || strcmp(command, "/unban", true) == 0 || strcmp(command, "/desban", true) == 0 || strcmp(command, "/banidos", true) == 0 || strcmp(command, "/bans", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/bugprio", true) == 0 || strcmp(command, "/bugprioridade", true) == 0 || strcmp(command, "/bugresponder", true) == 0 || strcmp(command, "/bugnota", true) == 0 || strcmp(command, "/bugresolver", true) == 0 || strcmp(command, "/bugabrir", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/anuncio", true) == 0 || strcmp(command, "/av", true) == 0 || strcmp(command, "/avisar", true) == 0 || strcmp(command, "/mutar", true) == 0 || strcmp(command, "/mute", true) == 0 || strcmp(command, "/desmutar", true) == 0 || strcmp(command, "/unmute", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/punir", true) == 0 || strcmp(command, "/cadeiaadm", true) == 0 || strcmp(command, "/despunir", true) == 0 || strcmp(command, "/soltaradm", true) == 0 || strcmp(command, "/congelar", true) == 0 || strcmp(command, "/freeze", true) == 0 || strcmp(command, "/descongelar", true) == 0 || strcmp(command, "/unfreeze", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/setvida", true) == 0 || strcmp(command, "/setcolete", true) == 0 || strcmp(command, "/tapa", true) == 0 || strcmp(command, "/limparchat", true) == 0 || strcmp(command, "/reloadbot", true) == 0 || strcmp(command, "/recarregarbot", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/reloadradio", true) == 0 || strcmp(command, "/resetcomandos", true) == 0 || strcmp(command, "/recarregarcomandos", true) == 0 || strcmp(command, "/debugcomandos", true) == 0 || strcmp(command, "/cmddebug", true) == 0 || strcmp(command, "/iacomandos", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/sentinelacmd", true) == 0 || strcmp(command, "/notfounds", true) == 0 || strcmp(command, "/notfoundshistorico", true) == 0 || strcmp(command, "/posdeploy", true) == 0 || strcmp(command, "/cmdfixpromover", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/cmdmodulos", true) == 0 || strcmp(command, "/balancegm", true) == 0 || strcmp(command, "/testarcomandos", true) == 0 || strcmp(command, "/modoemergenciacmd", true) == 0 || strcmp(command, "/setadmin", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/setvip", true) == 0 || strcmp(command, "/tirarvip", true) == 0 || strcmp(command, "/removevip", true) == 0 || strcmp(command, "/reloadvip", true) == 0 || strcmp(command, "/recarregarvip", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/kick", true) == 0 || strcmp(command, "/ir", true) == 0 || strcmp(command, "/goto", true) == 0 || strcmp(command, "/trazer", true) == 0 || strcmp(command, "/gethere", true) == 0 || strcmp(command, "/setskin", true) == 0 || strcmp(command, "/dargrana", true) == 0 || strcmp(command, "/aprovarprof", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/autorizarnome", true) == 0 || strcmp(command, "/aprovartrocarnome", true) == 0 || strcmp(command, "/negarnome", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/veh", true) == 0 || strcmp(command, "/dv", true) == 0 || strcmp(command, "/savepos", true) == 0 || strcmp(command, "/sethora", true) == 0 || strcmp(command, "/setclima", true) == 0 || strcmp(command, "/ruasradar", true) == 0 || strcmp(command, "/radares", true) == 0 || strcmp(command, "/addradar", true) == 0 || strcmp(command, "/adicionarradar", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/addobjeto", true) == 0 || strcmp(command, "/addportao", true) == 0)
    {
        return 1;
    }
    if (strcmp(command, "/addjobveiculo", true) == 0)
    {
        return 1;
    }
    return 0;
}

stock HandleAdminCommands(playerid, cmdtext[])
{
    new command[32];
    new param[64];
    new param2[64];
    new message[128];
    new index;
    new targetid;
    new value;
    new color1;
    new color2;
    new rankName[32];

    index = GetCommandName(cmdtext, command, sizeof(command));
    Dispatch_CommandTrace(playerid, command, "cadeia-admin", "entrada", "checking");

    if (Admin_IsOperationalCommand(command) && HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        WritePlayerLog(LOG_ADMIN_FILE, "COMMAND", playerid, cmdtext);
    }

    if (strcmp(command, "/a", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "admin-chat", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
        {
            return SendNoPermission(playerid);
        }

        if (!GetRemainingText(cmdtext, index, message, sizeof(message)))
        {
            return SendUsage(playerid, "/a [texto]");
        }

        SendAdminChatMessage(playerid, message);
        return 1;
    }

    if (strcmp(command, "/admins", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "admins-online", "handled");
        SendAdminsList(playerid);
        return 1;
    }

    if (strcmp(command, "/bugs", true) == 0 || strcmp(command, "/bugreports", true) == 0 || strcmp(command, "/relatos", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "bug-reports", "handled");
        return ShowBugReportsDialog(playerid);
    }

    if (strcmp(command, "/autorizarnome", true) == 0 || strcmp(command, "/aprovartrocarnome", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "autorizar-nome", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_ADMIN))
        {
            return SendNoPermission(playerid);
        }
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/autorizarnome [id]");
        }
        return Account_ApproveRename(strval(param), playerid);
    }

    if (strcmp(command, "/negarnome", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "negar-nome", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_ADMIN))
        {
            return SendNoPermission(playerid);
        }
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/negarnome [id]");
        }
        return Account_DenyRename(strval(param), playerid);
    }

    Dispatch_CommandTrace(playerid, command, "submodulo-admin", "ops", "checking");
    if (Ops_HandleCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "ops", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo-admin", "ops", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo-admin", "seguranca", "checking");
    if (Security_HandleCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "seguranca", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo-admin", "seguranca", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo-admin", "selfheal", "checking");
    if (SelfHeal_HandleCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "selfheal", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo-admin", "selfheal", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo-admin", "cmdfix", "checking");
    if (CommandHotfix_HandleCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "cmdfix", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo-admin", "cmdfix", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo-admin", "config", "checking");
    if (Config_HandleCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "config-admin", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo-admin", "config", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo-admin", "bug-admin", "checking");
    if (BugReport_HandleAdminCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "bug-admin", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo-admin", "bug-admin", "miss");

    Dispatch_CommandTrace(playerid, command, "submodulo-admin", "radar", "checking");
    if (HandleRadarAdminCommands(playerid, cmdtext))
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "radar-admin", "handled");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "submodulo-admin", "radar", "miss");

    if (strcmp(command, "/objetosmapa", true) == 0 || strcmp(command, "/mapobjects", true) == 0 || strcmp(command, "/reloadobjetos", true) == 0 || strcmp(command, "/reloadmapobjects", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "submodulo-admin", "mapa", "direct");
        return MapObjects_HandleCommands(playerid, cmdtext);
    }

    if (strcmp(command, "/addobjeto", true) == 0 || strcmp(command, "/criarobjeto", true) == 0 || strcmp(command, "/salvarobjeto", true) == 0 || strcmp(command, "/addportao", true) == 0 || strcmp(command, "/criarportao", true) == 0 || strcmp(command, "/salvarportao", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "submodulo-admin", "mapa", "direct");
        return MapObjects_HandleCommands(playerid, cmdtext);
    }

    if (strcmp(command, "/jobveiculos", true) == 0 || strcmp(command, "/veiculostrabalho", true) == 0 || strcmp(command, "/reloadjobveiculos", true) == 0 || strcmp(command, "/recarregarjobveiculos", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "submodulo-admin", "job-veiculos", "direct");
        return HandleJobCommands(playerid, cmdtext);
    }

    if (strcmp(command, "/addjobveiculo", true) == 0 || strcmp(command, "/criarjobveiculo", true) == 0 || strcmp(command, "/salvarjobveiculo", true) == 0 || strcmp(command, "/removerjobveiculo", true) == 0 || strcmp(command, "/removerveiculo", true) == 0 || strcmp(command, "/irveiculo", true) == 0 || strcmp(command, "/irjobveiculo", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "submodulo-admin", "job-veiculos", "direct");
        return HandleJobCommands(playerid, cmdtext);
    }

    if (strcmp(command, "/anuncio", true) == 0 || strcmp(command, "/av", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "anuncio", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
        {
            return SendNoPermission(playerid);
        }

        if (!GetRemainingText(cmdtext, index, message, sizeof(message)))
        {
            return SendUsage(playerid, "/anuncio [texto]");
        }

        SendAdminAnnouncement(playerid, message);
        return 1;
    }

    if (strcmp(command, "/avisar", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "avisar", "handled");
        if (!GetRemainingText(cmdtext, index, message, sizeof(message)))
        {
            return SendUsage(playerid, "/avisar [id] [motivo]");
        }
        gPlayerAdminInputAction[playerid] = ADMIN_ACTION_WARN;
        return HandleAdminActionInput(playerid, 1, message);
    }

    if (strcmp(command, "/mutar", true) == 0 || strcmp(command, "/mute", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "mutar", "handled");
        if (!GetRemainingText(cmdtext, index, message, sizeof(message)))
        {
            return SendUsage(playerid, "/mutar [id] [minutos] [motivo]");
        }
        gPlayerAdminInputAction[playerid] = ADMIN_ACTION_MUTE;
        return HandleAdminActionInput(playerid, 1, message);
    }

    if (strcmp(command, "/desmutar", true) == 0 || strcmp(command, "/unmute", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "desmutar", "handled");
        if (!GetRemainingText(cmdtext, index, message, sizeof(message)))
        {
            return SendUsage(playerid, "/desmutar [id]");
        }
        gPlayerAdminInputAction[playerid] = ADMIN_ACTION_UNMUTE;
        return HandleAdminActionInput(playerid, 1, message);
    }

    if (strcmp(command, "/punir", true) == 0 || strcmp(command, "/cadeiaadm", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "punir", "handled");
        if (!GetRemainingText(cmdtext, index, message, sizeof(message)))
        {
            return SendUsage(playerid, "/punir [id] [minutos] [motivo]");
        }
        gPlayerAdminInputAction[playerid] = ADMIN_ACTION_PUNISH;
        return HandleAdminActionInput(playerid, 1, message);
    }

    if (strcmp(command, "/despunir", true) == 0 || strcmp(command, "/soltaradm", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "despunir", "handled");
        if (!GetRemainingText(cmdtext, index, message, sizeof(message)))
        {
            return SendUsage(playerid, "/despunir [id]");
        }
        gPlayerAdminInputAction[playerid] = ADMIN_ACTION_UNPUNISH;
        return HandleAdminActionInput(playerid, 1, message);
    }

    if (strcmp(command, "/congelar", true) == 0 || strcmp(command, "/freeze", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "congelar", "handled");
        if (!GetRemainingText(cmdtext, index, message, sizeof(message)))
        {
            return SendUsage(playerid, "/congelar [id]");
        }
        gPlayerAdminInputAction[playerid] = ADMIN_ACTION_FREEZE;
        return HandleAdminActionInput(playerid, 1, message);
    }

    if (strcmp(command, "/descongelar", true) == 0 || strcmp(command, "/unfreeze", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "descongelar", "handled");
        if (!GetRemainingText(cmdtext, index, message, sizeof(message)))
        {
            return SendUsage(playerid, "/descongelar [id]");
        }
        gPlayerAdminInputAction[playerid] = ADMIN_ACTION_UNFREEZE;
        return HandleAdminActionInput(playerid, 1, message);
    }

    if (strcmp(command, "/setvida", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "setvida", "handled");
        if (!GetRemainingText(cmdtext, index, message, sizeof(message)))
        {
            return SendUsage(playerid, "/setvida [id] [0-100]");
        }
        gPlayerAdminInputAction[playerid] = ADMIN_ACTION_HEALTH;
        return HandleAdminActionInput(playerid, 1, message);
    }

    if (strcmp(command, "/setcolete", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "setcolete", "handled");
        if (!GetRemainingText(cmdtext, index, message, sizeof(message)))
        {
            return SendUsage(playerid, "/setcolete [id] [0-100]");
        }
        gPlayerAdminInputAction[playerid] = ADMIN_ACTION_ARMOUR;
        return HandleAdminActionInput(playerid, 1, message);
    }

    if (strcmp(command, "/tapa", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "tapa", "handled");
        if (!GetRemainingText(cmdtext, index, message, sizeof(message)))
        {
            return SendUsage(playerid, "/tapa [id] [altura]");
        }
        gPlayerAdminInputAction[playerid] = ADMIN_ACTION_SLAP;
        return HandleAdminActionInput(playerid, 1, message);
    }

    if (strcmp(command, "/limparchat", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "limparchat", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_ADMIN))
        {
            return SendNoPermission(playerid);
        }
        Admin_ClearChat(playerid);
        return 1;
    }

    if (strcmp(command, "/reloadbot", true) == 0 || strcmp(command, "/recarregarbot", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "reloadbot", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_ADMIN))
        {
            return SendNoPermission(playerid);
        }
        Bot_Reload();
        SendClientMessage(playerid, COLOR_GREEN, "Bot recarregado a partir dos arquivos txt.");
        return 1;
    }

    if (strcmp(command, "/setadmin", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "setadmin", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
        {
            return SendNoPermission(playerid);
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)))
        {
            SendAdminLevelList(playerid);
            return SendUsage(playerid, "/setadmin [id] [nivel 0-5]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid) || !IsNumericString(param2))
        {
            return 1;
        }

        value = strval(param2);
        if (value < 0 || value > ADMIN_LEVEL_OWNER)
        {
            SendClientMessage(playerid, COLOR_RED, "Nivel admin permitido: 0 a 5.");
            SendAdminLevelList(playerid);
            return 1;
        }

        if (!PlayerInfo[targetid][pLogged])
        {
            SendClientMessage(playerid, COLOR_RED, "O jogador precisa estar logado.");
            return 1;
        }

        PlayerInfo[targetid][pAdminLevel] = value;
        SaveAccountData(targetid);
        GetAdminLevelName(value, rankName, sizeof(rankName));
        format(message, sizeof(message), "Voce definiu o admin de ID %d para %s (%d).", targetid, rankName, value);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        format(message, sizeof(message), "Seu nivel admin agora e %s (%d).", rankName, value);
        SendClientMessage(targetid, COLOR_ORANGE, message);
        return 1;
    }

    if (strcmp(command, "/kick", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "kick", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
        {
            return SendNoPermission(playerid);
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/kick [id] [motivo]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid))
        {
            return 1;
        }

        if (!GetRemainingText(cmdtext, index, param2, sizeof(param2)))
        {
            format(param2, sizeof(param2), "Sem motivo");
        }

        format(message, sizeof(message), "[ADMIN] ID %d foi kickado. Motivo: %s", targetid, param2);
        SendClientMessageToAll(COLOR_ADMIN, message);
        Kick(targetid);
        return 1;
    }

    if (strcmp(command, "/ir", true) == 0 || strcmp(command, "/goto", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "goto-player", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
        {
            return SendNoPermission(playerid);
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/goto [id]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid))
        {
            return 1;
        }

        TeleportPlayerNearPlayer(playerid, targetid);
        SendClientMessage(playerid, COLOR_ORANGE, "Voce foi teleportado.");
        return 1;
    }

    if (strcmp(command, "/trazer", true) == 0 || strcmp(command, "/gethere", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "trazer-player", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
        {
            return SendNoPermission(playerid);
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/gethere [id]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid))
        {
            return 1;
        }

        TeleportPlayerNearPlayer(targetid, playerid);
        SendClientMessage(playerid, COLOR_ORANGE, "Jogador trazido ate voce.");
        SendClientMessage(targetid, COLOR_ORANGE, "Voce foi trazido por um admin.");
        return 1;
    }

    if (strcmp(command, "/setskin", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "setskin", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
        {
            return SendNoPermission(playerid);
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)))
        {
            return SendUsage(playerid, "/setskin [id] [skin]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid) || !IsNumericString(param2))
        {
            return 1;
        }

        value = strval(param2);
        if (value < 0 || value > 311)
        {
            SendClientMessage(playerid, COLOR_RED, "Skin invalida. Use 0 a 311.");
            return 1;
        }

        SetPlayerSkin(targetid, value);
        PlayerInfo[targetid][pSkin] = value;
        SaveAccountData(targetid);
        format(message, sizeof(message), "Skin do ID %d alterada para %d.", targetid, value);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        return 1;
    }

    if (strcmp(command, "/dargrana", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "dargrana", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_MANAGER))
        {
            return SendNoPermission(playerid);
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)))
        {
            return SendUsage(playerid, "/dargrana [id] [valor]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid) || !IsNumericString(param2, 1))
        {
            return 1;
        }

        value = strval(param2);
        GivePlayerCashReason(targetid, value, 1, "admin_money_command");
        format(message, sizeof(message), "Voce alterou o dinheiro do ID %d em $%d.", targetid, value);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        format(message, sizeof(message), "Seu dinheiro foi alterado em $%d por um admin.", value);
        SendClientMessage(targetid, COLOR_ORANGE, message);
        UpdatePlayerHud(targetid);
        return 1;
    }

    if (strcmp(command, "/aprovarprof", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "aprovarprof", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_MANAGER))
        {
            return SendNoPermission(playerid);
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)))
        {
            return SendUsage(playerid, "/aprovarprof [id] [cnh|pesada|medico|oab|publico|policial|porte]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid))
        {
            return 1;
        }

        if (!PlayerInfo[targetid][pLogged])
        {
            SendClientMessage(playerid, COLOR_RED, "O jogador precisa estar logado.");
            return 1;
        }

        if (strcmp(param2, "cnh", true) == 0)
        {
            PlayerInfo[targetid][pLicenseCNH] = 1;
        }
        else if (strcmp(param2, "pesada", true) == 0)
        {
            PlayerInfo[targetid][pLicenseHeavy] = 1;
        }
        else if (strcmp(param2, "medico", true) == 0)
        {
            PlayerInfo[targetid][pLicenseMedical] = 1;
        }
        else if (strcmp(param2, "oab", true) == 0)
        {
            PlayerInfo[targetid][pLicenseOAB] = 1;
        }
        else if (strcmp(param2, "publico", true) == 0)
        {
            PlayerInfo[targetid][pLicensePublic] = 1;
        }
        else if (strcmp(param2, "policial", true) == 0 || strcmp(param2, "porte", true) == 0 || strcmp(param2, "arma", true) == 0)
        {
            PlayerInfo[targetid][pLicensePolice] = 1;
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Tipo invalido. Use cnh, pesada, medico, oab, publico, policial ou porte.");
            return 1;
        }

        SaveAccountData(targetid, 0);
        format(message, sizeof(message), "Licenca/aprovacao '%s' concedida ao ID %d.", param2, targetid);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        SendClientMessage(targetid, COLOR_GREEN, "Voce recebeu uma licenca/aprovacao profissional da administracao.");
        return 1;
    }

    if (strcmp(command, "/veh", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "criar-veiculo", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
        {
            return SendNoPermission(playerid);
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/veh [modelo 400-611] [cor1] [cor2]");
        }

        value = strval(param);
        if (value < 400 || value > 611)
        {
            SendClientMessage(playerid, COLOR_RED, "Modelo de veiculo invalido. Use 400 a 611.");
            return 1;
        }

        color1 = 1;
        color2 = 1;
        if (GetNextParam(cmdtext, index, param2, sizeof(param2)) && IsNumericString(param2, 1))
        {
            color1 = strval(param2);
        }
        if (GetNextParam(cmdtext, index, param2, sizeof(param2)) && IsNumericString(param2, 1))
        {
            color2 = strval(param2);
        }

        if (!CreateAdminVehicle(playerid, value, color1, color2))
        {
            SendClientMessage(playerid, COLOR_RED, "Nao foi possivel criar o veiculo.");
            return 1;
        }

        SendClientMessage(playerid, COLOR_ORANGE, "Veiculo criado.");
        return 1;
    }

    if (strcmp(command, "/dv", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "deletar-veiculo", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
        {
            return SendNoPermission(playerid);
        }

        if (!IsPlayerInAnyVehicle(playerid))
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce precisa estar em um veiculo.");
            return 1;
        }

        DestroyVehicle(GetPlayerVehicleID(playerid));
        SendClientMessage(playerid, COLOR_ORANGE, "Veiculo destruido.");
        return 1;
    }

    if (strcmp(command, "/savepos", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "savepos", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
        {
            return SendNoPermission(playerid);
        }

        if (!GetRemainingText(cmdtext, index, message, sizeof(message)))
        {
            format(message, sizeof(message), "sem_nome");
        }

        UpdatePlayerLiveData(playerid);
        SaveAccountData(playerid, 0);

        if (!SavePlayerPositionToFile(playerid, message))
        {
            SendClientMessage(playerid, COLOR_RED, "Nao foi possivel salvar em saved_positions.txt.");
            return 1;
        }

        SendClientMessage(playerid, COLOR_ORANGE, "Posicao salva na conta e em saved_positions.txt.");
        return 1;
    }

    if (strcmp(command, "/sethora", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "sethora", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_MANAGER))
        {
            return SendNoPermission(playerid);
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/sethora [0-23]");
        }

        value = strval(param);
        if (value < 0 || value > 23)
        {
            SendClientMessage(playerid, COLOR_RED, "Hora invalida. Use 0 a 23.");
            return 1;
        }

        SetWorldTime(value);
        format(message, sizeof(message), "Hora do mundo alterada para %02d:00.", value);
        SendClientMessageToAll(COLOR_ORANGE, message);
        return 1;
    }

    if (strcmp(command, "/setclima", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "setclima", "handled");
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_MANAGER))
        {
            return SendNoPermission(playerid);
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/setclima [id/random]");
        }

        if (strcmp(param, "random", true) == 0 || strcmp(param, "aleatorio", true) == 0)
        {
            Climate_Randomize(1);
            return 1;
        }

        if (!IsNumericString(param))
        {
            return SendUsage(playerid, "/setclima [id/random]");
        }
        value = strval(param);
        if (value < 0 || value > 255)
        {
            SendClientMessage(playerid, COLOR_RED, "Clima invalido. Use 0 a 255.");
            return 1;
        }

        Climate_SetManual(value, 1);
        return 1;
    }

    Dispatch_CommandTrace(playerid, command, "cadeia-admin", "saida", "miss");
    return 0;
}

stock Dispatch_CommandTrace(playerid, command[], routeText[], moduleText[], resultText[])
{
    new line[192];

    if (!gCommandDebugMode || command[0] == 0)
    {
        return 0;
    }

    format(line, sizeof(line), "rota=%s modulo=%s comando=%s resultado=%s", routeText, moduleText, command, resultText);
    WritePlayerLog(LOG_ADMIN_FILE, "COMMAND_TRACE", playerid, line);
    return 1;
}

stock CommandAI_SendOwnerAlert(message[])
{
    new targetid;
    new maxPlayers = GetMaxPlayers();

    for (targetid = 0; targetid < maxPlayers; targetid++)
    {
        if (IsPlayerConnected(targetid) && PlayerInfo[targetid][pLogged] && HasAdminLevel(targetid, ADMIN_LEVEL_OWNER))
        {
            SendClientMessage(targetid, COLOR_ADMIN, message);
        }
    }
    return 1;
}

stock CommandAI_WasNotFoundAlerted(command[])
{
    for (new slot = 0; slot < gCommandNotFoundAlertCount; slot++)
    {
        if (strcmp(gCommandNotFoundAlerted[slot], command, true) == 0)
        {
            return 1;
        }
    }
    return 0;
}

stock CommandAI_AlertNewNotFound(playerid, command[])
{
    new message[144];
    new name[MAX_PLAYER_NAME + 1];

    if (command[0] != '/' || CommandAI_WasNotFoundAlerted(command))
    {
        return 0;
    }
    if (gCommandNotFoundAlertCount >= COMMAND_NOTFOUND_ALERT_MAX)
    {
        return 0;
    }

    format(gCommandNotFoundAlerted[gCommandNotFoundAlertCount], 32, "%s", command);
    gCommandNotFoundAlertCount++;
    GetPlayerNameEx(playerid, name, sizeof(name));
    format(message, sizeof(message), "[POS-DEPLOY] NOT_FOUND novo: %s por %s ID %d. Use /notfounds aplicar.", command, name, playerid);
    CommandAI_SendOwnerAlert(message);
    WritePlayerLog(LOG_ADMIN_FILE, "NOT_FOUND_NEW", playerid, command);
    return 1;
}

stock CommandAI_Record(playerid, command[], moduleText[], resultText[], severity, details[])
{
    new line[192];
    new alert[144];
    new name[MAX_PLAYER_NAME + 1];
    new status[12];
    new tick;

    if (command[0] == 0)
    {
        return 0;
    }

    format(line, sizeof(line), "cmd=%s modulo=%s resultado=%s severidade=%d detalhe=%s", command, moduleText, resultText, severity, details);
    WritePlayerLog(LOG_COMMAND_AI_FILE, "COMMAND_AI", playerid, line);
    if (strcmp(resultText, "NOT_FOUND", true) == 0)
    {
        CommandAI_AlertNewNotFound(playerid, command);
    }

    if (severity <= 0)
    {
        return 1;
    }

    tick = GetTickCount();
    if (tick - gCommandAiAlertTick[playerid] < 3000)
    {
        return 1;
    }
    gCommandAiAlertTick[playerid] = tick;

    GetPlayerNameEx(playerid, name, sizeof(name));
    format(status, sizeof(status), "%s", severity >= 2 ? ("FALHA") : ("AVISO"));
    format(alert, sizeof(alert), "[IA-CMD] %s: %s ID %d usou %s em %s: %s.", status, name, playerid, command, moduleText, resultText);
    CommandAI_SendOwnerAlert(alert);
    return 1;
}

stock CommandAI_RecordText(playerid, cmdtext[], moduleText[], resultText[], severity, details[])
{
    new command[32];

    GetCommandName(cmdtext, command, sizeof(command));
    return CommandAI_Record(playerid, command, moduleText, resultText, severity, details);
}

stock Dispatch_CommandTraceText(playerid, cmdtext[], routeText[], moduleText[], resultText[])
{
    new command[32];

    GetCommandName(cmdtext, command, sizeof(command));
    return Dispatch_CommandTrace(playerid, command, routeText, moduleText, resultText);
}

stock Dispatch_ModuleFailure(playerid, cmdtext[], moduleText[])
{
    new command[32];
    new message[144];

    GetCommandName(cmdtext, command, sizeof(command));
    Dispatch_DebugTrace(playerid, command, "modulo mapeado falhou");
    Dispatch_CommandTrace(playerid, command, "resultado", moduleText, "failed");
    CommandAI_Record(playerid, command, moduleText, "HANDLER_RETURN_0", 2, "modulo_mapeado_nao_executou");
    Dispatch_AlertUnknownCommand(playerid, command);
    format(message, sizeof(message), "Comando %s chegou ao modulo %s, mas nao executou. Staff foi avisada; use /resetcomandos se persistir.", command, moduleText);
    SendClientMessage(playerid, COLOR_RED, message);
    return 1;
}

stock Dispatch_RunLifeCommand(playerid, cmdtext[])
{
    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "politica", "checking");
    if (Life_HandleCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "resultado", "politica", "handled");
        CommandAI_RecordText(playerid, cmdtext, "politica", "OK", 0, "modulo_respondeu");
        return 1;
    }

    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "politica", "miss");
    if (HandlePlayerCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "fallback", "player-chain", "handled");
        CommandAI_RecordText(playerid, cmdtext, "politica/player-chain", "OK", 0, "fallback_respondeu");
        return 1;
    }
    Dispatch_ModuleFailure(playerid, cmdtext, "politica");
    return 1;
}

stock Dispatch_RunPropertyCommand(playerid, cmdtext[])
{
    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "imovel/hotel", "checking");
    if (HandlePropertyCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "resultado", "imovel/hotel", "handled");
        CommandAI_RecordText(playerid, cmdtext, "imovel/hotel", "OK", 0, "modulo_respondeu");
        return 1;
    }

    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "imovel/hotel", "miss");
    if (HandlePlayerCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "fallback", "player-chain", "handled");
        CommandAI_RecordText(playerid, cmdtext, "imovel/hotel/player-chain", "OK", 0, "fallback_respondeu");
        return 1;
    }
    Dispatch_ModuleFailure(playerid, cmdtext, "imovel/hotel");
    return 1;
}

stock Dispatch_RunPhoneCommand(playerid, cmdtext[])
{
    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "celular", "checking");
    if (HandlePhoneCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "resultado", "celular", "handled");
        CommandAI_RecordText(playerid, cmdtext, "celular", "OK", 0, "modulo_respondeu");
        return 1;
    }

    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "celular", "miss");
    if (HandlePlayerCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "fallback", "player-chain", "handled");
        CommandAI_RecordText(playerid, cmdtext, "celular/player-chain", "OK", 0, "fallback_respondeu");
        return 1;
    }
    Dispatch_ModuleFailure(playerid, cmdtext, "celular");
    return 1;
}

stock Dispatch_RunBankCommand(playerid, cmdtext[])
{
    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "banco", "checking");
    if (HandleBankCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "resultado", "banco", "handled");
        CommandAI_RecordText(playerid, cmdtext, "banco", "OK", 0, "modulo_respondeu");
        return 1;
    }

    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "banco", "miss");
    if (HandlePlayerCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "fallback", "player-chain", "handled");
        CommandAI_RecordText(playerid, cmdtext, "banco/player-chain", "OK", 0, "fallback_respondeu");
        return 1;
    }
    Dispatch_ModuleFailure(playerid, cmdtext, "banco");
    return 1;
}

stock Dispatch_RunRadioCommand(playerid, cmdtext[])
{
    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "radio", "checking");
    if (Radio_HandleCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "resultado", "radio", "handled");
        CommandAI_RecordText(playerid, cmdtext, "radio", "OK", 0, "modulo_respondeu");
        return 1;
    }

    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "radio", "miss");
    if (HandlePlayerCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "fallback", "player-chain", "handled");
        CommandAI_RecordText(playerid, cmdtext, "radio/player-chain", "OK", 0, "fallback_respondeu");
        return 1;
    }
    Dispatch_ModuleFailure(playerid, cmdtext, "radio");
    return 1;
}

stock Dispatch_RunVehicleCommand(playerid, cmdtext[])
{
    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "veiculo", "checking");
    if (HandleDealershipCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "resultado", "veiculo", "handled");
        CommandAI_RecordText(playerid, cmdtext, "veiculo", "OK", 0, "modulo_respondeu");
        return 1;
    }

    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "veiculo", "miss");
    if (HandlePlayerCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "fallback", "player-chain", "handled");
        CommandAI_RecordText(playerid, cmdtext, "veiculo/player-chain", "OK", 0, "fallback_respondeu");
        return 1;
    }
    Dispatch_ModuleFailure(playerid, cmdtext, "veiculo");
    return 1;
}

stock Dispatch_RunTollCommand(playerid, cmdtext[])
{
    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "pedagio", "checking");
    if (Tolls_HandleCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "resultado", "pedagio", "handled");
        CommandAI_RecordText(playerid, cmdtext, "pedagio", "OK", 0, "modulo_respondeu");
        return 1;
    }

    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "pedagio", "miss");
    if (HandlePlayerCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "fallback", "player-chain", "handled");
        CommandAI_RecordText(playerid, cmdtext, "pedagio/player-chain", "OK", 0, "fallback_respondeu");
        return 1;
    }
    Dispatch_ModuleFailure(playerid, cmdtext, "pedagio");
    return 1;
}

stock Dispatch_RunJobCommand(playerid, cmdtext[])
{
    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "emprego", "checking");
    if (HandleJobCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "resultado", "emprego", "handled");
        CommandAI_RecordText(playerid, cmdtext, "emprego", "OK", 0, "modulo_respondeu");
        return 1;
    }

    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "emprego", "miss");
    if (HandlePlayerCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "fallback", "player-chain", "handled");
        CommandAI_RecordText(playerid, cmdtext, "emprego/player-chain", "OK", 0, "fallback_respondeu");
        return 1;
    }
    Dispatch_ModuleFailure(playerid, cmdtext, "emprego");
    return 1;
}

stock Dispatch_RunHospitalCommand(playerid, cmdtext[])
{
    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "saude", "checking");
    if (HandleHospitalCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "resultado", "saude", "handled");
        CommandAI_RecordText(playerid, cmdtext, "saude", "OK", 0, "modulo_respondeu");
        return 1;
    }

    Dispatch_CommandTraceText(playerid, cmdtext, "modulo", "saude", "miss");
    if (HandlePlayerCommands(playerid, cmdtext))
    {
        Dispatch_CommandTraceText(playerid, cmdtext, "fallback", "player-chain", "handled");
        CommandAI_RecordText(playerid, cmdtext, "saude/player-chain", "OK", 0, "fallback_respondeu");
        return 1;
    }
    Dispatch_ModuleFailure(playerid, cmdtext, "saude");
    return 1;
}

stock Dispatch_IsPoliticalCommand(command[])
{
    if (strcmp(command, "/politica", true) == 0) return 1;
    if (strcmp(command, "/painelpolitico", true) == 0 || strcmp(command, "/painelpolitica", true) == 0 || strcmp(command, "/governopainel", true) == 0) return 1;
    if (strcmp(command, "/propostaspoliticas", true) == 0 || strcmp(command, "/pref", true) == 0 || strcmp(command, "/meucargo", true) == 0) return 1;
    if (strcmp(command, "/cargopolitico", true) == 0 || strcmp(command, "/mandato", true) == 0 || strcmp(command, "/governo", true) == 0 || strcmp(command, "/governar", true) == 0) return 1;
    if (strcmp(command, "/propostapolitica", true) == 0 || strcmp(command, "/criarproposta", true) == 0) return 1;
    if (strcmp(command, "/votarproposta", true) == 0 || strcmp(command, "/aprovarproposta", true) == 0) return 1;
    if (strcmp(command, "/cancelarproposta", true) == 0 || strcmp(command, "/reprovarproposta", true) == 0) return 1;
    if (strcmp(command, "/candidatar", true) == 0 || strcmp(command, "/candidatura", true) == 0) return 1;
    if (strcmp(command, "/votar", true) == 0 || strcmp(command, "/votareleicao", true) == 0 || strcmp(command, "/votacao", true) == 0) return 1;
    if (strcmp(command, "/apurareleicao", true) == 0 || strcmp(command, "/fechareleicao", true) == 0) return 1;
    if (strcmp(command, "/admeleicao", true) == 0 || strcmp(command, "/gerireleicao", true) == 0) return 1;
    if (strcmp(command, "/abrireleicao", true) == 0 || strcmp(command, "/fechareleicaoadm", true) == 0 || strcmp(command, "/apurareleicaoadm", true) == 0) return 1;
    if (strcmp(command, "/limparpolitica", true) == 0 || strcmp(command, "/limparcargospoliticos", true) == 0) return 1;
    if (strcmp(command, "/prioridade", true) == 0 || strcmp(command, "/prioridadeorcamento", true) == 0) return 1;
    return 0;
}

stock Dispatch_IsCrimeCommand(command[])
{
    if (strcmp(command, "/apreendercrime", true) == 0) return 1;
    if (strcmp(command, "/comprarsementeilegal", true) == 0) return 1;
    if (strcmp(command, "/crimeinfo", true) == 0) return 1;
    if (strcmp(command, "/crimemissoes", true) == 0) return 1;
    if (strcmp(command, "/ocupacoesilegais", true) == 0) return 1;
    if (strcmp(command, "/ocupacoescrime", true) == 0) return 1;
    if (strcmp(command, "/crimeocupacoes", true) == 0) return 1;
    if (strcmp(command, "/crimepontos", true) == 0) return 1;
    if (strcmp(command, "/denunciarcrime", true) == 0) return 1;
    if (strcmp(command, "/faccoes", true) == 0) return 1;
    if (strcmp(command, "/entrarfaccao", true) == 0) return 1;
    if (strcmp(command, "/sairfaccao", true) == 0) return 1;
    if (strcmp(command, "/faccaostatus", true) == 0) return 1;
    if (strcmp(command, "/lavardinheiro", true) == 0) return 1;
    if (strcmp(command, "/plantar", true) == 0) return 1;
    if (strcmp(command, "/colher", true) == 0) return 1;
    if (strcmp(command, "/produzir", true) == 0) return 1;
    if (strcmp(command, "/venderprodutoilegal", true) == 0) return 1;
    if (strcmp(command, "/roubaratm", true) == 0) return 1;
    if (strcmp(command, "/roubarbanco", true) == 0) return 1;
    if (strcmp(command, "/roubarcarga", true) == 0) return 1;
    if (strcmp(command, "/roubarloja", true) == 0) return 1;
    if (strcmp(command, "/roubarveiculo", true) == 0) return 1;
    if (strcmp(command, "/atacarunidade", true) == 0) return 1;
    return 0;
}

stock Dispatch_IsPoliceCommand(command[])
{
    if (strcmp(command, "/centralpolicia", true) == 0) return 1;
    if (strcmp(command, "/centralprf", true) == 0) return 1;
    if (strcmp(command, "/abordagem", true) == 0) return 1;
    if (strcmp(command, "/abordar", true) == 0) return 1;
    if (strcmp(command, "/revistar", true) == 0) return 1;
    if (strcmp(command, "/revista", true) == 0) return 1;
    if (strcmp(command, "/ficha", true) == 0) return 1;
    if (strcmp(command, "/procurados", true) == 0) return 1;
    if (strcmp(command, "/wanted", true) == 0) return 1;
    if (strcmp(command, "/procurar", true) == 0) return 1;
    if (strcmp(command, "/limparficha", true) == 0) return 1;
    if (strcmp(command, "/crimes", true) == 0) return 1;
    if (strcmp(command, "/codigopenal", true) == 0) return 1;
    if (strcmp(command, "/leispenais", true) == 0) return 1;
    if (strcmp(command, "/algemar", true) == 0) return 1;
    if (strcmp(command, "/desalgemar", true) == 0) return 1;
    if (strcmp(command, "/prender", true) == 0) return 1;
    if (strcmp(command, "/soltar", true) == 0) return 1;
    if (strcmp(command, "/fianca", true) == 0) return 1;
    if (strcmp(command, "/blitz", true) == 0) return 1;
    if (strcmp(command, "/criarblitz", true) == 0) return 1;
    if (strcmp(command, "/montarblitz", true) == 0) return 1;
    if (strcmp(command, "/barreira", true) == 0) return 1;
    if (strcmp(command, "/criarbarreira", true) == 0) return 1;
    if (strcmp(command, "/removerblitz", true) == 0) return 1;
    if (strcmp(command, "/desmontarblitz", true) == 0) return 1;
    if (strcmp(command, "/limparblitz", true) == 0) return 1;
    if (strcmp(command, "/limparminhasblitz", true) == 0) return 1;
    if (strcmp(command, "/fiscalizar", true) == 0) return 1;
    if (strcmp(command, "/fiscalprf", true) == 0) return 1;
    if (strcmp(command, "/postofiscal", true) == 0) return 1;
    if (strcmp(command, "/postosfiscais", true) == 0) return 1;
    if (strcmp(command, "/barreiraprf", true) == 0) return 1;
    if (strcmp(command, "/criarbarreiraprf", true) == 0) return 1;
    if (strcmp(command, "/blitzprf", true) == 0) return 1;
    if (strcmp(command, "/montarprf", true) == 0) return 1;
    if (strcmp(command, "/consultarfiscal", true) == 0) return 1;
    if (strcmp(command, "/cargafiscal", true) == 0) return 1;
    if (strcmp(command, "/fiscalizarcarga", true) == 0) return 1;
    if (strcmp(command, "/multacarga", true) == 0) return 1;
    if (strcmp(command, "/apreenderfiscal", true) == 0) return 1;
    if (strcmp(command, "/apreenderveiculo", true) == 0) return 1;
    if (strcmp(command, "/liberar", true) == 0) return 1;
    if (strcmp(command, "/liberarfiscal", true) == 0) return 1;
    if (strcmp(command, "/liberarveiculo", true) == 0) return 1;
    return 0;
}

stock Dispatch_DebugCommand(playerid, targetCommand[])
{
    new message[160];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }
    if (Dispatch_IsPoliticalCommand(targetCommand))
    {
        format(message, sizeof(message), "Debug comando: %s -> modulo politica/LifeServices -> rota prioritaria direta.", targetCommand);
        SendClientMessage(playerid, COLOR_GREEN, message);
        return 1;
    }
    if (strcmp(targetCommand, "/dormir", true) == 0 || strcmp(targetCommand, "/hotel", true) == 0 || strcmp(targetCommand, "/entrarcasa", true) == 0)
    {
        format(message, sizeof(message), "Debug comando: %s -> modulo imoveis/hoteis -> rota prioritaria.", targetCommand);
        SendClientMessage(playerid, COLOR_GREEN, message);
        return 1;
    }
    if (strcmp(targetCommand, "/celular", true) == 0 || strcmp(targetCommand, "/app", true) == 0)
    {
        format(message, sizeof(message), "Debug comando: %s -> modulo celular -> rota prioritaria.", targetCommand);
        SendClientMessage(playerid, COLOR_GREEN, message);
        return 1;
    }
    if (strcmp(targetCommand, "/banco", true) == 0 || strcmp(targetCommand, "/pix", true) == 0 || strcmp(targetCommand, "/saldo", true) == 0)
    {
        format(message, sizeof(message), "Debug comando: %s -> modulo banco -> rota prioritaria.", targetCommand);
        SendClientMessage(playerid, COLOR_GREEN, message);
        return 1;
    }
    format(message, sizeof(message), "Debug comando: %s -> sem rota prioritaria; cai na cadeia geral de handlers.", targetCommand);
    SendClientMessage(playerid, COLOR_ORANGE, message);
    return 1;
}

stock Dispatch_IsBusinessCommand(command[])
{
    return (strcmp(command, "/empresa", true) == 0
        || strcmp(command, "/cnpj", true) == 0
        || strcmp(command, "/minhaempresa", true) == 0
        || strcmp(command, "/abrirempresalocal", true) == 0
        || strcmp(command, "/abrircnpjlocal", true) == 0
        || strcmp(command, "/enderecoempresa", true) == 0
        || strcmp(command, "/localempresa", true) == 0
        || strcmp(command, "/contratarempresa", true) == 0
        || strcmp(command, "/creditoempresa", true) == 0
        || strcmp(command, "/emprestimoempresa", true) == 0
        || strcmp(command, "/fiscalizarempresa", true) == 0
        || strcmp(command, "/fiscalizarcnpj", true) == 0
        || strcmp(command, "/regularizarempresa", true) == 0
        || strcmp(command, "/contabilidade", true) == 0);
}

stock Dispatch_GetCommandRoute(command[], output[], size = sizeof(output))
{
    if (Dispatch_IsPoliticalCommand(command))
    {
        format(output, size, "politica/LifeServices");
        return 1;
    }
    if (strcmp(command, "/prefeitura", true) == 0 || strcmp(command, "/painelprefeitura", true) == 0 || strcmp(command, "/orcamento", true) == 0 || strcmp(command, "/transparencia", true) == 0 || strcmp(command, "/cofrepublico", true) == 0)
    {
        format(output, size, "prefeitura/LifeServices");
        return 1;
    }
    if (Dispatch_IsBusinessCommand(command))
    {
        format(output, size, "empresa/LifeServices");
        return 1;
    }
    if (strcmp(command, "/boletos", true) == 0 || strcmp(command, "/boleto", true) == 0 || strcmp(command, "/contas", true) == 0 || strcmp(command, "/energia", true) == 0 || strcmp(command, "/instalarsolar", true) == 0)
    {
        format(output, size, "boletos/LifeServices");
        return 1;
    }
    if (strcmp(command, "/dormir", true) == 0 || strcmp(command, "/sono", true) == 0 || strcmp(command, "/entrarcasa", true) == 0 || strcmp(command, "/saircasa", true) == 0 || strcmp(command, "/entrarhotel", true) == 0 || strcmp(command, "/sairhotel", true) == 0)
    {
        format(output, size, "imoveis/hoteis");
        return 1;
    }
    if (strcmp(command, "/hoteis", true) == 0 || strcmp(command, "/hotel", true) == 0 || strcmp(command, "/gpshotel", true) == 0 || strcmp(command, "/imoveis", true) == 0 || strcmp(command, "/comprarcasa", true) == 0 || strcmp(command, "/alugarcasa", true) == 0)
    {
        format(output, size, "imoveis/hoteis");
        return 1;
    }
    if (strcmp(command, "/entrarlocal", true) == 0 || strcmp(command, "/entrarinterior", true) == 0 || strcmp(command, "/sairlocal", true) == 0 || strcmp(command, "/criarcasaedit", true) == 0 || strcmp(command, "/criarempresaedit", true) == 0 || strcmp(command, "/criarpostoedit", true) == 0)
    {
        format(output, size, "editor/imoveis");
        return 1;
    }
    if (strcmp(command, "/entrar", true) == 0 || strcmp(command, "/interagir", true) == 0 || strcmp(command, "/interact", true) == 0)
    {
        format(output, size, "interacao/mundo");
        return 1;
    }
    if (strcmp(command, "/editarmapa", true) == 0 || strcmp(command, "/editar", true) == 0 || strcmp(command, "/mapeditor", true) == 0 || strcmp(command, "/editmapa", true) == 0)
    {
        format(output, size, "editor/mapa");
        return 1;
    }
    if (strcmp(command, "/celular", true) == 0 || strcmp(command, "/phone", true) == 0 || strcmp(command, "/app", true) == 0)
    {
        format(output, size, "celular");
        return 1;
    }
    if (strcmp(command, "/190", true) == 0 || strcmp(command, "/192", true) == 0 || strcmp(command, "/193", true) == 0 || strcmp(command, "/abrirchamado", true) == 0 || strcmp(command, "/chamados", true) == 0 || strcmp(command, "/aceitarchamado", true) == 0 || strcmp(command, "/cancelarchamado", true) == 0)
    {
        format(output, size, "chamados/LifeServices");
        return 1;
    }
    if (strcmp(command, "/banco", true) == 0 || strcmp(command, "/saldo", true) == 0 || strcmp(command, "/extrato", true) == 0 || strcmp(command, "/pix", true) == 0 || strcmp(command, "/transferir", true) == 0 || strcmp(command, "/salario", true) == 0)
    {
        format(output, size, "banco");
        return 1;
    }
    if (strcmp(command, "/radio", true) == 0 || strcmp(command, "/radios", true) == 0 || strcmp(command, "/musica", true) == 0 || strcmp(command, "/pararradio", true) == 0 || strcmp(command, "/pararmusica", true) == 0 || strcmp(command, "/stopradio", true) == 0)
    {
        format(output, size, "radio");
        return 1;
    }
    if (strcmp(command, "/veiculo", true) == 0 || strcmp(command, "/veiculos", true) == 0 || strcmp(command, "/garagem", true) == 0 || strcmp(command, "/garagemcasa", true) == 0 || strcmp(command, "/detran", true) == 0 || strcmp(command, "/ipva", true) == 0)
    {
        format(output, size, "veiculos/DETRAN");
        return 1;
    }
    if (strcmp(command, "/motor", true) == 0 || strcmp(command, "/combustivel", true) == 0 || strcmp(command, "/recarregar", true) == 0 || strcmp(command, "/cambio", true) == 0 || strcmp(command, "/marcha", true) == 0)
    {
        format(output, size, "veiculos/DETRAN");
        return 1;
    }
    if (strcmp(command, "/pedagio", true) == 0 || strcmp(command, "/pedagios", true) == 0 || strcmp(command, "/irpedagio", true) == 0 || strcmp(command, "/criarpedagio", true) == 0 || strcmp(command, "/removerpedagio", true) == 0 || strcmp(command, "/ajustarpedagio", true) == 0)
    {
        format(output, size, "pedagios");
        return 1;
    }
    if (strcmp(command, "/emprego", true) == 0 || strcmp(command, "/profissoes", true) == 0 || strcmp(command, "/profissao", true) == 0 || strcmp(command, "/empregos", true) == 0 || strcmp(command, "/progresso", true) == 0 || strcmp(command, "/trabalhar", true) == 0 || strcmp(command, "/baterponto", true) == 0 || strcmp(command, "/plantao", true) == 0 || strcmp(command, "/bico", true) == 0 || strcmp(command, "/freela", true) == 0 || strcmp(command, "/cancelartrabalho", true) == 0)
    {
        format(output, size, "empregos");
        return 1;
    }
    if (strcmp(command, "/saude", true) == 0 || strcmp(command, "/ferimentos", true) == 0 || strcmp(command, "/plano", true) == 0 || strcmp(command, "/planosaude", true) == 0)
    {
        format(output, size, "hospital/saude");
        return 1;
    }
    if (strcmp(command, "/contratos", true) == 0 || strcmp(command, "/contrato", true) == 0 || strcmp(command, "/financiamento", true) == 0 || strcmp(command, "/finaciamento", true) == 0)
    {
        format(output, size, "contratos/LifeServices");
        return 1;
    }
    if (strcmp(command, "/obraspublicas", true) == 0 || strcmp(command, "/obras", true) == 0 || strcmp(command, "/financiarobra", true) == 0 || strcmp(command, "/financiamentoobra", true) == 0)
    {
        format(output, size, "obras/LifeServices");
        return 1;
    }
    if (strcmp(command, "/missaopublica", true) == 0 || strcmp(command, "/ocorrencia", true) == 0 || strcmp(command, "/fogo", true) == 0)
    {
        format(output, size, "missoes-publicas/LifeServices");
        return 1;
    }
    if (strcmp(command, "/multa", true) == 0 || strcmp(command, "/multas", true) == 0 || strcmp(command, "/ctb", true) == 0 || strcmp(command, "/multar", true) == 0)
    {
        format(output, size, "multas/empregos");
        return 1;
    }
    if (Dispatch_IsCrimeCommand(command))
    {
        format(output, size, "crime");
        return 1;
    }
    if (Dispatch_IsPoliceCommand(command))
    {
        format(output, size, "policia");
        return 1;
    }
    if (strcmp(command, "/ajuda", true) == 0 || strcmp(command, "/menu", true) == 0 || strcmp(command, "/admin", true) == 0 || strcmp(command, "/debugcomandos", true) == 0 || strcmp(command, "/iacomandos", true) == 0 || strcmp(command, "/notfounds", true) == 0)
    {
        format(output, size, "central/admin");
        return 1;
    }
    if (strcmp(command, "/notfoundshistorico", true) == 0 || strcmp(command, "/posdeploy", true) == 0 || strcmp(command, "/cmdfixpromover", true) == 0 || strcmp(command, "/cmdmodulos", true) == 0 || strcmp(command, "/balancegm", true) == 0)
    {
        format(output, size, "central/admin");
        return 1;
    }
    if (strcmp(command, "/resetcomandos", true) == 0 || strcmp(command, "/recarregarcomandos", true) == 0 || strcmp(command, "/testarcomandos", true) == 0 || strcmp(command, "/modoemergenciacmd", true) == 0)
    {
        format(output, size, "central/admin");
        return 1;
    }
    if (strcmp(command, "/integridade", true) == 0 || strcmp(command, "/saudegm", true) == 0 || strcmp(command, "/releasecheck", true) == 0 || strcmp(command, "/selftestgm", true) == 0 || strcmp(command, "/statusserver", true) == 0 || strcmp(command, "/versao", true) == 0)
    {
        format(output, size, "integridade/admin");
        return 1;
    }
    format(output, size, "cadeia geral");
    return 1;
}

stock Dispatch_AddCommandTestLine(list[], size, &okCount, &warnCount, command[], expected[])
{
    new route[48];
    new line[128];

    Dispatch_GetCommandRoute(command, route, sizeof(route));
    if (strcmp(route, "cadeia geral", true) == 0)
    {
        warnCount++;
        format(line, sizeof(line), "AVISO\t%s\t%s\t%s\n", command, expected, route);
    }
    else
    {
        okCount++;
        format(line, sizeof(line), "OK\t%s\t%s\t%s\n", command, expected, route);
    }
    strcat(list, line, size);
    return 1;
}

stock Dispatch_ShowCommandTest(playerid)
{
    new list[3072];
    new summary[128];
    new okCount;
    new warnCount;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    format(list, sizeof(list), "Status\tComando\tEsperado\tRota detectada\n");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/ajuda", "ajuda");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/versao", "versao");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/saudegm", "saude-gm");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/integridade", "integridade");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/selftestgm", "selftest");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/releasecheck", "release");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/statusserver", "status");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/politica", "politica");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/votar", "politica");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/admeleicao", "politica");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/prefeitura", "prefeitura");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/transparencia", "prefeitura");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/empresa", "empresa");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/minhaempresa", "empresa");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/creditoempresa", "empresa");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/fiscalizarempresa", "empresa");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/abrirempresalocal", "empresa");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/boleto", "boletos");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/energia", "boletos");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/190", "chamados");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/chamados", "chamados");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/celular", "celular");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/bairros", "LifeServices");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/progressourbano", "LifeServices");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/banco", "banco");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/radio", "radio");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/pix", "banco");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/dormir", "imoveis");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/imoveis", "imoveis");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/entrar", "interacao");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/entrarlocal", "editor");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/criarempresaedit", "editor");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/pedagio", "pedagios");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/criarpedagio", "pedagios");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/recarregar", "veiculos");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/cambio", "veiculos");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/emprego", "empregos");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/profissoes", "empregos");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/trabalhar", "empregos");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/bico", "empregos");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/saude", "saude");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/fogo", "missoes");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/finaciamento", "contratos");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/financiamento", "contratos");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/financiamentoobra", "obras");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/multa", "multas");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/faccoes", "crime");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/roubaratm", "crime");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/crimeinfo", "crime");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/apreendercrime", "crime");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/abordagem", "policia");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/revistar", "policia");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/ficha", "policia");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/prender", "policia");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/crimes", "policia");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/procurados", "policia");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/barreira", "policia");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/criarbarreira", "policia");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/blitzprf", "policia");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/menu", "central");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/admin", "admin");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/editar", "editor");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/iacomandos", "debug");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/notfounds", "debug");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/notfoundshistorico", "debug");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/posdeploy", "debug");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/cmdfixpromover", "debug");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/cmdmodulos", "debug");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/balancegm", "debug");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/centralpolicia", "policia");
    Dispatch_AddCommandTestLine(list, sizeof(list), okCount, warnCount, "/resetcomandos", "debug");

    format(summary, sizeof(summary), "Teste de comandos: %d OK | %d avisos. Nenhum comando real foi executado.", okCount, warnCount);
    SendClientMessage(playerid, warnCount ? COLOR_ORANGE : COLOR_GREEN, summary);
    WritePlayerLog(LOG_ADMIN_FILE, "COMMAND_TEST", playerid, summary);
    Dispatch_ResetCmdState(playerid);
    ShowPlayerDialog(playerid, DIALOG_GM_SELFTEST, DIALOG_STYLE_TABLIST_HEADERS, "Teste de comandos", list, "Fechar", "");
    return 1;
}

stock Dispatch_CountRouteHit(&count, command[], needle[])
{
    new route[48];

    Dispatch_GetCommandRoute(command, route, sizeof(route));
    if (strfind(route, needle, true) != -1)
    {
        count++;
    }
    return 1;
}

stock Dispatch_CountModuleCentral()
{
    new count;

    Dispatch_CountRouteHit(count, "/ajuda", "central/admin");
    Dispatch_CountRouteHit(count, "/menu", "central/admin");
    Dispatch_CountRouteHit(count, "/admin", "central/admin");
    Dispatch_CountRouteHit(count, "/notfounds", "central/admin");
    Dispatch_CountRouteHit(count, "/notfoundshistorico", "central/admin");
    Dispatch_CountRouteHit(count, "/posdeploy", "central/admin");
    Dispatch_CountRouteHit(count, "/cmdfixpromover", "central/admin");
    Dispatch_CountRouteHit(count, "/cmdmodulos", "central/admin");
    Dispatch_CountRouteHit(count, "/balancegm", "central/admin");
    Dispatch_CountRouteHit(count, "/testarcomandos", "central/admin");
    return count;
}

stock Dispatch_CountModulePolice()
{
    new count;

    Dispatch_CountRouteHit(count, "/centralpolicia", "policia");
    Dispatch_CountRouteHit(count, "/procurados", "policia");
    Dispatch_CountRouteHit(count, "/abordagem", "policia");
    Dispatch_CountRouteHit(count, "/revistar", "policia");
    Dispatch_CountRouteHit(count, "/ficha", "policia");
    Dispatch_CountRouteHit(count, "/prender", "policia");
    Dispatch_CountRouteHit(count, "/crimes", "policia");
    Dispatch_CountRouteHit(count, "/barreira", "policia");
    Dispatch_CountRouteHit(count, "/criarbarreira", "policia");
    Dispatch_CountRouteHit(count, "/blitzprf", "policia");
    Dispatch_CountRouteHit(count, "/multa", "multas");
    return count;
}

stock Dispatch_CountModuleLife()
{
    new count;

    Dispatch_CountRouteHit(count, "/prefeitura", "LifeServices");
    Dispatch_CountRouteHit(count, "/empresa", "LifeServices");
    Dispatch_CountRouteHit(count, "/minhaempresa", "LifeServices");
    Dispatch_CountRouteHit(count, "/creditoempresa", "LifeServices");
    Dispatch_CountRouteHit(count, "/fiscalizarempresa", "LifeServices");
    Dispatch_CountRouteHit(count, "/regularizarempresa", "LifeServices");
    Dispatch_CountRouteHit(count, "/boleto", "LifeServices");
    Dispatch_CountRouteHit(count, "/190", "LifeServices");
    Dispatch_CountRouteHit(count, "/missaopublica", "LifeServices");
    Dispatch_CountRouteHit(count, "/contratos", "LifeServices");
    Dispatch_CountRouteHit(count, "/financiamento", "LifeServices");
    Dispatch_CountRouteHit(count, "/obras", "LifeServices");
    Dispatch_CountRouteHit(count, "/financiamentoobra", "LifeServices");
    return count;
}

stock Dispatch_CountModuleJobs()
{
    new count;

    Dispatch_CountRouteHit(count, "/emprego", "empregos");
    Dispatch_CountRouteHit(count, "/profissoes", "empregos");
    Dispatch_CountRouteHit(count, "/trabalhar", "empregos");
    Dispatch_CountRouteHit(count, "/bico", "empregos");
    Dispatch_CountRouteHit(count, "/progresso", "empregos");
    Dispatch_CountRouteHit(count, "/plantao", "empregos");
    Dispatch_CountRouteHit(count, "/cancelartrabalho", "empregos");
    return count;
}

stock Dispatch_ShowCommandModules(playerid)
{
    new list[1600];
    new line[160];
    new central = Dispatch_CountModuleCentral();
    new police = Dispatch_CountModulePolice();
    new life = Dispatch_CountModuleLife();
    new jobs = Dispatch_CountModuleJobs();

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    format(list, sizeof(list), "Modulo\tComandos auditados\tObservacao\n");
    format(line, sizeof(line), "admin/central\t%d\tdeploy, NOT_FOUND e diagnosticos\n", central);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "policia/PRF\t%d\tabordagem, BO, blitz, procurados\n", police);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "vida/economia\t%d\tprefeitura, boletos, contratos, chamados\n", life);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "empregos\t%d\texpediente, progresso e rotas\n", jobs);
    strcat(list, line, sizeof(list));
    strcat(list, "crime\t3\t/faccoes /roubaratm /crimeinfo auditados no self-test\n", sizeof(list));
    strcat(list, "banco\t3\t/banco /pix /saldo auditados no self-test\n", sizeof(list));
    strcat(list, "veiculos\t4\t/detran /recarregar /cambio /pedagio no router\n", sizeof(list));
    strcat(list, "help x handler\tativo\tUse /testarcomandos e build_deploy_check.ps1\n", sizeof(list));

    WritePlayerLog(LOG_ADMIN_FILE, "COMMAND_MODULES_VIEW", playerid, "consultou /cmdmodulos");
    ShowPlayerDialog(playerid, DIALOG_COMMAND_MODULES, DIALOG_STYLE_TABLIST_HEADERS, "Auditoria de comandos por modulo", list, "Fechar", "");
    return 1;
}

#define BALANCE_GM_TOP_JOBS          (4)
#define BALANCE_GM_FARM_SHARE_WARN   (45)
#define BALANCE_GM_FARM_MIN_HITS     (3)

stock BalanceGm_DateSerial(year, month, day)
{
    return (year * 372) + (month * 31) + day;
}

stock BalanceGm_CurrentSerial()
{
    new year;
    new month;
    new day;
    new hour;
    new minute;
    new second;

    GetBrasiliaDateTime(year, month, day, hour, minute, second);
    return BalanceGm_DateSerial(year, month, day);
}

stock BalanceGm_LineSerial(line[])
{
    new text[8];
    new year;
    new month;
    new day;

    if (strlen(line) < 10)
    {
        return 0;
    }
    strmid(text, line, 0, 4, sizeof(text));
    year = strval(text);
    strmid(text, line, 5, 7, sizeof(text));
    month = strval(text);
    strmid(text, line, 8, 10, sizeof(text));
    day = strval(text);
    if (year < 2020 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        return 0;
    }
    return BalanceGm_DateSerial(year, month, day);
}

stock BalanceGm_PeriodDays(period[])
{
    if (strcmp(period, "hoje", true) == 0 || strcmp(period, "today", true) == 0)
    {
        return 1;
    }
    if (strcmp(period, "7d", true) == 0 || strcmp(period, "semana", true) == 0)
    {
        return 7;
    }
    if (strcmp(period, "30d", true) == 0 || strcmp(period, "mes", true) == 0)
    {
        return 30;
    }
    if (strcmp(period, "tudo", true) == 0 || strcmp(period, "all", true) == 0)
    {
        return 0;
    }
    return 7;
}

stock BalanceGm_FormatPeriod(period[], output[], size = sizeof(output))
{
    new days = BalanceGm_PeriodDays(period);

    if (days == 1)
    {
        format(output, size, "hoje");
    }
    else if (days == 7)
    {
        format(output, size, "7 dias");
    }
    else if (days == 30)
    {
        format(output, size, "30 dias");
    }
    else
    {
        format(output, size, "todo log");
    }
    return 1;
}

stock BalanceGm_LineInPeriod(line[], period[])
{
    new days = BalanceGm_PeriodDays(period);
    new currentSerial;
    new lineSerial;
    new age;

    if (days <= 0)
    {
        return 1;
    }

    currentSerial = BalanceGm_CurrentSerial();
    lineSerial = BalanceGm_LineSerial(line);
    if (!lineSerial)
    {
        return 0;
    }
    age = currentSerial - lineSerial;
    return (age >= 0 && age < days);
}

stock BalanceGm_ExtractInt(line[], token[])
{
    new start = strfind(line, token, true);
    new end;
    new value[24];
    new length = strlen(line);

    if (start == -1)
    {
        return 0;
    }
    start += strlen(token);
    end = start;
    if (end < length && line[end] == '-')
    {
        end++;
    }
    while (end < length && line[end] >= '0' && line[end] <= '9')
    {
        end++;
    }
    if (end <= start)
    {
        return 0;
    }
    strmid(value, line, start, end, sizeof(value));
    return strval(value);
}

stock BalanceGm_AddTopJob(list[], size, rank, jobid, cash, hits)
{
    new line[160];
    new balanceJobName[48];

    if (jobid <= JOB_NONE || jobid > JOB_MAX_ID || hits <= 0)
    {
        return 0;
    }
    GetJobName(jobid, balanceJobName, sizeof(balanceJobName));
    format(line, sizeof(line), "Top emprego #%d\t%s\t$%d | %d lancamento(s)\n", rank, balanceJobName, cash, hits);
    strcat(list, line, size);
    return 1;
}

stock BalanceGm_AppendTopJobs(list[], size, jobCash[], jobHits[])
{
    new used[JOB_MAX_ID + 1];
    new rank;
    new jobid;
    new bestJob;
    new bestCash;

    for (rank = 1; rank <= BALANCE_GM_TOP_JOBS; rank++)
    {
        bestJob = JOB_NONE;
        bestCash = 0;
        for (jobid = 1; jobid <= JOB_MAX_ID; jobid++)
        {
            if (used[jobid] || jobHits[jobid] <= 0)
            {
                continue;
            }
            if (bestJob == JOB_NONE || jobCash[jobid] > bestCash)
            {
                bestJob = jobid;
                bestCash = jobCash[jobid];
            }
        }
        if (bestJob == JOB_NONE)
        {
            if (rank == 1)
            {
                strcat(list, "Top emprego\tsem dados\tNenhum JOB_REWARD no periodo\n", size);
            }
            return 1;
        }
        used[bestJob] = 1;
        BalanceGm_AddTopJob(list, size, rank, bestJob, jobCash[bestJob], jobHits[bestJob]);
    }
    return 1;
}

stock BalanceGm_FindFarmRisk(jobCash[], jobHits[], totalCash, &riskJob, &riskPercent, &riskCash, &riskHits)
{
    new jobid;
    new percent;

    riskJob = JOB_NONE;
    riskPercent = 0;
    riskCash = 0;
    riskHits = 0;
    if (totalCash <= 0)
    {
        return 0;
    }

    for (jobid = 1; jobid <= JOB_MAX_ID; jobid++)
    {
        if (jobHits[jobid] < BALANCE_GM_FARM_MIN_HITS || jobCash[jobid] <= 0)
        {
            continue;
        }
        percent = (jobCash[jobid] * 100) / totalCash;
        if (percent > riskPercent)
        {
            riskJob = jobid;
            riskPercent = percent;
            riskCash = jobCash[jobid];
            riskHits = jobHits[jobid];
        }
    }
    return (riskJob != JOB_NONE && riskPercent >= BALANCE_GM_FARM_SHARE_WARN);
}

stock BalanceGm_ScanMoneyLog(period[], &cashIn, &cashOut, &jobCash, &jobXp, &jobHits, &govIn, &govOut, jobCashById[], jobHitsById[])
{
    new File:file;
    new line[256];
    new matched;
    new delta;
    new jobid;
    new amount;

    cashIn = 0;
    cashOut = 0;
    jobCash = 0;
    jobXp = 0;
    jobHits = 0;
    govIn = 0;
    govOut = 0;
    for (jobid = 0; jobid <= JOB_MAX_ID; jobid++)
    {
        jobCashById[jobid] = 0;
        jobHitsById[jobid] = 0;
    }

    if (!fexist(LOG_MONEY_FILE))
    {
        return 0;
    }

    file = fopen(LOG_MONEY_FILE, io_read);
    if (!file)
    {
        return 0;
    }
    while (fread(file, line, sizeof(line)))
    {
        if (!BalanceGm_LineInPeriod(line, period))
        {
            continue;
        }
        matched++;
        if (strfind(line, "|CASH|", true) != -1)
        {
            delta = BalanceGm_ExtractInt(line, "delta=");
            if (delta > 0)
            {
                cashIn += delta;
            }
            else if (delta < 0)
            {
                cashOut -= delta;
            }
        }
        if (strfind(line, "|JOB_REWARD|", true) != -1)
        {
            amount = BalanceGm_ExtractInt(line, "cash=");
            jobid = BalanceGm_ExtractInt(line, "job=");
            jobCash += amount;
            jobXp += BalanceGm_ExtractInt(line, "xp=");
            jobHits++;
            if (jobid > JOB_NONE && jobid <= JOB_MAX_ID)
            {
                jobCashById[jobid] += amount;
                jobHitsById[jobid]++;
            }
        }
        if (strfind(line, "|GOV_REVENUE|", true) != -1)
        {
            govIn += BalanceGm_ExtractInt(line, "amount=");
        }
        if (strfind(line, "|GOV_EXPENSE|", true) != -1)
        {
            govOut += BalanceGm_ExtractInt(line, "amount=");
        }
    }
    fclose(file);
    return matched;
}

stock Dispatch_ShowBalanceGm(playerid, period[] = "7d")
{
    new list[2600];
    new line[192];
    new serviceOpen = Life_ServiceCall_Count(LIFE_CALL_STATUS_PENDING);
    new serviceTaken = Life_ServiceCall_Count(LIFE_CALL_STATUS_ACCEPTED);
    new periodLabel[24];
    new cashIn;
    new cashOut;
    new jobCash;
    new jobXp;
    new jobHits;
    new govIn;
    new govOut;
    new matched;
    new jobCashById[JOB_MAX_ID + 1];
    new jobHitsById[JOB_MAX_ID + 1];
    new riskJob;
    new riskPercent;
    new riskCash;
    new riskHits;
    new riskName[48];
    new hasFarmRisk;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    BalanceGm_FormatPeriod(period, periodLabel, sizeof(periodLabel));
    matched = BalanceGm_ScanMoneyLog(period, cashIn, cashOut, jobCash, jobXp, jobHits, govIn, govOut, jobCashById, jobHitsById);
    hasFarmRisk = BalanceGm_FindFarmRisk(jobCashById, jobHitsById, jobCash, riskJob, riskPercent, riskCash, riskHits);

    format(list, sizeof(list), "Area\tIndicador\tValor\n");
    format(line, sizeof(line), "Periodo\tjanela\t%s | %d linha(s) lida(s)\n", periodLabel, matched);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Economia\tprecos globais\t%d%% | dinheiro inicial $%d\n", gCfgPricePercent, gCfgStartingMoney);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Inflacao log\tCASH entrada/saida\t$%d | $%d\n", cashIn, cashOut);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Empregos log\tJOB_REWARD\t$%d | XP %d | %d lancamento(s)\n", jobCash, jobXp, jobHits);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Cofre log\treceita/despesa\t$%d | $%d\n", govIn, govOut);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Prefeitura\tcofre/gastos\t$%d | $%d\n", gGovernmentRevenue, gGovernmentExpense);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Combustivel\tgas/alc/diesel/GLP\t$%d/$%d/$%d/$%d\n", gCfgFuelGasolinePrice, gCfgFuelEthanolPrice, gCfgFuelDieselPrice, gCfgFuelGlpPrice);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Multas CTB\tleve/media/grave/grav\t$%d/$%d/$%d/$%d\n", gCfgTrafficFineLight, gCfgTrafficFineMedium, gCfgTrafficFineSerious, gCfgTrafficFineVerySerious);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Veiculos\tIPVA/radares/frota\t%d%% | %d | %d\n", gCfgVehicleIpvaPercent, gRadarCount, Work_CountConfigVehicles());
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Servicos\tchamados\t%d aberto(s) | %d aceito(s)\n", serviceOpen, serviceTaken);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Saude/empresa\tplano/abrir empresa\t$%d | $%d\n", Cfg_Price(gCfgHospitalPlanCost), Cfg_Price(gCfgBusinessOpenCost));
    strcat(list, line, sizeof(list));
    if (hasFarmRisk)
    {
        GetJobName(riskJob, riskName, sizeof(riskName));
        format(line, sizeof(line), "ALERTA farm\t%s\t%d%% do JOB_REWARD | $%d | %d lancamento(s)\n", riskName, riskPercent, riskCash, riskHits);
        strcat(list, line, sizeof(list));
    }
    else
    {
        format(line, sizeof(line), "Alerta farm\tOK\tlimite %d%% | minimo %d lancamento(s)\n", BALANCE_GM_FARM_SHARE_WARN, BALANCE_GM_FARM_MIN_HITS);
        strcat(list, line, sizeof(list));
    }
    BalanceGm_AppendTopJobs(list, sizeof(list), jobCashById, jobHitsById);
    strcat(list, "Uso\tperiodos\t/balancegm hoje | 7d | 30d | tudo\n", sizeof(list));
    strcat(list, "Leitura\tajuste\tMexa em recompensa so depois de comparar top empregos\n", sizeof(list));

    format(line, sizeof(line), "period=%s cash_in=%d cash_out=%d job_cash=%d job_hits=%d", periodLabel, cashIn, cashOut, jobCash, jobHits);
    WritePlayerLog(LOG_ADMIN_FILE, "BALANCE_GM_VIEW", playerid, line);
    if (hasFarmRisk)
    {
        format(line, sizeof(line), "period=%s job=%d percent=%d cash=%d hits=%d total_job_cash=%d", periodLabel, riskJob, riskPercent, riskCash, riskHits, jobCash);
        WritePlayerLog(LOG_ADMIN_FILE, "BALANCE_GM_FARM_ALERT", playerid, line);
    }
    ShowPlayerDialog(playerid, DIALOG_BALANCE_GM, DIALOG_STYLE_TABLIST_HEADERS, "Painel de balanceamento", list, "Fechar", "");
    return 1;
}

#define DISPATCH_NOTFOUND_MAX       (16)
#define DISPATCH_NOTFOUND_CMD_SIZE  (32)
#define DISPATCH_NOTFOUND_DONE_MAX  (64)

new gPlayerNotFoundApplyCount[MAX_PLAYERS];
new gPlayerNotFoundApplyCommands[MAX_PLAYERS][DISPATCH_NOTFOUND_MAX][DISPATCH_NOTFOUND_CMD_SIZE];
new gPlayerNotFoundApplySelected[MAX_PLAYERS][DISPATCH_NOTFOUND_CMD_SIZE];
new gPlayerNotFoundApplySuggest[MAX_PLAYERS][COMMAND_HOTFIX_TARGET_SIZE];
new gNfResolvedBootCount;
new gNfResolvedBootCommands[DISPATCH_NOTFOUND_DONE_MAX][DISPATCH_NOTFOUND_CMD_SIZE];

stock Dispatch_FindLastBootMarker(output[], size = sizeof(output))
{
    new File:file;
    new line[256];
    new found;

    output[0] = 0;
    if (!fexist(LOG_ADMIN_FILE))
    {
        return 0;
    }

    file = fopen(LOG_ADMIN_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (strfind(line, "|COMMAND_HOTFIX_INIT|", false) == -1)
        {
            continue;
        }
        strmid(output, line, 0, 19, size);
        found = 1;
    }

    fclose(file);
    return found;
}

stock Dispatch_ExtractNotFoundCommand(line[], output[], size = sizeof(output))
{
    new start = strfind(line, " cmd=/", false);
    new end;

    output[0] = 0;
    if (start == -1)
    {
        return 0;
    }

    start += 5;
    end = start;
    while (line[end] != 0 && line[end] != ' ' && line[end] != '|')
    {
        end++;
    }

    if (end <= start)
    {
        return 0;
    }

    strmid(output, line, start, end, size);
    return 1;
}

stock Dispatch_IsNfResolvedBoot(command[])
{
    for (new slot = 0; slot < gNfResolvedBootCount; slot++)
    {
        if (strcmp(gNfResolvedBootCommands[slot], command, true) == 0)
        {
            return 1;
        }
    }
    return 0;
}

stock Dispatch_MarkNfResolvedBoot(command[])
{
    if (command[0] != '/')
    {
        return 0;
    }
    if (Dispatch_IsNfResolvedBoot(command))
    {
        return 1;
    }
    if (gNfResolvedBootCount >= DISPATCH_NOTFOUND_DONE_MAX)
    {
        return 0;
    }

    format(gNfResolvedBootCommands[gNfResolvedBootCount], DISPATCH_NOTFOUND_CMD_SIZE, "%s", command);
    gNfResolvedBootCount++;
    return 1;
}

stock Dispatch_AddUniqueNfCommand(commands[][DISPATCH_NOTFOUND_CMD_SIZE], &count, maxCount, command[])
{
    for (new slot = 0; slot < count; slot++)
    {
        if (strcmp(commands[slot], command, true) == 0)
        {
            return 0;
        }
    }
    if (count >= maxCount)
    {
        return 0;
    }

    format(commands[count], DISPATCH_NOTFOUND_CMD_SIZE, "%s", command);
    count++;
    return 1;
}

stock Dispatch_LogNfSummary(playerid, pending, resolvedBoot, hotfixCovered, overflow, markerFound, bootTime[], status[])
{
    new detail[176];

    if (markerFound)
    {
        format(detail, sizeof(detail), "pendentes=%d resolvidos_boot=%d hotfix=%d overflow=%d boot=%s status=%s", pending, resolvedBoot, hotfixCovered, overflow, bootTime, status);
    }
    else
    {
        format(detail, sizeof(detail), "pendentes=%d resolvidos_boot=%d hotfix=%d overflow=%d boot=sem_marcador status=%s", pending, resolvedBoot, hotfixCovered, overflow, status);
    }
    WritePlayerLog(LOG_ADMIN_FILE, "NOT_FOUND_REPORT", playerid, detail);
    return 1;
}

stock Dispatch_ShowNotFoundReport(playerid)
{
    new File:file;
    new line[256];
    new bootTime[24];
    new lineTime[24];
    new command[DISPATCH_NOTFOUND_CMD_SIZE];
    new firstSeen[DISPATCH_NOTFOUND_MAX][24];
    new lastSeen[DISPATCH_NOTFOUND_MAX][24];
    new counts[DISPATCH_NOTFOUND_MAX];
    new resolvedBoot[DISPATCH_NOTFOUND_DONE_MAX][DISPATCH_NOTFOUND_CMD_SIZE];
    new hotfixCovered[DISPATCH_NOTFOUND_DONE_MAX][DISPATCH_NOTFOUND_CMD_SIZE];
    new resolvedBootCount;
    new hotfixCoveredCount;
    new total;
    new overflow;
    new slot;
    new foundSlot;
    new report[4096];
    new row[192];
    new markerFound;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    gPlayerNotFoundApplyCount[playerid] = 0;
    gPlayerNotFoundApplySelected[playerid][0] = 0;
    markerFound = Dispatch_FindLastBootMarker(bootTime, sizeof(bootTime));
    if (!fexist(LOG_COMMAND_AI_FILE))
    {
        Dispatch_LogNfSummary(playerid, 0, 0, 0, 0, markerFound, bootTime, "sem_log");
        SendClientMessage(playerid, COLOR_ORANGE, "Log de IA de comandos ainda nao existe.");
        return 1;
    }

    file = fopen(LOG_COMMAND_AI_FILE, io_read);
    if (!file)
    {
        Dispatch_LogNfSummary(playerid, 0, 0, 0, 0, markerFound, bootTime, "erro_abrir_log");
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel abrir log_command_ai.txt.");
        return 1;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (strfind(line, "resultado=NOT_FOUND", false) == -1)
        {
            continue;
        }

        strmid(lineTime, line, 0, 19, sizeof(lineTime));
        if (markerFound && strcmp(lineTime, bootTime, false) < 0)
        {
            continue;
        }

        if (!Dispatch_ExtractNotFoundCommand(line, command, sizeof(command)))
        {
            continue;
        }
        if (Dispatch_IsNfResolvedBoot(command))
        {
            Dispatch_AddUniqueNfCommand(resolvedBoot, resolvedBootCount, DISPATCH_NOTFOUND_DONE_MAX, command);
            continue;
        }
        if (Dispatch_FindCommandHotfix(command) != -1)
        {
            Dispatch_AddUniqueNfCommand(hotfixCovered, hotfixCoveredCount, DISPATCH_NOTFOUND_DONE_MAX, command);
            continue;
        }

        foundSlot = -1;
        for (slot = 0; slot < total; slot++)
        {
            if (strcmp(gPlayerNotFoundApplyCommands[playerid][slot], command, true) == 0)
            {
                foundSlot = slot;
                break;
            }
        }

        if (foundSlot == -1)
        {
            if (total >= DISPATCH_NOTFOUND_MAX)
            {
                overflow++;
                continue;
            }
            foundSlot = total;
            format(gPlayerNotFoundApplyCommands[playerid][foundSlot], DISPATCH_NOTFOUND_CMD_SIZE, "%s", command);
            format(firstSeen[foundSlot], 24, "%s", lineTime);
            counts[foundSlot] = 0;
            total++;
            gPlayerNotFoundApplyCount[playerid] = total;
        }

        counts[foundSlot]++;
        format(lastSeen[foundSlot], 24, "%s", lineTime);
    }

    fclose(file);

    if (total == 0)
    {
        if (markerFound)
        {
            format(report, sizeof(report), "Nenhum NOT_FOUND pendente desde o ultimo boot.\n\nPendentes: 0\nResolvidos neste boot: %d\nJa cobertos por hotfix: %d\n\nMarcador: %s\nArquivo: %s", resolvedBootCount, hotfixCoveredCount, bootTime, LOG_COMMAND_AI_FILE);
        }
        else
        {
            format(report, sizeof(report), "Nenhum NOT_FOUND pendente encontrado.\n\nPendentes: 0\nResolvidos neste boot: %d\nJa cobertos por hotfix: %d\n\nMarcador de boot nao encontrado em %s.", resolvedBootCount, hotfixCoveredCount, LOG_ADMIN_FILE);
        }
        Dispatch_LogNfSummary(playerid, 0, resolvedBootCount, hotfixCoveredCount, overflow, markerFound, bootTime, "ok");
        ShowPlayerDialog(playerid, DIALOG_COMMAND_NOTFOUNDS, DIALOG_STYLE_MSGBOX, "NOT_FOUND recentes", report, "Fechar", "");
        return 1;
    }

    format(report, sizeof(report), "Item\tQtd\tDetalhe\n");
    format(row, sizeof(row), "Pendentes\t%d\tprecisam de alias\n", total);
    strcat(report, row, sizeof(report));
    format(row, sizeof(row), "Resolvidos neste boot\t%d\taplicados e ocultos do log bruto\n", resolvedBootCount);
    strcat(report, row, sizeof(report));
    format(row, sizeof(row), "Ja cobertos por hotfix\t%d\tcarregados em command_hotfixes.txt\n", hotfixCoveredCount);
    strcat(report, row, sizeof(report));
    for (slot = 0; slot < total; slot++)
    {
        format(row, sizeof(row), "%s\t%d\t%s -> %s | /cmdfixadd %s /comando_certo\n", gPlayerNotFoundApplyCommands[playerid][slot], counts[slot], firstSeen[slot], lastSeen[slot], gPlayerNotFoundApplyCommands[playerid][slot]);
        strcat(report, row, sizeof(report));
    }
    if (overflow > 0)
    {
        format(row, sizeof(row), "\n+%d comando(s) excederam o limite do dialog. Consulte %s.", overflow, LOG_COMMAND_AI_FILE);
        strcat(report, row, sizeof(report));
    }
    if (markerFound)
    {
        format(row, sizeof(row), "\nDesde: %s", bootTime);
        strcat(report, row, sizeof(report));
    }

    Dispatch_LogNfSummary(playerid, total, resolvedBootCount, hotfixCoveredCount, overflow, markerFound, bootTime, "ok");
    ShowPlayerDialog(playerid, DIALOG_COMMAND_NOTFOUNDS, DIALOG_STYLE_TABLIST_HEADERS, "NOT_FOUND recentes", report, "Fechar", "");
    return 1;
}

stock Dispatch_ReadNfLogInt(line[], key[])
{
    new needle[32];
    new value[16];
    new start;
    new end;

    format(needle, sizeof(needle), "%s=", key);
    start = strfind(line, needle, false);
    if (start == -1)
    {
        return 0;
    }

    start += strlen(needle);
    end = start;
    while (line[end] != 0 && line[end] != ' ' && line[end] != '|')
    {
        end++;
    }

    strmid(value, line, start, end, sizeof(value));
    return strval(value);
}

stock Dispatch_ReadNfLogText(line[], key[], output[], size = sizeof(output))
{
    new needle[32];
    new start;
    new end;

    output[0] = 0;
    format(needle, sizeof(needle), "%s=", key);
    start = strfind(line, needle, false);
    if (start == -1)
    {
        return 0;
    }

    start += strlen(needle);
    end = start;
    while (line[end] != 0 && line[end] != ' ' && line[end] != '|')
    {
        end++;
    }

    strmid(output, line, start, end, size);
    return 1;
}

stock Dispatch_ShowNotFoundHistory(playerid)
{
    new File:file;
    new line[256];
    new rows[12][192];
    new rowCount;
    new rowIndex;
    new output[3072];
    new row[192];
    new timestamp[24];
    new bootTime[24];
    new status[24];
    new pending;
    new resolvedBoot;
    new hotfixCovered;
    new overflow;
    new firstPending = -1;
    new lastPending = -1;
    new trend[32];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    if (!fexist(LOG_ADMIN_FILE))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "log_admin_actions.txt ainda nao existe.");
        return 1;
    }

    file = fopen(LOG_ADMIN_FILE, io_read);
    if (!file)
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel abrir log_admin_actions.txt.");
        return 1;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (strfind(line, "|NOT_FOUND_REPORT|", false) == -1)
        {
            continue;
        }

        strmid(timestamp, line, 0, 19, sizeof(timestamp));
        pending = Dispatch_ReadNfLogInt(line, "pendentes");
        if (firstPending == -1)
        {
            firstPending = pending;
        }
        lastPending = pending;
        resolvedBoot = Dispatch_ReadNfLogInt(line, "resolvidos_boot");
        hotfixCovered = Dispatch_ReadNfLogInt(line, "hotfix");
        overflow = Dispatch_ReadNfLogInt(line, "overflow");
        if (!Dispatch_ReadNfLogText(line, "boot", bootTime, sizeof(bootTime)))
        {
            format(bootTime, sizeof(bootTime), "-");
        }
        if (!Dispatch_ReadNfLogText(line, "status", status, sizeof(status)))
        {
            format(status, sizeof(status), "legado");
        }

        format(row, sizeof(row), "%s\t%d\t%d\t%d\t%d\t%s\t%s\n", timestamp, pending, resolvedBoot, hotfixCovered, overflow, status, bootTime);
        rowIndex = rowCount % 12;
        format(rows[rowIndex], 192, "%s", row);
        rowCount++;
    }

    fclose(file);

    if (rowCount == 0)
    {
        ShowPlayerDialog(playerid, DIALOG_COMMAND_NOTFOUND_HISTORY, DIALOG_STYLE_MSGBOX, "Historico NOT_FOUND", "Nenhum NOT_FOUND_REPORT encontrado em log_admin_actions.txt.\n\nUse /notfounds para gerar o primeiro resumo.", "Fechar", "");
        return 1;
    }

    format(output, sizeof(output), "Data\tPend\tBoot\tHotfix\tOver\tStatus\tMarcador\n");
    if (lastPending == 0)
    {
        format(trend, sizeof(trend), "zerou");
    }
    else if (lastPending < firstPending)
    {
        format(trend, sizeof(trend), "caiu");
    }
    else if (lastPending > firstPending)
    {
        format(trend, sizeof(trend), "subiu");
    }
    else
    {
        format(trend, sizeof(trend), "estavel");
    }
    format(row, sizeof(row), "Tendencia\t%d\t%d\t0\t0\t%s\tbase %d\n", lastPending, firstPending, trend, firstPending);
    strcat(output, row, sizeof(output));
    new start = rowCount > 12 ? (rowCount % 12) : 0;
    new limit = rowCount > 12 ? 12 : rowCount;
    for (new offset = 0; offset < limit; offset++)
    {
        rowIndex = (start + offset) % 12;
        strcat(output, rows[rowIndex], sizeof(output));
    }

    WritePlayerLog(LOG_ADMIN_FILE, "NOT_FOUND_HISTORY", playerid, "consultou historico NOT_FOUND_REPORT");
    ShowPlayerDialog(playerid, DIALOG_COMMAND_NOTFOUND_HISTORY, DIALOG_STYLE_TABLIST_HEADERS, "Historico NOT_FOUND", output, "Fechar", "");
    return 1;
}

stock Dispatch_CountPendingNf(output[], size = sizeof(output))
{
    new File:file;
    new line[256];
    new bootTime[24];
    new lineTime[24];
    new command[DISPATCH_NOTFOUND_CMD_SIZE];
    new seen[DISPATCH_NOTFOUND_DONE_MAX][DISPATCH_NOTFOUND_CMD_SIZE];
    new count;
    new markerFound;

    output[0] = 0;
    markerFound = Dispatch_FindLastBootMarker(bootTime, sizeof(bootTime));
    if (!fexist(LOG_COMMAND_AI_FILE))
    {
        return 0;
    }

    file = fopen(LOG_COMMAND_AI_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (strfind(line, "resultado=NOT_FOUND", false) == -1)
        {
            continue;
        }
        strmid(lineTime, line, 0, 19, sizeof(lineTime));
        if (markerFound && strcmp(lineTime, bootTime, false) < 0)
        {
            continue;
        }
        if (!Dispatch_ExtractNotFoundCommand(line, command, sizeof(command)))
        {
            continue;
        }
        if (Dispatch_IsNfResolvedBoot(command) || Dispatch_FindCommandHotfix(command) != -1)
        {
            continue;
        }
        Dispatch_AddUniqueNfCommand(seen, count, DISPATCH_NOTFOUND_DONE_MAX, command);
        format(output, size, "%s", command);
    }

    fclose(file);
    return count;
}

stock Dispatch_CountHotfixUse(source[])
{
    new File:file;
    new line[256];
    new needle[48];
    new count;

    if (!fexist(LOG_COMMAND_AI_FILE))
    {
        return 0;
    }

    format(needle, sizeof(needle), "from=%s", source);
    file = fopen(LOG_COMMAND_AI_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (strfind(line, "|COMMAND_HOTFIX|", false) != -1 && strfind(line, needle, true) != -1)
        {
            count++;
        }
    }

    fclose(file);
    return count;
}

stock Dispatch_ShowCmdFixPromote(playerid)
{
    new File:file;
    new list[3072];
    new row[192];
    new route[48];
    new targetCommand[COMMAND_HOTFIX_CMD_SIZE];
    new useCount;
    new shown;
    new overflow;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    file = fopen(COMMAND_HOTFIX_PROMOTE_FILE, io_write);
    if (!file)
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel gravar command_hotfix_promote.txt.");
        return 1;
    }

    fwrite(file, "Alias\tDestino\tUso\tRota\tAcao\r\n");
    format(list, sizeof(list), "Alias\tDestino\tUso / acao\n");
    for (new slot = 0; slot < gCommandHotfixCount; slot++)
    {
        GetCommandName(gCommandHotfixTo[slot], targetCommand, sizeof(targetCommand));
        Dispatch_GetCommandRoute(targetCommand, route, sizeof(route));
        useCount = Dispatch_CountHotfixUse(gCommandHotfixFrom[slot]);

        if (useCount >= 3)
        {
            format(row, sizeof(row), "%s\t%s\t%d usos | promover handler\n", gCommandHotfixFrom[slot], targetCommand, useCount);
        }
        else if (useCount == 0)
        {
            format(row, sizeof(row), "%s\t%s\tsem uso | revisar remocao\n", gCommandHotfixFrom[slot], targetCommand);
        }
        else
        {
            format(row, sizeof(row), "%s\t%s\t%d uso(s) | monitorar\n", gCommandHotfixFrom[slot], targetCommand, useCount);
        }

        if (shown < 16)
        {
            strcat(list, row, sizeof(list));
            shown++;
        }
        else
        {
            overflow++;
        }

        format(row, sizeof(row), "%s\t%s\t%d\t%s\t%s\r\n", gCommandHotfixFrom[slot], targetCommand, useCount, route, useCount >= 3 ? ("promover_handler") : (useCount == 0 ? ("revisar_remocao") : ("monitorar")));
        fwrite(file, row);
    }

    fclose(file);
    if (overflow > 0)
    {
        format(row, sizeof(row), "\n+%d hotfix(es) no arquivo %s.", overflow, COMMAND_HOTFIX_PROMOTE_FILE);
        strcat(list, row, sizeof(list));
    }
    if (gCommandHotfixCount == 0)
    {
        strcat(list, "-\t-\tnenhum hotfix carregado\n", sizeof(list));
    }

    WritePlayerLog(LOG_ADMIN_FILE, "COMMAND_HOTFIX_PROMOTE", playerid, COMMAND_HOTFIX_PROMOTE_FILE);
    ShowPlayerDialog(playerid, DIALOG_CMD_HOTFIX_PROMOTE, DIALOG_STYLE_TABLIST_HEADERS, "Promover command hotfix", list, "Fechar", "");
    return 1;
}

stock Dispatch_ShowPostDeploy(playerid)
{
    new list[3072];
    new row[192];
    new bootTime[24];
    new lastNotFound[DISPATCH_NOTFOUND_CMD_SIZE];
    new pendingNf;
    new markerFound;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    Gm_WriteIntegrityReport();
    markerFound = Dispatch_FindLastBootMarker(bootTime, sizeof(bootTime));
    pendingNf = Dispatch_CountPendingNf(lastNotFound, sizeof(lastNotFound));

    format(list, sizeof(list), "Item\tStatus\tDetalhe\n");
    format(row, sizeof(row), "Versao\t%s\t%s\n", strcmp(gServerVersion, GM_VERSION, false) == 0 ? ("OK") : ("ALERTA"), GM_VERSION);
    strcat(list, row, sizeof(list));
    format(row, sizeof(row), "AMX\tOK\t%s | hash no deploy_manifest.txt\n", GM_RELEASE_AMX);
    strcat(list, row, sizeof(list));
    format(row, sizeof(row), "Hotfixes\t%s\t%d carregado(s)\n", gCommandHotfixCount > 0 ? ("OK") : ("VAZIO"), gCommandHotfixCount);
    strcat(list, row, sizeof(list));
    format(row, sizeof(row), "NOT_FOUND\t%s\tpendentes %d | ultimo %s\n", pendingNf == 0 ? ("OK") : ("ALERTA"), pendingNf, lastNotFound[0] ? lastNotFound : ("-"));
    strcat(list, row, sizeof(list));
    format(row, sizeof(row), "Alertas boot\t%s\t%d NOT_FOUND novo(s)\n", gCommandNotFoundAlertCount == 0 ? ("OK") : ("ALERTA"), gCommandNotFoundAlertCount);
    strcat(list, row, sizeof(list));
    format(row, sizeof(row), "Boot\t%s\t%s\n", markerFound ? ("OK") : ("ALERTA"), markerFound ? bootTime : ("sem marcador"));
    strcat(list, row, sizeof(list));
    format(row, sizeof(row), "server_log\t%s\tserver_log.txt\n", fexist("server_log.txt") ? ("OK") : ("FALTA"));
    strcat(list, row, sizeof(list));
    format(row, sizeof(row), "crashinfo\t%s\tcrashinfo.txt\n", fexist("crashinfo.txt") ? ("VERIFICAR") : ("OK"));
    strcat(list, row, sizeof(list));
    format(row, sizeof(row), "Integridade\t%s\t%s\n", fexist(INTEGRITY_REPORT_FILE) ? ("OK") : ("FALTA"), INTEGRITY_REPORT_FILE);
    strcat(list, row, sizeof(list));
    strcat(list, "Historico\tINFO\t/notfoundshistorico | /cmdfixpromover\n", sizeof(list));

    WritePlayerLog(LOG_ADMIN_FILE, "POST_DEPLOY_PANEL", playerid, "consultou /posdeploy");
    ShowPlayerDialog(playerid, DIALOG_POST_DEPLOY, DIALOG_STYLE_TABLIST_HEADERS, "Saude pos-deploy", list, "Fechar", "");
    return 1;
}

stock Dispatch_LoadNotFoundApply(playerid)
{
    new File:file;
    new line[256];
    new bootTime[24];
    new lineTime[24];
    new command[DISPATCH_NOTFOUND_CMD_SIZE];
    new markerFound;
    new slot;
    new exists;

    gPlayerNotFoundApplyCount[playerid] = 0;
    gPlayerNotFoundApplySelected[playerid][0] = 0;

    markerFound = Dispatch_FindLastBootMarker(bootTime, sizeof(bootTime));
    if (!fexist(LOG_COMMAND_AI_FILE))
    {
        return 0;
    }

    file = fopen(LOG_COMMAND_AI_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (strfind(line, "resultado=NOT_FOUND", false) == -1)
        {
            continue;
        }

        strmid(lineTime, line, 0, 19, sizeof(lineTime));
        if (markerFound && strcmp(lineTime, bootTime, false) < 0)
        {
            continue;
        }

        if (!Dispatch_ExtractNotFoundCommand(line, command, sizeof(command)))
        {
            continue;
        }
        if (Dispatch_IsNfResolvedBoot(command) || Dispatch_FindCommandHotfix(command) != -1)
        {
            continue;
        }

        exists = 0;
        for (slot = 0; slot < gPlayerNotFoundApplyCount[playerid]; slot++)
        {
            if (strcmp(gPlayerNotFoundApplyCommands[playerid][slot], command, true) == 0)
            {
                exists = 1;
                break;
            }
        }
        if (exists)
        {
            continue;
        }
        if (gPlayerNotFoundApplyCount[playerid] >= DISPATCH_NOTFOUND_MAX)
        {
            continue;
        }

        slot = gPlayerNotFoundApplyCount[playerid];
        format(gPlayerNotFoundApplyCommands[playerid][slot], DISPATCH_NOTFOUND_CMD_SIZE, "%s", command);
        gPlayerNotFoundApplyCount[playerid]++;
    }

    fclose(file);
    return gPlayerNotFoundApplyCount[playerid];
}

stock Dispatch_CmdNorm(source[], output[], size = sizeof(output))
{
    new length = strlen(source);
    new target;
    new ch;

    for (new index = 0; index < length && target < size - 1; index++)
    {
        ch = source[index];
        if (ch == '/')
        {
            continue;
        }
        if (ch >= 'A' && ch <= 'Z')
        {
            ch += 32;
        }
        output[target++] = ch;
    }
    output[target] = 0;
    return target;
}

stock Dispatch_CmdDistance(left[], right[])
{
    new leftText[COMMAND_HOTFIX_CMD_SIZE];
    new rightText[COMMAND_HOTFIX_CMD_SIZE];
    new previous[COMMAND_HOTFIX_CMD_SIZE];
    new current[COMMAND_HOTFIX_CMD_SIZE];
    new leftLen = Dispatch_CmdNorm(left, leftText, sizeof(leftText));
    new rightLen = Dispatch_CmdNorm(right, rightText, sizeof(rightText));
    new deletion;
    new insertion;
    new substitution;
    new cost;
    new best;

    if (leftLen == 0)
    {
        return rightLen;
    }
    if (rightLen == 0)
    {
        return leftLen;
    }

    for (new column = 0; column <= rightLen; column++)
    {
        previous[column] = column;
    }

    for (new row = 1; row <= leftLen; row++)
    {
        current[0] = row;
        for (new column = 1; column <= rightLen; column++)
        {
            cost = (leftText[row - 1] == rightText[column - 1]) ? 0 : 1;
            deletion = previous[column] + 1;
            insertion = current[column - 1] + 1;
            substitution = previous[column - 1] + cost;
            best = deletion;
            if (insertion < best)
            {
                best = insertion;
            }
            if (substitution < best)
            {
                best = substitution;
            }
            current[column] = best;
        }
        for (new column = 0; column <= rightLen; column++)
        {
            previous[column] = current[column];
        }
    }

    return previous[rightLen];
}

stock Dispatch_CmdPrefixScore(left[], right[])
{
    new leftText[COMMAND_HOTFIX_CMD_SIZE];
    new rightText[COMMAND_HOTFIX_CMD_SIZE];
    new leftLen = Dispatch_CmdNorm(left, leftText, sizeof(leftText));
    new rightLen = Dispatch_CmdNorm(right, rightText, sizeof(rightText));
    new limit = (leftLen < rightLen) ? leftLen : rightLen;
    new count;

    while (count < limit && leftText[count] == rightText[count])
    {
        count++;
    }
    return count * 3;
}

stock Dispatch_NfKeywordScore(source[], candidate[])
{
    new score;

    if (strfind(source, "blitz", true) != -1 && strfind(candidate, "blitz", true) != -1) score += 35;
    if (strfind(source, "barreira", true) != -1 && strfind(candidate, "barreira", true) != -1) score += 30;
    if (strfind(source, "prf", true) != -1 && strfind(candidate, "prf", true) != -1) score += 25;
    if (strfind(source, "financ", true) != -1 && strfind(candidate, "financ", true) != -1) score += 25;
    if (strfind(source, "boleto", true) != -1 && strfind(candidate, "boleto", true) != -1) score += 25;
    if (strfind(source, "editar", true) != -1 && strfind(candidate, "editar", true) != -1) score += 25;
    if (strfind(source, "fogo", true) != -1 && strfind(candidate, "missaopublica", true) != -1) score += 55;
    if (strfind(source, "entrar", true) != -1 && strfind(candidate, "interagir", true) != -1) score += 45;

    return score;
}

stock Dispatch_CmdSimilarity(source[], candidate[])
{
    new sourceText[COMMAND_HOTFIX_CMD_SIZE];
    new candidateText[COMMAND_HOTFIX_CMD_SIZE];
    new sourceLen = Dispatch_CmdNorm(source, sourceText, sizeof(sourceText));
    new candidateLen = Dispatch_CmdNorm(candidate, candidateText, sizeof(candidateText));
    new maxLen = (sourceLen > candidateLen) ? sourceLen : candidateLen;
    new distance;
    new score;

    if (maxLen <= 0)
    {
        return 0;
    }

    distance = Dispatch_CmdDistance(source, candidate);
    score = 100 - ((distance * 100) / maxLen);
    score += Dispatch_CmdPrefixScore(source, candidate);
    score += Dispatch_NfKeywordScore(source, candidate);
    return score;
}

stock Dispatch_TryNfSuggestion(source[], candidate[], best[], size, &bestScore)
{
    new route[48];
    new score;

    if (strcmp(source, candidate, true) == 0)
    {
        return 0;
    }

    Dispatch_GetCommandRoute(candidate, route, sizeof(route));
    if (strcmp(route, "cadeia geral", true) == 0)
    {
        return 0;
    }

    score = Dispatch_CmdSimilarity(source, candidate);
    if (score > bestScore)
    {
        bestScore = score;
        format(best, size, "%s", candidate);
    }
    return 1;
}

stock Dispatch_FindNfSuggestion(source[], output[], size = sizeof(output))
{
    new bestScore;

    output[0] = 0;
    Dispatch_TryNfSuggestion(source, "/ajuda", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/menu", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/admin", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/versao", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/saudegm", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/integridade", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/selftestgm", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/releasecheck", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/statusserver", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/politica", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/prefeitura", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/transparencia", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/empresa", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/boletos", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/dormir", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/hoteis", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/imoveis", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/entrarlocal", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/interagir", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/editarmapa", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/celular", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/chamados", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/banco", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/pix", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/radio", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/veiculo", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/garagem", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/detran", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/pedagio", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/criarpedagio", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/emprego", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/profissoes", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/trabalhar", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/bico", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/saude", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/contratos", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/financiamento", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/obraspublicas", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/financiarobra", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/missaopublica", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/multa", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/faccoes", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/roubaratm", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/crimeinfo", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/apreendercrime", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/abordagem", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/revistar", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/ficha", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/prender", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/crimes", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/procurados", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/criarblitz", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/barreiraprf", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/criarbarreiraprf", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/notfounds", output, size, bestScore);
    Dispatch_TryNfSuggestion(source, "/recarregarcomandos", output, size, bestScore);

    if (bestScore < 65)
    {
        output[0] = 0;
        return 0;
    }
    return 1;
}

stock Dispatch_ShowNotFoundApplyList(playerid)
{
    new list[2048];
    new line[128];
    new suggestion[COMMAND_HOTFIX_TARGET_SIZE];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    if (Dispatch_LoadNotFoundApply(playerid) <= 0)
    {
        SendClientMessage(playerid, COLOR_GREEN, "Nenhum NOT_FOUND novo desde o ultimo boot para aplicar.");
        return 1;
    }

    format(list, sizeof(list), "Comando\tSugestao\n");
    for (new slot = 0; slot < gPlayerNotFoundApplyCount[playerid]; slot++)
    {
        if (Dispatch_FindNfSuggestion(gPlayerNotFoundApplyCommands[playerid][slot], suggestion, sizeof(suggestion)))
        {
            format(line, sizeof(line), "%s\t%s\n", gPlayerNotFoundApplyCommands[playerid][slot], suggestion);
        }
        else
        {
            format(line, sizeof(line), "%s\tDigitar manualmente\n", gPlayerNotFoundApplyCommands[playerid][slot]);
        }
        strcat(list, line, sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_COMMAND_NOTFOUND_PICK, DIALOG_STYLE_TABLIST_HEADERS, "Aplicar command hotfix", list, "Escolher", "Fechar");
    return 1;
}

stock Dispatch_FindCommandHotfix(source[])
{
    for (new slot = 0; slot < gCommandHotfixCount; slot++)
    {
        if (strcmp(gCommandHotfixFrom[slot], source, true) == 0)
        {
            return slot;
        }
    }
    return -1;
}

stock Dispatch_ShowNfManualTarget(playerid)
{
    new message[256];

    if (gPlayerNotFoundApplySuggest[playerid][0] == '/')
    {
        format(message, sizeof(message), "Digite o comando correto para %s.\n\nSugestao atual: %s\nUse outro destino se a sugestao nao for a rota certa.\n\nSera gravado em command_hotfixes.txt.", gPlayerNotFoundApplySelected[playerid], gPlayerNotFoundApplySuggest[playerid]);
    }
    else
    {
        format(message, sizeof(message), "Digite o comando correto para %s.\n\nExemplo: /comando_certo\nSera gravado em command_hotfixes.txt.", gPlayerNotFoundApplySelected[playerid]);
    }

    ShowPlayerDialog(playerid, DIALOG_COMMAND_NOTFOUND_MANUAL, DIALOG_STYLE_INPUT, "Destino do hotfix", message, "Salvar", "Voltar");
    return 1;
}

stock Dispatch_SaveNfHotfix(playerid, source[], target[])
{
    new existing;
    new loaded;
    new message[160];
    new targetCommand[COMMAND_HOTFIX_CMD_SIZE];
    new route[48];
    new sourceRoute[48];

    Cfg_Trim(target);
    if (source[0] != '/' || target[0] != '/')
    {
        SendClientMessage(playerid, COLOR_RED, "Destino invalido. Use um comando iniciando com /.");
        return 1;
    }

    Dispatch_GetCommandRoute(source, sourceRoute, sizeof(sourceRoute));
    if (strcmp(sourceRoute, "cadeia geral", true) != 0)
    {
        format(message, sizeof(message), "Hotfix recusado: %s ja tem handler Pawn real (%s).", source, sourceRoute);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        WritePlayerLog(LOG_ADMIN_FILE, "COMMAND_HOTFIX_REJECT", playerid, message);
        Dispatch_MarkNfResolvedBoot(source);
        return Dispatch_ShowNotFoundApplyList(playerid);
    }

    GetCommandName(target, targetCommand, sizeof(targetCommand));
    Dispatch_GetCommandRoute(targetCommand, route, sizeof(route));
    if (strcmp(route, "cadeia geral", true) == 0)
    {
        format(message, sizeof(message), "Destino recusado: %s nao aparece como comando real no router.", targetCommand);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    existing = Dispatch_FindCommandHotfix(source);
    if (existing != -1)
    {
        format(message, sizeof(message), "Hotfix ja existe: %s -> %s. Edite command_hotfixes.txt se quiser substituir.", source, gCommandHotfixTo[existing]);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        return 1;
    }

    if (!CommandHotfix_SaveAlias(source, target))
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel salvar command_hotfixes.txt.");
        return 1;
    }

    loaded = CommandHotfix_Load();
    format(message, sizeof(message), "Hotfix aplicado: %s -> %s | %d carregado(s).", source, target, loaded);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(message, sizeof(message), "notfound=%s target=%s route=%s", source, target, route);
    WritePlayerLog(LOG_ADMIN_FILE, "NOT_FOUND_APPLY", playerid, message);
    Dispatch_MarkNfResolvedBoot(source);
    gPlayerNotFoundApplySelected[playerid][0] = 0;
    gPlayerNotFoundApplySuggest[playerid][0] = 0;
    return Dispatch_ShowNotFoundApplyList(playerid);
}

stock Dispatch_HandleNotFoundDialog(playerid, dialogid, response, listitem, inputtext[])
{
    new source[DISPATCH_NOTFOUND_CMD_SIZE];
    new target[COMMAND_HOTFIX_TARGET_SIZE];
    new message[256];
    new route[48];
    new targetCommand[COMMAND_HOTFIX_CMD_SIZE];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    if (dialogid == DIALOG_COMMAND_NOTFOUND_PICK)
    {
        if (!response)
        {
            return 1;
        }
        if (listitem < 0 || listitem >= gPlayerNotFoundApplyCount[playerid])
        {
            SendClientMessage(playerid, COLOR_RED, "Selecao de NOT_FOUND invalida. Use /notfounds aplicar novamente.");
            return 1;
        }

        format(gPlayerNotFoundApplySelected[playerid], DISPATCH_NOTFOUND_CMD_SIZE, "%s", gPlayerNotFoundApplyCommands[playerid][listitem]);
        if (Dispatch_FindNfSuggestion(gPlayerNotFoundApplySelected[playerid], gPlayerNotFoundApplySuggest[playerid], COMMAND_HOTFIX_TARGET_SIZE))
        {
            GetCommandName(gPlayerNotFoundApplySuggest[playerid], targetCommand, sizeof(targetCommand));
            Dispatch_GetCommandRoute(targetCommand, route, sizeof(route));
            format(message, sizeof(message), "Opcao\tDestino / rota\nUsar sugestao\t%s | %s\nDigitar manualmente\tOutro comando\n", gPlayerNotFoundApplySuggest[playerid], route);
            ShowPlayerDialog(playerid, DIALOG_COMMAND_NOTFOUND_TARGET, DIALOG_STYLE_TABLIST_HEADERS, "Destino do hotfix", message, "Escolher", "Voltar");
        }
        else
        {
            gPlayerNotFoundApplySuggest[playerid][0] = 0;
            return Dispatch_ShowNfManualTarget(playerid);
        }
        return 1;
    }

    if (dialogid == DIALOG_COMMAND_NOTFOUND_TARGET)
    {
        if (!response)
        {
            return Dispatch_ShowNotFoundApplyList(playerid);
        }
        format(source, sizeof(source), "%s", gPlayerNotFoundApplySelected[playerid]);
        if (listitem == 0 && gPlayerNotFoundApplySuggest[playerid][0] == '/')
        {
            format(target, sizeof(target), "%s", gPlayerNotFoundApplySuggest[playerid]);
            return Dispatch_SaveNfHotfix(playerid, source, target);
        }
        return Dispatch_ShowNfManualTarget(playerid);
    }

    if (dialogid == DIALOG_COMMAND_NOTFOUND_MANUAL)
    {
        if (!response)
        {
            return Dispatch_ShowNotFoundApplyList(playerid);
        }

        format(source, sizeof(source), "%s", gPlayerNotFoundApplySelected[playerid]);
        format(target, sizeof(target), "%s", inputtext);
        return Dispatch_SaveNfHotfix(playerid, source, target);
    }

    return 1;
}

stock DispatchPriorityCommand(playerid, cmdtext[], command[])
{
    if (Dispatch_IsPoliticalCommand(command))
    {
        return Dispatch_RunLifeCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/prefeitura", true) == 0 || strcmp(command, "/painelprefeitura", true) == 0 || strcmp(command, "/orcamento", true) == 0 || strcmp(command, "/transparencia", true) == 0 || strcmp(command, "/cofrepublico", true) == 0)
    {
        return Dispatch_RunLifeCommand(playerid, cmdtext);
    }
    if (Dispatch_IsBusinessCommand(command))
    {
        return Dispatch_RunLifeCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/boletos", true) == 0 || strcmp(command, "/boleto", true) == 0 || strcmp(command, "/contas", true) == 0 || strcmp(command, "/energia", true) == 0 || strcmp(command, "/instalarsolar", true) == 0)
    {
        return Dispatch_RunLifeCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/dormir", true) == 0 || strcmp(command, "/sono", true) == 0 || strcmp(command, "/entrarcasa", true) == 0 || strcmp(command, "/saircasa", true) == 0 || strcmp(command, "/entrarhotel", true) == 0 || strcmp(command, "/sairhotel", true) == 0)
    {
        return Dispatch_RunPropertyCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/hoteis", true) == 0 || strcmp(command, "/hotel", true) == 0 || strcmp(command, "/gpshotel", true) == 0 || strcmp(command, "/imoveis", true) == 0 || strcmp(command, "/comprarcasa", true) == 0 || strcmp(command, "/alugarcasa", true) == 0)
    {
        return Dispatch_RunPropertyCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/entrarlocal", true) == 0 || strcmp(command, "/entrarinterior", true) == 0 || strcmp(command, "/sairlocal", true) == 0 || strcmp(command, "/criarcasaedit", true) == 0 || strcmp(command, "/criarempresaedit", true) == 0 || strcmp(command, "/criarpostoedit", true) == 0)
    {
        return Dispatch_RunPropertyCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/entrar", true) == 0)
    {
        HandleLocationInteraction(playerid);
        return 1;
    }
    if (strcmp(command, "/celular", true) == 0 || strcmp(command, "/phone", true) == 0 || strcmp(command, "/app", true) == 0)
    {
        return Dispatch_RunPhoneCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/190", true) == 0 || strcmp(command, "/192", true) == 0 || strcmp(command, "/193", true) == 0 || strcmp(command, "/abrirchamado", true) == 0 || strcmp(command, "/chamados", true) == 0 || strcmp(command, "/aceitarchamado", true) == 0 || strcmp(command, "/cancelarchamado", true) == 0)
    {
        return Dispatch_RunLifeCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/banco", true) == 0 || strcmp(command, "/saldo", true) == 0 || strcmp(command, "/extrato", true) == 0 || strcmp(command, "/pix", true) == 0 || strcmp(command, "/transferir", true) == 0 || strcmp(command, "/salario", true) == 0)
    {
        return Dispatch_RunBankCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/radio", true) == 0 || strcmp(command, "/radios", true) == 0 || strcmp(command, "/musica", true) == 0 || strcmp(command, "/pararradio", true) == 0 || strcmp(command, "/pararmusica", true) == 0 || strcmp(command, "/stopradio", true) == 0)
    {
        return Dispatch_RunRadioCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/veiculo", true) == 0 || strcmp(command, "/veiculos", true) == 0 || strcmp(command, "/garagem", true) == 0 || strcmp(command, "/garagemcasa", true) == 0 || strcmp(command, "/detran", true) == 0 || strcmp(command, "/ipva", true) == 0)
    {
        return Dispatch_RunVehicleCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/pedagio", true) == 0 || strcmp(command, "/pedagios", true) == 0 || strcmp(command, "/irpedagio", true) == 0 || strcmp(command, "/criarpedagio", true) == 0 || strcmp(command, "/removerpedagio", true) == 0 || strcmp(command, "/ajustarpedagio", true) == 0)
    {
        return Dispatch_RunTollCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/emprego", true) == 0 || strcmp(command, "/profissoes", true) == 0 || strcmp(command, "/profissao", true) == 0 || strcmp(command, "/empregos", true) == 0 || strcmp(command, "/progresso", true) == 0 || strcmp(command, "/trabalhar", true) == 0 || strcmp(command, "/baterponto", true) == 0 || strcmp(command, "/plantao", true) == 0 || strcmp(command, "/bico", true) == 0 || strcmp(command, "/freela", true) == 0 || strcmp(command, "/cancelartrabalho", true) == 0)
    {
        return Dispatch_RunJobCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/saude", true) == 0 || strcmp(command, "/ferimentos", true) == 0 || strcmp(command, "/plano", true) == 0 || strcmp(command, "/planosaude", true) == 0)
    {
        return Dispatch_RunHospitalCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/contratos", true) == 0 || strcmp(command, "/contrato", true) == 0 || strcmp(command, "/financiamento", true) == 0 || strcmp(command, "/finaciamento", true) == 0)
    {
        return Dispatch_RunLifeCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/obraspublicas", true) == 0 || strcmp(command, "/obras", true) == 0 || strcmp(command, "/financiarobra", true) == 0 || strcmp(command, "/financiamentoobra", true) == 0)
    {
        return Dispatch_RunLifeCommand(playerid, cmdtext);
    }
    if (strcmp(command, "/missaopublica", true) == 0 || strcmp(command, "/ocorrencia", true) == 0 || strcmp(command, "/fogo", true) == 0)
    {
        return Dispatch_RunLifeCommand(playerid, cmdtext);
    }
    if (Dispatch_IsPoliceCommand(command))
    {
        return HandlePoliceCommands(playerid, cmdtext);
    }
    return 0;
}

stock Dispatch_ResetCommandRouter(playerid)
{
    new targetid;
    new maxPlayers = GetMaxPlayers();
    new name[MAX_PLAYER_NAME + 1];
    new message[144];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    for (targetid = 0; targetid < maxPlayers; targetid++)
    {
        if (!IsPlayerConnected(targetid))
        {
            continue;
        }
        Dispatch_ResetCmdState(targetid);
    }

    ShowPlayerDialog(playerid, -1, DIALOG_STYLE_MSGBOX, " ", " ", "", "");
    GetPlayerNameEx(playerid, name, sizeof(name));
    format(message, sizeof(message), "[COMANDOS] Cadeia de comandos reiniciada por %s. Estados temporarios limpos.", name);
    CommandAI_SendOwnerAlert(message);
    WritePlayerLog(LOG_ADMIN_FILE, "COMMAND_ROUTER_RESET", playerid, "resetou estados temporarios da cadeia de comandos");
    SendClientMessage(playerid, COLOR_GREEN, "Cadeia de comandos reiniciada. Se algum comando falhar, a staff sera avisada no chat.");
    return 1;
}

stock Dispatch_ResetCmdState(playerid)
{
    gCommandUnknownAlertTick[playerid] = 0;
    gCommandAiAlertTick[playerid] = 0;
    gPlayerMenuDialogCount[playerid] = 0;
    Security_ResetCommandState(playerid);
    for (new index = 0; index < MENU_MAX_CATEGORIES; index++)
    {
        gPlayerMenuDialogCategories[playerid][index] = -1;
    }
    for (new index = 0; index < HELP_MAX_CATEGORIES; index++)
    {
        gPlayerHelpDialogCategories[playerid][index] = -1;
    }
    return 1;
}

stock Dispatch_AlertUnknownCommand(playerid, command[])
{
    new tick = GetTickCount();

    if (command[0] == 0)
    {
        return 0;
    }
    if (tick - gCommandUnknownAlertTick[playerid] < 10000)
    {
        return 0;
    }

    gCommandUnknownAlertTick[playerid] = tick;
    WritePlayerLog(LOG_ADMIN_FILE, "UNKNOWN_COMMAND", playerid, command);
    return 1;
}

stock Dispatch_DebugTrace(playerid, command[], stageText[])
{
    new name[MAX_PLAYER_NAME + 1];
    new message[160];

    if (!gCommandDebugMode || command[0] == 0)
    {
        return 0;
    }

    GetPlayerNameEx(playerid, name, sizeof(name));
    format(message, sizeof(message), "[CMD-DEBUG] %s ID %d %s: %s", name, playerid, stageText, command);
    CommandAI_SendOwnerAlert(message);
    WritePlayerLog(LOG_ADMIN_FILE, "COMMAND_DEBUG", playerid, message);
    return 1;
}

stock Dispatch_RunPlayerCommand(playerid, cmdtext[], command[], stageText[])
{
    new message[144];

    Dispatch_CommandTrace(playerid, command, "modulo", "player-chain", "checking");
    if (HandlePlayerCommands(playerid, cmdtext))
    {
        Dispatch_DebugTrace(playerid, command, stageText);
        Dispatch_CommandTrace(playerid, command, "resultado", "player-chain", stageText);
        CommandAI_Record(playerid, command, "player-chain", "OK", 0, stageText);
        return 1;
    }

    Dispatch_DebugTrace(playerid, command, "falhou player chain");
    Dispatch_CommandTrace(playerid, command, "resultado", "player-chain", "failed");
    CommandAI_Record(playerid, command, "player-chain", "HANDLER_RETURN_0", 2, "cadeia_player_nao_respondeu");
    Dispatch_AlertUnknownCommand(playerid, command);
    format(message, sizeof(message), "Comando %s nao respondeu na central protegida. Staff foi avisada; use /resetcomandos se persistir.", command);
    SendClientMessage(playerid, COLOR_ORANGE, message);
    return 1;
}

stock Dispatch_SetCommandDebug(playerid, enabled)
{
    new name[MAX_PLAYER_NAME + 1];
    new message[144];
    new trace[160];
    new targetid;
    new maxPlayers = GetMaxPlayers();

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    gCommandDebugMode = enabled;
    if (enabled)
    {
        for (targetid = 0; targetid < maxPlayers; targetid++)
        {
            if (IsPlayerConnected(targetid))
            {
                Dispatch_ResetCmdState(targetid);
            }
        }
    }

    GetPlayerNameEx(playerid, name, sizeof(name));
    format(message, sizeof(message), "[COMANDOS] Debug de comandos %s por %s.", gCommandDebugMode ? ("ATIVADO") : ("DESATIVADO"), name);
    CommandAI_SendOwnerAlert(message);
    WritePlayerLog(LOG_ADMIN_FILE, "COMMAND_DEBUG_MODE", playerid, message);
    format(trace, sizeof(trace), "rota=resultado modulo=command-router comando=/debugcomandos resultado=%s", gCommandDebugMode ? ("debug_ativado") : ("debug_desativado"));
    WritePlayerLog(LOG_ADMIN_FILE, "COMMAND_TRACE", playerid, trace);
    if (enabled)
    {
        SendClientMessage(playerid, COLOR_GREEN, "Debug profundo ativado. Estados temporarios de comandos foram limpos.");
    }
    return 1;
}

stock DispatchPlayerCommandText(playerid, cmdtext[])
{
    new command[32];
    new message[144];

    if (!IsValidConnectedPlayer(playerid) || IsPlayerNPC(playerid))
    {
        return 1;
    }

    GetCommandName(cmdtext, command, sizeof(command));
    if (command[0] == 0)
    {
        return 1;
    }

    if (!PlayerInfo[playerid][pLogged])
    {
        Dispatch_CommandTrace(playerid, command, "seguranca", "login", "blocked");
        CommandAI_Record(playerid, command, "login", "BLOCKED", 1, "player_sem_login");
        SendClientMessage(playerid, COLOR_RED, "Voce precisa fazer login antes de usar comandos.");
        ShowAuthDialog(playerid);
        return 1;
    }

    CommandAI_Record(playerid, command, "callback", "START", 0, "OnPlayerCommandText");
    Dispatch_DebugTrace(playerid, command, "entrou");
    Dispatch_CommandTrace(playerid, command, "callback", "OnPlayerCommandText", "entered");
    if (strcmp(command, "/ajuda", true) == 0 || strcmp(command, "/help", true) == 0 || strcmp(command, "/comandos", true) == 0)
    {
        Dispatch_DebugTrace(playerid, command, "handler ajuda direto");
        Dispatch_CommandTrace(playerid, command, "resultado", "ajuda", "handled-direct");
        CommandAI_Record(playerid, command, "ajuda", "OK", 0, "dialog_aberto_direto");
        return ShowHelpDialog(playerid);
    }
    if (strcmp(command, "/menu", true) == 0 || strcmp(command, "/painel", true) == 0 || strcmp(command, "/central", true) == 0 || strcmp(command, "/minhacentral", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "seguranca", "central", "bypass-menu");
        return Dispatch_RunPlayerCommand(playerid, cmdtext, command, "handler menu");
    }
    if (strcmp(command, "/versao", true) == 0 || strcmp(command, "/version", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "versao-direto", "queued");
        return Dispatch_QueueDeferredCommand(playerid, command, DISPATCH_DEFER_VERSION, "release-direto");
    }
    if (strcmp(command, "/saudegm", true) == 0 || strcmp(command, "/healthgm", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "saude-direto", "queued");
        return Dispatch_QueueDeferredCommand(playerid, command, DISPATCH_DEFER_HEALTH, "release-direto");
    }
    if (strcmp(command, "/integridade", true) == 0 || strcmp(command, "/integrity", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "integridade-direto", "queued");
        return Dispatch_QueueDeferredCommand(playerid, command, DISPATCH_DEFER_INTEGRITY, "release-direto");
    }
    if (strcmp(command, "/selftestgm", true) == 0 || strcmp(command, "/testegm", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "selftest-direto", "queued");
        return Dispatch_QueueDeferredCommand(playerid, command, DISPATCH_DEFER_SELFTEST, "release-direto");
    }
    if (strcmp(command, "/releasecheck", true) == 0 || strcmp(command, "/checkrelease", true) == 0 || strcmp(command, "/check1", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "releasecheck-direto", "queued");
        return Dispatch_QueueDeferredCommand(playerid, command, DISPATCH_DEFER_RELEASE, "release-direto");
    }
    if (strcmp(command, "/jornadadiaria", true) == 0 || strcmp(command, "/rotinadiaria", true) == 0 || strcmp(command, "/dia", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "jornada-direta", "queued");
        return Dispatch_QueueDeferredCommand(playerid, command, DISPATCH_DEFER_DAILY, "retencao-urbana");
    }
    if (strcmp(command, "/agendasemanal", true) == 0 || strcmp(command, "/metassemanais", true) == 0 || strcmp(command, "/semanal", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "agenda-direta", "queued");
        return Dispatch_QueueDeferredCommand(playerid, command, DISPATCH_DEFER_WEEKLY, "retencao-urbana");
    }
    if (strcmp(command, "/bairros", true) == 0 || strcmp(command, "/eventosbairro", true) == 0 || strcmp(command, "/metabairro", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "bairros-direto", "queued");
        return Dispatch_QueueDeferredCommand(playerid, command, DISPATCH_DEFER_DISTRICT, "retencao-urbana");
    }
    if (strcmp(command, "/progressourbano", true) == 0 || strcmp(command, "/reputacaourbana", true) == 0 || strcmp(command, "/urbano", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "urbano-direto", "queued");
        return Dispatch_QueueDeferredCommand(playerid, command, DISPATCH_DEFER_URBAN, "retencao-urbana");
    }
    if (strcmp(command, "/multa", true) == 0 || strcmp(command, "/multas", true) == 0 || strcmp(command, "/ctb", true) == 0 || strcmp(command, "/multar", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "seguranca", "multa", "checking");
        if (!Security_CheckCommand(playerid, cmdtext))
        {
            Dispatch_DebugTrace(playerid, command, "bloqueado security multa");
            Dispatch_CommandTrace(playerid, command, "seguranca", "multa", "blocked");
            CommandAI_Record(playerid, command, "seguranca/multa", "BLOCKED", 1, "Security_CheckCommand_retornou_0");
            return 1;
        }
        Dispatch_CommandTrace(playerid, command, "seguranca", "multa", "ok");
        Dispatch_CommandTrace(playerid, command, "modulo", "emprego/multas", "checking");
        if (HandleJobCommands(playerid, cmdtext))
        {
            Dispatch_DebugTrace(playerid, command, "handler job multa");
            Dispatch_CommandTrace(playerid, command, "resultado", "emprego/multas", "handled");
            CommandAI_Record(playerid, command, "emprego/multas", "OK", 0, "modulo_respondeu");
            return 1;
        }
        Dispatch_CommandTrace(playerid, command, "modulo", "emprego/multas", "miss");
        Dispatch_RunPlayerCommand(playerid, cmdtext, command, "fallback player multa");
        return 1;
    }
    if (Dispatch_IsPoliceCommand(command))
    {
        Dispatch_CommandTrace(playerid, command, "seguranca", "policia", "checking");
        if (!Security_CheckCommand(playerid, cmdtext))
        {
            Dispatch_DebugTrace(playerid, command, "bloqueado security policia");
            Dispatch_CommandTrace(playerid, command, "seguranca", "policia", "blocked");
            CommandAI_Record(playerid, command, "seguranca/policia", "BLOCKED", 1, "Security_CheckCommand_retornou_0");
            return 1;
        }
        Dispatch_CommandTrace(playerid, command, "seguranca", "policia", "ok");
        Dispatch_CommandTrace(playerid, command, "modulo", "policia", "checking");
        if (HandlePoliceCommands(playerid, cmdtext))
        {
            Dispatch_DebugTrace(playerid, command, "handler policia");
            Dispatch_CommandTrace(playerid, command, "resultado", "policia", "handled");
            CommandAI_Record(playerid, command, "policia", "OK", 0, "modulo_respondeu");
            return 1;
        }
        Dispatch_CommandTrace(playerid, command, "modulo", "policia", "miss");
        Dispatch_RunPlayerCommand(playerid, cmdtext, command, "fallback player policia");
        return 1;
    }
    if (strcmp(command, "/ajudaadmin", true) == 0 || strcmp(command, "/ajudaadm", true) == 0 || strcmp(command, "/adminhelp", true) == 0 || strcmp(command, "/comandosadmin", true) == 0)
    {
        Dispatch_DebugTrace(playerid, command, "handler ajudaadmin");
        Dispatch_CommandTrace(playerid, command, "resultado", "admin-help", "handled");
        CommandAI_Record(playerid, command, "admin-help", "OK", 0, "dialog_aberto");
        ShowAdminHelpDialog(playerid);
        return 1;
    }
    if (strcmp(command, "/resetcomandos", true) == 0 || strcmp(command, "/recarregarcomandos", true) == 0 || strcmp(command, "/reloadcomandos", true) == 0)
    {
        Dispatch_DebugTrace(playerid, command, "handler resetcomandos");
        Dispatch_CommandTrace(playerid, command, "resultado", "command-router", "reset");
        CommandAI_Record(playerid, command, "command-router", "OK", 0, "reset_executado");
        Dispatch_ResetCommandRouter(playerid);
        return 1;
    }
    if (strcmp(command, "/debugcomandos", true) == 0 || strcmp(command, "/cmddebug", true) == 0)
    {
        Dispatch_CommandTrace(playerid, command, "resultado", "command-router", "toggle-debug");
        CommandAI_Record(playerid, command, "command-router", "OK", 0, "debug_toggle");
        Dispatch_SetCommandDebug(playerid, !gCommandDebugMode);
        return 1;
    }
    if (Owner_HandlePersistentCommands(playerid, cmdtext))
    {
        Dispatch_DebugTrace(playerid, command, "handler owner");
        Dispatch_CommandTrace(playerid, command, "resultado", "owner-persistent", "handled");
        CommandAI_Record(playerid, command, "owner-persistent", "OK", 0, "comando_persistente");
        return 1;
    }

    Dispatch_CommandTrace(playerid, command, "seguranca", "global", "checking");
    if (!Security_CheckCommand(playerid, cmdtext))
    {
        Dispatch_DebugTrace(playerid, command, "bloqueado security");
        Dispatch_CommandTrace(playerid, command, "seguranca", "global", "blocked");
        CommandAI_Record(playerid, command, "seguranca/global", "BLOCKED", 1, "Security_CheckCommand_retornou_0");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "seguranca", "global", "ok");

    Dispatch_CommandTrace(playerid, command, "modulo", "prioridade", "checking");
    if (DispatchPriorityCommand(playerid, cmdtext, command))
    {
        Dispatch_DebugTrace(playerid, command, "handler prioritario");
        Dispatch_CommandTrace(playerid, command, "resultado", "prioridade", "handled");
        CommandAI_Record(playerid, command, "prioridade", "OK", 0, "rota_prioritaria_respondeu");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "modulo", "prioridade", "miss");

    Dispatch_CommandTrace(playerid, command, "modulo", "player-chain", "checking");
    if (HandlePlayerCommands(playerid, cmdtext))
    {
        Dispatch_DebugTrace(playerid, command, "handler player/admin geral");
        Dispatch_CommandTrace(playerid, command, "resultado", "player-chain", "handled");
        CommandAI_Record(playerid, command, "player-chain", "OK", 0, "cadeia_geral_respondeu");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "modulo", "player-chain", "miss");

    Dispatch_CommandTrace(playerid, command, "modulo", "admin", "checking");
    if (HandleAdminCommands(playerid, cmdtext))
    {
        Dispatch_DebugTrace(playerid, command, "handler admin");
        Dispatch_CommandTrace(playerid, command, "resultado", "admin", "handled");
        CommandAI_Record(playerid, command, "admin", "OK", 0, "cadeia_admin_respondeu");
        return 1;
    }
    Dispatch_CommandTrace(playerid, command, "modulo", "admin", "miss");

    if (command[0] != 0)
    {
        Dispatch_DebugTrace(playerid, command, "nao encontrado");
        Dispatch_CommandTrace(playerid, command, "resultado", "central", "not_found");
        CommandAI_Record(playerid, command, "central", "NOT_FOUND", 2, "nenhum_handler_respondeu");
        Dispatch_AlertUnknownCommand(playerid, command);
        format(message, sizeof(message), "Comando %s nao encontrado na central. Use /ajuda ou /menu para ver os comandos disponiveis.", command);
        SendClientMessage(playerid, COLOR_ORANGE, message);
    }
    return 1;
}
