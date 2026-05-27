#if defined _nova_ambient_npcs_included
    #endinput
#endif
#define _nova_ambient_npcs_included

#define AMBIENT_NPC_KIND_PED        (1)
#define AMBIENT_NPC_KIND_DRIVER     (2)
#define AMBIENT_NPC_COUNT           (8)
#define AMBIENT_NPC_NAME_SIZE       (24)
#define AMBIENT_NPC_LABEL_SIZE      (32)
#define AMBIENT_NPC_SCRIPT_SIZE     (32)
#define AMBIENT_NPC_STOP_MS         (30000)
#define AMBIENT_NPC_ACTION_MIN_MS   (45000)
#define AMBIENT_NPC_ACTION_SPREAD_MS (90000)
#define AMBIENT_NPC_ACTION_TIME_MS  (8000)
#define AMBIENT_NPC_ACTION_RANGE    (28.0)
#define AMBIENT_NPC_DRIVER_RESTART_MS (850)
#define AMBIENT_NPC_DRIVER_SEAT_RETRY_MS (650)
#define AMBIENT_NPC_CONNECT_FIRST_MS (60000)
#define AMBIENT_NPC_CONNECT_STEP_MS (90000)
#define AMBIENT_NPC_CRIME_FIRST_MS  (3600000)
#define AMBIENT_NPC_CRIME_MIN_MS    (3600000)
#define AMBIENT_NPC_CRIME_SPREAD_MS (1)
#define AMBIENT_NPC_CRIME_ACTIVE_MS (1200000)
#define AMBIENT_NPC_CRIME_MAX_ACTIVE (1)
#define AMBIENT_NPC_CRIME_TITLE_SIZE (48)
#define AMBIENT_NPC_CRIME_LOC_SIZE  (32)
#define AMBIENT_NPC_RESPAWN_MS      (30000)
#define AMBIENT_NPC_HOSPITAL_RECOVER_MS (60000)
#define AMBIENT_NPC_HOSPITAL_X      (1179.6000)
#define AMBIENT_NPC_HOSPITAL_Y      (-1323.8000)
#define AMBIENT_NPC_HOSPITAL_Z      (14.0470)
#define AMBIENT_NPC_HOSPITAL_A      (270.0)
#define AMBIENT_NPC_REVENGE_MS      (18000)
#define AMBIENT_NPC_ATTACK_RATE_MS  (1600)
#define AMBIENT_NPC_MELEE_RANGE     (2.8)
#define AMBIENT_NPC_GUN_RANGE       (22.0)
#define AMBIENT_NPC_FIGHT_MIN_MS    (90000)
#define AMBIENT_NPC_FIGHT_SPREAD_MS (90000)

#define AMBIENT_NPC_ACTION_NONE     (0)
#define AMBIENT_NPC_ACTION_PHONE    (1)
#define AMBIENT_NPC_ACTION_CHAT     (2)
#define AMBIENT_NPC_ACTION_LOOK     (3)
#define AMBIENT_NPC_ACTION_WAVE     (4)

#define AMBIENT_NPC_CRIME_MODE_ANY  (0)
#define AMBIENT_NPC_CRIME_MODE_PED  (1)
#define AMBIENT_NPC_CRIME_MODE_DRIVER (2)

enum eAmbientNpc
{
    ambientName[AMBIENT_NPC_NAME_SIZE],
    ambientLabel[AMBIENT_NPC_LABEL_SIZE],
    ambientScript[AMBIENT_NPC_SCRIPT_SIZE],
    ambientKind,
    ambientSkin,
    ambientVehicleModel,
    Float:ambientX,
    Float:ambientY,
    Float:ambientZ,
    Float:ambientA,
    ambientColor1,
    ambientColor2
}

enum eAmbientNpcWeapon
{
    ambientWeaponId,
    ambientWeaponAmmo,
    Float:ambientWeaponDamage,
    Float:ambientWeaponRange
}

enum eAmbientNpcCrime
{
    ambientCrimeTitle[AMBIENT_NPC_CRIME_TITLE_SIZE],
    ambientCrimeLocation[AMBIENT_NPC_CRIME_LOC_SIZE],
    ambientCrimeId,
    ambientCrimeWanted,
    ambientCrimeMode,
    Float:ambientCrimeX,
    Float:ambientCrimeY,
    Float:ambientCrimeZ,
    Float:ambientCrimeA,
    ambientCrimeInterior,
    ambientCrimeWorld,
    ambientCrimeNpcIndex
}

new gAmbientNpc[][eAmbientNpc] =
{
    { "NPC_CIVIL_01", "Cidadao Prefeitura", "ls_ped_cityhall", AMBIENT_NPC_KIND_PED, 7, 0, 1472.0000, -1726.0000, 13.5469, 180.0, 0, 0 },
    { "NPC_CIVIL_02", "Paciente Hospital", "ls_ped_hospital", AMBIENT_NPC_KIND_PED, 12, 0, 1177.3000, -1328.1000, 14.0470, 270.0, 0, 0 },
    { "NPC_CIVIL_03", "Morador Idlewood", "ls_ped_idlewood", AMBIENT_NPC_KIND_PED, 29, 0, 1837.2000, -1684.5000, 13.5469, 90.0, 0, 0 },
    { "NPC_CIVIL_04", "Fiscal PRF", "ls_ped_prf", AMBIENT_NPC_KIND_PED, 60, 0, 1422.9353, -952.1232, 36.1640, 353.6627, 0, 0 },
    { "NPC_CIVIL_05", "Cidadao Centro", "ls_ped_cityhall_2", AMBIENT_NPC_KIND_PED, 20, 0, 1448.0000, -1754.0000, 13.5469, 0.0, 0, 0 },
    { "NPC_CIVIL_06", "Cliente Banco", "ls_ped_bank", AMBIENT_NPC_KIND_PED, 17, 0, 1455.0000, -1012.0000, 26.8438, 180.0, 0, 0 },
    { "NPC_CIVIL_07", "Condutor DETRAN", "ls_ped_detran", AMBIENT_NPC_KIND_PED, 15, 0, 1026.0000, -1028.0000, 32.1016, 90.0, 0, 0 },
    { "NPC_CIVIL_08", "Testemunha Civil", "ls_ped_police_civil", AMBIENT_NPC_KIND_PED, 24, 0, 288.8905, -1601.2700, 32.8313, 183.5020, 0, 0 },
    { "NPC_CIVIL_09", "Servidor Federal", "ls_ped_pf", AMBIENT_NPC_KIND_PED, 71, 0, 323.2891, -1517.4176, 36.0325, 50.6560, 0, 0 },
    { "NPC_CIVIL_10", "Visitante Penal", "ls_ped_penal", AMBIENT_NPC_KIND_PED, 23, 0, 1591.0000, -1638.0000, 13.5469, 180.0, 0, 0 },
    { "NPC_CIVIL_11", "Morador Bombeiro", "ls_ped_fire", AMBIENT_NPC_KIND_PED, 25, 0, 1754.0000, -1454.0000, 13.5313, 270.0, 0, 0 },
    { "NPC_CIVIL_12", "Passageiro Terminal", "ls_ped_terminal", AMBIENT_NPC_KIND_PED, 26, 0, 1804.0000, -1900.0000, 13.5748, 0.0, 0, 0 },
    { "NPC_CIVIL_13", "Pescador Pier", "ls_ped_pier", AMBIENT_NPC_KIND_PED, 45, 0, 386.0000, -2089.0000, 7.8359, 90.0, 0, 0 },
    { "NPC_CIVIL_14", "Cliente Oficina", "ls_ped_mechanic", AMBIENT_NPC_KIND_PED, 46, 0, 1036.0000, -1031.0000, 32.1016, 270.0, 0, 0 },
    { "NPC_CIVIL_15", "Cliente Posto", "ls_ped_gas", AMBIENT_NPC_KIND_PED, 47, 0, 1924.0000, -1776.0000, 13.5469, 90.0, 0, 0 },
    { "NPC_CIVIL_16", "Cliente Loja", "ls_ped_store", AMBIENT_NPC_KIND_PED, 48, 0, 1363.0000, -1280.0000, 13.5469, 0.0, 0, 0 },
    { "NPC_CIVIL_17", "Morador Praca", "ls_ped_cityhall_2", AMBIENT_NPC_KIND_PED, 21, 0, 1495.0000, -1740.0000, 13.5469, 180.0, 0, 0 },
    { "NPC_CIVIL_18", "Cliente Hospital", "ls_ped_hospital", AMBIENT_NPC_KIND_PED, 13, 0, 1189.0000, -1321.5000, 14.0470, 90.0, 0, 0 },
    { "NPC_CIVIL_19", "Morador Bairro", "ls_ped_idlewood", AMBIENT_NPC_KIND_PED, 30, 0, 1850.0000, -1692.0000, 13.5469, 180.0, 0, 0 },
    { "NPC_CIVIL_20", "Fiscal Rodovia", "ls_ped_prf", AMBIENT_NPC_KIND_PED, 61, 0, 1406.2000, -960.4000, 35.9000, 330.0, 0, 0 },
    { "NPC_CIVIL_21", "Cliente Terminal", "ls_ped_terminal", AMBIENT_NPC_KIND_PED, 27, 0, 1817.0000, -1889.0000, 13.5748, 180.0, 0, 0 },
    { "NPC_CIVIL_22", "Cliente Oficina 2", "ls_ped_mechanic", AMBIENT_NPC_KIND_PED, 50, 0, 1029.0000, -1018.0000, 32.1016, 180.0, 0, 0 },
    { "NPC_CIVIL_23", "Cliente Banco 2", "ls_ped_bank", AMBIENT_NPC_KIND_PED, 57, 0, 1468.5000, -1014.5000, 26.8438, 90.0, 0, 0 },
    { "NPC_CIVIL_24", "Visitante Loja", "ls_ped_store", AMBIENT_NPC_KIND_PED, 59, 0, 1352.5000, -1276.5000, 13.5469, 270.0, 0, 0 }
};

new gAmbientNpcCrimes[][eAmbientNpcCrime] =
{
    { "Roubo ao banco", "Banco Central", 1, 4, AMBIENT_NPC_CRIME_MODE_PED, 1461.2980, -1011.5210, 26.8438, 180.0, 0, 0, 5 },
    { "Roubo ao posto", "Posto Idlewood", 1, 3, AMBIENT_NPC_CRIME_MODE_PED, 1937.3510, -1768.2030, 13.5469, 0.0, 0, 0, 2 },
    { "Roubo a conveniencia", "Conveniencia Posto", 1, 2, AMBIENT_NPC_CRIME_MODE_PED, 1937.2000, -1769.1000, 13.5469, 0.0, 0, 0, 7 },
    { "Agressao em via publica", "Idlewood", 9, 3, AMBIENT_NPC_CRIME_MODE_PED, 1837.2000, -1684.5000, 13.5469, 90.0, 0, 0, 2 },
    { "Fraude na prefeitura", "Prefeitura", 3, 4, AMBIENT_NPC_CRIME_MODE_PED, 1481.0690, -1771.0450, 18.7958, 0.0, 0, 0, 0 }
};

