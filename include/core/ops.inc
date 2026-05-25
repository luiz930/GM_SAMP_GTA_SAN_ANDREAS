#if defined _nova_ops_included
    #endinput
#endif
#define _nova_ops_included

new gMaintenanceMode;
new gWhitelistEnabled;
new gServerStartTick;

stock Ops_CreateFileIfMissing(fileName[], header[])
{
    new File:file;

    if (fexist(fileName))
    {
        return 1;
    }

    file = fopen(fileName, io_write);
    if (!file)
    {
        return 0;
    }

    if (strlen(header) > 0)
    {
        fwrite(file, header);
    }

    fclose(file);
    return 1;
}

stock Ops_LoadConfig()
{
    new File:file;
    new line[96];
    new equalPos;
    new key[32];
    new value[32];

    gMaintenanceMode = 0;
    gWhitelistEnabled = 0;

    if (!fexist(ACCESS_CONFIG_FILE))
    {
        Ops_SaveConfig();
        return 1;
    }

    file = fopen(ACCESS_CONFIG_FILE, io_read);
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

        equalPos = strfind(line, "=", false);
        if (equalPos == -1)
        {
            continue;
        }

        strmid(key, line, 0, equalPos, sizeof(key));
        strmid(value, line, equalPos + 1, strlen(line), sizeof(value));

        if (strcmp(key, "maintenance", false) == 0)
        {
            gMaintenanceMode = strval(value);
        }
        else if (strcmp(key, "whitelist", false) == 0)
        {
            gWhitelistEnabled = strval(value);
        }
    }

    fclose(file);
    return 1;
}

stock Ops_SaveConfig()
{
    new File:file;
    new line[64];

    file = fopen(ACCESS_CONFIG_FILE, io_write);
    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Configuracao de acesso do servidor.\r\n");
    fwrite(file, "# maintenance=1 bloqueia entrada de jogadores comuns.\r\n");
    fwrite(file, "# whitelist=1 permite apenas nomes em whitelist.txt, com staff liberada.\r\n");
    format(line, sizeof(line), "maintenance=%d\r\n", gMaintenanceMode); fwrite(file, line);
    format(line, sizeof(line), "whitelist=%d\r\n", gWhitelistEnabled); fwrite(file, line);
    fclose(file);
    return 1;
}

stock Ops_Init()
{
    gServerStartTick = GetTickCount();
    Ops_LoadConfig();
    Cfg_WriteDefaultFile();
    Ops_CreateFileIfMissing(WHITELIST_FILE, "# Um nick por linha. Staff salva como admin na conta passa mesmo sem whitelist.\r\n");
    Ops_CreateFileIfMissing(ACCOUNT_INDEX_FILE, "# Contas criadas pelo servidor. Um nick por linha.\r\n");
    Ops_CreateFileIfMissing(BUG_REPORT_FILE, "# Relatos de bugs/problemas enviados pelos jogadores.\r\n# Formato: data|player|personagem|x|y|z|interior|virtualworld|mensagem\r\n");
    Ops_CreateFileIfMissing(ACCOUNT_FOLDER_MARKER, "");
    Ops_CreateFileIfMissing(LOG_ADMIN_FILE, "# data|categoria|detalhes\r\n");
    Ops_CreateFileIfMissing(LOG_PUNISH_FILE, "# data|categoria|detalhes\r\n");
    Ops_CreateFileIfMissing(LOG_MONEY_FILE, "# data|categoria|detalhes\r\n");
    Ops_CreateFileIfMissing(LOG_DEATH_FILE, "# data|categoria|detalhes\r\n");
    Ops_CreateFileIfMissing(LOG_BUG_FILE, "# data|categoria|detalhes\r\n");
    Ops_CreateFileIfMissing(LOG_CHAT_FILTER_FILE, "# data|categoria|detalhes\r\n");
    Ops_CreateFileIfMissing(LOG_VIP_FILE, "# data|categoria|detalhes\r\n");
    Ops_CreateFileIfMissing(LOG_CONTRACT_FILE, "# data|categoria|detalhes\r\n");
    Ops_CreateFileIfMissing(LOG_COMMAND_AI_FILE, "# data|categoria|detalhes\r\n");
    Ops_CreateFileIfMissing(RELEASE_PLAN_FILE, "# Trilha oficial rumo a v1.0.0.\r\n# v0.4 dinheiro/banco; v0.5 economia; v0.6 profissoes; v0.7 GovBR; v0.8 servicos publicos; v0.9 beta; v1.0 estavel.\r\n");
    Ops_CreateFileIfMissing(VIP_ORDERS_FILE, "# JSONL gerado pelo painel externo VIP.\r\n");
    Ops_CreateFileIfMissing(VIP_GRANT_MARKER, "");
    Vip_WriteDefaultPlans();
    if (!fexist(JOB_VEHICLES_FILE))
    {
        JobVehicle_WriteDefaultFile();
    }
    if (!fexist(MAP_OBJECTS_FILE))
    {
        MapObj_WriteDefaultFile();
    }
    return 1;
}

stock Ops_CountConfigLines(fileName[])
{
    new File:file;
    new line[256];
    new count;

    if (!fexist(fileName))
    {
        return 0;
    }

    file = fopen(fileName, io_read);
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
        count++;
    }

    fclose(file);
    return count;
}

stock Ops_CountLogMatches(fileName[], needle[])
{
    new File:file;
    new line[256];
    new count;

    if (!fexist(fileName))
    {
        return 0;
    }

    file = fopen(fileName, io_read);
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
        if (strfind(line, needle, true) != -1)
        {
            count++;
        }
    }

    fclose(file);
    return count;
}

stock Ops_ReadLastConfigLine(fileName[], output[], size)
{
    new File:file;
    new line[256];
    new found;

    output[0] = 0;
    if (!fexist(fileName))
    {
        return 0;
    }

    file = fopen(fileName, io_read);
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
        format(output, size, "%s", line);
        found = 1;
    }

    fclose(file);
    return found;
}

