#if defined _nova_vip_included
    #endinput
#endif
#define _nova_vip_included

#define VIP_NONE                    (0)
#define VIP_BRONZE                  (1)
#define VIP_PRATA                   (2)
#define VIP_OURO                    (3)
#define VIP_DIAMANTE                (4)
#define VIP_MENU_ACTIONS            (6)
#define VIP_ACT_PLANS               (1)
#define VIP_ACT_BUY                 (2)
#define VIP_ACT_KIT                 (3)
#define VIP_ACT_BENEFITS            (4)
#define VIP_ACT_ACTIVATE            (5)
#define VIP_ACT_ONLINE              (6)

enum eVipPlan
{
    vipPlanName[24],
    vipPrice,
    vipCashBonus,
    vipXpBonus,
    vipDiscount,
    vipExtraVehicles,
    vipKitCash,
    vipKitWater,
    vipKitFood,
    vipKitMedkit,
    vipKitTools
}

new gVipPlans[VIP_MAX_LEVEL + 1][eVipPlan] =
{
    { "Nenhum", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { "Bronze", 15, 5, 5, 5, 1, 1200, 1, 1, 0, 0 },
    { "Prata", 25, 8, 10, 8, 1, 2200, 2, 2, 1, 0 },
    { "Ouro", 40, 12, 15, 12, 2, 3800, 3, 3, 1, 1 },
    { "Diamante", 60, 15, 20, 15, 3, 6000, 4, 4, 2, 2 }
};

new gVipTimer;
new gVipDialogActions[MAX_PLAYERS][VIP_MENU_ACTIONS];
new gVipDialogActionCount[MAX_PLAYERS];

forward Vip_UpdateAll();

stock Vip_AddMenuAction(playerid, list[], size, actionid, label[])
{
    new line[96];

    if (gVipDialogActionCount[playerid] >= VIP_MENU_ACTIONS)
    {
        return 0;
    }

    gVipDialogActions[playerid][gVipDialogActionCount[playerid]] = actionid;
    gVipDialogActionCount[playerid]++;
    format(line, sizeof(line), "%s\n", label);
    strcat(list, line, size);
    return 1;
}

stock Vip_IsValidLevel(level)
{
    return (level >= VIP_NONE && level <= VIP_MAX_LEVEL);
}

stock Vip_GetPlanName(level, output[], size = sizeof(output))
{
    if (!Vip_IsValidLevel(level))
    {
        level = VIP_NONE;
    }

    format(output, size, "%s", gVipPlans[level][vipPlanName]);
    return 1;
}

stock Vip_IsActive(playerid)
{
    return (PlayerInfo[playerid][pVipLevel] > VIP_NONE && PlayerInfo[playerid][pVipLevel] <= VIP_MAX_LEVEL && PlayerInfo[playerid][pVipExpire] > gettime());
}

stock Vip_ExpireIfNeeded(playerid, notify = 0)
{
    new oldLevel;
    new oldName[24];
    new details[96];

    if (PlayerInfo[playerid][pVipLevel] <= VIP_NONE)
    {
        return 0;
    }

    if (PlayerInfo[playerid][pVipExpire] <= 0 || PlayerInfo[playerid][pVipExpire] > gettime())
    {
        return 0;
    }

    oldLevel = PlayerInfo[playerid][pVipLevel];
    Vip_GetPlanName(oldLevel, oldName, sizeof(oldName));
    PlayerInfo[playerid][pVipLevel] = VIP_NONE;
    PlayerInfo[playerid][pVipExpire] = 0;
    PlayerInfo[playerid][pVipLastKitDay] = 0;
    SaveAccountData(playerid, 0);

    format(details, sizeof(details), "expired level=%d name=%s", oldLevel, oldName);
    WritePlayerLog(LOG_VIP_FILE, "VIP_EXPIRE", playerid, details);

    if (notify)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Seu VIP expirou. Use /comprarvip para ver os planos.");
    }
    return 1;
}

stock Vip_GetLevel(playerid)
{
    if (Vip_ExpireIfNeeded(playerid, 0))
    {
        return VIP_NONE;
    }
    return Vip_IsActive(playerid) ? PlayerInfo[playerid][pVipLevel] : VIP_NONE;
}

