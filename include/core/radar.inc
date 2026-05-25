#if defined _nova_radar_included
    #endinput
#endif
#define _nova_radar_included

#define MAX_RADARS                  (64)
#define MAX_RADAR_MAP_ICONS         (28)
#define MAX_MOBILE_RADARS           (5)
#define RADAR_ICON_OFFSET           (70)
#define RADAR_MAP_ICON              (30)
#define RADAR_TYPE_FIXED            (1)
#define RADAR_TYPE_MANUAL           (2)
#define RADAR_TYPE_MOBILE           (3)

enum eRadarStreet
{
    radarStreetName[36],
    radarStreetLimit
}

enum eFixedRadar
{
    fixedName[32],
    fixedStreet,
    Float:fixedX,
    Float:fixedY,
    Float:fixedZ,
    fixedLimit
}

enum eMobileRadarCandidate
{
    candidateName[32],
    candidateStreet,
    Float:candidateX,
    Float:candidateY,
    Float:candidateZ,
    candidateLimit
}

enum eRadarData
{
    radarName[32],
    radarStreet,
    Float:radarX,
    Float:radarY,
    Float:radarZ,
    radarLimit,
    radarType,
    radarActive
}

new gRadarStreets[][eRadarStreet] =
{
    { "Centro / Prefeitura", 60 },
    { "Idlewood / Posto", 70 },
    { "Unity Station", 60 },
    { "Hospital / Jefferson", 50 },
    { "Concessionaria / Market", 60 },
    { "Porto / Cargas", 80 },
    { "Praia / Pier", 60 },
    { "Mulholland / Alta velocidade", 80 }
};

new gFixedRadars[][eFixedRadar] =
{
    { "Radar Prefeitura Norte", 0, 1480.4000, -1735.4000, 13.5469, 60 },
    { "Radar Commerce", 0, 1625.3000, -1720.2000, 13.5469, 60 },
    { "Radar Idlewood", 1, 1975.2000, -1752.3000, 13.5469, 70 },
    { "Radar Unity", 2, 1762.3000, -1863.2000, 13.5765, 60 },
    { "Radar Hospital", 3, 1184.6000, -1325.2000, 13.5748, 50 },
    { "Radar Concessionaria", 4, 2131.6000, -1158.4000, 24.1232, 60 },
    { "Radar Porto", 5, 2448.4000, -2094.2000, 13.5469, 80 },
    { "Radar Pier", 6, 388.8000, -2056.5000, 7.8359, 60 }
};

new gMobileRadarCandidates[][eMobileRadarCandidate] =
{
    { "Movel Prefeitura Sul", 0, 1447.2000, -1733.5000, 13.5469, 50 },
    { "Movel Commerce", 0, 1703.6000, -1721.8000, 13.5469, 60 },
    { "Movel Idlewood Leste", 1, 2048.4000, -1776.3000, 13.5469, 70 },
    { "Movel Idlewood Oeste", 1, 1888.9000, -1756.4000, 13.5469, 60 },
    { "Movel Terminal", 2, 1807.4000, -1908.8000, 13.5748, 60 },
    { "Movel Unity Norte", 2, 1708.4000, -1858.2000, 13.5765, 50 },
    { "Movel Hospital", 3, 1152.7000, -1324.6000, 13.5748, 50 },
    { "Movel Delegacia", 3, 1540.9000, -1675.8000, 13.5469, 50 },
    { "Movel Market", 4, 2089.6000, -1178.7000, 23.9936, 60 },
    { "Movel Concessionaria", 4, 2165.9000, -1148.5000, 24.1232, 60 },
    { "Movel Porto", 5, 2505.3000, -2090.1000, 13.5469, 80 },
    { "Movel Industrial", 5, 2366.9000, -2007.8000, 13.5469, 70 },
    { "Movel Pier", 6, 410.9000, -2028.2000, 7.8359, 60 },
    { "Movel Praia", 6, 326.5000, -1808.6000, 4.4844, 60 },
    { "Movel Mulholland", 7, 1328.3000, -936.2000, 36.1613, 80 },
    { "Movel Vinewood", 7, 1417.9000, -812.3000, 85.0000, 80 }
};

