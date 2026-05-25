#if defined _nova_security_included
    #endinput
#endif
#define _nova_security_included

#define SECURITY_CD_BUG             (0)
#define SECURITY_CD_GPS             (1)
#define SECURITY_CD_PHONE           (2)
#define SECURITY_CD_MENU            (3)
#define SECURITY_CD_HELP            (4)
#define SECURITY_CD_DIALOG          (5)

new gSecurityTimer;
new gSecurityExpectedCash[MAX_PLAYERS];
new gSecurityExpectedCashReady[MAX_PLAYERS];
new gSecurityLastChatTick[MAX_PLAYERS];
new gSecurityChatBurst[MAX_PLAYERS];
new gSecurityLastCommandTick[MAX_PLAYERS];
new gSecurityCommandBurst[MAX_PLAYERS];
new gSecurityCooldownTick[MAX_PLAYERS][SECURITY_COOLDOWN_SLOTS];
new gSecurityTeleportGraceTick[MAX_PLAYERS];
new gSecuritySuspectScore[MAX_PLAYERS];
new Float:gSecurityLastX[MAX_PLAYERS];
new Float:gSecurityLastY[MAX_PLAYERS];
new Float:gSecurityLastZ[MAX_PLAYERS];
new gSecurityLastInterior[MAX_PLAYERS];
new gSecurityLastVirtualWorld[MAX_PLAYERS];
new gSecurityHasPosition[MAX_PLAYERS];
new gSecurityBanNames[SECURITY_MAX_BAN_DIALOG][MAX_PLAYER_NAME + 1];
new gSecurityBanAdmins[SECURITY_MAX_BAN_DIALOG][32];
new gSecurityBanReasons[SECURITY_MAX_BAN_DIALOG][96];
new gSecurityBanDates[SECURITY_MAX_BAN_DIALOG][24];
new gSecurityBanActive[SECURITY_MAX_BAN_DIALOG];

forward Security_UpdateAll();

stock Security_ResetPlayer(playerid)
{
    new index;

    gSecurityExpectedCash[playerid] = 0;
    gSecurityExpectedCashReady[playerid] = 0;
    gSecurityLastChatTick[playerid] = 0;
    gSecurityChatBurst[playerid] = 0;
    gSecurityLastCommandTick[playerid] = 0;
    gSecurityCommandBurst[playerid] = 0;
    gSecurityTeleportGraceTick[playerid] = 0;
    gSecuritySuspectScore[playerid] = 0;
    gSecurityHasPosition[playerid] = 0;
    gSecurityLastInterior[playerid] = 0;
    gSecurityLastVirtualWorld[playerid] = 0;

    for (index = 0; index < SECURITY_COOLDOWN_SLOTS; index++)
    {
        gSecurityCooldownTick[playerid][index] = 0;
    }
    return 1;
}

stock Security_ResetCommandState(playerid)
{
    new index;

    gSecurityLastCommandTick[playerid] = 0;
    gSecurityCommandBurst[playerid] = 0;
    for (index = 0; index < SECURITY_COOLDOWN_SLOTS; index++)
    {
        gSecurityCooldownTick[playerid][index] = 0;
    }
    return 1;
}

stock Security_Init()
{
    Ops_CreateFileIfMissing(BANS_FILE, "# Formato: BAN|nick|admin|data|motivo ou UNBAN|nick|admin|data|motivo\r\n");
    Ops_CreateFileIfMissing(SECURITY_ALERT_FILE, "# data|categoria|detalhes\r\n");
    Ops_CreateFileIfMissing(BUG_REPORT_UPDATES_FILE, "# Formato: id|data|status|prioridade|staff|nota\r\n");

    if (gSecurityTimer)
    {
        KillTimer(gSecurityTimer);
    }

    gSecurityTimer = SetTimer("Security_UpdateAll", SECURITY_UPDATE_INTERVAL, 1);
    return 1;
}