stock Vip_GetPlayerName(playerid, output[], size = sizeof(output))
{
    return Vip_GetPlanName(Vip_GetLevel(playerid), output, size);
}

stock Vip_FormatRemaining(playerid, output[], size = sizeof(output))
{
    new remaining;
    new days;
    new hours;

    if (!Vip_IsActive(playerid))
    {
        format(output, size, "sem VIP ativo");
        return 1;
    }

    remaining = PlayerInfo[playerid][pVipExpire] - gettime();
    days = remaining / VIP_SECONDS_PER_DAY;
    hours = (remaining % VIP_SECONDS_PER_DAY) / 3600;

    if (days > 0)
    {
        format(output, size, "%d dias e %d horas", days, hours);
    }
    else
    {
        format(output, size, "%d horas", hours);
    }
    return 1;
}

stock Vip_GetCashBonusPercent(playerid)
{
    return gVipPlans[Vip_GetLevel(playerid)][vipCashBonus];
}

stock Vip_GetXpBonusPercent(playerid)
{
    return gVipPlans[Vip_GetLevel(playerid)][vipXpBonus];
}

stock Vip_GetDiscountPercent(playerid)
{
    return gVipPlans[Vip_GetLevel(playerid)][vipDiscount];
}

stock Vip_GetExtraVehicleSlots(playerid)
{
    return gVipPlans[Vip_GetLevel(playerid)][vipExtraVehicles];
}

stock Vip_ApplyCashBonus(playerid, amount)
{
    new percent = Vip_GetCashBonusPercent(playerid);

    if (amount <= 0 || percent <= 0)
    {
        return amount;
    }
    return amount + ((amount * percent) / 100);
}

stock Vip_ApplyXpBonus(playerid, xp)
{
    new percent = Vip_GetXpBonusPercent(playerid);

    if (xp <= 0 || percent <= 0)
    {
        return xp;
    }
    return xp + ((xp * percent) / 100);
}

stock Vip_ApplyDiscount(playerid, price)
{
    new percent = Vip_GetDiscountPercent(playerid);

    if (price <= 0 || percent <= 0)
    {
        return price;
    }
    return price - ((price * percent) / 100);
}

stock Vip_SetPlayer(playerid, level, days, source[], saveNow = 1)
{
    new baseTime;
    new expire;
    new vipName[24];
    new remaining[48];
    new message[144];
    new details[160];

    if (!Vip_IsValidLevel(level))
    {
        return 0;
    }

    if (level == VIP_NONE || days <= 0)
    {
        PlayerInfo[playerid][pVipLevel] = VIP_NONE;
        PlayerInfo[playerid][pVipExpire] = 0;
        PlayerInfo[playerid][pVipLastKitDay] = 0;

        if (saveNow)
        {
            SaveAccountData(playerid, 0);
        }

        format(details, sizeof(details), "removed source=%s", source);
        WritePlayerLog(LOG_VIP_FILE, "VIP_REMOVE", playerid, details);
        SendClientMessage(playerid, COLOR_ORANGE, "Seu VIP foi removido.");
        return 1;
    }

    baseTime = gettime();
    if (Vip_IsActive(playerid) && PlayerInfo[playerid][pVipExpire] > baseTime)
    {
        baseTime = PlayerInfo[playerid][pVipExpire];
    }

    expire = baseTime + (days * VIP_SECONDS_PER_DAY);
    PlayerInfo[playerid][pVipLevel] = level;
    PlayerInfo[playerid][pVipExpire] = expire;
    PlayerInfo[playerid][pVipTotalDays] += days;

    if (saveNow)
    {
        SaveAccountData(playerid, 0);
    }

    Vip_GetPlanName(level, vipName, sizeof(vipName));
    Vip_FormatRemaining(playerid, remaining, sizeof(remaining));
    format(message, sizeof(message), "VIP %s ativado por %d dias. Validade: %s.", vipName, days, remaining);
    SendClientMessage(playerid, COLOR_GREEN, message);

    format(details, sizeof(details), "level=%d days=%d expire=%d source=%s", level, days, PlayerInfo[playerid][pVipExpire], source);
    WritePlayerLog(LOG_VIP_FILE, "VIP_SET", playerid, details);
    UpdatePlayerHud(playerid);
    return 1;
}