new gAmbientNpcWeapons[][eAmbientNpcWeapon] =
{
    { WEAPON_BAT, 1, 8.0, AMBIENT_NPC_MELEE_RANGE },
    { WEAPON_KNIFE, 1, 13.0, AMBIENT_NPC_MELEE_RANGE },
    { WEAPON_COLT45, 80, 18.0, AMBIENT_NPC_GUN_RANGE }
};

new gAmbientNpcVehicle[AMBIENT_NPC_COUNT];
new gAmbientNpcPlayer[AMBIENT_NPC_COUNT];
new gAmbientNpcStopUntil[AMBIENT_NPC_COUNT];
new gAmbientNpcOrderedBy[AMBIENT_NPC_COUNT];
new gAmbientNpcJailTime[AMBIENT_NPC_COUNT];
new gAmbientNpcJailCrimeId[AMBIENT_NPC_COUNT];
new gAmbientNpcWanted[AMBIENT_NPC_COUNT];
new gAmbientNpcCrimeIndex[AMBIENT_NPC_COUNT];
new gAmbientNpcCrimeExpireTick[AMBIENT_NPC_COUNT];
new Text3D:gAmbientNpcCrimeLabel[AMBIENT_NPC_COUNT];
new gAmbientNpcActionUntil[AMBIENT_NPC_COUNT];
new gAmbientNpcNextAction[AMBIENT_NPC_COUNT];
new gAmbientNpcActionKind[AMBIENT_NPC_COUNT];
new gAmbientNpcDriverRestartTick[AMBIENT_NPC_COUNT];
new gAmbientNpcDriverSeatAttempts[AMBIENT_NPC_COUNT];
new Float:gAmbientNpcHealth[AMBIENT_NPC_COUNT];
new gAmbientNpcWeaponSlot[AMBIENT_NPC_COUNT];
new gAmbientNpcAttackTarget[AMBIENT_NPC_COUNT];
new gAmbientNpcAttackUntil[AMBIENT_NPC_COUNT];
new gAmbientNpcNextAttackTick[AMBIENT_NPC_COUNT];
new gAmbientNpcDeadUntil[AMBIENT_NPC_COUNT];
new gAmbientNpcRecoverUntil[AMBIENT_NPC_COUNT];
new gAmbientNpcLastDamager[AMBIENT_NPC_COUNT];
new gAmbientNpcLastDamageTick[AMBIENT_NPC_COUNT];
new gAmbientNpcTimer;
new gAmbientNpcNextCrimeTick;
new gAmbientNpcNextFightTick;

forward AmbientNpc_DelayedSpawn(playerid);
forward AmbientNpc_DelayedConnect(index);
forward AmbientNpc_DelayedDriverSeat(playerid);
forward AmbientNpc_DelayedDriverRestart(playerid);
forward AmbientNpc_UpdateAll();

stock AmbientNpc_FindByName(name[])
{
    new index;

    for (index = 0; index < AMBIENT_NPC_COUNT; index++)
    {
        if (strcmp(name, gAmbientNpc[index][ambientName], true) == 0)
        {
            return index;
        }
    }
    return -1;
}

stock AmbientNpc_FindByPlayer(playerid)
{
    new index;

    for (index = 0; index < AMBIENT_NPC_COUNT; index++)
    {
        if (gAmbientNpcPlayer[index] == playerid)
        {
            return index;
        }
    }
    return -1;
}

stock AmbientNpc_IsManaged(playerid)
{
    if (!IsPlayerNPC(playerid))
    {
        return 0;
    }
    return AmbientNpc_FindByPlayer(playerid) != -1;
}

stock AmbientNpc_FindDriverByVehicle(vehicleid)
{
    new index;

    if (vehicleid == INVALID_VEHICLE_ID)
    {
        return -1;
    }

    for (index = 0; index < AMBIENT_NPC_COUNT; index++)
    {
        if (
            gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_DRIVER &&
            gAmbientNpcVehicle[index] == vehicleid
        )
        {
            return index;
        }
    }
    return -1;
}

stock AmbientNpc_IsDriverVehicle(vehicleid)
{
    return AmbientNpc_FindDriverByVehicle(vehicleid) != -1;
}

stock AmbientNpc_EjectHumans(vehicleid)
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    if (!AmbientNpc_IsDriverVehicle(vehicleid))
    {
        return 0;
    }

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (
            IsPlayerConnected(playerid) &&
            !IsPlayerNPC(playerid) &&
            IsPlayerInAnyVehicle(playerid) &&
            GetPlayerVehicleID(playerid) == vehicleid
        )
        {
            RemovePlayerFromVehicle(playerid);
            ClearAnimations(playerid, 1);
            SendClientMessage(playerid, COLOR_GRAY, "Este veiculo pertence aos NPCs do servidor.");
        }
    }
    return 1;
}

stock AmbientNpc_CountConnected()
{
    new index;
    new total;

    for (index = 0; index < AMBIENT_NPC_COUNT; index++)
    {
        if (gAmbientNpcPlayer[index] != INVALID_PLAYER_ID && IsPlayerConnected(gAmbientNpcPlayer[index]))
        {
            total++;
        }
    }
    return total;
}

stock AmbientNpc_CountConfigured()
{
    return AMBIENT_NPC_COUNT;
}

stock AmbientNpc_CountWanted()
{
    new index;
    new total;

    for (index = 0; index < AMBIENT_NPC_COUNT; index++)
    {
        if (gAmbientNpcWanted[index] > 0 && gAmbientNpcPlayer[index] != INVALID_PLAYER_ID && IsPlayerConnected(gAmbientNpcPlayer[index]))
        {
            total++;
        }
    }
    return total;
}

stock Float:AmbientNpc_DistPlayers(playerid, targetid)
{
    new Float:x1;
    new Float:y1;
    new Float:z1;
    new Float:x2;
    new Float:y2;
    new Float:z2;
    new Float:dx;
    new Float:dy;
    new Float:dz;

    GetPlayerPos(playerid, x1, y1, z1);
    GetPlayerPos(targetid, x2, y2, z2);
    dx = x1 - x2;
    dy = y1 - y2;
    dz = z1 - z2;
    return floatsqroot((dx * dx) + (dy * dy) + (dz * dz));
}

stock AmbientNpc_IsAliveIndex(index)
{
    if (index < 0 || index >= AMBIENT_NPC_COUNT)
    {
        return 0;
    }
    return gAmbientNpcDeadUntil[index] <= 0 && gAmbientNpcHealth[index] > 0.0;
}

stock AmbientNpc_ResetCombat(index)
{
    if (index < 0 || index >= AMBIENT_NPC_COUNT)
    {
        return 0;
    }

    gAmbientNpcAttackTarget[index] = INVALID_PLAYER_ID;
    gAmbientNpcAttackUntil[index] = 0;
    gAmbientNpcNextAttackTick[index] = 0;
    return 1;
}

stock AmbientNpc_GetHospitalSpawn(index, &Float:x, &Float:y, &Float:z, &Float:a)
{
    x = AMBIENT_NPC_HOSPITAL_X + float((index % 4) * 1);
    y = AMBIENT_NPC_HOSPITAL_Y - float((index / 4) * 1);
    z = AMBIENT_NPC_HOSPITAL_Z;
    a = AMBIENT_NPC_HOSPITAL_A;
    return 1;
}

stock AmbientNpc_SetLoadout(index)
{
    new npcid;
    new slot;

    if (index < 0 || index >= AMBIENT_NPC_COUNT)
    {
        return 0;
    }

    npcid = gAmbientNpcPlayer[index];
    if (npcid == INVALID_PLAYER_ID || !IsPlayerConnected(npcid))
    {
        return 0;
    }

    ResetPlayerWeapons(npcid);
    slot = gAmbientNpcWeaponSlot[index];
    if (slot < 0 || slot >= sizeof(gAmbientNpcWeapons))
    {
        slot = 0;
    }
    GivePlayerWeapon(npcid, gAmbientNpcWeapons[slot][ambientWeaponId], gAmbientNpcWeapons[slot][ambientWeaponAmmo]);
    SetPlayerArmedWeapon(npcid, gAmbientNpcWeapons[slot][ambientWeaponId]);
    return 1;
}

stock AmbientNpc_SpawnAtHospital(index)
{
    new npcid;
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:a;

    if (index < 0 || index >= AMBIENT_NPC_COUNT)
    {
        return 0;
    }

    npcid = gAmbientNpcPlayer[index];
    if (npcid == INVALID_PLAYER_ID || !IsPlayerConnected(npcid))
    {
        return 0;
    }

    AmbientNpc_GetHospitalSpawn(index, x, y, z, a);
    gAmbientNpcHealth[index] = 100.0;
    SendClientMessage(npcid, COLOR_WHITE, "NPC_CMD_IDLE");
    SetPlayerHealth(npcid, 100.0);
    SetPlayerInterior(npcid, 0);
    SetPlayerVirtualWorld(npcid, 0);
    SetPlayerPos(npcid, x, y, z);
    SetPlayerFacingAngle(npcid, a);
    TogglePlayerControllable(npcid, 1);
    SetPlayerSpecialAction(npcid, SPECIAL_ACTION_NONE);
    AmbientNpc_SetLoadout(index);
    return 1;
}

stock AmbientNpc_ResetPed(index, resumePlayback = 1)
{
    new npcid;

    if (index < 0 || index >= AMBIENT_NPC_COUNT)
    {
        return 0;
    }

    npcid = gAmbientNpcPlayer[index];
    gAmbientNpcHealth[index] = 100.0;
    gAmbientNpcDeadUntil[index] = 0;
    gAmbientNpcRecoverUntil[index] = 0;
    AmbientNpc_ResetCombat(index);

    if (npcid != INVALID_PLAYER_ID && IsPlayerConnected(npcid))
    {
        SetPlayerHealth(npcid, 100.0);
        SetPlayerInterior(npcid, 0);
        SetPlayerVirtualWorld(npcid, 0);
        SetPlayerPos(npcid, gAmbientNpc[index][ambientX], gAmbientNpc[index][ambientY], gAmbientNpc[index][ambientZ]);
        SetPlayerFacingAngle(npcid, gAmbientNpc[index][ambientA]);
        TogglePlayerControllable(npcid, 1);
        SetPlayerSpecialAction(npcid, SPECIAL_ACTION_NONE);
        AmbientNpc_SetLoadout(index);
        if (resumePlayback)
        {
            SendClientMessage(npcid, COLOR_WHITE, "NPC_CMD_RESTART");
        }
    }
    return 1;
}

