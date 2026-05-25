#if defined _nova_phone_included
    #endinput
#endif
#define _nova_phone_included

#define PHONE_GOV_MAX_ACTIONS       (44)
#define PHONE_PROP_MAX_ACTIONS      (8)
#define PHONE_PROP_ACTIONS          (3)
#define PHONE_GOV_ACTIVITY          (1)
#define PHONE_GOV_CHARACTER         (2)
#define PHONE_GOV_DOCUMENTS         (3)
#define PHONE_GOV_FINES_SHOW        (4)
#define PHONE_GOV_FINES_PAY         (5)
#define PHONE_GOV_IPVA_SHOW         (6)
#define PHONE_GOV_IPVA_PAY          (7)
#define PHONE_GOV_VEH_DOC           (8)
#define PHONE_GOV_TOW               (9)
#define PHONE_GOV_ISSUE_DOCS        (10)
#define PHONE_GOV_LICENSES          (11)
#define PHONE_GOV_JOB_PANEL         (12)
#define PHONE_GOV_TAXES             (13)
#define PHONE_GOV_JUSTICE           (14)
#define PHONE_GOV_SCORE             (15)
#define PHONE_GOV_BILLS             (16)
#define PHONE_GOV_CONTRACTS         (17)
#define PHONE_GOV_CARTORIO          (18)
#define PHONE_GOV_EVENTS            (19)
#define PHONE_GOV_NOTIFY            (20)
#define PHONE_GOV_PASS              (21)
#define PHONE_GOV_RANKING           (22)
#define PHONE_GOV_HISTORY           (23)
#define PHONE_GOV_NEWS              (24)
#define PHONE_GOV_BUDGET            (25)
#define PHONE_GOV_BID               (26)
#define PHONE_GOV_GPS_DETRAN        (27)
#define PHONE_GOV_BACK              (28)
#define PHONE_GOV_NEXT_STEP         (29)
#define PHONE_GOV_JOURNEY           (30)
#define PHONE_GOV_PUBLIC_SERVICES   (31)
#define PHONE_GOV_TOLL_TAG          (32)
#define PHONE_GOV_LOGISTICS         (33)
#define PHONE_GOV_LOGISTICS_RANKING (34)
#define PHONE_GOV_AUTO_BUSINESS     (35)
#define PHONE_GOV_AUTO_PROFIT       (36)
#define PHONE_GOV_TRANSPARENCY      (37)
#define PHONE_GOV_POLITICS          (38)
#define PHONE_GOV_CITYHALL_PANEL    (39)
#define PHONE_GOV_CALL_CENTER       (40)
#define PHONE_GOV_DAILY_JOURNEY     (41)
#define PHONE_GOV_WEEKLY_AGENDA     (42)
#define PHONE_GOV_NEIGHBORHOOD_EVENTS (43)
#define PHONE_GOV_URBAN_PROGRESS    (44)
#define PHONE_PROP_BUY              (1)
#define PHONE_PROP_RENT             (2)
#define PHONE_PROP_BACK             (3)

enum ePhoneDeliveryItem
{
    deliveryName[32],
    deliveryPrice,
    deliveryHunger,
    deliveryThirst,
    deliveryInventoryItem
}

new gPhoneDeliveryItems[][ePhoneDeliveryItem] =
{
    { "iFood - Lanche", 70, 45, 10, INV_ITEM_SNACK },
    { "iFood - Refeicao", 120, 85, 15, INV_ITEM_MEAL },
    { "Mercado - Agua", 35, 0, 35, INV_ITEM_WATER },
    { "Mercado - Bebida", 45, 5, 25, INV_ITEM_SODA },
    { "Mercado - Kit viagem", 160, 100, 100, INV_ITEM_NONE }
};

new gPhoneSelectedProperty[MAX_PLAYERS];
new gPhoneGovActions[MAX_PLAYERS][PHONE_GOV_MAX_ACTIONS];
new gPhoneGovActionCount[MAX_PLAYERS];
new gPhonePropertyList[MAX_PLAYERS][PHONE_PROP_MAX_ACTIONS];
new gPhonePropertyCount[MAX_PLAYERS];
new gPhonePropertyActions[MAX_PLAYERS][PHONE_PROP_ACTIONS];
new gPhonePropertyActionCount[MAX_PLAYERS];

