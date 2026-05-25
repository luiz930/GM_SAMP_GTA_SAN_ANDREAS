#if defined _nova_needs_included
    #endinput
#endif
#define _nova_needs_included

#define CONV_DIALOG_ITEMS           (8)
#define REST_DIALOG_ITEMS           (6)
#define WEAPON_SHOP_DIALOG_ITEMS    (4)
#define SLEEP_LOW_VALUE             (65)
#define SLEEP_CRITICAL_VALUE        (95)
#define HOTEL_SLEEP_COST            (350)

enum eConvenienceItem
{
    convName[32],
    convPrice,
    convHunger,
    convThirst
}

new gConvenienceItems[][eConvenienceItem] =
{
    { "Agua mineral", 15, 0, 35 },
    { "Refrigerante", 25, 5, 25 },
    { "Cafe", 20, 0, 15 },
    { "Sanduiche natural", 35, 35, 5 },
    { "Salgado", 30, 28, 3 },
    { "Marmita", 60, 60, 8 },
    { "Combo refeicao", 85, 80, 45 },
    { "Kit viagem", 120, 100, 100 }
};

enum eRestaurantItem
{
    restName[32],
    restPrice,
    restHunger,
    restThirst
}

new gRestaurantItems[][eRestaurantItem] =
{
    { "Prato feito", 75, 70, 8 },
    { "Marmita executiva", 95, 85, 10 },
    { "Lanche completo", 55, 45, 15 },
    { "Suco natural", 30, 0, 35 },
    { "Cafe e pao", 35, 25, 15 },
    { "Refeicao reforcada", 130, 100, 30 }
};

enum eWeaponShopItem
{
    weaponShopName[32],
    weaponShopWeapon,
    weaponShopAmmo,
    weaponShopPrice
}

new gWeaponShopItems[][eWeaponShopItem] =
{
    { "9mm legal", WEAPON_COLT45, 50, 2500 },
    { "Escopeta civil", WEAPON_SHOTGUN, 20, 6500 },
    { "Rifle de caca", WEAPON_RIFLE, 18, 9000 },
    { "MP5 registrada", WEAPON_MP5, 80, 14000 }
};

new gConvDialogItems[MAX_PLAYERS][CONV_DIALOG_ITEMS];
new gConvDialogCount[MAX_PLAYERS];
new gRestDialogItems[MAX_PLAYERS][REST_DIALOG_ITEMS];
new gRestDialogCount[MAX_PLAYERS];
new gWeaponShopDialogItems[MAX_PLAYERS][WEAPON_SHOP_DIALOG_ITEMS];
new gWeaponShopDialogCount[MAX_PLAYERS];

new gNeedsTimer;

forward Needs_UpdateAll();

stock ClampNeedValue(value)
{
    if (value < 0)
    {
        return 0;
    }

    if (value > gCfgNeedsMaxValue)
    {
        return gCfgNeedsMaxValue;
    }

    return value;
}

stock Needs_AddPlayerValues(playerid, hunger, thirst, saveNow = 1)
{
    if (!PlayerInfo[playerid][pLogged])
    {
        return 0;
    }

    PlayerInfo[playerid][pHunger] = ClampNeedValue(PlayerInfo[playerid][pHunger] + hunger);
    PlayerInfo[playerid][pThirst] = ClampNeedValue(PlayerInfo[playerid][pThirst] + thirst);
    PlayerInfo[playerid][pNeedsWarningTick] = 0;
    UpdatePlayerHud(playerid);

    if (saveNow)
    {
        SaveAccountData(playerid, 0);
    }
    return 1;
}

stock Needs_AddRestValues(playerid, fatigue, sleepValue, saveNow = 1)
{
    if (!PlayerInfo[playerid][pLogged])
    {
        return 0;
    }

    PlayerInfo[playerid][pFatigue] = ClampNeedValue(PlayerInfo[playerid][pFatigue] + fatigue);
    PlayerInfo[playerid][pSleep] = ClampNeedValue(PlayerInfo[playerid][pSleep] + sleepValue);
    PlayerInfo[playerid][pNeedsWarningTick] = 0;
    UpdatePlayerHud(playerid);

    if (saveNow)
    {
        SaveAccountData(playerid, 0);
    }
    return 1;
}

