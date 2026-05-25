#if defined _nova_world_included
    #endinput
#endif
#define _nova_world_included

#define LOCATION_SPAWN              (0)
#define LOCATION_PREFEITURA         (1)
#define LOCATION_HOSPITAL           (2)
#define LOCATION_DELEGACIA          (3)
#define LOCATION_CONCESSIONARIA     (4)
#define LOCATION_JOB_LIXEIRO        (5)
#define LOCATION_JOB_ENTREGADOR     (6)
#define LOCATION_JOB_MOTORISTA      (7)
#define LOCATION_INTERIOR_PREF      (8)
#define LOCATION_JOB_TAXISTA        (9)
#define LOCATION_JOB_CAMINHONEIRO   (10)
#define LOCATION_JOB_MECANICO       (11)
#define LOCATION_JOB_FRENTISTA      (12)
#define LOCATION_JOB_POLICIAL       (13)
#define LOCATION_JOB_MEDICO         (14)
#define LOCATION_JOB_BOMBEIRO       (15)
#define LOCATION_JOB_SEGURANCA      (16)
#define LOCATION_JOB_CARTEIRO       (17)
#define LOCATION_JOB_MOTOBOY        (18)
#define LOCATION_JOB_PESCADOR       (19)
#define LOCATION_JOB_AGRICULTOR     (20)
#define LOCATION_JOB_MINERADOR      (21)
#define LOCATION_JOB_PEDREIRO       (22)
#define LOCATION_JOB_GARCOM         (23)
#define LOCATION_JOB_COZINHEIRO     (24)
#define LOCATION_JOB_VENDEDOR       (25)
#define LOCATION_JOB_JORNALISTA     (26)
#define LOCATION_JOB_ADVOGADO       (27)
#define LOCATION_JOB_JUIZ           (28)
#define LOCATION_JOB_AMBULANCIA     (29)
#define LOCATION_JOB_TECNICO        (30)
#define LOCATION_CONVENIENCIA_1     (31)
#define LOCATION_CONVENIENCIA_2     (32)
#define LOCATION_BANCO              (33)
#define LOCATION_ATM_PREFEITURA     (34)
#define LOCATION_ATM_HOSPITAL       (35)
#define LOCATION_ATM_IDLEWOOD       (36)
#define LOCATION_ATM_CONCESSIONARIA (37)
#define LOCATION_POSTO_IDLEWOOD     (38)
#define LOCATION_POSTO_MARKET       (39)
#define LOCATION_POSTO_DILLIMORE    (40)
#define LOCATION_POSTO_FLINT        (41)
#define LOCATION_POSTO_EL_QUEBRADOS (42)
#define LOCATION_POSTO_TIERRA       (43)
#define LOCATION_DETRAN             (44)
#define LOCATION_GARAGEM_PUBLICA    (45)
#define LOCATION_PATIO_MUNICIPAL    (46)
#define LOCATION_JOB_PRF            (47)
#define LOCATION_JOB_POLICIA_FEDERAL (48)
#define LOCATION_JOB_POLICIA_CIVIL  (49)
#define LOCATION_JOB_POLICIA_PENAL  (50)

#define GPS_ICON_OFFSET             (20)
#define GPS_CHECKPOINT_SIZE         (3.0)
#define LOCATION_INTERACT_DEFAULT   (3.0)
#define LOCATION_INTERACT_PUBLIC    (4.0)
#define LOCATION_INTERACT_BUSINESS  (3.5)
#define LOCATION_INTERACT_GAS       (12.0)
#define LOCATION_INTERACT_JOB       (5.0)
#define LOCATION_INTERACT_FIELD     (8.0)
#define LOCATION_LABEL_DRAW_DISTANCE (24.0)
#define MAX_GPS_DIALOG_LOCATIONS    (64)
#define AUTO_INTERIOR_ENTER_RADIUS  (1.8)
#define AUTO_INTERIOR_EXIT_RADIUS   (1.8)
#define AUTO_INTERIOR_EXIT_ACTION_RADIUS (2.2)
#define AUTO_INTERIOR_ACTION_RADIUS (1.5)
#define AUTO_INTERIOR_COOLDOWN_MS   (4000)
#define INTERIOR_SPOT_ACTION_RADIUS (1.4)
#define SPOT_MIN_CONTROL_DIST       (2.2)
#define INTERIOR_SPOT_COOLDOWN_MS   (15000)
#define AUTO_ACTION_PUBLIC          (1)
#define AUTO_ACTION_JOB             (2)
#define AUTO_ACTION_CONVENIENCE     (3)
#if !defined INVALID_ACTOR_ID
    #define INVALID_ACTOR_ID        (65535)
#endif
#define SPOT_ACTION_INFO            (0)
#define SPOT_ACTION_CITYHALL        (1)
#define SPOT_ACTION_HOSPITAL        (2)
#define SPOT_ACTION_POLICE_REPORT   (3)
#define SPOT_ACTION_POLICE_CELL     (4)
#define SPOT_ACTION_DEALERSHIP      (5)
#define SPOT_ACTION_MECHANIC        (6)
#define SPOT_ACTION_STORE           (7)
#define SPOT_ACTION_KITCHEN         (8)
#define SPOT_ACTION_TABLE_SERVICE   (9)
#define SPOT_ACTION_JOB_SERVICE     (10)

enum eServerLocation
{
    locName[32],
    Float:locX,
    Float:locY,
    Float:locZ,
    Float:locA,
    locInterior,
    locVirtualWorld,
    locMapIcon,
    locMapColor
}

enum eAutoInterior
{
    autoLocation,
    autoName[32],
    autoActionType,
    Float:autoSpawnX,
    Float:autoSpawnY,
    Float:autoSpawnZ,
    Float:autoSpawnA,
    autoInterior,
    autoVirtualWorld,
    Float:autoActionX,
    Float:autoActionY,
    Float:autoActionZ,
    Float:autoExitX,
    Float:autoExitY,
    Float:autoExitZ
}

enum eInteriorSpot
{
    spotLocation,
    spotText[72],
    Float:spotX,
    Float:spotY,
    Float:spotZ,
    spotColor
}

enum eServiceNpc
{
    serviceNpcName[32],
    serviceNpcSkin,
    Float:serviceNpcX,
    Float:serviceNpcY,
    Float:serviceNpcZ,
    Float:serviceNpcA,
    serviceNpcInterior,
    serviceNpcWorld
}

new gServerLocations[][eServerLocation] =
{
    { "Spawn Principal", 1742.5350, -1862.4083, 13.5765, 90.0, 0, 0, 0, 0 },
    { "Prefeitura", 1481.0690, -1771.0450, 18.7958, 0.0, 0, 0, 52, 0 },
    { "Hospital", 1172.0360, -1323.5170, 15.4030, 270.0, 0, 0, 22, 0 },
    { "Delegacia", 1554.9530, -1675.6580, 16.1953, 90.0, 0, 0, 30, 0 },
    { "Concessionaria", 2131.8490, -1149.3340, 24.1232, 270.0, 0, 0, 55, 0 },
    { "Emprego Lixeiro", 2200.1020, -1970.3240, 13.7841, 180.0, 0, 0, 51, 0 },
    { "Emprego Entregador", 2096.5660, -1806.2340, 13.5547, 90.0, 0, 0, 51, 0 },
    { "Emprego Motorista Onibus", 1808.7130, -1900.2240, 13.5748, 0.0, 0, 0, 51, 0 },
    { "Interior Prefeitura", 386.5259, 173.6381, 1008.3828, 90.0, 3, 1, 0, 0 },
    { "Emprego Taxista", 1774.7130, -1896.7740, 13.5625, 0.0, 0, 0, 56, 0 },
    { "Emprego Caminhoneiro", 2451.8810, -2092.6350, 13.5469, 180.0, 0, 0, 51, 0 },
    { "Emprego Mecanico", 1041.8400, -1030.7100, 32.1016, 270.0, 0, 0, 63, 0 },
    { "Emprego Frentista", 1929.5778, -1776.3170, 13.5469, 90.0, 0, 0, 55, 0 },
    { "Emprego Policial", 1569.4630, -1690.3390, 5.8906, 180.0, 0, 0, 30, 0 },
    { "Emprego Medico", 1184.8060, -1326.9100, 13.5748, 270.0, 0, 0, 22, 0 },
    { "Emprego Bombeiro", 1759.3640, -1454.2280, 13.5313, 270.0, 0, 0, 20, 0 },
    { "Emprego Seguranca", 1518.4150, -1675.6200, 14.0469, 90.0, 0, 0, 30, 0 },
    { "Emprego Carteiro", 1117.5850, -1793.3430, 16.5938, 0.0, 0, 0, 51, 0 },
    { "Emprego Motoboy", 2122.5470, -1784.3560, 13.5547, 180.0, 0, 0, 51, 0 },
    { "Emprego Pescador", 389.8040, -2088.7880, 7.8359, 90.0, 0, 0, 9, 0 },
    { "Emprego Agricultor", -383.2300, -1438.5440, 25.7266, 90.0, 0, 0, 51, 0 },
    { "Emprego Minerador", 587.6740, 867.0870, -42.4973, 0.0, 0, 0, 51, 0 },
    { "Emprego Pedreiro", 2522.4880, -1275.5900, 34.9453, 180.0, 0, 0, 51, 0 },
    { "Emprego Garcom", 1199.1260, -918.1780, 43.1230, 180.0, 0, 0, 50, 0 },
    { "Emprego Cozinheiro", 928.5490, -1352.9180, 13.3438, 90.0, 0, 0, 50, 0 },
    { "Ammu-Nation Los Santos", 1368.2140, -1279.8530, 13.5469, 0.0, 0, 0, 45, 0 },
    { "Emprego Jornalista", 740.4350, -1352.9400, 13.5000, 270.0, 0, 0, 56, 0 },
    { "Emprego Advogado", 1474.6310, -1749.7340, 15.4453, 0.0, 0, 0, 52, 0 },
    { "Emprego Juiz", 1410.5250, -1701.1490, 13.5395, 0.0, 0, 0, 52, 0 },
    { "Emprego Motorista Ambulancia", 1177.9120, -1308.6220, 13.9688, 270.0, 0, 0, 22, 0 },
    { "Emprego Tecnico", 2339.1560, -1182.0620, 27.9766, 90.0, 0, 0, 51, 0 },
    { "Conveniencia Idlewood", 1836.8150, -1682.5210, 13.3320, 90.0, 0, 0, 17, 0 },
    { "Conveniencia Posto", 1937.3510, -1768.2030, 13.5469, 0.0, 0, 0, 17, 0 },
    { "Banco Central", 1461.2980, -1011.5210, 26.8438, 180.0, 0, 0, 52, 0 },
    { "Caixa Eletronico Prefeitura", 1486.5000, -1771.4000, 18.7958, 90.0, 0, 0, 52, 0 },
    { "Caixa Eletronico Hospital", 1177.0000, -1328.0000, 14.0000, 270.0, 0, 0, 52, 0 },
    { "Caixa Eletronico Idlewood", 1928.9000, -1776.5000, 13.5469, 90.0, 0, 0, 52, 0 },
    { "ATM Concessionaria", 2127.8000, -1151.0000, 24.1232, 270.0, 0, 0, 52, 0 },
    { "Posto Idlewood", 1942.2160, -1772.9300, 13.5469, 90.0, 0, 0, 55, 0 },
    { "Posto Market", 1004.0070, -939.3100, 42.1797, 0.0, 0, 0, 55, 0 },
    { "Posto Dillimore", 655.6110, -565.6710, 16.3359, 90.0, 0, 0, 55, 0 },
    { "Posto Flint", -1605.7150, -2714.4570, 48.5335, 145.0, 0, 0, 55, 0 },
    { "Posto El Quebrados", -1328.8250, 2677.2170, 50.0625, 0.0, 0, 0, 55, 0 },
    { "Posto Tierra Robada", -1476.6750, 1863.1660, 32.6328, 0.0, 0, 0, 55, 0 },
    { "DETRAN Los Santos", 1034.1500, -1027.6200, 32.1016, 90.0, 0, 0, 55, 0 },
    { "Garagem Publica", 1643.7200, -1524.1200, 13.5547, 0.0, 0, 0, 55, 0 },
    { "Patio Municipal", 1591.8500, -1608.4100, 13.3828, 270.0, 0, 0, 55, 0 },
    { "QG PRF Rodovia LS", 1428.0861, -964.7896, 37.0835, 151.5440, 0, 0, 30, 0 },
    { "QG Policia Federal", 1391.7720, -1700.6690, 13.5395, 90.0, 0, 0, 30, 0 },
    { "QG Policia Civil", 1526.8700, -1677.8200, 13.5469, 90.0, 0, 0, 30, 0 },
    { "QG Policia Penal", 1595.8700, -1638.2200, 13.5469, 180.0, 0, 0, 30, 0 }
};