new gRadars[MAX_RADARS][eRadarData];
new Text3D:gRadarLabel[MAX_RADARS];
new gRadarCount;
new gRadarTimer;
new gRadarMobileTimer;
new gPlayerLastRadarTicketTick[MAX_PLAYERS];
new gPlayerLastRadarId[MAX_PLAYERS];
new gPlayerRadarIconVisible[MAX_PLAYERS][MAX_RADAR_MAP_ICONS];

forward Radar_UpdateAll();
forward Radar_RelocateMobileRadars();

stock Radar_Reset()
{
    new index;

    gRadarCount = 0;
    for (index = 0; index < MAX_RADARS; index++)
    {
        gRadars[index][radarActive] = 0;
        gRadarLabel[index] = Text3D:INVALID_3DTEXT_ID;
    }
    return 1;
}

stock Radar_GetStreetName(streetid, output[], size = sizeof(output))
{
    if (streetid < 0 || streetid >= sizeof(gRadarStreets))
    {
        format(output, size, "Rua desconhecida");
        return 0;
    }

    format(output, size, "%s", gRadarStreets[streetid][radarStreetName]);
    return 1;
}

stock Float:Radar_GetDistance2D(Float:x1, Float:y1, Float:x2, Float:y2)
{
    return floatsqroot(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

stock Radar_CountNearbyOnStreet(streetid, Float:x, Float:y)
{
    new index;
    new count;

    for (index = 0; index < gRadarCount; index++)
    {
        if (!gRadars[index][radarActive] || gRadars[index][radarStreet] != streetid)
        {
            continue;
        }

        if (Radar_GetDistance2D(x, y, gRadars[index][radarX], gRadars[index][radarY]) <= RADAR_MIN_STREET_DISTANCE)
        {
            count++;
        }
    }
    return count;
}

stock Radar_HasRadarNear(Float:x, Float:y, Float:radius)
{
    new index;

    for (index = 0; index < gRadarCount; index++)
    {
        if (!gRadars[index][radarActive])
        {
            continue;
        }

        if (Radar_GetDistance2D(x, y, gRadars[index][radarX], gRadars[index][radarY]) <= radius)
        {
            return 1;
        }
    }
    return 0;
}

stock Radar_CanPlaceOnStreet(streetid, Float:x, Float:y)
{
    if (streetid < 0 || streetid >= sizeof(gRadarStreets))
    {
        return 0;
    }

    return (Radar_CountNearbyOnStreet(streetid, x, y) < 2);
}

stock Radar_CreateLabel(index)
{
    new text[144];
    new typeName[16];
    new streetName[36];

    if (index < 0 || index >= MAX_RADARS || !gRadars[index][radarActive])
    {
        return 0;
    }

    if (gRadarLabel[index] != Text3D:INVALID_3DTEXT_ID)
    {
        Delete3DTextLabel(gRadarLabel[index]);
        gRadarLabel[index] = Text3D:INVALID_3DTEXT_ID;
    }

    switch (gRadars[index][radarType])
    {
        case RADAR_TYPE_FIXED: format(typeName, sizeof(typeName), "Fixo");
        case RADAR_TYPE_MOBILE: format(typeName, sizeof(typeName), "Movel");
        default: format(typeName, sizeof(typeName), "Manual");
    }

    Radar_GetStreetName(gRadars[index][radarStreet], streetName, sizeof(streetName));
    format(text, sizeof(text), "Radar %s\n%s\nLimite %d km/h", typeName, streetName, gRadars[index][radarLimit]);
    gRadarLabel[index] = Create3DTextLabel(text, COLOR_RED, gRadars[index][radarX], gRadars[index][radarY], gRadars[index][radarZ] + 1.2, 35.0, 0, 1);
    return 1;
}

stock Radar_AddRadar(name[], streetid, Float:x, Float:y, Float:z, limit, type, createLabel = 1)
{
    new index = gRadarCount;

    if (index >= MAX_RADARS)
    {
        return -1;
    }

    if (streetid < 0 || streetid >= sizeof(gRadarStreets))
    {
        return -1;
    }

    if (limit < 30 || limit > 140)
    {
        return -1;
    }

    format(gRadars[index][radarName], 32, "%s", name);
    gRadars[index][radarStreet] = streetid;
    gRadars[index][radarX] = x;
    gRadars[index][radarY] = y;
    gRadars[index][radarZ] = z;
    gRadars[index][radarLimit] = limit;
    gRadars[index][radarType] = type;
    gRadars[index][radarActive] = 1;
    gRadarLabel[index] = Text3D:INVALID_3DTEXT_ID;
    gRadarCount++;

    if (createLabel)
    {
        Radar_CreateLabel(index);
    }
    return index;
}

stock Radar_LoadFixedRadars()
{
    new index;

    for (index = 0; index < sizeof(gFixedRadars); index++)
    {
        Radar_AddRadar(
            gFixedRadars[index][fixedName],
            gFixedRadars[index][fixedStreet],
            gFixedRadars[index][fixedX],
            gFixedRadars[index][fixedY],
            gFixedRadars[index][fixedZ],
            gFixedRadars[index][fixedLimit],
            RADAR_TYPE_FIXED,
            0
        );
    }
    return 1;
}

stock Radar_SaveManualRadar(index)
{
    new File:file;
    new line[144];

    if (index < 0 || index >= gRadarCount || gRadars[index][radarType] != RADAR_TYPE_MANUAL)
    {
        return 0;
    }

    file = fopen(RADAR_MANUAL_FILE, io_append);
    if (!file)
    {
        return 0;
    }

    format(line, sizeof(line), "%.4f %.4f %.4f %d %d\r\n", gRadars[index][radarX], gRadars[index][radarY], gRadars[index][radarZ], gRadars[index][radarLimit], gRadars[index][radarStreet]);
    fwrite(file, line);
    fclose(file);
    return 1;
}

stock Radar_LoadManualRadars()
{
    new File:file;
    new line[144];
    new param[32];
    new indexPos;
    new Float:x;
    new Float:y;
    new Float:z;
    new limit;
    new streetid;

    if (!fexist(RADAR_MANUAL_FILE))
    {
        return 1;
    }

    file = fopen(RADAR_MANUAL_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        indexPos = 0;
        if (!GetNextParam(line, indexPos, param, sizeof(param))) continue;
        x = floatstr(param);
        if (!GetNextParam(line, indexPos, param, sizeof(param))) continue;
        y = floatstr(param);
        if (!GetNextParam(line, indexPos, param, sizeof(param))) continue;
        z = floatstr(param);
        if (!GetNextParam(line, indexPos, param, sizeof(param)) || !IsNumericString(param)) continue;
        limit = strval(param);
        if (!GetNextParam(line, indexPos, param, sizeof(param)) || !IsNumericString(param)) continue;
        streetid = strval(param);

        Radar_AddRadar("Radar Manual", streetid, x, y, z, limit, RADAR_TYPE_MANUAL, 0);
    }

    fclose(file);
    return 1;
}

stock Radar_DestroyMobileRadars()
{
    new index;

    for (index = 0; index < gRadarCount; index++)
    {
        if (gRadars[index][radarType] != RADAR_TYPE_MOBILE)
        {
            continue;
        }

        if (gRadarLabel[index] != Text3D:INVALID_3DTEXT_ID)
        {
            Delete3DTextLabel(gRadarLabel[index]);
            gRadarLabel[index] = Text3D:INVALID_3DTEXT_ID;
        }
        gRadars[index][radarActive] = 0;
    }
    return 1;
}

stock Radar_RebuildActiveList()
{
    new index;
    new writeIndex;

    for (index = 0; index < gRadarCount; index++)
    {
        if (!gRadars[index][radarActive])
        {
            continue;
        }

        if (writeIndex != index)
        {
            format(gRadars[writeIndex][radarName], 32, "%s", gRadars[index][radarName]);
            gRadars[writeIndex][radarStreet] = gRadars[index][radarStreet];
            gRadars[writeIndex][radarX] = gRadars[index][radarX];
            gRadars[writeIndex][radarY] = gRadars[index][radarY];
            gRadars[writeIndex][radarZ] = gRadars[index][radarZ];
            gRadars[writeIndex][radarLimit] = gRadars[index][radarLimit];
            gRadars[writeIndex][radarType] = gRadars[index][radarType];
            gRadars[writeIndex][radarActive] = gRadars[index][radarActive];
            gRadarLabel[writeIndex] = gRadarLabel[index];
            gRadarLabel[index] = Text3D:INVALID_3DTEXT_ID;
        }
        writeIndex++;
    }

    gRadarCount = writeIndex;
    return 1;
}

stock Radar_SetupPlayerMapIcons(playerid)
{
    Radar_UpdatePlayerMapIcons(playerid);
    return 1;
}

stock Radar_UpdatePlayerMapIcons(playerid)
{
    new index;
    new visible;

    for (index = 0; index < gRadarCount && index < MAX_RADAR_MAP_ICONS; index++)
    {
        if (!gRadars[index][radarActive])
        {
            if (gPlayerRadarIconVisible[playerid][index])
            {
                ManagedMapIcon_Remove(playerid, MAP_ICON_NS_RADAR, index);
                gPlayerRadarIconVisible[playerid][index] = 0;
            }
            continue;
        }

        visible = IsPlayerInRangeOfPoint(playerid, MAP_ICON_VISIBLE_RANGE, gRadars[index][radarX], gRadars[index][radarY], gRadars[index][radarZ]);
        if (visible && !gPlayerRadarIconVisible[playerid][index])
        {
            if (!ManagedMapIcon_Set(
                playerid,
                MAP_ICON_NS_RADAR,
                index,
                gRadars[index][radarX],
                gRadars[index][radarY],
                gRadars[index][radarZ],
                RADAR_MAP_ICON,
                COLOR_RED,
                MAPICON_LOCAL
            ))
            {
                continue;
            }
            gPlayerRadarIconVisible[playerid][index] = 1;
        }
        else if (!visible && gPlayerRadarIconVisible[playerid][index])
        {
            ManagedMapIcon_Remove(playerid, MAP_ICON_NS_RADAR, index);
            gPlayerRadarIconVisible[playerid][index] = 0;
        }
    }
    for (; index < MAX_RADAR_MAP_ICONS; index++)
    {
        if (gPlayerRadarIconVisible[playerid][index])
        {
            ManagedMapIcon_Remove(playerid, MAP_ICON_NS_RADAR, index);
            gPlayerRadarIconVisible[playerid][index] = 0;
        }
    }
    return 1;
}

stock Radar_ClearPlayerMapIcons(playerid)
{
    new index;

    for (index = 0; index < MAX_RADAR_MAP_ICONS; index++)
    {
        gPlayerRadarIconVisible[playerid][index] = 0;
    }
    ManagedMapIcon_ClearNamespace(playerid, MAP_ICON_NS_RADAR);
    return 1;
}

stock Radar_UpdateMapIconsForAll()
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid))
        {
            Radar_ClearPlayerMapIcons(playerid);
            Radar_UpdatePlayerMapIcons(playerid);
        }
    }
    return 1;
}

