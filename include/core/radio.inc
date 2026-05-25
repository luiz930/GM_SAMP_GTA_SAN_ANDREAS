#if defined _nova_radio_included
    #endinput
#endif
#define _nova_radio_included

enum eRadioAmbient
{
    ambientName[32],
    ambientStation[RADIO_NAME_SIZE],
    Float:ambientX,
    Float:ambientY,
    Float:ambientZ,
    ambientInterior,
    ambientVirtualWorld,
    Float:ambientRange
}

new gRadioNames[RADIO_MAX_STATIONS][RADIO_NAME_SIZE];
new gRadioUrls[RADIO_MAX_STATIONS][RADIO_URL_SIZE];
new gRadioCategories[RADIO_MAX_STATIONS][RADIO_CATEGORY_SIZE];
new gRadioCount;
new gRadioTimer;
new gPlayerRadioStation[MAX_PLAYERS];
new gPlayerRadioSource[MAX_PLAYERS];
new gPlayerRadioDialogMode[MAX_PLAYERS];
new gPlayerRadioDialogIndex[MAX_PLAYERS][RADIO_MAX_STATIONS];
new gPlayerRadioDialogCount[MAX_PLAYERS];
new gPlayerAmbientZone[MAX_PLAYERS];
new gVehicleRadioStation[MAX_VEHICLES];

new gLocalSoundActive;
new gLocalSoundStation;
new Float:gLocalSoundX;
new Float:gLocalSoundY;
new Float:gLocalSoundZ;
new Float:gLocalSoundRange;
new gLocalSoundInterior;
new gLocalSoundVirtualWorld;
new gLocalSoundAdmin[MAX_PLAYER_NAME + 1];

new gRadioAmbientZones[][eRadioAmbient] =
{
    { "Boate Alhambra", "Funk - RMC Disco Funk", 1836.8150, -1682.5210, 13.3320, 0, 0, 45.0 },
    { "Prefeitura", "TheRadio.CC", 386.5259, 173.6381, 1008.3828, 3, 1, 28.0 },
    { "Hospital", "Pop BR - Antena 1 SP", 1494.3252, 1304.9429, 1093.2891, 3, 102, 30.0 },
    { "Concessionaria", "Rock - Big R 90s Alternative", -2031.1196, -115.8281, 1035.1719, 3, 104, 30.0 },
    { "Loja Conveniencia 1", "Pop - Fun Radio", -25.8845, -185.8689, 1003.5469, 17, 130, 24.0 },
    { "Loja Conveniencia 2", "Pop - Fun Radio", -25.8845, -185.8689, 1003.5469, 17, 131, 24.0 },
    { "Posto Conveniencia", "Pop BR - Antena 1 SP", -25.8845, -185.8689, 1003.5469, 17, 111, 24.0 },
    { "Loja Comercial", "Pop - Fun Radio", -25.8845, -185.8689, 1003.5469, 17, 124, 24.0 },
    { "Restaurante Salao", "Funk - RMC Disco Funk", 363.1346, -74.8461, 1001.5078, 10, 122, 26.0 },
    { "Restaurante Cozinha", "Funk - RMC Disco Funk", 363.1346, -74.8461, 1001.5078, 10, 123, 26.0 }
};

forward Radio_UpdateAll();

stock Radio_GetField(line[], field, output[], size)
{
    new current;
    new start;
    new end;
    new length = strlen(line);

    while (current < field)
    {
        end = strfind(line, "|", false, start);
        if (end == -1)
        {
            output[0] = 0;
            return 0;
        }
        start = end + 1;
        current++;
    }

    end = strfind(line, "|", false, start);
    if (end == -1)
    {
        end = length;
    }

    strmid(output, line, start, end, size);
    return 1;
}

stock Radio_ResetPlayer(playerid)
{
    gPlayerRadioStation[playerid] = -1;
    gPlayerRadioSource[playerid] = RADIO_SOURCE_NONE;
    gPlayerRadioDialogMode[playerid] = RADIO_SOURCE_PERSONAL;
    gPlayerRadioDialogCount[playerid] = 0;
    gPlayerAmbientZone[playerid] = -1;
    return 1;
}

