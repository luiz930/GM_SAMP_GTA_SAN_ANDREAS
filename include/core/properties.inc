#if defined _nova_properties_included
    #endinput
#endif
#define _nova_properties_included

#define PROPERTY_ICON_OFFSET        (90)
#define HOTEL_ICON_OFFSET           (96)
#define PROPERTY_ICON_HOUSE         (31)
#define PROPERTY_ICON_HOTEL         (35)
#define PROPERTY_ICON_COLOR_FREE    (0x33CC33FF)
#define PROPERTY_ICON_COLOR_USED    (0xCC3333FF)
#define PROPERTY_ICON_VISIBLE_RANGE (MAP_ICON_VISIBLE_RANGE)
#define PROPERTY_RANGE              (4.5)
#define PROPERTY_SELL_PERCENT       (70)
#define PROPERTY_INTERIOR           (10)
#define PROPERTY_INTERIOR_VW_BASE   (600)
#define HOTEL_INTERIOR              (10)
#define HOTEL_INTERIOR_VW_BASE      (700)
#define PROPERTY_INT_X              (2262.8301)
#define PROPERTY_INT_Y              (-1137.7100)
#define PROPERTY_INT_Z              (1050.6328)
#define PROPERTY_INT_A              (270.0)
#define PROPERTY_EXIT_X             (2260.7600)
#define PROPERTY_EXIT_Y             (-1137.7100)
#define PROPERTY_EXIT_Z             (1050.6328)
#define PROPERTY_BED_X              (2259.5300)
#define PROPERTY_BED_Y              (-1139.9300)
#define PROPERTY_BED_Z              (1050.6328)
#define PROPERTY_CHEST_X            (2265.0300)
#define PROPERTY_CHEST_Y            (-1138.1500)
#define PROPERTY_CHEST_Z            (1050.6328)
#define HOTEL_INT_X                 (2262.8301)
#define HOTEL_INT_Y                 (-1137.7100)
#define HOTEL_INT_Z                 (1050.6328)
#define HOTEL_INT_A                 (270.0)
#define HOTEL_EXIT_X                (2260.7600)
#define HOTEL_EXIT_Y                (-1137.7100)
#define HOTEL_EXIT_Z                (1050.6328)
#define HOTEL_BED_X                 (2259.5300)
#define HOTEL_BED_Y                 (-1139.9300)
#define HOTEL_BED_Z                 (1050.6328)
#define PROPERTY_HISTORY_FILE       "property_history.txt"
#define PROPERTY_LEGACY_HOUSES_FILE "properties/houses.txt"
#define MAX_PROPERTIES              (128)
#define DEFAULT_PROPERTY_COUNT      (6)
#define EDITOR_LOCATIONS_FILE       "editor_locations.txt"
#define MAX_EDITOR_LOCATIONS        (128)
#define EDITOR_LOCATION_RANGE       (4.5)
#define EDITOR_LOCATION_VW_BASE     (900)
#define EDITOR_LOC_TYPE_NONE        (0)
#define EDITOR_LOC_TYPE_HOUSE       (1)
#define EDITOR_LOC_TYPE_BUSINESS    (2)
#define EDITOR_LOC_TYPE_FUEL        (3)
#define EDITOR_LOC_PROFILE_HOUSE_1  (1)
#define EDITOR_LOC_PROFILE_HOUSE_2  (2)
#define EDITOR_LOC_PROFILE_APT      (3)
#define EDITOR_LOC_PROFILE_STORE    (4)
#define EDITOR_LOC_PROFILE_OFFICE   (5)
#define EDITOR_LOC_PROFILE_WORKSHOP (6)
#define EDITOR_LOC_PROFILE_WAREHOUSE (7)
#define EDITOR_LOC_PROFILE_RESTAURANT (8)
#define EDITOR_LOC_PROFILE_GAS      (9)
#define PANTRY_MAX_STOCK            (80)
#define SUPERMARKET_PRODUCTS        (8)
#define SUPERMARKET_DELIVERY_FEE    (180)

#define PROPERTY_ROOM_NONE          (0)
#define PROPERTY_ROOM_HOME          (1)
#define PROPERTY_ROOM_HOTEL         (2)
#define PROPERTY_ROOM_EDITOR        (3)
#define PROPERTY_ROOM_OBJECTS       (8)

enum ePropertyData
{
    propName[32],
    Float:propX,
    Float:propY,
    Float:propZ,
    Float:propA,
    propPrice,
    propRent,
    propGarageSlots
}

enum eHotelData
{
    hotelName[32],
    Float:hotelX,
    Float:hotelY,
    Float:hotelZ,
    Float:hotelA,
    hotelCost
}

enum eSupermarketProduct
{
    marketProductName[32],
    marketProductCategory[24],
    marketProductStockItem,
    marketProductBasePrice,
    marketProductFood,
    marketProductDrink
}

new gProperties[MAX_PROPERTIES][ePropertyData];
new gPropertyCount = DEFAULT_PROPERTY_COUNT;

new gHotels[][eHotelData] =
{
    { "Hotel Jefferson", 2224.3560, -1159.8020, 25.7331, 90.0, 350 },
    { "Hotel Commerce", 1704.8720, -1665.3290, 20.2188, 180.0, 420 },
    { "Hotel Santa Maria", 379.8750, -1885.7420, 7.8359, 270.0, 500 }
};

new gSupermarketProducts[][eSupermarketProduct] =
{
    { "Arroz e feijao", "Basicos", 0, 95, 5, 0 },
    { "Carnes e mistura", "Basicos", 0, 140, 6, 0 },
    { "Hortifruti", "Feira", 0, 80, 4, 1 },
    { "Kit cafe da manha", "Padaria", 0, 70, 3, 2 },
    { "Agua e sucos", "Bebidas", 1, 60, 0, 5 },
    { "Refrigerantes", "Bebidas", 1, 85, 0, 5 },
    { "Congelados", "Praticos", 0, 120, 5, 1 },
    { "Kit limpeza", "Casa", 5, 110, 0, 0 }
};

new gPlayerPropertyRoomType[MAX_PLAYERS];
new gPlayerPropertyRoomId[MAX_PLAYERS];
new gPlayerPropertyObjects[MAX_PLAYERS][PROPERTY_ROOM_OBJECTS];
new gPlayerMarketCart[MAX_PLAYERS][SUPERMARKET_PRODUCTS];
new gPlayerPropertyIconVisible[MAX_PLAYERS][MAX_PROPERTIES];
new gPlayerHotelIconVisible[MAX_PLAYERS][sizeof(gHotels)];
new Text3D:gPropertyExteriorLabel[MAX_PROPERTIES];
new Text3D:gHotelExteriorLabel[sizeof(gHotels)];
new Text3D:gPropertyExitLabel[MAX_PROPERTIES];
new Text3D:gPropertyBedLabel[MAX_PROPERTIES];
new Text3D:gPropertyChestLabel[MAX_PROPERTIES];
new Text3D:gHotelExitLabel[sizeof(gHotels)];
new Text3D:gHotelBedLabel[sizeof(gHotels)];
new gEditorLocCount;
new gEditorLocType[MAX_EDITOR_LOCATIONS];
new gEditorLocSubtype[MAX_EDITOR_LOCATIONS];
new gEditorLocProfile[MAX_EDITOR_LOCATIONS];
new gEditorLocInterior[MAX_EDITOR_LOCATIONS];
new gEditorLocWorld[MAX_EDITOR_LOCATIONS];
new Float:gEditorLocX[MAX_EDITOR_LOCATIONS];
new Float:gEditorLocY[MAX_EDITOR_LOCATIONS];
new Float:gEditorLocZ[MAX_EDITOR_LOCATIONS];
new Float:gEditorLocA[MAX_EDITOR_LOCATIONS];
new gEditorLocName[MAX_EDITOR_LOCATIONS][40];
new Text3D:gEditorLocLabel[MAX_EDITOR_LOCATIONS];

stock Property_IsValid(propertyid)
{
    return (propertyid > HOUSE_NONE && propertyid <= gPropertyCount);
}

stock Property_GetIndex(propertyid)
{
    if (!Property_IsValid(propertyid))
    {
        return -1;
    }
    return propertyid - 1;
}

stock Property_GetPlayerResidence(playerid)
{
    if (PlayerInfo[playerid][pHouse] != HOUSE_NONE)
    {
        return PlayerInfo[playerid][pHouse];
    }
    return PlayerInfo[playerid][pRentedHouse];
}

stock Property_GetNeighborhood(propertyid, output[], size = sizeof(output))
{
    switch (propertyid)
    {
        case 1: format(output, size, "Idlewood");
        case 2: format(output, size, "Commerce");
        case 3: format(output, size, "Santa Maria Beach");
        case 4: format(output, size, "Centro");
        case 5: format(output, size, "Ganton");
        case 6: format(output, size, "Marina");
        default: format(output, size, "Los Santos");
    }
    return 1;
}

stock Property_GetNeighborhoodPercent(propertyid)
{
    switch (propertyid)
    {
        case 1: return 92;
        case 2: return 112;
        case 3: return 126;
        case 4: return 138;
        case 5: return 84;
        case 6: return 130;
    }
    return 100;
}

stock Property_GetMarketPrice(propertyid)
{
    new index = Property_GetIndex(propertyid);

    if (index == -1)
    {
        return 0;
    }
    return (Cfg_PropertyPrice(gProperties[index][propPrice]) * Property_GetNeighborhoodPercent(propertyid)) / 100;
}

stock Property_GetMarketRent(propertyid)
{
    new index = Property_GetIndex(propertyid);

    if (index == -1)
    {
        return 0;
    }
    return (Cfg_Price(gProperties[index][propRent]) * Property_GetNeighborhoodPercent(propertyid)) / 100;
}

stock Supermarket_GetRegionalPercent(playerid)
{
    new propertyid = Property_GetPlayerResidence(playerid);

    if (Property_IsValid(propertyid))
    {
        return Property_GetNeighborhoodPercent(propertyid);
    }
    return 100;
}

stock Supermarket_GetProductPrice(playerid, productid)
{
    new stockItem;
    new price;
    new demandPercent;
    new regionalPercent;

    if (productid < 0 || productid >= sizeof(gSupermarketProducts))
    {
        return 0;
    }

    stockItem = gSupermarketProducts[productid][marketProductStockItem];
    price = Cfg_Price(gSupermarketProducts[productid][marketProductBasePrice]);
    demandPercent = Life_GetMarketDemandPercent(stockItem);
    regionalPercent = Supermarket_GetRegionalPercent(playerid);

    if (demandPercent != 0)
    {
        price += (price * demandPercent) / 100;
    }
    price = (price * regionalPercent) / 100;
    if (price < 5)
    {
        price = 5;
    }
    return price;
}

stock Supermarket_ClearCart(playerid)
{
    new index;

    for (index = 0; index < sizeof(gSupermarketProducts); index++)
    {
        gPlayerMarketCart[playerid][index] = 0;
    }
    return 1;
}

stock Supermarket_GetCartTotal(playerid)
{
    new index;
    new total;

    for (index = 0; index < sizeof(gSupermarketProducts); index++)
    {
        if (gPlayerMarketCart[playerid][index] > 0)
        {
            total += Supermarket_GetProductPrice(playerid, index) * gPlayerMarketCart[playerid][index];
        }
    }
    return total;
}

stock Supermarket_GetCartFood(playerid)
{
    new index;
    new total;

    for (index = 0; index < sizeof(gSupermarketProducts); index++)
    {
        total += gSupermarketProducts[index][marketProductFood] * gPlayerMarketCart[playerid][index];
    }
    return total;
}

stock Supermarket_GetCartDrink(playerid)
{
    new index;
    new total;

    for (index = 0; index < sizeof(gSupermarketProducts); index++)
    {
        total += gSupermarketProducts[index][marketProductDrink] * gPlayerMarketCart[playerid][index];
    }
    return total;
}

stock Property_CountLiveOccupants(propertyid)
{
    new player;
    new count;
    new maxPlayers = GetMaxPlayers();

    for (player = 0; player < maxPlayers; player++)
    {
        if (IsPlayerConnected(player) && PlayerInfo[player][pLogged] && (PlayerInfo[player][pHouse] == propertyid || PlayerInfo[player][pRentedHouse] == propertyid))
        {
            count++;
        }
    }
    return count;
}

