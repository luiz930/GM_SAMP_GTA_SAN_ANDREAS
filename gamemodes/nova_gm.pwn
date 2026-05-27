//----------------------------------------------------------
//
//  Life Simulator BR
//  Gamemode principal
//
//----------------------------------------------------------

#include <a_samp>

#pragma tabsize 4

#include <core/utils>
#include <core/config>
#include <core/traffic_fines>
#include <core/world>
#include <core/accounts>
#include <core/ambient_npcs>
#include <core/mapobjects>
#include <core/inventory>
#include <core/fuel>
#include <core/climate>
#include <core/hud>
#include <core/money>
#include <core/vip>
#include <core/bank>
#include <core/properties>
#include <core/modbot>
#include <core/reports>
#include <core/chat>
#include <core/jobs>
#include <core/police>
#include <core/crime>
#include <core/radar>
#include <core/cityhall>
#include <core/dealership>
#include <core/hospital>
#include <core/life_services>
#include <core/tolls>
#include <core/needs>
#include <core/phone>
#include <core/ops>
#include <core/radio>
#include <core/security>
#include <core/command_hotfix>
#include <core/self_heal>
#include <core/admin>

new gHostnameTimer;

forward AtualizarHostname();

main()
{
    LoadServerInfo();
    LoadGameConfig();
    print("\n--------------------------------------");
    printf(" %s carregado", gServerName);
    print("--------------------------------------\n");
}

public OnGameModeInit()
{
    LoadServerInfo();
    LoadGameConfig();
    ApplyServerInfo();
    ShowPlayerMarkers(1);
    ShowNameTags(1);
    SetWorldTime(12);
    Climate_Init();
    UsePlayerPedAnims();
    DisableInteriorEnterExits();
    ManualVehicleEngineAndLights();
    EnableStuntBonusForAll(0);

    AddWorldPlayerClasses();
    AmbientNpc_Init();
    CreateWorldVehicles();
    CreateWorldInteractionLabels();
    World_InitSafetyObjects();
    Fuel_Init();
    MapObjects_Init();
    Work_InitVehicles();
    Police_Init();
    Crime_Init();
    Property_Init();
    Radar_Init();
    Ops_Init();
    Radio_Init();
    Security_Init();
    Vip_Init();
    Life_Init();
    Tolls_Init();
    Bot_Init();
    CommandHotfix_Init();
    SelfHeal_Init();

    gHudTimer = SetTimer("UpdateHudForAll", gCfgHudUpdateInterval, 1);
    gHostnameTimer = SetTimer("AtualizarHostname", gCfgHostnameInterval, 1);
    gAutoSaveTimer = SetTimer("AutoSaveAccounts", gCfgAutosaveInterval, 1);
    gNeedsTimer = SetTimer("Needs_UpdateAll", gCfgNeedsUpdateInterval, 1);
    gFuelTimer = SetTimer("Fuel_UpdateAll", gCfgFuelUpdateInterval, 1);
    gPoliceTimer = SetTimer("Police_UpdateAll", 1000, 1);
    gRadarTimer = SetTimer("Radar_UpdateAll", RADAR_CHECK_INTERVAL, 1);
    gRadarMobileTimer = SetTimer("Radar_RelocateMobileRadars", RADAR_MOBILE_ROTATE_INTERVAL, 1);
    Gm_WriteIntegrityReport();
    AtualizarHostname();
    return 1;
}

