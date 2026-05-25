#if defined _nova_crime_included
    #endinput
#endif
#define _nova_crime_included

#define CRIME_FACTION_COUNT         (4)
#define CRIME_FACTION_NAME_SIZE     (32)
#define CRIME_PLANT_GROW_SECONDS    (120)
#define CRIME_PLAYER_COOLDOWN       (600)
#define CRIME_FACTION_COOLDOWN      (420)
#define CRIME_HOURLY_CAP            (9000)
#define CRIME_FACTION_MIN_LEVEL     (1)
#define CRIME_FACTION_MAX_LEVEL     (15)
#define CRIME_MISSION_NONE          (0)
#define CRIME_MISSION_ATM           (1)
#define CRIME_MISSION_BANK          (2)
#define CRIME_MISSION_VEHICLE       (3)
#define CRIME_MISSION_ATTACK        (4)
#define CRIME_MISSION_STORE         (5)
#define CRIME_MISSION_CARGO         (6)
#define CRIME_MISSION_LAUNDER       (7)
#define CRIME_DIRTY_UNIT_VALUE      (100)
#define CRIME_LAUNDER_TAX_PERCENT   (28)
#define CRIME_SEED_PRICE            (350)

enum eCrimeSpot
{
    crimeSpotName[32],
    Float:crimeSpotX,
    Float:crimeSpotY,
    Float:crimeSpotZ
}

new gCrimeFactionName[CRIME_FACTION_COUNT + 1][CRIME_FACTION_NAME_SIZE] =
{
    "Nenhuma",
    "Ordem do Morro",
    "Sindicato Norte",
    "Comando da Ponte",
    "Frente Cinza"
};
new gCrimeFactionBank[CRIME_FACTION_COUNT + 1];
new gCrimeFactionRespect[CRIME_FACTION_COUNT + 1];
new gCrimeFactionCooldown[CRIME_FACTION_COUNT + 1];

new gCrimePlantActive[MAX_PLAYERS];
new gCrimePlantTick[MAX_PLAYERS];
new Float:gCrimePlantX[MAX_PLAYERS];
new Float:gCrimePlantY[MAX_PLAYERS];
new Float:gCrimePlantZ[MAX_PLAYERS];

new gCrimeMissionType[MAX_PLAYERS];
new gCrimeMissionReward[MAX_PLAYERS];
new gCrimeMissionRespect[MAX_PLAYERS];
new gCrimeMissionWanted[MAX_PLAYERS];

new gCrimeFields[][eCrimeSpot] =
{
    { "Campo Flint County", -1104.4200, -1620.3500, 76.3600 },
    { "Fazenda Blueberry", 32.7400, 23.4200, 3.1100 },
    { "Sitio Red County", 844.9000, -604.3000, 18.4200 }
};

new gCrimeLabs[][eCrimeSpot] =
{
    { "Galpao rural Flint", -77.6800, -1136.5400, 1.0800 },
    { "Deposito Blueberry", 201.7100, -66.4400, 1.5700 }
};

new gCrimeSellSpots[][eCrimeSpot] =
{
    { "Beco Idlewood", 1921.4000, -1745.8200, 13.5400 },
    { "Docas Los Santos", 2782.3800, -2455.3000, 13.6300 }
};

new gCrimeEscapeSpots[][eCrimeSpot] =
{
    { "Rota de fuga rural", -565.7400, -1498.6200, 10.0800 },
    { "Galpao de fuga", 2477.4000, -1962.2800, 13.5400 },
    { "Ponto frio", 1059.4500, -313.1800, 73.9900 },
    { "Saida norte", 1393.8400, -933.6200, 36.3300 }
};

stock Crime_ResetPlayer(playerid)
{
    gCrimePlantActive[playerid] = 0;
    gCrimePlantTick[playerid] = 0;
    gCrimePlantX[playerid] = 0.0;
    gCrimePlantY[playerid] = 0.0;
    gCrimePlantZ[playerid] = 0.0;
    gCrimeMissionType[playerid] = CRIME_MISSION_NONE;
    gCrimeMissionReward[playerid] = 0;
    gCrimeMissionRespect[playerid] = 0;
    gCrimeMissionWanted[playerid] = 0;
    return 1;
}

stock Crime_FieldName(index, output[], size = sizeof(output))
{
    if (index < 0 || index >= sizeof(gCrimeFields))
    {
        format(output, size, "Campo ilegal");
        return 0;
    }
    format(output, size, "%s", gCrimeFields[index][crimeSpotName]);
    return 1;
}

stock Crime_FindNearField(playerid)
{
    new index;

    for (index = 0; index < sizeof(gCrimeFields); index++)
    {
        if (IsPlayerInRangeOfPoint(playerid, 8.0, gCrimeFields[index][crimeSpotX], gCrimeFields[index][crimeSpotY], gCrimeFields[index][crimeSpotZ]))
        {
            return index;
        }
    }
    return -1;
}

stock Crime_FindNearLab(playerid)
{
    new index;

    for (index = 0; index < sizeof(gCrimeLabs); index++)
    {
        if (IsPlayerInRangeOfPoint(playerid, 8.0, gCrimeLabs[index][crimeSpotX], gCrimeLabs[index][crimeSpotY], gCrimeLabs[index][crimeSpotZ]))
        {
            return index;
        }
    }
    return -1;
}

stock Crime_FindNearSell(playerid)
{
    new index;

    for (index = 0; index < sizeof(gCrimeSellSpots); index++)
    {
        if (IsPlayerInRangeOfPoint(playerid, 8.0, gCrimeSellSpots[index][crimeSpotX], gCrimeSellSpots[index][crimeSpotY], gCrimeSellSpots[index][crimeSpotZ]))
        {
            return index;
        }
    }
    return -1;
}

stock Crime_IsNearStoreRobberyPoint(playerid)
{
    return (
        World_IsPlayerNearLocation(playerid, LOCATION_CONVENIENCIA_1, LOCATION_INTERACT_BUSINESS) ||
        World_IsPlayerNearLocation(playerid, LOCATION_CONVENIENCIA_2, LOCATION_INTERACT_BUSINESS) ||
        World_IsPlayerNearLocation(playerid, LOCATION_JOB_FRENTISTA, LOCATION_INTERACT_BUSINESS)
    );
}