stock Phone_AddGovAction(playerid, list[], size, actionid, label[])
{
    if (gPhoneGovActionCount[playerid] >= PHONE_GOV_MAX_ACTIONS)
    {
        return 0;
    }

    gPhoneGovActions[playerid][gPhoneGovActionCount[playerid]] = actionid;
    gPhoneGovActionCount[playerid]++;
    strcat(list, label, size);
    strcat(list, "\n", size);
    return 1;
}

stock Phone_AddPropertyItem(playerid, list[], size, propertyid)
{
    new index = Property_GetIndex(propertyid);
    new line[96];

    if (index == -1 || gPhonePropertyCount[playerid] >= PHONE_PROP_MAX_ACTIONS)
    {
        return 0;
    }

    gPhonePropertyList[playerid][gPhonePropertyCount[playerid]] = propertyid;
    gPhonePropertyCount[playerid]++;
    format(line, sizeof(line), "%s\t$%d\t$%d | %d vaga(s)\n", gProperties[index][propName], gProperties[index][propPrice], gProperties[index][propRent], gProperties[index][propGarageSlots]);
    strcat(list, line, size);
    return 1;
}

stock Phone_AddPropertyAction(playerid, text[], size, actionid, label[])
{
    if (gPhonePropertyActionCount[playerid] >= PHONE_PROP_ACTIONS)
    {
        return 0;
    }

    gPhonePropertyActions[playerid][gPhonePropertyActionCount[playerid]] = actionid;
    gPhonePropertyActionCount[playerid]++;
    strcat(text, label, size);
    strcat(text, "\n", size);
    return 1;
}

stock ShowPhoneHomeDialog(playerid)
{
    ShowPlayerDialog(
        playerid,
        DIALOG_PHONE_HOME,
        DIALOG_STYLE_LIST,
        "Celular - LF OS",
        "LF Pay - Banco\nGovBR Online\nImoveis Online\niFood / Mercado\nUber / 99\nGPS\nFechar",
        "Abrir",
        "Guardar"
    );
    return 1;
}

stock ShowPhoneGovDialog(playerid)
{
    new list[1900];
    new politicsLabel[64];

    gPhoneGovActionCount[playerid] = 0;
    Life_FormatPoliticsPhoneLabel(politicsLabel, sizeof(politicsLabel));
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_ACTIVITY, "Central de atividades");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_DAILY_JOURNEY, "Jornada diaria 2.0");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_WEEKLY_AGENDA, "Agenda semanal 2.0");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_NEIGHBORHOOD_EVENTS, "Eventos por bairro 2.0");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_URBAN_PROGRESS, "Progresso urbano 2.0");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_NEXT_STEP, "Proximo passo");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_JOURNEY, "Primeira jornada");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_CALL_CENTER, "Central 190/192/193");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_CHARACTER, "Documento digital");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_DOCUMENTS, "Documentos e vencimentos");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_FINES_SHOW, "Consultar multas");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_FINES_PAY, "Pagar multas");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_IPVA_SHOW, "Consultar IPVA");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_IPVA_PAY, "Pagar IPVA");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_VEH_DOC, "Documento do veiculo");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_TOW, "Pedir guincho");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_ISSUE_DOCS, "Emitir documentos");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_LICENSES, "Solicitar licencas");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_JOB_PANEL, "Painel da profissao");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_TAXES, "Impostos e taxas");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_JUSTICE, "Justica online");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_SCORE, "Score bancario");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_BILLS, "Boletos e SPC/Serasa");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_CONTRACTS, "Contratos");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_CARTORIO, "Cartorio digital");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_EVENTS, "Eventos da cidade");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_NOTIFY, "Notificacoes GovBR");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_PASS, "Passe da cidade");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_RANKING, "Ranking semanal");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_HISTORY, "Historico pessoal");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_NEWS, "Noticias da cidade");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_BUDGET, "Orcamento prefeitura");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_CITYHALL_PANEL, "Painel da prefeitura");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_POLITICS, politicsLabel);
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_TRANSPARENCY, "Central da transparencia");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_BID, "Licitacao publica");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_PUBLIC_SERVICES, "Servicos publicos");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_LOGISTICS, "Fretes logisticos");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_LOGISTICS_RANKING, "Ranking logistico");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_AUTO_BUSINESS, "Empresas automaticas");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_AUTO_PROFIT, "Resgatar lucro empresa");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_TOLL_TAG, "Instalar tag de pedagio");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_GPS_DETRAN, "Marcar GPS DETRAN");
    Phone_AddGovAction(playerid, list, sizeof(list), PHONE_GOV_BACK, "Voltar");

    ShowPlayerDialog(
        playerid,
        DIALOG_PHONE_GOV,
        DIALOG_STYLE_LIST,
        "GovBR Online",
        list,
        "Abrir",
        "Voltar"
    );
    return 1;
}

