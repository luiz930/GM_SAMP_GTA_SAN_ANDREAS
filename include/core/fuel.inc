#if defined _nova_fuel_included
    #endinput
#endif
#define _nova_fuel_included

new gVehicleFuel[MAX_VEHICLES];
new gVehicleEngineOn[MAX_VEHICLES];
new gVehicleFuelReady[MAX_VEHICLES];
new gVehicleGear[MAX_VEHICLES];
new gVehicleShiftTick[MAX_VEHICLES];
new gVehicleGearWarnTick[MAX_VEHICLES];
new gFuelTimer;

#define EV_CHARGE_RANGE            (10.0)
#define EV_CHARGE_LABEL_RANGE      (30.0)
#define EV_CHARGE_HOME_RANGE       (12.0)
#define EV_CHARGE_MIN_COST         (25)
#define MANUAL_GEAR_MIN            (1)
#define MANUAL_GEAR_MAX            (5)
#define MANUAL_SHIFT_COOLDOWN_MS   (600)
#define MANUAL_WARN_COOLDOWN_MS    (7000)

new gEvChargeLocations[] =
{
    LOCATION_POSTO_IDLEWOOD,
    LOCATION_POSTO_MARKET,
    LOCATION_POSTO_DILLIMORE,
    LOCATION_POSTO_FLINT,
    LOCATION_POSTO_EL_QUEBRADOS,
    LOCATION_POSTO_TIERRA,
    LOCATION_DELEGACIA,
    LOCATION_JOB_POLICIAL,
    LOCATION_JOB_PRF,
    LOCATION_JOB_POLICIA_FEDERAL,
    LOCATION_JOB_POLICIA_CIVIL,
    LOCATION_JOB_POLICIA_PENAL
};

new Text3D:gEvChargeLabels[sizeof(gEvChargeLocations)];

forward Fuel_UpdateAll();

stock Fuel_Init()
{
    new index;
    new locationid;
    new label[128];

    for (index = 0; index < sizeof(gEvChargeLocations); index++)
    {
        locationid = gEvChargeLocations[index];
        format(label, sizeof(label), "Ponto de recarga eletrica\n%s\nUse /recarregar", gServerLocations[locationid][locName]);
        gEvChargeLabels[index] = Create3DTextLabel(label, COLOR_BLUE, gServerLocations[locationid][locX], gServerLocations[locationid][locY], gServerLocations[locationid][locZ] + 0.7, EV_CHARGE_LABEL_RANGE, 0, 1);
    }
    return 1;
}

stock Fuel_Exit()
{
    new index;

    for (index = 0; index < sizeof(gEvChargeLabels); index++)
    {
        Delete3DTextLabel(gEvChargeLabels[index]);
    }
    return 1;
}

stock Fuel_IsValidVehicle(vehicleid)
{
    if (vehicleid <= 0 || vehicleid >= MAX_VEHICLES)
    {
        return 0;
    }

    return (GetVehicleModel(vehicleid) != 0);
}

stock Fuel_IsBicycleModel(modelid)
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

stock Fuel_IsMotorcycleModel(modelid)
{
    switch (modelid)
    {
        case 448, 461, 462, 463, 468, 471, 481, 509, 510, 521, 522, 523, 581, 586:
        {
            return 1;
        }
    }
    return 0;
}

stock Fuel_IsDieselModel(modelid)
{
    switch (modelid)
    {
        case 403, 406, 407, 408, 413, 414, 416, 423, 427, 431, 432, 433, 437, 440, 443, 455, 456, 482, 498, 499, 514, 515, 524, 525, 528, 530, 531, 532, 544, 552, 573, 578, 582:
        {
            return 1;
        }
    }
    return 0;
}

stock Fuel_IsElectricModel(modelid)
{
    switch (modelid)
    {
        case 415, 429, 541:
        {
            return 1;
        }
    }
    return 0;
}