stock Radio_ResetVehicle(vehicleid)
{
    if (vehicleid <= 0 || vehicleid >= MAX_VEHICLES)
    {
        return 0;
    }

    gVehicleRadioStation[vehicleid] = -1;
    return 1;
}

stock Radio_Load()
{
    new File:file;
    new line[256];
    new name[RADIO_NAME_SIZE];
    new url[RADIO_URL_SIZE];
    new category[RADIO_CATEGORY_SIZE];

    gRadioCount = 0;

    if (!fexist(RADIO_PLAYLIST_FILE))
    {
        return 0;
    }

    file = fopen(RADIO_PLAYLIST_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (line[0] == 0 || line[0] == '#')
        {
            continue;
        }

        if (!Radio_GetField(line, 0, name, sizeof(name)) || !Radio_GetField(line, 1, url, sizeof(url)) || !Radio_GetField(line, 2, category, sizeof(category)))
        {
            continue;
        }

        if (name[0] == 0 || url[0] == 0 || category[0] == 0)
        {
            continue;
        }

        format(gRadioNames[gRadioCount], RADIO_NAME_SIZE, "%s", name);
        format(gRadioUrls[gRadioCount], RADIO_URL_SIZE, "%s", url);
        format(gRadioCategories[gRadioCount], RADIO_CATEGORY_SIZE, "%s", category);
        gRadioCount++;

        if (gRadioCount >= RADIO_MAX_STATIONS)
        {
            break;
        }
    }

    fclose(file);
    return gRadioCount;
}

stock Radio_Init()
{
    new vehicleid;

    Ops_CreateFileIfMissing(
        RADIO_PLAYLIST_FILE,
        "# Formato: nome|url|categoria\r\n# Use URL direta de audio: mp3, aac, ogg, stream Icecast/Shoutcast ou playlist compativel.\r\nTheRadio.CC|http://mp3.theradio.cc/|CC Pop/Rock\r\n"
    );

    for (vehicleid = 0; vehicleid < MAX_VEHICLES; vehicleid++)
    {
        gVehicleRadioStation[vehicleid] = -1;
    }

    gLocalSoundActive = 0;
    gLocalSoundStation = -1;
    Radio_Load();

    if (gRadioTimer)
    {
        KillTimer(gRadioTimer);
    }
    gRadioTimer = SetTimer("Radio_UpdateAll", RADIO_UPDATE_INTERVAL, 1);
    return 1;
}

stock Radio_Exit()
{
    if (gRadioTimer)
    {
        KillTimer(gRadioTimer);
        gRadioTimer = 0;
    }
    return 1;
}

stock Radio_FindStationByName(stationName[])
{
    new stationid;

    for (stationid = 0; stationid < gRadioCount; stationid++)
    {
        if (strcmp(gRadioNames[stationid], stationName, true) == 0)
        {
            return stationid;
        }
    }
    return -1;
}

stock Radio_IsPlayerInLocalSound(playerid)
{
    if (!gLocalSoundActive || gLocalSoundStation < 0 || gLocalSoundStation >= gRadioCount)
    {
        return 0;
    }

    if (GetPlayerInterior(playerid) != gLocalSoundInterior || GetPlayerVirtualWorld(playerid) != gLocalSoundVirtualWorld)
    {
        return 0;
    }

    return IsPlayerInRangeOfPoint(playerid, gLocalSoundRange, gLocalSoundX, gLocalSoundY, gLocalSoundZ);
}

stock Radio_FindAmbientZone(playerid)
{
    new zoneid;

    for (zoneid = 0; zoneid < sizeof(gRadioAmbientZones); zoneid++)
    {
        if (GetPlayerInterior(playerid) != gRadioAmbientZones[zoneid][ambientInterior])
        {
            continue;
        }

        if (GetPlayerVirtualWorld(playerid) != gRadioAmbientZones[zoneid][ambientVirtualWorld])
        {
            continue;
        }

        if (IsPlayerInRangeOfPoint(playerid, gRadioAmbientZones[zoneid][ambientRange], gRadioAmbientZones[zoneid][ambientX], gRadioAmbientZones[zoneid][ambientY], gRadioAmbientZones[zoneid][ambientZ]))
        {
            return zoneid;
        }
    }
    return -1;
}