stock Ops_IsNameInFile(fileName[], name[])
{
    new File:file;
    new line[MAX_PLAYER_NAME + 8];
    new index;
    new clean[MAX_PLAYER_NAME + 1];

    if (!fexist(fileName))
    {
        return 0;
    }

    file = fopen(fileName, io_read);
    if (!file)
    {
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        index = SkipSpaces(line, 0);
        if (line[index] == 0 || line[index] == '#')
        {
            continue;
        }

        format(clean, sizeof(clean), "%s", line[index]);
        if (strcmp(clean, name, true) == 0)
        {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

stock Ops_AddNameToFile(fileName[], name[])
{
    new File:file;
    new line[MAX_PLAYER_NAME + 4];

    if (Ops_IsNameInFile(fileName, name))
    {
        return 1;
    }

    file = fopen(fileName, io_append);
    if (!file)
    {
        return 0;
    }

    format(line, sizeof(line), "%s\r\n", name);
    fwrite(file, line);
    fclose(file);
    return 1;
}

stock Ops_AddAccountName(playerid)
{
    new name[MAX_PLAYER_NAME + 1];

    GetPlayerNameEx(playerid, name, sizeof(name));
    return Ops_AddNameToFile(ACCOUNT_INDEX_FILE, name);
}

stock Ops_GetAccountAdminLevelByName(name[])
{
    new path[ACCOUNT_PATH_SIZE];
    new line[128];
    new equalPos;
    new key[32];
    new value[32];
    new File:file;

    format(path, sizeof(path), "contas/%s.ini", name);
    if (!fexist(path))
    {
        return 0;
    }

    file = fopen(path, io_read);
    if (!file)
    {
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        equalPos = strfind(line, "=", false);
        if (equalPos == -1)
        {
            continue;
        }

        strmid(key, line, 0, equalPos, sizeof(key));
        if (strcmp(key, "admin", false) == 0)
        {
            strmid(value, line, equalPos + 1, strlen(line), sizeof(value));
            fclose(file);
            return strval(value);
        }
    }

    fclose(file);
    return 0;
}

stock Ops_IsPlayerStaffByAccount(playerid)
{
    new name[MAX_PLAYER_NAME + 1];

    if (IsPlayerAdmin(playerid) || PlayerInfo[playerid][pAdminLevel] >= ADMIN_LEVEL_HELPER)
    {
        return 1;
    }

    GetPlayerNameEx(playerid, name, sizeof(name));
    return (Ops_GetAccountAdminLevelByName(name) >= ADMIN_LEVEL_HELPER);
}

stock Ops_CanPlayerConnect(playerid)
{
    new name[MAX_PLAYER_NAME + 1];
    new details[96];

    GetPlayerNameEx(playerid, name, sizeof(name));

    if (gMaintenanceMode && !Ops_IsPlayerStaffByAccount(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Servidor em manutencao. Apenas staff pode entrar agora.");
        format(details, sizeof(details), "blocked_maintenance player=%s", name);
        WriteServerLog(LOG_ADMIN_FILE, "ACCESS", details);
        Kick(playerid);
        return 0;
    }

    if (gWhitelistEnabled && !Ops_IsPlayerStaffByAccount(playerid) && !Ops_IsNameInFile(WHITELIST_FILE, name))
    {
        SendClientMessage(playerid, COLOR_RED, "Servidor em Alpha fechado. Seu nick nao esta na whitelist.");
        format(details, sizeof(details), "blocked_whitelist player=%s", name);
        WriteServerLog(LOG_ADMIN_FILE, "ACCESS", details);
        Kick(playerid);
        return 0;
    }

    return 1;
}

stock Ops_CountAdminsOnline()
{
    new playerid;
    new count;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && PlayerInfo[playerid][pLogged] && HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
        {
            count++;
        }
    }
    return count;
}

stock Ops_CountActiveVehicles()
{
    new vehicleid;
    new count;
    new pool = GetVehiclePoolSize();

    for (vehicleid = 1; vehicleid <= pool; vehicleid++)
    {
        if (GetVehicleModel(vehicleid) != 0)
        {
            count++;
        }
    }
    return count;
}

stock Ops_FormatUptime(output[], size)
{
    new seconds = (GetTickCount() - gServerStartTick) / 1000;
    new hours;
    new minutes;

    if (seconds < 0)
    {
        seconds = 0;
    }

    hours = seconds / 3600;
    minutes = (seconds % 3600) / 60;
    seconds = seconds % 60;
    format(output, size, "%02d:%02d:%02d", hours, minutes, seconds);
    return 1;
}

stock Ops_AddStatusLine(list[], size, item[], status[], detail[])
{
    new line[220];

    format(line, sizeof(line), "%s\t%s\t%s\n", item, status, detail);
    strcat(list, line, size);
    return 1;
}

stock Ops_AddTimerStatusLine(list[], size, timerid)
{
    new name[16];
    new status[16];
    new detail[128];

    Gm_GetTimerName(timerid, name, sizeof(name));
    if (gGmTimerRuns[timerid] <= 0)
    {
        format(status, sizeof(status), "AGUARDANDO");
    }
    else if (gGmTimerLastMs[timerid] >= GM_TIMER_WARN_MS)
    {
        format(status, sizeof(status), "LENTO");
    }
    else
    {
        format(status, sizeof(status), "OK");
    }

    format(detail, sizeof(detail), "last %dms | max %dms | scan %d | ativo %d | runs %d | lentos %d", gGmTimerLastMs[timerid], gGmTimerMaxMs[timerid], gGmTimerScanned[timerid], gGmTimerActive[timerid], gGmTimerRuns[timerid], gGmTimerSlowRuns[timerid]);
    return Ops_AddStatusLine(list, size, name, status, detail);
}

stock Ops_AddLogStatusLine(list[], size, label[], fileName[])
{
    new status[48];
    new detail[144];
    new lastLine[144];

    format(status, sizeof(status), "%d linha(s)", Ops_CountConfigLines(fileName));
    if (Ops_ReadLastConfigLine(fileName, lastLine, sizeof(lastLine)))
    {
        format(detail, sizeof(detail), "%s", lastLine);
    }
    else
    {
        format(detail, sizeof(detail), "sem registros recentes");
    }
    return Ops_AddStatusLine(list, size, label, status, detail);
}

stock Ops_ShowCheckServer(playerid)
{
    new list[4096];
    new detail[96];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    format(list, sizeof(list), "Item\tStatus\tDetalhe\n");
    Ops_AddStatusLine(list, sizeof(list), SERVER_INFO_FILE, fexist(SERVER_INFO_FILE) ? ("OK") : ("FALTA"), gServerName);
    Ops_AddStatusLine(list, sizeof(list), GAME_CONFIG_FILE, fexist(GAME_CONFIG_FILE) ? ("OK") : ("FALTA"), "precos, XP, fome/sede, impostos");
    Ops_AddStatusLine(list, sizeof(list), BOT_MESSAGES_FILE, fexist(BOT_MESSAGES_FILE) ? ("OK") : ("FALTA"), "avisos automaticos");
    Ops_AddStatusLine(list, sizeof(list), BOT_BADWORDS_FILE, fexist(BOT_BADWORDS_FILE) ? ("OK") : ("FALTA"), "filtro de chat");
    Ops_AddStatusLine(list, sizeof(list), RADIO_PLAYLIST_FILE, fexist(RADIO_PLAYLIST_FILE) ? ("OK") : ("FALTA"), "radios e playlists");
    Ops_AddStatusLine(list, sizeof(list), BUG_REPORT_FILE, fexist(BUG_REPORT_FILE) ? ("OK") : ("FALTA"), "relatos de players");
    Ops_AddStatusLine(list, sizeof(list), BUG_REPORT_UPDATES_FILE, fexist(BUG_REPORT_UPDATES_FILE) ? ("OK") : ("FALTA"), "status/prioridade de bugs");
    Ops_AddStatusLine(list, sizeof(list), BANS_FILE, fexist(BANS_FILE) ? ("OK") : ("FALTA"), "bans salvos");
    Ops_AddStatusLine(list, sizeof(list), SECURITY_ALERT_FILE, fexist(SECURITY_ALERT_FILE) ? ("OK") : ("FALTA"), "alertas anti-cheat/flood");
    Ops_AddStatusLine(list, sizeof(list), RADAR_MANUAL_FILE, fexist(RADAR_MANUAL_FILE) ? ("OK") : ("FALTA"), "radares manuais");
    Ops_AddStatusLine(list, sizeof(list), VIP_PLANS_FILE, fexist(VIP_PLANS_FILE) ? ("OK") : ("FALTA"), "planos VIP");
    Ops_AddStatusLine(list, sizeof(list), VIP_ORDERS_FILE, fexist(VIP_ORDERS_FILE) ? ("OK") : ("FALTA"), "pedidos do painel VIP");
    Ops_AddStatusLine(list, sizeof(list), VIP_GRANT_MARKER, fexist(VIP_GRANT_MARKER) ? ("OK") : ("FALTA"), "pasta vip_grants");
    Ops_AddStatusLine(list, sizeof(list), LOG_VIP_FILE, fexist(LOG_VIP_FILE) ? ("OK") : ("FALTA"), "logs VIP");
    Ops_AddStatusLine(list, sizeof(list), JOB_VEHICLES_FILE, fexist(JOB_VEHICLES_FILE) ? ("OK") : ("FALTA"), "frota das profissoes");
    Ops_AddStatusLine(list, sizeof(list), MAP_OBJECTS_FILE, fexist(MAP_OBJECTS_FILE) ? ("OK") : ("FALTA"), "objetos e portoes do mapa");
    Ops_AddStatusLine(list, sizeof(list), MARKET_STOCK_FILE, fexist(MARKET_STOCK_FILE) ? ("OK") : ("FALTA"), "estoque autonomo de lojas");
    Ops_AddStatusLine(list, sizeof(list), GOVERNMENT_REVENUE_FILE, fexist(GOVERNMENT_REVENUE_FILE) ? ("OK") : ("FALTA"), "arrecadacao publica");
    Ops_AddStatusLine(list, sizeof(list), LOG_CONTRACT_FILE, fexist(LOG_CONTRACT_FILE) ? ("OK") : ("FALTA"), "contratos e cartorio");
    Ops_AddStatusLine(list, sizeof(list), RELEASE_PLAN_FILE, fexist(RELEASE_PLAN_FILE) ? ("OK") : ("FALTA"), "trilha v0.4 ate v1.0");
    Ops_AddStatusLine(list, sizeof(list), LOG_PUNISH_FILE, fexist(LOG_PUNISH_FILE) ? ("OK") : ("FALTA"), "punicoes e bans");
    Ops_AddStatusLine(list, sizeof(list), ACCOUNT_FOLDER_MARKER, fexist(ACCOUNT_FOLDER_MARKER) ? ("OK") : ("AVISO"), "pasta contas");
    Ops_AddStatusLine(list, sizeof(list), BACKUP_STATUS_FILE, fexist(BACKUP_STATUS_FILE) ? ("OK") : ("AVISO"), "ultimo backup");
    Ops_AddStatusLine(list, sizeof(list), WHITELIST_FILE, fexist(WHITELIST_FILE) ? ("OK") : ("FALTA"), gWhitelistEnabled ? ("ativa") : ("desativada"));
    Ops_AddStatusLine(list, sizeof(list), ACCESS_CONFIG_FILE, fexist(ACCESS_CONFIG_FILE) ? ("OK") : ("FALTA"), gMaintenanceMode ? ("manutencao ativa") : ("aberto"));
    format(detail, sizeof(detail), "%s / %s", gServerModeText, gServerVersion);
    Ops_AddStatusLine(list, sizeof(list), "GM versao", "INFO", detail);
    format(detail, sizeof(detail), "%d/%d", CountConnectedPlayers(), GetMaxPlayers());
    Ops_AddStatusLine(list, sizeof(list), "Players online", "INFO", detail);

    ShowPlayerDialog(playerid, DIALOG_SERVER_CHECK, DIALOG_STYLE_TABLIST_HEADERS, "Checkserver - Pre online", list, "Fechar", "");
    return 1;
}

stock Ops_ShowServerStatus(playerid)
{
    new list[4096];
    new detail[96];
    new year;
    new month;
    new day;
    new hour;
    new minute;
    new second;
    new uptime[24];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }

    GetBrasiliaDateTime(year, month, day, hour, minute, second);
    Ops_FormatUptime(uptime, sizeof(uptime));

    format(list, sizeof(list), "Metrica\tValor\tDetalhe\n");
    format(detail, sizeof(detail), "%d/%d", CountConnectedPlayers(), GetMaxPlayers());
    Ops_AddStatusLine(list, sizeof(list), "Players online", detail, "conectados agora");
    format(detail, sizeof(detail), "%d", Ops_CountAdminsOnline());
    Ops_AddStatusLine(list, sizeof(list), "Admins online", detail, "/admins");
    format(detail, sizeof(detail), "%d", Ops_CountConfigLines(BUG_REPORT_FILE));
    Ops_AddStatusLine(list, sizeof(list), "Relatos de bugs", detail, "/bugs");
    format(detail, sizeof(detail), "%d", Ops_CountConfigLines(RADIO_PLAYLIST_FILE));
    Ops_AddStatusLine(list, sizeof(list), "Radios cadastradas", detail, "/radio");
    format(detail, sizeof(detail), "%d", Ops_CountConfigLines(BUG_REPORT_UPDATES_FILE));
    Ops_AddStatusLine(list, sizeof(list), "Triagens de bugs", detail, "/bugprio /bugresolver");
    format(detail, sizeof(detail), "%d", Ops_CountConfigLines(BANS_FILE));
    Ops_AddStatusLine(list, sizeof(list), "Historico de bans", detail, "/banidos");
    format(detail, sizeof(detail), "%d", Ops_CountConfigLines(SECURITY_ALERT_FILE));
    Ops_AddStatusLine(list, sizeof(list), "Alertas seguranca", detail, "/seguranca");
    format(detail, sizeof(detail), "%d", Ops_CountConfigLines(VIP_ORDERS_FILE));
    Ops_AddStatusLine(list, sizeof(list), "Pedidos VIP", detail, "painel externo");
    format(detail, sizeof(detail), "%d", Ops_CountConfigLines(ACCOUNT_INDEX_FILE));
    Ops_AddStatusLine(list, sizeof(list), "Contas criadas", detail, ACCOUNT_INDEX_FILE);
    format(detail, sizeof(detail), "%d", Ops_CountConfigLines(GAME_CONFIG_FILE));
    Ops_AddStatusLine(list, sizeof(list), "Config economia", detail, GAME_CONFIG_FILE);
    format(detail, sizeof(detail), "%d", Ops_CountConfigLines(MARKET_STOCK_FILE));
    Ops_AddStatusLine(list, sizeof(list), "Estoque mercado", detail, MARKET_STOCK_FILE);
    format(detail, sizeof(detail), "$%d | gastos $%d", gGovernmentRevenue, gGovernmentExpense);
    Ops_AddStatusLine(list, sizeof(list), "Cofre publico", detail, GOVERNMENT_REVENUE_FILE);
    format(detail, sizeof(detail), "%d", Ops_CountActiveVehicles());
    Ops_AddStatusLine(list, sizeof(list), "Veiculos ativos", detail, "pool atual");
    format(detail, sizeof(detail), "%d", gRadarCount);
    Ops_AddStatusLine(list, sizeof(list), "Radares ativos", detail, "fixos/manuais/moveis");
    Ops_AddTimerStatusLine(list, sizeof(list), GM_TIMER_HUD);
    Ops_AddTimerStatusLine(list, sizeof(list), GM_TIMER_FUEL);
    Ops_AddTimerStatusLine(list, sizeof(list), GM_TIMER_RADAR);
    format(detail, sizeof(detail), "%d", Work_CountConfigVehicles());
    Ops_AddStatusLine(list, sizeof(list), "Veiculos profissoes", detail, JOB_VEHICLES_FILE);
    format(detail, sizeof(detail), "%d", MapObjects_Count());
    Ops_AddStatusLine(list, sizeof(list), "Objetos/portoes", detail, MAP_OBJECTS_FILE);
    Climate_FormatHud(detail, sizeof(detail));
    Ops_AddStatusLine(list, sizeof(list), "Clima atual", detail, "/clima");
    format(detail, sizeof(detail), "%02d/%02d/%04d %02d:%02d:%02d", day, month, year, hour, minute, second);
    Ops_AddStatusLine(list, sizeof(list), "Horario Brasilia", detail, "HUD/hostname");
    Ops_AddStatusLine(list, sizeof(list), "Uptime", uptime, "desde OnGameModeInit");
    Ops_AddStatusLine(list, sizeof(list), "Manutencao", gMaintenanceMode ? ("ON") : ("OFF"), "/manutencao");
    Ops_AddStatusLine(list, sizeof(list), "Whitelist", gWhitelistEnabled ? ("ON") : ("OFF"), WHITELIST_FILE);

    ShowPlayerDialog(playerid, DIALOG_SERVER_STATUS, DIALOG_STYLE_TABLIST_HEADERS, "Status do servidor", list, "Fechar", "");
    return 1;
}

stock Ops_ShowPerfPanel(playerid)
{
    new list[2200];
    new detail[128];
    new pendingSaves;
    new pid;
    new maxPlayers = GetMaxPlayers();

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }
    Gm_MarkReleaseChecklist(RELCHK_PERF);

    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (IsPlayerConnected(pid) && PlayerInfo[pid][pLogged] && gAccountSaveDirty[pid])
        {
            pendingSaves++;
        }
    }

    format(list, sizeof(list), "Timer\tStatus\tDetalhe\n");
    Ops_AddTimerStatusLine(list, sizeof(list), GM_TIMER_HUD);
    Ops_AddTimerStatusLine(list, sizeof(list), GM_TIMER_FUEL);
    Ops_AddTimerStatusLine(list, sizeof(list), GM_TIMER_RADAR);
    format(detail, sizeof(detail), "%d/%d", CountConnectedPlayers(), GetMaxPlayers());
    Ops_AddStatusLine(list, sizeof(list), "Players", detail, "base de varredura dos timers");
    format(detail, sizeof(detail), "%d", Ops_CountActiveVehicles());
    Ops_AddStatusLine(list, sizeof(list), "Veiculos ativos", detail, "pool atual");
    format(detail, sizeof(detail), "%d", gRadarCount);
    Ops_AddStatusLine(list, sizeof(list), "Radares", detail, "Radar_UpdateAll ignora ciclo sem radar");
    format(detail, sizeof(detail), "%d", pendingSaves);
    Ops_AddStatusLine(list, sizeof(list), "Saves pendentes", detail, "fila dirty/autosave");
    format(detail, sizeof(detail), "%d", Gm_CountTimerRisks());
    Ops_AddStatusLine(list, sizeof(list), "Risco timers", detail, "sem run ou acima de 60ms");

    ShowPlayerDialog(playerid, DIALOG_SERVER_STATUS, DIALOG_STYLE_TABLIST_HEADERS, "Performance da GM", list, "Fechar", "");
    return 1;
}

