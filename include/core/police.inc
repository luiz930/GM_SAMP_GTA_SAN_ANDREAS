#if defined _nova_police_included
    #endinput
#endif
#define _nova_police_included

#define MAX_POLICE_BLITZ            (24)
#define POLICE_BLITZ_OBJECTS        (9)
#define POLICE_BLITZ_RANGE          (18.0)
#define POLICE_ID_MAX_LABELS        (32)
#define POLICE_ID_DRAW_DISTANCE     (38.0)
#define POLICE_ID_UPDATE_INTERVAL   (2000)
#define POLICE_CRIME_COUNT          (10)
#define POLICE_CRIME_ARTICLE_SIZE   (16)
#define POLICE_CRIME_NAME_SIZE      (64)
#define POLICE_JUSTICE_STATUS_RESOLVED (4)
#define POLICE_SEARCH_DIALOG_SIZE   (2200)
#define POLICE_SEARCH_LINE_SIZE     (192)
#define POLICE_SEARCH_INV_MAX_ROWS  (8)
#define POLICE_SEARCH_WEAPON_MAX_ROWS (8)
#define POLICE_FISCAL_POSTS         (4)
#define POLICE_FISCAL_OBJECTS       (3)
#define POLICE_FISCAL_RANGE         (32.0)
#define POLICE_FISCAL_DRIVER_RANGE  (24.0)
#define POLICE_DETECTOR_COOLDOWN_MS (60000)
#define POLICE_DETECTOR_PREF        (1)
#define POLICE_DETECTOR_JUSTICE     (2)

enum ePoliceFiscalPost
{
    fiscalName[40],
    Float:fiscalX,
    Float:fiscalY,
    Float:fiscalZ,
    Float:fiscalA
}

new gPoliceFiscalPosts[POLICE_FISCAL_POSTS][ePoliceFiscalPost] =
{
    { "Posto Fiscal PRF Dillimore", 1208.6000, -323.2000, 42.1000, 180.0 },
    { "Posto Fiscal PRF Flint", -81.8000, -1157.4000, 2.1000, 90.0 },
    { "Posto Fiscal PRF Bone County", 1699.8000, 713.5000, 10.8000, 90.0 },
    { "Posto Fiscal PRF Garver", -1388.4000, 452.1000, 7.2000, 270.0 }
};

new gPoliceTimer;
new gPoliceIdTimer;
new gPoliceBlitzActive[MAX_POLICE_BLITZ];
new gPoliceBlitzCreator[MAX_POLICE_BLITZ];
new Float:gPoliceBlitzX[MAX_POLICE_BLITZ];
new Float:gPoliceBlitzY[MAX_POLICE_BLITZ];
new Float:gPoliceBlitzZ[MAX_POLICE_BLITZ];
new Float:gPoliceBlitzA[MAX_POLICE_BLITZ];
new gPoliceBlitzObject[MAX_POLICE_BLITZ][POLICE_BLITZ_OBJECTS];
new Text3D:gPoliceBlitzLabel[MAX_POLICE_BLITZ];
new gPlayerBlitzDialog[MAX_PLAYERS];
new PlayerText3D:gPoliceIdLabel[MAX_PLAYERS][POLICE_ID_MAX_LABELS];
new gPoliceIdLabelTarget[MAX_PLAYERS][POLICE_ID_MAX_LABELS];
new gPoliceCuffed[MAX_PLAYERS];
new gPoliceCuffedBy[MAX_PLAYERS];
new gPolicePendingArrestTarget[MAX_PLAYERS];
new gPoliceDetectorZone[MAX_PLAYERS];
new gPoliceDetectorTick[MAX_PLAYERS];
new Text3D:gPoliceFiscalLabel[POLICE_FISCAL_POSTS];
new gPoliceFiscalObject[POLICE_FISCAL_POSTS][POLICE_FISCAL_OBJECTS];

enum ePoliceCrimeData
{
    policeCrimeId,
    policeCrimeArticle[POLICE_CRIME_ARTICLE_SIZE],
    policeCrimeName[POLICE_CRIME_NAME_SIZE],
    policeCrimeMinutes,
    policeCrimeWanted,
    policeCrimeFine
}

new gPoliceCrimes[][ePoliceCrimeData] =
{
    { 1, "Art. 4-A", "Roubo, furto ou receptacao", 15, 2, 600 },
    { 2, "Art. 4-B", "Homicidio, tentativa ou latrocinio", 30, 5, 1500 },
    { 3, "Art. 5", "Fraude, lavagem ou desvio de dinheiro", 25, 4, 2500 },
    { 4, "Art. 6-A", "Contrabando ou descaminho", 20, 3, 1200 },
    { 5, "Art. 6-B", "Trafico ou transporte de produto ilegal", 25, 4, 1800 },
    { 6, "Art. 7-A", "Corrupcao, desacato ou obstrucao", 15, 2, 900 },
    { 7, "Art. 7-B", "Falso documento ou falsa identidade", 20, 3, 1200 },
    { 8, "Art. 8-A", "Fuga ou desobediencia a abordagem", 10, 2, 700 },
    { 9, "Art. 8-B", "Porte ilegal, ameaca ou resistencia", 20, 3, 1100 },
    { 10, "Art. 10", "Exploit, farm grave ou dinheiro irregular", 40, 6, 5000 }
};

enum eBlitzFineData
{
    blitzFineReason[48],
    blitzFineSeverity,
    blitzFineMultiplier
}

new gBlitzFines[][eBlitzFineData] =
{
    { "Sem CNH", TRAFFIC_FINE_VERY_SERIOUS, 3 },
    { "CRLV/documento irregular", TRAFFIC_FINE_SERIOUS, 1 },
    { "IPVA/licenciamento vencido", TRAFFIC_FINE_SERIOUS, 1 },
    { "Veiculo sem seguro", TRAFFIC_FINE_MEDIUM, 1 },
    { "Fuga/desobediencia", TRAFFIC_FINE_VERY_SERIOUS, 3 },
    { "Direcao perigosa", TRAFFIC_FINE_VERY_SERIOUS, 5 },
    { "Alcool/drogas na direcao", TRAFFIC_FINE_VERY_SERIOUS, 10 },
    { "Racha/disputa", TRAFFIC_FINE_VERY_SERIOUS, 10 },
    { "Ultrapassagem proibida", TRAFFIC_FINE_VERY_SERIOUS, 5 }
};

forward Police_UpdateAll();
forward Police_UpdateIdLabelsAll();

stock Police_Init()
{
    new index;
    new playerid;
    new slot;
    new label[144];

    for (index = 0; index < MAX_POLICE_BLITZ; index++)
    {
        gPoliceBlitzActive[index] = 0;
        gPoliceBlitzCreator[index] = INVALID_PLAYER_ID;
        gPoliceBlitzLabel[index] = Text3D:INVALID_3DTEXT_ID;
    }

    for (playerid = 0; playerid < MAX_PLAYERS; playerid++)
    {
        gPoliceCuffed[playerid] = 0;
        gPoliceCuffedBy[playerid] = INVALID_PLAYER_ID;
        gPolicePendingArrestTarget[playerid] = INVALID_PLAYER_ID;
        gPoliceDetectorZone[playerid] = 0;
        gPoliceDetectorTick[playerid] = 0;

        for (slot = 0; slot < POLICE_ID_MAX_LABELS; slot++)
        {
            gPoliceIdLabel[playerid][slot] = PlayerText3D:INVALID_3DTEXT_ID;
            gPoliceIdLabelTarget[playerid][slot] = INVALID_PLAYER_ID;
        }
    }

    for (index = 0; index < POLICE_FISCAL_POSTS; index++)
    {
        format(label, sizeof(label), "%s\nPosto fiscal rodoviario\nPRF: /postofiscal /fiscalizar /fiscalizarcarga", gPoliceFiscalPosts[index][fiscalName]);
        gPoliceFiscalLabel[index] = Create3DTextLabel(label, COLOR_ADMIN, gPoliceFiscalPosts[index][fiscalX], gPoliceFiscalPosts[index][fiscalY], gPoliceFiscalPosts[index][fiscalZ] + 1.2, 35.0, 0, 0);
        gPoliceFiscalObject[index][0] = CreateObject(1422, gPoliceFiscalPosts[index][fiscalX] + 2.5, gPoliceFiscalPosts[index][fiscalY], gPoliceFiscalPosts[index][fiscalZ] - 0.6, 0.0, 0.0, gPoliceFiscalPosts[index][fiscalA], 80.0);
        gPoliceFiscalObject[index][1] = CreateObject(1422, gPoliceFiscalPosts[index][fiscalX] - 2.5, gPoliceFiscalPosts[index][fiscalY], gPoliceFiscalPosts[index][fiscalZ] - 0.6, 0.0, 0.0, gPoliceFiscalPosts[index][fiscalA], 80.0);
        gPoliceFiscalObject[index][2] = CreateObject(1238, gPoliceFiscalPosts[index][fiscalX], gPoliceFiscalPosts[index][fiscalY], gPoliceFiscalPosts[index][fiscalZ] - 0.7, 0.0, 0.0, gPoliceFiscalPosts[index][fiscalA], 80.0);
    }

    if (!gPoliceIdTimer)
    {
        gPoliceIdTimer = SetTimer("Police_UpdateIdLabelsAll", POLICE_ID_UPDATE_INTERVAL, 1);
    }
    return 1;
}

stock Police_ResetPlayer(playerid)
{
    gPoliceCuffed[playerid] = 0;
    gPoliceCuffedBy[playerid] = INVALID_PLAYER_ID;
    gPolicePendingArrestTarget[playerid] = INVALID_PLAYER_ID;
    return 1;
}

stock Police_IsOfficer(playerid)
{
    return IsLawEnforcementJob(PlayerInfo[playerid][pJob]);
}

stock Police_CanManageBlitz(playerid)
{
    return Police_IsOfficer(playerid);
}

stock Police_CanCreatePrfBarrier(playerid)
{
    return (PlayerInfo[playerid][pJob] == JOB_PRF);
}

stock Police_CanUseCustody(playerid)
{
    return IsLawEnforcementJob(PlayerInfo[playerid][pJob]);
}

stock Police_GetCrimeIndexById(crimeid)
{
    new index;

    for (index = 0; index < sizeof(gPoliceCrimes); index++)
    {
        if (gPoliceCrimes[index][policeCrimeId] == crimeid)
        {
            return index;
        }
    }
    return -1;
}

stock Police_GetCrimeName(crimeid, output[], size = sizeof(output))
{
    new index = Police_GetCrimeIndexById(crimeid);

    if (index == -1)
    {
        format(output, size, "Crime nao informado");
        return 0;
    }

    format(output, size, "%s", gPoliceCrimes[index][policeCrimeName]);
    return 1;
}

stock Police_FormatJailTime(seconds, output[], size = sizeof(output))
{
    if (seconds < 0)
    {
        seconds = 0;
    }
    format(output, size, "%02d:%02d", seconds / 60, seconds % 60);
    return 1;
}

stock Police_BuildCrimeList(output[], size = sizeof(output))
{
    new index;
    new line[144];

    format(output, size, "ID/Artigo\tCrime\tPena\n");
    for (index = 0; index < sizeof(gPoliceCrimes); index++)
    {
        format(line, sizeof(line), "%d %s\t%s\t%d min\n",
            gPoliceCrimes[index][policeCrimeId],
            gPoliceCrimes[index][policeCrimeArticle],
            gPoliceCrimes[index][policeCrimeName],
            gPoliceCrimes[index][policeCrimeMinutes]
        );
        strcat(output, line, size);
    }
    return 1;
}

stock Police_AppendConstitutionCrimes(body[], size = sizeof(body))
{
    new index;
    new line[160];

    strcat(body, "\nCODIGO PENAL RP - PRISAO MINIMA 10 MIN\n", size);
    for (index = 0; index < sizeof(gPoliceCrimes); index++)
    {
        format(line, sizeof(line), "ID %d | %s | %s | pena %d min | multa base $%d\n",
            gPoliceCrimes[index][policeCrimeId],
            gPoliceCrimes[index][policeCrimeArticle],
            gPoliceCrimes[index][policeCrimeName],
            gPoliceCrimes[index][policeCrimeMinutes],
            gPoliceCrimes[index][policeCrimeFine]
        );
        strcat(body, line, size);
    }
    return 1;
}

stock Police_AppendLawCrimeRows(list[], size = sizeof(list))
{
    new index;
    new line[168];

    for (index = 0; index < sizeof(gPoliceCrimes); index++)
    {
        format(line, sizeof(line), "Crime %d - %s\t%s\t%d min / multa $%d\n",
            gPoliceCrimes[index][policeCrimeId],
            gPoliceCrimes[index][policeCrimeArticle],
            gPoliceCrimes[index][policeCrimeName],
            gPoliceCrimes[index][policeCrimeMinutes],
            gPoliceCrimes[index][policeCrimeFine]
        );
        strcat(list, line, size);
    }
    return 1;
}

stock Police_CanSeeIdLabels(playerid)
{
    if (!IsValidConnectedPlayer(playerid) || IsPlayerNPC(playerid) || !PlayerInfo[playerid][pLogged])
    {
        return 0;
    }

    return (IsPublicSecurityJob(PlayerInfo[playerid][pJob]) || HasAdminLevel(playerid, ADMIN_LEVEL_HELPER));
}

stock Police_DestroyIdLabelSlot(playerid, slot)
{
    if (slot < 0 || slot >= POLICE_ID_MAX_LABELS)
    {
        return 0;
    }

    if (gPoliceIdLabel[playerid][slot] != PlayerText3D:INVALID_3DTEXT_ID)
    {
        DeletePlayer3DTextLabel(playerid, gPoliceIdLabel[playerid][slot]);
    }

    gPoliceIdLabel[playerid][slot] = PlayerText3D:INVALID_3DTEXT_ID;
    gPoliceIdLabelTarget[playerid][slot] = INVALID_PLAYER_ID;
    return 1;
}