new gAutoInteriors[][eAutoInterior] =
{
    { LOCATION_PREFEITURA, "Prefeitura", AUTO_ACTION_PUBLIC, 386.5259, 173.6381, 1008.3828, 90.0, 3, 1, 386.5259, 173.6381, 1008.3828, 389.2000, 173.6381, 1008.3828 },
    { LOCATION_HOSPITAL, "Recepcao Hospital", AUTO_ACTION_PUBLIC, 1494.3252, 1304.9429, 1093.2891, 90.0, 3, 102, 1497.0500, 1304.9429, 1093.2891, 1491.6500, 1304.9429, 1093.2891 },
    { LOCATION_DELEGACIA, "Recepcao Delegacia", AUTO_ACTION_PUBLIC, 246.7839, 63.9002, 1003.6406, 0.0, 6, 103, 246.7839, 67.3002, 1003.6406, 246.7839, 60.7002, 1003.6406 },
    { LOCATION_CONCESSIONARIA, "Showroom Concessionaria", AUTO_ACTION_PUBLIC, -2031.1196, -115.8281, 1035.1719, 0.0, 3, 104, -2028.5196, -115.8281, 1035.1719, -2033.5196, -115.8281, 1035.1719 },
    { LOCATION_JOB_LIXEIRO, "Base Coleta Urbana", AUTO_ACTION_JOB, 1302.5199, -1.7875, 1001.0283, 90.0, 18, 105, 1305.1199, -1.7875, 1001.0283, 1299.9199, -1.7875, 1001.0283 },
    { LOCATION_JOB_ENTREGADOR, "Central Entregas", AUTO_ACTION_JOB, 372.5565, -131.3607, 1001.4922, 0.0, 5, 106, 374.8565, -131.3607, 1001.4922, 370.2565, -131.3607, 1001.4922 },
    { LOCATION_JOB_MOTORISTA, "Terminal Onibus", AUTO_ACTION_JOB, 386.5259, 173.6381, 1008.3828, 90.0, 3, 107, 386.5259, 176.2381, 1008.3828, 389.2000, 173.6381, 1008.3828 },
    { LOCATION_JOB_TAXISTA, "Central Taxi", AUTO_ACTION_JOB, 834.2698, 7.4100, 1004.1797, 90.0, 3, 108, 836.8698, 7.4100, 1004.1797, 831.6698, 7.4100, 1004.1797 },
    { LOCATION_JOB_CAMINHONEIRO, "Deposito Cargas", AUTO_ACTION_JOB, 1302.5199, -1.7875, 1001.0283, 90.0, 18, 109, 1305.1199, -1.7875, 1001.0283, 1299.9199, -1.7875, 1001.0283 },
    { LOCATION_JOB_MECANICO, "Oficina Mecanica", AUTO_ACTION_JOB, 617.2274, -74.7031, 997.9922, 90.0, 2, 110, 620.0274, -74.7031, 997.9922, 614.6274, -74.7031, 997.9922 },
    { LOCATION_JOB_FRENTISTA, "Posto Conveniencia", AUTO_ACTION_JOB, -25.8845, -185.8689, 1003.5469, 0.0, 17, 111, -23.5845, -185.8689, 1003.5469, -28.2845, -185.8689, 1003.5469 },
    { LOCATION_JOB_POLICIAL, "Balcao Policial", AUTO_ACTION_JOB, 246.7839, 63.9002, 1003.6406, 0.0, 6, 112, 246.7839, 67.3002, 1003.6406, 246.7839, 60.7002, 1003.6406 },
    { LOCATION_JOB_MEDICO, "Plantao Medico", AUTO_ACTION_JOB, 1494.3252, 1304.9429, 1093.2891, 90.0, 3, 113, 1497.0500, 1304.9429, 1093.2891, 1491.6500, 1304.9429, 1093.2891 },
    { LOCATION_JOB_BOMBEIRO, "Base Bombeiro", AUTO_ACTION_JOB, 617.2274, -74.7031, 997.9922, 90.0, 2, 114, 620.0274, -74.7031, 997.9922, 614.6274, -74.7031, 997.9922 },
    { LOCATION_JOB_SEGURANCA, "Central Seguranca", AUTO_ACTION_JOB, 386.5259, 173.6381, 1008.3828, 90.0, 3, 115, 386.5259, 176.2381, 1008.3828, 389.2000, 173.6381, 1008.3828 },
    { LOCATION_JOB_CARTEIRO, "Agencia Correios", AUTO_ACTION_JOB, 1302.5199, -1.7875, 1001.0283, 90.0, 18, 116, 1305.1199, -1.7875, 1001.0283, 1299.9199, -1.7875, 1001.0283 },
    { LOCATION_JOB_MOTOBOY, "Base Motoboy", AUTO_ACTION_JOB, 372.5565, -131.3607, 1001.4922, 0.0, 5, 117, 374.8565, -131.3607, 1001.4922, 370.2565, -131.3607, 1001.4922 },
    { LOCATION_JOB_PESCADOR, "Entreposto Pesca", AUTO_ACTION_JOB, 1302.5199, -1.7875, 1001.0283, 90.0, 18, 118, 1305.1199, -1.7875, 1001.0283, 1299.9199, -1.7875, 1001.0283 },
    { LOCATION_JOB_AGRICULTOR, "Escritorio Fazenda", AUTO_ACTION_JOB, 1302.5199, -1.7875, 1001.0283, 90.0, 18, 119, 1305.1199, -1.7875, 1001.0283, 1299.9199, -1.7875, 1001.0283 },
    { LOCATION_JOB_MINERADOR, "Administracao Mina", AUTO_ACTION_JOB, 1302.5199, -1.7875, 1001.0283, 90.0, 18, 120, 1305.1199, -1.7875, 1001.0283, 1299.9199, -1.7875, 1001.0283 },
    { LOCATION_JOB_PEDREIRO, "Canteiro Obra", AUTO_ACTION_JOB, 1302.5199, -1.7875, 1001.0283, 90.0, 18, 121, 1305.1199, -1.7875, 1001.0283, 1299.9199, -1.7875, 1001.0283 },
    { LOCATION_JOB_GARCOM, "Salao Restaurante", AUTO_ACTION_JOB, 363.1346, -74.8461, 1001.5078, 90.0, 10, 122, 365.7346, -74.8461, 1001.5078, 360.5346, -74.8461, 1001.5078 },
    { LOCATION_JOB_COZINHEIRO, "Cozinha Restaurante", AUTO_ACTION_JOB, 372.5565, -131.3607, 1001.4922, 0.0, 5, 123, 374.8565, -131.3607, 1001.4922, 370.2565, -131.3607, 1001.4922 },
    { LOCATION_JOB_VENDEDOR, "Ammu-Nation", AUTO_ACTION_JOB, 296.9199, -108.0719, 1001.5156, 0.0, 6, 124, 296.9199, -112.0719, 1001.5156, 296.9199, -104.0719, 1001.5156 },
    { LOCATION_JOB_JORNALISTA, "Redacao Jornal", AUTO_ACTION_JOB, 834.2698, 7.4100, 1004.1797, 90.0, 3, 125, 836.8698, 7.4100, 1004.1797, 831.6698, 7.4100, 1004.1797 },
    { LOCATION_JOB_ADVOGADO, "Escritorio Advocacia", AUTO_ACTION_JOB, 386.5259, 173.6381, 1008.3828, 90.0, 3, 126, 386.5259, 176.2381, 1008.3828, 389.2000, 173.6381, 1008.3828 },
    { LOCATION_JOB_JUIZ, "Gabinete Juiz", AUTO_ACTION_JOB, 386.5259, 173.6381, 1008.3828, 90.0, 3, 127, 386.5259, 176.2381, 1008.3828, 389.2000, 173.6381, 1008.3828 },
    { LOCATION_JOB_AMBULANCIA, "Base Ambulancia", AUTO_ACTION_JOB, 1494.3252, 1304.9429, 1093.2891, 90.0, 3, 128, 1497.0500, 1304.9429, 1093.2891, 1491.6500, 1304.9429, 1093.2891 },
    { LOCATION_JOB_TECNICO, "Central Tecnica", AUTO_ACTION_JOB, 617.2274, -74.7031, 997.9922, 90.0, 2, 129, 620.0274, -74.7031, 997.9922, 614.6274, -74.7031, 997.9922 },
    { LOCATION_JOB_PRF, "QG PRF Rodovia", AUTO_ACTION_JOB, 246.7839, 63.9002, 1003.6406, 0.0, 6, 132, 246.7839, 67.3002, 1003.6406, 246.7839, 60.7002, 1003.6406 },
    { LOCATION_JOB_POLICIA_FEDERAL, "QG Policia Federal", AUTO_ACTION_JOB, 246.7839, 63.9002, 1003.6406, 0.0, 6, 133, 246.7839, 67.3002, 1003.6406, 246.7839, 60.7002, 1003.6406 },
    { LOCATION_JOB_POLICIA_CIVIL, "QG Policia Civil", AUTO_ACTION_JOB, 246.7839, 63.9002, 1003.6406, 0.0, 6, 134, 246.7839, 67.3002, 1003.6406, 246.7839, 60.7002, 1003.6406 },
    { LOCATION_JOB_POLICIA_PENAL, "QG Policia Penal", AUTO_ACTION_JOB, 246.7839, 63.9002, 1003.6406, 0.0, 6, 135, 246.7839, 67.3002, 1003.6406, 246.7839, 60.7002, 1003.6406 },
    { LOCATION_CONVENIENCIA_1, "Conveniencia", AUTO_ACTION_CONVENIENCE, -25.8845, -185.8689, 1003.5469, 0.0, 17, 130, -23.5845, -185.8689, 1003.5469, -28.2845, -185.8689, 1003.5469 },
    { LOCATION_CONVENIENCIA_2, "Conveniencia", AUTO_ACTION_CONVENIENCE, -25.8845, -185.8689, 1003.5469, 0.0, 17, 131, -23.5845, -185.8689, 1003.5469, -28.2845, -185.8689, 1003.5469 }
};