stock Ops_ShowLogsPanel(playerid)
{
    new list[3600];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }
    Gm_MarkReleaseChecklist(RELCHK_LOGS);

    format(list, sizeof(list), "Log\tVolume\tUltimo registro\n");
    Ops_AddLogStatusLine(list, sizeof(list), "Admin/staff", LOG_ADMIN_FILE);
    Ops_AddLogStatusLine(list, sizeof(list), "Dinheiro/banco", LOG_MONEY_FILE);
    Ops_AddLogStatusLine(list, sizeof(list), "Punicoes/justica", LOG_PUNISH_FILE);
    Ops_AddLogStatusLine(list, sizeof(list), "Contratos/empresas", LOG_CONTRACT_FILE);
    Ops_AddLogStatusLine(list, sizeof(list), "Seguranca", SECURITY_ALERT_FILE);
    Ops_AddLogStatusLine(list, sizeof(list), "IA comandos", LOG_COMMAND_AI_FILE);
    Ops_AddLogStatusLine(list, sizeof(list), "Bugs", LOG_BUG_FILE);
    Ops_AddLogStatusLine(list, sizeof(list), "VIP", LOG_VIP_FILE);
    Ops_AddStatusLine(list, sizeof(list), "Acoes", "/antiabuso /perf", "use /debugplayer [id] antes de intervir");

    ShowPlayerDialog(playerid, DIALOG_SERVER_STATUS, DIALOG_STYLE_TABLIST_HEADERS, "Logs recentes da GM", list, "Fechar", "");
    return 1;
}