stock Police_DestroyIdLabelsFor(playerid)
{
    new slot;

    for (slot = 0; slot < POLICE_ID_MAX_LABELS; slot++)
    {
        Police_DestroyIdLabelSlot(playerid, slot);
    }
    return 1;
}

stock Police_DestroyIdLabelsForTarget(targetid)
{
    new playerid;
    new slot;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        for (slot = 0; slot < POLICE_ID_MAX_LABELS; slot++)
        {
            if (gPoliceIdLabelTarget[playerid][slot] == targetid)
            {
                Police_DestroyIdLabelSlot(playerid, slot);
            }
        }
    }
    return 1;
}

stock Police_DestroyAllIdLabels()
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        Police_DestroyIdLabelsFor(playerid);
    }
    return 1;
}

stock Police_FindIdLabelSlot(playerid, targetid)
{
    new slot;

    for (slot = 0; slot < POLICE_ID_MAX_LABELS; slot++)
    {
        if (gPoliceIdLabelTarget[playerid][slot] == targetid)
        {
            return slot;
        }
    }
    return -1;
}

stock Police_FindFreeIdLabelSlot(playerid)
{
    new slot;

    for (slot = 0; slot < POLICE_ID_MAX_LABELS; slot++)
    {
        if (gPoliceIdLabelTarget[playerid][slot] == INVALID_PLAYER_ID)
        {
            return slot;
        }
    }
    return -1;
}

stock Police_IsIdLabelTargetVisible(playerid, targetid)
{
    new Float:x;
    new Float:y;
    new Float:z;

    if (targetid == playerid || !IsValidConnectedPlayer(targetid))
    {
        return 0;
    }

    if (GetPlayerInterior(playerid) != GetPlayerInterior(targetid) || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(targetid))
    {
        return 0;
    }

    if (IsPlayerNPC(targetid))
    {
        if (!AmbientNpc_IsManaged(targetid))
        {
            return 0;
        }
    }
    else if (!PlayerInfo[targetid][pLogged])
    {
        return 0;
    }

    GetPlayerPos(targetid, x, y, z);
    return IsPlayerInRangeOfPoint(playerid, POLICE_ID_DRAW_DISTANCE, x, y, z);
}

stock Police_FormatIdLabel(targetid, output[], size = sizeof(output))
{
    new label[AMBIENT_NPC_LABEL_SIZE];
    new name[MAX_PLAYER_NAME + 1];

    if (IsPlayerNPC(targetid) && AmbientNpc_IsManaged(targetid))
    {
        AmbientNpc_GetDisplayName(targetid, label, sizeof(label));
        format(output, size, "NPC ID %d\n%s", targetid, label);
        return 1;
    }

    GetPlayerNameEx(targetid, name, sizeof(name));
    format(output, size, "ID %d\n%s", targetid, name);
    return 1;
}

stock Police_EnsureIdLabel(playerid, targetid)
{
    new slot = Police_FindIdLabelSlot(playerid, targetid);
    new text[80];

    if (slot == -1)
    {
        slot = Police_FindFreeIdLabelSlot(playerid);
        if (slot == -1)
        {
            return 0;
        }
        gPoliceIdLabelTarget[playerid][slot] = targetid;
    }

    Police_FormatIdLabel(targetid, text, sizeof(text));
    if (gPoliceIdLabel[playerid][slot] == PlayerText3D:INVALID_3DTEXT_ID)
    {
        gPoliceIdLabel[playerid][slot] = CreatePlayer3DTextLabel(playerid, text, COLOR_YELLOW, 0.0, 0.0, 0.65, POLICE_ID_DRAW_DISTANCE, targetid, INVALID_VEHICLE_ID, 1);
    }
    else
    {
        UpdatePlayer3DTextLabelText(playerid, gPoliceIdLabel[playerid][slot], COLOR_YELLOW, text);
    }
    return 1;
}

stock Police_UpdateIdLabelsFor(playerid)
{
    new slot;
    new targetid;
    new maxPlayers = GetMaxPlayers();

    if (!Police_CanSeeIdLabels(playerid))
    {
        Police_DestroyIdLabelsFor(playerid);
        return 1;
    }

    for (slot = 0; slot < POLICE_ID_MAX_LABELS; slot++)
    {
        targetid = gPoliceIdLabelTarget[playerid][slot];
        if (targetid != INVALID_PLAYER_ID && !Police_IsIdLabelTargetVisible(playerid, targetid))
        {
            Police_DestroyIdLabelSlot(playerid, slot);
        }
    }

    for (targetid = 0; targetid < maxPlayers; targetid++)
    {
        if (Police_IsIdLabelTargetVisible(playerid, targetid))
        {
            Police_EnsureIdLabel(playerid, targetid);
        }
    }
    return 1;
}

stock Police_DestroyBlitz(blitzid)
{
    new index;

    if (blitzid < 0 || blitzid >= MAX_POLICE_BLITZ || !gPoliceBlitzActive[blitzid])
    {
        return 0;
    }

    for (index = 0; index < POLICE_BLITZ_OBJECTS; index++)
    {
        if (gPoliceBlitzObject[blitzid][index] != 0 && IsValidObject(gPoliceBlitzObject[blitzid][index]))
        {
            DestroyObject(gPoliceBlitzObject[blitzid][index]);
        }
        gPoliceBlitzObject[blitzid][index] = 0;
    }

    if (gPoliceBlitzLabel[blitzid] != Text3D:INVALID_3DTEXT_ID)
    {
        Delete3DTextLabel(gPoliceBlitzLabel[blitzid]);
        gPoliceBlitzLabel[blitzid] = Text3D:INVALID_3DTEXT_ID;
    }

    gPoliceBlitzActive[blitzid] = 0;
    gPoliceBlitzCreator[blitzid] = INVALID_PLAYER_ID;
    return 1;
}

stock Police_DestroyAllBlitz()
{
    new blitzid;
    new index;
    new objectid;

    for (blitzid = 0; blitzid < MAX_POLICE_BLITZ; blitzid++)
    {
        Police_DestroyBlitz(blitzid);
    }
    for (index = 0; index < POLICE_FISCAL_POSTS; index++)
    {
        if (gPoliceFiscalLabel[index] != Text3D:INVALID_3DTEXT_ID)
        {
            Delete3DTextLabel(gPoliceFiscalLabel[index]);
            gPoliceFiscalLabel[index] = Text3D:INVALID_3DTEXT_ID;
        }
        for (objectid = 0; objectid < POLICE_FISCAL_OBJECTS; objectid++)
        {
            if (gPoliceFiscalObject[index][objectid] != 0 && IsValidObject(gPoliceFiscalObject[index][objectid]))
            {
                DestroyObject(gPoliceFiscalObject[index][objectid]);
            }
            gPoliceFiscalObject[index][objectid] = 0;
        }
    }
    return 1;
}

stock Police_DestroyPlayerBlitz(playerid)
{
    new blitzid;
    new removed;

    for (blitzid = 0; blitzid < MAX_POLICE_BLITZ; blitzid++)
    {
        if (gPoliceBlitzActive[blitzid] && gPoliceBlitzCreator[blitzid] == playerid)
        {
            if (Police_DestroyBlitz(blitzid))
            {
                removed++;
            }
        }
    }
    return removed;
}

stock Police_DestroyNearestBlitz(playerid)
{
    new blitzid = Police_FindNearestBlitz(playerid, POLICE_BLITZ_RANGE);

    if (blitzid == -1)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Chegue perto da blitz que deseja remover.");
        return 0;
    }

    if (gPoliceBlitzCreator[blitzid] != playerid)
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas quem criou esta blitz pode remover.");
        return 0;
    }

    Police_DestroyBlitz(blitzid);
    SendClientMessage(playerid, COLOR_GREEN, "Blitz proxima removida.");
    return 1;
}

stock Police_FindFreeBlitzSlot()
{
    new blitzid;

    for (blitzid = 0; blitzid < MAX_POLICE_BLITZ; blitzid++)
    {
        if (!gPoliceBlitzActive[blitzid])
        {
            return blitzid;
        }
    }
    return -1;
}

stock Police_FindNearestBlitz(playerid, Float:range = POLICE_BLITZ_RANGE)
{
    new blitzid;
    new nearest = -1;
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:distance;
    new Float:best = 999999.0;

    GetPlayerPos(playerid, x, y, z);
    for (blitzid = 0; blitzid < MAX_POLICE_BLITZ; blitzid++)
    {
        if (!gPoliceBlitzActive[blitzid])
        {
            continue;
        }

        if (!IsPlayerInRangeOfPoint(playerid, range, gPoliceBlitzX[blitzid], gPoliceBlitzY[blitzid], gPoliceBlitzZ[blitzid]))
        {
            continue;
        }

        distance = floatsqroot(floatpower(x - gPoliceBlitzX[blitzid], 2.0) + floatpower(y - gPoliceBlitzY[blitzid], 2.0) + floatpower(z - gPoliceBlitzZ[blitzid], 2.0));
        if (distance < best)
        {
            best = distance;
            nearest = blitzid;
        }
    }
    return nearest;
}

stock Police_CreateBlitz(playerid)
{
    new blitzid;
    new message[144];
    new Float:forwardX;
    new Float:forwardY;
    new Float:rightX;
    new Float:rightY;
    new Float:x;
    new Float:y;
    new Float:z;

    if (!Police_CanManageBlitz(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policiais podem criar blitz.");
        return 1;
    }

    if (GetPlayerInterior(playerid) != 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Crie blitz apenas em area externa.");
        return 1;
    }

    blitzid = Police_FindFreeBlitzSlot();
    if (blitzid == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Limite de blitz ativas atingido.");
        return 1;
    }

    GetPlayerPos(playerid, gPoliceBlitzX[blitzid], gPoliceBlitzY[blitzid], gPoliceBlitzZ[blitzid]);
    GetPlayerFacingAngle(playerid, gPoliceBlitzA[blitzid]);
    forwardX = floatsin(-gPoliceBlitzA[blitzid], degrees);
    forwardY = floatcos(-gPoliceBlitzA[blitzid], degrees);
    rightX = floatcos(-gPoliceBlitzA[blitzid], degrees);
    rightY = -floatsin(-gPoliceBlitzA[blitzid], degrees);

    gPoliceBlitzActive[blitzid] = 1;
    gPoliceBlitzCreator[blitzid] = playerid;

    x = gPoliceBlitzX[blitzid] + (rightX * -3.4);
    y = gPoliceBlitzY[blitzid] + (rightY * -3.4);
    z = gPoliceBlitzZ[blitzid] - 0.6;
    gPoliceBlitzObject[blitzid][0] = CreateObject(1422, x, y, z, 0.0, 0.0, gPoliceBlitzA[blitzid]);

    x = gPoliceBlitzX[blitzid];
    y = gPoliceBlitzY[blitzid];
    gPoliceBlitzObject[blitzid][1] = CreateObject(1422, x, y, z, 0.0, 0.0, gPoliceBlitzA[blitzid]);

    x = gPoliceBlitzX[blitzid] + (rightX * 3.4);
    y = gPoliceBlitzY[blitzid] + (rightY * 3.4);
    gPoliceBlitzObject[blitzid][2] = CreateObject(1422, x, y, z, 0.0, 0.0, gPoliceBlitzA[blitzid]);

    gPoliceBlitzObject[blitzid][3] = CreateObject(1238, gPoliceBlitzX[blitzid] + (rightX * -5.8) + (forwardX * -2.2), gPoliceBlitzY[blitzid] + (rightY * -5.8) + (forwardY * -2.2), gPoliceBlitzZ[blitzid] - 0.7, 0.0, 0.0, gPoliceBlitzA[blitzid]);
    gPoliceBlitzObject[blitzid][4] = CreateObject(1238, gPoliceBlitzX[blitzid] + (rightX * 5.8) + (forwardX * -2.2), gPoliceBlitzY[blitzid] + (rightY * 5.8) + (forwardY * -2.2), gPoliceBlitzZ[blitzid] - 0.7, 0.0, 0.0, gPoliceBlitzA[blitzid]);
    gPoliceBlitzObject[blitzid][5] = CreateObject(1238, gPoliceBlitzX[blitzid] + (rightX * -5.8) + (forwardX * 2.2), gPoliceBlitzY[blitzid] + (rightY * -5.8) + (forwardY * 2.2), gPoliceBlitzZ[blitzid] - 0.7, 0.0, 0.0, gPoliceBlitzA[blitzid]);
    gPoliceBlitzObject[blitzid][6] = CreateObject(1238, gPoliceBlitzX[blitzid] + (rightX * 5.8) + (forwardX * 2.2), gPoliceBlitzY[blitzid] + (rightY * 5.8) + (forwardY * 2.2), gPoliceBlitzZ[blitzid] - 0.7, 0.0, 0.0, gPoliceBlitzA[blitzid]);
    gPoliceBlitzObject[blitzid][7] = CreateObject(1238, gPoliceBlitzX[blitzid] + (forwardX * -6.0), gPoliceBlitzY[blitzid] + (forwardY * -6.0), gPoliceBlitzZ[blitzid] - 0.7, 0.0, 0.0, gPoliceBlitzA[blitzid]);
    gPoliceBlitzObject[blitzid][8] = CreateObject(1238, gPoliceBlitzX[blitzid] + (forwardX * 6.0), gPoliceBlitzY[blitzid] + (forwardY * 6.0), gPoliceBlitzZ[blitzid] - 0.7, 0.0, 0.0, gPoliceBlitzA[blitzid]);
    gPoliceBlitzLabel[blitzid] = Create3DTextLabel("BLITZ POLICIAL\nAperte ENTER ou use /blitz\nPare, apresente CNH e documentos", COLOR_ADMIN, gPoliceBlitzX[blitzid], gPoliceBlitzY[blitzid], gPoliceBlitzZ[blitzid] + 1.2, 35.0, 0, 1);

    format(message, sizeof(message), "Blitz criada. ID %d | voce pode criar outras barreiras com /criarblitz.", blitzid + 1);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_ADMIN_FILE, "CREATE_BLITZ", playerid, message);
    return 1;
}