stock Security_Exit()
{
    if (gSecurityTimer)
    {
        KillTimer(gSecurityTimer);
        gSecurityTimer = 0;
    }
    return 1;
}

stock Security_SetExpectedCash(playerid, amount)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
    {
        return 0;
    }

    if (amount < 0)
    {
        amount = 0;
    }

    gSecurityExpectedCash[playerid] = amount;
    gSecurityExpectedCashReady[playerid] = 1;
    return 1;
}

stock Security_HasExpectedCash(playerid)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
    {
        return 0;
    }

    return gSecurityExpectedCashReady[playerid];
}

stock Security_IsExpectedCash(playerid, amount)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
    {
        return 0;
    }

    if (amount < 0)
    {
        amount = 0;
    }

    return (gSecurityExpectedCashReady[playerid] && gSecurityExpectedCash[playerid] == amount);
}

stock Security_GrantTeleportGrace(playerid, milliseconds = SECURITY_TELEPORT_GRACE)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
    {
        return 0;
    }

    gSecurityTeleportGraceTick[playerid] = GetTickCount() + milliseconds;
    return 1;
}

stock Security_UpdatePlayerPosition(playerid)
{
    GetPlayerPos(playerid, gSecurityLastX[playerid], gSecurityLastY[playerid], gSecurityLastZ[playerid]);
    gSecurityLastInterior[playerid] = GetPlayerInterior(playerid);
    gSecurityLastVirtualWorld[playerid] = GetPlayerVirtualWorld(playerid);
    gSecurityHasPosition[playerid] = 1;
    return 1;
}

stock Security_OnPlayerSpawn(playerid)
{
    Security_SetExpectedCash(playerid, GetPlayerMoney(playerid));
    Security_GrantTeleportGrace(playerid);
    Security_UpdatePlayerPosition(playerid);
    return 1;
}

stock Security_SendStaffAlert(message[])
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && PlayerInfo[playerid][pLogged] && HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
        {
            SendClientMessage(playerid, COLOR_ADMIN, message);
        }
    }
    return 1;
}

stock Security_AddAlert(playerid, category[], details[])
{
    new name[MAX_PLAYER_NAME + 1];
    new clean[192];
    new line[256];
    new staffMessage[144];

    if (IsValidConnectedPlayer(playerid))
    {
        GetPlayerNameEx(playerid, name, sizeof(name));
        gSecuritySuspectScore[playerid]++;
    }
    else
    {
        format(name, sizeof(name), "offline");
    }

    SanitizeLogText(details, clean, sizeof(clean));
    format(line, sizeof(line), "player=%s id=%d score=%d %s", name, playerid, (IsValidConnectedPlayer(playerid) ? gSecuritySuspectScore[playerid] : 0), clean);
    WriteServerLog(SECURITY_ALERT_FILE, category, line);
    format(staffMessage, sizeof(staffMessage), "[SEGURANCA] %s: %s", category, clean);
    Security_SendStaffAlert(staffMessage);
    return 1;
}