stock AmbientNpc_Kill(index, killerid = INVALID_PLAYER_ID, reason = 0)
{
    new npcid;
    new label[AMBIENT_NPC_LABEL_SIZE];
    new message[144];
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:a;

    if (index < 0 || index >= AMBIENT_NPC_COUNT || gAmbientNpcDeadUntil[index] > 0)
    {
        return 0;
    }

    npcid = gAmbientNpcPlayer[index];
    gAmbientNpcHealth[index] = 0.0;
    gAmbientNpcDeadUntil[index] = GetTickCount() + AMBIENT_NPC_RESPAWN_MS;
    gAmbientNpcRecoverUntil[index] = 0;
    gAmbientNpcStopUntil[index] = 0;
    gAmbientNpcActionUntil[index] = 0;
    gAmbientNpcActionKind[index] = AMBIENT_NPC_ACTION_NONE;
    AmbientNpc_ResetCombat(index);
    AmbientNpc_ClearCrime(index, 0);

    if (npcid != INVALID_PLAYER_ID && IsPlayerConnected(npcid))
    {
        AmbientNpc_GetHospitalSpawn(index, x, y, z, a);
        SetSpawnInfo(npcid, NO_TEAM, gAmbientNpc[index][ambientSkin], x, y, z, a, 0, 0, 0, 0, 0, 0);
        SendClientMessage(npcid, COLOR_WHITE, "NPC_CMD_IDLE");
        TogglePlayerControllable(npcid, 0);
        SetPlayerHealth(npcid, 0.0);
    }

    if (killerid != INVALID_PLAYER_ID && IsPlayerConnected(killerid) && !IsPlayerNPC(killerid))
    {
        format(label, sizeof(label), "%s", gAmbientNpc[index][ambientLabel]);
        format(message, sizeof(message), "Voce matou %s (ID %d).", label, npcid);
        SendClientMessage(killerid, COLOR_RED, message);
    }
    #pragma unused reason
    return 1;
}

stock AmbientNpc_StartAttack(index, targetid, reasonText[] = "agressao")
{
    new npcid;
    new label[AMBIENT_NPC_LABEL_SIZE];
    new message[144];

    if (index < 0 || index >= AMBIENT_NPC_COUNT || !AmbientNpc_IsAliveIndex(index))
    {
        return 0;
    }
    if (targetid == INVALID_PLAYER_ID || !IsPlayerConnected(targetid) || targetid == gAmbientNpcPlayer[index])
    {
        return 0;
    }
    if (gAmbientNpcJailTime[index] > 0 || gAmbientNpcOrderedBy[index] != INVALID_PLAYER_ID)
    {
        return 0;
    }

    npcid = gAmbientNpcPlayer[index];
    if (npcid == INVALID_PLAYER_ID || !IsPlayerConnected(npcid))
    {
        return 0;
    }

    if (gAmbientNpcActionUntil[index] > 0)
    {
        AmbientNpc_StopAction(index, 0);
    }

    SendClientMessage(npcid, COLOR_WHITE, "NPC_CMD_IDLE");
    ClearAnimations(npcid, 1);
    SetPlayerSpecialAction(npcid, SPECIAL_ACTION_NONE);
    TogglePlayerControllable(npcid, 1);
    AmbientNpc_SetLoadout(index);
    gAmbientNpcAttackTarget[index] = targetid;
    gAmbientNpcAttackUntil[index] = GetTickCount() + AMBIENT_NPC_REVENGE_MS;
    gAmbientNpcNextAttackTick[index] = 0;

    if (gAmbientNpcWanted[index] < 2)
    {
        gAmbientNpcWanted[index] = 2;
        gAmbientNpcCrimeIndex[index] = 3;
        gAmbientNpcCrimeExpireTick[index] = GetTickCount() + AMBIENT_NPC_CRIME_ACTIVE_MS;
        gAmbientNpcJailCrimeId[index] = 0;
    }

    AmbientNpc_GetDisplayName(npcid, label, sizeof(label));
    format(message, sizeof(message), "%s reageu a %s.", label, reasonText);
    AmbientNpc_SendNearby(index, message);
    ApplyAnimation(npcid, "FIGHT_D", "FightD_IDLE", 4.1, 1, 0, 0, 0, 0, 1);
    return 1;
}

stock AmbientNpc_Damage(index, Float:amount, attackerid = INVALID_PLAYER_ID, weaponid = 0)
{
    new npcid;
    new tick;

    if (index < 0 || index >= AMBIENT_NPC_COUNT || !AmbientNpc_IsAliveIndex(index))
    {
        return 0;
    }
    if (amount <= 0.0)
    {
        amount = 5.0;
    }

    tick = GetTickCount();
    if (gAmbientNpcLastDamager[index] == attackerid && (tick - gAmbientNpcLastDamageTick[index]) < 250)
    {
        return 1;
    }
    gAmbientNpcLastDamager[index] = attackerid;
    gAmbientNpcLastDamageTick[index] = tick;

    npcid = gAmbientNpcPlayer[index];
    gAmbientNpcHealth[index] -= amount;

    if (gAmbientNpcHealth[index] <= 0.0)
    {
        return AmbientNpc_Kill(index, attackerid, weaponid);
    }

    if (npcid != INVALID_PLAYER_ID && IsPlayerConnected(npcid))
    {
        SetPlayerHealth(npcid, gAmbientNpcHealth[index]);
    }

    if (attackerid != INVALID_PLAYER_ID && IsPlayerConnected(attackerid))
    {
        AmbientNpc_StartAttack(index, attackerid, "agressao");
    }
    return 1;
}

stock AmbientNpc_ApplyAttackHit(index, targetid)
{
    new npcid;
    new slot;
    new weaponid;
    new Float:range;
    new Float:damage;
    new targetIndex;
    new Float:health;

    if (index < 0 || index >= AMBIENT_NPC_COUNT || !AmbientNpc_IsAliveIndex(index))
    {
        return 0;
    }
    if (targetid == INVALID_PLAYER_ID || !IsPlayerConnected(targetid))
    {
        return 0;
    }

    npcid = gAmbientNpcPlayer[index];
    if (npcid == INVALID_PLAYER_ID || !IsPlayerConnected(npcid))
    {
        return 0;
    }

    slot = gAmbientNpcWeaponSlot[index];
    if (slot < 0 || slot >= sizeof(gAmbientNpcWeapons))
    {
        slot = 0;
    }
    weaponid = gAmbientNpcWeapons[slot][ambientWeaponId];
    range = gAmbientNpcWeapons[slot][ambientWeaponRange];
    damage = gAmbientNpcWeapons[slot][ambientWeaponDamage];

    if (AmbientNpc_DistPlayers(npcid, targetid) > range)
    {
        return 0;
    }

    SetPlayerArmedWeapon(npcid, weaponid);
    if (weaponid == WEAPON_COLT45)
    {
        ApplyAnimation(npcid, "PED", "GUN_STAND", 4.1, 0, 1, 1, 1, 750, 1);
    }
    else
    {
        ApplyAnimation(npcid, "FIGHT_D", "FightD_3", 4.1, 0, 1, 1, 0, 750, 1);
    }

    targetIndex = AmbientNpc_FindByPlayer(targetid);
    if (targetIndex != -1)
    {
        AmbientNpc_Damage(targetIndex, damage, npcid, weaponid);
        return 1;
    }

    if (!IsPlayerNPC(targetid))
    {
        GetPlayerHealth(targetid, health);
        health -= damage;
        if (health < 25.0)
        {
            health = 25.0;
            AmbientNpc_ResetCombat(index);
        }
        SetPlayerHealth(targetid, health);
    }
    return 1;
}

stock AmbientNpc_UpdateCombat(tick)
{
    new index;
    new targetid;
    new targetIndex;
    new npcid;
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:a;

    for (index = 0; index < AMBIENT_NPC_COUNT; index++)
    {
        if (gAmbientNpcDeadUntil[index] > 0)
        {
            if (tick >= gAmbientNpcDeadUntil[index])
            {
                npcid = gAmbientNpcPlayer[index];
                gAmbientNpcDeadUntil[index] = 0;
                gAmbientNpcRecoverUntil[index] = tick + AMBIENT_NPC_HOSPITAL_RECOVER_MS;
                gAmbientNpcHealth[index] = 100.0;
                AmbientNpc_ResetCombat(index);
                AmbientNpc_GetHospitalSpawn(index, x, y, z, a);
                if (npcid != INVALID_PLAYER_ID && IsPlayerConnected(npcid))
                {
                    SetSpawnInfo(npcid, NO_TEAM, gAmbientNpc[index][ambientSkin], x, y, z, a, 0, 0, 0, 0, 0, 0);
                    SpawnPlayer(npcid);
                    AmbientNpc_SpawnAtHospital(index);
                }
            }
            continue;
        }

        targetid = gAmbientNpcAttackTarget[index];
        if (targetid == INVALID_PLAYER_ID)
        {
            continue;
        }

        if (tick >= gAmbientNpcAttackUntil[index] || !IsPlayerConnected(targetid))
        {
            AmbientNpc_ResetCombat(index);
            if (gAmbientNpcRecoverUntil[index] <= 0)
            {
                AmbientNpc_ResetPed(index, 1);
            }
            continue;
        }

        targetIndex = AmbientNpc_FindByPlayer(targetid);
        if (targetIndex != -1 && !AmbientNpc_IsAliveIndex(targetIndex))
        {
            AmbientNpc_ResetCombat(index);
            if (gAmbientNpcRecoverUntil[index] <= 0)
            {
                AmbientNpc_ResetPed(index, 1);
            }
            continue;
        }

        if (tick >= gAmbientNpcNextAttackTick[index])
        {
            AmbientNpc_ApplyAttackHit(index, targetid);
            gAmbientNpcNextAttackTick[index] = tick + AMBIENT_NPC_ATTACK_RATE_MS;
        }
    }
    return 1;
}

stock AmbientNpc_StartRandomFight(tick)
{
    new first = -1;
    new second = -1;
    new offset;
    new index;
    new start = random(AMBIENT_NPC_COUNT);

    for (offset = 0; offset < AMBIENT_NPC_COUNT; offset++)
    {
        index = (start + offset) % AMBIENT_NPC_COUNT;
        if (
            AmbientNpc_IsAliveIndex(index) &&
            gAmbientNpcJailTime[index] <= 0 &&
            gAmbientNpcOrderedBy[index] == INVALID_PLAYER_ID &&
            gAmbientNpcPlayer[index] != INVALID_PLAYER_ID &&
            IsPlayerConnected(gAmbientNpcPlayer[index])
        )
        {
            if (first == -1)
            {
                first = index;
            }
            else
            {
                second = index;
                break;
            }
        }
    }

    if (first != -1 && second != -1)
    {
        AmbientNpc_StartAttack(first, gAmbientNpcPlayer[second], "briga de rua");
        AmbientNpc_StartAttack(second, gAmbientNpcPlayer[first], "briga de rua");
    }

    gAmbientNpcNextFightTick = tick + AMBIENT_NPC_FIGHT_MIN_MS + random(AMBIENT_NPC_FIGHT_SPREAD_MS);
    return 1;
}