stock Police_CreatePrfBarrier(playerid)
{
    new blitzid;
    new message[144];
    new Float:forwardX;
    new Float:forwardY;
    new Float:rightX;
    new Float:rightY;
    new Float:x;
    new Float:y;
    new Float:z;

    if (!Police_CanCreatePrfBarrier(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas PRF pode montar barreira fiscal PRF.");
        return 1;
    }

    if (GetPlayerInterior(playerid) != 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Monte barreiras PRF apenas em area externa.");
        return 1;
    }

    blitzid = Police_FindFreeBlitzSlot();
    if (blitzid == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Limite de barreiras/blitz ativas atingido.");
        return 1;
    }

    GetPlayerPos(playerid, gPoliceBlitzX[blitzid], gPoliceBlitzY[blitzid], gPoliceBlitzZ[blitzid]);
    GetPlayerFacingAngle(playerid, gPoliceBlitzA[blitzid]);
    forwardX = floatsin(-gPoliceBlitzA[blitzid], degrees);
    forwardY = floatcos(-gPoliceBlitzA[blitzid], degrees);
    rightX = floatcos(-gPoliceBlitzA[blitzid], degrees);
    rightY = -floatsin(-gPoliceBlitzA[blitzid], degrees);

    gPoliceBlitzActive[blitzid] = 1;
    gPoliceBlitzCreator[blitzid] = playerid;

    x = gPoliceBlitzX[blitzid] + (rightX * -3.4);
    y = gPoliceBlitzY[blitzid] + (rightY * -3.4);
    z = gPoliceBlitzZ[blitzid] - 0.6;
    gPoliceBlitzObject[blitzid][0] = CreateObject(1422, x, y, z, 0.0, 0.0, gPoliceBlitzA[blitzid]);

    x = gPoliceBlitzX[blitzid];
    y = gPoliceBlitzY[blitzid];
    gPoliceBlitzObject[blitzid][1] = CreateObject(1422, x, y, z, 0.0, 0.0, gPoliceBlitzA[blitzid]);

    x = gPoliceBlitzX[blitzid] + (rightX * 3.4);
    y = gPoliceBlitzY[blitzid] + (rightY * 3.4);
    gPoliceBlitzObject[blitzid][2] = CreateObject(1422, x, y, z, 0.0, 0.0, gPoliceBlitzA[blitzid]);

    gPoliceBlitzObject[blitzid][3] = CreateObject(1238, gPoliceBlitzX[blitzid] + (rightX * -5.8) + (forwardX * -2.2), gPoliceBlitzY[blitzid] + (rightY * -5.8) + (forwardY * -2.2), gPoliceBlitzZ[blitzid] - 0.7, 0.0, 0.0, gPoliceBlitzA[blitzid]);
    gPoliceBlitzObject[blitzid][4] = CreateObject(1238, gPoliceBlitzX[blitzid] + (rightX * 5.8) + (forwardX * -2.2), gPoliceBlitzY[blitzid] + (rightY * 5.8) + (forwardY * -2.2), gPoliceBlitzZ[blitzid] - 0.7, 0.0, 0.0, gPoliceBlitzA[blitzid]);
    gPoliceBlitzObject[blitzid][5] = CreateObject(1238, gPoliceBlitzX[blitzid] + (rightX * -5.8) + (forwardX * 2.2), gPoliceBlitzY[blitzid] + (rightY * -5.8) + (forwardY * 2.2), gPoliceBlitzZ[blitzid] - 0.7, 0.0, 0.0, gPoliceBlitzA[blitzid]);
    gPoliceBlitzObject[blitzid][6] = CreateObject(1238, gPoliceBlitzX[blitzid] + (rightX * 5.8) + (forwardX * 2.2), gPoliceBlitzY[blitzid] + (rightY * 5.8) + (forwardY * 2.2), gPoliceBlitzZ[blitzid] - 0.7, 0.0, 0.0, gPoliceBlitzA[blitzid]);
    gPoliceBlitzObject[blitzid][7] = CreateObject(1238, gPoliceBlitzX[blitzid] + (forwardX * -6.0), gPoliceBlitzY[blitzid] + (forwardY * -6.0), gPoliceBlitzZ[blitzid] - 0.7, 0.0, 0.0, gPoliceBlitzA[blitzid]);
    gPoliceBlitzObject[blitzid][8] = CreateObject(1238, gPoliceBlitzX[blitzid] + (forwardX * 6.0), gPoliceBlitzY[blitzid] + (forwardY * 6.0), gPoliceBlitzZ[blitzid] - 0.7, 0.0, 0.0, gPoliceBlitzA[blitzid]);
    gPoliceBlitzLabel[blitzid] = Create3DTextLabel("BARREIRA PRF\nFiscalizacao rodoviaria\nUse /postofiscal, /fiscalizar e /fiscalizarcarga", COLOR_ADMIN, gPoliceBlitzX[blitzid], gPoliceBlitzY[blitzid], gPoliceBlitzZ[blitzid] + 1.2, 35.0, 0, 1);

    format(message, sizeof(message), "Barreira fiscal PRF criada. ID %d | remova com /removerblitz.", blitzid + 1);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_ADMIN_FILE, "CREATE_PRF_BARRIER", playerid, message);
    return 1;
}

