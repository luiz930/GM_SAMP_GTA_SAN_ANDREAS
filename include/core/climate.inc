#if defined _nova_climate_included
    #endinput
#endif
#define _nova_climate_included

#define CLIMATE_PROFILE_CLEAR       (0)
#define CLIMATE_PROFILE_SUNNY       (1)
#define CLIMATE_PROFILE_PARTLY      (2)
#define CLIMATE_PROFILE_CLOUDY      (3)
#define CLIMATE_PROFILE_RAIN        (4)
#define CLIMATE_PROFILE_STORM       (5)
#define CLIMATE_PROFILE_FOG         (6)
#define CLIMATE_PROFILE_DRY_HEAT    (7)

enum E_CLIMATE_PROFILE
{
    clWeatherId,
    clName[CLIMATE_NAME_SIZE],
    clTempMin,
    clTempMax,
    clHumMin,
    clHumMax,
    clWindMin,
    clWindMax,
    clBaseChance
}

new const gClimateProfiles[][E_CLIMATE_PROFILE] =
{
    {0, "Ceu limpo", 23, 32, 45, 65, 4, 16, 22},
    {1, "Sol aberto", 25, 36, 35, 58, 5, 18, 18},
    {3, "Parcial nublado", 21, 31, 55, 78, 6, 22, 22},
    {4, "Nublado", 19, 28, 65, 86, 8, 26, 16},
    {8, "Chuva leve", 18, 26, 78, 96, 10, 30, 11},
    {16, "Temporal", 17, 25, 82, 99, 18, 48, 4},
    {9, "Neblina", 16, 24, 75, 96, 3, 12, 5},
    {11, "Calor seco", 29, 40, 25, 48, 5, 19, 2}
};

new gClimateTimer;
new gClimateProfile = CLIMATE_PROFILE_CLEAR;
new gClimateWeatherId = 0;
new gClimateTemp = 26;
new gClimateHumidity = 60;
new gClimateWind = 8;
new gClimateName[CLIMATE_NAME_SIZE] = "Ceu limpo";

forward Climate_UpdateAll();

stock Climate_IsRainProfile(profile)
{
    return (profile == CLIMATE_PROFILE_RAIN || profile == CLIMATE_PROFILE_STORM);
}

stock Climate_IsDrySeason(month)
{
    return (month >= 5 && month <= 8);
}

stock Climate_IsRainSeason(month)
{
    return (month >= 10 || month <= 3);
}

stock Climate_GetProfileChance(profile, month, hour)
{
    new chance = gClimateProfiles[profile][clBaseChance];

    if (Climate_IsRainSeason(month))
    {
        if (profile == CLIMATE_PROFILE_RAIN) chance += 10;
        if (profile == CLIMATE_PROFILE_STORM) chance += 5;
        if (profile == CLIMATE_PROFILE_CLOUDY || profile == CLIMATE_PROFILE_PARTLY) chance += 4;
        if (profile == CLIMATE_PROFILE_CLEAR || profile == CLIMATE_PROFILE_SUNNY) chance -= 4;
    }

    if (Climate_IsDrySeason(month))
    {
        if (profile == CLIMATE_PROFILE_CLEAR || profile == CLIMATE_PROFILE_SUNNY) chance += 7;
        if (profile == CLIMATE_PROFILE_DRY_HEAT) chance += 5;
        if (Climate_IsRainProfile(profile)) chance -= 6;
    }

    if (hour >= 0 && hour < 6)
    {
        if (profile == CLIMATE_PROFILE_FOG) chance += 8;
        if (profile == CLIMATE_PROFILE_DRY_HEAT || profile == CLIMATE_PROFILE_SUNNY) chance -= 8;
        if (profile == CLIMATE_PROFILE_CLEAR) chance += 2;
    }
    else if (hour >= 12 && hour <= 16)
    {
        if (profile == CLIMATE_PROFILE_SUNNY || profile == CLIMATE_PROFILE_DRY_HEAT) chance += 4;
        if (profile == CLIMATE_PROFILE_FOG) chance -= 6;
    }

    if (chance < 1)
    {
        chance = 1;
    }
    return chance;
}

stock Climate_GetTempOffset(month, hour)
{
    new offset;

    if (month == 12 || month == 1 || month == 2)
    {
        offset += 2;
    }
    else if (month >= 6 && month <= 8)
    {
        offset -= 4;
    }
    else if (month == 4 || month == 5 || month == 9)
    {
        offset -= 1;
    }

    if (hour >= 0 && hour < 6)
    {
        offset -= 5;
    }
    else if (hour >= 6 && hour < 10)
    {
        offset -= 2;
    }
    else if (hour >= 12 && hour <= 16)
    {
        offset += 3;
    }
    else if (hour >= 20)
    {
        offset -= 2;
    }

    return offset;
}

stock Climate_RandomBetween(minValue, maxValue)
{
    if (maxValue <= minValue)
    {
        return minValue;
    }
    return minValue + random((maxValue - minValue) + 1);
}

stock Climate_PickProfile(month, hour)
{
    new total;
    new profile;
    new chance;
    new roll;

    for (profile = 0; profile < sizeof(gClimateProfiles); profile++)
    {
        total += Climate_GetProfileChance(profile, month, hour);
    }

    roll = random(total);
    for (profile = 0; profile < sizeof(gClimateProfiles); profile++)
    {
        chance = Climate_GetProfileChance(profile, month, hour);
        if (roll < chance)
        {
            return profile;
        }
        roll -= chance;
    }

    return CLIMATE_PROFILE_CLEAR;
}

