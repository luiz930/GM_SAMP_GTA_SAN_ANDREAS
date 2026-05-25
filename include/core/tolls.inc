#if defined _nova_tolls_included
    #endinput
#endif
#define _nova_tolls_included

#define TOLL_DEFAULT_COUNT          (0)
#define TOLL_MAX_COUNT              (48)
#define TOLL_RANGE                  (11.0)
#define TOLL_GATE_RANGE             (5.5)
#define TOLL_ICON_OFFSET            (0)
#define TOLL_MAP_ICON               (52)
#define TOLL_CHECK_INTERVAL         (2000)
#define TOLL_COOLDOWN_MS            (18000)
#define TOLL_TAG_COST               (650)
#define TOLL_TAG_DISCOUNT_PERCENT   (35)
#define TOLL_GATE_MODEL             (968)
#define TOLL_GATE_MOVE_Z            (3.2)
#define TOLL_GATE_SPEED             (2.5)
#define TOLL_GATE_CLOSE_MS          (6500)
#define TOLL_GOTO_PAGE_SIZE         (30)

enum eTollData
{
    tollName[40],
    Float:tollX,
    Float:tollY,
    Float:tollZ,
    Float:tollA,
    tollCost
}

new gTolls[TOLL_MAX_COUNT][eTollData] =
{
    { "Pedagio LS Norte - Sul", 1712.5000, -854.8000, 56.2000, 90.0, 75 },
    { "Pedagio LS Norte - Norte", 1712.5000, -846.2000, 56.2000, 90.0, 75 },
    { "Pedagio LS Leste - Oeste", 2798.9000, -1644.8000, 10.9000, 0.0, 85 },
    { "Pedagio LS Leste - Leste", 2807.7000, -1644.8000, 10.9000, 0.0, 85 },
    { "Pedagio LS Sul - Norte", 2457.6000, -2212.7000, 13.5000, 90.0, 70 },
    { "Pedagio LS Sul - Sul", 2457.6000, -2204.1000, 13.5000, 90.0, 70 },
    { "Pedagio LS Oeste - Ida", -81.4000, -1535.3000, 2.9000, 45.0, 65 },
    { "Pedagio LS Oeste - Volta", -75.4000, -1529.1000, 2.9000, 45.0, 65 },
    { "Pedagio Red County - LS", 1191.8000, -335.5000, 41.3000, 0.0, 60 },
    { "Pedagio Red County - Dillimore", 1200.6000, -335.5000, 41.3000, 0.0, 60 },
    { "Pedagio SF Ponte Garver - Sul", -1395.5000, 466.0000, 7.2000, 90.0, 95 },
    { "Pedagio SF Ponte Garver - Norte", -1395.5000, 474.6000, 7.2000, 90.0, 95 },
    { "Pedagio LV Sul - LS", 1694.5000, 689.9000, 10.8000, 90.0, 90 },
    { "Pedagio LV Sul - LV", 1694.5000, 698.5000, 10.8000, 90.0, 90 },
    { "Pedagio LV Oeste - Oeste", 1028.3000, 1365.4000, 10.8000, 0.0, 90 },
    { "Pedagio LV Oeste - Leste", 1037.1000, 1365.4000, 10.8000, 0.0, 90 },
    { "Pedagio LS Vinewood - Sul", 1784.3000, -620.1000, 60.6000, 90.0, 70 },
    { "Pedagio LS Vinewood - Norte", 1784.3000, -611.5000, 60.6000, 90.0, 70 },
    { "Pedagio Flint County - Oeste", -528.8000, -498.9000, 25.5000, 0.0, 65 },
    { "Pedagio Flint County - Leste", -520.0000, -498.9000, 25.5000, 0.0, 65 },
    { "Pedagio Angel Pine - Norte", -2027.4000, -2414.6000, 30.6000, 90.0, 75 },
    { "Pedagio Angel Pine - Sul", -2027.4000, -2406.0000, 30.6000, 90.0, 75 },
    { "Pedagio SF Sul - Ida", -1672.9000, -565.6000, 14.1000, 45.0, 85 },
    { "Pedagio SF Sul - Volta", -1666.7000, -559.4000, 14.1000, 45.0, 85 },
    { "Pedagio SF Norte - Sul", -2589.4000, 1125.2000, 55.6000, 90.0, 90 },
    { "Pedagio SF Norte - Norte", -2589.4000, 1133.8000, 55.6000, 90.0, 90 },
    { "Pedagio LV Norte - Oeste", 1934.1000, 2307.4000, 10.8000, 0.0, 85 },
    { "Pedagio LV Norte - Leste", 1942.9000, 2307.4000, 10.8000, 0.0, 85 },
    { "Pedagio LV Leste - Sul", 2636.8000, 1840.6000, 10.8000, 90.0, 80 },
    { "Pedagio LV Leste - Norte", 2636.8000, 1849.2000, 10.8000, 90.0, 80 },
    { "Pedagio Bone County - Oeste", 58.8000, 1208.3000, 18.7000, 0.0, 75 },
    { "Pedagio Bone County - Leste", 67.6000, 1208.3000, 18.7000, 0.0, 75 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 },
    { "", 0.0, 0.0, 0.0, 0.0, 0 }
};