stock AmbientNpc_IsJailed(playerid)
{
    new index = AmbientNpc_FindByPlayer(playerid);

    if (index == -1)
    {
        return 0;
    }
    return gAmbientNpcJailTime[index] > 0;
}

stock AmbientNpc_GetJailTime(playerid)
{
    new index = AmbientNpc_FindByPlayer(playerid);

    if (index == -1)
    {
        return 0;
    }
    return gAmbientNpcJailTime[index];
}

stock AmbientNpc_GetWanted(playerid)
{
    new index = AmbientNpc_FindByPlayer(playerid);

    if (index == -1)
    {
        return 0;
    }
    return gAmbientNpcWanted[index];
}

stock AmbientNpc_GetCrimeId(playerid)
{
    new index = AmbientNpc_FindByPlayer(playerid);
    new crimeIndex;

    if (index == -1)
    {
        return 0;
    }
    if (gAmbientNpcJailCrimeId[index] > 0)
    {
        return gAmbientNpcJailCrimeId[index];
    }
    crimeIndex = gAmbientNpcCrimeIndex[index];
    if (crimeIndex < 0 || crimeIndex >= sizeof(gAmbientNpcCrimes))
    {
        return 0;
    }
    return gAmbientNpcCrimes[crimeIndex][ambientCrimeId];
}

stock AmbientNpc_GetCrimeTitle(playerid, output[], size = sizeof(output))
{
    new index = AmbientNpc_FindByPlayer(playerid);
    new crimeIndex;

    if (index == -1)
    {
        format(output, size, "sem registro");
        return 0;
    }
    crimeIndex = gAmbientNpcCrimeIndex[index];
    if (crimeIndex < 0 || crimeIndex >= sizeof(gAmbientNpcCrimes))
    {
        if (gAmbientNpcJailCrimeId[index] > 0)
        {
            format(output, size, "custodia crime %d", gAmbientNpcJailCrimeId[index]);
            return 1;
        }
        format(output, size, "sem registro");
        return 0;
    }
    format(output, size, "%s", gAmbientNpcCrimes[crimeIndex][ambientCrimeTitle]);
    return 1;
}

stock AmbientNpc_GetCrimeLocation(playerid, output[], size = sizeof(output))
{
    new index = AmbientNpc_FindByPlayer(playerid);
    new crimeIndex;

    if (index == -1)
    {
        format(output, size, "desconhecido");
        return 0;
    }
    crimeIndex = gAmbientNpcCrimeIndex[index];
    if (crimeIndex < 0 || crimeIndex >= sizeof(gAmbientNpcCrimes))
    {
        format(output, size, "sem ocorrencia ativa");
        return 0;
    }
    format(output, size, "%s", gAmbientNpcCrimes[crimeIndex][ambientCrimeLocation]);
    return 1;
}

stock AmbientNpc_GetDisplayName(playerid, output[], size = sizeof(output))
{
    new index = AmbientNpc_FindByPlayer(playerid);

    if (index == -1)
    {
        GetPlayerNameEx(playerid, output, size);
        return 0;
    }

    format(output, size, "%s", gAmbientNpc[index][ambientLabel]);
    return 1;
}

stock AmbientNpc_DestroyCrimeLabel(index)
{
    if (index < 0 || index >= AMBIENT_NPC_COUNT)
    {
        return 0;
    }
    if (gAmbientNpcCrimeLabel[index] != Text3D:INVALID_3DTEXT_ID)
    {
        Delete3DTextLabel(gAmbientNpcCrimeLabel[index]);
        gAmbientNpcCrimeLabel[index] = Text3D:INVALID_3DTEXT_ID;
    }
    return 1;
}

stock AmbientNpc_ClearCrime(index, resumeRoute = 1)
{
    new npcid;

    if (index < 0 || index >= AMBIENT_NPC_COUNT)
    {
        return 0;
    }

    AmbientNpc_DestroyCrimeLabel(index);
    gAmbientNpcWanted[index] = 0;
    gAmbientNpcCrimeIndex[index] = -1;
    gAmbientNpcCrimeExpireTick[index] = 0;

    npcid = gAmbientNpcPlayer[index];
    if (resumeRoute && npcid != INVALID_PLAYER_ID && IsPlayerConnected(npcid) && gAmbientNpcJailTime[index] <= 0 && gAmbientNpcOrderedBy[index] == INVALID_PLAYER_ID)
    {
        if (gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_DRIVER)
        {
            AmbientNpc_ResetDriver(index, 1);
        }
        else
        {
            SetPlayerInterior(npcid, 0);
            SetPlayerVirtualWorld(npcid, 0);
            SetPlayerPos(npcid, gAmbientNpc[index][ambientX], gAmbientNpc[index][ambientY], gAmbientNpc[index][ambientZ]);
            SetPlayerFacingAngle(npcid, gAmbientNpc[index][ambientA]);
            TogglePlayerControllable(npcid, 1);
            SetPlayerSpecialAction(npcid, SPECIAL_ACTION_NONE);
            SendClientMessage(npcid, COLOR_WHITE, "NPC_CMD_RESTART");
            AmbientNpc_ScheduleNextAction(index);
        }
    }
    return 1;
}

stock AmbientNpc_CrimeModeMatches(index, crimeIndex)
{
    new wantedMode;

    if (crimeIndex < 0 || crimeIndex >= sizeof(gAmbientNpcCrimes))
    {
        return 0;
    }
    if (gAmbientNpcCrimes[crimeIndex][ambientCrimeNpcIndex] >= 0 && gAmbientNpcCrimes[crimeIndex][ambientCrimeNpcIndex] != index)
    {
        return 0;
    }

    wantedMode = gAmbientNpcCrimes[crimeIndex][ambientCrimeMode];
    if (wantedMode == AMBIENT_NPC_CRIME_MODE_ANY)
    {
        return 1;
    }
    if (wantedMode == AMBIENT_NPC_CRIME_MODE_PED)
    {
        return gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_PED;
    }
    if (wantedMode == AMBIENT_NPC_CRIME_MODE_DRIVER)
    {
        return gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_DRIVER;
    }
    return 0;
}

stock AmbientNpc_SelectCrime(index)
{
    new offset;
    new crimeIndex;
    new start = random(sizeof(gAmbientNpcCrimes));

    for (offset = 0; offset < sizeof(gAmbientNpcCrimes); offset++)
    {
        crimeIndex = (start + offset) % sizeof(gAmbientNpcCrimes);
        if (AmbientNpc_CrimeModeMatches(index, crimeIndex))
        {
            return crimeIndex;
        }
    }
    return -1;
}

stock AmbientNpc_CanStartCrime(index)
{
    if (index < 0 || index >= AMBIENT_NPC_COUNT)
    {
        return 0;
    }
    if (gAmbientNpcPlayer[index] == INVALID_PLAYER_ID || !IsPlayerConnected(gAmbientNpcPlayer[index]))
    {
        return 0;
    }
    if (gAmbientNpcJailTime[index] > 0 || gAmbientNpcOrderedBy[index] != INVALID_PLAYER_ID || gAmbientNpcWanted[index] > 0)
    {
        return 0;
    }
    return 1;
}

stock AmbientNpc_SendCrimeAlert(index)
{
    new playerid;
    new maxPlayers = GetMaxPlayers();
    new npcid;
    new label[AMBIENT_NPC_LABEL_SIZE];
    new message[160];
    new crimeIndex;

    if (index < 0 || index >= AMBIENT_NPC_COUNT)
    {
        return 0;
    }
    crimeIndex = gAmbientNpcCrimeIndex[index];
    if (crimeIndex < 0 || crimeIndex >= sizeof(gAmbientNpcCrimes))
    {
        return 0;
    }

    npcid = gAmbientNpcPlayer[index];
    AmbientNpc_GetDisplayName(npcid, label, sizeof(label));
    format(message, sizeof(message), "[190] Procurado NPC ID %d | %s | %s em %s | %d estrela(s). Use /procurados.", npcid, label, gAmbientNpcCrimes[crimeIndex][ambientCrimeTitle], gAmbientNpcCrimes[crimeIndex][ambientCrimeLocation], gAmbientNpcWanted[index]);

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (!IsPlayerConnected(playerid) || IsPlayerNPC(playerid) || !PlayerInfo[playerid][pLogged])
        {
            continue;
        }
        if (IsPublicSecurityJob(PlayerInfo[playerid][pJob]) || PlayerInfo[playerid][pJob] == JOB_JUIZ || HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
        {
            SendClientMessage(playerid, COLOR_ADMIN, message);
        }
        else if (IsPlayerInRangeOfPoint(playerid, 80.0, gAmbientNpcCrimes[crimeIndex][ambientCrimeX], gAmbientNpcCrimes[crimeIndex][ambientCrimeY], gAmbientNpcCrimes[crimeIndex][ambientCrimeZ]))
        {
            SendClientMessage(playerid, COLOR_ORANGE, "Voce ouviu sirenes: uma ocorrencia com NPC acabou de ser registrada perto daqui.");
        }
    }
    WriteServerLog(LOG_PUNISH_FILE, "NPC_WANTED", message);
    return 1;
}

stock AmbientNpc_ApplyCrimeAction(npcid, crimeIndex)
{
    new crimeid;

    if (crimeIndex < 0 || crimeIndex >= sizeof(gAmbientNpcCrimes))
    {
        return 0;
    }

    crimeid = gAmbientNpcCrimes[crimeIndex][ambientCrimeId];
    ClearAnimations(npcid, 1);
    SetPlayerSpecialAction(npcid, SPECIAL_ACTION_NONE);

    if (crimeid == 1)
    {
        ApplyAnimation(npcid, "SHOP", "ROB_Loop", 4.1, 1, 0, 0, 0, 0, 1);
        return 1;
    }
    if (crimeid == 3)
    {
        SetPlayerSpecialAction(npcid, SPECIAL_ACTION_USECELLPHONE);
        return 1;
    }
    if (crimeid == 9)
    {
        ApplyAnimation(npcid, "FIGHT_D", "FightD_IDLE", 4.1, 1, 0, 0, 0, 0, 1);
        return 1;
    }

    ApplyAnimation(npcid, "PED", "IDLE_CHAT", 4.1, 1, 0, 0, 0, 0, 1);
    return 1;
}