stock Security_GetCooldownSlot(command[])
{
    if (strcmp(command, "/bug", true) == 0 || strcmp(command, "/problema", true) == 0 || strcmp(command, "/relatarbug", true) == 0 || strcmp(command, "/reportarbug", true) == 0)
    {
        return SECURITY_CD_BUG;
    }
    if (strcmp(command, "/gps", true) == 0)
    {
        return SECURITY_CD_GPS;
    }
    if (strcmp(command, "/celular", true) == 0 || strcmp(command, "/phone", true) == 0 || strcmp(command, "/app", true) == 0)
    {
        return SECURITY_CD_PHONE;
    }
    if (strcmp(command, "/menu", true) == 0 || strcmp(command, "/painel", true) == 0)
    {
        return SECURITY_CD_MENU;
    }
    if (strcmp(command, "/ajuda", true) == 0 || strcmp(command, "/help", true) == 0 || strcmp(command, "/comandos", true) == 0 || strcmp(command, "/ajudaadmin", true) == 0 || strcmp(command, "/ajudaadm", true) == 0 || strcmp(command, "/adminhelp", true) == 0 || strcmp(command, "/comandosadmin", true) == 0 || strcmp(command, "/tutorial", true) == 0)
    {
        return SECURITY_CD_HELP;
    }
    if (strcmp(command, "/banco", true) == 0 || strcmp(command, "/caixa", true) == 0 || strcmp(command, "/atm", true) == 0)
    {
        return SECURITY_CD_DIALOG;
    }
    if (strcmp(command, "/inventario", true) == 0 || strcmp(command, "/inv", true) == 0)
    {
        return SECURITY_CD_DIALOG;
    }
    if (strcmp(command, "/radio", true) == 0 || strcmp(command, "/radios", true) == 0 || strcmp(command, "/musica", true) == 0)
    {
        return SECURITY_CD_DIALOG;
    }
    if (strcmp(command, "/radioveiculo", true) == 0 || strcmp(command, "/radiocarro", true) == 0)
    {
        return SECURITY_CD_DIALOG;
    }
    if (strcmp(command, "/detran", true) == 0 || strcmp(command, "/garagem", true) == 0)
    {
        return SECURITY_CD_DIALOG;
    }
    if (strcmp(command, "/garagempublica", true) == 0 || strcmp(command, "/garagemcasa", true) == 0)
    {
        return SECURITY_CD_DIALOG;
    }
    if (strcmp(command, "/blitz", true) == 0 || strcmp(command, "/fiscalizar", true) == 0 || strcmp(command, "/barreira", true) == 0 || strcmp(command, "/criarbarreira", true) == 0 || strcmp(command, "/blitzprf", true) == 0)
    {
        return SECURITY_CD_DIALOG;
    }
    if (strcmp(command, "/multa", true) == 0 || strcmp(command, "/multas", true) == 0 || strcmp(command, "/ctb", true) == 0)
    {
        return SECURITY_CD_DIALOG;
    }
    if (strcmp(command, "/abordagem", true) == 0 || strcmp(command, "/abordar", true) == 0 || strcmp(command, "/revistar", true) == 0 || strcmp(command, "/revista", true) == 0 || strcmp(command, "/procurados", true) == 0 || strcmp(command, "/wanted", true) == 0)
    {
        return SECURITY_CD_DIALOG;
    }
    return -1;
}

stock Security_GetCooldownTime(slot)
{
    switch (slot)
    {
        case SECURITY_CD_BUG: return SECURITY_BUG_COOLDOWN;
        case SECURITY_CD_GPS: return SECURITY_GPS_COOLDOWN;
        case SECURITY_CD_PHONE: return SECURITY_PHONE_COOLDOWN;
        case SECURITY_CD_MENU: return SECURITY_MENU_COOLDOWN;
        case SECURITY_CD_HELP: return SECURITY_HELP_COOLDOWN;
        case SECURITY_CD_DIALOG: return SECURITY_DIALOG_COOLDOWN;
    }
    return 0;
}

stock Security_CheckCommandCooldown(playerid, command[])
{
    new slot = Security_GetCooldownSlot(command);
    new cooldown;
    new tick;
    new waitSeconds;
    new message[96];

    if (slot == -1 || HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return 1;
    }

    cooldown = Security_GetCooldownTime(slot);
    tick = GetTickCount();

    if (gSecurityCooldownTick[playerid][slot] > 0 && (tick - gSecurityCooldownTick[playerid][slot]) < cooldown)
    {
        waitSeconds = (cooldown - (tick - gSecurityCooldownTick[playerid][slot]) + 999) / 1000;
        format(message, sizeof(message), "Aguarde %d segundos para usar este comando novamente.", waitSeconds);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        return 0;
    }

    gSecurityCooldownTick[playerid][slot] = tick;
    return 1;
}