stock Property_WriteHistory(playerid, propertyid, action[], amount)
{
    new File:file = fopen(PROPERTY_HISTORY_FILE, io_append);
    new line[160];
    new playerName[MAX_PLAYER_NAME];
    new year;
    new month;
    new day;
    new hour;
    new minute;
    new second;

    if (!file)
    {
        return 0;
    }

    GetPlayerNameEx(playerid, playerName, sizeof(playerName));
    GetBrasiliaDateTime(year, month, day, hour, minute, second);
    format(line, sizeof(line), "%02d/%02d/%04d %02d:%02d|%d|%s|%s|$%d\r\n", day, month, year, hour, minute, propertyid, playerName, action, amount);
    fwrite(file, line);
    fclose(file);
    return 1;
}

stock Property_ShowHistory(playerid, propertyid)
{
    new File:file;
    new line[160];
    new marker[12];
    new shown;
    new header[96];

    if (!Property_IsValid(propertyid))
    {
        SendClientMessage(playerid, COLOR_RED, "Imovel invalido.");
        return 1;
    }

    file = fopen(PROPERTY_HISTORY_FILE, io_read);
    if (!file)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Este imovel ainda nao tem historico registrado.");
        return 1;
    }

    format(header, sizeof(header), "Historico recente do imovel %d:", propertyid);
    SendClientMessage(playerid, COLOR_BLUE, header);
    format(marker, sizeof(marker), "|%d|", propertyid);
    while (fread(file, line, sizeof(line)))
    {
        if (strfind(line, marker, false) != -1)
        {
            SendClientMessage(playerid, COLOR_GRAY, line);
            shown++;
            if (shown >= 8)
            {
                break;
            }
        }
    }
    fclose(file);

    if (!shown)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Nenhuma movimentacao encontrada para este imovel.");
    }
    return 1;
}

stock Property_IsPlayerAtProperty(playerid, propertyid, Float:range = PROPERTY_RANGE)
{
    new index = Property_GetIndex(propertyid);

    if (index == -1)
    {
        return 0;
    }

    return IsPlayerInRangeOfPoint(playerid, range, gProperties[index][propX], gProperties[index][propY], gProperties[index][propZ]);
}

stock Property_IsPlayerAtResidence(playerid)
{
    new propertyid = Property_GetPlayerResidence(playerid);

    if (gPlayerPropertyRoomType[playerid] == PROPERTY_ROOM_HOME && gPlayerPropertyRoomId[playerid] == propertyid && propertyid != HOUSE_NONE)
    {
        return 1;
    }
    if (propertyid == HOUSE_NONE)
    {
        return 0;
    }
    return Property_IsPlayerAtProperty(playerid, propertyid, 8.0);
}

stock Property_IsNearHomeCharger(playerid)
{
    new propertyid = Property_GetPlayerResidence(playerid);

    if (propertyid == HOUSE_NONE)
    {
        return 0;
    }
    return Property_IsPlayerAtProperty(playerid, propertyid, EV_CHARGE_HOME_RANGE);
}

stock Property_GetNearestHotel(playerid)
{
    new index;

    if (gPlayerPropertyRoomType[playerid] == PROPERTY_ROOM_HOTEL)
    {
        return gPlayerPropertyRoomId[playerid] - 1;
    }

    for (index = 0; index < sizeof(gHotels); index++)
    {
        if (IsPlayerInRangeOfPoint(playerid, 8.0, gHotels[index][hotelX], gHotels[index][hotelY], gHotels[index][hotelZ]))
        {
            return index;
        }
    }
    return -1;
}

stock Property_SetupPlayerMapIcons(playerid)
{
    Property_UpdatePlayerMapIcons(playerid);
    return 1;
}

stock Property_UpdatePlayerMapIcons(playerid)
{
    new index;
    new propertyid;
    new color;
    new visible;

    for (index = 0; index < gPropertyCount; index++)
    {
        propertyid = index + 1;
        visible = IsPlayerInRangeOfPoint(playerid, PROPERTY_ICON_VISIBLE_RANGE, gProperties[index][propX], gProperties[index][propY], gProperties[index][propZ]);
        if (visible && !gPlayerPropertyIconVisible[playerid][index])
        {
            color = (PlayerInfo[playerid][pHouse] == propertyid || PlayerInfo[playerid][pRentedHouse] == propertyid) ? (PROPERTY_ICON_COLOR_USED) : (PROPERTY_ICON_COLOR_FREE);
            if (ManagedMapIcon_Set(playerid, MAP_ICON_NS_PROPERTY, index, gProperties[index][propX], gProperties[index][propY], gProperties[index][propZ], PROPERTY_ICON_HOUSE, color, MAPICON_GLOBAL))
            {
                gPlayerPropertyIconVisible[playerid][index] = 1;
            }
        }
        else if (!visible && gPlayerPropertyIconVisible[playerid][index])
        {
            ManagedMapIcon_Remove(playerid, MAP_ICON_NS_PROPERTY, index);
            gPlayerPropertyIconVisible[playerid][index] = 0;
        }
    }

    for (index = 0; index < sizeof(gHotels); index++)
    {
        visible = IsPlayerInRangeOfPoint(playerid, PROPERTY_ICON_VISIBLE_RANGE, gHotels[index][hotelX], gHotels[index][hotelY], gHotels[index][hotelZ]);
        if (visible && !gPlayerHotelIconVisible[playerid][index])
        {
            if (ManagedMapIcon_Set(playerid, MAP_ICON_NS_HOTEL, index, gHotels[index][hotelX], gHotels[index][hotelY], gHotels[index][hotelZ], PROPERTY_ICON_HOTEL, 0x66CCFFFF, MAPICON_GLOBAL))
            {
                gPlayerHotelIconVisible[playerid][index] = 1;
            }
        }
        else if (!visible && gPlayerHotelIconVisible[playerid][index])
        {
            ManagedMapIcon_Remove(playerid, MAP_ICON_NS_HOTEL, index);
            gPlayerHotelIconVisible[playerid][index] = 0;
        }
    }
    return 1;
}

stock Property_ClearPlayerMapIcons(playerid)
{
    new index;

    for (index = 0; index < MAX_PROPERTIES; index++)
    {
        gPlayerPropertyIconVisible[playerid][index] = 0;
    }
    for (index = 0; index < sizeof(gHotels); index++)
    {
        gPlayerHotelIconVisible[playerid][index] = 0;
    }
    ManagedMapIcon_ClearNamespace(playerid, MAP_ICON_NS_PROPERTY);
    ManagedMapIcon_ClearNamespace(playerid, MAP_ICON_NS_HOTEL);
    return 1;
}

stock Property_EditorTypeName(type, output[], size = sizeof(output))
{
    switch (type)
    {
        case EDITOR_LOC_TYPE_HOUSE: format(output, size, "Casa/apartamento");
        case EDITOR_LOC_TYPE_BUSINESS: format(output, size, "Empresa");
        case EDITOR_LOC_TYPE_FUEL: format(output, size, "Posto");
        default: format(output, size, "Local");
    }
    return 1;
}

stock Property_EditorProfileName(profile, output[], size = sizeof(output))
{
    switch (profile)
    {
        case EDITOR_LOC_PROFILE_HOUSE_1: format(output, size, "Casa popular");
        case EDITOR_LOC_PROFILE_HOUSE_2: format(output, size, "Casa familiar");
        case EDITOR_LOC_PROFILE_APT: format(output, size, "Apartamento");
        case EDITOR_LOC_PROFILE_STORE: format(output, size, "Loja/mercado");
        case EDITOR_LOC_PROFILE_OFFICE: format(output, size, "Escritorio");
        case EDITOR_LOC_PROFILE_WORKSHOP: format(output, size, "Oficina");
        case EDITOR_LOC_PROFILE_WAREHOUSE: format(output, size, "Galpao");
        case EDITOR_LOC_PROFILE_RESTAURANT: format(output, size, "Restaurante");
        case EDITOR_LOC_PROFILE_GAS: format(output, size, "Posto");
        default: format(output, size, "Interior");
    }
    return 1;
}

stock Property_EditorPrivateJobByList(listitem)
{
    switch (listitem)
    {
        case 0: return JOB_ENTREGADOR;
        case 1: return JOB_TAXISTA;
        case 2: return JOB_CAMINHONEIRO;
        case 3: return JOB_MECANICO;
        case 4: return JOB_FRENTISTA;
        case 5: return JOB_MOTOBOY;
        case 6: return JOB_PESCADOR;
        case 7: return JOB_AGRICULTOR;
        case 8: return JOB_MINERADOR;
        case 9: return JOB_PEDREIRO;
        case 10: return JOB_GARCOM;
        case 11: return JOB_COZINHEIRO;
        case 12: return JOB_VENDEDOR;
        case 13: return JOB_JORNALISTA;
        case 14: return JOB_ADVOGADO;
        case 15: return JOB_TECNICO;
        case 16: return JOB_BANCARIO;
        case 17: return JOB_CORRETOR_IMOVEIS;
        case 18: return JOB_CONTADOR;
        case 19: return JOB_FARMACEUTICO;
        case 20: return JOB_CAIXA_REPOSITOR;
        case 21: return JOB_BARTENDER;
        case 22: return JOB_PADEIRO_PIZZAIOLO;
        case 23: return JOB_RECEPCIONISTA_HOTEL;
        case 24: return JOB_GUINCHEIRO;
        case 25: return JOB_MOTORISTA_APP;
        case 26: return JOB_ENCANADOR;
        case 27: return JOB_JARDINEIRO;
        case 28: return JOB_ZELADOR;
        case 29: return JOB_OPERADOR_FABRICA;
    }
    return JOB_NONE;
}

stock Property_EditorProfileForJob(jobid)
{
    switch (jobid)
    {
        case JOB_MECANICO, JOB_TECNICO, JOB_GUINCHEIRO, JOB_ENCANADOR: return EDITOR_LOC_PROFILE_WORKSHOP;
        case JOB_CAMINHONEIRO, JOB_LIXEIRO, JOB_CARTEIRO, JOB_MINERADOR, JOB_PEDREIRO, JOB_AGRICULTOR, JOB_OPERADOR_FABRICA: return EDITOR_LOC_PROFILE_WAREHOUSE;
        case JOB_GARCOM, JOB_COZINHEIRO, JOB_MOTOBOY, JOB_BARTENDER, JOB_PADEIRO_PIZZAIOLO: return EDITOR_LOC_PROFILE_RESTAURANT;
        case JOB_VENDEDOR, JOB_ENTREGADOR, JOB_FRENTISTA, JOB_PESCADOR, JOB_CAIXA_REPOSITOR: return EDITOR_LOC_PROFILE_STORE;
    }
    return EDITOR_LOC_PROFILE_OFFICE;
}

stock Property_EditorProfileData(profile, &interior, &Float:x, &Float:y, &Float:z, &Float:a)
{
    switch (profile)
    {
        case EDITOR_LOC_PROFILE_HOUSE_1:
        {
            interior = 5; x = 2233.6919; y = -1112.8107; z = 1050.8828; a = 8.6483;
        }
        case EDITOR_LOC_PROFILE_HOUSE_2:
        {
            interior = 9; x = 2319.1272; y = -1023.9562; z = 1050.2109; a = 167.3959;
        }
        case EDITOR_LOC_PROFILE_APT:
        {
            interior = 3; x = 1527.0468; y = -12.0236; z = 1002.0971; a = 350.0013;
        }
        case EDITOR_LOC_PROFILE_STORE:
        {
            interior = 17; x = -25.8845; y = -185.8689; z = 1003.5469; a = 0.0;
        }
        case EDITOR_LOC_PROFILE_WORKSHOP:
        {
            interior = 2; x = 617.2274; y = -74.7031; z = 997.9922; a = 90.0;
        }
        case EDITOR_LOC_PROFILE_WAREHOUSE:
        {
            interior = 18; x = 1302.5199; y = -1.7875; z = 1001.0283; a = 90.0;
        }
        case EDITOR_LOC_PROFILE_RESTAURANT:
        {
            interior = 10; x = 363.1346; y = -74.8461; z = 1001.5078; a = 90.0;
        }
        default:
        {
            interior = 3; x = 386.5259; y = 173.6381; z = 1008.3828; a = 90.0;
        }
    }
    return 1;
}