public OnGameModeExit()
{
    FlushAccountSaves(1);
    SaveAllLoggedAccounts();

    if (gHudTimer)
    {
        KillTimer(gHudTimer);
    }

    if (gHostnameTimer)
    {
        KillTimer(gHostnameTimer);
    }

    Climate_Exit();
    Tolls_Exit();
    Fuel_Exit();

    if (gAutoSaveTimer)
    {
        KillTimer(gAutoSaveTimer);
    }

    if (gNeedsTimer)
    {
        KillTimer(gNeedsTimer);
    }

    if (gFuelTimer)
    {
        KillTimer(gFuelTimer);
    }

    if (gPoliceTimer)
    {
        KillTimer(gPoliceTimer);
    }

    if (gPoliceIdTimer)
    {
        KillTimer(gPoliceIdTimer);
        gPoliceIdTimer = 0;
    }

    if (gRadarTimer)
    {
        KillTimer(gRadarTimer);
    }

    if (gRadarMobileTimer)
    {
        KillTimer(gRadarMobileTimer);
    }

    Bot_Exit();
    Police_DestroyAllIdLabels();
    AmbientNpc_Exit();
    Vip_Exit();
    Radio_Exit();
    Security_Exit();
    SelfHeal_Exit();
    Life_Exit();
    Crime_Exit();
    MapObjects_Exit();
    Work_DestroyConfigVehicles();
    Police_DestroyAllBlitz();
    Property_Exit();
    DestroyWorldInteractionLabels();
    Radar_DestroyAllLabels();
    return 1;
}

public OnPlayerConnect(playerid)
{
    ResetPlayerData(playerid);
    Gm_ClearPlayerLastAction(playerid);
    Dealership_ResetPlayerVehicles(playerid);
    ResetPlayerMenuData(playerid);
    Property_ResetPlayer(playerid);
    Bot_ResetPlayer(playerid);
    Radio_ResetPlayer(playerid);
    Security_ResetPlayer(playerid);
    Police_ResetPlayer(playerid);
    Crime_ResetPlayer(playerid);
    gPlayerConnected[playerid] = 1;
    AtualizarHostname();

    if (IsPlayerNPC(playerid))
    {
        AmbientNpc_OnConnect(playerid);
        return 1;
    }

    Climate_ApplyToPlayer(playerid);

    if (!Security_CanPlayerConnect(playerid))
    {
        return 1;
    }

    if (!Ops_CanPlayerConnect(playerid))
    {
        return 1;
    }

    SendClientMessage(playerid, COLOR_WHITE, "Bem-vindo. Faca login ou cadastre sua conta para jogar.");
    ShowAuthDialog(playerid);
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    new saved;
    new actionDetail[40];

    if (IsPlayerNPC(playerid))
    {
        AmbientNpc_OnDisconnect(playerid);
        Police_DestroyIdLabelsForTarget(playerid);
        ResetPlayerData(playerid);
        AtualizarHostname();
        return 1;
    }

    DestroyPlayerHud(playerid);
    ClearPlayerMapIcons(playerid);
    Property_ClearPlayerMapIcons(playerid);
    Radar_ClearPlayerMapIcons(playerid);
    Tolls_ClearPlayerMapIcons(playerid);
    if (PlayerInfo[playerid][pLogged])
    {
        UpdatePlayerLiveData(playerid);
        Dealership_SaveActiveVehState(playerid);
    }
    Work_OnPlayerDisconnect(playerid);
    Dealership_OnPlayerDisconnect(playerid);
    Crime_ResetPlayer(playerid);
    Police_OnPlayerDisconnect(playerid);
    Hospital_OnPlayerDisconnect(playerid);
    Needs_OnPlayerDisconnect(playerid);
    Life_OnPlayerDisconnect(playerid);

    if (PlayerInfo[playerid][pLogged])
    {
        format(actionDetail, sizeof(actionDetail), "reason=%d", reason);
        Gm_RecordPlayerAction(playerid, "disconnect", actionDetail);
        UpdatePlayerLiveData(playerid);
        saved = SaveAccountNow(playerid, 0);
        if (!saved)
        {
            print("[SAVE] Falha ao salvar conta no disconnect.");
        }
        PlayerInfo[playerid][pLogged] = 0;
    }

    ResetPlayerData(playerid);
    Gm_ClearPlayerLastAction(playerid);
    ResetPlayerMenuData(playerid);
    Bot_ResetPlayer(playerid);
    Radio_ResetPlayer(playerid);
    Tolls_ResetPlayer(playerid);
    Security_ResetPlayer(playerid);
    AtualizarHostname();
    return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
    if (IsPlayerNPC(playerid))
    {
        return AmbientNpc_OnRequestClass(playerid);
    }

    SetupPlayerForClassSelection(playerid);

    if (classid >= 0 && classid < sizeof(gClassSkins))
    {
        PlayerInfo[playerid][pSkin] = gClassSkins[classid];
    }

    if (!PlayerInfo[playerid][pLogged] && gPlayerAuthDialog[playerid] == 0)
    {
        ShowAuthDialog(playerid);
    }
    return 1;
}

