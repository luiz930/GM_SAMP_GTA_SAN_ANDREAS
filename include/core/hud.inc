#if defined _nova_hud_included
    #endinput
#endif
#define _nova_hud_included

new PlayerText:gHudCover[MAX_PLAYERS];
new PlayerText:gHudDateTime[MAX_PLAYERS];
new PlayerText:gHudMoney[MAX_PLAYERS];
new PlayerText:gHudHealth[MAX_PLAYERS];
new PlayerText:gHudLocation[MAX_PLAYERS];
new PlayerText:gHudTitle[MAX_PLAYERS];
new PlayerText:gHudJob[MAX_PLAYERS];
new PlayerText:gHudProgress[MAX_PLAYERS];
new PlayerText:gHudNeeds[MAX_PLAYERS];
new PlayerText:gHudRest[MAX_PLAYERS];
new PlayerText:gHudWeather[MAX_PLAYERS];
new PlayerText:gElectionCover[MAX_PLAYERS];
new PlayerText:gElectionTitle[MAX_PLAYERS];
new PlayerText:gElectionLineA[MAX_PLAYERS];
new PlayerText:gElectionLineB[MAX_PLAYERS];
new PlayerText:gElectionLineC[MAX_PLAYERS];
new PlayerText:gSpeedoCover[MAX_PLAYERS];
new PlayerText:gSpeedoTitle[MAX_PLAYERS];
new PlayerText:gSpeedoSpeed[MAX_PLAYERS];
new PlayerText:gSpeedoDetail[MAX_PLAYERS];
new PlayerText:gSpeedoRpm[MAX_PLAYERS];
new gPlayerHudCreated[MAX_PLAYERS];
new gPlayerSpeedometerVisible[MAX_PLAYERS];
new gPlayerElectionHudVisible[MAX_PLAYERS];
new gHudTimer;
new gHudLogicTick;

forward UpdateHudForAll();

stock CreateHudText(playerid, PlayerText:draw, color, Float:letterX, Float:letterY, font, alignment = 3)
{
    PlayerTextDrawUseBox(playerid, draw, 0);
    PlayerTextDrawLetterSize(playerid, draw, letterX, letterY);
    PlayerTextDrawFont(playerid, draw, font);
    PlayerTextDrawSetShadow(playerid, draw, 0);
    PlayerTextDrawSetOutline(playerid, draw, 1);
    PlayerTextDrawBackgroundColor(playerid, draw, 0x000000FF);
    PlayerTextDrawColor(playerid, draw, color);
    PlayerTextDrawAlignment(playerid, draw, alignment);
    return 1;
}

stock IsBicycleModel(modelid)
{
    switch (modelid)
    {
        case 481, 509, 510:
        {
            return 1;
        }
    }
    return 0;
}

stock IsMotorcycleModel(modelid)
{
    switch (modelid)
    {
        case 448, 461, 462, 463, 468, 471, 521, 522, 523, 581, 586:
        {
            return 1;
        }
    }
    return 0;
}

stock GetVehicleSpeedKmh(vehicleid)
{
    new Float:vx;
    new Float:vy;
    new Float:vz;
    new Float:speed;

    GetVehicleVelocity(vehicleid, vx, vy, vz);
    speed = floatsqroot((vx * vx) + (vy * vy) + (vz * vz)) * 180.0;
    return floatround(speed);
}

stock GetVehicleGear(speed)
{
    new gear;

    if (speed < 4)
    {
        return 0;
    }

    gear = (speed / 35) + 1;
    if (gear > 6)
    {
        gear = 6;
    }
    return gear;
}

stock GetVehicleRpm(speed, motorcycle)
{
    new rpm;

    if (motorcycle)
    {
        rpm = 1400 + (speed * 55) + random(240);
        if (rpm > 11500)
        {
            rpm = 11500;
        }
        return rpm;
    }

    rpm = 850 + (speed * 42) + random(180);
    if (rpm > 8200)
    {
        rpm = 8200;
    }
    return rpm;
}

stock Hud_FormatNeedBar(value, output[], size = sizeof(output))
{
    new filled = value / 20;

    if (filled < 0) filled = 0;
    if (filled > 5) filled = 5;

    switch (filled)
    {
        case 0: format(output, size, ".....");
        case 1: format(output, size, "|....");
        case 2: format(output, size, "||...");
        case 3: format(output, size, "|||..");
        case 4: format(output, size, "||||.");
        default: format(output, size, "|||||");
    }
    return 1;
}