stock AmbientNpc_StartCrime(index, crimeIndex, tick)
{
    new npcid;
    new text[160];

    if (!AmbientNpc_CanStartCrime(index) || crimeIndex < 0 || crimeIndex >= sizeof(gAmbientNpcCrimes))
    {
        return 0;
    }

    npcid = gAmbientNpcPlayer[index];
    gAmbientNpcWanted[index] = gAmbientNpcCrimes[crimeIndex][ambientCrimeWanted];
    if (gAmbientNpcWanted[index] > MAX_WANTED_LEVEL)
    {
        gAmbientNpcWanted[index] = MAX_WANTED_LEVEL;
    }
    gAmbientNpcCrimeIndex[index] = crimeIndex;
    gAmbientNpcCrimeExpireTick[index] = tick + AMBIENT_NPC_CRIME_ACTIVE_MS;
    gAmbientNpcJailCrimeId[index] = 0;

    AmbientNpc_DestroyCrimeLabel(index);
    format(text, sizeof(text), "OCORRENCIA NPC\n%s\nID %d | %d estrela(s)\n/procurados", gAmbientNpcCrimes[crimeIndex][ambientCrimeTitle], npcid, gAmbientNpcWanted[index]);
    gAmbientNpcCrimeLabel[index] = Create3DTextLabel(text, COLOR_RED, gAmbientNpcCrimes[crimeIndex][ambientCrimeX], gAmbientNpcCrimes[crimeIndex][ambientCrimeY], gAmbientNpcCrimes[crimeIndex][ambientCrimeZ] + 1.1, 45.0, gAmbientNpcCrimes[crimeIndex][ambientCrimeWorld], 0);

    if (gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_DRIVER)
    {
        AmbientNpc_ResetDriver(index, 1);
    }
    else
    {
        if (gAmbientNpcActionUntil[index] > 0)
        {
            AmbientNpc_StopAction(index, 0);
        }
        SendClientMessage(npcid, COLOR_WHITE, "NPC_CMD_IDLE");
        SetPlayerInterior(npcid, gAmbientNpcCrimes[crimeIndex][ambientCrimeInterior]);
        SetPlayerVirtualWorld(npcid, gAmbientNpcCrimes[crimeIndex][ambientCrimeWorld]);
        SetPlayerPos(npcid, gAmbientNpcCrimes[crimeIndex][ambientCrimeX], gAmbientNpcCrimes[crimeIndex][ambientCrimeY], gAmbientNpcCrimes[crimeIndex][ambientCrimeZ]);
        SetPlayerFacingAngle(npcid, gAmbientNpcCrimes[crimeIndex][ambientCrimeA]);
        TogglePlayerControllable(npcid, 1);
        AmbientNpc_ApplyCrimeAction(npcid, crimeIndex);
    }

    AmbientNpc_SendCrimeAlert(index);
    return 1;
}

stock AmbientNpc_UpdateCrimeSystem(tick)
{
    new index;
    new offset;
    new crimeIndex;
    new start;

    for (index = 0; index < AMBIENT_NPC_COUNT; index++)
    {
        if (gAmbientNpcWanted[index] > 0 && gAmbientNpcCrimeExpireTick[index] > 0 && tick >= gAmbientNpcCrimeExpireTick[index] && gAmbientNpcJailTime[index] <= 0)
        {
            AmbientNpc_ClearCrime(index, 1);
        }
    }

    if (gAmbientNpcNextCrimeTick <= 0)
    {
        gAmbientNpcNextCrimeTick = tick + AMBIENT_NPC_CRIME_FIRST_MS;
        return 1;
    }
    if (tick < gAmbientNpcNextCrimeTick)
    {
        return 1;
    }

    gAmbientNpcNextCrimeTick = tick + AMBIENT_NPC_CRIME_MIN_MS + random(AMBIENT_NPC_CRIME_SPREAD_MS);
    if (AmbientNpc_CountWanted() >= AMBIENT_NPC_CRIME_MAX_ACTIVE)
    {
        return 1;
    }

    start = random(AMBIENT_NPC_COUNT);
    for (offset = 0; offset < AMBIENT_NPC_COUNT; offset++)
    {
        index = (start + offset) % AMBIENT_NPC_COUNT;
        if (!AmbientNpc_CanStartCrime(index))
        {
            continue;
        }

        crimeIndex = AmbientNpc_SelectCrime(index);
        if (crimeIndex != -1)
        {
            return AmbientNpc_StartCrime(index, crimeIndex, tick);
        }
    }
    return 1;
}

stock AmbientNpc_AppendWantedRows(list[], size, &count)
{
    new index;
    new npcid;
    new line[192];
    new label[AMBIENT_NPC_LABEL_SIZE];
    new crime[AMBIENT_NPC_CRIME_TITLE_SIZE];
    new location[AMBIENT_NPC_CRIME_LOC_SIZE];

    for (index = 0; index < AMBIENT_NPC_COUNT; index++)
    {
        if (gAmbientNpcWanted[index] <= 0 || gAmbientNpcPlayer[index] == INVALID_PLAYER_ID || !IsPlayerConnected(gAmbientNpcPlayer[index]))
        {
            continue;
        }
        npcid = gAmbientNpcPlayer[index];
        AmbientNpc_GetDisplayName(npcid, label, sizeof(label));
        AmbientNpc_GetCrimeTitle(npcid, crime, sizeof(crime));
        AmbientNpc_GetCrimeLocation(npcid, location, sizeof(location));
        format(line, sizeof(line), "NPC\tID %d %s\t%d estrela(s) | crime %d\t%s | %s\n", npcid, label, gAmbientNpcWanted[index], AmbientNpc_GetCrimeId(npcid), crime, location);
        if (strlen(list) + strlen(line) < size - 1)
        {
            strcat(list, line, size);
            count++;
        }
    }
    return 1;
}

stock AmbientNpc_ScheduleNextAction(index, tick = 0)
{
    if (index < 0 || index >= AMBIENT_NPC_COUNT)
    {
        return 0;
    }

    if (tick <= 0)
    {
        tick = GetTickCount();
    }

    gAmbientNpcNextAction[index] = tick + AMBIENT_NPC_ACTION_MIN_MS + ((index * 7139) % AMBIENT_NPC_ACTION_SPREAD_MS);
    return 1;
}

stock AmbientNpc_SendNearby(index, text[])
{
    new npcid;
    new playerid;
    new maxPlayers = GetMaxPlayers();
    new label[AMBIENT_NPC_LABEL_SIZE];
    new message[144];
    new Float:x;
    new Float:y;
    new Float:z;

    if (index < 0 || index >= AMBIENT_NPC_COUNT)
    {
        return 0;
    }

    npcid = gAmbientNpcPlayer[index];
    if (npcid == INVALID_PLAYER_ID || !IsPlayerConnected(npcid))
    {
        return 0;
    }

    GetPlayerPos(npcid, x, y, z);
    AmbientNpc_GetDisplayName(npcid, label, sizeof(label));
    format(message, sizeof(message), "[NPC] %s: %s", label, text);

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (!IsPlayerConnected(playerid) || IsPlayerNPC(playerid) || !PlayerInfo[playerid][pLogged])
        {
            continue;
        }
        if (GetPlayerInterior(playerid) != GetPlayerInterior(npcid) || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(npcid))
        {
            continue;
        }
        if (IsPlayerInRangeOfPoint(playerid, AMBIENT_NPC_ACTION_RANGE, x, y, z))
        {
            SendClientMessage(playerid, COLOR_LOCAL, message);
        }
    }
    return 1;
}

stock AmbientNpc_ActionText(index, action, output[], size = sizeof(output))
{
    switch (action)
    {
        case AMBIENT_NPC_ACTION_PHONE:
        {
            format(output, size, "Vou resolver isso pelo GovBR.");
        }
        case AMBIENT_NPC_ACTION_CHAT:
        {
            switch (index % 4)
            {
                case 0: format(output, size, "A cidade esta movimentada hoje.");
                case 1: format(output, size, "Estou indo resolver umas pendencias.");
                case 2: format(output, size, "Vi uma blitz mais cedo, melhor dirigir certo.");
                default: format(output, size, "Preciso passar no banco depois.");
            }
        }
        case AMBIENT_NPC_ACTION_LOOK:
        {
            format(output, size, "Parece que tem bastante movimento por aqui.");
        }
        case AMBIENT_NPC_ACTION_WAVE:
        {
            format(output, size, "Bom dia.");
        }
        default:
        {
            format(output, size, "...");
        }
    }
    return 1;
}

stock AmbientNpc_StartAction(index, tick)
{
    new npcid;
    new action;
    new text[96];

    if (index < 0 || index >= AMBIENT_NPC_COUNT || gAmbientNpc[index][ambientKind] != AMBIENT_NPC_KIND_PED)
    {
        return 0;
    }

    npcid = gAmbientNpcPlayer[index];
    if (npcid == INVALID_PLAYER_ID || !IsPlayerConnected(npcid) || gAmbientNpcJailTime[index] > 0 || gAmbientNpcStopUntil[index] > 0)
    {
        return 0;
    }

    action = (index % 4) + 1;
    gAmbientNpcActionKind[index] = action;
    gAmbientNpcActionUntil[index] = tick + AMBIENT_NPC_ACTION_TIME_MS + ((index % 3) * 1500);
    SendClientMessage(npcid, COLOR_WHITE, "NPC_CMD_IDLE");
    ClearAnimations(npcid, 1);
    SetPlayerSpecialAction(npcid, SPECIAL_ACTION_NONE);

    switch (action)
    {
        case AMBIENT_NPC_ACTION_PHONE:
        {
            SetPlayerSpecialAction(npcid, SPECIAL_ACTION_USECELLPHONE);
        }
        case AMBIENT_NPC_ACTION_CHAT:
        {
            ApplyAnimation(npcid, "PED", "IDLE_CHAT", 4.1, 1, 0, 0, 0, 0, 1);
        }
        case AMBIENT_NPC_ACTION_LOOK:
        {
            ApplyAnimation(npcid, "ON_LOOKERS", "lkup_loop", 4.1, 1, 0, 0, 0, 0, 1);
        }
        case AMBIENT_NPC_ACTION_WAVE:
        {
            ApplyAnimation(npcid, "ON_LOOKERS", "wave_loop", 4.1, 1, 0, 0, 0, 0, 1);
        }
    }

    AmbientNpc_ActionText(index, action, text, sizeof(text));
    AmbientNpc_SendNearby(index, text);
    return 1;
}