stock Fuel_IsManualModel(modelid)
{
    switch (modelid)
    {
        case 400, 401, 403, 404, 410, 412, 414, 426, 436, 455, 456, 466, 467, 474, 478, 482, 489, 496, 498, 499, 507, 514, 515, 516, 517, 518, 526, 527, 529, 540, 542, 545, 547, 549, 550, 551, 560, 566, 575, 576, 578, 580, 585, 589, 600, 602, 603:
        {
            return 1;
        }
    }
    return 0;
}

stock Fuel_IsElectricVehicle(vehicleid)
{
    if (!Fuel_IsValidVehicle(vehicleid))
    {
        return 0;
    }
    return Fuel_IsElectricModel(GetVehicleModel(vehicleid));
}

stock Fuel_IsManualVehicle(vehicleid)
{
    if (!Fuel_IsValidVehicle(vehicleid))
    {
        return 0;
    }
    return 0;
}

stock Fuel_GetElectricUnitPrice()
{
    new price = gCfgFuelGasolinePrice / 3;

    if (price < 2)
    {
        price = 2;
    }
    return price;
}

stock Fuel_GetDefaultUnitPrice(vehicleid)
{
    new modelid;

    if (!Fuel_IsValidVehicle(vehicleid))
    {
        return gCfgFuelGasolinePrice;
    }

    modelid = GetVehicleModel(vehicleid);
    if (Fuel_IsElectricModel(modelid))
    {
        return Fuel_GetElectricUnitPrice();
    }
    if (Fuel_IsDieselModel(modelid))
    {
        if (gCfgFuelDieselPrice > 0)
        {
            return gCfgFuelDieselPrice;
        }
        return gCfgNpcRefuelPrice;
    }
    if (gCfgFuelGasolinePrice > 0)
    {
        return gCfgFuelGasolinePrice;
    }
    return gCfgNpcRefuelPrice;
}

stock Fuel_GetDefaultFuelName(vehicleid, output[], size)
{
    new modelid;

    if (!Fuel_IsValidVehicle(vehicleid))
    {
        format(output, size, "gasolina");
        return 1;
    }

    modelid = GetVehicleModel(vehicleid);
    if (Fuel_IsElectricModel(modelid))
    {
        format(output, size, "bateria");
        return 1;
    }
    if (Fuel_IsDieselModel(modelid))
    {
        format(output, size, "diesel");
        return 1;
    }
    format(output, size, "gasolina");
    return 1;
}

stock Fuel_IsMotorizedVehicle(vehicleid)
{
    if (!Fuel_IsValidVehicle(vehicleid))
    {
        return 0;
    }

    return !Fuel_IsBicycleModel(GetVehicleModel(vehicleid));
}

stock Fuel_InitVehicle(vehicleid, fuel = FUEL_MAX_VALUE, engine = 0)
{
    if (!Fuel_IsValidVehicle(vehicleid))
    {
        return 0;
    }

    if (fuel < 0)
    {
        fuel = 0;
    }
    if (fuel > FUEL_MAX_VALUE)
    {
        fuel = FUEL_MAX_VALUE;
    }

    gVehicleFuel[vehicleid] = fuel;
    gVehicleEngineOn[vehicleid] = engine;
    gVehicleFuelReady[vehicleid] = 1;
    gVehicleGear[vehicleid] = MANUAL_GEAR_MIN;
    gVehicleShiftTick[vehicleid] = 0;
    gVehicleGearWarnTick[vehicleid] = 0;
    Fuel_ApplyEngine(vehicleid);
    return 1;
}

stock Fuel_EnsureVehicle(vehicleid)
{
    if (!Fuel_IsValidVehicle(vehicleid))
    {
        return 0;
    }

    if (!gVehicleFuelReady[vehicleid])
    {
        Fuel_InitVehicle(vehicleid, FUEL_MAX_VALUE, 0);
    }
    return 1;
}

stock Fuel_ApplyEngine(vehicleid)
{
    new engine;
    new lights;
    new alarm;
    new doors;
    new bonnet;
    new boot;
    new objective;

    if (!Fuel_IsValidVehicle(vehicleid))
    {
        return 0;
    }

    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);

    if (!Fuel_IsMotorizedVehicle(vehicleid))
    {
        SetVehicleParamsEx(vehicleid, 1, lights, alarm, doors, bonnet, boot, objective);
        return 1;
    }

    SetVehicleParamsEx(vehicleid, gVehicleEngineOn[vehicleid], lights, alarm, doors, bonnet, boot, objective);
    return 1;
}