new Text3D:gTollLabels[TOLL_MAX_COUNT];
new gTollGateObject[TOLL_MAX_COUNT];
new gTollGateOpen[TOLL_MAX_COUNT];
new gTollCount = TOLL_DEFAULT_COUNT;
new gTollDirty;
new gTollTimer;
new gPlayerLastTollTick[MAX_PLAYERS];
new gPlayerLastTollId[MAX_PLAYERS];
new gPlayerPendingTollId[MAX_PLAYERS];
new gPlayerPendingTollTick[MAX_PLAYERS];
new gPlayerTollGotoPage[MAX_PLAYERS];
new gPlayerTollIconVisible[MAX_PLAYERS][TOLL_MAX_COUNT];

forward Tolls_UpdateAll();
forward Tolls_CloseGate(tollid);

stock Tolls_DestroyVisual(index)
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    if (index < 0 || index >= TOLL_MAX_COUNT)
    {
        return 0;
    }
    if (gTollLabels[index] != Text3D:0)
    {
        Delete3DTextLabel(gTollLabels[index]);
        gTollLabels[index] = Text3D:0;
    }
    if (gTollGateObject[index] != 0 && IsValidObject(gTollGateObject[index]))
    {
        DestroyObject(gTollGateObject[index]);
    }
    gTollGateObject[index] = 0;
    gTollGateOpen[index] = 0;

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid))
        {
            ManagedMapIcon_Remove(playerid, MAP_ICON_NS_TOLL, index);
            gPlayerTollIconVisible[playerid][index] = 0;
        }
    }
    return 1;
}

stock Tolls_UpdateVisual(index)
{
    new label[128];
    new playerid;
    new maxPlayers = GetMaxPlayers();

    if (index < 0 || index >= gTollCount)
    {
        return 0;
    }
    Tolls_DestroyVisual(index);

    format(label, sizeof(label), "%s\nPedagio $%d\nUse /pedagio ou instale tag no celular", gTolls[index][tollName], gTolls[index][tollCost]);
    gTollLabels[index] = Create3DTextLabel(label, COLOR_YELLOW, gTolls[index][tollX], gTolls[index][tollY], gTolls[index][tollZ] + 1.2, 35.0, 0, 0);
    gTollGateObject[index] = CreateObject(TOLL_GATE_MODEL, gTolls[index][tollX], gTolls[index][tollY], gTolls[index][tollZ], 0.0, 90.0, gTolls[index][tollA], 80.0);
    gTollGateOpen[index] = 0;

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid))
        {
            ManagedMapIcon_Remove(playerid, MAP_ICON_NS_TOLL, index);
            gPlayerTollIconVisible[playerid][index] = 0;
            Tolls_UpdatePlayerMapIcons(playerid);
        }
    }
    return 1;
}

stock Tolls_SavePositions()
{
    new File:file;
    new line[128];
    new index;

    file = fopen(TOLLS_FILE, io_write);
    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Posicoes customizadas dos pedagios: id=x,y,z,a\r\n");
    format(line, sizeof(line), "count=%d\r\n", gTollCount);
    fwrite(file, line);
    for (index = 0; index < gTollCount; index++)
    {
        format(line, sizeof(line), "name_%d=%s\r\n", index, gTolls[index][tollName]);
        fwrite(file, line);
        format(line, sizeof(line), "cost_%d=%d\r\n", index, gTolls[index][tollCost]);
        fwrite(file, line);
        format(line, sizeof(line), "%d=%.4f,%.4f,%.4f,%.2f\r\n", index, gTolls[index][tollX], gTolls[index][tollY], gTolls[index][tollZ], gTolls[index][tollA]);
        fwrite(file, line);
    }
    fclose(file);
    gTollDirty = 0;
    return 1;
}

stock Tolls_ParsePosition(value[], &Float:x, &Float:y, &Float:z, &Float:a)
{
    new first;
    new second;
    new third;
    new part[32];

    first = strfind(value, ",", false);
    if (first <= 0)
    {
        return 0;
    }
    second = strfind(value[first + 1], ",", false);
    if (second < 0)
    {
        return 0;
    }
    second += first + 1;
    third = strfind(value[second + 1], ",", false);
    if (third < 0)
    {
        return 0;
    }
    third += second + 1;

    strmid(part, value, 0, first, sizeof(part));
    x = floatstr(part);
    strmid(part, value, first + 1, second, sizeof(part));
    y = floatstr(part);
    strmid(part, value, second + 1, third, sizeof(part));
    z = floatstr(part);
    strmid(part, value, third + 1, strlen(value), sizeof(part));
    a = floatstr(part);
    return 1;
}