stock Ops_ShowEconomyHealth(playerid)
{
    new list[2048];
    new detail[96];
    new pid;
    new maxPlayers = GetMaxPlayers();
    new logged;
    new dirtyNames;
    new debtPlayers;
    new companies;
    new financedVehicles;
    new totalBills;
    new totalLoans;
    new totalBank;
    new missionsDone;
    new businessOrders;
    new openCases;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }

    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged])
        {
            continue;
        }

        logged++;
        Life_ApplyLateFees(pid, 0);
        Life_GetBankScore(pid);
        totalBills += Life_BillTotal(pid);
        totalLoans += PlayerInfo[pid][pBankLoan];
        totalBank += PlayerInfo[pid][pBankMoney];
        if (PlayerInfo[pid][pDirtyName]) dirtyNames++;
        if (Life_IsDebtBlocked(pid)) debtPlayers++;
        if (PlayerInfo[pid][pBusinessType] != LIFE_BUSINESS_NONE) companies++;
        if (PlayerInfo[pid][pBankLoan] > 0 || PlayerInfo[pid][pContractFinancing]) financedVehicles++;
        if (PlayerInfo[pid][pMissionRewarded]) missionsDone++;
        businessOrders += PlayerInfo[pid][pBusinessOrders];
        if (PlayerInfo[pid][pJusticeStatus] == JUSTICE_STATUS_OPEN || PlayerInfo[pid][pJusticeStatus] == JUSTICE_STATUS_INVESTIGATING || PlayerInfo[pid][pJusticeStatus] == JUSTICE_STATUS_HEARING) openCases++;
    }

    format(list, sizeof(list), "Indicador\tValor\tDetalhe\n");
    format(detail, sizeof(detail), "%d", logged);
    Ops_AddStatusLine(list, sizeof(list), "Players logados", detail, "amostra online");
    format(detail, sizeof(detail), "%d", Ops_CountConfigLines(ACCOUNT_INDEX_FILE));
    Ops_AddStatusLine(list, sizeof(list), "Contas totais", detail, ACCOUNT_INDEX_FILE);
    format(detail, sizeof(detail), "%d", dirtyNames);
    Ops_AddStatusLine(list, sizeof(list), "Nomes restritos", detail, "SPC/Serasa online");
    format(detail, sizeof(detail), "%d", debtPlayers);
    Ops_AddStatusLine(list, sizeof(list), "Bloqueados por divida", detail, "/boletos");
    format(detail, sizeof(detail), "$%d", totalBills);
    Ops_AddStatusLine(list, sizeof(list), "Boletos e multas online", detail, "inclui sentencas");
    format(detail, sizeof(detail), "$%d", totalLoans);
    Ops_AddStatusLine(list, sizeof(list), "Emprestimos ativos online", detail, "banco");
    format(detail, sizeof(detail), "$%d", totalBank);
    Ops_AddStatusLine(list, sizeof(list), "Saldo bancario online", detail, "contas logadas");
    format(detail, sizeof(detail), "%d", companies);
    Ops_AddStatusLine(list, sizeof(list), "Empresas ativas online", detail, "/empresa");
    format(detail, sizeof(detail), "%d", financedVehicles);
    Ops_AddStatusLine(list, sizeof(list), "Financiamentos online", detail, "emprestimo/contrato");
    format(detail, sizeof(detail), "%d", missionsDone);
    Ops_AddStatusLine(list, sizeof(list), "Missoes diarias completas", detail, "/missoes");
    format(detail, sizeof(detail), "%d", businessOrders);
    Ops_AddStatusLine(list, sizeof(list), "Pedidos empresariais", detail, "/empresa");
    format(detail, sizeof(detail), "%d", openCases);
    Ops_AddStatusLine(list, sizeof(list), "Casos abertos", detail, "/casos");
    format(detail, sizeof(detail), "$%d | gastos $%d", gGovernmentRevenue, gGovernmentExpense);
    Ops_AddStatusLine(list, sizeof(list), "Cofre publico", detail, GOVERNMENT_REVENUE_FILE);
    Ops_AddStatusLine(list, sizeof(list), "Log contratos", fexist(LOG_CONTRACT_FILE) ? ("OK") : ("FALTA"), LOG_CONTRACT_FILE);
    Ops_AddStatusLine(list, sizeof(list), "Log dinheiro", fexist(LOG_MONEY_FILE) ? ("OK") : ("FALTA"), LOG_MONEY_FILE);

    ShowPlayerDialog(playerid, DIALOG_SERVER_STATUS, DIALOG_STYLE_TABLIST_HEADERS, "Saude da economia", list, "Fechar", "");
    return 1;
}

stock Ops_AddEconomyAlert(list[], size, severity[], item[], value[], expected[])
{
    new line[192];

    format(line, sizeof(line), "%s\t%s\t%s\t%s\n", severity, item, value, expected);
    strcat(list, line, size);
    return 1;
}