stock Fuel_GetVehicleFuel(vehicleid)
{
    if (!Fuel_EnsureVehicle(vehicleid))
    {
        return 0;
    }
    return gVehicleFuel[vehicleid];
}

stock Fuel_IsEngineOn(vehicleid)
{
    if (!Fuel_EnsureVehicle(vehicleid))
    {
        return 0;
    }
    return gVehicleEngineOn[vehicleid];
}

stock Fuel_SetVehicleFuel(vehicleid, fuel)
{
    if (!Fuel_EnsureVehicle(vehicleid))
    {
        return 0;
    }

    if (fuel < 0)
    {
        fuel = 0;
    }
    if (fuel > FUEL_MAX_VALUE)
    {
        fuel = FUEL_MAX_VALUE;
    }

    gVehicleFuel[vehicleid] = fuel;
    if (fuel <= 0)
    {
        gVehicleEngineOn[vehicleid] = 0;
        Fuel_ApplyEngine(vehicleid);
    }
    return 1;
}

stock Fuel_RefuelVehicle(vehicleid, amount)
{
    if (!Fuel_EnsureVehicle(vehicleid))
    {
        return 0;
    }

    if (amount <= 0)
    {
        amount = FUEL_MAX_VALUE;
    }

    return Fuel_SetVehicleFuel(vehicleid, gVehicleFuel[vehicleid] + amount);
}

stock Fuel_TogglePlayerEngine(playerid)
{
    new vehicleid;
    new message[96];
    new electric;

    if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce precisa estar dirigindo um veiculo.");
        return 1;
    }

    vehicleid = GetPlayerVehicleID(playerid);
    if (!Fuel_IsMotorizedVehicle(vehicleid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Este veiculo nao possui motor.");
        return 1;
    }

    Fuel_EnsureVehicle(vehicleid);
    electric = Fuel_IsElectricVehicle(vehicleid);
    if (gVehicleFuel[vehicleid] <= 0)
    {
        SendClientMessage(playerid, COLOR_RED, electric ? ("A bateria acabou. Use /recarregar em um ponto de recarga.") : ("O tanque esta vazio. Abasteca o veiculo."));
        return 1;
    }

    gVehicleEngineOn[vehicleid] = !gVehicleEngineOn[vehicleid];
    Fuel_ApplyEngine(vehicleid);

    if (gVehicleEngineOn[vehicleid])
    {
        if (Fuel_IsManualVehicle(vehicleid))
        {
            gVehicleGear[vehicleid] = MANUAL_GEAR_MIN;
        }
        format(message, sizeof(message), "%s ligado. %s: %d%%.", electric ? ("Sistema eletrico") : ("Motor"), electric ? ("Bateria") : ("Combustivel"), gVehicleFuel[vehicleid]);
    }
    else
    {
        format(message, sizeof(message), "%s desligado. %s: %d%%.", electric ? ("Sistema eletrico") : ("Motor"), electric ? ("Bateria") : ("Combustivel"), gVehicleFuel[vehicleid]);
    }
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Fuel_GetVehicleDriver(vehicleid)
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && IsPlayerInVehicle(playerid, vehicleid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
        {
            return playerid;
        }
    }
    return INVALID_PLAYER_ID;
}

stock Fuel_UpdateVehicle(vehicleid)
{
    new driverid;

    if (!Fuel_IsMotorizedVehicle(vehicleid) || !gVehicleFuelReady[vehicleid] || !gVehicleEngineOn[vehicleid])
    {
        return 0;
    }

    driverid = Fuel_GetVehicleDriver(vehicleid);
    if (driverid == INVALID_PLAYER_ID)
    {
        return 0;
    }

    return Fuel_UpdateDriver(driverid);
}

stock Fuel_GetGearMinSpeed(gear)
{
    switch (gear)
    {
        case 1: return 0;
        case 2: return 15;
        case 3: return 40;
        case 4: return 70;
        case 5: return 100;
    }
    return 0;
}