stock Tolls_LoadPositions()
{
    new File:file;
    new line[128];
    new key[16];
    new value[96];
    new pos;
    new index;
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:a;
    new count;
    new customKey[16];

    if (!fexist(TOLLS_FILE))
    {
        return Tolls_SavePositions();
    }

    file = fopen(TOLLS_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (fread(file, line))
    {
        StripLineEnd(line);
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

        strmid(key, line, 0, pos, sizeof(key));
        strmid(value, line, pos + 1, strlen(line), sizeof(value));
        Cfg_Trim(key);
        Cfg_Trim(value);

        if (strcmp(key, "count", true) == 0)
        {
            count = strval(value);
            if (count < 0)
            {
                count = 0;
            }
            if (count > TOLL_MAX_COUNT)
            {
                count = TOLL_MAX_COUNT;
            }
            gTollCount = count;
            continue;
        }

        if (strfind(key, "name_", false) == 0)
        {
            strmid(customKey, key, 5, strlen(key), sizeof(customKey));
            index = strval(customKey);
            if (index >= 0 && index < TOLL_MAX_COUNT)
            {
                format(gTolls[index][tollName], 40, "%s", value);
            }
            continue;
        }

        if (strfind(key, "cost_", false) == 0)
        {
            strmid(customKey, key, 5, strlen(key), sizeof(customKey));
            index = strval(customKey);
            if (index >= 0 && index < TOLL_MAX_COUNT)
            {
                gTolls[index][tollCost] = strval(value);
            }
            continue;
        }

        index = strval(key);
        if (index >= 0 && index < TOLL_MAX_COUNT && Tolls_ParsePosition(value, x, y, z, a))
        {
            if (index >= gTollCount)
            {
                gTollCount = index + 1;
            }
            gTolls[index][tollX] = x;
            gTolls[index][tollY] = y;
            gTolls[index][tollZ] = z;
            gTolls[index][tollA] = a;
        }
    }
    fclose(file);
    gTollDirty = 0;
    return 1;
}

stock Tolls_Init()
{
    new index;

    Tolls_LoadPositions();

    for (index = 0; index < TOLL_MAX_COUNT; index++)
    {
        gTollLabels[index] = Text3D:0;
        gTollGateObject[index] = 0;
        if (index < gTollCount)
        {
            Tolls_UpdateVisual(index);
        }
    }

    gTollTimer = SetTimer("Tolls_UpdateAll", TOLL_CHECK_INTERVAL, 1);
    return 1;
}

stock Tolls_Exit()
{
    new index;

    if (gTollTimer)
    {
        KillTimer(gTollTimer);
        gTollTimer = 0;
    }
    for (index = 0; index < TOLL_MAX_COUNT; index++)
    {
        Tolls_DestroyVisual(index);
    }
    if (gTollDirty)
    {
        Tolls_SavePositions();
    }
    return 1;
}

stock Tolls_ResetPlayer(playerid)
{
    gPlayerLastTollTick[playerid] = 0;
    gPlayerLastTollId[playerid] = -1;
    gPlayerPendingTollId[playerid] = -1;
    gPlayerPendingTollTick[playerid] = 0;
    return 1;
}

stock Tolls_SetupPlayerMapIcons(playerid)
{
    Tolls_UpdatePlayerMapIcons(playerid);
    return 1;
}

stock Tolls_UpdatePlayerMapIcons(playerid)
{
    new index;
    new visible;

    for (index = 0; index < gTollCount; index++)
    {
        visible = IsPlayerInRangeOfPoint(playerid, MAP_ICON_VISIBLE_RANGE, gTolls[index][tollX], gTolls[index][tollY], gTolls[index][tollZ]);
        if (visible && !gPlayerTollIconVisible[playerid][index])
        {
            if (ManagedMapIcon_Set(playerid, MAP_ICON_NS_TOLL, index, gTolls[index][tollX], gTolls[index][tollY], gTolls[index][tollZ], TOLL_MAP_ICON, COLOR_YELLOW, MAPICON_GLOBAL))
            {
                gPlayerTollIconVisible[playerid][index] = 1;
            }
        }
        else if (!visible && gPlayerTollIconVisible[playerid][index])
        {
            ManagedMapIcon_Remove(playerid, MAP_ICON_NS_TOLL, index);
            gPlayerTollIconVisible[playerid][index] = 0;
        }
    }
    for (; index < TOLL_MAX_COUNT; index++)
    {
        if (gPlayerTollIconVisible[playerid][index])
        {
            ManagedMapIcon_Remove(playerid, MAP_ICON_NS_TOLL, index);
            gPlayerTollIconVisible[playerid][index] = 0;
        }
    }
    return 1;
}

stock Tolls_ClearPlayerMapIcons(playerid)
{
    new index;

    for (index = 0; index < TOLL_MAX_COUNT; index++)
    {
        gPlayerTollIconVisible[playerid][index] = 0;
    }
    ManagedMapIcon_ClearNamespace(playerid, MAP_ICON_NS_TOLL);
    return 1;
}

stock Tolls_GetNearest(playerid, Float:range = TOLL_RANGE)
{
    new index;
    new nearest = -1;
    new Float:px;
    new Float:py;
    new Float:pz;
    new Float:dx;
    new Float:dy;
    new Float:dz;
    new Float:distSq;
    new Float:bestSq;
    new Float:rangeSq = range * range;

    if (GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
    {
        return -1;
    }

    GetPlayerPos(playerid, px, py, pz);
    for (index = 0; index < gTollCount; index++)
    {
        dx = px - gTolls[index][tollX];
        dy = py - gTolls[index][tollY];
        dz = pz - gTolls[index][tollZ];
        distSq = (dx * dx) + (dy * dy) + (dz * dz);
        if (distSq <= rangeSq && (nearest == -1 || distSq < bestSq))
        {
            nearest = index;
            bestSq = distSq;
        }
    }
    return nearest;
}

stock Tolls_IsPlayerNearToll(playerid, tollid, Float:range = TOLL_GATE_RANGE)
{
    if (tollid < 0 || tollid >= gTollCount)
    {
        return 0;
    }
    return IsPlayerInRangeOfPoint(playerid, range, gTolls[tollid][tollX], gTolls[tollid][tollY], gTolls[tollid][tollZ]);
}

stock Tolls_GetPaymentTarget(playerid)
{
    new pending = gPlayerPendingTollId[playerid];

    if (pending != -1 && Tolls_IsPlayerNearToll(playerid, pending, TOLL_RANGE))
    {
        return pending;
    }
    return Tolls_GetNearest(playerid, TOLL_RANGE);
}

stock Tolls_GetCharge(index, useTag)
{
    new cost;

    if (index < 0 || index >= gTollCount)
    {
        return 0;
    }

    cost = Cfg_Price(gTolls[index][tollCost]);
    if (useTag)
    {
        cost -= (cost * TOLL_TAG_DISCOUNT_PERCENT) / 100;
        if (cost < 1)
        {
            cost = 1;
        }
    }
    return cost;
}

stock Tolls_CanCharge(playerid, tollid)
{
    new tick = GetTickCount();

    if (gPlayerLastTollId[playerid] == tollid && gPlayerLastTollTick[playerid] > 0 && (tick - gPlayerLastTollTick[playerid]) < TOLL_COOLDOWN_MS)
    {
        return 0;
    }
    return 1;
}

stock Tolls_MarkCharged(playerid, tollid)
{
    gPlayerLastTollId[playerid] = tollid;
    gPlayerLastTollTick[playerid] = GetTickCount();
    gPlayerPendingTollId[playerid] = -1;
    gPlayerPendingTollTick[playerid] = 0;
    return 1;
}

stock Tolls_OpenGate(tollid)
{
    if (tollid < 0 || tollid >= gTollCount || gTollGateObject[tollid] == 0)
    {
        return 0;
    }

    if (!gTollGateOpen[tollid])
    {
        MoveObject(gTollGateObject[tollid], gTolls[tollid][tollX], gTolls[tollid][tollY], gTolls[tollid][tollZ] + TOLL_GATE_MOVE_Z, TOLL_GATE_SPEED);
        gTollGateOpen[tollid] = 1;
    }
    SetTimerEx("Tolls_CloseGate", TOLL_GATE_CLOSE_MS, 0, "d", tollid);
    return 1;
}

public Tolls_CloseGate(tollid)
{
    if (tollid < 0 || tollid >= gTollCount || gTollGateObject[tollid] == 0)
    {
        return 0;
    }

    MoveObject(gTollGateObject[tollid], gTolls[tollid][tollX], gTolls[tollid][tollY], gTolls[tollid][tollZ], TOLL_GATE_SPEED);
    gTollGateOpen[tollid] = 0;
    return 1;
}

stock Tolls_ApplyEvasionFine(playerid, tollid)
{
    new fine = Cfg_TrafficFine(TRAFFIC_FINE_SERIOUS, 1);
    new points = Cfg_TrafficPoints(TRAFFIC_FINE_SERIOUS);
    new message[144];
    new logLine[144];

    if (tollid < 0 || tollid >= gTollCount)
    {
        return 0;
    }
    if (!Tolls_CanCharge(playerid, tollid))
    {
        return 0;
    }
    if (Account_IsNewcomerProtected(playerid))
    {
        Tolls_MarkCharged(playerid, tollid);
        Tolls_OpenGate(tollid);
        format(message, sizeof(message), "Aviso educativo: voce furou %s, mas recem chegado nao recebe multa ate o nivel 3.", gTolls[tollid][tollName]);
        SendClientMessage(playerid, COLOR_YELLOW, message);
        GameTextForPlayer(playerid, "~y~AVISO DE PEDAGIO~n~~w~Sem multa ate nivel 3", 3500, 3);
        return 1;
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
    SaveAccountData(playerid, 0);
    Tolls_MarkCharged(playerid, tollid);

    format(message, sizeof(message), "Multa: evasao de pedagio em %s. $%d | %d pts CNH.", gTolls[tollid][tollName], fine, points);
    SendClientMessage(playerid, COLOR_RED, message);
    GameTextForPlayer(playerid, "~r~PEDAGIO FURADO~n~~w~Multa no GovBR", 4000, 3);
    format(logLine, sizeof(logLine), "toll=%d fine=%d points=%d", tollid + 1, fine, points);
    WritePlayerLog(LOG_MONEY_FILE, "TOLL_EVASION", playerid, logLine);
    return 1;
}

stock Tolls_WarnManualPayment(playerid, tollid)
{
    new message[144];

    if (tollid < 0 || tollid >= gTollCount)
    {
        return 0;
    }
    if (gPlayerPendingTollId[playerid] == tollid)
    {
        return 0;
    }
    if (!Tolls_CanCharge(playerid, tollid))
    {
        return 0;
    }

    gPlayerPendingTollId[playerid] = tollid;
    gPlayerPendingTollTick[playerid] = GetTickCount();
    format(message, sizeof(message), "%s: pare e use /pedagio. Tag automatica disponivel no celular > GovBR.", gTolls[tollid][tollName]);
    SendClientMessage(playerid, COLOR_ORANGE, message);
    return 1;
}

stock Tolls_Pay(playerid, tollid, useTag)
{
    new cost = Tolls_GetCharge(tollid, useTag);
    new message[144];
    new logLine[144];

    if (tollid < 0 || tollid >= gTollCount)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao esta em um pedagio.");
        return 1;
    }
    if (!Tolls_CanCharge(playerid, tollid))
    {
        return 1;
    }

    if (!Bank_TakePaymentReason(playerid, cost, 0, useTag ? ("toll_tag") : ("toll_manual")))
    {
        format(message, sizeof(message), "Pedagio %s custa $%d. Saldo insuficiente.", gTolls[tollid][tollName], cost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    Life_AddGovernmentRevenue(cost, useTag ? ("pedagio_tag") : ("pedagio_manual"));
    SaveAccountData(playerid, 0);
    Tolls_MarkCharged(playerid, tollid);
    Tolls_OpenGate(tollid);

    format(message, sizeof(message), "%s pago%s: $%d.", gTolls[tollid][tollName], useTag ? (" pela tag") : (""), cost);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(logLine, sizeof(logLine), "toll=%d cost=%d tag=%d", tollid + 1, cost, useTag);
    WritePlayerLog(LOG_MONEY_FILE, "TOLL", playerid, logLine);
    return 1;
}

stock Tolls_BuyTag(playerid)
{
    new message[144];

    if (PlayerInfo[playerid][pTollTag])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Seu veiculo/conta ja possui tag de pedagio ativa.");
        return 1;
    }
    if (!Bank_RequireAccount(playerid))
    {
        return 1;
    }
    if (!Bank_TakePaymentReason(playerid, Cfg_Price(TOLL_TAG_COST), 0, "toll_tag_install"))
    {
        format(message, sizeof(message), "Instalar tag de pedagio custa $%d.", Cfg_Price(TOLL_TAG_COST));
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    PlayerInfo[playerid][pTollTag] = 1;
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Tag de pedagio instalada. Passagens automaticas tem %d%% de desconto.", TOLL_TAG_DISCOUNT_PERCENT);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Tolls_ShowStatus(playerid)
{
    new index;
    new message[144];

    SendClientMessage(playerid, COLOR_BLUE, "Pedagios ativos:");
    for (index = 0; index < gTollCount; index++)
    {
        format(message, sizeof(message), "%d. %s | manual $%d | tag $%d", index + 1, gTolls[index][tollName], Tolls_GetCharge(index, 0), Tolls_GetCharge(index, 1));
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    format(message, sizeof(message), "Sua tag: %s. Use /pedagio em uma cabine ou instale pelo celular > GovBR.", PlayerInfo[playerid][pTollTag] ? ("ativa") : ("nao instalada"));
    SendClientMessage(playerid, COLOR_GRAY, message);
    if (HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Dono: use /pedagiomaisperto e /ajustarpedagio [id] para reposicionar cancelas.");
    }
    return 1;
}

stock Tolls_SendNearest(playerid)
{
    new tollid;
    new message[160];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    tollid = Tolls_GetNearest(playerid, 80.0);
    if (tollid == -1)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Nenhum pedagio encontrado perto de voce.");
        return 1;
    }

    format(message, sizeof(message), "Pedagio mais perto: ID %d | %s | pos %.2f, %.2f, %.2f.", tollid + 1, gTolls[tollid][tollName], gTolls[tollid][tollX], gTolls[tollid][tollY], gTolls[tollid][tollZ]);
    SendClientMessage(playerid, COLOR_YELLOW, message);
    SendClientMessage(playerid, COLOR_GRAY, "Use /ajustarpedagio [id] em cima da faixa/cancela para salvar sua posicao atual.");
    return 1;
}

stock Tolls_AdjustCommand(playerid, tollid)
{
    new index = tollid - 1;
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:a;
    new message[180];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }
    if (index < 0 || index >= gTollCount)
    {
        return SendUsage(playerid, "/ajustarpedagio [id]");
    }
    if (GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Ajuste o pedagio no mundo aberto, fora de interior/virtual world.");
        return 1;
    }

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);
    gTolls[index][tollX] = x;
    gTolls[index][tollY] = y;
    gTolls[index][tollZ] = z;
    gTolls[index][tollA] = a;
    gTollDirty = 1;
    Tolls_SavePositions();
    Tolls_UpdateVisual(index);

    format(message, sizeof(message), "Pedagio %d ajustado para sua posicao: %.2f, %.2f, %.2f ang %.1f.", tollid, x, y, z, a);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(playerid, COLOR_GRAY, "Dica: fique parado no centro da faixa e olhando no sentido em que a cancela deve atravessar a pista.");
    return 1;
}

stock Tolls_CreateCommand(playerid)
{
    new index;
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:a;
    new message[180];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }
    if (gTollCount >= TOLL_MAX_COUNT)
    {
        format(message, sizeof(message), "Limite de pedagios atingido (%d). Aumente TOLL_MAX_COUNT antes de criar mais.", TOLL_MAX_COUNT);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }
    if (GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Crie o pedagio no mundo aberto, fora de interior/virtual world.");
        return 1;
    }

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);
    x += floatsin(-a, degrees) * 2.4;
    y += floatcos(-a, degrees) * 2.4;

    index = gTollCount;
    format(gTolls[index][tollName], 40, "Pedagio Criado %d", index + 1);
    gTolls[index][tollX] = x;
    gTolls[index][tollY] = y;
    gTolls[index][tollZ] = z;
    gTolls[index][tollA] = a;
    gTolls[index][tollCost] = 70;
    gTollLabels[index] = Text3D:0;
    gTollGateObject[index] = 0;
    gTollGateOpen[index] = 0;
    gTollCount++;

    Tolls_UpdateVisual(index);
    gTollDirty = 1;
    Tolls_SavePositions();

    format(message, sizeof(message), "Pedagio %d criado a sua frente: %.2f, %.2f, %.2f ang %.1f.", index + 1, x, y, z, a);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(playerid, COLOR_GRAY, "Depois use /ajustarpedagio [id] para refinar exatamente em cima da faixa.");
    return 1;
}

stock Tolls_CreateDualLaneCommand(playerid)
{
    new firstIndex;
    new secondIndex;
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:a;
    new Float:forwardX;
    new Float:forwardY;
    new Float:rightX;
    new Float:rightY;
    new Float:secondAngle;
    new message[180];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }
    if (gTollCount + 2 > TOLL_MAX_COUNT)
    {
        format(message, sizeof(message), "Limite de pedagios quase cheio (%d). Remova algum antes de criar duas cancelas.", TOLL_MAX_COUNT);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }
    if (GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Crie o pedagio no mundo aberto, fora de interior/virtual world.");
        return 1;
    }

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);
    forwardX = floatsin(-a, degrees);
    forwardY = floatcos(-a, degrees);
    rightX = floatcos(-a, degrees);
    rightY = -floatsin(-a, degrees);
    x += forwardX * 3.2;
    y += forwardY * 3.2;
    secondAngle = a + 180.0;
    if (secondAngle >= 360.0)
    {
        secondAngle -= 360.0;
    }

    firstIndex = gTollCount;
    format(gTolls[firstIndex][tollName], 40, "Pedagio Duas Faixas A");
    gTolls[firstIndex][tollX] = x + (rightX * -7.2);
    gTolls[firstIndex][tollY] = y + (rightY * -7.2);
    gTolls[firstIndex][tollZ] = z;
    gTolls[firstIndex][tollA] = a;
    gTolls[firstIndex][tollCost] = 70;
    gTollLabels[firstIndex] = Text3D:0;
    gTollGateObject[firstIndex] = 0;
    gTollGateOpen[firstIndex] = 0;
    gTollCount++;

    secondIndex = gTollCount;
    format(gTolls[secondIndex][tollName], 40, "Pedagio Duas Faixas B");
    gTolls[secondIndex][tollX] = x + (rightX * 7.2);
    gTolls[secondIndex][tollY] = y + (rightY * 7.2);
    gTolls[secondIndex][tollZ] = z;
    gTolls[secondIndex][tollA] = secondAngle;
    gTolls[secondIndex][tollCost] = 70;
    gTollLabels[secondIndex] = Text3D:0;
    gTollGateObject[secondIndex] = 0;
    gTollGateOpen[secondIndex] = 0;
    gTollCount++;

    Tolls_UpdateVisual(firstIndex);
    Tolls_UpdateVisual(secondIndex);
    gTollDirty = 1;
    Tolls_SavePositions();

    format(message, sizeof(message), "Criadas duas cancelas funcionais: IDs %d e %d, uma contra a outra.", firstIndex + 1, secondIndex + 1);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(playerid, COLOR_GRAY, "As bases nascem afastadas para as pontas se encontrarem no centro. Refine com /ajustarpedagio [id].");
    return 1;
}