stock ShowPlayerSpeedometer(playerid)
{
    if (gPlayerSpeedometerVisible[playerid])
    {
        return 1;
    }

    PlayerTextDrawShow(playerid, gSpeedoCover[playerid]);
    PlayerTextDrawShow(playerid, gSpeedoTitle[playerid]);
    PlayerTextDrawShow(playerid, gSpeedoSpeed[playerid]);
    PlayerTextDrawShow(playerid, gSpeedoDetail[playerid]);
    PlayerTextDrawShow(playerid, gSpeedoRpm[playerid]);
    gPlayerSpeedometerVisible[playerid] = 1;
    return 1;
}

stock HidePlayerSpeedometer(playerid)
{
    if (!gPlayerSpeedometerVisible[playerid])
    {
        return 1;
    }

    PlayerTextDrawHide(playerid, gSpeedoCover[playerid]);
    PlayerTextDrawHide(playerid, gSpeedoTitle[playerid]);
    PlayerTextDrawHide(playerid, gSpeedoSpeed[playerid]);
    PlayerTextDrawHide(playerid, gSpeedoDetail[playerid]);
    PlayerTextDrawHide(playerid, gSpeedoRpm[playerid]);
    gPlayerSpeedometerVisible[playerid] = 0;
    return 1;
}

stock ShowPlayerElectionHud(playerid)
{
    if (gPlayerElectionHudVisible[playerid])
    {
        return 1;
    }

    PlayerTextDrawShow(playerid, gElectionCover[playerid]);
    PlayerTextDrawShow(playerid, gElectionTitle[playerid]);
    PlayerTextDrawShow(playerid, gElectionLineA[playerid]);
    PlayerTextDrawShow(playerid, gElectionLineB[playerid]);
    PlayerTextDrawShow(playerid, gElectionLineC[playerid]);
    gPlayerElectionHudVisible[playerid] = 1;
    return 1;
}

stock HidePlayerElectionHud(playerid)
{
    if (!gPlayerElectionHudVisible[playerid])
    {
        return 1;
    }

    PlayerTextDrawHide(playerid, gElectionCover[playerid]);
    PlayerTextDrawHide(playerid, gElectionTitle[playerid]);
    PlayerTextDrawHide(playerid, gElectionLineA[playerid]);
    PlayerTextDrawHide(playerid, gElectionLineB[playerid]);
    PlayerTextDrawHide(playerid, gElectionLineC[playerid]);
    gPlayerElectionHudVisible[playerid] = 0;
    return 1;
}