stock AmbientNpc_StopAction(index, resumePlayback = 1)
{
    new npcid;

    if (index < 0 || index >= AMBIENT_NPC_COUNT)
    {
        return 0;
    }

    npcid = gAmbientNpcPlayer[index];
    gAmbientNpcActionUntil[index] = 0;
    gAmbientNpcActionKind[index] = AMBIENT_NPC_ACTION_NONE;
    AmbientNpc_ScheduleNextAction(index);

    if (npcid != INVALID_PLAYER_ID && IsPlayerConnected(npcid))
    {
        ClearAnimations(npcid, 1);
        SetPlayerSpecialAction(npcid, SPECIAL_ACTION_NONE);
        if (resumePlayback && gAmbientNpcJailTime[index] <= 0 && gAmbientNpcStopUntil[index] <= 0)
        {
            SendClientMessage(npcid, COLOR_WHITE, "NPC_CMD_RESUME");
        }
    }
    return 1;
}

stock AmbientNpc_SetSpawnInfo(playerid, index)
{
    new Float:spawnX = gAmbientNpc[index][ambientX];
    new Float:spawnY = gAmbientNpc[index][ambientY];
    new Float:spawnZ = gAmbientNpc[index][ambientZ];

    if (gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_DRIVER)
    {
        spawnX += 4.0;
        spawnY += 4.0;
        spawnZ += 0.5;
    }

    SetSpawnInfo(
        playerid,
        NO_TEAM,
        gAmbientNpc[index][ambientSkin],
        spawnX,
        spawnY,
        spawnZ,
        gAmbientNpc[index][ambientA],
        0, 0, 0, 0, 0, 0
    );
    return 1;
}

stock AmbientNpc_SetDriverVehReady(vehicleid)
{
    new engine;
    new lights;
    new alarm;
    new doors;
    new bonnet;
    new boot;
    new objective;

    if (vehicleid == INVALID_VEHICLE_ID || GetVehicleModel(vehicleid) == 0)
    {
        return 0;
    }

    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_ON, lights, alarm, VEHICLE_PARAMS_ON, bonnet, boot, objective);
    RepairVehicle(vehicleid);
    return 1;
}

stock AmbientNpc_CreateDriverVehicle(index)
{
    if (index < 0 || index >= AMBIENT_NPC_COUNT || gAmbientNpc[index][ambientKind] != AMBIENT_NPC_KIND_DRIVER)
    {
        return INVALID_VEHICLE_ID;
    }

    if (gAmbientNpcVehicle[index] != INVALID_VEHICLE_ID && GetVehicleModel(gAmbientNpcVehicle[index]) != 0)
    {
        DestroyVehicle(gAmbientNpcVehicle[index]);
    }

    gAmbientNpcVehicle[index] = CreateVehicle(
        gAmbientNpc[index][ambientVehicleModel],
        gAmbientNpc[index][ambientX],
        gAmbientNpc[index][ambientY],
        gAmbientNpc[index][ambientZ],
        gAmbientNpc[index][ambientA],
        gAmbientNpc[index][ambientColor1],
        gAmbientNpc[index][ambientColor2],
        -1
    );

    if (gAmbientNpcVehicle[index] != INVALID_VEHICLE_ID)
    {
        LinkVehicleToInterior(gAmbientNpcVehicle[index], 0);
        SetVehicleVirtualWorld(gAmbientNpcVehicle[index], 0);
        AmbientNpc_SetDriverVehReady(gAmbientNpcVehicle[index]);
    }
    return gAmbientNpcVehicle[index];
}

stock AmbientNpc_ResetDriver(index, restartPlayback = 1)
{
    new npcid;
    new tick;

    if (index < 0 || index >= AMBIENT_NPC_COUNT || gAmbientNpc[index][ambientKind] != AMBIENT_NPC_KIND_DRIVER)
    {
        return 0;
    }

    npcid = gAmbientNpcPlayer[index];
    if (gAmbientNpcVehicle[index] == INVALID_VEHICLE_ID || GetVehicleModel(gAmbientNpcVehicle[index]) == 0)
    {
        AmbientNpc_CreateDriverVehicle(index);
    }

    if (gAmbientNpcVehicle[index] == INVALID_VEHICLE_ID || GetVehicleModel(gAmbientNpcVehicle[index]) == 0)
    {
        return 0;
    }

    AmbientNpc_EjectHumans(gAmbientNpcVehicle[index]);
    SetVehiclePos(gAmbientNpcVehicle[index], gAmbientNpc[index][ambientX], gAmbientNpc[index][ambientY], gAmbientNpc[index][ambientZ]);
    SetVehicleZAngle(gAmbientNpcVehicle[index], gAmbientNpc[index][ambientA]);
    LinkVehicleToInterior(gAmbientNpcVehicle[index], 0);
    SetVehicleVirtualWorld(gAmbientNpcVehicle[index], 0);
    AmbientNpc_SetDriverVehReady(gAmbientNpcVehicle[index]);

    if (npcid != INVALID_PLAYER_ID && IsPlayerConnected(npcid))
    {
        SendClientMessage(npcid, COLOR_WHITE, "NPC_CMD_DRIVER_RESET");
        SetPlayerInterior(npcid, 0);
        SetPlayerVirtualWorld(npcid, 0);
        TogglePlayerControllable(npcid, 1);
        SetPlayerPos(npcid, gAmbientNpc[index][ambientX] + 2.0, gAmbientNpc[index][ambientY] + 2.0, gAmbientNpc[index][ambientZ] + 0.5);
        PutPlayerInVehicle(npcid, gAmbientNpcVehicle[index], 0);

        if (restartPlayback)
        {
            gAmbientNpcDriverSeatAttempts[index] = 0;
            tick = GetTickCount();
            gAmbientNpcDriverRestartTick[index] = tick + AMBIENT_NPC_DRIVER_SEAT_RETRY_MS;
            SetTimerEx("AmbientNpc_DelayedDriverRestart", AMBIENT_NPC_DRIVER_SEAT_RETRY_MS, 0, "d", npcid);
        }
    }
    return 1;
}

public AmbientNpc_DelayedDriverRestart(playerid)
{
    new index = AmbientNpc_FindByPlayer(playerid);

    if (index == -1 || gAmbientNpc[index][ambientKind] != AMBIENT_NPC_KIND_DRIVER)
    {
        return 1;
    }
    if (!IsPlayerConnected(playerid) || gAmbientNpcJailTime[index] > 0 || gAmbientNpcOrderedBy[index] != INVALID_PLAYER_ID)
    {
        return 1;
    }
    if (gAmbientNpcDriverRestartTick[index] > 0 && GetTickCount() + 50 < gAmbientNpcDriverRestartTick[index])
    {
        return 1;
    }
    if (
        gAmbientNpcVehicle[index] != INVALID_VEHICLE_ID &&
        GetVehicleModel(gAmbientNpcVehicle[index]) != 0 &&
        GetPlayerState(playerid) == PLAYER_STATE_DRIVER &&
        GetPlayerVehicleID(playerid) == gAmbientNpcVehicle[index]
    )
    {
        gAmbientNpcDriverRestartTick[index] = 0;
        gAmbientNpcDriverSeatAttempts[index] = 0;
        SendClientMessage(playerid, COLOR_WHITE, "NPC_CMD_RESTART");
        return 1;
    }
    if (
        gAmbientNpcVehicle[index] == INVALID_VEHICLE_ID ||
        GetVehicleModel(gAmbientNpcVehicle[index]) == 0
    )
    {
        AmbientNpc_CreateDriverVehicle(index);
    }
    if (
        gAmbientNpcVehicle[index] != INVALID_VEHICLE_ID &&
        GetVehicleModel(gAmbientNpcVehicle[index]) != 0
    )
    {
        AmbientNpc_EjectHumans(gAmbientNpcVehicle[index]);
        gAmbientNpcDriverSeatAttempts[index]++;
        if ((gAmbientNpcDriverSeatAttempts[index] % 4) == 0)
        {
            SetVehiclePos(gAmbientNpcVehicle[index], gAmbientNpc[index][ambientX], gAmbientNpc[index][ambientY], gAmbientNpc[index][ambientZ]);
            SetVehicleZAngle(gAmbientNpcVehicle[index], gAmbientNpc[index][ambientA]);
        }
        AmbientNpc_SetDriverVehReady(gAmbientNpcVehicle[index]);
        SetPlayerInterior(playerid, 0);
        SetPlayerVirtualWorld(playerid, 0);
        TogglePlayerControllable(playerid, 1);
        SetPlayerPos(playerid, gAmbientNpc[index][ambientX] + 2.0, gAmbientNpc[index][ambientY] + 2.0, gAmbientNpc[index][ambientZ] + 0.5);
        PutPlayerInVehicle(playerid, gAmbientNpcVehicle[index], 0);
        gAmbientNpcDriverRestartTick[index] = GetTickCount() + AMBIENT_NPC_DRIVER_SEAT_RETRY_MS;
        SetTimerEx("AmbientNpc_DelayedDriverRestart", AMBIENT_NPC_DRIVER_SEAT_RETRY_MS, 0, "d", playerid);
    }
    return 1;
}

public AmbientNpc_DelayedDriverSeat(playerid)
{
    new index = AmbientNpc_FindByPlayer(playerid);

    if (index == -1 || gAmbientNpc[index][ambientKind] != AMBIENT_NPC_KIND_DRIVER)
    {
        return 1;
    }
    AmbientNpc_ResetDriver(index, 1);
    return 1;
}

stock AmbientNpc_ConnectIndex(index)
{
    if (index < 0 || index >= AMBIENT_NPC_COUNT)
    {
        return 0;
    }
    if (gAmbientNpcPlayer[index] != INVALID_PLAYER_ID && IsPlayerConnected(gAmbientNpcPlayer[index]))
    {
        return 1;
    }
    ConnectNPC(gAmbientNpc[index][ambientName], gAmbientNpc[index][ambientScript]);
    return 1;
}

public AmbientNpc_DelayedConnect(index)
{
    AmbientNpc_ConnectIndex(index);
    return 1;
}