stock Security_CheckCommand(playerid, cmdtext[])
{
    new command[32];
    new tick = GetTickCount();
    new details[128];

    GetCommandName(cmdtext, command, sizeof(command));

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        if (gSecurityLastCommandTick[playerid] > 0 && (tick - gSecurityLastCommandTick[playerid]) < SECURITY_COMMAND_MIN_INTERVAL)
        {
            gSecurityCommandBurst[playerid]++;
        }
        else
        {
            gSecurityCommandBurst[playerid] = 0;
        }

        gSecurityLastCommandTick[playerid] = tick;

        if (gSecurityCommandBurst[playerid] >= SECURITY_COMMAND_FLOOD_LIMIT)
        {
            format(details, sizeof(details), "spam_comando command=%s", command);
            Security_AddAlert(playerid, "FLOOD_CMD", details);
            SendClientMessage(playerid, COLOR_RED, "Comando bloqueado por flood. Aguarde um momento.");
            return 0;
        }
    }

    return Security_CheckCommandCooldown(playerid, command);
}

stock Security_CheckChat(playerid, text[])
{
    new tick = GetTickCount();
    new details[128];

    if (HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return 1;
    }

    if (gSecurityLastChatTick[playerid] > 0 && (tick - gSecurityLastChatTick[playerid]) < SECURITY_CHAT_MIN_INTERVAL)
    {
        gSecurityChatBurst[playerid]++;
    }
    else
    {
        gSecurityChatBurst[playerid] = 0;
    }

    gSecurityLastChatTick[playerid] = tick;

    if (gSecurityChatBurst[playerid] >= SECURITY_CHAT_FLOOD_LIMIT)
    {
        format(details, sizeof(details), "spam_chat text=%s", text);
        Security_AddAlert(playerid, "FLOOD_CHAT", details);
        PlayerInfo[playerid][pMuteTime] = SECURITY_CHAT_MUTE_SECONDS;
        SaveAccountData(playerid, 0);
        SendClientMessage(playerid, COLOR_RED, "Chat bloqueado por flood. Voce foi mutado temporariamente.");
        return 0;
    }

    return 1;
}

stock Security_GetField(line[], field, output[], size)
{
    return BugReport_GetField(line, field, output, size);
}

stock Security_IsNameBanned(name[], reason[], reasonSize, admin[], adminSize, date[], dateSize)
{
    new File:file;
    new line[256];
    new action[12];
    new banName[MAX_PLAYER_NAME + 1];

    reason[0] = 0;
    admin[0] = 0;
    date[0] = 0;

    if (!fexist(BANS_FILE))
    {
        return 0;
    }

    file = fopen(BANS_FILE, io_read);
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

        Security_GetField(line, 0, action, sizeof(action));
        Security_GetField(line, 1, banName, sizeof(banName));
        if (strcmp(banName, name, true) != 0)
        {
            continue;
        }

        if (strcmp(action, "BAN", true) == 0)
        {
            Security_GetField(line, 2, admin, adminSize);
            Security_GetField(line, 3, date, dateSize);
            Security_GetField(line, 4, reason, reasonSize);
        }
        else if (strcmp(action, "UNBAN", true) == 0)
        {
            reason[0] = 0;
            admin[0] = 0;
            date[0] = 0;
        }
    }

    fclose(file);
    return (reason[0] != 0);
}

stock Security_AppendBanAction(action[], name[], adminName[], reason[])
{
    new File:file;
    new cleanReason[128];
    new line[256];
    new year;
    new month;
    new day;
    new hour;
    new minute;
    new second;

    file = fopen(BANS_FILE, io_append);
    if (!file)
    {
        return 0;
    }

    SanitizeLogText(reason, cleanReason, sizeof(cleanReason));
    GetBrasiliaDateTime(year, month, day, hour, minute, second);
    format(line, sizeof(line), "%s|%s|%s|%04d-%02d-%02d %02d:%02d:%02d|%s\r\n", action, name, adminName, year, month, day, hour, minute, second, cleanReason);
    fwrite(file, line);
    fclose(file);
    return 1;
}