stock Radio_PlayPlayerStation(playerid, stationid, source)
{
    if (stationid < 0 || stationid >= gRadioCount)
    {
        return 0;
    }

    PlayAudioStreamForPlayer(playerid, gRadioUrls[stationid]);
    gPlayerRadioStation[playerid] = stationid;
    gPlayerRadioSource[playerid] = source;
    gPlayerAmbientZone[playerid] = -1;
    return 1;
}

stock Radio_PlayPositionedStation(playerid, stationid, source, Float:x, Float:y, Float:z, Float:range)
{
    if (stationid < 0 || stationid >= gRadioCount)
    {
        return 0;
    }

    PlayAudioStreamForPlayer(playerid, gRadioUrls[stationid], x, y, z, range, 1);
    gPlayerRadioStation[playerid] = stationid;
    gPlayerRadioSource[playerid] = source;
    return 1;
}

stock Radio_StopPlayer(playerid, notify = 0)
{
    StopAudioStreamForPlayer(playerid);
    gPlayerRadioStation[playerid] = -1;
    gPlayerRadioSource[playerid] = RADIO_SOURCE_NONE;
    gPlayerAmbientZone[playerid] = -1;

    if (notify)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Radio desligada.");
    }
    return 1;
}

stock Radio_PlayVehicleForPlayer(playerid, vehicleid)
{
    new stationid;

    if (vehicleid <= 0 || vehicleid >= MAX_VEHICLES)
    {
        return 0;
    }

    stationid = gVehicleRadioStation[vehicleid];
    if (stationid < 0 || stationid >= gRadioCount)
    {
        return 0;
    }

    if (gPlayerRadioSource[playerid] == RADIO_SOURCE_PERSONAL)
    {
        return 0;
    }

    return Radio_PlayPlayerStation(playerid, stationid, RADIO_SOURCE_VEHICLE);
}

stock Radio_PlayVehicleForOccupants(vehicleid)
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && PlayerInfo[playerid][pLogged] && IsPlayerInVehicle(playerid, vehicleid))
        {
            Radio_PlayVehicleForPlayer(playerid, vehicleid);
        }
    }
    return 1;
}

stock Radio_StopVehicleStation(vehicleid, notify = 0)
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    if (vehicleid <= 0 || vehicleid >= MAX_VEHICLES)
    {
        return 0;
    }

    gVehicleRadioStation[vehicleid] = -1;

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && gPlayerRadioSource[playerid] == RADIO_SOURCE_VEHICLE && IsPlayerInVehicle(playerid, vehicleid))
        {
            Radio_StopPlayer(playerid, notify);
        }
    }
    return 1;
}

stock Radio_ShowDialog(playerid, mode = RADIO_SOURCE_PERSONAL)
{
    new list[3072];
    new row[144];
    new index;
    new count;

    if (mode == RADIO_SOURCE_VEHICLE)
    {
        if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce precisa estar dirigindo para ligar a radio do veiculo.");
            return 1;
        }
    }

    if (gRadioCount <= 0)
    {
        Radio_Load();
    }

    if (gRadioCount <= 0)
    {
        ShowPlayerDialog(playerid, DIALOG_RADIO_LIST, DIALOG_STYLE_MSGBOX, "Radios", "Nenhuma radio cadastrada em music_playlists.txt.", "Fechar", "");
        return 1;
    }

    gPlayerRadioDialogMode[playerid] = mode;
    format(list, sizeof(list), "ID\tRadio\tCategoria\n");
    for (index = 0; index < gRadioCount && count < RADIO_MAX_STATIONS; index++)
    {
        format(row, sizeof(row), "%d\t%s\t%s\n", index + 1, gRadioNames[index], gRadioCategories[index]);
        strcat(list, row, sizeof(list));
        gPlayerRadioDialogIndex[playerid][count] = index;
        count++;
    }

    gPlayerRadioDialogCount[playerid] = count;
    ShowPlayerDialog(playerid, DIALOG_RADIO_LIST, DIALOG_STYLE_TABLIST_HEADERS, mode == RADIO_SOURCE_VEHICLE ? ("Radio do veiculo") : ("Radios e playlists"), list, "Tocar", "Fechar");
    return 1;
}