stock Police_SendRecord(playerid, targetid)
{
    new message[144];
    new crimeName[POLICE_CRIME_NAME_SIZE];
    new location[AMBIENT_NPC_CRIME_LOC_SIZE];
    new name[MAX_PLAYER_NAME + 1];
    new status[24];
    new jailTime[24];
    new wanted;
    new crimeid;

    if (AmbientNpc_IsManaged(targetid))
    {
        AmbientNpc_GetDisplayName(targetid, crimeName, sizeof(crimeName));
        wanted = AmbientNpc_GetWanted(targetid);
        crimeid = AmbientNpc_GetCrimeId(targetid);
        AmbientNpc_GetCrimeLocation(targetid, location, sizeof(location));
        format(message, sizeof(message), "Ficha NPC ID %d | %s | Procurado: %d | Crime: %d | Local: %s | Custodia: %d seg", targetid, crimeName, wanted, crimeid, location, AmbientNpc_GetJailTime(targetid));
        SendClientMessage(playerid, COLOR_BLUE, message);
        return 1;
    }

    GetPlayerNameEx(targetid, name, sizeof(name));
    Police_GetCrimeName(PlayerInfo[targetid][pJailCrimeId], crimeName, sizeof(crimeName));
    Police_FormatJailTime(PlayerInfo[targetid][pJailTime], jailTime, sizeof(jailTime));
    if (PlayerInfo[targetid][pWanted] > 0)
    {
        format(status, sizeof(status), "PROCURADO");
    }
    else if (PlayerInfo[targetid][pCriminalRecords] > 0)
    {
        format(status, sizeof(status), "COM PASSAGEM");
    }
    else
    {
        format(status, sizeof(status), "FICHA LIMPA");
    }

    format(message, sizeof(message), "Ficha ID %d | %s | %s | wanted %d | antecedentes %d", targetid, name, status, PlayerInfo[targetid][pWanted], PlayerInfo[targetid][pCriminalRecords]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Pendencias: multas $%d | pontos CNH %d | prisao %s | tornozeleira %s", PlayerInfo[targetid][pFines], PlayerInfo[targetid][pTrafficPoints], jailTime, PlayerInfo[targetid][pAnkleMonitor] ? ("sim") : ("nao"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Porte de arma: %s | Compra armas: %s", PlayerInfo[targetid][pLicensePolice] ? ("sim") : ("nao"), (PlayerInfo[targetid][pLicensePolice] && PlayerInfo[targetid][pWanted] == 0 && PlayerInfo[targetid][pJailTime] <= 0) ? ("liberada") : ("bloqueada"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Crime organizado: faccao %d | rank %d | respeito %d | ganho/hora $%d", PlayerInfo[targetid][pCrimeFaction], PlayerInfo[targetid][pCrimeRank], PlayerInfo[targetid][pCrimeRespect], PlayerInfo[targetid][pCrimeHourlyGain]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    if (PlayerInfo[targetid][pJailTime] > 0)
    {
        format(message, sizeof(message), "Crime da prisao: ID %d | %s", PlayerInfo[targetid][pJailCrimeId], crimeName);
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    return 1;
}

stock Police_CanSearchPlayer(playerid)
{
    return Police_IsOfficer(playerid);
}

stock Police_CanBasicApproach(playerid)
{
    return (PlayerInfo[playerid][pJob] == JOB_SEGURANCA || Police_CanSearchPlayer(playerid));
}

stock Police_AppendSearchRow(list[], size, section[], item[], status[])
{
    new line[POLICE_SEARCH_LINE_SIZE];

    format(line, sizeof(line), "%s\t%s\t%s\n", section, item, status);
    if (strlen(list) + strlen(line) >= size - 1)
    {
        return 0;
    }
    strcat(list, line, size);
    return 1;
}

stock Police_FormatSearchValidity(active, expireDay, output[], size = sizeof(output))
{
    new days;

    if (!active)
    {
        format(output, size, "nao possui");
        return 1;
    }

    if (expireDay <= 0)
    {
        format(output, size, "ativo sem vencimento");
        return 1;
    }

    days = expireDay - GetBrasiliaDayStamp();
    if (days < 0)
    {
        format(output, size, "vencido ha %d dia(s)", -days);
    }
    else if (days == 0)
    {
        format(output, size, "vence hoje");
    }
    else
    {
        format(output, size, "valido por %d dia(s)", days);
    }
    return 1;
}

stock Police_AppendSearchValidity(list[], size, section[], item[], active, expireDay)
{
    new status[64];

    Police_FormatSearchValidity(active, expireDay, status, sizeof(status));
    return Police_AppendSearchRow(list, size, section, item, status);
}

stock Police_IsSearchWeaponAuth(targetid, weaponid)
{
    if (weaponid == 0 || weaponid == WEAPON_PARACHUTE)
    {
        return 1;
    }

    if (Work_IsActive(targetid))
    {
        switch (weaponid)
        {
            case WEAPON_NITESTICK, WEAPON_SHOTGUN, WEAPON_MP5:
            {
                return IsPublicSecurityJob(PlayerInfo[targetid][pJob]);
            }
            case WEAPON_M4:
            {
                return IsLawEnforcementJob(PlayerInfo[targetid][pJob]);
            }
            case WEAPON_FIREEXTINGUISHER:
            {
                return (PlayerInfo[targetid][pJob] == JOB_BOMBEIRO);
            }
            case WEAPON_SPRAYCAN:
            {
                return (PlayerInfo[targetid][pJob] == JOB_MEDICO || PlayerInfo[targetid][pJob] == JOB_MOTORISTA_AMBULANCIA || PlayerInfo[targetid][pJob] == JOB_MECANICO || PlayerInfo[targetid][pJob] == JOB_TECNICO);
            }
            case WEAPON_CAMERA:
            {
                return (PlayerInfo[targetid][pJob] == JOB_JORNALISTA);
            }
        }
    }

    if (PlayerInfo[targetid][pLicensePolice] && PlayerInfo[targetid][pWanted] == 0 && PlayerInfo[targetid][pJailTime] <= 0)
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

stock Police_GetSearchWeaponName(weaponid, output[], size = sizeof(output))
{
    output[0] = 0;
    GetWeaponName(weaponid, output, size);

    if (output[0] == 0)
    {
        format(output, size, "Arma ID %d", weaponid);
    }
    return 1;
}

stock Police_AppendSearchInventory(list[], size, targetid)
{
    new itemid;
    new amount;
    new count;
    new omitted;
    new itemName[32];
    new status[96];

    for (itemid = 1; itemid < INV_MAX_ITEMS; itemid++)
    {
        amount = Inventory_GetAmount(targetid, itemid);
        if (amount <= 0)
        {
            continue;
        }

        Inventory_GetItemName(itemid, itemName, sizeof(itemName));
        format(status, sizeof(status), "%d unidade(s)", amount);
        if (count >= POLICE_SEARCH_INV_MAX_ROWS)
        {
            omitted++;
            continue;
        }
        if (!Police_AppendSearchRow(list, size, "Inventario", itemName, status))
        {
            omitted++;
            continue;
        }
        count++;
    }

    if (!count)
    {
        Police_AppendSearchRow(list, size, "Inventario", "itens", "nenhum item encontrado");
    }
    else if (omitted > 0)
    {
        format(status, sizeof(status), "+%d item(ns) oculto(s) para manter a dialog segura", omitted);
        Police_AppendSearchRow(list, size, "Inventario", "resumo", status);
    }
    return count;
}

stock Police_IsContrabandItem(itemid)
{
    new itemName[32];

    if (!Inventory_IsValidItem(itemid))
    {
        return 0;
    }

    Inventory_GetItemName(itemid, itemName, sizeof(itemName));
    if (strfind(itemName, "droga", true) != -1 || strfind(itemName, "maconha", true) != -1 || strfind(itemName, "cocaina", true) != -1 || strfind(itemName, "crack", true) != -1 || strfind(itemName, "ilicito", true) != -1 || strfind(itemName, "ilegal", true) != -1 || strfind(itemName, "bruto", true) != -1 || strfind(itemName, "embalado", true) != -1 || strfind(itemName, "sujo", true) != -1)
    {
        return 1;
    }
    return 0;
}

stock Police_AppendSearchContraband(list[], size, targetid)
{
    new itemid;
    new amount;
    new count;
    new itemName[32];
    new status[96];

    for (itemid = 1; itemid < INV_MAX_ITEMS; itemid++)
    {
        amount = Inventory_GetAmount(targetid, itemid);
        if (amount <= 0 || !Police_IsContrabandItem(itemid))
        {
            continue;
        }

        Inventory_GetItemName(itemid, itemName, sizeof(itemName));
        format(status, sizeof(status), "%d unidade(s)", amount);
        Police_AppendSearchRow(list, size, "Drogas/ilicitos", itemName, status);
        count++;
    }

    if (!count)
    {
        Police_AppendSearchRow(list, size, "Drogas/ilicitos", "itens", "nenhum item ilicito encontrado");
    }
    return count;
}

stock Police_CountContrabandItems(playerid)
{
    new itemid;
    new amount;
    new count;

    for (itemid = 1; itemid < INV_MAX_ITEMS; itemid++)
    {
        amount = Inventory_GetAmount(playerid, itemid);
        if (amount > 0 && Police_IsContrabandItem(itemid))
        {
            count += amount;
        }
    }
    return count;
}

stock Police_AppendSearchWeapons(list[], size, targetid)
{
    new slot;
    new weaponid;
    new ammo;
    new count;
    new omitted;
    new weaponName[32];
    new status[112];

    for (slot = 0; slot < 13; slot++)
    {
        GetPlayerWeaponData(targetid, slot, weaponid, ammo);
        if (weaponid <= 0 || ammo <= 0)
        {
            continue;
        }

        Police_GetSearchWeaponName(weaponid, weaponName, sizeof(weaponName));
        format(status, sizeof(status), "ID %d | %d muni | %s", weaponid, ammo, Police_IsSearchWeaponAuth(targetid, weaponid) ? ("regular") : ("suspeita/sem porte"));
        if (count >= POLICE_SEARCH_WEAPON_MAX_ROWS)
        {
            omitted++;
            continue;
        }
        if (!Police_AppendSearchRow(list, size, "Armas", weaponName, status))
        {
            omitted++;
            continue;
        }
        count++;
    }

    if (!count)
    {
        Police_AppendSearchRow(list, size, "Armas", "porte/posse", "nenhuma arma detectada");
    }
    else if (omitted > 0)
    {
        format(status, sizeof(status), "+%d arma(s) ocultas para manter a dialog segura", omitted);
        Police_AppendSearchRow(list, size, "Armas", "resumo", status);
    }
    return count;
}

stock Police_CountIllegalWeapons(playerid)
{
    new slot;
    new weaponid;
    new ammo;
    new count;

    for (slot = 0; slot < 13; slot++)
    {
        GetPlayerWeaponData(playerid, slot, weaponid, ammo);
        if (weaponid > 0 && ammo > 0 && !Police_IsSearchWeaponAuth(playerid, weaponid))
        {
            count++;
        }
    }
    return count;
}

stock Police_CountDetectedWeapons(targetid)
{
    new slot;
    new weaponid;
    new ammo;
    new count;

    for (slot = 0; slot < 13; slot++)
    {
        GetPlayerWeaponData(targetid, slot, weaponid, ammo);
        if (weaponid > 0 && ammo > 0)
        {
            count++;
        }
    }
    return count;
}

stock Police_ShowNpcSearchDialog(playerid, targetid)
{
    new body[640];
    new title[64];
    new label[AMBIENT_NPC_LABEL_SIZE];
    new jailTime[24];
    new crimeTitle[AMBIENT_NPC_CRIME_TITLE_SIZE];
    new crimeLocation[AMBIENT_NPC_CRIME_LOC_SIZE];
    new status[96];

    AmbientNpc_GetDisplayName(targetid, label, sizeof(label));
    Police_FormatJailTime(AmbientNpc_GetJailTime(targetid), jailTime, sizeof(jailTime));
    AmbientNpc_GetCrimeTitle(targetid, crimeTitle, sizeof(crimeTitle));
    AmbientNpc_GetCrimeLocation(targetid, crimeLocation, sizeof(crimeLocation));

    format(title, sizeof(title), "Revista - NPC ID %d", targetid);
    format(body, sizeof(body), "Secao\tItem\tStatus\n");
    Police_AppendSearchRow(body, sizeof(body), "Identificacao", "Nome", label);
    Police_AppendSearchRow(body, sizeof(body), "Identificacao", "Tipo", "NPC ambiente");
    format(status, sizeof(status), "%d estrela(s) | crime %d", AmbientNpc_GetWanted(targetid), AmbientNpc_GetCrimeId(targetid));
    Police_AppendSearchRow(body, sizeof(body), "Ficha", "Procurado", status);
    Police_AppendSearchRow(body, sizeof(body), "Ficha", crimeTitle, crimeLocation);
    Police_AppendSearchRow(body, sizeof(body), "Custodia", "Tempo restante", jailTime);
    Police_AppendSearchRow(body, sizeof(body), "Inventario", "itens", "nao disponivel para NPC");
    Police_AppendSearchRow(body, sizeof(body), "Drogas/ilicitos", "itens", "nao disponivel para NPC");
    Police_AppendSearchRow(body, sizeof(body), "Armas", "porte/posse", "nao detectado");
    ShowPlayerDialog(playerid, DIALOG_POLICE_SEARCH, DIALOG_STYLE_TABLIST_HEADERS, title, body, "Fechar", "");
    return 1;
}

stock Police_ShowSearchDialog(playerid, targetid)
{
    new body[POLICE_SEARCH_DIALOG_SIZE];
    new title[64];
    new status[96];
    new name[MAX_PLAYER_NAME + 1];
    new jobLabel[32];
    new jailTime[24];

    if (AmbientNpc_IsManaged(targetid))
    {
        return Police_ShowNpcSearchDialog(playerid, targetid);
    }

    GetPlayerNameEx(targetid, name, sizeof(name));
    GetJobName(PlayerInfo[targetid][pJob], jobLabel, sizeof(jobLabel));
    Police_FormatJailTime(PlayerInfo[targetid][pJailTime], jailTime, sizeof(jailTime));

    format(title, sizeof(title), "Revista - ID %d", targetid);
    format(body, sizeof(body), "Secao\tItem\tStatus\n");

    Police_AppendSearchRow(body, sizeof(body), "Identificacao", "Nome", name);
    Police_AppendSearchRow(body, sizeof(body), "Identificacao", "Emprego", jobLabel);

    format(status, sizeof(status), "score %d | nivel %d", PlayerInfo[targetid][pBankScore], PlayerInfo[targetid][pLevel]);
    Police_AppendSearchRow(body, sizeof(body), "Identificacao", "Score/Nivel", status);

    Police_AppendSearchValidity(body, sizeof(body), "Documentos", "RG/CPF", PlayerInfo[targetid][pDocuments], PlayerInfo[targetid][pDocumentsExpire]);
    Police_AppendSearchValidity(body, sizeof(body), "Licencas", "CNH", PlayerInfo[targetid][pLicenseCNH], PlayerInfo[targetid][pLicenseCNHExpire]);
    Police_AppendSearchValidity(body, sizeof(body), "Licencas", "CNH pesada", PlayerInfo[targetid][pLicenseHeavy], PlayerInfo[targetid][pLicenseHeavyExpire]);
    Police_AppendSearchValidity(body, sizeof(body), "Licencas", "Medica", PlayerInfo[targetid][pLicenseMedical], PlayerInfo[targetid][pLicenseMedicalExpire]);
    Police_AppendSearchValidity(body, sizeof(body), "Licencas", "OAB", PlayerInfo[targetid][pLicenseOAB], PlayerInfo[targetid][pLicenseOABExpire]);
    Police_AppendSearchValidity(body, sizeof(body), "Licencas", "Cargo publico", PlayerInfo[targetid][pLicensePublic], PlayerInfo[targetid][pLicensePublicExpire]);
    Police_AppendSearchValidity(body, sizeof(body), "Porte", "Arma legalizada", PlayerInfo[targetid][pLicensePolice], PlayerInfo[targetid][pLicensePoliceExpire]);

    format(status, sizeof(status), "%s", (IsPublicSecurityJob(PlayerInfo[targetid][pJob]) && Work_IsActive(targetid)) ? ("em servico") : ("fora de servico"));
    Police_AppendSearchRow(body, sizeof(body), "Porte", "Status funcional", status);

    format(status, sizeof(status), "wanted %d | multas $%d | pontos CNH %d", PlayerInfo[targetid][pWanted], PlayerInfo[targetid][pFines], PlayerInfo[targetid][pTrafficPoints]);
    Police_AppendSearchRow(body, sizeof(body), "Ficha", "Pendencias", status);

    format(status, sizeof(status), "antecedentes %d | prisao %s | tornozeleira %s", PlayerInfo[targetid][pCriminalRecords], jailTime, PlayerInfo[targetid][pAnkleMonitor] ? ("sim") : ("nao"));
    Police_AppendSearchRow(body, sizeof(body), "Ficha", "Criminal", status);

    format(status, sizeof(status), "faccao %d | rank %d | respeito %d | ganho/hora $%d", PlayerInfo[targetid][pCrimeFaction], PlayerInfo[targetid][pCrimeRank], PlayerInfo[targetid][pCrimeRespect], PlayerInfo[targetid][pCrimeHourlyGain]);
    Police_AppendSearchRow(body, sizeof(body), "Crime organizado", "Status", status);

    Police_AppendSearchInventory(body, sizeof(body), targetid);
    Police_AppendSearchContraband(body, sizeof(body), targetid);
    Police_AppendSearchWeapons(body, sizeof(body), targetid);

    ShowPlayerDialog(playerid, DIALOG_POLICE_SEARCH, DIALOG_STYLE_TABLIST_HEADERS, title, body, "Fechar", "");
    return 1;
}

stock Police_ShowBasicApproachDialog(playerid, targetid)
{
    new body[960];
    new title[64];
    new status[96];
    new name[MAX_PLAYER_NAME + 1];
    new jobLabel[32];
    new weaponCount;

    format(title, sizeof(title), "Abordagem basica - ID %d", targetid);
    format(body, sizeof(body), "Secao\tItem\tStatus\n");

    if (AmbientNpc_IsManaged(targetid))
    {
        AmbientNpc_GetDisplayName(targetid, name, sizeof(name));
        Police_AppendSearchRow(body, sizeof(body), "Identificacao", "Nome", name);
        Police_AppendSearchRow(body, sizeof(body), "Identificacao", "Tipo", "NPC ambiente");
        Police_AppendSearchRow(body, sizeof(body), "Abordagem", "Nivel", "basico seguranca privada");
        Police_AppendSearchRow(body, sizeof(body), "Abordagem", "Orientacao", "acionar policia para ficha e revista completa");
        ShowPlayerDialog(playerid, DIALOG_POLICE_SEARCH, DIALOG_STYLE_TABLIST_HEADERS, title, body, "Fechar", "");
        return 1;
    }

    GetPlayerNameEx(targetid, name, sizeof(name));
    GetJobName(PlayerInfo[targetid][pJob], jobLabel, sizeof(jobLabel));
    weaponCount = Police_CountDetectedWeapons(targetid);

    Police_AppendSearchRow(body, sizeof(body), "Identificacao", "Nome", name);
    Police_AppendSearchRow(body, sizeof(body), "Identificacao", "Emprego", jobLabel);
    format(status, sizeof(status), "nivel %d | score %d", PlayerInfo[targetid][pLevel], PlayerInfo[targetid][pBankScore]);
    Police_AppendSearchRow(body, sizeof(body), "Identificacao", "Nivel/Score", status);
    format(status, sizeof(status), "%s", weaponCount > 0 ? ("sim") : ("nao"));
    Police_AppendSearchRow(body, sizeof(body), "Abordagem", "Armas detectadas", status);
    Police_AppendSearchRow(body, sizeof(body), "Abordagem", "Ficha/licencas/drogas", "restrito a policia");
    Police_AppendSearchRow(body, sizeof(body), "Abordagem", "Orientacao", "acionar policia se houver suspeita");

    ShowPlayerDialog(playerid, DIALOG_POLICE_SEARCH, DIALOG_STYLE_TABLIST_HEADERS, title, body, "Fechar", "");
    return 1;
}

stock Police_CommandSearch(playerid, targetid)
{
    new message[144];

    if (!Police_CanSearchPlayer(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policiais, PRF, PF, Policia Civil ou Penal podem revistar.");
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "Alvo invalido.");
        return 1;
    }
    if (targetid == playerid)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Use /inventario e /minhaconta para consultar seus proprios dados.");
        return 1;
    }
    if (!Job_ArePlayersClose(playerid, targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "O alvo precisa estar perto para revista.");
        return 1;
    }
    if (!AmbientNpc_IsManaged(targetid) && !PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido ou sem login.");
        return 1;
    }

    if (!AmbientNpc_IsManaged(targetid))
    {
        SendClientMessage(targetid, COLOR_ORANGE, "Voce esta sendo revistado pela seguranca publica. Colabore com a abordagem.");
    }

    format(message, sizeof(message), "revista target=%d job=%d", targetid, PlayerInfo[playerid][pJob]);
    WritePlayerLog(LOG_PUNISH_FILE, "POLICE_SEARCH", playerid, message);
    return Police_ShowSearchDialog(playerid, targetid);
}

stock Police_CommandApproach(playerid, targetid)
{
    new message[144];
    new fullApproach;

    if (!Police_CanBasicApproach(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policiais ou segurancas podem abordar.");
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "Alvo invalido.");
        return 1;
    }
    if (targetid == playerid)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Use /inventario e /minhaconta para consultar seus proprios dados.");
        return 1;
    }
    if (!Job_ArePlayersClose(playerid, targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "O alvo precisa estar perto para abordagem.");
        return 1;
    }
    if (!AmbientNpc_IsManaged(targetid) && !PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido ou sem login.");
        return 1;
    }

    fullApproach = Police_CanSearchPlayer(playerid);
    if (AmbientNpc_IsManaged(targetid))
    {
        AmbientNpc_OrderStop(playerid, targetid);
    }
    else if (fullApproach)
    {
        SendClientMessage(targetid, COLOR_ORANGE, "Voce esta sendo abordado pela seguranca publica. Colabore com a autoridade.");
    }
    else
    {
        SendClientMessage(targetid, COLOR_ORANGE, "Voce esta sendo abordado pela seguranca privada. Aguarde orientacao.");
    }

    format(message, sizeof(message), "abordagem target=%d job=%d full=%d", targetid, PlayerInfo[playerid][pJob], fullApproach);
    if (fullApproach)
    {
        WritePlayerLog(LOG_PUNISH_FILE, "POLICE_APPROACH", playerid, message);
        return Police_ShowSearchDialog(playerid, targetid);
    }
    WritePlayerLog(LOG_PUNISH_FILE, "SECURITY_APPROACH", playerid, message);
    return Police_ShowBasicApproachDialog(playerid, targetid);
}

stock Police_GetDetectorZone(playerid)
{
    if (World_IsPlayerAtServiceInterior(playerid, LOCATION_PREFEITURA) || World_IsPlayerNearLocation(playerid, LOCATION_PREFEITURA, 10.0))
    {
        return POLICE_DETECTOR_PREF;
    }

    if (
        World_IsPlayerAtServiceInterior(playerid, LOCATION_JOB_JUIZ) ||
        World_IsPlayerAtServiceInterior(playerid, LOCATION_JOB_ADVOGADO) ||
        World_IsPlayerNearLocation(playerid, LOCATION_JOB_JUIZ, 10.0) ||
        World_IsPlayerNearLocation(playerid, LOCATION_JOB_ADVOGADO, 10.0)
    )
    {
        return POLICE_DETECTOR_JUSTICE;
    }
    return 0;
}

stock Police_GetDetectorZoneName(zone, output[], size = sizeof(output))
{
    switch (zone)
    {
        case POLICE_DETECTOR_PREF:
        {
            format(output, size, "Prefeitura");
        }
        case POLICE_DETECTOR_JUSTICE:
        {
            format(output, size, "Area judicial");
        }
        default:
        {
            format(output, size, "Area protegida");
        }
    }
    return 1;
}

stock Police_BuildDetectorReason(playerid, output[], size = sizeof(output))
{
    new illegalWeapons = Police_CountIllegalWeapons(playerid);
    new contraband = Police_CountContrabandItems(playerid);
    new count;
    new line[64];

    output[0] = 0;

    if (illegalWeapons > 0)
    {
        format(line, sizeof(line), "arma sem licenca/irregular x%d", illegalWeapons);
        strcat(output, line, size);
        count++;
    }

    if (contraband > 0)
    {
        if (count > 0)
        {
            strcat(output, ", ", size);
        }
        format(line, sizeof(line), "drogas/ilicitos x%d", contraband);
        strcat(output, line, size);
        count++;
    }

    if (PlayerInfo[playerid][pWanted] > 0)
    {
        if (count > 0)
        {
            strcat(output, ", ", size);
        }
        format(line, sizeof(line), "procurado %d estrela(s)", PlayerInfo[playerid][pWanted]);
        strcat(output, line, size);
        count++;
    }

    if (PlayerInfo[playerid][pAnkleMonitor])
    {
        if (count > 0)
        {
            strcat(output, ", ", size);
        }
        strcat(output, "tornozeleira ativa", size);
        count++;
    }
    return count;
}

stock Police_SendDetectorAlert(playerid, zone, reason[])
{
    new pid;
    new maxPlayers = GetMaxPlayers();
    new name[MAX_PLAYER_NAME + 1];
    new zoneName[32];
    new message[192];
    new sent;

    GetPlayerNameEx(playerid, name, sizeof(name));
    Police_GetDetectorZoneName(zone, zoneName, sizeof(zoneName));
    format(message, sizeof(message), "Policia Judicial: detector acionado em %s | ID %d %s | %s.", zoneName, playerid, name, reason);

    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || IsPlayerNPC(pid) || !PlayerInfo[pid][pLogged])
        {
            continue;
        }
        if (!IsLawEnforcementJob(PlayerInfo[pid][pJob]))
        {
            continue;
        }

        SendClientMessage(pid, COLOR_ORANGE, message);
        sent++;
    }

    SendClientMessage(playerid, COLOR_ORANGE, "Detector de seguranca acionado. Aguarde orientacao da autoridade policial.");
    format(message, sizeof(message), "zone=%d sent=%d reason=%s", zone, sent, reason);
    WritePlayerLog(LOG_PUNISH_FILE, "JUDICIAL_DETECTOR", playerid, message);
    return 1;
}