stock Security_CanPlayerConnect(playerid)
{
    new name[MAX_PLAYER_NAME + 1];
    new reason[128];
    new admin[32];
    new date[24];
    new message[144];

    GetPlayerNameEx(playerid, name, sizeof(name));
    if (!Security_IsNameBanned(name, reason, sizeof(reason), admin, sizeof(admin), date, sizeof(date)))
    {
        return 1;
    }

    format(message, sizeof(message), "Voce esta banido. Admin: %s | Data: %s | Motivo: %s", admin, date, reason);
    SendClientMessage(playerid, COLOR_RED, message);
    format(message, sizeof(message), "blocked_ban player=%s admin=%s reason=%s", name, admin, reason);
    WriteServerLog(LOG_PUNISH_FILE, "BAN_BLOCK", message);
    Kick(playerid);
    return 0;
}

stock Security_FindPlayerByName(name[])
{
    new playerid;
    new playerName[MAX_PLAYER_NAME + 1];
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (!IsPlayerConnected(playerid))
        {
            continue;
        }

        GetPlayerNameEx(playerid, playerName, sizeof(playerName));
        if (strcmp(playerName, name, true) == 0)
        {
            return playerid;
        }
    }
    return INVALID_PLAYER_ID;
}

stock Security_BanName(playerid, name[], reason[])
{
    new adminName[MAX_PLAYER_NAME + 1];
    new targetid;
    new message[144];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_MANAGER))
    {
        return SendNoPermission(playerid);
    }

    GetPlayerNameEx(playerid, adminName, sizeof(adminName));
    if (!Security_AppendBanAction("BAN", name, adminName, reason))
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel salvar o ban em bans.txt.");
        return 1;
    }

    format(message, sizeof(message), "[ADMIN] %s baniu %s. Motivo: %s", adminName, name, reason);
    SendClientMessageToAll(COLOR_ADMIN, message);
    WriteServerLog(LOG_PUNISH_FILE, "BAN", message);

    targetid = Security_FindPlayerByName(name);
    if (targetid != INVALID_PLAYER_ID)
    {
        Kick(targetid);
    }
    return 1;
}

stock Security_UnbanName(playerid, name[], reason[])
{
    new adminName[MAX_PLAYER_NAME + 1];
    new message[144];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_MANAGER))
    {
        return SendNoPermission(playerid);
    }

    GetPlayerNameEx(playerid, adminName, sizeof(adminName));
    if (!Security_AppendBanAction("UNBAN", name, adminName, reason))
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel salvar o unban em bans.txt.");
        return 1;
    }

    format(message, sizeof(message), "[ADMIN] %s desbaniu %s. Motivo: %s", adminName, name, reason);
    SendClientMessageToAll(COLOR_ADMIN, message);
    WriteServerLog(LOG_PUNISH_FILE, "UNBAN", message);
    return 1;
}