stock CreatePlayerHud(playerid)
{
    if (gPlayerHudCreated[playerid])
    {
        return 1;
    }

    gHudCover[playerid] = CreatePlayerTextDraw(playerid, 456.0, 18.0, "LD_SPAC:white");
    PlayerTextDrawFont(playerid, gHudCover[playerid], 4);
    PlayerTextDrawTextSize(playerid, gHudCover[playerid], 180.0, 182.0);
    PlayerTextDrawColor(playerid, gHudCover[playerid], 0x000000DD);
    PlayerTextDrawBackgroundColor(playerid, gHudCover[playerid], 0x000000DD);

    gHudTitle[playerid] = CreatePlayerTextDraw(playerid, 628.0, 21.0, "SERVIDOR");
    CreateHudText(playerid, gHudTitle[playerid], 0xAAAAAAFF, 0.1900, 0.8000, 2);

    gHudDateTime[playerid] = CreatePlayerTextDraw(playerid, 628.0, 34.0, "00/00/0000 00:00");
    CreateHudText(playerid, gHudDateTime[playerid], 0xFFFFFFFF, 0.2500, 0.9500, 2);

    gHudMoney[playerid] = CreatePlayerTextDraw(playerid, 628.0, 48.0, "$0");
    CreateHudText(playerid, gHudMoney[playerid], 0x66CC66FF, 0.4400, 1.3500, 3);

    gHudHealth[playerid] = CreatePlayerTextDraw(playerid, 628.0, 68.0, "Vida 100% | Colete 0%");
    CreateHudText(playerid, gHudHealth[playerid], 0xE74C3CFF, 0.2300, 0.8500, 2);

    gHudWeather[playerid] = CreatePlayerTextDraw(playerid, 628.0, 84.0, "Clima: Ceu limpo 26C");
    CreateHudText(playerid, gHudWeather[playerid], 0x80BFFFFFFF, 0.2200, 0.8200, 2);

    gHudJob[playerid] = CreatePlayerTextDraw(playerid, 628.0, 100.0, "Profissao: Desempregado");
    CreateHudText(playerid, gHudJob[playerid], 0xF1C40FFF, 0.2300, 0.8500, 2);

    gHudProgress[playerid] = CreatePlayerTextDraw(playerid, 628.0, 116.0, "Nivel 1 | XP 0/4");
    CreateHudText(playerid, gHudProgress[playerid], 0xDDDDDDFF, 0.2300, 0.8500, 2);

    gHudNeeds[playerid] = CreatePlayerTextDraw(playerid, 628.0, 134.0, "Fome 100% | Sede 100%");
    CreateHudText(playerid, gHudNeeds[playerid], 0xF39C12FF, 0.2300, 0.8500, 2);

    gHudRest[playerid] = CreatePlayerTextDraw(playerid, 628.0, 150.0, "Cans [.....] Sono [.....]");
    CreateHudText(playerid, gHudRest[playerid], 0xC39BD3FF, 0.2200, 0.8200, 2);

    gHudLocation[playerid] = CreatePlayerTextDraw(playerid, 628.0, 168.0, "San Andreas");
    CreateHudText(playerid, gHudLocation[playerid], 0x80BFFFFFFF, 0.2500, 0.9000, 2);

    gElectionCover[playerid] = CreatePlayerTextDraw(playerid, 456.0, 208.0, "LD_SPAC:white");
    PlayerTextDrawFont(playerid, gElectionCover[playerid], 4);
    PlayerTextDrawTextSize(playerid, gElectionCover[playerid], 180.0, 72.0);
    PlayerTextDrawColor(playerid, gElectionCover[playerid], 0x101018DD);
    PlayerTextDrawBackgroundColor(playerid, gElectionCover[playerid], 0x101018DD);

    gElectionTitle[playerid] = CreatePlayerTextDraw(playerid, 628.0, 212.0, "ELEICAO 60m");
    CreateHudText(playerid, gElectionTitle[playerid], 0xF1C40FFF, 0.2200, 0.8500, 2);

    gElectionLineA[playerid] = CreatePlayerTextDraw(playerid, 628.0, 228.0, "A [..........] 0%");
    CreateHudText(playerid, gElectionLineA[playerid], 0x66CC66FF, 0.2000, 0.7600, 2);

    gElectionLineB[playerid] = CreatePlayerTextDraw(playerid, 628.0, 244.0, "B [..........] 0%");
    CreateHudText(playerid, gElectionLineB[playerid], 0x80BFFFFFFF, 0.2000, 0.7600, 2);

    gElectionLineC[playerid] = CreatePlayerTextDraw(playerid, 628.0, 260.0, "C [..........] 0%");
    CreateHudText(playerid, gElectionLineC[playerid], 0xF39C12FF, 0.2000, 0.7600, 2);

    gSpeedoCover[playerid] = CreatePlayerTextDraw(playerid, 462.0, 336.0, "LD_SPAC:white");
    PlayerTextDrawFont(playerid, gSpeedoCover[playerid], 4);
    PlayerTextDrawTextSize(playerid, gSpeedoCover[playerid], 166.0, 74.0);
    PlayerTextDrawColor(playerid, gSpeedoCover[playerid], 0x050505DD);
    PlayerTextDrawBackgroundColor(playerid, gSpeedoCover[playerid], 0x050505DD);

    gSpeedoTitle[playerid] = CreatePlayerTextDraw(playerid, 620.0, 340.0, "PAINEL DIGITAL");
    CreateHudText(playerid, gSpeedoTitle[playerid], 0x80BFFFFFFF, 0.2300, 0.8500, 2);

    gSpeedoSpeed[playerid] = CreatePlayerTextDraw(playerid, 620.0, 354.0, "000 KM/H");
    CreateHudText(playerid, gSpeedoSpeed[playerid], 0xFFFFFFFF, 0.6200, 2.0000, 3);

    gSpeedoDetail[playerid] = CreatePlayerTextDraw(playerid, 620.0, 382.0, "AUTO | FUEL");
    CreateHudText(playerid, gSpeedoDetail[playerid], 0xDDDDDDFF, 0.2400, 0.9000, 2);

    gSpeedoRpm[playerid] = CreatePlayerTextDraw(playerid, 620.0, 396.0, "RPM 0000");
    CreateHudText(playerid, gSpeedoRpm[playerid], 0xF1C40FFF, 0.2400, 0.9000, 2);

    PlayerTextDrawShow(playerid, gHudCover[playerid]);
    PlayerTextDrawShow(playerid, gHudTitle[playerid]);
    PlayerTextDrawShow(playerid, gHudDateTime[playerid]);
    PlayerTextDrawShow(playerid, gHudMoney[playerid]);
    PlayerTextDrawShow(playerid, gHudHealth[playerid]);
    PlayerTextDrawShow(playerid, gHudWeather[playerid]);
    PlayerTextDrawShow(playerid, gHudJob[playerid]);
    PlayerTextDrawShow(playerid, gHudProgress[playerid]);
    PlayerTextDrawShow(playerid, gHudNeeds[playerid]);
    PlayerTextDrawShow(playerid, gHudRest[playerid]);
    PlayerTextDrawShow(playerid, gHudLocation[playerid]);

    gPlayerHudCreated[playerid] = 1;
    gPlayerSpeedometerVisible[playerid] = 0;
    gPlayerElectionHudVisible[playerid] = 0;
    return 1;
}