stock Radar_CreateAllLabels()
{
    new index;

    for (index = 0; index < gRadarCount; index++)
    {
        Radar_CreateLabel(index);
    }
    return 1;
}

stock Radar_DestroyAllLabels()
{
    new index;

    for (index = 0; index < MAX_RADARS; index++)
    {
        if (gRadarLabel[index] != Text3D:INVALID_3DTEXT_ID)
        {
            Delete3DTextLabel(gRadarLabel[index]);
            gRadarLabel[index] = Text3D:INVALID_3DTEXT_ID;
        }
    }
    return 1;
}

public Radar_RelocateMobileRadars()
{
    new placed;
    new attempts;
    new candidate;
    new index;

    Radar_DestroyMobileRadars();
    Radar_RebuildActiveList();

    while (placed < MAX_MOBILE_RADARS && attempts < 80)
    {
        attempts++;
        candidate = random(sizeof(gMobileRadarCandidates));

        if (Radar_HasRadarNear(gMobileRadarCandidates[candidate][candidateX], gMobileRadarCandidates[candidate][candidateY], 50.0))
        {
            continue;
        }

        if (!Radar_CanPlaceOnStreet(gMobileRadarCandidates[candidate][candidateStreet], gMobileRadarCandidates[candidate][candidateX], gMobileRadarCandidates[candidate][candidateY]))
        {
            continue;
        }

        index = Radar_AddRadar(
            gMobileRadarCandidates[candidate][candidateName],
            gMobileRadarCandidates[candidate][candidateStreet],
            gMobileRadarCandidates[candidate][candidateX],
            gMobileRadarCandidates[candidate][candidateY],
            gMobileRadarCandidates[candidate][candidateZ],
            gMobileRadarCandidates[candidate][candidateLimit],
            RADAR_TYPE_MOBILE,
            1
        );

        if (index != -1)
        {
            placed++;
        }
    }

    Radar_UpdateMapIconsForAll();
    printf("[Radar] Radares moveis reposicionados: %d", placed);
    return 1;
}