stock Needs_SleepPlayer(playerid, atHotel = 0)
{
    new message[128];

    PlayerInfo[playerid][pFatigue] = 0;
    PlayerInfo[playerid][pSleep] = 0;
    PlayerInfo[playerid][pNeedsWarningTick] = 0;
    SetPlayerHealth(playerid, 100.0);
    Needs_AddPlayerValues(playerid, 10, 10, 0);
    ClearAnimations(playerid);
    SaveAccountData(playerid, 0);
    UpdatePlayerHud(playerid);
    format(message, sizeof(message), "Voce dormiu %s. Cansaco e sono zerados.", atHotel ? ("no hotel") : ("na residencia"));
    SendClientMessage(playerid, COLOR_GREEN, message);
    GameTextForPlayer(playerid, "~g~Voce descansou~n~~w~Sono e cansaco zerados", 4500, 3);
    return 1;
}

stock Needs_ShowRestStatus(playerid)
{
    new message[128];

    format(message, sizeof(message), "Cansaco: %d%% | Sono: %d%%. Durma em casa ou em um hotel.", PlayerInfo[playerid][pFatigue], PlayerInfo[playerid][pSleep]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}

stock Needs_ShowWarning(playerid)
{
    new tick = GetTickCount();

    if (PlayerInfo[playerid][pNeedsWarningTick] > 0 && (tick - PlayerInfo[playerid][pNeedsWarningTick]) < gCfgNeedsWarningInterval)
    {
        return 0;
    }

    PlayerInfo[playerid][pNeedsWarningTick] = tick;

    if (PlayerInfo[playerid][pHunger] <= gCfgNeedsLowValue && PlayerInfo[playerid][pThirst] <= gCfgNeedsLowValue)
    {
        GameTextForPlayer(playerid, "~r~Voce esta com fome e sede~n~~w~Procure uma conveniencia", 5000, 3);
        SendClientMessage(playerid, COLOR_ORANGE, "Voce esta com fome e sede. Compre comida ou bebida em uma conveniencia.");
        return 1;
    }

    if (PlayerInfo[playerid][pHunger] <= gCfgNeedsLowValue)
    {
        GameTextForPlayer(playerid, "~r~Voce esta com fome~n~~w~Procure uma conveniencia", 5000, 3);
        SendClientMessage(playerid, COLOR_ORANGE, "Voce esta com fome. Compre comida em uma conveniencia.");
        return 1;
    }

    if (PlayerInfo[playerid][pThirst] <= gCfgNeedsLowValue)
    {
        GameTextForPlayer(playerid, "~r~Voce esta com sede~n~~w~Procure uma conveniencia", 5000, 3);
        SendClientMessage(playerid, COLOR_ORANGE, "Voce esta com sede. Compre bebida em uma conveniencia.");
        return 1;
    }

    if (PlayerInfo[playerid][pSleep] >= SLEEP_LOW_VALUE || PlayerInfo[playerid][pFatigue] >= SLEEP_LOW_VALUE)
    {
        GameTextForPlayer(playerid, "~y~Voce esta cansado~n~~w~Durma em casa ou hotel", 5000, 3);
        SendClientMessage(playerid, COLOR_ORANGE, "Cansaco/sono alto. Va para sua casa, apartamento ou hotel e use /dormir.");
        return 1;
    }

    return 0;
}

stock Needs_ApplyCriticalDamage(playerid)
{
    new Float:health;

    if (PlayerInfo[playerid][pHunger] > gCfgNeedsCriticalValue && PlayerInfo[playerid][pThirst] > gCfgNeedsCriticalValue && PlayerInfo[playerid][pSleep] < SLEEP_CRITICAL_VALUE)
    {
        return 0;
    }

    GetPlayerHealth(playerid, health);
    if (health <= gCfgNeedsStarveDamage + 1.0)
    {
        PlayerInfo[playerid][pHunger] = gCfgNeedsMinSafe;
        PlayerInfo[playerid][pThirst] = gCfgNeedsMinSafe;
        PlayerInfo[playerid][pFatigue] = 80;
        PlayerInfo[playerid][pSleep] = 80;
        Hospital_OnPlayerDeath(playerid);
        GameTextForPlayer(playerid, "~r~Voce desmaiou~n~~w~Necessidade extrema", 5000, 3);
        SendClientMessage(playerid, COLOR_RED, "Voce desmaiou por fome, sede ou sono extremo. Ao renascer, sera levado ao hospital.");
        SaveAccountData(playerid, 0);
        SetPlayerHealth(playerid, 0.0);
        return 1;
    }

    SetPlayerHealth(playerid, health - gCfgNeedsStarveDamage);
    GameTextForPlayer(playerid, "~r~Necessidade critica~n~~w~Sua vida esta caindo", 4000, 3);
    SendClientMessage(playerid, COLOR_RED, "Fome, sede ou sono em nivel critico. Sua vida esta diminuindo.");
    return 1;
}

stock Needs_UpdatePlayer(playerid)
{
    new tick;
    new updated;

    if (!PlayerInfo[playerid][pLogged])
    {
        return 0;
    }

    tick = GetTickCount();
    if (PlayerInfo[playerid][pNeedsTick] == 0)
    {
        PlayerInfo[playerid][pNeedsTick] = tick;
        return 0;
    }

    while ((tick - PlayerInfo[playerid][pNeedsTick]) >= gCfgNeedsUpdateInterval)
    {
        PlayerInfo[playerid][pNeedsTick] += gCfgNeedsUpdateInterval;
        PlayerInfo[playerid][pHunger] = ClampNeedValue(PlayerInfo[playerid][pHunger] - gCfgNeedsHungerLoss);
        PlayerInfo[playerid][pThirst] = ClampNeedValue(PlayerInfo[playerid][pThirst] - gCfgNeedsThirstLoss);
        PlayerInfo[playerid][pFatigue] = ClampNeedValue(PlayerInfo[playerid][pFatigue] + 1);
        if (PlayerInfo[playerid][pFatigue] >= 70)
        {
            PlayerInfo[playerid][pSleep] = ClampNeedValue(PlayerInfo[playerid][pSleep] + 2);
        }
        else if (PlayerInfo[playerid][pFatigue] >= 35)
        {
            PlayerInfo[playerid][pSleep] = ClampNeedValue(PlayerInfo[playerid][pSleep] + 1);
        }
        updated = 1;
    }

    if (!updated)
    {
        return 0;
    }

    Needs_ShowWarning(playerid);
    Needs_ApplyCriticalDamage(playerid);
    UpdatePlayerHud(playerid);
    return 1;
}

public Needs_UpdateAll()
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && PlayerInfo[playerid][pLogged])
        {
            Needs_UpdatePlayer(playerid);
        }
    }
    return 1;
}