stock Climate_ApplyToPlayer(playerid)
{
    if (IsPlayerConnected(playerid))
    {
        SetPlayerWeather(playerid, gClimateWeatherId);
    }
    return 1;
}

stock Climate_ApplyToPlayers()
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    SetWeather(gClimateWeatherId);
    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid))
        {
            SetPlayerWeather(playerid, gClimateWeatherId);
        }
    }
    return 1;
}

stock Climate_FormatHud(dest[], size)
{
    format(dest, size, "Clima: %s %dC | U%d%% V%d", gClimateName, gClimateTemp, gClimateHumidity, gClimateWind);
    return 1;
}

stock Climate_FormatFull(dest[], size)
{
    format(dest, size, "%s\n\nTemperatura: %d C\nUmidade: %d%%\nVento: %d km/h\nID SA-MP: %d\nPerfil: %d\nAtualizacao: automatica/randomica a cada 10 minutos.",
        gClimateName,
        gClimateTemp,
        gClimateHumidity,
        gClimateWind,
        gClimateWeatherId,
        gClimateProfile
    );
    return 1;
}

stock Climate_ApplyProfile(profile, notify)
{
    new year;
    new month;
    new day;
    new hour;
    new minute;
    new second;
    new tempOffset;
    new message[128];

    GetBrasiliaDateTime(year, month, day, hour, minute, second);

    if (profile < 0 || profile >= sizeof(gClimateProfiles))
    {
        profile = CLIMATE_PROFILE_CLEAR;
    }

    gClimateProfile = profile;
    gClimateWeatherId = gClimateProfiles[profile][clWeatherId];
    format(gClimateName, sizeof(gClimateName), "%s", gClimateProfiles[profile][clName]);

    tempOffset = Climate_GetTempOffset(month, hour);
    gClimateTemp = Climate_RandomBetween(gClimateProfiles[profile][clTempMin], gClimateProfiles[profile][clTempMax]) + tempOffset;
    gClimateHumidity = Climate_RandomBetween(gClimateProfiles[profile][clHumMin], gClimateProfiles[profile][clHumMax]);
    gClimateWind = Climate_RandomBetween(gClimateProfiles[profile][clWindMin], gClimateProfiles[profile][clWindMax]);

    if (gClimateTemp < 8) gClimateTemp = 8;
    if (gClimateTemp > 45) gClimateTemp = 45;

    Climate_ApplyToPlayers();

    if (notify)
    {
        format(message, sizeof(message), "[CLIMA] %s, %d C, umidade %d%%, vento %d km/h.", gClimateName, gClimateTemp, gClimateHumidity, gClimateWind);
        SendClientMessageToAll(COLOR_BLUE, message);
    }
    return 1;
}

stock Climate_Randomize(notify)
{
    new year;
    new month;
    new day;
    new hour;
    new minute;
    new second;
    new profile;

    GetBrasiliaDateTime(year, month, day, hour, minute, second);
    profile = Climate_PickProfile(month, hour);
    return Climate_ApplyProfile(profile, notify);
}

stock Climate_FindProfileByWeather(weatherid)
{
    new profile;

    for (profile = 0; profile < sizeof(gClimateProfiles); profile++)
    {
        if (gClimateProfiles[profile][clWeatherId] == weatherid)
        {
            return profile;
        }
    }
    return -1;
}

stock Climate_SetManual(weatherid, notify)
{
    new profile = Climate_FindProfileByWeather(weatherid);
    new message[128];

    if (weatherid < 0 || weatherid > 255)
    {
        return 0;
    }

    if (profile != -1)
    {
        Climate_ApplyProfile(profile, 0);
    }
    else
    {
        gClimateProfile = -1;
        gClimateWeatherId = weatherid;
        format(gClimateName, sizeof(gClimateName), "Clima manual");
        gClimateTemp = 20 + random(15);
        gClimateHumidity = 40 + random(50);
        gClimateWind = 5 + random(25);
        Climate_ApplyToPlayers();
    }

    if (notify)
    {
        format(message, sizeof(message), "[CLIMA] Clima definido para ID %d (%s).", gClimateWeatherId, gClimateName);
        SendClientMessageToAll(COLOR_ORANGE, message);
    }
    return 1;
}

stock ShowClimateDialog(playerid)
{
    new body[512];

    Climate_FormatFull(body, sizeof(body));
    ShowPlayerDialog(playerid, DIALOG_CLIMATE_INFO, DIALOG_STYLE_MSGBOX, "Clima atual", body, "Fechar", "");
    return 1;
}

stock Climate_Init()
{
    Climate_Randomize(0);
    gClimateTimer = SetTimer("Climate_UpdateAll", CLIMATE_UPDATE_INTERVAL, 1);
    return 1;
}

stock Climate_Exit()
{
    if (gClimateTimer)
    {
        KillTimer(gClimateTimer);
        gClimateTimer = 0;
    }
    return 1;
}

public Climate_UpdateAll()
{
    Climate_Randomize(1);
    return 1;
}

stock Climate_HandleCommands(playerid, cmdtext[])
{
    new command[32];

    GetCommandName(cmdtext, command, sizeof(command));
    if (strcmp(command, "/clima", true) == 0 || strcmp(command, "/tempo", true) == 0)
    {
        return ShowClimateDialog(playerid);
    }
    return 0;
}