stock Radar_Init()
{
    Radar_Reset();
    Radar_LoadFixedRadars();
    Radar_LoadManualRadars();
    Radar_CreateAllLabels();
    Radar_RelocateMobileRadars();
    return 1;
}

stock Radar_GetTrafficFineData(overSpeed, limit, &severity, &multiplier)
{
    new percentOver;

    if (limit <= 0)
    {
        limit = 1;
    }

    percentOver = (overSpeed * 100) / limit;
    multiplier = 1;

    if (percentOver <= 20)
    {
        severity = TRAFFIC_FINE_MEDIUM;
    }
    else if (percentOver <= 50)
    {
        severity = TRAFFIC_FINE_SERIOUS;
    }
    else
    {
        severity = TRAFFIC_FINE_VERY_SERIOUS;
        multiplier = 3;
    }
    return 1;
}

stock Radar_AddPlayerFine(playerid, radarid, speed)
{
    new overSpeed = speed - gRadars[radarid][radarLimit];
    new severity;
    new multiplier;
    new points;
    new fine;
    new message[144];
    new streetName[36];
    new severityName[16];

    if (overSpeed <= RADAR_SPEED_TOLERANCE)
    {
        return 0;
    }
    if (Account_IsNewcomerProtected(playerid))
    {
        Radar_GetStreetName(gRadars[radarid][radarStreet], streetName, sizeof(streetName));
        format(message, sizeof(message), "Radar educativo: %s | %d/%d km/h. Multas liberam a partir do nivel 3.", streetName, speed, gRadars[radarid][radarLimit]);
        SendClientMessage(playerid, COLOR_YELLOW, message);
        GameTextForPlayer(playerid, "~y~AVISO DE RADAR~n~~w~Protecao de recem chegado", 3500, 3);
        return 1;
    }

    Radar_GetTrafficFineData(overSpeed, gRadars[radarid][radarLimit], severity, multiplier);
    Cfg_TrafficSeverityName(severity, severityName, sizeof(severityName));
    fine = Cfg_TrafficFine(severity, multiplier);
    points = Cfg_TrafficPoints(severity);
    if (fine > MAX_PLAYER_FINE)
    {
        fine = MAX_PLAYER_FINE;
    }

    PlayerInfo[playerid][pFines] += fine;
    if (PlayerInfo[playerid][pFines] > MAX_PLAYER_FINE)
    {
        PlayerInfo[playerid][pFines] = MAX_PLAYER_FINE;
    }
    PlayerInfo[playerid][pTrafficPoints] += points;
    if (PlayerInfo[playerid][pTrafficPoints] > MAX_TRAFFIC_POINTS)
    {
        PlayerInfo[playerid][pTrafficPoints] = MAX_TRAFFIC_POINTS;
    }
    Radar_GetStreetName(gRadars[radarid][radarStreet], streetName, sizeof(streetName));
    SaveAccountNow(playerid, 0);

    format(message, sizeof(message), "Radar: %s | %d/%d km/h | %s x%d | %d pts | Multa: $%d.", streetName, speed, gRadars[radarid][radarLimit], severityName, multiplier, points, fine);
    WritePlayerLog(LOG_MONEY_FILE, "RADAR_FINE", playerid, message);
    SendClientMessage(playerid, COLOR_RED, message);
    format(message, sizeof(message), "GovBR: multas $%d | pontos CNH %d. Use /celular > GovBR Online.", PlayerInfo[playerid][pFines], PlayerInfo[playerid][pTrafficPoints]);
    SendClientMessage(playerid, COLOR_ORANGE, message);
    GameTextForPlayer(playerid, "~r~MULTA DE RADAR~n~~w~Consulte no GovBR", 4000, 3);
    return 1;
}