stock Radio_PlayStation(playerid, stationid)
{
    new message[144];
    new vehicleid;

    if (stationid < 0 || stationid >= gRadioCount)
    {
        SendClientMessage(playerid, COLOR_RED, "Radio invalida.");
        return 1;
    }

    if (gPlayerRadioDialogMode[playerid] == RADIO_SOURCE_VEHICLE)
    {
        if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce precisa estar dirigindo para ligar a radio do veiculo.");
            return 1;
        }

        vehicleid = GetPlayerVehicleID(playerid);
        gVehicleRadioStation[vehicleid] = stationid;
        Radio_PlayVehicleForOccupants(vehicleid);
        format(message, sizeof(message), "Radio do veiculo: %s. Passageiros tambem escutam.", gRadioNames[stationid]);
        SendClientMessage(playerid, COLOR_GREEN, message);
        return 1;
    }

    Radio_PlayPlayerStation(playerid, stationid, RADIO_SOURCE_PERSONAL);
    format(message, sizeof(message), "Tocando radio pessoal: %s (%s). Use /pararradio para parar.", gRadioNames[stationid], gRadioCategories[stationid]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Radio_PlayDefaultStation(playerid, mode = RADIO_SOURCE_PERSONAL)
{
    if (gRadioCount <= 0)
    {
        Radio_Load();
    }

    if (gRadioCount <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Nenhuma radio cadastrada em music_playlists.txt.");
        return 1;
    }

    gPlayerRadioDialogMode[playerid] = mode;
    return Radio_PlayStation(playerid, 0);
}

stock Radio_Stop(playerid)
{
    return Radio_StopPlayer(playerid, 1);
}

stock Radio_HandleListDialog(playerid, response, listitem)
{
    if (!response)
    {
        return 1;
    }

    if (listitem < 0 || listitem >= gPlayerRadioDialogCount[playerid])
    {
        return Radio_ShowDialog(playerid, gPlayerRadioDialogMode[playerid]);
    }

    return Radio_PlayStation(playerid, gPlayerRadioDialogIndex[playerid][listitem]);
}

stock Radio_StartLocalSound(playerid, stationid, Float:range)
{
    new message[160];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_ADMIN))
    {
        return SendNoPermission(playerid);
    }

    if (stationid < 0 || stationid >= gRadioCount)
    {
        SendClientMessage(playerid, COLOR_RED, "Radio invalida. Use /radio para ver os IDs.");
        return 1;
    }

    if (range <= 0.0)
    {
        range = RADIO_LOCAL_DEFAULT_RANGE;
    }
    if (range > RADIO_LOCAL_MAX_RANGE)
    {
        range = RADIO_LOCAL_MAX_RANGE;
    }

    GetPlayerPos(playerid, gLocalSoundX, gLocalSoundY, gLocalSoundZ);
    gLocalSoundInterior = GetPlayerInterior(playerid);
    gLocalSoundVirtualWorld = GetPlayerVirtualWorld(playerid);
    gLocalSoundRange = range;
    gLocalSoundStation = stationid;
    gLocalSoundActive = 1;
    GetPlayerNameEx(playerid, gLocalSoundAdmin, sizeof(gLocalSoundAdmin));

    format(message, sizeof(message), "Som local iniciado: %s | raio %.0fm.", gRadioNames[stationid], range);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_ADMIN_FILE, "LOCAL_SOUND", playerid, message);
    Radio_UpdateAll();
    return 1;
}