stock Security_BuildActiveBanList(list[], size)
{
    new File:file;
    new line[256];
    new action[12];
    new name[MAX_PLAYER_NAME + 1];
    new admin[32];
    new date[24];
    new reason[96];
    new count;
    new index;
    new slot;
    new displayCount;
    new row[160];

    format(list, size, "Nick\tAdmin\tMotivo\n");
    for (index = 0; index < SECURITY_MAX_BAN_DIALOG; index++)
    {
        gSecurityBanNames[index][0] = 0;
        gSecurityBanAdmins[index][0] = 0;
        gSecurityBanReasons[index][0] = 0;
        gSecurityBanDates[index][0] = 0;
        gSecurityBanActive[index] = 0;
    }

    if (!fexist(BANS_FILE))
    {
        return 0;
    }

    file = fopen(BANS_FILE, io_read);
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

        Security_GetField(line, 0, action, sizeof(action));
        Security_GetField(line, 1, name, sizeof(name));

        slot = -1;
        for (index = 0; index < count; index++)
        {
            if (strcmp(gSecurityBanNames[index], name, true) == 0)
            {
                slot = index;
                break;
            }
        }

        if (slot == -1 && count < SECURITY_MAX_BAN_DIALOG)
        {
            slot = count;
            format(gSecurityBanNames[slot], MAX_PLAYER_NAME + 1, "%s", name);
            count++;
        }

        if (slot == -1)
        {
            continue;
        }

        if (strcmp(action, "BAN", true) == 0)
        {
            Security_GetField(line, 2, admin, sizeof(admin));
            Security_GetField(line, 3, date, sizeof(date));
            Security_GetField(line, 4, reason, sizeof(reason));
            format(gSecurityBanAdmins[slot], 32, "%s", admin);
            format(gSecurityBanDates[slot], 24, "%s", date);
            format(gSecurityBanReasons[slot], 96, "%s", reason);
            gSecurityBanActive[slot] = 1;
        }
        else if (strcmp(action, "UNBAN", true) == 0)
        {
            gSecurityBanActive[slot] = 0;
        }
    }

    fclose(file);

    for (index = 0; index < count; index++)
    {
        if (!gSecurityBanActive[index])
        {
            continue;
        }

        format(row, sizeof(row), "%s\t%s\t%s\n", gSecurityBanNames[index], gSecurityBanAdmins[index], gSecurityBanReasons[index]);
        strcat(list, row, size);
        displayCount++;
    }

    return displayCount;
}

stock Security_ShowBansDialog(playerid)
{
    new list[3072];
    new count;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }

    count = Security_BuildActiveBanList(list, sizeof(list));
    if (count <= 0)
    {
        ShowPlayerDialog(playerid, DIALOG_BAN_LIST, DIALOG_STYLE_MSGBOX, "Banidos", "Nenhum ban ativo encontrado.", "Fechar", "");
        return 1;
    }

    ShowPlayerDialog(playerid, DIALOG_BAN_LIST, DIALOG_STYLE_TABLIST_HEADERS, "Banidos ativos", list, "Fechar", "");
    return 1;
}

stock Security_IsAllowedWeapon(playerid, weaponid)
{
    if (weaponid == 0 || weaponid == WEAPON_PARACHUTE)
    {
        return 1;
    }

    if (Work_IsActive(playerid))
    {
        switch (weaponid)
        {
            case WEAPON_NITESTICK, WEAPON_SHOTGUN, WEAPON_MP5:
            {
                return IsPublicSecurityJob(PlayerInfo[playerid][pJob]);
            }
            case WEAPON_M4:
            {
                return IsLawEnforcementJob(PlayerInfo[playerid][pJob]);
            }
            case WEAPON_FIREEXTINGUISHER:
            {
                return (PlayerInfo[playerid][pJob] == JOB_BOMBEIRO);
            }
            case WEAPON_SPRAYCAN:
            {
                return (PlayerInfo[playerid][pJob] == JOB_MEDICO || PlayerInfo[playerid][pJob] == JOB_MOTORISTA_AMBULANCIA || PlayerInfo[playerid][pJob] == JOB_MECANICO || PlayerInfo[playerid][pJob] == JOB_TECNICO);
            }
            case WEAPON_CAMERA:
            {
                return (PlayerInfo[playerid][pJob] == JOB_JORNALISTA);
            }
        }
    }

    if (PlayerInfo[playerid][pLicensePolice] && PlayerInfo[playerid][pWanted] == 0 && PlayerInfo[playerid][pJailTime] <= 0)
    {
        switch (weaponid)
        {
            case WEAPON_COLT45, WEAPON_SHOTGUN, WEAPON_RIFLE, WEAPON_MP5:
            {
                return 1;
            }
        }
    }
    return 0;
}

stock Security_CheckWeapons(playerid)
{
    new slot;
    new weaponid;
    new ammo;
    new details[96];

    for (slot = 0; slot < 13; slot++)
    {
        GetPlayerWeaponData(playerid, slot, weaponid, ammo);
        if (weaponid <= 0 || ammo <= 0)
        {
            continue;
        }

        if (!Security_IsAllowedWeapon(playerid, weaponid))
        {
            format(details, sizeof(details), "arma_nao_permitida weapon=%d ammo=%d", weaponid, ammo);
            Security_AddAlert(playerid, "ANTICHEAT_WEAPON", details);
            ResetPlayerWeapons(playerid);
            return 0;
        }
    }
    return 1;
}