stock Radar_CheckPlayer(playerid)
{
    new vehicleid;
    new speed;
    new index;
    new tick;

    if (!PlayerInfo[playerid][pLogged] || !IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        return 0;
    }

    if (GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
    {
        return 0;
    }

    vehicleid = GetPlayerVehicleID(playerid);
    if (!Fuel_IsMotorizedVehicle(vehicleid))
    {
        return 0;
    }

    if (Job_IsPublicServantOnDuty(playerid))
    {
        return 0;
    }

    speed = GetVehicleSpeedKmh(vehicleid);
    tick = GetTickCount();

    if (gPlayerLastRadarTicketTick[playerid] > 0 && (tick - gPlayerLastRadarTicketTick[playerid]) < 30000)
    {
        return 0;
    }

    for (index = 0; index < gRadarCount; index++)
    {
        if (!gRadars[index][radarActive])
        {
            continue;
        }

        if (speed <= (gRadars[index][radarLimit] + RADAR_SPEED_TOLERANCE))
        {
            continue;
        }

        if (!IsPlayerInRangeOfPoint(playerid, RADAR_RANGE, gRadars[index][radarX], gRadars[index][radarY], gRadars[index][radarZ]))
        {
            continue;
        }

        gPlayerLastRadarTicketTick[playerid] = tick;
        gPlayerLastRadarId[playerid] = index;
        Radar_AddPlayerFine(playerid, index, speed);
        return 1;
    }
    return 0;
}

public Radar_UpdateAll()
{
    new playerid;
    new maxPlayers = GetMaxPlayers();
    new startTick = GetTickCount();
    new scanned;
    new fined;

    if (gRadarCount <= 0)
    {
        Gm_RecordTimerMetric(GM_TIMER_RADAR, GetTickCount() - startTick, 0, 0);
        return 1;
    }

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && PlayerInfo[playerid][pLogged] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
        {
            scanned++;
            fined += Radar_CheckPlayer(playerid);
        }
    }
    Gm_RecordTimerMetric(GM_TIMER_RADAR, GetTickCount() - startTick, scanned, fined);
    return 1;
}