new gInteriorSpots[][eInteriorSpot] =
{
    { LOCATION_PREFEITURA, "Guiche de documentos", 384.8259, 176.2381, 1008.3828, COLOR_BLUE },
    { LOCATION_PREFEITURA, "Setor de empregos e licencas", 386.5259, 170.9381, 1008.3828, COLOR_YELLOW },
    { LOCATION_HOSPITAL, "Triagem e atendimento", 1497.0500, 1304.9429, 1093.2891, COLOR_GREEN },
    { LOCATION_HOSPITAL, "Leitos de observacao", 1494.3252, 1308.2429, 1093.2891, COLOR_GRAY },
    { LOCATION_DELEGACIA, "Recepcao de ocorrencias", 246.7839, 67.3002, 1003.6406, COLOR_ADMIN },
    { LOCATION_DELEGACIA, "Celas e custodia", 264.6000, 77.5000, 1001.0391, COLOR_GRAY },
    { LOCATION_CONCESSIONARIA, "Mesa de venda", -2028.5196, -115.8281, 1035.1719, COLOR_ORANGE },
    { LOCATION_CONCESSIONARIA, "Showroom de veiculos", -2031.1196, -112.3281, 1035.1719, COLOR_BLUE },
    { LOCATION_JOB_LIXEIRO, "Escala de coleta", 1305.1199, -1.7875, 1001.0283, COLOR_YELLOW },
    { LOCATION_JOB_LIXEIRO, "EPIs e vestiario", 1302.5199, 1.0125, 1001.0283, COLOR_GRAY },
    { LOCATION_JOB_ENTREGADOR, "Balcao de pacotes", 374.8565, -131.3607, 1001.4922, COLOR_YELLOW },
    { LOCATION_JOB_ENTREGADOR, "Estoque de encomendas", 372.5565, -128.5607, 1001.4922, COLOR_GRAY },
    { LOCATION_JOB_MOTORISTA, "Quadro de linhas", 386.5259, 176.2381, 1008.3828, COLOR_YELLOW },
    { LOCATION_JOB_MOTORISTA, "Sala dos motoristas", 384.8259, 170.9381, 1008.3828, COLOR_GRAY },
    { LOCATION_JOB_TAXISTA, "Radio taxi", 836.8698, 7.4100, 1004.1797, COLOR_YELLOW },
    { LOCATION_JOB_TAXISTA, "Mapa de corridas", 834.2698, 10.2100, 1004.1797, COLOR_GRAY },
    { LOCATION_JOB_CAMINHONEIRO, "Expedicao de cargas", 1305.1199, -1.7875, 1001.0283, COLOR_YELLOW },
    { LOCATION_JOB_CAMINHONEIRO, "Docas e manifesto", 1302.5199, 1.0125, 1001.0283, COLOR_GRAY },
    { LOCATION_JOB_MECANICO, "Balcao da oficina", 620.0274, -74.7031, 997.9922, COLOR_ORANGE },
    { LOCATION_JOB_MECANICO, "Box de reparo", 617.2274, -71.9031, 997.9922, COLOR_GRAY },
    { LOCATION_JOB_FRENTISTA, "Caixa do posto", -23.5845, -185.8689, 1003.5469, COLOR_ORANGE },
    { LOCATION_JOB_FRENTISTA, "Estoque de oleo e filtros", -25.8845, -182.8689, 1003.5469, COLOR_GRAY },
    { LOCATION_JOB_POLICIAL, "Arsenal e escala", 246.7839, 67.3002, 1003.6406, COLOR_ADMIN },
    { LOCATION_JOB_POLICIAL, "Celas e custodia", 264.6000, 77.5000, 1001.0391, COLOR_GRAY },
    { LOCATION_JOB_MEDICO, "Plantao e triagem", 1497.0500, 1304.9429, 1093.2891, COLOR_GREEN },
    { LOCATION_JOB_MEDICO, "Farmacia hospitalar", 1494.3252, 1308.2429, 1093.2891, COLOR_GRAY },
    { LOCATION_JOB_BOMBEIRO, "Central de ocorrencias", 620.0274, -74.7031, 997.9922, COLOR_ADMIN },
    { LOCATION_JOB_BOMBEIRO, "Equipamentos de resgate", 617.2274, -71.9031, 997.9922, COLOR_GRAY },
    { LOCATION_JOB_SEGURANCA, "Mesa de monitoramento", 386.5259, 176.2381, 1008.3828, COLOR_ADMIN },
    { LOCATION_JOB_SEGURANCA, "Armarios e relatorios", 384.8259, 170.9381, 1008.3828, COLOR_GRAY },
    { LOCATION_JOB_CARTEIRO, "Triagem de cartas", 1305.1199, -1.7875, 1001.0283, COLOR_YELLOW },
    { LOCATION_JOB_CARTEIRO, "Caixas de entrega", 1302.5199, 1.0125, 1001.0283, COLOR_GRAY },
    { LOCATION_JOB_MOTOBOY, "Retirada de pedidos", 374.8565, -131.3607, 1001.4922, COLOR_YELLOW },
    { LOCATION_JOB_MOTOBOY, "Cozinha de apoio", 372.5565, -128.5607, 1001.4922, COLOR_GRAY },
    { LOCATION_JOB_PESCADOR, "Balanca de pescado", 1305.1199, -1.7875, 1001.0283, COLOR_YELLOW },
    { LOCATION_JOB_PESCADOR, "Camara fria", 1302.5199, 1.0125, 1001.0283, COLOR_GRAY },
    { LOCATION_JOB_AGRICULTOR, "Escritorio da fazenda", 1305.1199, -1.7875, 1001.0283, COLOR_YELLOW },
    { LOCATION_JOB_AGRICULTOR, "Deposito de sementes", 1302.5199, 1.0125, 1001.0283, COLOR_GRAY },
    { LOCATION_JOB_MINERADOR, "Controle da mina", 1305.1199, -1.7875, 1001.0283, COLOR_YELLOW },
    { LOCATION_JOB_MINERADOR, "Equipamentos de extracao", 1302.5199, 1.0125, 1001.0283, COLOR_GRAY },
    { LOCATION_JOB_PEDREIRO, "Engenharia da obra", 1305.1199, -1.7875, 1001.0283, COLOR_YELLOW },
    { LOCATION_JOB_PEDREIRO, "Materiais e ferramentas", 1302.5199, 1.0125, 1001.0283, COLOR_GRAY },
    { LOCATION_JOB_GARCOM, "Balcao do salao", 365.7346, -74.8461, 1001.5078, COLOR_YELLOW },
    { LOCATION_JOB_GARCOM, "Mesas para atendimento", 363.1346, -72.0461, 1001.5078, COLOR_GRAY },
    { LOCATION_JOB_COZINHEIRO, "Passa-pratos", 374.8565, -131.3607, 1001.4922, COLOR_YELLOW },
    { LOCATION_JOB_COZINHEIRO, "Preparo e estoque", 372.5565, -128.5607, 1001.4922, COLOR_GRAY },
    { LOCATION_JOB_VENDEDOR, "Balcao de armas", 296.9199, -112.0719, 1001.5156, COLOR_ORANGE },
    { LOCATION_JOB_VENDEDOR, "Vitrine e estoque controlado", 294.8199, -109.6719, 1001.5156, COLOR_GRAY },
    { LOCATION_JOB_JORNALISTA, "Mesa de redacao", 836.8698, 7.4100, 1004.1797, COLOR_YELLOW },
    { LOCATION_JOB_JORNALISTA, "Estudio de boletins", 834.2698, 10.2100, 1004.1797, COLOR_GRAY },
    { LOCATION_JOB_ADVOGADO, "Mesa de atendimento juridico", 386.5259, 176.2381, 1008.3828, COLOR_BLUE },
    { LOCATION_JOB_ADVOGADO, "Arquivo de processos", 384.8259, 170.9381, 1008.3828, COLOR_GRAY },
    { LOCATION_JOB_JUIZ, "Gabinete de audiencias", 386.5259, 176.2381, 1008.3828, COLOR_BLUE },
    { LOCATION_JOB_JUIZ, "Cartorio e processos", 384.8259, 170.9381, 1008.3828, COLOR_GRAY },
    { LOCATION_JOB_AMBULANCIA, "Central de ambulancias", 1497.0500, 1304.9429, 1093.2891, COLOR_GREEN },
    { LOCATION_JOB_AMBULANCIA, "Macas e equipamentos", 1494.3252, 1308.2429, 1093.2891, COLOR_GRAY },
    { LOCATION_JOB_TECNICO, "Mesa de chamados", 620.0274, -74.7031, 997.9922, COLOR_YELLOW },
    { LOCATION_JOB_TECNICO, "Ferramentas e cabos", 617.2274, -71.9031, 997.9922, COLOR_GRAY },
    { LOCATION_JOB_PRF, "Arsenal PRF e escala", 246.7839, 67.3002, 1003.6406, COLOR_ADMIN },
    { LOCATION_JOB_PRF, "Sala de ocorrencias rodoviarias", 250.3839, 63.9002, 1003.6406, COLOR_GRAY },
    { LOCATION_JOB_POLICIA_FEDERAL, "Arsenal federal e mandados", 246.7839, 67.3002, 1003.6406, COLOR_ADMIN },
    { LOCATION_JOB_POLICIA_FEDERAL, "Sala de operacoes federais", 250.3839, 63.9002, 1003.6406, COLOR_GRAY },
    { LOCATION_JOB_POLICIA_CIVIL, "Cartorio e investigacao", 246.7839, 67.3002, 1003.6406, COLOR_ADMIN },
    { LOCATION_JOB_POLICIA_CIVIL, "Pericia e custodia civil", 264.6000, 77.5000, 1001.0391, COLOR_GRAY },
    { LOCATION_JOB_POLICIA_PENAL, "Escala penal e escolta", 246.7839, 67.3002, 1003.6406, COLOR_ADMIN },
    { LOCATION_JOB_POLICIA_PENAL, "Custodia e transferencia", 264.6000, 77.5000, 1001.0391, COLOR_GRAY },
    { LOCATION_CONVENIENCIA_1, "Geladeira de bebidas", -25.8845, -182.8689, 1003.5469, COLOR_BLUE },
    { LOCATION_CONVENIENCIA_1, "Prateleira de alimentos", -23.5845, -185.8689, 1003.5469, COLOR_ORANGE },
    { LOCATION_CONVENIENCIA_2, "Geladeira de bebidas", -25.8845, -182.8689, 1003.5469, COLOR_BLUE },
    { LOCATION_CONVENIENCIA_2, "Prateleira de alimentos", -23.5845, -185.8689, 1003.5469, COLOR_ORANGE }
};

new gServiceNpcs[][eServiceNpc] =
{
    { "Recepcionista Prefeitura", 147, 1482.3000, -1771.2000, 18.7958, 90.0, 0, 0 },
    { "Triagem Hospital", 274, 1173.2000, -1324.3000, 15.4030, 270.0, 0, 0 },
    { "Recepcao Delegacia", 280, 1553.7000, -1675.2000, 16.1953, 180.0, 0, 0 },
    { "Gerente Banco", 150, 1460.4000, -1012.3000, 26.8438, 0.0, 0, 0 },
    { "Vendedor Concessionaria", 171, 2130.7000, -1149.0000, 24.1232, 180.0, 0, 0 },
    { "Atendente DETRAN", 255, 1034.9500, -1027.2000, 32.1016, 180.0, 0, 0 },
    { "Frentista Idlewood", 50, 1939.5000, -1773.1000, 13.5469, 180.0, 0, 0 },
    { "Caixa Conveniencia", 29, 1937.2000, -1769.1000, 13.5469, 0.0, 0, 0 }
};

new gPlayerGpsLocation[MAX_PLAYERS];
new gPlayerGpsDialogLocations[MAX_PLAYERS][MAX_GPS_DIALOG_LOCATIONS];
new gPlayerGpsDialogCount[MAX_PLAYERS];
new Text3D:gLocationTextLabel[sizeof(gServerLocations)];
new Text3D:gAutoInteriorActionLabel[sizeof(gAutoInteriors)];
new Text3D:gAutoInteriorExitLabel[sizeof(gAutoInteriors)];
new Text3D:gInteriorSpotLabel[sizeof(gInteriorSpots)];
new Text3D:gPrfPostWarningLabel = Text3D:INVALID_3DTEXT_ID;
new gServiceNpcActor[sizeof(gServiceNpcs)];
new gPlayerAutoInterior[MAX_PLAYERS];
new gPlayerInteriorMoveTick[MAX_PLAYERS];
new gPlayerInteriorSpotTick[MAX_PLAYERS];
new gPlayerInPoliceCell[MAX_PLAYERS];
new gPlayerLocationIconVisible[MAX_PLAYERS][sizeof(gServerLocations)];

