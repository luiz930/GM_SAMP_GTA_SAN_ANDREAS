#if defined _nova_dealership_included
    #endinput
#endif
#define _nova_dealership_included

#define DETRAN_DIALOG_ACTIONS      (12)
#define DETRAN_ACT_REGISTER        (1)
#define DETRAN_ACT_PLATE           (2)
#define DETRAN_ACT_SHOW_IPVA       (3)
#define DETRAN_ACT_PAY_IPVA        (4)
#define DETRAN_ACT_SHOW_FINES      (5)
#define DETRAN_ACT_PAY_FINES       (6)
#define DETRAN_ACT_TRANSFER        (7)
#define DETRAN_ACT_DOC             (8)
#define DETRAN_ACT_INSPECTION      (9)
#define DETRAN_ACT_AUCTION         (10)
#define DETRAN_ACT_GPS             (11)
#define DEALER_DIALOG_ITEMS        (8)

enum eDealerVehicle
{
    dealerName[32],
    dealerModel,
    dealerPrice,
    dealerColor1,
    dealerColor2
}

new gDealerVehicles[][eDealerVehicle] =
{
    { "Honda Biz 125", 462, 2500, 1, 1 },
    { "Fiat Tipo", 496, 12000, 3, 3 },
    { "Fiat Palio", 426, 18000, 0, 0 },
    { "MB 608-D Bau", 482, 25000, 1, 1 },
    { "Fiat Palio EDX", 560, 55000, 6, 6 },
    { "E-Compacto Volt", 429, 42000, 1, 1 },
    { "E-Sedan Urbano", 415, 62000, 0, 1 },
    { "E-Sport GT", 541, 85000, 6, 6 }
};

