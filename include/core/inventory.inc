#if defined _nova_inventory_included
    #endinput
#endif
#define _nova_inventory_included

#define INV_MAX_STACK_AMOUNT        (999)

new gInventoryAmount[MAX_PLAYERS][INV_MAX_ITEMS];
new gHomeStorageAmount[MAX_PLAYERS][INV_MAX_ITEMS];
new gInventoryDialogItems[MAX_PLAYERS][INV_MAX_ITEMS];
new gInventoryDialogCount[MAX_PLAYERS];

new gInventoryItemNames[INV_MAX_ITEMS][32] =
{
    "Nenhum",
    "Agua mineral",
    "Refrigerante",
    "Lanche",
    "Marmita",
    "Kit medico",
    "Ferramentas",
    "Isca",
    "Minerio",
    "Peixe",
    "Sementes",
    "Documentos",
    "Semente ilegal",
    "Planta ilegal",
    "Produto bruto",
    "Produto embalado",
    "Dinheiro sujo"
};

stock ResetPlayerInventory(playerid)
{
    new itemid;

    for (itemid = 0; itemid < INV_MAX_ITEMS; itemid++)
    {
        gInventoryAmount[playerid][itemid] = 0;
        gHomeStorageAmount[playerid][itemid] = 0;
    }
    return 1;
}

stock Inventory_IsValidItem(itemid)
{
    return (itemid > INV_ITEM_NONE && itemid < INV_MAX_ITEMS);
}

stock Inventory_GetAmount(playerid, itemid)
{
    if (!Inventory_IsValidItem(itemid))
    {
        return 0;
    }
    return gInventoryAmount[playerid][itemid];
}

stock Inventory_AddItem(playerid, itemid, amount, saveNow = 1)
{
    if (!Inventory_IsValidItem(itemid) || amount <= 0)
    {
        return 0;
    }

    gInventoryAmount[playerid][itemid] += amount;

    if (saveNow && PlayerInfo[playerid][pLogged])
    {
        SaveAccountNow(playerid, 0);
    }
    return 1;
}

stock Inventory_TakeItem(playerid, itemid, amount, saveNow = 1)
{
    if (!Inventory_IsValidItem(itemid) || amount <= 0)
    {
        return 0;
    }

    if (gInventoryAmount[playerid][itemid] < amount)
    {
        return 0;
    }

    gInventoryAmount[playerid][itemid] -= amount;

    if (saveNow && PlayerInfo[playerid][pLogged])
    {
        SaveAccountNow(playerid, 0);
    }
    return 1;
}

stock Inventory_GetItemName(itemid, output[], size = sizeof(output))
{
    if (!Inventory_IsValidItem(itemid))
    {
        format(output, size, "Item invalido");
        return 0;
    }

    format(output, size, "%s", gInventoryItemNames[itemid]);
    return 1;
}

stock SaveInventoryData(playerid, File:account)
{
    new itemid;
    new line[48];

    for (itemid = 1; itemid < INV_MAX_ITEMS; itemid++)
    {
        format(line, sizeof(line), "inv_%d=%d\r\n", itemid, gInventoryAmount[playerid][itemid]);
        fwrite(account, line);
        format(line, sizeof(line), "home_inv_%d=%d\r\n", itemid, gHomeStorageAmount[playerid][itemid]);
        fwrite(account, line);
    }
    return 1;
}