stock Needs_OnPlayerSpawn(playerid)
{
    if (PlayerInfo[playerid][pHunger] < gCfgNeedsMinSafe)
    {
        PlayerInfo[playerid][pHunger] = gCfgNeedsMinSafe;
    }

    if (PlayerInfo[playerid][pThirst] < gCfgNeedsMinSafe)
    {
        PlayerInfo[playerid][pThirst] = gCfgNeedsMinSafe;
    }

    if (PlayerInfo[playerid][pFatigue] < 0) PlayerInfo[playerid][pFatigue] = 0;
    if (PlayerInfo[playerid][pSleep] < 0) PlayerInfo[playerid][pSleep] = 0;
    if (PlayerInfo[playerid][pFatigue] > NEEDS_MAX_VALUE) PlayerInfo[playerid][pFatigue] = NEEDS_MAX_VALUE;
    if (PlayerInfo[playerid][pSleep] > NEEDS_MAX_VALUE) PlayerInfo[playerid][pSleep] = NEEDS_MAX_VALUE;

    PlayerInfo[playerid][pNeedsTick] = GetTickCount();
    PlayerInfo[playerid][pNeedsWarningTick] = 0;
    return 1;
}

stock Needs_OnPlayerDisconnect(playerid)
{
    PlayerInfo[playerid][pNeedsTick] = 0;
    PlayerInfo[playerid][pNeedsWarningTick] = 0;
    gWeaponShopDialogCount[playerid] = 0;
    return 1;
}