stock Vip_ReadPipeToken(line[], &index, output[], size = sizeof(output))
{
    new offset;
    new length = strlen(line);

    output[0] = 0;
    while (index < length && line[index] == ' ')
    {
        index++;
    }

    while (index < length && line[index] != '|' && offset < (size - 1))
    {
        output[offset] = line[index];
        offset++;
        index++;
    }
    output[offset] = 0;

    if (index < length && line[index] == '|')
    {
        index++;
    }
    return (offset > 0);
}

stock Vip_GetGrantPath(playerid, path[], size = sizeof(path))
{
    new name[MAX_PLAYER_NAME + 1];

    GetPlayerNameEx(playerid, name, sizeof(name));
    format(path, size, "%s/%s.txt", VIP_GRANT_FOLDER, name);
    return 1;
}

stock Vip_ProcessGrantFile(playerid, notify = 1)
{
    new path[ACCOUNT_PATH_SIZE];
    new line[160];
    new token[64];
    new order[48];
    new source[48];
    new index;
    new level;
    new days;
    new grants;
    new File:file;
    new message[128];

    Vip_GetGrantPath(playerid, path, sizeof(path));
    if (!fexist(path))
    {
        if (notify)
        {
            SendClientMessage(playerid, COLOR_GRAY, "Nenhuma ativacao VIP pendente para sua conta.");
        }
        return 0;
    }

    file = fopen(path, io_read);
    if (!file)
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel ler sua ativacao VIP. Avise a administracao.");
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (line[0] == 0 || line[0] == '#')
        {
            continue;
        }

        index = 0;
        if (!Vip_ReadPipeToken(line, index, token, sizeof(token)) || !IsNumericString(token))
        {
            continue;
        }
        level = strval(token);

        if (!Vip_ReadPipeToken(line, index, token, sizeof(token)) || !IsNumericString(token))
        {
            continue;
        }
        days = strval(token);

        if (!Vip_ReadPipeToken(line, index, order, sizeof(order)))
        {
            format(order, sizeof(order), "sem_pedido");
        }
        if (!Vip_ReadPipeToken(line, index, source, sizeof(source)))
        {
            format(source, sizeof(source), "painel");
        }

        if (!Vip_IsValidLevel(level) || level <= VIP_NONE || days <= 0)
        {
            continue;
        }

        format(message, sizeof(message), "%s order=%s", source, order);
        Vip_SetPlayer(playerid, level, days, message, 0);
        grants++;
    }
    fclose(file);

    if (grants > 0)
    {
        fremove(path);
        SaveAccountData(playerid, 0);
        format(message, sizeof(message), "%d ativacao(oes) VIP aplicada(s).", grants);
        SendClientMessage(playerid, COLOR_GREEN, message);
        return grants;
    }

    if (notify)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Arquivo de VIP encontrado, mas sem ativacao valida.");
    }
    return 0;
}

stock Vip_OnPlayerAuth(playerid)
{
    Vip_ExpireIfNeeded(playerid, 1);
    Vip_ProcessGrantFile(playerid, 0);
    return 1;
}