stock Police_CheckJudicialDetector(playerid)
{
    new zone;
    new tick;
    new reason[160];

    if (IsPlayerNPC(playerid) || !PlayerInfo[playerid][pLogged])
    {
        return 0;
    }

    zone = Police_GetDetectorZone(playerid);
    if (!zone)
    {
        gPoliceDetectorZone[playerid] = 0;
        return 0;
    }

    if (!Police_BuildDetectorReason(playerid, reason, sizeof(reason)))
    {
        gPoliceDetectorZone[playerid] = zone;
        return 0;
    }

    tick = GetTickCount();
    if (gPoliceDetectorZone[playerid] == zone && gPoliceDetectorTick[playerid] > 0 && (tick - gPoliceDetectorTick[playerid]) < POLICE_DETECTOR_COOLDOWN_MS)
    {
        return 0;
    }

    gPoliceDetectorZone[playerid] = zone;
    gPoliceDetectorTick[playerid] = tick;
    return Police_SendDetectorAlert(playerid, zone, reason);
}

stock Police_ShowWantedList(playerid)
{
    new list[3200];
    new line[192];
    new name[MAX_PLAYER_NAME + 1];
    new crimeName[POLICE_CRIME_NAME_SIZE];
    new pid;
    new count;
    new maxPlayers = GetMaxPlayers();

    format(list, sizeof(list), "Tipo\tSuspeito\tEstrelas/Crime\tStatus\n");
    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || IsPlayerNPC(pid) || !PlayerInfo[pid][pLogged] || PlayerInfo[pid][pWanted] <= 0)
        {
            continue;
        }

        GetPlayerNameEx(pid, name, sizeof(name));
        Police_GetCrimeName(PlayerInfo[pid][pJailCrimeId], crimeName, sizeof(crimeName));
        format(line, sizeof(line), "Player\tID %d %s\t%d estrela(s) | %s\t%s\n", pid, name, PlayerInfo[pid][pWanted], crimeName, PlayerInfo[pid][pJailTime] > 0 ? ("preso") : ("foragido"));
        if (strlen(list) + strlen(line) < sizeof(list) - 1)
        {
            strcat(list, line, sizeof(list));
            count++;
        }
    }

    AmbientNpc_AppendWantedRows(list, sizeof(list), count);
    if (!count)
    {
        strcat(list, "-\tNenhum procurado ativo\t-\t-\n", sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_WANTED_LIST, DIALOG_STYLE_TABLIST_HEADERS, "Procurados e estrelas", list, "Fechar", "");
    return 1;
}

stock Police_CountOnlineOfficers(&onDuty)
{
    new pid;
    new count;
    new maxPlayers = GetMaxPlayers();

    onDuty = 0;
    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || IsPlayerNPC(pid) || !PlayerInfo[pid][pLogged])
        {
            continue;
        }
        if (!Police_IsOfficer(pid))
        {
            continue;
        }
        count++;
        if (Work_IsActive(pid))
        {
            onDuty++;
        }
    }
    return count;
}

stock Police_CountActiveBlitz()
{
    new blitzid;
    new count;

    for (blitzid = 0; blitzid < MAX_POLICE_BLITZ; blitzid++)
    {
        if (gPoliceBlitzActive[blitzid])
        {
            count++;
        }
    }
    return count;
}

stock Police_CountJusticeBacklog(&warrants, &evidence)
{
    new pid;
    new cases;
    new maxPlayers = GetMaxPlayers();

    warrants = 0;
    evidence = 0;
    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || IsPlayerNPC(pid) || !PlayerInfo[pid][pLogged])
        {
            continue;
        }
        cases += PlayerInfo[pid][pJusticeCases];
        warrants += PlayerInfo[pid][pJusticeActiveWarrants];
        evidence += PlayerInfo[pid][pJusticeActiveEvidence];
    }
    return cases;
}

stock Police_CountWantedPlayers()
{
    new pid;
    new count;
    new maxPlayers = GetMaxPlayers();

    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || IsPlayerNPC(pid) || !PlayerInfo[pid][pLogged])
        {
            continue;
        }
        if (PlayerInfo[pid][pWanted] > 0)
        {
            count++;
        }
    }
    return count;
}

stock Police_ShowCentralDialog(playerid)
{
    new list[2200];
    new line[176];
    new creatorName[MAX_PLAYER_NAME + 1];
    new officersDuty;
    new officers = Police_CountOnlineOfficers(officersDuty);
    new wantedPlayers = Police_CountWantedPlayers();
    new wantedNpcs = AmbientNpc_CountWanted();
    new warrants;
    new evidence;
    new justiceCases = Police_CountJusticeBacklog(warrants, evidence);
    new blitzCount = Police_CountActiveBlitz();
    new shownBlitz;

    if (!Police_IsOfficer(playerid) && !HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendNoPermission(playerid);
    }

    format(list, sizeof(list), "Area\tStatus\tDetalhe\n");
    format(line, sizeof(line), "Escala\t%d online\t%d em servico\n", officers, officersDuty);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Procurados\t%d player(s)\t%d NPC(s) denunciados\n", wantedPlayers, wantedNpcs);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Justica\t%d caso(s)\t%d mandado(s) | %d prova(s)\n", justiceCases, warrants, evidence);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Blitz\t%d ativa(s)\t/barreira /removerblitz /blitzprf\n", blitzCount);
    strcat(list, line, sizeof(list));
    strcat(list, "BO e provas\tfluxo ativo\t/bo /prova /mandado /processos\n", sizeof(list));
    strcat(list, "Ocorrencias\tcentral publica\t/missaopublica | /chamados\n", sizeof(list));

    for (new blitzid = 0; blitzid < MAX_POLICE_BLITZ && shownBlitz < 5; blitzid++)
    {
        if (!gPoliceBlitzActive[blitzid])
        {
            continue;
        }
        creatorName[0] = 0;
        if (IsValidConnectedPlayer(gPoliceBlitzCreator[blitzid]))
        {
            GetPlayerNameEx(gPoliceBlitzCreator[blitzid], creatorName, sizeof(creatorName));
        }
        else
        {
            format(creatorName, sizeof(creatorName), "offline");
        }
        format(line, sizeof(line), "Blitz #%d\tativa\t%s | X %.1f Y %.1f\n", blitzid + 1, creatorName, gPoliceBlitzX[blitzid], gPoliceBlitzY[blitzid]);
        strcat(list, line, sizeof(list));
        shownBlitz++;
    }

    if (!shownBlitz)
    {
        strcat(list, "Blitz recentes\tsem ativa\tUse /barreira ou /blitzprf em operacao\n", sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_POLICE_CENTRAL, DIALOG_STYLE_TABLIST_HEADERS, "Central Policia/PRF", list, "Fechar", "");
    WritePlayerLog(LOG_ADMIN_FILE, "POLICE_CENTRAL_VIEW", playerid, "consultou central operacional");
    return 1;
}

stock Police_SetWanted(playerid, targetid, wanted)
{
    new message[128];

    if (!Police_IsOfficer(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policiais podem alterar procurado.");
        return 1;
    }

    if (wanted < 0)
    {
        wanted = 0;
    }
    if (wanted > MAX_WANTED_LEVEL)
    {
        wanted = MAX_WANTED_LEVEL;
    }
    if (wanted > 0 && Account_IsNewcomerProtected(targetid))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Recem chegado protegido: nao pode ficar procurado ate o nivel 3.");
        SendClientMessage(targetid, COLOR_YELLOW, "Aviso educativo: voce ainda esta protegido contra procurado ate o nivel 3.");
        return 1;
    }

    PlayerInfo[targetid][pWanted] = wanted;
    if (wanted > 0)
    {
        PlayerInfo[targetid][pCriminalRecords]++;
    }
    SaveAccountNow(targetid, 0);

    format(message, sizeof(message), "Nivel de procurado do ID %d definido para %d.", targetid, wanted);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(message, sizeof(message), "Seu nivel de procurado foi alterado para %d.", wanted);
    SendClientMessage(targetid, COLOR_RED, message);
    return 1;
}