new gPlayerOwnedVehicle[MAX_PLAYERS];
new gPlayerVehicleCount[MAX_PLAYERS];
new gPlayerVehicleActiveSlot[MAX_PLAYERS];
new gPlayerVehicleSpawnedSlot[MAX_PLAYERS];
new gPlayerGarageDialogSlot[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerGarageDialogCount[MAX_PLAYERS];
new gDealerDialogItems[MAX_PLAYERS][DEALER_DIALOG_ITEMS];
new gDealerDialogCount[MAX_PLAYERS];
new gDetranDialogActions[MAX_PLAYERS][DETRAN_DIALOG_ACTIONS];
new gDetranDialogActionCount[MAX_PLAYERS];

new gPlayerVehicleModel[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleColor1[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleColor2[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehiclePlate[MAX_PLAYERS][MAX_PLAYER_VEHICLES][16];
new gPlayerVehicleFuel[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new Float:gPlayerVehicleHealth[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new Float:gPlayerVehiclePosX[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new Float:gPlayerVehiclePosY[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new Float:gPlayerVehiclePosZ[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new Float:gPlayerVehiclePosA[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleInterior[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleVirtualWorld[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleParked[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleInsurance[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleGarage[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleImpounded[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleTaxDue[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleRegistered[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleLocked[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleGarageType[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleGarageProperty[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleTaxExpiry[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleInsuranceExpiry[MAX_PLAYERS][MAX_PLAYER_VEHICLES];
new gPlayerVehicleKeyHolder[MAX_PLAYERS][MAX_PLAYER_VEHICLES][MAX_VEHICLE_SHARED_KEYS];

stock Dealership_ClearVehicleKeys(playerid, slot)
{
    new index;

    if (slot < 0 || slot >= MAX_PLAYER_VEHICLES)
    {
        return 0;
    }

    for (index = 0; index < MAX_VEHICLE_SHARED_KEYS; index++)
    {
        gPlayerVehicleKeyHolder[playerid][slot][index] = INVALID_PLAYER_ID;
    }
    return 1;
}

stock Dealership_ResetVehicleSlot(playerid, slot)
{
    if (slot < 0 || slot >= MAX_PLAYER_VEHICLES)
    {
        return 0;
    }

    gPlayerVehicleModel[playerid][slot] = 0;
    gPlayerVehicleColor1[playerid][slot] = 1;
    gPlayerVehicleColor2[playerid][slot] = 1;
    format(gPlayerVehiclePlate[playerid][slot], 16, "");
    gPlayerVehicleFuel[playerid][slot] = FUEL_MAX_VALUE;
    gPlayerVehicleHealth[playerid][slot] = 1000.0;
    gPlayerVehiclePosX[playerid][slot] = 0.0;
    gPlayerVehiclePosY[playerid][slot] = 0.0;
    gPlayerVehiclePosZ[playerid][slot] = 0.0;
    gPlayerVehiclePosA[playerid][slot] = 0.0;
    gPlayerVehicleInterior[playerid][slot] = 0;
    gPlayerVehicleVirtualWorld[playerid][slot] = 0;
    gPlayerVehicleParked[playerid][slot] = 0;
    gPlayerVehicleInsurance[playerid][slot] = 0;
    gPlayerVehicleGarage[playerid][slot] = 0;
    gPlayerVehicleImpounded[playerid][slot] = 0;
    gPlayerVehicleTaxDue[playerid][slot] = 0;
    gPlayerVehicleRegistered[playerid][slot] = 0;
    gPlayerVehicleLocked[playerid][slot] = 0;
    gPlayerVehicleGarageType[playerid][slot] = VEHICLE_GARAGE_NONE;
    gPlayerVehicleGarageProperty[playerid][slot] = HOUSE_NONE;
    gPlayerVehicleTaxExpiry[playerid][slot] = 0;
    gPlayerVehicleInsuranceExpiry[playerid][slot] = 0;
    Dealership_ClearVehicleKeys(playerid, slot);
    return 1;
}

stock Dealership_ResetPlayerVehicles(playerid)
{
    new slot;

    gPlayerOwnedVehicle[playerid] = 0;
    gPlayerVehicleCount[playerid] = 0;
    gPlayerVehicleActiveSlot[playerid] = -1;
    gPlayerVehicleSpawnedSlot[playerid] = -1;
    gPlayerGarageDialogCount[playerid] = 0;
    gDealerDialogCount[playerid] = 0;
    gDetranDialogActionCount[playerid] = 0;

    for (slot = 0; slot < MAX_PLAYER_VEHICLES; slot++)
    {
        Dealership_ResetVehicleSlot(playerid, slot);
        gPlayerGarageDialogSlot[playerid][slot] = -1;
    }
    return 1;
}

stock Dealership_IsValidSlot(playerid, slot)
{
    if (slot < 0 || slot >= gPlayerVehicleCount[playerid] || slot >= MAX_PLAYER_VEHICLES)
    {
        return 0;
    }

    return (gPlayerVehicleModel[playerid][slot] >= 400 && gPlayerVehicleModel[playerid][slot] <= 611);
}

stock Dealership_PlayerLimit(playerid)
{
    new limit = 2;
    new propertyid = PlayerInfo[playerid][pHouse];
    new index;

    if (PlayerInfo[playerid][pLevel] >= 5)
    {
        limit++;
    }

    if (propertyid == HOUSE_NONE)
    {
        propertyid = PlayerInfo[playerid][pRentedHouse];
    }

    index = Property_GetIndex(propertyid);
    if (index != -1)
    {
        limit += gProperties[index][propGarageSlots];
    }

    limit += Vip_GetExtraVehicleSlots(playerid);

    if (limit > MAX_PLAYER_VEHICLES)
    {
        limit = MAX_PLAYER_VEHICLES;
    }
    return limit;
}

stock Dealership_SyncSlotToPlayer(playerid, slot)
{
    if (!Dealership_IsValidSlot(playerid, slot))
    {
        PlayerInfo[playerid][pVehicleModel] = 0;
        return 0;
    }

    PlayerInfo[playerid][pVehicleModel] = gPlayerVehicleModel[playerid][slot];
    PlayerInfo[playerid][pVehicleColor1] = gPlayerVehicleColor1[playerid][slot];
    PlayerInfo[playerid][pVehicleColor2] = gPlayerVehicleColor2[playerid][slot];
    format(PlayerInfo[playerid][pVehiclePlate], 16, "%s", gPlayerVehiclePlate[playerid][slot]);
    PlayerInfo[playerid][pVehicleFuel] = gPlayerVehicleFuel[playerid][slot];
    PlayerInfo[playerid][pVehicleHealth] = gPlayerVehicleHealth[playerid][slot];
    PlayerInfo[playerid][pVehiclePosX] = gPlayerVehiclePosX[playerid][slot];
    PlayerInfo[playerid][pVehiclePosY] = gPlayerVehiclePosY[playerid][slot];
    PlayerInfo[playerid][pVehiclePosZ] = gPlayerVehiclePosZ[playerid][slot];
    PlayerInfo[playerid][pVehiclePosA] = gPlayerVehiclePosA[playerid][slot];
    PlayerInfo[playerid][pVehicleInterior] = gPlayerVehicleInterior[playerid][slot];
    PlayerInfo[playerid][pVehicleVirtualWorld] = gPlayerVehicleVirtualWorld[playerid][slot];
    PlayerInfo[playerid][pVehicleParked] = gPlayerVehicleParked[playerid][slot];
    PlayerInfo[playerid][pVehicleInsurance] = gPlayerVehicleInsurance[playerid][slot];
    PlayerInfo[playerid][pVehicleGarage] = gPlayerVehicleGarage[playerid][slot];
    PlayerInfo[playerid][pVehicleImpounded] = gPlayerVehicleImpounded[playerid][slot];
    PlayerInfo[playerid][pVehicleTaxDue] = gPlayerVehicleTaxDue[playerid][slot];
    return 1;
}

stock Dealership_SyncPlayerToSlot(playerid, slot)
{
    if (slot < 0 || slot >= MAX_PLAYER_VEHICLES)
    {
        return 0;
    }

    gPlayerVehicleModel[playerid][slot] = PlayerInfo[playerid][pVehicleModel];
    gPlayerVehicleColor1[playerid][slot] = PlayerInfo[playerid][pVehicleColor1];
    gPlayerVehicleColor2[playerid][slot] = PlayerInfo[playerid][pVehicleColor2];
    format(gPlayerVehiclePlate[playerid][slot], 16, "%s", PlayerInfo[playerid][pVehiclePlate]);
    gPlayerVehicleFuel[playerid][slot] = PlayerInfo[playerid][pVehicleFuel];
    gPlayerVehicleHealth[playerid][slot] = PlayerInfo[playerid][pVehicleHealth];
    gPlayerVehiclePosX[playerid][slot] = PlayerInfo[playerid][pVehiclePosX];
    gPlayerVehiclePosY[playerid][slot] = PlayerInfo[playerid][pVehiclePosY];
    gPlayerVehiclePosZ[playerid][slot] = PlayerInfo[playerid][pVehiclePosZ];
    gPlayerVehiclePosA[playerid][slot] = PlayerInfo[playerid][pVehiclePosA];
    gPlayerVehicleInterior[playerid][slot] = PlayerInfo[playerid][pVehicleInterior];
    gPlayerVehicleVirtualWorld[playerid][slot] = PlayerInfo[playerid][pVehicleVirtualWorld];
    gPlayerVehicleParked[playerid][slot] = PlayerInfo[playerid][pVehicleParked];
    gPlayerVehicleInsurance[playerid][slot] = PlayerInfo[playerid][pVehicleInsurance];
    gPlayerVehicleGarage[playerid][slot] = PlayerInfo[playerid][pVehicleGarage];
    gPlayerVehicleImpounded[playerid][slot] = PlayerInfo[playerid][pVehicleImpounded];
    gPlayerVehicleTaxDue[playerid][slot] = PlayerInfo[playerid][pVehicleTaxDue];
    return 1;
}

stock Dealership_SetActiveSlot(playerid, slot)
{
    if (!Dealership_IsValidSlot(playerid, slot))
    {
        return 0;
    }

    if (gPlayerOwnedVehicle[playerid] != 0 && gPlayerVehicleSpawnedSlot[playerid] != slot)
    {
        Dealership_DestroyPlayerVehicle(playerid);
    }

    gPlayerVehicleActiveSlot[playerid] = slot;
    return Dealership_SyncSlotToPlayer(playerid, slot);
}

stock Dealership_FindVehicleOwner(vehicleid)
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && gPlayerOwnedVehicle[playerid] == vehicleid)
        {
            return playerid;
        }
    }
    return INVALID_PLAYER_ID;
}

stock Dealership_SaveActiveVehState(playerid)
{
    new slot = gPlayerVehicleActiveSlot[playerid];
    new vehicleid = gPlayerOwnedVehicle[playerid];

    if (slot < 0 || slot >= MAX_PLAYER_VEHICLES)
    {
        return 0;
    }

    if (vehicleid != 0 && vehicleid != INVALID_VEHICLE_ID && Fuel_IsValidVehicle(vehicleid))
    {
        GetVehiclePos(vehicleid, PlayerInfo[playerid][pVehiclePosX], PlayerInfo[playerid][pVehiclePosY], PlayerInfo[playerid][pVehiclePosZ]);
        GetVehicleZAngle(vehicleid, PlayerInfo[playerid][pVehiclePosA]);
        GetVehicleHealth(vehicleid, PlayerInfo[playerid][pVehicleHealth]);
        PlayerInfo[playerid][pVehicleFuel] = Fuel_GetVehicleFuel(vehicleid);
        if (IsPlayerInVehicle(playerid, vehicleid))
        {
            PlayerInfo[playerid][pVehicleInterior] = GetPlayerInterior(playerid);
        }
        PlayerInfo[playerid][pVehicleVirtualWorld] = GetVehicleVirtualWorld(vehicleid);
    }

    return Dealership_SyncPlayerToSlot(playerid, slot);
}

stock SavePlayerOwnedVehicleState(playerid)
{
    return Dealership_SaveActiveVehState(playerid);
}

stock Dealership_DestroyPlayerVehicle(playerid)
{
    if (gPlayerOwnedVehicle[playerid] != 0 && gPlayerOwnedVehicle[playerid] != INVALID_VEHICLE_ID)
    {
        SavePlayerOwnedVehicleState(playerid);
        Radio_OnVehicleDestroyed(gPlayerOwnedVehicle[playerid]);
        DestroyVehicle(gPlayerOwnedVehicle[playerid]);
    }

    gPlayerOwnedVehicle[playerid] = 0;
    gPlayerVehicleSpawnedSlot[playerid] = -1;
    return 1;
}

stock GetDealerVehicleNameByModel(modelid, output[], size = sizeof(output))
{
    new index;

    for (index = 0; index < sizeof(gDealerVehicles); index++)
    {
        if (gDealerVehicles[index][dealerModel] == modelid)
        {
            format(output, size, "%s", gDealerVehicles[index][dealerName]);
            return 1;
        }
    }

    format(output, size, "Modelo %d", modelid);
    return 0;
}

stock GetDealerVehiclePriceByModel(modelid)
{
    new index;

    for (index = 0; index < sizeof(gDealerVehicles); index++)
    {
        if (gDealerVehicles[index][dealerModel] == modelid)
        {
            return Cfg_VehiclePrice(gDealerVehicles[index][dealerPrice]);
        }
    }
    return 10000;
}

stock Dealership_GetVehicleTax(modelid)
{
    new price = GetDealerVehiclePriceByModel(modelid);
    new tax;

    if (Fuel_IsMotorcycleModel(modelid))
    {
        tax = gCfgVehicleIpvaBase + ((price * 2) / 100);
    }
    else if (Fuel_IsDieselModel(modelid))
    {
        tax = gCfgVehicleIpvaBase + ((price * 15) / 1000);
    }
    else
    {
        tax = gCfgVehicleIpvaBase + ((price * gCfgVehicleIpvaPercent) / 100);
    }

    if (gCfgVehicleIpvaBase > 0 && tax < gCfgVehicleIpvaBase)
    {
        tax = gCfgVehicleIpvaBase;
    }
    return tax;
}

stock Dealership_AddVehicle(playerid, modelid, color1, color2, registered = 0)
{
    new slot = gPlayerVehicleCount[playerid];

    if (slot >= Dealership_PlayerLimit(playerid) || slot >= MAX_PLAYER_VEHICLES)
    {
        return -1;
    }

    Dealership_ResetVehicleSlot(playerid, slot);
    gPlayerVehicleModel[playerid][slot] = modelid;
    gPlayerVehicleColor1[playerid][slot] = color1;
    gPlayerVehicleColor2[playerid][slot] = color2;
    gPlayerVehicleFuel[playerid][slot] = FUEL_MAX_VALUE;
    gPlayerVehicleHealth[playerid][slot] = 1000.0;
    gPlayerVehicleTaxDue[playerid][slot] = Dealership_GetVehicleTax(modelid);
    gPlayerVehicleRegistered[playerid][slot] = registered;
    gPlayerVehicleLocked[playerid][slot] = 0;
    gPlayerVehicleGarageType[playerid][slot] = VEHICLE_GARAGE_NONE;
    gPlayerVehicleGarageProperty[playerid][slot] = HOUSE_NONE;
    gPlayerVehicleTaxExpiry[playerid][slot] = GetBrasiliaDayStamp();
    gPlayerVehicleInsuranceExpiry[playerid][slot] = 0;
    format(gPlayerVehiclePlate[playerid][slot], 16, "LS-%04d", random(10000));
    gPlayerVehicleCount[playerid]++;
    Dealership_SetActiveSlot(playerid, slot);
    return slot;
}

stock Dealership_RemoveSlot(playerid, slot)
{
    new index;
    new keyIndex;

    if (!Dealership_IsValidSlot(playerid, slot))
    {
        return 0;
    }

    if (gPlayerVehicleSpawnedSlot[playerid] == slot)
    {
        Dealership_DestroyPlayerVehicle(playerid);
    }

    for (index = slot; index < (gPlayerVehicleCount[playerid] - 1); index++)
    {
        gPlayerVehicleModel[playerid][index] = gPlayerVehicleModel[playerid][index + 1];
        gPlayerVehicleColor1[playerid][index] = gPlayerVehicleColor1[playerid][index + 1];
        gPlayerVehicleColor2[playerid][index] = gPlayerVehicleColor2[playerid][index + 1];
        format(gPlayerVehiclePlate[playerid][index], 16, "%s", gPlayerVehiclePlate[playerid][index + 1]);
        gPlayerVehicleFuel[playerid][index] = gPlayerVehicleFuel[playerid][index + 1];
        gPlayerVehicleHealth[playerid][index] = gPlayerVehicleHealth[playerid][index + 1];
        gPlayerVehiclePosX[playerid][index] = gPlayerVehiclePosX[playerid][index + 1];
        gPlayerVehiclePosY[playerid][index] = gPlayerVehiclePosY[playerid][index + 1];
        gPlayerVehiclePosZ[playerid][index] = gPlayerVehiclePosZ[playerid][index + 1];
        gPlayerVehiclePosA[playerid][index] = gPlayerVehiclePosA[playerid][index + 1];
        gPlayerVehicleInterior[playerid][index] = gPlayerVehicleInterior[playerid][index + 1];
        gPlayerVehicleVirtualWorld[playerid][index] = gPlayerVehicleVirtualWorld[playerid][index + 1];
        gPlayerVehicleParked[playerid][index] = gPlayerVehicleParked[playerid][index + 1];
        gPlayerVehicleInsurance[playerid][index] = gPlayerVehicleInsurance[playerid][index + 1];
        gPlayerVehicleGarage[playerid][index] = gPlayerVehicleGarage[playerid][index + 1];
        gPlayerVehicleImpounded[playerid][index] = gPlayerVehicleImpounded[playerid][index + 1];
        gPlayerVehicleTaxDue[playerid][index] = gPlayerVehicleTaxDue[playerid][index + 1];
        gPlayerVehicleRegistered[playerid][index] = gPlayerVehicleRegistered[playerid][index + 1];
        gPlayerVehicleLocked[playerid][index] = gPlayerVehicleLocked[playerid][index + 1];
        gPlayerVehicleGarageType[playerid][index] = gPlayerVehicleGarageType[playerid][index + 1];
        gPlayerVehicleGarageProperty[playerid][index] = gPlayerVehicleGarageProperty[playerid][index + 1];
        gPlayerVehicleTaxExpiry[playerid][index] = gPlayerVehicleTaxExpiry[playerid][index + 1];
        gPlayerVehicleInsuranceExpiry[playerid][index] = gPlayerVehicleInsuranceExpiry[playerid][index + 1];
        for (keyIndex = 0; keyIndex < MAX_VEHICLE_SHARED_KEYS; keyIndex++)
        {
            gPlayerVehicleKeyHolder[playerid][index][keyIndex] = gPlayerVehicleKeyHolder[playerid][index + 1][keyIndex];
        }
    }

    gPlayerVehicleCount[playerid]--;
    Dealership_ResetVehicleSlot(playerid, gPlayerVehicleCount[playerid]);

    if (gPlayerVehicleCount[playerid] <= 0)
    {
        gPlayerVehicleActiveSlot[playerid] = -1;
        PlayerInfo[playerid][pVehicleModel] = 0;
        return 1;
    }

    if (gPlayerVehicleActiveSlot[playerid] >= gPlayerVehicleCount[playerid])
    {
        gPlayerVehicleActiveSlot[playerid] = gPlayerVehicleCount[playerid] - 1;
    }
    Dealership_SetActiveSlot(playerid, gPlayerVehicleActiveSlot[playerid]);
    return 1;
}

stock Dealership_FormatStatus(playerid, slot, output[], size = sizeof(output))
{
    if (gPlayerVehicleImpounded[playerid][slot])
    {
        format(output, size, "Patio");
    }
    else if (gPlayerVehicleGarage[playerid][slot])
    {
        if (gPlayerVehicleGarageType[playerid][slot] == VEHICLE_GARAGE_HOME)
        {
            format(output, size, "Garagem casa");
        }
        else
        {
            format(output, size, "Garagem publica");
        }
    }
    else if (gPlayerVehicleSpawnedSlot[playerid] == slot && gPlayerOwnedVehicle[playerid] != 0)
    {
        format(output, size, "Em uso");
    }
    else if (gPlayerVehicleParked[playerid][slot])
    {
        format(output, size, "Estacionado");
    }
    else
    {
        format(output, size, "Disponivel");
    }
    return 1;
}

stock Dlr_UpdateVehicleDocs(playerid, notify = 0)
{
    new slot;
    new changed;
    new today = GetBrasiliaDayStamp();
    new message[128];

    for (slot = 0; slot < gPlayerVehicleCount[playerid] && slot < MAX_PLAYER_VEHICLES; slot++)
    {
        if (!Dealership_IsValidSlot(playerid, slot))
        {
            continue;
        }

        if (gPlayerVehicleTaxDue[playerid][slot] <= 0 && gPlayerVehicleTaxExpiry[playerid][slot] <= 0)
        {
            gPlayerVehicleTaxExpiry[playerid][slot] = today + VEHICLE_IPVA_VALID_DAYS;
            changed = 1;
        }

        if (gPlayerVehicleTaxDue[playerid][slot] <= 0 && gPlayerVehicleTaxExpiry[playerid][slot] > 0 && gPlayerVehicleTaxExpiry[playerid][slot] <= today)
        {
            gPlayerVehicleTaxDue[playerid][slot] = Dealership_GetVehicleTax(gPlayerVehicleModel[playerid][slot]);
            gPlayerVehicleTaxExpiry[playerid][slot] = today;
            changed = 1;
            if (notify && slot == gPlayerVehicleActiveSlot[playerid])
            {
                format(message, sizeof(message), "IPVA do veiculo ativo venceu. Debito atual: $%d.", gPlayerVehicleTaxDue[playerid][slot]);
                SendClientMessage(playerid, COLOR_ORANGE, message);
            }
        }

        if (gPlayerVehicleInsurance[playerid][slot] && gPlayerVehicleInsuranceExpiry[playerid][slot] <= 0)
        {
            gPlayerVehicleInsuranceExpiry[playerid][slot] = today + VEHICLE_INSURANCE_VALID_DAYS;
            changed = 1;
        }

        if (gPlayerVehicleInsurance[playerid][slot] && gPlayerVehicleInsuranceExpiry[playerid][slot] > 0 && gPlayerVehicleInsuranceExpiry[playerid][slot] <= today)
        {
            gPlayerVehicleInsurance[playerid][slot] = 0;
            gPlayerVehicleInsuranceExpiry[playerid][slot] = 0;
            changed = 1;
            if (notify && slot == gPlayerVehicleActiveSlot[playerid])
            {
                SendClientMessage(playerid, COLOR_ORANGE, "Seguro do veiculo ativo venceu.");
            }
        }
    }

    if (changed && Dealership_IsValidSlot(playerid, gPlayerVehicleActiveSlot[playerid]))
    {
        Dealership_SyncSlotToPlayer(playerid, gPlayerVehicleActiveSlot[playerid]);
    }
    return changed;
}

stock Dealership_GetDaysLeft(expiryDay)
{
    new days = expiryDay - GetBrasiliaDayStamp();

    if (days < 0)
    {
        days = 0;
    }
    return days;
}

stock Dealership_FinalizeAccountLoad(playerid)
{
    if (gPlayerVehicleCount[playerid] <= 0 && PlayerInfo[playerid][pVehicleModel] >= 400 && PlayerInfo[playerid][pVehicleModel] <= 611)
    {
        gPlayerVehicleCount[playerid] = 1;
        gPlayerVehicleActiveSlot[playerid] = 0;
        Dealership_SyncPlayerToSlot(playerid, 0);
        gPlayerVehicleRegistered[playerid][0] = 1;
    }

    if (gPlayerVehicleCount[playerid] > MAX_PLAYER_VEHICLES)
    {
        gPlayerVehicleCount[playerid] = MAX_PLAYER_VEHICLES;
    }

    if (gPlayerVehicleCount[playerid] > 0)
    {
        if (gPlayerVehicleActiveSlot[playerid] < 0 || gPlayerVehicleActiveSlot[playerid] >= gPlayerVehicleCount[playerid])
        {
            gPlayerVehicleActiveSlot[playerid] = 0;
        }
        Dealership_SyncSlotToPlayer(playerid, gPlayerVehicleActiveSlot[playerid]);
    }
    Dlr_UpdateVehicleDocs(playerid, 0);
    return 1;
}

stock Dlr_RepairAccountVehicles(playerid, apply, report[], size)
{
    new slot;
    new repairs;
    new firstValid = -1;
    new invalidFlags;

    if (gPlayerVehicleCount[playerid] < 0 || gPlayerVehicleCount[playerid] > MAX_PLAYER_VEHICLES)
    {
        repairs++;
        Account_AppendRepair(report, size, "contagem veiculo");
        if (apply)
        {
            if (gPlayerVehicleCount[playerid] < 0) gPlayerVehicleCount[playerid] = 0;
            if (gPlayerVehicleCount[playerid] > MAX_PLAYER_VEHICLES) gPlayerVehicleCount[playerid] = MAX_PLAYER_VEHICLES;
        }
    }

    for (slot = 0; slot < gPlayerVehicleCount[playerid] && slot < MAX_PLAYER_VEHICLES; slot++)
    {
        if (gPlayerVehicleModel[playerid][slot] < 400 || gPlayerVehicleModel[playerid][slot] > 611)
        {
            repairs++;
            Account_AppendRepair(report, size, "slot veiculo invalido");
            if (apply) Dealership_ResetVehicleSlot(playerid, slot);
            continue;
        }

        if (firstValid == -1)
        {
            firstValid = slot;
        }
        if (gPlayerVehicleFuel[playerid][slot] < 0 || gPlayerVehicleFuel[playerid][slot] > FUEL_MAX_VALUE)
        {
            repairs++;
            Account_AppendRepair(report, size, "combustivel veiculo");
            if (apply)
            {
                if (gPlayerVehicleFuel[playerid][slot] < 0) gPlayerVehicleFuel[playerid][slot] = 0;
                if (gPlayerVehicleFuel[playerid][slot] > FUEL_MAX_VALUE) gPlayerVehicleFuel[playerid][slot] = FUEL_MAX_VALUE;
            }
        }
        if (gPlayerVehicleHealth[playerid][slot] < 250.0 || gPlayerVehicleHealth[playerid][slot] > 1000.0)
        {
            repairs++;
            Account_AppendRepair(report, size, "vida veiculo");
            if (apply) gPlayerVehicleHealth[playerid][slot] = 1000.0;
        }
        if (gPlayerVehicleColor1[playerid][slot] < 0 || gPlayerVehicleColor1[playerid][slot] > 255
            || gPlayerVehicleColor2[playerid][slot] < 0 || gPlayerVehicleColor2[playerid][slot] > 255)
        {
            repairs++;
            Account_AppendRepair(report, size, "cor veiculo");
            if (apply)
            {
                if (gPlayerVehicleColor1[playerid][slot] < 0 || gPlayerVehicleColor1[playerid][slot] > 255)
                {
                    gPlayerVehicleColor1[playerid][slot] = 1;
                }
                if (gPlayerVehicleColor2[playerid][slot] < 0 || gPlayerVehicleColor2[playerid][slot] > 255)
                {
                    gPlayerVehicleColor2[playerid][slot] = 1;
                }
            }
        }
        if (gPlayerVehicleInterior[playerid][slot] < 0 || gPlayerVehicleInterior[playerid][slot] > 255
            || gPlayerVehicleVirtualWorld[playerid][slot] < 0)
        {
            repairs++;
            Account_AppendRepair(report, size, "mundo veiculo");
            if (apply)
            {
                if (gPlayerVehicleInterior[playerid][slot] < 0 || gPlayerVehicleInterior[playerid][slot] > 255)
                {
                    gPlayerVehicleInterior[playerid][slot] = 0;
                }
                if (gPlayerVehicleVirtualWorld[playerid][slot] < 0) gPlayerVehicleVirtualWorld[playerid][slot] = 0;
            }
        }
        invalidFlags = 0;
        if (gPlayerVehicleParked[playerid][slot] < 0 || gPlayerVehicleParked[playerid][slot] > 1) invalidFlags = 1;
        if (gPlayerVehicleInsurance[playerid][slot] < 0 || gPlayerVehicleInsurance[playerid][slot] > 1) invalidFlags = 1;
        if (gPlayerVehicleGarage[playerid][slot] < 0 || gPlayerVehicleGarage[playerid][slot] > 1) invalidFlags = 1;
        if (gPlayerVehicleImpounded[playerid][slot] < 0 || gPlayerVehicleImpounded[playerid][slot] > 1) invalidFlags = 1;
        if (gPlayerVehicleRegistered[playerid][slot] < 0 || gPlayerVehicleRegistered[playerid][slot] > 1) invalidFlags = 1;
        if (gPlayerVehicleLocked[playerid][slot] < 0 || gPlayerVehicleLocked[playerid][slot] > 1) invalidFlags = 1;
        if (invalidFlags)
        {
            repairs++;
            Account_AppendRepair(report, size, "flags veiculo");
            if (apply)
            {
                gPlayerVehicleParked[playerid][slot] = gPlayerVehicleParked[playerid][slot] ? 1 : 0;
                gPlayerVehicleInsurance[playerid][slot] = gPlayerVehicleInsurance[playerid][slot] ? 1 : 0;
                gPlayerVehicleGarage[playerid][slot] = gPlayerVehicleGarage[playerid][slot] ? 1 : 0;
                gPlayerVehicleImpounded[playerid][slot] = gPlayerVehicleImpounded[playerid][slot] ? 1 : 0;
                gPlayerVehicleRegistered[playerid][slot] = gPlayerVehicleRegistered[playerid][slot] ? 1 : 0;
                gPlayerVehicleLocked[playerid][slot] = gPlayerVehicleLocked[playerid][slot] ? 1 : 0;
            }
        }
        if (gPlayerVehicleTaxDue[playerid][slot] < 0 || gPlayerVehicleTaxExpiry[playerid][slot] < 0 || gPlayerVehicleInsuranceExpiry[playerid][slot] < 0)
        {
            repairs++;
            Account_AppendRepair(report, size, "taxas veiculo");
            if (apply)
            {
                if (gPlayerVehicleTaxDue[playerid][slot] < 0) gPlayerVehicleTaxDue[playerid][slot] = 0;
                if (gPlayerVehicleTaxExpiry[playerid][slot] < 0) gPlayerVehicleTaxExpiry[playerid][slot] = 0;
                if (gPlayerVehicleInsuranceExpiry[playerid][slot] < 0) gPlayerVehicleInsuranceExpiry[playerid][slot] = 0;
            }
        }
    }

    while (gPlayerVehicleCount[playerid] > 0 && (gPlayerVehicleModel[playerid][gPlayerVehicleCount[playerid] - 1] < 400 || gPlayerVehicleModel[playerid][gPlayerVehicleCount[playerid] - 1] > 611))
    {
        if (apply)
        {
            gPlayerVehicleCount[playerid]--;
        }
        else
        {
            break;
        }
    }

    if (gPlayerVehicleCount[playerid] <= 0 || firstValid == -1)
    {
        if (gPlayerVehicleCount[playerid] != 0 || gPlayerVehicleActiveSlot[playerid] != -1)
        {
            repairs++;
            Account_AppendRepair(report, size, "garagem vazia");
            if (apply)
            {
                gPlayerVehicleCount[playerid] = 0;
                gPlayerVehicleActiveSlot[playerid] = -1;
                PlayerInfo[playerid][pVehicleModel] = 0;
            }
        }
        return repairs;
    }

    if (gPlayerVehicleActiveSlot[playerid] < 0 || gPlayerVehicleActiveSlot[playerid] >= gPlayerVehicleCount[playerid] || !Dealership_IsValidSlot(playerid, gPlayerVehicleActiveSlot[playerid]))
    {
        repairs++;
        Account_AppendRepair(report, size, "veiculo ativo");
        if (apply)
        {
            gPlayerVehicleActiveSlot[playerid] = firstValid;
            Dealership_SyncSlotToPlayer(playerid, firstValid);
        }
    }

    return repairs;
}

stock ApplyVehicleAccountField(playerid, key[], value[])
{
    new rest[32];
    new field[28];
    new slot;

    if (strcmp(key, "vehicle_count", false) == 0)
    {
        gPlayerVehicleCount[playerid] = strval(value);
        if (gPlayerVehicleCount[playerid] < 0) gPlayerVehicleCount[playerid] = 0;
        if (gPlayerVehicleCount[playerid] > MAX_PLAYER_VEHICLES) gPlayerVehicleCount[playerid] = MAX_PLAYER_VEHICLES;
        return 1;
    }

    if (strcmp(key, "vehicle_active_slot", false) == 0)
    {
        gPlayerVehicleActiveSlot[playerid] = strval(value);
        return 1;
    }

    if (strfind(key, "vehicle_", false) != 0)
    {
        return 0;
    }

    strmid(rest, key, 8, strlen(key), sizeof(rest));
    if (rest[0] < '0' || rest[0] > '9' || rest[1] != '_')
    {
        return 0;
    }

    slot = rest[0] - '0';
    if (slot < 0 || slot >= MAX_PLAYER_VEHICLES)
    {
        return 1;
    }

    strmid(field, rest, 2, strlen(rest), sizeof(field));
    if (slot >= gPlayerVehicleCount[playerid])
    {
        gPlayerVehicleCount[playerid] = slot + 1;
    }

    if (strcmp(field, "model", false) == 0) gPlayerVehicleModel[playerid][slot] = strval(value);
    else if (strcmp(field, "color1", false) == 0) gPlayerVehicleColor1[playerid][slot] = strval(value);
    else if (strcmp(field, "color2", false) == 0) gPlayerVehicleColor2[playerid][slot] = strval(value);
    else if (strcmp(field, "plate", false) == 0) format(gPlayerVehiclePlate[playerid][slot], 16, "%s", value);
    else if (strcmp(field, "fuel", false) == 0) gPlayerVehicleFuel[playerid][slot] = strval(value);
    else if (strcmp(field, "health", false) == 0) gPlayerVehicleHealth[playerid][slot] = floatstr(value);
    else if (strcmp(field, "pos_x", false) == 0) gPlayerVehiclePosX[playerid][slot] = floatstr(value);
    else if (strcmp(field, "pos_y", false) == 0) gPlayerVehiclePosY[playerid][slot] = floatstr(value);
    else if (strcmp(field, "pos_z", false) == 0) gPlayerVehiclePosZ[playerid][slot] = floatstr(value);
    else if (strcmp(field, "pos_a", false) == 0) gPlayerVehiclePosA[playerid][slot] = floatstr(value);
    else if (strcmp(field, "interior", false) == 0) gPlayerVehicleInterior[playerid][slot] = strval(value);
    else if (strcmp(field, "virtual_world", false) == 0) gPlayerVehicleVirtualWorld[playerid][slot] = strval(value);
    else if (strcmp(field, "parked", false) == 0) gPlayerVehicleParked[playerid][slot] = strval(value);
    else if (strcmp(field, "insurance", false) == 0) gPlayerVehicleInsurance[playerid][slot] = strval(value);
    else if (strcmp(field, "garage", false) == 0) gPlayerVehicleGarage[playerid][slot] = strval(value);
    else if (strcmp(field, "impounded", false) == 0) gPlayerVehicleImpounded[playerid][slot] = strval(value);
    else if (strcmp(field, "tax_due", false) == 0) gPlayerVehicleTaxDue[playerid][slot] = strval(value);
    else if (strcmp(field, "registered", false) == 0) gPlayerVehicleRegistered[playerid][slot] = strval(value);
    else if (strcmp(field, "locked", false) == 0) gPlayerVehicleLocked[playerid][slot] = strval(value);
    else if (strcmp(field, "garage_type", false) == 0) gPlayerVehicleGarageType[playerid][slot] = strval(value);
    else if (strcmp(field, "garage_property", false) == 0) gPlayerVehicleGarageProperty[playerid][slot] = strval(value);
    else if (strcmp(field, "tax_expiry", false) == 0) gPlayerVehicleTaxExpiry[playerid][slot] = strval(value);
    else if (strcmp(field, "insurance_expiry", false) == 0) gPlayerVehicleInsuranceExpiry[playerid][slot] = strval(value);
    return 1;
}

stock SaveVehicleData(playerid, File:account)
{
    new slot;
    new line[144];

    Dealership_SaveActiveVehState(playerid);
    Dlr_UpdateVehicleDocs(playerid, 0);
    format(line, sizeof(line), "vehicle_count=%d\r\n", gPlayerVehicleCount[playerid]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_active_slot=%d\r\n", gPlayerVehicleActiveSlot[playerid]); fwrite(account, line);

    for (slot = 0; slot < gPlayerVehicleCount[playerid] && slot < MAX_PLAYER_VEHICLES; slot++)
    {
        format(line, sizeof(line), "vehicle_%d_model=%d\r\n", slot, gPlayerVehicleModel[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_color1=%d\r\n", slot, gPlayerVehicleColor1[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_color2=%d\r\n", slot, gPlayerVehicleColor2[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_plate=%s\r\n", slot, gPlayerVehiclePlate[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_fuel=%d\r\n", slot, gPlayerVehicleFuel[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_health=%.2f\r\n", slot, gPlayerVehicleHealth[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_pos_x=%.4f\r\n", slot, gPlayerVehiclePosX[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_pos_y=%.4f\r\n", slot, gPlayerVehiclePosY[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_pos_z=%.4f\r\n", slot, gPlayerVehiclePosZ[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_pos_a=%.4f\r\n", slot, gPlayerVehiclePosA[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_interior=%d\r\n", slot, gPlayerVehicleInterior[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_virtual_world=%d\r\n", slot, gPlayerVehicleVirtualWorld[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_parked=%d\r\n", slot, gPlayerVehicleParked[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_insurance=%d\r\n", slot, gPlayerVehicleInsurance[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_garage=%d\r\n", slot, gPlayerVehicleGarage[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_impounded=%d\r\n", slot, gPlayerVehicleImpounded[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_tax_due=%d\r\n", slot, gPlayerVehicleTaxDue[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_registered=%d\r\n", slot, gPlayerVehicleRegistered[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_locked=%d\r\n", slot, gPlayerVehicleLocked[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_garage_type=%d\r\n", slot, gPlayerVehicleGarageType[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_garage_property=%d\r\n", slot, gPlayerVehicleGarageProperty[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_tax_expiry=%d\r\n", slot, gPlayerVehicleTaxExpiry[playerid][slot]); fwrite(account, line);
        format(line, sizeof(line), "vehicle_%d_insurance_expiry=%d\r\n", slot, gPlayerVehicleInsuranceExpiry[playerid][slot]); fwrite(account, line);
    }
    return 1;
}

stock SpawnPlayerOwnedVehicle(playerid)
{
    new vehicleid;
    new message[144];
    new vehicleName[32];
    new slot = gPlayerVehicleActiveSlot[playerid];
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:angle;

    if (!Dealership_IsValidSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce ainda nao possui um veiculo salvo.");
        return 0;
    }

    Dlr_UpdateVehicleDocs(playerid, 1);
    Dealership_SyncSlotToPlayer(playerid, slot);
    if (PlayerInfo[playerid][pVehicleImpounded])
    {
        SendClientMessage(playerid, COLOR_RED, "Este veiculo esta no patio. Use /patio para recuperar.");
        return 0;
    }

    if (GetPlayerInterior(playerid) != 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Saia do interior antes de puxar seu veiculo.");
        return 0;
    }

    Dealership_DestroyPlayerVehicle(playerid);

    if (PlayerInfo[playerid][pVehicleParked])
    {
        x = PlayerInfo[playerid][pVehiclePosX];
        y = PlayerInfo[playerid][pVehiclePosY];
        z = PlayerInfo[playerid][pVehiclePosZ];
        angle = PlayerInfo[playerid][pVehiclePosA];
    }
    else
    {
        GetPlayerPos(playerid, x, y, z);
        GetPlayerFacingAngle(playerid, angle);
        x += 3.0;
    }

    vehicleid = CreateVehicle(PlayerInfo[playerid][pVehicleModel], x, y, z, angle, PlayerInfo[playerid][pVehicleColor1], PlayerInfo[playerid][pVehicleColor2], -1);
    if (vehicleid == INVALID_VEHICLE_ID)
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel criar seu veiculo salvo.");
        return 0;
    }

    if (PlayerInfo[playerid][pVehicleParked])
    {
        SetVehicleVirtualWorld(vehicleid, PlayerInfo[playerid][pVehicleVirtualWorld]);
        LinkVehicleToInterior(vehicleid, PlayerInfo[playerid][pVehicleInterior]);
    }
    else
    {
        SetVehicleVirtualWorld(vehicleid, GetPlayerVirtualWorld(playerid));
        LinkVehicleToInterior(vehicleid, GetPlayerInterior(playerid));
    }

    SetVehicleHealth(vehicleid, PlayerInfo[playerid][pVehicleHealth]);
    SetVehicleNumberPlate(vehicleid, PlayerInfo[playerid][pVehiclePlate]);
    Fuel_InitVehicle(vehicleid, PlayerInfo[playerid][pVehicleFuel], 0);
    Radio_ResetVehicle(vehicleid);
    PutPlayerInVehicle(playerid, vehicleid, 0);
    gPlayerOwnedVehicle[playerid] = vehicleid;
    gPlayerVehicleSpawnedSlot[playerid] = slot;
    PlayerInfo[playerid][pVehicleGarage] = 0;
    gPlayerVehicleGarage[playerid][slot] = 0;
    gPlayerVehicleGarageType[playerid][slot] = VEHICLE_GARAGE_NONE;
    gPlayerVehicleGarageProperty[playerid][slot] = HOUSE_NONE;

    GetDealerVehicleNameByModel(PlayerInfo[playerid][pVehicleModel], vehicleName, sizeof(vehicleName));
    format(message, sizeof(message), "Veiculo ativo: %s | Placa: %s | Slot %d/%d.", vehicleName, PlayerInfo[playerid][pVehiclePlate], slot + 1, gPlayerVehicleCount[playerid]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    if (!gPlayerVehicleRegistered[playerid][slot])
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Veiculo ainda nao registrado no DETRAN. Use /detran.");
    }
    if (PlayerInfo[playerid][pVehicleTaxDue] > 0)
    {
        format(message, sizeof(message), "IPVA pendente: $%d. Use /ipva ou /pagaripva.", PlayerInfo[playerid][pVehicleTaxDue]);
        SendClientMessage(playerid, COLOR_ORANGE, message);
    }
    return 1;
}

stock ParkPlayerOwnedVehicle(playerid)
{
    new vehicleid;

    if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce precisa estar dirigindo seu veiculo.");
        return 1;
    }

    vehicleid = GetPlayerVehicleID(playerid);
    if (vehicleid != gPlayerOwnedVehicle[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Este nao e o seu veiculo salvo.");
        return 1;
    }

    SavePlayerOwnedVehicleState(playerid);
    PlayerInfo[playerid][pVehicleParked] = 1;
    PlayerInfo[playerid][pVehicleGarage] = 0;
    Dealership_SyncPlayerToSlot(playerid, gPlayerVehicleActiveSlot[playerid]);
    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Veiculo estacionado e salvo nesta posicao.");
    return 1;
}

stock Dealership_IsNearHomeGarage(playerid)
{
    return (Dlr_CurrentHomeGarageProp(playerid) != HOUSE_NONE);
}

stock Dlr_CurrentHomeGarageProp(playerid)
{
    new propertyid = PlayerInfo[playerid][pHouse];
    new index;

    if (propertyid == HOUSE_NONE)
    {
        propertyid = PlayerInfo[playerid][pRentedHouse];
    }

    index = Property_GetIndex(propertyid);
    if (index == -1)
    {
        return HOUSE_NONE;
    }

    if (IsPlayerInRangeOfPoint(playerid, 8.0, gProperties[index][propX], gProperties[index][propY], gProperties[index][propZ]))
    {
        return propertyid;
    }
    return HOUSE_NONE;
}

stock Dealership_GetCurrentGarageType(playerid, &propertyid)
{
    propertyid = HOUSE_NONE;

    if (World_IsPlayerNearLocation(playerid, LOCATION_GARAGEM_PUBLICA, 8.0))
    {
        return VEHICLE_GARAGE_PUBLIC;
    }

    propertyid = Dlr_CurrentHomeGarageProp(playerid);
    if (propertyid != HOUSE_NONE)
    {
        return VEHICLE_GARAGE_HOME;
    }
    return VEHICLE_GARAGE_NONE;
}

stock Dealership_CanUseGarage(playerid, showError = 1)
{
    new propertyid;

    if (Dealership_GetCurrentGarageType(playerid, propertyid) != VEHICLE_GARAGE_NONE)
    {
        return 1;
    }

    if (showError)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Use a garagem publica ou a garagem da sua casa/apartamento.");
    }
    return 0;
}

stock Dlr_CanAccessGarageSlot(playerid, slot)
{
    new propertyid;
    new garageType = Dealership_GetCurrentGarageType(playerid, propertyid);

    if (garageType == VEHICLE_GARAGE_NONE)
    {
        return 0;
    }

    if (!gPlayerVehicleGarage[playerid][slot])
    {
        return 1;
    }

    if (gPlayerVehicleGarageType[playerid][slot] == VEHICLE_GARAGE_PUBLIC)
    {
        return (garageType == VEHICLE_GARAGE_PUBLIC);
    }

    if (gPlayerVehicleGarageType[playerid][slot] == VEHICLE_GARAGE_HOME)
    {
        return (garageType == VEHICLE_GARAGE_HOME && gPlayerVehicleGarageProperty[playerid][slot] == propertyid);
    }
    return 1;
}

stock GuardPlayerOwnedVehicle(playerid)
{
    new vehicleid;
    new message[128];
    new propertyid;
    new garageType;
    new cost = Vip_ApplyDiscount(playerid, Cfg_Price(gCfgVehicleGarageCost));

    if (!Dealership_CanUseGarage(playerid))
    {
        return 1;
    }
    garageType = Dealership_GetCurrentGarageType(playerid, propertyid);

    if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce precisa estar dirigindo seu veiculo para guardar na garagem.");
        return 1;
    }

    vehicleid = GetPlayerVehicleID(playerid);
    if (vehicleid != gPlayerOwnedVehicle[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Este nao e o seu veiculo salvo.");
        return 1;
    }

    if (!Bank_TakePayment(playerid, cost, 0))
    {
        format(message, sizeof(message), "Guardar na garagem custa $%d.", cost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    SavePlayerOwnedVehicleState(playerid);
    PlayerInfo[playerid][pVehicleParked] = 1;
    PlayerInfo[playerid][pVehicleGarage] = 1;
    gPlayerVehicleGarageType[playerid][gPlayerVehicleActiveSlot[playerid]] = garageType;
    gPlayerVehicleGarageProperty[playerid][gPlayerVehicleActiveSlot[playerid]] = propertyid;
    gPlayerVehicleLocked[playerid][gPlayerVehicleActiveSlot[playerid]] = 1;
    Dealership_SyncPlayerToSlot(playerid, gPlayerVehicleActiveSlot[playerid]);
    Radio_OnVehicleDestroyed(vehicleid);
    DestroyVehicle(vehicleid);
    gPlayerOwnedVehicle[playerid] = 0;
    gPlayerVehicleSpawnedSlot[playerid] = -1;
    SaveAccountData(playerid, 0);
    if (garageType == VEHICLE_GARAGE_HOME)
    {
        format(message, sizeof(message), "Veiculo guardado na garagem residencial. Taxa: $%d.", cost);
    }
    else
    {
        format(message, sizeof(message), "Veiculo guardado na garagem publica. Taxa: $%d.", cost);
    }
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Dealership_ShowVehicleInfo(playerid)
{
    new vehicleName[32];
    new message[144];
    new status[24];
    new slot = gPlayerVehicleActiveSlot[playerid];

    if (!Dealership_IsValidSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce ainda nao possui um veiculo salvo.");
        return 1;
    }

    Dlr_UpdateVehicleDocs(playerid, 1);
    Dealership_SyncSlotToPlayer(playerid, slot);
    GetDealerVehicleNameByModel(PlayerInfo[playerid][pVehicleModel], vehicleName, sizeof(vehicleName));
    Dealership_FormatStatus(playerid, slot, status, sizeof(status));
    format(message, sizeof(message), "Ativo #%d: %s | Placa: %s | %s", slot + 1, vehicleName, PlayerInfo[playerid][pVehiclePlate], status);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Combustivel: %d%% | Vida: %.0f | Cor: %d/%d", PlayerInfo[playerid][pVehicleFuel], PlayerInfo[playerid][pVehicleHealth], PlayerInfo[playerid][pVehicleColor1], PlayerInfo[playerid][pVehicleColor2]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Registro DETRAN: %s | CRLV: %s | Trava: %s", gPlayerVehicleRegistered[playerid][slot] ? ("ativo") : ("pendente"), (gPlayerVehicleRegistered[playerid][slot] && PlayerInfo[playerid][pVehicleTaxDue] <= 0) ? ("regular") : ("irregular"), gPlayerVehicleLocked[playerid][slot] ? ("trancado") : ("destrancado"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    if (PlayerInfo[playerid][pVehicleTaxDue] > 0)
    {
        format(message, sizeof(message), "Seguro: %s | IPVA vencido: $%d", PlayerInfo[playerid][pVehicleInsurance] ? ("ativo") : ("nao"), PlayerInfo[playerid][pVehicleTaxDue]);
    }
    else
    {
        format(message, sizeof(message), "Seguro: %s | IPVA vence em %d dia(s)", PlayerInfo[playerid][pVehicleInsurance] ? ("ativo") : ("nao"), Dealership_GetDaysLeft(gPlayerVehicleTaxExpiry[playerid][slot]));
    }
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Garagem: %s | Patio: %s | Veiculos: %d/%d", PlayerInfo[playerid][pVehicleGarage] ? ("guardado") : ("fora"), PlayerInfo[playerid][pVehicleImpounded] ? ("sim") : ("nao"), gPlayerVehicleCount[playerid], Dealership_PlayerLimit(playerid));
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}

stock Dealership_ShowAllVehicles(playerid)
{
    new slot;
    new vehicleName[32];
    new status[24];
    new message[144];

    if (gPlayerVehicleCount[playerid] <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce ainda nao possui veiculos.");
        return 1;
    }

    Dlr_UpdateVehicleDocs(playerid, 0);
    SendClientMessage(playerid, COLOR_BLUE, "Seus veiculos:");
    for (slot = 0; slot < gPlayerVehicleCount[playerid]; slot++)
    {
        if (!Dealership_IsValidSlot(playerid, slot))
        {
            continue;
        }
        GetDealerVehicleNameByModel(gPlayerVehicleModel[playerid][slot], vehicleName, sizeof(vehicleName));
        Dealership_FormatStatus(playerid, slot, status, sizeof(status));
        format(message, sizeof(message), "%d. %s | %s | %s | IPVA $%d | %s", slot + 1, vehicleName, gPlayerVehiclePlate[playerid][slot], status, gPlayerVehicleTaxDue[playerid][slot], gPlayerVehicleLocked[playerid][slot] ? ("trancado") : ("aberto"));
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    return 1;
}

stock Dealership_BuyInsurance(playerid)
{
    new message[128];
    new cost = Vip_ApplyDiscount(playerid, Cfg_Price(gCfgVehicleInsuranceCost));
    new slot = gPlayerVehicleActiveSlot[playerid];

    if (!Dealership_IsValidSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce precisa ter um veiculo para contratar seguro.");
        return 1;
    }

    Dlr_UpdateVehicleDocs(playerid, 1);
    if (gPlayerVehicleInsurance[playerid][slot])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Este veiculo ja possui seguro ativo.");
        return 1;
    }

    if (!Bank_TakePayment(playerid, cost, 0))
    {
        format(message, sizeof(message), "Seguro veicular custa $%d.", cost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    gPlayerVehicleInsurance[playerid][slot] = 1;
    gPlayerVehicleInsuranceExpiry[playerid][slot] = GetBrasiliaDayStamp() + VEHICLE_INSURANCE_VALID_DAYS;
    Dealership_SyncSlotToPlayer(playerid, slot);
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Seguro veicular contratado por $%d.", cost);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Dealership_ShowVehicleTax(playerid)
{
    new message[128];
    new tax;
    new slot = gPlayerVehicleActiveSlot[playerid];

    if (!Dealership_IsValidSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce ainda nao possui veiculo.");
        return 1;
    }

    Dlr_UpdateVehicleDocs(playerid, 1);
    tax = Dealership_GetVehicleTax(gPlayerVehicleModel[playerid][slot]);
    if (gPlayerVehicleTaxDue[playerid][slot] <= 0)
    {
        format(message, sizeof(message), "IPVA quitado. Vence em %d dia(s). Proxima referencia: $%d.", Dealership_GetDaysLeft(gPlayerVehicleTaxExpiry[playerid][slot]), tax);
        SendClientMessage(playerid, COLOR_GREEN, message);
        return 1;
    }

    format(message, sizeof(message), "IPVA pendente: $%d. Use /pagaripva para quitar.", gPlayerVehicleTaxDue[playerid][slot]);
    SendClientMessage(playerid, COLOR_ORANGE, message);
    return 1;
}

stock Dealership_PayVehicleTax(playerid)
{
    new message[128];
    new cost;
    new slot = gPlayerVehicleActiveSlot[playerid];

    if (!Dealership_IsValidSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce ainda nao possui veiculo.");
        return 1;
    }

    Dlr_UpdateVehicleDocs(playerid, 1);
    if (gPlayerVehicleTaxDue[playerid][slot] <= 0)
    {
        SendClientMessage(playerid, COLOR_GREEN, "Seu IPVA ja esta quitado.");
        return 1;
    }

    cost = Vip_ApplyDiscount(playerid, gPlayerVehicleTaxDue[playerid][slot]);
    if (!Bank_TakePayment(playerid, cost, 0))
    {
        format(message, sizeof(message), "Voce precisa de $%d em dinheiro/banco para pagar o IPVA.", cost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    format(message, sizeof(message), "IPVA pago: $%d.", cost);
    gPlayerVehicleTaxDue[playerid][slot] = 0;
    gPlayerVehicleTaxExpiry[playerid][slot] = GetBrasiliaDayStamp() + VEHICLE_IPVA_VALID_DAYS;
    Dealership_SyncSlotToPlayer(playerid, slot);
    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_MONEY_FILE, "VEHICLE_TAX", playerid, message);
    return 1;
}

stock Dealership_RequireDetran(playerid)
{
    if (World_IsPlayerNearLocation(playerid, LOCATION_DETRAN, 8.0))
    {
        return 1;
    }

    SendClientMessage(playerid, COLOR_GRAY, "Este servico precisa de atendimento presencial no DETRAN.");
    SetPlayerGps(playerid, LOCATION_DETRAN);
    return 0;
}

stock Dealership_RegisterVehicle(playerid)
{
    new message[128];
    new cost = Vip_ApplyDiscount(playerid, Cfg_Price(gCfgVehicleRegisterCost));
    new slot = gPlayerVehicleActiveSlot[playerid];

    if (!Dealership_RequireDetran(playerid))
    {
        return 1;
    }

    if (!Dealership_IsValidSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce precisa ter um veiculo ativo para registrar.");
        return 1;
    }

    if (gPlayerVehicleRegistered[playerid][slot])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Este veiculo ja esta registrado no DETRAN.");
        return 1;
    }

    if (!Bank_TakePayment(playerid, cost, 0))
    {
        format(message, sizeof(message), "Registro DETRAN custa $%d.", cost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    gPlayerVehicleRegistered[playerid][slot] = 1;
    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Veiculo registrado no DETRAN. Documento digital liberado.");
    return 1;
}

stock Dealership_SanitizePlate(input[], output[], size)
{
    new index;
    new offset;
    new ch;
    new length = strlen(input);

    while (index < length && offset < (size - 1))
    {
        ch = input[index];
        if (ch >= 'a' && ch <= 'z')
        {
            ch -= 32;
        }

        if ((ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '-')
        {
            output[offset] = ch;
            offset++;
        }
        index++;
    }

    output[offset] = 0;
    return offset;
}

stock Dealership_ChangePlate(playerid, input[])
{
    new plate[16];
    new message[128];
    new cost = Vip_ApplyDiscount(playerid, Cfg_Price(gCfgVehiclePlateCost));
    new slot = gPlayerVehicleActiveSlot[playerid];

    if (!Dealership_RequireDetran(playerid))
    {
        return 1;
    }

    if (!Dealership_IsValidSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce precisa ter um veiculo ativo.");
        return 1;
    }

    if (!gPlayerVehicleRegistered[playerid][slot])
    {
        SendClientMessage(playerid, COLOR_RED, "Registre o veiculo no DETRAN antes de trocar placa.");
        return 1;
    }

    if (Dealership_SanitizePlate(input, plate, sizeof(plate)) < 4)
    {
        SendClientMessage(playerid, COLOR_RED, "Placa invalida. Use 4 a 12 caracteres com letras, numeros ou hifen.");
        return 1;
    }

    if (!Bank_TakePayment(playerid, cost, 0))
    {
        format(message, sizeof(message), "Troca de placa custa $%d.", cost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    format(gPlayerVehiclePlate[playerid][slot], 16, "%s", plate);
    Dealership_SyncSlotToPlayer(playerid, slot);
    if (gPlayerOwnedVehicle[playerid] != 0)
    {
        SetVehicleNumberPlate(gPlayerOwnedVehicle[playerid], plate);
    }
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Nova placa registrada: %s.", plate);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Dealership_SendVehicleDoc(playerid)
{
    new slot = gPlayerVehicleActiveSlot[playerid];
    new vehicleName[32];
    new message[144];
    new crlvRegular;

    if (!Dealership_IsValidSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui veiculo ativo.");
        return 1;
    }

    if (!gPlayerVehicleRegistered[playerid][slot])
    {
        SendClientMessage(playerid, COLOR_RED, "Documento indisponivel. Registre o veiculo no DETRAN.");
        return 1;
    }

    Dlr_UpdateVehicleDocs(playerid, 1);
    crlvRegular = (gPlayerVehicleRegistered[playerid][slot] && gPlayerVehicleTaxDue[playerid][slot] <= 0);
    GetDealerVehicleNameByModel(gPlayerVehicleModel[playerid][slot], vehicleName, sizeof(vehicleName));
    SendClientMessage(playerid, COLOR_BLUE, "CRLV Digital - Life Simulator BR");
    format(message, sizeof(message), "Proprietario: %s | Veiculo: %s | Modelo: %d", PlayerInfo[playerid][pCharacterName], vehicleName, gPlayerVehicleModel[playerid][slot]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Placa: %s | CRLV: %s | Seguro: %s", gPlayerVehiclePlate[playerid][slot], crlvRegular ? ("regular") : ("irregular"), gPlayerVehicleInsurance[playerid][slot] ? ("ativo") : ("nao"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    if (gPlayerVehicleTaxDue[playerid][slot] > 0)
    {
        format(message, sizeof(message), "IPVA pendente: $%d. Documento fica irregular ate quitar.", gPlayerVehicleTaxDue[playerid][slot]);
    }
    else
    {
        format(message, sizeof(message), "IPVA quitado. Vencimento em %d dia(s).", Dealership_GetDaysLeft(gPlayerVehicleTaxExpiry[playerid][slot]));
    }
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}

stock Dealership_TransferVehicle(playerid, targetid)
{
    new slot = gPlayerVehicleActiveSlot[playerid];
    new newSlot;
    new message[144];
    new targetName[MAX_PLAYER_NAME + 1];
    new cost = Vip_ApplyDiscount(playerid, Cfg_Price(gCfgVehicleTransferCost));

    if (!Dealership_RequireDetran(playerid))
    {
        return 1;
    }

    if (!IsValidConnectedPlayer(targetid) || !PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido ou nao logado.");
        return 1;
    }

    if (!Dealership_IsValidSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui veiculo ativo para transferir.");
        return 1;
    }

    if (!gPlayerVehicleRegistered[playerid][slot])
    {
        SendClientMessage(playerid, COLOR_RED, "Registre o veiculo no DETRAN antes de transferir.");
        return 1;
    }

    if (gPlayerVehicleCount[targetid] >= Dealership_PlayerLimit(targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "O jogador alvo nao tem vaga livre na garagem.");
        return 1;
    }

    if (!Bank_TakePayment(playerid, cost, 0))
    {
        format(message, sizeof(message), "Transferencia custa $%d.", cost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    if (gPlayerVehicleSpawnedSlot[playerid] == slot)
    {
        Dealership_DestroyPlayerVehicle(playerid);
    }

    newSlot = gPlayerVehicleCount[targetid];
    gPlayerVehicleCount[targetid]++;
    gPlayerVehicleModel[targetid][newSlot] = gPlayerVehicleModel[playerid][slot];
    gPlayerVehicleColor1[targetid][newSlot] = gPlayerVehicleColor1[playerid][slot];
    gPlayerVehicleColor2[targetid][newSlot] = gPlayerVehicleColor2[playerid][slot];
    format(gPlayerVehiclePlate[targetid][newSlot], 16, "%s", gPlayerVehiclePlate[playerid][slot]);
    gPlayerVehicleFuel[targetid][newSlot] = gPlayerVehicleFuel[playerid][slot];
    gPlayerVehicleHealth[targetid][newSlot] = gPlayerVehicleHealth[playerid][slot];
    gPlayerVehiclePosX[targetid][newSlot] = gPlayerVehiclePosX[playerid][slot];
    gPlayerVehiclePosY[targetid][newSlot] = gPlayerVehiclePosY[playerid][slot];
    gPlayerVehiclePosZ[targetid][newSlot] = gPlayerVehiclePosZ[playerid][slot];
    gPlayerVehiclePosA[targetid][newSlot] = gPlayerVehiclePosA[playerid][slot];
    gPlayerVehicleInterior[targetid][newSlot] = 0;
    gPlayerVehicleVirtualWorld[targetid][newSlot] = 0;
    gPlayerVehicleParked[targetid][newSlot] = 0;
    gPlayerVehicleInsurance[targetid][newSlot] = gPlayerVehicleInsurance[playerid][slot];
    gPlayerVehicleGarage[targetid][newSlot] = 1;
    gPlayerVehicleImpounded[targetid][newSlot] = 0;
    gPlayerVehicleTaxDue[targetid][newSlot] = gPlayerVehicleTaxDue[playerid][slot];
    gPlayerVehicleRegistered[targetid][newSlot] = 1;
    gPlayerVehicleLocked[targetid][newSlot] = 1;
    gPlayerVehicleGarageType[targetid][newSlot] = VEHICLE_GARAGE_PUBLIC;
    gPlayerVehicleGarageProperty[targetid][newSlot] = HOUSE_NONE;
    gPlayerVehicleTaxExpiry[targetid][newSlot] = gPlayerVehicleTaxExpiry[playerid][slot];
    gPlayerVehicleInsuranceExpiry[targetid][newSlot] = gPlayerVehicleInsuranceExpiry[playerid][slot];
    Dealership_ClearVehicleKeys(targetid, newSlot);

    Dealership_RemoveSlot(playerid, slot);
    if (gPlayerVehicleActiveSlot[targetid] == -1)
    {
        Dealership_SetActiveSlot(targetid, newSlot);
    }

    SaveAccountData(playerid, 0);
    SaveAccountData(targetid, 0);
    GetPlayerNameEx(targetid, targetName, sizeof(targetName));
    format(message, sizeof(message), "Veiculo transferido para %s. Taxa DETRAN: $%d.", targetName, cost);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(targetid, COLOR_GREEN, "Voce recebeu um veiculo transferido. Use /garagem para retirar.");
    return 1;
}

stock Dealership_SellActiveVehicle(playerid)
{
    new slot = gPlayerVehicleActiveSlot[playerid];
    new vehicleName[32];
    new price;
    new message[144];

    if (!Dealership_IsValidSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui veiculo ativo para vender.");
        return 1;
    }

    if (gPlayerVehicleImpounded[playerid][slot])
    {
        SendClientMessage(playerid, COLOR_RED, "Recupere o veiculo do patio antes de vender.");
        return 1;
    }

    price = (GetDealerVehiclePriceByModel(gPlayerVehicleModel[playerid][slot]) * gCfgVehicleSellPercent) / 100;
    GetDealerVehicleNameByModel(gPlayerVehicleModel[playerid][slot], vehicleName, sizeof(vehicleName));
    Dealership_RemoveSlot(playerid, slot);
    GivePlayerCashReason(playerid, price, 0, "vehicle_used_sale");
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Veiculo vendido: %s por $%d.", vehicleName, price);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock ShowDealershipDialog(playerid)
{
    new list[768];
    new line[72];
    new index;

    list[0] = 0;
    gDealerDialogCount[playerid] = 0;
    for (index = 0; index < sizeof(gDealerVehicles); index++)
    {
        if (gDealerDialogCount[playerid] < DEALER_DIALOG_ITEMS)
        {
            gDealerDialogItems[playerid][gDealerDialogCount[playerid]] = index;
            gDealerDialogCount[playerid]++;
        }
        format(line, sizeof(line), "%s\t$%d\n", gDealerVehicles[index][dealerName], Cfg_VehiclePrice(gDealerVehicles[index][dealerPrice]));
        strcat(list, line, sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_DEALERSHIP, DIALOG_STYLE_LIST, "Concessionaria", list, "Comprar", "Fechar");
    return 1;
}

stock HandleDealershipDialog(playerid, response, listitem)
{
    new message[144];
    new logLine[144];
    new slot;
    new item;

    if (!response)
    {
        return 1;
    }

    if (listitem < 0 || listitem >= gDealerDialogCount[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Veiculo invalido.");
        return 1;
    }
    item = gDealerDialogItems[playerid][listitem];

    if (gPlayerVehicleCount[playerid] >= Dealership_PlayerLimit(playerid))
    {
        format(message, sizeof(message), "Sua garagem esta cheia: %d/%d veiculos.", gPlayerVehicleCount[playerid], Dealership_PlayerLimit(playerid));
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    if (!Life_CheckScoreGate(playerid, gCfgCitizenVehicleMinScore, "Compra de veiculo"))
    {
        return 1;
    }

    if (!Bank_TakePayment(playerid, Cfg_VehiclePrice(gDealerVehicles[item][dealerPrice]), 0))
    {
        format(message, sizeof(message), "Voce precisa de $%d em dinheiro/banco para comprar este veiculo.", Cfg_VehiclePrice(gDealerVehicles[item][dealerPrice]));
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    slot = Dealership_AddVehicle(playerid, gDealerVehicles[item][dealerModel], gDealerVehicles[item][dealerColor1], gDealerVehicles[item][dealerColor2], 0);
    if (slot == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel criar vaga para este veiculo.");
        return 1;
    }

    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Compra aprovada: %s por $%d. Registre no DETRAN.", gDealerVehicles[item][dealerName], Cfg_VehiclePrice(gDealerVehicles[item][dealerPrice]));
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(logLine, sizeof(logLine), "vehicle_buy model=%d price=%d score=%d", gDealerVehicles[item][dealerModel], Cfg_VehiclePrice(gDealerVehicles[item][dealerPrice]), PlayerInfo[playerid][pBankScore]);
    WritePlayerLog(LOG_MONEY_FILE, "VEHICLE", playerid, logLine);
    SpawnPlayerOwnedVehicle(playerid);
    return 1;
}

stock Dealership_TowPlayerVehicle(playerid)
{
    new message[128];
    new cost = Vip_ApplyDiscount(playerid, Cfg_Price(gCfgNpcTowCost));
    new slot = gPlayerVehicleActiveSlot[playerid];

    if (!Dealership_IsValidSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce ainda nao possui um veiculo salvo.");
        return 1;
    }

    if (gPlayerVehicleImpounded[playerid][slot])
    {
        SendClientMessage(playerid, COLOR_RED, "Este veiculo esta no patio. Use /patio para recuperar oficialmente.");
        return 1;
    }

    if (Work_IsActive(playerid))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Guincho NPC bloqueado durante expediente de trabalho.");
        return 1;
    }

    if (IsPlayerInAnyVehicle(playerid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Saia do veiculo antes de chamar o guincho NPC.");
        return 1;
    }

    if (GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Saia do interior antes de chamar o guincho NPC.");
        return 1;
    }

    if (!Bank_TakePayment(playerid, cost, 0))
    {
        format(message, sizeof(message), "Guincho NPC custa $%d em dinheiro/banco.", cost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    Dealership_DestroyPlayerVehicle(playerid);
    if (gPlayerVehicleFuel[playerid][slot] < FUEL_LOW_VALUE) gPlayerVehicleFuel[playerid][slot] = FUEL_LOW_VALUE;
    if (gPlayerVehicleHealth[playerid][slot] < 650.0) gPlayerVehicleHealth[playerid][slot] = 650.0;
    gPlayerVehicleParked[playerid][slot] = 0;
    gPlayerVehicleGarage[playerid][slot] = 0;
    gPlayerVehicleGarageType[playerid][slot] = VEHICLE_GARAGE_NONE;
    gPlayerVehicleGarageProperty[playerid][slot] = HOUSE_NONE;
    Dealership_SyncSlotToPlayer(playerid, slot);
    SaveAccountData(playerid, 0);

    if (!SpawnPlayerOwnedVehicle(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Guincho pago, mas o veiculo nao pode ser criado agora. Avise a staff.");
        return 1;
    }

    format(message, sizeof(message), "Guincho NPC trouxe seu veiculo. Custo: $%d.", cost);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Dealership_RecoverImpound(playerid)
{
    new message[144];
    new cost = Cfg_Price(gCfgVehicleImpoundCost);
    new fines;
    new slot = gPlayerVehicleActiveSlot[playerid];

    if (!World_IsPlayerNearLocation(playerid, LOCATION_PATIO_MUNICIPAL, 8.0))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Va ate o Patio Municipal para recuperar veiculo apreendido.");
        SetPlayerGps(playerid, LOCATION_PATIO_MUNICIPAL);
        return 1;
    }

    if (!Dealership_IsValidSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce ainda nao possui um veiculo salvo.");
        return 1;
    }

    Dlr_UpdateVehicleDocs(playerid, 1);
    if (!gPlayerVehicleImpounded[playerid][slot])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Seu veiculo ativo nao esta no patio.");
        return 1;
    }

    if (gPlayerVehicleInsurance[playerid][slot])
    {
        cost = cost / 2;
    }

    cost = Vip_ApplyDiscount(playerid, cost);
    cost += gPlayerVehicleTaxDue[playerid][slot];
    fines = PlayerInfo[playerid][pFines];
    if (fines > 0)
    {
        cost += fines;
    }
    if (!Bank_TakePayment(playerid, cost, 0))
    {
        format(message, sizeof(message), "Recuperar no patio custa $%d, incluindo taxa, multas e IPVA pendente.", cost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    gPlayerVehicleImpounded[playerid][slot] = 0;
    gPlayerVehicleGarage[playerid][slot] = 0;
    gPlayerVehicleParked[playerid][slot] = 0;
    gPlayerVehicleTaxDue[playerid][slot] = 0;
    gPlayerVehicleTaxExpiry[playerid][slot] = GetBrasiliaDayStamp() + VEHICLE_IPVA_VALID_DAYS;
    if (fines > 0)
    {
        PlayerInfo[playerid][pFines] = 0;
    }
    if (gPlayerVehicleFuel[playerid][slot] < FUEL_LOW_VALUE) gPlayerVehicleFuel[playerid][slot] = FUEL_LOW_VALUE;
    if (gPlayerVehicleHealth[playerid][slot] < 700.0) gPlayerVehicleHealth[playerid][slot] = 700.0;

    Dealership_SyncSlotToPlayer(playerid, slot);
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Veiculo liberado do patio. Custo total: $%d.", cost);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_MONEY_FILE, "VEHICLE_IMPOUND", playerid, message);
    SpawnPlayerOwnedVehicle(playerid);
    return 1;
}

stock Dealership_OnVehicleDeath(vehicleid, killerid)
{
    new ownerid = Dealership_FindVehicleOwner(vehicleid);
    new slot;
    new message[128];

    if (ownerid == INVALID_PLAYER_ID)
    {
        return 0;
    }

    slot = gPlayerVehicleSpawnedSlot[ownerid];
    if (slot < 0 || slot >= MAX_PLAYER_VEHICLES)
    {
        return 0;
    }

    SavePlayerOwnedVehicleState(ownerid);
    gPlayerVehicleHealth[ownerid][slot] = 350.0;
    gPlayerVehicleImpounded[ownerid][slot] = 1;
    gPlayerVehicleGarage[ownerid][slot] = 0;
    gPlayerVehicleGarageType[ownerid][slot] = VEHICLE_GARAGE_NONE;
    gPlayerVehicleGarageProperty[ownerid][slot] = HOUSE_NONE;
    gPlayerVehicleParked[ownerid][slot] = 0;
    Dealership_SyncSlotToPlayer(ownerid, slot);
    gPlayerOwnedVehicle[ownerid] = 0;
    gPlayerVehicleSpawnedSlot[ownerid] = -1;
    Radio_OnVehicleDestroyed(vehicleid);
    DestroyVehicle(vehicleid);
    SaveAccountData(ownerid, 0);

    if (gPlayerVehicleInsurance[ownerid][slot])
    {
        SendClientMessage(ownerid, COLOR_ORANGE, "Seu veiculo foi removido para o patio. Seguro ativo reduz o custo de liberacao.");
    }
    else
    {
        SendClientMessage(ownerid, COLOR_ORANGE, "Seu veiculo foi removido para o patio. Use /patio no Patio Municipal para recuperar.");
    }

    format(message, sizeof(message), "vehicle=%d killer=%d plate=%s", vehicleid, killerid, PlayerInfo[ownerid][pVehiclePlate]);
    WritePlayerLog(LOG_MONEY_FILE, "VEHICLE_DESTROYED", ownerid, message);
    return 1;
}

stock Dealership_ShowGarageDialog(playerid)
{
    new list[1024];
    new line[128];
    new vehicleName[32];
    new status[24];
    new slot;
    new count;

    if (!Dealership_CanUseGarage(playerid))
    {
        return 1;
    }

    if (gPlayerVehicleCount[playerid] <= 0)
    {
        ShowPlayerDialog(playerid, DIALOG_GARAGE_LIST, DIALOG_STYLE_MSGBOX, "Garagem", "Nenhum veiculo na sua garagem.", "Fechar", "");
        return 1;
    }

    format(list, sizeof(list), "Slot\tVeiculo\tStatus\n");
    for (slot = 0; slot < gPlayerVehicleCount[playerid] && count < MAX_PLAYER_VEHICLES; slot++)
    {
        if (!Dealership_IsValidSlot(playerid, slot))
        {
            continue;
        }
        GetDealerVehicleNameByModel(gPlayerVehicleModel[playerid][slot], vehicleName, sizeof(vehicleName));
        Dealership_FormatStatus(playerid, slot, status, sizeof(status));
        format(line, sizeof(line), "%d\t%s %s\t%s\n", slot + 1, vehicleName, gPlayerVehiclePlate[playerid][slot], status);
        strcat(list, line, sizeof(list));
        gPlayerGarageDialogSlot[playerid][count] = slot;
        count++;
    }

    gPlayerGarageDialogCount[playerid] = count;
    ShowPlayerDialog(playerid, DIALOG_GARAGE_LIST, DIALOG_STYLE_TABLIST_HEADERS, "Garagem - escolher veiculo", list, "Retirar", "Fechar");
    return 1;
}

stock HandleGarageDialog(playerid, response, listitem)
{
    new slot;

    if (!response)
    {
        return 1;
    }

    if (listitem < 0)
    {
        return 1;
    }

    if (listitem >= gPlayerGarageDialogCount[playerid])
    {
        return Dealership_ShowGarageDialog(playerid);
    }

    slot = gPlayerGarageDialogSlot[playerid][listitem];
    if (!Dealership_SetActiveSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_RED, "Veiculo invalido.");
        return 1;
    }

    if (!Dlr_CanAccessGarageSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_RED, "Este veiculo esta guardado em outra garagem.");
        return 1;
    }

    return SpawnPlayerOwnedVehicle(playerid);
}

stock Detran_AddAction(playerid, list[], size, actionid, label[])
{
    if (gDetranDialogActionCount[playerid] >= DETRAN_DIALOG_ACTIONS)
    {
        return 0;
    }

    gDetranDialogActions[playerid][gDetranDialogActionCount[playerid]] = actionid;
    gDetranDialogActionCount[playerid]++;
    strcat(list, label, size);
    strcat(list, "\n", size);
    return 1;
}

stock Dealership_ShowDetranDialog(playerid)
{
    new list[512];

    if (!World_IsPlayerNearLocation(playerid, LOCATION_DETRAN, 8.0))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Va ate o DETRAN para atendimento presencial. Pelo celular, use GovBR para servicos digitais.");
        SetPlayerGps(playerid, LOCATION_DETRAN);
        return 1;
    }

    gDetranDialogActionCount[playerid] = 0;
    Detran_AddAction(playerid, list, sizeof(list), DETRAN_ACT_REGISTER, "Registrar veiculo ativo");
    Detran_AddAction(playerid, list, sizeof(list), DETRAN_ACT_PLATE, "Trocar placa");
    Detran_AddAction(playerid, list, sizeof(list), DETRAN_ACT_SHOW_IPVA, "Consultar IPVA");
    Detran_AddAction(playerid, list, sizeof(list), DETRAN_ACT_PAY_IPVA, "Pagar IPVA");
    Detran_AddAction(playerid, list, sizeof(list), DETRAN_ACT_SHOW_FINES, "Consultar multas");
    Detran_AddAction(playerid, list, sizeof(list), DETRAN_ACT_PAY_FINES, "Pagar multas");
    Detran_AddAction(playerid, list, sizeof(list), DETRAN_ACT_TRANSFER, "Transferir veiculo");
    Detran_AddAction(playerid, list, sizeof(list), DETRAN_ACT_DOC, "Emitir documento do veiculo");
    Detran_AddAction(playerid, list, sizeof(list), DETRAN_ACT_INSPECTION, "Fazer vistoria");
    Detran_AddAction(playerid, list, sizeof(list), DETRAN_ACT_AUCTION, "Leilao de apreendidos");
    Detran_AddAction(playerid, list, sizeof(list), DETRAN_ACT_GPS, "Marcar GPS DETRAN");

    ShowPlayerDialog(
        playerid,
        DIALOG_DETRAN_MENU,
        DIALOG_STYLE_LIST,
        "DETRAN - Atendimento",
        list,
        "Selecionar",
        "Fechar"
    );
    return 1;
}

stock HandleDetranDialog(playerid, response, listitem)
{
    new actionid;

    if (!response)
    {
        return 1;
    }
    if (listitem < 0 || listitem >= gDetranDialogActionCount[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Opcao do DETRAN expirou. Abra o menu novamente.");
        return Dealership_ShowDetranDialog(playerid);
    }

    actionid = gDetranDialogActions[playerid][listitem];

    switch (actionid)
    {
        case DETRAN_ACT_REGISTER: return Dealership_RegisterVehicle(playerid);
        case DETRAN_ACT_PLATE:
        {
            ShowPlayerDialog(playerid, DIALOG_DETRAN_PLATE, DIALOG_STYLE_INPUT, "DETRAN - Trocar placa", "Digite a nova placa.\nUse letras, numeros ou hifen. Exemplo: LSB-2026", "Trocar", "Voltar");
            return 1;
        }
        case DETRAN_ACT_SHOW_IPVA: return Dealership_ShowVehicleTax(playerid);
        case DETRAN_ACT_PAY_IPVA: return Dealership_PayVehicleTax(playerid);
        case DETRAN_ACT_SHOW_FINES: return Radar_ShowGovFines(playerid);
        case DETRAN_ACT_PAY_FINES: return Bank_PayFines(playerid);
        case DETRAN_ACT_TRANSFER:
        {
            ShowPlayerDialog(playerid, DIALOG_DETRAN_TRANSFER, DIALOG_STYLE_INPUT, "DETRAN - Transferir veiculo", "Digite o ID do jogador que vai receber o veiculo ativo.", "Transferir", "Voltar");
            return 1;
        }
        case DETRAN_ACT_DOC: return Dealership_SendVehicleDoc(playerid);
        case DETRAN_ACT_INSPECTION: return Life_RunVehicleInspection(playerid);
        case DETRAN_ACT_AUCTION: return Life_ShowVehicleAuction(playerid);
        case DETRAN_ACT_GPS: return SetPlayerGps(playerid, LOCATION_DETRAN);
    }
    return 1;
}

stock HandleDetranPlateDlg(playerid, response, inputtext[])
{
    if (!response)
    {
        return Dealership_ShowDetranDialog(playerid);
    }
    return Dealership_ChangePlate(playerid, inputtext);
}

stock HandleDetranTransferDlg(playerid, response, inputtext[])
{
    if (!response)
    {
        return Dealership_ShowDetranDialog(playerid);
    }

    if (!IsNumericString(inputtext))
    {
        SendClientMessage(playerid, COLOR_RED, "Digite apenas o ID do jogador.");
        return 1;
    }
    return Dealership_TransferVehicle(playerid, strval(inputtext));
}

stock Dlr_FindSpawnedVehSlot(vehicleid, &ownerid, &slot)
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    ownerid = INVALID_PLAYER_ID;
    slot = -1;

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (!IsPlayerConnected(playerid))
        {
            continue;
        }

        if (gPlayerOwnedVehicle[playerid] == vehicleid)
        {
            ownerid = playerid;
            slot = gPlayerVehicleSpawnedSlot[playerid];
            return Dealership_IsValidSlot(ownerid, slot);
        }
    }
    return 0;
}

stock Dlr_FindNearestSpawnedVeh(playerid, &ownerid, &slot, Float:range = 8.0)
{
    new testid;
    new vehicleid;
    new maxPlayers = GetMaxPlayers();
    new Float:x;
    new Float:y;
    new Float:z;

    ownerid = INVALID_PLAYER_ID;
    slot = -1;

    for (testid = 0; testid < maxPlayers; testid++)
    {
        if (!IsPlayerConnected(testid))
        {
            continue;
        }

        vehicleid = gPlayerOwnedVehicle[testid];
        if (vehicleid == 0 || vehicleid == INVALID_VEHICLE_ID)
        {
            continue;
        }

        GetVehiclePos(vehicleid, x, y, z);
        if (IsPlayerInRangeOfPoint(playerid, range, x, y, z))
        {
            ownerid = testid;
            slot = gPlayerVehicleSpawnedSlot[testid];
            return Dealership_IsValidSlot(ownerid, slot);
        }
    }
    return 0;
}

stock Dealership_FindCommandVehicle(playerid, &ownerid, &slot)
{
    if (IsPlayerInAnyVehicle(playerid))
    {
        if (Dlr_FindSpawnedVehSlot(GetPlayerVehicleID(playerid), ownerid, slot))
        {
            return 1;
        }
    }

    return Dlr_FindNearestSpawnedVeh(playerid, ownerid, slot, 8.0);
}

stock Dealership_PlayerHasVehicleKey(playerid, ownerid, slot)
{
    new index;

    if (!Dealership_IsValidSlot(ownerid, slot))
    {
        return 0;
    }

    if (playerid == ownerid)
    {
        return 1;
    }

    for (index = 0; index < MAX_VEHICLE_SHARED_KEYS; index++)
    {
        if (gPlayerVehicleKeyHolder[ownerid][slot][index] == playerid)
        {
            return 1;
        }
    }
    return 0;
}

stock Dlr_ClearSharedKeysFor(playerid)
{
    new ownerid;
    new slot;
    new index;
    new maxPlayers = GetMaxPlayers();

    for (ownerid = 0; ownerid < maxPlayers; ownerid++)
    {
        for (slot = 0; slot < MAX_PLAYER_VEHICLES; slot++)
        {
            for (index = 0; index < MAX_VEHICLE_SHARED_KEYS; index++)
            {
                if (gPlayerVehicleKeyHolder[ownerid][slot][index] == playerid)
                {
                    gPlayerVehicleKeyHolder[ownerid][slot][index] = INVALID_PLAYER_ID;
                }
            }
        }
    }
    return 1;
}

stock Dealership_TriggerVehicleAlarm(playerid, ownerid, slot)
{
    new message[144];
    new vehicleName[32];

    GetDealerVehicleNameByModel(gPlayerVehicleModel[ownerid][slot], vehicleName, sizeof(vehicleName));
    GameTextForPlayer(playerid, "~r~ALARME DO VEICULO", 2500, 3);
    SendClientMessage(playerid, COLOR_RED, "Voce nao tem a chave deste veiculo.");

    if (ownerid != playerid && IsPlayerConnected(ownerid))
    {
        format(message, sizeof(message), "Alarme: alguem tentou acessar seu %s placa %s.", vehicleName, gPlayerVehiclePlate[ownerid][slot]);
        SendClientMessage(ownerid, COLOR_ORANGE, message);
    }
    return 1;
}

stock Dealership_SetVehicleLock(playerid, locked)
{
    new ownerid;
    new slot;
    new message[128];

    if (!Dealership_FindCommandVehicle(playerid, ownerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Chegue perto do veiculo salvo ou entre nele.");
        return 1;
    }

    if (!Dealership_PlayerHasVehicleKey(playerid, ownerid, slot))
    {
        Dealership_TriggerVehicleAlarm(playerid, ownerid, slot);
        return 1;
    }

    gPlayerVehicleLocked[ownerid][slot] = locked;
    SaveAccountData(ownerid, 0);
    format(message, sizeof(message), "Veiculo %s.", locked ? ("trancado") : ("destrancado"));
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Dealership_GrantVehicleKey(playerid, targetid)
{
    new slot = gPlayerVehicleActiveSlot[playerid];
    new index;
    new targetName[MAX_PLAYER_NAME + 1];
    new message[144];

    if (!IsValidConnectedPlayer(targetid) || !PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido ou nao logado.");
        return 1;
    }

    if (targetid == playerid)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce ja tem a chave do seu veiculo.");
        return 1;
    }

    if (!Dealership_IsValidSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce precisa ter um veiculo ativo.");
        return 1;
    }

    for (index = 0; index < MAX_VEHICLE_SHARED_KEYS; index++)
    {
        if (gPlayerVehicleKeyHolder[playerid][slot][index] == targetid)
        {
            SendClientMessage(playerid, COLOR_GRAY, "Este jogador ja tem uma chave emprestada.");
            return 1;
        }
    }

    for (index = 0; index < MAX_VEHICLE_SHARED_KEYS; index++)
    {
        if (gPlayerVehicleKeyHolder[playerid][slot][index] == INVALID_PLAYER_ID)
        {
            gPlayerVehicleKeyHolder[playerid][slot][index] = targetid;
            GetPlayerNameEx(targetid, targetName, sizeof(targetName));
            format(message, sizeof(message), "Chave emprestada para %s.", targetName);
            SendClientMessage(playerid, COLOR_GREEN, message);
            format(message, sizeof(message), "%s emprestou a chave do veiculo %s para voce.", PlayerInfo[playerid][pCharacterName], gPlayerVehiclePlate[playerid][slot]);
            SendClientMessage(targetid, COLOR_GREEN, message);
            return 1;
        }
    }

    SendClientMessage(playerid, COLOR_RED, "Limite de chaves emprestadas atingido.");
    return 1;
}

stock Dealership_RevokeVehicleKey(playerid, targetid)
{
    new slot = gPlayerVehicleActiveSlot[playerid];
    new index;
    new targetName[MAX_PLAYER_NAME + 1];
    new message[144];

    if (!IsValidConnectedPlayer(targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido.");
        return 1;
    }

    if (!Dealership_IsValidSlot(playerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce precisa ter um veiculo ativo.");
        return 1;
    }

    for (index = 0; index < MAX_VEHICLE_SHARED_KEYS; index++)
    {
        if (gPlayerVehicleKeyHolder[playerid][slot][index] == targetid)
        {
            gPlayerVehicleKeyHolder[playerid][slot][index] = INVALID_PLAYER_ID;
            GetPlayerNameEx(targetid, targetName, sizeof(targetName));
            format(message, sizeof(message), "Chave removida de %s.", targetName);
            SendClientMessage(playerid, COLOR_GREEN, message);
            SendClientMessage(targetid, COLOR_ORANGE, "A chave emprestada do veiculo foi removida.");
            return 1;
        }
    }

    SendClientMessage(playerid, COLOR_GRAY, "Este jogador nao possui chave emprestada do veiculo ativo.");
    return 1;
}

stock Dealership_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    new ownerid;
    new slot;

    if (!Dlr_FindSpawnedVehSlot(vehicleid, ownerid, slot))
    {
        return 0;
    }

    if (!ispassenger && !Dealership_PlayerHasVehicleKey(playerid, ownerid, slot))
    {
        Dealership_TriggerVehicleAlarm(playerid, ownerid, slot);
        return 1;
    }

    if (ispassenger && !Dealership_PlayerHasVehicleKey(playerid, ownerid, slot))
    {
        Dealership_TriggerVehicleAlarm(playerid, ownerid, slot);
        return 1;
    }
    return 0;
}

stock Dealership_OnPlayerStateChange(playerid, newstate, oldstate)
{
    new ownerid;
    new slot;
    new vehicleid;

    if (newstate != PLAYER_STATE_DRIVER && newstate != PLAYER_STATE_PASSENGER)
    {
        return 0;
    }

    vehicleid = GetPlayerVehicleID(playerid);
    if (!Dlr_FindSpawnedVehSlot(vehicleid, ownerid, slot))
    {
        return 0;
    }

    if (newstate == PLAYER_STATE_DRIVER && !Dealership_PlayerHasVehicleKey(playerid, ownerid, slot))
    {
        RemovePlayerFromVehicle(playerid);
        Dealership_TriggerVehicleAlarm(playerid, ownerid, slot);
        return 1;
    }

    if (newstate == PLAYER_STATE_PASSENGER && !Dealership_PlayerHasVehicleKey(playerid, ownerid, slot))
    {
        RemovePlayerFromVehicle(playerid);
        Dealership_TriggerVehicleAlarm(playerid, ownerid, slot);
        return 1;
    }
    return 0;
}

stock Dealership_FindVehicleByPlate(input[], &ownerid, &slot)
{
    new searchPlate[16];
    new playerid;
    new testSlot;
    new maxPlayers = GetMaxPlayers();

    ownerid = INVALID_PLAYER_ID;
    slot = -1;
    Dealership_SanitizePlate(input, searchPlate, sizeof(searchPlate));

    if (strlen(searchPlate) < 2)
    {
        return 0;
    }

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (!IsPlayerConnected(playerid) || !PlayerInfo[playerid][pLogged])
        {
            continue;
        }

        for (testSlot = 0; testSlot < gPlayerVehicleCount[playerid] && testSlot < MAX_PLAYER_VEHICLES; testSlot++)
        {
            if (Dealership_IsValidSlot(playerid, testSlot) && strcmp(gPlayerVehiclePlate[playerid][testSlot], searchPlate, true) == 0)
            {
                ownerid = playerid;
                slot = testSlot;
                return 1;
            }
        }
    }
    return 0;
}

stock Dealership_SendPlateInfo(playerid, ownerid, slot)
{
    new vehicleName[32];
    new status[24];
    new message[144];

    if (!Dealership_IsValidSlot(ownerid, slot))
    {
        SendClientMessage(playerid, COLOR_RED, "Veiculo invalido.");
        return 1;
    }

    Dlr_UpdateVehicleDocs(ownerid, 0);
    GetDealerVehicleNameByModel(gPlayerVehicleModel[ownerid][slot], vehicleName, sizeof(vehicleName));
    Dealership_FormatStatus(ownerid, slot, status, sizeof(status));
    format(message, sizeof(message), "Placa %s | %s | Dono: %s", gPlayerVehiclePlate[ownerid][slot], vehicleName, PlayerInfo[ownerid][pCharacterName]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Registro: %s | CRLV: %s | Seguro: %s | Trava: %s", gPlayerVehicleRegistered[ownerid][slot] ? ("ativo") : ("pendente"), (gPlayerVehicleRegistered[ownerid][slot] && gPlayerVehicleTaxDue[ownerid][slot] <= 0) ? ("regular") : ("irregular"), gPlayerVehicleInsurance[ownerid][slot] ? ("ativo") : ("vencido/nao"), gPlayerVehicleLocked[ownerid][slot] ? ("trancado") : ("aberto"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "IPVA: $%d | Multas dono: $%d | Pontos CNH: %d | Status: %s", gPlayerVehicleTaxDue[ownerid][slot], PlayerInfo[ownerid][pFines], PlayerInfo[ownerid][pTrafficPoints], status);
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}

stock Dlr_ImpoundVehiclePolice(playerid, reason[])
{
    new ownerid;
    new slot;
    new vehicleid;
    new message[144];

    if (!Police_IsOfficer(playerid) && !HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policiais ou staff podem apreender veiculos.");
        return 1;
    }

    if (!Dealership_FindCommandVehicle(playerid, ownerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Entre ou fique perto de um veiculo salvo para apreender.");
        return 1;
    }

    vehicleid = gPlayerOwnedVehicle[ownerid];
    if (vehicleid != 0 && vehicleid != INVALID_VEHICLE_ID)
    {
        SavePlayerOwnedVehicleState(ownerid);
        Radio_OnVehicleDestroyed(vehicleid);
        DestroyVehicle(vehicleid);
    }

    gPlayerOwnedVehicle[ownerid] = 0;
    gPlayerVehicleSpawnedSlot[ownerid] = -1;
    gPlayerVehicleImpounded[ownerid][slot] = 1;
    gPlayerVehicleGarage[ownerid][slot] = 0;
    gPlayerVehicleGarageType[ownerid][slot] = VEHICLE_GARAGE_NONE;
    gPlayerVehicleGarageProperty[ownerid][slot] = HOUSE_NONE;
    gPlayerVehicleParked[ownerid][slot] = 0;
    if (gPlayerVehicleHealth[ownerid][slot] < 500.0)
    {
        gPlayerVehicleHealth[ownerid][slot] = 500.0;
    }
    Dealership_SyncSlotToPlayer(ownerid, slot);
    SaveAccountData(ownerid, 0);

    if (strlen(reason) < 1)
    {
        format(reason, 96, "fiscalizacao policial");
    }

    format(message, sizeof(message), "Veiculo %s apreendido para o Patio Municipal. Motivo: %s.", gPlayerVehiclePlate[ownerid][slot], reason);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(ownerid, COLOR_ORANGE, "Seu veiculo foi apreendido. Va ao Patio Municipal para liberar.");
    WritePlayerLog(LOG_PUNISH_FILE, "VEHICLE_IMPOUND_POLICE", ownerid, message);
    return 1;
}

stock HandleDealershipCommands(playerid, cmdtext[])
{
    new command[32];
    new param[32];
    new param2[96];
    new index;
    new slot;
    new targetid;
    new ownerid;

    index = GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/veiculo", true) == 0 || strcmp(command, "/meucarro", true) == 0)
    {
        return Dealership_ShowVehicleInfo(playerid);
    }

    if (strcmp(command, "/veiculos", true) == 0 || strcmp(command, "/meusveiculos", true) == 0)
    {
        return Dealership_ShowAllVehicles(playerid);
    }

    if (strcmp(command, "/selecionarveiculo", true) == 0 || strcmp(command, "/usarveiculo", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/selecionarveiculo [slot]");
        }
        slot = strval(param) - 1;
        if (!Dealership_SetActiveSlot(playerid, slot))
        {
            SendClientMessage(playerid, COLOR_RED, "Slot de veiculo invalido.");
            return 1;
        }
        return Dealership_ShowVehicleInfo(playerid);
    }

    if (strcmp(command, "/garagem", true) == 0 || strcmp(command, "/garagempublica", true) == 0 || strcmp(command, "/garagemcasa", true) == 0)
    {
        return Dealership_ShowGarageDialog(playerid);
    }

    if (strcmp(command, "/guardarveiculo", true) == 0)
    {
        return GuardPlayerOwnedVehicle(playerid);
    }

    if (strcmp(command, "/guincho", true) == 0 || strcmp(command, "/chamarguincho", true) == 0)
    {
        return Dealership_TowPlayerVehicle(playerid);
    }

    if (strcmp(command, "/seguroveiculo", true) == 0 || strcmp(command, "/segurocarro", true) == 0)
    {
        return Dealership_BuyInsurance(playerid);
    }

    if (strcmp(command, "/ipva", true) == 0)
    {
        return Dealership_ShowVehicleTax(playerid);
    }

    if (strcmp(command, "/pagaripva", true) == 0)
    {
        return Dealership_PayVehicleTax(playerid);
    }

    if (strcmp(command, "/patio", true) == 0 || strcmp(command, "/recuperarveiculo", true) == 0)
    {
        return Dealership_RecoverImpound(playerid);
    }

    if (strcmp(command, "/detran", true) == 0)
    {
        return Dealership_ShowDetranDialog(playerid);
    }

    if (strcmp(command, "/registrarveiculo", true) == 0)
    {
        return Dealership_RegisterVehicle(playerid);
    }

    if (strcmp(command, "/documentoveiculo", true) == 0 || strcmp(command, "/crlv", true) == 0)
    {
        return Dealership_SendVehicleDoc(playerid);
    }

    if (strcmp(command, "/transferirveiculo", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/transferirveiculo [id]");
        }
        return Dealership_TransferVehicle(playerid, strval(param));
    }

    if (strcmp(command, "/venderveiculo", true) == 0 || strcmp(command, "/vendercarro", true) == 0)
    {
        return Dealership_SellActiveVehicle(playerid);
    }

    if (strcmp(command, "/trancar", true) == 0 || strcmp(command, "/lock", true) == 0)
    {
        return Dealership_SetVehicleLock(playerid, 1);
    }

    if (strcmp(command, "/destrancar", true) == 0 || strcmp(command, "/unlock", true) == 0)
    {
        return Dealership_SetVehicleLock(playerid, 0);
    }

    if (strcmp(command, "/emprestarchave", true) == 0 || strcmp(command, "/darchave", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/emprestarchave [id]");
        }
        return Dealership_GrantVehicleKey(playerid, targetid);
    }

    if (strcmp(command, "/removerchave", true) == 0 || strcmp(command, "/tirarchave", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/removerchave [id]");
        }
        return Dealership_RevokeVehicleKey(playerid, targetid);
    }

    if (strcmp(command, "/consultarplaca", true) == 0)
    {
        if (!Police_IsOfficer(playerid) && !HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
        {
            SendClientMessage(playerid, COLOR_RED, "Apenas policiais ou staff podem consultar placas.");
            return 1;
        }

        if (GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            if (!Dealership_FindVehicleByPlate(param, ownerid, slot))
            {
                SendClientMessage(playerid, COLOR_RED, "Placa nao encontrada entre veiculos carregados.");
                return 1;
            }
            return Dealership_SendPlateInfo(playerid, ownerid, slot);
        }

        if (!Dealership_FindCommandVehicle(playerid, ownerid, slot))
        {
            return SendUsage(playerid, "/consultarplaca [placa]");
        }
        return Dealership_SendPlateInfo(playerid, ownerid, slot);
    }

    if (strcmp(command, "/apreenderveiculo", true) == 0 || strcmp(command, "/guinchopm", true) == 0)
    {
        GetRemainingText(cmdtext, index, param2, sizeof(param2));
        return Dlr_ImpoundVehiclePolice(playerid, param2);
    }

    return 0;
}

stock Dealership_OnPlayerDisconnect(playerid)
{
    Dlr_ClearSharedKeysFor(playerid);
    Dealership_DestroyPlayerVehicle(playerid);
    return 1;
}