stock Ops_CountEconomyAlerts()
{
    new count;
    new index;
    new jobid;
    new pay;
    new bonus;
    new price;
    new rent;

    if (gCfgStartingMoney < 250 || gCfgStartingMoney > 2500) count++;
    if (gCfgPricePercent < 50 || gCfgPricePercent > 150) count++;
    if (gCfgVehiclePricePercent < 50 || gCfgVehiclePricePercent > 150) count++;
    if (gCfgPropertyPricePercent < 50 || gCfgPropertyPricePercent > 150) count++;
    if (gCfgJobPayPercent < 60 || gCfgJobPayPercent > 150) count++;
    if (gCfgJobBonusPercent < 0 || gCfgJobBonusPercent > 150) count++;
    if (gCfgFuelGasolinePrice < 4 || gCfgFuelGasolinePrice > 10) count++;
    if (gCfgFuelEthanolPrice < 2 || gCfgFuelEthanolPrice > 8) count++;
    if (gCfgFuelDieselPrice < 4 || gCfgFuelDieselPrice > 11) count++;
    if (gCfgFuelGlpPrice < 70 || gCfgFuelGlpPrice > 170) count++;
    if (gCfgTrafficFineLight != 88 || gCfgTrafficFineMedium != 130 || gCfgTrafficFineSerious != 195 || gCfgTrafficFineVerySerious != 293) count++;
    if (gCfgVehicleIpvaPercent < 2 || gCfgVehicleIpvaPercent > 5) count++;
    if (gCfgHospitalPlanCost > 1800 || gCfgHospitalPlanCost < 300) count++;
    if (gCfgBusinessOpenCost > 6000 || gCfgBusinessOpenCost < 500) count++;

    for (index = 0; index < sizeof(gJobs); index++)
    {
        jobid = gJobs[index][jobId];
        pay = Cfg_GetJobPay(jobid, gJobs[index][jobPay]);
        bonus = Cfg_GetJobBonus(jobid, gJobs[index][jobBonus]);
        if (pay < 250 || pay > 1600) count++;
        if (Job_IsPublicServant(jobid) && bonus > 0) count++;
        if (!Job_IsPublicServant(jobid) && bonus > 2500) count++;
    }

    for (index = 0; index < sizeof(gDealerVehicles); index++)
    {
        price = Cfg_VehiclePrice(gDealerVehicles[index][dealerPrice]);
        if (price < 1500 || price > 150000) count++;
    }

    for (index = 0; index < sizeof(gProperties); index++)
    {
        price = Property_GetMarketPrice(index + 1);
        rent = Property_GetMarketRent(index + 1);
        if (price < 20000 || price > 250000) count++;
        if (rent < 500 || rent > 6000) count++;
        if (rent > 0 && price / rent < 12) count++;
    }

    for (index = 0; index < sizeof(gSupermarketProducts); index++)
    {
        price = Cfg_Price(gSupermarketProducts[index][marketProductBasePrice]);
        if (price < 30 || price > 250) count++;
    }
    return count;
}

stock Ops_ShowEconomyAlerts(playerid)
{
    new list[4096];
    new value[48];
    new item[80];
    new index;
    new jobid;
    new pay;
    new bonus;
    new price;
    new rent;
    new alerts;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }

    format(list, sizeof(list), "Nivel\tItem\tValor atual\tFaixa saudavel\n");

    if (gCfgStartingMoney < 250 || gCfgStartingMoney > 2500)
    {
        format(value, sizeof(value), "$%d", gCfgStartingMoney);
        Ops_AddEconomyAlert(list, sizeof(list), "ALERTA", "Dinheiro inicial", value, "$250 a $2500");
        alerts++;
    }
    if (gCfgPricePercent < 50 || gCfgPricePercent > 150)
    {
        format(value, sizeof(value), "%d%%", gCfgPricePercent);
        Ops_AddEconomyAlert(list, sizeof(list), "ALERTA", "Multiplicador geral", value, "50% a 150%");
        alerts++;
    }
    if (gCfgFuelGasolinePrice < 4 || gCfgFuelGasolinePrice > 10)
    {
        format(value, sizeof(value), "$%d", gCfgFuelGasolinePrice);
        Ops_AddEconomyAlert(list, sizeof(list), "ALERTA", "Gasolina", value, "$4 a $10");
        alerts++;
    }
    if (gCfgFuelEthanolPrice < 2 || gCfgFuelEthanolPrice > 8)
    {
        format(value, sizeof(value), "$%d", gCfgFuelEthanolPrice);
        Ops_AddEconomyAlert(list, sizeof(list), "ALERTA", "Alcool/etanol", value, "$2 a $8");
        alerts++;
    }
    if (gCfgFuelDieselPrice < 4 || gCfgFuelDieselPrice > 11)
    {
        format(value, sizeof(value), "$%d", gCfgFuelDieselPrice);
        Ops_AddEconomyAlert(list, sizeof(list), "ALERTA", "Diesel", value, "$4 a $11");
        alerts++;
    }
    if (gCfgFuelGlpPrice < 70 || gCfgFuelGlpPrice > 170)
    {
        format(value, sizeof(value), "$%d", gCfgFuelGlpPrice);
        Ops_AddEconomyAlert(list, sizeof(list), "ALERTA", "GLP botijao", value, "$70 a $170");
        alerts++;
    }
    if (gCfgTrafficFineLight != 88 || gCfgTrafficFineMedium != 130 || gCfgTrafficFineSerious != 195 || gCfgTrafficFineVerySerious != 293)
    {
        format(value, sizeof(value), "$%d/%d/%d/%d", gCfgTrafficFineLight, gCfgTrafficFineMedium, gCfgTrafficFineSerious, gCfgTrafficFineVerySerious);
        Ops_AddEconomyAlert(list, sizeof(list), "AVISO", "Multas CTB", value, "88/130/195/293");
        alerts++;
    }
    if (gCfgVehicleIpvaPercent < 2 || gCfgVehicleIpvaPercent > 5)
    {
        format(value, sizeof(value), "%d%%", gCfgVehicleIpvaPercent);
        Ops_AddEconomyAlert(list, sizeof(list), "ALERTA", "IPVA carro", value, "2% a 5%");
        alerts++;
    }
    if (gCfgHospitalPlanCost > 1800 || gCfgHospitalPlanCost < 300)
    {
        format(value, sizeof(value), "$%d", Cfg_Price(gCfgHospitalPlanCost));
        Ops_AddEconomyAlert(list, sizeof(list), "ALERTA", "Plano de saude", value, "$300 a $1800");
        alerts++;
    }
    if (gCfgBusinessOpenCost > 6000 || gCfgBusinessOpenCost < 500)
    {
        format(value, sizeof(value), "$%d", Cfg_Price(gCfgBusinessOpenCost));
        Ops_AddEconomyAlert(list, sizeof(list), "ALERTA", "Abrir empresa", value, "$500 a $6000");
        alerts++;
    }

    for (index = 0; index < sizeof(gJobs); index++)
    {
        jobid = gJobs[index][jobId];
        pay = Cfg_GetJobPay(jobid, gJobs[index][jobPay]);
        bonus = Cfg_GetJobBonus(jobid, gJobs[index][jobBonus]);
        if (pay < 250 || pay > 1600)
        {
            format(item, sizeof(item), "Salario %s", gJobs[index][jobName]);
            format(value, sizeof(value), "$%d", pay);
            Ops_AddEconomyAlert(list, sizeof(list), "ALERTA", item, value, "$250 a $1600/tarefa");
            alerts++;
        }
        if (Job_IsPublicServant(jobid) && bonus > 0)
        {
            format(item, sizeof(item), "Bonus publico %s", gJobs[index][jobName]);
            format(value, sizeof(value), "$%d", bonus);
            Ops_AddEconomyAlert(list, sizeof(list), "AVISO", item, value, "deve ser $0");
            alerts++;
        }
        if (!Job_IsPublicServant(jobid) && bonus > 2500)
        {
            format(item, sizeof(item), "Bonus privado %s", gJobs[index][jobName]);
            format(value, sizeof(value), "$%d", bonus);
            Ops_AddEconomyAlert(list, sizeof(list), "ALERTA", item, value, "ate $2500");
            alerts++;
        }
    }

    for (index = 0; index < sizeof(gDealerVehicles); index++)
    {
        price = Cfg_VehiclePrice(gDealerVehicles[index][dealerPrice]);
        if (price < 1500 || price > 150000)
        {
            format(item, sizeof(item), "Veiculo %s", gDealerVehicles[index][dealerName]);
            format(value, sizeof(value), "$%d", price);
            Ops_AddEconomyAlert(list, sizeof(list), "ALERTA", item, value, "$1500 a $150000");
            alerts++;
        }
    }

    for (index = 0; index < sizeof(gProperties); index++)
    {
        price = Property_GetMarketPrice(index + 1);
        rent = Property_GetMarketRent(index + 1);
        if (price < 20000 || price > 250000)
        {
            format(item, sizeof(item), "Imovel %s", gProperties[index][propName]);
            format(value, sizeof(value), "$%d", price);
            Ops_AddEconomyAlert(list, sizeof(list), "ALERTA", item, value, "$20000 a $250000");
            alerts++;
        }
        if (rent < 500 || rent > 6000)
        {
            format(item, sizeof(item), "Aluguel %s", gProperties[index][propName]);
            format(value, sizeof(value), "$%d", rent);
            Ops_AddEconomyAlert(list, sizeof(list), "ALERTA", item, value, "$500 a $6000");
            alerts++;
        }
        if (rent > 0 && price / rent < 12)
        {
            format(item, sizeof(item), "Compra/aluguel %s", gProperties[index][propName]);
            format(value, sizeof(value), "%dx", price / rent);
            Ops_AddEconomyAlert(list, sizeof(list), "AVISO", item, value, ">= 12x aluguel");
            alerts++;
        }
    }

    for (index = 0; index < sizeof(gSupermarketProducts); index++)
    {
        price = Cfg_Price(gSupermarketProducts[index][marketProductBasePrice]);
        if (price < 30 || price > 250)
        {
            format(item, sizeof(item), "Mercado %s", gSupermarketProducts[index][marketProductName]);
            format(value, sizeof(value), "$%d", price);
            Ops_AddEconomyAlert(list, sizeof(list), "ALERTA", item, value, "$30 a $250");
            alerts++;
        }
    }

    if (alerts <= 0)
    {
        Ops_AddEconomyAlert(list, sizeof(list), "OK", "Economia base", "sem alertas", "faixas saudaveis");
    }

    ShowPlayerDialog(playerid, DIALOG_SERVER_STATUS, DIALOG_STYLE_TABLIST_HEADERS, "Alertas de economia quebrada", list, "Fechar", "");
    return 1;
}