stock Police_ClearRecord(playerid, targetid)
{
    if (!Police_IsOfficer(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policiais podem limpar ficha.");
        return 1;
    }

    PlayerInfo[targetid][pWanted] = 0;
    PlayerInfo[targetid][pFines] = 0;
    PlayerInfo[targetid][pJailTime] = 0;
    SaveAccountNow(targetid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Ficha operacional limpa.");
    SendClientMessage(targetid, COLOR_GREEN, "Sua ficha operacional foi limpa.");
    return 1;
}

stock Police_CommandCuff(playerid, targetid)
{
    new message[144];

    if (!Police_CanUseCustody(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policia pode algemar.");
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "Alvo invalido.");
        return 1;
    }
    if (!Job_ArePlayersClose(playerid, targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "O alvo precisa estar perto para algemar.");
        return 1;
    }
    if (gPoliceCuffed[targetid])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Este alvo ja esta algemado.");
        return 1;
    }
    if (!AmbientNpc_IsManaged(targetid) && Account_IsNewcomerProtected(targetid))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Recem chegado protegido: oriente o jogador, sem algema/prisao ate o nivel 3.");
        SendClientMessage(targetid, COLOR_YELLOW, "Aviso educativo: voce esta protegido contra algema/prisao ate o nivel 3.");
        return 1;
    }

    gPoliceCuffed[targetid] = 1;
    gPoliceCuffedBy[targetid] = playerid;

    if (AmbientNpc_IsManaged(targetid))
    {
        AmbientNpc_Cuff(playerid, targetid);
        return 1;
    }

    if (!PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido ou sem login.");
        gPoliceCuffed[targetid] = 0;
        gPoliceCuffedBy[targetid] = INVALID_PLAYER_ID;
        return 1;
    }

    TogglePlayerControllable(targetid, 0);
    SetPlayerSpecialAction(targetid, SPECIAL_ACTION_CUFFED);
    format(message, sizeof(message), "ID %d algemado. Use /prender %d e escolha o crime.", targetid, targetid);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(targetid, COLOR_RED, "Voce foi algemado. Aguarde a autoridade.");
    WritePlayerLog(LOG_PUNISH_FILE, "POLICE_CUFF", playerid, message);
    return 1;
}

stock Police_CommandUncuff(playerid, targetid)
{
    new message[144];

    if (!Police_CanUseCustody(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policia pode desalgemar.");
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "Alvo invalido.");
        return 1;
    }
    if (!gPoliceCuffed[targetid])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Este alvo nao esta algemado.");
        return 1;
    }

    gPoliceCuffed[targetid] = 0;
    gPoliceCuffedBy[targetid] = INVALID_PLAYER_ID;

    if (AmbientNpc_IsManaged(targetid))
    {
        AmbientNpc_Uncuff(playerid, targetid);
        return 1;
    }

    TogglePlayerControllable(targetid, 1);
    SetPlayerSpecialAction(targetid, SPECIAL_ACTION_NONE);
    format(message, sizeof(message), "ID %d desalgemado.", targetid);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(targetid, COLOR_GREEN, "Voce foi desalgemado.");
    WritePlayerLog(LOG_PUNISH_FILE, "POLICE_UNCUFF", playerid, message);
    return 1;
}

stock Police_ArrestPlayer(targetid, crimeid = 0, seconds = 0)
{
    new jailTime;
    new crimeIndex;

    if (Account_IsNewcomerProtected(targetid))
    {
        PlayerInfo[targetid][pWanted] = 0;
        PlayerInfo[targetid][pJailTime] = 0;
        PlayerInfo[targetid][pJailCrimeId] = 0;
        SaveAccountNow(targetid, 0);
        SendClientMessage(targetid, COLOR_YELLOW, "Protecao de recem chegado: prisao bloqueada ate o nivel 3.");
        return 0;
    }

    if (PlayerInfo[targetid][pWanted] < 1)
    {
        PlayerInfo[targetid][pWanted] = 1;
    }

    crimeIndex = Police_GetCrimeIndexById(crimeid);
    if (seconds <= 0 && crimeIndex != -1)
    {
        seconds = gPoliceCrimes[crimeIndex][policeCrimeMinutes] * 60;
    }
    if (seconds <= 0)
    {
        seconds = PlayerInfo[targetid][pWanted] * 120;
    }

    jailTime = seconds;
    if (jailTime < JAIL_MIN_SECONDS)
    {
        jailTime = JAIL_MIN_SECONDS;
    }

    PlayerInfo[targetid][pJailTime] = jailTime;
    PlayerInfo[targetid][pJailCrimeId] = crimeid;
    PlayerInfo[targetid][pCriminalRecords]++;
    World_SendPlayerToPoliceCell(targetid);
    SaveAccountNow(targetid, 0);
    return 1;
}

stock Police_ReleasePlayer(targetid)
{
    PlayerInfo[targetid][pJailTime] = 0;
    PlayerInfo[targetid][pJailCrimeId] = 0;
    PlayerInfo[targetid][pAdminJail] = 0;
    PlayerInfo[targetid][pWanted] = 0;
    gPoliceCuffed[targetid] = 0;
    gPoliceCuffedBy[targetid] = INVALID_PLAYER_ID;
    TogglePlayerControllable(targetid, 1);
    SetPlayerSpecialAction(targetid, SPECIAL_ACTION_NONE);
    World_ReleaseFromPoliceCell(targetid);
    SaveAccountNow(targetid, 0);
    return 1;
}

stock Police_ApplyArrestCrime(playerid, targetid, crimeIndex)
{
    new message[144];
    new crimeid;
    new seconds;
    new crimeName[POLICE_CRIME_NAME_SIZE];
    new canForce = 0;

    if (!Police_CanUseCustody(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policia pode prender.");
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "Alvo invalido.");
        return 1;
    }
    if (crimeIndex < 0 || crimeIndex >= sizeof(gPoliceCrimes))
    {
        SendClientMessage(playerid, COLOR_RED, "Crime invalido. Use /crimes para ver a lista.");
        return 1;
    }
    if (!canForce && !Job_ArePlayersClose(playerid, targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "O alvo precisa estar perto para prisao.");
        return 1;
    }

    crimeid = gPoliceCrimes[crimeIndex][policeCrimeId];
    seconds = gPoliceCrimes[crimeIndex][policeCrimeMinutes] * 60;
    if (seconds < JAIL_MIN_SECONDS)
    {
        seconds = JAIL_MIN_SECONDS;
    }
    format(crimeName, sizeof(crimeName), "%s", gPoliceCrimes[crimeIndex][policeCrimeName]);

    if (AmbientNpc_IsManaged(targetid))
    {
        if (AmbientNpc_IsJailed(targetid))
        {
            SendClientMessage(playerid, COLOR_GRAY, "Este NPC ja esta preso.");
            return 1;
        }
        if (!gPoliceCuffed[targetid] && !canForce)
        {
            SendClientMessage(playerid, COLOR_RED, "Algeme o NPC primeiro com /algemar [id].");
            return 1;
        }
        gPoliceCuffed[targetid] = 0;
        gPoliceCuffedBy[targetid] = INVALID_PLAYER_ID;
        AmbientNpc_Arrest(playerid, targetid, crimeid, seconds, crimeName);
        Life_AddCityPassProgress(playerid, CITY_PASS_KIND_PUBLIC, 1);
        Life_AddWeeklyScore(playerid, WEEKLY_SCORE_POLICE, 3);
        return 1;
    }

    if (!PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido ou sem login.");
        return 1;
    }
    if (PlayerInfo[targetid][pJailTime] > 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Este jogador ja esta preso.");
        return 1;
    }
    if (Account_IsNewcomerProtected(targetid))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Recem chegado protegido: prisao bloqueada ate o nivel 3.");
        SendClientMessage(targetid, COLOR_YELLOW, "Aviso educativo: voce nao pode ser preso/procurado ate o nivel 3.");
        return 1;
    }
    if (!gPoliceCuffed[targetid] && !canForce)
    {
        SendClientMessage(playerid, COLOR_RED, "Algeme o jogador primeiro com /algemar [id].");
        return 1;
    }

    PlayerInfo[targetid][pAnkleMonitor] = 0;
    if (PlayerInfo[targetid][pWanted] < gPoliceCrimes[crimeIndex][policeCrimeWanted])
    {
        PlayerInfo[targetid][pWanted] = gPoliceCrimes[crimeIndex][policeCrimeWanted];
    }
    if (gPoliceCrimes[crimeIndex][policeCrimeFine] > 0)
    {
        PlayerInfo[targetid][pFines] += Cfg_Fine(gPoliceCrimes[crimeIndex][policeCrimeFine]);
        if (PlayerInfo[targetid][pFines] > MAX_PLAYER_FINE)
        {
            PlayerInfo[targetid][pFines] = MAX_PLAYER_FINE;
        }
    }
    PlayerInfo[targetid][pJusticeCases]++;
    PlayerInfo[targetid][pJusticeStatus] = POLICE_JUSTICE_STATUS_RESOLVED;
    PlayerInfo[targetid][pJusticeActiveEvidence] = 0;
    PlayerInfo[targetid][pJusticeActiveWarrants] = 0;
    ResetPlayerWeapons(targetid);
    Police_ArrestPlayer(targetid, crimeid, seconds);
    if (IsLawEnforcementJob(PlayerInfo[playerid][pJob]))
    {
        PlayerInfo[playerid][pWeeklyPoliceScore] += 2;
        SaveAccountData(playerid, 0);
    }

    format(message, sizeof(message), "prisao target=%d crime=%d minutes=%d wanted=%d", targetid, crimeid, seconds / 60, PlayerInfo[targetid][pWanted]);
    WritePlayerLog(LOG_PUNISH_FILE, "POLICE_ARREST", playerid, message);
    format(message, sizeof(message), "ID %d preso por %d min | crime %d: %s.", targetid, seconds / 60, crimeid, crimeName);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(message, sizeof(message), "Voce foi preso por %d min | crime %d: %s.", seconds / 60, crimeid, crimeName);
    SendClientMessage(targetid, COLOR_RED, message);
    GameTextForPlayer(targetid, "~r~PRESO~n~~w~Veja o contador no HUD", 5000, 3);
    return 1;
}

stock Police_ShowCrimeList(playerid)
{
    new list[1600];
    new button[16];

    Police_BuildCrimeList(list, sizeof(list));
    format(button, sizeof(button), "%s", gPolicePendingArrestTarget[playerid] == INVALID_PLAYER_ID ? ("Fechar") : ("Prender"));
    ShowPlayerDialog(playerid, DIALOG_POLICE_ARREST_CRIME, DIALOG_STYLE_TABLIST_HEADERS, "Codigo Penal - escolha o crime", list, button, "Fechar");
    return 1;
}

stock Police_ShowArrestCrimeDialog(playerid, targetid)
{
    if (!Police_CanUseCustody(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policia pode prender.");
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "Alvo invalido.");
        return 1;
    }

    gPolicePendingArrestTarget[playerid] = targetid;
    return Police_ShowCrimeList(playerid);
}

stock Police_HandleArrestCrimeDialog(playerid, response, listitem)
{
    new targetid = gPolicePendingArrestTarget[playerid];

    if (!response)
    {
        gPolicePendingArrestTarget[playerid] = INVALID_PLAYER_ID;
        return 1;
    }

    if (targetid == INVALID_PLAYER_ID)
    {
        return 1;
    }

    if (listitem < 0 || listitem >= sizeof(gPoliceCrimes))
    {
        SendClientMessage(playerid, COLOR_RED, "Crime expirado. Use /prender [id] novamente.");
        gPolicePendingArrestTarget[playerid] = INVALID_PLAYER_ID;
        return 1;
    }

    if (!IsValidConnectedPlayer(targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "Alvo da prisao expirou. Use /prender [id] novamente.");
        gPolicePendingArrestTarget[playerid] = INVALID_PLAYER_ID;
        return 1;
    }

    gPolicePendingArrestTarget[playerid] = INVALID_PLAYER_ID;
    return Police_ApplyArrestCrime(playerid, targetid, listitem);
}

stock Police_CommandArrest(playerid, targetid, crimeid = 0)
{
    new crimeIndex;

    if (crimeid > 0)
    {
        crimeIndex = Police_GetCrimeIndexById(crimeid);
        return Police_ApplyArrestCrime(playerid, targetid, crimeIndex);
    }

    return Police_ShowArrestCrimeDialog(playerid, targetid);
}

stock Police_CommandRelease(playerid, targetid)
{
    new message[144];
    new canForce = 0;

    if (!Police_CanUseCustody(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policia pode soltar.");
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "Alvo invalido.");
        return 1;
    }
    if (AmbientNpc_IsManaged(targetid))
    {
        gPoliceCuffed[targetid] = 0;
        gPoliceCuffedBy[targetid] = INVALID_PLAYER_ID;
        return AmbientNpc_ReleaseFromJail(playerid, targetid);
    }
    if (!PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido ou sem login.");
        return 1;
    }
    if (PlayerInfo[targetid][pAdminJail] && !canForce)
    {
        SendClientMessage(playerid, COLOR_RED, "Punicao administrativa nao pode ser removida por comando policial.");
        return 1;
    }
    if (PlayerInfo[targetid][pJailTime] <= 0 && PlayerInfo[targetid][pWanted] <= 0 && !PlayerInfo[targetid][pAnkleMonitor])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Este jogador nao possui prisao, procurado ou tornozeleira ativa.");
        return 1;
    }

    PlayerInfo[targetid][pAnkleMonitor] = 0;
    Police_ReleasePlayer(targetid);
    format(message, sizeof(message), "soltura target=%d", targetid);
    WritePlayerLog(LOG_PUNISH_FILE, "POLICE_RELEASE", playerid, message);
    SendClientMessage(playerid, COLOR_GREEN, "Jogador liberado e pendencias policiais operacionais removidas.");
    SendClientMessage(targetid, COLOR_GREEN, "Voce foi liberado pela autoridade.");
    return 1;
}

