#if defined _nova_self_heal_included
    #endinput
#endif
#define _nova_self_heal_included

#define SELFHEAL_INTERVAL_MS        (300000)
#define SELFHEAL_ALERT_COOLDOWN_MS  (300000)

new gSelfHealTimer;
new gSelfHealRuns;
new gSelfHealLastRepairs;
new gSelfHealTotalRepairs;
new gSelfHealLastTick;
new gSelfHealLastMs;
new gSelfHealLastAlertTick;

forward SelfHeal_UpdateAll();

stock SelfHeal_NotifyAdmins(message[])
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && PlayerInfo[playerid][pLogged] && HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
        {
            SendClientMessage(playerid, COLOR_ORANGE, message);
        }
    }
    return 1;
}

stock SelfHeal_Append(report[], size, item[])
{
    return Account_AppendRepair(report, size, item);
}

stock SelfHeal_RepairDialogState(playerid, report[], size)
{
    new repairs;

    if (gBankDialogActionCount[playerid] < 0 || gBankDialogActionCount[playerid] > MAX_BANK_DIALOG_ACTIONS)
    {
        repairs++;
        SelfHeal_Append(report, size, "dialog banco");
        gBankDialogActionCount[playerid] = 0;
    }
    if (gPhoneGovActionCount[playerid] < 0 || gPhoneGovActionCount[playerid] > PHONE_GOV_MAX_ACTIONS)
    {
        repairs++;
        SelfHeal_Append(report, size, "dialog govbr");
        gPhoneGovActionCount[playerid] = 0;
    }
    if (gPhonePropertyCount[playerid] < 0 || gPhonePropertyCount[playerid] > PHONE_PROP_MAX_ACTIONS)
    {
        repairs++;
        SelfHeal_Append(report, size, "dialog imovel");
        gPhonePropertyCount[playerid] = 0;
    }
    if (gPhonePropertyActionCount[playerid] < 0 || gPhonePropertyActionCount[playerid] > PHONE_PROP_ACTIONS)
    {
        repairs++;
        SelfHeal_Append(report, size, "acao imovel");
        gPhonePropertyActionCount[playerid] = 0;
    }
    if (gCityHallActionCount[playerid] < 0 || gCityHallActionCount[playerid] > CITYHALL_MAX_ACTIONS)
    {
        repairs++;
        SelfHeal_Append(report, size, "dialog prefeitura");
        gCityHallActionCount[playerid] = 0;
    }
    if (gCityHallJobActionCount[playerid] < 0 || gCityHallJobActionCount[playerid] > CITYHALL_JOB_ACTIONS)
    {
        repairs++;
        SelfHeal_Append(report, size, "dialog emprego prefeitura");
        gCityHallJobActionCount[playerid] = 0;
    }
    if (gVipDialogActionCount[playerid] < 0 || gVipDialogActionCount[playerid] > VIP_MENU_ACTIONS)
    {
        repairs++;
        SelfHeal_Append(report, size, "dialog vip");
        gVipDialogActionCount[playerid] = 0;
    }
    return repairs;
}

stock SelfHeal_RepairRuntimePlayer(playerid, report[], size)
{
    new repairs;
    new vehicleid;
    new Float:health;
    new Float:armour;

    if (GetPlayerHealth(playerid, health) && health > 100.0)
    {
        repairs++;
        SelfHeal_Append(report, size, "vida runtime");
        SetPlayerHealth(playerid, 100.0);
    }
    if (GetPlayerArmour(playerid, armour) && armour > 100.0)
    {
        repairs++;
        SelfHeal_Append(report, size, "colete runtime");
        SetPlayerArmour(playerid, 100.0);
    }

    vehicleid = gPlayerOwnedVehicle[playerid];
    if (vehicleid != 0 && (vehicleid == INVALID_VEHICLE_ID || !Fuel_IsValidVehicle(vehicleid)))
    {
        repairs++;
        SelfHeal_Append(report, size, "veiculo runtime");
        gPlayerOwnedVehicle[playerid] = 0;
        gPlayerVehicleSpawnedSlot[playerid] = -1;
    }
    if (gPlayerVehicleSpawnedSlot[playerid] >= gPlayerVehicleCount[playerid]
        || gPlayerVehicleSpawnedSlot[playerid] >= MAX_PLAYER_VEHICLES)
    {
        repairs++;
        SelfHeal_Append(report, size, "slot spawn veiculo");
        gPlayerVehicleSpawnedSlot[playerid] = -1;
    }
    return repairs;
}

stock SelfHeal_RepairPlayer(playerid)
{
    new repairs;
    new report[256];
    new message[320];

    if (!IsPlayerConnected(playerid) || IsPlayerNPC(playerid) || !PlayerInfo[playerid][pLogged])
    {
        return 0;
    }

    repairs = Account_RepairLegacyData(playerid, 1, report, sizeof(report));
    repairs += SelfHeal_RepairDialogState(playerid, report, sizeof(report));
    repairs += SelfHeal_RepairRuntimePlayer(playerid, report, sizeof(report));

    if (repairs > 0)
    {
        Dealership_FinalizeAccountLoad(playerid);
        SaveAccountData(playerid, 0);
        format(message, sizeof(message), "repairs=%d items=%s", repairs, report);
        WritePlayerLog(LOG_ADMIN_FILE, "SELF_HEAL_PLAYER", playerid, message);
    }
    return repairs;
}

