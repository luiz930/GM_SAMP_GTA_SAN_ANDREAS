#if defined _nova_money_included
    #endinput
#endif
#define _nova_money_included

stock NormalizePlayerCash(playerid)
{
    new nativeCash;
    new storedCash;
    new safeCash;
    new logLine[128];

    if (!IsValidConnectedPlayer(playerid))
    {
        return 0;
    }

    nativeCash = GetPlayerMoney(playerid);
    storedCash = PlayerInfo[playerid][pMoney];

    if (nativeCash < 0)
    {
        nativeCash = 0;
    }
    if (storedCash < 0)
    {
        storedCash = 0;
    }

    if (!PlayerInfo[playerid][pLogged])
    {
        PlayerInfo[playerid][pMoney] = nativeCash;
        return nativeCash;
    }

    if (nativeCash == storedCash)
    {
        return nativeCash;
    }

    if (storedCash > nativeCash)
    {
        safeCash = storedCash;
    }
    else if (Security_IsExpectedCash(playerid, nativeCash))
    {
        safeCash = nativeCash;
    }
    else
    {
        safeCash = storedCash;
    }

    format(logLine, sizeof(logLine), "cash_desync native=%d stored=%d normalized=%d", nativeCash, storedCash, safeCash);
    WritePlayerLog(LOG_MONEY_FILE, "MONEY_GUARD", playerid, logLine);
    PlayerInfo[playerid][pMoney] = safeCash;
    ResetPlayerMoney(playerid);
    GivePlayerMoney(playerid, safeCash);
    Security_SetExpectedCash(playerid, safeCash);
    return safeCash;
}

stock SyncPlayerCash(playerid)
{
    return NormalizePlayerCash(playerid);
}

stock SetPlayerCashCore(playerid, amount, saveNow, reason[])
{
    new oldAmount;
    new logLine[144];

    if (!IsValidConnectedPlayer(playerid))
    {
        return 0;
    }

    if (amount < 0)
    {
        amount = 0;
    }

    oldAmount = GetPlayerMoney(playerid);
    PlayerInfo[playerid][pMoney] = amount;
    ResetPlayerMoney(playerid);
    GivePlayerMoney(playerid, amount);
    Security_SetExpectedCash(playerid, amount);
    UpdatePlayerHud(playerid);

    if (PlayerInfo[playerid][pLogged] && oldAmount != amount)
    {
        format(logLine, sizeof(logLine), "cash %d -> %d delta=%d reason=%s", oldAmount, amount, amount - oldAmount, reason);
        WritePlayerLog(LOG_MONEY_FILE, "CASH", playerid, logLine);
    }

    if (PlayerInfo[playerid][pLogged])
    {
        if (saveNow)
        {
            SaveAccountNow(playerid, 0);
        }
        else
        {
            MarkAccountDirty(playerid);
        }
    }
    return 1;
}

stock SetPlayerCash(playerid, amount, saveNow = 0)
{
    return SetPlayerCashCore(playerid, amount, saveNow, "set_cash");
}

stock GivePlayerCashReason(playerid, amount, saveNow, reason[])
{
    new current;

    if (!IsValidConnectedPlayer(playerid))
    {
        return 0;
    }

    current = NormalizePlayerCash(playerid);
    return SetPlayerCashCore(playerid, current + amount, saveNow, reason);
}

stock GivePlayerCash(playerid, amount, saveNow = 0)
{
    return GivePlayerCashReason(playerid, amount, saveNow, "cash_gain");
}

stock TakePlayerCashReason(playerid, amount, saveNow, reason[])
{
    new current;

    if (!IsValidConnectedPlayer(playerid))
    {
        return 0;
    }

    if (amount <= 0)
    {
        return 1;
    }

    current = NormalizePlayerCash(playerid);
    if (current < amount)
    {
        return 0;
    }

    return SetPlayerCashCore(playerid, current - amount, saveNow, reason);
}

stock TakePlayerCash(playerid, amount, saveNow = 0)
{
    return TakePlayerCashReason(playerid, amount, saveNow, "cash_spend");
}