stock Police_PayBail(playerid)
{
    new cost;
    new message[96];

    if (PlayerInfo[playerid][pJailTime] <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta preso.");
        return 1;
    }

    if (PlayerInfo[playerid][pAdminJail])
    {
        SendClientMessage(playerid, COLOR_RED, "Punicao administrativa nao permite fianca.");
        return 1;
    }

    cost = PlayerInfo[playerid][pWanted] * JAIL_BAIL_COST_PER_LEVEL;
    if (cost < JAIL_BAIL_COST_PER_LEVEL)
    {
        cost = JAIL_BAIL_COST_PER_LEVEL;
    }

    if (!Bank_TakePaymentReason(playerid, cost, 0, "police_bail"))
    {
        format(message, sizeof(message), "Fianca: $%d. Voce nao tem dinheiro/banco suficiente.", cost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    Police_ReleasePlayer(playerid);
    WritePlayerLog(LOG_PUNISH_FILE, "BAIL", playerid, "pagou fianca");
    format(message, sizeof(message), "Fianca paga: $%d. Voce foi liberado.", cost);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Police_OnPlayerSpawn(playerid)
{
    if (PlayerInfo[playerid][pJailTime] > 0)
    {
        World_SendPlayerToPoliceCell(playerid);
        if (PlayerInfo[playerid][pAdminJail])
        {
            SendClientMessage(playerid, COLOR_RED, "Voce esta em punicao administrativa. Aguarde o tempo acabar.");
        }
        else
        {
            SendClientMessage(playerid, COLOR_RED, "Voce ainda esta preso. Aguarde o tempo acabar ou pague fianca.");
        }
        return 1;
    }
    return 0;
}

stock Police_FindNearestBlitzDriver(playerid)
{
    new targetid;
    new nearest = INVALID_PLAYER_ID;
    new maxPlayers = GetMaxPlayers();
    new Float:px;
    new Float:py;
    new Float:pz;
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:distance;
    new Float:best = 999999.0;

    GetPlayerPos(playerid, px, py, pz);
    for (targetid = 0; targetid < maxPlayers; targetid++)
    {
        if (targetid == playerid || !IsPlayerConnected(targetid) || !PlayerInfo[targetid][pLogged])
        {
            continue;
        }

        if (GetPlayerState(targetid) != PLAYER_STATE_DRIVER)
        {
            continue;
        }

        GetPlayerPos(targetid, x, y, z);
        if (!IsPlayerInRangeOfPoint(targetid, POLICE_BLITZ_RANGE, px, py, pz))
        {
            continue;
        }

        distance = floatsqroot(floatpower(px - x, 2.0) + floatpower(py - y, 2.0) + floatpower(pz - z, 2.0));
        if (distance < best)
        {
            best = distance;
            nearest = targetid;
        }
    }
    return nearest;
}

stock Police_IsFiscalAgent(playerid)
{
    return (PlayerInfo[playerid][pJob] == JOB_PRF);
}

stock Police_FindNearestFiscalPost(playerid)
{
    new index;

    if (GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
    {
        return -1;
    }

    for (index = 0; index < POLICE_FISCAL_POSTS; index++)
    {
        if (IsPlayerInRangeOfPoint(playerid, POLICE_FISCAL_RANGE, gPoliceFiscalPosts[index][fiscalX], gPoliceFiscalPosts[index][fiscalY], gPoliceFiscalPosts[index][fiscalZ]))
        {
            return index;
        }
    }
    return -1;
}

stock Police_FindNearestFiscalDriver(playerid)
{
    new targetid;
    new nearest = INVALID_PLAYER_ID;
    new maxPlayers = GetMaxPlayers();
    new Float:px;
    new Float:py;
    new Float:pz;
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:distance;
    new Float:best = 999999.0;

    GetPlayerPos(playerid, px, py, pz);
    for (targetid = 0; targetid < maxPlayers; targetid++)
    {
        if (targetid == playerid || !IsPlayerConnected(targetid) || !PlayerInfo[targetid][pLogged])
        {
            continue;
        }
        if (GetPlayerState(targetid) != PLAYER_STATE_DRIVER)
        {
            continue;
        }
        GetPlayerPos(targetid, x, y, z);
        if (!IsPlayerInRangeOfPoint(targetid, POLICE_FISCAL_DRIVER_RANGE, px, py, pz))
        {
            continue;
        }
        distance = floatsqroot(floatpower(px - x, 2.0) + floatpower(py - y, 2.0) + floatpower(pz - z, 2.0));
        if (distance < best)
        {
            best = distance;
            nearest = targetid;
        }
    }
    return nearest;
}

stock Police_ShowFiscalPosts(playerid)
{
    new index;
    new message[144];

    SendClientMessage(playerid, COLOR_BLUE, "Postos fiscais PRF:");
    for (index = 0; index < POLICE_FISCAL_POSTS; index++)
    {
        format(message, sizeof(message), "%d. %s | comandos: /postofiscal, /fiscalizar, /fiscalizarcarga, /liberarfiscal, /apreenderfiscal", index + 1, gPoliceFiscalPosts[index][fiscalName]);
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    return 1;
}

stock Police_RequireFiscalPost(playerid)
{
    new postid;

    if (!Police_IsFiscalAgent(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas PRF pode operar posto fiscal.");
        return -1;
    }
    postid = Police_FindNearestFiscalPost(playerid);
    if (postid == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar em um posto fiscal PRF.");
        Police_ShowFiscalPosts(playerid);
        return -1;
    }
    return postid;
}

stock Police_FiscalSignalStop(playerid)
{
    new postid = Police_RequireFiscalPost(playerid);
    new targetid;
    new message[144];

    if (postid == -1)
    {
        return 1;
    }

    targetid = Police_FindNearestFiscalDriver(playerid);
    if (targetid == INVALID_PLAYER_ID)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Nenhum motorista proximo do posto fiscal.");
        return 1;
    }

    format(message, sizeof(message), "PRF: encoste no %s e aguarde fiscalizacao.", gPoliceFiscalPosts[postid][fiscalName]);
    SendClientMessage(targetid, COLOR_RED, message);
    GameTextForPlayer(targetid, "~r~POSTO FISCAL~n~~w~Encoste o veiculo", 4000, 3);
    SendClientMessage(playerid, COLOR_GREEN, "Ordem de parada enviada ao motorista proximo.");
    return 1;
}

stock Police_FiscalCheck(playerid)
{
    new postid = Police_RequireFiscalPost(playerid);
    new targetid;
    new ownerid;
    new slot;
    new vehicleid;
    new message[144];
    new cnhStatus[32];
    new docsStatus[32];

    if (postid == -1)
    {
        return 1;
    }

    targetid = Police_FindNearestFiscalDriver(playerid);
    if (targetid == INVALID_PLAYER_ID)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Nenhum motorista proximo para fiscalizar.");
        return 1;
    }

    Police_FormatSearchValidity(PlayerInfo[targetid][pLicenseCNH], PlayerInfo[targetid][pLicenseCNHExpire], cnhStatus, sizeof(cnhStatus));
    Police_FormatSearchValidity(PlayerInfo[targetid][pDocuments], PlayerInfo[targetid][pDocumentsExpire], docsStatus, sizeof(docsStatus));
    format(message, sizeof(message), "Posto: %s | Motorista: %s", gPoliceFiscalPosts[postid][fiscalName], PlayerInfo[targetid][pCharacterName]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "CNH: %s | RG/CPF: %s | Multas: $%d | Pontos CNH: %d", cnhStatus, docsStatus, PlayerInfo[targetid][pFines], PlayerInfo[targetid][pTrafficPoints]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Ficha: procurado %d | antecedentes %d | jail %d seg", PlayerInfo[targetid][pWanted], PlayerInfo[targetid][pCriminalRecords], PlayerInfo[targetid][pJailTime]);
    SendClientMessage(playerid, COLOR_BLUE, message);

    if (IsPlayerInAnyVehicle(targetid))
    {
        vehicleid = GetPlayerVehicleID(targetid);
        if (Dlr_FindSpawnedVehSlot(vehicleid, ownerid, slot))
        {
            Dealership_SendPlateInfo(playerid, ownerid, slot);
        }
    }
    Cargo_SendFiscalInfo(playerid, targetid);

    SendClientMessage(playerid, COLOR_GRAY, "Acoes: /multa [id] [numero], /fiscalizarcarga [id], /apreenderfiscal [motivo] ou /liberarfiscal [id].");
    return 1;
}

stock Police_FiscalCargoFine(playerid, targetid)
{
    new result;

    if (Police_RequireFiscalPost(playerid) == -1)
    {
        return 1;
    }
    if (targetid == INVALID_PLAYER_ID)
    {
        targetid = Police_FindNearestFiscalDriver(playerid);
    }
    if (targetid == INVALID_PLAYER_ID)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Nenhum motorista proximo do posto fiscal.");
        return 1;
    }

    result = Cargo_ApplyFiscalPenalty(playerid, targetid);
    if (result == 2)
    {
        Dlr_ImpoundVehiclePolice(playerid, "carga fiscal irregular");
    }
    return 1;
}

stock Police_FiscalRelease(playerid, targetid)
{
    if (Police_RequireFiscalPost(playerid) == -1)
    {
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid) || !PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido.");
        return 1;
    }

    SendClientMessage(targetid, COLOR_GREEN, "PRF: fiscalizacao encerrada. Voce esta liberado para seguir viagem.");
    SendClientMessage(playerid, COLOR_GREEN, "Motorista liberado do posto fiscal.");
    return 1;
}

stock Police_FiscalImpound(playerid, reason[])
{
    if (Police_RequireFiscalPost(playerid) == -1)
    {
        return 1;
    }
    if (strlen(reason) < 1)
    {
        format(reason, 96, "irregularidade em posto fiscal PRF");
    }
    return Dlr_ImpoundVehiclePolice(playerid, reason);
}

stock Police_FindBlitzFineTarget(playerid)
{
    new targetid = Police_FindNearestBlitzDriver(playerid);
    new ownerid;
    new slot;

    if (targetid != INVALID_PLAYER_ID)
    {
        return targetid;
    }

    if (Dealership_FindCommandVehicle(playerid, ownerid, slot))
    {
        return ownerid;
    }
    return INVALID_PLAYER_ID;
}

stock Police_BlitzConsultPlate(playerid)
{
    new ownerid;
    new slot;

    if (!Dealership_FindCommandVehicle(playerid, ownerid, slot))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Fique perto do veiculo ou informe a placa com /consultarplaca.");
        return 1;
    }

    return Dealership_SendPlateInfo(playerid, ownerid, slot);
}

stock Police_BlitzCheckDriverDocs(playerid)
{
    new targetid = Police_FindNearestBlitzDriver(playerid);
    new ownerid;
    new slot;
    new vehicleid;
    new message[144];

    if (targetid == INVALID_PLAYER_ID)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Nenhum motorista parado perto da blitz.");
        return 1;
    }

    format(message, sizeof(message), "Motorista: %s | CNH: %s | Documentos: %s", PlayerInfo[targetid][pCharacterName], PlayerInfo[targetid][pLicenseCNH] ? ("sim") : ("nao"), PlayerInfo[targetid][pDocuments] ? ("emitidos") : ("nao emitidos"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Ficha: Procurado %d | Multas $%d | Antecedentes %d", PlayerInfo[targetid][pWanted], PlayerInfo[targetid][pFines], PlayerInfo[targetid][pCriminalRecords]);
    SendClientMessage(playerid, COLOR_BLUE, message);

    if (IsPlayerInAnyVehicle(targetid))
    {
        vehicleid = GetPlayerVehicleID(targetid);
        if (Dlr_FindSpawnedVehSlot(vehicleid, ownerid, slot))
        {
            Dealership_SendPlateInfo(playerid, ownerid, slot);
        }
    }
    return 1;
}

stock Police_ShowBlitzFineDialog(playerid)
{
    new list[1024];
    new line[128];
    new index;
    new amount;
    new severityName[16];

    if (!Police_CanManageBlitz(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policiais podem multar em blitz.");
        return 1;
    }

    format(list, sizeof(list), "Infracao\tGravidade\tValor/Pontos\n");
    for (index = 0; index < sizeof(gBlitzFines); index++)
    {
        Cfg_TrafficSeverityName(gBlitzFines[index][blitzFineSeverity], severityName, sizeof(severityName));
        amount = Cfg_TrafficFine(gBlitzFines[index][blitzFineSeverity], gBlitzFines[index][blitzFineMultiplier]);
        format(line, sizeof(line), "%s\t%s x%d\t$%d / %d pts\n",
            gBlitzFines[index][blitzFineReason],
            severityName,
            gBlitzFines[index][blitzFineMultiplier],
            amount,
            Cfg_TrafficPoints(gBlitzFines[index][blitzFineSeverity])
        );
        strcat(list, line, sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_BLITZ_FINE, DIALOG_STYLE_TABLIST_HEADERS, "Blitz - aplicar multa", list, "Aplicar", "Voltar");
    return 1;
}

stock Police_ApplyBlitzFine(playerid, fineid)
{
    new targetid;
    new amount;
    new points;
    new message[144];
    new severityName[16];

    if (fineid < 0 || fineid >= sizeof(gBlitzFines))
    {
        return Police_ShowBlitzFineDialog(playerid);
    }

    targetid = Police_FindBlitzFineTarget(playerid);
    if (targetid == INVALID_PLAYER_ID)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Nenhum motorista/veiculo proximo para multar.");
        return 1;
    }
    if (Account_IsNewcomerProtected(targetid))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Recem chegado protegido: blitz deve orientar, sem multa ate o nivel 3.");
        SendClientMessage(targetid, COLOR_YELLOW, "Aviso educativo de blitz: multas liberam a partir do nivel 3.");
        return 1;
    }

    amount = Cfg_TrafficFine(gBlitzFines[fineid][blitzFineSeverity], gBlitzFines[fineid][blitzFineMultiplier]);
    points = Cfg_TrafficPoints(gBlitzFines[fineid][blitzFineSeverity]);
    Cfg_TrafficSeverityName(gBlitzFines[fineid][blitzFineSeverity], severityName, sizeof(severityName));
    PlayerInfo[targetid][pFines] += amount;
    if (PlayerInfo[targetid][pFines] > MAX_PLAYER_FINE)
    {
        PlayerInfo[targetid][pFines] = MAX_PLAYER_FINE;
    }
    PlayerInfo[targetid][pTrafficPoints] += points;
    if (PlayerInfo[targetid][pTrafficPoints] > MAX_TRAFFIC_POINTS)
    {
        PlayerInfo[targetid][pTrafficPoints] = MAX_TRAFFIC_POINTS;
    }
    SaveAccountNow(targetid, 0);

    format(message, sizeof(message), "Multa aplicada: %s | %s x%d | $%d | %d pts | alvo: %s.", gBlitzFines[fineid][blitzFineReason], severityName, gBlitzFines[fineid][blitzFineMultiplier], amount, points, PlayerInfo[targetid][pCharacterName]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(message, sizeof(message), "Voce recebeu multa de blitz: %s | $%d | %d pts na CNH.", gBlitzFines[fineid][blitzFineReason], amount, points);
    SendClientMessage(targetid, COLOR_ORANGE, message);
    WritePlayerLog(LOG_PUNISH_FILE, "BLITZ_FINE", targetid, message);
    return 1;
}

stock Police_BlitzSignalStop(playerid)
{
    new targetid = Police_FindNearestBlitzDriver(playerid);

    if (targetid == INVALID_PLAYER_ID)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Nenhum motorista proximo da blitz.");
        return 1;
    }

    SendClientMessage(targetid, COLOR_RED, "BLITZ POLICIAL: encoste o veiculo e aguarde a abordagem.");
    GameTextForPlayer(targetid, "~r~BLITZ~n~~w~Encoste o veiculo", 4000, 3);
    SendClientMessage(playerid, COLOR_GREEN, "Ordem de parada enviada ao motorista proximo.");
    return 1;
}

stock Police_ShowBlitzDialog(playerid)
{
    new blitzid = Police_FindNearestBlitz(playerid);

    if (blitzid == -1)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta perto de uma blitz ativa.");
        return 1;
    }

    if (!Police_CanManageBlitz(playerid))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Blitz policial: reduza, encoste e apresente CNH/documentos se solicitado.");
        return 1;
    }

    gPlayerBlitzDialog[playerid] = blitzid;
    ShowPlayerDialog(
        playerid,
        DIALOG_BLITZ_MENU,
        DIALOG_STYLE_LIST,
        "Blitz Policial",
        "Consultar placa do veiculo proximo\nConsultar CNH/documentos do motorista\nAplicar multa de blitz\nApreender/guinchar veiculo\nSinalizar parada ao motorista\nRemover blitz proxima\n",
        "Selecionar",
        "Fechar"
    );
    return 1;
}

stock Police_HandleBlitzDialog(playerid, response, listitem)
{
    new blitzid = gPlayerBlitzDialog[playerid];

    if (!response)
    {
        return 1;
    }

    if (blitzid < 0 || blitzid >= MAX_POLICE_BLITZ || !gPoliceBlitzActive[blitzid])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Esta blitz nao esta mais ativa.");
        return 1;
    }

    if (listitem < 0 || listitem > 5)
    {
        SendClientMessage(playerid, COLOR_RED, "Opcao da blitz expirada. Abra o menu novamente.");
        return Police_ShowBlitzDialog(playerid);
    }

    switch (listitem)
    {
        case 0: return Police_BlitzConsultPlate(playerid);
        case 1: return Police_BlitzCheckDriverDocs(playerid);
        case 2: return Police_ShowBlitzFineDialog(playerid);
        case 3: return Dlr_ImpoundVehiclePolice(playerid, "blitz policial");
        case 4: return Police_BlitzSignalStop(playerid);
        case 5: return Police_DestroyNearestBlitz(playerid);
    }
    return 1;
}