stock Crime_IsNearCargoRobberyPoint(playerid)
{
    return (
        World_IsPlayerNearLocation(playerid, LOCATION_JOB_ENTREGADOR, 6.0) ||
        World_IsPlayerNearLocation(playerid, LOCATION_JOB_CAMINHONEIRO, 6.0) ||
        World_IsPlayerNearLocation(playerid, LOCATION_JOB_MOTOBOY, 6.0)
    );
}

stock Crime_IsNearLaunderPoint(playerid)
{
    return (
        World_IsPlayerAtBankBranch(playerid) ||
        World_IsPlayerNearLocation(playerid, LOCATION_JOB_ADVOGADO, 6.0)
    );
}

stock Crime_IsValidFaction(factionid)
{
    return (factionid >= 1 && factionid <= CRIME_FACTION_COUNT);
}

stock Crime_GetRankByRespect(respect)
{
    if (respect >= 90) return 5;
    if (respect >= 50) return 4;
    if (respect >= 25) return 3;
    if (respect >= 10) return 2;
    return 1;
}

stock Crime_UpdateRank(playerid)
{
    new newRank;
    new message[112];

    if (!Crime_IsValidFaction(PlayerInfo[playerid][pCrimeFaction]))
    {
        return 0;
    }

    newRank = Crime_GetRankByRespect(PlayerInfo[playerid][pCrimeRespect]);
    if (newRank > PlayerInfo[playerid][pCrimeRank])
    {
        PlayerInfo[playerid][pCrimeRank] = newRank;
        format(message, sizeof(message), "Faccao: voce subiu para rank %d pelo respeito acumulado.", newRank);
        SendClientMessage(playerid, COLOR_GREEN, message);
        WritePlayerLog(CRIME_LOG_FILE, "FACTION_RANK_UP", playerid, message);
        MarkAccountDirty(playerid);
    }
    return PlayerInfo[playerid][pCrimeRank];
}

stock Crime_OnlineMembers(factionid)
{
    new playerid;
    new count;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && !IsPlayerNPC(playerid) && PlayerInfo[playerid][pLogged] && PlayerInfo[playerid][pCrimeFaction] == factionid)
        {
            count++;
        }
    }
    return count;
}

stock Crime_SaveFactions()
{
    new File:file;
    new line[128];
    new factionid;

    file = fopen(CRIME_FACTIONS_FILE, io_write);
    if (!file)
    {
        return 0;
    }

    fwrite(file, "# id|nome|caixa|respeito|cooldown_epoch\r\n");
    for (factionid = 1; factionid <= CRIME_FACTION_COUNT; factionid++)
    {
        format(line, sizeof(line), "%d|%s|%d|%d|%d\r\n", factionid, gCrimeFactionName[factionid], gCrimeFactionBank[factionid], gCrimeFactionRespect[factionid], gCrimeFactionCooldown[factionid]);
        fwrite(file, line);
    }
    fclose(file);
    return 1;
}

stock Crime_GetField(line[], fieldIndex, output[], size = sizeof(output))
{
    new index;
    new start;
    new current;
    new length = strlen(line);

    output[0] = 0;
    for (index = 0; index <= length; index++)
    {
        if (line[index] == '|' || line[index] == 0)
        {
            if (current == fieldIndex)
            {
                strmid(output, line, start, index, size);
                Cfg_Trim(output);
                return 1;
            }
            current++;
            start = index + 1;
        }
    }
    return 0;
}

stock Crime_LoadFactions()
{
    new File:file;
    new line[160];
    new token[64];
    new factionid;
    new loaded;

    if (!fexist(CRIME_FACTIONS_FILE))
    {
        return Crime_SaveFactions();
    }

    file = fopen(CRIME_FACTIONS_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        Cfg_Trim(line);
        if (line[0] == 0 || line[0] == '#')
        {
            continue;
        }

        if (!Crime_GetField(line, 0, token, sizeof(token)) || !IsNumericString(token))
        {
            continue;
        }
        factionid = strval(token);
        if (!Crime_IsValidFaction(factionid))
        {
            continue;
        }

        if (Crime_GetField(line, 1, token, sizeof(token)) && token[0] != 0)
        {
            format(gCrimeFactionName[factionid], CRIME_FACTION_NAME_SIZE, "%s", token);
        }
        if (Crime_GetField(line, 2, token, sizeof(token)) && IsNumericString(token))
        {
            gCrimeFactionBank[factionid] = strval(token);
        }
        if (Crime_GetField(line, 3, token, sizeof(token)) && IsNumericString(token))
        {
            gCrimeFactionRespect[factionid] = strval(token);
        }
        if (Crime_GetField(line, 4, token, sizeof(token)) && IsNumericString(token))
        {
            gCrimeFactionCooldown[factionid] = strval(token);
        }
        loaded++;
    }
    fclose(file);
    return loaded;
}

stock Crime_CreateSpotsFile()
{
    new File:file;
    new index;
    new line[160];

    if (fexist(CRIME_SPOTS_FILE))
    {
        return 1;
    }

    file = fopen(CRIME_SPOTS_FILE, io_write);
    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Pontos RP do sistema de crime. Formato: tipo|nome|x|y|z\r\n");
    for (index = 0; index < sizeof(gCrimeFields); index++)
    {
        format(line, sizeof(line), "campo|%s|%.4f|%.4f|%.4f\r\n", gCrimeFields[index][crimeSpotName], gCrimeFields[index][crimeSpotX], gCrimeFields[index][crimeSpotY], gCrimeFields[index][crimeSpotZ]);
        fwrite(file, line);
    }
    for (index = 0; index < sizeof(gCrimeLabs); index++)
    {
        format(line, sizeof(line), "laboratorio|%s|%.4f|%.4f|%.4f\r\n", gCrimeLabs[index][crimeSpotName], gCrimeLabs[index][crimeSpotX], gCrimeLabs[index][crimeSpotY], gCrimeLabs[index][crimeSpotZ]);
        fwrite(file, line);
    }
    for (index = 0; index < sizeof(gCrimeSellSpots); index++)
    {
        format(line, sizeof(line), "venda|%s|%.4f|%.4f|%.4f\r\n", gCrimeSellSpots[index][crimeSpotName], gCrimeSellSpots[index][crimeSpotX], gCrimeSellSpots[index][crimeSpotY], gCrimeSellSpots[index][crimeSpotZ]);
        fwrite(file, line);
    }
    fclose(file);
    return 1;
}