stock WeaponShop_CanBuy(playerid, notify = 1)
{
    if (!World_IsPlayerAtWeaponShop(playerid))
    {
        if (notify) SendClientMessage(playerid, COLOR_RED, "Voce precisa estar no balcao da Ammu-Nation.");
        return 0;
    }
    if (!PlayerInfo[playerid][pLicensePolice])
    {
        if (notify) SendClientMessage(playerid, COLOR_RED, "Compra bloqueada. Voce precisa de Porte de Arma emitido na Prefeitura.");
        return 0;
    }
    if (PlayerInfo[playerid][pWanted] > 0 || PlayerInfo[playerid][pJailTime] > 0)
    {
        if (notify) SendClientMessage(playerid, COLOR_RED, "Compra bloqueada. Procurados ou presos nao podem comprar armas legalizadas.");
        return 0;
    }
    return 1;
}

stock ShowWeaponShopDialog(playerid)
{
    new list[768];
    new line[112];
    new index;

    if (!WeaponShop_CanBuy(playerid))
    {
        return 1;
    }

    list[0] = 0;
    strcat(list, "Arma\tPreco\tMunicao\n", sizeof(list));
    gWeaponShopDialogCount[playerid] = 0;

    for (index = 0; index < sizeof(gWeaponShopItems); index++)
    {
        if (gWeaponShopDialogCount[playerid] < WEAPON_SHOP_DIALOG_ITEMS)
        {
            gWeaponShopDialogItems[playerid][gWeaponShopDialogCount[playerid]] = index;
            gWeaponShopDialogCount[playerid]++;
        }
        format(line, sizeof(line), "%s\t$%d\t%d\n", gWeaponShopItems[index][weaponShopName], Cfg_Price(gWeaponShopItems[index][weaponShopPrice]), gWeaponShopItems[index][weaponShopAmmo]);
        strcat(list, line, sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_WEAPON_SHOP, DIALOG_STYLE_TABLIST_HEADERS, "Ammu-Nation - Venda legal", list, "Comprar", "Fechar");
    return 1;
}

stock HandleWeaponShopDialog(playerid, response, listitem)
{
    new item;
    new price;
    new message[144];

    if (!response)
    {
        return 1;
    }

    if (listitem < 0 || listitem >= gWeaponShopDialogCount[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Arma invalida.");
        return 1;
    }
    if (!WeaponShop_CanBuy(playerid))
    {
        return 1;
    }

    item = gWeaponShopDialogItems[playerid][listitem];
    price = Cfg_Price(gWeaponShopItems[item][weaponShopPrice]);
    if (!Bank_TakePayment(playerid, price, 0))
    {
        format(message, sizeof(message), "Voce precisa de $%d em dinheiro/banco para comprar esta arma.", price);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    GivePlayerWeapon(playerid, gWeaponShopItems[item][weaponShopWeapon], gWeaponShopItems[item][weaponShopAmmo]);
    format(message, sizeof(message), "Compra legalizada: %s por $%d. Porte valido apenas enquanto voce nao estiver procurado.", gWeaponShopItems[item][weaponShopName], price);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_CONTRACT_FILE, "WEAPON_SHOP", playerid, message);
    return 1;
}

stock ShowConvenienceStoreDialog(playerid)
{
    new list[768];
    new line[96];
    new index;

    list[0] = 0;
    strcat(list, "Produto\tPreco\tEfeito\n", sizeof(list));
    gConvDialogCount[playerid] = 0;

    for (index = 0; index < sizeof(gConvenienceItems); index++)
    {
        if (gConvDialogCount[playerid] < CONV_DIALOG_ITEMS)
        {
            gConvDialogItems[playerid][gConvDialogCount[playerid]] = index;
            gConvDialogCount[playerid]++;
        }
        format(line, sizeof(line), "%s\t$%d\tFome +%d / Sede +%d\n", gConvenienceItems[index][convName], Cfg_Price(gConvenienceItems[index][convPrice]), gConvenienceItems[index][convHunger], gConvenienceItems[index][convThirst]);
        strcat(list, line, sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_CONVENIENCE, DIALOG_STYLE_TABLIST_HEADERS, "Loja NPC - Comida e bebida", list, "Comprar", "Fechar");
    return 1;
}

stock Convenience_GivePurchasedItem(playerid, listitem)
{
    switch (listitem)
    {
        case 0:
        {
            Inventory_AddItem(playerid, INV_ITEM_WATER, 1, 0);
        }
        case 1:
        {
            Inventory_AddItem(playerid, INV_ITEM_SODA, 1, 0);
        }
        case 2:
        {
            Inventory_AddItem(playerid, INV_ITEM_SODA, 1, 0);
        }
        case 3:
        {
            Inventory_AddItem(playerid, INV_ITEM_SNACK, 1, 0);
        }
        case 4:
        {
            Inventory_AddItem(playerid, INV_ITEM_SNACK, 1, 0);
        }
        case 5:
        {
            Inventory_AddItem(playerid, INV_ITEM_MEAL, 1, 0);
        }
        case 6:
        {
            Inventory_AddItem(playerid, INV_ITEM_MEAL, 1, 0);
            Inventory_AddItem(playerid, INV_ITEM_SODA, 1, 0);
        }
        case 7:
        {
            Inventory_AddItem(playerid, INV_ITEM_MEAL, 1, 0);
            Inventory_AddItem(playerid, INV_ITEM_WATER, 2, 0);
        }
    }
    return 1;
}

stock HandleConvenienceStoreDialog(playerid, response, listitem)
{
    new message[144];
    new item;

    if (!response)
    {
        return 1;
    }

    if (listitem < 0 || listitem >= gConvDialogCount[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Produto invalido.");
        return 1;
    }
    item = gConvDialogItems[playerid][listitem];

    if (!World_IsPlayerAtNpcStore(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar no balcao de uma loja ou conveniencia.");
        return 1;
    }

    if (!Bank_TakePayment(playerid, Cfg_Price(gConvenienceItems[item][convPrice]), 0))
    {
        format(message, sizeof(message), "Voce precisa de $%d em dinheiro/banco para comprar este produto.", Cfg_Price(gConvenienceItems[item][convPrice]));
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    Convenience_GivePurchasedItem(playerid, item);
    SaveAccountData(playerid, 0);

    format(message, sizeof(message), "Voce comprou %s por $%d e guardou no inventario. Use /inventario.", gConvenienceItems[item][convName], Cfg_Price(gConvenienceItems[item][convPrice]));
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock ShowRestaurantDialog(playerid)
{
    new list[768];
    new line[96];
    new index;

    list[0] = 0;
    strcat(list, "Pedido\tPreco\tEfeito\n", sizeof(list));
    gRestDialogCount[playerid] = 0;

    for (index = 0; index < sizeof(gRestaurantItems); index++)
    {
        if (gRestDialogCount[playerid] < REST_DIALOG_ITEMS)
        {
            gRestDialogItems[playerid][gRestDialogCount[playerid]] = index;
            gRestDialogCount[playerid]++;
        }
        format(
            line,
            sizeof(line),
            "%s\t$%d\tFome +%d / Sede +%d\n",
            gRestaurantItems[index][restName],
            Cfg_Price(gRestaurantItems[index][restPrice]),
            gRestaurantItems[index][restHunger],
            gRestaurantItems[index][restThirst]
        );
        strcat(list, line, sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_RESTAURANT, DIALOG_STYLE_TABLIST_HEADERS, "Restaurante NPC - Cardapio", list, "Pedir", "Fechar");
    return 1;
}

stock HandleRestaurantDialog(playerid, response, listitem)
{
    new message[144];
    new item;

    if (!response)
    {
        return 1;
    }

    if (listitem < 0 || listitem >= gRestDialogCount[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Pedido invalido.");
        return 1;
    }
    item = gRestDialogItems[playerid][listitem];

    if (!World_IsPlayerAtRestaurant(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar no salao de um restaurante.");
        return 1;
    }

    if (!Bank_TakePayment(playerid, Cfg_Price(gRestaurantItems[item][restPrice]), 0))
    {
        format(message, sizeof(message), "Voce precisa de $%d em dinheiro/banco.", Cfg_Price(gRestaurantItems[item][restPrice]));
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    Needs_AddPlayerValues(playerid, gRestaurantItems[item][restHunger], gRestaurantItems[item][restThirst], 0);
    SaveAccountData(playerid, 0);

    format(message, sizeof(message), "Atendente NPC serviu %s por $%d.", gRestaurantItems[item][restName], Cfg_Price(gRestaurantItems[item][restPrice]));
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}