stock AmbientNpc_Init()
{
    new index;
    new detail[96];

    for (index = 0; index < AMBIENT_NPC_COUNT; index++)
    {
        gAmbientNpcPlayer[index] = INVALID_PLAYER_ID;
        gAmbientNpcVehicle[index] = INVALID_VEHICLE_ID;
        gAmbientNpcStopUntil[index] = 0;
        gAmbientNpcOrderedBy[index] = INVALID_PLAYER_ID;
        gAmbientNpcJailTime[index] = 0;
        gAmbientNpcJailCrimeId[index] = 0;
        gAmbientNpcWanted[index] = 0;
        gAmbientNpcCrimeIndex[index] = -1;
        gAmbientNpcCrimeExpireTick[index] = 0;
        gAmbientNpcCrimeLabel[index] = Text3D:INVALID_3DTEXT_ID;
        gAmbientNpcActionUntil[index] = 0;
        gAmbientNpcActionKind[index] = AMBIENT_NPC_ACTION_NONE;
        gAmbientNpcDriverRestartTick[index] = 0;
        gAmbientNpcDriverSeatAttempts[index] = 0;
        gAmbientNpcHealth[index] = 100.0;
        gAmbientNpcWeaponSlot[index] = index % sizeof(gAmbientNpcWeapons);
        AmbientNpc_ResetCombat(index);
        gAmbientNpcDeadUntil[index] = 0;
        gAmbientNpcRecoverUntil[index] = 0;
        gAmbientNpcLastDamager[index] = INVALID_PLAYER_ID;
        gAmbientNpcLastDamageTick[index] = 0;
        AmbientNpc_ScheduleNextAction(index, GetTickCount() + (index * 1200));

        if (gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_DRIVER)
        {
            AmbientNpc_CreateDriverVehicle(index);
        }

        SetTimerEx("AmbientNpc_DelayedConnect", AMBIENT_NPC_CONNECT_FIRST_MS + (index * AMBIENT_NPC_CONNECT_STEP_MS), 0, "d", index);
    }
    gAmbientNpcNextCrimeTick = GetTickCount() + AMBIENT_NPC_CRIME_FIRST_MS;
    gAmbientNpcNextFightTick = GetTickCount() + AMBIENT_NPC_FIGHT_MIN_MS;

    if (!gAmbientNpcTimer)
    {
        gAmbientNpcTimer = SetTimer("AmbientNpc_UpdateAll", 1000, 1);
    }

    format(detail, sizeof(detail), "configured=%d", AMBIENT_NPC_COUNT);
    WriteServerLog(LOG_ADMIN_FILE, "AMBIENT_NPC_INIT", detail);
    return 1;
}

stock AmbientNpc_Exit()
{
    new index;

    if (gAmbientNpcTimer)
    {
        KillTimer(gAmbientNpcTimer);
        gAmbientNpcTimer = 0;
    }

    for (index = 0; index < AMBIENT_NPC_COUNT; index++)
    {
        AmbientNpc_ClearCrime(index, 0);
        if (gAmbientNpcVehicle[index] != INVALID_VEHICLE_ID && GetVehicleModel(gAmbientNpcVehicle[index]) != 0)
        {
            DestroyVehicle(gAmbientNpcVehicle[index]);
        }
        gAmbientNpcVehicle[index] = INVALID_VEHICLE_ID;
        gAmbientNpcPlayer[index] = INVALID_PLAYER_ID;
        gAmbientNpcStopUntil[index] = 0;
        gAmbientNpcOrderedBy[index] = INVALID_PLAYER_ID;
        gAmbientNpcJailTime[index] = 0;
        gAmbientNpcJailCrimeId[index] = 0;
        gAmbientNpcWanted[index] = 0;
        gAmbientNpcCrimeIndex[index] = -1;
        gAmbientNpcCrimeExpireTick[index] = 0;
        gAmbientNpcActionUntil[index] = 0;
        gAmbientNpcNextAction[index] = 0;
        gAmbientNpcActionKind[index] = AMBIENT_NPC_ACTION_NONE;
        gAmbientNpcDriverRestartTick[index] = 0;
        gAmbientNpcDriverSeatAttempts[index] = 0;
        gAmbientNpcHealth[index] = 0.0;
        gAmbientNpcWeaponSlot[index] = 0;
        AmbientNpc_ResetCombat(index);
        gAmbientNpcDeadUntil[index] = 0;
        gAmbientNpcRecoverUntil[index] = 0;
        gAmbientNpcLastDamager[index] = INVALID_PLAYER_ID;
        gAmbientNpcLastDamageTick[index] = 0;
    }
    return 1;
}

stock AmbientNpc_OnConnect(playerid)
{
    new name[MAX_PLAYER_NAME + 1];
    new index;
    new detail[96];

    GetPlayerName(playerid, name, sizeof(name));
    index = AmbientNpc_FindByName(name);
    if (index == -1)
    {
        return 0;
    }

    gAmbientNpcPlayer[index] = playerid;
    gPlayerConnected[playerid] = 1;
    AmbientNpc_SetSpawnInfo(playerid, index);
    SetTimerEx("AmbientNpc_DelayedSpawn", 500 + (index * 850), 0, "d", playerid);
    format(detail, sizeof(detail), "name=%s kind=%d", name, gAmbientNpc[index][ambientKind]);
    WriteServerLog(LOG_ADMIN_FILE, "AMBIENT_NPC_CONNECT", detail);
    return 1;
}

public AmbientNpc_DelayedSpawn(playerid)
{
    if (IsPlayerConnected(playerid) && IsPlayerNPC(playerid) && AmbientNpc_FindByPlayer(playerid) != -1)
    {
        SpawnPlayer(playerid);
    }
    return 1;
}

stock AmbientNpc_OnDisconnect(playerid)
{
    new index = AmbientNpc_FindByPlayer(playerid);

    if (index != -1)
    {
        gAmbientNpcPlayer[index] = INVALID_PLAYER_ID;
        gAmbientNpcStopUntil[index] = 0;
        gAmbientNpcOrderedBy[index] = INVALID_PLAYER_ID;
        gAmbientNpcJailTime[index] = 0;
        gAmbientNpcJailCrimeId[index] = 0;
        AmbientNpc_ClearCrime(index, 0);
        gAmbientNpcActionUntil[index] = 0;
        gAmbientNpcActionKind[index] = AMBIENT_NPC_ACTION_NONE;
        gAmbientNpcNextAction[index] = 0;
        gAmbientNpcDriverRestartTick[index] = 0;
        gAmbientNpcDriverSeatAttempts[index] = 0;
        gAmbientNpcHealth[index] = 0.0;
        AmbientNpc_ResetCombat(index);
        gAmbientNpcDeadUntil[index] = 0;
        gAmbientNpcRecoverUntil[index] = 0;
        gAmbientNpcLastDamager[index] = INVALID_PLAYER_ID;
        gAmbientNpcLastDamageTick[index] = 0;
    }
    return 1;
}

stock AmbientNpc_OnRequestClass(playerid)
{
    new index = AmbientNpc_FindByPlayer(playerid);

    if (index == -1)
    {
        return 0;
    }
    AmbientNpc_SetSpawnInfo(playerid, index);
    return 1;
}

stock AmbientNpc_ReleaseOrderByIndex(index)
{
    new npcid;

    if (index < 0 || index >= AMBIENT_NPC_COUNT)
    {
        return 0;
    }

    npcid = gAmbientNpcPlayer[index];
    if (gAmbientNpcActionUntil[index] > 0)
    {
        AmbientNpc_StopAction(index, 0);
    }
    gAmbientNpcStopUntil[index] = 0;
    gAmbientNpcOrderedBy[index] = INVALID_PLAYER_ID;

    if (npcid != INVALID_PLAYER_ID && IsPlayerConnected(npcid))
    {
        if (gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_DRIVER)
        {
            AmbientNpc_ResetDriver(index, 1);
        }
        else
        {
            SendClientMessage(npcid, COLOR_WHITE, "NPC_CMD_RESUME");
            TogglePlayerControllable(npcid, 1);
            SetPlayerSpecialAction(npcid, SPECIAL_ACTION_NONE);
        }
    }
    return 1;
}

stock AmbientNpc_OrderStop(officerid, targetid)
{
    new index = AmbientNpc_FindByPlayer(targetid);
    new label[AMBIENT_NPC_LABEL_SIZE];
    new officerName[MAX_PLAYER_NAME + 1];
    new message[144];
    new detail[160];

    if (index == -1)
    {
        return 0;
    }

    gAmbientNpcStopUntil[index] = GetTickCount() + AMBIENT_NPC_STOP_MS;
    gAmbientNpcOrderedBy[index] = officerid;
    if (gAmbientNpcActionUntil[index] > 0)
    {
        AmbientNpc_StopAction(index, 0);
    }
    AmbientNpc_GetDisplayName(targetid, label, sizeof(label));
    GetPlayerNameEx(officerid, officerName, sizeof(officerName));

    SendClientMessage(targetid, COLOR_WHITE, "NPC_CMD_STOP");
    TogglePlayerControllable(targetid, 0);
    if (gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_PED)
    {
        ClearAnimations(targetid, 1);
        SetPlayerSpecialAction(targetid, SPECIAL_ACTION_HANDSUP);
    }

    format(message, sizeof(message), "%s (ID %d) recebeu ordem de parada por 30 segundos.", label, targetid);
    SendClientMessage(officerid, COLOR_GREEN, message);

    format(detail, sizeof(detail), "officer=%s officer_id=%d npc=%s npc_id=%d", officerName, officerid, label, targetid);
    WriteServerLog(LOG_ADMIN_FILE, "NPC_POLICE_ORDER", detail);
    return 1;
}

stock AmbientNpc_Cuff(officerid, targetid)
{
    new index = AmbientNpc_FindByPlayer(targetid);
    new label[AMBIENT_NPC_LABEL_SIZE];
    new message[128];

    if (index == -1)
    {
        return 0;
    }

    gAmbientNpcStopUntil[index] = 0;
    gAmbientNpcOrderedBy[index] = officerid;
    if (gAmbientNpcActionUntil[index] > 0)
    {
        AmbientNpc_StopAction(index, 0);
    }
    AmbientNpc_GetDisplayName(targetid, label, sizeof(label));
    SendClientMessage(targetid, COLOR_WHITE, "NPC_CMD_CUFF");
    TogglePlayerControllable(targetid, 0);
    SetPlayerSpecialAction(targetid, SPECIAL_ACTION_CUFFED);
    format(message, sizeof(message), "%s (ID %d) algemado e aguardando conducao.", label, targetid);
    SendClientMessage(officerid, COLOR_GREEN, message);
    return 1;
}

stock AmbientNpc_Uncuff(officerid, targetid)
{
    new index = AmbientNpc_FindByPlayer(targetid);
    new label[AMBIENT_NPC_LABEL_SIZE];
    new message[128];

    if (index == -1)
    {
        return 0;
    }

    if (gAmbientNpcJailTime[index] > 0)
    {
        SendClientMessage(officerid, COLOR_RED, "NPC esta preso. Use /soltar [id] para liberar a custodia.");
        return 1;
    }

    gAmbientNpcStopUntil[index] = 0;
    gAmbientNpcOrderedBy[index] = INVALID_PLAYER_ID;
    if (gAmbientNpcActionUntil[index] > 0)
    {
        AmbientNpc_StopAction(index, 0);
    }
    AmbientNpc_GetDisplayName(targetid, label, sizeof(label));
    if (gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_DRIVER)
    {
        AmbientNpc_ResetDriver(index, 1);
    }
    else
    {
        SendClientMessage(targetid, COLOR_WHITE, "NPC_CMD_RESUME");
        TogglePlayerControllable(targetid, 1);
        SetPlayerSpecialAction(targetid, SPECIAL_ACTION_NONE);
    }
    format(message, sizeof(message), "%s (ID %d) desalgemado e liberado.", label, targetid);
    SendClientMessage(officerid, COLOR_GREEN, message);
    return 1;
}