stock Property_EditorDestroyLocations()
{
    new index;

    for (index = 0; index < MAX_EDITOR_LOCATIONS; index++)
    {
        if (gEditorLocLabel[index] != Text3D:INVALID_3DTEXT_ID)
        {
            Delete3DTextLabel(gEditorLocLabel[index]);
            gEditorLocLabel[index] = Text3D:INVALID_3DTEXT_ID;
        }
    }
    gEditorLocCount = 0;
    return 1;
}

stock Property_EditorCreateLabel(slot)
{
    new text[180];
    new typeName[32];
    new profileName[32];
    new color = COLOR_YELLOW;

    if (slot < 0 || slot >= gEditorLocCount)
    {
        return 0;
    }

    Property_EditorTypeName(gEditorLocType[slot], typeName, sizeof(typeName));
    Property_EditorProfileName(gEditorLocProfile[slot], profileName, sizeof(profileName));
    switch (gEditorLocType[slot])
    {
        case EDITOR_LOC_TYPE_HOUSE:
        {
            color = PROPERTY_ICON_COLOR_FREE;
            format(text, sizeof(text), "%s\n%s | %s\nUse /entrarlocal", gEditorLocName[slot], typeName, profileName);
        }
        case EDITOR_LOC_TYPE_BUSINESS:
        {
            color = COLOR_BLUE;
            format(text, sizeof(text), "%s\nEmpresa privada | %s\nUse /entrarlocal ou /empresa", gEditorLocName[slot], profileName);
        }
        case EDITOR_LOC_TYPE_FUEL:
        {
            color = COLOR_ORANGE;
            format(text, sizeof(text), "%s\nPosto de abastecimento\nUse /abastecer no veiculo", gEditorLocName[slot]);
        }
        default:
        {
            format(text, sizeof(text), "%s\nLocal editor", gEditorLocName[slot]);
        }
    }

    gEditorLocLabel[slot] = Create3DTextLabel(text, color, gEditorLocX[slot], gEditorLocY[slot], gEditorLocZ[slot] + 0.75, 28.0, gEditorLocWorld[slot], 1);
    return 1;
}

stock Property_EditorSaveLocations()
{
    new File:file = fopen(EDITOR_LOCATIONS_FILE, io_write);
    new line[220];
    new slot;

    if (!file)
    {
        return 0;
    }

    fwrite(file, "# type|subtype/job|profile|x|y|z|a|interior|world|name\r\n");
    for (slot = 0; slot < gEditorLocCount; slot++)
    {
        if (gEditorLocType[slot] <= EDITOR_LOC_TYPE_NONE)
        {
            continue;
        }
        format(line, sizeof(line), "%d|%d|%d|%.4f|%.4f|%.4f|%.4f|%d|%d|%s\r\n",
            gEditorLocType[slot],
            gEditorLocSubtype[slot],
            gEditorLocProfile[slot],
            gEditorLocX[slot],
            gEditorLocY[slot],
            gEditorLocZ[slot],
            gEditorLocA[slot],
            gEditorLocInterior[slot],
            gEditorLocWorld[slot],
            gEditorLocName[slot]
        );
        fwrite(file, line);
    }
    fclose(file);
    return 1;
}

stock Property_EditorLoadLocations()
{
    new File:file;
    new line[220];
    new token[80];
    new pos;
    new slot;

    Property_EditorDestroyLocations();
    for (slot = 0; slot < MAX_EDITOR_LOCATIONS; slot++)
    {
        gEditorLocLabel[slot] = Text3D:INVALID_3DTEXT_ID;
    }

    if (!fexist(EDITOR_LOCATIONS_FILE))
    {
        return Property_EditorSaveLocations();
    }

    file = fopen(EDITOR_LOCATIONS_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (fread(file, line, sizeof(line)) && gEditorLocCount < MAX_EDITOR_LOCATIONS)
    {
        StripLineEnd(line);
        Cfg_Trim(line);
        if (line[0] == 0 || line[0] == '#')
        {
            continue;
        }

        pos = 0;
        slot = gEditorLocCount;
        if (!MapObj_GetToken(line, pos, token, sizeof(token))) continue; gEditorLocType[slot] = strval(token);
        if (!MapObj_GetToken(line, pos, token, sizeof(token))) continue; gEditorLocSubtype[slot] = strval(token);
        if (!MapObj_GetToken(line, pos, token, sizeof(token))) continue; gEditorLocProfile[slot] = strval(token);
        if (!MapObj_GetToken(line, pos, token, sizeof(token))) continue; gEditorLocX[slot] = floatstr(token);
        if (!MapObj_GetToken(line, pos, token, sizeof(token))) continue; gEditorLocY[slot] = floatstr(token);
        if (!MapObj_GetToken(line, pos, token, sizeof(token))) continue; gEditorLocZ[slot] = floatstr(token);
        if (!MapObj_GetToken(line, pos, token, sizeof(token))) continue; gEditorLocA[slot] = floatstr(token);
        if (!MapObj_GetToken(line, pos, token, sizeof(token))) continue; gEditorLocInterior[slot] = strval(token);
        if (!MapObj_GetToken(line, pos, token, sizeof(token))) continue; gEditorLocWorld[slot] = strval(token);
        if (!MapObj_GetToken(line, pos, gEditorLocName[slot], sizeof(gEditorLocName[]))) format(gEditorLocName[slot], sizeof(gEditorLocName[]), "Local %d", slot + 1);

        if (gEditorLocType[slot] <= EDITOR_LOC_TYPE_NONE || gEditorLocType[slot] > EDITOR_LOC_TYPE_FUEL)
        {
            continue;
        }
        gEditorLocCount++;
        Property_EditorCreateLabel(slot);
    }
    fclose(file);
    return 1;
}

stock Property_EditorAddLocation(playerid, type, subtype, profile, name[])
{
    new slot = gEditorLocCount;
    new message[160];
    new cleanName[40];
    new typeName[32];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas DONO pode criar locais pelo editor.");
        return 1;
    }
    if (slot >= MAX_EDITOR_LOCATIONS)
    {
        SendClientMessage(playerid, COLOR_RED, "Limite de locais do editor atingido.");
        return 1;
    }

    MapObj_CopyName(name, cleanName, sizeof(cleanName));
    if (cleanName[0] == 0)
    {
        Property_EditorTypeName(type, typeName, sizeof(typeName));
        format(cleanName, sizeof(cleanName), "%s %d", typeName, slot + 1);
    }

    GetPlayerPos(playerid, gEditorLocX[slot], gEditorLocY[slot], gEditorLocZ[slot]);
    GetPlayerFacingAngle(playerid, gEditorLocA[slot]);
    gEditorLocInterior[slot] = GetPlayerInterior(playerid);
    gEditorLocWorld[slot] = GetPlayerVirtualWorld(playerid);
    gEditorLocType[slot] = type;
    gEditorLocSubtype[slot] = subtype;
    gEditorLocProfile[slot] = profile;
    format(gEditorLocName[slot], sizeof(gEditorLocName[]), "%s", cleanName);
    gEditorLocLabel[slot] = Text3D:INVALID_3DTEXT_ID;
    gEditorLocCount++;
    Property_EditorCreateLabel(slot);

    if (!Property_EditorSaveLocations())
    {
        SendClientMessage(playerid, COLOR_RED, "Local criado, mas nao foi possivel salvar editor_locations.txt.");
        return 1;
    }

    Property_EditorTypeName(type, typeName, sizeof(typeName));
    format(message, sizeof(message), "%s criado: ID %d | %s.", typeName, slot + 1, cleanName);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(playerid, COLOR_GRAY, "Arquivo salvo: scriptfiles/editor_locations.txt");
    return 1;
}

stock Prop_ShowEditHouseDlg(playerid)
{
    new list[512];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas DONO pode criar casas pelo editor.");
        return 1;
    }

    format(list, sizeof(list), "Tipo\tInterior\n");
    strcat(list, "Casa popular\tSafe House simples\n", sizeof(list));
    strcat(list, "Casa familiar\tSafe House maior\n", sizeof(list));
    strcat(list, "Apartamento\tApartamento urbano\n", sizeof(list));
    strcat(list, "Aleatorio\tSorteia casa/apartamento\n", sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_EDIT_HOUSE_CREATE, DIALOG_STYLE_TABLIST_HEADERS, "Criar casa/apartamento", list, "Criar", "Voltar");
    return 1;
}

stock Prop_ShowEditBizDlg(playerid)
{
    new list[2048];
    new line[96];
    new index;
    new jobid;
    new jobName[32];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas DONO pode criar empresas pelo editor.");
        return 1;
    }

    format(list, sizeof(list), "Empresa/profissao\tInterior\n");
    for (index = 0; index < 30; index++)
    {
        jobid = Property_EditorPrivateJobByList(index);
        GetJobName(jobid, jobName, sizeof(jobName));
        Property_EditorProfileName(Property_EditorProfileForJob(jobid), line, sizeof(line));
        format(line, sizeof(line), "%s\t%s\n", jobName, line);
        strcat(list, line, sizeof(list));
    }
    ShowPlayerDialog(playerid, DIALOG_EDIT_BUSINESS_CREATE, DIALOG_STYLE_TABLIST_HEADERS, "Criar empresa privada", list, "Criar", "Voltar");
    return 1;
}

stock Prop_HandleEditHouseDlg(playerid, response, listitem)
{
    new profile;
    new name[40];

    if (!response)
    {
        return ShowEditMapDialog(playerid);
    }
    if (listitem < 0 || listitem > 3)
    {
        SendClientMessage(playerid, COLOR_RED, "Opcao de casa expirada. Abra o editor novamente.");
        return Prop_ShowEditHouseDlg(playerid);
    }
    switch (listitem)
    {
        case 0: profile = EDITOR_LOC_PROFILE_HOUSE_1;
        case 1: profile = EDITOR_LOC_PROFILE_HOUSE_2;
        case 2: profile = EDITOR_LOC_PROFILE_APT;
        default: profile = EDITOR_LOC_PROFILE_HOUSE_1 + random(3);
    }
    Property_EditorProfileName(profile, name, sizeof(name));
    Property_EditorAddLocation(playerid, EDITOR_LOC_TYPE_HOUSE, 0, profile, name);
    return ShowEditMapDialog(playerid);
}

stock Prop_HandleEditBizDlg(playerid, response, listitem)
{
    new jobid;
    new profile;
    new jobName[32];
    new name[40];

    if (!response)
    {
        return ShowEditMapDialog(playerid);
    }

    if (listitem < 0 || listitem >= 30)
    {
        SendClientMessage(playerid, COLOR_RED, "Opcao de empresa expirada. Abra o editor novamente.");
        return Prop_ShowEditBizDlg(playerid);
    }

    jobid = Property_EditorPrivateJobByList(listitem);
    if (jobid == JOB_NONE)
    {
        return Prop_ShowEditBizDlg(playerid);
    }

    profile = Property_EditorProfileForJob(jobid);
    GetJobName(jobid, jobName, sizeof(jobName));
    format(name, sizeof(name), "Empresa %s", jobName);
    Property_EditorAddLocation(playerid, EDITOR_LOC_TYPE_BUSINESS, jobid, profile, name);
    return ShowEditMapDialog(playerid);
}

stock Property_EditorFindNearest(playerid, typeFilter = EDITOR_LOC_TYPE_NONE, Float:range = EDITOR_LOCATION_RANGE)
{
    new slot;
    new nearest = -1;
    new Float:distance;
    new Float:bestDistance = 999999.0;
    new interior = GetPlayerInterior(playerid);
    new world = GetPlayerVirtualWorld(playerid);

    for (slot = 0; slot < gEditorLocCount; slot++)
    {
        if (gEditorLocType[slot] == EDITOR_LOC_TYPE_NONE)
        {
            continue;
        }
        if (typeFilter != EDITOR_LOC_TYPE_NONE && gEditorLocType[slot] != typeFilter)
        {
            continue;
        }
        if (gEditorLocInterior[slot] != interior || gEditorLocWorld[slot] != world)
        {
            continue;
        }
        if (!IsPlayerInRangeOfPoint(playerid, range, gEditorLocX[slot], gEditorLocY[slot], gEditorLocZ[slot]))
        {
            continue;
        }

        distance = GetPlayerDistanceFromPoint(playerid, gEditorLocX[slot], gEditorLocY[slot], gEditorLocZ[slot]);
        if (distance < bestDistance)
        {
            bestDistance = distance;
            nearest = slot;
        }
    }
    return nearest;
}