stock SelfHeal_RepairGlobalData(report[], size)
{
    new repairs;
    new index;

    if (gMapObjCount < 0 || gMapObjCount > MAX_MAP_OBJECTS)
    {
        repairs++;
        SelfHeal_Append(report, size, "reload map_objects");
        MapObj_LoadAll();
    }
    if (gJobVehicleCount < 0 || gJobVehicleCount > MAX_JOB_CONFIG_VEHICLES)
    {
        repairs++;
        SelfHeal_Append(report, size, "reload job_vehicles");
        JobVehicle_LoadAll();
    }
    if (gEditorLocCount < 0 || gEditorLocCount > MAX_EDITOR_LOCATIONS)
    {
        repairs++;
        SelfHeal_Append(report, size, "reload editor_locations");
        Property_EditorLoadLocations();
    }
    if (gRadarCount < 0 || gRadarCount > MAX_RADARS)
    {
        repairs++;
        SelfHeal_Append(report, size, "reload radares");
        Radar_Init();
    }
    if (gTollCount < 0 || gTollCount > TOLL_MAX_COUNT)
    {
        repairs++;
        SelfHeal_Append(report, size, "reload pedagios");
        gTollCount = 0;
        Tolls_LoadPositions();
        for (index = 0; index < gTollCount && index < TOLL_MAX_COUNT; index++)
        {
            Tolls_UpdateVisual(index);
        }
    }
    return repairs;
}

stock SelfHeal_Run(reason[], playerid = INVALID_PLAYER_ID)
{
    new pid;
    new maxPlayers = GetMaxPlayers();
    new repairs;
    new total;
    new scanned;
    new startTick = GetTickCount();
    new report[256];
    new detail[384];

    report[0] = 0;
    total += SelfHeal_RepairGlobalData(report, sizeof(report));

    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (IsPlayerConnected(pid) && PlayerInfo[pid][pLogged] && !IsPlayerNPC(pid))
        {
            scanned++;
            repairs = SelfHeal_RepairPlayer(pid);
            total += repairs;
        }
    }

    gSelfHealRuns++;
    gSelfHealLastRepairs = total;
    gSelfHealTotalRepairs += total;
    gSelfHealLastTick = GetTickCount();
    gSelfHealLastMs = gSelfHealLastTick - startTick;

    if (total > 0)
    {
        format(detail, sizeof(detail), "reason=%s repairs=%d scanned=%d global=%s ms=%d", reason, total, scanned, report, gSelfHealLastMs);
        WriteServerLog(LOG_ADMIN_FILE, "SELF_HEAL", detail);
        if (playerid != INVALID_PLAYER_ID)
        {
            SendClientMessage(playerid, COLOR_GREEN, "SelfHeal executado: a GM corrigiu inconsistencias e salvou os dados afetados.");
        }
        if (!gSelfHealLastAlertTick || (gSelfHealLastTick - gSelfHealLastAlertTick) >= SELFHEAL_ALERT_COOLDOWN_MS)
        {
            gSelfHealLastAlertTick = gSelfHealLastTick;
            format(detail, sizeof(detail), "[SelfHeal] Reparos automaticos: %d | players verificados: %d | %dms.", total, scanned, gSelfHealLastMs);
            SelfHeal_NotifyAdmins(detail);
        }
    }
    else if (playerid != INVALID_PLAYER_ID)
    {
        SendClientMessage(playerid, COLOR_GREEN, "SelfHeal executado: nenhuma falha detectada.");
    }
    return total;
}

public SelfHeal_UpdateAll()
{
    SelfHeal_Run("timer");
    return 1;
}

stock SelfHeal_Init()
{
    if (!gSelfHealTimer)
    {
        gSelfHealTimer = SetTimer("SelfHeal_UpdateAll", SELFHEAL_INTERVAL_MS, 1);
        WriteServerLog(LOG_ADMIN_FILE, "SELF_HEAL_INIT", "timer=300000ms");
    }
    return 1;
}

stock SelfHeal_Exit()
{
    if (gSelfHealTimer)
    {
        KillTimer(gSelfHealTimer);
        gSelfHealTimer = 0;
    }
    return 1;
}

stock SelfHeal_ShowStatus(playerid)
{
    new message[144];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }

    format(message, sizeof(message), "SelfHeal: runs %d | ultimo %d reparo(s) | total %d | ultimo tempo %dms.", gSelfHealRuns, gSelfHealLastRepairs, gSelfHealTotalRepairs, gSelfHealLastMs);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(playerid, COLOR_GRAY, "Use /selfheal run para forcar uma varredura agora.");
    return 1;
}

stock SelfHeal_HandleCommands(playerid, cmdtext[])
{
    new command[32];
    new param[24];
    new index;

    index = GetCommandName(cmdtext, command, sizeof(command));
    if (strcmp(command, "/selfheal", true) != 0
        && strcmp(command, "/autocurar", true) != 0
        && strcmp(command, "/reparargm", true) != 0)
    {
        return 0;
    }

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }

    GetNextParam(cmdtext, index, param, sizeof(param));
    if (strcmp(param, "run", true) == 0 || strcmp(param, "agora", true) == 0)
    {
        SelfHeal_Run("manual", playerid);
        return 1;
    }

    return SelfHeal_ShowStatus(playerid);
}