stock Radar_ShowGovFines(playerid)
{
    new message[144];

    format(message, sizeof(message), "GovBR Multas: pendente $%d | Pontos CNH %d | Procurado %d | Antecedentes %d.", PlayerInfo[playerid][pFines], PlayerInfo[playerid][pTrafficPoints], PlayerInfo[playerid][pWanted], PlayerInfo[playerid][pCriminalRecords]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    if (PlayerInfo[playerid][pFines] > 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Pague pelo app GovBR ou use /pagarmultas.");
    }
    else
    {
        SendClientMessage(playerid, COLOR_GREEN, "Nenhuma multa pendente no momento.");
    }
    return 1;
}

stock Radar_SendStreetList(playerid)
{
    new index;
    new message[128];

    SendClientMessage(playerid, COLOR_ORANGE, "Ruas para radar:");
    for (index = 0; index < sizeof(gRadarStreets); index++)
    {
        format(message, sizeof(message), "%d - %s | limite base %d km/h", index, gRadarStreets[index][radarStreetName], gRadarStreets[index][radarStreetLimit]);
        SendClientMessage(playerid, COLOR_ORANGE, message);
    }
    return 1;
}

stock Radar_SendAdminList(playerid)
{
    new index;
    new message[144];
    new streetName[36];
    new typeName[16];

    format(message, sizeof(message), "Radares ativos: %d | moveis trocam a cada %d min.", gRadarCount, RADAR_MOBILE_ROTATE_INTERVAL / 60000);
    SendClientMessage(playerid, COLOR_ORANGE, message);

    for (index = 0; index < gRadarCount; index++)
    {
        Radar_GetStreetName(gRadars[index][radarStreet], streetName, sizeof(streetName));
        switch (gRadars[index][radarType])
        {
            case RADAR_TYPE_FIXED: format(typeName, sizeof(typeName), "fixo");
            case RADAR_TYPE_MOBILE: format(typeName, sizeof(typeName), "movel");
            default: format(typeName, sizeof(typeName), "manual");
        }
        format(message, sizeof(message), "%d | %s | %s | %d km/h", index, typeName, streetName, gRadars[index][radarLimit]);
        SendClientMessage(playerid, COLOR_ORANGE, message);
    }
    return 1;
}

stock Radar_AddManualCommand(playerid, limit, streetid)
{
    new Float:x;
    new Float:y;
    new Float:z;
    new radarid;
    new message[144];
    new streetName[36];

    if (limit < 30 || limit > 140)
    {
        SendClientMessage(playerid, COLOR_RED, "Velocidade do radar deve ser entre 30 e 140 km/h.");
        return 1;
    }

    if (streetid < 0 || streetid >= sizeof(gRadarStreets))
    {
        SendClientMessage(playerid, COLOR_RED, "Rua invalida. Use /ruasradar para ver IDs.");
        return 1;
    }

    GetPlayerPos(playerid, x, y, z);
    if (!Radar_CanPlaceOnStreet(streetid, x, y))
    {
        SendClientMessage(playerid, COLOR_RED, "Esta rua ja possui dois radares em um raio de 500 metros. Escolha outro ponto ou outra rua.");
        return 1;
    }

    radarid = Radar_AddRadar("Radar Manual", streetid, x, y, z, limit, RADAR_TYPE_MANUAL, 1);
    if (radarid == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel adicionar radar. Limite interno atingido ou dados invalidos.");
        return 1;
    }

    if (!Radar_SaveManualRadar(radarid))
    {
        SendClientMessage(playerid, COLOR_RED, "Radar criado, mas nao foi possivel salvar em radares.txt.");
    }

    Radar_UpdateMapIconsForAll();
    Radar_GetStreetName(streetid, streetName, sizeof(streetName));
    format(message, sizeof(message), "Radar manual criado em %s com limite de %d km/h.", streetName, limit);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock HandleRadarAdminCommands(playerid, cmdtext[])
{
    new command[32];
    new param[32];
    new param2[32];
    new index;

    index = GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/ruasradar", true) == 0)
    {
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
        {
            return SendNoPermission(playerid);
        }

        Radar_SendStreetList(playerid);
        return 1;
    }

    if (strcmp(command, "/radares", true) == 0)
    {
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
        {
            return SendNoPermission(playerid);
        }

        Radar_SendAdminList(playerid);
        return 1;
    }

    if (strcmp(command, "/addradar", true) == 0 || strcmp(command, "/adicionarradar", true) == 0)
    {
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
        {
            return SendNoPermission(playerid);
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)) || !IsNumericString(param) || !IsNumericString(param2))
        {
            return SendUsage(playerid, "/addradar [limite] [rua_id]");
        }

        Radar_AddManualCommand(playerid, strval(param), strval(param2));
        return 1;
    }

    return 0;
}
