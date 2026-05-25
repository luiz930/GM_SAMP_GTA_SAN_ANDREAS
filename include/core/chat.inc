#if defined _nova_chat_included
    #endinput
#endif
#define _nova_chat_included

stock SendClientMessageToLogged(color, message[])
{
    new targetid;
    new maxPlayers = GetMaxPlayers();

    for (targetid = 0; targetid < maxPlayers; targetid++)
    {
        if (IsPlayerConnected(targetid) && PlayerInfo[targetid][pLogged])
        {
            SendClientMessage(targetid, color, message);
        }
    }

    return 1;
}

stock SendLocalChatMessage(playerid, text[])
{
    new targetid;
    new maxPlayers = GetMaxPlayers();
    new name[MAX_PLAYER_NAME + 1];
    new vipName[24];
    new message[144];
    new Float:x;
    new Float:y;
    new Float:z;
    new interior;
    new virtualWorld;

    GetPlayerNameEx(playerid, name, sizeof(name));
    Vip_GetPlayerName(playerid, vipName, sizeof(vipName));
    GetPlayerPos(playerid, x, y, z);
    interior = GetPlayerInterior(playerid);
    virtualWorld = GetPlayerVirtualWorld(playerid);

    if (Vip_GetLevel(playerid) > VIP_NONE)
    {
        format(message, sizeof(message), "[VIP %s] %s diz: %s", vipName, name, text);
    }
    else
    {
        format(message, sizeof(message), "%s diz: %s", name, text);
    }

    for (targetid = 0; targetid < maxPlayers; targetid++)
    {
        if (!IsPlayerConnected(targetid) || !PlayerInfo[targetid][pLogged])
        {
            continue;
        }

        if (GetPlayerInterior(targetid) != interior || GetPlayerVirtualWorld(targetid) != virtualWorld)
        {
            continue;
        }

        if (IsPlayerInRangeOfPoint(targetid, LOCAL_CHAT_DISTANCE, x, y, z))
        {
            SendClientMessage(targetid, COLOR_LOCAL, message);
        }
    }

    return 1;
}

stock SendGlobalChatMessage(playerid, text[])
{
    new name[MAX_PLAYER_NAME + 1];
    new vipName[24];
    new message[144];

    if (PlayerInfo[playerid][pMuteTime] > 0)
    {
        format(message, sizeof(message), "Voce esta mutado por mais %d segundos.", PlayerInfo[playerid][pMuteTime]);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    if (!Security_CheckChat(playerid, text))
    {
        return 1;
    }

    if (!Bot_CheckPlayerChat(playerid, text))
    {
        return 1;
    }

    GetPlayerNameEx(playerid, name, sizeof(name));
    Vip_GetPlayerName(playerid, vipName, sizeof(vipName));
    if (Vip_GetLevel(playerid) > VIP_NONE)
    {
        format(message, sizeof(message), "[Global][VIP %s] %s: %s", vipName, name, text);
    }
    else
    {
        format(message, sizeof(message), "[Global] %s: %s", name, text);
    }
    SendClientMessageToLogged(COLOR_GLOBAL, message);
    return 1;
}

stock SendAdminAnnouncement(playerid, text[])
{
    new name[MAX_PLAYER_NAME + 1];
    new rankName[32];
    new message[144];

    GetPlayerNameEx(playerid, name, sizeof(name));
    GetPlayerAdminRankName(playerid, rankName, sizeof(rankName));
    format(message, sizeof(message), "[ADMIN] %s %s: %s", rankName, name, text);
    SendClientMessageToAll(COLOR_ADMIN, message);
    return 1;
}

stock SendAdminChatMessage(playerid, text[])
{
    new targetid;
    new name[MAX_PLAYER_NAME + 1];
    new rankName[32];
    new message[144];
    new maxPlayers = GetMaxPlayers();

    GetPlayerNameEx(playerid, name, sizeof(name));
    GetPlayerAdminRankName(playerid, rankName, sizeof(rankName));
    format(message, sizeof(message), "[A] %s %s: %s", rankName, name, text);

    for (targetid = 0; targetid < maxPlayers; targetid++)
    {
        if (IsPlayerConnected(targetid) && PlayerInfo[targetid][pLogged] && HasAdminLevel(targetid, ADMIN_LEVEL_HELPER))
        {
            SendClientMessage(targetid, COLOR_ADMIN, message);
        }
    }
    return 1;
}

public OnPlayerText(playerid, text[])
{
    new message[96];

    if (!PlayerInfo[playerid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa fazer login antes de falar no chat.");
        ShowAuthDialog(playerid);
        return 0;
    }

    if (PlayerInfo[playerid][pMuteTime] > 0)
    {
        format(message, sizeof(message), "Voce esta mutado por mais %d segundos.", PlayerInfo[playerid][pMuteTime]);
        SendClientMessage(playerid, COLOR_RED, message);
        return 0;
    }

    if (!Security_CheckChat(playerid, text))
    {
        return 0;
    }

    if (!Bot_CheckPlayerChat(playerid, text))
    {
        return 0;
    }

    SendLocalChatMessage(playerid, text);
    return 0;
}