stock ShowPhonePropertiesDialog(playerid)
{
    new list[768];
    new index;

    format(list, sizeof(list), "Imovel\tCompra\tAluguel\n");
    gPhonePropertyCount[playerid] = 0;
    for (index = 0; index < sizeof(gProperties); index++)
    {
        Phone_AddPropertyItem(playerid, list, sizeof(list), index + 1);
    }

    ShowPlayerDialog(playerid, DIALOG_PHONE_PROPERTIES, DIALOG_STYLE_TABLIST_HEADERS, "Imoveis Online", list, "Ver", "Voltar");
    return 1;
}

stock ShowPhonePropertyActionDialog(playerid, propertyid)
{
    new index = Property_GetIndex(propertyid);
    new text[192];
    new title[64];
    new row[64];

    if (index == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Imovel invalido.");
        return 1;
    }

    gPhoneSelectedProperty[playerid] = propertyid;
    gPhonePropertyActionCount[playerid] = 0;
    format(title, sizeof(title), "Imovel - %s", gProperties[index][propName]);
    text[0] = 0;
    format(row, sizeof(row), "Comprar por $%d", gProperties[index][propPrice]);
    Phone_AddPropertyAction(playerid, text, sizeof(text), PHONE_PROP_BUY, row);
    format(row, sizeof(row), "Alugar por $%d", gProperties[index][propRent]);
    Phone_AddPropertyAction(playerid, text, sizeof(text), PHONE_PROP_RENT, row);
    Phone_AddPropertyAction(playerid, text, sizeof(text), PHONE_PROP_BACK, "Voltar");
    ShowPlayerDialog(playerid, DIALOG_PHONE_PROPERTY, DIALOG_STYLE_LIST, title, text, "Selecionar", "Voltar");
    return 1;
}