stock ApplyInventoryAccountField(playerid, key[], value[])
{
    new itemText[8];
    new itemid;

    if (strfind(key, "home_inv_", false) == 0)
    {
        strmid(itemText, key, 9, strlen(key), sizeof(itemText));
        if (!IsNumericString(itemText))
        {
            return 0;
        }

        itemid = strval(itemText);
        if (!Inventory_IsValidItem(itemid))
        {
            return 0;
        }

        gHomeStorageAmount[playerid][itemid] = strval(value);
        if (gHomeStorageAmount[playerid][itemid] < 0) gHomeStorageAmount[playerid][itemid] = 0;
        if (gHomeStorageAmount[playerid][itemid] > INV_MAX_STACK_AMOUNT) gHomeStorageAmount[playerid][itemid] = INV_MAX_STACK_AMOUNT;
        return 1;
    }

    if (strfind(key, "inv_", false) != 0)
    {
        return 0;
    }

    strmid(itemText, key, 4, strlen(key), sizeof(itemText));
    if (!IsNumericString(itemText))
    {
        return 0;
    }

    itemid = strval(itemText);
    if (!Inventory_IsValidItem(itemid))
    {
        return 0;
    }

    gInventoryAmount[playerid][itemid] = strval(value);
    if (gInventoryAmount[playerid][itemid] < 0)
    {
        gInventoryAmount[playerid][itemid] = 0;
    }
    if (gInventoryAmount[playerid][itemid] > INV_MAX_STACK_AMOUNT)
    {
        gInventoryAmount[playerid][itemid] = INV_MAX_STACK_AMOUNT;
    }
    return 1;
}

stock Inventory_RepairData(playerid, apply, report[], size)
{
    new itemid;
    new repairs;

    for (itemid = 1; itemid < INV_MAX_ITEMS; itemid++)
    {
        if (gInventoryAmount[playerid][itemid] < 0 || gInventoryAmount[playerid][itemid] > INV_MAX_STACK_AMOUNT)
        {
            repairs++;
            Account_AppendRepair(report, size, "inventario invalido");
            if (apply)
            {
                if (gInventoryAmount[playerid][itemid] < 0) gInventoryAmount[playerid][itemid] = 0;
                if (gInventoryAmount[playerid][itemid] > INV_MAX_STACK_AMOUNT) gInventoryAmount[playerid][itemid] = INV_MAX_STACK_AMOUNT;
            }
        }
        if (gHomeStorageAmount[playerid][itemid] < 0 || gHomeStorageAmount[playerid][itemid] > INV_MAX_STACK_AMOUNT)
        {
            repairs++;
            Account_AppendRepair(report, size, "bau invalido");
            if (apply)
            {
                if (gHomeStorageAmount[playerid][itemid] < 0) gHomeStorageAmount[playerid][itemid] = 0;
                if (gHomeStorageAmount[playerid][itemid] > INV_MAX_STACK_AMOUNT) gHomeStorageAmount[playerid][itemid] = INV_MAX_STACK_AMOUNT;
            }
        }
    }
    return repairs;
}