stock Fuel_GetGearMaxSpeed(gear)
{
    switch (gear)
    {
        case 1: return 35;
        case 2: return 65;
        case 3: return 95;
        case 4: return 125;
        case 5: return 180;
    }
    return 180;
}

stock Fuel_SendGearWarning(playerid, vehicleid, text[])
{
    new tick = GetTickCount();

    if (tick - gVehicleGearWarnTick[vehicleid] < MANUAL_WARN_COOLDOWN_MS)
    {
        return 0;
    }

    gVehicleGearWarnTick[vehicleid] = tick;
    SendClientMessage(playerid, COLOR_ORANGE, text);
    return 1;
}

stock Fuel_UpdateManualTransmission(playerid, vehicleid, speed)
{
    new gear;
    new minSpeed;
    new maxSpeed;

    if (!Fuel_IsManualVehicle(vehicleid))
    {
        return 0;
    }

    gear = gVehicleGear[vehicleid];
    if (gear < MANUAL_GEAR_MIN || gear > MANUAL_GEAR_MAX)
    {
        gear = MANUAL_GEAR_MIN;
        gVehicleGear[vehicleid] = gear;
    }

    if (speed < 10 && gear >= 3)
    {
        gVehicleEngineOn[vehicleid] = 0;
        Fuel_ApplyEngine(vehicleid);
        SendClientMessage(playerid, COLOR_RED, "Motor apagou por marcha alta em baixa velocidade. Reduza e ligue de novo.");
        return -1;
    }

    minSpeed = Fuel_GetGearMinSpeed(gear);
    maxSpeed = Fuel_GetGearMaxSpeed(gear);

    if (speed > maxSpeed)
    {
        if (speed > maxSpeed + 25)
        {
            gVehicleEngineOn[vehicleid] = 0;
            Fuel_ApplyEngine(vehicleid);
            SendClientMessage(playerid, COLOR_RED, "Motor cortou por marcha baixa em alta velocidade. Suba a marcha e ligue de novo.");
            return -1;
        }
        Fuel_SendGearWarning(playerid, vehicleid, "Cambio manual: suba a marcha para nao forcar o motor.");
        return 1;
    }

    if (speed > 12 && speed < minSpeed)
    {
        Fuel_SendGearWarning(playerid, vehicleid, "Cambio manual: reduza a marcha para retomar melhor.");
        return 1;
    }
    return 0;
}

stock Fuel_UpdateDriver(playerid)
{
    new vehicleid;
    new speed;
    new drain;
    new manualDrain;
    new electric;

    if (!IsPlayerConnected(playerid) || !PlayerInfo[playerid][pLogged] || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        return 0;
    }

    vehicleid = GetPlayerVehicleID(playerid);
    if (!Fuel_IsValidVehicle(vehicleid) || !Fuel_IsMotorizedVehicle(vehicleid) || !gVehicleFuelReady[vehicleid] || !gVehicleEngineOn[vehicleid])
    {
        return 0;
    }

    speed = GetVehicleSpeedKmh(vehicleid);
    if (speed < 5)
    {
        return 0;
    }

    electric = Fuel_IsElectricVehicle(vehicleid);
    manualDrain = Fuel_UpdateManualTransmission(playerid, vehicleid, speed);
    if (manualDrain < 0)
    {
        return 1;
    }
    drain = manualDrain;
    if (speed >= 90)
    {
        drain += electric ? 1 : 2;
    }
    else
    {
        drain += 1;
    }

    Fuel_SetVehicleFuel(vehicleid, gVehicleFuel[vehicleid] - drain);

    if (gVehicleFuel[vehicleid] == gCfgFuelLowValue)
    {
        SendClientMessage(playerid, COLOR_ORANGE, electric ? ("Bateria baixa. Procure um ponto de recarga.") : ("Combustivel baixo. Procure um posto."));
    }

    if (gVehicleFuel[vehicleid] <= 0)
    {
        SendClientMessage(playerid, COLOR_RED, electric ? ("A bateria acabou e o veiculo desligou.") : ("O veiculo ficou sem combustivel e desligou."));
    }
    return 1;
}