stock Security_CheckMoney(playerid)
{
    new current = GetPlayerMoney(playerid);
    new details[96];

    if (!gSecurityExpectedCashReady[playerid])
    {
        Security_SetExpectedCash(playerid, PlayerInfo[playerid][pMoney]);
    }

    if (current == gSecurityExpectedCash[playerid])
    {
        return 1;
    }

    format(details, sizeof(details), "dinheiro_invalido atual=%d esperado=%d", current, gSecurityExpectedCash[playerid]);
    Security_AddAlert(playerid, "ANTICHEAT_MONEY", details);
    ResetPlayerMoney(playerid);
    GivePlayerMoney(playerid, gSecurityExpectedCash[playerid]);
    PlayerInfo[playerid][pMoney] = gSecurityExpectedCash[playerid];
    UpdatePlayerHud(playerid);
    return 0;
}

stock Security_CheckHealthArmour(playerid)
{
    new Float:health;
    new Float:armour;
    new details[96];

    GetPlayerHealth(playerid, health);
    GetPlayerArmour(playerid, armour);

    if (health > 105.0)
    {
        format(details, sizeof(details), "vida_anormal %.2f", health);
        Security_AddAlert(playerid, "ANTICHEAT_HEALTH", details);
        SetPlayerHealth(playerid, 100.0);
    }

    if (armour > 105.0)
    {
        format(details, sizeof(details), "colete_anormal %.2f", armour);
        Security_AddAlert(playerid, "ANTICHEAT_ARMOUR", details);
        SetPlayerArmour(playerid, 100.0);
    }
    return 1;
}

stock Float:Security_Distance3D(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2)
{
    return floatsqroot(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)) + ((z1 - z2) * (z1 - z2)));
}

stock Security_CheckTeleport(playerid)
{
    new tick = GetTickCount();
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:distance;
    new Float:limit;
    new details[128];

    if (!gSecurityHasPosition[playerid])
    {
        return Security_UpdatePlayerPosition(playerid);
    }

    if (tick <= gSecurityTeleportGraceTick[playerid])
    {
        return Security_UpdatePlayerPosition(playerid);
    }

    if (GetPlayerInterior(playerid) != gSecurityLastInterior[playerid] || GetPlayerVirtualWorld(playerid) != gSecurityLastVirtualWorld[playerid])
    {
        return Security_UpdatePlayerPosition(playerid);
    }

    GetPlayerPos(playerid, x, y, z);
    distance = Security_Distance3D(x, y, z, gSecurityLastX[playerid], gSecurityLastY[playerid], gSecurityLastZ[playerid]);
    limit = SECURITY_TELEPORT_DISTANCE;
    if (IsPlayerInAnyVehicle(playerid))
    {
        limit = SECURITY_VEHICLE_TELEPORT_DISTANCE;
    }

    if (distance > limit)
    {
        format(details, sizeof(details), "teleport_suspeito dist=%.2f de %.1f %.1f %.1f para %.1f %.1f %.1f", distance, gSecurityLastX[playerid], gSecurityLastY[playerid], gSecurityLastZ[playerid], x, y, z);
        Security_AddAlert(playerid, "ANTICHEAT_TP", details);
    }

    return Security_UpdatePlayerPosition(playerid);
}

stock Security_CheckPlayer(playerid)
{
    if (!IsPlayerConnected(playerid) || !PlayerInfo[playerid][pLogged])
    {
        return 0;
    }

    if (HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        Security_SetExpectedCash(playerid, GetPlayerMoney(playerid));
        Security_UpdatePlayerPosition(playerid);
        return 1;
    }

    Security_CheckMoney(playerid);
    Security_CheckWeapons(playerid);
    Security_CheckHealthArmour(playerid);
    Security_CheckTeleport(playerid);
    return 1;
}