stock Ops_ShowStaffPanel(playerid)
{
    new list[2200];
    new detail[160];
    new eventText[128];
    new warText[128];
    new pid;
    new maxPlayers = GetMaxPlayers();
    new name[MAX_PLAYER_NAME + 1];
    new debt;
    new topDebt;
    new topDebtId = INVALID_PLAYER_ID;
    new companiesIdle;
    new companiesBankrupt;
    new openCases;
    new totalOrders;
    new suspiciousFarm;
    new economyAlerts;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }
    Gm_MarkReleaseChecklist(RELCHK_STAFF);

    Life_FormatCityEvent(eventText, sizeof(eventText));
    Life_FormatWarZoneStatus(warText, sizeof(warText));
    economyAlerts = Ops_CountEconomyAlerts();

    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged])
        {
            continue;
        }

        debt = Life_BillTotal(pid);
        if (debt > topDebt)
        {
            topDebt = debt;
            topDebtId = pid;
        }
        if (PlayerInfo[pid][pBusinessType] != LIFE_BUSINESS_NONE)
        {
            totalOrders += PlayerInfo[pid][pBusinessOrders];
            if (PlayerInfo[pid][pBusinessOrders] >= 6 || PlayerInfo[pid][pBusinessBalance] <= 0)
            {
                companiesIdle++;
            }
            if (PlayerInfo[pid][pBusinessBankrupt] || PlayerInfo[pid][pBusinessDebt] >= 5000)
            {
                companiesBankrupt++;
            }
        }
        if (Life_HasOpenJusticeRisk(pid))
        {
            openCases++;
        }
        if (gLifeMoneyGainToday[pid] >= LIFE_ANTI_ABUSE_MONEY_DAY / 2 || gLifeXpGainToday[pid] >= LIFE_ANTI_ABUSE_XP_DAY / 2)
        {
            suspiciousFarm++;
        }
    }

    format(list, sizeof(list), "Area\tValor\tDetalhe\n");
    Ops_AddStatusLine(list, sizeof(list), "Evento da cidade", eventText, "/eventos");
    Ops_AddStatusLine(list, sizeof(list), "Zona de guerra", warText, "/zonaguerra");
    if (topDebtId != INVALID_PLAYER_ID)
    {
        GetPlayerNameEx(topDebtId, name, sizeof(name));
        format(detail, sizeof(detail), "%s ID %d", name, topDebtId);
        Ops_AddStatusLine(list, sizeof(list), "Maior devedor online", detail, "$ pendente");
    }
    else
    {
        Ops_AddStatusLine(list, sizeof(list), "Maior devedor online", "nenhum", "sem players logados");
    }
    format(detail, sizeof(detail), "$%d", topDebt);
    Ops_AddStatusLine(list, sizeof(list), "Valor maior divida", detail, "boletos/multas/sentencas");
    format(detail, sizeof(detail), "%d", companiesIdle);
    Ops_AddStatusLine(list, sizeof(list), "Empresas paradas", detail, "pedidos altos ou caixa zerado");
    format(detail, sizeof(detail), "%d", companiesBankrupt);
    Ops_AddStatusLine(list, sizeof(list), "Empresas quebradas/divida", detail, "falencia ou divida >= 5000");
    format(detail, sizeof(detail), "%d", totalOrders);
    Ops_AddStatusLine(list, sizeof(list), "Pedidos empresariais", detail, "cadeia produtiva");
    format(detail, sizeof(detail), "%d", openCases);
    Ops_AddStatusLine(list, sizeof(list), "Casos judiciais abertos", detail, "/casos");
    format(detail, sizeof(detail), "%d", Ops_CountConfigLines(BUG_REPORT_FILE));
    Ops_AddStatusLine(list, sizeof(list), "Denuncias/bugs abertos", detail, "/bugs");
    format(detail, sizeof(detail), "%d", Ops_CountConfigLines(SECURITY_ALERT_FILE));
    Ops_AddStatusLine(list, sizeof(list), "Alertas de abuso", detail, "/seguranca");
    format(detail, sizeof(detail), "%d", Gm_CountTimerRisks());
    Ops_AddStatusLine(list, sizeof(list), "Risco performance", detail, "/perf");
    format(detail, sizeof(detail), "%d", suspiciousFarm);
    Ops_AddStatusLine(list, sizeof(list), "Farm suspeito online", detail, "/debugplayer [id]");
    format(detail, sizeof(detail), "%d", economyAlerts);
    Ops_AddStatusLine(list, sizeof(list), "Economia quebrada", detail, "/alertaeconomia");
    format(detail, sizeof(detail), "%d", Ops_CountConfigLines(LOG_PUNISH_FILE));
    Ops_AddStatusLine(list, sizeof(list), "Historico punicoes", detail, LOG_PUNISH_FILE);
    Ops_AddLogStatusLine(list, sizeof(list), "Ultimo dinheiro", LOG_MONEY_FILE);
    Ops_AddLogStatusLine(list, sizeof(list), "Ultimo contrato", LOG_CONTRACT_FILE);
    Ops_AddLogStatusLine(list, sizeof(list), "Ultima punicao", LOG_PUNISH_FILE);
    Ops_AddStatusLine(list, sizeof(list), "Acoes rapidas", "/goto /avisar /congelar", "use /debugplayer e /logsstaff antes de agir");

    ShowPlayerDialog(playerid, DIALOG_SERVER_STATUS, DIALOG_STYLE_TABLIST_HEADERS, "Painel staff - operacao", list, "Fechar", "");
    return 1;
}