stock Crime_Init()
{
    new File:file;
    new loaded;

    if (!fexist(CRIME_LOG_FILE))
    {
        file = fopen(CRIME_LOG_FILE, io_write);
        if (file)
        {
            fwrite(file, "# Log do sistema criminal RP\r\n");
            fclose(file);
        }
    }
    loaded = Crime_LoadFactions();
    Crime_CreateSpotsFile();
    WriteServerLog(LOG_ADMIN_FILE, "CRIME_INIT", loaded ? ("factions_loaded") : ("factions_default"));
    return 1;
}

stock Crime_Exit()
{
    return Crime_SaveFactions();
}

stock Crime_RequireFaction(playerid)
{
    if (!Crime_IsValidFaction(PlayerInfo[playerid][pCrimeFaction]))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa entrar em uma faccao ficticia com /entrarfaccao [id].");
        return 0;
    }
    return 1;
}

stock Crime_GetFactionMinLevel(factionid)
{
    switch (factionid)
    {
        case 1: return 1;
        case 2: return 5;
        case 3: return 10;
        case 4: return 15;
    }
    return CRIME_FACTION_MIN_LEVEL;
}

stock Crime_MeetsFactionLevel(playerid, factionid, showError = 1)
{
    new minLevel;
    new message[144];

    if (!Crime_IsValidFaction(factionid))
    {
        return 0;
    }

    minLevel = Crime_GetFactionMinLevel(factionid);
    if (PlayerInfo[playerid][pLevel] >= minLevel)
    {
        return 1;
    }

    if (showError)
    {
        format(message, sizeof(message), "%s exige nivel %d. Seu nivel atual: %d.", gCrimeFactionName[factionid], minLevel, PlayerInfo[playerid][pLevel]);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        SendClientMessage(playerid, COLOR_GRAY, "Faccoes liberam em degraus de nivel 1, 5, 10 e 15.");
    }
    return 0;
}

stock Crime_RequireLevel(playerid)
{
    new factionid = PlayerInfo[playerid][pCrimeFaction];
    new minLevel = Crime_IsValidFaction(factionid) ? Crime_GetFactionMinLevel(factionid) : CRIME_FACTION_MIN_LEVEL;
    new message[128];

    if (PlayerInfo[playerid][pLevel] < minLevel)
    {
        format(message, sizeof(message), "Acao criminal bloqueada. Sua faccao exige nivel minimo %d.", minLevel);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        return 0;
    }
    return 1;
}

stock Crime_AddWanted(playerid, wanted)
{
    if (wanted <= 0)
    {
        return 1;
    }
    if (PlayerInfo[playerid][pWanted] < wanted)
    {
        PlayerInfo[playerid][pWanted] = wanted;
    }
    if (PlayerInfo[playerid][pWanted] > MAX_WANTED_LEVEL)
    {
        PlayerInfo[playerid][pWanted] = MAX_WANTED_LEVEL;
    }
    PlayerInfo[playerid][pCriminalRecords]++;
    return 1;
}

stock Crime_SendPoliceAlert(playerid, action[])
{
    new pid;
    new maxPlayers = GetMaxPlayers();
    new name[MAX_PLAYER_NAME + 1];
    new message[160];

    GetPlayerNameEx(playerid, name, sizeof(name));
    format(message, sizeof(message), "Alerta criminal: %s | suspeito ID %d %s | faccao %s.", action, playerid, name, gCrimeFactionName[PlayerInfo[playerid][pCrimeFaction]]);
    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || IsPlayerNPC(pid) || !PlayerInfo[pid][pLogged])
        {
            continue;
        }
        if (IsLawEnforcementJob(PlayerInfo[pid][pJob]))
        {
            SendClientMessage(pid, COLOR_ORANGE, message);
        }
    }
    WritePlayerLog(CRIME_LOG_FILE, "POLICE_ALERT", playerid, message);
    return 1;
}

stock Crime_CheckCooldown(playerid)
{
    new now = gettime();
    new factionid = PlayerInfo[playerid][pCrimeFaction];
    new wait;
    new message[96];

    if (PlayerInfo[playerid][pCrimeMissionCooldown] > now)
    {
        wait = PlayerInfo[playerid][pCrimeMissionCooldown] - now;
        format(message, sizeof(message), "Aguarde %d segundo(s) para outra acao criminal.", wait);
        SendClientMessage(playerid, COLOR_GRAY, message);
        return 0;
    }
    if (Crime_IsValidFaction(factionid) && gCrimeFactionCooldown[factionid] > now)
    {
        wait = gCrimeFactionCooldown[factionid] - now;
        format(message, sizeof(message), "Sua faccao precisa aguardar %d segundo(s).", wait);
        SendClientMessage(playerid, COLOR_GRAY, message);
        return 0;
    }
    return 1;
}

stock Crime_SetCooldown(playerid, seconds)
{
    new now = gettime();
    new factionid = PlayerInfo[playerid][pCrimeFaction];

    PlayerInfo[playerid][pCrimeMissionCooldown] = now + seconds;
    if (Crime_IsValidFaction(factionid))
    {
        gCrimeFactionCooldown[factionid] = now + CRIME_FACTION_COOLDOWN;
        Crime_SaveFactions();
    }
    MarkAccountDirty(playerid);
    return 1;
}

stock Crime_CanEarn(playerid, amount)
{
    new hour = gettime() / 3600;
    new message[112];

    if (PlayerInfo[playerid][pCrimeHourlyStamp] != hour)
    {
        PlayerInfo[playerid][pCrimeHourlyStamp] = hour;
        PlayerInfo[playerid][pCrimeHourlyGain] = 0;
    }
    if (PlayerInfo[playerid][pCrimeHourlyGain] + amount > CRIME_HOURLY_CAP)
    {
        format(message, sizeof(message), "Limite criminal por hora atingido: $%d.", CRIME_HOURLY_CAP);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        return 0;
    }
    return 1;
}