stock DestroyPlayerHud(playerid)
{
    if (!gPlayerHudCreated[playerid])
    {
        return 1;
    }

    HidePlayerSpeedometer(playerid);
    HidePlayerElectionHud(playerid);
    PlayerTextDrawDestroy(playerid, gHudCover[playerid]);
    PlayerTextDrawDestroy(playerid, gHudTitle[playerid]);
    PlayerTextDrawDestroy(playerid, gHudDateTime[playerid]);
    PlayerTextDrawDestroy(playerid, gHudMoney[playerid]);
    PlayerTextDrawDestroy(playerid, gHudHealth[playerid]);
    PlayerTextDrawDestroy(playerid, gHudWeather[playerid]);
    PlayerTextDrawDestroy(playerid, gHudJob[playerid]);
    PlayerTextDrawDestroy(playerid, gHudProgress[playerid]);
    PlayerTextDrawDestroy(playerid, gHudNeeds[playerid]);
    PlayerTextDrawDestroy(playerid, gHudRest[playerid]);
    PlayerTextDrawDestroy(playerid, gHudLocation[playerid]);
    PlayerTextDrawDestroy(playerid, gElectionCover[playerid]);
    PlayerTextDrawDestroy(playerid, gElectionTitle[playerid]);
    PlayerTextDrawDestroy(playerid, gElectionLineA[playerid]);
    PlayerTextDrawDestroy(playerid, gElectionLineB[playerid]);
    PlayerTextDrawDestroy(playerid, gElectionLineC[playerid]);
    PlayerTextDrawDestroy(playerid, gSpeedoCover[playerid]);
    PlayerTextDrawDestroy(playerid, gSpeedoTitle[playerid]);
    PlayerTextDrawDestroy(playerid, gSpeedoSpeed[playerid]);
    PlayerTextDrawDestroy(playerid, gSpeedoDetail[playerid]);
    PlayerTextDrawDestroy(playerid, gSpeedoRpm[playerid]);

    gPlayerHudCreated[playerid] = 0;
    gPlayerSpeedometerVisible[playerid] = 0;
    gPlayerElectionHudVisible[playerid] = 0;
    return 1;
}