stock Tolls_RemoveCommand(playerid, tollid)
{
    new index = tollid - 1;
    new shift;
    new playerid2;
    new maxPlayers = GetMaxPlayers();
    new message[180];
    new removedName[40];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }
    if (index < 0 || index >= gTollCount)
    {
        return SendUsage(playerid, "/removerpedagio [id]");
    }

    format(removedName, sizeof(removedName), "%s", gTolls[index][tollName]);

    for (shift = 0; shift < TOLL_MAX_COUNT; shift++)
    {
        Tolls_DestroyVisual(shift);
    }

    for (shift = index; shift < gTollCount - 1; shift++)
    {
        format(gTolls[shift][tollName], 40, "%s", gTolls[shift + 1][tollName]);
        gTolls[shift][tollX] = gTolls[shift + 1][tollX];
        gTolls[shift][tollY] = gTolls[shift + 1][tollY];
        gTolls[shift][tollZ] = gTolls[shift + 1][tollZ];
        gTolls[shift][tollA] = gTolls[shift + 1][tollA];
        gTolls[shift][tollCost] = gTolls[shift + 1][tollCost];
    }

    gTollCount--;
    if (gTollCount < 0)
    {
        gTollCount = 0;
    }
    format(gTolls[gTollCount][tollName], 40, "");
    gTolls[gTollCount][tollX] = 0.0;
    gTolls[gTollCount][tollY] = 0.0;
    gTolls[gTollCount][tollZ] = 0.0;
    gTolls[gTollCount][tollA] = 0.0;
    gTolls[gTollCount][tollCost] = 0;

    for (shift = 0; shift < gTollCount; shift++)
    {
        Tolls_UpdateVisual(shift);
    }

    for (playerid2 = 0; playerid2 < maxPlayers; playerid2++)
    {
        if (IsPlayerConnected(playerid2))
        {
            gPlayerPendingTollId[playerid2] = -1;
            gPlayerPendingTollTick[playerid2] = 0;
        }
    }

    gTollDirty = 1;
    Tolls_SavePositions();
    format(message, sizeof(message), "Pedagio %d removido: %s. IDs reorganizados e arquivo salvo.", tollid, removedName);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Tolls_GotoCommand(playerid, tollid)
{
    new index = tollid - 1;
    new message[180];
    new Float:x;
    new Float:y;
    new Float:z;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }
    if (index < 0 || index >= gTollCount)
    {
        return SendUsage(playerid, "/irpedagio [id]");
    }

    x = gTolls[index][tollX] + 2.0;
    y = gTolls[index][tollY] + 2.0;
    z = gTolls[index][tollZ] + 1.0;
    if (IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        SetVehiclePos(GetPlayerVehicleID(playerid), x, y, z);
        SetVehicleZAngle(GetPlayerVehicleID(playerid), gTolls[index][tollA]);
    }
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerPos(playerid, x, y, z);
    SetPlayerFacingAngle(playerid, gTolls[index][tollA]);
    Security_GrantTeleportGrace(playerid);
    SetCameraBehindPlayer(playerid);

    format(message, sizeof(message), "Teleportado para pedagio %d: %s.", tollid, gTolls[index][tollName]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Tolls_ShowGotoDialog(playerid, page = 0)
{
    new list[3000];
    new line[128];
    new index;
    new shown;
    new start;
    new title[64];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }
    if (page < 0)
    {
        page = 0;
    }

    start = page * TOLL_GOTO_PAGE_SIZE;
    if (start >= gTollCount && page > 0)
    {
        page--;
        start = page * TOLL_GOTO_PAGE_SIZE;
    }

    gPlayerTollGotoPage[playerid] = page;
    format(list, sizeof(list), "ID\tPedagio\n");
    for (index = start; index < gTollCount && shown < TOLL_GOTO_PAGE_SIZE; index++)
    {
        format(line, sizeof(line), "%d\t%s\n", index + 1, gTolls[index][tollName]);
        strcat(list, line, sizeof(list));
        shown++;
    }
    if (start + shown < gTollCount)
    {
        strcat(list, ">>\tProxima pagina\n", sizeof(list));
    }
    if (page > 0)
    {
        strcat(list, "<<\tPagina anterior\n", sizeof(list));
    }
    if (shown == 0)
    {
        strcat(list, "-\tNenhum pedagio criado\n", sizeof(list));
    }

    format(title, sizeof(title), "Ir ate pedagio - Pagina %d", page + 1);
    ShowPlayerDialog(playerid, DIALOG_TOLL_GOTO_LIST, DIALOG_STYLE_TABLIST_HEADERS, title, list, "Ir", "Fechar");
    return 1;
}