stock Crime_GiveReward(playerid, amount, respect, reason[])
{
    new factionid = PlayerInfo[playerid][pCrimeFaction];
    new message[160];

    if (!Crime_CanEarn(playerid, amount))
    {
        return 0;
    }

    GivePlayerCashReason(playerid, amount, 0, reason);
    PlayerInfo[playerid][pCrimeRespect] += respect;
    PlayerInfo[playerid][pCrimeHourlyGain] += amount;
    Inventory_AddItem(playerid, INV_ITEM_DIRTY_MONEY, amount / 100, 0);
    if (Crime_IsValidFaction(factionid))
    {
        gCrimeFactionBank[factionid] += amount / 4;
        gCrimeFactionRespect[factionid] += respect;
        Crime_SaveFactions();
    }
    Crime_UpdateRank(playerid);
    format(message, sizeof(message), "Acao concluida: +$%d | respeito +%d | dinheiro sujo registrado.", amount, respect);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(message, sizeof(message), "reward=%d respect=%d faction=%d reason=%s", amount, respect, factionid, reason);
    WritePlayerLog(CRIME_LOG_FILE, "CRIME_REWARD", playerid, message);
    MarkAccountDirty(playerid);
    return 1;
}

stock Crime_ShowFactions(playerid)
{
    new factionid;
    new message[160];

    SendClientMessage(playerid, COLOR_BLUE, "Faccoes ficticias disponiveis:");
    for (factionid = 1; factionid <= CRIME_FACTION_COUNT; factionid++)
    {
        format(message, sizeof(message), "%d. %s | nivel %d+ | membros online %d | caixa $%d | respeito %d", factionid, gCrimeFactionName[factionid], Crime_GetFactionMinLevel(factionid), Crime_OnlineMembers(factionid), gCrimeFactionBank[factionid], gCrimeFactionRespect[factionid]);
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    SendClientMessage(playerid, COLOR_GRAY, "Use /entrarfaccao [id]. Faccoes liberam do nivel 1 ao 15. Veja funcoes em /ocupacoesilegais.");
    return 1;
}

stock Crime_JoinFaction(playerid, factionid)
{
    new message[144];

    if (!Crime_IsValidFaction(factionid))
    {
        return SendUsage(playerid, "/entrarfaccao [1-4]");
    }
    if (PlayerInfo[playerid][pCrimeFaction] != 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce ja esta em uma faccao. Use /sairfaccao primeiro.");
        return 1;
    }
    if (!Crime_MeetsFactionLevel(playerid, factionid))
    {
        return 1;
    }

    PlayerInfo[playerid][pCrimeFaction] = factionid;
    PlayerInfo[playerid][pCrimeRank] = 1;
    Inventory_AddItem(playerid, INV_ITEM_ILLEGAL_SEED, 2, 0);
    SaveAccountNow(playerid, 0);
    format(message, sizeof(message), "Voce entrou na faccao ficticia %s. Kit inicial: 2 sementes ilegais.", gCrimeFactionName[factionid]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(CRIME_LOG_FILE, "FACTION_JOIN", playerid, message);
    return 1;
}

stock Crime_LeaveFaction(playerid)
{
    new message[128];

    if (!Crime_IsValidFaction(PlayerInfo[playerid][pCrimeFaction]))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta em faccao.");
        return 1;
    }

    format(message, sizeof(message), "Saiu da faccao %s.", gCrimeFactionName[PlayerInfo[playerid][pCrimeFaction]]);
    PlayerInfo[playerid][pCrimeFaction] = 0;
    PlayerInfo[playerid][pCrimeRank] = 0;
    SaveAccountNow(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Voce saiu da faccao.");
    WritePlayerLog(CRIME_LOG_FILE, "FACTION_LEAVE", playerid, message);
    return 1;
}

stock Crime_ShowStatus(playerid)
{
    new message[160];
    new factionid = PlayerInfo[playerid][pCrimeFaction];
    new now = gettime();
    new cooldown = 0;

    if (!Crime_IsValidFaction(factionid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta em faccao. Use /faccoes.");
        return 1;
    }

    if (PlayerInfo[playerid][pCrimeMissionCooldown] > now)
    {
        cooldown = PlayerInfo[playerid][pCrimeMissionCooldown] - now;
    }
    format(message, sizeof(message), "Faccao: %s | rank %d | respeito %d | cooldown %d seg", gCrimeFactionName[factionid], PlayerInfo[playerid][pCrimeRank], PlayerInfo[playerid][pCrimeRespect], cooldown);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Caixa da faccao $%d | respeito total %d | ganho/hora $%d/%d", gCrimeFactionBank[factionid], gCrimeFactionRespect[factionid], PlayerInfo[playerid][pCrimeHourlyGain], CRIME_HOURLY_CAP);
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}

stock Crime_ShowMissions(playerid)
{
    SendClientMessage(playerid, COLOR_BLUE, "Missoes criminais RP controladas:");
    SendClientMessage(playerid, COLOR_BLUE, "/roubaratm perto de caixa eletronico | risco medio | fuga obrigatoria");
    SendClientMessage(playerid, COLOR_BLUE, "/roubarbanco no banco | risco alto | fuga obrigatoria");
    SendClientMessage(playerid, COLOR_BLUE, "/roubarloja em conveniencia/posto | risco medio | fuga obrigatoria");
    SendClientMessage(playerid, COLOR_BLUE, "/roubarcarga em central de entregas/cargas | risco medio | fuga obrigatoria");
    SendClientMessage(playerid, COLOR_BLUE, "/roubarveiculo dentro de veiculo | risco medio | fuga obrigatoria");
    SendClientMessage(playerid, COLOR_BLUE, "/atacarunidade perto de unidade policial | RP contra objeto/NPC, sem premio por matar player");
    SendClientMessage(playerid, COLOR_GRAY, "Regras: nivel da faccao, cooldown por player/faccao e limite de ganho por hora.");
    return 1;
}

stock Crime_ShowOccupations(playerid)
{
    SendClientMessage(playerid, COLOR_BLUE, "Ocupacoes de faccao ficam fora da Prefeitura:");
    SendClientMessage(playerid, COLOR_BLUE, "Traficante | nivel 1+ | /plantar, /colher, /produzir e /venderprodutoilegal");
    SendClientMessage(playerid, COLOR_BLUE, "Contrabandista | nivel 5+ | /roubarcarga e /lavardinheiro");
    SendClientMessage(playerid, COLOR_BLUE, "Ladrao de carga | nivel 5+ | /roubarcarga");
    SendClientMessage(playerid, COLOR_BLUE, "Assaltante de ATM | nivel 10+ | /roubaratm");
    SendClientMessage(playerid, COLOR_BLUE, "Hacker/clonador | nivel 10+ | /roubarbanco e /roubarveiculo");
    SendClientMessage(playerid, COLOR_BLUE, "Receptador | nivel 15+ | /lavardinheiro e /venderprodutoilegal");
    SendClientMessage(playerid, COLOR_BLUE, "Chefe de faccao | nivel 15+ e rank alto | coordena caixa/respeito em /faccaostatus");
    SendClientMessage(playerid, COLOR_GRAY, "Use /faccoes para entrar. As tarefas usam cooldown, risco policial e limite horario.");
    return 1;
}

stock Crime_ShowPoints(playerid)
{
    new index;
    new message[160];

    SendClientMessage(playerid, COLOR_BLUE, "Pontos criminais RP:");
    for (index = 0; index < sizeof(gCrimeFields); index++)
    {
        format(message, sizeof(message), "Campo: %s | %.1f %.1f %.1f", gCrimeFields[index][crimeSpotName], gCrimeFields[index][crimeSpotX], gCrimeFields[index][crimeSpotY], gCrimeFields[index][crimeSpotZ]);
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    for (index = 0; index < sizeof(gCrimeLabs); index++)
    {
        format(message, sizeof(message), "Laboratorio: %s | %.1f %.1f %.1f", gCrimeLabs[index][crimeSpotName], gCrimeLabs[index][crimeSpotX], gCrimeLabs[index][crimeSpotY], gCrimeLabs[index][crimeSpotZ]);
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    for (index = 0; index < sizeof(gCrimeSellSpots); index++)
    {
        format(message, sizeof(message), "Venda de risco: %s | %.1f %.1f %.1f", gCrimeSellSpots[index][crimeSpotName], gCrimeSellSpots[index][crimeSpotX], gCrimeSellSpots[index][crimeSpotY], gCrimeSellSpots[index][crimeSpotZ]);
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    SendClientMessage(playerid, COLOR_GRAY, "Lavagem RP abstrata: banco ou escritorio de advocacia. Roubos: ATM, banco, loja, carga, veiculo e unidade policial.");
    SendClientMessage(playerid, COLOR_GRAY, "Ocupacoes ilegais: /ocupacoesilegais.");
    return 1;
}

stock Crime_ShowInfo(playerid, targetid)
{
    new message[160];
    new name[MAX_PLAYER_NAME + 1];
    new factionid;
    new contraband;

    if (targetid != playerid && !IsLawEnforcementJob(PlayerInfo[playerid][pJob]))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policiais podem consultar crimeinfo de outro jogador.");
        return 1;
    }
    if (!IsPlayerConnected(targetid) || IsPlayerNPC(targetid) || !PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido ou nao logado.");
        return 1;
    }

    GetPlayerNameEx(targetid, name, sizeof(name));
    factionid = PlayerInfo[targetid][pCrimeFaction];
    contraband = Police_CountContrabandItems(targetid);
    if (!Crime_IsValidFaction(factionid))
    {
        format(message, sizeof(message), "CrimeInfo ID %d %s | sem faccao | wanted %d | antecedentes %d | ilicitos %d", targetid, name, PlayerInfo[targetid][pWanted], PlayerInfo[targetid][pCriminalRecords], contraband);
        SendClientMessage(playerid, COLOR_BLUE, message);
        return 1;
    }
    format(message, sizeof(message), "CrimeInfo ID %d %s | %s rank %d | respeito %d | wanted %d", targetid, name, gCrimeFactionName[factionid], PlayerInfo[targetid][pCrimeRank], PlayerInfo[targetid][pCrimeRespect], PlayerInfo[targetid][pWanted]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Ganho criminal/hora $%d/%d | ilicitos %d | dinheiro sujo %d", PlayerInfo[targetid][pCrimeHourlyGain], CRIME_HOURLY_CAP, contraband, Inventory_GetAmount(targetid, INV_ITEM_DIRTY_MONEY));
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}

stock Crime_Plant(playerid)
{
    new field;
    new fieldName[32];

    if (!Crime_RequireFaction(playerid) || !Crime_RequireLevel(playerid))
    {
        return 1;
    }
    if (gCrimePlantActive[playerid])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce ja possui uma plantacao ativa. Use /colher quando maturar.");
        return 1;
    }
    field = Crime_FindNearField(playerid);
    if (field == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar em um ponto rural de plantio.");
        return 1;
    }
    if (Inventory_GetAmount(playerid, INV_ITEM_ILLEGAL_SEED) <= 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa de semente ilegal.");
        return 1;
    }

    Inventory_TakeItem(playerid, INV_ITEM_ILLEGAL_SEED, 1, 0);
    gCrimePlantActive[playerid] = 1;
    gCrimePlantTick[playerid] = gettime();
    GetPlayerPos(playerid, gCrimePlantX[playerid], gCrimePlantY[playerid], gCrimePlantZ[playerid]);
    Crime_FieldName(field, fieldName, sizeof(fieldName));
    SendClientMessage(playerid, COLOR_GREEN, "Plantio iniciado. Volte em alguns minutos e use /colher.");
    WritePlayerLog(CRIME_LOG_FILE, "PLANT", playerid, fieldName);
    SaveAccountNow(playerid, 0);
    return 1;
}

stock Crime_BuyIllegalSeed(playerid)
{
    new field;
    new message[128];

    if (!Crime_RequireFaction(playerid))
    {
        return 1;
    }
    field = Crime_FindNearField(playerid);
    if (field == -1 && Crime_FindNearLab(playerid) == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Procure um campo rural ou laboratorio da faccao para comprar sementes.");
        return 1;
    }
    if (!Bank_TakePayment(playerid, CRIME_SEED_PRICE, 0))
    {
        format(message, sizeof(message), "Semente ilegal custa $%d em dinheiro/banco.", CRIME_SEED_PRICE);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    Inventory_AddItem(playerid, INV_ITEM_ILLEGAL_SEED, 1, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Fornecedor RP entregou 1 semente ilegal.");
    WritePlayerLog(CRIME_LOG_FILE, "BUY_SEED", playerid, "seed=1");
    SaveAccountNow(playerid, 0);
    return 1;
}

stock Crime_Harvest(playerid)
{
    new elapsed;
    new message[128];

    if (!gCrimePlantActive[playerid])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui plantacao ativa.");
        return 1;
    }
    if (!IsPlayerInRangeOfPoint(playerid, 12.0, gCrimePlantX[playerid], gCrimePlantY[playerid], gCrimePlantZ[playerid]))
    {
        SendClientMessage(playerid, COLOR_RED, "Volte ao ponto onde voce iniciou o plantio.");
        return 1;
    }

    elapsed = gettime() - gCrimePlantTick[playerid];
    if (elapsed < CRIME_PLANT_GROW_SECONDS)
    {
        format(message, sizeof(message), "Plantio ainda crescendo. Aguarde %d segundo(s).", CRIME_PLANT_GROW_SECONDS - elapsed);
        SendClientMessage(playerid, COLOR_GRAY, message);
        return 1;
    }

    gCrimePlantActive[playerid] = 0;
    Inventory_AddItem(playerid, INV_ITEM_ILLEGAL_PLANT, 3, 0);
    Inventory_AddItem(playerid, INV_ITEM_ILLEGAL_SEED, 1, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Colheita concluida: produto bruto de campo adicionado ao inventario.");
    WritePlayerLog(CRIME_LOG_FILE, "HARVEST", playerid, "plant=3 seed=1");
    SaveAccountNow(playerid, 0);
    return 1;
}

stock Crime_Produce(playerid)
{
    if (!Crime_RequireFaction(playerid) || !Crime_RequireLevel(playerid))
    {
        return 1;
    }
    if (Crime_FindNearLab(playerid) == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar em um laboratorio rural.");
        return 1;
    }
    if (Inventory_GetAmount(playerid, INV_ITEM_ILLEGAL_PLANT) < 2)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa de 2 plantas ilegais para produzir.");
        return 1;
    }

    Inventory_TakeItem(playerid, INV_ITEM_ILLEGAL_PLANT, 2, 0);
    Inventory_AddItem(playerid, INV_ITEM_ILLEGAL_RAW, 1, 0);
    Inventory_AddItem(playerid, INV_ITEM_ILLEGAL_PACKED, 1, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Producao RP concluida: produto bruto e embalado adicionados.");
    WritePlayerLog(CRIME_LOG_FILE, "PRODUCE", playerid, "plant=2 packed=1");
    SaveAccountNow(playerid, 0);
    return 1;
}

stock Crime_SellIllegal(playerid)
{
    new reward = 700 + random(550);
    new chance;

    if (!Crime_RequireFaction(playerid) || !Crime_RequireLevel(playerid))
    {
        return 1;
    }
    if (Crime_FindNearSell(playerid) == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar em um ponto de venda de risco.");
        return 1;
    }
    if (Inventory_GetAmount(playerid, INV_ITEM_ILLEGAL_PACKED) <= 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa de produto embalado.");
        return 1;
    }
    if (!Crime_CheckCooldown(playerid) || !Crime_CanEarn(playerid, reward))
    {
        return 1;
    }

    Inventory_TakeItem(playerid, INV_ITEM_ILLEGAL_PACKED, 1, 0);
    Crime_GiveReward(playerid, reward, 2, "illegal_sell");
    Crime_SetCooldown(playerid, CRIME_PLAYER_COOLDOWN / 2);
    chance = random(100);
    if (chance < 35)
    {
        Crime_AddWanted(playerid, 1);
        Crime_SendPoliceAlert(playerid, "denuncia de venda ilegal");
    }
    SaveAccountNow(playerid, 0);
    return 1;
}

stock Crime_LaunderMoney(playerid)
{
    new dirtyUnits;
    new gross;
    new clean;
    new tax;
    new message[144];

    if (!Crime_RequireFaction(playerid) || !Crime_RequireLevel(playerid))
    {
        return 1;
    }
    if (!Crime_IsNearLaunderPoint(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Lavagem RP abstrata exige banco ou escritorio de advocacia.");
        return 1;
    }
    dirtyUnits = Inventory_GetAmount(playerid, INV_ITEM_DIRTY_MONEY);
    if (dirtyUnits < 10)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa de pelo menos 10 unidades de dinheiro sujo.");
        return 1;
    }
    if (!Crime_CheckCooldown(playerid))
    {
        return 1;
    }

    gross = dirtyUnits * CRIME_DIRTY_UNIT_VALUE;
    tax = (gross * CRIME_LAUNDER_TAX_PERCENT) / 100;
    clean = gross - tax;
    if (!Crime_CanEarn(playerid, clean))
    {
        return 1;
    }

    Inventory_TakeItem(playerid, INV_ITEM_DIRTY_MONEY, dirtyUnits, 0);
    GivePlayerCashReason(playerid, clean, 0, "crime_launder");
    PlayerInfo[playerid][pCrimeRespect] += 1;
    PlayerInfo[playerid][pCrimeHourlyGain] += clean;
    Crime_UpdateRank(playerid);
    Crime_SetCooldown(playerid, CRIME_PLAYER_COOLDOWN / 2);
    format(message, sizeof(message), "Lavagem RP concluida: bruto $%d | taxa $%d | limpo $%d.", gross, tax, clean);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(CRIME_LOG_FILE, "LAUNDER", playerid, message);
    if (random(100) < 22)
    {
        Crime_AddWanted(playerid, 2);
        Crime_SendPoliceAlert(playerid, "movimentacao suspeita de dinheiro sujo");
    }
    SaveAccountNow(playerid, 0);
    return 1;
}

stock Crime_StartMission(playerid, missionType, reward, respect, wanted, action[])
{
    new escape = random(sizeof(gCrimeEscapeSpots));
    new message[160];
    new factionid = PlayerInfo[playerid][pCrimeFaction];

    if (!Crime_RequireFaction(playerid) || !Crime_RequireLevel(playerid))
    {
        return 1;
    }
    if (gCrimeMissionType[playerid] != CRIME_MISSION_NONE)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce ja possui missao criminal ativa. Va ao checkpoint de fuga.");
        return 1;
    }
    if (!Crime_CheckCooldown(playerid) || !Crime_CanEarn(playerid, reward))
    {
        return 1;
    }

    gCrimeMissionType[playerid] = missionType;
    gCrimeMissionReward[playerid] = reward;
    gCrimeMissionRespect[playerid] = respect;
    gCrimeMissionWanted[playerid] = wanted;
    Crime_SetCooldown(playerid, CRIME_PLAYER_COOLDOWN);
    Crime_AddWanted(playerid, wanted);
    SetPlayerCheckpoint(playerid, gCrimeEscapeSpots[escape][crimeSpotX], gCrimeEscapeSpots[escape][crimeSpotY], gCrimeEscapeSpots[escape][crimeSpotZ], 4.0);
    format(message, sizeof(message), "%s iniciado. Fuja ate o checkpoint para concluir.", action);
    SendClientMessage(playerid, COLOR_ORANGE, message);
    Crime_SendPoliceAlert(playerid, action);
    format(message, sizeof(message), "type=%d reward=%d respect=%d wanted=%d faction=%d", missionType, reward, respect, wanted, factionid);
    WritePlayerLog(CRIME_LOG_FILE, "MISSION_START", playerid, message);
    SaveAccountNow(playerid, 0);
    return 1;
}

stock Crime_MissionAtm(playerid)
{
    if (!World_IsPlayerAtAtm(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar perto de um caixa eletronico.");
        return 1;
    }
    return Crime_StartMission(playerid, CRIME_MISSION_ATM, 1600 + random(900), 3, 2, "roubo de ATM");
}

stock Crime_MissionBank(playerid)
{
    if (!World_IsPlayerAtBankBranch(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar perto do banco.");
        return 1;
    }
    return Crime_StartMission(playerid, CRIME_MISSION_BANK, 4200 + random(1800), 7, 4, "roubo ao banco");
}

stock Crime_MissionVehicle(playerid)
{
    if (!IsPlayerInAnyVehicle(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar em um veiculo para iniciar roubo de veiculo.");
        return 1;
    }
    return Crime_StartMission(playerid, CRIME_MISSION_VEHICLE, 1300 + random(700), 2, 2, "roubo de veiculo");
}

stock Crime_MissionStore(playerid)
{
    if (!Crime_IsNearStoreRobberyPoint(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar perto de uma conveniencia ou posto.");
        return 1;
    }
    return Crime_StartMission(playerid, CRIME_MISSION_STORE, 1900 + random(900), 3, 3, "roubo a loja");
}

stock Crime_MissionCargo(playerid)
{
    if (!Crime_IsNearCargoRobberyPoint(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar perto de uma central de entregas ou cargas.");
        return 1;
    }
    return Crime_StartMission(playerid, CRIME_MISSION_CARGO, 2400 + random(1100), 4, 3, "roubo de carga");
}

stock Crime_MissionAttack(playerid)
{
    if (
        !World_IsPlayerNearLocation(playerid, LOCATION_DELEGACIA, 18.0) &&
        !World_IsPlayerNearLocation(playerid, LOCATION_JOB_POLICIAL, 18.0) &&
        !World_IsPlayerNearLocation(playerid, LOCATION_JOB_PRF, 18.0) &&
        !World_IsPlayerNearLocation(playerid, LOCATION_JOB_POLICIA_FEDERAL, 18.0) &&
        !World_IsPlayerNearLocation(playerid, LOCATION_JOB_POLICIA_CIVIL, 18.0) &&
        !World_IsPlayerNearLocation(playerid, LOCATION_JOB_POLICIA_PENAL, 18.0)
    )
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar perto de uma unidade policial.");
        return 1;
    }
    return Crime_StartMission(playerid, CRIME_MISSION_ATTACK, 2600 + random(1200), 5, 4, "ataque RP a unidade policial");
}

stock Crime_OnPlayerEnterCheckpoint(playerid)
{
    new message[144];
    new failChance;

    if (gCrimeMissionType[playerid] == CRIME_MISSION_NONE)
    {
        return 0;
    }

    DisablePlayerCheckpoint(playerid);
    failChance = random(100);
    if (failChance < 18)
    {
        Crime_AddWanted(playerid, gCrimeMissionWanted[playerid] + 1);
        if (Inventory_GetAmount(playerid, INV_ITEM_ILLEGAL_PACKED) > 0)
        {
            Inventory_TakeItem(playerid, INV_ITEM_ILLEGAL_PACKED, 1, 0);
        }
        format(message, sizeof(message), "type=%d fail=1 wanted=%d", gCrimeMissionType[playerid], PlayerInfo[playerid][pWanted]);
        WritePlayerLog(CRIME_LOG_FILE, "MISSION_FAIL", playerid, message);
        SendClientMessage(playerid, COLOR_RED, "Missao falhou. A policia recebeu novas informacoes e parte do material pode ter sido perdida.");
        Crime_SendPoliceAlert(playerid, "falha em missao criminal");
        gCrimeMissionType[playerid] = CRIME_MISSION_NONE;
        gCrimeMissionReward[playerid] = 0;
        gCrimeMissionRespect[playerid] = 0;
        gCrimeMissionWanted[playerid] = 0;
        SaveAccountNow(playerid, 0);
        return 1;
    }

    Crime_GiveReward(playerid, gCrimeMissionReward[playerid], gCrimeMissionRespect[playerid], "crime_mission");
    format(message, sizeof(message), "type=%d reward=%d wanted=%d", gCrimeMissionType[playerid], gCrimeMissionReward[playerid], gCrimeMissionWanted[playerid]);
    WritePlayerLog(CRIME_LOG_FILE, "MISSION_DONE", playerid, message);
    gCrimeMissionType[playerid] = CRIME_MISSION_NONE;
    gCrimeMissionReward[playerid] = 0;
    gCrimeMissionRespect[playerid] = 0;
    gCrimeMissionWanted[playerid] = 0;
    SaveAccountNow(playerid, 0);
    return 1;
}

stock Crime_ReportTarget(playerid, targetid)
{
    new message[160];
    new targetName[MAX_PLAYER_NAME + 1];
    new contraband;

    if (targetid == playerid)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao pode denunciar a si mesmo.");
        return 1;
    }
    if (!IsPlayerConnected(targetid) || IsPlayerNPC(targetid) || !PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido ou nao logado.");
        return 1;
    }
    if (!Job_ArePlayersClose(playerid, targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar perto do suspeito para denunciar.");
        return 1;
    }

    contraband = Police_CountContrabandItems(targetid);
    GetPlayerNameEx(targetid, targetName, sizeof(targetName));
    if (PlayerInfo[targetid][pWanted] <= 0 && contraband <= 0)
    {
        format(message, sizeof(message), "Denuncia sem indicio contra ID %d %s.", targetid, targetName);
        WritePlayerLog(CRIME_LOG_FILE, "REPORT_EMPTY", playerid, message);
        SendClientMessage(playerid, COLOR_GRAY, "Denuncia registrada, mas sem indicio automatico detectado.");
        return 1;
    }

    format(message, sizeof(message), "Denuncia civil: ID %d %s | wanted %d | ilicitos %d", targetid, targetName, PlayerInfo[targetid][pWanted], contraband);
    Crime_SendPoliceAlert(targetid, "denuncia civil de atividade criminal");
    WritePlayerLog(CRIME_LOG_FILE, "REPORT_VALID", playerid, message);
    SendClientMessage(playerid, COLOR_GREEN, "Denuncia enviada para a policia.");
    return 1;
}

stock Crime_SeizeContraband(playerid, targetid)
{
    new itemid;
    new amount;
    new seized;
    new message[160];

    if (!IsLawEnforcementJob(PlayerInfo[playerid][pJob]))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policiais podem apreender itens criminais.");
        return 1;
    }
    if (!IsPlayerConnected(targetid) || IsPlayerNPC(targetid) || !PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido ou nao logado.");
        return 1;
    }
    if (!Job_ArePlayersClose(playerid, targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "O alvo precisa estar perto para apreensao.");
        return 1;
    }

    for (itemid = 1; itemid < INV_MAX_ITEMS; itemid++)
    {
        amount = Inventory_GetAmount(targetid, itemid);
        if (amount > 0 && Police_IsContrabandItem(itemid))
        {
            Inventory_TakeItem(targetid, itemid, amount, 0);
            seized += amount;
        }
    }

    if (seized <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Nenhum item ilicito encontrado para apreender.");
        return 1;
    }

    Crime_AddWanted(targetid, 2);
    format(message, sizeof(message), "apreensao target=%d itens=%d wanted=%d", targetid, seized, PlayerInfo[targetid][pWanted]);
    WritePlayerLog(CRIME_LOG_FILE, "SEIZE_CONTRABAND", playerid, message);
    WritePlayerLog(LOG_PUNISH_FILE, "POLICE_SEIZE_CRIME", playerid, message);
    SendClientMessage(playerid, COLOR_GREEN, "Itens ilicitos apreendidos e ficha atualizada.");
    SendClientMessage(targetid, COLOR_RED, "Itens ilicitos foram apreendidos pela policia.");
    SaveAccountNow(targetid, 0);
    return 1;
}

stock Crime_HandleCommands(playerid, cmdtext[])
{
    new command[32];
    new param[32];
    new index;
    new targetid;

    index = GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/apreendercrime", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/apreendercrime [id]");
        }
        return Crime_SeizeContraband(playerid, targetid);
    }
    if (strcmp(command, "/comprarsementeilegal", true) == 0)
    {
        return Crime_BuyIllegalSeed(playerid);
    }
    if (strcmp(command, "/crimeinfo", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return Crime_ShowInfo(playerid, playerid);
        }
        if (!ParseTargetPlayer(playerid, param, targetid))
        {
            return 1;
        }
        return Crime_ShowInfo(playerid, targetid);
    }
    if (strcmp(command, "/crimemissoes", true) == 0)
    {
        return Crime_ShowMissions(playerid);
    }
    if (strcmp(command, "/ocupacoesilegais", true) == 0 || strcmp(command, "/ocupacoescrime", true) == 0 || strcmp(command, "/crimeocupacoes", true) == 0)
    {
        return Crime_ShowOccupations(playerid);
    }
    if (strcmp(command, "/crimepontos", true) == 0)
    {
        return Crime_ShowPoints(playerid);
    }
    if (strcmp(command, "/denunciarcrime", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/denunciarcrime [id]");
        }
        return Crime_ReportTarget(playerid, targetid);
    }
    if (strcmp(command, "/faccoes", true) == 0)
    {
        return Crime_ShowFactions(playerid);
    }
    if (strcmp(command, "/entrarfaccao", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/entrarfaccao [id]");
        }
        return Crime_JoinFaction(playerid, strval(param));
    }
    if (strcmp(command, "/sairfaccao", true) == 0)
    {
        return Crime_LeaveFaction(playerid);
    }
    if (strcmp(command, "/faccaostatus", true) == 0)
    {
        return Crime_ShowStatus(playerid);
    }
    if (strcmp(command, "/lavardinheiro", true) == 0)
    {
        return Crime_LaunderMoney(playerid);
    }
    if (strcmp(command, "/plantar", true) == 0)
    {
        return Crime_Plant(playerid);
    }
    if (strcmp(command, "/colher", true) == 0)
    {
        return Crime_Harvest(playerid);
    }
    if (strcmp(command, "/produzir", true) == 0)
    {
        return Crime_Produce(playerid);
    }
    if (strcmp(command, "/venderprodutoilegal", true) == 0)
    {
        return Crime_SellIllegal(playerid);
    }
    if (strcmp(command, "/roubaratm", true) == 0)
    {
        return Crime_MissionAtm(playerid);
    }
    if (strcmp(command, "/roubarbanco", true) == 0)
    {
        return Crime_MissionBank(playerid);
    }
    if (strcmp(command, "/roubarloja", true) == 0)
    {
        return Crime_MissionStore(playerid);
    }
    if (strcmp(command, "/roubarcarga", true) == 0)
    {
        return Crime_MissionCargo(playerid);
    }
    if (strcmp(command, "/roubarveiculo", true) == 0)
    {
        return Crime_MissionVehicle(playerid);
    }
    if (strcmp(command, "/atacarunidade", true) == 0)
    {
        return Crime_MissionAttack(playerid);
    }
    return 0;
}