public Fuel_UpdateAll()
{
    new playerid;
    new maxPlayers = GetMaxPlayers();
    new startTick = GetTickCount();
    new scanned;
    new active;

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && PlayerInfo[playerid][pLogged] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
        {
            scanned++;
            active += Fuel_UpdateDriver(playerid);
        }
    }
    Gm_RecordTimerMetric(GM_TIMER_FUEL, GetTickCount() - startTick, scanned, active);
    return 1;
}

stock Fuel_OnPlayerStateChange(playerid, newstate, oldstate)
{
    new vehicleid;
    #pragma unused oldstate

    if (newstate == PLAYER_STATE_DRIVER)
    {
        vehicleid = GetPlayerVehicleID(playerid);
        Fuel_EnsureVehicle(vehicleid);

        if (Fuel_IsMotorizedVehicle(vehicleid))
        {
            Fuel_ApplyEngine(vehicleid);
            SendClientMessage(playerid, COLOR_YELLOW, "Use /motor para ligar ou desligar o veiculo.");
            if (Fuel_IsElectricVehicle(vehicleid))
            {
                SendClientMessage(playerid, COLOR_BLUE, "Veiculo eletrico: use /recarregar nos postos, delegacias ou na garagem da sua residencia.");
            }
        }
    }
    return 1;
}

stock Fuel_OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        return 0;
    }
    #pragma unused newkeys
    #pragma unused oldkeys
    return 0;
}

stock Fuel_ShiftPlayerGear(playerid, direction, showError = 1)
{
    new vehicleid;
    new gear;
    new tick;
    new text[32];

    if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        if (showError) SendClientMessage(playerid, COLOR_GRAY, "Voce precisa estar dirigindo um veiculo.");
        return 0;
    }

    vehicleid = GetPlayerVehicleID(playerid);
    if (!Fuel_IsManualVehicle(vehicleid))
    {
        if (showError) SendClientMessage(playerid, COLOR_GRAY, "Este veiculo usa cambio automatico.");
        return 0;
    }

    tick = GetTickCount();
    if (tick - gVehicleShiftTick[vehicleid] < MANUAL_SHIFT_COOLDOWN_MS)
    {
        return 1;
    }

    Fuel_EnsureVehicle(vehicleid);
    gear = gVehicleGear[vehicleid] + direction;
    if (gear < MANUAL_GEAR_MIN)
    {
        gear = MANUAL_GEAR_MIN;
    }
    if (gear > MANUAL_GEAR_MAX)
    {
        gear = MANUAL_GEAR_MAX;
    }

    if (gear == gVehicleGear[vehicleid])
    {
        if (showError) SendClientMessage(playerid, COLOR_GRAY, "Cambio ja esta no limite.");
        return 1;
    }

    gVehicleGear[vehicleid] = gear;
    gVehicleShiftTick[vehicleid] = tick;
    format(text, sizeof(text), "~w~Marcha ~y~%d", gear);
    GameTextForPlayer(playerid, text, 1200, 3);
    return 1;
}

stock Fuel_FindPlayerChargePoint(playerid, output[], size = sizeof(output))
{
    new index;
    new locationid;

    for (index = 0; index < sizeof(gEvChargeLocations); index++)
    {
        locationid = gEvChargeLocations[index];
        if (GetPlayerInterior(playerid) == gServerLocations[locationid][locInterior] && GetPlayerVirtualWorld(playerid) == gServerLocations[locationid][locVirtualWorld] && IsPlayerInRangeOfPoint(playerid, EV_CHARGE_RANGE, gServerLocations[locationid][locX], gServerLocations[locationid][locY], gServerLocations[locationid][locZ]))
        {
            format(output, size, "%s", gServerLocations[locationid][locName]);
            return 1;
        }
    }

    if (Property_IsNearHomeCharger(playerid))
    {
        format(output, size, "garagem residencial");
        return 1;
    }
    return 0;
}