new gNpcTransportLocations[] =
{
    LOCATION_PREFEITURA,
    LOCATION_HOSPITAL,
    LOCATION_DELEGACIA,
    LOCATION_CONCESSIONARIA,
    LOCATION_CONVENIENCIA_1,
    LOCATION_CONVENIENCIA_2,
    LOCATION_POSTO_IDLEWOOD,
    LOCATION_POSTO_MARKET,
    LOCATION_DETRAN,
    LOCATION_GARAGEM_PUBLICA,
    LOCATION_PATIO_MUNICIPAL,
    LOCATION_JOB_TAXISTA,
    LOCATION_JOB_MOTORISTA,
    LOCATION_JOB_MECANICO,
    LOCATION_JOB_FRENTISTA,
    LOCATION_JOB_PRF,
    LOCATION_JOB_POLICIA_FEDERAL,
    LOCATION_JOB_POLICIA_CIVIL,
    LOCATION_JOB_POLICIA_PENAL,
    LOCATION_BANCO
};

stock GetLocationName(locationid, name[], size = sizeof(name))
{
    if (locationid < 0 || locationid >= sizeof(gServerLocations))
    {
        format(name, size, "Local invalido");
        return 0;
    }

    format(name, size, "%s", gServerLocations[locationid][locName]);
    return 1;
}

stock SetPlayerToLocation(playerid, locationid)
{
    if (locationid < 0 || locationid >= sizeof(gServerLocations))
    {
        return 0;
    }

    SetPlayerInterior(playerid, gServerLocations[locationid][locInterior]);
    SetPlayerVirtualWorld(playerid, gServerLocations[locationid][locVirtualWorld]);
    SetPlayerPos(playerid, gServerLocations[locationid][locX], gServerLocations[locationid][locY], gServerLocations[locationid][locZ]);
    SetPlayerFacingAngle(playerid, gServerLocations[locationid][locA]);
    SetCameraBehindPlayer(playerid);
    Security_GrantTeleportGrace(playerid);
    gPlayerAutoInterior[playerid] = -1;
    gPlayerInteriorMoveTick[playerid] = GetTickCount();
    return 1;
}

stock FindAutoInteriorByLocation(locationid)
{
    new index;

    for (index = 0; index < sizeof(gAutoInteriors); index++)
    {
        if (gAutoInteriors[index][autoLocation] == locationid)
        {
            return index;
        }
    }
    return -1;
}

stock World_IsWorkplaceLocation(locationid)
{
    return (
        (locationid >= LOCATION_JOB_LIXEIRO && locationid <= LOCATION_JOB_MOTORISTA) ||
        (locationid >= LOCATION_JOB_TAXISTA && locationid <= LOCATION_JOB_TECNICO) ||
        locationid == LOCATION_JOB_PRF ||
        locationid == LOCATION_JOB_POLICIA_FEDERAL ||
        locationid == LOCATION_JOB_POLICIA_CIVIL ||
        locationid == LOCATION_JOB_POLICIA_PENAL
    );
}

stock World_AutoInteriorHasExit(interiorIndex)
{
    if (interiorIndex < 0 || interiorIndex >= sizeof(gAutoInteriors))
    {
        return 0;
    }

    if (gAutoInteriors[interiorIndex][autoExitX] == 0.0 && gAutoInteriors[interiorIndex][autoExitY] == 0.0 && gAutoInteriors[interiorIndex][autoExitZ] == 0.0)
    {
        return 0;
    }

    return 1;
}

stock World_CountJobExitProblems()
{
    new locationid;
    new interiorIndex;
    new problems;

    for (locationid = 1; locationid < sizeof(gServerLocations); locationid++)
    {
        if (!World_IsWorkplaceLocation(locationid))
        {
            continue;
        }

        interiorIndex = FindAutoInteriorByLocation(locationid);
        if (interiorIndex == -1 || !World_AutoInteriorHasExit(interiorIndex))
        {
            problems++;
        }
    }
    return problems;
}