stock Ops_ShowAntiAbusePanel(playerid)
{
    new list[3400];
    new detail[160];
    new name[MAX_PLAYER_NAME + 1];
    new lastLog[144];
    new pid;
    new maxPlayers = GetMaxPlayers();
    new topMoneyId = INVALID_PLAYER_ID;
    new topXpId = INVALID_PLAYER_ID;
    new topDebtId = INVALID_PLAYER_ID;
    new topContractId = INVALID_PLAYER_ID;
    new topMoney;
    new topXp;
    new topDebt;
    new topContracts;
    new pendingSaves;
    new highDebtPlayers;
    new contractRisk;
    new farmRisk;
    new moneyLogs;
    new deniedPayments;
    new jobLogs;
    new contractLogs;
    new securityLogs;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }
    Gm_MarkReleaseChecklist(RELCHK_ANTIABUSE);

    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged])
        {
            continue;
        }

        if (gLifeMoneyGainToday[pid] > topMoney)
        {
            topMoney = gLifeMoneyGainToday[pid];
            topMoneyId = pid;
        }
        if (gLifeXpGainToday[pid] > topXp)
        {
            topXp = gLifeXpGainToday[pid];
            topXpId = pid;
        }
        if (Life_BillTotal(pid) > topDebt)
        {
            topDebt = Life_BillTotal(pid);
            topDebtId = pid;
        }
        if (PlayerInfo[pid][pContractsToday] > topContracts)
        {
            topContracts = PlayerInfo[pid][pContractsToday];
            topContractId = pid;
        }
        if (gAccountSaveDirty[pid])
        {
            pendingSaves++;
        }
        if (Life_BillTotal(pid) >= 5000 || PlayerInfo[pid][pFines] >= 3000 || PlayerInfo[pid][pBankLoan] >= 10000)
        {
            highDebtPlayers++;
        }
        if (PlayerInfo[pid][pContractsToday] >= LIFE_CONTRACTS_DAILY_LIMIT || PlayerInfo[pid][pBusinessContracts] >= 15)
        {
            contractRisk++;
        }
        if (gLifeMoneyGainToday[pid] >= LIFE_ANTI_ABUSE_MONEY_DAY / 2 || gLifeXpGainToday[pid] >= LIFE_ANTI_ABUSE_XP_DAY / 2)
        {
            farmRisk++;
        }
    }

    format(list, sizeof(list), "Indicador\tValor\tAcao\n");
    if (topMoneyId != INVALID_PLAYER_ID)
    {
        GetPlayerNameEx(topMoneyId, name, sizeof(name));
        format(detail, sizeof(detail), "%s ID %d | $%d", name, topMoneyId, topMoney);
        Ops_AddStatusLine(list, sizeof(list), "Top dinheiro sessao", detail, "/debugplayer id");
    }
    else
    {
        Ops_AddStatusLine(list, sizeof(list), "Top dinheiro sessao", "nenhum", "sem logados");
    }

    if (topXpId != INVALID_PLAYER_ID)
    {
        GetPlayerNameEx(topXpId, name, sizeof(name));
        format(detail, sizeof(detail), "%s ID %d | XP %d", name, topXpId, topXp);
        Ops_AddStatusLine(list, sizeof(list), "Top XP sessao", detail, "/debugplayer id");
    }
    else
    {
        Ops_AddStatusLine(list, sizeof(list), "Top XP sessao", "nenhum", "sem logados");
    }

    if (topContractId != INVALID_PLAYER_ID)
    {
        GetPlayerNameEx(topContractId, name, sizeof(name));
        format(detail, sizeof(detail), "%s ID %d | %d/%d hoje", name, topContractId, topContracts, LIFE_CONTRACTS_DAILY_LIMIT);
        Ops_AddStatusLine(list, sizeof(list), "Contratos suspeitos", detail, "/debugplayer id");
    }
    else
    {
        Ops_AddStatusLine(list, sizeof(list), "Contratos suspeitos", "nenhum", "sem contratos");
    }

    if (topDebtId != INVALID_PLAYER_ID)
    {
        GetPlayerNameEx(topDebtId, name, sizeof(name));
        format(detail, sizeof(detail), "%s ID %d | $%d", name, topDebtId, topDebt);
        Ops_AddStatusLine(list, sizeof(list), "Maior divida", detail, "/debugplayer id");
    }
    else
    {
        Ops_AddStatusLine(list, sizeof(list), "Maior divida", "nenhum", "sem logados");
    }

    format(detail, sizeof(detail), "%d player(s)", farmRisk);
    Ops_AddStatusLine(list, sizeof(list), "Risco farm dinheiro/XP", detail, "ganho alto na sessao");
    format(detail, sizeof(detail), "%d player(s)", contractRisk);
    Ops_AddStatusLine(list, sizeof(list), "Risco contratos/empresa", detail, "limite ou volume alto");
    format(detail, sizeof(detail), "%d player(s)", highDebtPlayers);
    Ops_AddStatusLine(list, sizeof(list), "Divida alta", detail, "boletos, multas ou emprestimo");
    format(detail, sizeof(detail), "%d conta(s)", pendingSaves);
    Ops_AddStatusLine(list, sizeof(list), "Save pendente", detail, "fila dirty aguardando autosave");

    moneyLogs = Ops_CountLogMatches(LOG_MONEY_FILE, "reason=");
    deniedPayments = Ops_CountLogMatches(LOG_MONEY_FILE, "payment_denied");
    jobLogs = Ops_CountLogMatches(LOG_MONEY_FILE, "job_");
    contractLogs = Ops_CountConfigLines(LOG_CONTRACT_FILE);
    securityLogs = Ops_CountConfigLines(SECURITY_ALERT_FILE);

    format(detail, sizeof(detail), "%d registro(s)", moneyLogs);
    Ops_AddStatusLine(list, sizeof(list), "Historico dinheiro", detail, "linhas com reason=");
    format(detail, sizeof(detail), "%d negado(s)", deniedPayments);
    Ops_AddStatusLine(list, sizeof(list), "Pagamentos bloqueados", detail, LOG_MONEY_FILE);
    format(detail, sizeof(detail), "%d job payout(s)", jobLogs);
    Ops_AddStatusLine(list, sizeof(list), "Pagamentos profissao", detail, "JOB_REWARD/job_route/job_service");
    format(detail, sizeof(detail), "%d linha(s)", contractLogs);
    Ops_AddStatusLine(list, sizeof(list), "Historico contratos", detail, LOG_CONTRACT_FILE);
    format(detail, sizeof(detail), "%d alerta(s)", securityLogs);
    Ops_AddStatusLine(list, sizeof(list), "Historico seguranca", detail, SECURITY_ALERT_FILE);
    if (Ops_ReadLastConfigLine(SECURITY_ALERT_FILE, lastLog, sizeof(lastLog)))
    {
        Ops_AddStatusLine(list, sizeof(list), "Ultimo alerta", lastLog, "/seguranca");
    }
    else
    {
        Ops_AddStatusLine(list, sizeof(list), "Ultimo alerta", "nenhum", SECURITY_ALERT_FILE);
    }
    Ops_AddLogStatusLine(list, sizeof(list), "Ultimo dinheiro", LOG_MONEY_FILE);
    Ops_AddLogStatusLine(list, sizeof(list), "Ultimo contrato", LOG_CONTRACT_FILE);
    Ops_AddLogStatusLine(list, sizeof(list), "Ultima punicao", LOG_PUNISH_FILE);
    Ops_AddStatusLine(list, sizeof(list), "Acoes rapidas", "/debugplayer /goto /avisar /congelar", "investigar antes de punir");

    ShowPlayerDialog(playerid, DIALOG_SERVER_STATUS, DIALOG_STYLE_TABLIST_HEADERS, "Painel anti-abuso", list, "Fechar", "");
    return 1;
}

stock Ops_KickRestrictedPlayers(checkWhitelist)
{
    new playerid;
    new name[MAX_PLAYER_NAME + 1];
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (!IsPlayerConnected(playerid) || Ops_IsPlayerStaffByAccount(playerid))
        {
            continue;
        }

        GetPlayerNameEx(playerid, name, sizeof(name));
        if (!checkWhitelist || !Ops_IsNameInFile(WHITELIST_FILE, name))
        {
            SendClientMessage(playerid, COLOR_RED, "Servidor entrou em modo restrito. Voce foi desconectado.");
            Kick(playerid);
        }
    }
    return 1;
}

stock Ops_SetMaintenance(playerid, enabled)
{
    new name[MAX_PLAYER_NAME + 1];
    new message[128];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    gMaintenanceMode = enabled ? 1 : 0;
    Ops_SaveConfig();
    GetPlayerNameEx(playerid, name, sizeof(name));
    format(message, sizeof(message), "[ADMIN] %s %s modo manutencao.", name, gMaintenanceMode ? ("ativou") : ("desativou"));
    SendClientMessageToAll(COLOR_ADMIN, message);
    WriteServerLog(LOG_ADMIN_FILE, "MAINTENANCE", message);

    if (gMaintenanceMode)
    {
        Ops_KickRestrictedPlayers(0);
    }
    return 1;
}