stock AmbientNpc_Arrest(officerid, targetid, crimeid, seconds, crimeName[])
{
    new index = AmbientNpc_FindByPlayer(targetid);
    new label[AMBIENT_NPC_LABEL_SIZE];
    new message[160];

    if (index == -1)
    {
        return 0;
    }

    if (seconds < JAIL_MIN_SECONDS)
    {
        seconds = JAIL_MIN_SECONDS;
    }

    gAmbientNpcStopUntil[index] = 0;
    gAmbientNpcJailTime[index] = seconds;
    gAmbientNpcJailCrimeId[index] = crimeid;
    gAmbientNpcOrderedBy[index] = officerid;
    AmbientNpc_ClearCrime(index, 0);
    if (gAmbientNpcActionUntil[index] > 0)
    {
        AmbientNpc_StopAction(index, 0);
    }
    AmbientNpc_GetDisplayName(targetid, label, sizeof(label));

    SendClientMessage(targetid, COLOR_WHITE, "NPC_CMD_JAIL");
    if (IsPlayerInAnyVehicle(targetid))
    {
        RemovePlayerFromVehicle(targetid);
    }
    TogglePlayerControllable(targetid, 0);
    SetPlayerSpecialAction(targetid, SPECIAL_ACTION_CUFFED);
    World_SendNpcToPoliceCell(targetid, index);

    format(message, sizeof(message), "%s (ID %d) preso por %d min | crime %d: %s.", label, targetid, seconds / 60, crimeid, crimeName);
    SendClientMessage(officerid, COLOR_GREEN, message);
    WriteServerLog(LOG_PUNISH_FILE, "NPC_ARREST", message);
    return 1;
}

stock AmbientNpc_ReleaseJailByIndex(index)
{
    new npcid;

    if (index < 0 || index >= AMBIENT_NPC_COUNT)
    {
        return 0;
    }

    npcid = gAmbientNpcPlayer[index];
    gAmbientNpcJailTime[index] = 0;
    gAmbientNpcJailCrimeId[index] = 0;
    gAmbientNpcStopUntil[index] = 0;
    gAmbientNpcOrderedBy[index] = INVALID_PLAYER_ID;
    AmbientNpc_ClearCrime(index, 0);
    gAmbientNpcActionUntil[index] = 0;
    gAmbientNpcActionKind[index] = AMBIENT_NPC_ACTION_NONE;
    AmbientNpc_ScheduleNextAction(index);

    if (npcid != INVALID_PLAYER_ID && IsPlayerConnected(npcid))
    {
        gPlayerInPoliceCell[npcid] = 0;
        if (gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_DRIVER)
        {
            AmbientNpc_ResetDriver(index, 1);
        }
        else
        {
            SetPlayerInterior(npcid, 0);
            SetPlayerVirtualWorld(npcid, 0);
            SetPlayerPos(npcid, gAmbientNpc[index][ambientX], gAmbientNpc[index][ambientY], gAmbientNpc[index][ambientZ]);
            SetPlayerFacingAngle(npcid, gAmbientNpc[index][ambientA]);
            TogglePlayerControllable(npcid, 1);
            SetPlayerSpecialAction(npcid, SPECIAL_ACTION_NONE);
            SendClientMessage(npcid, COLOR_WHITE, "NPC_CMD_RESTART");
        }
    }
    return 1;
}

stock AmbientNpc_ReleaseFromJail(officerid, targetid)
{
    new index = AmbientNpc_FindByPlayer(targetid);
    new label[AMBIENT_NPC_LABEL_SIZE];
    new message[128];

    if (index == -1)
    {
        return 0;
    }

    AmbientNpc_GetDisplayName(targetid, label, sizeof(label));
    AmbientNpc_ReleaseJailByIndex(index);
    format(message, sizeof(message), "%s (ID %d) liberado da custodia.", label, targetid);
    SendClientMessage(officerid, COLOR_GREEN, message);
    WriteServerLog(LOG_PUNISH_FILE, "NPC_RELEASE", message);
    return 1;
}

public AmbientNpc_UpdateAll()
{
    new index;
    new tick = GetTickCount();
    new npcid;

    AmbientNpc_UpdateCrimeSystem(tick);
    AmbientNpc_UpdateCombat(tick);

    if (tick >= gAmbientNpcNextFightTick)
    {
        AmbientNpc_StartRandomFight(tick);
    }

    for (index = 0; index < AMBIENT_NPC_COUNT; index++)
    {
        if (gAmbientNpcDeadUntil[index] > 0)
        {
            continue;
        }

        if (gAmbientNpcRecoverUntil[index] > 0)
        {
            if (tick >= gAmbientNpcRecoverUntil[index])
            {
                gAmbientNpcRecoverUntil[index] = 0;
                AmbientNpc_ResetPed(index, 1);
            }
            continue;
        }

        if (gAmbientNpcJailTime[index] > 0)
        {
            gAmbientNpcJailTime[index]--;
            if (gAmbientNpcJailTime[index] <= 0)
            {
                AmbientNpc_ReleaseJailByIndex(index);
                continue;
            }
            npcid = gAmbientNpcPlayer[index];
            if (npcid != INVALID_PLAYER_ID && IsPlayerConnected(npcid) && (gAmbientNpcJailTime[index] % 10) == 0)
            {
                World_SendNpcToPoliceCell(npcid, index);
            }
        }

        if (gAmbientNpcStopUntil[index] > 0 && tick >= gAmbientNpcStopUntil[index])
        {
            AmbientNpc_ReleaseOrderByIndex(index);
        }

        if (gAmbientNpcActionUntil[index] > 0)
        {
            if (tick >= gAmbientNpcActionUntil[index])
            {
                AmbientNpc_StopAction(index, 1);
            }
            continue;
        }

        if (
            gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_DRIVER &&
            gAmbientNpcJailTime[index] <= 0 &&
            gAmbientNpcOrderedBy[index] == INVALID_PLAYER_ID &&
            gAmbientNpcPlayer[index] != INVALID_PLAYER_ID &&
            IsPlayerConnected(gAmbientNpcPlayer[index])
        )
        {
            npcid = gAmbientNpcPlayer[index];
            if (
                gAmbientNpcVehicle[index] == INVALID_VEHICLE_ID ||
                GetVehicleModel(gAmbientNpcVehicle[index]) == 0 ||
                GetPlayerState(npcid) != PLAYER_STATE_DRIVER ||
                GetPlayerVehicleID(npcid) != gAmbientNpcVehicle[index]
            )
            {
                AmbientNpc_ResetDriver(index, 1);
            }
        }

        if (
            gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_PED &&
            gAmbientNpcJailTime[index] <= 0 &&
            gAmbientNpcStopUntil[index] <= 0 &&
            gAmbientNpcAttackTarget[index] == INVALID_PLAYER_ID &&
            gAmbientNpcPlayer[index] != INVALID_PLAYER_ID &&
            IsPlayerConnected(gAmbientNpcPlayer[index]) &&
            tick >= gAmbientNpcNextAction[index]
        )
        {
            AmbientNpc_StartAction(index, tick);
        }
    }
    return 1;
}

stock AmbientNpc_OnRequestSpawn(playerid)
{
    return AmbientNpc_FindByPlayer(playerid) != -1;
}

stock AmbientNpc_OnSpawn(playerid)
{
    new index = AmbientNpc_FindByPlayer(playerid);

    if (index == -1)
    {
        return 0;
    }

    if (gAmbientNpcJailTime[index] > 0)
    {
        World_SendNpcToPoliceCell(playerid, index);
        return 1;
    }

    if (gAmbientNpcDeadUntil[index] > 0)
    {
        AmbientNpc_SpawnAtHospital(index);
        return 1;
    }

    if (gAmbientNpcRecoverUntil[index] > 0)
    {
        AmbientNpc_SpawnAtHospital(index);
        return 1;
    }

    if (gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_PED)
    {
        AmbientNpc_ResetPed(index, 0);
        return 1;
    }

    if (gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_DRIVER)
    {
        SetPlayerInterior(playerid, 0);
        SetPlayerVirtualWorld(playerid, 0);
        SetPlayerPos(playerid, gAmbientNpc[index][ambientX] + 4.0, gAmbientNpc[index][ambientY] + 4.0, gAmbientNpc[index][ambientZ] + 0.5);
        TogglePlayerControllable(playerid, 1);
        SetTimerEx("AmbientNpc_DelayedDriverSeat", 350, 0, "d", playerid);
    }
    return 1;
}

stock AmbientNpc_OnDeath(playerid, killerid, reason)
{
    new index = AmbientNpc_FindByPlayer(playerid);

    if (index == -1)
    {
        return 0;
    }

    AmbientNpc_Kill(index, killerid, reason);
    return 1;
}

stock AmbientNpc_OnGiveDamage(playerid, damagedid, Float:amount, weaponid)
{
    new index = AmbientNpc_FindByPlayer(damagedid);

    if (index == -1)
    {
        return 0;
    }

    AmbientNpc_Damage(index, amount, playerid, weaponid);
    return 1;
}

stock AmbientNpc_OnStateChange(playerid, newstate)
{
    new index = AmbientNpc_FindByPlayer(playerid);

    if (index == -1)
    {
        return 0;
    }

    if (gAmbientNpcJailTime[index] > 0)
    {
        World_SendNpcToPoliceCell(playerid, index);
        return 1;
    }

    if (gAmbientNpc[index][ambientKind] == AMBIENT_NPC_KIND_DRIVER && newstate != PLAYER_STATE_DRIVER)
    {
        AmbientNpc_ResetDriver(index, 1);
    }
    return 1;
}

stock AmbientNpc_OnHumanEnterVehicle(playerid, vehicleid)
{
    if (AmbientNpc_IsDriverVehicle(vehicleid))
    {
        RemovePlayerFromVehicle(playerid);
        ClearAnimations(playerid, 1);
        SendClientMessage(playerid, COLOR_GRAY, "Este veiculo e controlado por NPCs do servidor.");
        return 1;
    }
    return 0;
}

stock AmbientNpc_OnHumanStateChange(playerid, newstate)
{
    new vehicleid;

    if (newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
    {
        vehicleid = GetPlayerVehicleID(playerid);
        if (AmbientNpc_IsDriverVehicle(vehicleid))
        {
            RemovePlayerFromVehicle(playerid);
            ClearAnimations(playerid, 1);
            SendClientMessage(playerid, COLOR_GRAY, "Este veiculo e controlado por NPCs do servidor.");
            AmbientNpc_SetDriverVehReady(vehicleid);
            return 1;
        }
    }
    return 0;
}