stock Float:World_Dist2D(Float:x1, Float:y1, Float:x2, Float:y2)
{
    return floatsqroot(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

stock World_SpotNearControls(spotid, interiorIndex)
{
    if (spotid < 0 || spotid >= sizeof(gInteriorSpots))
    {
        return 1;
    }

    if (interiorIndex < 0 || interiorIndex >= sizeof(gAutoInteriors))
    {
        return 0;
    }

    if (World_Dist2D(
        gInteriorSpots[spotid][spotX],
        gInteriorSpots[spotid][spotY],
        gAutoInteriors[interiorIndex][autoActionX],
        gAutoInteriors[interiorIndex][autoActionY]) < SPOT_MIN_CONTROL_DIST)
    {
        return 1;
    }

    if (World_Dist2D(
        gInteriorSpots[spotid][spotX],
        gInteriorSpots[spotid][spotY],
        gAutoInteriors[interiorIndex][autoExitX],
        gAutoInteriors[interiorIndex][autoExitY]) < SPOT_MIN_CONTROL_DIST)
    {
        return 1;
    }

    return 0;
}

stock World_TryEnterAutoInterior(playerid, locationid)
{
    new interiorIndex = FindAutoInteriorByLocation(locationid);

    if (interiorIndex == -1)
    {
        return 0;
    }

    return SetPlayerToAutoInterior(playerid, interiorIndex);
}

stock SetPlayerToAutoInterior(playerid, interiorIndex)
{
    new locationid;
    new message[96];

    if (interiorIndex < 0 || interiorIndex >= sizeof(gAutoInteriors))
    {
        return 0;
    }

    locationid = gAutoInteriors[interiorIndex][autoLocation];
    SetPlayerInterior(playerid, gAutoInteriors[interiorIndex][autoInterior]);
    SetPlayerVirtualWorld(playerid, gAutoInteriors[interiorIndex][autoVirtualWorld]);
    SetPlayerPos(playerid, gAutoInteriors[interiorIndex][autoSpawnX], gAutoInteriors[interiorIndex][autoSpawnY], gAutoInteriors[interiorIndex][autoSpawnZ]);
    SetPlayerFacingAngle(playerid, gAutoInteriors[interiorIndex][autoSpawnA]);
    SetCameraBehindPlayer(playerid);
    Security_GrantTeleportGrace(playerid);

    gPlayerAutoInterior[playerid] = interiorIndex;
    gPlayerInteriorMoveTick[playerid] = GetTickCount();

    format(message, sizeof(message), "Voce entrou em: %s.", gServerLocations[locationid][locName]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock World_ExitAutoInterior(playerid, notify = 1)
{
    new interiorIndex = gPlayerAutoInterior[playerid];
    new locationid;

    if (interiorIndex < 0 || interiorIndex >= sizeof(gAutoInteriors))
    {
        interiorIndex = FindCurrentAutoInterior(playerid);
        if (interiorIndex < 0 || interiorIndex >= sizeof(gAutoInteriors))
        {
            return 0;
        }
    }

    if (gPlayerInPoliceCell[playerid])
    {
        if (notify)
        {
            SendClientMessage(playerid, COLOR_RED, "Voce esta detido e nao pode sair da custodia.");
        }
        return 1;
    }

    locationid = gAutoInteriors[interiorIndex][autoLocation];
    SetPlayerToLocation(playerid, locationid);
    gPlayerAutoInterior[playerid] = -1;
    gPlayerInteriorMoveTick[playerid] = GetTickCount();

    if (notify)
    {
        SendClientMessage(playerid, COLOR_GREEN, "Voce saiu do estabelecimento.");
    }
    return 1;
}

stock FindNearestAutoInteriorExit(playerid)
{
    new interiorIndex = FindCurrentAutoInterior(playerid);

    if (interiorIndex < 0 || interiorIndex >= sizeof(gAutoInteriors))
    {
        return -1;
    }

    if (IsPlayerInRangeOfPoint(playerid, AUTO_INTERIOR_EXIT_ACTION_RADIUS, gAutoInteriors[interiorIndex][autoExitX], gAutoInteriors[interiorIndex][autoExitY], gAutoInteriors[interiorIndex][autoExitZ]))
    {
        return interiorIndex;
    }

    return -1;
}

stock HandleAutoInteriorExit(playerid, showError = 1)
{
    new interiorIndex = FindNearestAutoInteriorExit(playerid);

    if (interiorIndex == -1)
    {
        if (showError)
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta perto de uma saida.");
        }
        return 0;
    }

    return World_ExitAutoInterior(playerid);
}

stock Float:GetAutoInteriorExitRadius(interiorIndex)
{
    new locationid;

    if (interiorIndex < 0 || interiorIndex >= sizeof(gAutoInteriors))
    {
        return AUTO_INTERIOR_EXIT_RADIUS;
    }

    locationid = gAutoInteriors[interiorIndex][autoLocation];
    switch (locationid)
    {
        case LOCATION_HOSPITAL, LOCATION_JOB_MEDICO, LOCATION_JOB_AMBULANCIA:
        {
            return 3.0;
        }
    }

    return AUTO_INTERIOR_EXIT_RADIUS;
}

stock World_SendToPoliceCellSlot(playerid, slot)
{
    new interiorIndex = FindAutoInteriorByLocation(LOCATION_DELEGACIA);
    new Float:x = 264.6000;
    new Float:y = 77.5000;
    new Float:z = 1001.0391;
    new Float:a = 90.0;

    if (interiorIndex == -1)
    {
        SetPlayerToLocation(playerid, LOCATION_DELEGACIA);
        return 0;
    }

    switch (slot % 6)
    {
        case 0: { x = 264.6000; y = 77.5000; z = 1001.0391; a = 90.0; }
        case 1: { x = 264.6000; y = 75.7000; z = 1001.0391; a = 90.0; }
        case 2: { x = 266.4000; y = 77.5000; z = 1001.0391; a = 270.0; }
        case 3: { x = 266.4000; y = 75.7000; z = 1001.0391; a = 270.0; }
        case 4: { x = 268.1000; y = 77.5000; z = 1001.0391; a = 270.0; }
        case 5: { x = 268.1000; y = 75.7000; z = 1001.0391; a = 270.0; }
    }

    SetPlayerInterior(playerid, gAutoInteriors[interiorIndex][autoInterior]);
    SetPlayerVirtualWorld(playerid, gAutoInteriors[interiorIndex][autoVirtualWorld]);
    SetPlayerPos(playerid, x, y, z);
    SetPlayerFacingAngle(playerid, a);
    SetCameraBehindPlayer(playerid);
    Security_GrantTeleportGrace(playerid);
    gPlayerAutoInterior[playerid] = interiorIndex;
    gPlayerInPoliceCell[playerid] = 1;
    gPlayerInteriorMoveTick[playerid] = GetTickCount();
    return 1;
}

stock World_SendPlayerToPoliceCell(playerid)
{
    return World_SendToPoliceCellSlot(playerid, 0);
}

stock World_SendNpcToPoliceCell(playerid, npcIndex)
{
    return World_SendToPoliceCellSlot(playerid, npcIndex + 1);
}

stock World_ReleaseFromPoliceCell(playerid)
{
    gPlayerInPoliceCell[playerid] = 0;
    SetPlayerToLocation(playerid, LOCATION_DELEGACIA);
    return 1;
}

stock IsPlayerInsideAutoInterior(playerid, interiorIndex)
{
    if (interiorIndex < 0 || interiorIndex >= sizeof(gAutoInteriors))
    {
        return 0;
    }

    if (GetPlayerInterior(playerid) != gAutoInteriors[interiorIndex][autoInterior])
    {
        return 0;
    }

    if (GetPlayerVirtualWorld(playerid) != gAutoInteriors[interiorIndex][autoVirtualWorld])
    {
        return 0;
    }

    return 1;
}

stock SetupPlayerForClassSelection(playerid)
{
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerPos(playerid, gServerLocations[LOCATION_SPAWN][locX], gServerLocations[LOCATION_SPAWN][locY], gServerLocations[LOCATION_SPAWN][locZ]);
    SetPlayerFacingAngle(playerid, gServerLocations[LOCATION_SPAWN][locA]);
    Security_GrantTeleportGrace(playerid);
    SetPlayerCameraPos(playerid, 1737.5350, -1862.4083, 16.5765);
    SetPlayerCameraLookAt(playerid, gServerLocations[LOCATION_SPAWN][locX], gServerLocations[LOCATION_SPAWN][locY], gServerLocations[LOCATION_SPAWN][locZ]);
    return 1;
}

stock AddWorldPlayerClasses()
{
    AddPlayerClass(0, gServerLocations[LOCATION_SPAWN][locX], gServerLocations[LOCATION_SPAWN][locY], gServerLocations[LOCATION_SPAWN][locZ], gServerLocations[LOCATION_SPAWN][locA], 0, 0, 0, 0, 0, 0);
    AddPlayerClass(7, gServerLocations[LOCATION_SPAWN][locX], gServerLocations[LOCATION_SPAWN][locY], gServerLocations[LOCATION_SPAWN][locZ], gServerLocations[LOCATION_SPAWN][locA], 0, 0, 0, 0, 0, 0);
    AddPlayerClass(23, gServerLocations[LOCATION_SPAWN][locX], gServerLocations[LOCATION_SPAWN][locY], gServerLocations[LOCATION_SPAWN][locZ], gServerLocations[LOCATION_SPAWN][locA], 0, 0, 0, 0, 0, 0);
    AddPlayerClass(29, gServerLocations[LOCATION_SPAWN][locX], gServerLocations[LOCATION_SPAWN][locY], gServerLocations[LOCATION_SPAWN][locZ], gServerLocations[LOCATION_SPAWN][locA], 0, 0, 0, 0, 0, 0);
    return 1;
}

stock CreateWorldVehicles()
{
    AddStaticVehicle(411, 1728.6145, -1863.0430, 13.2776, 90.0, 1, 1);
    AddStaticVehicle(560, 1728.6145, -1857.0430, 13.2776, 90.0, 3, 3);
    AddStaticVehicle(468, 1738.6145, -1851.0430, 13.2776, 180.0, 6, 6);
    return 1;
}

stock World_IsGasStationLocation(locationid)
{
    return (
        locationid == LOCATION_POSTO_IDLEWOOD ||
        locationid == LOCATION_POSTO_MARKET ||
        locationid == LOCATION_POSTO_DILLIMORE ||
        locationid == LOCATION_POSTO_FLINT ||
        locationid == LOCATION_POSTO_EL_QUEBRADOS ||
        locationid == LOCATION_POSTO_TIERRA
    );
}

stock Float:GetLocationInteractRadius(locationid)
{
    if (World_IsGasStationLocation(locationid))
    {
        return LOCATION_INTERACT_GAS;
    }

    if (
        locationid == LOCATION_PREFEITURA ||
        locationid == LOCATION_INTERIOR_PREF ||
        locationid == LOCATION_CONCESSIONARIA ||
        locationid == LOCATION_BANCO ||
        locationid == LOCATION_DETRAN ||
        locationid == LOCATION_GARAGEM_PUBLICA ||
        locationid == LOCATION_PATIO_MUNICIPAL
    )
    {
        return LOCATION_INTERACT_BUSINESS;
    }

    if (locationid == LOCATION_HOSPITAL || locationid == LOCATION_DELEGACIA)
    {
        return LOCATION_INTERACT_PUBLIC;
    }

    if (locationid == LOCATION_JOB_PESCADOR || locationid == LOCATION_JOB_AGRICULTOR || locationid == LOCATION_JOB_MINERADOR)
    {
        return LOCATION_INTERACT_FIELD;
    }

    if (
        (locationid >= LOCATION_JOB_LIXEIRO && locationid <= LOCATION_JOB_MOTORISTA) ||
        (locationid >= LOCATION_JOB_TAXISTA && locationid <= LOCATION_JOB_TECNICO) ||
        locationid == LOCATION_JOB_PRF ||
        locationid == LOCATION_JOB_POLICIA_FEDERAL ||
        locationid == LOCATION_JOB_POLICIA_CIVIL ||
        locationid == LOCATION_JOB_POLICIA_PENAL
    )
    {
        return LOCATION_INTERACT_JOB;
    }

    return LOCATION_INTERACT_DEFAULT;
}

stock World_IsAtmLocation(locationid)
{
    return (
        locationid == LOCATION_ATM_PREFEITURA ||
        locationid == LOCATION_ATM_HOSPITAL ||
        locationid == LOCATION_ATM_IDLEWOOD ||
        locationid == LOCATION_ATM_CONCESSIONARIA
    );
}

stock World_IsBankBranchLocation(locationid)
{
    return (locationid == LOCATION_BANCO);
}

stock World_IsRestaurantLocation(locationid)
{
    return (locationid == LOCATION_JOB_GARCOM || locationid == LOCATION_JOB_COZINHEIRO || locationid == LOCATION_JOB_MOTOBOY);
}

stock World_IsStoreLocation(locationid)
{
    return (
        locationid == LOCATION_CONVENIENCIA_1 ||
        locationid == LOCATION_CONVENIENCIA_2 ||
        locationid == LOCATION_JOB_FRENTISTA
    );
}

stock World_IsWeaponShopLocation(locationid)
{
    return (locationid == LOCATION_JOB_VENDEDOR);
}

stock GetLocationLabelText(locationid, text[], size = sizeof(text))
{
    switch (locationid)
    {
        case LOCATION_PREFEITURA:
        {
            format(text, size, "Prefeitura\nAproxime-se para entrar\nAtendimento NPC no interior");
        }
        case LOCATION_INTERIOR_PREF:
        {
            format(text, size, "Balcao da Prefeitura\nAtendente NPC\nAperte ENTER");
        }
        case LOCATION_HOSPITAL:
        {
            format(text, size, "Hospital\nAproxime-se para entrar\nTriagem NPC no interior");
        }
        case LOCATION_DELEGACIA:
        {
            format(text, size, "Delegacia\nAproxime-se para entrar\nRecepcao NPC no interior");
        }
        case LOCATION_CONCESSIONARIA:
        {
            format(text, size, "Concessionaria\nAproxime-se para entrar\nVendedor NPC no balcao");
        }
        case LOCATION_DETRAN:
        {
            format(text, size, "DETRAN Los Santos\nAperte ENTER ou use /detran\nRegistro, placa, IPVA e CRLV");
        }
        case LOCATION_GARAGEM_PUBLICA:
        {
            format(text, size, "Garagem Publica\nAperte ENTER ou use /garagem\nGuardar e retirar veiculos");
        }
        case LOCATION_PATIO_MUNICIPAL:
        {
            format(text, size, "Patio Municipal\nAperte ENTER ou use /patio\nAtendente NPC libera veiculos");
        }
        case LOCATION_CONVENIENCIA_1, LOCATION_CONVENIENCIA_2:
        {
            format(text, size, "%s\nAproxime-se para entrar\nAtendente NPC", gServerLocations[locationid][locName]);
        }
        case LOCATION_BANCO:
        {
            format(text, size, "Banco Central\nAperte ENTER ou use /interagir\nGerente, conta e emprestimos");
        }
        case LOCATION_ATM_PREFEITURA, LOCATION_ATM_HOSPITAL, LOCATION_ATM_IDLEWOOD, LOCATION_ATM_CONCESSIONARIA:
        {
            format(text, size, "%s\nAperte ENTER ou use /caixa\nSaque, PIX e cartao virtual", gServerLocations[locationid][locName]);
        }
        case LOCATION_POSTO_IDLEWOOD, LOCATION_POSTO_MARKET, LOCATION_POSTO_DILLIMORE, LOCATION_POSTO_FLINT, LOCATION_POSTO_EL_QUEBRADOS, LOCATION_POSTO_TIERRA:
        {
            format(text, size, "%s\nAperte ENTER ou use /abastecer\nFrentista NPC", gServerLocations[locationid][locName]);
        }
        default:
        {
            if (World_IsWeaponShopLocation(locationid))
            {
                format(text, size, "%s\nAproxime-se para entrar\nLoja de armas legalizada", gServerLocations[locationid][locName]);
            }
            else if (World_IsRestaurantLocation(locationid) || World_IsStoreLocation(locationid))
            {
                format(text, size, "%s\nAproxime-se para entrar\nAtendimento NPC", gServerLocations[locationid][locName]);
            }
            else
            {
                format(text, size, "%s\nAproxime-se para entrar\nAtendimento de servico", gServerLocations[locationid][locName]);
            }
        }
    }
    return 1;
}

stock GetLocationLabelColor(locationid)
{
    switch (locationid)
    {
        case LOCATION_PREFEITURA, LOCATION_INTERIOR_PREF:
        {
            return COLOR_BLUE;
        }
        case LOCATION_HOSPITAL:
        {
            return COLOR_GREEN;
        }
        case LOCATION_DELEGACIA, LOCATION_JOB_POLICIAL, LOCATION_JOB_SEGURANCA, LOCATION_JOB_PRF, LOCATION_JOB_POLICIA_FEDERAL, LOCATION_JOB_POLICIA_CIVIL, LOCATION_JOB_POLICIA_PENAL:
        {
            return COLOR_ADMIN;
        }
        case LOCATION_CONCESSIONARIA, LOCATION_DETRAN, LOCATION_GARAGEM_PUBLICA, LOCATION_PATIO_MUNICIPAL, LOCATION_JOB_FRENTISTA, LOCATION_JOB_VENDEDOR, LOCATION_CONVENIENCIA_1, LOCATION_CONVENIENCIA_2, LOCATION_BANCO, LOCATION_ATM_PREFEITURA, LOCATION_ATM_HOSPITAL, LOCATION_ATM_IDLEWOOD, LOCATION_ATM_CONCESSIONARIA, LOCATION_POSTO_IDLEWOOD, LOCATION_POSTO_MARKET, LOCATION_POSTO_DILLIMORE, LOCATION_POSTO_FLINT, LOCATION_POSTO_EL_QUEBRADOS, LOCATION_POSTO_TIERRA:
        {
            return COLOR_ORANGE;
        }
    }
    return COLOR_YELLOW;
}

stock GetAutoInteriorActionText(interiorIndex, text[], size = sizeof(text))
{
    new locationid = gAutoInteriors[interiorIndex][autoLocation];
    new jobName[32];

    switch (gAutoInteriors[interiorIndex][autoActionType])
    {
        case AUTO_ACTION_CONVENIENCE:
        {
            format(text, size, "Atendente NPC\nAperte ENTER ou use /comprar\nComida e bebida");
        }
        case AUTO_ACTION_JOB:
        {
            GetJobName(Job_FindByLocation(locationid), jobName, sizeof(jobName));
            if (World_IsRestaurantLocation(locationid))
            {
                format(text, size, "Restaurante\nAtendente NPC\nAperte ENTER para cardapio");
            }
            else if (World_IsWeaponShopLocation(locationid))
            {
                format(text, size, "Ammu-Nation\nVenda legal de armas\nENTER para comprar");
            }
            else if (World_IsStoreLocation(locationid))
            {
                format(text, size, "Loja\nAtendente NPC\nAperte ENTER para comprar");
            }
            else
            {
                format(text, size, "%s\nBalcao de servico\nENTER para atender ou bater ponto", jobName);
            }
        }
        default:
        {
            format(text, size, "%s\nAtendimento NPC\nENTER para interagir", gServerLocations[locationid][locName]);
        }
    }
    return 1;
}

stock CreateAutoInteriorLabels()
{
    new index;
    new text[144];

    for (index = 0; index < sizeof(gAutoInteriors); index++)
    {
        GetAutoInteriorActionText(index, text, sizeof(text));
        gAutoInteriorActionLabel[index] = Create3DTextLabel(
            text,
            GetLocationLabelColor(gAutoInteriors[index][autoLocation]),
            gAutoInteriors[index][autoActionX],
            gAutoInteriors[index][autoActionY],
            gAutoInteriors[index][autoActionZ] + 0.75,
            LOCATION_LABEL_DRAW_DISTANCE,
            gAutoInteriors[index][autoVirtualWorld],
            1
        );

        gAutoInteriorExitLabel[index] = Create3DTextLabel(
            "Saida\nENTER ou /sair",
            COLOR_GRAY,
            gAutoInteriors[index][autoExitX],
            gAutoInteriors[index][autoExitY],
            gAutoInteriors[index][autoExitZ] + 0.35,
            LOCATION_LABEL_DRAW_DISTANCE,
            gAutoInteriors[index][autoVirtualWorld],
            1
        );
    }
    return 1;
}

stock DestroyAutoInteriorLabels()
{
    new index;

    for (index = 0; index < sizeof(gAutoInteriors); index++)
    {
        if (gAutoInteriorActionLabel[index] != Text3D:INVALID_3DTEXT_ID)
        {
            Delete3DTextLabel(gAutoInteriorActionLabel[index]);
            gAutoInteriorActionLabel[index] = Text3D:INVALID_3DTEXT_ID;
        }

        if (gAutoInteriorExitLabel[index] != Text3D:INVALID_3DTEXT_ID)
        {
            Delete3DTextLabel(gAutoInteriorExitLabel[index]);
            gAutoInteriorExitLabel[index] = Text3D:INVALID_3DTEXT_ID;
        }
    }
    return 1;
}

stock GetInteriorSpotLabelText(spotid, text[], size = sizeof(text))
{
    new spotName[72];
    new locationid;

    if (spotid < 0 || spotid >= sizeof(gInteriorSpots))
    {
        format(text, size, "Ponto interno\nAperte ENTER");
        return 0;
    }

    format(spotName, sizeof(spotName), "%s", gInteriorSpots[spotid][spotText]);
    locationid = gInteriorSpots[spotid][spotLocation];

    if (
        World_IsRestaurantLocation(locationid) &&
        (strfind(spotName, "Balcao", true) != -1 || strfind(spotName, "Mesas", true) != -1 || strfind(spotName, "Passa-pratos", true) != -1)
    )
    {
        format(text, size, "%s\nAtendente NPC\nAperte ENTER", spotName);
        return 1;
    }

    if (
        (World_IsStoreLocation(locationid) || World_IsWeaponShopLocation(locationid)) &&
        (strfind(spotName, "Caixa", true) != -1 || strfind(spotName, "Prateleira", true) != -1 || strfind(spotName, "Geladeira", true) != -1)
    )
    {
        format(text, size, "%s\nAtendente NPC\nAperte ENTER", spotName);
        return 1;
    }

    if (
        World_IsWeaponShopLocation(locationid) &&
        (strfind(spotName, "Balcao", true) != -1 || strfind(spotName, "Vitrine", true) != -1)
    )
    {
        format(text, size, "%s\nVenda legal de armas\nAperte ENTER", spotName);
        return 1;
    }

    if (strfind(spotName, "Triagem", true) != -1 || strfind(spotName, "Leitos", true) != -1 || strfind(spotName, "Recepcao", true) != -1 || strfind(spotName, "venda", true) != -1)
    {
        format(text, size, "%s\nAtendimento NPC\nAperte ENTER", spotName);
        return 1;
    }

    format(text, size, "%s\nArea de trabalho\nAperte ENTER", spotName);
    return 1;
}

stock CreateInteriorSpotLabels()
{
    new index;
    new interiorIndex;
    new text[128];

    for (index = 0; index < sizeof(gInteriorSpots); index++)
    {
        interiorIndex = FindAutoInteriorByLocation(gInteriorSpots[index][spotLocation]);
        if (interiorIndex == -1)
        {
            continue;
        }

        if (World_SpotNearControls(index, interiorIndex))
        {
            continue;
        }

        GetInteriorSpotLabelText(index, text, sizeof(text));
        gInteriorSpotLabel[index] = Create3DTextLabel(
            text,
            gInteriorSpots[index][spotColor],
            gInteriorSpots[index][spotX],
            gInteriorSpots[index][spotY],
            gInteriorSpots[index][spotZ] + 0.35,
            LOCATION_LABEL_DRAW_DISTANCE,
            gAutoInteriors[interiorIndex][autoVirtualWorld],
            1
        );
    }
    return 1;
}

stock DestroyInteriorSpotLabels()
{
    new index;

    for (index = 0; index < sizeof(gInteriorSpots); index++)
    {
        if (gInteriorSpotLabel[index] != Text3D:INVALID_3DTEXT_ID)
        {
            Delete3DTextLabel(gInteriorSpotLabel[index]);
            gInteriorSpotLabel[index] = Text3D:INVALID_3DTEXT_ID;
        }
    }
    return 1;
}

stock CreateServiceNpcActors()
{
    new index;
    new actorid;

    for (index = 0; index < sizeof(gServiceNpcs); index++)
    {
        gServiceNpcActor[index] = INVALID_ACTOR_ID;
        actorid = CreateActor(
            gServiceNpcs[index][serviceNpcSkin],
            gServiceNpcs[index][serviceNpcX],
            gServiceNpcs[index][serviceNpcY],
            gServiceNpcs[index][serviceNpcZ],
            gServiceNpcs[index][serviceNpcA]
        );

        if (actorid == INVALID_ACTOR_ID)
        {
            continue;
        }

        SetActorVirtualWorld(actorid, gServiceNpcs[index][serviceNpcWorld]);
        SetActorInvulnerable(actorid, 1);
        gServiceNpcActor[index] = actorid;
    }
    return 1;
}

stock DestroyServiceNpcActors()
{
    new index;

    for (index = 0; index < sizeof(gServiceNpcs); index++)
    {
        if (gServiceNpcActor[index] != INVALID_ACTOR_ID)
        {
            DestroyActor(gServiceNpcActor[index]);
            gServiceNpcActor[index] = INVALID_ACTOR_ID;
        }
    }
    return 1;
}

stock CreatePrfPostWarning()
{
    gPrfPostWarningLabel = Create3DTextLabel(
        "POSTO DA PRF\nDIMINUA A VELOCIDADE\nFiscalizacao rodoviaria",
        COLOR_ADMIN,
        1422.9353,
        -952.1232,
        38.9000,
        80.0,
        0,
        1
    );
    return 1;
}

stock DestroyPrfPostWarning()
{
    if (gPrfPostWarningLabel != Text3D:INVALID_3DTEXT_ID)
    {
        Delete3DTextLabel(gPrfPostWarningLabel);
        gPrfPostWarningLabel = Text3D:INVALID_3DTEXT_ID;
    }
    return 1;
}

stock CreateWorldInteractionLabels()
{
    new locationid;
    new text[144];
    new index;

    for (locationid = 0; locationid < sizeof(gServerLocations); locationid++)
    {
        gLocationTextLabel[locationid] = Text3D:INVALID_3DTEXT_ID;
    }

    for (index = 0; index < sizeof(gAutoInteriors); index++)
    {
        gAutoInteriorActionLabel[index] = Text3D:INVALID_3DTEXT_ID;
        gAutoInteriorExitLabel[index] = Text3D:INVALID_3DTEXT_ID;
    }

    for (index = 0; index < sizeof(gInteriorSpots); index++)
    {
        gInteriorSpotLabel[index] = Text3D:INVALID_3DTEXT_ID;
    }

    for (index = 0; index < sizeof(gServiceNpcs); index++)
    {
        gServiceNpcActor[index] = INVALID_ACTOR_ID;
    }

    for (locationid = 1; locationid < sizeof(gServerLocations); locationid++)
    {
        GetLocationLabelText(locationid, text, sizeof(text));
        gLocationTextLabel[locationid] = Create3DTextLabel(
            text,
            GetLocationLabelColor(locationid),
            gServerLocations[locationid][locX],
            gServerLocations[locationid][locY],
            gServerLocations[locationid][locZ] + 0.85,
            LOCATION_LABEL_DRAW_DISTANCE,
            gServerLocations[locationid][locVirtualWorld],
            1
        );
    }

    CreateAutoInteriorLabels();
    CreateInteriorSpotLabels();
    CreateServiceNpcActors();
    CreatePrfPostWarning();
    return 1;
}

stock DestroyWorldInteractionLabels()
{
    new locationid;

    for (locationid = 1; locationid < sizeof(gServerLocations); locationid++)
    {
        if (gLocationTextLabel[locationid] != Text3D:INVALID_3DTEXT_ID)
        {
            Delete3DTextLabel(gLocationTextLabel[locationid]);
            gLocationTextLabel[locationid] = Text3D:INVALID_3DTEXT_ID;
        }
    }

    DestroyAutoInteriorLabels();
    DestroyInteriorSpotLabels();
    DestroyServiceNpcActors();
    DestroyPrfPostWarning();
    return 1;
}

stock ResetPlayerWorldData(playerid)
{
    gPlayerGpsLocation[playerid] = -1;
    gPlayerGpsDialogCount[playerid] = 0;
    gPlayerAutoInterior[playerid] = -1;
    gPlayerInteriorMoveTick[playerid] = 0;
    gPlayerInteriorSpotTick[playerid] = 0;
    gPlayerInPoliceCell[playerid] = 0;
    return 1;
}

stock SetupPlayerMapIcons(playerid)
{
    UpdatePlayerMapIcons(playerid);
    return 1;
}

stock UpdatePlayerMapIcons(playerid)
{
    new locationid;
    new visible;

    for (locationid = 1; locationid < sizeof(gServerLocations); locationid++)
    {
        if (gServerLocations[locationid][locInterior] != 0 || gServerLocations[locationid][locMapIcon] == 0)
        {
            continue;
        }

        visible = IsPlayerInRangeOfPoint(playerid, MAP_ICON_VISIBLE_RANGE, gServerLocations[locationid][locX], gServerLocations[locationid][locY], gServerLocations[locationid][locZ]);
        if (visible && !gPlayerLocationIconVisible[playerid][locationid])
        {
            if (!ManagedMapIcon_Set(
                playerid,
                MAP_ICON_NS_WORLD,
                locationid,
                gServerLocations[locationid][locX],
                gServerLocations[locationid][locY],
                gServerLocations[locationid][locZ],
                gServerLocations[locationid][locMapIcon],
                gServerLocations[locationid][locMapColor],
                MAPICON_GLOBAL
            ))
            {
                continue;
            }
            gPlayerLocationIconVisible[playerid][locationid] = 1;
        }
        else if (!visible && gPlayerLocationIconVisible[playerid][locationid])
        {
            ManagedMapIcon_Remove(playerid, MAP_ICON_NS_WORLD, locationid);
            gPlayerLocationIconVisible[playerid][locationid] = 0;
        }
    }
    return 1;
}

stock ClearPlayerMapIcons(playerid)
{
    new locationid;

    for (locationid = 1; locationid < sizeof(gServerLocations); locationid++)
    {
        gPlayerLocationIconVisible[playerid][locationid] = 0;
    }
    ManagedMapIcon_ClearNamespace(playerid, MAP_ICON_NS_WORLD);
    return 1;
}

stock ShowGpsDialog(playerid)
{
    new list[2048];
    new line[64];
    new locationid;
    new count;

    list[0] = 0;
    gPlayerGpsDialogCount[playerid] = 0;

    for (locationid = 1; locationid < sizeof(gServerLocations); locationid++)
    {
        if (locationid == LOCATION_INTERIOR_PREF)
        {
            continue;
        }

        if (count >= MAX_GPS_DIALOG_LOCATIONS)
        {
            break;
        }

        gPlayerGpsDialogLocations[playerid][count] = locationid;
        count++;

        format(line, sizeof(line), "%s\n", gServerLocations[locationid][locName]);
        strcat(list, line, sizeof(list));
    }

    gPlayerGpsDialogCount[playerid] = count;
    ShowPlayerDialog(playerid, DIALOG_GPS, DIALOG_STYLE_LIST, "GPS - Locais importantes", list, "Marcar", "Fechar");
    return 1;
}

stock GetGpsLocationFromListItem(playerid, listitem)
{
    if (listitem < 0 || listitem >= gPlayerGpsDialogCount[playerid])
    {
        return -1;
    }

    return gPlayerGpsDialogLocations[playerid][listitem];
}

stock FindCurrentAutoInterior(playerid)
{
    new index;

    for (index = 0; index < sizeof(gAutoInteriors); index++)
    {
        if (IsPlayerInsideAutoInterior(playerid, index))
        {
            return index;
        }
    }
    return -1;
}

stock World_IsPlayerAtServiceInterior(playerid, locationid)
{
    new interiorIndex = FindAutoInteriorByLocation(locationid);

    if (interiorIndex == -1)
    {
        return 0;
    }

    return IsPlayerInsideAutoInterior(playerid, interiorIndex);
}

stock World_IsPlayerAtRestaurant(playerid)
{
    new index = FindCurrentAutoInterior(playerid);
    new locationid;

    if (index == -1)
    {
        return 0;
    }

    locationid = gAutoInteriors[index][autoLocation];
    return World_IsRestaurantLocation(locationid);
}

stock World_IsPlayerAtNpcStore(playerid)
{
    new index = FindCurrentAutoInterior(playerid);
    new locationid;

    if (index == -1)
    {
        return 0;
    }

    locationid = gAutoInteriors[index][autoLocation];
    return World_IsStoreLocation(locationid);
}

stock World_IsPlayerAtWeaponShop(playerid)
{
    new index = FindCurrentAutoInterior(playerid);
    new locationid;

    if (index == -1)
    {
        return 0;
    }

    locationid = gAutoInteriors[index][autoLocation];
    return World_IsWeaponShopLocation(locationid);
}

stock World_IsPlayerNearLocation(playerid, locationid, Float:radius)
{
    if (locationid < 0 || locationid >= sizeof(gServerLocations))
    {
        return 0;
    }

    if (GetPlayerInterior(playerid) != gServerLocations[locationid][locInterior])
    {
        return 0;
    }

    if (GetPlayerVirtualWorld(playerid) != gServerLocations[locationid][locVirtualWorld])
    {
        return 0;
    }

    return IsPlayerInRangeOfPoint(playerid, radius, gServerLocations[locationid][locX], gServerLocations[locationid][locY], gServerLocations[locationid][locZ]);
}

stock World_IsPlayerAtBankBranch(playerid)
{
    return World_IsPlayerNearLocation(playerid, LOCATION_BANCO, LOCATION_INTERACT_BUSINESS);
}

stock World_IsPlayerAtAtm(playerid)
{
    return (
        World_IsPlayerNearLocation(playerid, LOCATION_ATM_PREFEITURA, LOCATION_INTERACT_BUSINESS) ||
        World_IsPlayerNearLocation(playerid, LOCATION_ATM_HOSPITAL, LOCATION_INTERACT_BUSINESS) ||
        World_IsPlayerNearLocation(playerid, LOCATION_ATM_IDLEWOOD, LOCATION_INTERACT_BUSINESS) ||
        World_IsPlayerNearLocation(playerid, LOCATION_ATM_CONCESSIONARIA, LOCATION_INTERACT_BUSINESS)
    );
}

stock World_IsPlayerAtBankService(playerid)
{
    return (World_IsPlayerAtBankBranch(playerid) || World_IsPlayerAtAtm(playerid));
}

stock World_IsPlayerAtGasStation(playerid)
{
    return (
        World_IsPlayerNearLocation(playerid, LOCATION_POSTO_IDLEWOOD, LOCATION_INTERACT_GAS) ||
        World_IsPlayerNearLocation(playerid, LOCATION_POSTO_MARKET, LOCATION_INTERACT_GAS) ||
        World_IsPlayerNearLocation(playerid, LOCATION_POSTO_DILLIMORE, LOCATION_INTERACT_GAS) ||
        World_IsPlayerNearLocation(playerid, LOCATION_POSTO_FLINT, LOCATION_INTERACT_GAS) ||
        World_IsPlayerNearLocation(playerid, LOCATION_POSTO_EL_QUEBRADOS, LOCATION_INTERACT_GAS) ||
        World_IsPlayerNearLocation(playerid, LOCATION_POSTO_TIERRA, LOCATION_INTERACT_GAS)
    );
}

stock World_CanUseNpcTransport(playerid, showError = 1)
{
    if (Work_IsActive(playerid))
    {
        if (showError)
        {
            SendClientMessage(playerid, COLOR_ORANGE, "Transporte NPC bloqueado durante expediente de trabalho.");
        }
        return 0;
    }

    if (IsPlayerInAnyVehicle(playerid))
    {
        if (showError)
        {
            SendClientMessage(playerid, COLOR_GRAY, "Saia do veiculo para usar transporte NPC.");
        }
        return 0;
    }

    if (World_IsPlayerNearLocation(playerid, LOCATION_JOB_TAXISTA, 12.0) || World_IsPlayerNearLocation(playerid, LOCATION_JOB_MOTORISTA, 12.0))
    {
        return 1;
    }

    if (World_IsPlayerAtServiceInterior(playerid, LOCATION_JOB_TAXISTA) || World_IsPlayerAtServiceInterior(playerid, LOCATION_JOB_MOTORISTA))
    {
        return 1;
    }

    if (showError)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Use transporte NPC no ponto de taxi ou no terminal de onibus.");
    }
    return 0;
}

stock ShowNpcTransportDialog(playerid)
{
    new list[1024];
    new line[96];
    new index;
    new locationid;
    new count;

    if (!World_CanUseNpcTransport(playerid))
    {
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

        format(line, sizeof(line), "%s\t$%d\n", gServerLocations[locationid][locName], Cfg_Price(gCfgNpcTransportCost));
        strcat(list, line, sizeof(list));
    }

    gPlayerGpsDialogCount[playerid] = count;
    ShowPlayerDialog(playerid, DIALOG_NPC_TRANSPORT, DIALOG_STYLE_TABLIST_HEADERS, "Transporte NPC", list, "Viajar", "Fechar");
    return 1;
}

stock HandleNpcTransportDialog(playerid, response, listitem)
{
    new locationid;
    new message[128];

    if (!response)
    {
        return 1;
    }

    if (!World_CanUseNpcTransport(playerid))
    {
        return 1;
    }

    locationid = GetGpsLocationFromListItem(playerid, listitem);
    if (locationid == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Destino invalido.");
        return 1;
    }

    if (!Bank_TakePayment(playerid, Cfg_Price(gCfgNpcTransportCost), 0))
    {
        format(message, sizeof(message), "Transporte NPC custa $%d em dinheiro/banco.", Cfg_Price(gCfgNpcTransportCost));
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    SetPlayerToLocation(playerid, locationid);
    SaveAccountData(playerid);
    format(message, sizeof(message), "Motorista NPC levou voce para: %s. Custo: $%d.", gServerLocations[locationid][locName], Cfg_Price(gCfgNpcTransportCost));
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock FindNearestInteriorSpot(playerid)
{
    new spotid;
    new interiorIndex = FindCurrentAutoInterior(playerid);
    new locationid;

    if (interiorIndex == -1)
    {
        return -1;
    }

    locationid = gAutoInteriors[interiorIndex][autoLocation];
    for (spotid = 0; spotid < sizeof(gInteriorSpots); spotid++)
    {
        if (gInteriorSpots[spotid][spotLocation] != locationid)
        {
            continue;
        }

        if (World_SpotNearControls(spotid, interiorIndex))
        {
            continue;
        }

        if (IsPlayerInRangeOfPoint(playerid, INTERIOR_SPOT_ACTION_RADIUS, gInteriorSpots[spotid][spotX], gInteriorSpots[spotid][spotY], gInteriorSpots[spotid][spotZ]))
        {
            return spotid;
        }
    }
    return -1;
}

stock GetInteriorSpotAction(spotid)
{
    new text[72];

    if (spotid < 0 || spotid >= sizeof(gInteriorSpots))
    {
        return SPOT_ACTION_INFO;
    }

    format(text, sizeof(text), "%s", gInteriorSpots[spotid][spotText]);

    if (strfind(text, "Guiche", true) != -1 || strfind(text, "Setor", true) != -1)
    {
        return SPOT_ACTION_CITYHALL;
    }

    if (strfind(text, "Triagem", true) != -1 || strfind(text, "Leitos", true) != -1 || strfind(text, "Farmacia", true) != -1 || strfind(text, "Macas", true) != -1 || strfind(text, "ambulancias", true) != -1)
    {
        return SPOT_ACTION_HOSPITAL;
    }

    if (strfind(text, "Celas", true) != -1 || strfind(text, "custodia", true) != -1)
    {
        return SPOT_ACTION_POLICE_CELL;
    }

    if (strfind(text, "ocorrencias", true) != -1 || strfind(text, "Arsenal", true) != -1 || strfind(text, "monitoramento", true) != -1)
    {
        return SPOT_ACTION_POLICE_REPORT;
    }

    if (strfind(text, "venda", true) != -1 || strfind(text, "Showroom", true) != -1)
    {
        return SPOT_ACTION_DEALERSHIP;
    }

    if (strfind(text, "oficina", true) != -1 || strfind(text, "reparo", true) != -1)
    {
        return SPOT_ACTION_MECHANIC;
    }

    if (strfind(text, "Caixa", true) != -1 || strfind(text, "Estoque", true) != -1 || strfind(text, "Prateleira", true) != -1 || strfind(text, "Geladeira", true) != -1)
    {
        return SPOT_ACTION_STORE;
    }

    if (strfind(text, "Cozinha", true) != -1 || strfind(text, "Preparo", true) != -1 || strfind(text, "Passa-pratos", true) != -1)
    {
        return SPOT_ACTION_KITCHEN;
    }

    if (strfind(text, "Mesas", true) != -1 || strfind(text, "salao", true) != -1)
    {
        return SPOT_ACTION_TABLE_SERVICE;
    }

    return SPOT_ACTION_JOB_SERVICE;
}

stock InteriorSpot_CanReward(playerid)
{
    new tick = GetTickCount();

    if (gPlayerInteriorSpotTick[playerid] > 0 && (tick - gPlayerInteriorSpotTick[playerid]) < INTERIOR_SPOT_COOLDOWN_MS)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Aguarde alguns segundos antes de usar outro ponto de servico.");
        return 0;
    }

    gPlayerInteriorSpotTick[playerid] = tick;
    return 1;
}

stock HandleInteriorSpotAction(playerid, showError = 1)
{
    new spotid = FindNearestInteriorSpot(playerid);
    new action;

    if (spotid == -1)
    {
        if (showError)
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta perto de nenhum ponto interno.");
        }
        return 0;
    }

    action = GetInteriorSpotAction(spotid);
    return HandleInteriorSpotServiceAction(playerid, action, spotid);
}

stock World_UpdatePlayerInteriors(playerid)
{
    new index;
    new locationid;
    new currentInterior;
    new tick;

    if (IsPlayerInAnyVehicle(playerid))
    {
        return 0;
    }

    tick = GetTickCount();
    if (gPlayerInteriorMoveTick[playerid] > 0 && (tick - gPlayerInteriorMoveTick[playerid]) < AUTO_INTERIOR_COOLDOWN_MS)
    {
        return 0;
    }

    currentInterior = FindCurrentAutoInterior(playerid);
    if (currentInterior != -1)
    {
        gPlayerAutoInterior[playerid] = currentInterior;
        if (IsPlayerInRangeOfPoint(playerid, GetAutoInteriorExitRadius(currentInterior), gAutoInteriors[currentInterior][autoExitX], gAutoInteriors[currentInterior][autoExitY], gAutoInteriors[currentInterior][autoExitZ]))
        {
            World_ExitAutoInterior(playerid);
            return 1;
        }
        return 0;
    }

    for (index = 0; index < sizeof(gAutoInteriors); index++)
    {
        locationid = gAutoInteriors[index][autoLocation];
        if (GetPlayerInterior(playerid) != gServerLocations[locationid][locInterior])
        {
            continue;
        }

        if (GetPlayerVirtualWorld(playerid) != gServerLocations[locationid][locVirtualWorld])
        {
            continue;
        }

        if (IsPlayerInRangeOfPoint(playerid, AUTO_INTERIOR_ENTER_RADIUS, gServerLocations[locationid][locX], gServerLocations[locationid][locY], gServerLocations[locationid][locZ]))
        {
            SetPlayerToAutoInterior(playerid, index);
            return 1;
        }
    }
    return 0;
}

stock FindNearestAutoInteriorAction(playerid)
{
    new index;

    for (index = 0; index < sizeof(gAutoInteriors); index++)
    {
        if (!IsPlayerInsideAutoInterior(playerid, index))
        {
            continue;
        }

        if (IsPlayerInRangeOfPoint(playerid, AUTO_INTERIOR_ACTION_RADIUS, gAutoInteriors[index][autoActionX], gAutoInteriors[index][autoActionY], gAutoInteriors[index][autoActionZ]))
        {
            return index;
        }
    }
    return -1;
}

stock HandleAutoInteriorAction(playerid, showError = 1)
{
    new interiorIndex = FindNearestAutoInteriorAction(playerid);
    new locationid;

    if (interiorIndex == -1)
    {
        if (showError)
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta perto de nenhum balcao de atendimento.");
        }
        return 0;
    }

    locationid = gAutoInteriors[interiorIndex][autoLocation];
    switch (gAutoInteriors[interiorIndex][autoActionType])
    {
        case AUTO_ACTION_CONVENIENCE:
        {
            ShowConvenienceStoreDialog(playerid);
        }
        case AUTO_ACTION_JOB:
        {
            if (World_IsRestaurantLocation(locationid))
            {
                ShowRestaurantDialog(playerid);
            }
            else if (World_IsWeaponShopLocation(locationid))
            {
                ShowWeaponShopDialog(playerid);
            }
            else if (World_IsStoreLocation(locationid))
            {
                ShowConvenienceStoreDialog(playerid);
            }
            else
            {
                ShowJobLocationDialog(playerid, locationid);
            }
        }
        default:
        {
            switch (locationid)
            {
                case LOCATION_PREFEITURA:
                {
                    ShowCityHallDialog(playerid);
                }
                case LOCATION_HOSPITAL:
                {
                    Hospital_TreatPlayer(playerid);
                }
                case LOCATION_DELEGACIA:
                {
                    SendClientMessage(playerid, COLOR_BLUE, "Escrivao NPC: ocorrencias e consulta de ficha ficam na recepcao interna.");
                    SendClientMessage(playerid, COLOR_GRAY, "Use /ficha para consultar sua ficha ou procure um policial para atendimento avancado.");
                }
                case LOCATION_CONCESSIONARIA:
                {
                    ShowDealershipDialog(playerid);
                }
                default:
                {
                    SendClientMessage(playerid, COLOR_GRAY, "Este balcao ainda nao tem atendimento configurado.");
                }
            }
        }
    }
    return 1;
}

stock SetPlayerGps(playerid, locationid)
{
    new message[96];

    if (Work_IsActive(playerid))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "GPS bloqueado durante expediente de trabalho.");
        return 0;
    }

    if (locationid <= LOCATION_SPAWN || locationid >= sizeof(gServerLocations))
    {
        return 0;
    }

    gPlayerGpsLocation[playerid] = locationid;
    SetPlayerCheckpoint(playerid, gServerLocations[locationid][locX], gServerLocations[locationid][locY], gServerLocations[locationid][locZ], GPS_CHECKPOINT_SIZE);

    format(message, sizeof(message), "GPS marcado para: %s.", gServerLocations[locationid][locName]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock HandleGpsDialog(playerid, response, listitem)
{
    new locationid;

    if (!response)
    {
        return 1;
    }

    locationid = GetGpsLocationFromListItem(playerid, listitem);
    if (locationid == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Local invalido.");
        return 1;
    }

    SetPlayerGps(playerid, locationid);
    return 1;
}

stock FindNearestInteractiveLocation(playerid)
{
    new locationid;
    new Float:radius;

    for (locationid = 1; locationid < sizeof(gServerLocations); locationid++)
    {
        if (GetPlayerInterior(playerid) != gServerLocations[locationid][locInterior])
        {
            continue;
        }

        if (GetPlayerVirtualWorld(playerid) != gServerLocations[locationid][locVirtualWorld])
        {
            continue;
        }

        radius = GetLocationInteractRadius(locationid);
        if (IsPlayerInRangeOfPoint(playerid, radius, gServerLocations[locationid][locX], gServerLocations[locationid][locY], gServerLocations[locationid][locZ]))
        {
            return locationid;
        }
    }

    return -1;
}

stock HandleLocationInteraction(playerid, showError = 1)
{
    new locationid = FindNearestInteractiveLocation(playerid);

    if (HandleAutoInteriorExit(playerid, 0))
    {
        return 1;
    }

    if (locationid == -1)
    {
        if (HandleInteriorSpotAction(playerid, 0))
        {
            return 1;
        }

        if (HandleAutoInteriorAction(playerid, 0))
        {
            return 1;
        }

        if (showError)
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta perto de nenhum local interativo.");
        }
        return 0;
    }

    switch (locationid)
    {
        case LOCATION_PREFEITURA:
        {
            World_TryEnterAutoInterior(playerid, locationid);
        }
        case LOCATION_INTERIOR_PREF:
        {
            ShowCityHallDialog(playerid);
        }
        case LOCATION_HOSPITAL:
        {
            World_TryEnterAutoInterior(playerid, locationid);
        }
        case LOCATION_DELEGACIA:
        {
            World_TryEnterAutoInterior(playerid, locationid);
        }
        case LOCATION_CONCESSIONARIA:
        {
            World_TryEnterAutoInterior(playerid, locationid);
        }
        case LOCATION_DETRAN:
        {
            Dealership_ShowDetranDialog(playerid);
        }
        case LOCATION_GARAGEM_PUBLICA:
        {
            Dealership_ShowGarageDialog(playerid);
        }
        case LOCATION_PATIO_MUNICIPAL:
        {
            Dealership_RecoverImpound(playerid);
        }
        case LOCATION_BANCO:
        {
            ShowBankDialog(playerid, BANK_ACCESS_BRANCH);
        }
        case LOCATION_ATM_PREFEITURA, LOCATION_ATM_HOSPITAL, LOCATION_ATM_IDLEWOOD, LOCATION_ATM_CONCESSIONARIA:
        {
            ShowBankDialog(playerid, BANK_ACCESS_ATM);
        }
        case LOCATION_POSTO_IDLEWOOD, LOCATION_POSTO_MARKET, LOCATION_POSTO_DILLIMORE, LOCATION_POSTO_FLINT, LOCATION_POSTO_EL_QUEBRADOS, LOCATION_POSTO_TIERRA:
        {
            NpcFuelRefuel(playerid);
        }
        case LOCATION_JOB_LIXEIRO:
        {
            World_TryEnterAutoInterior(playerid, locationid);
        }
        case LOCATION_JOB_ENTREGADOR:
        {
            World_TryEnterAutoInterior(playerid, locationid);
        }
        case LOCATION_JOB_MOTORISTA:
        {
            World_TryEnterAutoInterior(playerid, locationid);
        }
        case LOCATION_CONVENIENCIA_1, LOCATION_CONVENIENCIA_2:
        {
            World_TryEnterAutoInterior(playerid, locationid);
        }
        default:
        {
            if (!World_TryEnterAutoInterior(playerid, locationid) && !ShowJobLocationDialog(playerid, locationid))
            {
                SendClientMessage(playerid, COLOR_GRAY, "Este local ainda nao tem interacao configurada.");
            }
        }
    }

    return 1;
}