stock ShowInventoryDialog(playerid)
{
    new list[768];
    new line[64];
    new itemid;

    list[0] = 0;
    strcat(list, "Item\tQuantidade\n", sizeof(list));
    gInventoryDialogCount[playerid] = 0;

    for (itemid = 1; itemid < INV_MAX_ITEMS; itemid++)
    {
        gInventoryDialogItems[playerid][gInventoryDialogCount[playerid]] = itemid;
        gInventoryDialogCount[playerid]++;
        format(line, sizeof(line), "%s\t%d\n", gInventoryItemNames[itemid], gInventoryAmount[playerid][itemid]);
        strcat(list, line, sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_INVENTORY, DIALOG_STYLE_TABLIST_HEADERS, "Inventario", list, "Usar", "Fechar");
    return 1;
}

stock Inventory_GetItemFromListItem(playerid, listitem)
{
    if (listitem < 0 || listitem >= gInventoryDialogCount[playerid])
    {
        return INV_ITEM_NONE;
    }
    return gInventoryDialogItems[playerid][listitem];
}

stock Inventory_UseItem(playerid, itemid)
{
    new Float:health;
    new message[96];

    if (!Inventory_IsValidItem(itemid))
    {
        SendClientMessage(playerid, COLOR_RED, "Item invalido.");
        return 1;
    }

    if (gInventoryAmount[playerid][itemid] <= 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao possui este item.");
        return 1;
    }

    switch (itemid)
    {
        case INV_ITEM_WATER:
        {
            Inventory_TakeItem(playerid, itemid, 1, 0);
            Needs_AddPlayerValues(playerid, 0, 35, 0);
            SendClientMessage(playerid, COLOR_GREEN, "Voce bebeu agua mineral.");
        }
        case INV_ITEM_SODA:
        {
            Inventory_TakeItem(playerid, itemid, 1, 0);
            Needs_AddPlayerValues(playerid, 5, 25, 0);
            SendClientMessage(playerid, COLOR_GREEN, "Voce tomou um refrigerante.");
        }
        case INV_ITEM_SNACK:
        {
            Inventory_TakeItem(playerid, itemid, 1, 0);
            Needs_AddPlayerValues(playerid, 30, 5, 0);
            SendClientMessage(playerid, COLOR_GREEN, "Voce comeu um lanche.");
        }
        case INV_ITEM_MEAL:
        {
            Inventory_TakeItem(playerid, itemid, 1, 0);
            Needs_AddPlayerValues(playerid, 65, 10, 0);
            SendClientMessage(playerid, COLOR_GREEN, "Voce comeu uma marmita.");
        }
        case INV_ITEM_MEDKIT:
        {
            Inventory_TakeItem(playerid, itemid, 1, 0);
            GetPlayerHealth(playerid, health);
            health += 45.0;
            if (health > 100.0)
            {
                health = 100.0;
            }
            SetPlayerHealth(playerid, health);
            PlayerInfo[playerid][pInjury] = 0;
            SendClientMessage(playerid, COLOR_GREEN, "Voce usou um kit medico.");
        }
        case INV_ITEM_TOOLS:
        {
            SendClientMessage(playerid, COLOR_GRAY, "Ferramentas sao usadas por servicos de mecanico/tecnico.");
            return 1;
        }
        case INV_ITEM_BAIT:
        {
            SendClientMessage(playerid, COLOR_GRAY, "Isca sera usada no sistema de pesca.");
            return 1;
        }
        case INV_ITEM_ORE, INV_ITEM_FISH, INV_ITEM_SEEDS, INV_ITEM_ILLEGAL_SEED, INV_ITEM_ILLEGAL_PLANT, INV_ITEM_ILLEGAL_RAW, INV_ITEM_ILLEGAL_PACKED, INV_ITEM_DIRTY_MONEY:
        {
            SendClientMessage(playerid, COLOR_GRAY, "Este material sera usado em producao/venda.");
            return 1;
        }
        case INV_ITEM_DOCUMENTS:
        {
            SendClientMessage(playerid, COLOR_BLUE, "Seus documentos RP estao guardados no inventario.");
            return 1;
        }
        default:
        {
            SendClientMessage(playerid, COLOR_GRAY, "Este item ainda nao tem uso direto.");
            return 1;
        }
    }

    format(message, sizeof(message), "Fome: %d%% | Sede: %d%%.", PlayerInfo[playerid][pHunger], PlayerInfo[playerid][pThirst]);
    SendClientMessage(playerid, COLOR_YELLOW, message);
    SaveAccountNow(playerid, 0);
    UpdatePlayerHud(playerid);
    return 1;
}

stock HandleInventoryDialog(playerid, response, listitem)
{
    new itemid;

    if (!response)
    {
        return 1;
    }

    itemid = Inventory_GetItemFromListItem(playerid, listitem);
    Inventory_UseItem(playerid, itemid);
    return 1;
}

stock HandleInventoryCommands(playerid, cmdtext[])
{
    new command[32];
    new param[32];
    new index;
    new itemid;

    index = GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/inventario", true) == 0 || strcmp(command, "/inv", true) == 0)
    {
        ShowInventoryDialog(playerid);
        return 1;
    }

    if (strcmp(command, "/usaritem", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/usaritem [id do item]");
        }

        itemid = strval(param);
        Inventory_UseItem(playerid, itemid);
        return 1;
    }

    return 0;
}