stock Radio_StopLocalSound(playerid)
{
    new player;
    new maxPlayers = GetMaxPlayers();

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_ADMIN))
    {
        return SendNoPermission(playerid);
    }

    gLocalSoundActive = 0;
    gLocalSoundStation = -1;

    for (player = 0; player < maxPlayers; player++)
    {
        if (IsPlayerConnected(player) && gPlayerRadioSource[player] == RADIO_SOURCE_LOCAL)
        {
            Radio_StopPlayer(player, 0);
        }
    }

    SendClientMessage(playerid, COLOR_ORANGE, "Som local encerrado.");
    WritePlayerLog(LOG_ADMIN_FILE, "LOCAL_SOUND_STOP", playerid, "som local encerrado");
    return 1;
}

stock Radio_UpdatePlayer(playerid)
{
    new vehicleid;
    new zoneid;
    new stationid;

    if (!IsPlayerConnected(playerid) || !PlayerInfo[playerid][pLogged])
    {
        return 0;
    }

    if (gPlayerRadioSource[playerid] == RADIO_SOURCE_VEHICLE)
    {
        if (!IsPlayerInAnyVehicle(playerid))
        {
            Radio_StopPlayer(playerid, 0);
        }
        else
        {
            vehicleid = GetPlayerVehicleID(playerid);
            if (gVehicleRadioStation[vehicleid] != gPlayerRadioStation[playerid])
            {
                Radio_PlayVehicleForPlayer(playerid, vehicleid);
            }
            return 1;
        }
    }

    if (Radio_IsPlayerInLocalSound(playerid))
    {
        if (gPlayerRadioSource[playerid] == RADIO_SOURCE_NONE || gPlayerRadioSource[playerid] == RADIO_SOURCE_AMBIENT || gPlayerRadioSource[playerid] == RADIO_SOURCE_LOCAL)
        {
            if (gPlayerRadioSource[playerid] != RADIO_SOURCE_LOCAL || gPlayerRadioStation[playerid] != gLocalSoundStation)
            {
                Radio_PlayPositionedStation(playerid, gLocalSoundStation, RADIO_SOURCE_LOCAL, gLocalSoundX, gLocalSoundY, gLocalSoundZ, gLocalSoundRange);
            }
            return 1;
        }
    }
    else if (gPlayerRadioSource[playerid] == RADIO_SOURCE_LOCAL)
    {
        Radio_StopPlayer(playerid, 0);
    }

    if (gPlayerRadioSource[playerid] == RADIO_SOURCE_PERSONAL || gPlayerRadioSource[playerid] == RADIO_SOURCE_VEHICLE)
    {
        return 1;
    }

    zoneid = Radio_FindAmbientZone(playerid);
    if (zoneid == -1)
    {
        if (gPlayerRadioSource[playerid] == RADIO_SOURCE_AMBIENT)
        {
            Radio_StopPlayer(playerid, 0);
        }
        return 0;
    }

    stationid = Radio_FindStationByName(gRadioAmbientZones[zoneid][ambientStation]);
    if (stationid == -1)
    {
        return 0;
    }

    if (gPlayerRadioSource[playerid] != RADIO_SOURCE_AMBIENT || gPlayerAmbientZone[playerid] != zoneid || gPlayerRadioStation[playerid] != stationid)
    {
        Radio_PlayPositionedStation(playerid, stationid, RADIO_SOURCE_AMBIENT, gRadioAmbientZones[zoneid][ambientX], gRadioAmbientZones[zoneid][ambientY], gRadioAmbientZones[zoneid][ambientZ], gRadioAmbientZones[zoneid][ambientRange]);
        gPlayerAmbientZone[playerid] = zoneid;
    }
    return 1;
}

public Radio_UpdateAll()
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        Radio_UpdatePlayer(playerid);
    }
    return 1;
}