stock Property_EditorEnterNearest(playerid)
{
    new slot = Property_EditorFindNearest(playerid);
    new interior;
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:a;

    if (slot == -1 || gEditorLocType[slot] == EDITOR_LOC_TYPE_FUEL)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta perto de uma casa ou empresa criada pelo editor.");
        return 1;
    }

    Property_EditorProfileData(gEditorLocProfile[slot], interior, x, y, z, a);
    SetPlayerInterior(playerid, interior);
    SetPlayerVirtualWorld(playerid, EDITOR_LOCATION_VW_BASE + slot + 1);
    SetPlayerPos(playerid, x, y, z);
    SetPlayerFacingAngle(playerid, a);
    SetCameraBehindPlayer(playerid);
    Security_GrantTeleportGrace(playerid);
    gPlayerPropertyRoomType[playerid] = PROPERTY_ROOM_EDITOR;
    gPlayerPropertyRoomId[playerid] = slot + 1;
    SendClientMessage(playerid, COLOR_GREEN, "Voce entrou no local criado pelo editor. Use /sairlocal para sair.");
    return 1;
}

stock Property_EditorExitLocation(playerid)
{
    new slot = gPlayerPropertyRoomId[playerid] - 1;

    if (gPlayerPropertyRoomType[playerid] != PROPERTY_ROOM_EDITOR || slot < 0 || slot >= gEditorLocCount)
    {
        return 0;
    }

    SetPlayerInterior(playerid, gEditorLocInterior[slot]);
    SetPlayerVirtualWorld(playerid, gEditorLocWorld[slot]);
    SetPlayerPos(playerid, gEditorLocX[slot], gEditorLocY[slot], gEditorLocZ[slot]);
    SetPlayerFacingAngle(playerid, gEditorLocA[slot]);
    SetCameraBehindPlayer(playerid);
    Security_GrantTeleportGrace(playerid);
    gPlayerPropertyRoomType[playerid] = PROPERTY_ROOM_NONE;
    gPlayerPropertyRoomId[playerid] = 0;
    SendClientMessage(playerid, COLOR_GREEN, "Voce saiu do local criado pelo editor.");
    return 1;
}

stock Prop_EditorAtFuel(playerid)
{
    return (Property_EditorFindNearest(playerid, EDITOR_LOC_TYPE_FUEL, 12.0) != -1);
}

stock Prop_EditorBusinessTypeForJob(jobid)
{
    switch (jobid)
    {
        case JOB_MECANICO, JOB_TECNICO, JOB_GUINCHEIRO, JOB_ENCANADOR:
        {
            return LIFE_BUSINESS_WORKSHOP;
        }
        case JOB_LIXEIRO, JOB_MOTORISTA_ONIBUS, JOB_TAXISTA, JOB_CAMINHONEIRO, JOB_CARTEIRO, JOB_MOTORISTA_APP:
        {
            return LIFE_BUSINESS_TRANSPORT;
        }
        case JOB_GARCOM, JOB_COZINHEIRO, JOB_MOTOBOY, JOB_BARTENDER, JOB_PADEIRO_PIZZAIOLO:
        {
            return LIFE_BUSINESS_RESTAURANT;
        }
        case JOB_RECEPCIONISTA_HOTEL, JOB_ZELADOR, JOB_JARDINEIRO:
        {
            return LIFE_BUSINESS_HOTEL;
        }
        case JOB_AGRICULTOR, JOB_MINERADOR, JOB_PEDREIRO, JOB_OPERADOR_FABRICA:
        {
            return LIFE_BUSINESS_FACTORY;
        }
        case JOB_CORRETOR_IMOVEIS:
        {
            return LIFE_BUSINESS_REAL_ESTATE;
        }
        case JOB_CONTADOR:
        {
            return LIFE_BUSINESS_ACCOUNTING;
        }
        case JOB_ENTREGADOR, JOB_FRENTISTA, JOB_PESCADOR, JOB_VENDEDOR, JOB_JORNALISTA, JOB_ADVOGADO, JOB_BANCARIO, JOB_FARMACEUTICO, JOB_CAIXA_REPOSITOR:
        {
            return LIFE_BUSINESS_COMMERCE;
        }
    }
    return LIFE_BUSINESS_NONE;
}

stock Prop_EditorIsBusinessSlot(slot)
{
    return (slot >= 0 && slot < gEditorLocCount && gEditorLocType[slot] == EDITOR_LOC_TYPE_BUSINESS);
}

stock Prop_EditorGetBusinessType(slot)
{
    if (!Prop_EditorIsBusinessSlot(slot))
    {
        return LIFE_BUSINESS_NONE;
    }
    return Prop_EditorBusinessTypeForJob(gEditorLocSubtype[slot]);
}

stock Prop_EditorGetBusinessJob(slot)
{
    if (!Prop_EditorIsBusinessSlot(slot))
    {
        return JOB_NONE;
    }
    return gEditorLocSubtype[slot];
}

stock Prop_EditorGetLocationName(slot, output[], size = sizeof(output))
{
    if (slot < 0 || slot >= gEditorLocCount)
    {
        format(output, size, "Sem endereco");
        return 0;
    }
    format(output, size, "%s", gEditorLocName[slot]);
    return 1;
}

stock Prop_EditorFindPlayerBusiness(playerid, Float:range = 6.0)
{
    new slot = -1;

    if (gPlayerPropertyRoomType[playerid] == PROPERTY_ROOM_EDITOR)
    {
        slot = gPlayerPropertyRoomId[playerid] - 1;
        if (Prop_EditorIsBusinessSlot(slot))
        {
            return slot;
        }
    }

    return Property_EditorFindNearest(playerid, EDITOR_LOC_TYPE_BUSINESS, range);
}

stock Prop_EditorPlayerAtBusiness(playerid, editorLocId)
{
    new slot = editorLocId - 1;

    if (!Prop_EditorIsBusinessSlot(slot))
    {
        return 0;
    }

    if (gPlayerPropertyRoomType[playerid] == PROPERTY_ROOM_EDITOR && gPlayerPropertyRoomId[playerid] == editorLocId)
    {
        return 1;
    }

    if (GetPlayerInterior(playerid) != gEditorLocInterior[slot] || GetPlayerVirtualWorld(playerid) != gEditorLocWorld[slot])
    {
        return 0;
    }
    return IsPlayerInRangeOfPoint(playerid, 8.0, gEditorLocX[slot], gEditorLocY[slot], gEditorLocZ[slot]);
}

stock Prop_EditorAtJobBusiness(playerid, jobid)
{
    new slot = Prop_EditorFindPlayerBusiness(playerid, 8.0);

    if (!Prop_EditorIsBusinessSlot(slot))
    {
        return 0;
    }
    return (gEditorLocSubtype[slot] == jobid);
}

stock Property_SetData(slot, name[], Float:x, Float:y, Float:z, Float:a, price, rent, garageSlots)
{
    if (slot < 0 || slot >= MAX_PROPERTIES)
    {
        return 0;
    }

    format(gProperties[slot][propName], 32, "%s", name);
    gProperties[slot][propX] = x;
    gProperties[slot][propY] = y;
    gProperties[slot][propZ] = z;
    gProperties[slot][propA] = a;
    gProperties[slot][propPrice] = price;
    gProperties[slot][propRent] = rent;
    gProperties[slot][propGarageSlots] = garageSlots;
    return 1;
}

stock Property_LoadDefaultProperties()
{
    Property_SetData(0, "Apartamento Idlewood", 2090.8420, -1125.1270, 27.6899, 90.0, 35000, 1200, 1);
    Property_SetData(1, "Casa Commerce", 1514.2100, -1456.8430, 14.2031, 180.0, 55000, 1800, 2);
    Property_SetData(2, "Casa Praia", 370.1690, -2046.7550, 7.8359, 270.0, 80000, 2500, 3);
    Property_SetData(3, "Apartamento Centro", 1458.2380, -1012.9210, 26.8438, 0.0, 95000, 3200, 2);
    Property_SetData(4, "Kitnet Ganton", 2407.1830, -1234.9060, 23.8203, 270.0, 28000, 900, 1);
    Property_SetData(5, "Apartamento Marina", 725.1890, -1451.2260, 17.6953, 180.0, 70000, 2400, 2);
    gPropertyCount = DEFAULT_PROPERTY_COUNT;
    return 1;
}

stock Property_LegacyGetToken(line[], &pos, output[], size = sizeof(output))
{
    new offset;
    new length = strlen(line);

    while (pos < length && (line[pos] == ' ' || line[pos] == 9))
    {
        pos++;
    }

    if (pos >= length || line[pos] == ';')
    {
        output[0] = 0;
        return 0;
    }

    while (pos < length && line[pos] != ',' && line[pos] != ';' && offset < (size - 1))
    {
        output[offset] = line[pos];
        offset++;
        pos++;
    }
    output[offset] = 0;

    if (line[pos] == ',')
    {
        pos++;
    }
    Cfg_Trim(output);
    return output[0] != 0;
}