stock Fuel_ChargePlayerVehicle(playerid)
{
    new vehicleid;
    new currentCharge;
    new neededCharge;
    new unitPrice;
    new cost;
    new pointName[40];
    new message[144];

    if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Entre dirigindo o veiculo eletrico que sera recarregado.");
        return 1;
    }

    vehicleid = GetPlayerVehicleID(playerid);
    if (!Fuel_IsElectricVehicle(vehicleid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Este veiculo nao e eletrico. Use /abastecer em um posto.");
        return 1;
    }

    if (!Fuel_FindPlayerChargePoint(playerid, pointName, sizeof(pointName)))
    {
        SendClientMessage(playerid, COLOR_RED, "Leve o veiculo ate um ponto de recarga, delegacia ou garagem residencial.");
        return 1;
    }

    if (GetVehicleSpeedKmh(vehicleid) > 3)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Pare o veiculo antes de iniciar a recarga.");
        return 1;
    }

    Fuel_EnsureVehicle(vehicleid);
    currentCharge = Fuel_GetVehicleFuel(vehicleid);
    if (currentCharge >= FUEL_MAX_VALUE)
    {
        SendClientMessage(playerid, COLOR_GRAY, "A bateria ja esta cheia.");
        return 1;
    }

    neededCharge = FUEL_MAX_VALUE - currentCharge;
    unitPrice = Fuel_GetDefaultUnitPrice(vehicleid);
    cost = neededCharge * Cfg_Price(unitPrice);
    if (cost < Cfg_Price(EV_CHARGE_MIN_COST))
    {
        cost = Cfg_Price(EV_CHARGE_MIN_COST);
    }
    cost = Vip_ApplyDiscount(playerid, cost);

    if (!Bank_TakePaymentReason(playerid, cost, 0, "electric_vehicle_charge"))
    {
        format(message, sizeof(message), "Recarga custa $%d em dinheiro/banco.", cost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    Fuel_SetVehicleFuel(vehicleid, FUEL_MAX_VALUE);
    gVehicleEngineOn[vehicleid] = 0;
    Fuel_ApplyEngine(vehicleid);
    Dealership_SaveActiveVehState(playerid);
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Bateria recarregada em %s: +%d%% por $%d.", pointName, neededCharge, cost);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Fuel_SendPlayerVehicleStatus(playerid)
{
    new vehicleid;
    new fuelName[24];
    new message[144];
    new electric;

    if (!IsPlayerInAnyVehicle(playerid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce precisa estar em um veiculo.");
        return 1;
    }

    vehicleid = GetPlayerVehicleID(playerid);
    Fuel_EnsureVehicle(vehicleid);
    Fuel_GetDefaultFuelName(vehicleid, fuelName, sizeof(fuelName));
    electric = Fuel_IsElectricVehicle(vehicleid);
    format(message, sizeof(message), "%s: %d%% | Tipo: %s | Motor: %s | Cambio: automatico.",
        electric ? ("Bateria") : ("Combustivel"),
        gVehicleFuel[vehicleid],
        fuelName,
        gVehicleEngineOn[vehicleid] ? ("ligado") : ("desligado"));
    SendClientMessage(playerid, COLOR_YELLOW, message);
    return 1;
}

stock HandleFuelCommands(playerid, cmdtext[])
{
    new command[32];

    GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/motor", true) == 0)
    {
        Fuel_TogglePlayerEngine(playerid);
        return 1;
    }

    if (strcmp(command, "/combustivel", true) == 0 || strcmp(command, "/fuel", true) == 0)
    {
        return Fuel_SendPlayerVehicleStatus(playerid);
    }

    if (strcmp(command, "/recarregar", true) == 0 || strcmp(command, "/recarga", true) == 0 || strcmp(command, "/carregarbateria", true) == 0)
    {
        return Fuel_ChargePlayerVehicle(playerid);
    }

    if (strcmp(command, "/cambio", true) == 0 || strcmp(command, "/marcha", true) == 0)
    {
        SendClientMessage(playerid, COLOR_YELLOW, "Cambio manual removido: os veiculos usam automatico. Eletricos continuam com /recarregar.");
        return Fuel_SendPlayerVehicleStatus(playerid);
    }

    return 0;
}