public Security_UpdateAll()
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        Security_CheckPlayer(playerid);
    }
    return 1;
}

stock Security_ReadLastLine(fileName[], output[], size)
{
    new File:file;
    new line[256];

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
    }

    fclose(file);
    return (output[0] != 0);
}

stock Security_CountOnlineSuspects()
{
    new playerid;
    new count;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && gSecuritySuspectScore[playerid] > 0)
        {
            count++;
        }
    }
    return count;
}

stock Security_ShowPanel(playerid)
{
    new body[3072];
    new line[256];
    new banList[2048];
    new bans;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }

    bans = Security_BuildActiveBanList(banList, sizeof(banList));
    format(body, sizeof(body), "Painel de seguranca\n\nBans ativos: %d\nAlertas registrados: %d\nSuspeitos online: %d\n\n", bans, Ops_CountConfigLines(SECURITY_ALERT_FILE), Security_CountOnlineSuspects());

    if (Security_ReadLastLine(SECURITY_ALERT_FILE, line, sizeof(line)))
    {
        strcat(body, "Ultimo alerta:\n", sizeof(body));
        strcat(body, line, sizeof(body));
        strcat(body, "\n\n", sizeof(body));
    }

    if (Security_ReadLastLine(LOG_PUNISH_FILE, line, sizeof(line)))
    {
        strcat(body, "Ultima punicao:\n", sizeof(body));
        strcat(body, line, sizeof(body));
        strcat(body, "\n\n", sizeof(body));
    }

    if (Security_ReadLastLine(LOG_ADMIN_FILE, line, sizeof(line)))
    {
        strcat(body, "Ultima acao admin:\n", sizeof(body));
        strcat(body, line, sizeof(body));
        strcat(body, "\n\n", sizeof(body));
    }

    if (Security_ReadLastLine(LOG_MONEY_FILE, line, sizeof(line)))
    {
        strcat(body, "Ultimo log financeiro:\n", sizeof(body));
        strcat(body, line, sizeof(body));
        strcat(body, "\n\n", sizeof(body));
    }

    strcat(body, "Comandos: /ban, /unban, /banidos, /bugs, /bugprio, /bugresponder, /bugresolver.", sizeof(body));
    ShowPlayerDialog(playerid, DIALOG_SECURITY_PANEL, DIALOG_STYLE_MSGBOX, "Seguranca", body, "Fechar", "");
    return 1;
}

stock Security_HandleCommands(playerid, cmdtext[])
{
    new command[32];
    new param[64];
    new reason[128];
    new index;
    new targetid;
    new targetName[MAX_PLAYER_NAME + 1];

    index = GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/seguranca", true) == 0 || strcmp(command, "/security", true) == 0)
    {
        return Security_ShowPanel(playerid);
    }

    if (strcmp(command, "/banidos", true) == 0 || strcmp(command, "/bans", true) == 0)
    {
        return Security_ShowBansDialog(playerid);
    }

    if (strcmp(command, "/ban", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/ban [id/nick] [motivo]");
        }

        if (!GetRemainingText(cmdtext, index, reason, sizeof(reason)))
        {
            format(reason, sizeof(reason), "Sem motivo");
        }

        if (IsNumericString(param) && ParseTargetPlayer(playerid, param, targetid))
        {
            GetPlayerNameEx(targetid, targetName, sizeof(targetName));
            return Security_BanName(playerid, targetName, reason);
        }

        return Security_BanName(playerid, param, reason);
    }

    if (strcmp(command, "/unban", true) == 0 || strcmp(command, "/desban", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/unban [nick] [motivo]");
        }

        if (!GetRemainingText(cmdtext, index, reason, sizeof(reason)))
        {
            format(reason, sizeof(reason), "Sem motivo");
        }

        return Security_UnbanName(playerid, param, reason);
    }

    return 0;
}