stock Tolls_HandleGotoDialog(playerid, response, listitem)
{
    new page = gPlayerTollGotoPage[playerid];
    new start = page * TOLL_GOTO_PAGE_SIZE;
    new shown = gTollCount - start;

    if (!response)
    {
        return 1;
    }
    if (shown > TOLL_GOTO_PAGE_SIZE)
    {
        shown = TOLL_GOTO_PAGE_SIZE;
    }
    if (listitem >= 0 && listitem < shown)
    {
        return Tolls_GotoCommand(playerid, start + listitem + 1);
    }
    if (listitem == shown && start + shown < gTollCount)
    {
        return Tolls_ShowGotoDialog(playerid, page + 1);
    }
    if ((listitem == shown || listitem == shown + 1) && page > 0)
    {
        return Tolls_ShowGotoDialog(playerid, page - 1);
    }
    return 1;
}

stock Tolls_ManualCommand(playerid)
{
    new tollid;

    if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar dirigindo no pedagio.");
        return 1;
    }

    tollid = Tolls_GetPaymentTarget(playerid);
    if (tollid == -1)
    {
        Tolls_ShowStatus(playerid);
        return 1;
    }

    return Tolls_Pay(playerid, tollid, 0);
}

stock Tolls_HandleCommands(playerid, cmdtext[])
{
    new command[32];
    new index;
    new param[16];

    index = GetCommandName(cmdtext, command, sizeof(command));
    if (strcmp(command, "/pedagio", true) == 0 || strcmp(command, "/pedagios", true) == 0)
    {
        return Tolls_ManualCommand(playerid);
    }
    if (strcmp(command, "/pedagiomaisperto", true) == 0 || strcmp(command, "/cancelamaisperto", true) == 0)
    {
        return Tolls_SendNearest(playerid);
    }
    if (strcmp(command, "/ajustarpedagio", true) == 0 || strcmp(command, "/setpedagio", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/ajustarpedagio [id]");
        }
        return Tolls_AdjustCommand(playerid, strval(param));
    }
    if (strcmp(command, "/criarpedagio", true) == 0 || strcmp(command, "/addpedagio", true) == 0)
    {
        return Tolls_CreateCommand(playerid);
    }
    if (strcmp(command, "/removerpedagio", true) == 0 || strcmp(command, "/delpedagio", true) == 0 || strcmp(command, "/deletepedagio", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/removerpedagio [id]");
        }
        return Tolls_RemoveCommand(playerid, strval(param));
    }
    if (strcmp(command, "/irpedagio", true) == 0 || strcmp(command, "/gotopedagio", true) == 0 || strcmp(command, "/tppedagio", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return Tolls_ShowGotoDialog(playerid, 0);
        }
        if (!IsNumericString(param))
        {
            return SendUsage(playerid, "/irpedagio [id]");
        }
        return Tolls_GotoCommand(playerid, strval(param));
    }
    return 0;
}

public Tolls_UpdateAll()
{
    new playerid;
    new maxPlayers = GetMaxPlayers();
    new tollid;
    new pending;

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (!IsPlayerConnected(playerid) || !PlayerInfo[playerid][pLogged])
        {
            continue;
        }
        if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        {
            if (gPlayerPendingTollId[playerid] != -1)
            {
                gPlayerPendingTollId[playerid] = -1;
                gPlayerPendingTollTick[playerid] = 0;
            }
            continue;
        }

        tollid = Tolls_GetPaymentTarget(playerid);
        if (tollid != -1 && PlayerInfo[playerid][pTollTag])
        {
            Tolls_Pay(playerid, tollid, 1);
            continue;
        }

        if (tollid != -1)
        {
            if (Tolls_IsPlayerNearToll(playerid, tollid, TOLL_GATE_RANGE))
            {
                Tolls_WarnManualPayment(playerid, tollid);
            }
            continue;
        }

        pending = gPlayerPendingTollId[playerid];
        if (pending != -1)
        {
            Tolls_ApplyEvasionFine(playerid, pending);
        }
    }
    return 1;
}