stock UpdatePlayerSpeedometer(playerid)
{
    new string[96];
    new vehicleid;
    new modelid;
    new speed;
    new rpm;
    new fuel;

    if (!gPlayerHudCreated[playerid] || !IsPlayerInAnyVehicle(playerid))
    {
        HidePlayerSpeedometer(playerid);
        return 1;
    }

    vehicleid = GetPlayerVehicleID(playerid);
    modelid = GetVehicleModel(vehicleid);
    speed = GetVehicleSpeedKmh(vehicleid);
    fuel = Fuel_GetVehicleFuel(vehicleid);
    ShowPlayerSpeedometer(playerid);

    if (IsBicycleModel(modelid))
    {
        PlayerTextDrawColor(playerid, gSpeedoCover[playerid], 0x082015DD);
        PlayerTextDrawSetString(playerid, gSpeedoTitle[playerid], "BICICLETA");
        format(string, sizeof(string), "%03d KM/H", speed);
        PlayerTextDrawSetString(playerid, gSpeedoSpeed[playerid], string);
        format(string, sizeof(string), "PEDAL | CAD %d", speed * 2);
        PlayerTextDrawSetString(playerid, gSpeedoDetail[playerid], string);
        PlayerTextDrawSetString(playerid, gSpeedoRpm[playerid], "SEM MOTOR | FUEL --");
        return 1;
    }

    rpm = GetVehicleRpm(speed, IsMotorcycleModel(modelid));

    if (IsMotorcycleModel(modelid))
    {
        PlayerTextDrawColor(playerid, gSpeedoCover[playerid], 0x120B1CDD);
        PlayerTextDrawSetString(playerid, gSpeedoTitle[playerid], "MOTO DIGITAL");
    }
    else
    {
        PlayerTextDrawColor(playerid, gSpeedoCover[playerid], 0x050505DD);
        PlayerTextDrawSetString(playerid, gSpeedoTitle[playerid], "PAINEL DIGITAL");
    }

    format(string, sizeof(string), "%03d KM/H", speed);
    PlayerTextDrawSetString(playerid, gSpeedoSpeed[playerid], string);

    if (Fuel_IsElectricVehicle(vehicleid))
    {
        format(string, sizeof(string), "AUTO | BAT %d%%", fuel);
        PlayerTextDrawSetString(playerid, gSpeedoDetail[playerid], string);
    }
    else
    {
        format(string, sizeof(string), "AUTO | FUEL %d%%", fuel);
        PlayerTextDrawSetString(playerid, gSpeedoDetail[playerid], string);
    }

    format(string, sizeof(string), "RPM %04d | %s", rpm, Fuel_IsEngineOn(vehicleid) ? ("ON") : ("OFF"));
    PlayerTextDrawSetString(playerid, gSpeedoRpm[playerid], string);
    return 1;
}

stock UpdatePlayerElectionHud(playerid)
{
    new title[96];
    new lineA[128];
    new lineB[128];
    new lineC[128];

    if (!gPlayerHudCreated[playerid])
    {
        return 1;
    }

    if (!Life_FormatElectionHud(title, sizeof(title), lineA, sizeof(lineA), lineB, sizeof(lineB), lineC, sizeof(lineC)))
    {
        HidePlayerElectionHud(playerid);
        return 1;
    }

    PlayerTextDrawSetString(playerid, gElectionTitle[playerid], title);
    PlayerTextDrawSetString(playerid, gElectionLineA[playerid], lineA);
    PlayerTextDrawSetString(playerid, gElectionLineB[playerid], lineB);
    PlayerTextDrawSetString(playerid, gElectionLineC[playerid], lineC);
    ShowPlayerElectionHud(playerid);
    return 1;
}