stock ShowPhoneDeliveryDialog(playerid)
{
    new list[768];
    new line[96];
    new index;

    format(list, sizeof(list), "Pedido\tPreco\tEfeito\n");
    for (index = 0; index < sizeof(gPhoneDeliveryItems); index++)
    {
        format(line, sizeof(line), "%s\t$%d\tFome +%d / Sede +%d\n", gPhoneDeliveryItems[index][deliveryName], Cfg_Price(gPhoneDeliveryItems[index][deliveryPrice] + gCfgPhoneDeliveryFee), gPhoneDeliveryItems[index][deliveryHunger], gPhoneDeliveryItems[index][deliveryThirst]);
        strcat(list, line, sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_PHONE_DELIVERY, DIALOG_STYLE_TABLIST_HEADERS, "iFood / Mercado", list, "Pedir", "Voltar");
    return 1;
}

stock ShowPhoneRideDialog(playerid)
{
    new list[1024];
    new line[96];
    new index;
    new locationid;
    new count;

    if (Work_IsActive(playerid))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Uber/99 bloqueado durante expediente de trabalho.");
        return 1;
    }

    if (IsPlayerInAnyVehicle(playerid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Saia do veiculo para pedir Uber/99.");
        return 1;
    }

    format(list, sizeof(list), "Destino\tPreco\n");
    gPlayerGpsDialogCount[playerid] = 0;

    for (index = 0; index < sizeof(gNpcTransportLocations); index++)
    {
        if (count >= MAX_GPS_DIALOG_LOCATIONS)
        {
            break;
        }

        locationid = gNpcTransportLocations[index];
        gPlayerGpsDialogLocations[playerid][count] = locationid;
        count++;

        format(line, sizeof(line), "%s\t$%d\n", gServerLocations[locationid][locName], Cfg_Price(gCfgPhoneRideCost));
        strcat(list, line, sizeof(list));
    }

    gPlayerGpsDialogCount[playerid] = count;
    ShowPlayerDialog(playerid, DIALOG_PHONE_RIDE, DIALOG_STYLE_TABLIST_HEADERS, "Uber / 99", list, "Chamar", "Voltar");
    return 1;
}

stock HandlePhoneHomeDialog(playerid, response, listitem)
{
    if (!response)
    {
        return 1;
    }

    if (listitem < 0 || listitem > 5)
    {
        SendClientMessage(playerid, COLOR_RED, "Opcao do celular expirada. Abra o menu novamente.");
        return ShowPhoneHomeDialog(playerid);
    }

    switch (listitem)
    {
        case 0:
        {
            ShowBankDialog(playerid, BANK_ACCESS_PHONE);
        }
        case 1:
        {
            ShowPhoneGovDialog(playerid);
        }
        case 2:
        {
            ShowPhonePropertiesDialog(playerid);
        }
        case 3:
        {
            ShowPhoneDeliveryDialog(playerid);
        }
        case 4:
        {
            ShowPhoneRideDialog(playerid);
        }
        case 5:
        {
            ShowGpsDialog(playerid);
        }
    }
    return 1;
}

stock HandlePhoneGovDialog(playerid, response, listitem)
{
    new actionid;

    if (!response)
    {
        ShowPhoneHomeDialog(playerid);
        return 1;
    }

    if (listitem < 0 || listitem >= gPhoneGovActionCount[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Opcao do GovBR expirou. Abra o menu novamente.");
        return ShowPhoneGovDialog(playerid);
    }

    actionid = gPhoneGovActions[playerid][listitem];

    switch (actionid)
    {
        case PHONE_GOV_ACTIVITY:
        {
            Life_ShowActivityCenter(playerid);
        }
        case PHONE_GOV_DAILY_JOURNEY:
        {
            Life_ShowDailyJourney(playerid);
        }
        case PHONE_GOV_WEEKLY_AGENDA:
        {
            Life_ShowWeeklyAgenda(playerid);
        }
        case PHONE_GOV_NEIGHBORHOOD_EVENTS:
        {
            Life_ShowNeighborhoodEvents(playerid);
        }
        case PHONE_GOV_URBAN_PROGRESS:
        {
            Life_ShowUrbanProgress(playerid);
        }
        case PHONE_GOV_NEXT_STEP:
        {
            Life_ShowNextStepDialog(playerid);
        }
        case PHONE_GOV_JOURNEY:
        {
            Life_ShowFirstJourneyDialog(playerid);
        }
        case PHONE_GOV_CHARACTER:
        {
            CityHall_SendCharacterInfo(playerid);
        }
        case PHONE_GOV_DOCUMENTS:
        {
            Life_ShowDocumentsDialog(playerid);
        }
        case PHONE_GOV_FINES_SHOW:
        {
            Radar_ShowGovFines(playerid);
        }
        case PHONE_GOV_FINES_PAY:
        {
            Bank_PayFines(playerid);
        }
        case PHONE_GOV_IPVA_SHOW:
        {
            Dealership_ShowVehicleTax(playerid);
        }
        case PHONE_GOV_IPVA_PAY:
        {
            Dealership_PayVehicleTax(playerid);
        }
        case PHONE_GOV_VEH_DOC:
        {
            Dealership_SendVehicleDoc(playerid);
        }
        case PHONE_GOV_TOW:
        {
            Life_ServiceCall_Create(playerid, LIFE_CALL_TOW, "guincho solicitado pelo celular");
        }
        case PHONE_GOV_CALL_CENTER:
        {
            Life_ServiceCall_ShowCreate(playerid);
        }
        case PHONE_GOV_ISSUE_DOCS:
        {
            CityHall_IssueDocuments(playerid);
        }
        case PHONE_GOV_LICENSES:
        {
            ShowCityHallLicenseDialog(playerid);
        }
        case PHONE_GOV_JOB_PANEL:
        {
            ShowCityHallJobPanelDialog(playerid);
        }
        case PHONE_GOV_TAXES:
        {
            Life_ShowTaxesDialog(playerid);
        }
        case PHONE_GOV_JUSTICE:
        {
            Life_ShowJusticeDialog(playerid);
        }
        case PHONE_GOV_SCORE:
        {
            Life_ShowBankScore(playerid);
        }
        case PHONE_GOV_BILLS:
        {
            Life_ShowBillsDialog(playerid);
        }
        case PHONE_GOV_CONTRACTS:
        {
            Life_ShowContractsDialog(playerid);
        }
        case PHONE_GOV_CARTORIO:
        {
            Life_ShowCartorioDialog(playerid);
        }
        case PHONE_GOV_EVENTS:
        {
            Life_ShowCityEvents(playerid);
        }
        case PHONE_GOV_NOTIFY:
        {
            Life_SendGovNotifications(playerid);
        }
        case PHONE_GOV_PASS:
        {
            Life_ShowCityPass(playerid);
        }
        case PHONE_GOV_RANKING:
        {
            Life_ShowWeeklyRanking(playerid);
        }
        case PHONE_GOV_HISTORY:
        {
            Life_ShowPersonalHistory(playerid);
        }
        case PHONE_GOV_NEWS:
        {
            Life_ShowCityNews(playerid);
        }
        case PHONE_GOV_BUDGET:
        {
            Life_ShowCityBudget(playerid);
        }
        case PHONE_GOV_TRANSPARENCY:
        {
            Life_ShowTransparencyCenter(playerid);
        }
        case PHONE_GOV_CITYHALL_PANEL:
        {
            Life_ShowCityHallPanel(playerid);
        }
        case PHONE_GOV_POLITICS:
        {
            Life_ShowPoliticsPanel(playerid);
        }
        case PHONE_GOV_BID:
        {
            Life_PublicBid(playerid);
        }
        case PHONE_GOV_PUBLIC_SERVICES:
        {
            Life_ShowPublicSvcDialog(playerid);
        }
        case PHONE_GOV_LOGISTICS:
        {
            Life_ShowLogisticsPanel(playerid);
        }
        case PHONE_GOV_LOGISTICS_RANKING:
        {
            Life_ShowLogisticsRanking(playerid);
        }
        case PHONE_GOV_AUTO_BUSINESS:
        {
            Life_ShowAutoBusinesses(playerid);
        }
        case PHONE_GOV_AUTO_PROFIT:
        {
            Life_ClaimAutoBusinessProfit(playerid);
        }
        case PHONE_GOV_TOLL_TAG:
        {
            Tolls_BuyTag(playerid);
        }
        case PHONE_GOV_GPS_DETRAN:
        {
            SetPlayerGps(playerid, LOCATION_DETRAN);
        }
        case PHONE_GOV_BACK:
        {
            ShowPhoneHomeDialog(playerid);
        }
    }
    return 1;
}

stock HandlePhonePropertiesDialog(playerid, response, listitem)
{
    new propertyid;

    if (!response)
    {
        ShowPhoneHomeDialog(playerid);
        return 1;
    }

    if (listitem < 0 || listitem >= gPhonePropertyCount[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Lista de imoveis expirou. Abra novamente.");
        return ShowPhonePropertiesDialog(playerid);
    }

    propertyid = gPhonePropertyList[playerid][listitem];
    ShowPhonePropertyActionDialog(playerid, propertyid);
    return 1;
}

stock HandlePhonePropertyDialog(playerid, response, listitem)
{
    new propertyid = gPhoneSelectedProperty[playerid];
    new actionid;

    if (!response)
    {
        ShowPhonePropertiesDialog(playerid);
        return 1;
    }

    if (!Property_IsValid(propertyid))
    {
        SendClientMessage(playerid, COLOR_RED, "Imovel selecionado expirou. Abra a lista novamente.");
        return ShowPhonePropertiesDialog(playerid);
    }

    if (listitem < 0 || listitem >= gPhonePropertyActionCount[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Acao do imovel expirou. Abra novamente.");
        return ShowPhonePropertiesDialog(playerid);
    }

    actionid = gPhonePropertyActions[playerid][listitem];
    switch (actionid)
    {
        case PHONE_PROP_BUY:
        {
            Property_Buy(playerid, propertyid);
        }
        case PHONE_PROP_RENT:
        {
            Property_Rent(playerid, propertyid);
        }
        case PHONE_PROP_BACK:
        {
            ShowPhonePropertiesDialog(playerid);
        }
    }
    return 1;
}

stock HandlePhoneDeliveryDialog(playerid, response, listitem)
{
    new price;
    new itemid;
    new stockItem;
    new message[144];

    if (!response)
    {
        ShowPhoneHomeDialog(playerid);
        return 1;
    }

    if (listitem < 0 || listitem >= sizeof(gPhoneDeliveryItems))
    {
        SendClientMessage(playerid, COLOR_RED, "Pedido invalido.");
        return 1;
    }

    stockItem = (listitem <= 1) ? (0) : (1);
    if (gMarketStock[stockItem] <= 0)
    {
        format(message, sizeof(message), "Produto indisponivel. Estoque de %s zerado no mercado.", gMarketNames[stockItem]);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    price = Cfg_Price(gPhoneDeliveryItems[listitem][deliveryPrice] + gCfgPhoneDeliveryFee);
    if (!Bank_TakePaymentReason(playerid, price, 0, "phone_delivery"))
    {
        format(message, sizeof(message), "Pedido custa $%d em dinheiro/banco.", price);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    itemid = gPhoneDeliveryItems[listitem][deliveryInventoryItem];
    if (itemid != INV_ITEM_NONE)
    {
        Inventory_AddItem(playerid, itemid, 1, 0);
    }

    gMarketStock[stockItem]--;
    Life_SaveMarketStock();
    Needs_AddPlayerValues(playerid, gPhoneDeliveryItems[listitem][deliveryHunger], gPhoneDeliveryItems[listitem][deliveryThirst], 0);
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Pedido entregue: %s. Total com entrega: $%d.", gPhoneDeliveryItems[listitem][deliveryName], price);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock HandlePhoneRideDialog(playerid, response, listitem)
{
    new locationid;
    new message[128];

    if (!response)
    {
        ShowPhoneHomeDialog(playerid);
        return 1;
    }

    if (Work_IsActive(playerid))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Uber/99 bloqueado durante expediente de trabalho.");
        return 1;
    }

    if (IsPlayerInAnyVehicle(playerid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Saia do veiculo para pedir Uber/99.");
        return 1;
    }

    locationid = GetGpsLocationFromListItem(playerid, listitem);
    if (locationid == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Destino invalido.");
        return 1;
    }

    if (!Bank_TakePaymentReason(playerid, Cfg_Price(gCfgPhoneRideCost), 0, "phone_ride"))
    {
        format(message, sizeof(message), "Corrida Uber/99 custa $%d em dinheiro/banco.", Cfg_Price(gCfgPhoneRideCost));
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    SetPlayerToLocation(playerid, locationid);
    SaveAccountData(playerid);
    format(message, sizeof(message), "Motorista Uber/99 deixou voce em: %s. Custo: $%d.", gServerLocations[locationid][locName], Cfg_Price(gCfgPhoneRideCost));
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock HandlePhoneCommands(playerid, cmdtext[])
{
    new command[32];

    GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/celular", true) == 0 || strcmp(command, "/phone", true) == 0 || strcmp(command, "/app", true) == 0)
    {
        ShowPhoneHomeDialog(playerid);
        return 1;
    }

    return 0;
}