public OnPlayerRequestSpawn(playerid)
{
    if (!IsValidConnectedPlayer(playerid))
    {
        return 0;
    }

    if (IsPlayerNPC(playerid))
    {
        return AmbientNpc_OnRequestSpawn(playerid);
    }

    if (!PlayerInfo[playerid][pLogged])
    {
        ShowAuthDialog(playerid);
        return 0;
    }

    return 1;
}

public OnPlayerSpawn(playerid)
{
    new actionDetail[64];

    if (IsPlayerNPC(playerid))
    {
        return AmbientNpc_OnSpawn(playerid);
    }

    if (!gPlayerConnected[playerid] || !PlayerInfo[playerid][pLogged])
    {
        return 1;
    }

    format(actionDetail, sizeof(actionDetail), "interior=%d world=%d", GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid));
    Gm_RecordPlayerAction(playerid, "spawn", actionDetail);
    CreatePlayerHud(playerid);
    SetupPlayerMapIcons(playerid);
    Property_SetupPlayerMapIcons(playerid);
    Radar_SetupPlayerMapIcons(playerid);
    Tolls_SetupPlayerMapIcons(playerid);
    SetupPlayerForSpawn(playerid);
    if (Police_OnPlayerSpawn(playerid))
    {
        Needs_OnPlayerSpawn(playerid);
        Life_OnPlayerSpawn(playerid);
        UpdatePlayerHud(playerid);
        Security_OnPlayerSpawn(playerid);
        Tutorial_OnPlayerSpawn(playerid);
        return 1;
    }

    if (!Hospital_OnPlayerSpawn(playerid))
    {
        if (!Property_OnPlayerSpawn(playerid))
        {
            SendClientMessage(playerid, COLOR_GREEN, "Voce nasceu no spawn principal do servidor.");
        }
    }
    Needs_OnPlayerSpawn(playerid);
    Life_OnPlayerSpawn(playerid);
    UpdatePlayerHud(playerid);
    Security_OnPlayerSpawn(playerid);
    Tutorial_OnPlayerSpawn(playerid);
    return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
    new name[MAX_PLAYER_NAME + 1];
    new killerName[MAX_PLAYER_NAME + 1];
    new logLine[160];
    new validKiller;

    if (IsPlayerNPC(playerid))
    {
        return AmbientNpc_OnDeath(playerid, killerid, reason);
    }

    validKiller = (killerid != INVALID_PLAYER_ID && IsValidConnectedPlayer(killerid) && !IsPlayerNPC(killerid) && PlayerInfo[killerid][pLogged]);
    if (validKiller)
    {
        PlayerInfo[killerid][pKills]++;
        SendClientMessage(killerid, COLOR_GREEN, "Voce eliminou um jogador.");
    }

    PlayerInfo[playerid][pDeaths]++;
    GetPlayerNameEx(playerid, name, sizeof(name));
    if (validKiller)
    {
        GetPlayerNameEx(killerid, killerName, sizeof(killerName));
        format(logLine, sizeof(logLine), "player=%s id=%d killer=%s killer_id=%d reason=%d", name, playerid, killerName, killerid, reason);
    }
    else
    {
        format(logLine, sizeof(logLine), "player=%s id=%d killer=none reason=%d", name, playerid, reason);
    }
    WriteServerLog(LOG_DEATH_FILE, "DEATH", logLine);
    Work_OnPlayerDeath(playerid);
    Hospital_OnPlayerDeath(playerid);
    Life_OnPlayerDeath(playerid, validKiller ? (killerid) : (INVALID_PLAYER_ID), reason);
    SendClientMessage(playerid, COLOR_RED, "Voce morreu. Ao renascer, sera levado ao hospital.");
    return 1;
}

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
    #pragma unused bodypart

    if (!IsValidConnectedPlayer(playerid) || !IsValidConnectedPlayer(damagedid))
    {
        return 1;
    }

    if (IsPlayerNPC(damagedid) && AmbientNpc_IsManaged(damagedid))
    {
        return AmbientNpc_OnGiveDamage(playerid, damagedid, amount, weaponid);
    }
    return 1;
}

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
{
    #pragma unused bodypart

    if (!IsValidConnectedPlayer(playerid))
    {
        return 1;
    }
    if (issuerid != INVALID_PLAYER_ID && !IsValidConnectedPlayer(issuerid))
    {
        return 1;
    }

    if (IsPlayerNPC(playerid) && AmbientNpc_IsManaged(playerid))
    {
        return AmbientNpc_OnGiveDamage(issuerid, playerid, amount, weaponid);
    }
    return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
    if (IsPlayerNPC(playerid))
    {
        return 1;
    }

    if (Life_ServiceCall_Complete(playerid))
    {
        return 1;
    }

    if (Life_PublicMission_OnCheckpoint(playerid))
    {
        return 1;
    }

    if (Life_Logistics_OnCheckpoint(playerid))
    {
        return 1;
    }

    if (Work_OnCheckpoint(playerid))
    {
        return 1;
    }

    if (Police_OnPlayerEnterCheckpoint(playerid))
    {
        return 1;
    }

    if (Crime_OnPlayerEnterCheckpoint(playerid))
    {
        return 1;
    }

    World_OnPlayerEnterCheckpoint(playerid);
    return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (IsPlayerNPC(playerid))
    {
        return 1;
    }

    if (Police_OnPlayerKeyStateChange(playerid, newkeys, oldkeys))
    {
        return 1;
    }

    if (MapObj_OnKeyStateChange(playerid, newkeys, oldkeys))
    {
        return 1;
    }

    if (Fuel_OnPlayerKeyStateChange(playerid, newkeys, oldkeys))
    {
        return 1;
    }

    World_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
    return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
    new actionDetail[48];

    if (IsPlayerNPC(playerid))
    {
        return AmbientNpc_OnStateChange(playerid, newstate);
    }

    format(actionDetail, sizeof(actionDetail), "old=%d new=%d", oldstate, newstate);
    Gm_RecordPlayerAction(playerid, "state_change", actionDetail);

    if (AmbientNpc_OnHumanStateChange(playerid, newstate))
    {
        return 1;
    }

    if (Dealership_OnPlayerStateChange(playerid, newstate, oldstate))
    {
        return 1;
    }

    if (JobVehicle_OnPlayerStateChange(playerid, newstate, oldstate))
    {
        return 1;
    }

    Fuel_OnPlayerStateChange(playerid, newstate, oldstate);
    Radio_OnPlayerStateChange(playerid, newstate, oldstate);
    HandlePlayerSpeedometerState(playerid, newstate, oldstate);
    return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    new actionDetail[56];

    if (IsPlayerNPC(playerid))
    {
        return 1;
    }

    format(actionDetail, sizeof(actionDetail), "vehicle=%d passenger=%d", vehicleid, ispassenger);
    Gm_RecordPlayerAction(playerid, "enter_vehicle", actionDetail);

    if (AmbientNpc_OnHumanEnterVehicle(playerid, vehicleid))
    {
        return 1;
    }

    Dealership_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
    JobVehicle_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
    return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
    JobVehicle_OnVehicleDeath(vehicleid);
    Dealership_OnVehicleDeath(vehicleid, killerid);
    Radio_OnVehicleDestroyed(vehicleid);
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    new actionDetail[72];

    if (!IsValidConnectedPlayer(playerid))
    {
        return 1;
    }

    if (IsPlayerNPC(playerid))
    {
        return 1;
    }

    format(actionDetail, sizeof(actionDetail), "dialog=%d response=%d item=%d", dialogid, response, listitem);
    Gm_RecordPlayerAction(playerid, "dialog", actionDetail);

    if (dialogid == DIALOG_LOGIN_MENU)
    {
        if (!response || listitem == 2)
        {
            Kick(playerid);
            return 1;
        }
        if (listitem == 0)
        {
            return ShowLoginPasswordDialog(playerid);
        }
        if (listitem == 1)
        {
            return Account_ShowLoginPassChangeDlg(playerid);
        }
        return ShowAuthDialog(playerid);
    }

    if (dialogid == DIALOG_LOGIN)
    {
        gPlayerAuthDialog[playerid] = 0;

        if (!response)
        {
            return ShowAuthDialog(playerid);
        }

        if (!VerifyAccountPassword(playerid, inputtext))
        {
            gPlayerLoginTries[playerid]++;
            SendClientMessage(playerid, COLOR_RED, "Senha incorreta.");

            if (gPlayerLoginTries[playerid] >= MAX_LOGIN_TRIES)
            {
                SendClientMessage(playerid, COLOR_RED, "Voce excedeu o limite de tentativas.");
                Kick(playerid);
                return 1;
            }

            ShowAuthDialog(playerid);
            return 1;
        }

        if (!LoadAccount(playerid))
        {
            SendClientMessage(playerid, COLOR_RED, "Nao foi possivel carregar sua conta.");
            Kick(playerid);
            return 1;
        }

        SendClientMessage(playerid, COLOR_GREEN, "Login efetuado com sucesso.");
        FinishPlayerAuth(playerid);
        return 1;
    }

    if (dialogid == DIALOG_REGISTER)
    {
        gPlayerAuthDialog[playerid] = 0;

        if (!response)
        {
            Kick(playerid);
            return 1;
        }

        if (strlen(inputtext) < PASSWORD_MIN_LENGTH)
        {
            SendClientMessage(playerid, COLOR_RED, "Sua senha precisa ter pelo menos 4 caracteres.");
            ShowAuthDialog(playerid);
            return 1;
        }

        if (!CreateAccount(playerid, inputtext))
        {
            SendClientMessage(playerid, COLOR_RED, "Nao foi possivel salvar sua conta. Avise a administracao.");
            Kick(playerid);
            return 1;
        }

        SendClientMessage(playerid, COLOR_GREEN, "Conta cadastrada com sucesso.");
        FinishPlayerAuth(playerid);
        return 1;
    }

    if (dialogid == DIALOG_CHANGE_PASS_CURRENT || dialogid == DIALOG_CHANGE_PASS_NEW || dialogid == DIALOG_CHANGE_PASS_CONFIRM)
    {
        Account_HandlePassChangeDlg(playerid, dialogid, response, inputtext);
        return 1;
    }

    if (!PlayerInfo[playerid][pLogged])
    {
        ShowAuthDialog(playerid);
        return 1;
    }

    if (dialogid == DIALOG_RP_NAME)
    {
        HandleCharacterNameDialog(playerid, response, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_RENAME_ACCOUNT_NAME)
    {
        Account_HandleRenameNameDlg(playerid, response, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_RENAME_ACCOUNT_PASS)
    {
        Account_HandleRenamePassDlg(playerid, response, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_GPS)
    {
        HandleGpsDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_CITYHALL)
    {
        HandleCityHallDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_CITYHALL_RENAME)
    {
        HandleCityHallRenameDialog(playerid, response, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_DEALERSHIP)
    {
        HandleDealershipDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_DETRAN_MENU)
    {
        HandleDetranDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_DETRAN_PLATE)
    {
        HandleDetranPlateDlg(playerid, response, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_DETRAN_TRANSFER)
    {
        HandleDetranTransferDlg(playerid, response, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_GARAGE_LIST)
    {
        HandleGarageDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_BLITZ_MENU)
    {
        Police_HandleBlitzDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_BLITZ_FINE)
    {
        Police_HandleBlitzFineDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_POLICE_ARREST_CRIME)
    {
        Police_HandleArrestCrimeDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_POLICE_SEARCH)
    {
        return 1;
    }

    if (dialogid == DIALOG_VIP_MENU)
    {
        HandleVipDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_VIP_PLANS)
    {
        return 1;
    }

    if (dialogid == DIALOG_CLIMATE_INFO)
    {
        return 1;
    }

    if (dialogid == DIALOG_MAP_OBJECT_LIST)
    {
        MapObj_HandleStaticDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_MAP_GATE_LIST)
    {
        MapObj_HandleGateDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_MAP_GATE_JOB)
    {
        MapObj_HandleGateJobDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_EDIT_MAP_PANEL)
    {
        HandleEditMapDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_TOLL_CREATE_MENU)
    {
        HandleTollCreateDialog(playerid, response, listitem);
        return 1;
    }
    if (dialogid == DIALOG_EDIT_HOUSE_CREATE)
    {
        Prop_HandleEditHouseDlg(playerid, response, listitem);
        return 1;
    }
    if (dialogid == DIALOG_EDIT_BUSINESS_CREATE)
    {
        Prop_HandleEditBizDlg(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_TOLL_GOTO_LIST)
    {
        Tolls_HandleGotoDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_MAP_GOTO_LIST)
    {
        MapObj_HandleGotoDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_JOBVEHICLE_GOTO_LIST)
    {
        JobVehicle_HandleGotoDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_CITYHALL_JOBS)
    {
        HandleJobSelectionDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_CITYHALL_LICENSES)
    {
        HandleCityHallLicenseDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_CITYHALL_JOB_PANEL)
    {
        HandleCityHallJobPanelDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_JOB_WORK)
    {
        HandleJobWorkDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_TRAFFIC_FINE)
    {
        Job_HandleTrafficFineDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_CONVENIENCE)
    {
        HandleConvenienceStoreDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_WEAPON_SHOP)
    {
        HandleWeaponShopDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_INVENTORY)
    {
        HandleInventoryDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_RESTAURANT)
    {
        HandleRestaurantDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_NPC_TRANSPORT)
    {
        HandleNpcTransportDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_BANK_MENU)
    {
        HandleBankMenuDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_BANK_DEPOSIT)
    {
        HandleBankDepositDialog(playerid, response, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_BANK_WITHDRAW)
    {
        HandleBankWithdrawDialog(playerid, response, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_BANK_PIX_TARGET)
    {
        HandleBankPixTargetDialog(playerid, response, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_BANK_PIX_AMOUNT)
    {
        HandleBankPixAmountDialog(playerid, response, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_BANK_MANAGER)
    {
        HandleBankManagerDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_BANK_LOAN)
    {
        HandleBankLoanDialog(playerid, response, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_PHONE_HOME)
    {
        HandlePhoneHomeDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_PHONE_GOV)
    {
        HandlePhoneGovDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_PHONE_PROPERTIES)
    {
        HandlePhonePropertiesDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_PHONE_PROPERTY)
    {
        HandlePhonePropertyDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_PHONE_DELIVERY)
    {
        HandlePhoneDeliveryDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_PHONE_RIDE)
    {
        HandlePhoneRideDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_RADIO_LIST)
    {
        Radio_HandleListDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_LIFE_DOCS || dialogid == DIALOG_LIFE_TAXES || dialogid == DIALOG_LIFE_JUSTICE || dialogid == DIALOG_LIFE_HEALTH || dialogid == DIALOG_LIFE_BUSINESS || dialogid == DIALOG_LIFE_MARKET || dialogid == DIALOG_LIFE_BILLS || dialogid == DIALOG_LIFE_CONTRACTS || dialogid == DIALOG_LIFE_CARTORIO || dialogid == DIALOG_LIFE_AUCTION || dialogid == DIALOG_LIFE_ECONOMY)
    {
        Life_HandleDialog(playerid, dialogid, response, listitem, inputtext);
        return 1;
    }

    if (
        dialogid == DIALOG_ACTIVITY_CENTER ||
        dialogid == DIALOG_DAILY_JOURNEY ||
        dialogid == DIALOG_WEEKLY_AGENDA ||
        dialogid == DIALOG_FIRST_JOURNEY ||
        dialogid == DIALOG_NEXT_STEP ||
        dialogid == DIALOG_PUBLIC_SERVICES ||
        dialogid == DIALOG_PUBLIC_CONSTITUTION ||
        dialogid == DIALOG_PUBLIC_WORKS ||
        dialogid == DIALOG_POLITICS_PANEL ||
        dialogid == DIALOG_CITYHALL_PANEL ||
        dialogid == DIALOG_LOGISTICS_PANEL ||
        dialogid == DIALOG_TRANSPARENCY_CENTER ||
        dialogid == DIALOG_SERVICE_CALL_CREATE ||
        dialogid == DIALOG_SERVICE_CALL_LIST
    )
    {
        Life_HandleDialog(playerid, dialogid, response, listitem, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_POLITICAL_DUTY_PANEL || dialogid == DIALOG_POLITICAL_VOTE_OFFICE || dialogid == DIALOG_POLITICAL_VOTE_CANDIDATE || dialogid == DIALOG_POLITICAL_ACTION_MENU || dialogid == DIALOG_POLITICAL_WORK_SELECT)
    {
        Life_HandleDialog(playerid, dialogid, response, listitem, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_POLITICAL_BUDGET_INPUT || dialogid == DIALOG_POLITICAL_QUICK_REASON || dialogid == DIALOG_POLITICAL_PROPOSAL_VOTE || dialogid == DIALOG_POLITICAL_MAIN_MENU || dialogid == DIALOG_POLITICAL_CANDIDATE_OFFICE || dialogid == DIALOG_POLITICAL_ADMIN_MENU)
    {
        Life_HandleDialog(playerid, dialogid, response, listitem, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_HELP_MAIN)
    {
        HandleHelpMainDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_HELP_CATEGORY)
    {
        HandleHelpCategoryDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_ADMIN_HELP)
    {
        HandleAdminHelpDialog(playerid, response);
        return 1;
    }

    if (dialogid == DIALOG_SERVER_GMX_CONFIRM)
    {
        Admin_HandleGmxConfirmDialog(playerid, response);
        return 1;
    }

    if (dialogid == DIALOG_CHANGELOG)
    {
        HandleChangelogDialog(playerid, response);
        return 1;
    }

    if (dialogid == DIALOG_CHANGELOG_MENU)
    {
        HandleChangelogMenuDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_MENU_MAIN)
    {
        HandlePlayerMenuMainDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_MENU_CATEGORY)
    {
        HandlePlayerMenuCategoryDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_TUTORIAL)
    {
        HandleTutorialDialog(playerid, response);
        return 1;
    }

    if (dialogid == DIALOG_BUG_REPORT_INPUT)
    {
        HandleBugReportInputDialog(playerid, response, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_BUG_REPORT_LIST)
    {
        HandleBugReportsListDialog(playerid, response, listitem);
        return 1;
    }

    if (dialogid == DIALOG_BUG_REPORT_DETAIL)
    {
        HandleBugReportDetailDialog(playerid, response);
        return 1;
    }

    if (dialogid == DIALOG_ADMIN_ACTION_INPUT)
    {
        HandleAdminActionInput(playerid, response, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_COMMAND_NOTFOUND_PICK || dialogid == DIALOG_COMMAND_NOTFOUND_TARGET || dialogid == DIALOG_COMMAND_NOTFOUND_MANUAL)
    {
        Dispatch_HandleNotFoundDialog(playerid, dialogid, response, listitem, inputtext);
        return 1;
    }

    if (dialogid == DIALOG_ADMINS_ONLINE)
    {
        return 1;
    }

    if (
        dialogid == DIALOG_SERVER_CHECK ||
        dialogid == DIALOG_SERVER_STATUS ||
        dialogid == DIALOG_WHITELIST_LIST ||
        dialogid == DIALOG_SECURITY_PANEL ||
        dialogid == DIALOG_BAN_LIST ||
        dialogid == DIALOG_ACTIVITY_CENTER ||
        dialogid == DIALOG_DAILY_JOURNEY ||
        dialogid == DIALOG_WEEKLY_AGENDA ||
        dialogid == DIALOG_CITY_EVENTS ||
        dialogid == DIALOG_CITY_PASS ||
        dialogid == DIALOG_WEEKLY_RANKING ||
        dialogid == DIALOG_DELIVERY_RANKING ||
        dialogid == DIALOG_TAXI_RANKING
    )
    {
        return 1;
    }

    if (dialogid == DIALOG_MECHANIC_RANKING || dialogid == DIALOG_PERSON_HISTORY || dialogid == DIALOG_CITY_NEWS || dialogid == DIALOG_WANTED_LIST)
    {
        return 1;
    }

    if (dialogid == DIALOG_GM_VERSION || dialogid == DIALOG_GM_HEALTH || dialogid == DIALOG_GM_RELEASE || dialogid == DIALOG_GM_INTEGRITY || dialogid == DIALOG_PLAYER_DEBUG || dialogid == DIALOG_WAR_ZONE || dialogid == DIALOG_GM_SELFTEST || dialogid == DIALOG_CONFIG_STATUS || dialogid == DIALOG_ECONOMY_TABLE)
    {
        return 1;
    }
    if (dialogid == DIALOG_COMMAND_NOTFOUNDS || dialogid == DIALOG_COMMAND_NOTFOUND_HISTORY || dialogid == DIALOG_POST_DEPLOY || dialogid == DIALOG_CMD_HOTFIX_PROMOTE || dialogid == DIALOG_POLICE_CENTRAL || dialogid == DIALOG_COMMAND_MODULES || dialogid == DIALOG_BALANCE_GM)
    {
        return 1;
    }

    return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
    new fixedCommand[144];
    new actionDetail[96];

    if (!IsValidConnectedPlayer(playerid))
    {
        return 1;
    }

    format(actionDetail, sizeof(actionDetail), "%s", cmdtext);
    Gm_RecordPlayerAction(playerid, "command", actionDetail);

    if (CommandHotfix_Rewrite(playerid, cmdtext, fixedCommand, sizeof(fixedCommand)))
    {
        DispatchPlayerCommandText(playerid, fixedCommand);
        return 1;
    }

    DispatchPlayerCommandText(playerid, cmdtext);
    return 1;
}

public AtualizarHostname()
{
    new str[128];
    new ano;
    new mes;
    new dia;
    new hora;
    new minuto;
    new segundo;

    GetBrasiliaDateTime(ano, mes, dia, hora, minuto, segundo);

    format(str, sizeof(str), "hostname %s | %02d:%02d | %s", gServerName, hora, minuto, gServerVersion);
    SendRconCommand(str);
    return 1;
}