stock Radio_OnPlayerStateChange(playerid, newstate, oldstate)
{
    new vehicleid;

    if (oldstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_PASSENGER)
    {
        if (gPlayerRadioSource[playerid] == RADIO_SOURCE_VEHICLE)
        {
            Radio_StopPlayer(playerid, 0);
        }
    }

    if (newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
    {
        vehicleid = GetPlayerVehicleID(playerid);
        if (gVehicleRadioStation[vehicleid] != -1 && gPlayerRadioSource[playerid] != RADIO_SOURCE_PERSONAL)
        {
            Radio_PlayVehicleForPlayer(playerid, vehicleid);
        }
    }
    return 1;
}

stock Radio_OnVehicleDestroyed(vehicleid)
{
    return Radio_ResetVehicle(vehicleid);
}

stock Radio_HandleCommands(playerid, cmdtext[])
{
    new command[32];
    new param[32];
    new param2[32];
    new message[128];
    new index;
    new stationid;
    new Float:range;
    new vehicleid;

    index = GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/radio", true) == 0)
    {
        gPlayerRadioDialogMode[playerid] = RADIO_SOURCE_PERSONAL;

        if (GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            if (strcmp(param, "parar", true) == 0 || strcmp(param, "off", true) == 0 || strcmp(param, "stop", true) == 0)
            {
                return Radio_Stop(playerid);
            }
            if (!IsNumericString(param))
            {
                return SendUsage(playerid, "/radio [id/parar]");
            }

            if (gRadioCount <= 0)
            {
                Radio_Load();
            }
            return Radio_PlayStation(playerid, strval(param) - 1);
        }

        if (gRadioCount <= 0)
        {
            Radio_Load();
        }
        SendClientMessage(playerid, COLOR_GRAY, "Use /radios para abrir a lista ou /radio [id] para escolher.");
        return Radio_PlayDefaultStation(playerid, RADIO_SOURCE_PERSONAL);
    }

    if (strcmp(command, "/radios", true) == 0 || strcmp(command, "/musica", true) == 0)
    {
        return Radio_ShowDialog(playerid, RADIO_SOURCE_PERSONAL);
    }

    if (strcmp(command, "/radioveiculo", true) == 0 || strcmp(command, "/radiocarro", true) == 0)
    {
        return Radio_ShowDialog(playerid, RADIO_SOURCE_VEHICLE);
    }

    if (strcmp(command, "/pararradio", true) == 0 || strcmp(command, "/pararmusica", true) == 0 || strcmp(command, "/stopradio", true) == 0)
    {
        return Radio_Stop(playerid);
    }

    if (strcmp(command, "/pararradioveiculo", true) == 0 || strcmp(command, "/desligarradioveiculo", true) == 0)
    {
        if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce precisa estar dirigindo para desligar a radio do veiculo.");
            return 1;
        }

        vehicleid = GetPlayerVehicleID(playerid);
        Radio_StopVehicleStation(vehicleid, 1);
        return 1;
    }

    if (strcmp(command, "/somlocal", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/somlocal [id_radio/parar] [raio]");
        }

        if (strcmp(param, "parar", true) == 0 || strcmp(param, "off", true) == 0)
        {
            return Radio_StopLocalSound(playerid);
        }

        if (!IsNumericString(param))
        {
            return SendUsage(playerid, "/somlocal [id_radio/parar] [raio]");
        }

        stationid = strval(param) - 1;
        range = RADIO_LOCAL_DEFAULT_RANGE;
        if (GetNextParam(cmdtext, index, param2, sizeof(param2)))
        {
            range = floatstr(param2);
        }
        return Radio_StartLocalSound(playerid, stationid, range);
    }

    if (strcmp(command, "/pararsomlocal", true) == 0)
    {
        return Radio_StopLocalSound(playerid);
    }

    if (strcmp(command, "/reloadradio", true) == 0)
    {
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_ADMIN))
        {
            return SendNoPermission(playerid);
        }

        Radio_Load();
        format(message, sizeof(message), "Radios recarregadas: %d estacoes.", gRadioCount);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        WritePlayerLog(LOG_ADMIN_FILE, "RELOAD_RADIO", playerid, message);
        return 1;
    }

    return 0;
}