stock Property_LoadLegacyHouses()
{
    new File:file;
    new line[220];
    new token[80];
    new name[32];
    new pos;
    new commentPos;
    new slot;
    new model;
    new interiorProfile;
    new price;
    new garageSlots;
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:a;

    Property_LoadDefaultProperties();
    for (slot = DEFAULT_PROPERTY_COUNT; slot < MAX_PROPERTIES; slot++)
    {
        format(gProperties[slot][propName], 32, "");
        gProperties[slot][propX] = 0.0;
        gProperties[slot][propY] = 0.0;
        gProperties[slot][propZ] = 0.0;
        gProperties[slot][propA] = 0.0;
        gProperties[slot][propPrice] = 0;
        gProperties[slot][propRent] = 0;
        gProperties[slot][propGarageSlots] = 0;
    }

    if (!fexist(PROPERTY_LEGACY_HOUSES_FILE))
    {
        return 0;
    }

    file = fopen(PROPERTY_LEGACY_HOUSES_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (fread(file, line, sizeof(line)) && gPropertyCount < MAX_PROPERTIES)
    {
        StripLineEnd(line);
        Cfg_Trim(line);
        if (line[0] == 0 || line[0] == '#')
        {
            continue;
        }

        pos = 0;
        if (!Property_LegacyGetToken(line, pos, token, sizeof(token))) continue; model = strval(token);
        if (!Property_LegacyGetToken(line, pos, token, sizeof(token))) continue; x = floatstr(token);
        if (!Property_LegacyGetToken(line, pos, token, sizeof(token))) continue; y = floatstr(token);
        if (!Property_LegacyGetToken(line, pos, token, sizeof(token))) continue; z = floatstr(token);
        if (!Property_LegacyGetToken(line, pos, token, sizeof(token))) continue; a = floatstr(token);
        if (!Property_LegacyGetToken(line, pos, token, sizeof(token))) continue; interiorProfile = strval(token);

        if (model <= 0)
        {
            continue;
        }

        slot = gPropertyCount;
        commentPos = strfind(line, "//", false);
        if (commentPos != -1)
        {
            strmid(name, line, commentPos + 2, strlen(line), sizeof(name));
            Cfg_Trim(name);
        }
        else
        {
            format(name, sizeof(name), "Casa Arquivo %d", slot + 1);
        }
        if (name[0] == 0)
        {
            format(name, sizeof(name), "Casa Arquivo %d", slot + 1);
        }

        price = 32000 + ((interiorProfile % 35) * 1800) + ((slot % 8) * 2500);
        garageSlots = 1;
        if (price >= 65000) garageSlots = 2;
        if (price >= 95000) garageSlots = 3;

        Property_SetData(slot, name, x, y, z, a, price, price / 32, garageSlots);
        gPropertyCount++;
    }

    fclose(file);
    return gPropertyCount - DEFAULT_PROPERTY_COUNT;
}

stock Property_Init()
{
    new index;
    new text[144];

    Property_LoadLegacyHouses();

    for (index = 0; index < gPropertyCount; index++)
    {
        format(text, sizeof(text), "%s\nCasa/apartamento\nUse /entrarcasa, /comprarcasa %d ou /alugarcasa %d", gProperties[index][propName], index + 1, index + 1);
        gPropertyExteriorLabel[index] = Create3DTextLabel(text, PROPERTY_ICON_COLOR_FREE, gProperties[index][propX], gProperties[index][propY], gProperties[index][propZ] + 0.6, 22.0, 0, 1);
        gPropertyExitLabel[index] = Create3DTextLabel("Porta de saida\nUse /saircasa", COLOR_YELLOW, PROPERTY_EXIT_X, PROPERTY_EXIT_Y, PROPERTY_EXIT_Z + 0.35, 18.0, PROPERTY_INTERIOR_VW_BASE + index + 1, 1);
        gPropertyBedLabel[index] = Create3DTextLabel("Cama\nUse /dormir", COLOR_GREEN, PROPERTY_BED_X, PROPERTY_BED_Y, PROPERTY_BED_Z + 0.35, 18.0, PROPERTY_INTERIOR_VW_BASE + index + 1, 1);
        gPropertyChestLabel[index] = Create3DTextLabel("Bau da residencia\nUse /bau", COLOR_BLUE, PROPERTY_CHEST_X, PROPERTY_CHEST_Y, PROPERTY_CHEST_Z + 0.35, 18.0, PROPERTY_INTERIOR_VW_BASE + index + 1, 1);
    }

    for (index = 0; index < sizeof(gHotels); index++)
    {
        format(text, sizeof(text), "%s\nHotel\nUse /entrarhotel ou /dormir na recepcao", gHotels[index][hotelName]);
        gHotelExteriorLabel[index] = Create3DTextLabel(text, 0x66CCFFFF, gHotels[index][hotelX], gHotels[index][hotelY], gHotels[index][hotelZ] + 0.6, 22.0, 0, 1);
        gHotelExitLabel[index] = Create3DTextLabel("Recepcao / saida\nUse /saircasa", COLOR_YELLOW, HOTEL_EXIT_X, HOTEL_EXIT_Y, HOTEL_EXIT_Z + 0.35, 18.0, HOTEL_INTERIOR_VW_BASE + index + 1, 1);
        gHotelBedLabel[index] = Create3DTextLabel("Cama do hotel\nUse /dormir", COLOR_GREEN, HOTEL_BED_X, HOTEL_BED_Y, HOTEL_BED_Z + 0.35, 18.0, HOTEL_INTERIOR_VW_BASE + index + 1, 1);
    }
    Property_EditorLoadLocations();
    return 1;
}

stock Property_Exit()
{
    new index;

    for (index = 0; index < gPropertyCount; index++)
    {
        Delete3DTextLabel(gPropertyExteriorLabel[index]);
        Delete3DTextLabel(gPropertyExitLabel[index]);
        Delete3DTextLabel(gPropertyBedLabel[index]);
        Delete3DTextLabel(gPropertyChestLabel[index]);
    }
    for (index = 0; index < sizeof(gHotels); index++)
    {
        Delete3DTextLabel(gHotelExteriorLabel[index]);
        Delete3DTextLabel(gHotelExitLabel[index]);
        Delete3DTextLabel(gHotelBedLabel[index]);
    }
    Property_EditorDestroyLocations();
    return 1;
}

stock Property_ResetPlayer(playerid)
{
    Supermarket_ClearCart(playerid);
    Property_DestroyRoomObjects(playerid);
    gPlayerPropertyRoomType[playerid] = PROPERTY_ROOM_NONE;
    gPlayerPropertyRoomId[playerid] = 0;
    return 1;
}

stock Property_DestroyRoomObjects(playerid)
{
    new index;

    for (index = 0; index < PROPERTY_ROOM_OBJECTS; index++)
    {
        if (gPlayerPropertyObjects[playerid][index])
        {
            DestroyPlayerObject(playerid, gPlayerPropertyObjects[playerid][index]);
            gPlayerPropertyObjects[playerid][index] = 0;
        }
    }
    return 1;
}

stock Property_AddRoomObject(playerid, &slot, modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if (slot >= PROPERTY_ROOM_OBJECTS)
    {
        return 0;
    }

    gPlayerPropertyObjects[playerid][slot] = CreatePlayerObject(playerid, modelid, x, y, z, rx, ry, rz, 60.0);
    slot++;
    return 1;
}

stock Property_GetDecorClass(propertyid)
{
    new index = Property_GetIndex(propertyid);

    if (index == -1)
    {
        return 0;
    }
    if (gProperties[index][propPrice] >= 80000)
    {
        return 2;
    }
    if (gProperties[index][propPrice] >= 50000)
    {
        return 1;
    }
    return 0;
}

stock Property_CreateRoomObjects(playerid, roomType, roomid)
{
    new slot;
    new decorClass;

    Property_DestroyRoomObjects(playerid);

    if (roomType == PROPERTY_ROOM_HOME)
    {
        decorClass = Property_GetDecorClass(roomid);
        switch (decorClass)
        {
            case 2:
            {
                Property_AddRoomObject(playerid, slot, 1798, 2259.5500, -1140.0500, 1050.1500, 0.0, 0.0, 90.0);
                Property_AddRoomObject(playerid, slot, 1741, 2265.1000, -1138.2500, 1050.1500, 0.0, 0.0, 180.0);
                Property_AddRoomObject(playerid, slot, 1703, 2262.8000, -1135.6500, 1050.1500, 0.0, 0.0, 180.0);
                Property_AddRoomObject(playerid, slot, 1825, 2262.6000, -1137.1000, 1050.1500, 0.0, 0.0, 0.0);
                Property_AddRoomObject(playerid, slot, 1786, 2265.9000, -1135.9000, 1051.2500, 0.0, 0.0, 270.0);
                Property_AddRoomObject(playerid, slot, 2813, 2263.2000, -1137.1200, 1050.6500, 0.0, 0.0, 0.0);
            }
            case 1:
            {
                Property_AddRoomObject(playerid, slot, 1793, 2259.5500, -1140.0500, 1050.1500, 0.0, 0.0, 90.0);
                Property_AddRoomObject(playerid, slot, 1742, 2265.1000, -1138.2500, 1050.1500, 0.0, 0.0, 180.0);
                Property_AddRoomObject(playerid, slot, 1726, 2262.8000, -1135.6500, 1050.1500, 0.0, 0.0, 180.0);
                Property_AddRoomObject(playerid, slot, 1815, 2262.6000, -1137.1000, 1050.1500, 0.0, 0.0, 0.0);
                Property_AddRoomObject(playerid, slot, 1781, 2265.9000, -1135.9000, 1051.0000, 0.0, 0.0, 270.0);
            }
            default:
            {
                Property_AddRoomObject(playerid, slot, 1794, 2259.5500, -1140.0500, 1050.1500, 0.0, 0.0, 90.0);
                Property_AddRoomObject(playerid, slot, 1743, 2265.1000, -1138.2500, 1050.1500, 0.0, 0.0, 180.0);
                Property_AddRoomObject(playerid, slot, 1812, 2262.6000, -1137.1000, 1050.1500, 0.0, 0.0, 0.0);
                Property_AddRoomObject(playerid, slot, 1785, 2265.9000, -1135.9000, 1050.9500, 0.0, 0.0, 270.0);
            }
        }
        return 1;
    }

    if (roomType == PROPERTY_ROOM_HOTEL)
    {
        Property_AddRoomObject(playerid, slot, 1793, HOTEL_BED_X, HOTEL_BED_Y, HOTEL_BED_Z - 0.4800, 0.0, 0.0, 90.0);
        Property_AddRoomObject(playerid, slot, 1742, 2265.1000, -1138.2500, 1050.1500, 0.0, 0.0, 180.0);
        Property_AddRoomObject(playerid, slot, 1815, 2262.6000, -1137.1000, 1050.1500, 0.0, 0.0, 0.0);
        Property_AddRoomObject(playerid, slot, 1781, 2265.9000, -1135.9000, 1051.0000, 0.0, 0.0, 270.0);
        return 1;
    }
    return 0;
}

stock ShowPropertiesList(playerid)
{
    new index;
    new propertyid;
    new message[144];
    new neighborhood[32];
    new occupants;

    SendClientMessage(playerid, COLOR_BLUE, "Mercado imobiliario:");
    for (index = 0; index < gPropertyCount; index++)
    {
        propertyid = index + 1;
        Property_GetNeighborhood(propertyid, neighborhood, sizeof(neighborhood));
        occupants = Property_CountLiveOccupants(propertyid);
        format(message, sizeof(message), "%d. %s | %s %d%% | $%d / aluguel $%d | online: %d", propertyid, gProperties[index][propName], neighborhood, Property_GetNeighborhoodPercent(propertyid), Property_GetMarketPrice(propertyid), Property_GetMarketRent(propertyid), occupants);
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    SendClientMessage(playerid, COLOR_GRAY, "Use /comprarcasa, /alugarcasa, /anunciarcasa, /historicoimovel ou /minhacasa.");
    return 1;
}

stock Property_Buy(playerid, propertyid)
{
    new index = Property_GetIndex(propertyid);
    new message[128];
    new logLine[144];
    new price;

    if (index == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Imovel invalido.");
        return 1;
    }

    if (PlayerInfo[playerid][pHouse] != HOUSE_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce ja possui um imovel.");
        return 1;
    }

    if (PlayerInfo[playerid][pRentedHouse] != HOUSE_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Cancele seu aluguel antes de comprar um imovel.");
        return 1;
    }

    if (!Life_CheckScoreGate(playerid, gCfgCitizenPropertyMinScore, "Compra de imovel"))
    {
        return 1;
    }

    price = Property_GetMarketPrice(propertyid);
    if (!Bank_TakePaymentReason(playerid, price, 0, "property_buy"))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao tem dinheiro/banco suficiente para comprar este imovel.");
        return 1;
    }

    PlayerInfo[playerid][pHouse] = propertyid;
    PlayerInfo[playerid][pRentedHouse] = HOUSE_NONE;
    PlayerInfo[playerid][pContractRent] = 0;
    PlayerInfo[playerid][pHomeSolar] = 0;
    PlayerInfo[playerid][pTaxLastDay] = GetBrasiliaDayStamp();
    PlayerInfo[playerid][pPropertyTaxDue] += (price * gCfgPropertyTaxPercent) / 100;
    SaveAccountData(playerid, 0);
    Property_SetupPlayerMapIcons(playerid);
    format(message, sizeof(message), "Imovel comprado: %s.", gProperties[index][propName]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(logLine, sizeof(logLine), "property_buy id=%d price=%d score=%d", propertyid, price, PlayerInfo[playerid][pBankScore]);
    WritePlayerLog(LOG_MONEY_FILE, "PROPERTY", playerid, logLine);
    Property_WriteHistory(playerid, propertyid, "compra", price);
    return 1;
}

stock Property_Rent(playerid, propertyid)
{
    new index = Property_GetIndex(propertyid);
    new message[128];
    new logLine[144];
    new rent;

    if (index == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Imovel invalido.");
        return 1;
    }

    if (PlayerInfo[playerid][pHouse] != HOUSE_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce ja possui imovel proprio e nao precisa alugar.");
        return 1;
    }

    if (PlayerInfo[playerid][pRentedHouse] != HOUSE_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce ja possui aluguel ativo. Use /cancelaraluguel primeiro.");
        return 1;
    }

    if (!Life_CheckScoreGate(playerid, gCfgCitizenRentMinScore, "Aluguel"))
    {
        return 1;
    }

    rent = Property_GetMarketRent(propertyid);
    if (!Bank_TakePaymentReason(playerid, rent, 0, "property_rent"))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao tem dinheiro/banco suficiente para pagar o aluguel.");
        return 1;
    }

    PlayerInfo[playerid][pRentedHouse] = propertyid;
    PlayerInfo[playerid][pContractRent] = 1;
    PlayerInfo[playerid][pTaxLastDay] = GetBrasiliaDayStamp();
    PlayerInfo[playerid][pGovernmentTaxDue] += Cfg_Price(gCfgGovernmentMonthlyFee);
    SaveAccountData(playerid, 0);
    Property_SetupPlayerMapIcons(playerid);
    format(message, sizeof(message), "Aluguel iniciado: %s.", gProperties[index][propName]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(logLine, sizeof(logLine), "property_rent id=%d rent=%d score=%d", propertyid, rent, PlayerInfo[playerid][pBankScore]);
    WritePlayerLog(LOG_CONTRACT_FILE, "RENT", playerid, logLine);
    Property_WriteHistory(playerid, propertyid, "aluguel", rent);
    return 1;
}

stock Property_SendInfo(playerid)
{
    new message[144];
    new propertyid = PlayerInfo[playerid][pHouse];
    new index;
    new debt;
    new neighborhood[32];

    if (propertyid == HOUSE_NONE)
    {
        propertyid = PlayerInfo[playerid][pRentedHouse];
    }

    if (propertyid == HOUSE_NONE)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui ou aluga nenhuma casa.");
        return 1;
    }

    index = Property_GetIndex(propertyid);
    if (index == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Seu imovel salvo esta invalido.");
        return 1;
    }

    debt = PlayerInfo[playerid][pPropertyTaxDue] + PlayerInfo[playerid][pBillRentDue];
    Property_GetNeighborhood(propertyid, neighborhood, sizeof(neighborhood));
    format(message, sizeof(message), "Seu imovel: %s | ID %d | %s | Garagem: %d vaga(s)", gProperties[index][propName], propertyid, PlayerInfo[playerid][pHouse] == propertyid ? ("comprado") : ("alugado"), gProperties[index][propGarageSlots]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Bairro: %s | valor atual $%d | aluguel atual $%d | moradores online: %d.", neighborhood, Property_GetMarketPrice(propertyid), Property_GetMarketRent(propertyid), Property_CountLiveOccupants(propertyid));
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Pendencias: imposto $%d | aluguel/boletos $%d | total $%d.", PlayerInfo[playerid][pPropertyTaxDue], PlayerInfo[playerid][pBillRentDue], debt);
    SendClientMessage(playerid, debt > 0 ? COLOR_ORANGE : COLOR_GREEN, message);
    format(message, sizeof(message), "Servicos: agua $%d | luz $%d | solar %s.", PlayerInfo[playerid][pBillWaterDue], PlayerInfo[playerid][pBillElectricDue], (PlayerInfo[playerid][pHomeSolar] && PlayerInfo[playerid][pHouse] == propertyid) ? ("instalada") : ("nao"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Dispensa: comida %d | bebida %d.", PlayerInfo[playerid][pPantryFood], PlayerInfo[playerid][pPantryDrink]);
    SendClientMessage(playerid, COLOR_GRAY, message);
    SendClientMessage(playerid, COLOR_GRAY, "Voce nasce neste imovel. Use /dormir, /bau, /dispensa e /garagemcasa quando estiver nele.");
    return 1;
}

stock Property_OnPlayerSpawn(playerid)
{
    new propertyid = PlayerInfo[playerid][pHouse];
    new index;

    if (propertyid == HOUSE_NONE)
    {
        propertyid = PlayerInfo[playerid][pRentedHouse];
    }

    index = Property_GetIndex(propertyid);
    if (index == -1)
    {
        return 0;
    }

    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerPos(playerid, gProperties[index][propX], gProperties[index][propY], gProperties[index][propZ]);
    SetPlayerFacingAngle(playerid, gProperties[index][propA]);
    SetCameraBehindPlayer(playerid);
    PlayerInfo[playerid][pLastSpawn] = propertyid;
    SendClientMessage(playerid, COLOR_GREEN, "Voce nasceu na sua residencia.");
    return 1;
}

stock Property_ShowHotels(playerid)
{
    new index;
    new message[144];

    SendClientMessage(playerid, COLOR_BLUE, "Hoteis disponiveis para dormir:");
    for (index = 0; index < sizeof(gHotels); index++)
    {
        format(message, sizeof(message), "%d. %s | diaria $%d | use /gpshotel %d ou va ate o icone azul.", index + 1, gHotels[index][hotelName], Cfg_Price(gHotels[index][hotelCost]), index + 1);
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    SendClientMessage(playerid, COLOR_GRAY, "Ao chegar no hotel, use /dormir para zerar sono e cansaco.");
    return 1;
}

stock Property_EnterResidence(playerid)
{
    new propertyid = Property_GetPlayerResidence(playerid);
    new index = Property_GetIndex(propertyid);

    if (index == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao possui ou aluga nenhuma residencia.");
        return 1;
    }
    if (!Property_IsPlayerAtProperty(playerid, propertyid, 8.0))
    {
        SendClientMessage(playerid, COLOR_RED, "Fique na porta da sua residencia para entrar.");
        return 1;
    }

    SetPlayerInterior(playerid, PROPERTY_INTERIOR);
    SetPlayerVirtualWorld(playerid, PROPERTY_INTERIOR_VW_BASE + propertyid);
    SetPlayerPos(playerid, PROPERTY_INT_X, PROPERTY_INT_Y, PROPERTY_INT_Z);
    SetPlayerFacingAngle(playerid, PROPERTY_INT_A);
    SetCameraBehindPlayer(playerid);
    Security_GrantTeleportGrace(playerid);
    gPlayerPropertyRoomType[playerid] = PROPERTY_ROOM_HOME;
    gPlayerPropertyRoomId[playerid] = propertyid;
    Property_CreateRoomObjects(playerid, PROPERTY_ROOM_HOME, propertyid);
    SendClientMessage(playerid, COLOR_GREEN, "Voce entrou na sua residencia. Use /dormir, /bau ou /saircasa.");
    return 1;
}

stock Property_EnterHotel(playerid)
{
    new hotelIndex = Property_GetNearestHotel(playerid);

    if (hotelIndex == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Fique na recepcao de um hotel para entrar no quarto.");
        return 1;
    }

    SetPlayerInterior(playerid, HOTEL_INTERIOR);
    SetPlayerVirtualWorld(playerid, HOTEL_INTERIOR_VW_BASE + hotelIndex + 1);
    SetPlayerPos(playerid, HOTEL_INT_X, HOTEL_INT_Y, HOTEL_INT_Z);
    SetPlayerFacingAngle(playerid, HOTEL_INT_A);
    SetCameraBehindPlayer(playerid);
    Security_GrantTeleportGrace(playerid);
    gPlayerPropertyRoomType[playerid] = PROPERTY_ROOM_HOTEL;
    gPlayerPropertyRoomId[playerid] = hotelIndex + 1;
    Property_CreateRoomObjects(playerid, PROPERTY_ROOM_HOTEL, hotelIndex + 1);
    SendClientMessage(playerid, COLOR_GREEN, "Voce entrou no quarto do hotel. Use /dormir ou /saircasa.");
    return 1;
}

stock Property_ExitInterior(playerid)
{
    new id = gPlayerPropertyRoomId[playerid];
    new index;

    if (Property_EditorExitLocation(playerid))
    {
        return 1;
    }

    if (gPlayerPropertyRoomType[playerid] == PROPERTY_ROOM_HOME)
    {
        index = Property_GetIndex(id);
        if (index != -1)
        {
            SetPlayerInterior(playerid, 0);
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerPos(playerid, gProperties[index][propX], gProperties[index][propY], gProperties[index][propZ]);
            SetPlayerFacingAngle(playerid, gProperties[index][propA]);
            SetCameraBehindPlayer(playerid);
            Security_GrantTeleportGrace(playerid);
            Property_ResetPlayer(playerid);
            SendClientMessage(playerid, COLOR_GREEN, "Voce saiu da residencia.");
            return 1;
        }
    }

    if (gPlayerPropertyRoomType[playerid] == PROPERTY_ROOM_HOTEL)
    {
        index = id - 1;
        if (index >= 0 && index < sizeof(gHotels))
        {
            SetPlayerInterior(playerid, 0);
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerPos(playerid, gHotels[index][hotelX], gHotels[index][hotelY], gHotels[index][hotelZ]);
            SetPlayerFacingAngle(playerid, gHotels[index][hotelA]);
            SetCameraBehindPlayer(playerid);
            Security_GrantTeleportGrace(playerid);
            Property_ResetPlayer(playerid);
            SendClientMessage(playerid, COLOR_GREEN, "Voce saiu do hotel.");
            return 1;
        }
    }

    SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta dentro de uma residencia ou hotel.");
    return 1;
}

stock Property_GpsHotel(playerid, hotelid)
{
    new index = hotelid - 1;
    new message[128];

    if (index < 0 || index >= sizeof(gHotels))
    {
        SendClientMessage(playerid, COLOR_RED, "Hotel invalido.");
        return 1;
    }

    SetPlayerCheckpoint(playerid, gHotels[index][hotelX], gHotels[index][hotelY], gHotels[index][hotelZ], GPS_CHECKPOINT_SIZE);
    format(message, sizeof(message), "GPS marcado: %s. Ao chegar, use /dormir.", gHotels[index][hotelName]);
    SendClientMessage(playerid, COLOR_YELLOW, message);
    return 1;
}

stock Property_SleepHere(playerid)
{
    new hotelIndex;

    if (Property_IsPlayerAtResidence(playerid))
    {
        if (gPlayerPropertyRoomType[playerid] == PROPERTY_ROOM_HOME && !IsPlayerInRangeOfPoint(playerid, 5.0, PROPERTY_BED_X, PROPERTY_BED_Y, PROPERTY_BED_Z))
        {
            SendClientMessage(playerid, COLOR_GRAY, "Chegue perto da cama da residencia para dormir.");
            return 1;
        }
        return Needs_SleepPlayer(playerid, 0);
    }

    hotelIndex = Property_GetNearestHotel(playerid);
    if (hotelIndex != -1)
    {
        if (gPlayerPropertyRoomType[playerid] == PROPERTY_ROOM_HOTEL && !IsPlayerInRangeOfPoint(playerid, 5.0, HOTEL_BED_X, HOTEL_BED_Y, HOTEL_BED_Z))
        {
            SendClientMessage(playerid, COLOR_GRAY, "Chegue perto da cama do hotel para dormir.");
            return 1;
        }
        if (!Bank_TakePaymentReason(playerid, Cfg_Price(gHotels[hotelIndex][hotelCost]), 0, "hotel_sleep"))
        {
            SendClientMessage(playerid, COLOR_RED, "Voce nao tem dinheiro/banco suficiente para pagar a diaria do hotel.");
            return 1;
        }
        return Needs_SleepPlayer(playerid, 1);
    }

    SendClientMessage(playerid, COLOR_RED, "Para dormir, fique na sua residencia ou em um hotel.");
    SendClientMessage(playerid, COLOR_GRAY, "Use /hoteis para ver locais ou /casas para comprar/alugar uma residencia.");
    return 1;
}

stock Property_SellHouse(playerid)
{
    new propertyid = PlayerInfo[playerid][pHouse];
    new index = Property_GetIndex(propertyid);
    new refund;
    new message[128];

    if (index == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao possui imovel proprio para vender.");
        return 1;
    }

    refund = (Property_GetMarketPrice(propertyid) * PROPERTY_SELL_PERCENT) / 100;
    PlayerInfo[playerid][pHouse] = HOUSE_NONE;
    PlayerInfo[playerid][pPropertyTaxDue] = 0;
    PlayerInfo[playerid][pHomeSolar] = 0;
    GivePlayerCashReason(playerid, refund, 0, "property_sell");
    SaveAccountData(playerid, 0);
    Property_SetupPlayerMapIcons(playerid);
    format(message, sizeof(message), "Imovel vendido: %s. Reembolso: $%d.", gProperties[index][propName], refund);
    SendClientMessage(playerid, COLOR_GREEN, message);
    Property_WriteHistory(playerid, propertyid, "venda", refund);
    return 1;
}

stock Property_CancelRent(playerid)
{
    new propertyid = PlayerInfo[playerid][pRentedHouse];
    new index = Property_GetIndex(propertyid);
    new fine = Cfg_Price(gCfgContractCancelFine);
    new message[128];

    if (index == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao possui aluguel ativo.");
        return 1;
    }

    if (!Bank_TakePaymentReason(playerid, fine, 0, "rent_cancel"))
    {
        format(message, sizeof(message), "Cancelar aluguel custa $%d.", fine);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    PlayerInfo[playerid][pRentedHouse] = HOUSE_NONE;
    PlayerInfo[playerid][pContractRent] = 0;
    PlayerInfo[playerid][pBillRentDue] = 0;
    SaveAccountData(playerid, 0);
    Property_SetupPlayerMapIcons(playerid);
    format(message, sizeof(message), "Aluguel cancelado: %s. Multa: $%d.", gProperties[index][propName], fine);
    SendClientMessage(playerid, COLOR_GREEN, message);
    Property_WriteHistory(playerid, propertyid, "cancelou aluguel", fine);
    return 1;
}

stock Property_PayResidenceDebt(playerid)
{
    new total = PlayerInfo[playerid][pPropertyTaxDue] + PlayerInfo[playerid][pBillRentDue];
    new message[128];

    if (total <= 0)
    {
        SendClientMessage(playerid, COLOR_GREEN, "Sua residencia nao possui imposto ou aluguel vencido.");
        return 1;
    }

    if (!Bank_TakePaymentReason(playerid, total, 0, "property_debt_pay"))
    {
        format(message, sizeof(message), "Pendencias da residencia: $%d.", total);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    PlayerInfo[playerid][pPropertyTaxDue] = 0;
    PlayerInfo[playerid][pBillRentDue] = 0;
    PlayerInfo[playerid][pBankGoodHistory]++;
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Pendencias da residencia pagas: $%d.", total);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Property_ShowStorage(playerid)
{
    new itemid;
    new message[96];

    if (!Property_IsPlayerAtResidence(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "O bau so pode ser usado na sua residencia.");
        return 1;
    }

    SendClientMessage(playerid, COLOR_BLUE, "Bau da residencia:");
    for (itemid = 1; itemid < INV_MAX_ITEMS; itemid++)
    {
        if (gHomeStorageAmount[playerid][itemid] > 0)
        {
            format(message, sizeof(message), "%d. %s: %d", itemid, gInventoryItemNames[itemid], gHomeStorageAmount[playerid][itemid]);
            SendClientMessage(playerid, COLOR_BLUE, message);
        }
    }
    SendClientMessage(playerid, COLOR_GRAY, "Use /bau guardar [itemid] [qtd] ou /bau pegar [itemid] [qtd].");
    return 1;
}

stock Property_StorageMove(playerid, store, itemid, amount)
{
    new message[128];

    if (!Property_IsPlayerAtResidence(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "O bau so pode ser usado na sua residencia.");
        return 1;
    }
    if (!Inventory_IsValidItem(itemid) || amount <= 0)
    {
        return SendUsage(playerid, "/bau [guardar/pegar] [itemid] [qtd]");
    }

    if (store)
    {
        if (!Inventory_TakeItem(playerid, itemid, amount, 0))
        {
            SendClientMessage(playerid, COLOR_RED, "Voce nao possui essa quantidade no inventario.");
            return 1;
        }
        gHomeStorageAmount[playerid][itemid] += amount;
        if (gHomeStorageAmount[playerid][itemid] > INV_MAX_STACK_AMOUNT) gHomeStorageAmount[playerid][itemid] = INV_MAX_STACK_AMOUNT;
        format(message, sizeof(message), "Guardado no bau: %s x%d.", gInventoryItemNames[itemid], amount);
    }
    else
    {
        if (gHomeStorageAmount[playerid][itemid] < amount)
        {
            SendClientMessage(playerid, COLOR_RED, "O bau nao possui essa quantidade.");
            return 1;
        }
        gHomeStorageAmount[playerid][itemid] -= amount;
        Inventory_AddItem(playerid, itemid, amount, 0);
        format(message, sizeof(message), "Retirado do bau: %s x%d.", gInventoryItemNames[itemid], amount);
    }

    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Property_Announce(playerid, adType[], amount)
{
    new propertyid = Property_GetPlayerResidence(playerid);
    new index = Property_GetIndex(propertyid);
    new message[144];
    new playerName[MAX_PLAYER_NAME];
    new logLine[144];

    if (index == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa ter uma residencia para anunciar.");
        return 1;
    }
    if (amount <= 0)
    {
        return SendUsage(playerid, "/anunciarcasa [venda/aluguel] [valor]");
    }
    if (strcmp(adType, "venda", true) != 0 && strcmp(adType, "aluguel", true) != 0)
    {
        return SendUsage(playerid, "/anunciarcasa [venda/aluguel] [valor]");
    }
    if (strcmp(adType, "venda", true) == 0 && PlayerInfo[playerid][pHouse] != propertyid)
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas donos podem anunciar venda. Inquilinos podem anunciar aluguel/repasse.");
        return 1;
    }

    GetPlayerNameEx(playerid, playerName, sizeof(playerName));
    format(message, sizeof(message), "[Imoveis] %s anunciou %s de %s por $%d. ID %d.", playerName, adType, gProperties[index][propName], amount, propertyid);
    SendClientMessageToAll(COLOR_YELLOW, message);
    format(logLine, sizeof(logLine), "ad_%s property=%d amount=%d", adType, propertyid, amount);
    WritePlayerLog(LOG_CONTRACT_FILE, "PROPERTY_AD", playerid, logLine);
    Property_WriteHistory(playerid, propertyid, "anuncio", amount);
    return 1;
}

stock Property_ShowPantry(playerid)
{
    new message[128];

    if (!Property_IsPlayerAtResidence(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "A dispensa fica dentro da sua residencia.");
        return 1;
    }

    format(message, sizeof(message), "Dispensa da casa: comida %d/%d | bebida %d/%d.", PlayerInfo[playerid][pPantryFood], PANTRY_MAX_STOCK, PlayerInfo[playerid][pPantryDrink], PANTRY_MAX_STOCK);
    SendClientMessage(playerid, COLOR_BLUE, message);
    SendClientMessage(playerid, COLOR_GRAY, "Use /usardispensa em casa ou /comprardispensa [basico/familia/premium] no mercado.");
    return 1;
}

stock Property_IsPlayerAtFoodMarket(playerid)
{
    return (World_IsPlayerAtNpcStore(playerid) || World_IsPlayerAtRestaurant(playerid));
}

stock Property_BuyPantryKit(playerid, kitName[])
{
    new food;
    new drink;
    new cost;
    new message[128];

    if (!Property_IsPlayerAtFoodMarket(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Compre mantimentos em um mercado ou restaurante.");
        return 1;
    }
    if (Property_GetPlayerResidence(playerid) == HOUSE_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa ter uma residencia para guardar compras na dispensa.");
        return 1;
    }

    if (strcmp(kitName, "basico", true) == 0)
    {
        food = 4;
        drink = 4;
        cost = 250;
    }
    else if (strcmp(kitName, "familia", true) == 0)
    {
        food = 12;
        drink = 12;
        cost = 750;
    }
    else if (strcmp(kitName, "premium", true) == 0)
    {
        food = 25;
        drink = 25;
        cost = 1500;
    }
    else
    {
        return SendUsage(playerid, "/comprardispensa [basico/familia/premium]");
    }

    if (PlayerInfo[playerid][pPantryFood] >= PANTRY_MAX_STOCK && PlayerInfo[playerid][pPantryDrink] >= PANTRY_MAX_STOCK)
    {
        SendClientMessage(playerid, COLOR_RED, "Sua dispensa ja esta cheia.");
        return 1;
    }
    if (!Bank_TakePaymentReason(playerid, Cfg_Price(cost), 0, "pantry_market"))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao tem dinheiro/banco suficiente para comprar mantimentos.");
        return 1;
    }

    PlayerInfo[playerid][pPantryFood] += food;
    PlayerInfo[playerid][pPantryDrink] += drink;
    if (PlayerInfo[playerid][pPantryFood] > PANTRY_MAX_STOCK) PlayerInfo[playerid][pPantryFood] = PANTRY_MAX_STOCK;
    if (PlayerInfo[playerid][pPantryDrink] > PANTRY_MAX_STOCK) PlayerInfo[playerid][pPantryDrink] = PANTRY_MAX_STOCK;
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Compras guardadas na dispensa: comida %d/%d | bebida %d/%d.", PlayerInfo[playerid][pPantryFood], PANTRY_MAX_STOCK, PlayerInfo[playerid][pPantryDrink], PANTRY_MAX_STOCK);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Property_UsePantry(playerid)
{
    new message[128];

    if (!Property_IsPlayerAtResidence(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Use a dispensa dentro da sua residencia.");
        return 1;
    }
    if (PlayerInfo[playerid][pPantryFood] <= 0 || PlayerInfo[playerid][pPantryDrink] <= 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Sua dispensa precisa ter comida e bebida.");
        return 1;
    }

    PlayerInfo[playerid][pPantryFood]--;
    PlayerInfo[playerid][pPantryDrink]--;
    Needs_AddPlayerValues(playerid, 45, 35, 0);
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Voce fez uma refeicao em casa. Dispensa: comida %d | bebida %d.", PlayerInfo[playerid][pPantryFood], PlayerInfo[playerid][pPantryDrink]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Supermarket_ShowCatalog(playerid)
{
    new index;
    new message[144];
    new stockItem;
    new status[64];
    new neighborhood[32];
    new propertyid = Property_GetPlayerResidence(playerid);

    if (Property_IsValid(propertyid))
    {
        Property_GetNeighborhood(propertyid, neighborhood, sizeof(neighborhood));
    }
    else
    {
        format(neighborhood, sizeof(neighborhood), "sem endereco");
    }

    format(message, sizeof(message), "Supermercado | regiao: %s | multiplicador: %d%%.", neighborhood, Supermarket_GetRegionalPercent(playerid));
    SendClientMessage(playerid, COLOR_BLUE, message);
    for (index = 0; index < sizeof(gSupermarketProducts); index++)
    {
        stockItem = gSupermarketProducts[index][marketProductStockItem];
        Life_FormatMarketStatus(stockItem, status, sizeof(status));
        format(message, sizeof(message), "%d. [%s] %s | $%d | dispensa +%d comida/+%d bebida | %s", index + 1, gSupermarketProducts[index][marketProductCategory], gSupermarketProducts[index][marketProductName], Supermarket_GetProductPrice(playerid, index), gSupermarketProducts[index][marketProductFood], gSupermarketProducts[index][marketProductDrink], status);
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    SendClientMessage(playerid, COLOR_GRAY, "Use /addcarrinho [id] [qtd], /carrinho, /fecharcompra [retirar/entregar] ou /limparcarrinho.");
    return 1;
}

stock Supermarket_ShowCart(playerid)
{
    new index;
    new message[144];
    new shown;
    new total = Supermarket_GetCartTotal(playerid);

    SendClientMessage(playerid, COLOR_BLUE, "Carrinho do supermercado:");
    for (index = 0; index < sizeof(gSupermarketProducts); index++)
    {
        if (gPlayerMarketCart[playerid][index] > 0)
        {
            format(message, sizeof(message), "%d. %s x%d | unit $%d | subtotal $%d", index + 1, gSupermarketProducts[index][marketProductName], gPlayerMarketCart[playerid][index], Supermarket_GetProductPrice(playerid, index), Supermarket_GetProductPrice(playerid, index) * gPlayerMarketCart[playerid][index]);
            SendClientMessage(playerid, COLOR_BLUE, message);
            shown++;
        }
    }
    if (!shown)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Carrinho vazio. Use /supermercado para ver produtos.");
        return 1;
    }
    format(message, sizeof(message), "Total: $%d | dispensa +%d comida/+%d bebida.", total, Supermarket_GetCartFood(playerid), Supermarket_GetCartDrink(playerid));
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(playerid, COLOR_GRAY, "Finalize com /fecharcompra retirar ou /fecharcompra entregar.");
    return 1;
}

stock Supermarket_AddToCart(playerid, productid, amount)
{
    new index = productid - 1;
    new message[128];

    if (index < 0 || index >= sizeof(gSupermarketProducts) || amount <= 0)
    {
        return SendUsage(playerid, "/addcarrinho [id] [qtd]");
    }
    if (amount > 20)
    {
        amount = 20;
    }
    if (gPlayerMarketCart[playerid][index] + amount > 50)
    {
        SendClientMessage(playerid, COLOR_RED, "Limite de 50 unidades por produto no carrinho.");
        return 1;
    }

    gPlayerMarketCart[playerid][index] += amount;
    format(message, sizeof(message), "Adicionado ao carrinho: %s x%d.", gSupermarketProducts[index][marketProductName], amount);
    SendClientMessage(playerid, COLOR_GREEN, message);
    Supermarket_ShowCart(playerid);
    return 1;
}

stock Supermarket_Checkout(playerid, delivery)
{
    new total = Supermarket_GetCartTotal(playerid);
    new food = Supermarket_GetCartFood(playerid);
    new drink = Supermarket_GetCartDrink(playerid);
    new index;
    new stockItem;
    new units;
    new message[144];
    new logLine[144];

    if (total <= 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Seu carrinho esta vazio.");
        return 1;
    }
    if (!delivery && !Property_IsPlayerAtFoodMarket(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Para retirar compras, esteja em um mercado ou restaurante.");
        return 1;
    }
    if (delivery && Property_GetPlayerResidence(playerid) == HOUSE_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Entrega em casa exige uma residencia comprada ou alugada.");
        return 1;
    }
    if (delivery)
    {
        total += Cfg_Price(SUPERMARKET_DELIVERY_FEE);
    }
    if (PlayerInfo[playerid][pPantryFood] + food > PANTRY_MAX_STOCK || PlayerInfo[playerid][pPantryDrink] + drink > PANTRY_MAX_STOCK)
    {
        SendClientMessage(playerid, COLOR_RED, "A dispensa nao tem espaco para essa compra toda.");
        return 1;
    }

    for (index = 0; index < sizeof(gSupermarketProducts); index++)
    {
        units = gPlayerMarketCart[playerid][index];
        if (units <= 0)
        {
            continue;
        }
        stockItem = gSupermarketProducts[index][marketProductStockItem];
        if (Life_GetMarketStock(stockItem) < units)
        {
            format(message, sizeof(message), "Estoque insuficiente para %s. Disponivel: %d.", gSupermarketProducts[index][marketProductName], Life_GetMarketStock(stockItem));
            SendClientMessage(playerid, COLOR_RED, message);
            return 1;
        }
    }

    if (!Bank_TakePaymentReason(playerid, total, 0, delivery ? ("supermarket_delivery") : ("supermarket_checkout")))
    {
        format(message, sizeof(message), "Compra custa $%d em dinheiro/banco.", total);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    for (index = 0; index < sizeof(gSupermarketProducts); index++)
    {
        units = gPlayerMarketCart[playerid][index];
        if (units > 0)
        {
            stockItem = gSupermarketProducts[index][marketProductStockItem];
            Life_TakeMarketStock(stockItem, units);
        }
    }

    PlayerInfo[playerid][pPantryFood] += food;
    PlayerInfo[playerid][pPantryDrink] += drink;
    Life_SaveMarketStock();
    SaveAccountData(playerid, 0);
    Supermarket_ClearCart(playerid);

    format(message, sizeof(message), "Compra finalizada%s: $%d | dispensa +%d comida/+%d bebida.", delivery ? (" com entrega") : (""), total, food, drink);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(logLine, sizeof(logLine), "checkout delivery=%d total=%d food=%d drink=%d", delivery, total, food, drink);
    WritePlayerLog(LOG_CONTRACT_FILE, "SUPERMARKET", playerid, logLine);
    return 1;
}

stock HandlePropertyCommands(playerid, cmdtext[])
{
    new command[32];
    new param[32];
    new param2[32];
    new param3[32];
    new index;

    index = GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/criarcasaedit", true) == 0 || strcmp(command, "/criarcasaeditor", true) == 0)
    {
        new profile = EDITOR_LOC_PROFILE_HOUSE_1 + random(3);
        new name[40];

        if (GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            if (strcmp(param, "popular", true) == 0) profile = EDITOR_LOC_PROFILE_HOUSE_1;
            else if (strcmp(param, "familiar", true) == 0 || strcmp(param, "casa", true) == 0) profile = EDITOR_LOC_PROFILE_HOUSE_2;
            else if (strcmp(param, "apartamento", true) == 0 || strcmp(param, "ap", true) == 0) profile = EDITOR_LOC_PROFILE_APT;
        }
        Property_EditorProfileName(profile, name, sizeof(name));
        Property_EditorAddLocation(playerid, EDITOR_LOC_TYPE_HOUSE, 0, profile, name);
        return 1;
    }

    if (strcmp(command, "/criarempresaedit", true) == 0 || strcmp(command, "/criarempresaeditor", true) == 0)
    {
        new jobid;
        new profile;
        new jobName[32];
        new name[40];

        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/criarempresaedit [jobid privado]");
        }
        jobid = strval(param);
        if (Job_IsPublicServiceJob(jobid) || jobid == JOB_SEGURANCA)
        {
            SendClientMessage(playerid, COLOR_RED, "Cargos publicos nao entram como empresa privada.");
            return 1;
        }
        if (jobid <= JOB_NONE || jobid > JOB_MAX_ID)
        {
            return SendUsage(playerid, "/criarempresaedit [jobid privado]");
        }
        profile = Property_EditorProfileForJob(jobid);
        GetJobName(jobid, jobName, sizeof(jobName));
        format(name, sizeof(name), "Empresa %s", jobName);
        Property_EditorAddLocation(playerid, EDITOR_LOC_TYPE_BUSINESS, jobid, profile, name);
        return 1;
    }

    if (strcmp(command, "/criarpostoedit", true) == 0 || strcmp(command, "/criarpostoeditor", true) == 0)
    {
        Property_EditorAddLocation(playerid, EDITOR_LOC_TYPE_FUEL, 0, EDITOR_LOC_PROFILE_GAS, "Posto criado");
        return 1;
    }

    if (strcmp(command, "/casas", true) == 0 || strcmp(command, "/imoveis", true) == 0 || strcmp(command, "/mercadoimobiliario", true) == 0 || strcmp(command, "/imoveisvivos", true) == 0)
    {
        ShowPropertiesList(playerid);
        return 1;
    }

    if (strcmp(command, "/historicoimovel", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/historicoimovel [id]");
        }

        Property_ShowHistory(playerid, strval(param));
        return 1;
    }

    if (strcmp(command, "/comprarcasa", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/comprarcasa [id]");
        }

        Property_Buy(playerid, strval(param));
        return 1;
    }

    if (strcmp(command, "/alugarcasa", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/alugarcasa [id]");
        }

        Property_Rent(playerid, strval(param));
        return 1;
    }

    if (strcmp(command, "/minhacasa", true) == 0)
    {
        Property_SendInfo(playerid);
        return 1;
    }

    if (strcmp(command, "/anunciarcasa", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)) || !IsNumericString(param2))
        {
            return SendUsage(playerid, "/anunciarcasa [venda/aluguel] [valor]");
        }

        Property_Announce(playerid, param, strval(param2));
        return 1;
    }

    if (strcmp(command, "/hoteis", true) == 0 || strcmp(command, "/hotel", true) == 0)
    {
        Property_ShowHotels(playerid);
        return 1;
    }

    if (strcmp(command, "/gpshotel", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/gpshotel [id]");
        }
        Property_GpsHotel(playerid, strval(param));
        return 1;
    }

    if (strcmp(command, "/dormir", true) == 0 || strcmp(command, "/sono", true) == 0)
    {
        Property_SleepHere(playerid);
        return 1;
    }

    if (strcmp(command, "/entrarcasa", true) == 0 || strcmp(command, "/entrarimovel", true) == 0)
    {
        Property_EnterResidence(playerid);
        return 1;
    }

    if (strcmp(command, "/entrarhotel", true) == 0 || strcmp(command, "/quarto", true) == 0)
    {
        Property_EnterHotel(playerid);
        return 1;
    }

    if (strcmp(command, "/entrarlocal", true) == 0 || strcmp(command, "/entrarinterior", true) == 0)
    {
        Property_EditorEnterNearest(playerid);
        return 1;
    }

    if (strcmp(command, "/saircasa", true) == 0 || strcmp(command, "/sairimovel", true) == 0 || strcmp(command, "/sairhotel", true) == 0 || strcmp(command, "/sairlocal", true) == 0)
    {
        Property_ExitInterior(playerid);
        return 1;
    }

    if (strcmp(command, "/descanso", true) == 0 || strcmp(command, "/cansaco", true) == 0)
    {
        Needs_ShowRestStatus(playerid);
        return 1;
    }

    if (strcmp(command, "/vendercasa", true) == 0)
    {
        Property_SellHouse(playerid);
        return 1;
    }

    if (strcmp(command, "/cancelaraluguel", true) == 0)
    {
        Property_CancelRent(playerid);
        return 1;
    }

    if (strcmp(command, "/pagarresidencia", true) == 0 || strcmp(command, "/pagarcasa", true) == 0)
    {
        Property_PayResidenceDebt(playerid);
        return 1;
    }

    if (strcmp(command, "/dispensa", true) == 0)
    {
        Property_ShowPantry(playerid);
        return 1;
    }

    if (strcmp(command, "/comprardispensa", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/comprardispensa [basico/familia/premium]");
        }

        Property_BuyPantryKit(playerid, param);
        return 1;
    }

    if (strcmp(command, "/supermercado", true) == 0 || strcmp(command, "/mercadocasa", true) == 0)
    {
        Supermarket_ShowCatalog(playerid);
        return 1;
    }

    if (strcmp(command, "/carrinho", true) == 0)
    {
        Supermarket_ShowCart(playerid);
        return 1;
    }

    if (strcmp(command, "/addcarrinho", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)) || !IsNumericString(param) || !IsNumericString(param2))
        {
            return SendUsage(playerid, "/addcarrinho [id] [qtd]");
        }

        Supermarket_AddToCart(playerid, strval(param), strval(param2));
        return 1;
    }

    if (strcmp(command, "/limparcarrinho", true) == 0)
    {
        Supermarket_ClearCart(playerid);
        SendClientMessage(playerid, COLOR_GREEN, "Carrinho limpo.");
        return 1;
    }

    if (strcmp(command, "/fecharcompra", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/fecharcompra [retirar/entregar]");
        }
        if (strcmp(param, "retirar", true) == 0 || strcmp(param, "retirada", true) == 0)
        {
            Supermarket_Checkout(playerid, 0);
            return 1;
        }
        if (strcmp(param, "entregar", true) == 0 || strcmp(param, "entrega", true) == 0)
        {
            Supermarket_Checkout(playerid, 1);
            return 1;
        }
        return SendUsage(playerid, "/fecharcompra [retirar/entregar]");
    }

    if (strcmp(command, "/usardispensa", true) == 0 || strcmp(command, "/cozinha", true) == 0)
    {
        Property_UsePantry(playerid);
        return 1;
    }

    if (strcmp(command, "/bau", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            Property_ShowStorage(playerid);
            return 1;
        }
        if (!GetNextParam(cmdtext, index, param2, sizeof(param2)) || !GetNextParam(cmdtext, index, param3, sizeof(param3)) || !IsNumericString(param2) || !IsNumericString(param3))
        {
            return SendUsage(playerid, "/bau [guardar/pegar] [itemid] [qtd]");
        }
        if (strcmp(param, "guardar", true) == 0 || strcmp(param, "depositar", true) == 0)
        {
            Property_StorageMove(playerid, 1, strval(param2), strval(param3));
            return 1;
        }
        if (strcmp(param, "pegar", true) == 0 || strcmp(param, "retirar", true) == 0)
        {
            Property_StorageMove(playerid, 0, strval(param2), strval(param3));
            return 1;
        }
        return SendUsage(playerid, "/bau [guardar/pegar] [itemid] [qtd]");
    }

    return 0;
}