stock Vip_ClaimDailyKit(playerid)
{
    new level = Vip_GetLevel(playerid);
    new today = GetBrasiliaDayStamp();
    new message[144];

    if (level <= VIP_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao possui VIP ativo.");
        return 1;
    }

    if (PlayerInfo[playerid][pVipLastKitDay] == today)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce ja pegou seu kit VIP hoje.");
        return 1;
    }

    PlayerInfo[playerid][pVipLastKitDay] = today;
    GivePlayerCashReason(playerid, gVipPlans[level][vipKitCash], 0, "vip_daily_kit");

    if (gVipPlans[level][vipKitWater] > 0) Inventory_AddItem(playerid, INV_ITEM_WATER, gVipPlans[level][vipKitWater], 0);
    if (gVipPlans[level][vipKitFood] > 0) Inventory_AddItem(playerid, INV_ITEM_MEAL, gVipPlans[level][vipKitFood], 0);
    if (gVipPlans[level][vipKitMedkit] > 0) Inventory_AddItem(playerid, INV_ITEM_MEDKIT, gVipPlans[level][vipKitMedkit], 0);
    if (gVipPlans[level][vipKitTools] > 0) Inventory_AddItem(playerid, INV_ITEM_TOOLS, gVipPlans[level][vipKitTools], 0);

    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Kit VIP recebido: $%d, comida/bebida e itens conforme seu plano.", gVipPlans[level][vipKitCash]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock ShowVipPlansDialog(playerid)
{
    new list[1024];
    new line[160];
    new level;

    format(list, sizeof(list), "Plano\tValor sugerido\tBeneficios\n");
    for (level = VIP_BRONZE; level <= VIP_DIAMANTE; level++)
    {
        format(line, sizeof(line), "%s\tR$ %d/30 dias\t+%d%% grana, +%d%% XP, %d vaga(s), %d%% desconto\n",
            gVipPlans[level][vipPlanName],
            gVipPlans[level][vipPrice],
            gVipPlans[level][vipCashBonus],
            gVipPlans[level][vipXpBonus],
            gVipPlans[level][vipExtraVehicles],
            gVipPlans[level][vipDiscount]
        );
        strcat(list, line, sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_VIP_PLANS, DIALOG_STYLE_TABLIST_HEADERS, "Planos VIP", list, "Fechar", "");
    return 1;
}

stock ShowVipPurchaseInfo(playerid)
{
    new text[768];

    format(text, sizeof(text),
        "Como comprar VIP\n\n1. Acesse o painel externo em http://127.0.0.1:8088\n2. Informe seu nick exato do SA-MP.\n3. Escolha Bronze, Prata, Ouro ou Diamante.\n4. Pague pelo metodo configurado no painel.\n5. A staff aprova o pagamento e a GM ativa seu VIP.\n\nDepois de aprovado, use /ativarvip ou relogue."
    );
    ShowPlayerDialog(playerid, DIALOG_VIP_PLANS, DIALOG_STYLE_MSGBOX, "Comprar VIP", text, "Fechar", "");
    return 1;
}

stock ShowVipBenefits(playerid)
{
    new level = Vip_GetLevel(playerid);
    new text[768];
    new vipName[24];
    new remaining[48];

    Vip_GetPlayerName(playerid, vipName, sizeof(vipName));
    Vip_FormatRemaining(playerid, remaining, sizeof(remaining));

    format(text, sizeof(text),
        "Seu VIP: %s\nValidade: %s\n\nBeneficios ativos:\n- Bonus de dinheiro em trabalhos: %d%%\n- Bonus de XP em trabalhos: %d%%\n- Desconto em servicos NPC: %d%%\n- Vagas extras de veiculo: %d\n- Kit diario: $%d + itens\n\nUse /kitvip uma vez por dia.",
        vipName,
        remaining,
        gVipPlans[level][vipCashBonus],
        gVipPlans[level][vipXpBonus],
        gVipPlans[level][vipDiscount],
        gVipPlans[level][vipExtraVehicles],
        gVipPlans[level][vipKitCash]
    );
    ShowPlayerDialog(playerid, DIALOG_VIP_PLANS, DIALOG_STYLE_MSGBOX, "Beneficios VIP", text, "Fechar", "");
    return 1;
}

stock ShowVipDialog(playerid)
{
    new list[384];
    new line[96];
    new title[64];
    new vipName[24];
    new remaining[48];

    Vip_ProcessGrantFile(playerid, 0);
    Vip_GetPlayerName(playerid, vipName, sizeof(vipName));
    Vip_FormatRemaining(playerid, remaining, sizeof(remaining));

    format(title, sizeof(title), "VIP - %s", vipName);
    list[0] = 0;
    gVipDialogActionCount[playerid] = 0;
    Vip_AddMenuAction(playerid, list, sizeof(list), VIP_ACT_PLANS, "Ver planos VIP");
    Vip_AddMenuAction(playerid, list, sizeof(list), VIP_ACT_BUY, "Comprar VIP");
    Vip_AddMenuAction(playerid, list, sizeof(list), VIP_ACT_KIT, "Pegar kit diario");
    Vip_AddMenuAction(playerid, list, sizeof(list), VIP_ACT_BENEFITS, "Ver meus beneficios");
    Vip_AddMenuAction(playerid, list, sizeof(list), VIP_ACT_ACTIVATE, "Ativar compra pendente");
    Vip_AddMenuAction(playerid, list, sizeof(list), VIP_ACT_ONLINE, "Vips online");
    format(line, sizeof(line), "\nValidade atual: %s", remaining);
    strcat(list, line, sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_VIP_MENU, DIALOG_STYLE_LIST, title, list, "Selecionar", "Fechar");
    return 1;
}

stock HandleVipDialog(playerid, response, listitem)
{
    new actionid;

    if (!response)
    {
        return 1;
    }

    if (listitem < 0 || listitem >= gVipDialogActionCount[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Opcao VIP expirou. Abra o menu novamente.");
        return ShowVipDialog(playerid);
    }

    actionid = gVipDialogActions[playerid][listitem];
    switch (actionid)
    {
        case VIP_ACT_PLANS: return ShowVipPlansDialog(playerid);
        case VIP_ACT_BUY: return ShowVipPurchaseInfo(playerid);
        case VIP_ACT_KIT: return Vip_ClaimDailyKit(playerid);
        case VIP_ACT_BENEFITS: return ShowVipBenefits(playerid);
        case VIP_ACT_ACTIVATE:
        {
            Vip_ProcessGrantFile(playerid, 1);
            return ShowVipDialog(playerid);
        }
        case VIP_ACT_ONLINE: return Vip_ShowOnline(playerid);
    }
    return ShowVipDialog(playerid);
}

stock Vip_ShowOnline(playerid)
{
    new list[1024];
    new line[96];
    new name[MAX_PLAYER_NAME + 1];
    new vipName[24];
    new targetid;
    new found;
    new maxPlayers = GetMaxPlayers();

    format(list, sizeof(list), "ID\tNick\tVIP\n");
    for (targetid = 0; targetid < maxPlayers; targetid++)
    {
        if (!IsPlayerConnected(targetid) || !PlayerInfo[targetid][pLogged] || Vip_GetLevel(targetid) <= VIP_NONE)
        {
            continue;
        }

        GetPlayerNameEx(targetid, name, sizeof(name));
        Vip_GetPlayerName(targetid, vipName, sizeof(vipName));
        format(line, sizeof(line), "%d\t%s\t%s\n", targetid, name, vipName);
        strcat(list, line, sizeof(list));
        found = 1;
    }

    if (!found)
    {
        strcat(list, "-\tNenhum VIP online\t-\n", sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_VIP_PLANS, DIALOG_STYLE_TABLIST_HEADERS, "VIPs Online", list, "Fechar", "");
    return 1;
}

stock Vip_WriteDefaultPlans()
{
    new File:file;

    if (fexist(VIP_PLANS_FILE))
    {
        return 1;
    }

    file = fopen(VIP_PLANS_FILE, io_write);
    if (!file)
    {
        return 0;
    }

    fwrite(file, "# level|nome|valor_sugerido|dias|beneficios\r\n");
    fwrite(file, "1|Bronze|15|30|+5% dinheiro, +5% XP, 1 vaga, kit diario simples\r\n");
    fwrite(file, "2|Prata|25|30|+8% dinheiro, +10% XP, 1 vaga, desconto 8%, kit melhor\r\n");
    fwrite(file, "3|Ouro|40|30|+12% dinheiro, +15% XP, 2 vagas, desconto 12%, ferramentas\r\n");
    fwrite(file, "4|Diamante|60|30|+15% dinheiro, +20% XP, 3 vagas, desconto 15%, kit maximo\r\n");
    fclose(file);
    return 1;
}

stock Vip_CreateFileIfMissing(fileName[], defaultText[])
{
    new File:file;

    if (fexist(fileName))
    {
        return 1;
    }

    file = fopen(fileName, io_write);
    if (!file)
    {
        return 0;
    }

    fwrite(file, defaultText);
    fclose(file);
    return 1;
}

stock Vip_Init()
{
    Vip_CreateFileIfMissing(VIP_GRANT_MARKER, "");
    Vip_CreateFileIfMissing(VIP_ORDERS_FILE, "# JSONL gerado pelo painel externo VIP.\r\n");
    Vip_CreateFileIfMissing(LOG_VIP_FILE, "# data|categoria|detalhes\r\n");
    Vip_WriteDefaultPlans();
    gVipTimer = SetTimer("Vip_UpdateAll", VIP_CHECK_INTERVAL, 1);
    return 1;
}

stock Vip_Exit()
{
    if (gVipTimer)
    {
        KillTimer(gVipTimer);
        gVipTimer = 0;
    }
    return 1;
}

public Vip_UpdateAll()
{
    new playerid;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (!IsPlayerConnected(playerid) || !PlayerInfo[playerid][pLogged])
        {
            continue;
        }

        Vip_ExpireIfNeeded(playerid, 1);
        Vip_ProcessGrantFile(playerid, 0);
    }
    return 1;
}

stock HandleVipCommands(playerid, cmdtext[])
{
    new command[32];
    new param[64];
    new param2[32];
    new param3[32];
    new index;
    new targetid;
    new level;
    new days;
    new message[128];

    index = GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/vip", true) == 0)
    {
        return ShowVipDialog(playerid);
    }

    if (strcmp(command, "/comprarvip", true) == 0 || strcmp(command, "/planosvip", true) == 0)
    {
        return ShowVipPurchaseInfo(playerid);
    }

    if (strcmp(command, "/kitvip", true) == 0)
    {
        return Vip_ClaimDailyKit(playerid);
    }

    if (strcmp(command, "/ativarvip", true) == 0)
    {
        Vip_ProcessGrantFile(playerid, 1);
        return 1;
    }

    if (strcmp(command, "/vips", true) == 0)
    {
        return Vip_ShowOnline(playerid);
    }

    if (strcmp(command, "/reloadvip", true) == 0 || strcmp(command, "/recarregarvip", true) == 0)
    {
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
        {
            return SendNoPermission(playerid);
        }

        Vip_UpdateAll();
        SendClientMessage(playerid, COLOR_GREEN, "Ativacoes VIP pendentes foram verificadas.");
        return 1;
    }

    if (strcmp(command, "/setvip", true) == 0)
    {
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
        {
            return SendNoPermission(playerid);
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)) || !GetNextParam(cmdtext, index, param3, sizeof(param3)) || !IsNumericString(param2) || !IsNumericString(param3))
        {
            return SendUsage(playerid, "/setvip [id] [nivel 1-4] [dias]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid))
        {
            return 1;
        }

        level = strval(param2);
        days = strval(param3);
        if (level < VIP_BRONZE || level > VIP_DIAMANTE || days <= 0 || days > 365)
        {
            return SendClientMessage(playerid, COLOR_RED, "Use nivel 1 a 4 e dias entre 1 e 365.");
        }

        format(message, sizeof(message), "admin=%d", playerid);
        Vip_SetPlayer(targetid, level, days, message, 1);
        format(message, sizeof(message), "VIP do ID %d definido para nivel %d por %d dias.", targetid, level, days);
        SendClientMessage(playerid, COLOR_GREEN, message);
        return 1;
    }

    if (strcmp(command, "/tirarvip", true) == 0 || strcmp(command, "/removevip", true) == 0)
    {
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
        {
            return SendNoPermission(playerid);
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/tirarvip [id]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid))
        {
            return 1;
        }

        format(message, sizeof(message), "admin=%d", playerid);
        Vip_SetPlayer(targetid, VIP_NONE, 0, message, 1);
        format(message, sizeof(message), "VIP removido do ID %d.", targetid);
        SendClientMessage(playerid, COLOR_GREEN, message);
        return 1;
    }

    return 0;
}