stock HandlePlayerSpeedometerState(playerid, newstate, oldstate)
{
    if (newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
    {
        UpdatePlayerSpeedometer(playerid);
        return 1;
    }

    if (oldstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_PASSENGER)
    {
        HidePlayerSpeedometer(playerid);
    }
    return 1;
}

stock UpdatePlayerHud(playerid)
{
    new string[128];
    new location[48];
    new jobName[32];
    new year;
    new month;
    new day;
    new hour;
    new minute;
    new second;
    new fatigueBar[8];
    new sleepBar[8];
    new rankName[24];
    new Float:health;
    new Float:armour;
    new healthValue;
    new armourValue;

    if (!gPlayerHudCreated[playerid])
    {
        return 1;
    }

    format(string, sizeof(string), "%s | %s", gServerName, gServerVersion);
    PlayerTextDrawSetString(playerid, gHudTitle[playerid], string);

    GetBrasiliaDateTime(year, month, day, hour, minute, second);
    format(string, sizeof(string), "%02d/%02d/%04d %02d:%02d", day, month, year, hour, minute);
    PlayerTextDrawSetString(playerid, gHudDateTime[playerid], string);

    format(string, sizeof(string), "$%d", GetPlayerMoney(playerid));
    PlayerTextDrawSetString(playerid, gHudMoney[playerid], string);

    GetPlayerHealth(playerid, health);
    GetPlayerArmour(playerid, armour);
    healthValue = floatround(health);
    armourValue = floatround(armour);
    if (healthValue < 0) healthValue = 0;
    if (healthValue > 100) healthValue = 100;
    if (armourValue < 0) armourValue = 0;
    if (armourValue > 100) armourValue = 100;
    format(string, sizeof(string), "Vida %d%% | Colete %d%%", healthValue, armourValue);
    PlayerTextDrawSetString(playerid, gHudHealth[playerid], string);

    Climate_FormatHud(string, sizeof(string));
    PlayerTextDrawSetString(playerid, gHudWeather[playerid], string);

    GetJobName(PlayerInfo[playerid][pJob], jobName, sizeof(jobName));
    format(string, sizeof(string), "Profissao: %s", jobName);
    PlayerTextDrawSetString(playerid, gHudJob[playerid], string);

    if (PlayerInfo[playerid][pJailTime] > 0)
    {
        format(string, sizeof(string), "Prisao: %02d:%02d | Crime ID %d", PlayerInfo[playerid][pJailTime] / 60, PlayerInfo[playerid][pJailTime] % 60, PlayerInfo[playerid][pJailCrimeId]);
    }
    else
    {
        Account_GetPlayerRankName(playerid, rankName, sizeof(rankName));
        format(string, sizeof(string), "N%d %s | XP %d/%d", PlayerInfo[playerid][pLevel], rankName, PlayerInfo[playerid][pExperience], gCfgCharacterXpPerLevel);
    }
    PlayerTextDrawSetString(playerid, gHudProgress[playerid], string);

    format(string, sizeof(string), "Fome %d%% | Sede %d%%", PlayerInfo[playerid][pHunger], PlayerInfo[playerid][pThirst]);
    PlayerTextDrawSetString(playerid, gHudNeeds[playerid], string);

    Hud_FormatNeedBar(PlayerInfo[playerid][pFatigue], fatigueBar, sizeof(fatigueBar));
    Hud_FormatNeedBar(PlayerInfo[playerid][pSleep], sleepBar, sizeof(sleepBar));
    format(string, sizeof(string), "Cans %d%% [%s] | Sono %d%% [%s]", PlayerInfo[playerid][pFatigue], fatigueBar, PlayerInfo[playerid][pSleep], sleepBar);
    PlayerTextDrawSetString(playerid, gHudRest[playerid], string);

    GetPlayerLocationName(playerid, location, sizeof(location));
    PlayerTextDrawSetString(playerid, gHudLocation[playerid], location);

    UpdatePlayerSpeedometer(playerid);
    UpdatePlayerElectionHud(playerid);
    return 1;
}

public UpdateHudForAll()
{
    new playerid;
    new maxPlayers = GetMaxPlayers();
    new runInteriors;
    new runExperience;
    new startTick = GetTickCount();
    new scanned;
    new logicRuns;

    gHudLogicTick++;
    if (gHudLogicTick >= 3600)
    {
        gHudLogicTick = 0;
    }
    runInteriors = ((gHudLogicTick % 3) == 0);
    runExperience = ((gHudLogicTick % 30) == 0);

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && PlayerInfo[playerid][pLogged])
        {
            scanned++;
            if (runInteriors)
            {
                World_UpdatePlayerInteriors(playerid);
                logicRuns++;
            }
            if (runExperience)
            {
                UpdateTimedPlayerExperience(playerid);
                logicRuns++;
            }
            UpdatePlayerHud(playerid);
            UpdatePlayerMapIcons(playerid);
            Property_UpdatePlayerMapIcons(playerid);
            Radar_UpdatePlayerMapIcons(playerid);
            Tolls_UpdatePlayerMapIcons(playerid);
        }
    }

    Gm_RecordTimerMetric(GM_TIMER_HUD, GetTickCount() - startTick, scanned, logicRuns);
    return 1;
}