stock Ops_ShowWhitelistDialog(playerid)
{
    new File:file;
    new line[64];
    new body[2048];
    new count;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    format(body, sizeof(body), "Whitelist: %s\n\n", gWhitelistEnabled ? ("ON") : ("OFF"));

    if (!fexist(WHITELIST_FILE))
    {
        strcat(body, "Arquivo whitelist.txt nao encontrado.", sizeof(body));
        ShowPlayerDialog(playerid, DIALOG_WHITELIST_LIST, DIALOG_STYLE_MSGBOX, "Whitelist", body, "Fechar", "");
        return 1;
    }

    file = fopen(WHITELIST_FILE, io_read);
    if (!file)
    {
        strcat(body, "Nao foi possivel abrir whitelist.txt.", sizeof(body));
        ShowPlayerDialog(playerid, DIALOG_WHITELIST_LIST, DIALOG_STYLE_MSGBOX, "Whitelist", body, "Fechar", "");
        return 1;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (line[0] == 0 || line[0] == '#')
        {
            continue;
        }

        if (strlen(body) < 1900)
        {
            strcat(body, line, sizeof(body));
            strcat(body, "\n", sizeof(body));
        }
        count++;
    }

    fclose(file);

    if (count <= 0)
    {
        strcat(body, "Nenhum jogador cadastrado.", sizeof(body));
    }

    ShowPlayerDialog(playerid, DIALOG_WHITELIST_LIST, DIALOG_STYLE_MSGBOX, "Whitelist", body, "Fechar", "");
    return 1;
}

stock Ops_RewriteWhitelist(names[][MAX_PLAYER_NAME + 1], count)
{
    new File:file;
    new index;
    new line[MAX_PLAYER_NAME + 4];

    file = fopen(WHITELIST_FILE, io_write);
    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Um nick por linha. Staff salva como admin na conta passa mesmo sem whitelist.\r\n");
    for (index = 0; index < count; index++)
    {
        format(line, sizeof(line), "%s\r\n", names[index]);
        fwrite(file, line);
    }

    fclose(file);
    return 1;
}

stock Ops_RemoveWhitelistName(name[])
{
    new names[OPS_MAX_WHITELIST_CACHE][MAX_PLAYER_NAME + 1];
    new File:file;
    new line[MAX_PLAYER_NAME + 8];
    new count;
    new found;
    new index;
    new start;

    if (!fexist(WHITELIST_FILE))
    {
        return 0;
    }

    file = fopen(WHITELIST_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        start = SkipSpaces(line, 0);
        if (line[start] == 0 || line[start] == '#')
        {
            continue;
        }

        if (strcmp(line[start], name, true) == 0)
        {
            found = 1;
            continue;
        }

        if (count < OPS_MAX_WHITELIST_CACHE)
        {
            format(names[count], MAX_PLAYER_NAME + 1, "%s", line[start]);
            count++;
        }
    }

    fclose(file);

    if (!found)
    {
        return 0;
    }

    return Ops_RewriteWhitelist(names, count);
}

stock Ops_HandleCommands(playerid, cmdtext[])
{
    new command[32];
    new param[32];
    new param2[MAX_PLAYER_NAME + 1];
    new index;
    new message[128];

    index = GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/checkserver", true) == 0)
    {
        return Ops_ShowCheckServer(playerid);
    }

    if (strcmp(command, "/statusserver", true) == 0 || strcmp(command, "/serverstatus", true) == 0)
    {
        return Ops_ShowServerStatus(playerid);
    }

    if (strcmp(command, "/saudeeconomia", true) == 0 || strcmp(command, "/economiastaff", true) == 0)
    {
        return Ops_ShowEconomyHealth(playerid);
    }

    if (strcmp(command, "/alertaeconomia", true) == 0 || strcmp(command, "/economiaquebrada", true) == 0 || strcmp(command, "/checkeconomia", true) == 0)
    {
        return Ops_ShowEconomyAlerts(playerid);
    }

    if (strcmp(command, "/perf", true) == 0 || strcmp(command, "/performance", true) == 0 || strcmp(command, "/laggm", true) == 0 || strcmp(command, "/timersgm", true) == 0)
    {
        return Ops_ShowPerfPanel(playerid);
    }

    if (strcmp(command, "/logsstaff", true) == 0 || strcmp(command, "/logsop", true) == 0 || strcmp(command, "/logsgm", true) == 0)
    {
        return Ops_ShowLogsPanel(playerid);
    }

    if (strcmp(command, "/painelstaff", true) == 0 || strcmp(command, "/staffpanel", true) == 0 || strcmp(command, "/operacao", true) == 0)
    {
        return Ops_ShowStaffPanel(playerid);
    }

    if (strcmp(command, "/antiabuso", true) == 0 || strcmp(command, "/farmsuspeito", true) == 0 || strcmp(command, "/auditoriafarm", true) == 0)
    {
        return Ops_ShowAntiAbusePanel(playerid);
    }

    if (strcmp(command, "/manutencao", true) == 0 || strcmp(command, "/maintenance", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            format(message, sizeof(message), "Modo manutencao: %s.", gMaintenanceMode ? ("ON") : ("OFF"));
            SendClientMessage(playerid, COLOR_ORANGE, message);
            return SendUsage(playerid, "/manutencao [on/off]");
        }

        if (strcmp(param, "on", true) == 0 || strcmp(param, "1", true) == 0)
        {
            return Ops_SetMaintenance(playerid, 1);
        }
        if (strcmp(param, "off", true) == 0 || strcmp(param, "0", true) == 0)
        {
            return Ops_SetMaintenance(playerid, 0);
        }
        return SendUsage(playerid, "/manutencao [on/off]");
    }

    if (strcmp(command, "/whitelist", true) == 0)
    {
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
        {
            return SendNoPermission(playerid);
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            format(message, sizeof(message), "Whitelist: %s | Nomes: %d.", gWhitelistEnabled ? ("ON") : ("OFF"), Ops_CountConfigLines(WHITELIST_FILE));
            SendClientMessage(playerid, COLOR_ORANGE, message);
            return SendUsage(playerid, "/whitelist [on/off/add/rem/list] [nick]");
        }

        if (strcmp(param, "on", true) == 0)
        {
            gWhitelistEnabled = 1;
            Ops_SaveConfig();
            SendClientMessage(playerid, COLOR_ORANGE, "Whitelist ativada.");
            WritePlayerLog(LOG_ADMIN_FILE, "WHITELIST", playerid, "ativou whitelist");
            Ops_KickRestrictedPlayers(1);
            return 1;
        }

        if (strcmp(param, "off", true) == 0)
        {
            gWhitelistEnabled = 0;
            Ops_SaveConfig();
            SendClientMessage(playerid, COLOR_ORANGE, "Whitelist desativada.");
            WritePlayerLog(LOG_ADMIN_FILE, "WHITELIST", playerid, "desativou whitelist");
            return 1;
        }

        if (strcmp(param, "list", true) == 0 || strcmp(param, "lista", true) == 0)
        {
            return Ops_ShowWhitelistDialog(playerid);
        }

        if (strcmp(param, "add", true) == 0 || strcmp(param, "adicionar", true) == 0)
        {
            if (!GetNextParam(cmdtext, index, param2, sizeof(param2)))
            {
                return SendUsage(playerid, "/whitelist add [nick]");
            }

            if (!Ops_AddNameToFile(WHITELIST_FILE, param2))
            {
                SendClientMessage(playerid, COLOR_RED, "Nao foi possivel salvar na whitelist.");
                return 1;
            }

            format(message, sizeof(message), "Nick %s adicionado na whitelist.", param2);
            SendClientMessage(playerid, COLOR_GREEN, message);
            WritePlayerLog(LOG_ADMIN_FILE, "WHITELIST", playerid, message);
            return 1;
        }

        if (strcmp(param, "rem", true) == 0 || strcmp(param, "remove", true) == 0 || strcmp(param, "remover", true) == 0)
        {
            if (!GetNextParam(cmdtext, index, param2, sizeof(param2)))
            {
                return SendUsage(playerid, "/whitelist rem [nick]");
            }

            if (!Ops_RemoveWhitelistName(param2))
            {
                SendClientMessage(playerid, COLOR_RED, "Nick nao encontrado na whitelist.");
                return 1;
            }

            format(message, sizeof(message), "Nick %s removido da whitelist.", param2);
            SendClientMessage(playerid, COLOR_GREEN, message);
            WritePlayerLog(LOG_ADMIN_FILE, "WHITELIST", playerid, message);
            return 1;
        }

        return SendUsage(playerid, "/whitelist [on/off/add/rem/list] [nick]");
    }

    return 0;
}