stock Police_HandleBlitzFineDialog(playerid, response, listitem)
{
    if (!response)
    {
        return Police_ShowBlitzDialog(playerid);
    }
    if (listitem < 0 || listitem >= sizeof(gBlitzFines))
    {
        SendClientMessage(playerid, COLOR_RED, "Multa da blitz expirada. Abra a lista novamente.");
        return Police_ShowBlitzFineDialog(playerid);
    }
    return Police_ApplyBlitzFine(playerid, listitem);
}

stock Police_OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if ((newkeys & KEY_SECONDARY_ATTACK) && !(oldkeys & KEY_SECONDARY_ATTACK))
    {
        if (Police_FindNearestBlitz(playerid) != -1)
        {
            Police_ShowBlitzDialog(playerid);
            return 1;
        }
    }
    return 0;
}

stock Police_OnPlayerEnterCheckpoint(playerid)
{
    #pragma unused playerid
    return 0;
}

stock Police_OnPlayerDisconnect(playerid)
{
    new index;
    new maxPlayers = GetMaxPlayers();

    Police_DestroyIdLabelsFor(playerid);
    Police_DestroyIdLabelsForTarget(playerid);
    Police_DestroyPlayerBlitz(playerid);
    gPoliceCuffed[playerid] = 0;
    gPoliceCuffedBy[playerid] = INVALID_PLAYER_ID;
    gPlayerBlitzDialog[playerid] = -1;
    gPolicePendingArrestTarget[playerid] = INVALID_PLAYER_ID;
    gPoliceDetectorZone[playerid] = 0;
    gPoliceDetectorTick[playerid] = 0;

    for (index = 0; index < maxPlayers; index++)
    {
        if (gPolicePendingArrestTarget[index] == playerid)
        {
            gPolicePendingArrestTarget[index] = INVALID_PLAYER_ID;
        }
    }
    return 1;
}

public Police_UpdateAll()
{
    new playerid;
    new saveNeeded;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (!IsPlayerConnected(playerid) || !PlayerInfo[playerid][pLogged])
        {
            continue;
        }

        saveNeeded = 0;
        Police_CheckJudicialDetector(playerid);

        if (PlayerInfo[playerid][pJailTime] > 0)
        {
            PlayerInfo[playerid][pJailTime]--;
            if (PlayerInfo[playerid][pJailTime] <= 0)
            {
                Police_ReleasePlayer(playerid);
                SendClientMessage(playerid, COLOR_GREEN, "Seu tempo de prisao acabou. Voce foi liberado.");
            }
            else if ((PlayerInfo[playerid][pJailTime] % 60) == 0)
            {
                saveNeeded = 1;
            }
        }

        if (PlayerInfo[playerid][pMuteTime] > 0)
        {
            PlayerInfo[playerid][pMuteTime]--;
            if (PlayerInfo[playerid][pMuteTime] <= 0)
            {
                PlayerInfo[playerid][pMuteTime] = 0;
                SendClientMessage(playerid, COLOR_GREEN, "Seu mute acabou. Voce pode falar novamente.");
            }
            if ((PlayerInfo[playerid][pMuteTime] % 60) == 0)
            {
                saveNeeded = 1;
            }
        }

        if (gPoliceCuffed[playerid] && PlayerInfo[playerid][pJailTime] <= 0)
        {
            TogglePlayerControllable(playerid, 0);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CUFFED);
        }

        if (saveNeeded)
        {
            SaveAccountNow(playerid, 0);
        }
    }
    return 1;
}

public Police_UpdateIdLabelsAll()
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && !IsPlayerNPC(playerid))
        {
            Police_UpdateIdLabelsFor(playerid);
        }
    }
    return 1;
}

stock HandlePoliceCommands(playerid, cmdtext[])
{
    new command[32];
    new param[32];
    new param2[32];
    new index;
    new targetid;

    index = GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/ficha", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            Police_SendRecord(playerid, playerid);
            return 1;
        }

        if (!ParseTargetPlayer(playerid, param, targetid))
        {
            return 1;
        }
        if (targetid != playerid && !Police_CanSearchPlayer(playerid))
        {
            SendClientMessage(playerid, COLOR_RED, "Apenas policiais podem consultar ficha de outro jogador em abordagem.");
            return 1;
        }

        Police_SendRecord(playerid, targetid);
        return 1;
    }

    if (strcmp(command, "/procurar", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)))
        {
            return SendUsage(playerid, "/procurar [id] [0-6]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid) || !IsNumericString(param2))
        {
            return 1;
        }

        Police_SetWanted(playerid, targetid, strval(param2));
        return 1;
    }

    if (strcmp(command, "/centralpolicia", true) == 0 || strcmp(command, "/centralprf", true) == 0)
    {
        Police_ShowCentralDialog(playerid);
        return 1;
    }

    if (strcmp(command, "/procurados", true) == 0 || strcmp(command, "/wanted", true) == 0)
    {
        Police_ShowWantedList(playerid);
        return 1;
    }

    if (strcmp(command, "/limparficha", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/limparficha [id]");
        }

        Police_ClearRecord(playerid, targetid);
        return 1;
    }

    if (strcmp(command, "/fianca", true) == 0)
    {
        Police_PayBail(playerid);
        return 1;
    }

    if (strcmp(command, "/crimes", true) == 0 || strcmp(command, "/codigopenal", true) == 0 || strcmp(command, "/leispenais", true) == 0)
    {
        gPolicePendingArrestTarget[playerid] = INVALID_PLAYER_ID;
        Police_ShowCrimeList(playerid);
        return 1;
    }

    if (strcmp(command, "/revistar", true) == 0 || strcmp(command, "/revista", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/revistar [id]");
        }

        Police_CommandSearch(playerid, targetid);
        return 1;
    }

    if (strcmp(command, "/abordagem", true) == 0 || strcmp(command, "/abordar", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/abordagem [id]");
        }

        Police_CommandApproach(playerid, targetid);
        return 1;
    }

    if (strcmp(command, "/algemar", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/algemar [id]");
        }

        Police_CommandCuff(playerid, targetid);
        return 1;
    }

    if (strcmp(command, "/desalgemar", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/desalgemar [id]");
        }

        Police_CommandUncuff(playerid, targetid);
        return 1;
    }

    if (strcmp(command, "/prender", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/prender [id] [crime_id opcional]");
        }

        if (GetNextParam(cmdtext, index, param2, sizeof(param2)))
        {
            if (!IsNumericString(param2))
            {
                return SendUsage(playerid, "/prender [id] [crime_id]");
            }
            Police_CommandArrest(playerid, targetid, strval(param2));
            return 1;
        }

        Police_CommandArrest(playerid, targetid, 0);
        return 1;
    }

    if (strcmp(command, "/soltar", true) == 0 || strcmp(command, "/liberar", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/soltar [id]");
        }

        Police_CommandRelease(playerid, targetid);
        return 1;
    }

    if (strcmp(command, "/criarblitz", true) == 0 || strcmp(command, "/montarblitz", true) == 0 || strcmp(command, "/barreira", true) == 0 || strcmp(command, "/criarbarreira", true) == 0)
    {
        Police_CreateBlitz(playerid);
        return 1;
    }

    if (strcmp(command, "/barreiraprf", true) == 0 || strcmp(command, "/criarbarreiraprf", true) == 0 || strcmp(command, "/montarprf", true) == 0 || strcmp(command, "/fiscalprf", true) == 0 || strcmp(command, "/blitzprf", true) == 0)
    {
        Police_CreatePrfBarrier(playerid);
        return 1;
    }

    if (strcmp(command, "/removerblitz", true) == 0 || strcmp(command, "/desmontarblitz", true) == 0)
    {
        if (!Police_CanManageBlitz(playerid))
        {
            SendClientMessage(playerid, COLOR_RED, "Apenas policiais podem remover blitz.");
            return 1;
        }

        Police_DestroyNearestBlitz(playerid);
        return 1;
    }

    if (strcmp(command, "/limparminhasblitz", true) == 0 || strcmp(command, "/limparblitz", true) == 0)
    {
        if (!Police_CanManageBlitz(playerid))
        {
            SendClientMessage(playerid, COLOR_RED, "Apenas policiais podem limpar blitz.");
            return 1;
        }

        if (!Police_DestroyPlayerBlitz(playerid))
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui blitz ativa.");
            return 1;
        }

        SendClientMessage(playerid, COLOR_GREEN, "Todas as suas blitz foram desmontadas.");
        return 1;
    }

    if (strcmp(command, "/postosfiscais", true) == 0 || strcmp(command, "/postofiscal", true) == 0)
    {
        if (Police_FindNearestFiscalPost(playerid) == -1)
        {
            Police_ShowFiscalPosts(playerid);
            return 1;
        }

        Police_FiscalSignalStop(playerid);
        return 1;
    }

    if (strcmp(command, "/fiscalizar", true) == 0 || strcmp(command, "/consultarfiscal", true) == 0)
    {
        Police_FiscalCheck(playerid);
        return 1;
    }

    if (strcmp(command, "/fiscalizarcarga", true) == 0 || strcmp(command, "/cargafiscal", true) == 0 || strcmp(command, "/multacarga", true) == 0)
    {
        targetid = INVALID_PLAYER_ID;
        if (GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            if (!ParseTargetPlayer(playerid, param, targetid))
            {
                return 1;
            }
        }
        Police_FiscalCargoFine(playerid, targetid);
        return 1;
    }

    if (strcmp(command, "/liberarfiscal", true) == 0 || strcmp(command, "/liberarveiculo", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/liberarfiscal [id]");
        }
        if (!ParseTargetPlayer(playerid, param, targetid))
        {
            return 1;
        }
        Police_FiscalRelease(playerid, targetid);
        return 1;
    }

    if (strcmp(command, "/apreenderfiscal", true) == 0 || strcmp(command, "/apreenderveiculo", true) == 0)
    {
        if (!GetRemainingText(cmdtext, index, param2, sizeof(param2)))
        {
            format(param2, sizeof(param2), "irregularidade em posto fiscal PRF");
        }
        Police_FiscalImpound(playerid, param2);
        return 1;
    }

    if (strcmp(command, "/blitz", true) == 0)
    {
        Police_ShowBlitzDialog(playerid);
        return 1;
    }

    return 0;
}