stock World_OnPlayerEnterCheckpoint(playerid)
{
    new locationid = gPlayerGpsLocation[playerid];

    if (locationid != -1)
    {
        DisablePlayerCheckpoint(playerid);
        gPlayerGpsLocation[playerid] = -1;
        SendClientMessage(playerid, COLOR_GREEN, "Voce chegou ao destino do GPS. Aproxime-se da porta ou do texto 3D para atendimento.");
    }
    return 1;
}

stock World_OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if ((newkeys & KEY_SECONDARY_ATTACK) && !(oldkeys & KEY_SECONDARY_ATTACK))
    {
        HandleLocationInteraction(playerid, 0);
    }
    return 1;
}

stock GetPlayerLocationName(playerid, location[], size = sizeof(location))
{
    new Float:x;
    new Float:y;
    new Float:z;
    new interior;
    new currentAuto;

    currentAuto = FindCurrentAutoInterior(playerid);
    if (currentAuto != -1)
    {
        format(location, size, "%s", gAutoInteriors[currentAuto][autoName]);
        return 1;
    }

    interior = GetPlayerInterior(playerid);
    if (interior != 0)
    {
        format(location, size, "Interior %d", interior);
        return 1;
    }

    GetPlayerPos(playerid, x, y, z);

    if (x >= 1670.0 && x <= 1830.0 && y >= -1970.0 && y <= -1800.0)
    {
        format(location, size, "Los Santos - Unity Station");
    }
    else if (x >= 1600.0 && x <= 1900.0 && y >= -1800.0 && y <= -1550.0)
    {
        format(location, size, "Los Santos - Commerce");
    }
    else if (x >= 1900.0 && x <= 2350.0 && y >= -1950.0 && y <= -1600.0)
    {
        format(location, size, "Los Santos - Idlewood");
    }
    else if (x >= 44.0 && x <= 2997.0 && y >= -2892.0 && y <= -768.0)
    {
        format(location, size, "Los Santos");
    }
    else if (x >= -2997.0 && x <= -1213.0 && y >= -1115.0 && y <= 1659.0)
    {
        format(location, size, "San Fierro");
    }
    else if (x >= 869.0 && x <= 2997.0 && y >= 596.0 && y <= 2993.0)
    {
        format(location, size, "Las Venturas");
    }
    else if (x >= -480.0 && x <= 869.0 && y >= 596.0 && y <= 2993.0)
    {
        format(location, size, "Bone County");
    }
    else if (x >= -2997.0 && x <= -480.0 && y >= 1659.0 && y <= 2993.0)
    {
        format(location, size, "Tierra Robada");
    }
    else if (x >= -1213.0 && x <= 2997.0 && y >= -768.0 && y <= 596.0)
    {
        format(location, size, "Red County");
    }
    else if (x >= -1213.0 && x <= 44.0 && y >= -2892.0 && y <= -768.0)
    {
        format(location, size, "Flint County");
    }
    else if (x >= -2997.0 && x <= -1213.0 && y >= -2892.0 && y <= -1115.0)
    {
        format(location, size, "Whetstone");
    }
    else
    {
        format(location, size, "San Andreas");
    }

    return 1;
}
