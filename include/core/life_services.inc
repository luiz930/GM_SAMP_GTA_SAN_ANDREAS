#if defined _nova_life_services_included
    #endinput
#endif
#define _nova_life_services_included

#define LIFE_MARKET_ITEMS           (6)
#define LIFE_MISSION_WORK_TARGET    (3)
#define LIFE_MISSION_REWARD_CASH    (900)
#define LIFE_MISSION_REWARD_XP      (2)
#define LIFE_DAILY_REWARD_CASH      (350)
#define LIFE_WEEKLY_REWARD_CASH     (2500)
#define LIFE_CITY_PASS_JOB_TARGET   (8)
#define LIFE_CITY_PASS_ECO_TARGET   (4)
#define LIFE_CITY_PASS_PUBLIC_TARGET (3)
#define LIFE_CITY_PASS_REWARD_CASH  (3500)
#define LIFE_DAILY_PROFILE_NEWCOMER (1)
#define LIFE_DAILY_PROFILE_WORKER   (2)
#define LIFE_DAILY_PROFILE_BUSINESS (3)
#define LIFE_DAILY_PROFILE_POLICE   (4)
#define LIFE_DAILY_PROFILE_PUBLIC   (5)
#define LIFE_DAILY_PROFILE_CRIME    (6)
#define LIFE_URBAN_AREA_WORK        (1)
#define LIFE_URBAN_AREA_ECONOMY     (2)
#define LIFE_URBAN_AREA_SECURITY    (3)
#define LIFE_URBAN_AREA_CIVIC       (4)
#define LIFE_URBAN_AREA_COMMUNITY   (5)
#define LIFE_WEEKLY_AGENDA_WORK_TARGET     (12)
#define LIFE_WEEKLY_AGENDA_BUSINESS_TARGET (10)
#define LIFE_WEEKLY_AGENDA_POLICE_TARGET   (10)
#define LIFE_WEEKLY_AGENDA_CITIZEN_TARGET  (8)
#define ACH_GOOD_PAYER              (1)
#define ACH_WORKER                  (2)
#define ACH_BUSINESS_OWNER          (4)
#define ACH_CLEAN_RECORD            (8)
#define ACH_LEGAL_DRIVER            (16)
#define ACH_LOYAL_CITIZEN           (32)
#define ACH_CITY_PASS               (64)
#define ACH_PUBLIC_SERVICE          (128)
#define JUSTICE_STATUS_NONE         (0)
#define JUSTICE_STATUS_OPEN         (1)
#define JUSTICE_STATUS_INVESTIGATING (2)
#define JUSTICE_STATUS_HEARING      (3)
#define JUSTICE_STATUS_RESOLVED     (4)
#define CITY_EVENT_NONE             (0)
#define CITY_EVENT_STOCK            (1)
#define CITY_EVENT_BLITZ            (2)
#define CITY_EVENT_HOSPITAL         (3)
#define CITY_EVENT_POLICE           (4)
#define CITY_EVENT_JOB_BONUS        (5)
#define CITY_EVENT_WAR_ZONE         (6)
#define CITY_EVENT_DURATION_MS      (1800000)
#define CITY_EVENT_TIMER_MS         (300000)
#define CITY_EVENT_MAX_ORDERS       (12)
#define LIFE_ANTI_ABUSE_MONEY_DAY   (25000)
#define LIFE_ANTI_ABUSE_XP_DAY      (40)
#define LIFE_CONTRACTS_DAILY_LIMIT  (5)
#define LIFE_CONTRACT_OFFER_EXPIRE_MS (180000)
#define LIFE_BUSINESS_MAX_STOCK     (80)
#define LIFE_LOGISTICS_OFFER_EXPIRE_MS (180000)
#define LIFE_LOGISTICS_NONE         (0)
#define LIFE_LOGISTICS_MARKET       (1)
#define LIFE_LOGISTICS_FUEL         (2)
#define LIFE_LOGISTICS_WORKSHOP     (3)
#define LIFE_LOGISTICS_BUILD        (4)
#define LIFE_LOGISTICS_STAGE_NONE   (0)
#define LIFE_LOGISTICS_STAGE_ACCEPTED (1)
#define LIFE_LOGISTICS_STAGE_LOADED (2)
#define LIFE_LOGISTICS_STAGE_UNLOAD (3)
#define LIFE_LOGISTICS_DOCKS        (4)
#define LIFE_LOGISTICS_DOCK_RANGE   (7.0)
#define LIFE_LOGISTICS_LATE_MS      (900000)
#define LIFE_AUTO_BUSINESS_COUNT    (6)
#define LIFE_AUTO_BUSINESS_TIMER_MS (600000)
#define LIFE_CITY_PASS_COOLDOWN_MS  (12000)
#define LIFE_MISSION_COOLDOWN_MS    (7000)
#define WAR_ZONE_TIMER_MS           (60000)
#define WAR_ZONE_START_A            (15)
#define WAR_ZONE_START_B            (22)
#define WAR_ZONE_DURATION_MIN       (30)
#define WAR_ZONE_REWARD_CASH        (250)
#define WAR_ZONE_MAX_REWARD_KILLS   (12)
#define WAR_ZONE_MIN_X              (900.0)
#define WAR_ZONE_MIN_Y              (-1050.0)
#define WAR_ZONE_MAX_X              (1510.0)
#define WAR_ZONE_MAX_Y              (-470.0)
#define LIFE_BIZ_MAX_ACTIONS        (32)
#define LIFE_CONTRACT_MAX_ACTIONS   (9)
#define LIFE_AUCTION_MAX_ACTIONS    (3)
#define LIFE_PUBLIC_MAX_ACTIONS     (12)
#define LIFE_BILL_MAX_ACTIONS       (16)
#define LIFE_AUCTION_STATUS         (1)
#define LIFE_AUCTION_RECOVER        (2)
#define LIFE_AUCTION_GPS            (3)
#define LIFE_PUBLIC_STATUS          (1)
#define LIFE_PUBLIC_JUSTICE         (2)
#define LIFE_PUBLIC_DETRAN          (3)
#define LIFE_PUBLIC_HEALTH          (4)
#define LIFE_PUBLIC_TAXES           (5)
#define LIFE_PUBLIC_BUDGET          (6)
#define LIFE_PUBLIC_BID             (7)
#define LIFE_PUBLIC_ROUTE           (8)
#define LIFE_PUBLIC_MISSION         (9)
#define LIFE_PUBLIC_CONSTITUTION    (10)
#define LIFE_PUBLIC_WORKS           (11)
#define LIFE_PUBLIC_CALL_CENTER     (12)
#define LIFE_PUBLIC_WORK_COUNT      (8)
#define LIFE_PUBLIC_WORK_HYDRO      (6)
#define LIFE_PUBLIC_WORK_SOLAR      (7)
#define LIFE_PUBLIC_WORK_PENDING    (0)
#define LIFE_PUBLIC_WORK_DONE       (1)
#define LIFE_POLITICAL_OFFICES      (18)
#define LIFE_POLITICAL_CANDIDATES   (5)
#define LIFE_POLITICAL_TERM_DAYS    (15)
#define LIFE_POLITICAL_ELECTION_MS  (3600000)
#define LIFE_POLITICAL_BOT_DECISION_MS (1800000)
#define LIFE_POLITICAL_PROPOSALS    (12)
#define LIFE_POLITICAL_VOTE_NEED    (2)
#define LIFE_POLITICAL_MAX_SPEND_PERCENT (15)
#define LIFE_POL_PROP_NONE          (0)
#define LIFE_POL_PROP_WORK          (1)
#define LIFE_POL_PROP_BUDGET        (2)
#define LIFE_POL_PROP_AUDIT         (3)
#define LIFE_POL_PROP_ACCOUNT       (4)
#define LIFE_POL_PROP_CPI           (5)
#define LIFE_POL_ACTION_WORK        (1)
#define LIFE_POL_ACTION_BUDGET      (2)
#define LIFE_POL_ACTION_AUDIT       (3)
#define LIFE_POL_ACTION_ACCOUNT     (4)
#define LIFE_POL_ACTION_CPI         (5)
#define LIFE_POL_ACTION_VOTE        (6)
#define LIFE_POL_ACTION_CANCEL      (7)
#define LIFE_POL_ACTION_TRANSPARENCY (8)
#define LIFE_POL_PROP_OPEN          (0)
#define LIFE_POL_PROP_APPROVED      (1)
#define LIFE_POL_PROP_CANCELED      (2)
#define LIFE_BUDGET_PRIORITY_INFRA  (0)
#define LIFE_BUDGET_PRIORITY_HEALTH (1)
#define LIFE_BUDGET_PRIORITY_SECURITY (2)
#define LIFE_BUDGET_PRIORITY_SOCIAL (3)
#define LIFE_PUBLIC_MISSION_NONE    (0)
#define LIFE_PUBLIC_MISSION_FIRE    (1)
#define LIFE_PUBLIC_MISSION_HOMICIDE (2)
#define LIFE_PUBLIC_MISSION_FEDERAL (3)
#define LIFE_PUBLIC_MISSION_PRF     (4)
#define LIFE_PUBLIC_MISSION_JUDGE   (5)
#define LIFE_PUBLIC_MISSION_PENAL   (6)
#define LIFE_PUBLIC_MISSION_PATROL  (7)
#define LIFE_PUBLIC_MISSION_HEALTH  (8)
#define LIFE_PUBLIC_MISSION_OBJECTS (8)
#define LIFE_PUBLIC_MISSION_REWARD  (850)
#define LIFE_PUBLIC_MISSION_XP      (2)
#define LIFE_PUBLIC_MISSION_CP_SIZE (4.5)
#define LIFE_PUBLIC_MISSION_COOLDOWN_MS (90000)
#define LIFE_PUBLIC_INVALID_ENTITY  (0xFFFF)
#define LIFE_FIRE_SCENE_HOUSE       (1)
#define LIFE_FIRE_SCENE_VEHICLE     (2)
#define LIFE_FIRE_SCENE_BUSINESS    (3)
#define LIFE_CALL_CENTER_TIMER_MS   (30000)
#define LIFE_CALL_CENTER_EXPIRE_MS  (180000)
#define LIFE_CALL_CENTER_ACTIVE_MS  (600000)
#define LIFE_CALL_CENTER_MAX        (16)
#define LIFE_CALL_NONE              (0)
#define LIFE_CALL_POLICE            (1)
#define LIFE_CALL_SAMU              (2)
#define LIFE_CALL_FIRE              (3)
#define LIFE_CALL_TOW               (4)
#define LIFE_CALL_STATUS_NONE       (0)
#define LIFE_CALL_STATUS_PENDING    (1)
#define LIFE_CALL_STATUS_ACCEPTED   (2)
#define SALARY_PRODUCTIVITY_PERCENT (50)
#define LIFE_DOC_WARN_DAYS          (14)
#define LIFE_ONBOARDING_TARGET      (4)
#define LIFE_STEP_DONE              (0)
#define LIFE_STEP_DOCUMENTS         (1)
#define LIFE_STEP_BANK              (2)
#define LIFE_STEP_JOB               (3)
#define LIFE_STEP_WORK              (4)
#define LIFE_STEP_VEHICLE           (5)
#define LIFE_STEP_DETRAN            (6)
#define LIFE_STEP_HOME              (7)
#define LIFE_STEP_GOVBR             (8)
#define LIFE_STEP_CITIZEN           (9)
#define LIFE_STEP_REWARD            (10)
#define LIFE_STEP_DOC_RENEW         (11)
#define LIFE_STEP_DEBT              (12)
#define LIFE_STEP_BUSINESS          (13)
#define GOV_REV_TAXES              (0)
#define GOV_REV_FINES              (1)
#define GOV_REV_TOLLS              (2)
#define GOV_REV_LICENSES           (3)
#define GOV_REV_VEHICLES           (4)
#define GOV_REV_BUSINESS           (5)
#define GOV_REV_CONTRACTS          (6)
#define GOV_REV_JUSTICE            (7)
#define GOV_REV_SERVICES           (8)
#define GOV_REV_OTHER              (9)
#define GOV_REV_CATEGORIES         (10)
#define GOV_EXP_INFRA              (0)
#define GOV_EXP_HEALTH             (1)
#define GOV_EXP_SECURITY           (2)
#define GOV_EXP_SOCIAL             (3)
#define GOV_EXP_ADMIN              (4)
#define GOV_EXP_RESERVE            (5)
#define GOV_EXP_CATEGORIES         (6)

new gMarketStock[LIFE_MARKET_ITEMS];
new gGovernmentRevenue;
new gGovernmentRevenueByCategory[GOV_REV_CATEGORIES];
new gGovernmentExpense;
new gGovernmentExpenseByCategory[GOV_EXP_CATEGORIES];
new gGovernmentLastRevenueAmount;
new gGovernmentLastRevenueReason[32];
new gGovernmentLastExpenseAmount;
new gGovernmentLastExpenseReason[32];
new gGovernmentLastDecisionOffice[28];
new gGovernmentLastDecisionText[96];
new gGovernmentLastDecisionImpact[96];
new gGovernmentLastDecisionDay;
new gPublicWorkStatus[LIFE_PUBLIC_WORK_COUNT];
new Text3D:gPublicWorkLabel[LIFE_PUBLIC_WORK_COUNT];
new gPublicWorkObject[LIFE_PUBLIC_WORK_COUNT];
new gCityBudgetPriority = GOV_EXP_INFRA;
new gPoliticalTermStartDay;
new gPoliticalTermEndDay;
new gPoliticalElectionActive;
new gPoliticalElectionEndTick;
new gPoliticalHolderName[LIFE_POLITICAL_OFFICES][MAX_PLAYER_NAME + 1];
new gPoliticalHolderBot[LIFE_POLITICAL_OFFICES];
new gPoliticalCandidateName[LIFE_POLITICAL_OFFICES][LIFE_POLITICAL_CANDIDATES][MAX_PLAYER_NAME + 1];
new gPoliticalCandidateBot[LIFE_POLITICAL_OFFICES][LIFE_POLITICAL_CANDIDATES];
new gPoliticalCandidateVotes[LIFE_POLITICAL_OFFICES][LIFE_POLITICAL_CANDIDATES];
new gPoliticalCandidateCount[LIFE_POLITICAL_OFFICES];
new gPoliticalVoted[MAX_PLAYERS][LIFE_POLITICAL_OFFICES];
new gPoliticalProposalType[LIFE_POLITICAL_PROPOSALS];
new gPoliticalProposalStatus[LIFE_POLITICAL_PROPOSALS];
new gPoliticalProposalAmount[LIFE_POLITICAL_PROPOSALS];
new gPoliticalProposalCategory[LIFE_POLITICAL_PROPOSALS];
new gPoliticalProposalWorkId[LIFE_POLITICAL_PROPOSALS];
new gPoliticalProposalVotes[LIFE_POLITICAL_PROPOSALS];
new gPoliticalProposalDay[LIFE_POLITICAL_PROPOSALS];
new gPoliticalProposalCreator[LIFE_POLITICAL_PROPOSALS][MAX_PLAYER_NAME + 1];
new gPoliticalProposalTitle[LIFE_POLITICAL_PROPOSALS][64];
new gPoliticalProposalVoters[LIFE_POLITICAL_PROPOSALS][180];
new gPoliticalLastProposalDay[MAX_PLAYERS];
new gPoliticalVoteOffice[MAX_PLAYERS];
new gPoliticalDialogAction[MAX_PLAYERS];
new gCityEventType;
new gCityEventExpireTick;
new gCityEventTargetJob;
new gCityEventTargetItem;
new gCityEventIntensity;
new gCityEventTimer;
new gWarZoneTimer;
new gAutoBusinessTimer;
new gPoliticalBotTimer;
new gServiceCallTimer;
new gWarZoneId = -1;
new gWarZoneWasActive;
new gBusinessOfferFrom[MAX_PLAYERS];
new gBusinessOfferAmount[MAX_PLAYERS];
new gBusinessOfferType[MAX_PLAYERS];
new gBusinessOfferTick[MAX_PLAYERS];
new gLogisticsOfferFrom[MAX_PLAYERS];
new gLogisticsOfferAmount[MAX_PLAYERS];
new gLogisticsOfferType[MAX_PLAYERS];
new gLogisticsOfferTick[MAX_PLAYERS];
new gLogisticsOwner[MAX_PLAYERS];
new gLogisticsAmount[MAX_PLAYERS];
new gLogisticsType[MAX_PLAYERS];
new gLogisticsStockGain[MAX_PLAYERS];
new gLogisticsStage[MAX_PLAYERS];
new gLogisticsStartTick[MAX_PLAYERS];
new gLifeLastMissionTick[MAX_PLAYERS];
new gLifeLastCityPassTick[MAX_PLAYERS];
new gLifeMoneyGainDay[MAX_PLAYERS];
new gLifeMoneyGainToday[MAX_PLAYERS];
new gLifeXpGainDay[MAX_PLAYERS];
new gLifeXpGainToday[MAX_PLAYERS];
new gWarZoneVisible[MAX_PLAYERS];
new gLifeOnboardingHintShown[MAX_PLAYERS];
new gLifeBizActions[MAX_PLAYERS][LIFE_BIZ_MAX_ACTIONS];
new gLifeBizActionCount[MAX_PLAYERS];
new gLifeContractActions[MAX_PLAYERS][LIFE_CONTRACT_MAX_ACTIONS];
new gLifeContractActionCount[MAX_PLAYERS];
new gLifeAuctionActions[MAX_PLAYERS][LIFE_AUCTION_MAX_ACTIONS];
new gLifeAuctionActionCount[MAX_PLAYERS];
new gLifePublicActions[MAX_PLAYERS][LIFE_PUBLIC_MAX_ACTIONS];
new gLifePublicActionCount[MAX_PLAYERS];
new gLifeBillActions[MAX_PLAYERS][LIFE_BILL_MAX_ACTIONS];
new gLifeBillActionCount[MAX_PLAYERS];
new gPublicMissionType[MAX_PLAYERS];
new gPublicMissionLastTick[MAX_PLAYERS];
new gPublicMissionActor[MAX_PLAYERS];
new gPublicMissionVehicle[MAX_PLAYERS];
new gPublicMissionObject[MAX_PLAYERS][LIFE_PUBLIC_MISSION_OBJECTS];
new Float:gPublicMissionX[MAX_PLAYERS];
new Float:gPublicMissionY[MAX_PLAYERS];
new Float:gPublicMissionZ[MAX_PLAYERS];
new gPublicMissionDetail[MAX_PLAYERS][48];
new gPlayerAcceptedCall[MAX_PLAYERS];

new gServiceCallStatus[LIFE_CALL_CENTER_MAX];
new gServiceCallType[LIFE_CALL_CENTER_MAX];
new gServiceCallCaller[LIFE_CALL_CENTER_MAX];
new gServiceCallResponder[LIFE_CALL_CENTER_MAX];
new gServiceCallTick[LIFE_CALL_CENTER_MAX];
new Float:gServiceCallX[LIFE_CALL_CENTER_MAX];
new Float:gServiceCallY[LIFE_CALL_CENTER_MAX];
new Float:gServiceCallZ[LIFE_CALL_CENTER_MAX];
new gServiceCallDesc[LIFE_CALL_CENTER_MAX][64];

enum eLogisticsDock
{
    logisticsDockType,
    logisticsDockName[36],
    Float:logisticsLoadX,
    Float:logisticsLoadY,
    Float:logisticsLoadZ,
    Float:logisticsUnloadX,
    Float:logisticsUnloadY,
    Float:logisticsUnloadZ,
    logisticsObjectModel
}

enum eAutoBusiness
{
    autoBizName[36],
    autoBizType,
    autoBizMarketItem,
    autoBizPrice,
    autoBizBaseProfit,
    autoBizStockGain
}

enum ePublicWorkData
{
    publicWorkName[40],
    publicWorkCategory,
    publicWorkCost,
    Float:publicWorkX,
    Float:publicWorkY,
    Float:publicWorkZ,
    publicWorkModel,
    publicWorkBenefit[88]
}

enum ePublicFireScene
{
    fireSceneName[48],
    fireSceneKind,
    fireSceneVehicleModel,
    Float:fireSceneX,
    Float:fireSceneY,
    Float:fireSceneZ,
    Float:fireSceneA
}

enum ePoliticalOfficeData
{
    politicalOfficeName[28],
    politicalOfficeArea
}

forward Life_UpdateCityEvent();
forward Life_UpdateWarZone();
forward Life_UpdatePoliticalBots();
forward Life_UpdateServiceCalls();

new gMarketKeys[LIFE_MARKET_ITEMS][24] =
{
    "food",
    "drinks",
    "medicine",
    "parts",
    "fuel",
    "materials"
};

new gMarketNames[LIFE_MARKET_ITEMS][32] =
{
    "Alimentos",
    "Bebidas",
    "Medicamentos",
    "Pecas mecanicas",
    "Combustivel",
    "Materiais"
};

new gMarketDefaults[LIFE_MARKET_ITEMS] =
{
    120,
    120,
    60,
    45,
    80,
    70
};

new gLogisticsDocks[LIFE_LOGISTICS_DOCKS][eLogisticsDock] =
{
    { LIFE_LOGISTICS_MARKET, "Docas do mercado", 2451.8810, -2092.6350, 13.5469, 1368.2140, -1279.8530, 13.5469, 964 },
    { LIFE_LOGISTICS_FUEL, "Base de combustivel", 2755.9210, -2454.1780, 13.6430, 1942.2160, -1772.9300, 13.5469, 1225 },
    { LIFE_LOGISTICS_WORKSHOP, "Centro de autopecas", 2522.8390, -1524.3250, 24.0000, 1025.6500, -1029.2000, 32.1000, 1271 },
    { LIFE_LOGISTICS_BUILD, "Patio de materiais", 2451.8810, -2092.6350, 13.5469, 1744.1000, -1861.9000, 13.5750, 12930 }
};

new gPublicFireScenes[][ePublicFireScene] =
{
    { "carro pegando fogo em Idlewood", LIFE_FIRE_SCENE_VEHICLE, 401, 2065.4200, -1778.7600, 13.5469, 88.0 },
    { "carro pegando fogo perto da Unity Station", LIFE_FIRE_SCENE_VEHICLE, 404, 1799.2800, -1858.3600, 13.5781, 270.0 },
    { "van em chamas no distrito industrial", LIFE_FIRE_SCENE_VEHICLE, 482, 2454.1200, -2100.5300, 13.5469, 180.0 },
    { "casa pegando fogo em Ganton", LIFE_FIRE_SCENE_HOUSE, 0, 2407.0500, -1234.2000, 23.8203, 270.0 },
    { "apartamento com fogo em Commerce", LIFE_FIRE_SCENE_HOUSE, 0, 1515.7600, -1456.5000, 14.2031, 180.0 },
    { "residencia em chamas perto da praia", LIFE_FIRE_SCENE_HOUSE, 0, 369.4500, -2046.2000, 7.8359, 270.0 },
    { "oficina com principio de incendio", LIFE_FIRE_SCENE_BUSINESS, 0, 1042.3000, -1028.3000, 32.1016, 180.0 },
    { "posto de combustivel com foco de fogo", LIFE_FIRE_SCENE_BUSINESS, 0, 1939.2500, -1772.6500, 13.5469, 90.0 },
    { "deposito com material inflamavel", LIFE_FIRE_SCENE_BUSINESS, 0, 2522.8000, -1524.3200, 24.0000, 90.0 },
    { "lixeira e fachada em chamas no centro", LIFE_FIRE_SCENE_BUSINESS, 0, 1482.2000, -1772.2000, 18.7958, 0.0 }
};

new Text3D:gLogisticsLoadLabel[LIFE_LOGISTICS_DOCKS];
new Text3D:gLogisticsUnloadLabel[LIFE_LOGISTICS_DOCKS];
new gLogisticsLoadObject[LIFE_LOGISTICS_DOCKS];
new gLogisticsUnloadObject[LIFE_LOGISTICS_DOCKS];

new gPublicWorks[LIFE_PUBLIC_WORK_COUNT][ePublicWorkData] =
{
    { "Reforma Rua Commerce", GOV_EXP_INFRA, 4500, 1744.1000, -1861.9000, 13.5750, 1237, "Infra: +5% em obras, fretes de obra e resposta urbana" },
    { "Iluminacao Idlewood", GOV_EXP_INFRA, 3200, 1940.8500, -1768.6000, 13.5469, 1231, "Infra: ruas sinalizadas e menor risco operacional" },
    { "Ala Hospital Jefferson", GOV_EXP_HEALTH, 6000, 1191.5048, -1324.8131, 13.3984, 1997, "Saude: +5% nas ocorrencias medicas publicas" },
    { "Base Delegacia LS", GOV_EXP_SECURITY, 5500, 1537.6119, -1676.4634, 13.5469, 1257, "Seguranca: +5% em ocorrencias policiais e PRF" },
    { "Manutencao Pedagio LS", GOV_EXP_INFRA, 3500, 1008.8067, -943.0485, 42.1797, 968, "Infra: rodovia melhor para pedagios e fiscalizacao" },
    { "Praca dos Novatos", GOV_EXP_SOCIAL, 2800, 2228.7000, -1159.9000, 25.7331, 1368, "Social: cidade mais acolhedora para recem chegados" },
    { "Usina Hidreletrica Flint", GOV_EXP_INFRA, 9000, -78.4000, -1156.2000, 2.1000, 1237, "Energia: -15% na luz residencial da cidade" },
    { "Programa Solar Residencial", GOV_EXP_INFRA, 7000, 2478.6000, -1667.4000, 13.3438, 1231, "Energia: instalacao solar fica mais barata e visivel no /energia" }
};

new gPoliticalOffices[LIFE_POLITICAL_OFFICES][ePoliticalOfficeData] =
{
    { "Presidente", GOV_EXP_ADMIN },
    { "Vice-presidente", GOV_EXP_ADMIN },
    { "Governador", GOV_EXP_INFRA },
    { "Vice-governador", GOV_EXP_INFRA },
    { "Prefeito", GOV_EXP_SOCIAL },
    { "Vice-prefeito", GOV_EXP_SOCIAL },
    { "Vereador", GOV_EXP_SOCIAL },
    { "Senador", GOV_EXP_SECURITY },
    { "Deputado 1", GOV_EXP_ADMIN },
    { "Deputado 2", GOV_EXP_ADMIN },
    { "Deputado 3", GOV_EXP_ADMIN },
    { "Deputado 4", GOV_EXP_ADMIN },
    { "Deputado 5", GOV_EXP_ADMIN },
    { "Parlamentar 1", GOV_EXP_ADMIN },
    { "Parlamentar 2", GOV_EXP_ADMIN },
    { "Parlamentar 3", GOV_EXP_ADMIN },
    { "Parlamentar 4", GOV_EXP_ADMIN },
    { "Parlamentar 5", GOV_EXP_ADMIN }
};

new gPoliticalBotNames[LIFE_POLITICAL_OFFICES][MAX_PLAYER_NAME + 1] =
{
    "Bot_Presidente",
    "Bot_VicePresidente",
    "Bot_Governador",
    "Bot_ViceGovernador",
    "Bot_Prefeito",
    "Bot_VicePrefeito",
    "Bot_Vereador",
    "Bot_Senador",
    "Bot_Deputado1",
    "Bot_Deputado2",
    "Bot_Deputado3",
    "Bot_Deputado4",
    "Bot_Deputado5",
    "Bot_Parlamentar1",
    "Bot_Parlamentar2",
    "Bot_Parlamentar3",
    "Bot_Parlamentar4",
    "Bot_Parlamentar5"
};

new gAutoBusinesses[LIFE_AUTO_BUSINESS_COUNT][eAutoBusiness] =
{
    { "Mercado Popular LS", LIFE_BUSINESS_COMMERCE, 0, 65000, 850, 2 },
    { "Posto Idlewood Auto", LIFE_BUSINESS_TRANSPORT, 4, 90000, 1050, 2 },
    { "Oficina Commerce", LIFE_BUSINESS_WORKSHOP, 3, 78000, 950, 2 },
    { "Construtora Marina", LIFE_BUSINESS_TRANSPORT, 5, 110000, 1200, 3 },
    { "Farmacia Jefferson", LIFE_BUSINESS_COMMERCE, 2, 72000, 900, 1 },
    { "Deposito Atacadista", LIFE_BUSINESS_TRANSPORT, 1, 98000, 1000, 3 }
};

forward Life_UpdateAutoBusinesses();

stock Life_GetCityEventName(eventType, output[], size = sizeof(output))
{
    switch (eventType)
    {
        case CITY_EVENT_STOCK: format(output, size, "Falta de estoque");
        case CITY_EVENT_BLITZ: format(output, size, "Blitz especial");
        case CITY_EVENT_HOSPITAL: format(output, size, "Surto hospitalar");
        case CITY_EVENT_POLICE: format(output, size, "Operacao policial");
        case CITY_EVENT_JOB_BONUS: format(output, size, "Bonus de profissao");
        case CITY_EVENT_WAR_ZONE: format(output, size, "Zona de guerra");
        default: format(output, size, "Sem evento");
    }
    return 1;
}

stock Life_FindLowStockItem()
{
    new index;

    for (index = 0; index < LIFE_MARKET_ITEMS; index++)
    {
        if (gMarketStock[index] <= gCfgMarketLowStock)
        {
            return index;
        }
    }
    return -1;
}

stock Life_CityEventActive()
{
    if (gCityEventType == CITY_EVENT_NONE)
    {
        return 0;
    }

    if (gCityEventExpireTick > 0 && GetTickCount() > gCityEventExpireTick)
    {
        gCityEventType = CITY_EVENT_NONE;
        gCityEventTargetJob = JOB_NONE;
        gCityEventTargetItem = -1;
        gCityEventIntensity = 0;
        return 0;
    }
    return 1;
}

stock Life_SetCityEvent(eventType, targetJob = JOB_NONE, targetItem = -1)
{
    new eventName[32];
    new detail[96];

    if (eventType <= CITY_EVENT_NONE || eventType > CITY_EVENT_WAR_ZONE)
    {
        eventType = CITY_EVENT_JOB_BONUS;
    }

    if (eventType == CITY_EVENT_STOCK && targetItem < 0)
    {
        targetItem = Life_FindLowStockItem();
        if (targetItem < 0)
        {
            targetItem = random(LIFE_MARKET_ITEMS);
        }
    }

    if (eventType == CITY_EVENT_JOB_BONUS && (targetJob == JOB_NONE || !Job_IsPrivateBonusEligible(targetJob)))
    {
        do
        {
            targetJob = 1 + random(JOB_MAX_ID);
        }
        while (!Job_IsPrivateBonusEligible(targetJob));
    }

    gCityEventType = eventType;
    gCityEventTargetJob = targetJob;
    gCityEventTargetItem = targetItem;
    gCityEventIntensity = 20 + random(16);
    gCityEventExpireTick = GetTickCount() + CITY_EVENT_DURATION_MS;

    Life_GetCityEventName(eventType, eventName, sizeof(eventName));
    format(detail, sizeof(detail), "evento=%s bonus=%d job=%d item=%d", eventName, gCityEventIntensity, targetJob, targetItem);
    WriteServerLog(LOG_CONTRACT_FILE, "CITY_EVENT", detail);
    Life_CallFromCityEvent(eventType, targetJob);
    return 1;
}

stock Life_SelectCityEvent()
{
    new lowItem = Life_FindLowStockItem();
    new roll;

    if (lowItem != -1)
    {
        return Life_SetCityEvent(CITY_EVENT_STOCK, JOB_NONE, lowItem);
    }

    roll = random(6);
    switch (roll)
    {
        case 0: return Life_SetCityEvent(CITY_EVENT_BLITZ, JOB_POLICIAL);
        case 1: return Life_SetCityEvent(CITY_EVENT_HOSPITAL, JOB_MEDICO);
        case 2: return Life_SetCityEvent(CITY_EVENT_POLICE, JOB_SEGURANCA);
        case 3: return Life_SetCityEvent(CITY_EVENT_WAR_ZONE);
        case 4: return Life_SetCityEvent(CITY_EVENT_JOB_BONUS, JOB_BOMBEIRO);
    }
    return Life_SetCityEvent(CITY_EVENT_JOB_BONUS);
}

public Life_UpdateCityEvent()
{
    if (Life_CityEventActive())
    {
        return 1;
    }
    return Life_SelectCityEvent();
}

stock Life_FormatCityEvent(output[], size = sizeof(output))
{
    new eventName[32];
    new eventJobName[32];
    new remaining;

    if (!Life_CityEventActive())
    {
        format(output, size, "Sem evento ativo");
        return 1;
    }

    Life_GetCityEventName(gCityEventType, eventName, sizeof(eventName));
    remaining = (gCityEventExpireTick - GetTickCount()) / 60000;
    if (remaining < 0)
    {
        remaining = 0;
    }

    if (gCityEventType == CITY_EVENT_STOCK && gCityEventTargetItem >= 0)
    {
        format(output, size, "%s: %s baixo | bonus %d%% | %d min", eventName, gMarketNames[gCityEventTargetItem], gCityEventIntensity, remaining);
        return 1;
    }

    if (gCityEventType == CITY_EVENT_JOB_BONUS && gCityEventTargetJob != JOB_NONE)
    {
        GetJobName(gCityEventTargetJob, eventJobName, sizeof(eventJobName));
        format(output, size, "%s: %s | bonus %d%% | %d min", eventName, eventJobName, gCityEventIntensity, remaining);
        return 1;
    }

    format(output, size, "%s | bonus %d%% | %d min", eventName, gCityEventIntensity, remaining);
    return 1;
}

stock Life_GetLocationDistrict(locationid, output[], size = sizeof(output))
{
    switch (locationid)
    {
        case LOCATION_PREFEITURA, LOCATION_DELEGACIA, LOCATION_BANCO, LOCATION_ATM_PREFEITURA:
        {
            format(output, size, "Centro civico");
        }
        case LOCATION_HOSPITAL, LOCATION_JOB_MEDICO, LOCATION_JOB_AMBULANCIA, LOCATION_ATM_HOSPITAL:
        {
            format(output, size, "Jefferson - saude");
        }
        case LOCATION_CONCESSIONARIA, LOCATION_DETRAN, LOCATION_GARAGEM_PUBLICA, LOCATION_PATIO_MUNICIPAL:
        {
            format(output, size, "Market e DETRAN");
        }
        case LOCATION_JOB_ENTREGADOR, LOCATION_JOB_MOTOBOY, LOCATION_JOB_COZINHEIRO, LOCATION_JOB_GARCOM:
        {
            format(output, size, "Idlewood - entregas");
        }
        case LOCATION_JOB_LIXEIRO, LOCATION_JOB_CAMINHONEIRO, LOCATION_JOB_CARTEIRO, LOCATION_JOB_PEDREIRO:
        {
            format(output, size, "Industrial sul");
        }
        case LOCATION_JOB_FRENTISTA,
             LOCATION_CONVENIENCIA_1,
             LOCATION_CONVENIENCIA_2,
             LOCATION_POSTO_IDLEWOOD,
             LOCATION_POSTO_MARKET,
             LOCATION_POSTO_DILLIMORE,
             LOCATION_POSTO_FLINT,
             LOCATION_POSTO_EL_QUEBRADOS,
             LOCATION_POSTO_TIERRA:
        {
            format(output, size, "Postos e conveniencias");
        }
        case LOCATION_JOB_PESCADOR, LOCATION_JOB_AGRICULTOR, LOCATION_JOB_MINERADOR:
        {
            format(output, size, "Interior e zona rural");
        }
        case LOCATION_JOB_POLICIAL,
             LOCATION_JOB_SEGURANCA,
             LOCATION_JOB_PRF,
             LOCATION_JOB_POLICIA_FEDERAL,
             LOCATION_JOB_POLICIA_CIVIL,
             LOCATION_JOB_POLICIA_PENAL:
        {
            format(output, size, "Centro - seguranca");
        }
        default:
        {
            format(output, size, "Los Santos");
        }
    }
    return 1;
}

stock Life_GetCityEventLocation()
{
    new locationid;

    switch (gCityEventType)
    {
        case CITY_EVENT_STOCK:
        {
            return LOCATION_CONVENIENCIA_1;
        }
        case CITY_EVENT_BLITZ:
        {
            return LOCATION_DELEGACIA;
        }
        case CITY_EVENT_HOSPITAL:
        {
            return LOCATION_HOSPITAL;
        }
        case CITY_EVENT_POLICE:
        {
            return LOCATION_JOB_POLICIAL;
        }
        case CITY_EVENT_JOB_BONUS:
        {
            locationid = Job_GetLocation(gCityEventTargetJob);
            if (locationid > LOCATION_SPAWN)
            {
                return locationid;
            }
            return LOCATION_PREFEITURA;
        }
        case CITY_EVENT_WAR_ZONE:
        {
            return -1;
        }
    }
    return LOCATION_PREFEITURA;
}

stock Life_GetCityEventDistrict(output[], size = sizeof(output))
{
    new locationid = Life_GetCityEventLocation();

    if (gCityEventType == CITY_EVENT_WAR_ZONE)
    {
        format(output, size, "Mulholland");
        return 1;
    }
    Life_GetLocationDistrict(locationid, output, size);
    return 1;
}

stock Life_GetCityEventGoal(output[], size = sizeof(output))
{
    new eventJobName[32];

    switch (gCityEventType)
    {
        case CITY_EVENT_STOCK:
        {
            format(output, size, "Repor mercado com /venderproduto ou visitar conveniencia");
        }
        case CITY_EVENT_BLITZ:
        {
            format(output, size, "Apoiar fiscalizacao com chamados, patrulha ou blitz");
        }
        case CITY_EVENT_HOSPITAL:
        {
            format(output, size, "Atender saude com /192, /193 ou servico medico");
        }
        case CITY_EVENT_POLICE:
        {
            format(output, size, "Responder seguranca com /190, mandados e rondas");
        }
        case CITY_EVENT_JOB_BONUS:
        {
            GetJobName(gCityEventTargetJob, eventJobName, sizeof(eventJobName));
            format(output, size, "Fazer servico de %s enquanto o bonus esta ativo", eventJobName);
        }
        case CITY_EVENT_WAR_ZONE:
        {
            format(output, size, "Consultar /zonaguerra e decidir risco em Mulholland");
        }
        default:
        {
            format(output, size, "Acompanhar GovBR e aguardar novo plantao urbano");
        }
    }
    return 1;
}

stock Life_ShowNeighborhoodEvents(playerid)
{
    new list[1500];
    new line[192];
    new eventText[128];
    new district[48];
    new goal[128];
    new locationName[48];
    new locationid;
    new remaining;

    Life_UpdateCityEvent();
    Life_UpdateWarZone();
    Life_FormatCityEvent(eventText, sizeof(eventText));
    Life_GetCityEventDistrict(district, sizeof(district));
    Life_GetCityEventGoal(goal, sizeof(goal));
    locationid = Life_GetCityEventLocation();
    remaining = (gCityEventExpireTick - GetTickCount()) / 60000;
    if (remaining < 0)
    {
        remaining = 0;
    }

    if (locationid > LOCATION_SPAWN)
    {
        GetLocationName(locationid, locationName, sizeof(locationName));
    }
    else
    {
        format(locationName, sizeof(locationName), "Sem GPS direto");
    }

    format(list, sizeof(list), "Area\tStatus\tAcao\n");
    format(line, sizeof(line), "Regiao ativa\t%s\t%s\n", district, locationName);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Evento urbano\t%s\t/eventos\n", eventText);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Meta leve\t%d min restantes\t%s\n", remaining, goal);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Passe semanal\tprofissao/economia/cidade\t/agendasemanal\n");
    strcat(list, line, sizeof(list));
    if (Life_IsWarZoneActive())
    {
        format(line, sizeof(line), "Zona de guerra\tMulholland ativo\t/zonaguerra\n");
        strcat(list, line, sizeof(list));
    }
    format(line, sizeof(line), "Base tecnica\teventos urbanos atuais\tsem sistema paralelo\n");
    strcat(list, line, sizeof(list));

    ShowPlayerDialog(playerid, DIALOG_NEIGHBORHOOD_EVENTS, DIALOG_STYLE_TABLIST_HEADERS, "GovBR - Eventos por bairro 2.0", list, "Agir", "Fechar");
    return 1;
}

stock Life_ApplyNeighborhoodEvent(playerid)
{
    new locationid;
    new district[48];
    new goal[128];
    new message[180];

    Life_UpdateCityEvent();
    Life_GetCityEventDistrict(district, sizeof(district));
    Life_GetCityEventGoal(goal, sizeof(goal));
    locationid = Life_GetCityEventLocation();

    if (gCityEventType == CITY_EVENT_WAR_ZONE)
    {
        SendClientMessage(playerid, COLOR_YELLOW, "Evento por bairro: Mulholland usa a zona de guerra atual.");
        return Life_ShowCityEvents(playerid);
    }

    if (locationid > LOCATION_SPAWN)
    {
        SetPlayerGps(playerid, locationid);
    }

    format(message, sizeof(message), "Evento por bairro: %s. Meta leve: %s.", district, goal);
    SendClientMessage(playerid, COLOR_YELLOW, message);
    return 1;
}

stock Life_IsWarZoneActive()
{
    new year;
    new month;
    new day;
    new hour;
    new minute;
    new second;

    GetBrasiliaDateTime(year, month, day, hour, minute, second);
    if ((hour == WAR_ZONE_START_A || hour == WAR_ZONE_START_B) && minute < WAR_ZONE_DURATION_MIN)
    {
        return 1;
    }
    return 0;
}

stock Life_GetWarZoneRemainingMinutes()
{
    new year;
    new month;
    new day;
    new hour;
    new minute;
    new second;

    GetBrasiliaDateTime(year, month, day, hour, minute, second);
    if ((hour == WAR_ZONE_START_A || hour == WAR_ZONE_START_B) && minute < WAR_ZONE_DURATION_MIN)
    {
        return WAR_ZONE_DURATION_MIN - minute;
    }
    return 0;
}

stock Life_FormatWarZoneStatus(output[], size = sizeof(output))
{
    new remaining = Life_GetWarZoneRemainingMinutes();

    if (remaining > 0)
    {
        format(output, size, "Mulholland ativo por %d min | kills liberadas dentro da zona", remaining);
        return 1;
    }

    format(output, size, "Mulholland inativo | proximas janelas %02d:00 e %02d:00 BRT", WAR_ZONE_START_A, WAR_ZONE_START_B);
    return 1;
}

stock Life_IsPointInWarZone(Float:x, Float:y)
{
    return (x >= WAR_ZONE_MIN_X && x <= WAR_ZONE_MAX_X && y >= WAR_ZONE_MIN_Y && y <= WAR_ZONE_MAX_Y);
}

stock Life_IsPlayerInWarZone(playerid)
{
    new Float:x;
    new Float:y;
    new Float:z;

    if (!IsValidConnectedPlayer(playerid))
    {
        return 0;
    }

    if (GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
    {
        return 0;
    }

    GetPlayerPos(playerid, x, y, z);
    #pragma unused z
    return Life_IsPointInWarZone(x, y);
}

stock Life_UpdateWarZoneForPlayer(playerid)
{
    new active = Life_IsWarZoneActive();

    if (gWarZoneId == -1 || !IsPlayerConnected(playerid))
    {
        return 0;
    }

    if (active && !gWarZoneVisible[playerid])
    {
        GangZoneShowForPlayer(playerid, gWarZoneId, 0xAA000066);
        gWarZoneVisible[playerid] = 1;
        SendClientMessage(playerid, COLOR_ORANGE, "Zona de guerra ativa em Mulholland por 30 minutos. Dentro da area vermelha, kills nao prendem.");
        return 1;
    }

    if (!active && gWarZoneVisible[playerid])
    {
        GangZoneHideForPlayer(playerid, gWarZoneId);
        gWarZoneVisible[playerid] = 0;
        SendClientMessage(playerid, COLOR_RED, "Zona de guerra encerrada. Kill em Mulholland agora gera prisao normal.");
        return 1;
    }
    return 0;
}

public Life_UpdateWarZone()
{
    new playerid;
    new maxPlayers = GetMaxPlayers();
    new active = Life_IsWarZoneActive();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid))
        {
            Life_UpdateWarZoneForPlayer(playerid);
        }
    }

    if (active != gWarZoneWasActive)
    {
        if (active)
        {
            SendClientMessageToAll(COLOR_ORANGE, "Zona de guerra ativa em Mulholland por 30 minutos. Area vermelha no mapa.");
            WriteServerLog(LOG_PUNISH_FILE, "WAR_ZONE_START", "bairro=Mulholland duracao=30min");
        }
        else
        {
            SendClientMessageToAll(COLOR_RED, "Zona de guerra encerrada em Mulholland. Kills no local voltam a prender.");
            WriteServerLog(LOG_PUNISH_FILE, "WAR_ZONE_END", "bairro=Mulholland");
        }
        gWarZoneWasActive = active;
    }
    return 1;
}

stock Life_AlertStaff(message[])
{
    new playerid;
    new maxPlayers = GetMaxPlayers();
    new line[180];

    format(line, sizeof(line), "[Anti-abuso] %s", message);
    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && PlayerInfo[playerid][pLogged] && HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
        {
            SendClientMessage(playerid, COLOR_ADMIN, line);
        }
    }
    WriteServerLog(LOG_ADMIN_FILE, "ANTI_ABUSE", message);
    return 1;
}

stock Life_TrackGain(playerid, cash, xp, source[])
{
    new today = GetBrasiliaDayStamp();
    new message[160];

    if (gLifeMoneyGainDay[playerid] != today)
    {
        gLifeMoneyGainDay[playerid] = today;
        gLifeMoneyGainToday[playerid] = 0;
    }
    if (gLifeXpGainDay[playerid] != today)
    {
        gLifeXpGainDay[playerid] = today;
        gLifeXpGainToday[playerid] = 0;
    }

    if (cash > 0) gLifeMoneyGainToday[playerid] += cash;
    if (xp > 0) gLifeXpGainToday[playerid] += xp;

    if (gLifeMoneyGainToday[playerid] >= LIFE_ANTI_ABUSE_MONEY_DAY || gLifeXpGainToday[playerid] >= LIFE_ANTI_ABUSE_XP_DAY)
    {
        format(message, sizeof(message), "player=%d cash_dia=%d xp_dia=%d origem=%s", playerid, gLifeMoneyGainToday[playerid], gLifeXpGainToday[playerid], source);
        Life_AlertStaff(message);
        gLifeMoneyGainToday[playerid] = 0;
        gLifeXpGainToday[playerid] = 0;
    }
    return 1;
}

stock Life_ResetDailyLimits(playerid)
{
    new today = GetBrasiliaDayStamp();

    if (PlayerInfo[playerid][pContractLimitDay] != today)
    {
        PlayerInfo[playerid][pContractLimitDay] = today;
        PlayerInfo[playerid][pContractsToday] = 0;
    }
    if (PlayerInfo[playerid][pWarZoneDay] != today)
    {
        PlayerInfo[playerid][pWarZoneDay] = today;
        PlayerInfo[playerid][pWarZoneKillsToday] = 0;
    }
    return 1;
}

stock Life_GetHourJobBonus(jobid)
{
    new year;
    new month;
    new day;
    new hour;
    new minute;
    new second;

    if (!Job_IsPrivateBonusEligible(jobid))
    {
        return 0;
    }

    GetBrasiliaDateTime(year, month, day, hour, minute, second);

    if (hour >= 6 && hour < 9)
    {
        if (jobid == JOB_TAXISTA || jobid == JOB_MOTORISTA_ONIBUS || jobid == JOB_CARTEIRO)
        {
            return 15;
        }
    }
    if (hour >= 11 && hour < 14)
    {
        if (jobid == JOB_COZINHEIRO || jobid == JOB_GARCOM || jobid == JOB_MOTOBOY || jobid == JOB_VENDEDOR)
        {
            return 15;
        }
    }
    if (hour >= 17 && hour < 20)
    {
        if (jobid == JOB_TAXISTA)
        {
            return 15;
        }
    }
    if (hour >= 20 || hour < 2)
    {
        if (jobid == JOB_SEGURANCA)
        {
            return 15;
        }
    }
    return 0;
}

stock Life_GetEventJobBonus(jobid)
{
    new item;

    if (!Job_IsPrivateBonusEligible(jobid))
    {
        return 0;
    }

    if (!Life_CityEventActive())
    {
        return 0;
    }

    switch (gCityEventType)
    {
        case CITY_EVENT_STOCK:
        {
            item = Life_GetMarketItemByJob(jobid);
            if (item == gCityEventTargetItem)
            {
                return gCityEventIntensity;
            }
        }
        case CITY_EVENT_BLITZ:
        {
            if (Job_IsPrivateBonusEligible(jobid) && jobid == JOB_SEGURANCA)
            {
                return gCityEventIntensity;
            }
        }
        case CITY_EVENT_HOSPITAL:
        {
            return 0;
        }
        case CITY_EVENT_POLICE:
        {
            if (Job_IsPrivateBonusEligible(jobid) && jobid == JOB_SEGURANCA)
            {
                return gCityEventIntensity;
            }
        }
        case CITY_EVENT_JOB_BONUS:
        {
            if (jobid == gCityEventTargetJob)
            {
                return gCityEventIntensity;
            }
        }
    }
    return 0;
}

stock Life_GetJobPayBonusPercent(playerid, jobid)
{
    new level = Job_GetPlayerLevel(playerid, jobid);
    new percent;

    if (!Job_IsPrivateBonusEligible(jobid))
    {
        return 0;
    }

    percent += Life_GetHourJobBonus(jobid);
    percent += Life_GetEventJobBonus(jobid);

    if (level >= 3)
    {
        percent += 5;
    }
    if (level >= 7)
    {
        percent += 5;
    }
    return percent;
}

stock Life_AddBusinessDemand(type, amount, reason[])
{
    new playerid;
    new maxPlayers = GetMaxPlayers();
    new message[128];
    new added;

    if (amount <= 0)
    {
        return 0;
    }

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (!IsPlayerConnected(playerid) || !PlayerInfo[playerid][pLogged])
        {
            continue;
        }

        if (PlayerInfo[playerid][pBusinessType] != type)
        {
            continue;
        }

        PlayerInfo[playerid][pBusinessOrders] += amount;
        PlayerInfo[playerid][pBusinessStock] += amount;
        if (PlayerInfo[playerid][pBusinessOrders] > CITY_EVENT_MAX_ORDERS)
        {
            PlayerInfo[playerid][pBusinessOrders] = CITY_EVENT_MAX_ORDERS;
        }
        if (PlayerInfo[playerid][pBusinessStock] > LIFE_BUSINESS_MAX_STOCK)
        {
            PlayerInfo[playerid][pBusinessStock] = LIFE_BUSINESS_MAX_STOCK;
        }
        Life_AddWeeklyScore(playerid, WEEKLY_SCORE_BUSINESS, amount);
        SaveAccountData(playerid, 0);
        format(message, sizeof(message), "Cadeia produtiva gerou %d pedido(s) para sua empresa: %s.", amount, reason);
        SendClientMessage(playerid, COLOR_GREEN, message);
        added++;
    }
    return added;
}

stock Life_ApplyProductionChain(playerid, jobid)
{
    new item;
    new businessType = Life_GetBusinessTypeForJob(jobid);

    switch (jobid)
    {
        case JOB_ENTREGADOR, JOB_CAIXA_REPOSITOR, JOB_VENDEDOR, JOB_BANCARIO:
        {
            item = Life_GetMarketItemByJob(jobid);
            if (item >= 0 && gMarketStock[item] < (gMarketDefaults[item] * 3))
            {
                gMarketStock[item]++;
                Life_SaveMarketStock();
            }
            Life_AddBusinessDemand(LIFE_BUSINESS_COMMERCE, 1, "abastecimento do mercado");
        }
        case JOB_GARCOM, JOB_COZINHEIRO, JOB_BARTENDER, JOB_PADEIRO_PIZZAIOLO, JOB_MOTOBOY:
        {
            Life_AddBusinessDemand(LIFE_BUSINESS_RESTAURANT, 1, "pedido de restaurante/bar");
        }
        case JOB_MECANICO, JOB_TECNICO, JOB_FRENTISTA, JOB_GUINCHEIRO, JOB_ENCANADOR:
        {
            item = Life_GetMarketItemByJob(jobid);
            if (item >= 0 && gMarketStock[item] < (gMarketDefaults[item] * 3))
            {
                gMarketStock[item]++;
                Life_SaveMarketStock();
            }
            Life_AddBusinessDemand(LIFE_BUSINESS_WORKSHOP, 1, "manutencao de frota");
        }
        case JOB_RECEPCIONISTA_HOTEL, JOB_ZELADOR, JOB_JARDINEIRO:
        {
            Life_AddBusinessDemand(LIFE_BUSINESS_HOTEL, 1, "reserva e manutencao de hotel");
        }
        case JOB_OPERADOR_FABRICA, JOB_MINERADOR, JOB_PEDREIRO, JOB_AGRICULTOR:
        {
            Life_AddBusinessDemand(LIFE_BUSINESS_FACTORY, 1, "lote industrial");
        }
        case JOB_TAXISTA, JOB_MOTORISTA_ONIBUS, JOB_CARTEIRO, JOB_MOTORISTA_APP, JOB_CAMINHONEIRO:
        {
            Life_AddBusinessDemand(LIFE_BUSINESS_TRANSPORT, 1, "demanda de transporte");
        }
        case JOB_CORRETOR_IMOVEIS:
        {
            Life_AddBusinessDemand(LIFE_BUSINESS_REAL_ESTATE, 1, "visita e contrato imobiliario");
        }
        case JOB_CONTADOR:
        {
            Life_AddBusinessDemand(LIFE_BUSINESS_ACCOUNTING, 1, "folha e imposto empresarial");
        }
    }
    if (businessType != LIFE_BUSINESS_NONE && PlayerInfo[playerid][pBusinessType] == businessType)
    {
        PlayerInfo[playerid][pBusinessOrders]++;
        PlayerInfo[playerid][pBusinessStock]++;
        if (PlayerInfo[playerid][pBusinessOrders] > CITY_EVENT_MAX_ORDERS) PlayerInfo[playerid][pBusinessOrders] = CITY_EVENT_MAX_ORDERS;
        if (PlayerInfo[playerid][pBusinessStock] > LIFE_BUSINESS_MAX_STOCK) PlayerInfo[playerid][pBusinessStock] = LIFE_BUSINESS_MAX_STOCK;
        Life_AddWeeklyScore(playerid, WEEKLY_SCORE_BUSINESS, 1);
        SaveAccountData(playerid, 0);
    }
    #pragma unused playerid
    return 1;
}

stock Life_HasOpenJusticeRisk(playerid)
{
    return (PlayerInfo[playerid][pJusticeCases] > 0
        && (PlayerInfo[playerid][pJusticeStatus] == JUSTICE_STATUS_OPEN
        || PlayerInfo[playerid][pJusticeStatus] == JUSTICE_STATUS_INVESTIGATING
        || PlayerInfo[playerid][pJusticeStatus] == JUSTICE_STATUS_HEARING));
}

stock Life_GetWeekStamp()
{
    return GetBrasiliaDayStamp() / 7;
}

stock Life_ResetWeeklyLoop(playerid)
{
    new week = Life_GetWeekStamp();

    if (PlayerInfo[playerid][pCityPassWeek] == week)
    {
        return 0;
    }

    PlayerInfo[playerid][pCityPassWeek] = week;
    PlayerInfo[playerid][pCityPassJob] = 0;
    PlayerInfo[playerid][pCityPassEconomy] = 0;
    PlayerInfo[playerid][pCityPassPublic] = 0;
    PlayerInfo[playerid][pCityPassRewarded] = 0;
    PlayerInfo[playerid][pWeeklyWorkScore] = 0;
    PlayerInfo[playerid][pWeeklyBusinessScore] = 0;
    PlayerInfo[playerid][pWeeklyPoliceScore] = 0;
    PlayerInfo[playerid][pWeeklyCitizenScore] = 0;
    return 1;
}

stock Life_TryCityPassReward(playerid)
{
    new reward;
    new message[144];

    Life_ResetWeeklyLoop(playerid);
    if (PlayerInfo[playerid][pCityPassRewarded])
    {
        return 0;
    }

    if (PlayerInfo[playerid][pCityPassJob] < LIFE_CITY_PASS_JOB_TARGET
        || PlayerInfo[playerid][pCityPassEconomy] < LIFE_CITY_PASS_ECO_TARGET
        || PlayerInfo[playerid][pCityPassPublic] < LIFE_CITY_PASS_PUBLIC_TARGET)
    {
        return 0;
    }

    reward = Vip_ApplyCashBonus(playerid, LIFE_CITY_PASS_REWARD_CASH);
    PlayerInfo[playerid][pCityPassRewarded] = 1;
    PlayerInfo[playerid][pBankGoodHistory] += 2;
    GivePlayerCashReason(playerid, reward, 0, "daily_mission_reward");
    GivePlayerExperience(playerid, 3, 0);
    Life_TrackGain(playerid, reward, 3, "city_pass");
    Life_GiveAchievement(playerid, ACH_CITY_PASS, "Passe da cidade");
    Life_GetBankScore(playerid);
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Passe da cidade concluido. Recompensa semanal: $%d, XP e reputacao.", reward);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_MONEY_FILE, "CITY_PASS", playerid, message);
    return 1;
}

stock Life_AddCityPassProgress(playerid, kind, amount)
{
    new tick;

    if (!PlayerInfo[playerid][pLogged])
    {
        return 0;
    }
    if (amount <= 0)
    {
        amount = 1;
    }

    Life_ResetWeeklyLoop(playerid);
    tick = GetTickCount();
    if (gLifeLastCityPassTick[playerid] > 0 && tick - gLifeLastCityPassTick[playerid] < LIFE_CITY_PASS_COOLDOWN_MS)
    {
        WritePlayerLog(LOG_ADMIN_FILE, "PASS_COOLDOWN", playerid, "progresso bloqueado por cooldown anti-farm");
        return 0;
    }
    gLifeLastCityPassTick[playerid] = tick;
    switch (kind)
    {
        case CITY_PASS_KIND_JOB:
        {
            PlayerInfo[playerid][pCityPassJob] += amount;
            if (PlayerInfo[playerid][pCityPassJob] > LIFE_CITY_PASS_JOB_TARGET) PlayerInfo[playerid][pCityPassJob] = LIFE_CITY_PASS_JOB_TARGET;
        }
        case CITY_PASS_KIND_ECONOMY:
        {
            PlayerInfo[playerid][pCityPassEconomy] += amount;
            if (PlayerInfo[playerid][pCityPassEconomy] > LIFE_CITY_PASS_ECO_TARGET) PlayerInfo[playerid][pCityPassEconomy] = LIFE_CITY_PASS_ECO_TARGET;
        }
        case CITY_PASS_KIND_PUBLIC:
        {
            PlayerInfo[playerid][pCityPassPublic] += amount;
            if (PlayerInfo[playerid][pCityPassPublic] > LIFE_CITY_PASS_PUBLIC_TARGET) PlayerInfo[playerid][pCityPassPublic] = LIFE_CITY_PASS_PUBLIC_TARGET;
        }
    }
    Life_TryCityPassReward(playerid);
    return 1;
}

stock Life_AddWeeklyScore(playerid, kind, amount)
{
    if (!PlayerInfo[playerid][pLogged])
    {
        return 0;
    }
    if (amount <= 0)
    {
        amount = 1;
    }

    Life_ResetWeeklyLoop(playerid);
    switch (kind)
    {
        case WEEKLY_SCORE_WORK: PlayerInfo[playerid][pWeeklyWorkScore] += amount;
        case WEEKLY_SCORE_BUSINESS: PlayerInfo[playerid][pWeeklyBusinessScore] += amount;
        case WEEKLY_SCORE_POLICE: PlayerInfo[playerid][pWeeklyPoliceScore] += amount;
        case WEEKLY_SCORE_CITIZEN: PlayerInfo[playerid][pWeeklyCitizenScore] += amount;
    }
    return 1;
}

stock Life_GetWeeklyAgendaKind(playerid)
{
    if (IsLawEnforcementJob(PlayerInfo[playerid][pJob]) || PlayerInfo[playerid][pJob] == JOB_SEGURANCA)
    {
        return WEEKLY_SCORE_POLICE;
    }
    if (PlayerInfo[playerid][pBusinessType] != LIFE_BUSINESS_NONE)
    {
        return WEEKLY_SCORE_BUSINESS;
    }
    if (Job_IsPublicServant(PlayerInfo[playerid][pJob]))
    {
        return WEEKLY_SCORE_CITIZEN;
    }
    return WEEKLY_SCORE_WORK;
}

stock Life_GetWeeklyAgendaTarget(kind)
{
    switch (kind)
    {
        case WEEKLY_SCORE_BUSINESS: return LIFE_WEEKLY_AGENDA_BUSINESS_TARGET;
        case WEEKLY_SCORE_POLICE: return LIFE_WEEKLY_AGENDA_POLICE_TARGET;
        case WEEKLY_SCORE_CITIZEN: return LIFE_WEEKLY_AGENDA_CITIZEN_TARGET;
    }
    return LIFE_WEEKLY_AGENDA_WORK_TARGET;
}

stock Life_GetWeeklyAgendaName(kind, output[], size = sizeof(output))
{
    switch (kind)
    {
        case WEEKLY_SCORE_BUSINESS: format(output, size, "Empresas");
        case WEEKLY_SCORE_POLICE: format(output, size, "Policia");
        case WEEKLY_SCORE_CITIZEN: format(output, size, "Cidadaos");
        default: format(output, size, "Trabalhadores");
    }
    return 1;
}

stock Life_GetWeeklyJobFocus(jobid, output[], size = sizeof(output))
{
    switch (jobid)
    {
        case JOB_ENTREGADOR, JOB_MOTOBOY, JOB_CARTEIRO, JOB_CAMINHONEIRO, JOB_GUINCHEIRO, JOB_OPERADOR_FABRICA:
        {
            format(output, size, "Logistica: rotas, entregas, fretes e avaliacao.");
        }
        case JOB_TAXISTA, JOB_MOTORISTA_ONIBUS, JOB_MOTORISTA_APP:
        {
            format(output, size, "Mobilidade: corridas limpas e sequencia semanal.");
        }
        case JOB_MECANICO, JOB_FRENTISTA, JOB_TECNICO, JOB_ENCANADOR, JOB_JARDINEIRO, JOB_ZELADOR:
        {
            format(output, size, "Servicos: reparos, abastecimento e manutencao.");
        }
        case JOB_POLICIAL, JOB_PRF, JOB_POLICIA_FEDERAL, JOB_POLICIA_CIVIL, JOB_POLICIA_PENAL, JOB_SEGURANCA, JOB_PERITO_CRIMINAL:
        {
            format(output, size, "Seguranca: chamados, abordagens, BOs e operacoes.");
        }
        case JOB_MEDICO, JOB_MOTORISTA_AMBULANCIA, JOB_FARMACEUTICO:
        {
            format(output, size, "Saude: atendimentos, plantao e ocorrencias 192.");
        }
        case JOB_BOMBEIRO:
        {
            format(output, size, "Bombeiro: ocorrencias, resgates e cidade viva.");
        }
        case JOB_JUIZ, JOB_ADVOGADO, JOB_PROMOTOR, JOB_DEFENSOR_PUBLICO, JOB_OFICIAL_JUSTICA, JOB_ESCRIVAO:
        {
            format(output, size, "Justica: casos, audiencias e regularizacao.");
        }
        case JOB_BANCARIO, JOB_CORRETOR_IMOVEIS, JOB_CONTADOR, JOB_CAIXA_REPOSITOR, JOB_BARTENDER, JOB_PADEIRO_PIZZAIOLO, JOB_RECEPCIONISTA_HOTEL:
        {
            format(output, size, "Economia: banco, contratos, imoveis, empresas e impostos.");
        }
        case JOB_AGENTE_DETRAN, JOB_FUNCIONARIO_PREFEITURA, JOB_PROFESSOR, JOB_ASSISTENTE_SOCIAL:
        {
            format(output, size, "Servico publico: atendimento, fiscalizacao e cidadania.");
        }
        case JOB_JORNALISTA:
        {
            format(output, size, "Comunicacao: noticias, eventos e vida urbana.");
        }
        case JOB_NONE:
        {
            format(output, size, "Escolha uma profissao na Prefeitura.");
        }
        default:
        {
            format(output, size, "Servicos semanais, progresso e passe da cidade.");
        }
    }
    return 1;
}

stock Life_GetWeeklyAgendaAction(kind, output[], size = sizeof(output))
{
    switch (kind)
    {
        case WEEKLY_SCORE_BUSINESS: format(output, size, "/empresa, contratos, estoque e fretes");
        case WEEKLY_SCORE_POLICE: format(output, size, "/centralchamados, BO, provas e mandados");
        case WEEKLY_SCORE_CITIZEN: format(output, size, "/missaopublica, GovBR e servicos publicos");
        default: format(output, size, "/trabalhar, /servico e rotas completas");
    }
    return 1;
}

stock Life_HasAchievement(playerid, achievement)
{
    return ((PlayerInfo[playerid][pAchievements] & achievement) != 0);
}

stock Life_GiveAchievement(playerid, achievement, title[])
{
    new message[128];

    if (Life_HasAchievement(playerid, achievement))
    {
        return 0;
    }

    PlayerInfo[playerid][pAchievements] |= achievement;
    PlayerInfo[playerid][pBankGoodHistory]++;
    Life_GetBankScore(playerid);
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Conquista desbloqueada: %s. Score cidadao recebeu historico positivo.", title);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_CONTRACT_FILE, "ACHIEVEMENT", playerid, title);
    return 1;
}

stock Life_CheckAchievements(playerid)
{
    if (PlayerInfo[playerid][pBankGoodHistory] >= 3 && !PlayerInfo[playerid][pDirtyName])
    {
        Life_GiveAchievement(playerid, ACH_GOOD_PAYER, "Bom pagador");
    }
    if (PlayerInfo[playerid][pJob] != JOB_NONE && Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob]) >= 3)
    {
        Life_GiveAchievement(playerid, ACH_WORKER, "Trabalhador");
    }
    if (PlayerInfo[playerid][pBusinessType] != LIFE_BUSINESS_NONE)
    {
        Life_GiveAchievement(playerid, ACH_BUSINESS_OWNER, "Empresario");
    }
    if (PlayerInfo[playerid][pCriminalRecords] == 0 && PlayerInfo[playerid][pWanted] == 0 && PlayerInfo[playerid][pFines] <= 0)
    {
        Life_GiveAchievement(playerid, ACH_CLEAN_RECORD, "Ficha limpa");
    }
    if (PlayerInfo[playerid][pVehicleModel] >= 400 && PlayerInfo[playerid][pLicenseCNH] && PlayerInfo[playerid][pVehicleTaxDue] <= 0)
    {
        Life_GiveAchievement(playerid, ACH_LEGAL_DRIVER, "Motorista legalizado");
    }
    if (PlayerInfo[playerid][pLoginStreak] >= 7)
    {
        Life_GiveAchievement(playerid, ACH_LOYAL_CITIZEN, "Cidadao frequente");
    }
    if (PlayerInfo[playerid][pMedicalShifts] >= 3 || PlayerInfo[playerid][pPoliceWarrants] >= 3)
    {
        Life_GiveAchievement(playerid, ACH_PUBLIC_SERVICE, "Servico publico");
    }
    return 1;
}

stock Life_ResetDailyLoop(playerid)
{
    new today = GetBrasiliaDayStamp();

    Life_ResetWeeklyLoop(playerid);
    Life_ResetDailyLimits(playerid);

    if (PlayerInfo[playerid][pMissionDay] == today)
    {
        return 0;
    }

    PlayerInfo[playerid][pMissionDay] = today;
    PlayerInfo[playerid][pMissionWork] = 0;
    PlayerInfo[playerid][pMissionMarket] = 0;
    PlayerInfo[playerid][pMissionBank] = 0;
    PlayerInfo[playerid][pMissionBill] = 0;
    PlayerInfo[playerid][pMissionDocs] = 0;
    PlayerInfo[playerid][pMissionRewarded] = 0;

    if (PlayerInfo[playerid][pBusinessType] != LIFE_BUSINESS_NONE)
    {
        PlayerInfo[playerid][pBusinessOrderDay] = today;
        PlayerInfo[playerid][pBusinessOrders] = 2 + PlayerInfo[playerid][pBusinessEmployees];
        if (PlayerInfo[playerid][pBusinessOrders] > 8) PlayerInfo[playerid][pBusinessOrders] = 8;
        if (PlayerInfo[playerid][pBusinessStock] <= 0)
        {
            PlayerInfo[playerid][pBusinessOrders] += 2;
            PlayerInfo[playerid][pBusinessDebt] += Cfg_Price(gCfgBusinessSalaryCost) / 2;
            SendClientMessage(playerid, COLOR_ORANGE, "Empresa parada por estoque baixo: novos pedidos e divida operacional foram gerados.");
        }
        if (PlayerInfo[playerid][pBusinessEmployees] > 0 && PlayerInfo[playerid][pBusinessBalance] < (Cfg_Price(gCfgBusinessSalaryCost) * PlayerInfo[playerid][pBusinessEmployees]))
        {
            PlayerInfo[playerid][pBusinessTaxDue] += Cfg_Price(gCfgBusinessSalaryCost) / 2;
            PlayerInfo[playerid][pBusinessDebt] += Cfg_Price(gCfgBusinessSalaryCost) / 2;
            PlayerInfo[playerid][pBankBadHistory]++;
            SendClientMessage(playerid, COLOR_ORANGE, "Empresa com risco trabalhista: caixa baixo para salarios NPC.");
        }
        if (PlayerInfo[playerid][pBusinessDebt] >= 15000 && !PlayerInfo[playerid][pBusinessBankrupt])
        {
            PlayerInfo[playerid][pBusinessBankrupt] = 1;
            PlayerInfo[playerid][pBankBadHistory]++;
            SendClientMessage(playerid, COLOR_RED, "Empresa entrou em falencia operacional. Use /recuperarempresa para tentar recuperacao judicial.");
        }
    }
    return 1;
}

stock Life_MissionDoneCount(playerid)
{
    new count;

    Life_ResetDailyLoop(playerid);
    if (PlayerInfo[playerid][pMissionWork] >= LIFE_MISSION_WORK_TARGET) count++;
    if (PlayerInfo[playerid][pMissionMarket] > 0) count++;
    if (PlayerInfo[playerid][pMissionBank] > 0) count++;
    if (PlayerInfo[playerid][pMissionBill] > 0) count++;
    if (PlayerInfo[playerid][pMissionDocs] > 0) count++;
    return count;
}

stock Life_TryMissionReward(playerid)
{
    new message[128];
    new completed = Life_MissionDoneCount(playerid);
    new reward;

    if (PlayerInfo[playerid][pMissionRewarded] || completed < 3)
    {
        return 0;
    }

    reward = Vip_ApplyCashBonus(playerid, LIFE_MISSION_REWARD_CASH);
    PlayerInfo[playerid][pMissionRewarded] = 1;
    PlayerInfo[playerid][pBankGoodHistory]++;
    GivePlayerCashReason(playerid, reward, 0, "daily_reward");
    GivePlayerExperience(playerid, LIFE_MISSION_REWARD_XP, 0);
    Life_TrackGain(playerid, reward, LIFE_MISSION_REWARD_XP, "daily_mission");
    if (PlayerInfo[playerid][pJob] != JOB_NONE)
    {
        Job_AddProgressOnly(playerid, PlayerInfo[playerid][pJob], gCfgJobXpPerTask);
    }
    Life_GetBankScore(playerid);
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Missoes civis concluidas: %d/3. Recompensa: $%d, XP geral e bonus de score.", completed, reward);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_MONEY_FILE, "DAILY_MISSION", playerid, message);
    return 1;
}

stock Life_AddMissionProgress(playerid, missionType, amount)
{
    new tick;

    if (amount <= 0)
    {
        amount = 1;
    }

    Life_ResetDailyLoop(playerid);
    tick = GetTickCount();
    if (gLifeLastMissionTick[playerid] > 0 && tick - gLifeLastMissionTick[playerid] < LIFE_MISSION_COOLDOWN_MS)
    {
        WritePlayerLog(LOG_ADMIN_FILE, "MISSION_COOLDOWN", playerid, "progresso bloqueado por cooldown anti-farm");
        return 0;
    }
    gLifeLastMissionTick[playerid] = tick;
    switch (missionType)
    {
        case 1:
        {
            PlayerInfo[playerid][pMissionWork] += amount;
            if (PlayerInfo[playerid][pMissionWork] > LIFE_MISSION_WORK_TARGET) PlayerInfo[playerid][pMissionWork] = LIFE_MISSION_WORK_TARGET;
        }
        case 2: PlayerInfo[playerid][pMissionMarket] = 1;
        case 3: PlayerInfo[playerid][pMissionBank] = 1;
        case 4: PlayerInfo[playerid][pMissionBill] = 1;
        case 5: PlayerInfo[playerid][pMissionDocs] = 1;
    }
    if (missionType == 1)
    {
        Life_AddCityPassProgress(playerid, CITY_PASS_KIND_JOB, amount);
        Life_AddWeeklyScore(playerid, WEEKLY_SCORE_WORK, amount);
    }
    else if (missionType == 2 || missionType == 3 || missionType == 4 || missionType == 5)
    {
        Life_AddCityPassProgress(playerid, CITY_PASS_KIND_ECONOMY, 1);
        Life_AddWeeklyScore(playerid, WEEKLY_SCORE_CITIZEN, 1);
    }
    Life_TryMissionReward(playerid);
    return 1;
}

stock Life_ShowMissions(playerid)
{
    new message[160];
    new completed = Life_MissionDoneCount(playerid);

    format(message, sizeof(message), "Missoes civis de hoje: %d/3 concluidas | Recompensa %s.", completed, PlayerInfo[playerid][pMissionRewarded] ? ("resgatada") : ("pendente"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "1. Trabalhar: %d/%d servicos.", PlayerInfo[playerid][pMissionWork], LIFE_MISSION_WORK_TARGET);
    SendClientMessage(playerid, PlayerInfo[playerid][pMissionWork] >= LIFE_MISSION_WORK_TARGET ? COLOR_GREEN : COLOR_GRAY, message);
    format(message, sizeof(message), "2. Abastecer mercado: %s. Use /venderproduto com profissao produtiva.", PlayerInfo[playerid][pMissionMarket] ? ("feito") : ("pendente"));
    SendClientMessage(playerid, PlayerInfo[playerid][pMissionMarket] ? COLOR_GREEN : COLOR_GRAY, message);
    format(message, sizeof(message), "3. Consultar banco/extrato: %s. Use /saldo, /banco ou /extrato.", PlayerInfo[playerid][pMissionBank] ? ("feito") : ("pendente"));
    SendClientMessage(playerid, PlayerInfo[playerid][pMissionBank] ? COLOR_GREEN : COLOR_GRAY, message);
    format(message, sizeof(message), "4. Pagar conta/multa: %s. Use /boletos, /limparnome ou /pagarmultas.", PlayerInfo[playerid][pMissionBill] ? ("feito") : ("pendente"));
    SendClientMessage(playerid, PlayerInfo[playerid][pMissionBill] ? COLOR_GREEN : COLOR_GRAY, message);
    format(message, sizeof(message), "5. Emitir/renovar documento: %s. Use Prefeitura ou Cartorio.", PlayerInfo[playerid][pMissionDocs] ? ("feito") : ("pendente"));
    SendClientMessage(playerid, PlayerInfo[playerid][pMissionDocs] ? COLOR_GREEN : COLOR_GRAY, message);
    return 1;
}

stock Life_ShowCityEvents(playerid)
{
    new list[1400];
    new line[160];
    new eventText[128];
    new warText[128];
    new district[48];
    new goal[128];
    new index;

    Life_UpdateCityEvent();
    Life_UpdateWarZone();
    Life_FormatCityEvent(eventText, sizeof(eventText));
    Life_FormatWarZoneStatus(warText, sizeof(warText));
    Life_GetCityEventDistrict(district, sizeof(district));
    Life_GetCityEventGoal(goal, sizeof(goal));

    format(list, sizeof(list), "Indicador\tValor\n");
    format(line, sizeof(line), "Evento ativo\t%s\n", eventText); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Bairro 2.0\t%s | %s\n", district, goal); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Zona de guerra\t%s\n", warText); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Bonus horario\tmanhas transporte | almoco comida | noite seguranca/saude\n"); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Blitz especial\tpolicia/seguranca em expediente ganham bonus no evento\n"); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Surto hospitalar\tmedicos, ambulancia e bombeiros recebem demanda extra\n"); strcat(list, line, sizeof(list));
    for (index = 0; index < LIFE_MARKET_ITEMS; index++)
    {
        if (gMarketStock[index] <= gCfgMarketLowStock)
        {
            format(line, sizeof(line), "Estoque baixo\t%s: %d unidade(s)\n", gMarketNames[index], gMarketStock[index]);
            strcat(list, line, sizeof(list));
        }
    }

    ShowPlayerDialog(playerid, DIALOG_CITY_EVENTS, DIALOG_STYLE_TABLIST_HEADERS, "Eventos dinamicos da cidade", list, "Fechar", "");
    return 1;
}

stock Life_IsExpireWarning(expireDay, today)
{
    if (expireDay <= 0)
    {
        return 0;
    }
    return ((expireDay - today) <= LIFE_DOC_WARN_DAYS);
}

stock Life_GetVehicleDocWarnCount(playerid)
{
    new slot = gPlayerVehicleActiveSlot[playerid];
    new today = GetBrasiliaDayStamp();
    new count;

    if (PlayerInfo[playerid][pVehicleModel] < 400 || slot < 0)
    {
        return 0;
    }

    if (PlayerInfo[playerid][pVehicleTaxDue] > 0 || Life_IsExpireWarning(gPlayerVehicleTaxExpiry[playerid][slot], today))
    {
        count++;
    }
    if (!PlayerInfo[playerid][pVehicleInsurance] || Life_IsExpireWarning(gPlayerVehicleInsuranceExpiry[playerid][slot], today))
    {
        count++;
    }
    if (!gPlayerVehicleRegistered[playerid][slot])
    {
        count++;
    }
    return count;
}

stock Life_GetDocumentWarningCount(playerid)
{
    new today = GetBrasiliaDayStamp();
    new count;

    Life_UpdateExpirations(playerid, 0);
    if (!PlayerInfo[playerid][pDocuments] || Life_IsExpireWarning(PlayerInfo[playerid][pDocumentsExpire], today)) count++;
    if (PlayerInfo[playerid][pLicenseCNH] && Life_IsExpireWarning(PlayerInfo[playerid][pLicenseCNHExpire], today)) count++;
    if (PlayerInfo[playerid][pLicenseHeavy] && Life_IsExpireWarning(PlayerInfo[playerid][pLicenseHeavyExpire], today)) count++;
    if (PlayerInfo[playerid][pLicenseMedical] && Life_IsExpireWarning(PlayerInfo[playerid][pLicenseMedicalExpire], today)) count++;
    if (PlayerInfo[playerid][pLicenseOAB] && Life_IsExpireWarning(PlayerInfo[playerid][pLicenseOABExpire], today)) count++;
    if (PlayerInfo[playerid][pLicensePublic] && Life_IsExpireWarning(PlayerInfo[playerid][pLicensePublicExpire], today)) count++;
    if (PlayerInfo[playerid][pLicensePolice] && Life_IsExpireWarning(PlayerInfo[playerid][pLicensePoliceExpire], today)) count++;
    if (PlayerInfo[playerid][pHealthPlan] && Life_IsExpireWarning(PlayerInfo[playerid][pHealthPlanExpire], today)) count++;
    count += Life_GetVehicleDocWarnCount(playerid);
    return count;
}

stock Life_IsVehicleDetranRegular(playerid)
{
    new slot = gPlayerVehicleActiveSlot[playerid];

    if (PlayerInfo[playerid][pVehicleModel] < 400 || slot < 0)
    {
        return 0;
    }
    return (gPlayerVehicleRegistered[playerid][slot] && PlayerInfo[playerid][pVehicleTaxDue] <= 0 && PlayerInfo[playerid][pVehicleInsurance]);
}

stock Life_OnboardingDoneCount(playerid)
{
    new done;

    if (PlayerInfo[playerid][pDocuments]) done++;
    if (PlayerInfo[playerid][pBankAccount]) done++;
    if (PlayerInfo[playerid][pJob] != JOB_NONE) done++;
    if (PlayerInfo[playerid][pTutorialStep] >= 3) done++;
    return done;
}

stock Life_IsOnboardingComplete(playerid)
{
    return (Life_OnboardingDoneCount(playerid) >= LIFE_ONBOARDING_TARGET);
}

stock Life_GetNextStepKind(playerid)
{
    if (!PlayerInfo[playerid][pDocuments]) return LIFE_STEP_DOCUMENTS;
    if (!PlayerInfo[playerid][pBankAccount]) return LIFE_STEP_BANK;
    if (PlayerInfo[playerid][pJob] == JOB_NONE) return LIFE_STEP_JOB;
    if (PlayerInfo[playerid][pTutorialStep] < 3) return LIFE_STEP_WORK;
    if (!PlayerInfo[playerid][pOnboardingRewarded]) return LIFE_STEP_REWARD;
    if (PlayerInfo[playerid][pVehicleModel] < 400) return LIFE_STEP_VEHICLE;
    if (!Life_IsVehicleDetranRegular(playerid)) return LIFE_STEP_DETRAN;
    if (PlayerInfo[playerid][pHouse] == HOUSE_NONE && PlayerInfo[playerid][pRentedHouse] == HOUSE_NONE) return LIFE_STEP_HOME;
    if (Life_MissionDoneCount(playerid) < 3 || !PlayerInfo[playerid][pMissionRewarded]) return LIFE_STEP_GOVBR;
    if (PlayerInfo[playerid][pTutorialStep] < 5) return LIFE_STEP_CITIZEN;
    if (Life_GetDocumentWarningCount(playerid) > 0) return LIFE_STEP_DOC_RENEW;
    if (Life_BillTotal(playerid) > 0 || PlayerInfo[playerid][pFines] > 0) return LIFE_STEP_DEBT;
    if (PlayerInfo[playerid][pBusinessType] == LIFE_BUSINESS_NONE) return LIFE_STEP_BUSINESS;
    return LIFE_STEP_DONE;
}

stock Life_GetNextStepLocation(playerid)
{
    switch (Life_GetNextStepKind(playerid))
    {
        case LIFE_STEP_DOCUMENTS, LIFE_STEP_JOB:
        {
            return LOCATION_PREFEITURA;
        }
        case LIFE_STEP_BANK, LIFE_STEP_DEBT:
        {
            return LOCATION_BANCO;
        }
        case LIFE_STEP_WORK:
        {
            return Job_GetLocation(PlayerInfo[playerid][pJob]);
        }
        case LIFE_STEP_VEHICLE:
        {
            return LOCATION_CONCESSIONARIA;
        }
        case LIFE_STEP_DETRAN:
        {
            return LOCATION_DETRAN;
        }
        case LIFE_STEP_DOC_RENEW:
        {
            if (Life_GetVehicleDocWarnCount(playerid) > 0)
            {
                return LOCATION_DETRAN;
            }
            return LOCATION_PREFEITURA;
        }
    }
    return -1;
}

stock Life_GetNextStepText(playerid, output[], size = sizeof(output))
{
    new jobLabel[32];

    switch (Life_GetNextStepKind(playerid))
    {
        case LIFE_STEP_DOCUMENTS:
        {
            format(output, size, "Emitir RG/CPF na Prefeitura para liberar banco, emprego e GovBR.");
        }
        case LIFE_STEP_BANK:
        {
            format(output, size, "Abrir conta no Banco Central para receber salario, PIX e pagar boletos.");
        }
        case LIFE_STEP_JOB:
        {
            format(output, size, "Escolher uma profissao na Prefeitura e iniciar sua rotina.");
        }
        case LIFE_STEP_WORK:
        {
            GetJobName(PlayerInfo[playerid][pJob], jobLabel, sizeof(jobLabel));
            format(output, size, "Fazer o primeiro servico como %s usando /trabalhar.", jobLabel);
        }
        case LIFE_STEP_VEHICLE:
        {
            format(output, size, "Comprar o primeiro veiculo na Concessionaria.");
        }
        case LIFE_STEP_DETRAN:
        {
            format(output, size, "Regularizar CRLV, IPVA, registro e seguro no DETRAN.");
        }
        case LIFE_STEP_HOME:
        {
            format(output, size, "Comprar ou alugar uma residencia pelo menu de imoveis.");
        }
        case LIFE_STEP_GOVBR:
        {
            format(output, size, "Concluir 3 missoes civis e resgatar a recompensa no GovBR.");
        }
        case LIFE_STEP_CITIZEN:
        {
            format(output, size, "Consultar /cidadao para fechar reputacao e documentos pessoais.");
        }
        case LIFE_STEP_REWARD:
        {
            format(output, size, "Resgatar a recompensa de novato da primeira jornada.");
        }
        case LIFE_STEP_DOC_RENEW:
        {
            format(output, size, "Renovar documento, licenca, seguro ou vencimento no GovBR.");
        }
        case LIFE_STEP_DEBT:
        {
            format(output, size, "Regularizar boletos, multas e sentencas pendentes.");
        }
        case LIFE_STEP_BUSINESS:
        {
            format(output, size, "Abrir uma empresa quando o score permitir e atender pedidos.");
        }
        default:
        {
            format(output, size, "Rotina livre: trabalhar, cuidar da empresa, eventos e reputacao.");
        }
    }
    return 1;
}

stock Life_TryOnboardingReward(playerid)
{
    new reward;

    if (PlayerInfo[playerid][pOnboardingRewarded])
    {
        return 0;
    }
    if (!Life_IsOnboardingComplete(playerid))
    {
        return 0;
    }

    reward = 1500;
    PlayerInfo[playerid][pOnboardingRewarded] = 1;
    PlayerInfo[playerid][pBankGoodHistory]++;
    PlayerInfo[playerid][pWeeklyCitizenScore] += 2;
    GivePlayerCashReason(playerid, reward, 0, "onboarding_complete");
    GivePlayerExperience(playerid, 3, 0);
    Life_TrackGain(playerid, reward, 3, "onboarding_complete");
    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Primeira jornada concluida: documentos, banco, emprego e primeiro servico.");
    SendClientMessage(playerid, COLOR_GREEN, "Recompensa de novato: $1500, XP e reputacao. Proximos objetivos: veiculo, moradia e GovBR.");
    return 1;
}

stock Life_ShowFirstJourneyDialog(playerid)
{
    new list[1600];
    new line[180];
    new status[24];
    new jobLabel[32];
    new done = Life_OnboardingDoneCount(playerid);

    GetJobName(PlayerInfo[playerid][pJob], jobLabel, sizeof(jobLabel));
    format(list, sizeof(list), "Etapa\tStatus\tAcao\n");
    format(status, sizeof(status), "%s", PlayerInfo[playerid][pDocuments] ? ("OK") : ("pendente"));
    format(line, sizeof(line), "Documentos\t%s\tPrefeitura ou /documentos\n", status); strcat(list, line, sizeof(list));
    format(status, sizeof(status), "%s", PlayerInfo[playerid][pBankAccount] ? ("OK") : ("pendente"));
    format(line, sizeof(line), "Banco\t%s\tBanco Central\n", status); strcat(list, line, sizeof(list));
    format(status, sizeof(status), "%s", PlayerInfo[playerid][pJob] != JOB_NONE ? ("OK") : ("pendente"));
    format(line, sizeof(line), "Emprego\t%s\t%s\n", status, jobLabel); strcat(list, line, sizeof(list));
    format(status, sizeof(status), "%s", PlayerInfo[playerid][pTutorialStep] >= 3 ? ("OK") : ("pendente"));
    format(line, sizeof(line), "Primeiro servico\t%s\t/trabalhar ou /servico\n", status); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Recompensa\t%s\t$1500 + XP + reputacao\n", PlayerInfo[playerid][pOnboardingRewarded] ? ("resgatada") : ("pendente")); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Progresso inicial\t%d/%d\t%s\n", done, LIFE_ONBOARDING_TARGET, PlayerInfo[playerid][pOnboardingRewarded] ? ("concluido") : ("use Proximo")); strcat(list, line, sizeof(list));
    format(status, sizeof(status), "%s", PlayerInfo[playerid][pVehicleModel] >= 400 ? ("OK") : ("pendente"));
    format(line, sizeof(line), "Extra: veiculo\t%s\tConcessionaria\n", status); strcat(list, line, sizeof(list));
    format(status, sizeof(status), "%s", Life_IsVehicleDetranRegular(playerid) ? ("OK") : ("pendente"));
    format(line, sizeof(line), "Extra: DETRAN\t%s\tCRLV, IPVA, registro e seguro\n", status); strcat(list, line, sizeof(list));
    format(status, sizeof(status), "%s", (PlayerInfo[playerid][pHouse] != HOUSE_NONE || PlayerInfo[playerid][pRentedHouse] != HOUSE_NONE) ? ("OK") : ("pendente"));
    format(line, sizeof(line), "Extra: moradia\t%s\tComprar ou alugar imovel\n", status); strcat(list, line, sizeof(list));
    format(status, sizeof(status), "%s", PlayerInfo[playerid][pMissionRewarded] ? ("OK") : ("pendente"));
    format(line, sizeof(line), "Extra: GovBR\t%s\tMissoes %d/3\n", status, Life_MissionDoneCount(playerid)); strcat(list, line, sizeof(list));
    format(status, sizeof(status), "%s", PlayerInfo[playerid][pTutorialStep] >= 5 ? ("OK") : ("pendente"));
    format(line, sizeof(line), "Extra: reputacao\t%s\t/cidadao\n", status); strcat(list, line, sizeof(list));

    ShowPlayerDialog(playerid, DIALOG_FIRST_JOURNEY, DIALOG_STYLE_TABLIST_HEADERS, "Primeira jornada - GovBR", list, "Proximo", "Fechar");
    return 1;
}

stock Life_GetDailyJourneyProfile(playerid)
{
    if (Life_OnboardingDoneCount(playerid) < LIFE_ONBOARDING_TARGET || !PlayerInfo[playerid][pOnboardingRewarded])
    {
        return LIFE_DAILY_PROFILE_NEWCOMER;
    }
    if (Crime_IsValidFaction(PlayerInfo[playerid][pCrimeFaction]))
    {
        return LIFE_DAILY_PROFILE_CRIME;
    }
    if (IsLawEnforcementJob(PlayerInfo[playerid][pJob]) || PlayerInfo[playerid][pJob] == JOB_SEGURANCA)
    {
        return LIFE_DAILY_PROFILE_POLICE;
    }
    if (PlayerInfo[playerid][pBusinessType] != LIFE_BUSINESS_NONE)
    {
        return LIFE_DAILY_PROFILE_BUSINESS;
    }
    if (Job_IsPublicServant(PlayerInfo[playerid][pJob]))
    {
        return LIFE_DAILY_PROFILE_PUBLIC;
    }
    return LIFE_DAILY_PROFILE_WORKER;
}

stock Life_GetDailyProfileName(profile, output[], size = sizeof(output))
{
    switch (profile)
    {
        case LIFE_DAILY_PROFILE_NEWCOMER: format(output, size, "Novato");
        case LIFE_DAILY_PROFILE_BUSINESS: format(output, size, "Empresario");
        case LIFE_DAILY_PROFILE_POLICE: format(output, size, "Seguranca publica");
        case LIFE_DAILY_PROFILE_PUBLIC: format(output, size, "Servidor publico");
        case LIFE_DAILY_PROFILE_CRIME: format(output, size, "Criminoso RP");
        default: format(output, size, "Trabalhador");
    }
    return 1;
}

stock Life_AddDailyJourneyLine(list[], size, title[], current, target, action[])
{
    new line[180];
    new status[32];

    if (target <= 0)
    {
        format(status, sizeof(status), "%d", current);
    }
    else if (current >= target)
    {
        format(status, sizeof(status), "OK");
    }
    else
    {
        format(status, sizeof(status), "%d/%d", current, target);
    }

    format(line, sizeof(line), "%s\t%s\t%s\n", title, status, action);
    strcat(list, line, size);
    return 1;
}

stock Life_ShowDailyJourney(playerid)
{
    new list[2600];
    new line[220];
    new profileName[40];
    new jobLabel[32];
    new businessName[32];
    new eventText[128];
    new rewardText[32];
    new profile = Life_GetDailyJourneyProfile(playerid);
    new missions = Life_MissionDoneCount(playerid);
    new cooldown;

    Life_ResetDailyLoop(playerid);
    Life_UpdateCityEvent();
    Life_FormatCityEvent(eventText, sizeof(eventText));
    Life_GetDailyProfileName(profile, profileName, sizeof(profileName));
    GetJobName(PlayerInfo[playerid][pJob], jobLabel, sizeof(jobLabel));
    Life_GetBusinessName(PlayerInfo[playerid][pBusinessType], businessName, sizeof(businessName));
    format(rewardText, sizeof(rewardText), "%s", PlayerInfo[playerid][pMissionRewarded] ? ("resgatada") : ("pendente"));

    format(list, sizeof(list), "Area\tStatus\tAcao\n");
    format(line, sizeof(line), "Perfil do dia\t%s\t%s\n", profileName, jobLabel); strcat(list, line, sizeof(list));
    Life_AddDailyJourneyLine(list, sizeof(list), "Missoes civis", missions, 3, "recompensa diaria GovBR");
    Life_AddDailyJourneyLine(list, sizeof(list), "Trabalho", PlayerInfo[playerid][pMissionWork], LIFE_MISSION_WORK_TARGET, "/trabalhar ou /servico");
    format(line, sizeof(line), "Recompensa\t%s\t$%d + XP + score\n", rewardText, LIFE_MISSION_REWARD_CASH); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Bairro ativo\t%s\t/bairros\n", eventText); strcat(list, line, sizeof(list));

    switch (profile)
    {
        case LIFE_DAILY_PROFILE_NEWCOMER:
        {
            Life_AddDailyJourneyLine(list, sizeof(list), "Primeira jornada", Life_OnboardingDoneCount(playerid), LIFE_ONBOARDING_TARGET, "/proximopasso");
            Life_AddDailyJourneyLine(list, sizeof(list), "Documentos", PlayerInfo[playerid][pDocuments], 1, "Prefeitura ou /documentos");
            Life_AddDailyJourneyLine(list, sizeof(list), "Banco e emprego", (PlayerInfo[playerid][pBankAccount] ? 1 : 0) + (PlayerInfo[playerid][pJob] != JOB_NONE ? 1 : 0), 2, "Banco + Prefeitura");
        }
        case LIFE_DAILY_PROFILE_BUSINESS:
        {
            format(line, sizeof(line), "Empresa\t%s\tcaixa $%d\n", businessName, PlayerInfo[playerid][pBusinessBalance]); strcat(list, line, sizeof(list));
            Life_AddDailyJourneyLine(list, sizeof(list), "Pedidos/estoque", PlayerInfo[playerid][pBusinessOrders], 2, "/empresa ou /relatorioempresa");
            Life_AddDailyJourneyLine(list, sizeof(list), "Economia semanal", PlayerInfo[playerid][pCityPassEconomy], LIFE_CITY_PASS_ECO_TARGET, "boletos, estoque e contratos");
        }
        case LIFE_DAILY_PROFILE_POLICE:
        {
            Life_AddDailyJourneyLine(list, sizeof(list), "Operacao semanal", PlayerInfo[playerid][pWeeklyPoliceScore], 3, "abordagens, casos e chamados");
            Life_AddDailyJourneyLine(list, sizeof(list), "Cidade viva", PlayerInfo[playerid][pCityPassPublic], LIFE_CITY_PASS_PUBLIC_TARGET, "/centralchamados ou /missaopublica");
            Life_AddDailyJourneyLine(list, sizeof(list), "Mandados/provas", PlayerInfo[playerid][pPoliceWarrants] + PlayerInfo[playerid][pPoliceEvidence], 1, "/centralpolicia");
        }
        case LIFE_DAILY_PROFILE_PUBLIC:
        {
            Life_AddDailyJourneyLine(list, sizeof(list), "Servico publico", PlayerInfo[playerid][pCityPassPublic], LIFE_CITY_PASS_PUBLIC_TARGET, "/missaopublica");
            Life_AddDailyJourneyLine(list, sizeof(list), "Score cidadao", PlayerInfo[playerid][pWeeklyCitizenScore], 3, "atender cidade e GovBR");
            format(line, sizeof(line), "Evento urbano\t%s\t/eventos\n", eventText); strcat(list, line, sizeof(list));
        }
        case LIFE_DAILY_PROFILE_CRIME:
        {
            cooldown = PlayerInfo[playerid][pCrimeMissionCooldown] - gettime();
            if (cooldown < 0) cooldown = 0;
            Life_AddDailyJourneyLine(list, sizeof(list), "Faccao", PlayerInfo[playerid][pCrimeRank], 1, "/crimeinfo");
            Life_AddDailyJourneyLine(list, sizeof(list), "Respeito RP", PlayerInfo[playerid][pCrimeRespect], 10, "/crimemissoes");
            format(line, sizeof(line), "Risco/cooldown\twanted %d | espera %ds\tmanter RP controlado\n", PlayerInfo[playerid][pWanted], cooldown); strcat(list, line, sizeof(list));
        }
        default:
        {
            Life_AddDailyJourneyLine(list, sizeof(list), "Passe profissao", PlayerInfo[playerid][pCityPassJob], LIFE_CITY_PASS_JOB_TARGET, "variar servicos");
            Life_AddDailyJourneyLine(list, sizeof(list), "Rank semanal", PlayerInfo[playerid][pWeeklyWorkScore], 5, "/rankingsemanal");
            format(line, sizeof(line), "Bonus urbano\t%s\t/eventos\n", eventText); strcat(list, line, sizeof(list));
        }
    }

    ShowPlayerDialog(playerid, DIALOG_DAILY_JOURNEY, DIALOG_STYLE_TABLIST_HEADERS, "GovBR - Jornada diaria 2.0", list, "Agir", "Fechar");
    return 1;
}

stock Life_ApplyDailyJourney(playerid)
{
    new profile = Life_GetDailyJourneyProfile(playerid);
    new locationid;
    new message[144];

    if (Life_TryMissionReward(playerid))
    {
        return 1;
    }

    if (!PlayerInfo[playerid][pDocuments])
    {
        SetPlayerGps(playerid, LOCATION_PREFEITURA);
        return 1;
    }
    if (!PlayerInfo[playerid][pBankAccount])
    {
        SetPlayerGps(playerid, LOCATION_BANCO);
        return 1;
    }
    if (PlayerInfo[playerid][pJob] == JOB_NONE)
    {
        SetPlayerGps(playerid, LOCATION_PREFEITURA);
        return 1;
    }
    if (PlayerInfo[playerid][pMissionWork] < LIFE_MISSION_WORK_TARGET)
    {
        locationid = Job_GetLocation(PlayerInfo[playerid][pJob]);
        if (locationid > LOCATION_SPAWN)
        {
            SetPlayerGps(playerid, locationid);
        }
        SendClientMessage(playerid, COLOR_YELLOW, "Jornada diaria: conclua servicos do seu emprego com /trabalhar ou /servico.");
        return 1;
    }

    switch (profile)
    {
        case LIFE_DAILY_PROFILE_BUSINESS:
        {
            return Life_ShowBusinessDialog(playerid);
        }
        case LIFE_DAILY_PROFILE_POLICE:
        {
            return Life_ServiceCall_ShowList(playerid);
        }
        case LIFE_DAILY_PROFILE_PUBLIC:
        {
            return Life_ShowPublicSvcDialog(playerid);
        }
        case LIFE_DAILY_PROFILE_CRIME:
        {
            return Crime_ShowMissions(playerid);
        }
    }

    format(message, sizeof(message), "Jornada diaria: %d/3 missoes civis. Use /missoes para fechar a recompensa.", Life_MissionDoneCount(playerid));
    SendClientMessage(playerid, COLOR_YELLOW, message);
    return Life_ShowMissions(playerid);
}

stock Life_ApplyNextStep(playerid)
{
    new kind = Life_GetNextStepKind(playerid);
    new locationid = Life_GetNextStepLocation(playerid);
    new message[144];

    if (kind == LIFE_STEP_REWARD && Life_TryOnboardingReward(playerid))
    {
        return 1;
    }

    if (locationid > LOCATION_SPAWN)
    {
        SetPlayerGps(playerid, locationid);
        return 1;
    }

    switch (kind)
    {
        case LIFE_STEP_HOME:
        {
            SendClientMessage(playerid, COLOR_YELLOW, "Proximo passo: abra /casas ou Imoveis Online no celular para comprar/alugar.");
        }
        case LIFE_STEP_GOVBR:
        {
            Life_ShowMissions(playerid);
        }
        case LIFE_STEP_CITIZEN:
        {
            Life_ShowCitizenStatus(playerid);
        }
        case LIFE_STEP_DOC_RENEW:
        {
            Life_ShowDocumentsDialog(playerid);
        }
        case LIFE_STEP_BUSINESS:
        {
            SendClientMessage(playerid, COLOR_YELLOW, "Proximo passo: use /empresa ou /contratos quando seu score permitir.");
        }
        default:
        {
            Life_GetNextStepText(playerid, message, sizeof(message));
            SendClientMessage(playerid, COLOR_YELLOW, message);
        }
    }
    return 1;
}

stock Life_ShowNextStepDialog(playerid)
{
    new body[620];
    new nextStep[160];
    new done = Life_OnboardingDoneCount(playerid);
    new docs = Life_GetDocumentWarningCount(playerid);
    new debt = Life_BillTotal(playerid) + PlayerInfo[playerid][pFines];

    if (Life_TryOnboardingReward(playerid))
    {
        return 1;
    }

    Life_GetNextStepText(playerid, nextStep, sizeof(nextStep));
    format(body, sizeof(body),
        "Primeira jornada: %d/%d etapa(s).\nDocumentos/licencas em alerta: %d.\nPendencias financeiras: $%d.\n\nProximo passo:\n%s\n\nUse GovBR no celular para ver missoes, boletos, documentos, empresa, score e eventos.",
        done,
        LIFE_ONBOARDING_TARGET,
        docs,
        debt,
        nextStep
    );
    ShowPlayerDialog(playerid, DIALOG_NEXT_STEP, DIALOG_STYLE_MSGBOX, "GovBR - Proximo passo", body, "Executar", "Fechar");
    return 1;
}

stock Life_ShowActivityCenter(playerid)
{
    new list[2100];
    new line[180];
    new eventText[128];
    new businessName[32];
    new days[32];
    new score = Life_GetBankScore(playerid);
    new debt = Life_BillTotal(playerid);
    new missions = Life_MissionDoneCount(playerid);
    new nextStep[160];
    new notifications = Life_CountGovNotifications(playerid);
    new journeyDone = Life_OnboardingDoneCount(playerid);
    new docWarnings = Life_GetDocumentWarningCount(playerid);

    Life_UpdateExpirations(playerid, 0);
    Life_GenMonthlyBills(playerid, 0);
    Life_ApplyLateFees(playerid, 0);
    Life_UpdateJusticeCase(playerid, 0);
    Life_FormatCityEvent(eventText, sizeof(eventText));
    Life_GetBusinessName(PlayerInfo[playerid][pBusinessType], businessName, sizeof(businessName));
    Life_FormatDays(PlayerInfo[playerid][pDocumentsExpire], days, sizeof(days));
    Life_GetNextStepText(playerid, nextStep, sizeof(nextStep));

    format(list, sizeof(list), "Area\tStatus\n");
    format(line, sizeof(line), "Jornada diaria 2.0\tperfil automatico | use /jornadadiaria\n"); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Agenda semanal 2.0\tmetas por profissao | use /agendasemanal\n"); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Progresso urbano 2.0\treputacao por area | use /progressourbano\n"); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Primeira jornada\t%d/%d | recompensa %s\n", journeyDone, LIFE_ONBOARDING_TARGET, PlayerInfo[playerid][pOnboardingRewarded] ? ("resgatada") : ("pendente")); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Missoes\t%d/3 | recompensa %s\n", missions, PlayerInfo[playerid][pMissionRewarded] ? ("resgatada") : ("pendente")); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Boletos/multas\t$%d | vencimento %d\n", debt, PlayerInfo[playerid][pBillDueDay]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Documentos\tbase %s | validade %s | alertas %d\n", PlayerInfo[playerid][pDocuments] ? ("ok") : ("pendente"), days, docWarnings); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Banco/emprego\tconta %s | profissao %s\n", PlayerInfo[playerid][pBankAccount] ? ("ok") : ("pendente"), PlayerInfo[playerid][pJob] != JOB_NONE ? ("ok") : ("pendente")); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Empresa\t%s | caixa $%d | pedidos %d\n", businessName, PlayerInfo[playerid][pBusinessBalance], PlayerInfo[playerid][pBusinessOrders]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Score cidadao\t%d/1000 | historico +%d/-%d\n", score, PlayerInfo[playerid][pBankGoodHistory], PlayerInfo[playerid][pBankBadHistory]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Justica\tcasos %d | prazo %d | sentenca $%d\n", PlayerInfo[playerid][pJusticeCases], PlayerInfo[playerid][pJusticeDeadlineDay], PlayerInfo[playerid][pJusticeFineDue]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Evento\t%s\n", eventText); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Notificacoes GovBR\t%d pendencia(s) | use /notificacoes\n", notifications); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Passe da cidade\ttrab %d/%d | econ %d/%d | pub %d/%d\n", PlayerInfo[playerid][pCityPassJob], LIFE_CITY_PASS_JOB_TARGET, PlayerInfo[playerid][pCityPassEconomy], LIFE_CITY_PASS_ECO_TARGET, PlayerInfo[playerid][pCityPassPublic], LIFE_CITY_PASS_PUBLIC_TARGET); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Proximo passo\t%s\n", nextStep); strcat(list, line, sizeof(list));

    ShowPlayerDialog(playerid, DIALOG_ACTIVITY_CENTER, DIALOG_STYLE_TABLIST_HEADERS, "Central de atividades - GovBR", list, "Proximo", "Fechar");
    return 1;
}

stock Life_CountGovNotifications(playerid)
{
    new count;
    new docWarnings = Life_GetDocumentWarningCount(playerid);

    if (Life_OnboardingDoneCount(playerid) < LIFE_ONBOARDING_TARGET) count++;
    if (!PlayerInfo[playerid][pBankAccount]) count++;
    if (PlayerInfo[playerid][pJob] == JOB_NONE) count++;
    if (Life_MissionDoneCount(playerid) < 3) count++;
    if (Life_BillTotal(playerid) > 0 || PlayerInfo[playerid][pFines] > 0) count++;
    if (docWarnings > 0) count++;
    if (Life_HasOpenJusticeRisk(playerid) || PlayerInfo[playerid][pJusticeFineDue] > 0) count++;
    if (Life_CityEventActive()) count++;
    if (Life_IsWarZoneActive()) count++;
    if (PlayerInfo[playerid][pJob] != JOB_NONE && Life_GetJobPayBonusPercent(playerid, PlayerInfo[playerid][pJob]) > 0) count++;
    if (!PlayerInfo[playerid][pCityPassRewarded]) count++;
    if (!PlayerInfo[playerid][pOnboardingRewarded] && Life_IsOnboardingComplete(playerid)) count++;
    return count;
}

stock Life_SendGovNotifications(playerid)
{
    new message[160];
    new eventText[96];
    new count = Life_CountGovNotifications(playerid);
    new nextStep[160];
    new docWarnings = Life_GetDocumentWarningCount(playerid);

    if (count <= 0)
    {
        SendClientMessage(playerid, COLOR_GREEN, "GovBR: nenhuma pendencia importante agora.");
        return 1;
    }

    format(message, sizeof(message), "GovBR: %d notificacao(oes) ativa(s). Use /notificacoes ou /central.", count);
    SendClientMessage(playerid, COLOR_YELLOW, message);

    if (Life_OnboardingDoneCount(playerid) < LIFE_ONBOARDING_TARGET)
    {
        Life_GetNextStepText(playerid, nextStep, sizeof(nextStep));
        format(message, sizeof(message), "GovBR: primeira jornada pendente. Proximo passo: %s", nextStep);
        SendClientMessage(playerid, COLOR_GRAY, message);
    }
    if (!PlayerInfo[playerid][pBankAccount]) SendClientMessage(playerid, COLOR_GRAY, "GovBR: abra conta no Banco Central para liberar pagamentos e salario.");
    if (PlayerInfo[playerid][pJob] == JOB_NONE) SendClientMessage(playerid, COLOR_GRAY, "GovBR: escolha uma profissao na Prefeitura.");
    if (Life_MissionDoneCount(playerid) < 3) SendClientMessage(playerid, COLOR_GRAY, "GovBR: missoes civis diarias ainda liberam recompensa.");
    if (Life_BillTotal(playerid) > 0 || PlayerInfo[playerid][pFines] > 0) SendClientMessage(playerid, COLOR_GRAY, "GovBR: existem boletos, multas ou pendencias financeiras.");
    if (docWarnings > 0)
    {
        format(message, sizeof(message), "GovBR: %d documento(s), licenca(s) ou vencimento(s) precisam de atencao.", docWarnings);
        SendClientMessage(playerid, COLOR_GRAY, message);
    }
    if (Life_HasOpenJusticeRisk(playerid) || PlayerInfo[playerid][pJusticeFineDue] > 0) SendClientMessage(playerid, COLOR_GRAY, "GovBR: ha prazo, audiencia, sentenca ou caso judicial.");
    if (Life_CityEventActive())
    {
        Life_FormatCityEvent(eventText, sizeof(eventText));
        format(message, sizeof(message), "GovBR: evento ativo - %s.", eventText);
        SendClientMessage(playerid, COLOR_GRAY, message);
    }
    if (Life_IsWarZoneActive()) SendClientMessage(playerid, COLOR_GRAY, "GovBR: zona de guerra ativa em Mulholland. Area vermelha no mapa.");
    if (!PlayerInfo[playerid][pCityPassRewarded]) SendClientMessage(playerid, COLOR_GRAY, "GovBR: passe da cidade semanal ainda tem objetivos pendentes.");
    if (!PlayerInfo[playerid][pOnboardingRewarded] && Life_IsOnboardingComplete(playerid)) SendClientMessage(playerid, COLOR_GREEN, "GovBR: recompensa de novato pronta. Use /proximopasso.");
    return 1;
}

stock Life_OnPlayerAuth(playerid)
{
    new today = GetBrasiliaDayStamp();
    new week = Life_GetWeekStamp();
    new streakBonus;
    new reward;
    new message[144];

    gWarZoneVisible[playerid] = 0;
    gLifeOnboardingHintShown[playerid] = 0;
    Life_ResetWeeklyLoop(playerid);
    Life_ResetDailyLimits(playerid);
    Life_UpdateWarZoneForPlayer(playerid);
    Life_SyncPlayerPoliticalCache(playerid, 0);
    if (PlayerInfo[playerid][pLastLoginDay] != today)
    {
        if (PlayerInfo[playerid][pLastLoginDay] == today - 1)
        {
            PlayerInfo[playerid][pLoginStreak]++;
        }
        else
        {
            PlayerInfo[playerid][pLoginStreak] = 1;
        }
        PlayerInfo[playerid][pLastLoginDay] = today;
    }

    if (PlayerInfo[playerid][pDailyRewardDay] != today)
    {
        streakBonus = PlayerInfo[playerid][pLoginStreak];
        if (streakBonus > 7) streakBonus = 7;
        reward = Vip_ApplyCashBonus(playerid, LIFE_DAILY_REWARD_CASH + (streakBonus * 75));
        PlayerInfo[playerid][pDailyRewardDay] = today;
        PlayerInfo[playerid][pWeeklyCitizenScore]++;
        GivePlayerCashReason(playerid, reward, 0, "weekly_reward");
        GivePlayerExperience(playerid, 1, 0);
        Life_TrackGain(playerid, reward, 1, "daily_login");
        format(message, sizeof(message), "Recompensa diaria GovBR: $%d | sequencia de login: %d dia(s).", reward, PlayerInfo[playerid][pLoginStreak]);
        SendClientMessage(playerid, COLOR_GREEN, message);
        WritePlayerLog(LOG_MONEY_FILE, "DAILY_REWARD", playerid, message);
    }

    if (PlayerInfo[playerid][pWeeklyRewardWeek] != week && PlayerInfo[playerid][pLoginStreak] >= 5)
    {
        reward = Vip_ApplyCashBonus(playerid, LIFE_WEEKLY_REWARD_CASH);
        PlayerInfo[playerid][pWeeklyRewardWeek] = week;
        PlayerInfo[playerid][pBankGoodHistory]++;
        PlayerInfo[playerid][pWeeklyCitizenScore] += 3;
        GivePlayerCashReason(playerid, reward, 0, "city_pass_reward");
        GivePlayerExperience(playerid, 2, 0);
        Life_TrackGain(playerid, reward, 2, "weekly_login");
        format(message, sizeof(message), "Recompensa semanal GovBR: $%d por manter sequencia de login.", reward);
        SendClientMessage(playerid, COLOR_GREEN, message);
        WritePlayerLog(LOG_MONEY_FILE, "WEEKLY_REWARD", playerid, message);
    }

    Life_CheckAchievements(playerid);
    Life_SendGovNotifications(playerid);
    SaveAccountData(playerid, 0);
    return 1;
}

stock Life_ShowCityPass(playerid)
{
    new list[900];
    new line[144];
    new rewardText[32];

    Life_ResetWeeklyLoop(playerid);
    format(rewardText, sizeof(rewardText), "%s", PlayerInfo[playerid][pCityPassRewarded] ? ("resgatado") : ("pendente"));
    format(list, sizeof(list), "Objetivo\tProgresso\n");
    format(line, sizeof(line), "Profissao\t%d/%d servicos ou progresso de trabalho\n", PlayerInfo[playerid][pCityPassJob], LIFE_CITY_PASS_JOB_TARGET); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Economia\t%d/%d acoes de banco, empresa, estoque ou boletos\n", PlayerInfo[playerid][pCityPassEconomy], LIFE_CITY_PASS_ECO_TARGET); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Cidade viva\t%d/%d acoes de saude, policia, justica ou prefeitura\n", PlayerInfo[playerid][pCityPassPublic], LIFE_CITY_PASS_PUBLIC_TARGET); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Recompensa\t$%d + XP + reputacao | %s\n", LIFE_CITY_PASS_REWARD_CASH, rewardText); strcat(list, line, sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_CITY_PASS, DIALOG_STYLE_TABLIST_HEADERS, "Passe da cidade - semanal", list, "Fechar", "");
    return 1;
}

stock Life_UrbanPercent(part, target)
{
    if (target <= 0)
    {
        return 0;
    }
    if (part < 0)
    {
        part = 0;
    }
    if (part > target)
    {
        part = target;
    }
    return (part * 100) / target;
}

stock Life_GetUrbanAreaName(area, output[], size = sizeof(output))
{
    switch (area)
    {
        case LIFE_URBAN_AREA_WORK: format(output, size, "Trabalho");
        case LIFE_URBAN_AREA_ECONOMY: format(output, size, "Economia");
        case LIFE_URBAN_AREA_SECURITY: format(output, size, "Seguranca");
        case LIFE_URBAN_AREA_CIVIC: format(output, size, "Civico");
        case LIFE_URBAN_AREA_COMMUNITY: format(output, size, "Comunidade");
        default: format(output, size, "Cidade");
    }
    return 1;
}

stock Life_GetUrbanAreaStatus(value, output[], size = sizeof(output))
{
    if (value >= 90)
    {
        format(output, size, "excelente");
    }
    else if (value >= 65)
    {
        format(output, size, "forte");
    }
    else if (value >= 35)
    {
        format(output, size, "ativo");
    }
    else
    {
        format(output, size, "baixo");
    }
    return 1;
}

stock Life_GetUrbanAreaAction(area, output[], size = sizeof(output))
{
    switch (area)
    {
        case LIFE_URBAN_AREA_WORK:
        {
            format(output, size, "/trabalhar, /servico e agenda semanal");
        }
        case LIFE_URBAN_AREA_ECONOMY:
        {
            format(output, size, "banco, boletos, estoque e empresa");
        }
        case LIFE_URBAN_AREA_SECURITY:
        {
            format(output, size, "/190, chamados, mandados e rondas");
        }
        case LIFE_URBAN_AREA_CIVIC:
        {
            format(output, size, "documentos, passe da cidade e GovBR");
        }
        case LIFE_URBAN_AREA_COMMUNITY:
        {
            format(output, size, "login, eventos, noticias e atendimento publico");
        }
        default:
        {
            format(output, size, "/atividades");
        }
    }
    return 1;
}

stock Life_GetUrbanAreaProgress(playerid, area)
{
    new score;
    new completed;

    switch (area)
    {
        case LIFE_URBAN_AREA_WORK:
        {
            score = Life_UrbanPercent(PlayerInfo[playerid][pCityPassJob], LIFE_CITY_PASS_JOB_TARGET) / 2;
            score += Life_UrbanPercent(PlayerInfo[playerid][pWeeklyWorkScore], LIFE_WEEKLY_AGENDA_WORK_TARGET) / 2;
            return score;
        }
        case LIFE_URBAN_AREA_ECONOMY:
        {
            score = (Life_UrbanPercent(PlayerInfo[playerid][pCityPassEconomy], LIFE_CITY_PASS_ECO_TARGET) * 4) / 10;
            score += (Life_UrbanPercent(PlayerInfo[playerid][pWeeklyBusinessScore], LIFE_WEEKLY_AGENDA_BUSINESS_TARGET) * 3) / 10;
            score += (Life_UrbanPercent(Life_GetBankScore(playerid), 1000) * 3) / 10;
            return score;
        }
        case LIFE_URBAN_AREA_SECURITY:
        {
            completed = PlayerInfo[playerid][pPoliceWarrants] + PlayerInfo[playerid][pPoliceEvidence];
            score = (Life_UrbanPercent(PlayerInfo[playerid][pWeeklyPoliceScore], LIFE_WEEKLY_AGENDA_POLICE_TARGET) * 5) / 10;
            score += (Life_UrbanPercent(completed, 6) * 3) / 10;
            score += (Life_UrbanPercent(PlayerInfo[playerid][pCityPassPublic], LIFE_CITY_PASS_PUBLIC_TARGET) * 2) / 10;
            return score;
        }
        case LIFE_URBAN_AREA_CIVIC:
        {
            completed = 0;
            if (PlayerInfo[playerid][pDocuments]) completed++;
            if (PlayerInfo[playerid][pBankAccount]) completed++;
            if (PlayerInfo[playerid][pJob] != JOB_NONE) completed++;
            if (PlayerInfo[playerid][pOnboardingRewarded]) completed++;
            score = (Life_UrbanPercent(PlayerInfo[playerid][pCityPassPublic], LIFE_CITY_PASS_PUBLIC_TARGET) * 4) / 10;
            score += (Life_UrbanPercent(Life_MissionDoneCount(playerid), 3) * 3) / 10;
            score += (Life_UrbanPercent(completed, 4) * 3) / 10;
            return score;
        }
        case LIFE_URBAN_AREA_COMMUNITY:
        {
            score = (Life_UrbanPercent(PlayerInfo[playerid][pWeeklyCitizenScore], LIFE_WEEKLY_AGENDA_CITIZEN_TARGET) * 5) / 10;
            score += (Life_UrbanPercent(PlayerInfo[playerid][pLoginStreak], 7) * 3) / 10;
            score += (Life_UrbanPercent(Life_OnboardingDoneCount(playerid), LIFE_ONBOARDING_TARGET) * 2) / 10;
            return score;
        }
    }
    return 0;
}

stock Life_GetLowestUrbanArea(playerid)
{
    new area;
    new score;
    new bestArea = LIFE_URBAN_AREA_WORK;
    new bestScore = 101;

    for (area = LIFE_URBAN_AREA_WORK; area <= LIFE_URBAN_AREA_COMMUNITY; area++)
    {
        score = Life_GetUrbanAreaProgress(playerid, area);
        if (score < bestScore)
        {
            bestScore = score;
            bestArea = area;
        }
    }
    return bestArea;
}

stock Life_AddUrbanProgressLine(playerid, list[], size, area)
{
    new line[192];
    new areaName[32];
    new status[24];
    new action[96];
    new score = Life_GetUrbanAreaProgress(playerid, area);

    Life_GetUrbanAreaName(area, areaName, sizeof(areaName));
    Life_GetUrbanAreaStatus(score, status, sizeof(status));
    Life_GetUrbanAreaAction(area, action, sizeof(action));
    format(line, sizeof(line), "%s\t%d/100 %s\t%s\n", areaName, score, status, action);
    strcat(list, line, size);
    return 1;
}

stock Life_ShowUrbanProgress(playerid)
{
    new list[1800];
    new line[192];
    new focusName[32];
    new focusAction[96];
    new focusArea;
    new total;
    new score = Life_GetBankScore(playerid);

    Life_ResetDailyLoop(playerid);
    Life_ResetWeeklyLoop(playerid);
    focusArea = Life_GetLowestUrbanArea(playerid);
    Life_GetUrbanAreaName(focusArea, focusName, sizeof(focusName));
    Life_GetUrbanAreaAction(focusArea, focusAction, sizeof(focusAction));

    format(list, sizeof(list), "Area\tReputacao\tComo melhora\n");
    Life_AddUrbanProgressLine(playerid, list, sizeof(list), LIFE_URBAN_AREA_WORK);
    Life_AddUrbanProgressLine(playerid, list, sizeof(list), LIFE_URBAN_AREA_ECONOMY);
    Life_AddUrbanProgressLine(playerid, list, sizeof(list), LIFE_URBAN_AREA_SECURITY);
    Life_AddUrbanProgressLine(playerid, list, sizeof(list), LIFE_URBAN_AREA_CIVIC);
    Life_AddUrbanProgressLine(playerid, list, sizeof(list), LIFE_URBAN_AREA_COMMUNITY);
    total += Life_GetUrbanAreaProgress(playerid, LIFE_URBAN_AREA_WORK);
    total += Life_GetUrbanAreaProgress(playerid, LIFE_URBAN_AREA_ECONOMY);
    total += Life_GetUrbanAreaProgress(playerid, LIFE_URBAN_AREA_SECURITY);
    total += Life_GetUrbanAreaProgress(playerid, LIFE_URBAN_AREA_CIVIC);
    total += Life_GetUrbanAreaProgress(playerid, LIFE_URBAN_AREA_COMMUNITY);
    format(line, sizeof(line), "Media urbana\t%d/100\tScore cidadao %d/1000\n", total / 5, score);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Foco recomendado\t%s\t%s\n", focusName, focusAction);
    strcat(list, line, sizeof(list));

    ShowPlayerDialog(playerid, DIALOG_URBAN_PROGRESS, DIALOG_STYLE_TABLIST_HEADERS, "GovBR - Progresso urbano 2.0", list, "Agir", "Fechar");
    return 1;
}

stock Life_ApplyUrbanProgress(playerid)
{
    new area = Life_GetLowestUrbanArea(playerid);
    new locationid;

    switch (area)
    {
        case LIFE_URBAN_AREA_WORK:
        {
            if (PlayerInfo[playerid][pJob] == JOB_NONE)
            {
                SetPlayerGps(playerid, LOCATION_PREFEITURA);
                SendClientMessage(playerid, COLOR_YELLOW, "Progresso urbano: escolha uma profissao na Prefeitura.");
                return 1;
            }
            locationid = Job_GetLocation(PlayerInfo[playerid][pJob]);
            if (locationid > LOCATION_SPAWN)
            {
                SetPlayerGps(playerid, locationid);
            }
            SendClientMessage(playerid, COLOR_YELLOW, "Progresso urbano: trabalho baixo. Inicie servicos da profissao.");
            return Work_Start(playerid);
        }
        case LIFE_URBAN_AREA_ECONOMY:
        {
            SendClientMessage(playerid, COLOR_YELLOW, "Progresso urbano: economia baixa. Veja banco, boletos e empresa.");
            return ShowBankDialog(playerid, BANK_ACCESS_PHONE);
        }
        case LIFE_URBAN_AREA_SECURITY:
        {
            SendClientMessage(playerid, COLOR_YELLOW, "Progresso urbano: seguranca baixa. Atenda chamados ou casos.");
            return Life_ServiceCall_ShowList(playerid);
        }
        case LIFE_URBAN_AREA_CIVIC:
        {
            SendClientMessage(playerid, COLOR_YELLOW, "Progresso urbano: civico baixo. Regularize documentos e passe.");
            return Life_ShowNextStepDialog(playerid);
        }
        case LIFE_URBAN_AREA_COMMUNITY:
        {
            SendClientMessage(playerid, COLOR_YELLOW, "Progresso urbano: comunidade baixa. Veja eventos e noticias.");
            return Life_ShowNeighborhoodEvents(playerid);
        }
    }
    return Life_ShowActivityCenter(playerid);
}

stock Life_ShowWeeklyAgenda(playerid)
{
    new list[1800];
    new line[192];
    new jobLabel[32];
    new category[32];
    new focus[112];
    new action[96];
    new rewardText[32];
    new kind = Life_GetWeeklyAgendaKind(playerid);
    new target = Life_GetWeeklyAgendaTarget(kind);
    new score;

    Life_ResetWeeklyLoop(playerid);
    score = Life_GetWeeklyScore(playerid, kind);
    GetJobName(PlayerInfo[playerid][pJob], jobLabel, sizeof(jobLabel));
    Life_GetWeeklyAgendaName(kind, category, sizeof(category));
    Life_GetWeeklyJobFocus(PlayerInfo[playerid][pJob], focus, sizeof(focus));
    Life_GetWeeklyAgendaAction(kind, action, sizeof(action));
    format(rewardText, sizeof(rewardText), "%s", PlayerInfo[playerid][pCityPassRewarded] ? ("resgatado") : ("pendente"));

    format(list, sizeof(list), "Meta\tProgresso\tAcao\n");
    format(line, sizeof(line), "Categoria do ranking\t%s\t/rankingsemanal\n", category); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Profissao\t%s\t%s\n", jobLabel, focus); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Meta principal\t%d/%d ponto(s)\t%s\n", score, target, action); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Passe profissao\t%d/%d\tservicos e progresso de trabalho\n", PlayerInfo[playerid][pCityPassJob], LIFE_CITY_PASS_JOB_TARGET); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Passe economia\t%d/%d\tbanco, empresa, estoque e boletos\n", PlayerInfo[playerid][pCityPassEconomy], LIFE_CITY_PASS_ECO_TARGET); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Passe cidade viva\t%d/%d\tsaude, policia, justica ou prefeitura\n", PlayerInfo[playerid][pCityPassPublic], LIFE_CITY_PASS_PUBLIC_TARGET); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Recompensa semanal\t%s\t/passe\n", rewardText); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Evento por bairro\tplantao regional\t/bairros\n"); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Placar atual\ttrab %d | emp %d | pol %d | cid %d\tHistorico pessoal\n", PlayerInfo[playerid][pWeeklyWorkScore], PlayerInfo[playerid][pWeeklyBusinessScore], PlayerInfo[playerid][pWeeklyPoliceScore], PlayerInfo[playerid][pWeeklyCitizenScore]); strcat(list, line, sizeof(list));

    ShowPlayerDialog(playerid, DIALOG_WEEKLY_AGENDA, DIALOG_STYLE_TABLIST_HEADERS, "GovBR - Agenda semanal 2.0", list, "Agir", "Fechar");
    return 1;
}

stock Life_ApplyWeeklyAgenda(playerid)
{
    new kind = Life_GetWeeklyAgendaKind(playerid);
    new target = Life_GetWeeklyAgendaTarget(kind);
    new score = Life_GetWeeklyScore(playerid, kind);
    new locationid;
    new message[144];

    if (Life_TryCityPassReward(playerid))
    {
        return 1;
    }

    if (PlayerInfo[playerid][pJob] == JOB_NONE)
    {
        SetPlayerGps(playerid, LOCATION_PREFEITURA);
        SendClientMessage(playerid, COLOR_YELLOW, "Agenda semanal: escolha uma profissao para ativar metas por carreira.");
        return 1;
    }

    if (score >= target)
    {
        SendClientMessage(playerid, COLOR_GREEN, "Agenda semanal: meta principal batida. Veja sua posicao no ranking.");
        return Life_ShowWeeklyRanking(playerid);
    }

    switch (kind)
    {
        case WEEKLY_SCORE_BUSINESS:
        {
            return Life_ShowBusinessDialog(playerid);
        }
        case WEEKLY_SCORE_POLICE:
        {
            return Life_ServiceCall_ShowList(playerid);
        }
        case WEEKLY_SCORE_CITIZEN:
        {
            return Life_ShowPublicSvcDialog(playerid);
        }
    }

    locationid = Job_GetLocation(PlayerInfo[playerid][pJob]);
    if (locationid > LOCATION_SPAWN)
    {
        SetPlayerGps(playerid, locationid);
    }
    format(message, sizeof(message), "Agenda semanal: %d/%d ponto(s). Complete rotas e servicos para subir no ranking.", score, target);
    SendClientMessage(playerid, COLOR_YELLOW, message);
    return Work_Start(playerid);
}

stock Life_GetWeeklyScore(playerid, kind)
{
    switch (kind)
    {
        case WEEKLY_SCORE_WORK: return PlayerInfo[playerid][pWeeklyWorkScore];
        case WEEKLY_SCORE_BUSINESS: return PlayerInfo[playerid][pWeeklyBusinessScore];
        case WEEKLY_SCORE_POLICE: return PlayerInfo[playerid][pWeeklyPoliceScore];
        case WEEKLY_SCORE_CITIZEN: return PlayerInfo[playerid][pWeeklyCitizenScore] + (Life_GetBankScore(playerid) / 100);
    }
    return 0;
}

stock Life_AddRankingLine(list[], size, title[], kind)
{
    new pid;
    new topid = INVALID_PLAYER_ID;
    new topScore = -1;
    new score;
    new name[MAX_PLAYER_NAME + 1];
    new line[128];
    new maxPlayers = GetMaxPlayers();

    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged])
        {
            continue;
        }
        score = Life_GetWeeklyScore(pid, kind);
        if (score > topScore)
        {
            topScore = score;
            topid = pid;
        }
    }

    if (topid == INVALID_PLAYER_ID || topScore <= 0)
    {
        format(line, sizeof(line), "%s\tsem pontuacao online\n", title);
    }
    else
    {
        GetPlayerNameEx(topid, name, sizeof(name));
        format(line, sizeof(line), "%s\t%s com %d ponto(s)\n", title, name, topScore);
    }
    strcat(list, line, size);
    return 1;
}

stock Life_ShowWeeklyRanking(playerid)
{
    new list[900];
    new line[160];
    new category[32];
    new kind = Life_GetWeeklyAgendaKind(playerid);
    new target = Life_GetWeeklyAgendaTarget(kind);
    new score;

    Life_ResetWeeklyLoop(playerid);
    score = Life_GetWeeklyScore(playerid, kind);
    Life_GetWeeklyAgendaName(kind, category, sizeof(category));
    format(list, sizeof(list), "Ranking\tLider online\n");
    Life_AddRankingLine(list, sizeof(list), "Trabalhadores", WEEKLY_SCORE_WORK);
    Life_AddRankingLine(list, sizeof(list), "Empresas", WEEKLY_SCORE_BUSINESS);
    Life_AddRankingLine(list, sizeof(list), "Policia", WEEKLY_SCORE_POLICE);
    Life_AddRankingLine(list, sizeof(list), "Cidadaos", WEEKLY_SCORE_CITIZEN);
    format(line, sizeof(line), "Sua agenda\t%s %d/%d ponto(s)\n", category, score, target); strcat(list, line, sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_WEEKLY_RANKING, DIALOG_STYLE_TABLIST_HEADERS, "Ranking semanal da cidade", list, "Fechar", "");
    return 1;
}

stock Life_FormatAchievements(playerid, output[], size = sizeof(output))
{
    output[0] = 0;
    if (Life_HasAchievement(playerid, ACH_GOOD_PAYER)) strcat(output, "Bom pagador, ", size);
    if (Life_HasAchievement(playerid, ACH_WORKER)) strcat(output, "Trabalhador, ", size);
    if (Life_HasAchievement(playerid, ACH_BUSINESS_OWNER)) strcat(output, "Empresario, ", size);
    if (Life_HasAchievement(playerid, ACH_CLEAN_RECORD)) strcat(output, "Ficha limpa, ", size);
    if (Life_HasAchievement(playerid, ACH_LEGAL_DRIVER)) strcat(output, "Motorista legalizado, ", size);
    if (Life_HasAchievement(playerid, ACH_LOYAL_CITIZEN)) strcat(output, "Cidadao frequente, ", size);
    if (Life_HasAchievement(playerid, ACH_CITY_PASS)) strcat(output, "Passe da cidade, ", size);
    if (Life_HasAchievement(playerid, ACH_PUBLIC_SERVICE)) strcat(output, "Servico publico, ", size);
    if (output[0] == 0)
    {
        format(output, size, "nenhuma ainda");
    }
    return 1;
}

stock Life_ShowPersonalHistory(playerid)
{
    new list[1100];
    new line[160];
    new achievements[256];
    new title[48];

    Life_FormatAchievements(playerid, achievements, sizeof(achievements));
    if (Life_HasAchievement(playerid, ACH_CITY_PASS)) format(title, sizeof(title), "Embaixador da cidade");
    else if (Life_HasAchievement(playerid, ACH_BUSINESS_OWNER)) format(title, sizeof(title), "Empreendedor");
    else if (Life_HasAchievement(playerid, ACH_WORKER)) format(title, sizeof(title), "Profissional");
    else format(title, sizeof(title), "Cidadao");

    format(list, sizeof(list), "Campo\tValor\n");
    format(line, sizeof(line), "Titulo atual\t%s\n", title); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Reputacao\tScore %d | bom hist %d | ruim hist %d\n", Life_GetBankScore(playerid), PlayerInfo[playerid][pBankGoodHistory], PlayerInfo[playerid][pBankBadHistory]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Login\tsequencia %d dia(s) | diaria dia %d\n", PlayerInfo[playerid][pLoginStreak], PlayerInfo[playerid][pDailyRewardDay]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Passe\ttrab %d/%d | econ %d/%d | pub %d/%d\n", PlayerInfo[playerid][pCityPassJob], LIFE_CITY_PASS_JOB_TARGET, PlayerInfo[playerid][pCityPassEconomy], LIFE_CITY_PASS_ECO_TARGET, PlayerInfo[playerid][pCityPassPublic], LIFE_CITY_PASS_PUBLIC_TARGET); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Rank semanal\ttrab %d | emp %d | pol %d | cid %d\n", PlayerInfo[playerid][pWeeklyWorkScore], PlayerInfo[playerid][pWeeklyBusinessScore], PlayerInfo[playerid][pWeeklyPoliceScore], PlayerInfo[playerid][pWeeklyCitizenScore]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Conquistas\t%s\n", achievements); strcat(list, line, sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_PERSON_HISTORY, DIALOG_STYLE_TABLIST_HEADERS, "Historico pessoal", list, "Fechar", "");
    return 1;
}

stock Life_ShowCityNews(playerid)
{
    new list[1000];
    new line[160];
    new eventText[128];
    new warText[128];
    new index;

    Life_UpdateCityEvent();
    Life_UpdateWarZone();
    Life_FormatCityEvent(eventText, sizeof(eventText));
    Life_FormatWarZoneStatus(warText, sizeof(warText));
    format(list, sizeof(list), "Noticia\tStatus\n");
    format(line, sizeof(line), "Plantao da cidade\t%s\n", eventText); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Zona de guerra\t%s\n", warText); strcat(list, line, sizeof(list));
    for (index = 0; index < LIFE_MARKET_ITEMS; index++)
    {
        if (gMarketStock[index] <= gCfgMarketLowStock)
        {
            format(line, sizeof(line), "Mercado sem estoque\t%s com %d unidade(s)\n", gMarketNames[index], gMarketStock[index]);
            strcat(list, line, sizeof(list));
        }
    }
    if (gCityEventType == CITY_EVENT_BLITZ) strcat(list, "Blitz ativa\tOperacao especial em andamento\n", sizeof(list));
    if (gCityEventType == CITY_EVENT_HOSPITAL) strcat(list, "Hospital lotado\tSAMU e medicos com demanda elevada\n", sizeof(list));
    if (gCityEventType == CITY_EVENT_POLICE) strcat(list, "Operacao policial\tMandados e pericias em destaque\n", sizeof(list));
    if (Life_IsWarZoneActive()) strcat(list, "Mulholland em guerra\tCombate liberado dentro da area vermelha\n", sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_CITY_NEWS, DIALOG_STYLE_TABLIST_HEADERS, "Noticias automaticas da cidade", list, "Fechar", "");
    return 1;
}

stock Life_TutorialAdvance(playerid, step)
{
    new message[180];
    new reward = 180;

    if (PlayerInfo[playerid][pTutorialStep] >= step)
    {
        return 0;
    }

    PlayerInfo[playerid][pTutorialStep] = step;
    GivePlayerCashReason(playerid, reward, 0, "activity_objective_reward");
    GivePlayerExperience(playerid, 1, 0);
    format(message, sizeof(message), "Objetivo inicial concluido (%d/5). Recompensa: $%d e XP.", step, reward);
    SendClientMessage(playerid, COLOR_GREEN, message);
    if (step >= 5)
    {
        PlayerInfo[playerid][pBankGoodHistory]++;
        SendClientMessage(playerid, COLOR_GREEN, "Tutorial de objetivos concluido. Seu historico cidadao melhorou.");
    }
    SaveAccountData(playerid, 0);
    return 1;
}

stock Life_SendFirstJourneyHint(playerid)
{
    new message[180];
    new nextStep[160];
    new done;

    if (gLifeOnboardingHintShown[playerid] || !PlayerInfo[playerid][pIntroTutorialDone] || PlayerInfo[playerid][pOnboardingRewarded])
    {
        return 0;
    }

    done = Life_OnboardingDoneCount(playerid);
    Life_GetNextStepText(playerid, nextStep, sizeof(nextStep));
    gLifeOnboardingHintShown[playerid] = 1;

    if (done >= LIFE_ONBOARDING_TARGET)
    {
        SendClientMessage(playerid, COLOR_GREEN, "Primeira jornada pronta para recompensa. Use /proximopasso para resgatar.");
        return 1;
    }

    format(message, sizeof(message), "Primeira jornada: %d/%d. Proximo passo: %s", done, LIFE_ONBOARDING_TARGET, nextStep);
    SendClientMessage(playerid, COLOR_BLUE, message);
    SendClientMessage(playerid, COLOR_GRAY, "Use /proximopasso para marcar no GPS ou /jornada para ver o checklist.");
    return 1;
}

stock Life_ShowTutorialObjectives(playerid)
{
    new message[128];

    format(message, sizeof(message), "Objetivos iniciais: %d/5 concluidos.", PlayerInfo[playerid][pTutorialStep]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    SendClientMessage(playerid, PlayerInfo[playerid][pTutorialStep] >= 1 ? COLOR_GREEN : COLOR_GRAY, "1. Emitir documentos na Prefeitura.");
    SendClientMessage(playerid, PlayerInfo[playerid][pTutorialStep] >= 2 ? COLOR_GREEN : COLOR_GRAY, "2. Escolher um emprego.");
    SendClientMessage(playerid, PlayerInfo[playerid][pTutorialStep] >= 3 ? COLOR_GREEN : COLOR_GRAY, "3. Fazer seu primeiro servico/trabalho.");
    SendClientMessage(playerid, PlayerInfo[playerid][pTutorialStep] >= 4 ? COLOR_GREEN : COLOR_GRAY, "4. Abrir conta bancaria.");
    SendClientMessage(playerid, PlayerInfo[playerid][pTutorialStep] >= 5 ? COLOR_GREEN : COLOR_GRAY, "5. Consultar /cidadao.");
    return 1;
}

stock Life_FormatDays(expireDay, output[], size = sizeof(output))
{
    new days;

    if (expireDay <= 0)
    {
        format(output, size, "nao emitido");
        return 1;
    }

    days = expireDay - GetBrasiliaDayStamp();
    if (days < 0)
    {
        format(output, size, "vencido");
    }
    else
    {
        format(output, size, "%d dia(s)", days);
    }
    return 1;
}

stock Life_AddGovernmentRevenue(amount, reason[])
{
    new line[96];
    new category;

    if (amount <= 0)
    {
        return 0;
    }

    category = Life_GovRevCat(reason);
    gGovernmentRevenue += amount;
    if (category >= 0 && category < GOV_REV_CATEGORIES)
    {
        gGovernmentRevenueByCategory[category] += amount;
    }
    gGovernmentLastRevenueAmount = amount;
    format(gGovernmentLastRevenueReason, sizeof(gGovernmentLastRevenueReason), "%s", reason);
    Life_SaveGovernmentRevenue();

    format(line, sizeof(line), "amount=%d reason=%s total=%d", amount, reason, gGovernmentRevenue);
    WriteServerLog(LOG_MONEY_FILE, "GOV_REVENUE", line);
    return 1;
}

stock Life_AdminAddGovernmentRevenue(playerid, amount, reason[])
{
    new message[144];
    new logLine[160];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }
    if (amount <= 0 || amount > 100000000)
    {
        return SendUsage(playerid, "/addcofre [valor] [motivo]");
    }
    if (strlen(reason) < 1)
    {
        format(reason, 64, "admin_add_cofre");
    }

    if (!Life_AddGovernmentRevenue(amount, reason))
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel adicionar verba ao cofre.");
        return 1;
    }

    format(message, sizeof(message), "Cofre publico recebeu $%d. Saldo atual: $%d.", amount, gGovernmentRevenue);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(logLine, sizeof(logLine), "admin_id=%d amount=%d reason=%s total=%d", playerid, amount, reason, gGovernmentRevenue);
    WritePlayerLog(LOG_ADMIN_FILE, "ADMIN_ADD_COFRE", playerid, logLine);
    return 1;
}

stock Life_GovRevCat(reason[])
{
    if (strfind(reason, "tax", true) != -1 || strfind(reason, "bills", true) != -1 || strfind(reason, "ipva", true) != -1)
    {
        return GOV_REV_TAXES;
    }
    if (strfind(reason, "fine", true) != -1 || strfind(reason, "multa", true) != -1 || strfind(reason, "contract_cancel", true) != -1)
    {
        return GOV_REV_FINES;
    }
    if (strfind(reason, "pedagio", true) != -1 || strfind(reason, "toll", true) != -1)
    {
        return GOV_REV_TOLLS;
    }
    if (strfind(reason, "license", true) != -1 || strfind(reason, "document", true) != -1 || strfind(reason, "cartorio", true) != -1 || strfind(reason, "cpf", true) != -1 || strfind(reason, "rg", true) != -1)
    {
        return GOV_REV_LICENSES;
    }
    if (strfind(reason, "vehicle", true) != -1 || strfind(reason, "detran", true) != -1 || strfind(reason, "plate", true) != -1 || strfind(reason, "tow", true) != -1 || strfind(reason, "impound", true) != -1)
    {
        return GOV_REV_VEHICLES;
    }
    if (strfind(reason, "business", true) != -1 || strfind(reason, "licitacao", true) != -1)
    {
        return GOV_REV_BUSINESS;
    }
    if (strfind(reason, "contract", true) != -1)
    {
        return GOV_REV_CONTRACTS;
    }
    if (strfind(reason, "justice", true) != -1 || strfind(reason, "sentence", true) != -1 || strfind(reason, "lawyer", true) != -1)
    {
        return GOV_REV_JUSTICE;
    }
    if (strfind(reason, "hospital", true) != -1 || strfind(reason, "health", true) != -1 || strfind(reason, "ambulance", true) != -1 || strfind(reason, "service", true) != -1)
    {
        return GOV_REV_SERVICES;
    }
    return GOV_REV_OTHER;
}

stock Life_GovRevName(category, output[], size = sizeof(output))
{
    switch (category)
    {
        case GOV_REV_TAXES: format(output, size, "Impostos e boletos");
        case GOV_REV_FINES: format(output, size, "Multas");
        case GOV_REV_TOLLS: format(output, size, "Pedagios");
        case GOV_REV_LICENSES: format(output, size, "Documentos/licencas");
        case GOV_REV_VEHICLES: format(output, size, "DETRAN/veiculos");
        case GOV_REV_BUSINESS: format(output, size, "Empresas/licitacao");
        case GOV_REV_CONTRACTS: format(output, size, "Contratos");
        case GOV_REV_JUSTICE: format(output, size, "Justica");
        case GOV_REV_SERVICES: format(output, size, "Servicos publicos");
        default: format(output, size, "Outras receitas");
    }
    return 1;
}

stock Life_SaveGovernmentRevenue()
{
    new File:file;
    new line[192];
    new index;
    new key[24];

    file = fopen(GOVERNMENT_REVENUE_FILE, io_write);
    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Cofre publico / Central da Transparencia\r\n");
    format(line, sizeof(line), "total=%d\r\n", gGovernmentRevenue); fwrite(file, line);
    format(line, sizeof(line), "expense_total=%d\r\n", gGovernmentExpense); fwrite(file, line);
    format(line, sizeof(line), "last_amount=%d\r\n", gGovernmentLastRevenueAmount); fwrite(file, line);
    format(line, sizeof(line), "last_reason=%s\r\n", gGovernmentLastRevenueReason); fwrite(file, line);
    format(line, sizeof(line), "last_expense_amount=%d\r\n", gGovernmentLastExpenseAmount); fwrite(file, line);
    format(line, sizeof(line), "last_expense_reason=%s\r\n", gGovernmentLastExpenseReason); fwrite(file, line);
    format(line, sizeof(line), "last_decision_office=%s\r\n", gGovernmentLastDecisionOffice); fwrite(file, line);
    format(line, sizeof(line), "last_decision_text=%s\r\n", gGovernmentLastDecisionText); fwrite(file, line);
    format(line, sizeof(line), "last_decision_impact=%s\r\n", gGovernmentLastDecisionImpact); fwrite(file, line);
    format(line, sizeof(line), "last_decision_day=%d\r\n", gGovernmentLastDecisionDay); fwrite(file, line);
    for (index = 0; index < GOV_REV_CATEGORIES; index++)
    {
        Life_GovRevKey(index, key, sizeof(key));
        format(line, sizeof(line), "%s=%d\r\n", key, gGovernmentRevenueByCategory[index]);
        fwrite(file, line);
    }
    for (index = 0; index < GOV_EXP_CATEGORIES; index++)
    {
        Life_GovExpKey(index, key, sizeof(key));
        format(line, sizeof(line), "%s=%d\r\n", key, gGovernmentExpenseByCategory[index]);
        fwrite(file, line);
    }
    fclose(file);
    return 1;
}

stock Life_GovRevKey(category, output[], size = sizeof(output))
{
    switch (category)
    {
        case GOV_REV_TAXES: format(output, size, "taxes");
        case GOV_REV_FINES: format(output, size, "fines");
        case GOV_REV_TOLLS: format(output, size, "tolls");
        case GOV_REV_LICENSES: format(output, size, "licenses");
        case GOV_REV_VEHICLES: format(output, size, "vehicles");
        case GOV_REV_BUSINESS: format(output, size, "business");
        case GOV_REV_CONTRACTS: format(output, size, "contracts");
        case GOV_REV_JUSTICE: format(output, size, "justice");
        case GOV_REV_SERVICES: format(output, size, "services");
        default: format(output, size, "other");
    }
    return 1;
}

stock Life_GovRevCatByKey(key[])
{
    if (strcmp(key, "taxes", false) == 0) return GOV_REV_TAXES;
    if (strcmp(key, "fines", false) == 0) return GOV_REV_FINES;
    if (strcmp(key, "tolls", false) == 0) return GOV_REV_TOLLS;
    if (strcmp(key, "licenses", false) == 0) return GOV_REV_LICENSES;
    if (strcmp(key, "vehicles", false) == 0) return GOV_REV_VEHICLES;
    if (strcmp(key, "business", false) == 0) return GOV_REV_BUSINESS;
    if (strcmp(key, "contracts", false) == 0) return GOV_REV_CONTRACTS;
    if (strcmp(key, "justice", false) == 0) return GOV_REV_JUSTICE;
    if (strcmp(key, "services", false) == 0) return GOV_REV_SERVICES;
    if (strcmp(key, "other", false) == 0) return GOV_REV_OTHER;
    return -1;
}

stock Life_GovExpName(category, output[], size = sizeof(output))
{
    switch (category)
    {
        case GOV_EXP_INFRA: format(output, size, "Infraestrutura");
        case GOV_EXP_HEALTH: format(output, size, "Saude");
        case GOV_EXP_SECURITY: format(output, size, "Seguranca");
        case GOV_EXP_SOCIAL: format(output, size, "Social/educacao");
        case GOV_EXP_ADMIN: format(output, size, "Administracao");
        default: format(output, size, "Reserva publica");
    }
    return 1;
}

stock Life_GovExpKey(category, output[], size = sizeof(output))
{
    switch (category)
    {
        case GOV_EXP_INFRA: format(output, size, "expense_infra");
        case GOV_EXP_HEALTH: format(output, size, "expense_health");
        case GOV_EXP_SECURITY: format(output, size, "expense_security");
        case GOV_EXP_SOCIAL: format(output, size, "expense_social");
        case GOV_EXP_ADMIN: format(output, size, "expense_admin");
        default: format(output, size, "expense_reserve");
    }
    return 1;
}

stock Life_GovExpCatByKey(key[])
{
    if (strcmp(key, "expense_infra", false) == 0) return GOV_EXP_INFRA;
    if (strcmp(key, "expense_health", false) == 0) return GOV_EXP_HEALTH;
    if (strcmp(key, "expense_security", false) == 0) return GOV_EXP_SECURITY;
    if (strcmp(key, "expense_social", false) == 0) return GOV_EXP_SOCIAL;
    if (strcmp(key, "expense_admin", false) == 0) return GOV_EXP_ADMIN;
    if (strcmp(key, "expense_reserve", false) == 0) return GOV_EXP_RESERVE;
    return -1;
}

stock Life_ParseGovExpenseCategory(input[])
{
    if (strcmp(input, "infra", true) == 0 || strcmp(input, "obra", true) == 0 || strcmp(input, "obras", true) == 0 || strcmp(input, "infraestrutura", true) == 0) return GOV_EXP_INFRA;
    if (strcmp(input, "saude", true) == 0 || strcmp(input, "hospital", true) == 0 || strcmp(input, "samu", true) == 0) return GOV_EXP_HEALTH;
    if (strcmp(input, "seguranca", true) == 0 || strcmp(input, "policia", true) == 0 || strcmp(input, "prf", true) == 0 || strcmp(input, "bombeiro", true) == 0) return GOV_EXP_SECURITY;
    if (strcmp(input, "social", true) == 0 || strcmp(input, "educacao", true) == 0 || strcmp(input, "novatos", true) == 0) return GOV_EXP_SOCIAL;
    if (strcmp(input, "admin", true) == 0 || strcmp(input, "administracao", true) == 0 || strcmp(input, "prefeitura", true) == 0) return GOV_EXP_ADMIN;
    if (strcmp(input, "reserva", true) == 0 || strcmp(input, "emergencia", true) == 0) return GOV_EXP_RESERVE;
    return -1;
}

stock Life_AddGovernmentExpense(playerid, amount, category, reason[], notify = 1)
{
    new message[160];
    new categoryName[32];

    if (gGovernmentRevenue < 0)
    {
        gGovernmentRevenue = 0;
    }
    if (gGovernmentExpense < 0)
    {
        gGovernmentExpense = 0;
    }
    if (amount <= 0)
    {
        if (IsValidConnectedPlayer(playerid))
        {
            SendClientMessage(playerid, COLOR_RED, "Valor de gasto invalido.");
        }
        format(message, sizeof(message), "denied_invalid_amount amount=%d reason=%s balance=%d", amount, reason, gGovernmentRevenue);
        WriteServerLog(LOG_MONEY_FILE, "GOV_EXPENSE_DENIED", message);
        return 0;
    }
    if (category < 0 || category >= GOV_EXP_CATEGORIES)
    {
        if (IsValidConnectedPlayer(playerid))
        {
            SendClientMessage(playerid, COLOR_RED, "Categoria invalida. Use infra, saude, seguranca, social, admin ou reserva.");
        }
        format(message, sizeof(message), "denied_invalid_category amount=%d category=%d reason=%s balance=%d", amount, category, reason, gGovernmentRevenue);
        WriteServerLog(LOG_MONEY_FILE, "GOV_EXPENSE_DENIED", message);
        return 0;
    }
    if (amount > gGovernmentRevenue)
    {
        if (IsValidConnectedPlayer(playerid))
        {
            SendClientMessage(playerid, COLOR_RED, "Cofre publico insuficiente para esse gasto.");
            format(message, sizeof(message), "Saldo: $%d | necessario: $%d.", gGovernmentRevenue, amount);
            SendClientMessage(playerid, COLOR_GRAY, message);
        }
        format(message, sizeof(message), "denied_no_funds amount=%d category=%d reason=%s balance=%d", amount, category, reason, gGovernmentRevenue);
        WriteServerLog(LOG_MONEY_FILE, "GOV_EXPENSE_DENIED", message);
        return 0;
    }

    gGovernmentRevenue -= amount;
    gGovernmentExpense += amount;
    gGovernmentExpenseByCategory[category] += amount;
    gGovernmentLastExpenseAmount = amount;
    format(gGovernmentLastExpenseReason, sizeof(gGovernmentLastExpenseReason), "%s", reason);
    Life_SaveGovernmentRevenue();

    Life_GovExpName(category, categoryName, sizeof(categoryName));
    if (notify && IsValidConnectedPlayer(playerid))
    {
        format(message, sizeof(message), "Gasto publico registrado: $%d em %s. Saldo do cofre: $%d.", amount, categoryName, gGovernmentRevenue);
        SendClientMessage(playerid, COLOR_GREEN, message);
    }
    format(message, sizeof(message), "expense amount=%d category=%s reason=%s balance=%d", amount, categoryName, reason, gGovernmentRevenue);
    WriteServerLog(LOG_MONEY_FILE, "GOV_EXPENSE", message);
    return 1;
}

stock Life_LoadGovernmentRevenue()
{
    new File:file;
    new line[192];
    new key[32];
    new value[128];
    new pos;
    new category;
    new index;

    gGovernmentRevenue = 0;
    gGovernmentExpense = 0;
    gGovernmentLastRevenueAmount = 0;
    gGovernmentLastRevenueReason[0] = 0;
    gGovernmentLastExpenseAmount = 0;
    gGovernmentLastExpenseReason[0] = 0;
    gGovernmentLastDecisionOffice[0] = 0;
    gGovernmentLastDecisionText[0] = 0;
    gGovernmentLastDecisionImpact[0] = 0;
    gGovernmentLastDecisionDay = 0;
    for (index = 0; index < GOV_REV_CATEGORIES; index++)
    {
        gGovernmentRevenueByCategory[index] = 0;
    }
    for (index = 0; index < GOV_EXP_CATEGORIES; index++)
    {
        gGovernmentExpenseByCategory[index] = 0;
    }
    if (!fexist(GOVERNMENT_REVENUE_FILE))
    {
        Life_SaveGovernmentRevenue();
        return 1;
    }

    file = fopen(GOVERNMENT_REVENUE_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (fread(file, line))
    {
        StripLineEnd(line);
        Cfg_Trim(line);
        pos = strfind(line, "=", false);
        if (pos <= 0)
        {
            continue;
        }

        strmid(key, line, 0, pos, sizeof(key));
        strmid(value, line, pos + 1, strlen(line), sizeof(value));
        Cfg_Trim(key);
        Cfg_Trim(value);
        if (strcmp(key, "total", false) == 0)
        {
            gGovernmentRevenue = strval(value);
        }
        else if (strcmp(key, "expense_total", false) == 0)
        {
            gGovernmentExpense = strval(value);
        }
        else if (strcmp(key, "last_amount", false) == 0)
        {
            gGovernmentLastRevenueAmount = strval(value);
        }
        else if (strcmp(key, "last_reason", false) == 0)
        {
            format(gGovernmentLastRevenueReason, sizeof(gGovernmentLastRevenueReason), "%s", value);
        }
        else if (strcmp(key, "last_expense_amount", false) == 0)
        {
            gGovernmentLastExpenseAmount = strval(value);
        }
        else if (strcmp(key, "last_expense_reason", false) == 0)
        {
            format(gGovernmentLastExpenseReason, sizeof(gGovernmentLastExpenseReason), "%s", value);
        }
        else if (strcmp(key, "last_decision_office", false) == 0)
        {
            format(gGovernmentLastDecisionOffice, sizeof(gGovernmentLastDecisionOffice), "%s", value);
        }
        else if (strcmp(key, "last_decision_text", false) == 0)
        {
            format(gGovernmentLastDecisionText, sizeof(gGovernmentLastDecisionText), "%s", value);
        }
        else if (strcmp(key, "last_decision_impact", false) == 0)
        {
            format(gGovernmentLastDecisionImpact, sizeof(gGovernmentLastDecisionImpact), "%s", value);
        }
        else if (strcmp(key, "last_decision_day", false) == 0)
        {
            gGovernmentLastDecisionDay = strval(value);
        }
        else
        {
            category = Life_GovRevCatByKey(key);
            if (category >= 0 && category < GOV_REV_CATEGORIES)
            {
                gGovernmentRevenueByCategory[category] = strval(value);
            }
            else
            {
                category = Life_GovExpCatByKey(key);
                if (category >= 0 && category < GOV_EXP_CATEGORIES)
                {
                    gGovernmentExpenseByCategory[category] = strval(value);
                }
            }
        }
    }
    fclose(file);
    Life_SaveGovernmentRevenue();
    return 1;
}

stock Life_GetPublicWorkStatusName(status, output[], size = sizeof(output))
{
    switch (status)
    {
        case LIFE_PUBLIC_WORK_DONE: format(output, size, "concluida");
        default: format(output, size, "aguardando verba");
    }
    return 1;
}

stock Life_PublicWorkColor(status)
{
    if (status == LIFE_PUBLIC_WORK_DONE)
    {
        return COLOR_GREEN;
    }
    return COLOR_YELLOW;
}

stock Life_SavePublicWorks()
{
    new File:file;
    new line[64];
    new index;

    file = fopen(PUBLIC_WORKS_FILE, io_write);
    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Obras publicas financiadas pelo cofre\r\n");
    for (index = 0; index < LIFE_PUBLIC_WORK_COUNT; index++)
    {
        format(line, sizeof(line), "%d=%d\r\n", index, gPublicWorkStatus[index]);
        fwrite(file, line);
    }
    fclose(file);
    return 1;
}

stock Life_LoadPublicWorks()
{
    new File:file;
    new line[64];
    new key[16];
    new value[24];
    new pos;
    new index;

    for (index = 0; index < LIFE_PUBLIC_WORK_COUNT; index++)
    {
        gPublicWorkStatus[index] = LIFE_PUBLIC_WORK_PENDING;
    }

    if (!fexist(PUBLIC_WORKS_FILE))
    {
        return Life_SavePublicWorks();
    }

    file = fopen(PUBLIC_WORKS_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (fread(file, line))
    {
        StripLineEnd(line);
        Cfg_Trim(line);
        if (line[0] == 0 || line[0] == '#')
        {
            continue;
        }

        pos = strfind(line, "=", false);
        if (pos <= 0)
        {
            continue;
        }

        strmid(key, line, 0, pos, sizeof(key));
        strmid(value, line, pos + 1, strlen(line), sizeof(value));
        Cfg_Trim(key);
        Cfg_Trim(value);
        index = strval(key);
        if (index >= 0 && index < LIFE_PUBLIC_WORK_COUNT)
        {
            gPublicWorkStatus[index] = strval(value) == LIFE_PUBLIC_WORK_DONE ? LIFE_PUBLIC_WORK_DONE : LIFE_PUBLIC_WORK_PENDING;
        }
    }
    fclose(file);
    Life_SavePublicWorks();
    return 1;
}

stock Life_DestroyPublicWorks()
{
    new index;

    for (index = 0; index < LIFE_PUBLIC_WORK_COUNT; index++)
    {
        if (gPublicWorkLabel[index] != Text3D:INVALID_3DTEXT_ID)
        {
            Delete3DTextLabel(gPublicWorkLabel[index]);
            gPublicWorkLabel[index] = Text3D:INVALID_3DTEXT_ID;
        }
        if (gPublicWorkObject[index] != INVALID_OBJECT_ID && IsValidObject(gPublicWorkObject[index]))
        {
            DestroyObject(gPublicWorkObject[index]);
        }
        gPublicWorkObject[index] = INVALID_OBJECT_ID;
    }
    return 1;
}

stock Life_UpdatePublicWorkVisual(index)
{
    new label[180];
    new statusName[24];

    if (index < 0 || index >= LIFE_PUBLIC_WORK_COUNT)
    {
        return 0;
    }
    if (gPublicWorkLabel[index] != Text3D:INVALID_3DTEXT_ID)
    {
        Delete3DTextLabel(gPublicWorkLabel[index]);
        gPublicWorkLabel[index] = Text3D:INVALID_3DTEXT_ID;
    }
    if (gPublicWorkObject[index] != INVALID_OBJECT_ID && !IsValidObject(gPublicWorkObject[index]))
    {
        gPublicWorkObject[index] = INVALID_OBJECT_ID;
    }

    if (gPublicWorkObject[index] == INVALID_OBJECT_ID)
    {
        gPublicWorkObject[index] = CreateObject(gPublicWorks[index][publicWorkModel], gPublicWorks[index][publicWorkX] + 1.2, gPublicWorks[index][publicWorkY], gPublicWorks[index][publicWorkZ] - 0.5, 0.0, 0.0, 0.0, 80.0);
        if (gPublicWorkObject[index] == INVALID_OBJECT_ID)
        {
            WriteServerLog(LOG_ADMIN_FILE, "PUBLIC_WORK_VISUAL_FAIL", "object_create_failed");
        }
    }

    Life_GetPublicWorkStatusName(gPublicWorkStatus[index], statusName, sizeof(statusName));
    format(label, sizeof(label), "Obra publica #%d\n%s\nStatus: %s | custo $%d\nUse /obraspublicas", index + 1, gPublicWorks[index][publicWorkName], statusName, gPublicWorks[index][publicWorkCost]);
    gPublicWorkLabel[index] = Create3DTextLabel(label, Life_PublicWorkColor(gPublicWorkStatus[index]), gPublicWorks[index][publicWorkX], gPublicWorks[index][publicWorkY], gPublicWorks[index][publicWorkZ] + 1.2, 35.0, 0, 0);
    return 1;
}

stock Life_CreatePublicWorks()
{
    new index;

    for (index = 0; index < LIFE_PUBLIC_WORK_COUNT; index++)
    {
        gPublicWorkLabel[index] = Text3D:INVALID_3DTEXT_ID;
        gPublicWorkObject[index] = INVALID_OBJECT_ID;
        Life_UpdatePublicWorkVisual(index);
    }
    return 1;
}

stock Life_CountPublicWorksDone(category = -1)
{
    new index;
    new count;

    for (index = 0; index < LIFE_PUBLIC_WORK_COUNT; index++)
    {
        if (gPublicWorkStatus[index] != LIFE_PUBLIC_WORK_DONE)
        {
            continue;
        }
        if (category == -1 || gPublicWorks[index][publicWorkCategory] == category)
        {
            count++;
        }
    }
    return count;
}

stock Life_GetPublicWorkBonus(category)
{
    new bonus = Life_CountPublicWorksDone(category) * 5;

    if (bonus > 20)
    {
        bonus = 20;
    }
    return bonus;
}

stock Life_IsPublicWorkDone(workIndex)
{
    return (workIndex >= 0 && workIndex < LIFE_PUBLIC_WORK_COUNT && gPublicWorkStatus[workIndex] == LIFE_PUBLIC_WORK_DONE);
}

stock Life_ShowPublicWorks(playerid)
{
    new list[2800];
    new line[260];
    new statusName[24];
    new categoryName[32];
    new index;

    format(list, sizeof(list), "ID\tObra\tCusto/Status\tBeneficio\n");
    for (index = 0; index < LIFE_PUBLIC_WORK_COUNT; index++)
    {
        Life_GetPublicWorkStatusName(gPublicWorkStatus[index], statusName, sizeof(statusName));
        Life_GovExpName(gPublicWorks[index][publicWorkCategory], categoryName, sizeof(categoryName));
        format(line, sizeof(line), "%d\t%s\t$%d | %s | %s\t%s\n", index + 1, gPublicWorks[index][publicWorkName], gPublicWorks[index][publicWorkCost], statusName, categoryName, gPublicWorks[index][publicWorkBenefit]);
        strcat(list, line, sizeof(list));
    }

    format(line, sizeof(line), "Cofre publico\tSaldo atual\t$%d\tUse /financiarobra [id]\n", gGovernmentRevenue);
    strcat(list, line, sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_PUBLIC_WORKS, DIALOG_STYLE_TABLIST_HEADERS, "Obras publicas da cidade", list, "Fechar", "");
    return 1;
}

stock Life_FundPublicWork(playerid, workid)
{
    new index = workid - 1;
    new message[180];
    new reason[32];

    if (Life_GetPlayerPoliticalOffice(playerid) != -1 && !HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        Life_MarkPoliticalCorruption(playerid, "tentativa_de_gasto_direto_em_obra", workid);
        SendClientMessage(playerid, COLOR_RED, "Politico eleito nao pode gastar direto. Use /propostapolitica obra [id].");
        return 1;
    }
    if (!Life_IsPoliticalAuthority(playerid))
    {
        return SendNoPermission(playerid);
    }
    if (index < 0 || index >= LIFE_PUBLIC_WORK_COUNT)
    {
        return SendUsage(playerid, "/financiarobra [id]");
    }
    if (gPublicWorkStatus[index] == LIFE_PUBLIC_WORK_DONE)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Essa obra publica ja esta concluida.");
        return 1;
    }
    if (gPublicWorks[index][publicWorkCost] > gGovernmentRevenue)
    {
        format(reason, sizeof(reason), "obra_publica_%d", workid);
        format(message, sizeof(message), "denied_work_no_funds work=%d cost=%d balance=%d reason=%s", workid, gPublicWorks[index][publicWorkCost], gGovernmentRevenue, reason);
        WriteServerLog(LOG_MONEY_FILE, "GOV_EXPENSE_DENIED", message);
        SendClientMessage(playerid, COLOR_RED, "Cofre publico insuficiente para financiar essa obra.");
        format(message, sizeof(message), "Saldo: $%d | custo da obra: $%d.", gGovernmentRevenue, gPublicWorks[index][publicWorkCost]);
        SendClientMessage(playerid, COLOR_GRAY, message);
        SendClientMessage(playerid, COLOR_GRAY, "Use /addcofre [valor] [motivo] se voce for admin nivel 5.");
        return 1;
    }

    format(reason, sizeof(reason), "obra_publica_%d", workid);
    if (!Life_AddGovernmentExpense(playerid, gPublicWorks[index][publicWorkCost], gPublicWorks[index][publicWorkCategory], reason, 0))
    {
        return 1;
    }

    gPublicWorkStatus[index] = LIFE_PUBLIC_WORK_DONE;
    Life_SavePublicWorks();
    format(message, sizeof(message), "work=%d cost=%d category=%d balance=%d", workid, gPublicWorks[index][publicWorkCost], gPublicWorks[index][publicWorkCategory], gGovernmentRevenue);
    WriteServerLog(LOG_MONEY_FILE, "PUBLIC_WORK_DONE", message);
    return 1;
}

stock Life_PoliticalProposalTypeName(type, output[], size = sizeof(output))
{
    switch (type)
    {
        case LIFE_POL_PROP_WORK: format(output, size, "obra");
        case LIFE_POL_PROP_BUDGET: format(output, size, "orcamento");
        case LIFE_POL_PROP_AUDIT: format(output, size, "fiscalizacao");
        case LIFE_POL_PROP_ACCOUNT: format(output, size, "prestacao_contas");
        case LIFE_POL_PROP_CPI: format(output, size, "cpi");
        default: format(output, size, "invalida");
    }
    return 1;
}

stock Life_PolPropStatusName(status, output[], size = sizeof(output))
{
    switch (status)
    {
        case LIFE_POL_PROP_OPEN: format(output, size, "aberta");
        case LIFE_POL_PROP_APPROVED: format(output, size, "aprovada");
        case LIFE_POL_PROP_CANCELED: format(output, size, "cancelada");
        default: format(output, size, "invalida");
    }
    return 1;
}

stock Life_ParsePoliticalProposalType(input[])
{
    if (strcmp(input, "obra", true) == 0 || strcmp(input, "obras", true) == 0) return LIFE_POL_PROP_WORK;
    if (strcmp(input, "orcamento", true) == 0 || strcmp(input, "verba", true) == 0 || strcmp(input, "gasto", true) == 0) return LIFE_POL_PROP_BUDGET;
    if (strcmp(input, "fiscalizar", true) == 0 || strcmp(input, "fiscalizacao", true) == 0 || strcmp(input, "auditoria", true) == 0) return LIFE_POL_PROP_AUDIT;
    if (strcmp(input, "contas", true) == 0 || strcmp(input, "prestacao", true) == 0 || strcmp(input, "prestacaocontas", true) == 0) return LIFE_POL_PROP_ACCOUNT;
    if (strcmp(input, "cpi", true) == 0 || strcmp(input, "investigacao", true) == 0) return LIFE_POL_PROP_CPI;
    return LIFE_POL_PROP_NONE;
}

stock Life_SavePoliticalProposals()
{
    new File:file;
    new line[300];
    new index;

    file = fopen(POLITICAL_PROPOSALS_FILE, io_write);
    if (!file)
    {
        return 0;
    }
    fwrite(file, "# id|type|status|amount|category|workid|votes|day|creator|title|voters\r\n");
    for (index = 0; index < LIFE_POLITICAL_PROPOSALS; index++)
    {
        if (gPoliticalProposalType[index] == LIFE_POL_PROP_NONE)
        {
            continue;
        }
        format(line, sizeof(line), "%d|%d|%d|%d|%d|%d|%d|%d|%s|%s|%s\r\n",
            index,
            gPoliticalProposalType[index],
            gPoliticalProposalStatus[index],
            gPoliticalProposalAmount[index],
            gPoliticalProposalCategory[index],
            gPoliticalProposalWorkId[index],
            gPoliticalProposalVotes[index],
            gPoliticalProposalDay[index],
            gPoliticalProposalCreator[index],
            gPoliticalProposalTitle[index],
            gPoliticalProposalVoters[index]
        );
        fwrite(file, line);
    }
    fclose(file);
    return 1;
}

stock Life_ResetPoliticalProposal(index)
{
    gPoliticalProposalType[index] = LIFE_POL_PROP_NONE;
    gPoliticalProposalStatus[index] = LIFE_POL_PROP_OPEN;
    gPoliticalProposalAmount[index] = 0;
    gPoliticalProposalCategory[index] = GOV_EXP_ADMIN;
    gPoliticalProposalWorkId[index] = 0;
    gPoliticalProposalVotes[index] = 0;
    gPoliticalProposalDay[index] = 0;
    gPoliticalProposalCreator[index][0] = 0;
    gPoliticalProposalTitle[index][0] = 0;
    gPoliticalProposalVoters[index][0] = 0;
    return 1;
}

stock Life_LoadPoliticalProposals()
{
    new File:file;
    new line[300];
    new part[11][96];
    new partIndex;
    new charIndex;
    new cursor;
    new id;
    new index;

    for (index = 0; index < LIFE_POLITICAL_PROPOSALS; index++)
    {
        Life_ResetPoliticalProposal(index);
    }
    if (!fexist(POLITICAL_PROPOSALS_FILE))
    {
        Life_SavePoliticalProposals();
        return 1;
    }

    file = fopen(POLITICAL_PROPOSALS_FILE, io_read);
    if (!file)
    {
        return 0;
    }
    while (fread(file, line))
    {
        StripLineEnd(line);
        Cfg_Trim(line);
        if (line[0] == 0 || line[0] == '#')
        {
            continue;
        }
        for (partIndex = 0; partIndex < 11; partIndex++)
        {
            part[partIndex][0] = 0;
        }
        partIndex = 0;
        charIndex = 0;
        for (cursor = 0; cursor < strlen(line) && partIndex < 11; cursor++)
        {
            if (line[cursor] == '|')
            {
                part[partIndex][charIndex] = 0;
                partIndex++;
                charIndex = 0;
                continue;
            }
            if (charIndex < 95)
            {
                part[partIndex][charIndex++] = line[cursor];
            }
        }
        part[partIndex][charIndex] = 0;
        id = strval(part[0]);
        if (id < 0 || id >= LIFE_POLITICAL_PROPOSALS)
        {
            continue;
        }
        gPoliticalProposalType[id] = strval(part[1]);
        gPoliticalProposalStatus[id] = strval(part[2]);
        gPoliticalProposalAmount[id] = strval(part[3]);
        gPoliticalProposalCategory[id] = strval(part[4]);
        gPoliticalProposalWorkId[id] = strval(part[5]);
        gPoliticalProposalVotes[id] = strval(part[6]);
        gPoliticalProposalDay[id] = strval(part[7]);
        format(gPoliticalProposalCreator[id], MAX_PLAYER_NAME + 1, "%s", part[8]);
        format(gPoliticalProposalTitle[id], 64, "%s", part[9]);
        format(gPoliticalProposalVoters[id], 180, "%s", part[10]);
    }
    fclose(file);
    return 1;
}

stock Life_MarkPoliticalCorruption(playerid, reason[], amount = 0)
{
    new message[180];
    new name[MAX_PLAYER_NAME + 1];
    new officeName[28];
    new office = Life_GetPlayerPoliticalOffice(playerid);

    if (office == -1 || HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return 0;
    }
    GetPlayerNameEx(playerid, name, sizeof(name));
    Life_GetPoliticalOfficeName(office, officeName, sizeof(officeName));
    if (PlayerInfo[playerid][pWanted] < 3)
    {
        PlayerInfo[playerid][pWanted] = 3;
    }
    if (PlayerInfo[playerid][pWanted] > MAX_WANTED_LEVEL)
    {
        PlayerInfo[playerid][pWanted] = MAX_WANTED_LEVEL;
    }
    PlayerInfo[playerid][pCriminalRecords]++;
    PlayerInfo[playerid][pJusticeCases]++;
    PlayerInfo[playerid][pJusticeStatus] = JUSTICE_STATUS_INVESTIGATING;
    PlayerInfo[playerid][pJusticeDeadlineDay] = GetBrasiliaDayStamp() + 3;
    SaveAccountData(playerid, 0);

    format(message, sizeof(message), "[ANTI-CORRUPCAO] %s (%s) entrou na lista de procurados. Motivo: %s.", name, officeName, reason);
    SendClientMessageToAll(COLOR_RED, message);
    format(message, sizeof(message), "player=%s office=%s reason=%s amount=%d wanted=%d", name, officeName, reason, amount, PlayerInfo[playerid][pWanted]);
    WritePlayerLog(LOG_PUNISH_FILE, "POLITICAL_CORRUPTION", playerid, message);
    WritePlayerLog(LOG_ADMIN_FILE, "POLITICAL_CORRUPTION", playerid, message);
    return 1;
}

stock Life_PoliticalSpendLimit()
{
    new limit = (gGovernmentRevenue * LIFE_POLITICAL_MAX_SPEND_PERCENT) / 100;
    if (limit < 1 && gGovernmentRevenue > 0)
    {
        limit = gGovernmentRevenue;
    }
    return limit;
}

stock Life_AddPoliticalDutyRows(playerid, list[], size)
{
    new line[220];
    new office = Life_GetPlayerPoliticalOffice(playerid);
    new officeName[28];

    if (office == -1)
    {
        if (HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
        {
            strcat(list, "Seu cargo\tAdmin nivel 5\tPode auditar, cancelar propostas e gerenciar eleicoes\n", size);
        }
        else
        {
            strcat(list, "Seu cargo\tNenhum cargo eleito\tUse /politica para acompanhar eleicoes e candidatos\n", size);
        }
        strcat(list, "Acesso\tPublico\tVoce pode acompanhar propostas, mas so eleito/admin executa acoes\n", size);
        return 1;
    }

    Life_GetPoliticalOfficeName(office, officeName, sizeof(officeName));
    format(line, sizeof(line), "Seu cargo\t%s\tMandato ativo ate a proxima eleicao real\n", officeName);
    strcat(list, line, size);
    strcat(list, "Regra do cargo\tSem saque direto\tToda verba passa por proposta, votos, limite e log\n", size);

    switch (office)
    {
        case 0:
        {
            strcat(list, "Presidente\tDiretrizes gerais\tPropor orcamento macro, CPI e fiscalizacao nacional RP\n", size);
            strcat(list, "Comandos\t/propostapolitica orcamento [valor] [categoria] [motivo]\tCria programa publico dentro do limite\n", size);
            strcat(list, "Comandos\t/propostapolitica cpi 0 admin [motivo]\tAbre investigacao politica RP\n", size);
        }
        case 1:
        {
            strcat(list, "Vice-presidente\tApoio e substituicao\tFiscalizar propostas, votar pautas e abrir prestacao de contas\n", size);
            strcat(list, "Comandos\t/votarproposta [id]\tAprova ou ajuda a barrar proposta publica\n", size);
            strcat(list, "Comandos\t/propostapolitica contas 0 admin [motivo]\tPede prestacao de contas\n", size);
        }
        case 2:
        {
            strcat(list, "Governador\tEstado, seguranca e rodovias\tPropor saude, seguranca, PRF, hospitais e infraestrutura estadual\n", size);
            strcat(list, "Comandos\t/propostapolitica orcamento [valor] seguranca [motivo]\tReforca seguranca/PRF com limite\n", size);
            strcat(list, "Comandos\t/propostapolitica obra [id_obra] voto\tLeva obra para votacao\n", size);
        }
        case 3:
        {
            strcat(list, "Vice-governador\tApoio estadual\tFiscalizar gastos estaduais e votar propostas\n", size);
            strcat(list, "Comandos\t/propostapolitica fiscalizar 0 admin [motivo]\tRegistra fiscalizacao publica\n", size);
            strcat(list, "Comandos\t/votarproposta [id]\tVota em proposta aberta\n", size);
        }
        case 4:
        {
            strcat(list, "Prefeito\tCidade, obras e servicos\tDefine prioridade municipal e propoe obras/gastos publicos\n", size);
            strcat(list, "Comandos\t/prioridade [infra/saude/seguranca/social]\tMuda prioridade da prefeitura\n", size);
            strcat(list, "Comandos\t/propostapolitica obra [id_obra] voto\tObra so sai com aprovacao\n", size);
        }
        case 5:
        {
            strcat(list, "Vice-prefeito\tApoio municipal\tAcompanha prefeitura, obras, votos e prestacao de contas\n", size);
            strcat(list, "Comandos\t/propostapolitica contas 0 admin [motivo]\tPede transparencia da prefeitura\n", size);
            strcat(list, "Comandos\t/votarproposta [id]\tVota em proposta aberta\n", size);
        }
        case 6:
        {
            strcat(list, "Vereador\tFiscalizacao municipal\tFiscaliza prefeito, aprova orcamento e abre CPI local\n", size);
            strcat(list, "Comandos\t/votarproposta [id]\tVota propostas da cidade\n", size);
            strcat(list, "Comandos\t/propostapolitica cpi 0 admin [motivo]\tInvestiga irregularidade RP\n", size);
        }
        case 7:
        {
            strcat(list, "Senador\tRevisao e fiscalizacao\tRevisa propostas grandes, CPI e controle de gastos maiores\n", size);
            strcat(list, "Comandos\t/votarproposta [id]\tVota/revisa proposta aberta\n", size);
            strcat(list, "Comandos\t/propostapolitica fiscalizar 0 admin [motivo]\tAudita gasto ou programa publico\n", size);
        }
        case 8 .. 12:
        {
            strcat(list, "Deputado\tLeis e emendas RP\tPropoe orcamento setorial, fiscaliza e vota propostas\n", size);
            strcat(list, "Comandos\t/propostapolitica orcamento [valor] [categoria] [motivo]\tCria emenda segura\n", size);
            strcat(list, "Comandos\t/votarproposta [id]\tVota proposta aberta\n", size);
        }
        case 13 .. 17:
        {
            strcat(list, "Parlamentar\tPlenario e comissoes\tVota, fiscaliza, cobra transparencia e abre pautas RP\n", size);
            strcat(list, "Comandos\t/propostapolitica fiscalizar 0 admin [motivo]\tCria fiscalizacao/comissao\n", size);
            strcat(list, "Comandos\t/votarproposta [id]\tVota proposta aberta\n", size);
        }
    }
    return 1;
}

stock Life_ShowPoliticalDutyPanel(playerid)
{
    new list[1800];
    new line[220];
    new office;
    new officeName[32];
    new limit = Life_PoliticalSpendLimit();

    Life_SyncPlayerPoliticalCache(playerid, 0);
    office = Life_GetPlayerPoliticalOffice(playerid);
    if (office == -1)
    {
        format(officeName, sizeof(officeName), HasAdminLevel(playerid, ADMIN_LEVEL_OWNER) ? ("Admin nivel 5") : ("Sem cargo"));
    }
    else
    {
        Life_GetPoliticalOfficeName(office, officeName, sizeof(officeName));
    }

    format(list, sizeof(list), "Acao\tStatus\tDetalhe\n");
    format(line, sizeof(line), "Cargos eleitos atuais\tAbrir\tPresidente, governador, prefeito, vereador e todos os cargos\n");
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Meu cargo\t%s\tVer mandato, responsabilidades e propostas\n", officeName);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Limite por proposta\t$%d\t%d%% do cofre publico ($%d)\n", limit, LIFE_POLITICAL_MAX_SPEND_PERCENT, gGovernmentRevenue);
    strcat(list, line, sizeof(list));
    strcat(list, "Criar proposta de obra\tClicavel\tEscolher obra publica pendente\n", sizeof(list));
    strcat(list, "Criar proposta de orcamento\tClicavel\tValor, categoria e motivo\n", sizeof(list));
    strcat(list, "Fiscalizar gasto\tClicavel\tAbre registro publico sem gasto\n", sizeof(list));
    strcat(list, "Pedir prestacao de contas\tClicavel\tCobra transparencia sem mexer no cofre\n", sizeof(list));
    strcat(list, "Abrir CPI RP\tClicavel\tInvestigacao politica segura\n", sizeof(list));
    strcat(list, "Votar proposta\tClicavel\tEscolher proposta aberta\n", sizeof(list));
    strcat(list, "Central da transparencia\tAbrir\tCofre publico, receitas e gastos\n", sizeof(list));
    if (HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        strcat(list, "Cancelar proposta\tAdmin nivel 5\tEscolher proposta aberta para cancelar\n", sizeof(list));
    }
    strcat(list, "Voltar\t/politica\tRetornar ao menu principal\n", sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_POLITICAL_DUTY_PANEL, DIALOG_STYLE_TABLIST_HEADERS, "Politica - central clicavel", list, "Abrir", "Fechar");
    return 1;
}

stock Life_ShowPoliticalActionMenu(playerid)
{
    new list[900];
    new line[160];
    new limit = Life_PoliticalSpendLimit();

    if (Life_GetPlayerPoliticalOffice(playerid) == -1 && !HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas politico eleito ou admin nivel 5 pode usar acoes politicas.");
        return Life_ShowPoliticalDutyPanel(playerid);
    }

    format(list, sizeof(list), "Acao\tRegra\n");
    strcat(list, "Criar proposta de obra\tEscolher obra publica pendente\n", sizeof(list));
    format(line, sizeof(line), "Criar proposta de orcamento\tLimite atual $%d por proposta\n", limit);
    strcat(list, line, sizeof(list));
    strcat(list, "Fiscalizar gasto\tCria registro publico sem mexer no cofre\n", sizeof(list));
    strcat(list, "Pedir prestacao de contas\tCria pauta de transparencia sem gasto\n", sizeof(list));
    strcat(list, "Abrir CPI RP\tCria investigacao politica sem gasto\n", sizeof(list));
    strcat(list, "Votar proposta\tEscolher proposta aberta\n", sizeof(list));
    if (HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        strcat(list, "Cancelar proposta\tSomente admin nivel 5\n", sizeof(list));
    }
    strcat(list, "Central da transparencia\tVer cofre, entradas e gastos\n", sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_POLITICAL_ACTION_MENU, DIALOG_STYLE_TABLIST_HEADERS, "Painel politico - acoes", list, "Abrir", "Voltar");
    return 1;
}

stock Life_ShowPoliticalWorkSelect(playerid)
{
    new list[1200];
    new line[180];
    new index;
    new statusName[24];
    new categoryName[32];

    format(list, sizeof(list), "Obra\tCusto\tCategoria\n");
    for (index = 0; index < LIFE_PUBLIC_WORK_COUNT; index++)
    {
        Life_GetPublicWorkStatusName(gPublicWorkStatus[index], statusName, sizeof(statusName));
        Life_GovExpName(gPublicWorks[index][publicWorkCategory], categoryName, sizeof(categoryName));
        format(line, sizeof(line), "%d. %s\t$%d | %s\t%s\n", index + 1, gPublicWorks[index][publicWorkName], gPublicWorks[index][publicWorkCost], statusName, categoryName);
        strcat(list, line, sizeof(list));
    }
    ShowPlayerDialog(playerid, DIALOG_POLITICAL_WORK_SELECT, DIALOG_STYLE_TABLIST_HEADERS, "Proposta de obra", list, "Propor", "Voltar");
    return 1;
}

stock Life_ShowPoliticalBudgetInput(playerid)
{
    new body[360];
    new limit = Life_PoliticalSpendLimit();

    format(body, sizeof(body), "Digite: valor categoria motivo\n\nCategorias: infra, saude, seguranca, social, admin, reserva.\nLimite atual por proposta: $%d.\nExemplo: 5000 saude compra_remedios", limit);
    ShowPlayerDialog(playerid, DIALOG_POLITICAL_BUDGET_INPUT, DIALOG_STYLE_INPUT, "Proposta de orcamento", body, "Criar", "Voltar");
    return 1;
}

stock Life_ShowPoliticalQuickReason(playerid, action)
{
    new title[48];
    new body[260];

    gPoliticalDialogAction[playerid] = action;
    switch (action)
    {
        case LIFE_POL_ACTION_AUDIT:
        {
            format(title, sizeof(title), "Fiscalizar gasto");
            format(body, sizeof(body), "Digite o motivo/area da fiscalizacao.\nExemplo: contratos_pedagios");
        }
        case LIFE_POL_ACTION_ACCOUNT:
        {
            format(title, sizeof(title), "Prestacao de contas");
            format(body, sizeof(body), "Digite o assunto da prestacao de contas.\nExemplo: gastos_saude");
        }
        case LIFE_POL_ACTION_CPI:
        {
            format(title, sizeof(title), "Abrir CPI RP");
            format(body, sizeof(body), "Digite o motivo da CPI RP.\nExemplo: suspeita_corrupcao_obras");
        }
        default:
        {
            format(title, sizeof(title), "Pauta politica");
            format(body, sizeof(body), "Digite o motivo da pauta politica.");
        }
    }
    ShowPlayerDialog(playerid, DIALOG_POLITICAL_QUICK_REASON, DIALOG_STYLE_INPUT, title, body, "Criar", "Voltar");
    return 1;
}

stock Life_ShowPolProposalVoteList(playerid, cancelMode = 0)
{
    new list[2600];
    new line[220];
    new typeName[32];
    new categoryName[32];
    new index;
    new shown;

    format(list, sizeof(list), "Proposta\tVotos\tDetalhe\n");
    for (index = 0; index < LIFE_POLITICAL_PROPOSALS; index++)
    {
        if (gPoliticalProposalType[index] == LIFE_POL_PROP_NONE || gPoliticalProposalStatus[index] != LIFE_POL_PROP_OPEN)
        {
            continue;
        }
        Life_PoliticalProposalTypeName(gPoliticalProposalType[index], typeName, sizeof(typeName));
        Life_GovExpName(gPoliticalProposalCategory[index], categoryName, sizeof(categoryName));
        format(line, sizeof(line), "#%d %s\t%d/%d voto(s)\t$%d | %s | %s | autor %s\n",
            index + 1,
            typeName,
            gPoliticalProposalVotes[index],
            LIFE_POLITICAL_VOTE_NEED,
            gPoliticalProposalAmount[index],
            categoryName,
            gPoliticalProposalTitle[index],
            gPoliticalProposalCreator[index]
        );
        strcat(list, line, sizeof(list));
        shown++;
    }
    if (!shown)
    {
        strcat(list, "-\tSem proposta aberta\t-\n", sizeof(list));
    }
    gPoliticalDialogAction[playerid] = cancelMode ? LIFE_POL_ACTION_CANCEL : LIFE_POL_ACTION_VOTE;
    ShowPlayerDialog(playerid, DIALOG_POLITICAL_PROPOSAL_VOTE, DIALOG_STYLE_TABLIST_HEADERS, cancelMode ? ("Cancelar proposta") : ("Votar proposta"), list, cancelMode ? ("Cancelar") : ("Votar"), "Voltar");
    return 1;
}

stock Life_ApplyPoliticalProposal(playerid, index)
{
    new message[180];
    new reason[40];

    if (gPoliticalProposalType[index] == LIFE_POL_PROP_WORK)
    {
        new work = gPoliticalProposalWorkId[index] - 1;
        if (work < 0 || work >= LIFE_PUBLIC_WORK_COUNT || gPublicWorkStatus[work] == LIFE_PUBLIC_WORK_DONE)
        {
            gPoliticalProposalStatus[index] = LIFE_POL_PROP_CANCELED;
            Life_SavePoliticalProposals();
            SendClientMessage(playerid, COLOR_ORANGE, "Proposta de obra cancelada: obra invalida ou ja concluida.");
            return 1;
        }
        format(reason, sizeof(reason), "proposta_obra_%d", index + 1);
        if (!Life_AddGovernmentExpense(playerid, gPublicWorks[work][publicWorkCost], gPublicWorks[work][publicWorkCategory], reason, 0))
        {
            return 1;
        }
        gPublicWorkStatus[work] = LIFE_PUBLIC_WORK_DONE;
        Life_SavePublicWorks();
        format(message, sizeof(message), "proposal=%d work=%d cost=%d balance=%d", index + 1, work + 1, gPublicWorks[work][publicWorkCost], gGovernmentRevenue);
        WriteServerLog(LOG_MONEY_FILE, "PUBLIC_WORK_DONE", message);
    }
    else if (gPoliticalProposalType[index] == LIFE_POL_PROP_BUDGET)
    {
        format(reason, sizeof(reason), "proposta_orc_%d", index + 1);
        if (!Life_AddGovernmentExpense(playerid, gPoliticalProposalAmount[index], gPoliticalProposalCategory[index], reason))
        {
            return 1;
        }
        format(message, sizeof(message), "Proposta orcamentaria #%d aprovada. Gasto publico executado com log.", index + 1);
        SendClientMessageToAll(COLOR_GREEN, message);
    }
    else
    {
        format(message, sizeof(message), "Proposta politica #%d aprovada: %s.", index + 1, gPoliticalProposalTitle[index]);
        SendClientMessageToAll(COLOR_BLUE, message);
        format(message, sizeof(message), "proposal=%d type=%d title=%s", index + 1, gPoliticalProposalType[index], gPoliticalProposalTitle[index]);
        WriteServerLog(LOG_CONTRACT_FILE, "POLITICAL_DUTY", message);
    }

    gPoliticalProposalStatus[index] = LIFE_POL_PROP_APPROVED;
    Life_SavePoliticalProposals();
    return 1;
}

stock Life_CreatePoliticalProposal(playerid, type, value, category, title[])
{
    new index;
    new name[MAX_PLAYER_NAME + 1];
    new message[180];
    new limit;
    new work;
    new amount = value;

    if (Life_GetPlayerPoliticalOffice(playerid) == -1 && !HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }
    if (gPoliticalLastProposalDay[playerid] == GetBrasiliaDayStamp() && !HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Limite diario: cada politico pode criar 1 proposta grande por dia real.");
        return 1;
    }
    if (type == LIFE_POL_PROP_NONE)
    {
        return SendUsage(playerid, "/propostapolitica [obra/orcamento/fiscalizar/contas/cpi] [valor/id] [categoria] [motivo]");
    }
    if (title[0] == 0)
    {
        format(title, 64, "pauta_publica");
    }

    if (type == LIFE_POL_PROP_WORK)
    {
        work = value - 1;
        if (work < 0 || work >= LIFE_PUBLIC_WORK_COUNT)
        {
            return SendUsage(playerid, "/propostapolitica obra [id_obra] voto");
        }
        if (gPublicWorkStatus[work] == LIFE_PUBLIC_WORK_DONE)
        {
            SendClientMessage(playerid, COLOR_ORANGE, "Essa obra ja esta concluida.");
            return 1;
        }
        amount = gPublicWorks[work][publicWorkCost];
        category = gPublicWorks[work][publicWorkCategory];
    }
    else if (type == LIFE_POL_PROP_BUDGET)
    {
        if (amount <= 0 || category < 0 || category >= GOV_EXP_CATEGORIES)
        {
            return SendUsage(playerid, "/propostapolitica orcamento [valor] [infra/saude/seguranca/social/admin/reserva] [motivo]");
        }
    }
    else
    {
        amount = 0;
        if (category < 0 || category >= GOV_EXP_CATEGORIES)
        {
            category = GOV_EXP_ADMIN;
        }
    }

    limit = Life_PoliticalSpendLimit();
    if (amount > 0 && amount > limit)
    {
        Life_MarkPoliticalCorruption(playerid, "proposta_acima_do_limite_economico", amount);
        format(message, sizeof(message), "Proposta bloqueada: limite economico atual e $%d.", limit);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    for (index = 0; index < LIFE_POLITICAL_PROPOSALS; index++)
    {
        if (gPoliticalProposalType[index] == LIFE_POL_PROP_NONE || gPoliticalProposalStatus[index] != LIFE_POL_PROP_OPEN)
        {
            break;
        }
    }
    if (index >= LIFE_POLITICAL_PROPOSALS)
    {
        SendClientMessage(playerid, COLOR_RED, "Limite de propostas politicas atingido. Aguarde aprovacao/cancelamento.");
        return 1;
    }

    GetPlayerNameEx(playerid, name, sizeof(name));
    gPoliticalProposalType[index] = type;
    gPoliticalProposalStatus[index] = LIFE_POL_PROP_OPEN;
    gPoliticalProposalAmount[index] = amount;
    gPoliticalProposalCategory[index] = category;
    gPoliticalProposalWorkId[index] = type == LIFE_POL_PROP_WORK ? value : 0;
    gPoliticalProposalVotes[index] = 0;
    gPoliticalProposalDay[index] = GetBrasiliaDayStamp();
    format(gPoliticalProposalCreator[index], MAX_PLAYER_NAME + 1, "%s", name);
    format(gPoliticalProposalTitle[index], 64, "%s", title);
    gPoliticalProposalVoters[index][0] = 0;
    gPoliticalLastProposalDay[playerid] = GetBrasiliaDayStamp();
    Life_SavePoliticalProposals();

    format(message, sizeof(message), "Proposta politica #%d criada. Outros politicos votam com /votarproposta %d.", index + 1, index + 1);
    SendClientMessageToAll(COLOR_YELLOW, message);
    format(message, sizeof(message), "proposal=%d type=%d amount=%d category=%d title=%s creator=%s", index + 1, type, amount, category, title, name);
    WritePlayerLog(LOG_CONTRACT_FILE, "POLITICAL_PROPOSAL", playerid, message);
    return 1;
}

stock Life_VotePoliticalProposal(playerid, proposalid)
{
    new index = proposalid - 1;
    new name[MAX_PLAYER_NAME + 1];
    new token[36];
    new message[180];

    if (Life_GetPlayerPoliticalOffice(playerid) == -1 && !HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }
    if (index < 0 || index >= LIFE_POLITICAL_PROPOSALS || gPoliticalProposalType[index] == LIFE_POL_PROP_NONE)
    {
        return SendUsage(playerid, "/votarproposta [id]");
    }
    if (gPoliticalProposalStatus[index] != LIFE_POL_PROP_OPEN)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Essa proposta nao esta aberta para votacao.");
        return 1;
    }

    GetPlayerNameEx(playerid, name, sizeof(name));
    if (strcmp(gPoliticalProposalCreator[index], name, true) == 0 && !HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "O autor da proposta nao vota nela. Precisa de outro cargo politico.");
        return 1;
    }
    format(token, sizeof(token), "|%s|", name);
    if (strfind(gPoliticalProposalVoters[index], token, true) != -1)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Voce ja votou nessa proposta.");
        return 1;
    }
    strcat(gPoliticalProposalVoters[index], token, sizeof(gPoliticalProposalVoters[]));
    gPoliticalProposalVotes[index]++;
    Life_SavePoliticalProposals();

    format(message, sizeof(message), "Voto registrado na proposta #%d (%d/%d).", proposalid, gPoliticalProposalVotes[index], LIFE_POLITICAL_VOTE_NEED);
    SendClientMessage(playerid, COLOR_GREEN, message);
    if (gPoliticalProposalVotes[index] >= LIFE_POLITICAL_VOTE_NEED || HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        Life_ApplyPoliticalProposal(playerid, index);
    }
    return 1;
}

stock Life_CancelPoliticalProposal(playerid, proposalid)
{
    new index = proposalid - 1;
    new message[144];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }
    if (index < 0 || index >= LIFE_POLITICAL_PROPOSALS || gPoliticalProposalType[index] == LIFE_POL_PROP_NONE)
    {
        return SendUsage(playerid, "/cancelarproposta [id]");
    }
    gPoliticalProposalStatus[index] = LIFE_POL_PROP_CANCELED;
    Life_SavePoliticalProposals();
    format(message, sizeof(message), "Proposta politica #%d cancelada por admin nivel 5.", proposalid);
    SendClientMessageToAll(COLOR_ORANGE, message);
    WritePlayerLog(LOG_ADMIN_FILE, "POLITICAL_PROPOSAL_CANCEL", playerid, message);
    return 1;
}

stock Life_HandlePolActionDialog(playerid, dialogid, response, listitem, inputtext[])
{
    new index;
    new param[32];
    new param2[32];
    new reason[64];

    if (dialogid == DIALOG_POLITICAL_ACTION_MENU)
    {
        if (!response)
        {
            return Life_ShowPoliticalDutyPanel(playerid);
        }
        switch (listitem)
        {
            case 0: return Life_ShowPoliticalWorkSelect(playerid);
            case 1: return Life_ShowPoliticalBudgetInput(playerid);
            case 2: return Life_ShowPoliticalQuickReason(playerid, LIFE_POL_ACTION_AUDIT);
            case 3: return Life_ShowPoliticalQuickReason(playerid, LIFE_POL_ACTION_ACCOUNT);
            case 4: return Life_ShowPoliticalQuickReason(playerid, LIFE_POL_ACTION_CPI);
            case 5: return Life_ShowPolProposalVoteList(playerid, 0);
            case 6:
            {
                if (HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
                {
                    return Life_ShowPolProposalVoteList(playerid, 1);
                }
                return Life_ShowTransparencyCenter(playerid);
            }
            case 7: return Life_ShowTransparencyCenter(playerid);
        }
        return 1;
    }
    if (dialogid == DIALOG_POLITICAL_WORK_SELECT)
    {
        if (!response)
        {
            return Life_ShowPoliticalActionMenu(playerid);
        }
        return Life_CreatePoliticalProposal(playerid, LIFE_POL_PROP_WORK, listitem + 1, GOV_EXP_INFRA, "obra_publica");
    }
    if (dialogid == DIALOG_POLITICAL_BUDGET_INPUT)
    {
        if (!response)
        {
            return Life_ShowPoliticalActionMenu(playerid);
        }
        index = 0;
        if (!GetNextParam(inputtext, index, param, sizeof(param)) || !GetNextParam(inputtext, index, param2, sizeof(param2)))
        {
            return Life_ShowPoliticalBudgetInput(playerid);
        }
        if (!GetRemainingText(inputtext, index, reason, sizeof(reason)))
        {
            format(reason, sizeof(reason), "%s", param2);
        }
        return Life_CreatePoliticalProposal(playerid, LIFE_POL_PROP_BUDGET, strval(param), Life_ParseGovExpenseCategory(param2), reason);
    }
    if (dialogid == DIALOG_POLITICAL_QUICK_REASON)
    {
        if (!response)
        {
            return Life_ShowPoliticalActionMenu(playerid);
        }
        format(reason, sizeof(reason), "%s", inputtext);
        Cfg_Trim(reason);
        if (reason[0] == 0)
        {
            format(reason, sizeof(reason), "pauta_publica");
        }
        switch (gPoliticalDialogAction[playerid])
        {
            case LIFE_POL_ACTION_AUDIT: return Life_CreatePoliticalProposal(playerid, LIFE_POL_PROP_AUDIT, 0, GOV_EXP_ADMIN, reason);
            case LIFE_POL_ACTION_ACCOUNT: return Life_CreatePoliticalProposal(playerid, LIFE_POL_PROP_ACCOUNT, 0, GOV_EXP_ADMIN, reason);
            case LIFE_POL_ACTION_CPI: return Life_CreatePoliticalProposal(playerid, LIFE_POL_PROP_CPI, 0, GOV_EXP_ADMIN, reason);
        }
        return Life_ShowPoliticalActionMenu(playerid);
    }
    if (dialogid == DIALOG_POLITICAL_PROPOSAL_VOTE)
    {
        if (!response)
        {
            return Life_ShowPoliticalActionMenu(playerid);
        }
        if (listitem < 0)
        {
            return 1;
        }
        index = -1;
        for (new proposal = 0; proposal < LIFE_POLITICAL_PROPOSALS; proposal++)
        {
            if (gPoliticalProposalType[proposal] == LIFE_POL_PROP_NONE || gPoliticalProposalStatus[proposal] != LIFE_POL_PROP_OPEN)
            {
                continue;
            }
            index++;
            if (index == listitem)
            {
                if (gPoliticalDialogAction[playerid] == LIFE_POL_ACTION_CANCEL)
                {
                    return Life_CancelPoliticalProposal(playerid, proposal + 1);
                }
                return Life_VotePoliticalProposal(playerid, proposal + 1);
            }
        }
        SendClientMessage(playerid, COLOR_ORANGE, "Proposta nao encontrada ou ja encerrada.");
        return Life_ShowPoliticalActionMenu(playerid);
    }
    return 0;
}

stock Life_GetBudgetPriorityName(category, output[], size = sizeof(output))
{
    Life_GovExpName(category, output, size);
    return 1;
}

stock Life_NormalizeBudgetPriority(category)
{
    switch (category)
    {
        case GOV_EXP_HEALTH, GOV_EXP_SECURITY, GOV_EXP_SOCIAL: return category;
    }
    return GOV_EXP_INFRA;
}

stock Life_ParseBudgetPriority(input[])
{
    if (strcmp(input, "infra", true) == 0 || strcmp(input, "obra", true) == 0 || strcmp(input, "obras", true) == 0) return GOV_EXP_INFRA;
    if (strcmp(input, "saude", true) == 0 || strcmp(input, "hospital", true) == 0) return GOV_EXP_HEALTH;
    if (strcmp(input, "seguranca", true) == 0 || strcmp(input, "policia", true) == 0) return GOV_EXP_SECURITY;
    if (strcmp(input, "social", true) == 0 || strcmp(input, "educacao", true) == 0) return GOV_EXP_SOCIAL;
    return -1;
}

stock Life_GetPoliticalOfficeName(office, output[], size = sizeof(output))
{
    if (office < 0 || office >= LIFE_POLITICAL_OFFICES)
    {
        format(output, size, "Cargo invalido");
        return 0;
    }
    format(output, size, "%s", gPoliticalOffices[office][politicalOfficeName]);
    return 1;
}

stock Life_GetPoliticalMinLevel(office)
{
    switch (office)
    {
        case 0: return 60;  // Presidente
        case 1: return 55;  // Vice-presidente
        case 2: return 50;  // Governador
        case 3: return 45;  // Vice-governador
        case 7: return 40;  // Senador
        case 4: return 35;  // Prefeito
        case 5: return 30;  // Vice-prefeito
        case 8, 9, 10, 11, 12: return 25;  // Deputados
        case 6, 13, 14, 15, 16, 17: return 20;  // Vereador e parlamentares
    }
    return 20;
}

stock Life_MeetsPoliticalLevel(playerid, office, showError = 1)
{
    new minLevel;
    new officeName[28];
    new message[144];

    if (office < 0 || office >= LIFE_POLITICAL_OFFICES)
    {
        return 0;
    }
    if (HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return 1;
    }

    minLevel = Life_GetPoliticalMinLevel(office);
    if (PlayerInfo[playerid][pLevel] >= minLevel)
    {
        return 1;
    }

    if (showError)
    {
        Life_GetPoliticalOfficeName(office, officeName, sizeof(officeName));
        format(message, sizeof(message), "%s exige nivel %d. Seu nivel atual: %d.", officeName, minLevel, PlayerInfo[playerid][pLevel]);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        SendClientMessage(playerid, COLOR_GRAY, "Cargos politicos liberam por reputacao e level geral do personagem.");
    }
    return 0;
}

stock Life_ParsePoliticalOffice(input[])
{
    new office;
    new officeText[28];

    if (IsNumericString(input))
    {
        office = strval(input) - 1;
        if (office >= 0 && office < LIFE_POLITICAL_OFFICES)
        {
            return office;
        }
    }

    for (office = 0; office < LIFE_POLITICAL_OFFICES; office++)
    {
        Life_GetPoliticalOfficeName(office, officeText, sizeof(officeText));
        if (strcmp(input, officeText, true) == 0)
        {
            return office;
        }
    }
    if (strcmp(input, "presidente", true) == 0) return 0;
    if (strcmp(input, "vicepresidente", true) == 0 || strcmp(input, "vice-presidente", true) == 0) return 1;
    if (strcmp(input, "governador", true) == 0) return 2;
    if (strcmp(input, "vicegovernador", true) == 0 || strcmp(input, "vice-governador", true) == 0) return 3;
    if (strcmp(input, "prefeito", true) == 0) return 4;
    if (strcmp(input, "viceprefeito", true) == 0 || strcmp(input, "vice-prefeito", true) == 0) return 5;
    if (strcmp(input, "vereador", true) == 0) return 6;
    if (strcmp(input, "senador", true) == 0) return 7;
    if (strcmp(input, "deputado", true) == 0 || strcmp(input, "deputado1", true) == 0) return 8;
    if (strcmp(input, "deputado2", true) == 0) return 9;
    if (strcmp(input, "deputado3", true) == 0) return 10;
    if (strcmp(input, "deputado4", true) == 0) return 11;
    if (strcmp(input, "deputado5", true) == 0) return 12;
    if (strcmp(input, "parlamentar", true) == 0 || strcmp(input, "parlamentar1", true) == 0) return 13;
    if (strcmp(input, "parlamentar2", true) == 0) return 14;
    if (strcmp(input, "parlamentar3", true) == 0) return 15;
    if (strcmp(input, "parlamentar4", true) == 0) return 16;
    if (strcmp(input, "parlamentar5", true) == 0) return 17;
    return -1;
}

stock Life_ResetPoliticalElection()
{
    new office;
    new candidate;

    for (office = 0; office < LIFE_POLITICAL_OFFICES; office++)
    {
        gPoliticalCandidateCount[office] = 0;
        for (candidate = 0; candidate < LIFE_POLITICAL_CANDIDATES; candidate++)
        {
            gPoliticalCandidateName[office][candidate][0] = 0;
            gPoliticalCandidateBot[office][candidate] = 0;
            gPoliticalCandidateVotes[office][candidate] = 0;
        }
    }
    for (new playerid = 0; playerid < MAX_PLAYERS; playerid++)
    {
        for (office = 0; office < LIFE_POLITICAL_OFFICES; office++)
        {
            gPoliticalVoted[playerid][office] = 0;
        }
    }
    return 1;
}

stock Life_EnsurePoliticalDefaults()
{
    new office;
    new today = GetBrasiliaDayStamp();

    if (gPoliticalTermStartDay <= 0)
    {
        gPoliticalTermStartDay = today;
    }
    if (gPoliticalTermEndDay <= gPoliticalTermStartDay)
    {
        gPoliticalTermEndDay = gPoliticalTermStartDay + LIFE_POLITICAL_TERM_DAYS;
    }

    for (office = 0; office < LIFE_POLITICAL_OFFICES; office++)
    {
        if (gPoliticalHolderName[office][0] == 0)
        {
            format(gPoliticalHolderName[office], MAX_PLAYER_NAME + 1, "%s", gPoliticalBotNames[office]);
            gPoliticalHolderBot[office] = 1;
        }
        if (gPoliticalCandidateCount[office] <= 0)
        {
            format(gPoliticalCandidateName[office][0], MAX_PLAYER_NAME + 1, "%s", gPoliticalBotNames[office]);
            gPoliticalCandidateBot[office][0] = 1;
            gPoliticalCandidateVotes[office][0] = 0;
            gPoliticalCandidateCount[office] = 1;
        }
    }
    return 1;
}

stock Life_GetPlayerPoliticalOffice(playerid)
{
    new name[MAX_PLAYER_NAME + 1];
    new office;

    if (!IsValidConnectedPlayer(playerid) || !PlayerInfo[playerid][pLogged])
    {
        return -1;
    }

    GetPlayerNameEx(playerid, name, sizeof(name));
    for (office = 0; office < LIFE_POLITICAL_OFFICES; office++)
    {
        if (!gPoliticalHolderBot[office] && strcmp(gPoliticalHolderName[office], name, true) == 0)
        {
            return office;
        }
    }
    return -1;
}

stock Life_SyncPlayerPoliticalCache(playerid, saveNow = 0)
{
    new office;
    new changed;

    if (!IsValidConnectedPlayer(playerid) || !PlayerInfo[playerid][pLogged])
    {
        return 0;
    }

    office = Life_GetPlayerPoliticalOffice(playerid);
    changed = (PlayerInfo[playerid][pPoliticalOffice] != office);

    PlayerInfo[playerid][pPoliticalOffice] = office;
    if (office == -1)
    {
        if (PlayerInfo[playerid][pPoliticalTermStartDay] != 0 || PlayerInfo[playerid][pPoliticalTermEndDay] != 0)
        {
            changed = 1;
        }
        PlayerInfo[playerid][pPoliticalTermStartDay] = 0;
        PlayerInfo[playerid][pPoliticalTermEndDay] = 0;
    }
    else
    {
        if (PlayerInfo[playerid][pPoliticalTermStartDay] != gPoliticalTermStartDay || PlayerInfo[playerid][pPoliticalTermEndDay] != gPoliticalTermEndDay)
        {
            changed = 1;
        }
        PlayerInfo[playerid][pPoliticalTermStartDay] = gPoliticalTermStartDay;
        PlayerInfo[playerid][pPoliticalTermEndDay] = gPoliticalTermEndDay;
    }

    if (changed && saveNow)
    {
        SaveAccountNow(playerid, 0);
    }
    return changed;
}

stock Life_SyncOnlinePoliticalCaches(saveNow = 0)
{
    new playerid;
    new count;

    for (playerid = 0; playerid < MAX_PLAYERS; playerid++)
    {
        if (IsValidConnectedPlayer(playerid) && PlayerInfo[playerid][pLogged])
        {
            count += Life_SyncPlayerPoliticalCache(playerid, saveNow);
        }
    }
    return count;
}

stock Life_IsPoliticalAuthority(playerid)
{
    new name[MAX_PLAYER_NAME + 1];
    new office;

    if (HasAdminLevel(playerid, ADMIN_LEVEL_GAME) || PlayerInfo[playerid][pJob] == JOB_JUIZ)
    {
        return 1;
    }
    if (!IsValidConnectedPlayer(playerid) || !PlayerInfo[playerid][pLogged])
    {
        return 0;
    }

    GetPlayerNameEx(playerid, name, sizeof(name));
    for (office = 0; office < LIFE_POLITICAL_OFFICES; office++)
    {
        if (!gPoliticalHolderBot[office] && strcmp(gPoliticalHolderName[office], name, true) == 0)
        {
            return 1;
        }
    }
    return 0;
}

stock Life_SavePolitics()
{
    new File:file;
    new line[128];
    new office;
    new candidate;

    file = fopen(POLITICS_STATE_FILE, io_write);
    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Sistema politico e prioridades da prefeitura\r\n");
    format(line, sizeof(line), "priority=%d\r\n", gCityBudgetPriority); fwrite(file, line);
    format(line, sizeof(line), "term_start=%d\r\n", gPoliticalTermStartDay); fwrite(file, line);
    format(line, sizeof(line), "term_end=%d\r\n", gPoliticalTermEndDay); fwrite(file, line);
    format(line, sizeof(line), "election_active=%d\r\n", gPoliticalElectionActive); fwrite(file, line);
    for (office = 0; office < LIFE_POLITICAL_OFFICES; office++)
    {
        format(line, sizeof(line), "holder_%d=%s\r\n", office, gPoliticalHolderName[office]); fwrite(file, line);
        format(line, sizeof(line), "holder_bot_%d=%d\r\n", office, gPoliticalHolderBot[office]); fwrite(file, line);
        format(line, sizeof(line), "candidate_count_%d=%d\r\n", office, gPoliticalCandidateCount[office]); fwrite(file, line);
        for (candidate = 0; candidate < LIFE_POLITICAL_CANDIDATES; candidate++)
        {
            format(line, sizeof(line), "candidate_%d_%d=%s\r\n", office, candidate, gPoliticalCandidateName[office][candidate]); fwrite(file, line);
            format(line, sizeof(line), "candidate_bot_%d_%d=%d\r\n", office, candidate, gPoliticalCandidateBot[office][candidate]); fwrite(file, line);
            format(line, sizeof(line), "candidate_votes_%d_%d=%d\r\n", office, candidate, gPoliticalCandidateVotes[office][candidate]); fwrite(file, line);
        }
    }
    fclose(file);
    return 1;
}

stock Life_LoadPolitics()
{
    new File:file;
    new line[128];
    new key[48];
    new value[64];
    new pos;
    new office;
    new candidate;
    new prefix[32];

    gCityBudgetPriority = GOV_EXP_INFRA;
    gPoliticalTermStartDay = GetBrasiliaDayStamp();
    gPoliticalTermEndDay = gPoliticalTermStartDay + LIFE_POLITICAL_TERM_DAYS;
    gPoliticalElectionActive = 0;
    gPoliticalElectionEndTick = 0;
    for (office = 0; office < LIFE_POLITICAL_OFFICES; office++)
    {
        gPoliticalHolderName[office][0] = 0;
        gPoliticalHolderBot[office] = 1;
    }
    Life_ResetPoliticalElection();

    if (!fexist(POLITICS_STATE_FILE))
    {
        Life_EnsurePoliticalDefaults();
        return Life_SavePolitics();
    }

    file = fopen(POLITICS_STATE_FILE, io_read);
    if (!file)
    {
        Life_EnsurePoliticalDefaults();
        return 0;
    }

    while (fread(file, line))
    {
        StripLineEnd(line);
        Cfg_Trim(line);
        if (line[0] == 0 || line[0] == '#')
        {
            continue;
        }
        pos = strfind(line, "=", false);
        if (pos <= 0)
        {
            continue;
        }

        strmid(key, line, 0, pos, sizeof(key));
        strmid(value, line, pos + 1, strlen(line), sizeof(value));
        Cfg_Trim(key);
        Cfg_Trim(value);
        if (strcmp(key, "priority", false) == 0)
        {
            gCityBudgetPriority = Life_NormalizeBudgetPriority(strval(value));
            continue;
        }
        if (strcmp(key, "term_start", false) == 0)
        {
            gPoliticalTermStartDay = strval(value);
            continue;
        }
        if (strcmp(key, "term_end", false) == 0)
        {
            gPoliticalTermEndDay = strval(value);
            continue;
        }
        if (strcmp(key, "election_active", false) == 0)
        {
            gPoliticalElectionActive = strval(value);
            if (gPoliticalElectionActive)
            {
                gPoliticalElectionEndTick = GetTickCount() + LIFE_POLITICAL_ELECTION_MS;
            }
            continue;
        }
        for (office = 0; office < LIFE_POLITICAL_OFFICES; office++)
        {
            format(prefix, sizeof(prefix), "holder_%d", office);
            if (strcmp(key, prefix, false) == 0)
            {
                format(gPoliticalHolderName[office], MAX_PLAYER_NAME + 1, "%s", value);
            }
            format(prefix, sizeof(prefix), "holder_bot_%d", office);
            if (strcmp(key, prefix, false) == 0)
            {
                gPoliticalHolderBot[office] = strval(value);
            }
            format(prefix, sizeof(prefix), "candidate_count_%d", office);
            if (strcmp(key, prefix, false) == 0)
            {
                gPoliticalCandidateCount[office] = strval(value);
                if (gPoliticalCandidateCount[office] < 0) gPoliticalCandidateCount[office] = 0;
                if (gPoliticalCandidateCount[office] > LIFE_POLITICAL_CANDIDATES) gPoliticalCandidateCount[office] = LIFE_POLITICAL_CANDIDATES;
            }
            for (candidate = 0; candidate < LIFE_POLITICAL_CANDIDATES; candidate++)
            {
                format(prefix, sizeof(prefix), "candidate_%d_%d", office, candidate);
                if (strcmp(key, prefix, false) == 0)
                {
                    format(gPoliticalCandidateName[office][candidate], MAX_PLAYER_NAME + 1, "%s", value);
                }
                format(prefix, sizeof(prefix), "candidate_bot_%d_%d", office, candidate);
                if (strcmp(key, prefix, false) == 0)
                {
                    gPoliticalCandidateBot[office][candidate] = strval(value);
                }
                format(prefix, sizeof(prefix), "candidate_votes_%d_%d", office, candidate);
                if (strcmp(key, prefix, false) == 0)
                {
                    gPoliticalCandidateVotes[office][candidate] = strval(value);
                }
            }
        }
    }
    fclose(file);
    Life_EnsurePoliticalDefaults();
    Life_SavePolitics();
    return 1;
}

stock Life_AddPoliticalCandidate(playerid, office)
{
    new name[MAX_PLAYER_NAME + 1];
    new message[144];
    new slot;
    new daysLeft;

    Life_UpdatePoliticalTerm();
    if (!gPoliticalElectionActive)
    {
        daysLeft = gPoliticalTermEndDay - GetBrasiliaDayStamp();
        if (daysLeft < 0) daysLeft = 0;
        format(message, sizeof(message), "Candidaturas fechadas. Nova eleicao automatica em %d dia(s) real(is). Veja /celular > GovBR > Eleicoes.", daysLeft);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        return 1;
    }
    if (office < 0 || office >= LIFE_POLITICAL_OFFICES)
    {
        return SendUsage(playerid, "/candidatar [cargo/id]");
    }
    if (!Life_MeetsPoliticalLevel(playerid, office))
    {
        return 1;
    }

    GetPlayerNameEx(playerid, name, sizeof(name));
    for (slot = 0; slot < gPoliticalCandidateCount[office]; slot++)
    {
        if (strcmp(gPoliticalCandidateName[office][slot], name, true) == 0)
        {
            SendClientMessage(playerid, COLOR_ORANGE, "Voce ja esta concorrendo a esse cargo.");
            return 1;
        }
    }
    if (gPoliticalCandidateCount[office] == 1 && gPoliticalCandidateBot[office][0] && gPoliticalCandidateVotes[office][0] == 0)
    {
        format(gPoliticalCandidateName[office][0], MAX_PLAYER_NAME + 1, "%s", name);
        gPoliticalCandidateBot[office][0] = 0;
        gPoliticalCandidateVotes[office][0] = 0;
        Life_SavePolitics();
        format(message, sizeof(message), "Candidatura registrada para %s. O bot reserva saiu da disputa.", gPoliticalOffices[office][politicalOfficeName]);
        SendClientMessage(playerid, COLOR_GREEN, message);
        return 1;
    }
    if (gPoliticalCandidateCount[office] >= LIFE_POLITICAL_CANDIDATES)
    {
        SendClientMessage(playerid, COLOR_RED, "Esse cargo ja possui candidatos suficientes para esta eleicao.");
        return 1;
    }

    slot = gPoliticalCandidateCount[office];
    format(gPoliticalCandidateName[office][slot], MAX_PLAYER_NAME + 1, "%s", name);
    gPoliticalCandidateBot[office][slot] = 0;
    gPoliticalCandidateVotes[office][slot] = 0;
    gPoliticalCandidateCount[office]++;
    Life_SavePolitics();

    format(message, sizeof(message), "Candidatura registrada para %s. Eleitores votam pelo /celular > GovBR.", gPoliticalOffices[office][politicalOfficeName]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Life_VotePoliticalCandidate(playerid, office, candidate)
{
    new message[160];
    new daysLeft;

    Life_UpdatePoliticalTerm();
    if (!gPoliticalElectionActive)
    {
        daysLeft = gPoliticalTermEndDay - GetBrasiliaDayStamp();
        if (daysLeft < 0) daysLeft = 0;
        format(message, sizeof(message), "Votacao fechada. Nova eleicao automatica em %d dia(s) real(is). Acompanhe pelo GovBR no celular.", daysLeft);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        return 1;
    }
    if (office < 0 || office >= LIFE_POLITICAL_OFFICES || candidate < 0 || candidate >= gPoliticalCandidateCount[office])
    {
        return SendUsage(playerid, "/votar [cargo/id] [candidato/id]");
    }
    if (gPoliticalVoted[playerid][office])
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Voce ja votou nesse cargo nesta sessao eleitoral.");
        return 1;
    }

    gPoliticalCandidateVotes[office][candidate]++;
    gPoliticalVoted[playerid][office] = 1;
    Life_SavePolitics();
    format(message, sizeof(message), "Voto confirmado para %s em %s.", gPoliticalCandidateName[office][candidate], gPoliticalOffices[office][politicalOfficeName]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Life_ShowPoliticalVoteOffices(playerid)
{
    new list[2600];
    new line[160];
    new office;
    new daysLeft;

    Life_UpdatePoliticalTerm();
    if (!gPoliticalElectionActive)
    {
        daysLeft = gPoliticalTermEndDay - GetBrasiliaDayStamp();
        if (daysLeft < 0) daysLeft = 0;
        format(line, sizeof(line), "Votacao fechada. Nova eleicao automatica em %d dia(s) real(is).", daysLeft);
        SendClientMessage(playerid, COLOR_ORANGE, line);
        return Life_ShowPoliticsPanel(playerid);
    }

    format(list, sizeof(list), "Cargo\tStatus\tCandidatos\n");
    for (office = 0; office < LIFE_POLITICAL_OFFICES; office++)
    {
        format(line, sizeof(line), "%d. %s\t%s\t%d candidato(s)\n",
            office + 1,
            gPoliticalOffices[office][politicalOfficeName],
            gPoliticalVoted[playerid][office] ? ("ja votou") : ("votar"),
            gPoliticalCandidateCount[office]
        );
        strcat(list, line, sizeof(list));
    }
    ShowPlayerDialog(playerid, DIALOG_POLITICAL_VOTE_OFFICE, DIALOG_STYLE_TABLIST_HEADERS, "Eleicoes - escolher cargo", list, "Abrir", "Fechar");
    return 1;
}

stock Life_ShowPoliticalMainMenu(playerid)
{
    new list[1200];
    new line[160];
    new daysLeft;
    new minutesLeft;

    Life_UpdatePoliticalTerm();
    Life_SyncPlayerPoliticalCache(playerid, 0);
    format(list, sizeof(list), "Opcao\tStatus\n");
    if (gPoliticalElectionActive)
    {
        minutesLeft = (gPoliticalElectionEndTick - GetTickCount()) / 60000;
        if (minutesLeft < 0) minutesLeft = 0;
        format(line, sizeof(line), "Eleicoes e candidatos\tABERTA | resultado em %d min\n", minutesLeft);
    }
    else
    {
        daysLeft = gPoliticalTermEndDay - GetBrasiliaDayStamp();
        if (daysLeft < 0) daysLeft = 0;
        format(line, sizeof(line), "Eleicoes e candidatos\tFECHADA | nova em %d dia(s)\n", daysLeft);
    }
    strcat(list, line, sizeof(list));
    strcat(list, "Votar\tEscolher cargo e candidato\n", sizeof(list));
    strcat(list, "Candidatar\tEscolher cargo pelo menu\n", sizeof(list));
    strcat(list, "Central do politico\tAcoes, cargos atuais, propostas e transparencia\n", sizeof(list));
    strcat(list, "Acoes politicas\tCriar proposta, votar, fiscalizar, CPI\n", sizeof(list));
    strcat(list, "Central da transparencia\tCofre publico, receitas e gastos\n", sizeof(list));
    if (HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        strcat(list, "Admin eleicao\tAbrir, fechar/apurar ou limpar politica\n", sizeof(list));
    }
    ShowPlayerDialog(playerid, DIALOG_POLITICAL_MAIN_MENU, DIALOG_STYLE_TABLIST_HEADERS, "Politica", list, "Abrir", "Fechar");
    return 1;
}

stock Life_ShowPolCandidacyOffices(playerid)
{
    new list[2600];
    new line[160];
    new office;
    new daysLeft;

    Life_UpdatePoliticalTerm();
    if (!gPoliticalElectionActive)
    {
        daysLeft = gPoliticalTermEndDay - GetBrasiliaDayStamp();
        if (daysLeft < 0) daysLeft = 0;
        format(line, sizeof(line), "Candidaturas fechadas. Nova eleicao em %d dia(s) real(is).", daysLeft);
        SendClientMessage(playerid, COLOR_ORANGE, line);
        return Life_ShowPoliticalMainMenu(playerid);
    }
    format(list, sizeof(list), "Cargo\tNivel\tVagas\n");
    for (office = 0; office < LIFE_POLITICAL_OFFICES; office++)
    {
        format(line, sizeof(line), "%d. %s\t%d+\t%d/%d\n",
            office + 1,
            gPoliticalOffices[office][politicalOfficeName],
            Life_GetPoliticalMinLevel(office),
            gPoliticalCandidateCount[office],
            LIFE_POLITICAL_CANDIDATES
        );
        strcat(list, line, sizeof(list));
    }
    ShowPlayerDialog(playerid, DIALOG_POLITICAL_CANDIDATE_OFFICE, DIALOG_STYLE_TABLIST_HEADERS, "Candidatar - escolher cargo", list, "Candidatar", "Voltar");
    return 1;
}

stock Life_ShowPoliticalAdminMenu(playerid)
{
    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }
    ShowPlayerDialog(playerid, DIALOG_POLITICAL_ADMIN_MENU, DIALOG_STYLE_LIST, "Politica - Admin nivel 5", "Status da eleicao\nAbrir eleicao\nFechar/apurar eleicao\nLimpar cargos politicos", "Executar", "Voltar");
    return 1;
}

stock Life_ShowPolVoteCandidates(playerid, office)
{
    new list[1200];
    new line[160];
    new candidate;

    Life_UpdatePoliticalTerm();
    if (!gPoliticalElectionActive)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Votacao fechada no momento.");
        return Life_ShowPoliticsPanel(playerid);
    }
    if (office < 0 || office >= LIFE_POLITICAL_OFFICES)
    {
        return Life_ShowPoliticalVoteOffices(playerid);
    }
    if (gPoliticalVoted[playerid][office])
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Voce ja votou nesse cargo nesta sessao eleitoral.");
        return Life_ShowPoliticalVoteOffices(playerid);
    }
    if (gPoliticalCandidateCount[office] <= 0)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Esse cargo ainda nao possui candidatos.");
        return Life_ShowPoliticalVoteOffices(playerid);
    }

    gPoliticalVoteOffice[playerid] = office;
    format(list, sizeof(list), "Candidato\tVotos atuais\tTipo\n");
    for (candidate = 0; candidate < gPoliticalCandidateCount[office]; candidate++)
    {
        format(line, sizeof(line), "%d. %s\t%d voto(s)\t%s\n",
            candidate + 1,
            gPoliticalCandidateName[office][candidate],
            gPoliticalCandidateVotes[office][candidate],
            gPoliticalCandidateBot[office][candidate] ? ("BOT") : ("PLAYER")
        );
        strcat(list, line, sizeof(list));
    }
    format(line, sizeof(line), "Eleicoes - votar em %s", gPoliticalOffices[office][politicalOfficeName]);
    ShowPlayerDialog(playerid, DIALOG_POLITICAL_VOTE_CANDIDATE, DIALOG_STYLE_TABLIST_HEADERS, line, list, "Votar", "Voltar");
    return 1;
}

stock Life_HandlePoliticalVoteDialog(playerid, dialogid, response, listitem)
{
    new office;

    if (dialogid == DIALOG_POLITICAL_VOTE_OFFICE)
    {
        if (!response)
        {
            return 1;
        }
        return Life_ShowPolVoteCandidates(playerid, listitem);
    }
    if (dialogid == DIALOG_POLITICAL_VOTE_CANDIDATE)
    {
        office = gPoliticalVoteOffice[playerid];
        if (!response)
        {
            return Life_ShowPoliticalVoteOffices(playerid);
        }
        return Life_VotePoliticalCandidate(playerid, office, listitem);
    }
    return 0;
}

stock Life_HandlePoliticalMainDialog(playerid, dialogid, response, listitem)
{
    if (dialogid == DIALOG_POLITICAL_MAIN_MENU)
    {
        if (!response)
        {
            return 1;
        }
        switch (listitem)
        {
            case 0: return Life_ShowPoliticsPanel(playerid);
            case 1: return Life_ShowPoliticalVoteOffices(playerid);
            case 2: return Life_ShowPolCandidacyOffices(playerid);
            case 3: return Life_ShowPoliticalDutyPanel(playerid);
            case 4: return Life_ShowPoliticalActionMenu(playerid);
            case 5: return Life_ShowTransparencyCenter(playerid);
            case 6: return Life_ShowPoliticalAdminMenu(playerid);
        }
        return 1;
    }
    if (dialogid == DIALOG_POLITICAL_CANDIDATE_OFFICE)
    {
        if (!response)
        {
            return Life_ShowPoliticalMainMenu(playerid);
        }
        return Life_AddPoliticalCandidate(playerid, listitem);
    }
    if (dialogid == DIALOG_POLITICAL_ADMIN_MENU)
    {
        if (!response)
        {
            return Life_ShowPoliticalMainMenu(playerid);
        }
        switch (listitem)
        {
            case 0: return Life_AdminElectionCommand(playerid, "status");
            case 1: return Life_AdminOpenPoliticalElection(playerid);
            case 2: return Life_AdminCloseElection(playerid);
            case 3: return Life_AdminClearPoliticalOffices(playerid);
        }
        return 1;
    }
    return 0;
}

stock Life_CloseElectionCore()
{
    new office;
    new candidate;
    new winner;
    new bestVotes;
    new totalVotes;

    Life_EnsurePoliticalDefaults();
    for (office = 0; office < LIFE_POLITICAL_OFFICES; office++)
    {
        winner = 0;
        bestVotes = -1;
        totalVotes = 0;
        for (candidate = 0; candidate < gPoliticalCandidateCount[office]; candidate++)
        {
            totalVotes += gPoliticalCandidateVotes[office][candidate];
            if (gPoliticalCandidateVotes[office][candidate] > bestVotes)
            {
                bestVotes = gPoliticalCandidateVotes[office][candidate];
                winner = candidate;
            }
        }
        if (totalVotes <= 0 && gPoliticalCandidateCount[office] > 1)
        {
            winner = random(gPoliticalCandidateCount[office]);
        }
        format(gPoliticalHolderName[office], MAX_PLAYER_NAME + 1, "%s", gPoliticalCandidateName[office][winner]);
        gPoliticalHolderBot[office] = gPoliticalCandidateBot[office][winner];
    }

    gPoliticalTermStartDay = GetBrasiliaDayStamp();
    gPoliticalTermEndDay = gPoliticalTermStartDay + LIFE_POLITICAL_TERM_DAYS;
    Life_ResetPoliticalElection();
    Life_EnsurePoliticalDefaults();
    Life_SavePolitics();
    Life_SyncOnlinePoliticalCaches(1);
    return 1;
}

stock Life_StartPoliticalElection()
{
    if (gPoliticalElectionActive)
    {
        return 1;
    }

    gPoliticalElectionActive = 1;
    gPoliticalElectionEndTick = GetTickCount() + LIFE_POLITICAL_ELECTION_MS;
    Life_EnsurePoliticalDefaults();
    Life_SavePolitics();
    return 1;
}

stock Life_AdminOpenPoliticalElection(playerid)
{
    new message[144];

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }
    Life_EnsurePoliticalDefaults();
    if (gPoliticalElectionActive)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "A eleicao ja esta aberta.");
        return 1;
    }

    gPoliticalElectionActive = 1;
    gPoliticalElectionEndTick = GetTickCount() + LIFE_POLITICAL_ELECTION_MS;
    Life_SavePolitics();
    format(message, sizeof(message), "Eleicao aberta manualmente por admin nivel 5. Resultado automatico em %d minuto(s).", LIFE_POLITICAL_ELECTION_MS / 60000);
    SendClientMessageToAll(COLOR_YELLOW, message);
    return 1;
}

stock Life_AdminCloseElection(playerid)
{
    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }
    Life_EnsurePoliticalDefaults();
    if (!gPoliticalElectionActive)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "A eleicao ja esta fechada.");
        return 1;
    }

    gPoliticalElectionActive = 0;
    gPoliticalElectionEndTick = 0;
    Life_CloseElectionCore();
    SendClientMessageToAll(COLOR_YELLOW, "Eleicao fechada manualmente por admin nivel 5. Vencedores atualizados.");
    return 1;
}

stock Life_AdminClearPoliticalOffices(playerid)
{
    new office;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }

    for (office = 0; office < LIFE_POLITICAL_OFFICES; office++)
    {
        format(gPoliticalHolderName[office], MAX_PLAYER_NAME + 1, "%s", gPoliticalBotNames[office]);
        gPoliticalHolderBot[office] = 1;
    }
    gPoliticalElectionActive = 0;
    gPoliticalElectionEndTick = 0;
    gPoliticalTermStartDay = GetBrasiliaDayStamp();
    gPoliticalTermEndDay = gPoliticalTermStartDay + LIFE_POLITICAL_TERM_DAYS;
    Life_ResetPoliticalElection();
    Life_EnsurePoliticalDefaults();
    Life_SavePolitics();
    Life_SyncOnlinePoliticalCaches(1);
    SendClientMessageToAll(COLOR_YELLOW, "Cargos politicos foram limpos por admin nivel 5. Bots assumiram ate a proxima eleicao.");
    return 1;
}

stock Life_AdminElectionCommand(playerid, action[])
{
    new status[128];
    new daysLeft;
    new minutesLeft;

    if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
    {
        return SendNoPermission(playerid);
    }
    if (strcmp(action, "abrir", true) == 0 || strcmp(action, "open", true) == 0)
    {
        return Life_AdminOpenPoliticalElection(playerid);
    }
    if (strcmp(action, "fechar", true) == 0 || strcmp(action, "close", true) == 0 || strcmp(action, "apurar", true) == 0)
    {
        return Life_AdminCloseElection(playerid);
    }
    if (strcmp(action, "limpar", true) == 0 || strcmp(action, "resetar", true) == 0 || strcmp(action, "reset", true) == 0)
    {
        return Life_AdminClearPoliticalOffices(playerid);
    }
    if (strcmp(action, "status", true) == 0)
    {
        Life_UpdatePoliticalTerm();
        if (gPoliticalElectionActive)
        {
            minutesLeft = (gPoliticalElectionEndTick - GetTickCount()) / 60000;
            if (minutesLeft < 0) minutesLeft = 0;
            format(status, sizeof(status), "Eleicao ABERTA. Resultado em %d minuto(s).", minutesLeft);
        }
        else
        {
            daysLeft = gPoliticalTermEndDay - GetBrasiliaDayStamp();
            if (daysLeft < 0) daysLeft = 0;
            format(status, sizeof(status), "Eleicao FECHADA. Proxima automatica em %d dia(s).", daysLeft);
        }
        SendClientMessage(playerid, COLOR_YELLOW, status);
        return 1;
    }
    SendUsage(playerid, "/admeleicao [abrir/fechar/limpar/status]");
    return 1;
}

stock Life_RegBotPolDecision(office, decision[], impact[], category)
{
    new message[192];
    new logLine[220];

    if (office < 0 || office >= LIFE_POLITICAL_OFFICES || !gPoliticalHolderBot[office])
    {
        return 0;
    }

    if (category >= 0 && category < GOV_EXP_CATEGORIES)
    {
        gCityBudgetPriority = category;
    }

    format(gGovernmentLastDecisionOffice, sizeof(gGovernmentLastDecisionOffice), "%s", gPoliticalOffices[office][politicalOfficeName]);
    format(gGovernmentLastDecisionText, sizeof(gGovernmentLastDecisionText), "%s", decision);
    format(gGovernmentLastDecisionImpact, sizeof(gGovernmentLastDecisionImpact), "%s", impact);
    gGovernmentLastDecisionDay = GetBrasiliaDayStamp();
    Life_SaveGovernmentRevenue();
    Life_SavePolitics();

    format(message, sizeof(message), "[Politica] %s %s decidiu: %s. Impacto: %s", gPoliticalOffices[office][politicalOfficeName], gPoliticalHolderName[office], decision, impact);
    SendClientMessageToAll(COLOR_YELLOW, message);
    format(logLine, sizeof(logLine), "office=%s holder=%s decision=%s impact=%s priority=%d", gPoliticalOffices[office][politicalOfficeName], gPoliticalHolderName[office], decision, impact, gCityBudgetPriority);
    WriteServerLog(LOG_CONTRACT_FILE, "BOT_POLITICAL_DECISION", logLine);
    return 1;
}

stock Life_RunBotPoliticalDecision(office)
{
    new option = random(3);

    switch (office)
    {
        case 0, 1:
        {
            switch (option)
            {
                case 0: return Life_RegBotPolDecision(office, "priorizar reserva publica e estabilidade do cofre", "mais controle antes de liberar gastos grandes", GOV_EXP_RESERVE);
                case 1: return Life_RegBotPolDecision(office, "pedir relatorio nacional de gastos", "transparencia reforcada na central publica", GOV_EXP_ADMIN);
                default: return Life_RegBotPolDecision(office, "recomendar equilibrio entre areas essenciais", "prefeitura mantem despesas sob limite economico", GOV_EXP_ADMIN);
            }
        }
        case 2, 3:
        {
            switch (option)
            {
                case 0: return Life_RegBotPolDecision(office, "priorizar manutencao das rodovias e pedagios", "infraestrutura ganha prioridade no planejamento", GOV_EXP_INFRA);
                case 1: return Life_RegBotPolDecision(office, "cobrar fiscalizacao de cargas e rotas", "PRF e logistica recebem atencao administrativa", GOV_EXP_SECURITY);
                default: return Life_RegBotPolDecision(office, "incentivar contratos de abastecimento regional", "mercados e empresas ficam no radar da prefeitura", GOV_EXP_INFRA);
            }
        }
        case 4, 5:
        {
            switch (option)
            {
                case 0: return Life_RegBotPolDecision(office, "priorizar obras municipais pendentes", "obras publicas aparecem como foco do governo local", GOV_EXP_INFRA);
                case 1: return Life_RegBotPolDecision(office, "reforcar acolhimento de novatos e servicos civis", "area social vira prioridade temporaria", GOV_EXP_SOCIAL);
                default: return Life_RegBotPolDecision(office, "pedir revisao dos gastos da prefeitura", "central da transparencia destaca controle publico", GOV_EXP_ADMIN);
            }
        }
        case 6:
        {
            switch (option)
            {
                case 0: return Life_RegBotPolDecision(office, "abrir fiscalizacao municipal sobre contratos", "mais controle RP sobre gastos e obras", GOV_EXP_ADMIN);
                case 1: return Life_RegBotPolDecision(office, "cobrar melhorias de atendimento ao cidadao", "servicos sociais ficam em destaque", GOV_EXP_SOCIAL);
                default: return Life_RegBotPolDecision(office, "solicitar vistoria em obras e pedagios", "infraestrutura sera acompanhada por fiscalizacao", GOV_EXP_INFRA);
            }
        }
        case 7:
        {
            switch (option)
            {
                case 0: return Life_RegBotPolDecision(office, "revisar seguranca publica e PRF", "seguranca ganha prioridade administrativa", GOV_EXP_SECURITY);
                case 1: return Life_RegBotPolDecision(office, "pedir prestacao de contas do cofre publico", "transparencia reforcada sem gasto automatico", GOV_EXP_ADMIN);
                default: return Life_RegBotPolDecision(office, "recomendar auditoria em multas e impostos", "economia publica fica sob observacao", GOV_EXP_ADMIN);
            }
        }
        case 8 .. 12:
        {
            switch (option)
            {
                case 0: return Life_RegBotPolDecision(office, "propor emenda de saude preventiva", "saude ganha prioridade no planejamento", GOV_EXP_HEALTH);
                case 1: return Life_RegBotPolDecision(office, "propor pauta de seguranca nas rodovias", "seguranca e PRF entram em foco", GOV_EXP_SECURITY);
                default: return Life_RegBotPolDecision(office, "propor melhoria em infraestrutura urbana", "infraestrutura passa a ser prioridade", GOV_EXP_INFRA);
            }
        }
        default:
        {
            switch (option)
            {
                case 0: return Life_RegBotPolDecision(office, "abrir pauta de transparencia publica", "decisoes ficam registradas para consulta", GOV_EXP_ADMIN);
                case 1: return Life_RegBotPolDecision(office, "acompanhar demandas sociais da cidade", "area social ganha atencao temporaria", GOV_EXP_SOCIAL);
                default: return Life_RegBotPolDecision(office, "solicitar fiscalizacao de servicos essenciais", "servicos publicos entram em monitoramento", GOV_EXP_ADMIN);
            }
        }
    }
    return 0;
}

public Life_UpdatePoliticalBots()
{
    new botOffices[LIFE_POLITICAL_OFFICES];
    new count;
    new office;

    Life_UpdatePoliticalTerm();
    if (gPoliticalElectionActive)
    {
        return 1;
    }

    for (office = 0; office < LIFE_POLITICAL_OFFICES; office++)
    {
        if (gPoliticalHolderBot[office])
        {
            botOffices[count] = office;
            count++;
        }
    }
    if (count <= 0)
    {
        return 1;
    }
    return Life_RunBotPoliticalDecision(botOffices[random(count)]);
}

stock Life_UpdatePoliticalTerm()
{
    new today = GetBrasiliaDayStamp();

    Life_EnsurePoliticalDefaults();
    if (gPoliticalElectionActive)
    {
        if (gPoliticalElectionEndTick <= 0)
        {
            gPoliticalElectionEndTick = GetTickCount() + LIFE_POLITICAL_ELECTION_MS;
        }
        if (GetTickCount() >= gPoliticalElectionEndTick)
        {
            gPoliticalElectionActive = 0;
            gPoliticalElectionEndTick = 0;
            Life_CloseElectionCore();
        }
        return 1;
    }
    if (today >= gPoliticalTermEndDay)
    {
        Life_StartPoliticalElection();
    }
    return 1;
}

stock Life_ClosePoliticalElection(playerid)
{
    new message[180];
    new daysLeft;

    if (!Life_IsPoliticalAuthority(playerid))
    {
        return SendNoPermission(playerid);
    }
    Life_UpdatePoliticalTerm();
    daysLeft = gPoliticalTermEndDay - GetBrasiliaDayStamp();
    if (!gPoliticalElectionActive && daysLeft > 0 && !HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
    {
        format(message, sizeof(message), "Mandato em andamento. Nova eleicao automatica em %d dia(s) real(is).", daysLeft);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        return 1;
    }

    gPoliticalElectionActive = 0;
    gPoliticalElectionEndTick = 0;
    Life_CloseElectionCore();
    format(message, sizeof(message), "Eleicao encerrada. Se nao houve votos em algum cargo, o sistema sorteou entre os candidatos.");
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Life_SetBudgetPriority(playerid, category)
{
    new message[144];
    new categoryName[32];

    Life_UpdatePoliticalTerm();
    if (!Life_IsPoliticalAuthority(playerid))
    {
        return SendNoPermission(playerid);
    }
    category = Life_NormalizeBudgetPriority(category);
    gCityBudgetPriority = category;
    Life_SavePolitics();
    Life_GetBudgetPriorityName(category, categoryName, sizeof(categoryName));
    format(message, sizeof(message), "Prioridade da prefeitura atualizada para %s.", categoryName);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Life_ElectionBar(value, total, output[], size = sizeof(output))
{
    new filled;

    if (total <= 0)
    {
        filled = 0;
    }
    else
    {
        filled = (value * 10) / total;
    }
    if (filled < 0) filled = 0;
    if (filled > 10) filled = 10;

    switch (filled)
    {
        case 0: format(output, size, "..........");
        case 1: format(output, size, "|.........");
        case 2: format(output, size, "||........");
        case 3: format(output, size, "|||.......");
        case 4: format(output, size, "||||......");
        case 5: format(output, size, "|||||.....");
        case 6: format(output, size, "||||||....");
        case 7: format(output, size, "|||||||...");
        case 8: format(output, size, "||||||||..");
        case 9: format(output, size, "|||||||||.");
        default: format(output, size, "||||||||||");
    }
    return 1;
}

stock Life_FormatElectionHud(title[], titleSize, lineA[], lineASize, lineB[], lineBSize, lineC[], lineCSize)
{
    new office;
    new candidate;
    new totalVotes;
    new minutesLeft;
    new bar[16];
    new percent;

    Life_UpdatePoliticalTerm();
    if (!gPoliticalElectionActive)
    {
        return 0;
    }

    office = (GetTickCount() / 8000) % LIFE_POLITICAL_OFFICES;
    for (candidate = 0; candidate < gPoliticalCandidateCount[office]; candidate++)
    {
        totalVotes += gPoliticalCandidateVotes[office][candidate];
    }
    minutesLeft = (gPoliticalElectionEndTick - GetTickCount()) / 60000;
    if (minutesLeft < 0)
    {
        minutesLeft = 0;
    }
    format(title, titleSize, "ELEICAO %02dm | %s", minutesLeft, gPoliticalOffices[office][politicalOfficeName]);

    for (candidate = 0; candidate < 3; candidate++)
    {
        if (candidate < gPoliticalCandidateCount[office])
        {
            percent = totalVotes > 0 ? (gPoliticalCandidateVotes[office][candidate] * 100) / totalVotes : 0;
            Life_ElectionBar(gPoliticalCandidateVotes[office][candidate], totalVotes, bar, sizeof(bar));
            if (candidate == 0) format(lineA, lineASize, "A %s [%s] %d%%", gPoliticalCandidateName[office][candidate], bar, percent);
            if (candidate == 1) format(lineB, lineBSize, "B %s [%s] %d%%", gPoliticalCandidateName[office][candidate], bar, percent);
            if (candidate == 2) format(lineC, lineCSize, "C %s [%s] %d%%", gPoliticalCandidateName[office][candidate], bar, percent);
        }
        else
        {
            if (candidate == 0) format(lineA, lineASize, "A sem candidato [..........] 0%%");
            if (candidate == 1) format(lineB, lineBSize, "B sem candidato [..........] 0%%");
            if (candidate == 2) format(lineC, lineCSize, "C sem candidato [..........] 0%%");
        }
    }
    return 1;
}

stock Life_FormatPoliticsPhoneLabel(output[], size = sizeof(output))
{
    new daysLeft;
    new minutesLeft;

    Life_UpdatePoliticalTerm();
    if (gPoliticalElectionActive)
    {
        minutesLeft = (gPoliticalElectionEndTick - GetTickCount()) / 60000;
        if (minutesLeft < 0) minutesLeft = 0;
        format(output, size, "Eleicoes ABERTAS - %d min", minutesLeft);
        return 1;
    }

    daysLeft = gPoliticalTermEndDay - GetBrasiliaDayStamp();
    if (daysLeft < 0) daysLeft = 0;
    format(output, size, "Eleicoes fechadas - %d dia(s)", daysLeft);
    return 1;
}

stock Life_ShowPoliticsPanel(playerid)
{
    new list[4096];
    new line[180];
    new office;
    new candidate;
    new holderType[16];
    new today = GetBrasiliaDayStamp();
    new daysLeft;

    Life_UpdatePoliticalTerm();
    today = GetBrasiliaDayStamp();
    daysLeft = gPoliticalTermEndDay - today;
    if (daysLeft < 0)
    {
        daysLeft = 0;
    }

    format(list, sizeof(list), "Cargo\tAtual\tCandidatos/Votos\n");
    if (gPoliticalElectionActive)
    {
        format(line, sizeof(line), "Status\tELEICAO ABERTA\tResultado em %d minuto(s), HUD eleitoral ativo\n", (gPoliticalElectionEndTick - GetTickCount()) / 60000);
        strcat(list, line, sizeof(list));
        strcat(list, "Candidatura\tAberta pelo celular GovBR\tUse /politica > Candidatar\n", sizeof(list));
        strcat(list, "Votacao\tAberta pelo celular GovBR\tUse /politica > Votar\n", sizeof(list));
    }
    else
    {
        format(line, sizeof(line), "Status\tELEICAO FECHADA\tNova eleicao em %d dia(s) real(is)\n", daysLeft);
        strcat(list, line, sizeof(list));
        format(line, sizeof(line), "Mandato\t%d dia(s) restante(s)\tEleicoes automaticas a cada %d dias reais\n", daysLeft, LIFE_POLITICAL_TERM_DAYS);
        strcat(list, line, sizeof(list));
        strcat(list, "Candidatura\tFechada agora\tAbra /celular > GovBR > Eleicoes na epoca eleitoral\n", sizeof(list));
        strcat(list, "Votacao\tFechada agora\tCandidatos e votos so contam com eleicao aberta\n", sizeof(list));
    }
    strcat(list, "Onde entrar\t/celular > GovBR > Eleicoes e politica\tTambem funciona por /politica\n", sizeof(list));
    Life_EnsurePoliticalDefaults();
    format(holderType, sizeof(holderType), gPoliticalHolderBot[0] ? ("BOT") : ("PLAYER"));
    format(line, sizeof(line), "Presidente\t%s (%s)\tMandato nacional\n", gPoliticalHolderName[0], holderType);
    strcat(list, line, sizeof(list));
    format(holderType, sizeof(holderType), gPoliticalHolderBot[2] ? ("BOT") : ("PLAYER"));
    format(line, sizeof(line), "Governador\t%s (%s)\tGestao estadual e infraestrutura\n", gPoliticalHolderName[2], holderType);
    strcat(list, line, sizeof(list));
    format(holderType, sizeof(holderType), gPoliticalHolderBot[4] ? ("BOT") : ("PLAYER"));
    format(line, sizeof(line), "Prefeito\t%s (%s)\tPrefeitura, obras e social\n", gPoliticalHolderName[4], holderType);
    strcat(list, line, sizeof(list));
    format(holderType, sizeof(holderType), gPoliticalHolderBot[6] ? ("BOT") : ("PLAYER"));
    format(line, sizeof(line), "Vereador\t%s (%s)\tFiscalizacao e propostas municipais\n", gPoliticalHolderName[6], holderType);
    strcat(list, line, sizeof(list));
    for (office = 0; office < LIFE_POLITICAL_OFFICES; office++)
    {
        format(holderType, sizeof(holderType), gPoliticalHolderBot[office] ? ("BOT") : ("PLAYER"));
        format(line, sizeof(line), "%d. %s\t%s (%s)\t", office + 1, gPoliticalOffices[office][politicalOfficeName], gPoliticalHolderName[office], holderType);
        strcat(list, line, sizeof(list));
        for (candidate = 0; candidate < gPoliticalCandidateCount[office]; candidate++)
        {
            format(line, sizeof(line), "%d:%s %dv ", candidate + 1, gPoliticalCandidateName[office][candidate], gPoliticalCandidateVotes[office][candidate]);
            strcat(list, line, sizeof(list));
        }
        strcat(list, "\n", sizeof(list));
    }
    strcat(list, "Como usar\t/politica\tMenu unico para candidatura, voto, propostas e administracao\n", sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_POLITICS_PANEL, DIALOG_STYLE_TABLIST_HEADERS, "GovBR - Eleicoes e cargos politicos", list, "Fechar", "");
    return 1;
}

stock Life_ShowCityHallPanel(playerid)
{
    new list[2200];
    new line[180];
    new name[32];
    new holderType[16];
    new daysLeft;

    Life_UpdatePoliticalTerm();
    daysLeft = gPoliticalTermEndDay - GetBrasiliaDayStamp();
    if (daysLeft < 0)
    {
        daysLeft = 0;
    }
    Life_GetBudgetPriorityName(gCityBudgetPriority, name, sizeof(name));
    format(list, sizeof(list), "Area\tStatus\tImpacto\n");
    format(line, sizeof(line), "Cofre publico\t$%d disponivel\tGastos registrados: $%d\n", gGovernmentRevenue, gGovernmentExpense);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Prioridade atual\t%s\tMuda com /prioridade [infra/saude/seguranca/social]\n", name);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Obras publicas\t%d/%d concluidas\tUse /obraspublicas e /financiarobra [id]\n", Life_CountPublicWorksDone(), LIFE_PUBLIC_WORK_COUNT);
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Infraestrutura\t+%d%%\tRuas, pedagios, docas e manutencao urbana\n", Life_GetPublicWorkBonus(GOV_EXP_INFRA));
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Saude\t+%d%%\tChamados medicos e hospital\n", Life_GetPublicWorkBonus(GOV_EXP_HEALTH));
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Seguranca\t+%d%%\tPolicia, PRF, delegacia e fiscalizacao\n", Life_GetPublicWorkBonus(GOV_EXP_SECURITY));
    strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Social\t+%d%%\tNovatos, praca e acolhimento\n", Life_GetPublicWorkBonus(GOV_EXP_SOCIAL));
    strcat(list, line, sizeof(list));
    format(holderType, sizeof(holderType), gPoliticalHolderBot[0] ? ("BOT") : ("PLAYER"));
    format(line, sizeof(line), "Presidente\t%s (%s)\tMandato: %d dia(s) restante(s)\n", gPoliticalHolderName[0], holderType, daysLeft);
    strcat(list, line, sizeof(list));
    format(holderType, sizeof(holderType), gPoliticalHolderBot[2] ? ("BOT") : ("PLAYER"));
    format(line, sizeof(line), "Governador\t%s (%s)\tInfraestrutura e estado\n", gPoliticalHolderName[2], holderType);
    strcat(list, line, sizeof(list));
    format(holderType, sizeof(holderType), gPoliticalHolderBot[4] ? ("BOT") : ("PLAYER"));
    format(line, sizeof(line), "Prefeito\t%s (%s)\tPrefeitura e obras municipais\n", gPoliticalHolderName[4], holderType);
    strcat(list, line, sizeof(list));
    format(holderType, sizeof(holderType), gPoliticalHolderBot[6] ? ("BOT") : ("PLAYER"));
    format(line, sizeof(line), "Vereador\t%s (%s)\tFiscalizacao e propostas locais\n", gPoliticalHolderName[6], holderType);
    strcat(list, line, sizeof(list));
    strcat(list, "Politica\t/politica\tMenu completo de eleicoes, cargos e propostas\n", sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_CITYHALL_PANEL, DIALOG_STYLE_TABLIST_HEADERS, "Painel da Prefeitura", list, "Fechar", "");
    return 1;
}

stock Life_SaveMarketStock()
{
    new File:file;
    new line[96];
    new index;

    file = fopen(MARKET_STOCK_FILE, io_write);
    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Estoque autonomo dos mercados/lojas\r\n");
    for (index = 0; index < LIFE_MARKET_ITEMS; index++)
    {
        format(line, sizeof(line), "%s=%d\r\n", gMarketKeys[index], gMarketStock[index]);
        fwrite(file, line);
    }
    fclose(file);
    return 1;
}

stock Life_GetMarketStock(item)
{
    if (item < 0 || item >= LIFE_MARKET_ITEMS)
    {
        return 0;
    }
    return gMarketStock[item];
}

stock Life_TakeMarketStock(item, amount)
{
    if (item < 0 || item >= LIFE_MARKET_ITEMS || amount <= 0)
    {
        return 0;
    }
    if (gMarketStock[item] < amount)
    {
        return 0;
    }
    gMarketStock[item] -= amount;
    if (gMarketStock[item] < 0)
    {
        gMarketStock[item] = 0;
    }
    return 1;
}

stock Life_LoadMarketStock()
{
    new File:file;
    new line[96];
    new key[32];
    new value[48];
    new pos;
    new index;

    for (index = 0; index < LIFE_MARKET_ITEMS; index++)
    {
        gMarketStock[index] = gMarketDefaults[index];
    }

    if (!fexist(MARKET_STOCK_FILE))
    {
        return Life_SaveMarketStock();
    }

    file = fopen(MARKET_STOCK_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (fread(file, line))
    {
        StripLineEnd(line);
        Cfg_Trim(line);
        if (line[0] == 0 || line[0] == '#')
        {
            continue;
        }

        pos = strfind(line, "=", false);
        if (pos <= 0)
        {
            continue;
        }

        strmid(key, line, 0, pos, sizeof(key));
        strmid(value, line, pos + 1, strlen(line), sizeof(value));
        Cfg_Trim(key);
        Cfg_Trim(value);
        for (index = 0; index < LIFE_MARKET_ITEMS; index++)
        {
            if (strcmp(key, gMarketKeys[index], false) == 0)
            {
                gMarketStock[index] = strval(value);
                if (gMarketStock[index] < 0)
                {
                    gMarketStock[index] = 0;
                }
            }
        }
    }
    fclose(file);
    return 1;
}

stock Life_Init()
{
    new playerid;
    new dock;
    new callid;

    Life_LoadMarketStock();
    Life_LoadGovernmentRevenue();
    Life_LoadPublicWorks();
    Life_LoadPolitics();
    Life_LoadPoliticalProposals();
    Life_UpdatePoliticalTerm();
    gCityEventType = CITY_EVENT_NONE;
    gCityEventTargetJob = JOB_NONE;
    gCityEventTargetItem = -1;
    gWarZoneWasActive = Life_IsWarZoneActive();
    if (gWarZoneId == -1)
    {
        gWarZoneId = GangZoneCreate(WAR_ZONE_MIN_X, WAR_ZONE_MIN_Y, WAR_ZONE_MAX_X, WAR_ZONE_MAX_Y);
    }
    for (playerid = 0; playerid < MAX_PLAYERS; playerid++)
    {
        gBusinessOfferFrom[playerid] = INVALID_PLAYER_ID;
        gBusinessOfferAmount[playerid] = 0;
        gBusinessOfferType[playerid] = LIFE_BUSINESS_NONE;
        gBusinessOfferTick[playerid] = 0;
        gLogisticsOfferFrom[playerid] = INVALID_PLAYER_ID;
        gLogisticsOfferAmount[playerid] = 0;
        gLogisticsOfferType[playerid] = LIFE_LOGISTICS_NONE;
        gLogisticsOfferTick[playerid] = 0;
        gLogisticsOwner[playerid] = INVALID_PLAYER_ID;
        gLogisticsAmount[playerid] = 0;
        gLogisticsType[playerid] = LIFE_LOGISTICS_NONE;
        gLogisticsStockGain[playerid] = 0;
        gLogisticsStage[playerid] = LIFE_LOGISTICS_STAGE_NONE;
        gLogisticsStartTick[playerid] = 0;
        gLifeLastMissionTick[playerid] = 0;
        gLifeLastCityPassTick[playerid] = 0;
        gLifeMoneyGainDay[playerid] = 0;
        gLifeMoneyGainToday[playerid] = 0;
        gLifeXpGainDay[playerid] = 0;
        gLifeXpGainToday[playerid] = 0;
        gWarZoneVisible[playerid] = 0;
        gLifeOnboardingHintShown[playerid] = 0;
        gPublicMissionType[playerid] = LIFE_PUBLIC_MISSION_NONE;
        gPublicMissionLastTick[playerid] = 0;
        gPublicMissionActor[playerid] = LIFE_PUBLIC_INVALID_ENTITY;
        gPublicMissionVehicle[playerid] = LIFE_PUBLIC_INVALID_ENTITY;
        gPublicMissionDetail[playerid][0] = 0;
        gPlayerAcceptedCall[playerid] = -1;
        for (new publicMissionObj = 0; publicMissionObj < LIFE_PUBLIC_MISSION_OBJECTS; publicMissionObj++)
        {
            gPublicMissionObject[playerid][publicMissionObj] = LIFE_PUBLIC_INVALID_ENTITY;
        }
    }
    for (callid = 0; callid < LIFE_CALL_CENTER_MAX; callid++)
    {
        Life_ServiceCall_Clear(callid);
    }
    for (dock = 0; dock < LIFE_LOGISTICS_DOCKS; dock++)
    {
        gLogisticsLoadLabel[dock] = Text3D:INVALID_3DTEXT_ID;
        gLogisticsUnloadLabel[dock] = Text3D:INVALID_3DTEXT_ID;
        gLogisticsLoadObject[dock] = INVALID_OBJECT_ID;
        gLogisticsUnloadObject[dock] = INVALID_OBJECT_ID;
    }
    Life_CreatePublicWorks();
    Life_CreateLogisticsDocks();
    Life_UpdateCityEvent();
    if (!gCityEventTimer)
    {
        gCityEventTimer = SetTimer("Life_UpdateCityEvent", CITY_EVENT_TIMER_MS, 1);
    }
    if (!gWarZoneTimer)
    {
        gWarZoneTimer = SetTimer("Life_UpdateWarZone", WAR_ZONE_TIMER_MS, 1);
    }
    if (!gAutoBusinessTimer)
    {
        gAutoBusinessTimer = SetTimer("Life_UpdateAutoBusinesses", LIFE_AUTO_BUSINESS_TIMER_MS, 1);
    }
    if (!gPoliticalBotTimer)
    {
        gPoliticalBotTimer = SetTimer("Life_UpdatePoliticalBots", LIFE_POLITICAL_BOT_DECISION_MS, 1);
    }
    if (!gServiceCallTimer)
    {
        gServiceCallTimer = SetTimer("Life_UpdateServiceCalls", LIFE_CALL_CENTER_TIMER_MS, 1);
    }
    return 1;
}

stock Life_Exit()
{
    Life_DestroyPublicWorks();
    Life_DestroyLogisticsDocks();
    if (gCityEventTimer)
    {
        KillTimer(gCityEventTimer);
        gCityEventTimer = 0;
    }
    if (gWarZoneTimer)
    {
        KillTimer(gWarZoneTimer);
        gWarZoneTimer = 0;
    }
    if (gAutoBusinessTimer)
    {
        KillTimer(gAutoBusinessTimer);
        gAutoBusinessTimer = 0;
    }
    if (gPoliticalBotTimer)
    {
        KillTimer(gPoliticalBotTimer);
        gPoliticalBotTimer = 0;
    }
    if (gServiceCallTimer)
    {
        KillTimer(gServiceCallTimer);
        gServiceCallTimer = 0;
    }
    if (gWarZoneId != -1)
    {
        GangZoneDestroy(gWarZoneId);
        gWarZoneId = -1;
    }
    Life_SaveMarketStock();
    Life_SavePublicWorks();
    Life_SavePolitics();
    return 1;
}

stock Life_SetPersonalDocuments(playerid)
{
    PlayerInfo[playerid][pDocuments] = 1;
    PlayerInfo[playerid][pDocumentsExpire] = GetBrasiliaDayStamp() + gCfgDocumentValidDays;
    return 1;
}

stock Life_SetLicenseExpiry(playerid, licenseid)
{
    new expire = GetBrasiliaDayStamp() + gCfgLicenseValidDays;

    switch (licenseid)
    {
        case 0:
        {
            PlayerInfo[playerid][pLicenseCNH] = 1;
            PlayerInfo[playerid][pLicenseCNHExpire] = expire;
        }
        case 1:
        {
            PlayerInfo[playerid][pLicenseHeavy] = 1;
            PlayerInfo[playerid][pLicenseHeavyExpire] = expire;
        }
        case 2:
        {
            PlayerInfo[playerid][pLicenseMedical] = 1;
            PlayerInfo[playerid][pLicenseMedicalExpire] = expire;
        }
        case 3:
        {
            PlayerInfo[playerid][pLicenseOAB] = 1;
            PlayerInfo[playerid][pLicenseOABExpire] = expire;
        }
        case 4:
        {
            PlayerInfo[playerid][pLicensePublic] = 1;
            PlayerInfo[playerid][pLicensePublicExpire] = expire;
        }
        case 5:
        {
            PlayerInfo[playerid][pLicensePolice] = 1;
            PlayerInfo[playerid][pLicensePoliceExpire] = expire;
        }
        default: return 0;
    }
    return 1;
}

stock Life_SetHealthPlan(playerid)
{
    PlayerInfo[playerid][pHealthPlan] = 1;
    PlayerInfo[playerid][pHealthPlanExpire] = GetBrasiliaDayStamp() + gCfgHealthPlanValidDays;
    return 1;
}

stock Life_EnsureExpiries(playerid)
{
    new today = GetBrasiliaDayStamp();

    if (PlayerInfo[playerid][pDocuments] && PlayerInfo[playerid][pDocumentsExpire] <= 0)
    {
        PlayerInfo[playerid][pDocumentsExpire] = today + gCfgDocumentValidDays;
    }
    if (PlayerInfo[playerid][pLicenseCNH] && PlayerInfo[playerid][pLicenseCNHExpire] <= 0) PlayerInfo[playerid][pLicenseCNHExpire] = today + gCfgLicenseValidDays;
    if (PlayerInfo[playerid][pLicenseHeavy] && PlayerInfo[playerid][pLicenseHeavyExpire] <= 0) PlayerInfo[playerid][pLicenseHeavyExpire] = today + gCfgLicenseValidDays;
    if (PlayerInfo[playerid][pLicenseMedical] && PlayerInfo[playerid][pLicenseMedicalExpire] <= 0) PlayerInfo[playerid][pLicenseMedicalExpire] = today + gCfgLicenseValidDays;
    if (PlayerInfo[playerid][pLicenseOAB] && PlayerInfo[playerid][pLicenseOABExpire] <= 0) PlayerInfo[playerid][pLicenseOABExpire] = today + gCfgLicenseValidDays;
    if (PlayerInfo[playerid][pLicensePublic] && PlayerInfo[playerid][pLicensePublicExpire] <= 0) PlayerInfo[playerid][pLicensePublicExpire] = today + gCfgLicenseValidDays;
    if (PlayerInfo[playerid][pLicensePolice] && PlayerInfo[playerid][pLicensePoliceExpire] <= 0) PlayerInfo[playerid][pLicensePoliceExpire] = today + gCfgLicenseValidDays;
    if (PlayerInfo[playerid][pHealthPlan] && PlayerInfo[playerid][pHealthPlanExpire] <= 0) PlayerInfo[playerid][pHealthPlanExpire] = today + gCfgHealthPlanValidDays;
    if (PlayerInfo[playerid][pBusinessType] && PlayerInfo[playerid][pBusinessPermitExpire] <= 0) PlayerInfo[playerid][pBusinessPermitExpire] = today + gCfgBusinessPermitValidDays;
    return 1;
}

stock Life_UpdateExpirations(playerid, notify = 0)
{
    new today = GetBrasiliaDayStamp();
    new changed;

    Life_EnsureExpiries(playerid);

    if (PlayerInfo[playerid][pDocuments] && PlayerInfo[playerid][pDocumentsExpire] > 0 && PlayerInfo[playerid][pDocumentsExpire] < today)
    {
        PlayerInfo[playerid][pDocuments] = 0;
        changed = 1;
        if (notify) SendClientMessage(playerid, COLOR_ORANGE, "Seus documentos venceram. Renove na Prefeitura ou em /documentos.");
    }
    if (PlayerInfo[playerid][pLicenseCNH] && PlayerInfo[playerid][pLicenseCNHExpire] > 0 && PlayerInfo[playerid][pLicenseCNHExpire] < today)
    {
        PlayerInfo[playerid][pLicenseCNH] = 0;
        changed = 1;
        if (notify) SendClientMessage(playerid, COLOR_ORANGE, "Sua CNH venceu.");
    }
    if (PlayerInfo[playerid][pLicenseHeavy] && PlayerInfo[playerid][pLicenseHeavyExpire] > 0 && PlayerInfo[playerid][pLicenseHeavyExpire] < today)
    {
        PlayerInfo[playerid][pLicenseHeavy] = 0;
        changed = 1;
        if (notify) SendClientMessage(playerid, COLOR_ORANGE, "Sua licenca pesada venceu.");
    }
    if (PlayerInfo[playerid][pLicenseMedical] && PlayerInfo[playerid][pLicenseMedicalExpire] > 0 && PlayerInfo[playerid][pLicenseMedicalExpire] < today)
    {
        PlayerInfo[playerid][pLicenseMedical] = 0;
        changed = 1;
        if (notify) SendClientMessage(playerid, COLOR_ORANGE, "Seu diploma/licenca medica venceu.");
    }
    if (PlayerInfo[playerid][pLicenseOAB] && PlayerInfo[playerid][pLicenseOABExpire] > 0 && PlayerInfo[playerid][pLicenseOABExpire] < today)
    {
        PlayerInfo[playerid][pLicenseOAB] = 0;
        changed = 1;
        if (notify) SendClientMessage(playerid, COLOR_ORANGE, "Sua OAB venceu.");
    }
    if (PlayerInfo[playerid][pLicensePublic] && PlayerInfo[playerid][pLicensePublicExpire] > 0 && PlayerInfo[playerid][pLicensePublicExpire] < today)
    {
        PlayerInfo[playerid][pLicensePublic] = 0;
        changed = 1;
        if (notify) SendClientMessage(playerid, COLOR_ORANGE, "Seu cargo/alvara publico venceu.");
    }
    if (PlayerInfo[playerid][pLicensePolice] && PlayerInfo[playerid][pLicensePoliceExpire] > 0 && PlayerInfo[playerid][pLicensePoliceExpire] < today)
    {
        PlayerInfo[playerid][pLicensePolice] = 0;
        changed = 1;
        if (notify) SendClientMessage(playerid, COLOR_ORANGE, "Sua aprovacao policial venceu.");
    }
    if (PlayerInfo[playerid][pHealthPlan] && PlayerInfo[playerid][pHealthPlanExpire] > 0 && PlayerInfo[playerid][pHealthPlanExpire] < today)
    {
        PlayerInfo[playerid][pHealthPlan] = 0;
        changed = 1;
        if (notify) SendClientMessage(playerid, COLOR_ORANGE, "Seu plano de saude venceu.");
    }

    if (changed)
    {
        SaveAccountData(playerid, 0);
    }
    return 1;
}

stock Life_BillCoreTotal(playerid)
{
    return PlayerInfo[playerid][pBillWaterDue]
        + PlayerInfo[playerid][pBillElectricDue]
        + PlayerInfo[playerid][pBillInternetDue]
        + PlayerInfo[playerid][pBillRentDue]
        + PlayerInfo[playerid][pBillVehicleInsuranceDue]
        + PlayerInfo[playerid][pBillHealthPlanDue]
        + PlayerInfo[playerid][pBillLoanInstallmentDue]
        + PlayerInfo[playerid][pBillBusinessPayrollDue];
}

stock Life_BillTotal(playerid)
{
    return Life_BillCoreTotal(playerid)
        + PlayerInfo[playerid][pPropertyTaxDue]
        + PlayerInfo[playerid][pGovernmentTaxDue]
        + PlayerInfo[playerid][pJusticeFineDue]
        + PlayerInfo[playerid][pVehicleTaxDue]
        + PlayerInfo[playerid][pFines];
}

stock Life_GetLateFee(amount)
{
    new fee;

    if (amount <= 0 || gCfgBillLateFeePercent <= 0)
    {
        return 0;
    }

    fee = (amount * gCfgBillLateFeePercent) / 100;
    if (fee < 1)
    {
        fee = 1;
    }
    return fee;
}

stock Life_AddLateFee(&amount)
{
    if (amount > 0)
    {
        amount += Life_GetLateFee(amount);
    }
    return 1;
}

stock Life_SetDirtyStatus(playerid, notify = 0)
{
    new total = Life_BillTotal(playerid);
    new overdue = 0;
    new today = GetBrasiliaDayStamp();

    if (PlayerInfo[playerid][pBillDueDay] > 0 && today > PlayerInfo[playerid][pBillDueDay] && total > 0)
    {
        overdue = 1;
    }

    if ((overdue && total >= gCfgDebtDirtyThreshold) || PlayerInfo[playerid][pDirtyName])
    {
        if (total <= 0)
        {
            PlayerInfo[playerid][pDirtyName] = 0;
            if (notify) SendClientMessage(playerid, COLOR_GREEN, "Seu nome saiu da restricao financeira.");
        }
        else if (!PlayerInfo[playerid][pDirtyName])
        {
            PlayerInfo[playerid][pDirtyName] = 1;
            PlayerInfo[playerid][pBankBadHistory]++;
            if (notify) SendClientMessage(playerid, COLOR_ORANGE, "Seu nome entrou em restricao por boletos vencidos.");
        }
    }
    return 1;
}

stock Life_ApplyLateFees(playerid, notify = 0)
{
    new today = GetBrasiliaDayStamp();

    if (PlayerInfo[playerid][pBillDueDay] <= 0 || Life_BillTotal(playerid) <= 0)
    {
        Life_SetDirtyStatus(playerid, notify);
        return 0;
    }

    if (today <= PlayerInfo[playerid][pBillDueDay])
    {
        Life_SetDirtyStatus(playerid, notify);
        return 0;
    }

    if (PlayerInfo[playerid][pBillLateChargeDay] >= today)
    {
        Life_SetDirtyStatus(playerid, notify);
        return 0;
    }

    Life_AddLateFee(PlayerInfo[playerid][pBillWaterDue]);
    Life_AddLateFee(PlayerInfo[playerid][pBillElectricDue]);
    Life_AddLateFee(PlayerInfo[playerid][pBillInternetDue]);
    Life_AddLateFee(PlayerInfo[playerid][pBillRentDue]);
    Life_AddLateFee(PlayerInfo[playerid][pBillVehicleInsuranceDue]);
    Life_AddLateFee(PlayerInfo[playerid][pBillHealthPlanDue]);
    Life_AddLateFee(PlayerInfo[playerid][pBillLoanInstallmentDue]);
    Life_AddLateFee(PlayerInfo[playerid][pBillBusinessPayrollDue]);
    Life_AddLateFee(PlayerInfo[playerid][pPropertyTaxDue]);
    Life_AddLateFee(PlayerInfo[playerid][pGovernmentTaxDue]);
    Life_AddLateFee(PlayerInfo[playerid][pJusticeFineDue]);
    Life_AddLateFee(PlayerInfo[playerid][pVehicleTaxDue]);
    Life_AddLateFee(PlayerInfo[playerid][pFines]);
    PlayerInfo[playerid][pBillLateChargeDay] = today;
    Life_SetDirtyStatus(playerid, notify);
    SaveAccountData(playerid, 0);

    if (notify)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Boletos vencidos receberam juros/multa diaria. Consulte /boletos.");
    }
    return 1;
}

stock Life_IsDebtBlocked(playerid)
{
    Life_ApplyLateFees(playerid, 0);
    return (PlayerInfo[playerid][pDirtyName] || Life_BillTotal(playerid) >= gCfgDebtDirtyThreshold);
}

stock Life_ResetSalaryWorkDay(playerid)
{
    new today = GetBrasiliaDayStamp();

    if (PlayerInfo[playerid][pSalaryWorkDay] != today)
    {
        PlayerInfo[playerid][pSalaryWorkDay] = today;
        PlayerInfo[playerid][pSalaryWorkTasks] = 0;
        PlayerInfo[playerid][pSalaryProductivityPaid] = 0;
    }
    return 1;
}

stock Life_GetDailySalaryBase(playerid)
{
    new jobid = PlayerInfo[playerid][pJob];
    new salary;

    if (jobid == JOB_NONE)
    {
        return 0;
    }

    salary = Job_GetMonthlySalary(jobid) / 30;
    if (salary < 50)
    {
        salary = 50;
    }
    return salary;
}

stock Life_HandleJobProductivity(playerid, jobid, source[])
{
    new productivity;
    new tax;
    new message[144];

    if (!Job_IsPrivateBonusEligible(jobid))
    {
        return 0;
    }
    if (strcmp(source, "job_level_reward", false) == 0)
    {
        return 0;
    }

    Life_ResetSalaryWorkDay(playerid);
    PlayerInfo[playerid][pSalaryWorkTasks]++;

    if (PlayerInfo[playerid][pSalaryProductivityPaid])
    {
        return 0;
    }
    if (PlayerInfo[playerid][pSalaryWorkTasks] < gCfgSalaryPayTasks)
    {
        return 0;
    }

    productivity = ((Job_GetMonthlySalary(jobid) / 30) * SALARY_PRODUCTIVITY_PERCENT) / 100;
    if (productivity < 80)
    {
        productivity = 80;
    }
    tax = (productivity * gCfgIncomeTaxPercent) / 100;
    Bank_AddSalary(playerid, productivity);
    PlayerInfo[playerid][pGovernmentTaxDue] += tax;
    PlayerInfo[playerid][pSalaryProductivityPaid] = 1;
    SaveAccountData(playerid, 0);

    format(message, sizeof(message), "Adicional de produtividade liberado: $%d pendente no banco. Meta diaria: %d servico(s).", productivity, gCfgSalaryPayTasks);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Life_GenSalary(playerid, notify = 0)
{
    new today = GetBrasiliaDayStamp();
    new salary;
    new tax;
    new message[180];

    if (PlayerInfo[playerid][pJob] == JOB_NONE)
    {
        return 0;
    }

    Life_ResetSalaryWorkDay(playerid);

    if (PlayerInfo[playerid][pSalaryLastDay] <= 0)
    {
        PlayerInfo[playerid][pSalaryLastDay] = today - 1;
    }

    if (PlayerInfo[playerid][pSalaryLastDay] == today)
    {
        return 0;
    }

    // Salario diario: pequena base de contrato, paga uma vez no login/spawn do dia, sem acumular dias offline.
    salary = Life_GetDailySalaryBase(playerid);
    tax = (salary * gCfgIncomeTaxPercent) / 100;
    Bank_AddSalary(playerid, salary);
    PlayerInfo[playerid][pGovernmentTaxDue] += tax;
    PlayerInfo[playerid][pSalaryLastDay] = today;
    PlayerInfo[playerid][pBankGoodHistory]++;
    Life_GetBankScore(playerid);
    SaveAccountData(playerid, 0);

    if (notify)
    {
        format(message, sizeof(message), "Salario diario registrado: $%d pendente no banco. Imposto de renda: $%d.", salary, tax);
        SendClientMessage(playerid, COLOR_GREEN, message);
    }
    return 1;
}

stock Life_GetResidenceOccupants(propertyid)
{
    new occupants;

    if (!Property_IsValid(propertyid))
    {
        return 0;
    }

    occupants = Property_CountLiveOccupants(propertyid);
    if (occupants < 1)
    {
        occupants = 1;
    }
    return occupants;
}

stock Life_GetResidenceWaterBill(propertyid)
{
    new occupants = Life_GetResidenceOccupants(propertyid);
    new amount;

    if (occupants <= 0)
    {
        return 0;
    }

    amount = Cfg_Price(gCfgBillWaterCost);
    if (occupants > 1)
    {
        amount += Cfg_Price(gCfgBillWaterOccupantExtra) * (occupants - 1);
    }
    return amount;
}

stock Life_GetResidenceElectricBill(playerid, propertyid)
{
    new occupants = Life_GetResidenceOccupants(propertyid);
    new amount;

    if (occupants <= 0)
    {
        return 0;
    }

    amount = Cfg_Price(gCfgBillElectricCost);
    if (occupants > 1)
    {
        amount += Cfg_Price(gCfgBillElectricOccupantExtra) * (occupants - 1);
    }
    if (Life_IsPublicWorkDone(LIFE_PUBLIC_WORK_HYDRO))
    {
        amount -= (amount * gCfgBillHydroDiscountPercent) / 100;
    }
    if (PlayerInfo[playerid][pHomeSolar] && PlayerInfo[playerid][pHouse] == propertyid)
    {
        amount -= (amount * gCfgHomeSolarDiscountPercent) / 100;
    }
    if (amount < 0)
    {
        amount = 0;
    }
    return amount;
}

stock Life_GetHomeSolarInstallCost(playerid)
{
    new cost = Cfg_Price(gCfgHomeSolarInstallCost);

    if (Life_IsPublicWorkDone(LIFE_PUBLIC_WORK_SOLAR))
    {
        cost -= (cost * 20) / 100;
    }
    if (Vip_GetLevel(playerid) > 0)
    {
        cost = Vip_ApplyDiscount(playerid, cost);
    }
    if (cost < 0)
    {
        cost = 0;
    }
    return cost;
}

stock Life_GenMonthlyBills(playerid, notify = 0)
{
    new today = GetBrasiliaDayStamp();
    new propertyid;
    new index;
    new message[144];
    new loanBillGenerated;

    if (PlayerInfo[playerid][pBillLastGenerateDay] <= 0)
    {
        PlayerInfo[playerid][pBillLastGenerateDay] = today;
        if (PlayerInfo[playerid][pBillDueDay] <= 0)
        {
            PlayerInfo[playerid][pBillDueDay] = today + gCfgBillDueDays;
        }
        return 0;
    }

    loanBillGenerated = Bank_GenerateLoanInstallment(playerid, today, notify);

    if ((today - PlayerInfo[playerid][pBillLastGenerateDay]) < 30)
    {
        if (loanBillGenerated)
        {
            SaveAccountData(playerid, 0);
        }
        return loanBillGenerated;
    }

    propertyid = PlayerInfo[playerid][pHouse];
    if (propertyid == HOUSE_NONE)
    {
        propertyid = PlayerInfo[playerid][pRentedHouse];
    }

    if (propertyid != HOUSE_NONE)
    {
        PlayerInfo[playerid][pBillWaterDue] += Life_GetResidenceWaterBill(propertyid);
        PlayerInfo[playerid][pBillElectricDue] += Life_GetResidenceElectricBill(playerid, propertyid);
        PlayerInfo[playerid][pBillInternetDue] += Cfg_Price(gCfgBillInternetCost);
    }

    if (PlayerInfo[playerid][pRentedHouse] != HOUSE_NONE)
    {
        index = Property_GetIndex(PlayerInfo[playerid][pRentedHouse]);
        if (index != -1)
        {
            PlayerInfo[playerid][pBillRentDue] += Cfg_Price(gProperties[index][propRent] + gCfgBillRentExtraCost);
        }
    }

    if (PlayerInfo[playerid][pVehicleModel] >= 400)
    {
        PlayerInfo[playerid][pVehicleTaxDue] += Dealership_GetVehicleTax(PlayerInfo[playerid][pVehicleModel]);
        PlayerInfo[playerid][pBillVehicleInsuranceDue] += Vip_ApplyDiscount(playerid, Cfg_Price(gCfgVehicleInsuranceCost));
    }

    if (PlayerInfo[playerid][pHealthPlan])
    {
        PlayerInfo[playerid][pBillHealthPlanDue] += Cfg_Price(gCfgHospitalPlanCost);
    }

    if (PlayerInfo[playerid][pBusinessType] != LIFE_BUSINESS_NONE)
    {
        PlayerInfo[playerid][pBillBusinessPayrollDue] += Life_GetBusinessOperatingCost(playerid);
        Life_WriteBusinessDeepSnapshot(playerid, "monthly_bill");
    }

    PlayerInfo[playerid][pBillDueDay] = today + gCfgBillDueDays;
    PlayerInfo[playerid][pBillLastGenerateDay] = today;
    PlayerInfo[playerid][pBillLateChargeDay] = 0;
    SaveAccountData(playerid, 0);

    if (notify)
    {
        format(message, sizeof(message), "Novos boletos mensais gerados. Vencimento em %d dia(s). Use /boletos.", gCfgBillDueDays);
        SendClientMessage(playerid, COLOR_ORANGE, message);
    }
    return 1;
}

stock Life_WarnBills(playerid)
{
    new days;
    new total = Life_BillTotal(playerid);

    if (total <= 0 || PlayerInfo[playerid][pBillDueDay] <= 0)
    {
        return 0;
    }

    days = PlayerInfo[playerid][pBillDueDay] - GetBrasiliaDayStamp();
    if (days < 0)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Voce tem boletos vencidos. Consulte /boletos para evitar restricoes.");
    }
    else if (days <= 3)
    {
        SendClientMessage(playerid, COLOR_YELLOW, "Voce tem boletos proximos do vencimento. Consulte /boletos.");
    }
    return 1;
}

stock Life_GetBankScore(playerid)
{
    new score = gCfgBankScoreBase;
    new debt = Life_BillTotal(playerid);
    new jobid;
    new jobHistory;
    new activeJobLevel;

    score += PlayerInfo[playerid][pLevel] * 15;
    score += PlayerInfo[playerid][pBankGoodHistory] * gCfgBankScoreGoodBonus;
    score -= PlayerInfo[playerid][pBankBadHistory] * gCfgBankScoreBadPenalty;
    score -= PlayerInfo[playerid][pCriminalRecords] * gCfgBankScoreCriminalPenalty;
    score -= PlayerInfo[playerid][pWanted] * 40;
    if (Life_HasOpenJusticeRisk(playerid)) score -= 55;
    if (PlayerInfo[playerid][pJusticeFineDue] > 0) score -= (PlayerInfo[playerid][pJusticeFineDue] / 1000) * gCfgBankScoreFinePenalty;
    score -= (PlayerInfo[playerid][pFines] / 1000) * gCfgBankScoreFinePenalty;
    if (PlayerInfo[playerid][pJob] != JOB_NONE) score += 60;
    if (PlayerInfo[playerid][pDocuments]) score += 50;
    if (PlayerInfo[playerid][pCivilCPF]) score += 20;
    if (PlayerInfo[playerid][pCivilRG]) score += 20;
    if (PlayerInfo[playerid][pCivilCertificate]) score += 15;
    if (PlayerInfo[playerid][pHouse] != HOUSE_NONE) score += 80;
    if (PlayerInfo[playerid][pRentedHouse] != HOUSE_NONE) score += 35;
    if (PlayerInfo[playerid][pContractRent]) score += 15;
    if (PlayerInfo[playerid][pContractWork]) score += 20;
    if (PlayerInfo[playerid][pContractInsurance]) score += 15;
    if (PlayerInfo[playerid][pBusinessType] != LIFE_BUSINESS_NONE) score += 65;
    if (Life_HasAchievement(playerid, ACH_GOOD_PAYER)) score += 30;
    if (Life_HasAchievement(playerid, ACH_WORKER)) score += 25;
    if (Life_HasAchievement(playerid, ACH_BUSINESS_OWNER)) score += 25;
    if (Life_HasAchievement(playerid, ACH_CLEAN_RECORD)) score += 30;
    if (Life_HasAchievement(playerid, ACH_LEGAL_DRIVER)) score += 25;
    if (PlayerInfo[playerid][pBankLoan] > 0) score -= 80;
    if (debt > 0) score -= (debt / 1000) * gCfgBankScoreFinePenalty;
    if (PlayerInfo[playerid][pDirtyName]) score -= gCfgDebtScorePenalty;
    if (PlayerInfo[playerid][pDocumentsExpire] > 0 && PlayerInfo[playerid][pDocumentsExpire] < GetBrasiliaDayStamp()) score -= 50;

    for (jobid = 1; jobid <= JOB_MAX_ID; jobid++)
    {
        if (Job_GetPlayerLevel(playerid, jobid) > 1)
        {
            jobHistory += Job_GetPlayerLevel(playerid, jobid) - 1;
        }
    }
    activeJobLevel = Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob]);
    score += Cfg_Clamp(jobHistory * 8, 0, 120);
    score += Cfg_Clamp(activeJobLevel * 6, 0, 60);

    score = Cfg_Clamp(score, 0, 1000);
    PlayerInfo[playerid][pBankScore] = score;
    return score;
}

stock Life_FormatAchievementTitle(playerid, output[], size = sizeof(output))
{
    if (Life_HasAchievement(playerid, ACH_GOOD_PAYER)) format(output, size, "Bom pagador");
    else if (Life_HasAchievement(playerid, ACH_WORKER)) format(output, size, "Trabalhador");
    else if (Life_HasAchievement(playerid, ACH_BUSINESS_OWNER)) format(output, size, "Empresario");
    else if (Life_HasAchievement(playerid, ACH_CLEAN_RECORD)) format(output, size, "Ficha limpa");
    else if (Life_HasAchievement(playerid, ACH_LEGAL_DRIVER)) format(output, size, "Motorista legalizado");
    else format(output, size, "Sem titulo");
    return 1;
}

stock Life_GetScoreLabel(score, output[], size = sizeof(output))
{
    if (score >= 800) format(output, size, "excelente");
    else if (score >= 650) format(output, size, "bom");
    else if (score >= 450) format(output, size, "regular");
    else if (score >= 250) format(output, size, "risco");
    else format(output, size, "critico");
    return 1;
}

stock Life_CheckScoreGate(playerid, minScore, action[])
{
    new score = Life_GetBankScore(playerid);
    new message[144];

    if (Life_IsDebtBlocked(playerid))
    {
        format(message, sizeof(message), "%s bloqueado: regularize boletos/dividas em /boletos.", action);
        SendClientMessage(playerid, COLOR_RED, message);
        return 0;
    }

    if (score < minScore)
    {
        format(message, sizeof(message), "%s bloqueado: score cidadao %d/%d. Use /cidadao para ver pendencias.", action, score, minScore);
        SendClientMessage(playerid, COLOR_RED, message);
        return 0;
    }
    return 1;
}

stock Life_ShowBankScore(playerid)
{
    new score = Life_GetBankScore(playerid);
    new message[144];
    new label[24];

    Life_GetScoreLabel(score, label, sizeof(label));
    format(message, sizeof(message), "Score cidadao: %d/1000 (%s) | Minimo para emprestimo: %d.", score, label, gCfgBankLoanMinScore);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Historico positivo: %d | Historico negativo: %d | Multas: $%d | Pontos CNH: %d | Antecedentes: %d", PlayerInfo[playerid][pBankGoodHistory], PlayerInfo[playerid][pBankBadHistory], PlayerInfo[playerid][pFines], PlayerInfo[playerid][pTrafficPoints], PlayerInfo[playerid][pCriminalRecords]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Travas: licenca %d | emprego sensivel %d | veiculo %d | aluguel %d | imovel %d | empresa %d.", gCfgCitizenLicenseMinScore, gCfgCitizenJobTrustedMinScore, gCfgCitizenVehicleMinScore, gCfgCitizenRentMinScore, gCfgCitizenPropertyMinScore, gCfgCitizenBusinessMinScore);
    SendClientMessage(playerid, COLOR_GRAY, message);
    return 1;
}

stock Life_ShowCitizenStatus(playerid)
{
    new message[160];
    new jobLabel[32];
    new score = Life_GetBankScore(playerid);
    new label[24];
    new debt = Life_BillTotal(playerid);
    new title[32];
    new justiceName[24];

    Life_GetScoreLabel(score, label, sizeof(label));
    Life_FormatAchievementTitle(playerid, title, sizeof(title));
    Life_GetJusticeStatusName(PlayerInfo[playerid][pJusticeStatus], justiceName, sizeof(justiceName));
    GetJobName(PlayerInfo[playerid][pJob], jobLabel, sizeof(jobLabel));

    format(message, sizeof(message), "Cidadao: score %d/1000 (%s) | Titulo: %s | Nome: %s", score, label, title, PlayerInfo[playerid][pDirtyName] ? ("restrito") : ("regular"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Pendencias: boletos/multas/sentencas $%d | Pontos CNH %d | Casos %d | Justica %s | prazo %d", debt, PlayerInfo[playerid][pTrafficPoints], PlayerInfo[playerid][pJusticeCases], justiceName, PlayerInfo[playerid][pJusticeDeadlineDay]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Documentos: base %s | CPF %s | RG %s | CNH %d | OAB %d | Porte arma %d", PlayerInfo[playerid][pDocuments] ? ("sim") : ("nao"), PlayerInfo[playerid][pCivilCPF] ? ("sim") : ("nao"), PlayerInfo[playerid][pCivilRG] ? ("sim") : ("nao"), PlayerInfo[playerid][pLicenseCNH], PlayerInfo[playerid][pLicenseOAB], PlayerInfo[playerid][pLicensePolice]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Trabalho: %s | nivel %d | XP %d | Contrato: %s", jobLabel, Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob]), Job_GetPlayerXP(playerid, PlayerInfo[playerid][pJob]), PlayerInfo[playerid][pContractWork] ? ("ativo") : ("nao"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Patrimonio: casa %d | aluguel %d | veiculo %d | empresa %d | banco $%d | emprestimo $%d", PlayerInfo[playerid][pHouse], PlayerInfo[playerid][pRentedHouse], PlayerInfo[playerid][pVehicleModel], PlayerInfo[playerid][pBusinessType], PlayerInfo[playerid][pBankMoney], PlayerInfo[playerid][pBankLoan]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Conquistas: bom pagador %s | trabalhador %s | empresario %s | ficha limpa %s | motorista %s", Life_HasAchievement(playerid, ACH_GOOD_PAYER) ? ("sim") : ("nao"), Life_HasAchievement(playerid, ACH_WORKER) ? ("sim") : ("nao"), Life_HasAchievement(playerid, ACH_BUSINESS_OWNER) ? ("sim") : ("nao"), Life_HasAchievement(playerid, ACH_CLEAN_RECORD) ? ("sim") : ("nao"), Life_HasAchievement(playerid, ACH_LEGAL_DRIVER) ? ("sim") : ("nao"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    SendClientMessage(playerid, COLOR_GRAY, "Melhore pagando boletos, mantendo documentos em dia, trabalhando, quitando multas e evitando ficha policial.");
    Life_TutorialAdvance(playerid, 5);
    Life_CheckAchievements(playerid);
    return 1;
}

stock Life_ShowDocumentsDialog(playerid)
{
    new list[1024];
    new line[128];
    new days[32];

    Life_UpdateExpirations(playerid, 0);
    format(list, sizeof(list), "Documento\tStatus\n");
    Life_FormatDays(PlayerInfo[playerid][pDocumentsExpire], days, sizeof(days));
    format(line, sizeof(line), "RG/CPF digital\t%s\n", PlayerInfo[playerid][pDocuments] ? days : ("pendente")); strcat(list, line, sizeof(list));
    Life_FormatDays(PlayerInfo[playerid][pLicenseCNHExpire], days, sizeof(days));
    format(line, sizeof(line), "CNH\t%s | pontos %d\n", PlayerInfo[playerid][pLicenseCNH] ? days : ("pendente"), PlayerInfo[playerid][pTrafficPoints]); strcat(list, line, sizeof(list));
    Life_FormatDays(PlayerInfo[playerid][pLicenseHeavyExpire], days, sizeof(days));
    format(line, sizeof(line), "Licenca pesada\t%s\n", PlayerInfo[playerid][pLicenseHeavy] ? days : ("pendente")); strcat(list, line, sizeof(list));
    Life_FormatDays(PlayerInfo[playerid][pLicenseMedicalExpire], days, sizeof(days));
    format(line, sizeof(line), "Licenca medica\t%s\n", PlayerInfo[playerid][pLicenseMedical] ? days : ("pendente")); strcat(list, line, sizeof(list));
    Life_FormatDays(PlayerInfo[playerid][pLicenseOABExpire], days, sizeof(days));
    format(line, sizeof(line), "OAB\t%s\n", PlayerInfo[playerid][pLicenseOAB] ? days : ("pendente")); strcat(list, line, sizeof(list));
    Life_FormatDays(PlayerInfo[playerid][pLicensePublicExpire], days, sizeof(days));
    format(line, sizeof(line), "Cargo publico\t%s\n", PlayerInfo[playerid][pLicensePublic] ? days : ("pendente")); strcat(list, line, sizeof(list));
    Life_FormatDays(PlayerInfo[playerid][pLicensePoliceExpire], days, sizeof(days));
    format(line, sizeof(line), "Porte de arma\t%s\n", PlayerInfo[playerid][pLicensePolice] ? days : ("pendente")); strcat(list, line, sizeof(list));
    Life_FormatDays(PlayerInfo[playerid][pHealthPlanExpire], days, sizeof(days));
    format(line, sizeof(line), "Plano de saude\t%s\n", PlayerInfo[playerid][pHealthPlan] ? days : ("pendente")); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "CRLV/IPVA\t%s\n", PlayerInfo[playerid][pVehicleTaxDue] > 0 ? ("pendente") : ("regular")); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Seguro veicular\t%s\n", PlayerInfo[playerid][pVehicleInsurance] ? ("ativo") : ("pendente")); strcat(list, line, sizeof(list));

    ShowPlayerDialog(playerid, DIALOG_LIFE_DOCS, DIALOG_STYLE_TABLIST_HEADERS, "Documentos e vencimentos", list, "Renovar", "Fechar");
    return 1;
}

stock Life_RenewDocumentByItem(playerid, item)
{
    new cost;
    new message[128];

    switch (item)
    {
        case 0:
        {
            cost = Cfg_Price(gCfgCityDocumentCost);
            if (!Bank_TakePayment(playerid, cost, 0)) return SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para renovar documentos.");
            Life_SetPersonalDocuments(playerid);
        }
        case 1:
        {
            cost = Cfg_Price(gCfgLicenseCNHCost);
            if (!Bank_TakePayment(playerid, cost, 0)) return SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para renovar CNH.");
            Life_SetLicenseExpiry(playerid, 0);
        }
        case 2:
        {
            cost = Cfg_Price(gCfgLicenseHeavyCost);
            if (!Bank_TakePayment(playerid, cost, 0)) return SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para renovar licenca pesada.");
            Life_SetLicenseExpiry(playerid, 1);
        }
        case 3:
        {
            cost = Cfg_Price(gCfgLicenseMedicalCost);
            if (!Bank_TakePayment(playerid, cost, 0)) return SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para renovar licenca medica.");
            Life_SetLicenseExpiry(playerid, 2);
        }
        case 4:
        {
            cost = Cfg_Price(gCfgLicenseOABCost);
            if (!Bank_TakePayment(playerid, cost, 0)) return SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para renovar OAB.");
            Life_SetLicenseExpiry(playerid, 3);
        }
        case 5:
        {
            cost = Cfg_Price(gCfgLicensePublicCost);
            if (!Bank_TakePayment(playerid, cost, 0)) return SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para renovar cargo publico.");
            Life_SetLicenseExpiry(playerid, 4);
        }
        case 6:
        {
            cost = Cfg_Price(gCfgLicensePoliceCost);
            if (!Bank_TakePayment(playerid, cost, 0)) return SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para renovar aprovacao policial.");
            Life_SetLicenseExpiry(playerid, 5);
        }
        case 7:
        {
            cost = Cfg_Price(gCfgHospitalPlanCost);
            if (!Bank_TakePayment(playerid, cost, 0)) return SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para renovar plano de saude.");
            Life_SetHealthPlan(playerid);
        }
        case 8: return Dealership_PayVehicleTax(playerid);
        case 9: return Dealership_BuyInsurance(playerid);
        default: return SendClientMessage(playerid, COLOR_RED, "Documento invalido.");
    }

    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Renovacao concluida. Custo: $%d.", cost);
    SendClientMessage(playerid, COLOR_GREEN, message);
    Life_AddMissionProgress(playerid, 5, 1);
    Life_CheckAchievements(playerid);
    return 1;
}

stock Life_GenerateMonthlyTaxes(playerid)
{
    new today = GetBrasiliaDayStamp();
    new propertyid = PlayerInfo[playerid][pHouse];
    new index;
    new base;

    if (PlayerInfo[playerid][pTaxLastDay] <= 0)
    {
        PlayerInfo[playerid][pTaxLastDay] = today;
        return 1;
    }

    if ((today - PlayerInfo[playerid][pTaxLastDay]) < 30)
    {
        return 1;
    }

    if (propertyid != HOUSE_NONE)
    {
        index = Property_GetIndex(propertyid);
        if (index != -1)
        {
            base = (Cfg_PropertyPrice(gProperties[index][propPrice]) * gCfgPropertyTaxPercent) / 100;
            if (base < 1 && gCfgPropertyTaxPercent > 0)
            {
                base = 1;
            }
            PlayerInfo[playerid][pPropertyTaxDue] += base;
        }
    }

    if (PlayerInfo[playerid][pDocuments])
    {
        PlayerInfo[playerid][pGovernmentTaxDue] += Cfg_Price(gCfgGovernmentMonthlyFee);
    }

    if (PlayerInfo[playerid][pBusinessType] != LIFE_BUSINESS_NONE)
    {
        PlayerInfo[playerid][pBusinessTaxDue] += (PlayerInfo[playerid][pBusinessBalance] * gCfgBusinessTaxPercent) / 100;
    }

    PlayerInfo[playerid][pTaxLastDay] = today;
    SaveAccountData(playerid, 0);
    return 1;
}

stock Life_ShowTaxesDialog(playerid)
{
    new list[768];
    new line[128];
    new total;

    Life_GenerateMonthlyTaxes(playerid);
    total = PlayerInfo[playerid][pPropertyTaxDue] + PlayerInfo[playerid][pGovernmentTaxDue] + PlayerInfo[playerid][pBusinessTaxDue] + PlayerInfo[playerid][pJusticeFineDue];

    format(list, sizeof(list), "Taxa\tValor\n");
    format(line, sizeof(line), "IPTU/Imovel\t$%d\n", PlayerInfo[playerid][pPropertyTaxDue]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Taxas GovBR\t$%d\n", PlayerInfo[playerid][pGovernmentTaxDue]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Imposto empresa\t$%d\n", PlayerInfo[playerid][pBusinessTaxDue]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Sentenca judicial\t$%d\n", PlayerInfo[playerid][pJusticeFineDue]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Pagar tudo\t$%d\n", total); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Arrecadacao prefeitura\t$%d\n", gGovernmentRevenue); strcat(list, line, sizeof(list));

    ShowPlayerDialog(playerid, DIALOG_LIFE_TAXES, DIALOG_STYLE_TABLIST_HEADERS, "Impostos e governo", list, "Selecionar", "Fechar");
    return 1;
}

stock Life_PayTaxItem(playerid, item)
{
    new amount;
    new reason[32];

    switch (item)
    {
        case 0:
        {
            amount = PlayerInfo[playerid][pPropertyTaxDue];
            format(reason, sizeof(reason), "property");
        }
        case 1:
        {
            amount = PlayerInfo[playerid][pGovernmentTaxDue];
            format(reason, sizeof(reason), "government");
        }
        case 2:
        {
            amount = PlayerInfo[playerid][pBusinessTaxDue];
            format(reason, sizeof(reason), "business");
        }
        case 3:
        {
            amount = PlayerInfo[playerid][pJusticeFineDue];
            format(reason, sizeof(reason), "justice");
        }
        case 4:
        {
            amount = PlayerInfo[playerid][pPropertyTaxDue] + PlayerInfo[playerid][pGovernmentTaxDue] + PlayerInfo[playerid][pBusinessTaxDue] + PlayerInfo[playerid][pJusticeFineDue];
            format(reason, sizeof(reason), "all");
        }
        case 5:
        {
            new message[96];
            format(message, sizeof(message), "Arrecadacao atual da prefeitura: $%d.", gGovernmentRevenue);
            SendClientMessage(playerid, COLOR_BLUE, message);
            return 1;
        }
        default: return 1;
    }

    if (amount <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Nao ha debito nesta categoria.");
        return 1;
    }

    if (!Bank_TakePayment(playerid, amount, 0))
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para pagar este debito.");
        return 1;
    }

    if (item == 0 || item == 4) PlayerInfo[playerid][pPropertyTaxDue] = 0;
    if (item == 1 || item == 4) PlayerInfo[playerid][pGovernmentTaxDue] = 0;
    if (item == 2 || item == 4) PlayerInfo[playerid][pBusinessTaxDue] = 0;
    if (item == 3 || item == 4) PlayerInfo[playerid][pJusticeFineDue] = 0;

    Life_AddGovernmentRevenue(amount, reason);
    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Debito pago e registrado na arrecadacao publica.");
    return 1;
}

stock Life_ShowMarketDialog(playerid)
{
    new list[1100];
    new line[160];
    new status[64];
    new index;

    format(list, sizeof(list), "Produto\tEstoque\tMercado\n");
    for (index = 0; index < LIFE_MARKET_ITEMS; index++)
    {
        Life_FormatMarketStatus(index, status, sizeof(status));
        format(line, sizeof(line), "%s\t%d\t%s\n", gMarketNames[index], gMarketStock[index], status);
        strcat(list, line, sizeof(list));
    }
    strcat(list, "Vender mercadorias\ttrabalho\tpreco varia por demanda\n", sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_LIFE_MARKET, DIALOG_STYLE_TABLIST_HEADERS, "Mercado e estoque", list, "Selecionar", "Fechar");
    return 1;
}

stock Life_GetMarketItemByJob(jobid)
{
    switch (jobid)
    {
        case JOB_ENTREGADOR, JOB_MOTOBOY, JOB_COZINHEIRO, JOB_GARCOM: return 0;
        case JOB_CAMINHONEIRO, JOB_FRENTISTA: return 4;
        case JOB_MECANICO, JOB_TECNICO: return 3;
        case JOB_MEDICO, JOB_MOTORISTA_AMBULANCIA: return 2;
        case JOB_PESCADOR, JOB_AGRICULTOR: return 0;
        case JOB_MINERADOR, JOB_PEDREIRO: return 5;
    }
    return -1;
}

stock Life_SellProductsToMarket(playerid)
{
    new item = Life_GetMarketItemByJob(PlayerInfo[playerid][pJob]);
    new pay;
    new message[144];
    new bonusPercent;
    new demandPercent;
    new logLine[144];

    if (item == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Sua profissao nao vende mercadorias ao mercado.");
        return 1;
    }

    pay = Life_GetMarketSellPay(playerid, item);
    demandPercent = Life_GetMarketDemandPercent(item);
    bonusPercent = Life_GetJobPayBonusPercent(playerid, PlayerInfo[playerid][pJob]);
    gMarketStock[item] += gCfgMarketDeliveryStock;
    GivePlayerCashReason(playerid, pay, 1, "market_sale");
    Bank_AddSalary(playerid, pay / 4);
    Job_AddProgress(playerid, PlayerInfo[playerid][pJob], gCfgJobXpPerTask);
    Life_AddMissionProgress(playerid, 2, 1);
    Life_AddBusinessDemand(LIFE_BUSINESS_COMMERCE, 1, "mercado abastecido por trabalhador");
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_WORK, 1);
    Life_SaveMarketStock();
    if (demandPercent >= 0)
    {
        format(message, sizeof(message), "Mercado comprou %d unidade(s) de %s. Recebido: $%d | demanda +%d%% | bonus %d%%.", gCfgMarketDeliveryStock, gMarketNames[item], pay, demandPercent, bonusPercent);
    }
    else
    {
        format(message, sizeof(message), "Mercado comprou %d unidade(s) de %s. Recebido: $%d | demanda %d%% | bonus %d%%.", gCfgMarketDeliveryStock, gMarketNames[item], pay, demandPercent, bonusPercent);
    }
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(logLine, sizeof(logLine), "market_sale item=%d stock=%d pay=%d demand=%d bonus=%d", item, gMarketStock[item], pay, demandPercent, bonusPercent);
    WritePlayerLog(LOG_CONTRACT_FILE, "ECONOMY_MARKET", playerid, logLine);
    return 1;
}

stock Life_UpdateJusticeCase(playerid, notify = 0)
{
    new today = GetBrasiliaDayStamp();
    new amount;

    if (!Life_HasOpenJusticeRisk(playerid))
    {
        return 0;
    }

    if (PlayerInfo[playerid][pJusticeDeadlineDay] <= 0)
    {
        PlayerInfo[playerid][pJusticeDeadlineDay] = today + 3;
        SaveAccountData(playerid, 0);
        return 1;
    }

    if (today <= PlayerInfo[playerid][pJusticeDeadlineDay])
    {
        return 0;
    }

    amount = Cfg_Fine(gCfgJusticeSentenceBase / 2);
    PlayerInfo[playerid][pJusticeFineDue] += amount;
    PlayerInfo[playerid][pJusticeStatus] = JUSTICE_STATUS_HEARING;
    PlayerInfo[playerid][pJusticeHearingDay] = today + 1;
    PlayerInfo[playerid][pJusticeDeadlineDay] = today + 2;
    PlayerInfo[playerid][pBankBadHistory]++;
    Life_GetBankScore(playerid);
    SaveAccountData(playerid, 0);
    WritePlayerLog(LOG_PUNISH_FILE, "JUSTICE_DEADLINE", playerid, "prazo vencido gerou audiencia automatica");
    if (notify)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Prazo judicial vencido: audiencia automatica marcada e taxa registrada.");
    }
    return 1;
}

stock Life_ShowJusticeDialog(playerid)
{
    new list[512];
    new line[128];
    new days[32];
    new deadline[32];

    Life_UpdateJusticeCase(playerid, 0);
    Life_FormatDays(PlayerInfo[playerid][pJusticeHearingDay], days, sizeof(days));
    Life_FormatDays(PlayerInfo[playerid][pJusticeDeadlineDay], deadline, sizeof(deadline));
    format(list, sizeof(list), "Acao\tStatus\n");
    format(line, sizeof(line), "Ver processo\tCasos %d | Provas %d | Mandados %d | Prazo %s | Sentenca $%d\n", PlayerInfo[playerid][pJusticeCases], PlayerInfo[playerid][pJusticeActiveEvidence], PlayerInfo[playerid][pJusticeActiveWarrants], deadline, PlayerInfo[playerid][pJusticeFineDue]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Registrar BO\t$%d\n", Cfg_Price(gCfgJusticeReportCost)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Solicitar audiencia\t$%d | %s\n", Cfg_Price(gCfgJusticeHearingCost), days); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Contratar advogado\t$%d\n", Cfg_Price(gCfgJusticeLawyerCost)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Realizar audiencia NPC\t%s\n", PlayerInfo[playerid][pJusticeHearingDay] > 0 ? ("disponivel na data") : ("sem audiencia")); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Recorrer sentenca\tusado %d vez(es)\n", PlayerInfo[playerid][pJusticeAppeals]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Pagar sentenca\t$%d\n", PlayerInfo[playerid][pJusticeFineDue]); strcat(list, line, sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_LIFE_JUSTICE, DIALOG_STYLE_TABLIST_HEADERS, "Justica", list, "Selecionar", "Fechar");
    return 1;
}

stock Life_GetJusticeStatusName(status, output[], size = sizeof(output))
{
    switch (status)
    {
        case JUSTICE_STATUS_OPEN: format(output, size, "aberto");
        case JUSTICE_STATUS_INVESTIGATING: format(output, size, "investigando");
        case JUSTICE_STATUS_HEARING: format(output, size, "audiencia");
        case JUSTICE_STATUS_RESOLVED: format(output, size, "resolvido");
        default: format(output, size, "sem caso");
    }
    return 1;
}

stock Life_ShowCases(playerid)
{
    new targetid;
    new maxPlayers = GetMaxPlayers();
    new name[MAX_PLAYER_NAME + 1];
    new statusName[24];
    new message[180];
    new shown;

    if (!IsLawEnforcementJob(PlayerInfo[playerid][pJob]) && PlayerInfo[playerid][pJob] != JOB_JUIZ && !HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return SendClientMessage(playerid, COLOR_RED, "Apenas policia, juiz ou staff podem consultar casos.");
    }

    SendClientMessage(playerid, COLOR_BLUE, "Casos judiciais online:");
    for (targetid = 0; targetid < maxPlayers; targetid++)
    {
        if (!IsPlayerConnected(targetid) || !PlayerInfo[targetid][pLogged] || PlayerInfo[targetid][pJusticeCases] <= 0)
        {
            continue;
        }

        GetPlayerNameEx(targetid, name, sizeof(name));
        Life_GetJusticeStatusName(PlayerInfo[targetid][pJusticeStatus], statusName, sizeof(statusName));
        format(message, sizeof(message), "%s(ID %d): casos %d | status %s | provas %d | mandados %d | prazo %d | sentenca $%d | ficha %d", name, targetid, PlayerInfo[targetid][pJusticeCases], statusName, PlayerInfo[targetid][pJusticeActiveEvidence], PlayerInfo[targetid][pJusticeActiveWarrants], PlayerInfo[targetid][pJusticeDeadlineDay], PlayerInfo[targetid][pJusticeFineDue], PlayerInfo[targetid][pCriminalRecords]);
        SendClientMessage(playerid, COLOR_BLUE, message);
        shown++;
    }

    if (!shown)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Nenhum caso online no momento.");
    }
    return 1;
}

stock Life_RegisterPoliceReportEx(playerid, details[])
{
    new logLine[256];

    if (!Bank_TakePayment(playerid, Cfg_Price(gCfgJusticeReportCost), 0))
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para registrar BO.");
        return 1;
    }

    PlayerInfo[playerid][pJusticeCases]++;
    PlayerInfo[playerid][pJusticeStatus] = JUSTICE_STATUS_OPEN;
    PlayerInfo[playerid][pJusticeDeadlineDay] = GetBrasiliaDayStamp() + 3;
    PlayerInfo[playerid][pJusticeAppeals] = 0;
    PlayerInfo[playerid][pJusticeActiveEvidence] = 1;
    SaveAccountData(playerid, 0);
    format(logLine, sizeof(logLine), "bo=%d status=aberto deadline=%d desc=%s", PlayerInfo[playerid][pJusticeCases], PlayerInfo[playerid][pJusticeDeadlineDay], details);
    WritePlayerLog(LOG_PUNISH_FILE, "POLICE_REPORT", playerid, logLine);
    WritePlayerLog(JUSTICE_CASES_FILE, "BO", playerid, logLine);
    SendClientMessage(playerid, COLOR_GREEN, "Boletim registrado com descricao. Investigacao aberta com prazo de 3 dias do servidor.");
    return 1;
}

stock Life_RegisterPoliceReport(playerid)
{
    return Life_RegisterPoliceReportEx(playerid, "BO registrado pelo cidadao");
}

stock Life_RequestHearing(playerid)
{
    if (!Bank_TakePayment(playerid, Cfg_Price(gCfgJusticeHearingCost), 0))
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para solicitar audiencia.");
        return 1;
    }

    PlayerInfo[playerid][pJusticeHearingDay] = GetBrasiliaDayStamp() + 1;
    PlayerInfo[playerid][pJusticeStatus] = JUSTICE_STATUS_HEARING;
    PlayerInfo[playerid][pJusticeDeadlineDay] = GetBrasiliaDayStamp() + 2;
    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Audiencia marcada para o proximo dia do servidor.");
    return 1;
}

stock Life_HireLawyer(playerid)
{
    if (!Bank_TakePayment(playerid, Cfg_Price(gCfgJusticeLawyerCost), 0))
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para contratar advogado.");
        return 1;
    }

    if (PlayerInfo[playerid][pJusticeFineDue] > 0)
    {
        PlayerInfo[playerid][pJusticeFineDue] -= PlayerInfo[playerid][pJusticeFineDue] / 3;
    }
    PlayerInfo[playerid][pJusticeSentence] = 1;
    PlayerInfo[playerid][pJusticeStatus] = JUSTICE_STATUS_INVESTIGATING;
    PlayerInfo[playerid][pJusticeDeadlineDay] = GetBrasiliaDayStamp() + 3;
    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Advogado contratado. Risco/valor de sentenca foi reduzido.");
    return 1;
}

stock Life_RunHearing(playerid)
{
    new fine;
    new message[128];

    if (PlayerInfo[playerid][pJusticeHearingDay] <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui audiencia marcada.");
        return 1;
    }

    if (PlayerInfo[playerid][pJusticeHearingDay] > GetBrasiliaDayStamp())
    {
        SendClientMessage(playerid, COLOR_GRAY, "Sua audiencia ainda nao chegou.");
        return 1;
    }

    fine = Cfg_Fine(gCfgJusticeSentenceBase
        + (PlayerInfo[playerid][pWanted] * 400)
        + (PlayerInfo[playerid][pCriminalRecords] * 350)
        + (PlayerInfo[playerid][pJusticeActiveEvidence] * 250)
        + (PlayerInfo[playerid][pJusticeActiveWarrants] * 300));
    if (PlayerInfo[playerid][pJusticeSentence])
    {
        fine -= fine / 3;
    }
    if (fine < 0)
    {
        fine = 0;
    }

    PlayerInfo[playerid][pJusticeFineDue] += fine;
    if (fine > 0)
    {
        PlayerInfo[playerid][pCriminalRecords]++;
    }
    PlayerInfo[playerid][pJusticeHearingDay] = 0;
    PlayerInfo[playerid][pJusticeSentence] = 0;
    PlayerInfo[playerid][pWanted] = 0;
    PlayerInfo[playerid][pJusticeStatus] = JUSTICE_STATUS_RESOLVED;
    PlayerInfo[playerid][pJusticeDeadlineDay] = 0;
    PlayerInfo[playerid][pJusticeActiveEvidence] = 0;
    PlayerInfo[playerid][pJusticeActiveWarrants] = 0;
    Life_GetBankScore(playerid);
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Audiencia finalizada. Sentenca financeira: $%d.", fine);
    SendClientMessage(playerid, COLOR_ORANGE, message);
    format(message, sizeof(message), "hearing fine=%d records=%d score=%d", fine, PlayerInfo[playerid][pCriminalRecords], PlayerInfo[playerid][pBankScore]);
    WritePlayerLog(LOG_PUNISH_FILE, "JUSTICE", playerid, message);
    return 1;
}

stock Life_AppealSentence(playerid)
{
    new reduce;
    new message[128];

    if (PlayerInfo[playerid][pJusticeFineDue] <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui sentenca financeira para recorrer.");
        return 1;
    }

    if (PlayerInfo[playerid][pJusticeAppeals] >= 2)
    {
        SendClientMessage(playerid, COLOR_RED, "Limite de recursos atingido neste caso.");
        return 1;
    }

    if (!Bank_TakePayment(playerid, Cfg_Price(gCfgJusticeLawyerCost / 2), 0))
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para preparar recurso.");
        return 1;
    }

    reduce = PlayerInfo[playerid][pJusticeFineDue] / 4;
    if (reduce < 1)
    {
        reduce = 1;
    }

    PlayerInfo[playerid][pJusticeFineDue] -= reduce;
    if (PlayerInfo[playerid][pJusticeFineDue] < 0)
    {
        PlayerInfo[playerid][pJusticeFineDue] = 0;
    }
    PlayerInfo[playerid][pJusticeAppeals]++;
    PlayerInfo[playerid][pJusticeStatus] = JUSTICE_STATUS_INVESTIGATING;
    PlayerInfo[playerid][pJusticeDeadlineDay] = GetBrasiliaDayStamp() + 2;
    PlayerInfo[playerid][pBankGoodHistory]++;
    Life_GetBankScore(playerid);
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Recurso aceito: sentenca reduzida em $%d. Novo valor: $%d.", reduce, PlayerInfo[playerid][pJusticeFineDue]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_PUNISH_FILE, "JUSTICE_APPEAL", playerid, message);
    return 1;
}

stock Life_ShowHealthDialog(playerid)
{
    new list[512];
    new line[128];
    new injuryName[32];
    new days[32];
    new Float:health;

    GetPlayerHealth(playerid, health);
    Hospital_GetInjuryName(PlayerInfo[playerid][pInjury], injuryName, sizeof(injuryName));
    Life_FormatDays(PlayerInfo[playerid][pHealthPlanExpire], days, sizeof(days));
    format(list, sizeof(list), "Acao\tStatus\n");
    format(line, sizeof(line), "Prontuario\tSaude %.0f | %s | gravidade %d\n", health, injuryName, PlayerInfo[playerid][pMedicalSeverity]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Comprar remedio\t$%d\n", Cfg_Price(gCfgMedicineCost)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Cirurgia/Tratamento avancado\t$%d\n", Cfg_Price(gCfgSurgeryCost)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Chamar ambulancia NPC\t$%d\n", Cfg_Price(gCfgAmbulanceCost)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Plano de saude\t%s\n", PlayerInfo[playerid][pHealthPlan] ? days : ("pendente")); strcat(list, line, sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_LIFE_HEALTH, DIALOG_STYLE_TABLIST_HEADERS, "Saude real", list, "Selecionar", "Fechar");
    return 1;
}

stock Life_UseMedicine(playerid)
{
    new Float:health;

    if (!Bank_TakePayment(playerid, Cfg_Price(gCfgMedicineCost), 0))
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para comprar remedio.");
        return 1;
    }

    GetPlayerHealth(playerid, health);
    health += 25.0;
    if (health > 100.0) health = 100.0;
    SetPlayerHealth(playerid, health);
    if (PlayerInfo[playerid][pInjury] == 1) PlayerInfo[playerid][pInjury] = 0;
    if (PlayerInfo[playerid][pMedicalSeverity] > 0) PlayerInfo[playerid][pMedicalSeverity]--;
    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Remedio comprado e utilizado. Ferimentos leves foram reduzidos.");
    return 1;
}

stock Life_DoSurgery(playerid)
{
    if (!Bank_TakePayment(playerid, Cfg_Price(gCfgSurgeryCost), 0))
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para cirurgia.");
        return 1;
    }

    PlayerInfo[playerid][pInjury] = 0;
    PlayerInfo[playerid][pMedicalSeverity] = 0;
    PlayerInfo[playerid][pMedicalTreatmentDue] = 0;
    SetPlayerHealth(playerid, 100.0);
    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Cirurgia concluida. Prontuario atualizado.");
    return 1;
}

stock Life_CallAmbulance(playerid)
{
    if (!Bank_TakePayment(playerid, Cfg_Price(gCfgAmbulanceCost), 0))
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para ambulancia NPC.");
        return 1;
    }

    SetPlayerToLocation(playerid, LOCATION_HOSPITAL);
    PlayerInfo[playerid][pMedicalTreatmentDue] = 1;
    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Ambulancia NPC levou voce ao hospital. Procure atendimento.");
    return 1;
}

stock Life_GetBusinessName(type, output[], size = sizeof(output))
{
    switch (type)
    {
        case LIFE_BUSINESS_COMMERCE: format(output, size, "Comercio");
        case LIFE_BUSINESS_WORKSHOP: format(output, size, "Oficina");
        case LIFE_BUSINESS_TRANSPORT: format(output, size, "Transportadora");
        case LIFE_BUSINESS_RESTAURANT: format(output, size, "Restaurante/Bar");
        case LIFE_BUSINESS_HOTEL: format(output, size, "Hotel");
        case LIFE_BUSINESS_FACTORY: format(output, size, "Fabrica");
        case LIFE_BUSINESS_REAL_ESTATE: format(output, size, "Imobiliaria");
        case LIFE_BUSINESS_ACCOUNTING: format(output, size, "Escritorio Contabil");
        default: format(output, size, "Nenhuma");
    }
    return 1;
}

stock Life_GetBusinessTypeForJob(jobid)
{
    switch (jobid)
    {
        case JOB_CAIXA_REPOSITOR, JOB_VENDEDOR, JOB_ENTREGADOR, JOB_FRENTISTA, JOB_PESCADOR, JOB_FARMACEUTICO, JOB_BANCARIO:
        {
            return LIFE_BUSINESS_COMMERCE;
        }
        case JOB_GARCOM, JOB_COZINHEIRO, JOB_BARTENDER, JOB_PADEIRO_PIZZAIOLO, JOB_MOTOBOY:
        {
            return LIFE_BUSINESS_RESTAURANT;
        }
        case JOB_MECANICO, JOB_GUINCHEIRO, JOB_TECNICO, JOB_ENCANADOR:
        {
            return LIFE_BUSINESS_WORKSHOP;
        }
        case JOB_RECEPCIONISTA_HOTEL, JOB_ZELADOR, JOB_JARDINEIRO:
        {
            return LIFE_BUSINESS_HOTEL;
        }
        case JOB_OPERADOR_FABRICA, JOB_MINERADOR, JOB_PEDREIRO, JOB_AGRICULTOR:
        {
            return LIFE_BUSINESS_FACTORY;
        }
        case JOB_CAMINHONEIRO, JOB_TAXISTA, JOB_MOTORISTA_ONIBUS, JOB_CARTEIRO, JOB_MOTORISTA_APP:
        {
            return LIFE_BUSINESS_TRANSPORT;
        }
        case JOB_CORRETOR_IMOVEIS:
        {
            return LIFE_BUSINESS_REAL_ESTATE;
        }
        case JOB_CONTADOR:
        {
            return LIFE_BUSINESS_ACCOUNTING;
        }
    }
    return LIFE_BUSINESS_NONE;
}

stock Life_GetBusinessSectorJobs(type, output[], size = sizeof(output))
{
    switch (type)
    {
        case LIFE_BUSINESS_COMMERCE: format(output, size, "Caixa/Repositor, Vendedor, Entregador, Bancario");
        case LIFE_BUSINESS_RESTAURANT: format(output, size, "Garcom, Cozinheiro, Bartender, Padeiro/Pizzaiolo");
        case LIFE_BUSINESS_WORKSHOP: format(output, size, "Mecanico, Guincheiro, Tecnico, Encanador");
        case LIFE_BUSINESS_HOTEL: format(output, size, "Recepcionista Hotel, Zelador, Jardineiro");
        case LIFE_BUSINESS_FACTORY: format(output, size, "Operador Fabrica, Minerador, Pedreiro, Agricultor");
        case LIFE_BUSINESS_TRANSPORT: format(output, size, "Caminhoneiro, Taxista, Motorista de Onibus/App, Carteiro");
        case LIFE_BUSINESS_REAL_ESTATE: format(output, size, "Corretor de Imoveis");
        case LIFE_BUSINESS_ACCOUNTING: format(output, size, "Contador");
        default: format(output, size, "sem profissao vinculada");
    }
    return 1;
}

stock Life_GetBusinessAddress(playerid, output[], size = sizeof(output))
{
    new slot = PlayerInfo[playerid][pBusinessEditorLoc] - 1;

    if (PlayerInfo[playerid][pBusinessEditorLoc] > 0 && Prop_EditorGetLocationName(slot, output, size))
    {
        return 1;
    }
    format(output, size, "Sem endereco fisico");
    return 0;
}

stock Life_PlayerAtBusinessAddress(playerid)
{
    if (PlayerInfo[playerid][pBusinessEditorLoc] <= 0)
    {
        return 0;
    }
    return Prop_EditorPlayerAtBusiness(playerid, PlayerInfo[playerid][pBusinessEditorLoc]);
}

stock Life_GetMarketDemandPercent(item)
{
    new defaultStock;
    new percent;

    if (item < 0 || item >= LIFE_MARKET_ITEMS)
    {
        return 0;
    }

    defaultStock = gMarketDefaults[item];
    if (defaultStock <= 0)
    {
        defaultStock = 1;
    }

    if (gMarketStock[item] <= gCfgMarketLowStock)
    {
        percent += 60;
    }
    else if (gMarketStock[item] <= gCfgMarketLowStock * 2)
    {
        percent += 25;
    }
    else if (gMarketStock[item] >= defaultStock * 2)
    {
        percent -= 30;
    }
    else if (gMarketStock[item] >= defaultStock + (defaultStock / 2))
    {
        percent -= 12;
    }

    if (gCityEventType == CITY_EVENT_STOCK && Life_CityEventActive() && gCityEventTargetItem == item)
    {
        percent += 30;
    }

    return percent;
}

stock Life_GetMarketSellPay(playerid, item)
{
    new pay;
    new demandPercent;
    new bonusPercent;

    if (item < 0 || item >= LIFE_MARKET_ITEMS)
    {
        return 0;
    }

    pay = Cfg_GetJobPay(PlayerInfo[playerid][pJob], gCfgMarketSellPay);
    demandPercent = Life_GetMarketDemandPercent(item);
    if (demandPercent != 0)
    {
        pay += (pay * demandPercent) / 100;
    }

    bonusPercent = Life_GetJobPayBonusPercent(playerid, PlayerInfo[playerid][pJob]);
    if (bonusPercent > 0)
    {
        pay += (pay * bonusPercent) / 100;
    }
    if (pay < 50)
    {
        pay = 50;
    }
    return pay;
}

stock Life_GetFuelPricePercent()
{
    new item = Life_GetLogisticsMarketItem(LIFE_LOGISTICS_FUEL);
    new demandPercent;

    if (item < 0)
    {
        return 100;
    }

    demandPercent = Life_GetMarketDemandPercent(item);
    if (demandPercent > 0)
    {
        return 100 + (demandPercent / 2);
    }
    if (demandPercent < 0)
    {
        return 100 + (demandPercent / 3);
    }
    return 100;
}

stock Life_FormatMarketStatus(item, output[], size)
{
    new demandPercent = Life_GetMarketDemandPercent(item);

    if (item < 0 || item >= LIFE_MARKET_ITEMS)
    {
        format(output, size, "invalido");
        return 0;
    }

    if (gMarketStock[item] <= gCfgMarketLowStock)
    {
        format(output, size, "baixo | demanda +%d%%", demandPercent);
    }
    else if (demandPercent < 0)
    {
        format(output, size, "excesso | demanda %d%%", demandPercent);
    }
    else
    {
        format(output, size, "normal | demanda +%d%%", demandPercent);
    }
    return 1;
}

stock Life_GetBusinessHealthScore(playerid)
{
    new score = 50;

    if (PlayerInfo[playerid][pBusinessType] == LIFE_BUSINESS_NONE)
    {
        return 0;
    }

    score += PlayerInfo[playerid][pBusinessEmployees] * 4;
    score += PlayerInfo[playerid][pBusinessContracts] / 2;
    score += PlayerInfo[playerid][pBusinessStock];
    if (PlayerInfo[playerid][pBusinessOrders] > 0) score += 8;
    if (PlayerInfo[playerid][pBusinessBalance] >= Cfg_Price(gCfgBusinessSalaryCost)) score += 8;
    score -= PlayerInfo[playerid][pBusinessDebt] / 1000;
    score -= PlayerInfo[playerid][pBusinessTaxDue] / 1200;
    if (PlayerInfo[playerid][pBusinessBankrupt]) score -= 45;
    if (PlayerInfo[playerid][pBusinessStock] <= 0) score -= 20;

    if (score < 0) score = 0;
    if (score > 100) score = 100;
    return score;
}

stock Life_GetBusinessContractLimit(playerid)
{
    new limit = 2500;
    new health = Life_GetBusinessHealthScore(playerid);

    if (PlayerInfo[playerid][pBusinessType] == LIFE_BUSINESS_NONE || PlayerInfo[playerid][pBusinessBankrupt])
    {
        return 0;
    }

    limit += PlayerInfo[playerid][pBusinessEmployees] * 1500;
    limit += PlayerInfo[playerid][pBusinessStock] * 80;
    limit += health * 85;
    limit += PlayerInfo[playerid][pBankScore] * 10;
    if (PlayerInfo[playerid][pBusinessBalance] > 0)
    {
        limit += PlayerInfo[playerid][pBusinessBalance] / 2;
    }
    if (PlayerInfo[playerid][pBusinessDebt] > 0)
    {
        limit -= PlayerInfo[playerid][pBusinessDebt] / 2;
    }
    if (limit < 500) limit = 500;
    if (limit > 50000) limit = 50000;
    return limit;
}

stock Life_BizMarketItem(type)
{
    switch (type)
    {
        case LIFE_BUSINESS_COMMERCE: return 0;
        case LIFE_BUSINESS_WORKSHOP: return 3;
        case LIFE_BUSINESS_TRANSPORT: return 4;
        case LIFE_BUSINESS_RESTAURANT: return 1;
        case LIFE_BUSINESS_HOTEL: return 5;
        case LIFE_BUSINESS_FACTORY: return 5;
        case LIFE_BUSINESS_REAL_ESTATE: return 5;
        case LIFE_BUSINESS_ACCOUNTING: return 5;
    }
    return -1;
}

stock Life_GetBusinessOperatingCost(playerid)
{
    new amount;

    if (PlayerInfo[playerid][pBusinessType] == LIFE_BUSINESS_NONE)
    {
        return 0;
    }

    amount = 250;
    amount += Cfg_Price(gCfgBusinessSalaryCost) * PlayerInfo[playerid][pBusinessEmployees];
    amount += PlayerInfo[playerid][pBusinessStock] * 10;
    amount += PlayerInfo[playerid][pBusinessOrders] * 40;

    switch (PlayerInfo[playerid][pBusinessType])
    {
        case LIFE_BUSINESS_COMMERCE: amount += 260;
        case LIFE_BUSINESS_WORKSHOP: amount += 420;
        case LIFE_BUSINESS_TRANSPORT: amount += 520;
        case LIFE_BUSINESS_RESTAURANT: amount += 360;
        case LIFE_BUSINESS_HOTEL: amount += 480;
        case LIFE_BUSINESS_FACTORY: amount += 620;
        case LIFE_BUSINESS_REAL_ESTATE: amount += 340;
        case LIFE_BUSINESS_ACCOUNTING: amount += 300;
    }
    if (PlayerInfo[playerid][pJob] == JOB_CONTADOR || PlayerInfo[playerid][pBusinessType] == LIFE_BUSINESS_ACCOUNTING)
    {
        amount -= amount / 10;
    }

    if (PlayerInfo[playerid][pBusinessEditorLoc] > 0)
    {
        amount += 120;
    }
    if (Life_IsPublicWorkDone(LIFE_PUBLIC_WORK_HYDRO))
    {
        amount -= amount / 10;
    }
    if (Life_IsPublicWorkDone(LIFE_PUBLIC_WORK_SOLAR))
    {
        amount -= amount / 20;
    }
    if (amount < 150)
    {
        amount = 150;
    }
    return amount;
}

stock Life_WriteBusinessDeepSnapshot(playerid, category[])
{
    new logLine[256];
    new businessName[32];
    new address[48];
    new item;
    new demand;

    if (PlayerInfo[playerid][pBusinessType] == LIFE_BUSINESS_NONE)
    {
        return 0;
    }

    Life_GetBusinessName(PlayerInfo[playerid][pBusinessType], businessName, sizeof(businessName));
    Life_GetBusinessAddress(playerid, address, sizeof(address));
    item = Life_BizMarketItem(PlayerInfo[playerid][pBusinessType]);
    demand = item >= 0 ? Life_GetMarketDemandPercent(item) : 0;
    format(logLine, sizeof(logLine), "business=%s loc=%d address=%s balance=%d stock=%d orders=%d employees=%d tax=%d bill=%d debt=%d health=%d demand=%d category=%s",
        businessName,
        PlayerInfo[playerid][pBusinessEditorLoc],
        address,
        PlayerInfo[playerid][pBusinessBalance],
        PlayerInfo[playerid][pBusinessStock],
        PlayerInfo[playerid][pBusinessOrders],
        PlayerInfo[playerid][pBusinessEmployees],
        PlayerInfo[playerid][pBusinessTaxDue],
        PlayerInfo[playerid][pBillBusinessPayrollDue],
        PlayerInfo[playerid][pBusinessDebt],
        Life_GetBusinessHealthScore(playerid),
        demand,
        category);
    WritePlayerLog(BUSINESS_ECONOMY_FILE, "BUSINESS_DEEP", playerid, logLine);
    return 1;
}

stock Life_ShowBusinessDeepReport(playerid)
{
    new body[1200];
    new line[160];
    new businessName[32];
    new address[48];
    new marketText[64];
    new item;
    new cost;

    if (PlayerInfo[playerid][pBusinessType] == LIFE_BUSINESS_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao possui empresa para auditar.");
        return 1;
    }

    Life_GetBusinessName(PlayerInfo[playerid][pBusinessType], businessName, sizeof(businessName));
    Life_GetBusinessAddress(playerid, address, sizeof(address));
    item = Life_BizMarketItem(PlayerInfo[playerid][pBusinessType]);
    if (item >= 0)
    {
        Life_FormatMarketStatus(item, marketText, sizeof(marketText));
    }
    else
    {
        format(marketText, sizeof(marketText), "sem cadeia vinculada");
    }
    cost = Life_GetBusinessOperatingCost(playerid);

    format(body, sizeof(body), "Indicador\tValor\n");
    format(line, sizeof(line), "CNPJ\t%s | endereco %s\n", businessName, address); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Saude\t%d/100 | limite contrato $%d\n", Life_GetBusinessHealthScore(playerid), Life_GetBusinessContractLimit(playerid)); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Caixa\t$%d | imposto $%d | conta oper. $%d\n", PlayerInfo[playerid][pBusinessBalance], PlayerInfo[playerid][pBusinessTaxDue], PlayerInfo[playerid][pBillBusinessPayrollDue]); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Operacao\tfunc %d | estoque %d/%d | pedidos %d\n", PlayerInfo[playerid][pBusinessEmployees], PlayerInfo[playerid][pBusinessStock], LIFE_BUSINESS_MAX_STOCK, PlayerInfo[playerid][pBusinessOrders]); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Cadeia\t%s | custo mensal previsto $%d\n", marketText, cost); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Risco\tdivida $%d | falida %s | local %s\n", PlayerInfo[playerid][pBusinessDebt], PlayerInfo[playerid][pBusinessBankrupt] ? ("sim") : ("nao"), PlayerInfo[playerid][pBusinessEditorLoc] > 0 ? ("sim") : ("nao")); strcat(body, line, sizeof(body));

    Life_WriteBusinessDeepSnapshot(playerid, "report");
    ShowPlayerDialog(playerid, DIALOG_LIFE_ECONOMY, DIALOG_STYLE_TABLIST_HEADERS, "Empresa profunda v1.2", body, "Fechar", "");
    return 1;
}

stock Life_GenBizOpBill(playerid)
{
    new amount = Life_GetBusinessOperatingCost(playerid);
    new message[144];

    if (amount <= 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao possui empresa ativa.");
        return 1;
    }
    if (PlayerInfo[playerid][pBillBusinessPayrollDue] > 0)
    {
        format(message, sizeof(message), "Sua empresa ja possui conta operacional pendente: $%d.", PlayerInfo[playerid][pBillBusinessPayrollDue]);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        return 1;
    }

    PlayerInfo[playerid][pBillBusinessPayrollDue] = amount;
    if (PlayerInfo[playerid][pBillDueDay] <= 0)
    {
        PlayerInfo[playerid][pBillDueDay] = GetBrasiliaDayStamp() + gCfgBillDueDays;
    }
    SaveAccountData(playerid, 0);
    Life_WriteBusinessDeepSnapshot(playerid, "operating_bill");
    format(message, sizeof(message), "Fechamento v1.2 gerado: folha, luz, agua e operacao = $%d. Pague em /empresa ou /boletos.", amount);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Life_PayBusinessOperatingBill(playerid)
{
    new amount = PlayerInfo[playerid][pBillBusinessPayrollDue];
    new govAmount;
    new message[144];

    if (amount <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Empresa sem conta operacional pendente.");
        return 1;
    }

    if (PlayerInfo[playerid][pBusinessBalance] >= amount)
    {
        PlayerInfo[playerid][pBusinessBalance] -= amount;
    }
    else if (!Bank_TakePaymentReason(playerid, amount, 0, "business_operating_bill"))
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para pagar conta operacional da empresa.");
        return 1;
    }

    govAmount = amount / 4;
    PlayerInfo[playerid][pBillBusinessPayrollDue] = 0;
    PlayerInfo[playerid][pBankGoodHistory]++;
    if (govAmount > 0)
    {
        Life_AddGovernmentRevenue(govAmount, "business_utilities");
    }
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_BUSINESS, 2);
    Life_GetBankScore(playerid);
    SaveAccountData(playerid, 0);
    Life_WriteBusinessDeepSnapshot(playerid, "operating_bill_paid");
    format(message, sizeof(message), "Conta operacional paga: $%d. Parte virou arrecadacao publica de agua/luz.", amount);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Life_ApplyBusinessMarketImpact(ownerid, stockGain, reason[])
{
    new item;
    new logLine[128];

    item = Life_BizMarketItem(PlayerInfo[ownerid][pBusinessType]);
    if (item < 0)
    {
        return 0;
    }

    gMarketStock[item] += stockGain;
    if (gMarketStock[item] > gMarketDefaults[item] * 3)
    {
        gMarketStock[item] = gMarketDefaults[item] * 3;
    }
    Life_SaveMarketStock();
    format(logLine, sizeof(logLine), "market_impact item=%d stock_gain=%d stock=%d reason=%s", item, stockGain, gMarketStock[item], reason);
    WritePlayerLog(LOG_CONTRACT_FILE, "ECONOMY_STOCK", ownerid, logLine);
    Life_WriteBusinessDeepSnapshot(ownerid, reason);
    return 1;
}

stock Life_FindLogisticsDock(type)
{
    new dock;

    for (dock = 0; dock < LIFE_LOGISTICS_DOCKS; dock++)
    {
        if (gLogisticsDocks[dock][logisticsDockType] == type)
        {
            return dock;
        }
    }
    return -1;
}

stock Life_CreateLogisticsDocks()
{
    new dock;
    new label[128];

    for (dock = 0; dock < LIFE_LOGISTICS_DOCKS; dock++)
    {
        format(label, sizeof(label), "%s\nCARREGAMENTO LOGISTICO\nCaminhoneiro: /carregarcarga", gLogisticsDocks[dock][logisticsDockName]);
        gLogisticsLoadLabel[dock] = Create3DTextLabel(label, COLOR_YELLOW, gLogisticsDocks[dock][logisticsLoadX], gLogisticsDocks[dock][logisticsLoadY], gLogisticsDocks[dock][logisticsLoadZ] + 1.2, 35.0, 0, 0);
        gLogisticsLoadObject[dock] = CreateObject(gLogisticsDocks[dock][logisticsObjectModel], gLogisticsDocks[dock][logisticsLoadX] + 1.4, gLogisticsDocks[dock][logisticsLoadY], gLogisticsDocks[dock][logisticsLoadZ] - 0.7, 0.0, 0.0, 0.0, 80.0);

        format(label, sizeof(label), "%s\nDESCARGA LOGISTICA\nCaminhoneiro: /descarregarcarga", gLogisticsDocks[dock][logisticsDockName]);
        gLogisticsUnloadLabel[dock] = Create3DTextLabel(label, COLOR_GREEN, gLogisticsDocks[dock][logisticsUnloadX], gLogisticsDocks[dock][logisticsUnloadY], gLogisticsDocks[dock][logisticsUnloadZ] + 1.2, 35.0, 0, 0);
        gLogisticsUnloadObject[dock] = CreateObject(gLogisticsDocks[dock][logisticsObjectModel], gLogisticsDocks[dock][logisticsUnloadX] - 1.4, gLogisticsDocks[dock][logisticsUnloadY], gLogisticsDocks[dock][logisticsUnloadZ] - 0.7, 0.0, 0.0, 0.0, 80.0);
    }
    return 1;
}

stock Life_DestroyLogisticsDocks()
{
    new dock;

    for (dock = 0; dock < LIFE_LOGISTICS_DOCKS; dock++)
    {
        if (gLogisticsLoadLabel[dock] != Text3D:INVALID_3DTEXT_ID)
        {
            Delete3DTextLabel(gLogisticsLoadLabel[dock]);
            gLogisticsLoadLabel[dock] = Text3D:INVALID_3DTEXT_ID;
        }
        if (gLogisticsUnloadLabel[dock] != Text3D:INVALID_3DTEXT_ID)
        {
            Delete3DTextLabel(gLogisticsUnloadLabel[dock]);
            gLogisticsUnloadLabel[dock] = Text3D:INVALID_3DTEXT_ID;
        }
        if (gLogisticsLoadObject[dock] != INVALID_OBJECT_ID && IsValidObject(gLogisticsLoadObject[dock]))
        {
            DestroyObject(gLogisticsLoadObject[dock]);
        }
        gLogisticsLoadObject[dock] = INVALID_OBJECT_ID;
        if (gLogisticsUnloadObject[dock] != INVALID_OBJECT_ID && IsValidObject(gLogisticsUnloadObject[dock]))
        {
            DestroyObject(gLogisticsUnloadObject[dock]);
        }
        gLogisticsUnloadObject[dock] = INVALID_OBJECT_ID;
    }
    return 1;
}

stock Life_ResetLogisticsOffer(playerid)
{
    gLogisticsOfferFrom[playerid] = INVALID_PLAYER_ID;
    gLogisticsOfferAmount[playerid] = 0;
    gLogisticsOfferType[playerid] = LIFE_LOGISTICS_NONE;
    gLogisticsOfferTick[playerid] = 0;
    return 1;
}

stock Life_ResetLogisticsActive(playerid)
{
    gLogisticsOwner[playerid] = INVALID_PLAYER_ID;
    gLogisticsAmount[playerid] = 0;
    gLogisticsType[playerid] = LIFE_LOGISTICS_NONE;
    gLogisticsStockGain[playerid] = 0;
    gLogisticsStage[playerid] = LIFE_LOGISTICS_STAGE_NONE;
    gLogisticsStartTick[playerid] = 0;
    return 1;
}

stock Life_CancelLogisticsContract(playerid, reason[])
{
    new message[144];

    if (gLogisticsType[playerid] != LIFE_LOGISTICS_NONE)
    {
        PlayerInfo[playerid][pLogisticsCanceled]++;
        Life_AddLogisticsReputation(playerid, -4);
        SaveAccountData(playerid, 0);
        format(message, sizeof(message), "cancel reason=%s canceled=%d rep=%d", reason, PlayerInfo[playerid][pLogisticsCanceled], PlayerInfo[playerid][pLogisticsReputation]);
        WritePlayerLog(LOG_CONTRACT_FILE, "LOGISTICS_CANCEL", playerid, message);
    }
    Life_ResetLogisticsOffer(playerid);
    Life_CancelLogisticsContract(playerid, "disconnect");
    DisablePlayerCheckpoint(playerid);
    return 1;
}

stock Life_GetLogisticsName(type, output[], size)
{
    switch (type)
    {
        case LIFE_LOGISTICS_MARKET: format(output, size, "Mercado/supermercado");
        case LIFE_LOGISTICS_FUEL: format(output, size, "Posto/combustivel");
        case LIFE_LOGISTICS_WORKSHOP: format(output, size, "Oficina/autopecas");
        case LIFE_LOGISTICS_BUILD: format(output, size, "Construtora/obra");
        default: format(output, size, "Carga logistica");
    }
    return 1;
}

stock Life_GetLogisticsTypeFromText(text[])
{
    if (strcmp(text, "mercado", true) == 0 || strcmp(text, "supermercado", true) == 0) return LIFE_LOGISTICS_MARKET;
    if (strcmp(text, "posto", true) == 0 || strcmp(text, "combustivel", true) == 0 || strcmp(text, "fuel", true) == 0) return LIFE_LOGISTICS_FUEL;
    if (strcmp(text, "oficina", true) == 0 || strcmp(text, "pecas", true) == 0) return LIFE_LOGISTICS_WORKSHOP;
    if (strcmp(text, "obra", true) == 0 || strcmp(text, "construtora", true) == 0 || strcmp(text, "materiais", true) == 0) return LIFE_LOGISTICS_BUILD;
    return LIFE_LOGISTICS_NONE;
}

stock Life_GetLogisticsMarketItem(type)
{
    switch (type)
    {
        case LIFE_LOGISTICS_MARKET: return 0;
        case LIFE_LOGISTICS_FUEL: return 4;
        case LIFE_LOGISTICS_WORKSHOP: return 3;
        case LIFE_LOGISTICS_BUILD: return 5;
    }
    return -1;
}

stock Life_LogisticsMatchesBusiness(ownerid, type)
{
    switch (type)
    {
        case LIFE_LOGISTICS_MARKET: return PlayerInfo[ownerid][pBusinessType] == LIFE_BUSINESS_COMMERCE;
        case LIFE_LOGISTICS_WORKSHOP: return PlayerInfo[ownerid][pBusinessType] == LIFE_BUSINESS_WORKSHOP;
        case LIFE_LOGISTICS_FUEL, LIFE_LOGISTICS_BUILD: return PlayerInfo[ownerid][pBusinessType] == LIFE_BUSINESS_TRANSPORT;
    }
    return 0;
}

stock Life_GetLogisticsStageName(stage, output[], size)
{
    switch (stage)
    {
        case LIFE_LOGISTICS_STAGE_ACCEPTED: format(output, size, "Aguardando coleta");
        case LIFE_LOGISTICS_STAGE_LOADED: format(output, size, "Carga carregada");
        case LIFE_LOGISTICS_STAGE_UNLOAD: format(output, size, "Aguardando descarga");
        default: format(output, size, "Sem frete ativo");
    }
    return 1;
}

stock Life_GetLogRepBonus(playerid)
{
    new rep = PlayerInfo[playerid][pLogisticsReputation];
    new percent;

    if (rep <= 0)
    {
        rep = 50;
    }
    percent = (rep - 50) / 5;
    if (percent > 10) percent = 10;
    if (percent < -10) percent = -10;
    return percent;
}

stock Life_AddLogisticsReputation(playerid, delta)
{
    PlayerInfo[playerid][pLogisticsReputation] += delta;
    if (PlayerInfo[playerid][pLogisticsReputation] < 0) PlayerInfo[playerid][pLogisticsReputation] = 0;
    if (PlayerInfo[playerid][pLogisticsReputation] > 100) PlayerInfo[playerid][pLogisticsReputation] = 100;
    return PlayerInfo[playerid][pLogisticsReputation];
}

stock Life_ShowLogisticsPanel(playerid)
{
    new body[1200];
    new line[160];
    new typeName[40];
    new stageName[32];
    new ownerName[32];
    new businessName[32];
    new dock;
    new item;
    new demandPercent;
    new demandBonus;
    new repBonus;
    new pid;
    new maxPlayers = GetMaxPlayers();
    new found;

    if (gLogisticsType[playerid] != LIFE_LOGISTICS_NONE)
    {
        dock = Life_FindLogisticsDock(gLogisticsType[playerid]);
        item = Life_GetLogisticsMarketItem(gLogisticsType[playerid]);
        demandPercent = item >= 0 ? Life_GetMarketDemandPercent(item) : 0;
        repBonus = Life_GetLogRepBonus(playerid);
        if (demandPercent > 0)
        {
            demandBonus = (gLogisticsAmount[playerid] * demandPercent) / 100;
        }
        Life_GetLogisticsName(gLogisticsType[playerid], typeName, sizeof(typeName));
        Life_GetLogisticsStageName(gLogisticsStage[playerid], stageName, sizeof(stageName));
        if (IsValidConnectedPlayer(gLogisticsOwner[playerid]) && PlayerInfo[gLogisticsOwner[playerid]][pLogged])
        {
            format(ownerName, sizeof(ownerName), "%s", PlayerInfo[gLogisticsOwner[playerid]][pCharacterName]);
            Life_GetBusinessName(PlayerInfo[gLogisticsOwner[playerid]][pBusinessType], businessName, sizeof(businessName));
        }
        else
        {
            format(ownerName, sizeof(ownerName), "Empresa offline");
            format(businessName, sizeof(businessName), "Indisponivel");
        }

        format(body, sizeof(body), "Frete ativo GovBR\n\n");
        format(line, sizeof(line), "Carga: %s\n", typeName); strcat(body, line, sizeof(body));
        format(line, sizeof(line), "Contratante: %s (%s)\n", ownerName, businessName); strcat(body, line, sizeof(body));
        format(line, sizeof(line), "Valor: $%d | bonus demanda estimado: $%d (%+d%%)\n", gLogisticsAmount[playerid], demandBonus, demandPercent); strcat(body, line, sizeof(body));
        format(line, sizeof(line), "Historico: %d entregas | %d atraso(s) | %d cancelada(s) | rep %d/100 (%+d%%)\n", PlayerInfo[playerid][pLogisticsCompleted], PlayerInfo[playerid][pLogisticsLate], PlayerInfo[playerid][pLogisticsCanceled], PlayerInfo[playerid][pLogisticsReputation], repBonus); strcat(body, line, sizeof(body));
        format(line, sizeof(line), "Faturamento logistico: $%d | fretes gerados por empresa: %d\n", PlayerInfo[playerid][pLogisticsEarnings], PlayerInfo[playerid][pLogisticsGenerated]); strcat(body, line, sizeof(body));
        format(line, sizeof(line), "Estoque previsto: +%d | status: %s\n\n", gLogisticsStockGain[playerid], stageName); strcat(body, line, sizeof(body));
        if (dock != -1)
        {
            format(line, sizeof(line), "Origem: %s - doca de carregamento\n", gLogisticsDocks[dock][logisticsDockName]); strcat(body, line, sizeof(body));
            format(line, sizeof(line), "Destino: %s - ponto de descarga\n\n", gLogisticsDocks[dock][logisticsDockName]); strcat(body, line, sizeof(body));
        }
        strcat(body, "Botao GPS: marca o proximo ponto correto da carga.", sizeof(body));
        ShowPlayerDialog(playerid, DIALOG_LOGISTICS_PANEL, DIALOG_STYLE_MSGBOX, "GovBR - Fretes logisticos", body, "GPS", "Fechar");
        return 1;
    }

    format(body, sizeof(body), "Fretes logisticos disponiveis\n\n");
    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged] || gLogisticsOfferFrom[pid] == INVALID_PLAYER_ID)
        {
            continue;
        }
        if ((GetTickCount() - gLogisticsOfferTick[pid]) > LIFE_LOGISTICS_OFFER_EXPIRE_MS)
        {
            continue;
        }
        if (!IsValidConnectedPlayer(gLogisticsOfferFrom[pid]) || !PlayerInfo[gLogisticsOfferFrom[pid]][pLogged])
        {
            continue;
        }
        item = Life_GetLogisticsMarketItem(gLogisticsOfferType[pid]);
        demandPercent = item >= 0 ? Life_GetMarketDemandPercent(item) : 0;
        Life_GetLogisticsName(gLogisticsOfferType[pid], typeName, sizeof(typeName));
        Life_GetBusinessName(PlayerInfo[gLogisticsOfferFrom[pid]][pBusinessType], businessName, sizeof(businessName));
        format(line, sizeof(line), "ID %d: %s | %s | $%d | demanda %+d%%\n", pid, typeName, businessName, gLogisticsOfferAmount[pid], demandPercent);
        strcat(body, line, sizeof(body));
        found++;
    }
    if (!found)
    {
        strcat(body, "Nenhum frete pendente agora.\n\nEmpresas podem gerar frete com /gerarcarga.", sizeof(body));
    }
    else
    {
        strcat(body, "\nPara aceitar uma proposta enviada para voce, use /aceitarcarga.", sizeof(body));
    }
    ShowPlayerDialog(playerid, DIALOG_LOGISTICS_PANEL, DIALOG_STYLE_MSGBOX, "GovBR - Fretes logisticos", body, "Atualizar", "Fechar");
    return 1;
}

stock Life_ShowLogisticsRanking(playerid)
{
    new list[2200];
    new line[180];
    new name[MAX_PLAYER_NAME];
    new bizName[32];
    new pid;
    new maxPlayers = GetMaxPlayers();
    new found;

    format(list, sizeof(list), "Categoria\tPlayer\tResultado\n");
    strcat(list, "Top entregas\t-\tCaminhoneiros online\n", sizeof(list));
    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged] || PlayerInfo[pid][pLogisticsCompleted] <= 0)
        {
            continue;
        }
        GetPlayerName(pid, name, sizeof(name));
        format(line, sizeof(line), "Entregas\t%s\t%d entrega(s) | rep %d/100\n", name, PlayerInfo[pid][pLogisticsCompleted], PlayerInfo[pid][pLogisticsReputation]);
        strcat(list, line, sizeof(list));
        found++;
    }
    if (!found)
    {
        strcat(list, "Entregas\tsem dados\tnenhum caminhoneiro online ranqueado\n", sizeof(list));
    }

    found = 0;
    strcat(list, "Melhor reputacao\t-\tCaminhoneiros online\n", sizeof(list));
    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged] || PlayerInfo[pid][pLogisticsReputation] <= 50)
        {
            continue;
        }
        GetPlayerName(pid, name, sizeof(name));
        format(line, sizeof(line), "Reputacao\t%s\t%d/100 | atraso %d | cancelada %d\n", name, PlayerInfo[pid][pLogisticsReputation], PlayerInfo[pid][pLogisticsLate], PlayerInfo[pid][pLogisticsCanceled]);
        strcat(list, line, sizeof(list));
        found++;
    }
    if (!found)
    {
        strcat(list, "Reputacao\tsem dados\tnenhum player acima de 50/100\n", sizeof(list));
    }

    found = 0;
    strcat(list, "Maior faturamento\t-\tFretes recebidos\n", sizeof(list));
    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged] || PlayerInfo[pid][pLogisticsEarnings] <= 0)
        {
            continue;
        }
        GetPlayerName(pid, name, sizeof(name));
        format(line, sizeof(line), "Faturamento\t%s\t$%d | %d entrega(s)\n", name, PlayerInfo[pid][pLogisticsEarnings], PlayerInfo[pid][pLogisticsCompleted]);
        strcat(list, line, sizeof(list));
        found++;
    }
    if (!found)
    {
        strcat(list, "Faturamento\tsem dados\tnenhum frete pago online\n", sizeof(list));
    }

    found = 0;
    strcat(list, "Empresas geradoras\t-\tFretes criados\n", sizeof(list));
    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged] || PlayerInfo[pid][pLogisticsGenerated] <= 0)
        {
            continue;
        }
        GetPlayerName(pid, name, sizeof(name));
        Life_GetBusinessName(PlayerInfo[pid][pBusinessType], bizName, sizeof(bizName));
        format(line, sizeof(line), "Empresa\t%s\t%s | %d frete(s) gerado(s)\n", name, bizName, PlayerInfo[pid][pLogisticsGenerated]);
        strcat(list, line, sizeof(list));
        found++;
    }
    if (!found)
    {
        strcat(list, "Empresa\tsem dados\tnenhuma empresa online gerou frete\n", sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_LOGISTICS_PANEL, DIALOG_STYLE_TABLIST_HEADERS, "Ranking logistico", list, "Fechar", "");
    return 1;
}

stock Life_GetAutoBusinessIndex(businessid)
{
    if (businessid <= 0 || businessid > LIFE_AUTO_BUSINESS_COUNT)
    {
        return -1;
    }
    return businessid - 1;
}

stock Life_FindAutoBusinessOwner(businessid)
{
    new pid;
    new maxPlayers = GetMaxPlayers();

    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (IsPlayerConnected(pid) && PlayerInfo[pid][pLogged] && PlayerInfo[pid][pAutoBusinessId] == businessid)
        {
            return pid;
        }
    }
    return INVALID_PLAYER_ID;
}

stock Life_ShowAutoBusinesses(playerid)
{
    new list[1400];
    new line[180];
    new bizName[32];
    new ownerid;
    new index;
    new ownerName[MAX_PLAYER_NAME];

    format(list, sizeof(list), "ID\tEmpresa\tPreco/Lucro\n");
    for (index = 0; index < LIFE_AUTO_BUSINESS_COUNT; index++)
    {
        ownerid = Life_FindAutoBusinessOwner(index + 1);
        Life_GetBusinessName(gAutoBusinesses[index][autoBizType], bizName, sizeof(bizName));
        if (ownerid != INVALID_PLAYER_ID)
        {
            GetPlayerName(ownerid, ownerName, sizeof(ownerName));
            format(line, sizeof(line), "%d\t%s (%s)\tDono: %s | lucro base $%d\n", index + 1, gAutoBusinesses[index][autoBizName], bizName, ownerName, gAutoBusinesses[index][autoBizBaseProfit]);
        }
        else
        {
            format(line, sizeof(line), "%d\t%s (%s)\t$%d | lucro base $%d\n", index + 1, gAutoBusinesses[index][autoBizName], bizName, gAutoBusinesses[index][autoBizPrice], gAutoBusinesses[index][autoBizBaseProfit]);
        }
        strcat(list, line, sizeof(list));
    }
    ShowPlayerDialog(playerid, DIALOG_LOGISTICS_PANEL, DIALOG_STYLE_TABLIST_HEADERS, "Empresas automaticas", list, "Fechar", "");
    SendClientMessage(playerid, COLOR_GRAY, "Use /comprarempresaauto [id], /minhaempresaauto e /resgatarlucro.");
    return 1;
}

stock Life_BuyAutoBusiness(playerid, businessid)
{
    new index = Life_GetAutoBusinessIndex(businessid);
    new message[144];
    new logLine[144];

    if (index == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Empresa automatica invalida.");
        return 1;
    }
    if (PlayerInfo[playerid][pAutoBusinessId] > 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce ja possui uma empresa automatica.");
        return 1;
    }
    if (Life_FindAutoBusinessOwner(businessid) != INVALID_PLAYER_ID)
    {
        SendClientMessage(playerid, COLOR_RED, "Esta empresa ja tem dono online.");
        return 1;
    }
    if (!Bank_TakePaymentReason(playerid, gAutoBusinesses[index][autoBizPrice], 0, "auto_business_buy"))
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para comprar esta empresa.");
        return 1;
    }

    PlayerInfo[playerid][pAutoBusinessId] = businessid;
    PlayerInfo[playerid][pAutoBusinessProfit] = 0;
    PlayerInfo[playerid][pAutoBusinessRevenue] = 0;
    PlayerInfo[playerid][pBusinessType] = gAutoBusinesses[index][autoBizType];
    if (PlayerInfo[playerid][pBusinessPermitExpire] <= 0)
    {
        PlayerInfo[playerid][pBusinessPermitExpire] = GetBrasiliaDayStamp() + gCfgBusinessPermitValidDays;
    }
    Life_AddGovernmentRevenue(gAutoBusinesses[index][autoBizPrice] / 20, "auto_business_buy");
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Empresa automatica comprada: %s. Lucros acumulam e podem ser resgatados.", gAutoBusinesses[index][autoBizName]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(logLine, sizeof(logLine), "auto_business_buy id=%d price=%d", businessid, gAutoBusinesses[index][autoBizPrice]);
    WritePlayerLog(LOG_CONTRACT_FILE, "AUTO_BUSINESS", playerid, logLine);
    return 1;
}

stock Life_ShowMyAutoBusiness(playerid)
{
    new index = Life_GetAutoBusinessIndex(PlayerInfo[playerid][pAutoBusinessId]);
    new message[144];
    new bizName[32];

    if (index == -1)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui empresa automatica. Veja /empresasauto.");
        return 1;
    }

    Life_GetBusinessName(gAutoBusinesses[index][autoBizType], bizName, sizeof(bizName));
    format(message, sizeof(message), "%s (%s) | lucro pendente $%d | receita total $%d.", gAutoBusinesses[index][autoBizName], bizName, PlayerInfo[playerid][pAutoBusinessProfit], PlayerInfo[playerid][pAutoBusinessRevenue]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Operacao automatica: estoque publico +%d a cada ciclo | lucro base $%d.", gAutoBusinesses[index][autoBizStockGain], gAutoBusinesses[index][autoBizBaseProfit]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}

stock Life_ShowMyBusinessPanel(playerid)
{
    new body[1200];
    new line[180];
    new businessName[32];
    new address[48];
    new sectorJobs[128];
    new payroll;
    new dailyProfit;
    new health;

    if (PlayerInfo[playerid][pBusinessType] == LIFE_BUSINESS_NONE)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Voce ainda nao tem CNPJ ativo. Abrindo painel de empresa automatica.");
        return Life_ShowMyAutoBusiness(playerid);
    }

    Life_GetBusinessName(PlayerInfo[playerid][pBusinessType], businessName, sizeof(businessName));
    Life_GetBusinessAddress(playerid, address, sizeof(address));
    Life_GetBusinessSectorJobs(PlayerInfo[playerid][pBusinessType], sectorJobs, sizeof(sectorJobs));
    payroll = Cfg_Price(gCfgBusinessSalaryCost) * PlayerInfo[playerid][pBusinessEmployees];
    dailyProfit = (PlayerInfo[playerid][pBusinessOrders] * Cfg_Price(gCfgBusinessRevenue)) - payroll - PlayerInfo[playerid][pBillBusinessPayrollDue];
    if (dailyProfit < 0) dailyProfit = 0;
    health = Life_GetBusinessHealthScore(playerid);

    format(body, sizeof(body), "Indicador\tValor\n");
    format(line, sizeof(line), "Ramo\t%s | %s\n", businessName, address); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Caixa\t$%d | lucro diario previsto $%d\n", PlayerInfo[playerid][pBusinessBalance], dailyProfit); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Funcionarios\t%d | folha $%d\n", PlayerInfo[playerid][pBusinessEmployees], payroll); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Profissoes\t%s\n", sectorJobs); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Estoque e pedidos\t%d/%d | pedidos %d\n", PlayerInfo[playerid][pBusinessStock], LIFE_BUSINESS_MAX_STOCK, PlayerInfo[playerid][pBusinessOrders]); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Impostos\t$%d | conta operacional $%d\n", PlayerInfo[playerid][pBusinessTaxDue], PlayerInfo[playerid][pBillBusinessPayrollDue]); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Reputacao\t%d/100 | contratos %d | limite $%d\n", health, PlayerInfo[playerid][pBusinessContracts], Life_GetBusinessContractLimit(playerid)); strcat(body, line, sizeof(body));
    format(line, sizeof(line), "Risco\tdivida $%d | falida %s\n", PlayerInfo[playerid][pBusinessDebt], PlayerInfo[playerid][pBusinessBankrupt] ? ("sim") : ("nao")); strcat(body, line, sizeof(body));

    Life_WriteBusinessDeepSnapshot(playerid, "panel_v15");
    ShowPlayerDialog(playerid, DIALOG_LIFE_ECONOMY, DIALOG_STYLE_TABLIST_HEADERS, "Minha empresa 2.0", body, "Fechar", "");
    return 1;
}

stock Life_ClaimAutoBusinessProfit(playerid)
{
    new amount = PlayerInfo[playerid][pAutoBusinessProfit];
    new message[144];
    new logLine[144];

    if (PlayerInfo[playerid][pAutoBusinessId] <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui empresa automatica.");
        return 1;
    }
    if (amount <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Sua empresa ainda nao tem lucro pendente.");
        return 1;
    }

    PlayerInfo[playerid][pAutoBusinessProfit] = 0;
    PlayerInfo[playerid][pBankMoney] += amount;
    Life_TrackGain(playerid, amount, 0, "auto_business_profit");
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Lucro da empresa resgatado no banco: $%d.", amount);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(logLine, sizeof(logLine), "auto_business_claim id=%d amount=%d bank=%d", PlayerInfo[playerid][pAutoBusinessId], amount, PlayerInfo[playerid][pBankMoney]);
    WritePlayerLog(LOG_MONEY_FILE, "AUTO_BUSINESS_PROFIT", playerid, logLine);
    return 1;
}

public Life_UpdateAutoBusinesses()
{
    new pid;
    new index;
    new item;
    new profit;
    new demandPercent;
    new maxPlayers = GetMaxPlayers();

    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged])
        {
            continue;
        }

        index = Life_GetAutoBusinessIndex(PlayerInfo[pid][pAutoBusinessId]);
        if (index == -1)
        {
            continue;
        }

        item = gAutoBusinesses[index][autoBizMarketItem];
        demandPercent = Life_GetMarketDemandPercent(item);
        profit = gAutoBusinesses[index][autoBizBaseProfit];
        if (demandPercent > 0)
        {
            profit += (profit * demandPercent) / 100;
        }
        if (PlayerInfo[pid][pBusinessStock] > 15)
        {
            profit += profit / 10;
        }
        if (PlayerInfo[pid][pBusinessDebt] > 0)
        {
            profit -= profit / 5;
        }
        if (profit < 100)
        {
            profit = 100;
        }

        PlayerInfo[pid][pAutoBusinessProfit] += profit;
        PlayerInfo[pid][pAutoBusinessRevenue] += profit;
        PlayerInfo[pid][pBusinessBalance] += profit / 2;
        PlayerInfo[pid][pBusinessTaxDue] += (profit * gCfgBusinessTaxPercent) / 100;
        PlayerInfo[pid][pBusinessOrders]++;
        if (PlayerInfo[pid][pBusinessOrders] > CITY_EVENT_MAX_ORDERS) PlayerInfo[pid][pBusinessOrders] = CITY_EVENT_MAX_ORDERS;
        PlayerInfo[pid][pBusinessStock] += gAutoBusinesses[index][autoBizStockGain];
        if (PlayerInfo[pid][pBusinessStock] > LIFE_BUSINESS_MAX_STOCK) PlayerInfo[pid][pBusinessStock] = LIFE_BUSINESS_MAX_STOCK;

        if (item >= 0 && item < LIFE_MARKET_ITEMS)
        {
            gMarketStock[item] += gAutoBusinesses[index][autoBizStockGain];
            if (gMarketStock[item] > gMarketDefaults[item] * 3)
            {
                gMarketStock[item] = gMarketDefaults[item] * 3;
            }
            Life_SaveMarketStock();
        }
        SaveAccountData(pid, 0);
    }
    return 1;
}

stock Life_LogisticsSetCheckpoint(playerid)
{
    new dock = Life_FindLogisticsDock(gLogisticsType[playerid]);
    new message[144];

    if (dock == -1)
    {
        return 0;
    }

    if (gLogisticsStage[playerid] == LIFE_LOGISTICS_STAGE_ACCEPTED)
    {
        SetPlayerCheckpoint(playerid, gLogisticsDocks[dock][logisticsLoadX], gLogisticsDocks[dock][logisticsLoadY], gLogisticsDocks[dock][logisticsLoadZ], LIFE_LOGISTICS_DOCK_RANGE);
        format(message, sizeof(message), "GPS da carga: va ate %s e use /carregarcarga.", gLogisticsDocks[dock][logisticsDockName]);
        SendClientMessage(playerid, COLOR_YELLOW, message);
        return 1;
    }

    if (gLogisticsStage[playerid] == LIFE_LOGISTICS_STAGE_LOADED)
    {
        SetPlayerCheckpoint(playerid, gLogisticsDocks[dock][logisticsUnloadX], gLogisticsDocks[dock][logisticsUnloadY], gLogisticsDocks[dock][logisticsUnloadZ], LIFE_LOGISTICS_DOCK_RANGE);
        format(message, sizeof(message), "GPS da entrega: %s. Conclua a rota de caminhoneiro antes de descarregar.", gLogisticsDocks[dock][logisticsDockName]);
        SendClientMessage(playerid, COLOR_YELLOW, message);
        return 1;
    }

    if (gLogisticsStage[playerid] == LIFE_LOGISTICS_STAGE_UNLOAD)
    {
        SetPlayerCheckpoint(playerid, gLogisticsDocks[dock][logisticsUnloadX], gLogisticsDocks[dock][logisticsUnloadY], gLogisticsDocks[dock][logisticsUnloadZ], LIFE_LOGISTICS_DOCK_RANGE);
        format(message, sizeof(message), "GPS da descarga: va ate %s e use /descarregarcarga.", gLogisticsDocks[dock][logisticsDockName]);
        SendClientMessage(playerid, COLOR_YELLOW, message);
        return 1;
    }
    return 0;
}

stock Life_LogisticsIsNearDock(playerid, stage)
{
    new dock = Life_FindLogisticsDock(gLogisticsType[playerid]);

    if (dock == -1)
    {
        return 0;
    }

    if (stage == LIFE_LOGISTICS_STAGE_ACCEPTED)
    {
        return IsPlayerInRangeOfPoint(playerid, LIFE_LOGISTICS_DOCK_RANGE, gLogisticsDocks[dock][logisticsLoadX], gLogisticsDocks[dock][logisticsLoadY], gLogisticsDocks[dock][logisticsLoadZ]);
    }
    if (stage == LIFE_LOGISTICS_STAGE_UNLOAD)
    {
        return IsPlayerInRangeOfPoint(playerid, LIFE_LOGISTICS_DOCK_RANGE, gLogisticsDocks[dock][logisticsUnloadX], gLogisticsDocks[dock][logisticsUnloadY], gLogisticsDocks[dock][logisticsUnloadZ]);
    }
    return 0;
}

stock Life_CanStartTruckLogistics(playerid)
{
    if (gLogisticsType[playerid] == LIFE_LOGISTICS_NONE)
    {
        return 1;
    }
    if (gLogisticsStage[playerid] == LIFE_LOGISTICS_STAGE_ACCEPTED)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Voce aceitou uma carga logistica. Carregue primeiro em /carregarcarga antes de iniciar a rota.");
        Life_LogisticsSetCheckpoint(playerid);
        return 0;
    }
    if (gLogisticsStage[playerid] == LIFE_LOGISTICS_STAGE_UNLOAD)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Voce ja finalizou a rota dessa carga. Descarregue em /descarregarcarga antes de novo frete.");
        Life_LogisticsSetCheckpoint(playerid);
        return 0;
    }
    return 1;
}

stock Life_LogisticsCommandStatus(playerid)
{
    new typeName[32];
    new message[144];

    if (gLogisticsType[playerid] == LIFE_LOGISTICS_NONE)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui carga logistica ativa. Veja /cargaslogisticas ou aguarde uma empresa gerar frete.");
        return 1;
    }

    Life_GetLogisticsName(gLogisticsType[playerid], typeName, sizeof(typeName));
    format(message, sizeof(message), "Carga atual: %s | frete $%d | estoque +%d | etapa %d/3.", typeName, gLogisticsAmount[playerid], gLogisticsStockGain[playerid], gLogisticsStage[playerid]);
    SendClientMessage(playerid, COLOR_YELLOW, message);
    Life_LogisticsSetCheckpoint(playerid);
    return 1;
}

stock Life_LoadLogisticsCargo(playerid)
{
    new typeName[32];
    new message[144];

    if (gLogisticsType[playerid] == LIFE_LOGISTICS_NONE || gLogisticsStage[playerid] != LIFE_LOGISTICS_STAGE_ACCEPTED)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao tem carga aguardando carregamento.");
        return 1;
    }
    if (PlayerInfo[playerid][pJob] != JOB_CAMINHONEIRO)
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas caminhoneiro pode carregar frete logistico.");
        return 1;
    }
    if (!Life_LogisticsIsNearDock(playerid, LIFE_LOGISTICS_STAGE_ACCEPTED))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar na doca de carregamento correta.");
        Life_LogisticsSetCheckpoint(playerid);
        return 1;
    }
    if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        SendClientMessage(playerid, COLOR_RED, "Estacione o caminhao na doca e fique como motorista.");
        return 1;
    }

    gLogisticsStage[playerid] = LIFE_LOGISTICS_STAGE_LOADED;
    Life_GetLogisticsName(gLogisticsType[playerid], typeName, sizeof(typeName));
    format(message, sizeof(message), "Carga carregada: %s. GPS marcou o ponto de entrega; conclua a rota antes de descarregar.", typeName);
    SendClientMessage(playerid, COLOR_GREEN, message);
    Life_LogisticsSetCheckpoint(playerid);
    WritePlayerLog(LOG_CONTRACT_FILE, "LOGISTICS_LOAD", playerid, message);
    return 1;
}

stock Life_MarkLogisticsReadyUnload(playerid)
{
    if (gLogisticsType[playerid] == LIFE_LOGISTICS_NONE)
    {
        return 0;
    }
    if (gLogisticsStage[playerid] != LIFE_LOGISTICS_STAGE_LOADED)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Frete logistico nao foi pago: carga nao passou pela doca de carregamento.");
        return 0;
    }

    gLogisticsStage[playerid] = LIFE_LOGISTICS_STAGE_UNLOAD;
    SendClientMessage(playerid, COLOR_YELLOW, "Rota concluida. Falta descarregar fisicamente a carga para receber o frete.");
    Life_LogisticsSetCheckpoint(playerid);
    return 1;
}

stock Life_ShowLogisticsBoard(playerid)
{
    new pid;
    new maxPlayers = GetMaxPlayers();
    new typeName[32];
    new businessName[32];
    new message[144];
    new found;

    SendClientMessage(playerid, COLOR_BLUE, "Cargas logisticas online:");
    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged] || gLogisticsOfferFrom[pid] == INVALID_PLAYER_ID)
        {
            continue;
        }
        if ((GetTickCount() - gLogisticsOfferTick[pid]) > LIFE_LOGISTICS_OFFER_EXPIRE_MS)
        {
            continue;
        }
        if (!IsValidConnectedPlayer(gLogisticsOfferFrom[pid]) || !PlayerInfo[gLogisticsOfferFrom[pid]][pLogged])
        {
            continue;
        }
        Life_GetLogisticsName(gLogisticsOfferType[pid], typeName, sizeof(typeName));
        Life_GetBusinessName(PlayerInfo[gLogisticsOfferFrom[pid]][pBusinessType], businessName, sizeof(businessName));
        format(message, sizeof(message), "ID %d: %s de %s | frete $%d | caminhoneiro deve usar /aceitarcarga.", pid, typeName, businessName, gLogisticsOfferAmount[pid]);
        SendClientMessage(playerid, COLOR_YELLOW, message);
        found++;
    }
    if (!found)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Nenhuma carga logistica pendente para caminhoneiros agora.");
    }
    return 1;
}

stock Life_OfferLogisticsContract(ownerid, targetid, type, amount)
{
    new message[160];
    new typeName[32];
    new demandPercent;
    new item;
    new limit;
    new repBonus;
    new baseAmount;

    Life_ResetDailyLimits(ownerid);
    if (PlayerInfo[ownerid][pBusinessType] == LIFE_BUSINESS_NONE)
    {
        SendClientMessage(ownerid, COLOR_RED, "Voce precisa ter empresa ativa para gerar carga logistica.");
        return 1;
    }
    if (PlayerInfo[ownerid][pBusinessBankrupt])
    {
        SendClientMessage(ownerid, COLOR_RED, "Empresa em falencia nao pode contratar frete.");
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid) || !PlayerInfo[targetid][pLogged] || targetid == ownerid)
    {
        SendClientMessage(ownerid, COLOR_RED, "Caminhoneiro invalido.");
        return 1;
    }
    if (PlayerInfo[targetid][pJob] != JOB_CAMINHONEIRO)
    {
        SendClientMessage(ownerid, COLOR_RED, "O jogador precisa ser caminhoneiro.");
        return 1;
    }
    if (type == LIFE_LOGISTICS_NONE || !Life_LogisticsMatchesBusiness(ownerid, type))
    {
        SendClientMessage(ownerid, COLOR_RED, "Tipo invalido para sua empresa. Comercio: mercado | Oficina: oficina | Transportadora: posto/obra.");
        return 1;
    }
    if (amount < 500 || amount > 30000)
    {
        SendClientMessage(ownerid, COLOR_RED, "Valor do frete deve ficar entre $500 e $30000.");
        return 1;
    }
    baseAmount = amount;
    repBonus = Life_GetLogRepBonus(targetid);
    amount += (amount * repBonus) / 100;
    if (amount < 500) amount = 500;
    if (amount > 30000) amount = 30000;
    limit = Life_GetBusinessContractLimit(ownerid);
    if (amount > limit)
    {
        format(message, sizeof(message), "Frete acima do limite economico da empresa. Limite atual: $%d.", limit);
        SendClientMessage(ownerid, COLOR_RED, message);
        return 1;
    }
    if (gLogisticsType[targetid] != LIFE_LOGISTICS_NONE)
    {
        SendClientMessage(ownerid, COLOR_RED, "Este caminhoneiro ja possui uma carga logistica ativa.");
        return 1;
    }

    gLogisticsOfferFrom[targetid] = ownerid;
    gLogisticsOfferAmount[targetid] = amount;
    gLogisticsOfferType[targetid] = type;
    gLogisticsOfferTick[targetid] = GetTickCount();
    PlayerInfo[ownerid][pLogisticsGenerated]++;
    SaveAccountData(ownerid, 0);
    item = Life_GetLogisticsMarketItem(type);
    demandPercent = item >= 0 ? Life_GetMarketDemandPercent(item) : 0;
    Life_GetLogisticsName(type, typeName, sizeof(typeName));
    format(message, sizeof(message), "Carga logistica enviada ao ID %d: %s | frete $%d | rep %+d%% | demanda %+d%%.", targetid, typeName, amount, repBonus, demandPercent);
    SendClientMessage(ownerid, COLOR_GREEN, message);
    format(message, sizeof(message), "%s gerou carga de %s por $%d (base $%d, rep %+d%%). Use /aceitarcarga.", PlayerInfo[ownerid][pCharacterName], typeName, amount, baseAmount, repBonus);
    SendClientMessage(targetid, COLOR_YELLOW, message);
    format(message, sizeof(message), "offer trucker=%d type=%d base=%d amount=%d rep=%d demand=%d business=%d", targetid, type, baseAmount, amount, PlayerInfo[targetid][pLogisticsReputation], demandPercent, PlayerInfo[ownerid][pBusinessType]);
    WritePlayerLog(LOG_CONTRACT_FILE, "LOGISTICS_OFFER", ownerid, message);
    return 1;
}

stock Life_AcceptLogisticsContract(playerid)
{
    new ownerid = gLogisticsOfferFrom[playerid];
    new amount = gLogisticsOfferAmount[playerid];
    new type = gLogisticsOfferType[playerid];
    new message[160];
    new typeName[32];
    new tick = GetTickCount();

    if (!IsValidConnectedPlayer(ownerid) || !PlayerInfo[ownerid][pLogged] || amount <= 0 || type == LIFE_LOGISTICS_NONE)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao tem carga logistica pendente.");
        Life_ResetLogisticsOffer(playerid);
        return 1;
    }
    if (PlayerInfo[playerid][pJob] != JOB_CAMINHONEIRO)
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas caminhoneiro pode aceitar carga logistica.");
        return 1;
    }
    if (gLogisticsType[playerid] != LIFE_LOGISTICS_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce ja possui uma carga logistica ativa.");
        return 1;
    }
    if ((tick - gLogisticsOfferTick[playerid]) > LIFE_LOGISTICS_OFFER_EXPIRE_MS)
    {
        SendClientMessage(playerid, COLOR_RED, "Proposta de carga logistica expirou.");
        SendClientMessage(ownerid, COLOR_ORANGE, "Uma proposta de carga logistica expirou sem aceite.");
        Life_ResetLogisticsOffer(playerid);
        return 1;
    }
    if (!Life_LogisticsMatchesBusiness(ownerid, type) || PlayerInfo[ownerid][pBusinessBankrupt])
    {
        SendClientMessage(playerid, COLOR_RED, "A empresa que gerou a carga nao esta mais apta.");
        Life_ResetLogisticsOffer(playerid);
        return 1;
    }

    gLogisticsOwner[playerid] = ownerid;
    gLogisticsAmount[playerid] = amount;
    gLogisticsType[playerid] = type;
    gLogisticsStockGain[playerid] = 2 + (amount / 4000);
    if (gLogisticsStockGain[playerid] > 10) gLogisticsStockGain[playerid] = 10;
    if (gLogisticsStockGain[playerid] < 2) gLogisticsStockGain[playerid] = 2;
    gLogisticsStage[playerid] = LIFE_LOGISTICS_STAGE_ACCEPTED;
    gLogisticsStartTick[playerid] = GetTickCount();
    Life_ResetLogisticsOffer(playerid);
    Life_GetLogisticsName(type, typeName, sizeof(typeName));
    format(message, sizeof(message), "Carga aceita: %s | frete $%d | estoque previsto +%d. Carregue na doca antes da rota.", typeName, amount, gLogisticsStockGain[playerid]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    Life_LogisticsSetCheckpoint(playerid);
    format(message, sizeof(message), "Caminhoneiro ID %d aceitou sua carga logistica de %s.", playerid, typeName);
    SendClientMessage(ownerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_CONTRACT_FILE, "LOGISTICS_ACCEPT", playerid, message);
    return 1;
}

stock Life_CompleteLogisticsDelivery(playerid)
{
    new ownerid = gLogisticsOwner[playerid];
    new type = gLogisticsType[playerid];
    new amount = gLogisticsAmount[playerid];
    new stockGain = gLogisticsStockGain[playerid];
    new item;
    new demandPercent;
    new demandBonus;
    new elapsed;
    new late;
    new repDelta;
    new message[160];
    new typeName[32];

    if (type == LIFE_LOGISTICS_NONE)
    {
        return 0;
    }
    if (gLogisticsStage[playerid] != LIFE_LOGISTICS_STAGE_UNLOAD)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "A carga ainda nao esta pronta para descarga. Complete a rota e va ao ponto marcado.");
        Life_LogisticsSetCheckpoint(playerid);
        return 0;
    }
    if (!Life_LogisticsIsNearDock(playerid, LIFE_LOGISTICS_STAGE_UNLOAD))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar no ponto fisico de descarga correto.");
        Life_LogisticsSetCheckpoint(playerid);
        return 0;
    }
    if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        SendClientMessage(playerid, COLOR_RED, "Estacione o caminhao no ponto de descarga e fique como motorista.");
        return 0;
    }
    if (!IsValidConnectedPlayer(ownerid) || !PlayerInfo[ownerid][pLogged] || PlayerInfo[ownerid][pBusinessBankrupt] || !Life_LogisticsMatchesBusiness(ownerid, type))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Carga logistica cancelada: empresa contratante saiu ou ficou indisponivel.");
        Life_CancelLogisticsContract(playerid, "owner_unavailable");
        return 0;
    }

    item = Life_GetLogisticsMarketItem(type);
    demandPercent = item >= 0 ? Life_GetMarketDemandPercent(item) : 0;
    if (demandPercent > 0)
    {
        demandBonus = (amount * demandPercent) / 100;
    }
    if (gLogisticsStartTick[playerid] > 0)
    {
        elapsed = GetTickCount() - gLogisticsStartTick[playerid];
        if (elapsed > LIFE_LOGISTICS_LATE_MS)
        {
            late = 1;
            demandBonus /= 2;
        }
    }
    if (PlayerInfo[ownerid][pBusinessBalance] >= amount)
    {
        PlayerInfo[ownerid][pBusinessBalance] -= amount;
    }
    else
    {
        PlayerInfo[ownerid][pBusinessDebt] += amount / 2;
    }

    GivePlayerCashReason(playerid, amount + demandBonus, 0, "logistics_delivery");
    Life_TrackGain(playerid, amount + demandBonus, 0, "logistics_delivery");
    PlayerInfo[ownerid][pBusinessStock] += stockGain;
    if (PlayerInfo[ownerid][pBusinessStock] > LIFE_BUSINESS_MAX_STOCK) PlayerInfo[ownerid][pBusinessStock] = LIFE_BUSINESS_MAX_STOCK;
    PlayerInfo[ownerid][pBusinessOrders] += 1;
    if (PlayerInfo[ownerid][pBusinessOrders] > CITY_EVENT_MAX_ORDERS) PlayerInfo[ownerid][pBusinessOrders] = CITY_EVENT_MAX_ORDERS;
    PlayerInfo[ownerid][pBusinessContracts]++;
    PlayerInfo[ownerid][pContractsToday]++;
    PlayerInfo[playerid][pLogisticsCompleted]++;
    PlayerInfo[playerid][pLogisticsEarnings] += amount + demandBonus;
    if (late)
    {
        PlayerInfo[playerid][pLogisticsLate]++;
        repDelta = -2;
    }
    else
    {
        repDelta = 2;
    }
    Life_AddLogisticsReputation(playerid, repDelta);
    if (item >= 0)
    {
        gMarketStock[item] += stockGain;
        if (gMarketStock[item] > gMarketDefaults[item] * 3)
        {
            gMarketStock[item] = gMarketDefaults[item] * 3;
        }
        Life_SaveMarketStock();
    }
    Life_AddCityPassProgress(playerid, CITY_PASS_KIND_ECONOMY, 1);
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_WORK, 3);
    Life_AddWeeklyScore(ownerid, WEEKLY_SCORE_BUSINESS, 4);
    SaveAccountData(playerid, 0);
    SaveAccountData(ownerid, 0);

    Life_GetLogisticsName(type, typeName, sizeof(typeName));
    format(message, sizeof(message), "Entrega logistica concluida: %s | frete $%d | bonus demanda $%d | estoque +%d | rep %d/100.", typeName, amount, demandBonus, stockGain, PlayerInfo[playerid][pLogisticsReputation]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    if (late)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Entrega marcada como atrasada: bonus de demanda reduzido e reputacao logistica perdeu pontos.");
    }
    format(message, sizeof(message), "Carga entregue por ID %d: %s | estoque +%d | pedido +1 | caixa -$%d.", playerid, typeName, stockGain, amount);
    SendClientMessage(ownerid, COLOR_GREEN, message);
    format(message, sizeof(message), "driver=%d owner=%d type=%d amount=%d demand_bonus=%d stock_gain=%d item=%d stock=%d late=%d rep=%d", playerid, ownerid, type, amount, demandBonus, stockGain, item, item >= 0 ? gMarketStock[item] : 0, late, PlayerInfo[playerid][pLogisticsReputation]);
    WritePlayerLog(LOG_CONTRACT_FILE, "LOGISTICS_DELIVERY", playerid, message);
    WritePlayerLog(LOG_CONTRACT_FILE, "LOGISTICS_OWNER", ownerid, message);
    Life_ResetLogisticsActive(playerid);
    return 1;
}

stock Life_Logistics_OnCheckpoint(playerid)
{
    if (gLogisticsType[playerid] == LIFE_LOGISTICS_NONE)
    {
        return 0;
    }
    if (gLogisticsStage[playerid] == LIFE_LOGISTICS_STAGE_ACCEPTED && Life_LogisticsIsNearDock(playerid, LIFE_LOGISTICS_STAGE_ACCEPTED))
    {
        SendClientMessage(playerid, COLOR_YELLOW, "Doca de carregamento. Estacione o caminhao e use /carregarcarga.");
        return 1;
    }
    if (gLogisticsStage[playerid] == LIFE_LOGISTICS_STAGE_UNLOAD && Life_LogisticsIsNearDock(playerid, LIFE_LOGISTICS_STAGE_UNLOAD))
    {
        SendClientMessage(playerid, COLOR_YELLOW, "Ponto de descarga. Estacione o caminhao e use /descarregarcarga para receber.");
        return 1;
    }
    if (gLogisticsStage[playerid] == LIFE_LOGISTICS_STAGE_LOADED && Life_LogisticsIsNearDock(playerid, LIFE_LOGISTICS_STAGE_UNLOAD))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Entrega localizada. Complete a rota de caminhoneiro antes de descarregar e receber.");
        return 1;
    }
    return 0;
}

stock Life_ShowBusinessEconomyDialog(playerid)
{
    new list[1600];
    new line[180];
    new name[32];
    new marketText[64];
    new item;
    new companyCount;
    new contractToday;
    new stockTotal;
    new ordersTotal;
    new pid;
    new maxPlayers = GetMaxPlayers();

    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged] || PlayerInfo[pid][pBusinessType] == LIFE_BUSINESS_NONE)
        {
            continue;
        }
        companyCount++;
        contractToday += PlayerInfo[pid][pContractsToday];
        stockTotal += PlayerInfo[pid][pBusinessStock];
        ordersTotal += PlayerInfo[pid][pBusinessOrders];
    }

    Life_GetBusinessName(PlayerInfo[playerid][pBusinessType], name, sizeof(name));
    format(list, sizeof(list), "Indicador\tValor\n");
    format(line, sizeof(line), "Economia publica\tArrecadacao $%d | empresas online %d\n", gGovernmentRevenue, companyCount); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Contratos hoje\t%d | limite por empresa %d\n", contractToday, LIFE_CONTRACTS_DAILY_LIMIT); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Estoque empresarial\t%d unidade(s) | pedidos %d\n", stockTotal, ordersTotal); strcat(list, line, sizeof(list));
    if (PlayerInfo[playerid][pBusinessType] != LIFE_BUSINESS_NONE)
    {
        format(line, sizeof(line), "Minha empresa\t%s | saude %d/100 | limite contrato $%d\n", name, Life_GetBusinessHealthScore(playerid), Life_GetBusinessContractLimit(playerid)); strcat(list, line, sizeof(list));
        format(line, sizeof(line), "Caixa/estoque\tCaixa $%d | estoque %d/%d | pedidos %d\n", PlayerInfo[playerid][pBusinessBalance], PlayerInfo[playerid][pBusinessStock], LIFE_BUSINESS_MAX_STOCK, PlayerInfo[playerid][pBusinessOrders]); strcat(list, line, sizeof(list));
        format(line, sizeof(line), "Risco\tDivida $%d | imposto $%d | falida %s\n", PlayerInfo[playerid][pBusinessDebt], PlayerInfo[playerid][pBusinessTaxDue], PlayerInfo[playerid][pBusinessBankrupt] ? ("sim") : ("nao")); strcat(list, line, sizeof(list));
    }
    for (item = 0; item < LIFE_MARKET_ITEMS; item++)
    {
        Life_FormatMarketStatus(item, marketText, sizeof(marketText));
        format(line, sizeof(line), "%s\tEstoque %d | %s\n", gMarketNames[item], gMarketStock[item], marketText);
        strcat(list, line, sizeof(list));
    }
    ShowPlayerDialog(playerid, DIALOG_LIFE_ECONOMY, DIALOG_STYLE_TABLIST_HEADERS, "Economia 2.0", list, "Fechar", "");
    return 1;
}

stock Life_AddBizAction(playerid, list[], size, actionid, label[])
{
    if (gLifeBizActionCount[playerid] >= LIFE_BIZ_MAX_ACTIONS)
    {
        return 0;
    }

    gLifeBizActions[playerid][gLifeBizActionCount[playerid]] = actionid;
    gLifeBizActionCount[playerid]++;
    strcat(list, label, size);
    strcat(list, "\n", size);
    return 1;
}

stock Life_AddContractAction(playerid, list[], size, actionid, label[])
{
    if (gLifeContractActionCount[playerid] >= LIFE_CONTRACT_MAX_ACTIONS)
    {
        return 0;
    }

    gLifeContractActions[playerid][gLifeContractActionCount[playerid]] = actionid;
    gLifeContractActionCount[playerid]++;
    strcat(list, label, size);
    strcat(list, "\n", size);
    return 1;
}

stock Life_AddBillAction(playerid, list[], size, actionid, label[])
{
    if (gLifeBillActionCount[playerid] >= LIFE_BILL_MAX_ACTIONS)
    {
        return 0;
    }

    gLifeBillActions[playerid][gLifeBillActionCount[playerid]] = actionid;
    gLifeBillActionCount[playerid]++;
    strcat(list, label, size);
    strcat(list, "\n", size);
    return 1;
}

stock Life_AddAuctionAction(playerid, list[], size, actionid, label[])
{
    if (gLifeAuctionActionCount[playerid] >= LIFE_AUCTION_MAX_ACTIONS)
    {
        return 0;
    }

    gLifeAuctionActions[playerid][gLifeAuctionActionCount[playerid]] = actionid;
    gLifeAuctionActionCount[playerid]++;
    strcat(list, label, size);
    strcat(list, "\n", size);
    return 1;
}

stock Life_ShowBusinessDialog(playerid)
{
    new list[2200];
    new line[160];
    new name[32];
    new days[32];
    new address[40];
    new localName[40];
    new localTypeName[32];
    new localSlot;
    new localType;
    new health;
    new contractLimit;

    Life_GetBusinessName(PlayerInfo[playerid][pBusinessType], name, sizeof(name));
    Life_GetBusinessAddress(playerid, address, sizeof(address));
    Life_FormatDays(PlayerInfo[playerid][pBusinessPermitExpire], days, sizeof(days));
    health = Life_GetBusinessHealthScore(playerid);
    contractLimit = Life_GetBusinessContractLimit(playerid);
    Life_ResetDailyLoop(playerid);
    format(list, sizeof(list), "Acao\tDetalhe\n");
    gLifeBizActionCount[playerid] = 0;
    format(line, sizeof(line), "Status\t%s | Caixa $%d | Estoque %d | Pedidos %d | Alvara %s", name, PlayerInfo[playerid][pBusinessBalance], PlayerInfo[playerid][pBusinessStock], PlayerInfo[playerid][pBusinessOrders], PlayerInfo[playerid][pBusinessType] ? days : ("pendente")); Life_AddBizAction(playerid, list, sizeof(list), 1, line);
    format(line, sizeof(line), "Endereco\t%s", address); Life_AddBizAction(playerid, list, sizeof(list), 1, line);
    format(line, sizeof(line), "Saude financeira\t%d/100 | limite contrato $%d | divida $%d", health, contractLimit, PlayerInfo[playerid][pBusinessDebt]); Life_AddBizAction(playerid, list, sizeof(list), 1, line);
    Life_AddBizAction(playerid, list, sizeof(list), 13, "Painel Economia 2.0\tmercado, demanda e saude empresarial");
    localSlot = Prop_EditorFindPlayerBusiness(playerid, 8.0);
    if (PlayerInfo[playerid][pBusinessType] == LIFE_BUSINESS_NONE && localSlot != -1)
    {
        localType = Prop_EditorGetBusinessType(localSlot);
        if (localType != LIFE_BUSINESS_NONE)
        {
            Prop_EditorGetLocationName(localSlot, localName, sizeof(localName));
            Life_GetBusinessName(localType, localTypeName, sizeof(localTypeName));
            format(line, sizeof(line), "Abrir neste endereco\t%s | %s", localName, localTypeName);
            Life_AddBizAction(playerid, list, sizeof(list), 16, line);
        }
    }
    format(line, sizeof(line), "Abrir comercio\t$%d", Cfg_Price(gCfgBusinessOpenCost)); Life_AddBizAction(playerid, list, sizeof(list), 2, line);
    format(line, sizeof(line), "Abrir oficina\t$%d", Cfg_Price(gCfgBusinessOpenCost)); Life_AddBizAction(playerid, list, sizeof(list), 3, line);
    format(line, sizeof(line), "Abrir transportadora\t$%d", Cfg_Price(gCfgBusinessOpenCost)); Life_AddBizAction(playerid, list, sizeof(list), 4, line);
    format(line, sizeof(line), "Abrir restaurante/bar\t$%d", Cfg_Price(gCfgBusinessOpenCost)); Life_AddBizAction(playerid, list, sizeof(list), 20, line);
    format(line, sizeof(line), "Abrir hotel\t$%d", Cfg_Price(gCfgBusinessOpenCost)); Life_AddBizAction(playerid, list, sizeof(list), 21, line);
    format(line, sizeof(line), "Abrir fabrica\t$%d", Cfg_Price(gCfgBusinessOpenCost)); Life_AddBizAction(playerid, list, sizeof(list), 22, line);
    format(line, sizeof(line), "Abrir imobiliaria\t$%d", Cfg_Price(gCfgBusinessOpenCost)); Life_AddBizAction(playerid, list, sizeof(list), 23, line);
    format(line, sizeof(line), "Abrir escritorio contabil\t$%d", Cfg_Price(gCfgBusinessOpenCost)); Life_AddBizAction(playerid, list, sizeof(list), 24, line);
    format(line, sizeof(line), "Contratar funcionario\t$%d", Cfg_Price(gCfgBusinessEmployeeCost)); Life_AddBizAction(playerid, list, sizeof(list), 5, line);
    format(line, sizeof(line), "Registrar venda/nota\tReceita $%d", Cfg_Price(gCfgBusinessRevenue)); Life_AddBizAction(playerid, list, sizeof(list), 6, line);
    format(line, sizeof(line), "Pagar salarios\t$%d por funcionario", Cfg_Price(gCfgBusinessSalaryCost)); Life_AddBizAction(playerid, list, sizeof(list), 7, line);
    format(line, sizeof(line), "Pagar imposto empresa\t$%d", PlayerInfo[playerid][pBusinessTaxDue]); Life_AddBizAction(playerid, list, sizeof(list), 8, line);
    Life_AddBizAction(playerid, list, sizeof(list), 9, "Fechar empresa\tbaixa do CNPJ");
    Life_AddBizAction(playerid, list, sizeof(list), 10, "Comprar estoque\t$600 por 5 unidade(s)");
    Life_AddBizAction(playerid, list, sizeof(list), 14, "Pedido automatico\tgera demanda se a empresa estiver parada");
    Life_AddBizAction(playerid, list, sizeof(list), 15, "Gerar carga logistica\tcontratar caminhoneiro para abastecer estoque");
    format(line, sizeof(line), "Fechamento v1.2\tgera folha, agua, luz e operacao ($%d)", Life_GetBusinessOperatingCost(playerid)); Life_AddBizAction(playerid, list, sizeof(list), 17, line);
    format(line, sizeof(line), "Pagar conta operacional\t$%d", PlayerInfo[playerid][pBillBusinessPayrollDue]); Life_AddBizAction(playerid, list, sizeof(list), 18, line);
    Life_AddBizAction(playerid, list, sizeof(list), 19, "Relatorio profundo\tcadeia, estoque, endereco, risco e auditoria");
    Life_AddBizAction(playerid, list, sizeof(list), 11, "Recuperacao judicial\tparcela divida e reabre operacao");
    Life_AddBizAction(playerid, list, sizeof(list), 12, "Declarar falencia\tzera operacao e assume restricao");
    ShowPlayerDialog(playerid, DIALOG_LIFE_BUSINESS, DIALOG_STYLE_TABLIST_HEADERS, "Empresa e CNPJ", list, "Selecionar", "Fechar");
    return 1;
}

stock Life_OpenBusiness(playerid, type, editorLoc = 0)
{
    new logLine[128];
    new address[40];
    new message[144];

    if (PlayerInfo[playerid][pBusinessType] != LIFE_BUSINESS_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce ja possui empresa aberta.");
        return 1;
    }
    if (!PlayerInfo[playerid][pDocuments])
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa de documentos validos para abrir empresa.");
        return 1;
    }
    if (!Life_CheckScoreGate(playerid, gCfgCitizenBusinessMinScore, "Abertura de empresa"))
    {
        return 1;
    }
    if (!Bank_TakePaymentReason(playerid, Cfg_Price(gCfgBusinessOpenCost), 0, "business_open"))
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para abrir empresa.");
        return 1;
    }

    PlayerInfo[playerid][pBusinessType] = type;
    PlayerInfo[playerid][pBusinessEmployees] = 0;
    PlayerInfo[playerid][pBusinessBalance] = 0;
    PlayerInfo[playerid][pBusinessTaxDue] = 0;
    PlayerInfo[playerid][pBusinessPermitExpire] = GetBrasiliaDayStamp() + gCfgBusinessPermitValidDays;
    PlayerInfo[playerid][pBusinessEditorLoc] = editorLoc;
    PlayerInfo[playerid][pBusinessStock] = 5;
    PlayerInfo[playerid][pBusinessContracts] = 0;
    PlayerInfo[playerid][pBusinessDebt] = 0;
    PlayerInfo[playerid][pBusinessBankrupt] = 0;
    PlayerInfo[playerid][pBusinessRecoveryDay] = 0;
    Life_AddGovernmentRevenue(Cfg_Price(gCfgBusinessOpenCost), "business_open");
    Life_AddCityPassProgress(playerid, CITY_PASS_KIND_ECONOMY, 1);
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_BUSINESS, 2);
    SaveAccountData(playerid, 0);
    format(logLine, sizeof(logLine), "business_open type=%d loc=%d cost=%d score=%d", type, editorLoc, Cfg_Price(gCfgBusinessOpenCost), PlayerInfo[playerid][pBankScore]);
    WritePlayerLog(LOG_CONTRACT_FILE, "BUSINESS", playerid, logLine);
    if (editorLoc > 0)
    {
        Life_GetBusinessAddress(playerid, address, sizeof(address));
        format(message, sizeof(message), "Empresa aberta com CNPJ, alvara e endereco: %s.", address);
        SendClientMessage(playerid, COLOR_GREEN, message);
    }
    else
    {
        SendClientMessage(playerid, COLOR_GREEN, "Empresa aberta com CNPJ e alvara temporario.");
    }
    return 1;
}

stock Life_OpenEditorBusiness(playerid)
{
    new slot = Prop_EditorFindPlayerBusiness(playerid, 8.0);
    new type;
    new jobid;
    new localJobName[32];
    new message[144];

    if (slot == -1)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Fique perto de uma empresa criada pelo /editarmapa para abrir CNPJ naquele endereco.");
        return 1;
    }

    if (PlayerInfo[playerid][pBusinessType] != LIFE_BUSINESS_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce ja possui empresa aberta.");
        return 1;
    }

    type = Prop_EditorGetBusinessType(slot);
    jobid = Prop_EditorGetBusinessJob(slot);
    if (type == LIFE_BUSINESS_NONE || jobid == JOB_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Esse local nao possui ramo privado valido para CNPJ.");
        return 1;
    }

    GetJobName(jobid, localJobName, sizeof(localJobName));
    format(message, sizeof(message), "Ramo do endereco: %s. O local tambem serve como base dessa profissao.", localJobName);
    SendClientMessage(playerid, COLOR_GRAY, message);
    return Life_OpenBusiness(playerid, type, slot + 1);
}

stock Life_BusinessAction(playerid, action)
{
    new amount;
    new logLine[128];

    if (action >= 5 && PlayerInfo[playerid][pBusinessType] == LIFE_BUSINESS_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao possui empresa.");
        return 1;
    }

    if (action >= 5 && action != 11 && action != 13 && PlayerInfo[playerid][pBusinessBankrupt])
    {
        SendClientMessage(playerid, COLOR_RED, "Empresa em falencia. Use recuperacao judicial antes de operar.");
        return 1;
    }

    switch (action)
    {
        case 1: return Life_ShowBusinessDialog(playerid);
        case 2: return Life_OpenBusiness(playerid, LIFE_BUSINESS_COMMERCE);
        case 3: return Life_OpenBusiness(playerid, LIFE_BUSINESS_WORKSHOP);
        case 4: return Life_OpenBusiness(playerid, LIFE_BUSINESS_TRANSPORT);
        case 20: return Life_OpenBusiness(playerid, LIFE_BUSINESS_RESTAURANT);
        case 21: return Life_OpenBusiness(playerid, LIFE_BUSINESS_HOTEL);
        case 22: return Life_OpenBusiness(playerid, LIFE_BUSINESS_FACTORY);
        case 23: return Life_OpenBusiness(playerid, LIFE_BUSINESS_REAL_ESTATE);
        case 24: return Life_OpenBusiness(playerid, LIFE_BUSINESS_ACCOUNTING);
        case 13: return Life_ShowBusinessEconomyDialog(playerid);
        case 16: return Life_OpenEditorBusiness(playerid);
        case 17: return Life_GenBizOpBill(playerid);
        case 18: return Life_PayBusinessOperatingBill(playerid);
        case 19: return Life_ShowBusinessDeepReport(playerid);
        case 15:
        {
            SendClientMessage(playerid, COLOR_YELLOW, "Use /gerarcarga [id caminhoneiro] [mercado/posto/oficina/obra] [valor].");
            SendClientMessage(playerid, COLOR_GRAY, "Comercio gera mercado; Oficina gera oficina; Transportadora gera posto ou obra.");
            return 1;
        }
        case 5:
        {
            if (!Bank_TakePaymentReason(playerid, Cfg_Price(gCfgBusinessEmployeeCost), 0, "business_hire_employee")) return SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para contratar.");
            PlayerInfo[playerid][pBusinessEmployees]++;
            PlayerInfo[playerid][pBusinessContracts]++;
            Life_AddWeeklyScore(playerid, WEEKLY_SCORE_BUSINESS, 1);
            SendClientMessage(playerid, COLOR_GREEN, "Funcionario contratado e registrado.");
        }
        case 6:
        {
            if (PlayerInfo[playerid][pBusinessOrders] <= 0) return SendClientMessage(playerid, COLOR_GRAY, "Sua empresa nao tem pedidos pendentes hoje.");
            if (PlayerInfo[playerid][pBusinessStock] <= 0) return SendClientMessage(playerid, COLOR_RED, "Empresa sem estoque real. Compre estoque ou aguarde abastecimento da cadeia produtiva.");
            amount = Cfg_Price(gCfgBusinessRevenue);
            amount += (amount * PlayerInfo[playerid][pBusinessEmployees]) / 10;
            amount += (amount * Life_GetBusinessHealthScore(playerid)) / 500;
            if (Life_PlayerAtBusinessAddress(playerid))
            {
                amount += amount / 10;
            }
            if (PlayerInfo[playerid][pBusinessStock] <= 2) amount += amount / 5;
            if (PlayerInfo[playerid][pBusinessStock] >= 20) amount -= amount / 10;
            PlayerInfo[playerid][pBusinessBalance] += amount;
            PlayerInfo[playerid][pBusinessTaxDue] += (amount * gCfgBusinessTaxPercent) / 100;
            PlayerInfo[playerid][pBusinessOrders]--;
            PlayerInfo[playerid][pBusinessStock]--;
            Life_AddCityPassProgress(playerid, CITY_PASS_KIND_ECONOMY, 1);
            Life_AddWeeklyScore(playerid, WEEKLY_SCORE_BUSINESS, 2);
            SendClientMessage(playerid, COLOR_GREEN, "Pedido empresarial atendido. Receita entrou no caixa da empresa.");
        }
        case 7:
        {
            amount = Cfg_Price(gCfgBusinessSalaryCost) * PlayerInfo[playerid][pBusinessEmployees];
            if (amount <= 0) return SendClientMessage(playerid, COLOR_GRAY, "Sua empresa nao tem funcionarios.");
            if (PlayerInfo[playerid][pBusinessBalance] < amount) return SendClientMessage(playerid, COLOR_RED, "Caixa da empresa insuficiente para salarios.");
            PlayerInfo[playerid][pBusinessBalance] -= amount;
            if (PlayerInfo[playerid][pBusinessDebt] > 0)
            {
                PlayerInfo[playerid][pBusinessDebt] -= amount / 2;
                if (PlayerInfo[playerid][pBusinessDebt] < 0) PlayerInfo[playerid][pBusinessDebt] = 0;
            }
            SendClientMessage(playerid, COLOR_GREEN, "Salarios pagos aos funcionarios.");
        }
        case 8:
        {
            amount = PlayerInfo[playerid][pBusinessTaxDue];
            if (amount <= 0) return SendClientMessage(playerid, COLOR_GRAY, "Empresa sem imposto pendente.");
            if (PlayerInfo[playerid][pBusinessBalance] >= amount)
            {
                PlayerInfo[playerid][pBusinessBalance] -= amount;
            }
            else if (!Bank_TakePaymentReason(playerid, amount, 0, "business_tax"))
            {
                return SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para imposto da empresa.");
            }
            PlayerInfo[playerid][pBusinessTaxDue] = 0;
            Life_AddGovernmentRevenue(amount, "business_tax");
            Life_AddCityPassProgress(playerid, CITY_PASS_KIND_ECONOMY, 1);
            Life_AddWeeklyScore(playerid, WEEKLY_SCORE_BUSINESS, 1);
            SendClientMessage(playerid, COLOR_GREEN, "Imposto da empresa pago.");
        }
        case 9:
        {
            PlayerInfo[playerid][pBusinessType] = LIFE_BUSINESS_NONE;
            PlayerInfo[playerid][pBusinessEmployees] = 0;
            PlayerInfo[playerid][pBusinessBalance] = 0;
            PlayerInfo[playerid][pBusinessTaxDue] = 0;
            PlayerInfo[playerid][pBusinessPermitExpire] = 0;
            PlayerInfo[playerid][pBusinessEditorLoc] = 0;
            PlayerInfo[playerid][pBusinessStock] = 0;
            PlayerInfo[playerid][pBusinessOrders] = 0;
            PlayerInfo[playerid][pBusinessContracts] = 0;
            SendClientMessage(playerid, COLOR_ORANGE, "Empresa fechada e CNPJ baixado.");
        }
        case 10:
        {
            amount = 600;
            if (!Bank_TakePaymentReason(playerid, amount, 0, "business_stock_buy")) return SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para estoque.");
            PlayerInfo[playerid][pBusinessStock] += 5;
            if (Life_PlayerAtBusinessAddress(playerid))
            {
                PlayerInfo[playerid][pBusinessStock]++;
            }
            if (PlayerInfo[playerid][pBusinessStock] > LIFE_BUSINESS_MAX_STOCK) PlayerInfo[playerid][pBusinessStock] = LIFE_BUSINESS_MAX_STOCK;
            Life_ApplyBusinessMarketImpact(playerid, 1, "business_stock_buy");
            Life_AddCityPassProgress(playerid, CITY_PASS_KIND_ECONOMY, 1);
            SendClientMessage(playerid, COLOR_GREEN, "Estoque empresarial comprado e registrado.");
        }
        case 14:
        {
            if (PlayerInfo[playerid][pBusinessOrders] >= 8) return SendClientMessage(playerid, COLOR_GRAY, "Sua empresa ja tem pedidos pendentes suficientes.");
            amount = 250 + (PlayerInfo[playerid][pBusinessEmployees] * 75);
            if (PlayerInfo[playerid][pBusinessBalance] >= amount)
            {
                PlayerInfo[playerid][pBusinessBalance] -= amount;
            }
            else if (!Bank_TakePaymentReason(playerid, amount, 0, "business_auto_order"))
            {
                return SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para campanha de pedido automatico.");
            }
            PlayerInfo[playerid][pBusinessOrders] += Life_PlayerAtBusinessAddress(playerid) ? 3 : 2;
            if (PlayerInfo[playerid][pBusinessOrders] > 8) PlayerInfo[playerid][pBusinessOrders] = 8;
            PlayerInfo[playerid][pBusinessContracts]++;
            Life_AddWeeklyScore(playerid, WEEKLY_SCORE_BUSINESS, 1);
            SendClientMessage(playerid, COLOR_GREEN, "Pedido automatico criado. Sua empresa recebeu nova demanda real.");
        }
        case 11:
        {
            if (!PlayerInfo[playerid][pBusinessBankrupt] && PlayerInfo[playerid][pBusinessDebt] <= 0) return SendClientMessage(playerid, COLOR_GRAY, "Empresa nao precisa de recuperacao judicial agora.");
            amount = PlayerInfo[playerid][pBusinessDebt] / 3;
            if (amount < 500) amount = 500;
            if (!Bank_TakePaymentReason(playerid, amount, 0, "business_recovery")) return SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para entrada da recuperacao judicial.");
            PlayerInfo[playerid][pBusinessDebt] -= amount * 2;
            if (PlayerInfo[playerid][pBusinessDebt] < 0) PlayerInfo[playerid][pBusinessDebt] = 0;
            PlayerInfo[playerid][pBusinessBankrupt] = 0;
            PlayerInfo[playerid][pBusinessRecoveryDay] = GetBrasiliaDayStamp();
            PlayerInfo[playerid][pBankGoodHistory]++;
            SendClientMessage(playerid, COLOR_GREEN, "Recuperacao judicial aprovada. Empresa voltou a operar com divida renegociada.");
            WritePlayerLog(LOG_CONTRACT_FILE, "BUSINESS_RECOVERY", playerid, "recuperacao_judicial_aprovada");
        }
        case 12:
        {
            PlayerInfo[playerid][pBusinessBankrupt] = 1;
            PlayerInfo[playerid][pBusinessDebt] += 3000;
            PlayerInfo[playerid][pBusinessOrders] = 0;
            PlayerInfo[playerid][pBankBadHistory]++;
            SendClientMessage(playerid, COLOR_ORANGE, "Falencia declarada. Operacao travada ate recuperacao judicial.");
            WritePlayerLog(LOG_CONTRACT_FILE, "BUSINESS_BANKRUPTCY", playerid, "falencia_declarada");
        }
    }

    SaveAccountData(playerid, 0);
    format(logLine, sizeof(logLine), "business_action=%d balance=%d employees=%d tax=%d", action, PlayerInfo[playerid][pBusinessBalance], PlayerInfo[playerid][pBusinessEmployees], PlayerInfo[playerid][pBusinessTaxDue]);
    WritePlayerLog(LOG_CONTRACT_FILE, "BUSINESS", playerid, logLine);
    return 1;
}

stock Life_OfferBusinessContract(playerid, targetid, amount)
{
    new message[160];
    new limit;
    new available;
    new targetBizType;
    new targetJobName[32];
    new sectorJobs[128];

    Life_ResetDailyLimits(playerid);
    if (PlayerInfo[playerid][pBusinessType] == LIFE_BUSINESS_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa ter empresa aberta para contratar jogador.");
        return 1;
    }
    if (PlayerInfo[playerid][pBusinessBankrupt])
    {
        SendClientMessage(playerid, COLOR_RED, "Empresa em falencia nao pode abrir contrato.");
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid) || !PlayerInfo[targetid][pLogged] || targetid == playerid)
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido para contrato.");
        return 1;
    }
    targetBizType = Life_GetBusinessTypeForJob(PlayerInfo[targetid][pJob]);
    if (targetBizType != PlayerInfo[playerid][pBusinessType])
    {
        GetJobName(PlayerInfo[targetid][pJob], targetJobName, sizeof(targetJobName));
        Life_GetBusinessSectorJobs(PlayerInfo[playerid][pBusinessType], sectorJobs, sizeof(sectorJobs));
        format(message, sizeof(message), "Contrato recusado: profissao atual do jogador (%s) nao atende este ramo.", targetJobName);
        SendClientMessage(playerid, COLOR_RED, message);
        format(message, sizeof(message), "Profissoes aceitas neste ramo: %s.", sectorJobs);
        SendClientMessage(playerid, COLOR_GRAY, message);
        return 1;
    }
    if (amount < 100 || amount > 50000)
    {
        SendClientMessage(playerid, COLOR_RED, "Valor de contrato deve ficar entre $100 e $50000.");
        return 1;
    }
    if (PlayerInfo[playerid][pContractsToday] >= LIFE_CONTRACTS_DAILY_LIMIT)
    {
        SendClientMessage(playerid, COLOR_RED, "Limite diario de contratos empresariais atingido.");
        return 1;
    }
    limit = Life_GetBusinessContractLimit(playerid);
    if (amount > limit)
    {
        format(message, sizeof(message), "Valor acima do limite economico da empresa. Limite atual: $%d.", limit);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }
    available = PlayerInfo[playerid][pBusinessBalance] + PlayerInfo[playerid][pBankMoney] + PlayerInfo[playerid][pMoney];
    if (available < amount)
    {
        format(message, sizeof(message), "Empresa sem caixa/reserva para honrar este contrato. Disponivel: $%d.", available);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    gBusinessOfferFrom[targetid] = playerid;
    gBusinessOfferAmount[targetid] = amount;
    gBusinessOfferType[targetid] = PlayerInfo[playerid][pBusinessType];
    gBusinessOfferTick[targetid] = GetTickCount();
    format(message, sizeof(message), "Contrato empresarial enviado ao ID %d por $%d. Ele deve usar /aceitarcontrato.", targetid, amount);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(message, sizeof(message), "%s ofereceu contrato empresarial de $%d. Use /aceitarcontrato em ate 3 minutos.", PlayerInfo[playerid][pCharacterName], amount);
    SendClientMessage(targetid, COLOR_YELLOW, message);
    format(message, sizeof(message), "offer target=%d amount=%d type=%d contracts_today=%d limit=%d health=%d", targetid, amount, PlayerInfo[playerid][pBusinessType], PlayerInfo[playerid][pContractsToday], limit, Life_GetBusinessHealthScore(playerid));
    WritePlayerLog(LOG_CONTRACT_FILE, "BUSINESS_CONTRACT_OFFER", playerid, message);
    return 1;
}

stock Life_AcceptBusinessContract(playerid)
{
    new ownerid = gBusinessOfferFrom[playerid];
    new amount = gBusinessOfferAmount[playerid];
    new type = gBusinessOfferType[playerid];
    new message[160];
    new stockGain;
    new orderGain;
    new tick = GetTickCount();

    if (!IsValidConnectedPlayer(ownerid) || !PlayerInfo[ownerid][pLogged] || amount <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui contrato empresarial pendente.");
        return 1;
    }

    if (IsValidConnectedPlayer(ownerid))
    {
        Life_ResetDailyLimits(ownerid);
        if (PlayerInfo[ownerid][pContractsToday] >= LIFE_CONTRACTS_DAILY_LIMIT)
        {
            SendClientMessage(playerid, COLOR_RED, "Empresa atingiu o limite diario de contratos.");
            SendClientMessage(ownerid, COLOR_RED, "Limite diario de contratos empresariais atingido.");
            return 1;
        }
    }

    if (gBusinessOfferTick[playerid] <= 0 || (tick - gBusinessOfferTick[playerid]) > LIFE_CONTRACT_OFFER_EXPIRE_MS)
    {
        SendClientMessage(playerid, COLOR_RED, "Contrato empresarial expirou. Peca uma nova proposta.");
        if (IsValidConnectedPlayer(ownerid))
        {
            SendClientMessage(ownerid, COLOR_ORANGE, "Uma proposta empresarial expirou sem aceite.");
        }
        gBusinessOfferFrom[playerid] = INVALID_PLAYER_ID;
        gBusinessOfferAmount[playerid] = 0;
        gBusinessOfferTick[playerid] = 0;
        return 1;
    }

    if (PlayerInfo[ownerid][pBusinessType] != type || PlayerInfo[ownerid][pBusinessBankrupt])
    {
        SendClientMessage(playerid, COLOR_RED, "A empresa que ofereceu o contrato nao esta mais disponivel.");
        gBusinessOfferFrom[playerid] = INVALID_PLAYER_ID;
        gBusinessOfferAmount[playerid] = 0;
        gBusinessOfferTick[playerid] = 0;
        return 1;
    }
    if (Life_GetBusinessTypeForJob(PlayerInfo[playerid][pJob]) != type)
    {
        SendClientMessage(playerid, COLOR_RED, "Sua profissao atual nao atende mais o ramo desse contrato.");
        SendClientMessage(ownerid, COLOR_ORANGE, "Contrato recusado: jogador mudou para profissao fora do ramo.");
        gBusinessOfferFrom[playerid] = INVALID_PLAYER_ID;
        gBusinessOfferAmount[playerid] = 0;
        gBusinessOfferTick[playerid] = 0;
        return 1;
    }

    if (PlayerInfo[ownerid][pBusinessBalance] >= amount)
    {
        PlayerInfo[ownerid][pBusinessBalance] -= amount;
    }
    else if (!Bank_TakePaymentReason(ownerid, amount, 0, "business_contract_owner"))
    {
        SendClientMessage(playerid, COLOR_RED, "Empresa sem saldo para pagar o contrato agora.");
        SendClientMessage(ownerid, COLOR_RED, "Contrato falhou por saldo insuficiente.");
        return 1;
    }

    GivePlayerCashReason(playerid, amount, 0, "business_contract_payment");
    Life_TrackGain(playerid, amount, 0, "business_contract");
    PlayerInfo[playerid][pContractWork] = 1;
    PlayerInfo[ownerid][pBusinessContracts]++;
    PlayerInfo[ownerid][pContractsToday]++;
    stockGain = 1 + (amount / 5000);
    if (stockGain > 8) stockGain = 8;
    orderGain = 1 + (amount / 15000);
    if (orderGain > 3) orderGain = 3;
    PlayerInfo[ownerid][pBusinessStock] += stockGain;
    PlayerInfo[ownerid][pBusinessOrders] += orderGain;
    if (PlayerInfo[ownerid][pBusinessStock] > LIFE_BUSINESS_MAX_STOCK) PlayerInfo[ownerid][pBusinessStock] = LIFE_BUSINESS_MAX_STOCK;
    if (PlayerInfo[ownerid][pBusinessOrders] > 12) PlayerInfo[ownerid][pBusinessOrders] = 12;
    Life_ApplyBusinessMarketImpact(ownerid, stockGain, "business_contract");
    Life_AddCityPassProgress(playerid, CITY_PASS_KIND_ECONOMY, 1);
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_WORK, 2);
    Life_AddWeeklyScore(ownerid, WEEKLY_SCORE_BUSINESS, 3);
    SaveAccountData(playerid, 0);
    SaveAccountData(ownerid, 0);
    format(message, sizeof(message), "Contrato aceito. Voce recebeu $%d e gerou %d estoque/%d pedido(s).", amount, stockGain, orderGain);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(message, sizeof(message), "Contrato aceito pelo ID %d. Estoque +%d | pedidos +%d.", playerid, stockGain, orderGain);
    SendClientMessage(ownerid, COLOR_GREEN, message);
    format(message, sizeof(message), "accepted worker=%d owner=%d amount=%d type=%d stock_gain=%d order_gain=%d owner_contracts_today=%d", playerid, ownerid, amount, type, stockGain, orderGain, PlayerInfo[ownerid][pContractsToday]);
    WritePlayerLog(LOG_CONTRACT_FILE, "BUSINESS_CONTRACT_ACCEPT", playerid, message);
    WritePlayerLog(LOG_CONTRACT_FILE, "BUSINESS_CONTRACT_OWNER", ownerid, message);
    gBusinessOfferFrom[playerid] = INVALID_PLAYER_ID;
    gBusinessOfferAmount[playerid] = 0;
    gBusinessOfferTick[playerid] = 0;
    return 1;
}

stock Life_RequestBusinessCredit(playerid, amount)
{
    new limit;
    new interest;
    new message[160];

    if (PlayerInfo[playerid][pBusinessType] == LIFE_BUSINESS_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa ter CNPJ ativo para credito empresarial.");
        return 1;
    }
    if (PlayerInfo[playerid][pBusinessBankrupt])
    {
        SendClientMessage(playerid, COLOR_RED, "Empresa em falencia precisa de recuperacao antes de credito.");
        return 1;
    }
    if (amount < 500 || amount > 80000)
    {
        SendClientMessage(playerid, COLOR_RED, "Credito empresarial deve ficar entre $500 e $80000.");
        return 1;
    }

    limit = 2500 + (Life_GetBusinessHealthScore(playerid) * 220) + (PlayerInfo[playerid][pBankScore] * 80);
    limit += PlayerInfo[playerid][pBusinessEmployees] * 900;
    limit += PlayerInfo[playerid][pBusinessContracts] * 120;
    limit -= PlayerInfo[playerid][pBusinessDebt] / 2;
    if (PlayerInfo[playerid][pJob] == JOB_BANCARIO)
    {
        limit += limit / 10;
    }
    if (limit < 500) limit = 500;

    if (amount > limit)
    {
        format(message, sizeof(message), "Credito recusado. Limite atual da empresa: $%d.", limit);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    interest = 8;
    if (Life_GetBusinessHealthScore(playerid) >= 75) interest = 5;
    else if (Life_GetBusinessHealthScore(playerid) < 45) interest = 12;
    if (PlayerInfo[playerid][pJob] == JOB_BANCARIO && interest > 3) interest -= 2;

    PlayerInfo[playerid][pBusinessBalance] += amount;
    PlayerInfo[playerid][pBusinessDebt] += amount + ((amount * interest) / 100);
    PlayerInfo[playerid][pBankGoodHistory]++;
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_BUSINESS, 2);
    SaveAccountData(playerid, 0);

    format(message, sizeof(message), "Credito empresarial aprovado: $%d no caixa. Divida com juros: $%d.", amount, amount + ((amount * interest) / 100));
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_CONTRACT_FILE, "BUSINESS_CREDIT", playerid, message);
    return 1;
}

stock Life_FiscalizeBusiness(playerid, targetid)
{
    new fine;
    new message[160];

    if (PlayerInfo[playerid][pJob] != JOB_FUNCIONARIO_PREFEITURA && !Job_IsPublicServant(PlayerInfo[playerid][pJob]))
    {
        SendClientMessage(playerid, COLOR_RED, "Fiscalizacao empresarial exige cargo publico em servico urbano.");
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid) || !PlayerInfo[targetid][pLogged] || PlayerInfo[targetid][pBusinessType] == LIFE_BUSINESS_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador sem empresa ativa para fiscalizar.");
        return 1;
    }

    if (PlayerInfo[targetid][pBusinessPermitExpire] < GetBrasiliaDayStamp() || PlayerInfo[targetid][pBusinessTaxDue] > 3000)
    {
        fine = 900 + (PlayerInfo[targetid][pBusinessTaxDue] / 10);
        PlayerInfo[targetid][pBusinessTaxDue] += fine;
        PlayerInfo[targetid][pBusinessDebt] += fine / 2;
        PlayerInfo[targetid][pBankBadHistory]++;
        format(message, sizeof(message), "Fiscalizacao: empresa irregular. Multa/imposto adicionados: $%d.", fine);
        SendClientMessage(targetid, COLOR_ORANGE, message);
        SendClientMessage(playerid, COLOR_GREEN, "Fiscalizacao registrada: irregularidade encontrada.");
    }
    else
    {
        PlayerInfo[targetid][pBusinessContracts]++;
        PlayerInfo[targetid][pBankGoodHistory]++;
        SendClientMessage(targetid, COLOR_GREEN, "Fiscalizacao municipal aprovada. Reputacao empresarial melhorou.");
        SendClientMessage(playerid, COLOR_GREEN, "Fiscalizacao registrada: empresa regular.");
    }
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_CITIZEN, 2);
    SaveAccountData(targetid, 0);
    SaveAccountData(playerid, 0);
    return 1;
}

stock Life_RegularizeBizAccounting(playerid, targetid)
{
    new discount;
    new message[160];

    if (PlayerInfo[playerid][pJob] != JOB_CONTADOR)
    {
        SendClientMessage(playerid, COLOR_RED, "Regularizacao empresarial exige profissao Contador.");
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid) || !PlayerInfo[targetid][pLogged] || PlayerInfo[targetid][pBusinessType] == LIFE_BUSINESS_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador sem empresa ativa para regularizar.");
        return 1;
    }

    if (PlayerInfo[targetid][pBusinessTaxDue] > 0)
    {
        discount = PlayerInfo[targetid][pBusinessTaxDue] / 10;
        if (discount < 100) discount = 100;
        if (discount > PlayerInfo[targetid][pBusinessTaxDue]) discount = PlayerInfo[targetid][pBusinessTaxDue];
        PlayerInfo[targetid][pBusinessTaxDue] -= discount;
    }
    if (PlayerInfo[targetid][pBusinessPermitExpire] < GetBrasiliaDayStamp() + 7)
    {
        PlayerInfo[targetid][pBusinessPermitExpire] = GetBrasiliaDayStamp() + 7;
    }
    PlayerInfo[targetid][pBusinessContracts]++;
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_WORK, 2);
    SaveAccountData(targetid, 0);
    SaveAccountData(playerid, 0);

    format(message, sizeof(message), "Regularizacao contabil aplicada. Desconto/ajuste fiscal: $%d.", discount);
    SendClientMessage(targetid, COLOR_GREEN, message);
    SendClientMessage(playerid, COLOR_GREEN, "Servico contabil empresarial concluido.");
    return 1;
}

stock Life_RunVehicleInspection(playerid)
{
    new cost = 350;
    new message[128];

    if (!Dealership_RequireDetran(playerid))
    {
        return 1;
    }
    if (PlayerInfo[playerid][pVehicleModel] < 400)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce precisa ter um veiculo ativo para fazer vistoria.");
        return 1;
    }
    if (PlayerInfo[playerid][pVehicleImpounded])
    {
        SendClientMessage(playerid, COLOR_RED, "Veiculo apreendido precisa ser regularizado no patio antes da vistoria.");
        return 1;
    }
    if (!Bank_TakePayment(playerid, cost, 0))
    {
        SendClientMessage(playerid, COLOR_RED, "Vistoria custa $350.");
        return 1;
    }

    PlayerInfo[playerid][pVehicleInspectionDay] = GetBrasiliaDayStamp() + 30;
    PlayerInfo[playerid][pBankGoodHistory]++;
    Life_AddCityPassProgress(playerid, CITY_PASS_KIND_PUBLIC, 1);
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_CITIZEN, 1);
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Vistoria aprovada. Validade: %d dia(s).", PlayerInfo[playerid][pVehicleInspectionDay] - GetBrasiliaDayStamp());
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Life_ShowVehicleAuction(playerid)
{
    new list[512];

    WritePlayerLog(LOG_CONTRACT_FILE, "VEHICLE_AUCTION", playerid, "consulta_leilao_detran");
    format(list, sizeof(list), "Acao\tDetalhe\n");
    gLifeAuctionActionCount[playerid] = 0;
    if (PlayerInfo[playerid][pVehicleImpounded])
    {
        Life_AddAuctionAction(playerid, list, sizeof(list), LIFE_AUCTION_STATUS, "Status\tVeiculo apreendido com risco de leilao");
        Life_AddAuctionAction(playerid, list, sizeof(list), LIFE_AUCTION_RECOVER, "Recuperar no patio\tpagar taxa e liberar");
        Life_AddAuctionAction(playerid, list, sizeof(list), LIFE_AUCTION_GPS, "GPS patio municipal\tmarcar rota");
    }
    else
    {
        Life_AddAuctionAction(playerid, list, sizeof(list), LIFE_AUCTION_STATUS, "Status\tSem veiculo apreendido seu");
        Life_AddAuctionAction(playerid, list, sizeof(list), LIFE_AUCTION_GPS, "GPS patio municipal\tver lotes administrativos");
    }
    ShowPlayerDialog(playerid, DIALOG_LIFE_AUCTION, DIALOG_STYLE_TABLIST_HEADERS, "Leilao DETRAN", list, "Selecionar", "Fechar");
    return 1;
}

stock Life_HandleAuctionItem(playerid, actionid)
{
    switch (actionid)
    {
        case LIFE_AUCTION_STATUS:
        {
            return Life_ShowVehicleAuction(playerid);
        }
        case LIFE_AUCTION_RECOVER:
        {
            return Dealership_RecoverImpound(playerid);
        }
        case LIFE_AUCTION_GPS:
        {
            return SetPlayerGps(playerid, LOCATION_PATIO_MUNICIPAL);
        }
    }
    return 1;
}

stock Life_MedicalShift(playerid)
{
    new reward;
    new message[128];

    if (PlayerInfo[playerid][pJob] != JOB_MEDICO && PlayerInfo[playerid][pJob] != JOB_MOTORISTA_AMBULANCIA)
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas medico ou motorista de ambulancia pode assumir plantao SAMU.");
        return 1;
    }
    if (!Work_IsActive(playerid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Bata ponto antes de registrar plantao.");
        return 1;
    }

    reward = Vip_ApplyCashBonus(playerid, 650 + (PlayerInfo[playerid][pMedicalSeverity] * 100));
    PlayerInfo[playerid][pMedicalShifts]++;
    PlayerInfo[playerid][pWeeklyWorkScore] += 2;
    Life_AddCityPassProgress(playerid, CITY_PASS_KIND_PUBLIC, 1);
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_CITIZEN, 1);
    GivePlayerCashReason(playerid, reward, 1, "medical_shift");
    Job_AddProgress(playerid, PlayerInfo[playerid][pJob], gCfgJobXpPerTask);
    Life_CheckAchievements(playerid);
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Plantao SAMU registrado. Atendimentos: %d | pagamento $%d.", PlayerInfo[playerid][pMedicalShifts], reward);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Life_HospitalIntern(playerid)
{
    new cost = 900;

    if (PlayerInfo[playerid][pMedicalSeverity] <= 0 && PlayerInfo[playerid][pInjury] <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao precisa de internacao agora.");
        return 1;
    }
    if (PlayerInfo[playerid][pHealthPlan])
    {
        cost = 180;
    }
    if (!Bank_TakePayment(playerid, cost, 0))
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para internacao.");
        return 1;
    }

    PlayerInfo[playerid][pMedicalSeverity] = 0;
    PlayerInfo[playerid][pMedicalTreatmentDue] = 0;
    PlayerInfo[playerid][pInjury] = 0;
    SetPlayerHealth(playerid, 100.0);
    Life_AddCityPassProgress(playerid, CITY_PASS_KIND_PUBLIC, 1);
    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Internacao leve concluida. Prontuario limpo e saude restaurada.");
    return 1;
}

stock Life_PoliceCreateWarrantEx(playerid, targetid, reason[])
{
    new message[160];
    new logLine[256];

    if (!IsLawEnforcementJob(PlayerInfo[playerid][pJob]) && !HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policia ou staff pode registrar mandado.");
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid) || !PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido.");
        return 1;
    }
    if (Account_IsNewcomerProtected(targetid))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Recem chegado protegido: mandado/procurado bloqueado ate o nivel 3.");
        SendClientMessage(targetid, COLOR_YELLOW, "Aviso educativo: voce nao pode ficar procurado ate o nivel 3.");
        return 1;
    }
    if (PlayerInfo[targetid][pJusticeActiveEvidence] <= 0 && PlayerInfo[targetid][pWanted] <= 0 && !HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
    {
        SendClientMessage(playerid, COLOR_RED, "Mandado precisa de prova/pericia ou procurado ativo. Use /prova [id] [descricao] primeiro.");
        return 1;
    }

    PlayerInfo[playerid][pPoliceWarrants]++;
    PlayerInfo[playerid][pWeeklyPoliceScore] += 3;
    PlayerInfo[targetid][pJusticeActiveWarrants]++;
    PlayerInfo[targetid][pWanted]++;
    if (PlayerInfo[targetid][pWanted] > MAX_WANTED_LEVEL) PlayerInfo[targetid][pWanted] = MAX_WANTED_LEVEL;
    PlayerInfo[targetid][pJusticeCases]++;
    PlayerInfo[targetid][pJusticeStatus] = JUSTICE_STATUS_INVESTIGATING;
    PlayerInfo[targetid][pJusticeDeadlineDay] = GetBrasiliaDayStamp() + 3;
    Life_AddCityPassProgress(playerid, CITY_PASS_KIND_PUBLIC, 1);
    Life_CheckAchievements(playerid);
    SaveAccountData(playerid, 0);
    SaveAccountData(targetid, 0);
    format(message, sizeof(message), "Mandado registrado contra ID %d. Procurado: %d.", targetid, PlayerInfo[targetid][pWanted]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(targetid, COLOR_ORANGE, "Existe mandado/investigacao contra voce. Consulte /justica.");
    format(logLine, sizeof(logLine), "warrant target=%d wanted=%d active_warrants=%d active_evidence=%d deadline=%d reason=%s", targetid, PlayerInfo[targetid][pWanted], PlayerInfo[targetid][pJusticeActiveWarrants], PlayerInfo[targetid][pJusticeActiveEvidence], PlayerInfo[targetid][pJusticeDeadlineDay], reason);
    WritePlayerLog(LOG_PUNISH_FILE, "POLICE_WARRANT", playerid, logLine);
    WritePlayerLog(JUSTICE_WARRANTS_FILE, "WARRANT", playerid, logLine);
    return 1;
}

stock Life_PoliceCreateWarrant(playerid, targetid)
{
    return Life_PoliceCreateWarrantEx(playerid, targetid, "mandado operacional");
}

stock Life_PoliceCollectEvidenceEx(playerid, targetid, details[])
{
    new logLine[256];

    if (!IsLawEnforcementJob(PlayerInfo[playerid][pJob]) && !HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policia ou staff pode anexar prova.");
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid) || !PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido.");
        return 1;
    }

    PlayerInfo[playerid][pPoliceEvidence]++;
    PlayerInfo[playerid][pWeeklyPoliceScore] += 2;
    PlayerInfo[targetid][pJusticeActiveEvidence]++;
    PlayerInfo[targetid][pJusticeStatus] = JUSTICE_STATUS_INVESTIGATING;
    if (PlayerInfo[targetid][pJusticeCases] <= 0) PlayerInfo[targetid][pJusticeCases] = 1;
    if (PlayerInfo[targetid][pJusticeDeadlineDay] <= 0) PlayerInfo[targetid][pJusticeDeadlineDay] = GetBrasiliaDayStamp() + 3;
    Life_AddCityPassProgress(playerid, CITY_PASS_KIND_PUBLIC, 1);
    SaveAccountData(playerid, 0);
    SaveAccountData(targetid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Prova/pericia anexada ao caso.");
    SendClientMessage(targetid, COLOR_ORANGE, "Uma prova foi anexada ao seu caso judicial.");
    format(logLine, sizeof(logLine), "evidence target=%d active_evidence=%d active_warrants=%d deadline=%d desc=%s", targetid, PlayerInfo[targetid][pJusticeActiveEvidence], PlayerInfo[targetid][pJusticeActiveWarrants], PlayerInfo[targetid][pJusticeDeadlineDay], details);
    WritePlayerLog(LOG_PUNISH_FILE, "POLICE_EVIDENCE", playerid, logLine);
    WritePlayerLog(JUSTICE_EVIDENCE_FILE, "EVIDENCE", playerid, logLine);
    return 1;
}

stock Life_PoliceCollectEvidence(playerid, targetid)
{
    return Life_PoliceCollectEvidenceEx(playerid, targetid, "prova/pericia operacional");
}

stock Life_SetAnkleMonitor(playerid, targetid)
{
    if (!IsLawEnforcementJob(PlayerInfo[playerid][pJob]) && PlayerInfo[playerid][pJob] != JOB_JUIZ && !HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policia, juiz ou staff pode aplicar tornozeleira.");
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid) || !PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido.");
        return 1;
    }

    PlayerInfo[targetid][pAnkleMonitor] = 1;
    PlayerInfo[targetid][pJusticeStatus] = JUSTICE_STATUS_HEARING;
    Life_AddCityPassProgress(playerid, CITY_PASS_KIND_PUBLIC, 1);
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_POLICE, 2);
    SaveAccountData(targetid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Tornozeleira aplicada e caso marcado para audiencia.");
    SendClientMessage(targetid, COLOR_ORANGE, "Voce esta com tornozeleira. Resolva o caso em /justica.");
    return 1;
}

stock Life_ShowCityBudget(playerid)
{
    new message[160];
    new openCases;
    new pid;
    new maxPlayers = GetMaxPlayers();

    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (IsPlayerConnected(pid) && PlayerInfo[pid][pLogged] && Life_HasOpenJusticeRisk(pid))
        {
            openCases++;
        }
    }

    format(message, sizeof(message), "Prefeitura: cofre $%d | gastos $%d | casos abertos %d | contratos publicos via /licitacao.", gGovernmentRevenue, gGovernmentExpense, openCases);
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}

stock Life_AddTransparencyLine(list[], size, area[], value[], detail[])
{
    new line[160];

    format(line, sizeof(line), "%s\t%s\t%s\n", area, value, detail);
    strcat(list, line, size);
    return 1;
}

stock Life_FormatBudgetShare(percent, output[], size = sizeof(output))
{
    format(output, size, "$%d", (gGovernmentRevenue * percent) / 100);
    return 1;
}

stock Life_ShowTransparencyCenter(playerid)
{
    new list[4096];
    new value[48];
    new detail[96];
    new categoryName[32];
    new index;
    new categoryTotal;
    new trackedTotal;
    new expenseTrackedTotal;
    new oldTotal;
    new expenseName[32];

    for (index = 0; index < GOV_REV_CATEGORIES; index++)
    {
        trackedTotal += gGovernmentRevenueByCategory[index];
    }
    for (index = 0; index < GOV_EXP_CATEGORIES; index++)
    {
        expenseTrackedTotal += gGovernmentExpenseByCategory[index];
    }
    oldTotal = gGovernmentRevenue - trackedTotal;

    format(list, sizeof(list), "Area\tValor\tDetalhe\n");
    format(value, sizeof(value), "$%d", gGovernmentRevenue);
    Life_AddTransparencyLine(list, sizeof(list), "Cofre publico", value, "saldo disponivel agora");
    format(value, sizeof(value), "$%d", trackedTotal);
    Life_AddTransparencyLine(list, sizeof(list), "Receita detalhada", value, "entradas classificadas por origem");
    format(value, sizeof(value), "$%d", gGovernmentExpense);
    Life_AddTransparencyLine(list, sizeof(list), "Gastos publicos", value, "total ja gasto pela prefeitura");
    format(value, sizeof(value), "%d/%d", Life_CountPublicWorksDone(), LIFE_PUBLIC_WORK_COUNT);
    Life_AddTransparencyLine(list, sizeof(list), "Obras publicas", value, "reformas, hospital, delegacia e pedagios");
    if (oldTotal > 0)
    {
        format(value, sizeof(value), "$%d", oldTotal);
        Life_AddTransparencyLine(list, sizeof(list), "Saldo antigo", value, "arrecadacao anterior sem categoria");
    }
    if (gGovernmentLastRevenueAmount > 0)
    {
        format(value, sizeof(value), "$%d", gGovernmentLastRevenueAmount);
        format(detail, sizeof(detail), "origem: %s", gGovernmentLastRevenueReason);
        Life_AddTransparencyLine(list, sizeof(list), "Ultima entrada", value, detail);
    }
    if (gGovernmentLastExpenseAmount > 0)
    {
        format(value, sizeof(value), "$%d", gGovernmentLastExpenseAmount);
        format(detail, sizeof(detail), "motivo: %s", gGovernmentLastExpenseReason);
        Life_AddTransparencyLine(list, sizeof(list), "Ultimo gasto", value, detail);
    }
    if (gGovernmentLastDecisionText[0] != 0)
    {
        format(value, sizeof(value), "%s", gGovernmentLastDecisionOffice);
        format(detail, sizeof(detail), "%s", gGovernmentLastDecisionText);
        Life_AddTransparencyLine(list, sizeof(list), "Ultima decisao politica", value, detail);
        format(value, sizeof(value), "dia %d", gGovernmentLastDecisionDay);
        format(detail, sizeof(detail), "%s", gGovernmentLastDecisionImpact);
        Life_AddTransparencyLine(list, sizeof(list), "Influencia da decisao", value, detail);
    }

    for (index = 0; index < GOV_REV_CATEGORIES; index++)
    {
        categoryTotal = gGovernmentRevenueByCategory[index];
        if (categoryTotal <= 0)
        {
            continue;
        }
        Life_GovRevName(index, categoryName, sizeof(categoryName));
        format(value, sizeof(value), "$%d", categoryTotal);
        format(detail, sizeof(detail), "%d%% do cofre", gGovernmentRevenue > 0 ? (categoryTotal * 100) / gGovernmentRevenue : 0);
        Life_AddTransparencyLine(list, sizeof(list), categoryName, value, detail);
    }

    for (index = 0; index < GOV_EXP_CATEGORIES; index++)
    {
        categoryTotal = gGovernmentExpenseByCategory[index];
        if (categoryTotal <= 0)
        {
            continue;
        }
        Life_GovExpName(index, expenseName, sizeof(expenseName));
        format(value, sizeof(value), "$%d", categoryTotal);
        format(detail, sizeof(detail), "%d%% dos gastos", expenseTrackedTotal > 0 ? (categoryTotal * 100) / expenseTrackedTotal : 0);
        Life_AddTransparencyLine(list, sizeof(list), expenseName, value, detail);
    }

    Life_FormatBudgetShare(22, value, sizeof(value));
    Life_AddTransparencyLine(list, sizeof(list), "Destino: infraestrutura", value, "22% ruas, pedagios, obras e manutencao");
    Life_FormatBudgetShare(20, value, sizeof(value));
    Life_AddTransparencyLine(list, sizeof(list), "Destino: saude", value, "20% hospital, ambulancia e remedios");
    Life_FormatBudgetShare(18, value, sizeof(value));
    Life_AddTransparencyLine(list, sizeof(list), "Destino: seguranca", value, "18% policias, PRF, bombeiro e prisao");
    Life_FormatBudgetShare(15, value, sizeof(value));
    Life_AddTransparencyLine(list, sizeof(list), "Destino: social/educacao", value, "15% novatos, missoes e servicos civis");
    Life_FormatBudgetShare(10, value, sizeof(value));
    Life_AddTransparencyLine(list, sizeof(list), "Destino: administracao", value, "10% prefeitura, cartorio e sistemas");
    Life_FormatBudgetShare(15, value, sizeof(value));
    Life_AddTransparencyLine(list, sizeof(list), "Reserva publica", value, "15% emergencias e eventos da cidade");

    ShowPlayerDialog(playerid, DIALOG_TRANSPARENCY_CENTER, DIALOG_STYLE_TABLIST_HEADERS, "Central da Transparencia", list, "Fechar", "");
    return 1;
}

stock Life_PublicBid(playerid)
{
    new cost = 1200;

    if (PlayerInfo[playerid][pBusinessType] == LIFE_BUSINESS_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas empresas podem participar de licitacao.");
        return 1;
    }
    if (PlayerInfo[playerid][pBusinessBankrupt])
    {
        SendClientMessage(playerid, COLOR_RED, "Empresa em falencia nao pode participar de licitacao.");
        return 1;
    }
    if (!Bank_TakePayment(playerid, cost, 0))
    {
        SendClientMessage(playerid, COLOR_RED, "Licitacao exige caução de $1200.");
        return 1;
    }

    PlayerInfo[playerid][pBusinessOrders] += 3;
    PlayerInfo[playerid][pBusinessContracts]++;
    PlayerInfo[playerid][pBusinessStock] += 3;
    Life_AddGovernmentRevenue(cost, "licitacao");
    Life_AddCityPassProgress(playerid, CITY_PASS_KIND_PUBLIC, 1);
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_BUSINESS, 3);
    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Licitacao aprovada. Sua empresa recebeu pedidos e estoque de contrato publico.");
    return 1;
}

stock Life_AddPublicSvcAction(playerid, list[], size, actionid, label[], status[])
{
    new line[180];

    if (gLifePublicActionCount[playerid] >= LIFE_PUBLIC_MAX_ACTIONS)
    {
        return 0;
    }

    gLifePublicActions[playerid][gLifePublicActionCount[playerid]] = actionid;
    gLifePublicActionCount[playerid]++;
    format(line, sizeof(line), "%s\t%s\n", label, status);
    strcat(list, line, size);
    return 1;
}

stock Life_PublicSvcRisk(playerid)
{
    new risk;
    new today = GetBrasiliaDayStamp();

    if (PlayerInfo[playerid][pJailTime] > 0 && !gPlayerInPoliceCell[playerid])
    {
        risk++;
    }
    if (PlayerInfo[playerid][pMedicalTreatmentDue] > 0 || (PlayerInfo[playerid][pInjury] > 0 && GetPlayerInterior(playerid) != gServerLocations[LOCATION_HOSPITAL][locInterior]))
    {
        risk++;
    }
    if (Life_HasOpenJusticeRisk(playerid) || PlayerInfo[playerid][pAnkleMonitor])
    {
        risk++;
    }
    if (PlayerInfo[playerid][pVehicleModel] >= 400)
    {
        if (PlayerInfo[playerid][pVehicleImpounded] || PlayerInfo[playerid][pVehicleTaxDue] > 0)
        {
            risk++;
        }
        if (PlayerInfo[playerid][pVehicleInspectionDay] <= today)
        {
            risk++;
        }
    }
    return risk;
}

stock Life_SendPublicSvcStatus(playerid)
{
    new message[180];
    new justiceName[24];
    new injuryName[32];
    new vehicleText[48];
    new risk = Life_PublicSvcRisk(playerid);
    new today = GetBrasiliaDayStamp();

    Life_GetJusticeStatusName(PlayerInfo[playerid][pJusticeStatus], justiceName, sizeof(justiceName));
    Hospital_GetInjuryName(PlayerInfo[playerid][pInjury], injuryName, sizeof(injuryName));

    if (PlayerInfo[playerid][pVehicleModel] >= 400)
    {
        format(vehicleText, sizeof(vehicleText), "IPVA $%d | vistoria %d dia(s)", PlayerInfo[playerid][pVehicleTaxDue], PlayerInfo[playerid][pVehicleInspectionDay] - today);
    }
    else
    {
        format(vehicleText, sizeof(vehicleText), "sem veiculo ativo");
    }

    format(message, sizeof(message), "Servicos publicos: %d pendencia(s) critica(s) na conta.", risk);
    SendClientMessage(playerid, risk > 0 ? COLOR_ORANGE : COLOR_GREEN, message);
    format(message, sizeof(message), "Policia/Justica: procurado %d | casos %d | status %s | tornozeleira %s", PlayerInfo[playerid][pWanted], PlayerInfo[playerid][pJusticeCases], justiceName, PlayerInfo[playerid][pAnkleMonitor] ? ("sim") : ("nao"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "DETRAN: %s | patio %s", vehicleText, PlayerInfo[playerid][pVehicleImpounded] ? ("sim") : ("nao"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Hospital/SAMU: %s | gravidade %d | plano %s", injuryName, PlayerInfo[playerid][pMedicalSeverity], PlayerInfo[playerid][pHealthPlan] ? ("ativo") : ("pendente"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Prefeitura: arrecadacao $%d | impostos/boletos $%d | licitacao por empresa.", gGovernmentRevenue, Life_BillTotal(playerid));
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}

stock Life_PublicMission_GetName(type, output[], size = sizeof(output))
{
    switch (type)
    {
        case LIFE_PUBLIC_MISSION_FIRE: format(output, size, "Chamado de incendio");
        case LIFE_PUBLIC_MISSION_HOMICIDE: format(output, size, "Pericia de homicidio");
        case LIFE_PUBLIC_MISSION_FEDERAL: format(output, size, "Crime contra a prefeitura");
        case LIFE_PUBLIC_MISSION_PRF: format(output, size, "Fiscalizacao rodoviaria");
        case LIFE_PUBLIC_MISSION_JUDGE: format(output, size, "Audiencia de flagrante");
        case LIFE_PUBLIC_MISSION_PENAL: format(output, size, "Custodia penal");
        case LIFE_PUBLIC_MISSION_PATROL: format(output, size, "Abordagem preventiva");
        case LIFE_PUBLIC_MISSION_HEALTH: format(output, size, "Chamado hospitalar");
        default: format(output, size, "Sem ocorrencia");
    }
    return 1;
}

stock Life_PM_GetLimitMinutes(type)
{
    switch (type)
    {
        case LIFE_PUBLIC_MISSION_FIRE: return 12;
        case LIFE_PUBLIC_MISSION_HOMICIDE: return 18;
        case LIFE_PUBLIC_MISSION_FEDERAL: return 16;
        case LIFE_PUBLIC_MISSION_PRF: return 14;
        case LIFE_PUBLIC_MISSION_JUDGE: return 20;
        case LIFE_PUBLIC_MISSION_PENAL: return 15;
        case LIFE_PUBLIC_MISSION_PATROL: return 10;
        case LIFE_PUBLIC_MISSION_HEALTH: return 9;
    }
    return 12;
}

stock Life_PublicMission_GetMeta(type, risk[], riskSize, role[], roleSize, consequence[], consequenceSize)
{
    switch (type)
    {
        case LIFE_PUBLIC_MISSION_FIRE:
        {
            format(risk, riskSize, "alto");
            format(role, roleSize, "bombeiro");
            format(consequence, consequenceSize, "propagacao e vitima NPC sem socorro");
        }
        case LIFE_PUBLIC_MISSION_HOMICIDE:
        {
            format(risk, riskSize, "alto");
            format(role, roleSize, "policia civil");
            format(consequence, consequenceSize, "caso fica sem prova e criminoso foge");
        }
        case LIFE_PUBLIC_MISSION_FEDERAL:
        {
            format(risk, riskSize, "medio");
            format(role, roleSize, "policia federal");
            format(consequence, consequenceSize, "desvio publico afeta cofre da prefeitura");
        }
        case LIFE_PUBLIC_MISSION_PRF:
        {
            format(risk, riskSize, "medio");
            format(role, roleSize, "PRF");
            format(consequence, consequenceSize, "carga suspeita segue pela rodovia");
        }
        case LIFE_PUBLIC_MISSION_JUDGE:
        {
            format(risk, riskSize, "medio");
            format(role, roleSize, "juiz/justica");
            format(consequence, consequenceSize, "flagrante perde prioridade judicial");
        }
        case LIFE_PUBLIC_MISSION_PENAL:
        {
            format(risk, riskSize, "alto");
            format(role, roleSize, "policia penal");
            format(consequence, consequenceSize, "custodia vira risco de fuga");
        }
        case LIFE_PUBLIC_MISSION_PATROL:
        {
            format(risk, riskSize, "baixo");
            format(role, roleSize, "policia/seguranca");
            format(consequence, consequenceSize, "suspeito permanece na area");
        }
        case LIFE_PUBLIC_MISSION_HEALTH:
        {
            format(risk, riskSize, "alto");
            format(role, roleSize, "SAMU/medico");
            format(consequence, consequenceSize, "paciente NPC piora sem atendimento");
        }
        default:
        {
            format(risk, riskSize, "medio");
            format(role, roleSize, "servico publico");
            format(consequence, consequenceSize, "cidade absorve a ocorrencia");
        }
    }
    return 1;
}

stock Life_PublicMission_SendMeta(playerid, type)
{
    new risk[24];
    new role[40];
    new consequence[80];
    new message[160];

    Life_PublicMission_GetMeta(type, risk, sizeof(risk), role, sizeof(role), consequence, sizeof(consequence));
    format(message, sizeof(message), "Ocorrencia publica: risco %s | prazo %d min | recomendado: %s.", risk, Life_PM_GetLimitMinutes(type), role);
    SendClientMessage(playerid, COLOR_YELLOW, message);
    format(message, sizeof(message), "Consequencia se ignorar: %s.", consequence);
    SendClientMessage(playerid, COLOR_GRAY, message);
    return 1;
}

stock Life_ServiceCall_GetTypeName(type, output[], size = sizeof(output))
{
    switch (type)
    {
        case LIFE_CALL_POLICE: format(output, size, "190 Policia");
        case LIFE_CALL_SAMU: format(output, size, "192 SAMU");
        case LIFE_CALL_FIRE: format(output, size, "193 Bombeiros");
        case LIFE_CALL_TOW: format(output, size, "Guincho/Mecanico");
        default: format(output, size, "Chamado");
    }
    return 1;
}

stock Life_ServiceCall_EligibleJob(type, jobid)
{
    switch (type)
    {
        case LIFE_CALL_POLICE:
        {
            return (IsLawEnforcementJob(jobid) || jobid == JOB_SEGURANCA);
        }
        case LIFE_CALL_SAMU:
        {
            return (jobid == JOB_MEDICO || jobid == JOB_MOTORISTA_AMBULANCIA);
        }
        case LIFE_CALL_FIRE:
        {
            return (jobid == JOB_BOMBEIRO);
        }
        case LIFE_CALL_TOW:
        {
            return (jobid == JOB_MECANICO);
        }
    }
    return 0;
}

stock Life_ServiceCall_RequiredLevel(type)
{
    switch (type)
    {
        case LIFE_CALL_FIRE: return 1;
        case LIFE_CALL_POLICE: return 1;
        case LIFE_CALL_SAMU: return 1;
        case LIFE_CALL_TOW: return 1;
    }
    return 1;
}

stock Life_ServiceCall_FindFreeSlot()
{
    new index;

    for (index = 0; index < LIFE_CALL_CENTER_MAX; index++)
    {
        if (gServiceCallStatus[index] == LIFE_CALL_STATUS_NONE)
        {
            return index;
        }
    }
    return -1;
}

stock Life_ServiceCall_Count(statusFilter = -1)
{
    new index;
    new count;

    for (index = 0; index < LIFE_CALL_CENTER_MAX; index++)
    {
        if (gServiceCallStatus[index] == LIFE_CALL_STATUS_NONE)
        {
            continue;
        }
        if (statusFilter == -1 || gServiceCallStatus[index] == statusFilter)
        {
            count++;
        }
    }
    return count;
}

stock Life_ServiceCall_Clear(callid)
{
    new responder;

    if (callid < 0 || callid >= LIFE_CALL_CENTER_MAX)
    {
        return 0;
    }
    responder = gServiceCallResponder[callid];
    if (IsValidConnectedPlayer(responder) && gPlayerAcceptedCall[responder] == callid)
    {
        gPlayerAcceptedCall[responder] = -1;
        DisablePlayerCheckpoint(responder);
        if (Work_IsActive(responder))
        {
            Work_SetCheckpoint(responder);
        }
    }
    gServiceCallStatus[callid] = LIFE_CALL_STATUS_NONE;
    gServiceCallType[callid] = LIFE_CALL_NONE;
    gServiceCallCaller[callid] = INVALID_PLAYER_ID;
    gServiceCallResponder[callid] = INVALID_PLAYER_ID;
    gServiceCallTick[callid] = 0;
    gServiceCallX[callid] = 0.0;
    gServiceCallY[callid] = 0.0;
    gServiceCallZ[callid] = 0.0;
    gServiceCallDesc[callid][0] = 0;
    return 1;
}

stock Life_ServiceCall_NotifyEligible(callid)
{
    new playerid;
    new maxPlayers = GetMaxPlayers();
    new typeName[32];
    new message[160];

    if (callid < 0 || callid >= LIFE_CALL_CENTER_MAX || gServiceCallStatus[callid] != LIFE_CALL_STATUS_PENDING)
    {
        return 0;
    }

    Life_ServiceCall_GetTypeName(gServiceCallType[callid], typeName, sizeof(typeName));
    format(message, sizeof(message), "Central %s: chamado #%d aberto. Use /chamados e /aceitarchamado %d.", typeName, callid + 1, callid + 1);
    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && PlayerInfo[playerid][pLogged] && Work_IsActive(playerid) && Life_ServiceCall_EligibleJob(gServiceCallType[callid], PlayerInfo[playerid][pJob]))
        {
            SendClientMessage(playerid, COLOR_YELLOW, message);
        }
    }
    return 1;
}

stock Life_ServiceCall_Create(playerid, type, desc[])
{
    new callid;
    new typeName[32];
    new message[180];

    if (GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Chamados da central precisam ser abertos no mundo aberto para marcar GPS.");
        return 1;
    }

    callid = Life_ServiceCall_FindFreeSlot();
    if (callid == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Central lotada no momento. Tente novamente em instantes.");
        return 1;
    }

    gServiceCallStatus[callid] = LIFE_CALL_STATUS_PENDING;
    gServiceCallType[callid] = type;
    gServiceCallCaller[callid] = playerid;
    gServiceCallResponder[callid] = INVALID_PLAYER_ID;
    gServiceCallTick[callid] = GetTickCount();
    GetPlayerPos(playerid, gServiceCallX[callid], gServiceCallY[callid], gServiceCallZ[callid]);
    format(gServiceCallDesc[callid], 64, "%s", desc);

    Life_ServiceCall_GetTypeName(type, typeName, sizeof(typeName));
    format(message, sizeof(message), "%s registrado como chamado #%d. Profissionais em expediente foram avisados.", typeName, callid + 1);
    SendClientMessage(playerid, COLOR_GREEN, message);
    Life_ServiceCall_NotifyEligible(callid);
    format(message, sizeof(message), "call=%d type=%d x=%.1f y=%.1f z=%.1f desc=%s", callid + 1, type, gServiceCallX[callid], gServiceCallY[callid], gServiceCallZ[callid], gServiceCallDesc[callid]);
    WritePlayerLog(LOG_CONTRACT_FILE, "SERVICE_CALL_CREATE", playerid, message);
    return 1;
}

stock Life_ServiceCall_CreateNpc(type, desc[], Float:x, Float:y, Float:z)
{
    new callid = Life_ServiceCall_FindFreeSlot();
    new message[160];

    if (callid == -1)
    {
        return 0;
    }

    gServiceCallStatus[callid] = LIFE_CALL_STATUS_PENDING;
    gServiceCallType[callid] = type;
    gServiceCallCaller[callid] = INVALID_PLAYER_ID;
    gServiceCallResponder[callid] = INVALID_PLAYER_ID;
    gServiceCallTick[callid] = GetTickCount();
    gServiceCallX[callid] = x;
    gServiceCallY[callid] = y;
    gServiceCallZ[callid] = z;
    format(gServiceCallDesc[callid], 64, "%s", desc);
    Life_ServiceCall_NotifyEligible(callid);
    format(message, sizeof(message), "npc_call=%d type=%d x=%.1f y=%.1f z=%.1f", callid + 1, type, x, y, z);
    WriteServerLog(LOG_CONTRACT_FILE, "SERVICE_CALL_NPC", message);
    return 1;
}

stock Life_CallFromCityEvent(eventType, targetJob)
{
    new scene;

    switch (eventType)
    {
        case CITY_EVENT_BLITZ:
        {
            return Life_ServiceCall_CreateNpc(LIFE_CALL_POLICE, "acidente e tumulto em via publica", 1642.0890, -1715.3920, 13.5469);
        }
        case CITY_EVENT_HOSPITAL:
        {
            return Life_ServiceCall_CreateNpc(LIFE_CALL_SAMU, "paciente grave aguardando SAMU", 2055.5930, -1772.3290, 13.5469);
        }
        case CITY_EVENT_POLICE:
        {
            return Life_ServiceCall_CreateNpc(LIFE_CALL_POLICE, "denuncia anonima de atividade suspeita", 1174.3225, -1323.0243, 14.1096);
        }
        case CITY_EVENT_STOCK:
        {
            return Life_ServiceCall_CreateNpc(LIFE_CALL_TOW, "veiculo de entrega quebrado afetando estoque", 2451.8810, -2092.6350, 13.5469);
        }
        case CITY_EVENT_JOB_BONUS:
        {
            if (targetJob == JOB_BOMBEIRO)
            {
                scene = random(sizeof(gPublicFireScenes));
                return Life_ServiceCall_CreateNpc(LIFE_CALL_FIRE, gPublicFireScenes[scene][fireSceneName], gPublicFireScenes[scene][fireSceneX], gPublicFireScenes[scene][fireSceneY], gPublicFireScenes[scene][fireSceneZ]);
            }
            if (targetJob == JOB_MEDICO || targetJob == JOB_MOTORISTA_AMBULANCIA)
            {
                return Life_ServiceCall_CreateNpc(LIFE_CALL_SAMU, "queda com feridos durante evento urbano", 1184.8060, -1326.9100, 13.5748);
            }
            if (targetJob == JOB_MECANICO)
            {
                return Life_ServiceCall_CreateNpc(LIFE_CALL_TOW, "carro quebrado bloqueando rua", 1827.3770, -1682.3420, 13.5469);
            }
        }
    }
    return 0;
}

stock Life_ServiceCall_ShowCreate(playerid)
{
    ShowPlayerDialog(playerid, DIALOG_SERVICE_CALL_CREATE, DIALOG_STYLE_LIST, "Central de Chamados", "190 - Policia\n192 - SAMU\n193 - Bombeiros\nGuincho / mecanico", "Chamar", "Fechar");
    return 1;
}

stock Life_ServiceCall_ShowList(playerid)
{
    new list[1400];
    new line[128];
    new index;
    new typeName[32];
    new statusName[16];
    new count;

    format(list, sizeof(list), "ID\tTipo\tStatus\tDescricao\n");
    for (index = 0; index < LIFE_CALL_CENTER_MAX; index++)
    {
        if (gServiceCallStatus[index] == LIFE_CALL_STATUS_NONE)
        {
            continue;
        }
        if (!Life_ServiceCall_EligibleJob(gServiceCallType[index], PlayerInfo[playerid][pJob]) && !HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
        {
            continue;
        }
        Life_ServiceCall_GetTypeName(gServiceCallType[index], typeName, sizeof(typeName));
        format(statusName, sizeof(statusName), gServiceCallStatus[index] == LIFE_CALL_STATUS_ACCEPTED ? ("aceito") : ("aberto"));
        format(line, sizeof(line), "#%d\t%s\t%s\t%s\n", index + 1, typeName, statusName, gServiceCallDesc[index]);
        strcat(list, line, sizeof(list));
        count++;
    }
    if (!count)
    {
        strcat(list, "-\tsem chamados\t-\tnada pendente para sua profissao\n", sizeof(list));
    }
    ShowPlayerDialog(playerid, DIALOG_SERVICE_CALL_LIST, DIALOG_STYLE_TABLIST_HEADERS, "Central 190/192/193", list, "Fechar", "");
    return 1;
}

stock Life_ServiceCall_Accept(playerid, callid)
{
    new typeName[32];
    new message[180];
    new requiredLevel;

    callid--;
    if (callid < 0 || callid >= LIFE_CALL_CENTER_MAX || gServiceCallStatus[callid] == LIFE_CALL_STATUS_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Chamado invalido ou ja encerrado.");
        return 1;
    }
    if (!Work_IsActive(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Entre em expediente com /trabalhar para aceitar chamados.");
        return 1;
    }
    if (!Life_ServiceCall_EligibleJob(gServiceCallType[callid], PlayerInfo[playerid][pJob]))
    {
        SendClientMessage(playerid, COLOR_RED, "Sua profissao nao atende esse tipo de chamado.");
        return 1;
    }
    requiredLevel = Life_ServiceCall_RequiredLevel(gServiceCallType[callid]);
    if (gPlayerJobLevel[playerid][PlayerInfo[playerid][pJob]] < requiredLevel)
    {
        format(message, sizeof(message), "Este chamado exige nivel %d na profissao.", requiredLevel);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }
    if (gServiceCallStatus[callid] == LIFE_CALL_STATUS_ACCEPTED && gServiceCallResponder[callid] != playerid)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Esse chamado ja foi aceito por outro profissional.");
        return 1;
    }
    if (gPlayerAcceptedCall[playerid] != -1 && gPlayerAcceptedCall[playerid] != callid)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Conclua ou cancele seu chamado atual antes de aceitar outro.");
        return 1;
    }

    gServiceCallStatus[callid] = LIFE_CALL_STATUS_ACCEPTED;
    gServiceCallResponder[callid] = playerid;
    gPlayerAcceptedCall[playerid] = callid;
    SetPlayerCheckpoint(playerid, gServiceCallX[callid], gServiceCallY[callid], gServiceCallZ[callid], 5.5);
    Life_ServiceCall_GetTypeName(gServiceCallType[callid], typeName, sizeof(typeName));
    format(message, sizeof(message), "%s #%d aceito. Siga o checkpoint e conclua o atendimento.", typeName, callid + 1);
    SendClientMessage(playerid, COLOR_GREEN, message);
    if (IsValidConnectedPlayer(gServiceCallCaller[callid]))
    {
        format(message, sizeof(message), "Seu chamado #%d foi aceito por %s.", callid + 1, PlayerInfo[playerid][pCharacterName]);
        SendClientMessage(gServiceCallCaller[callid], COLOR_GREEN, message);
    }
    return 1;
}

stock Life_ServiceCall_Cancel(playerid)
{
    new callid = gPlayerAcceptedCall[playerid];

    if (callid < 0 || callid >= LIFE_CALL_CENTER_MAX || gServiceCallResponder[callid] != playerid)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui chamado aceito.");
        return 1;
    }
    gServiceCallStatus[callid] = LIFE_CALL_STATUS_PENDING;
    gServiceCallResponder[callid] = INVALID_PLAYER_ID;
    gServiceCallTick[callid] = GetTickCount();
    gPlayerAcceptedCall[playerid] = -1;
    DisablePlayerCheckpoint(playerid);
    if (Work_IsActive(playerid))
    {
        Work_SetCheckpoint(playerid);
    }
    SendClientMessage(playerid, COLOR_ORANGE, "Chamado devolvido para a central.");
    Life_ServiceCall_NotifyEligible(callid);
    return 1;
}

stock Life_ServiceCall_Complete(playerid)
{
    new callid = gPlayerAcceptedCall[playerid];
    new reward = LIFE_PUBLIC_MISSION_REWARD;
    new typeName[32];
    new message[180];

    if (callid < 0 || callid >= LIFE_CALL_CENTER_MAX || gServiceCallStatus[callid] != LIFE_CALL_STATUS_ACCEPTED || gServiceCallResponder[callid] != playerid)
    {
        return 0;
    }
    if (!IsPlayerInRangeOfPoint(playerid, 11.0, gServiceCallX[callid], gServiceCallY[callid], gServiceCallZ[callid]))
    {
        return 1;
    }

    reward += (gPlayerJobLevel[playerid][PlayerInfo[playerid][pJob]] * 35);
    Life_ServiceCall_GetTypeName(gServiceCallType[callid], typeName, sizeof(typeName));
    Job_GiveReward(playerid, PlayerInfo[playerid][pJob], reward, LIFE_PUBLIC_MISSION_XP + 1, "service_call_center", 1);
    Life_AddCityPassProgress(playerid, CITY_PASS_KIND_PUBLIC, 1);
    Life_AddWeeklyScore(playerid, (IsLawEnforcementJob(PlayerInfo[playerid][pJob]) || PlayerInfo[playerid][pJob] == JOB_SEGURANCA) ? WEEKLY_SCORE_POLICE : WEEKLY_SCORE_CITIZEN, 2);
    if (IsValidConnectedPlayer(gServiceCallCaller[callid]))
    {
        format(message, sizeof(message), "%s #%d atendido por %s.", typeName, callid + 1, PlayerInfo[playerid][pCharacterName]);
        SendClientMessage(gServiceCallCaller[callid], COLOR_GREEN, message);
    }
    format(message, sizeof(message), "%s concluido. Atendimento registrado e recompensa paga.", typeName);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_CONTRACT_FILE, "SERVICE_CALL_DONE", playerid, message);
    Life_ServiceCall_Clear(callid);
    return 1;
}

public Life_UpdateServiceCalls()
{
    new index;
    new elapsed;
    new message[144];

    for (index = 0; index < LIFE_CALL_CENTER_MAX; index++)
    {
        if (gServiceCallStatus[index] == LIFE_CALL_STATUS_NONE)
        {
            continue;
        }
        elapsed = GetTickCount() - gServiceCallTick[index];
        if (gServiceCallStatus[index] == LIFE_CALL_STATUS_PENDING && elapsed >= LIFE_CALL_CENTER_EXPIRE_MS)
        {
            if (IsValidConnectedPlayer(gServiceCallCaller[index]))
            {
                if (gServiceCallType[index] == LIFE_CALL_TOW)
                {
                    Dealership_TowPlayerVehicle(gServiceCallCaller[index]);
                }
                format(message, sizeof(message), "Chamado #%d foi resolvido por equipe NPC da cidade.", index + 1);
                SendClientMessage(gServiceCallCaller[index], COLOR_BLUE, message);
            }
            Life_ServiceCall_Clear(index);
            continue;
        }
        if (gServiceCallStatus[index] == LIFE_CALL_STATUS_ACCEPTED && elapsed >= LIFE_CALL_CENTER_ACTIVE_MS)
        {
            if (IsValidConnectedPlayer(gServiceCallResponder[index]))
            {
                SendClientMessage(gServiceCallResponder[index], COLOR_ORANGE, "Chamado expirou por demora e voltou para a central NPC.");
            }
            if (IsValidConnectedPlayer(gServiceCallCaller[index]))
            {
                SendClientMessage(gServiceCallCaller[index], COLOR_BLUE, "A central acionou equipe NPC para concluir seu chamado.");
            }
            Life_ServiceCall_Clear(index);
        }
    }
    return 1;
}

stock Life_PublicMission_JobType(jobid)
{
    switch (jobid)
    {
        case JOB_BOMBEIRO: return LIFE_PUBLIC_MISSION_FIRE;
        case JOB_POLICIA_CIVIL: return LIFE_PUBLIC_MISSION_HOMICIDE;
        case JOB_POLICIA_FEDERAL: return LIFE_PUBLIC_MISSION_FEDERAL;
        case JOB_PRF: return LIFE_PUBLIC_MISSION_PRF;
        case JOB_JUIZ: return LIFE_PUBLIC_MISSION_JUDGE;
        case JOB_POLICIA_PENAL: return LIFE_PUBLIC_MISSION_PENAL;
        case JOB_POLICIAL, JOB_SEGURANCA: return LIFE_PUBLIC_MISSION_PATROL;
        case JOB_MEDICO, JOB_MOTORISTA_AMBULANCIA: return LIFE_PUBLIC_MISSION_HEALTH;
    }
    return LIFE_PUBLIC_MISSION_NONE;
}

stock Life_PublicMission_AddObject(playerid, slot, modelid, Float:x, Float:y, Float:z, Float:rx = 0.0, Float:ry = 0.0, Float:rz = 0.0)
{
    if (slot < 0 || slot >= LIFE_PUBLIC_MISSION_OBJECTS)
    {
        return 0;
    }
    if (gPublicMissionObject[playerid][slot] != LIFE_PUBLIC_INVALID_ENTITY && IsValidObject(gPublicMissionObject[playerid][slot]))
    {
        DestroyObject(gPublicMissionObject[playerid][slot]);
    }
    gPublicMissionObject[playerid][slot] = CreateObject(modelid, x, y, z, rx, ry, rz);
    if (gPublicMissionObject[playerid][slot] == INVALID_OBJECT_ID)
    {
        gPublicMissionObject[playerid][slot] = LIFE_PUBLIC_INVALID_ENTITY;
        WritePlayerLog(LOG_ADMIN_FILE, "PUBLIC_MISSION_VISUAL_FAIL", playerid, "object_create_failed");
        return 0;
    }
    return 1;
}

stock Life_PublicMission_Clear(playerid, restoreWork = 1)
{
    for (new index = 0; index < LIFE_PUBLIC_MISSION_OBJECTS; index++)
    {
        if (gPublicMissionObject[playerid][index] != LIFE_PUBLIC_INVALID_ENTITY && IsValidObject(gPublicMissionObject[playerid][index]))
        {
            DestroyObject(gPublicMissionObject[playerid][index]);
        }
        gPublicMissionObject[playerid][index] = LIFE_PUBLIC_INVALID_ENTITY;
    }
    if (gPublicMissionActor[playerid] != LIFE_PUBLIC_INVALID_ENTITY && IsValidActor(gPublicMissionActor[playerid]))
    {
        DestroyActor(gPublicMissionActor[playerid]);
    }
    gPublicMissionActor[playerid] = LIFE_PUBLIC_INVALID_ENTITY;
    if (gPublicMissionVehicle[playerid] != LIFE_PUBLIC_INVALID_ENTITY && Fuel_IsValidVehicle(gPublicMissionVehicle[playerid]))
    {
        DestroyVehicle(gPublicMissionVehicle[playerid]);
    }
    gPublicMissionVehicle[playerid] = LIFE_PUBLIC_INVALID_ENTITY;

    gPublicMissionType[playerid] = LIFE_PUBLIC_MISSION_NONE;
    gPublicMissionX[playerid] = 0.0;
    gPublicMissionY[playerid] = 0.0;
    gPublicMissionZ[playerid] = 0.0;
    gPublicMissionDetail[playerid][0] = 0;
    DisablePlayerCheckpoint(playerid);
    if (restoreWork && Work_IsActive(playerid))
    {
        Work_SetCheckpoint(playerid);
    }
    return 1;
}

stock Life_PublicMission_SetActor(playerid, skinid, Float:x, Float:y, Float:z, Float:a, fallen = 0)
{
    gPublicMissionActor[playerid] = CreateActor(skinid, x, y, z, a);
    if (gPublicMissionActor[playerid] != LIFE_PUBLIC_INVALID_ENTITY)
    {
        SetActorVirtualWorld(gPublicMissionActor[playerid], 0);
        SetActorInvulnerable(gPublicMissionActor[playerid], 1);
        if (fallen)
        {
            ApplyActorAnimation(gPublicMissionActor[playerid], "PED", "KO_shot_front", 4.1, 0, 1, 1, 1, 0);
        }
    }
    return 1;
}

stock Life_PM_SpawnFireScene(playerid)
{
    new scene = random(sizeof(gPublicFireScenes));
    new level = gPlayerJobLevel[playerid][JOB_BOMBEIRO];
    new attempt;
    new Float:x = gPublicFireScenes[scene][fireSceneX];
    new Float:y = gPublicFireScenes[scene][fireSceneY];
    new Float:z = gPublicFireScenes[scene][fireSceneZ];
    new Float:a = gPublicFireScenes[scene][fireSceneA];
    new kind = gPublicFireScenes[scene][fireSceneKind];
    new modelid = gPublicFireScenes[scene][fireSceneVehicleModel];

    for (attempt = 0; attempt < 12; attempt++)
    {
        scene = random(sizeof(gPublicFireScenes));
        kind = gPublicFireScenes[scene][fireSceneKind];
        if (level < 3 && kind != LIFE_FIRE_SCENE_VEHICLE)
        {
            continue;
        }
        if (level < 5 && kind == LIFE_FIRE_SCENE_BUSINESS)
        {
            continue;
        }
        break;
    }

    x = gPublicFireScenes[scene][fireSceneX];
    y = gPublicFireScenes[scene][fireSceneY];
    z = gPublicFireScenes[scene][fireSceneZ];
    a = gPublicFireScenes[scene][fireSceneA];
    modelid = gPublicFireScenes[scene][fireSceneVehicleModel];
    format(gPublicMissionDetail[playerid], 48, "%s", gPublicFireScenes[scene][fireSceneName]);
    gPublicMissionX[playerid] = x;
    gPublicMissionY[playerid] = y;
    gPublicMissionZ[playerid] = z;

    if (kind == LIFE_FIRE_SCENE_VEHICLE && modelid >= 400)
    {
        gPublicMissionVehicle[playerid] = CreateVehicle(modelid, x, y, z + 0.2, a, 3, 1, -1);
        if (gPublicMissionVehicle[playerid] != INVALID_VEHICLE_ID)
        {
            SetVehicleVirtualWorld(gPublicMissionVehicle[playerid], 0);
            SetVehicleHealth(gPublicMissionVehicle[playerid], 330.0);
            Fuel_SetVehicleFuel(gPublicMissionVehicle[playerid], 12);
        }
        Life_PublicMission_AddObject(playerid, 0, 18688, x, y, z - 0.65);
        Life_PublicMission_AddObject(playerid, 1, 18688, x + 1.2, y + 0.8, z - 0.65);
        Life_PublicMission_AddObject(playerid, 2, 18688, x - 1.0, y - 0.7, z - 0.65);
        Life_PublicMission_AddObject(playerid, 3, 1238, x + 3.0, y + 2.2, z - 0.65);
        Life_PublicMission_AddObject(playerid, 4, 1238, x - 3.0, y - 2.2, z - 0.65);
        Life_PublicMission_SetActor(playerid, 277, x + 4.0, y + 1.8, z, a + 90.0);
        return 1;
    }

    if (kind == LIFE_FIRE_SCENE_HOUSE)
    {
        Life_PublicMission_AddObject(playerid, 0, 18688, x, y, z - 0.55);
        Life_PublicMission_AddObject(playerid, 1, 18688, x + 1.6, y - 0.9, z - 0.55);
        Life_PublicMission_AddObject(playerid, 2, 18688, x - 1.4, y + 1.1, z - 0.55);
        Life_PublicMission_AddObject(playerid, 3, 1431, x + 2.0, y + 1.2, z - 0.35, 0.0, 0.0, a);
        Life_PublicMission_AddObject(playerid, 4, 1238, x + 3.6, y, z - 0.65);
        Life_PublicMission_AddObject(playerid, 5, 1238, x - 3.6, y, z - 0.65);
        Life_PublicMission_SetActor(playerid, 25, x + 2.8, y - 1.8, z, a + 180.0, 1);
        return 1;
    }

    Life_PublicMission_AddObject(playerid, 0, 18688, x, y, z - 0.65);
    Life_PublicMission_AddObject(playerid, 1, 18688, x + 1.3, y + 1.1, z - 0.65);
    Life_PublicMission_AddObject(playerid, 2, 18688, x - 1.2, y - 1.2, z - 0.65);
    Life_PublicMission_AddObject(playerid, 3, 1225, x + 1.8, y - 0.9, z - 0.45, 0.0, 0.0, a);
    Life_PublicMission_AddObject(playerid, 4, 1431, x - 2.0, y + 1.2, z - 0.35, 0.0, 0.0, a + 35.0);
    Life_PublicMission_AddObject(playerid, 5, 1238, x + 3.4, y + 1.0, z - 0.65);
    Life_PublicMission_AddObject(playerid, 6, 1238, x - 3.4, y - 1.0, z - 0.65);
    Life_PublicMission_SetActor(playerid, 277, x + 3.0, y + 2.0, z, a);
    return 1;
}

stock Life_PublicMission_SpawnScene(playerid, type)
{
    switch (type)
    {
        case LIFE_PUBLIC_MISSION_FIRE:
        {
            return Life_PM_SpawnFireScene(playerid);
        }
        case LIFE_PUBLIC_MISSION_HOMICIDE:
        {
            gPublicMissionX[playerid] = 1795.6241;
            gPublicMissionY[playerid] = -1578.2218;
            gPublicMissionZ[playerid] = 14.0870;
            Life_PublicMission_SetActor(playerid, 29, 1793.6, -1578.8, 14.0870, 180.0, 1);
            Life_PublicMission_AddObject(playerid, 0, 1210, 1794.8, -1577.8, 13.70, 0.0, 0.0, 18.0);
            Life_PublicMission_AddObject(playerid, 1, 2894, 1796.1, -1579.0, 13.70, 0.0, 0.0, 80.0);
        }
        case LIFE_PUBLIC_MISSION_FEDERAL:
        {
            gPublicMissionX[playerid] = 1484.4487;
            gPublicMissionY[playerid] = -1771.5841;
            gPublicMissionZ[playerid] = 18.7958;
            Life_PublicMission_SetActor(playerid, 187, 1481.9, -1772.4, 18.7958, 0.0);
            Life_PublicMission_AddObject(playerid, 0, 1212, 1483.6, -1770.6, 18.30);
            Life_PublicMission_AddObject(playerid, 1, 1550, 1485.2, -1772.0, 18.25, 0.0, 0.0, 25.0);
        }
        case LIFE_PUBLIC_MISSION_PRF:
        {
            gPublicMissionX[playerid] = 1008.8067;
            gPublicMissionY[playerid] = -943.0485;
            gPublicMissionZ[playerid] = 42.1797;
            gPublicMissionVehicle[playerid] = CreateVehicle(414, 1006.4, -947.4, 42.1, 102.0, 6, 6, -1);
            if (gPublicMissionVehicle[playerid] != INVALID_VEHICLE_ID)
            {
                SetVehicleVirtualWorld(gPublicMissionVehicle[playerid], 0);
            }
            Life_PublicMission_SetActor(playerid, 180, 1011.2, -944.2, 42.1797, 281.0);
            Life_PublicMission_AddObject(playerid, 0, 1271, 1007.8, -945.3, 41.80);
            Life_PublicMission_AddObject(playerid, 1, 1575, 1009.0, -945.9, 41.80);
        }
        case LIFE_PUBLIC_MISSION_JUDGE:
        {
            gPublicMissionX[playerid] = 1387.5189;
            gPublicMissionY[playerid] = -1763.1035;
            gPublicMissionZ[playerid] = 13.5391;
            Life_PublicMission_SetActor(playerid, 17, 1385.7, -1762.5, 13.5391, 94.0);
            Life_PublicMission_AddObject(playerid, 0, 2894, 1388.4, -1762.1, 13.18, 0.0, 0.0, 92.0);
        }
        case LIFE_PUBLIC_MISSION_PENAL:
        {
            gPublicMissionX[playerid] = 1537.6119;
            gPublicMissionY[playerid] = -1676.4634;
            gPublicMissionZ[playerid] = 13.5469;
            gPublicMissionVehicle[playerid] = CreateVehicle(427, 1534.4, -1672.7, 13.5, 180.0, 0, 1, -1);
            if (gPublicMissionVehicle[playerid] != INVALID_VEHICLE_ID)
            {
                SetVehicleVirtualWorld(gPublicMissionVehicle[playerid], 0);
            }
            Life_PublicMission_SetActor(playerid, 268, 1539.7, -1676.0, 13.5469, 260.0);
        }
        case LIFE_PUBLIC_MISSION_PATROL:
        {
            gPublicMissionX[playerid] = 1174.3225;
            gPublicMissionY[playerid] = -1323.0243;
            gPublicMissionZ[playerid] = 14.1096;
            gPublicMissionVehicle[playerid] = CreateVehicle(405, 1171.2, -1325.8, 14.0, 88.0, 0, 0, -1);
            if (gPublicMissionVehicle[playerid] != INVALID_VEHICLE_ID)
            {
                SetVehicleVirtualWorld(gPublicMissionVehicle[playerid], 0);
            }
            Life_PublicMission_SetActor(playerid, 184, 1176.6, -1322.3, 14.1096, 270.0);
        }
        case LIFE_PUBLIC_MISSION_HEALTH:
        {
            gPublicMissionX[playerid] = 1191.5048;
            gPublicMissionY[playerid] = -1324.8131;
            gPublicMissionZ[playerid] = 13.3984;
            Life_PublicMission_SetActor(playerid, 274, 1189.5, -1324.8, 13.3984, 90.0, 1);
            Life_PublicMission_AddObject(playerid, 0, 1997, 1191.1, -1323.4, 13.0, 0.0, 0.0, 0.0);
        }
        default:
        {
            return 0;
        }
    }
    return 1;
}

stock Life_PublicMission_SendBrief(playerid, type)
{
    switch (type)
    {
        case LIFE_PUBLIC_MISSION_FIRE:
        {
            new message[160];
            format(message, sizeof(message), "Central 193: %s. Desloque a viatura, isole a area e combata as chamas.", gPublicMissionDetail[playerid]);
            SendClientMessage(playerid, COLOR_ORANGE, message);
            SendClientMessage(playerid, COLOR_GRAY, "O local tem fogo visual real, vitima/NPC ou risco de propagacao. Conclua no checkpoint.");
        }
        case LIFE_PUBLIC_MISSION_HOMICIDE:
        {
            SendClientMessage(playerid, COLOR_BLUE, "Policia Civil: homicidio com NPC caido. Colete prova, fotografe a cena e conclua a pericia.");
        }
        case LIFE_PUBLIC_MISSION_FEDERAL:
        {
            SendClientMessage(playerid, COLOR_BLUE, "Policia Federal: suspeita de desvio de dinheiro na Prefeitura. Aborde o servidor e apreenda documentos.");
        }
        case LIFE_PUBLIC_MISSION_PRF:
        {
            SendClientMessage(playerid, COLOR_BLUE, "PRF: veiculo suspeito na rodovia. Procure descaminho, trafico e produtos ilegais.");
        }
        case LIFE_PUBLIC_MISSION_JUDGE:
        {
            SendClientMessage(playerid, COLOR_BLUE, "Judiciario: audiencia de flagrante criada. Analise prisao, trafico ou pensao e aplique decisao.");
        }
        case LIFE_PUBLIC_MISSION_PENAL:
        {
            SendClientMessage(playerid, COLOR_BLUE, "Policia Penal: custodia com preso NPC aguardando triagem e escolta.");
        }
        case LIFE_PUBLIC_MISSION_PATROL:
        {
            SendClientMessage(playerid, COLOR_BLUE, "Seguranca publica: abordagem preventiva criada com NPC e veiculo suspeito.");
        }
        case LIFE_PUBLIC_MISSION_HEALTH:
        {
            SendClientMessage(playerid, COLOR_BLUE, "Saude publica: paciente NPC aguardando atendimento de urgencia no local.");
        }
    }
    Life_PublicMission_SendMeta(playerid, type);
    return 1;
}

stock Life_PublicMission_Start(playerid)
{
    new type;
    new missionName[48];
    new message[160];
    new elapsed;

    if (gPublicMissionType[playerid] != LIFE_PUBLIC_MISSION_NONE)
    {
        Life_PublicMission_GetName(gPublicMissionType[playerid], missionName, sizeof(missionName));
        format(message, sizeof(message), "%s em andamento. Siga o checkpoint amarelo ou use /cancelarmissaopublica.", missionName);
        SendClientMessage(playerid, COLOR_YELLOW, message);
        SetPlayerCheckpoint(playerid, gPublicMissionX[playerid], gPublicMissionY[playerid], gPublicMissionZ[playerid], LIFE_PUBLIC_MISSION_CP_SIZE);
        return 1;
    }

    type = Life_PublicMission_JobType(PlayerInfo[playerid][pJob]);
    if (type == LIFE_PUBLIC_MISSION_NONE)
    {
        SendClientMessage(playerid, COLOR_RED, "Sua profissao atual ainda nao possui ocorrencia publica com NPC.");
        SendClientMessage(playerid, COLOR_GRAY, "Disponivel para bombeiro, policias, PRF, PF, Civil, Penal, juiz, seguranca e saude.");
        return 1;
    }
    if (!Work_IsActive(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Entre em expediente com /trabalhar antes de assumir uma ocorrencia publica.");
        return 1;
    }
    if (gPublicMissionLastTick[playerid] > 0)
    {
        elapsed = GetTickCount() - gPublicMissionLastTick[playerid];
        if (elapsed < LIFE_PUBLIC_MISSION_COOLDOWN_MS)
        {
            format(message, sizeof(message), "A central so libera outra ocorrencia em %d segundo(s).", (LIFE_PUBLIC_MISSION_COOLDOWN_MS - elapsed) / 1000);
            SendClientMessage(playerid, COLOR_ORANGE, message);
            return 1;
        }
    }

    if (!Life_PublicMission_SpawnScene(playerid, type))
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel gerar a ocorrencia publica agora.");
        return 1;
    }

    gPublicMissionType[playerid] = type;
    Life_PublicMission_GetName(type, missionName, sizeof(missionName));
    Life_PublicMission_SendBrief(playerid, type);
    SetPlayerCheckpoint(playerid, gPublicMissionX[playerid], gPublicMissionY[playerid], gPublicMissionZ[playerid], LIFE_PUBLIC_MISSION_CP_SIZE);
    format(message, sizeof(message), "Ocorrencia marcada: %s. Va ate o checkpoint e conclua a acao.", missionName);
    SendClientMessage(playerid, COLOR_YELLOW, message);
    format(message, sizeof(message), "type=%d job=%d x=%.1f y=%.1f z=%.1f", type, PlayerInfo[playerid][pJob], gPublicMissionX[playerid], gPublicMissionY[playerid], gPublicMissionZ[playerid]);
    WritePlayerLog(LOG_CONTRACT_FILE, "PUBLIC_MISSION_START", playerid, message);
    return 1;
}

stock Life_PublicMission_Complete(playerid)
{
    new type = gPublicMissionType[playerid];
    new missionName[48];
    new message[160];
    new rewardOk;
    new category = GOV_EXP_ADMIN;
    new bonusPercent;
    new rewardAmount = LIFE_PUBLIC_MISSION_REWARD;

    if (type == LIFE_PUBLIC_MISSION_NONE)
    {
        return 0;
    }

    Life_PublicMission_GetName(type, missionName, sizeof(missionName));
    switch (type)
    {
        case LIFE_PUBLIC_MISSION_FIRE:
        {
            if (gPublicMissionDetail[playerid][0])
            {
                format(message, sizeof(message), "Fogo controlado em %s. Area isolada, risco eliminado e vitima/NPC atendida.", gPublicMissionDetail[playerid]);
                SendClientMessage(playerid, COLOR_GREEN, message);
            }
            else
            {
                SendClientMessage(playerid, COLOR_GREEN, "Fogo controlado, area isolada e vitima NPC atendida.");
            }
        }
        case LIFE_PUBLIC_MISSION_HOMICIDE:
        {
            SendClientMessage(playerid, COLOR_GREEN, "Pericia concluida: corpo identificado, prova apreendida e inquerito aberto.");
        }
        case LIFE_PUBLIC_MISSION_FEDERAL:
        {
            SendClientMessage(playerid, COLOR_GREEN, "Operacao federal concluida: documentos e dinheiro suspeito apreendidos na Prefeitura.");
        }
        case LIFE_PUBLIC_MISSION_PRF:
        {
            SendClientMessage(playerid, COLOR_GREEN, "Fiscalizacao concluida: carga ilegal apreendida e ocorrencia rodoviaria registrada.");
        }
        case LIFE_PUBLIC_MISSION_JUDGE:
        {
            SendClientMessage(playerid, COLOR_GREEN, "Audiencia concluida: flagrante analisado, decisao registrada e processo encerrado.");
        }
        case LIFE_PUBLIC_MISSION_PENAL:
        {
            SendClientMessage(playerid, COLOR_GREEN, "Custodia concluida: preso NPC conferido e transferencia autorizada.");
        }
        case LIFE_PUBLIC_MISSION_PATROL:
        {
            SendClientMessage(playerid, COLOR_GREEN, "Abordagem concluida: veiculo suspeito fiscalizado e area liberada.");
        }
        case LIFE_PUBLIC_MISSION_HEALTH:
        {
            SendClientMessage(playerid, COLOR_GREEN, "Atendimento concluido: paciente NPC estabilizado e encaminhado ao hospital.");
        }
    }

    switch (type)
    {
        case LIFE_PUBLIC_MISSION_FIRE, LIFE_PUBLIC_MISSION_PRF, LIFE_PUBLIC_MISSION_PATROL: category = GOV_EXP_SECURITY;
        case LIFE_PUBLIC_MISSION_HEALTH: category = GOV_EXP_HEALTH;
        case LIFE_PUBLIC_MISSION_JUDGE, LIFE_PUBLIC_MISSION_PENAL, LIFE_PUBLIC_MISSION_FEDERAL, LIFE_PUBLIC_MISSION_HOMICIDE: category = GOV_EXP_SECURITY;
    }
    bonusPercent = Life_GetPublicWorkBonus(category);
    if (bonusPercent > 0)
    {
        rewardAmount += (LIFE_PUBLIC_MISSION_REWARD * bonusPercent) / 100;
        format(message, sizeof(message), "Obras publicas ativas: pagamento da ocorrencia recebeu +%d%%.", bonusPercent);
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    if (gGovernmentRevenue >= rewardAmount)
    {
        Life_AddGovernmentExpense(playerid, rewardAmount, category, "public_mission");
    }
    else
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Cofre publico baixo: servico concluido, mas pagamento entrou como verba emergencial.");
    }

    rewardOk = Job_GiveReward(playerid, PlayerInfo[playerid][pJob], rewardAmount, LIFE_PUBLIC_MISSION_XP, "public_service_pve", 1);
    Life_AddCityPassProgress(playerid, CITY_PASS_KIND_PUBLIC, 1);
    if (IsLawEnforcementJob(PlayerInfo[playerid][pJob]) || PlayerInfo[playerid][pJob] == JOB_SEGURANCA)
    {
        Life_AddWeeklyScore(playerid, WEEKLY_SCORE_POLICE, 2);
    }
    else
    {
        Life_AddWeeklyScore(playerid, WEEKLY_SCORE_CITIZEN, 1);
    }
    gPublicMissionLastTick[playerid] = GetTickCount();
    format(message, sizeof(message), "complete type=%d name=%s reward=%d", type, missionName, rewardOk);
    WritePlayerLog(LOG_CONTRACT_FILE, "PUBLIC_MISSION_COMPLETE", playerid, message);
    Life_PublicMission_Clear(playerid, 1);
    return 1;
}

stock Life_PublicMission_OnCheckpoint(playerid)
{
    if (gPublicMissionType[playerid] == LIFE_PUBLIC_MISSION_NONE)
    {
        return 0;
    }
    if (GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
    {
        SendClientMessage(playerid, COLOR_RED, "A ocorrencia publica esta no mundo aberto. Saia do interior e siga o checkpoint.");
        SetPlayerCheckpoint(playerid, gPublicMissionX[playerid], gPublicMissionY[playerid], gPublicMissionZ[playerid], LIFE_PUBLIC_MISSION_CP_SIZE);
        return 1;
    }
    if (!IsPlayerInRangeOfPoint(playerid, LIFE_PUBLIC_MISSION_CP_SIZE + 6.0, gPublicMissionX[playerid], gPublicMissionY[playerid], gPublicMissionZ[playerid]))
    {
        return 1;
    }
    return Life_PublicMission_Complete(playerid);
}

stock Life_PublicMission_Cancel(playerid)
{
    if (gPublicMissionType[playerid] == LIFE_PUBLIC_MISSION_NONE)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui ocorrencia publica ativa.");
        return 1;
    }
    gPublicMissionLastTick[playerid] = GetTickCount();
    Life_PublicMission_Clear(playerid, 1);
    SendClientMessage(playerid, COLOR_ORANGE, "Ocorrencia publica cancelada.");
    return 1;
}

stock Life_ShowEnergyDialog(playerid)
{
    new propertyid = Property_GetPlayerResidence(playerid);
    new message[180];
    new occupants;
    new waterBill;
    new electricBill;
    new solarCost;

    if (!Property_IsValid(propertyid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce precisa morar em uma casa/apartamento para ter conta de agua e energia.");
        SendClientMessage(playerid, COLOR_GRAY, "Use /casas para comprar ou alugar uma residencia.");
        return 1;
    }

    occupants = Life_GetResidenceOccupants(propertyid);
    waterBill = Life_GetResidenceWaterBill(propertyid);
    electricBill = Life_GetResidenceElectricBill(playerid, propertyid);
    solarCost = Life_GetHomeSolarInstallCost(playerid);

    format(message, sizeof(message), "Residencia ID %d | moradores online: %d | agua mensal estimada $%d | luz mensal estimada $%d.", propertyid, occupants, waterBill, electricBill);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Hidreletrica: %s | desconto publico energia: %d%%.", Life_IsPublicWorkDone(LIFE_PUBLIC_WORK_HYDRO) ? ("ativa") : ("pendente em /obraspublicas"), gCfgBillHydroDiscountPercent);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Energia solar da casa: %s | desconto residencial: %d%% | instalacao: $%d.", PlayerInfo[playerid][pHomeSolar] ? ("instalada") : ("nao instalada"), gCfgHomeSolarDiscountPercent, solarCost);
    SendClientMessage(playerid, COLOR_BLUE, message);
    SendClientMessage(playerid, COLOR_GRAY, "Use /instalarsolar para colocar painel solar no seu imovel proprio. Use /boletos para pagar agua/luz.");
    return 1;
}

stock Life_InstallHomeSolar(playerid)
{
    new propertyid = PlayerInfo[playerid][pHouse];
    new cost;
    new message[144];

    if (!Property_IsValid(propertyid))
    {
        SendClientMessage(playerid, COLOR_RED, "Energia solar so pode ser instalada em imovel proprio.");
        return 1;
    }
    if (PlayerInfo[playerid][pHomeSolar])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Sua residencia ja possui energia solar instalada.");
        return 1;
    }

    cost = Life_GetHomeSolarInstallCost(playerid);
    if (!Bank_TakePaymentReason(playerid, cost, 0, "home_solar_install"))
    {
        format(message, sizeof(message), "Instalar energia solar custa $%d.", cost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    PlayerInfo[playerid][pHomeSolar] = 1;
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Energia solar instalada. Sua conta de luz residencial tera desconto de %d%%.", gCfgHomeSolarDiscountPercent);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_MONEY_FILE, "HOME_SOLAR", playerid, "installed=1");
    return 1;
}

stock Life_OnPlayerDisconnect(playerid)
{
    new pid;
    new maxPlayers = GetMaxPlayers();
    new callid;

    Life_PublicMission_Clear(playerid, 0);
    Life_ResetLogisticsOffer(playerid);
    Life_ResetLogisticsActive(playerid);
    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (gLogisticsOfferFrom[pid] == playerid)
        {
            Life_ResetLogisticsOffer(pid);
        }
        if (gLogisticsOwner[pid] == playerid)
        {
            Life_CancelLogisticsContract(pid, "owner_disconnect");
        }
    }
    for (callid = 0; callid < LIFE_CALL_CENTER_MAX; callid++)
    {
        if (gServiceCallStatus[callid] != LIFE_CALL_STATUS_NONE && (gServiceCallCaller[callid] == playerid || gServiceCallResponder[callid] == playerid))
        {
            Life_ServiceCall_Clear(callid);
        }
    }
    gPlayerAcceptedCall[playerid] = -1;
    gPublicMissionLastTick[playerid] = 0;
    gLifeOnboardingHintShown[playerid] = 0;
    return 1;
}

stock Life_ShowConstitutionDialog(playerid)
{
    new list[3800];

    format(list, sizeof(list), "Artigo\tTema\tResumo/Pena\n");
    strcat(list, "Art. 1\tDireitos do player\tAtendimento publico, defesa, propriedade, trabalho, circulacao e devido processo.\n", sizeof(list));
    strcat(list, "Art. 2\tLimite do poder publico\tCargo publico nao pode abusar de prisao, multa, abordagem, sentenca ou apreensao.\n", sizeof(list));
    strcat(list, "Art. 3\tInstituicoes\tPM, PRF, PF, Civil, Penal, Bombeiros, SAMU, Prefeitura e Judiciario atuam em servico.\n", sizeof(list));
    strcat(list, "Art. 4\tCrimes contra a vida\tHomicidio, tentativa, latrocinio RP e omissao de socorro em ocorrencia ativa.\n", sizeof(list));
    strcat(list, "Art. 5\tCrimes economicos\tFraude, desvio publico, lavagem, sonegacao, contrato falso e abuso de empresa.\n", sizeof(list));
    strcat(list, "Art. 6\tRodovia/fronteira\tDescaminho, contrabando, trafico, produto ilegal e fuga de fiscalizacao.\n", sizeof(list));
    strcat(list, "Art. 7\tAdministracao publica\tCorrupcao, desacato RP, falso documento, falsa identidade e obstrucao de servico.\n", sizeof(list));
    strcat(list, "Art. 8\tPenalidades\tMulta, apreensao, prisao, fianca, tornozeleira, perda de score e bloqueio de cargo.\n", sizeof(list));
    strcat(list, "Art. 9\tJudiciario\tJuiz decide flagrante, trafico, pensao, recurso, fianca e conflitos com caso aberto.\n", sizeof(list));
    strcat(list, "Art. 10\tAnti-exploit\tBug, farm, teleport indevido e dinheiro irregular podem gerar punicao staff.\n", sizeof(list));
    Police_AppendLawCrimeRows(list, sizeof(list));
    strcat(list, "Consulta\tComandos\tUse /leis, /constituicao, /crimes, /justica e /servicospublicos.\n", sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_PUBLIC_CONSTITUTION, DIALOG_STYLE_TABLIST_HEADERS, "Constituicao e leis da cidade", list, "Fechar", "");
    return 1;
}
stock Life_ShowPublicSvcDialog(playerid)
{
    new list[1200];
    new status[160];
    new justiceName[24];
    new injuryName[32];
    new daysLeft;
    new today = GetBrasiliaDayStamp();

    Life_UpdateJusticeCase(playerid, 0);
    Life_GetJusticeStatusName(PlayerInfo[playerid][pJusticeStatus], justiceName, sizeof(justiceName));
    Hospital_GetInjuryName(PlayerInfo[playerid][pInjury], injuryName, sizeof(injuryName));

    format(list, sizeof(list), "Servico\tStatus\n");
    gLifePublicActionCount[playerid] = 0;

    format(status, sizeof(status), "%d pendencia(s) critica(s)", Life_PublicSvcRisk(playerid));
    Life_AddPublicSvcAction(playerid, list, sizeof(list), LIFE_PUBLIC_STATUS, "Resumo operacional", status);

    format(status, sizeof(status), "casos %d | status %s | sentenca $%d", PlayerInfo[playerid][pJusticeCases], justiceName, PlayerInfo[playerid][pJusticeFineDue]);
    Life_AddPublicSvcAction(playerid, list, sizeof(list), LIFE_PUBLIC_JUSTICE, "Policia e justica", status);

    if (PlayerInfo[playerid][pVehicleModel] >= 400)
    {
        daysLeft = PlayerInfo[playerid][pVehicleInspectionDay] - today;
        format(status, sizeof(status), "IPVA $%d | vistoria %d dia(s) | patio %s", PlayerInfo[playerid][pVehicleTaxDue], daysLeft, PlayerInfo[playerid][pVehicleImpounded] ? ("sim") : ("nao"));
    }
    else
    {
        format(status, sizeof(status), "sem veiculo ativo");
    }
    Life_AddPublicSvcAction(playerid, list, sizeof(list), LIFE_PUBLIC_DETRAN, "DETRAN", status);

    format(status, sizeof(status), "%s | gravidade %d | tratamento %s", injuryName, PlayerInfo[playerid][pMedicalSeverity], PlayerInfo[playerid][pMedicalTreatmentDue] ? ("pendente") : ("regular"));
    Life_AddPublicSvcAction(playerid, list, sizeof(list), LIFE_PUBLIC_HEALTH, "Hospital e SAMU", status);

    format(status, sizeof(status), "impostos/boletos $%d", Life_BillTotal(playerid));
    Life_AddPublicSvcAction(playerid, list, sizeof(list), LIFE_PUBLIC_TAXES, "Impostos e taxas", status);

    format(status, sizeof(status), "arrecadacao $%d | contratos publicos", gGovernmentRevenue);
    Life_AddPublicSvcAction(playerid, list, sizeof(list), LIFE_PUBLIC_BUDGET, "Prefeitura e orcamento", status);

    format(status, sizeof(status), PlayerInfo[playerid][pBusinessType] == LIFE_BUSINESS_NONE ? ("exige empresa ativa") : ("caucao $1200"));
    Life_AddPublicSvcAction(playerid, list, sizeof(list), LIFE_PUBLIC_BID, "Licitacao publica", status);

    format(status, sizeof(status), "GPS para o orgao mais urgente");
    Life_AddPublicSvcAction(playerid, list, sizeof(list), LIFE_PUBLIC_ROUTE, "Atendimento presencial", status);

    format(status, sizeof(status), "190/192/193 e guincho com profissionais online");
    Life_AddPublicSvcAction(playerid, list, sizeof(list), LIFE_PUBLIC_CALL_CENTER, "Central de chamados", status);

    if (gPublicMissionType[playerid] != LIFE_PUBLIC_MISSION_NONE)
    {
        Life_PublicMission_GetName(gPublicMissionType[playerid], status, sizeof(status));
        strcat(status, " ativa", sizeof(status));
    }
    else if (Life_PublicMission_JobType(PlayerInfo[playerid][pJob]) == LIFE_PUBLIC_MISSION_NONE)
    {
        format(status, sizeof(status), "exige cargo publico elegivel");
    }
    else if (!Work_IsActive(playerid))
    {
        format(status, sizeof(status), "use /trabalhar primeiro");
    }
    else
    {
        format(status, sizeof(status), "gerar ocorrencia com NPC");
    }
    Life_AddPublicSvcAction(playerid, list, sizeof(list), LIFE_PUBLIC_MISSION, "Missao publica com NPC", status);

    format(status, sizeof(status), "direitos, crimes e instituicoes");
    Life_AddPublicSvcAction(playerid, list, sizeof(list), LIFE_PUBLIC_CONSTITUTION, "Constituicao da cidade", status);

    format(status, sizeof(status), "%d/%d concluidas | bonus real por area", Life_CountPublicWorksDone(), LIFE_PUBLIC_WORK_COUNT);
    Life_AddPublicSvcAction(playerid, list, sizeof(list), LIFE_PUBLIC_WORKS, "Obras publicas", status);

    ShowPlayerDialog(playerid, DIALOG_PUBLIC_SERVICES, DIALOG_STYLE_TABLIST_HEADERS, "Servicos publicos", list, "Abrir", "Fechar");
    return 1;
}

stock Life_HandlePublicSvcAction(playerid, actionid)
{
    switch (actionid)
    {
        case LIFE_PUBLIC_STATUS:
        {
            Life_SendPublicSvcStatus(playerid);
        }
        case LIFE_PUBLIC_JUSTICE:
        {
            Life_ShowJusticeDialog(playerid);
        }
        case LIFE_PUBLIC_DETRAN:
        {
            Dealership_ShowDetranDialog(playerid);
        }
        case LIFE_PUBLIC_HEALTH:
        {
            Life_ShowHealthDialog(playerid);
        }
        case LIFE_PUBLIC_TAXES:
        {
            Life_ShowTaxesDialog(playerid);
        }
        case LIFE_PUBLIC_BUDGET:
        {
            Life_ShowCityBudget(playerid);
            SendClientMessage(playerid, COLOR_GRAY, "Use /licitacao para contratos publicos se voce tiver empresa ativa.");
        }
        case LIFE_PUBLIC_BID:
        {
            Life_PublicBid(playerid);
        }
        case LIFE_PUBLIC_ROUTE:
        {
            if (PlayerInfo[playerid][pMedicalTreatmentDue] > 0 || PlayerInfo[playerid][pInjury] > 0)
            {
                SetPlayerGps(playerid, LOCATION_HOSPITAL);
            }
            else if (PlayerInfo[playerid][pWanted] > 0 || Life_HasOpenJusticeRisk(playerid) || PlayerInfo[playerid][pAnkleMonitor])
            {
                SetPlayerGps(playerid, LOCATION_DELEGACIA);
            }
            else if (PlayerInfo[playerid][pVehicleModel] >= 400)
            {
                SetPlayerGps(playerid, LOCATION_DETRAN);
            }
            else
            {
                SetPlayerGps(playerid, LOCATION_PREFEITURA);
            }
        }
        case LIFE_PUBLIC_CALL_CENTER:
        {
            Life_ServiceCall_ShowCreate(playerid);
        }
        case LIFE_PUBLIC_MISSION:
        {
            Life_PublicMission_Start(playerid);
        }
        case LIFE_PUBLIC_CONSTITUTION:
        {
            Life_ShowConstitutionDialog(playerid);
        }
        case LIFE_PUBLIC_WORKS:
        {
            Life_ShowPublicWorks(playerid);
        }
    }
    return 1;
}

stock Life_ShowBusinessRanking(playerid)
{
    new pid;
    new maxPlayers = GetMaxPlayers();
    new name[MAX_PLAYER_NAME + 1];
    new typeName[32];
    new message[144];
    new shown;

    SendClientMessage(playerid, COLOR_BLUE, "Ranking simples de empresas online:");
    for (pid = 0; pid < maxPlayers; pid++)
    {
        if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged] || PlayerInfo[pid][pBusinessType] == LIFE_BUSINESS_NONE)
        {
            continue;
        }

        GetPlayerNameEx(pid, name, sizeof(name));
        Life_GetBusinessName(PlayerInfo[pid][pBusinessType], typeName, sizeof(typeName));
        format(message, sizeof(message), "%s | %s | Caixa $%d | Func %d | Imposto $%d", name, typeName, PlayerInfo[pid][pBusinessBalance], PlayerInfo[pid][pBusinessEmployees], PlayerInfo[pid][pBusinessTaxDue]);
        SendClientMessage(playerid, COLOR_BLUE, message);
        shown++;
    }

    if (!shown)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Nenhuma empresa online no momento.");
    }
    return 1;
}

stock Life_ShowBillsDialog(playerid)
{
    new list[1600];
    new line[144];
    new days[32];
    new total;

    Life_GenMonthlyBills(playerid, 0);
    Life_ApplyLateFees(playerid, 0);
    Life_FormatDays(PlayerInfo[playerid][pBillDueDay], days, sizeof(days));
    total = Life_BillTotal(playerid);

    format(list, sizeof(list), "Boleto\tValor\n");
    gLifeBillActionCount[playerid] = 0;
    format(line, sizeof(line), "Agua\t$%d", PlayerInfo[playerid][pBillWaterDue]); Life_AddBillAction(playerid, list, sizeof(list), 0, line);
    format(line, sizeof(line), "Luz\t$%d", PlayerInfo[playerid][pBillElectricDue]); Life_AddBillAction(playerid, list, sizeof(list), 1, line);
    format(line, sizeof(line), "Internet\t$%d", PlayerInfo[playerid][pBillInternetDue]); Life_AddBillAction(playerid, list, sizeof(list), 2, line);
    format(line, sizeof(line), "Aluguel\t$%d", PlayerInfo[playerid][pBillRentDue]); Life_AddBillAction(playerid, list, sizeof(list), 3, line);
    format(line, sizeof(line), "IPTU\t$%d", PlayerInfo[playerid][pPropertyTaxDue]); Life_AddBillAction(playerid, list, sizeof(list), 4, line);
    format(line, sizeof(line), "IPVA/CRLV\t$%d", PlayerInfo[playerid][pVehicleTaxDue]); Life_AddBillAction(playerid, list, sizeof(list), 5, line);
    format(line, sizeof(line), "Seguro veicular\t$%d", PlayerInfo[playerid][pBillVehicleInsuranceDue]); Life_AddBillAction(playerid, list, sizeof(list), 6, line);
    format(line, sizeof(line), "Plano de saude\t$%d", PlayerInfo[playerid][pBillHealthPlanDue]); Life_AddBillAction(playerid, list, sizeof(list), 7, line);
    format(line, sizeof(line), "Parcela de emprestimo\t$%d", PlayerInfo[playerid][pBillLoanInstallmentDue]); Life_AddBillAction(playerid, list, sizeof(list), 8, line);
    format(line, sizeof(line), "Empresa/funcionarios\t$%d", PlayerInfo[playerid][pBillBusinessPayrollDue]); Life_AddBillAction(playerid, list, sizeof(list), 9, line);
    format(line, sizeof(line), "Multas\t$%d | pontos CNH %d", PlayerInfo[playerid][pFines], PlayerInfo[playerid][pTrafficPoints]); Life_AddBillAction(playerid, list, sizeof(list), 10, line);
    format(line, sizeof(line), "Sentenca judicial\t$%d", PlayerInfo[playerid][pJusticeFineDue]); Life_AddBillAction(playerid, list, sizeof(list), 11, line);
    format(line, sizeof(line), "Taxas GovBR\t$%d", PlayerInfo[playerid][pGovernmentTaxDue]); Life_AddBillAction(playerid, list, sizeof(list), 14, line);
    format(line, sizeof(line), "Pagar tudo\t$%d | vencimento %s", total, days); Life_AddBillAction(playerid, list, sizeof(list), 12, line);
    format(line, sizeof(line), "Situacao SPC/Serasa\t%s | score %d", PlayerInfo[playerid][pDirtyName] ? ("restrito") : ("regular"), Life_GetBankScore(playerid)); Life_AddBillAction(playerid, list, sizeof(list), 13, line);
    ShowPlayerDialog(playerid, DIALOG_LIFE_BILLS, DIALOG_STYLE_TABLIST_HEADERS, "Boletos e SPC/Serasa", list, "Pagar", "Fechar");
    return 1;
}

stock Life_ClearPaidStatus(playerid)
{
    if (Life_BillTotal(playerid) <= 0)
    {
        PlayerInfo[playerid][pDirtyName] = 0;
        PlayerInfo[playerid][pBillDueDay] = GetBrasiliaDayStamp() + gCfgBillDueDays;
        PlayerInfo[playerid][pBillLateChargeDay] = 0;
    }
    Life_GetBankScore(playerid);
    return 1;
}

stock Life_ReduceLoanByBill(playerid, amount)
{
    return Bank_RegisterLoanPay(playerid, amount);
}

stock Life_PayBillItem(playerid, item)
{
    new amount;
    new govAmount;
    new loanAmount;
    new message[144];
    new source[64];

    switch (item)
    {
        case 0: amount = PlayerInfo[playerid][pBillWaterDue];
        case 1: amount = PlayerInfo[playerid][pBillElectricDue];
        case 2: amount = PlayerInfo[playerid][pBillInternetDue];
        case 3: amount = PlayerInfo[playerid][pBillRentDue];
        case 4: amount = PlayerInfo[playerid][pPropertyTaxDue];
        case 5: amount = PlayerInfo[playerid][pVehicleTaxDue];
        case 6: amount = PlayerInfo[playerid][pBillVehicleInsuranceDue];
        case 7: amount = PlayerInfo[playerid][pBillHealthPlanDue];
        case 8: amount = PlayerInfo[playerid][pBillLoanInstallmentDue];
        case 9: amount = PlayerInfo[playerid][pBillBusinessPayrollDue];
        case 10: amount = PlayerInfo[playerid][pFines];
        case 11: amount = PlayerInfo[playerid][pJusticeFineDue];
        case 12: amount = Life_BillTotal(playerid);
        case 13:
        {
            Life_ShowBankScore(playerid);
            return 1;
        }
        case 14: amount = PlayerInfo[playerid][pGovernmentTaxDue];
        default: return 1;
    }

    if (amount <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Nao ha boleto pendente nesta categoria.");
        return 1;
    }

    if (!Bank_TakePayment(playerid, amount, 0))
    {
        format(message, sizeof(message), "Saldo insuficiente para pagar este boleto: $%d.", amount);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    if (item == 0 || item == 12) { govAmount += PlayerInfo[playerid][pBillWaterDue]; PlayerInfo[playerid][pBillWaterDue] = 0; }
    if (item == 1 || item == 12) { govAmount += PlayerInfo[playerid][pBillElectricDue]; PlayerInfo[playerid][pBillElectricDue] = 0; }
    if (item == 2 || item == 12) { govAmount += PlayerInfo[playerid][pBillInternetDue]; PlayerInfo[playerid][pBillInternetDue] = 0; }
    if (item == 3 || item == 12) { govAmount += PlayerInfo[playerid][pBillRentDue]; PlayerInfo[playerid][pBillRentDue] = 0; }
    if (item == 4 || item == 12) { govAmount += PlayerInfo[playerid][pPropertyTaxDue]; PlayerInfo[playerid][pPropertyTaxDue] = 0; }
    if (item == 5 || item == 12) { govAmount += PlayerInfo[playerid][pVehicleTaxDue]; PlayerInfo[playerid][pVehicleTaxDue] = 0; }
    if (item == 6 || item == 12)
    {
        govAmount += PlayerInfo[playerid][pBillVehicleInsuranceDue];
        PlayerInfo[playerid][pBillVehicleInsuranceDue] = 0;
        if (PlayerInfo[playerid][pVehicleModel] >= 400)
        {
            PlayerInfo[playerid][pVehicleInsurance] = 1;
        }
    }
    if (item == 7 || item == 12)
    {
        govAmount += PlayerInfo[playerid][pBillHealthPlanDue];
        PlayerInfo[playerid][pBillHealthPlanDue] = 0;
        Life_SetHealthPlan(playerid);
    }
    if (item == 8 || item == 12)
    {
        loanAmount = PlayerInfo[playerid][pBillLoanInstallmentDue];
        Life_ReduceLoanByBill(playerid, loanAmount);
        PlayerInfo[playerid][pBillLoanInstallmentDue] = 0;
    }
    if (item == 9 || item == 12) { PlayerInfo[playerid][pBillBusinessPayrollDue] = 0; }
    if (item == 10 || item == 12) { govAmount += PlayerInfo[playerid][pFines]; PlayerInfo[playerid][pFines] = 0; }
    if (item == 11 || item == 12) { govAmount += PlayerInfo[playerid][pJusticeFineDue]; PlayerInfo[playerid][pJusticeFineDue] = 0; }
    if (item == 14 || item == 12) { govAmount += PlayerInfo[playerid][pGovernmentTaxDue]; PlayerInfo[playerid][pGovernmentTaxDue] = 0; }

    if (govAmount > 0)
    {
        Life_AddGovernmentRevenue(govAmount, "bills");
    }
    if (Life_BillTotal(playerid) <= 0)
    {
        PlayerInfo[playerid][pBankGoodHistory]++;
    }

    Life_ClearPaidStatus(playerid);
    SaveAccountData(playerid, 0);
    Bank_FormatLastPaymentSource(playerid, source, sizeof(source));
    format(message, sizeof(message), "Pagamento registrado: $%d (%s).", amount, source);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(message, sizeof(message), "bill_pay item=%d amount=%d remaining=%d score=%d", item, amount, Life_BillTotal(playerid), PlayerInfo[playerid][pBankScore]);
    WritePlayerLog(LOG_MONEY_FILE, "BILLS", playerid, message);
    Life_AddMissionProgress(playerid, 4, 1);
    Life_CheckAchievements(playerid);
    return 1;
}

stock Life_ShowContractsDialog(playerid)
{
    new list[1024];
    new line[128];

    format(list, sizeof(list), "Contrato\tStatus\n");
    gLifeContractActionCount[playerid] = 0;
    format(line, sizeof(line), "Status geral\tAluguel %s | Financiamento %s | Trabalho %s | Seguro %s", PlayerInfo[playerid][pContractRent] ? ("ativo") : ("nao"), PlayerInfo[playerid][pContractFinancing] ? ("ativo") : ("nao"), PlayerInfo[playerid][pContractWork] ? ("ativo") : ("nao"), PlayerInfo[playerid][pContractInsurance] ? ("ativo") : ("nao")); Life_AddContractAction(playerid, list, sizeof(list), 0, line);
    format(line, sizeof(line), "Contrato de aluguel\t$%d", Cfg_Price(gCfgContractRentCost)); Life_AddContractAction(playerid, list, sizeof(list), 1, line);
    format(line, sizeof(line), "Contrato de financiamento\t$%d", Cfg_Price(gCfgContractFinanceCost)); Life_AddContractAction(playerid, list, sizeof(list), 2, line);
    format(line, sizeof(line), "Contrato de trabalho\t$%d", Cfg_Price(gCfgContractWorkCost)); Life_AddContractAction(playerid, list, sizeof(list), 3, line);
    format(line, sizeof(line), "Contrato de seguro\t$%d", Cfg_Price(gCfgContractInsuranceCost)); Life_AddContractAction(playerid, list, sizeof(list), 4, line);
    format(line, sizeof(line), "Cancelar aluguel\tMulta $%d", Cfg_Price(gCfgContractCancelFine)); Life_AddContractAction(playerid, list, sizeof(list), 5, line);
    format(line, sizeof(line), "Cancelar financiamento\tMulta $%d", Cfg_Price(gCfgContractCancelFine)); Life_AddContractAction(playerid, list, sizeof(list), 6, line);
    format(line, sizeof(line), "Cancelar trabalho\tMulta $%d", Cfg_Price(gCfgContractCancelFine)); Life_AddContractAction(playerid, list, sizeof(list), 7, line);
    format(line, sizeof(line), "Cancelar seguro\tMulta $%d", Cfg_Price(gCfgContractCancelFine)); Life_AddContractAction(playerid, list, sizeof(list), 8, line);
    ShowPlayerDialog(playerid, DIALOG_LIFE_CONTRACTS, DIALOG_STYLE_TABLIST_HEADERS, "Contratos civis", list, "Selecionar", "Fechar");
    return 1;
}

stock Life_ContractCost(playerid, cost, reason[])
{
    if (!Bank_TakePaymentReason(playerid, Cfg_Price(cost), 0, reason))
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para registrar este contrato.");
        return 0;
    }
    Life_AddGovernmentRevenue(Cfg_Price(cost), reason);
    return 1;
}

stock Life_HandleContractItem(playerid, item)
{
    new message[128];

    switch (item)
    {
        case 0: return Life_ShowContractsDialog(playerid);
        case 1:
        {
            if (PlayerInfo[playerid][pRentedHouse] == HOUSE_NONE) return SendClientMessage(playerid, COLOR_RED, "Voce nao possui aluguel ativo.");
            if (!Life_ContractCost(playerid, gCfgContractRentCost, "contract_rent")) return 1;
            PlayerInfo[playerid][pContractRent] = 1;
            SendClientMessage(playerid, COLOR_GREEN, "Contrato de aluguel registrado em cartorio.");
        }
        case 2:
        {
            if (PlayerInfo[playerid][pBankLoan] <= 0) return SendClientMessage(playerid, COLOR_RED, "Voce nao possui financiamento/emprestimo ativo.");
            if (!Life_ContractCost(playerid, gCfgContractFinanceCost, "contract_finance")) return 1;
            PlayerInfo[playerid][pContractFinancing] = 1;
            SendClientMessage(playerid, COLOR_GREEN, "Contrato de financiamento registrado.");
        }
        case 3:
        {
            if (PlayerInfo[playerid][pJob] == JOB_NONE) return SendClientMessage(playerid, COLOR_RED, "Voce precisa ter emprego para contrato de trabalho.");
            if (!Life_ContractCost(playerid, gCfgContractWorkCost, "contract_work")) return 1;
            PlayerInfo[playerid][pContractWork] = 1;
            SendClientMessage(playerid, COLOR_GREEN, "Contrato de trabalho registrado.");
        }
        case 4:
        {
            if (PlayerInfo[playerid][pVehicleModel] < 400) return SendClientMessage(playerid, COLOR_RED, "Voce precisa ter veiculo para contrato de seguro.");
            if (!Life_ContractCost(playerid, gCfgContractInsuranceCost, "contract_insurance")) return 1;
            PlayerInfo[playerid][pContractInsurance] = 1;
            SendClientMessage(playerid, COLOR_GREEN, "Contrato de seguro registrado.");
        }
        case 5, 6, 7, 8:
        {
            if (!Bank_TakePaymentReason(playerid, Cfg_Price(gCfgContractCancelFine), 0, "contract_cancel")) return SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para multa de cancelamento.");
            if (item == 5) { PlayerInfo[playerid][pContractRent] = 0; PlayerInfo[playerid][pRentedHouse] = HOUSE_NONE; }
            if (item == 6) PlayerInfo[playerid][pContractFinancing] = 0;
            if (item == 7) { PlayerInfo[playerid][pContractWork] = 0; SetPlayerJob(playerid, JOB_NONE); }
            if (item == 8) { PlayerInfo[playerid][pContractInsurance] = 0; PlayerInfo[playerid][pVehicleInsurance] = 0; }
            Life_AddGovernmentRevenue(Cfg_Price(gCfgContractCancelFine), "contract_cancel");
            SendClientMessage(playerid, COLOR_ORANGE, "Contrato cancelado com multa registrada.");
        }
        default: return 1;
    }

    format(message, sizeof(message), "Contratos: aluguel %d | financiamento %d | trabalho %d | seguro %d", PlayerInfo[playerid][pContractRent], PlayerInfo[playerid][pContractFinancing], PlayerInfo[playerid][pContractWork], PlayerInfo[playerid][pContractInsurance]);
    WritePlayerLog(LOG_CONTRACT_FILE, "CONTRACT", playerid, message);
    SaveAccountData(playerid, 0);
    return 1;
}

stock Life_ShowCartorioDialog(playerid)
{
    new list[1200];
    new line[144];

    format(list, sizeof(list), "Servico\tStatus/valor\n");
    format(line, sizeof(line), "Status civil\tCPF %s | RG %s | Certidao %s | Firma %s | Casado %s\n", PlayerInfo[playerid][pCivilCPF] ? ("sim") : ("nao"), PlayerInfo[playerid][pCivilRG] ? ("sim") : ("nao"), PlayerInfo[playerid][pCivilCertificate] ? ("sim") : ("nao"), PlayerInfo[playerid][pCivilSignature] ? ("sim") : ("nao"), PlayerInfo[playerid][pCivilMarried] ? ("sim") : ("nao")); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Emitir CPF\t$%d\n", Cfg_Price(gCfgCartorioCpfCost)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Emitir RG\t$%d\n", Cfg_Price(gCfgCartorioRgCost)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Segunda via certidao\t$%d\n", Cfg_Price(gCfgCartorioCertCost)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Reconhecer firma\t$%d\n", Cfg_Price(gCfgCartorioFirmaCost)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Alterar nome RP\t$%d\n", Cfg_Price(gCfgCityRenameCost)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Contrato compra/venda\t$%d\n", Cfg_Price(gCfgContractFinanceCost)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Transferencia veiculo/imovel\t$%d\n", Cfg_Price(gCfgContractFinanceCost)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Casamento civil\t$%d\n", Cfg_Price(gCfgCartorioFirmaCost)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Divorcio\t$%d | divorcios %d\n", Cfg_Price(gCfgContractCancelFine), PlayerInfo[playerid][pCivilDivorces]); strcat(list, line, sizeof(list));
    ShowPlayerDialog(playerid, DIALOG_LIFE_CARTORIO, DIALOG_STYLE_TABLIST_HEADERS, "Cartorio e documentos civis", list, "Selecionar", "Fechar");
    return 1;
}

stock Life_PayCartorio(playerid, amount, reason[])
{
    if (!Bank_TakePayment(playerid, amount, 0))
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo insuficiente para o servico do cartorio.");
        return 0;
    }
    Life_AddGovernmentRevenue(amount, reason);
    return 1;
}

stock Life_HandleCartorioItem(playerid, item)
{
    switch (item)
    {
        case 0: return Life_ShowCartorioDialog(playerid);
        case 1:
        {
            if (!Life_PayCartorio(playerid, Cfg_Price(gCfgCartorioCpfCost), "cpf")) return 1;
            PlayerInfo[playerid][pCivilCPF] = 1;
            SendClientMessage(playerid, COLOR_GREEN, "CPF emitido no cartorio digital.");
        }
        case 2:
        {
            if (!Life_PayCartorio(playerid, Cfg_Price(gCfgCartorioRgCost), "rg")) return 1;
            PlayerInfo[playerid][pCivilRG] = 1;
            SendClientMessage(playerid, COLOR_GREEN, "RG emitido no cartorio digital.");
        }
        case 3:
        {
            if (!Life_PayCartorio(playerid, Cfg_Price(gCfgCartorioCertCost), "certificate")) return 1;
            PlayerInfo[playerid][pCivilCertificate] = 1;
            SendClientMessage(playerid, COLOR_GREEN, "Certidao civil emitida.");
        }
        case 4:
        {
            if (!Life_PayCartorio(playerid, Cfg_Price(gCfgCartorioFirmaCost), "signature")) return 1;
            PlayerInfo[playerid][pCivilSignature] = 1;
            SendClientMessage(playerid, COLOR_GREEN, "Firma reconhecida para contratos.");
        }
        case 5:
        {
            ShowCityHallRenameDialog(playerid);
            return 1;
        }
        case 6:
        {
            if (!Life_PayCartorio(playerid, Cfg_Price(gCfgContractFinanceCost), "sale_contract")) return 1;
            PlayerInfo[playerid][pCivilSignature] = 1;
            SendClientMessage(playerid, COLOR_GREEN, "Contrato de compra/venda reconhecido.");
        }
        case 7:
        {
            if (!Life_PayCartorio(playerid, Cfg_Price(gCfgContractFinanceCost), "transfer_contract")) return 1;
            SendClientMessage(playerid, COLOR_GREEN, "Transferencia reconhecida. Use os comandos de veiculo/imovel para concluir.");
        }
        case 8:
        {
            if (PlayerInfo[playerid][pCivilMarried]) return SendClientMessage(playerid, COLOR_GRAY, "Voce ja possui casamento civil ativo.");
            if (!Life_PayCartorio(playerid, Cfg_Price(gCfgCartorioFirmaCost), "marriage")) return 1;
            PlayerInfo[playerid][pCivilMarried] = 1;
            SendClientMessage(playerid, COLOR_GREEN, "Casamento civil registrado.");
        }
        case 9:
        {
            if (!PlayerInfo[playerid][pCivilMarried]) return SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui casamento civil ativo.");
            if (!Life_PayCartorio(playerid, Cfg_Price(gCfgContractCancelFine), "divorce")) return 1;
            PlayerInfo[playerid][pCivilMarried] = 0;
            PlayerInfo[playerid][pCivilDivorces]++;
            SendClientMessage(playerid, COLOR_ORANGE, "Divorcio registrado.");
        }
        default: return 1;
    }

    if (item >= 1 && item <= 4)
    {
        Life_AddMissionProgress(playerid, 5, 1);
    }
    Life_CheckAchievements(playerid);
    SaveAccountData(playerid, 0);
    return 1;
}

stock Life_OnPlayerSpawn(playerid)
{
    new protected = Account_ApplyNewcomerProtection(playerid);
    new currentJob = PlayerInfo[playerid][pJob];
    new jobLabel[32];
    new message[144];

    if (currentJob != JOB_NONE && !Job_PlayerMeetsAccessLevel(playerid, currentJob, 0))
    {
        GetJobName(currentJob, jobLabel, sizeof(jobLabel));
        SetPlayerJob(playerid, JOB_NONE, 0);
        format(message, sizeof(message), "%s removido: este emprego exige nivel %d+.", jobLabel, Job_GetAccessLevelRequirement(currentJob));
        SendClientMessage(playerid, COLOR_ORANGE, message);
        SaveAccountData(playerid, 0);
    }
    else if (protected)
    {
        SaveAccountData(playerid, 0);
    }
    Life_ResetDailyLoop(playerid);
    Life_UpdateWarZoneForPlayer(playerid);
    Life_UpdateExpirations(playerid, 1);
    Life_GenerateMonthlyTaxes(playerid);
    Life_GenMonthlyBills(playerid, 1);
    Life_GenSalary(playerid, 1);
    Life_ApplyLateFees(playerid, 1);
    Life_UpdateJusticeCase(playerid, 1);
    Life_WarnBills(playerid);
    Life_GetBankScore(playerid);
    Life_SendFirstJourneyHint(playerid);
    return 1;
}

stock Life_HandlePlayerKill(victimid, killerid, reason)
{
    new message[160];
    new reward;

    if (killerid == INVALID_PLAYER_ID || killerid == victimid || !IsValidConnectedPlayer(killerid) || IsPlayerNPC(killerid) || !PlayerInfo[killerid][pLogged])
    {
        return 0;
    }

    if (!Life_IsPlayerInWarZone(killerid) || !Life_IsPlayerInWarZone(victimid))
    {
        return 0;
    }

    Life_ResetDailyLimits(killerid);
    if (Life_IsWarZoneActive())
    {
        PlayerInfo[killerid][pWarZoneKillsToday]++;
        Life_AddWeeklyScore(killerid, WEEKLY_SCORE_CITIZEN, 1);
        if (PlayerInfo[killerid][pWarZoneKillsToday] <= WAR_ZONE_MAX_REWARD_KILLS)
        {
            reward = Vip_ApplyCashBonus(killerid, WAR_ZONE_REWARD_CASH);
            GivePlayerCashReason(killerid, reward, 0, "war_zone");
            GivePlayerExperience(killerid, 1, 0);
            Life_TrackGain(killerid, reward, 1, "war_zone");
            format(message, sizeof(message), "Zona de guerra: kill valida em Mulholland. Recompensa $%d. Sem prisao.", reward);
            SendClientMessage(killerid, COLOR_GREEN, message);
        }
        else
        {
            SendClientMessage(killerid, COLOR_ORANGE, "Zona de guerra: kill valida, mas limite diario de recompensa atingido.");
        }
        format(message, sizeof(message), "killer=%d victim=%d reason=%d reward=%d kills_today=%d", killerid, victimid, reason, reward, PlayerInfo[killerid][pWarZoneKillsToday]);
        WritePlayerLog(LOG_PUNISH_FILE, "WAR_ZONE_KILL", killerid, message);
        SaveAccountData(killerid, 0);
        return 1;
    }

    if (Account_IsNewcomerProtected(killerid))
    {
        PlayerInfo[killerid][pWanted] = 0;
        format(message, sizeof(message), "Kill em Mulholland fora da zona ativa. Aviso educativo: protecao de recem chegado ate nivel 3.");
        SendClientMessage(killerid, COLOR_YELLOW, message);
    }
    else
    {
        PlayerInfo[killerid][pWanted] += 2;
        if (PlayerInfo[killerid][pWanted] > MAX_WANTED_LEVEL)
        {
            PlayerInfo[killerid][pWanted] = MAX_WANTED_LEVEL;
        }
        Police_ArrestPlayer(killerid, 2, 1800);
        format(message, sizeof(message), "Kill em Mulholland fora da zona ativa. Preso automaticamente. Vitima ID %d.", victimid);
        SendClientMessage(killerid, COLOR_RED, message);
    }
    format(message, sizeof(message), "killer=%d victim=%d reason=%d wanted=%d", killerid, victimid, reason, PlayerInfo[killerid][pWanted]);
    WritePlayerLog(LOG_PUNISH_FILE, "WAR_ZONE_ILLEGAL_KILL", killerid, message);
    return 1;
}

stock Life_OnPlayerDeath(playerid, killerid = INVALID_PLAYER_ID, reason = 0)
{
    PlayerInfo[playerid][pMedicalSeverity] = 1 + random(3);
    if (gCityEventType == CITY_EVENT_HOSPITAL && Life_CityEventActive())
    {
        PlayerInfo[playerid][pMedicalSeverity]++;
    }
    PlayerInfo[playerid][pMedicalTreatmentDue] = 1;
    Life_HandlePlayerKill(playerid, killerid, reason);
    return 1;
}

stock Life_HandleDialog(playerid, dialogid, response, listitem, inputtext[] = "")
{
    if (!IsValidConnectedPlayer(playerid) || IsPlayerNPC(playerid) || !PlayerInfo[playerid][pLogged])
    {
        return 1;
    }

    if (dialogid == DIALOG_ACTIVITY_CENTER) return Life_ShowNextStepDialog(playerid);
    if (dialogid == DIALOG_DAILY_JOURNEY)
    {
        if (!response) return 1;
        return Life_ApplyDailyJourney(playerid);
    }
    if (dialogid == DIALOG_WEEKLY_AGENDA)
    {
        if (!response) return 1;
        return Life_ApplyWeeklyAgenda(playerid);
    }
    if (dialogid == DIALOG_NEIGHBORHOOD_EVENTS)
    {
        if (!response) return 1;
        return Life_ApplyNeighborhoodEvent(playerid);
    }
    if (dialogid == DIALOG_URBAN_PROGRESS)
    {
        if (!response) return 1;
        return Life_ApplyUrbanProgress(playerid);
    }
    if (dialogid == DIALOG_FIRST_JOURNEY) return Life_ShowNextStepDialog(playerid);
    if (dialogid == DIALOG_NEXT_STEP) return Life_ApplyNextStep(playerid);
    if (dialogid == DIALOG_LIFE_DOCS)
    {
        if (!response) return 1;
        return Life_RenewDocumentByItem(playerid, listitem);
    }
    if (dialogid == DIALOG_LIFE_TAXES)
    {
        if (!response) return 1;
        return Life_PayTaxItem(playerid, listitem);
    }
    if (dialogid == DIALOG_LIFE_MARKET)
    {
        if (!response) return 1;
        if (listitem < 0) return 1;
        if (listitem >= LIFE_MARKET_ITEMS) return Life_SellProductsToMarket(playerid);
        SendClientMessage(playerid, COLOR_BLUE, "Use entregador, caminhoneiro, produtor ou tecnico para abastecer estoques.");
        return 1;
    }
    if (dialogid == DIALOG_LIFE_JUSTICE)
    {
        switch (listitem)
        {
            case 0: return Life_ShowJusticeDialog(playerid);
            case 1: return Life_RegisterPoliceReport(playerid);
            case 2: return Life_RequestHearing(playerid);
            case 3: return Life_HireLawyer(playerid);
            case 4: return Life_RunHearing(playerid);
            case 5: return Life_AppealSentence(playerid);
            case 6: return Life_PayTaxItem(playerid, 3);
        }
        return 1;
    }
    if (dialogid == DIALOG_LIFE_HEALTH)
    {
        switch (listitem)
        {
            case 0: return Hospital_SendStatus(playerid);
            case 1: return Life_UseMedicine(playerid);
            case 2: return Life_DoSurgery(playerid);
            case 3: return Life_CallAmbulance(playerid);
            case 4: return Hospital_BuyHealthPlan(playerid);
        }
        return 1;
    }
    if (dialogid == DIALOG_LIFE_BUSINESS)
    {
        if (listitem < 0 || listitem >= gLifeBizActionCount[playerid])
        {
            SendClientMessage(playerid, COLOR_RED, "Opcao de empresa expirou. Abra novamente.");
            return Life_ShowBusinessDialog(playerid);
        }
        return Life_BusinessAction(playerid, gLifeBizActions[playerid][listitem]);
    }
    if (dialogid == DIALOG_LIFE_BILLS)
    {
        if (!response) return 1;
        if (listitem < 0 || listitem >= gLifeBillActionCount[playerid])
        {
            SendClientMessage(playerid, COLOR_RED, "Opcao de boleto expirou. Abra novamente.");
            return Life_ShowBillsDialog(playerid);
        }
        return Life_PayBillItem(playerid, gLifeBillActions[playerid][listitem]);
    }
    if (dialogid == DIALOG_LIFE_CONTRACTS)
    {
        if (listitem < 0 || listitem >= gLifeContractActionCount[playerid])
        {
            SendClientMessage(playerid, COLOR_RED, "Opcao de contrato expirou. Abra novamente.");
            return Life_ShowContractsDialog(playerid);
        }
        return Life_HandleContractItem(playerid, gLifeContractActions[playerid][listitem]);
    }
    if (dialogid == DIALOG_LIFE_AUCTION)
    {
        if (listitem < 0 || listitem >= gLifeAuctionActionCount[playerid])
        {
            SendClientMessage(playerid, COLOR_RED, "Opcao de leilao expirou. Abra novamente.");
            return Life_ShowVehicleAuction(playerid);
        }
        return Life_HandleAuctionItem(playerid, gLifeAuctionActions[playerid][listitem]);
    }
    if (dialogid == DIALOG_PUBLIC_SERVICES)
    {
        if (listitem < 0 || listitem >= gLifePublicActionCount[playerid])
        {
            SendClientMessage(playerid, COLOR_RED, "Opcao de servico publico expirou. Abra novamente.");
            return Life_ShowPublicSvcDialog(playerid);
        }
        return Life_HandlePublicSvcAction(playerid, gLifePublicActions[playerid][listitem]);
    }
    if (dialogid == DIALOG_PUBLIC_CONSTITUTION) return 1;
    if (dialogid == DIALOG_PUBLIC_WORKS) return 1;
    if (dialogid == DIALOG_SERVICE_CALL_CREATE)
    {
        if (!response) return 1;
        switch (listitem)
        {
            case 0: return Life_ServiceCall_Create(playerid, LIFE_CALL_POLICE, "solicitacao civil via celular");
            case 1: return Life_ServiceCall_Create(playerid, LIFE_CALL_SAMU, "emergencia medica via celular");
            case 2: return Life_ServiceCall_Create(playerid, LIFE_CALL_FIRE, "emergencia de incendio/resgate");
            case 3: return Life_ServiceCall_Create(playerid, LIFE_CALL_TOW, "guincho ou apoio mecanico");
        }
        return 1;
    }
    if (dialogid == DIALOG_SERVICE_CALL_LIST) return 1;
    if (dialogid == DIALOG_POLITICS_PANEL) return 1;
    if (dialogid == DIALOG_POLITICAL_MAIN_MENU || dialogid == DIALOG_POLITICAL_CANDIDATE_OFFICE || dialogid == DIALOG_POLITICAL_ADMIN_MENU) return Life_HandlePoliticalMainDialog(playerid, dialogid, response, listitem);
    if (dialogid == DIALOG_POLITICAL_DUTY_PANEL)
    {
        if (!response) return 1;
        switch (listitem)
        {
            case 0: return Life_ShowPoliticsPanel(playerid);
            case 1: return Life_ShowPoliticalActionMenu(playerid);
            case 2: return Life_ShowPoliticalDutyPanel(playerid);
            case 3: return Life_ShowPoliticalWorkSelect(playerid);
            case 4: return Life_ShowPoliticalBudgetInput(playerid);
            case 5: return Life_ShowPoliticalQuickReason(playerid, LIFE_POL_ACTION_AUDIT);
            case 6: return Life_ShowPoliticalQuickReason(playerid, LIFE_POL_ACTION_ACCOUNT);
            case 7: return Life_ShowPoliticalQuickReason(playerid, LIFE_POL_ACTION_CPI);
            case 8: return Life_ShowPolProposalVoteList(playerid, 0);
            case 9: return Life_ShowTransparencyCenter(playerid);
            case 10:
            {
                if (HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
                {
                    return Life_ShowPolProposalVoteList(playerid, 1);
                }
                return Life_ShowPoliticalMainMenu(playerid);
            }
            case 11: return Life_ShowPoliticalMainMenu(playerid);
        }
        return Life_ShowPoliticalMainMenu(playerid);
    }
    if (dialogid == DIALOG_POLITICAL_VOTE_OFFICE || dialogid == DIALOG_POLITICAL_VOTE_CANDIDATE) return Life_HandlePoliticalVoteDialog(playerid, dialogid, response, listitem);
    if (dialogid == DIALOG_POLITICAL_ACTION_MENU || dialogid == DIALOG_POLITICAL_WORK_SELECT || dialogid == DIALOG_POLITICAL_BUDGET_INPUT || dialogid == DIALOG_POLITICAL_QUICK_REASON || dialogid == DIALOG_POLITICAL_PROPOSAL_VOTE) return Life_HandlePolActionDialog(playerid, dialogid, response, listitem, inputtext);
    if (dialogid == DIALOG_CITYHALL_PANEL) return 1;
    if (dialogid == DIALOG_LIFE_CARTORIO)
    {
        if (!response) return 1;
        return Life_HandleCartorioItem(playerid, listitem);
    }
    if (dialogid == DIALOG_LIFE_ECONOMY) return 1;
    if (dialogid == DIALOG_TRANSPARENCY_CENTER) return 1;
    if (dialogid == DIALOG_LOGISTICS_PANEL)
    {
        if (response)
        {
            if (!Life_LogisticsSetCheckpoint(playerid))
            {
                Life_ShowLogisticsPanel(playerid);
            }
        }
        return 1;
    }
    return 0;
}

stock Life_SentencePlayer(playerid, targetid, amount)
{
    new message[144];
    new finalAmount;

    if (PlayerInfo[playerid][pJob] != JOB_JUIZ && !HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas juiz ou staff pode sentenciar.");
        return 1;
    }
    if (amount < 0)
    {
        amount = 0;
    }
    if (Account_IsNewcomerProtected(targetid))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Recem chegado protegido: sentenca financeira bloqueada ate o nivel 3.");
        SendClientMessage(targetid, COLOR_YELLOW, "Aviso educativo: sentencas liberam a partir do nivel 3.");
        return 1;
    }
    if (PlayerInfo[targetid][pJusticeActiveEvidence] <= 0 && PlayerInfo[targetid][pJusticeActiveWarrants] <= 0 && !HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
    {
        SendClientMessage(playerid, COLOR_RED, "Sentenca bloqueada: caso sem prova ou mandado ativo. Use /prova ou /mandado antes.");
        return 1;
    }

    finalAmount = amount
        + (PlayerInfo[targetid][pJusticeActiveEvidence] * 250)
        + (PlayerInfo[targetid][pJusticeActiveWarrants] * 300);
    PlayerInfo[targetid][pJusticeFineDue] += Cfg_Fine(finalAmount);
    PlayerInfo[targetid][pJusticeCases]++;
    PlayerInfo[targetid][pWanted] = 0;
    PlayerInfo[targetid][pJusticeStatus] = JUSTICE_STATUS_RESOLVED;
    PlayerInfo[targetid][pJusticeDeadlineDay] = 0;
    PlayerInfo[targetid][pJusticeActiveEvidence] = 0;
    PlayerInfo[targetid][pJusticeActiveWarrants] = 0;
    PlayerInfo[targetid][pBankBadHistory]++;
    Life_GetBankScore(targetid);
    SaveAccountData(targetid, 0);
    format(message, sizeof(message), "Sentenca aplicada ao ID %d: $%d.", targetid, Cfg_Fine(finalAmount));
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(message, sizeof(message), "Voce recebeu sentenca judicial de $%d.", Cfg_Fine(finalAmount));
    SendClientMessage(targetid, COLOR_ORANGE, message);
    WritePlayerLog(LOG_PUNISH_FILE, "JUSTICE_SENTENCE", targetid, message);
    WritePlayerLog(JUSTICE_CASES_FILE, "SENTENCE", targetid, message);
    return 1;
}

stock Life_ArchiveJusticeCase(playerid, targetid, reason[])
{
    new message[160];

    if (!IsLawEnforcementJob(PlayerInfo[playerid][pJob]) && PlayerInfo[playerid][pJob] != JOB_JUIZ && !HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas policia, juiz ou staff pode arquivar caso.");
        return 1;
    }
    if (!IsValidConnectedPlayer(targetid) || !PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido.");
        return 1;
    }
    if (PlayerInfo[targetid][pJusticeCases] <= 0 && PlayerInfo[targetid][pJusticeActiveEvidence] <= 0 && PlayerInfo[targetid][pJusticeActiveWarrants] <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Esse jogador nao possui caso ativo para arquivar.");
        return 1;
    }

    PlayerInfo[targetid][pJusticeStatus] = JUSTICE_STATUS_RESOLVED;
    PlayerInfo[targetid][pJusticeDeadlineDay] = 0;
    PlayerInfo[targetid][pJusticeHearingDay] = 0;
    PlayerInfo[targetid][pJusticeActiveEvidence] = 0;
    PlayerInfo[targetid][pJusticeActiveWarrants] = 0;
    SaveAccountData(targetid, 0);
    format(message, sizeof(message), "Caso do ID %d arquivado. Motivo: %s", targetid, reason);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(targetid, COLOR_GREEN, "Seu caso judicial foi arquivado.");
    WritePlayerLog(JUSTICE_CASES_FILE, "ARCHIVE", playerid, message);
    return 1;
}

stock Life_HandleCommands(playerid, cmdtext[])
{
    new command[32];
    new param[32];
    new param2[32];
    new param3[32];
    new param4[64];
    new message[160];
    new index;
    new targetid;

    index = GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/documentos", true) == 0 || strcmp(command, "/docs", true) == 0)
    {
        Life_ShowDocumentsDialog(playerid);
        return 1;
    }
    if (strcmp(command, "/missoes", true) == 0 || strcmp(command, "/missao", true) == 0 || strcmp(command, "/diarias", true) == 0)
    {
        Life_ShowMissions(playerid);
        return 1;
    }
    if (strcmp(command, "/atividades", true) == 0 || strcmp(command, "/central", true) == 0 || strcmp(command, "/govbr", true) == 0)
    {
        Life_ShowActivityCenter(playerid);
        return 1;
    }
    if (strcmp(command, "/jornadadiaria", true) == 0 || strcmp(command, "/rotinadiaria", true) == 0 || strcmp(command, "/dia", true) == 0)
    {
        Life_ShowDailyJourney(playerid);
        return 1;
    }
    if (strcmp(command, "/agendasemanal", true) == 0 || strcmp(command, "/metassemanais", true) == 0 || strcmp(command, "/semanal", true) == 0)
    {
        Life_ShowWeeklyAgenda(playerid);
        return 1;
    }
    if (strcmp(command, "/bairros", true) == 0 || strcmp(command, "/eventosbairro", true) == 0 || strcmp(command, "/metabairro", true) == 0)
    {
        Life_ShowNeighborhoodEvents(playerid);
        return 1;
    }
    if (strcmp(command, "/progressourbano", true) == 0 || strcmp(command, "/reputacaourbana", true) == 0 || strcmp(command, "/urbano", true) == 0)
    {
        Life_ShowUrbanProgress(playerid);
        return 1;
    }
    if (strcmp(command, "/centralchamados", true) == 0 || strcmp(command, "/chamados", true) == 0 || strcmp(command, "/emergencia", true) == 0)
    {
        Life_ServiceCall_ShowList(playerid);
        return 1;
    }
    if (strcmp(command, "/abrirchamado", true) == 0 || strcmp(command, "/chamarservico", true) == 0)
    {
        Life_ServiceCall_ShowCreate(playerid);
        return 1;
    }
    if (strcmp(command, "/190", true) == 0 || strcmp(command, "/policia190", true) == 0)
    {
        if (!GetRemainingText(cmdtext, index, param4, sizeof(param4))) format(param4, sizeof(param4), "solicitacao policial");
        return Life_ServiceCall_Create(playerid, LIFE_CALL_POLICE, param4);
    }
    if (strcmp(command, "/192", true) == 0 || strcmp(command, "/samu192", true) == 0)
    {
        if (!GetRemainingText(cmdtext, index, param4, sizeof(param4))) format(param4, sizeof(param4), "emergencia medica");
        return Life_ServiceCall_Create(playerid, LIFE_CALL_SAMU, param4);
    }
    if (strcmp(command, "/193", true) == 0 || strcmp(command, "/bombeiro193", true) == 0)
    {
        if (!GetRemainingText(cmdtext, index, param4, sizeof(param4))) format(param4, sizeof(param4), "incendio ou resgate");
        return Life_ServiceCall_Create(playerid, LIFE_CALL_FIRE, param4);
    }
    if (strcmp(command, "/aceitarchamado", true) == 0 || strcmp(command, "/atenderchamado", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/aceitarchamado [id]");
        }
        return Life_ServiceCall_Accept(playerid, strval(param));
    }
    if (strcmp(command, "/cancelarchamado", true) == 0 || strcmp(command, "/devolverchamado", true) == 0)
    {
        return Life_ServiceCall_Cancel(playerid);
    }
    if (strcmp(command, "/jornada", true) == 0 || strcmp(command, "/primeirajornada", true) == 0)
    {
        Life_ShowFirstJourneyDialog(playerid);
        return 1;
    }
    if (strcmp(command, "/proximopasso", true) == 0 || strcmp(command, "/proximo", true) == 0)
    {
        Life_ShowNextStepDialog(playerid);
        return 1;
    }
    if (strcmp(command, "/eventos", true) == 0 || strcmp(command, "/eventocidade", true) == 0)
    {
        Life_ShowCityEvents(playerid);
        return 1;
    }
    if (strcmp(command, "/zonaguerra", true) == 0 || strcmp(command, "/zonavermelha", true) == 0 || strcmp(command, "/warzone", true) == 0)
    {
        new warText[128];
        new body[420];
        Life_UpdateWarZoneForPlayer(playerid);
        Life_FormatWarZoneStatus(warText, sizeof(warText));
        format(body, sizeof(body), "Bairro: Mulholland, Los Santos.\nArea: colina ao norte da cidade, marcada em vermelho quando ativa.\nHorario: %02d:00 e %02d:00 BRT, por %d minutos.\nStatus: %s\n\nDurante a janela ativa, kill dentro da area nao prende. Fora dela, kill no local gera prisao.", WAR_ZONE_START_A, WAR_ZONE_START_B, WAR_ZONE_DURATION_MIN, warText);
        ShowPlayerDialog(playerid, DIALOG_WAR_ZONE, DIALOG_STYLE_MSGBOX, "Zona de guerra", body, "Fechar", "");
        return 1;
    }
    if (strcmp(command, "/noticias", true) == 0 || strcmp(command, "/jornal", true) == 0)
    {
        Life_ShowCityNews(playerid);
        return 1;
    }
    if (strcmp(command, "/notificacoes", true) == 0 || strcmp(command, "/avisosgov", true) == 0)
    {
        Life_SendGovNotifications(playerid);
        return 1;
    }
    if (strcmp(command, "/passe", true) == 0 || strcmp(command, "/passacidade", true) == 0)
    {
        Life_ShowCityPass(playerid);
        return 1;
    }
    if (strcmp(command, "/rankingsemanal", true) == 0 || strcmp(command, "/rankings", true) == 0)
    {
        Life_ShowWeeklyRanking(playerid);
        return 1;
    }
    if (strcmp(command, "/historico", true) == 0 || strcmp(command, "/conquistas", true) == 0 || strcmp(command, "/titulos", true) == 0)
    {
        Life_ShowPersonalHistory(playerid);
        return 1;
    }
    if (strcmp(command, "/objetivos", true) == 0 || strcmp(command, "/tutorialobjetivos", true) == 0)
    {
        Life_ShowTutorialObjectives(playerid);
        return 1;
    }
    if (strcmp(command, "/score", true) == 0 || strcmp(command, "/scorebanco", true) == 0)
    {
        Life_ShowBankScore(playerid);
        return 1;
    }
    if (strcmp(command, "/cidadao", true) == 0 || strcmp(command, "/reputacao", true) == 0 || strcmp(command, "/scorecidadao", true) == 0)
    {
        Life_ShowCitizenStatus(playerid);
        return 1;
    }
    if (strcmp(command, "/mercado", true) == 0 || strcmp(command, "/estoque", true) == 0)
    {
        Life_ShowMarketDialog(playerid);
        return 1;
    }
    if (strcmp(command, "/economiacidade", true) == 0 || strcmp(command, "/economiaempresas", true) == 0 || strcmp(command, "/economia2", true) == 0)
    {
        Life_ShowBusinessEconomyDialog(playerid);
        return 1;
    }
    if (strcmp(command, "/empresasauto", true) == 0 || strcmp(command, "/empresasautomaticas", true) == 0)
    {
        Life_ShowAutoBusinesses(playerid);
        return 1;
    }
    if (strcmp(command, "/comprarempresaauto", true) == 0 || strcmp(command, "/comprarempresa", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/comprarempresaauto [id]");
        }
        Life_BuyAutoBusiness(playerid, strval(param));
        return 1;
    }
    if (strcmp(command, "/minhaempresaauto", true) == 0)
    {
        Life_ShowMyAutoBusiness(playerid);
        return 1;
    }
    if (strcmp(command, "/minhaempresa", true) == 0)
    {
        Life_ShowMyBusinessPanel(playerid);
        return 1;
    }
    if (strcmp(command, "/resgatarlucro", true) == 0 || strcmp(command, "/lucroempresa", true) == 0)
    {
        Life_ClaimAutoBusinessProfit(playerid);
        return 1;
    }
    if (strcmp(command, "/cargaslogisticas", true) == 0 || strcmp(command, "/fretes", true) == 0 || strcmp(command, "/logistica", true) == 0)
    {
        Life_ShowLogisticsPanel(playerid);
        return 1;
    }
    if (strcmp(command, "/rankinglogistica", true) == 0 || strcmp(command, "/rankingfretes", true) == 0 || strcmp(command, "/topfretes", true) == 0)
    {
        Life_ShowLogisticsRanking(playerid);
        return 1;
    }
    if (strcmp(command, "/cargaatual", true) == 0 || strcmp(command, "/meufrete", true) == 0)
    {
        Life_LogisticsCommandStatus(playerid);
        return 1;
    }
    if (strcmp(command, "/carregarcarga", true) == 0 || strcmp(command, "/carregarfrete", true) == 0)
    {
        Life_LoadLogisticsCargo(playerid);
        return 1;
    }
    if (strcmp(command, "/descarregarcarga", true) == 0 || strcmp(command, "/descarregarfrete", true) == 0)
    {
        Life_CompleteLogisticsDelivery(playerid);
        return 1;
    }
    if (strcmp(command, "/cancelarcarga", true) == 0 || strcmp(command, "/cancelarfrete", true) == 0)
    {
        Life_CancelLogisticsContract(playerid, "player_command");
        SendClientMessage(playerid, COLOR_ORANGE, "Carga logistica cancelada.");
        return 1;
    }
    if (strcmp(command, "/venderproduto", true) == 0 || strcmp(command, "/abastecermercado", true) == 0)
    {
        Life_SellProductsToMarket(playerid);
        return 1;
    }
    if (strcmp(command, "/justica", true) == 0 || strcmp(command, "/forum", true) == 0)
    {
        Life_ShowJusticeDialog(playerid);
        return 1;
    }
    if (strcmp(command, "/boletim", true) == 0 || strcmp(command, "/bo", true) == 0)
    {
        if (!GetRemainingText(cmdtext, index, param4, sizeof(param4)))
        {
            format(param4, sizeof(param4), "BO registrado pelo cidadao");
        }
        Life_RegisterPoliceReportEx(playerid, param4);
        return 1;
    }
    if (strcmp(command, "/casos", true) == 0 || strcmp(command, "/investigacoes", true) == 0)
    {
        Life_ShowCases(playerid);
        return 1;
    }
    if (strcmp(command, "/audiencia", true) == 0)
    {
        Life_RequestHearing(playerid);
        return 1;
    }
    if (strcmp(command, "/advogado", true) == 0)
    {
        Life_HireLawyer(playerid);
        return 1;
    }
    if (strcmp(command, "/sentenciar", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)))
        {
            return SendUsage(playerid, "/sentenciar [id] [valor]");
        }
        if (!ParseTargetPlayer(playerid, param, targetid) || !IsNumericString(param2))
        {
            return 1;
        }
        Life_SentencePlayer(playerid, targetid, strval(param2));
        return 1;
    }
    if (strcmp(command, "/mandado", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/mandado [id] [motivo]");
        }
        if (!GetRemainingText(cmdtext, index, param4, sizeof(param4)))
        {
            format(param4, sizeof(param4), "mandado operacional");
        }
        Life_PoliceCreateWarrantEx(playerid, targetid, param4);
        return 1;
    }
    if (strcmp(command, "/prova", true) == 0 || strcmp(command, "/pericia", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/prova [id] [descricao]");
        }
        if (!GetRemainingText(cmdtext, index, param4, sizeof(param4)))
        {
            format(param4, sizeof(param4), "prova/pericia operacional");
        }
        Life_PoliceCollectEvidenceEx(playerid, targetid, param4);
        return 1;
    }
    if (strcmp(command, "/arquivarcaso", true) == 0 || strcmp(command, "/arquivarbo", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/arquivarcaso [id] [motivo]");
        }
        if (!GetRemainingText(cmdtext, index, param4, sizeof(param4)))
        {
            format(param4, sizeof(param4), "sem motivo informado");
        }
        Life_ArchiveJusticeCase(playerid, targetid, param4);
        return 1;
    }
    if (strcmp(command, "/tornozeleira", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/tornozeleira [id]");
        }
        Life_SetAnkleMonitor(playerid, targetid);
        return 1;
    }
    if (strcmp(command, "/prontuario", true) == 0 || strcmp(command, "/saudereal", true) == 0)
    {
        Life_ShowHealthDialog(playerid);
        return 1;
    }
    if (strcmp(command, "/remedio", true) == 0)
    {
        Life_UseMedicine(playerid);
        return 1;
    }
    if (strcmp(command, "/cirurgia", true) == 0)
    {
        Life_DoSurgery(playerid);
        return 1;
    }
    if (strcmp(command, "/ambulancia", true) == 0)
    {
        Life_CallAmbulance(playerid);
        return 1;
    }
    if (strcmp(command, "/plantaomedico", true) == 0 || strcmp(command, "/plantaosamu", true) == 0)
    {
        Life_MedicalShift(playerid);
        return 1;
    }
    if (strcmp(command, "/internacao", true) == 0 || strcmp(command, "/internar", true) == 0)
    {
        Life_HospitalIntern(playerid);
        return 1;
    }
    if (strcmp(command, "/empresa", true) == 0 || strcmp(command, "/cnpj", true) == 0)
    {
        Life_ShowBusinessDialog(playerid);
        return 1;
    }
    if (strcmp(command, "/abrirempresalocal", true) == 0 || strcmp(command, "/abrircnpjlocal", true) == 0)
    {
        Life_OpenEditorBusiness(playerid);
        return 1;
    }
    if (strcmp(command, "/enderecoempresa", true) == 0 || strcmp(command, "/localempresa", true) == 0)
    {
        new address[40];
        Life_GetBusinessAddress(playerid, address, sizeof(address));
        format(message, sizeof(message), "Endereco da empresa: %s.", address);
        SendClientMessage(playerid, COLOR_YELLOW, message);
        return 1;
    }
    if (strcmp(command, "/fechamentoempresa", true) == 0 || strcmp(command, "/contaempresa", true) == 0)
    {
        Life_GenBizOpBill(playerid);
        return 1;
    }
    if (strcmp(command, "/pagarcontaempresa", true) == 0 || strcmp(command, "/pagarempresa", true) == 0)
    {
        Life_PayBusinessOperatingBill(playerid);
        return 1;
    }
    if (strcmp(command, "/relatorioempresa", true) == 0 || strcmp(command, "/auditoriaempresa", true) == 0)
    {
        Life_ShowBusinessDeepReport(playerid);
        return 1;
    }
    if (strcmp(command, "/contratarempresa", true) == 0 || strcmp(command, "/contratarplayer", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)))
        {
            return SendUsage(playerid, "/contratarempresa [id] [valor]");
        }
        if (!ParseTargetPlayer(playerid, param, targetid) || !IsNumericString(param2))
        {
            return 1;
        }
        Life_OfferBusinessContract(playerid, targetid, strval(param2));
        return 1;
    }
    if (strcmp(command, "/creditoempresa", true) == 0 || strcmp(command, "/emprestimoempresa", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/creditoempresa [valor]");
        }
        Life_RequestBusinessCredit(playerid, strval(param));
        return 1;
    }
    if (strcmp(command, "/fiscalizarempresa", true) == 0 || strcmp(command, "/fiscalizarcnpj", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/fiscalizarempresa [id]");
        }
        Life_FiscalizeBusiness(playerid, targetid);
        return 1;
    }
    if (strcmp(command, "/regularizarempresa", true) == 0 || strcmp(command, "/contabilidade", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            targetid = playerid;
        }
        else if (!ParseTargetPlayer(playerid, param, targetid))
        {
            return SendUsage(playerid, "/regularizarempresa [id opcional]");
        }
        Life_RegularizeBizAccounting(playerid, targetid);
        return 1;
    }
    if (strcmp(command, "/gerarcarga", true) == 0 || strcmp(command, "/contratarfrete", true) == 0 || strcmp(command, "/pedidologistico", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)) || !GetNextParam(cmdtext, index, param3, sizeof(param3)))
        {
            return SendUsage(playerid, "/gerarcarga [id caminhoneiro] [mercado/posto/oficina/obra] [valor]");
        }
        if (!ParseTargetPlayer(playerid, param, targetid) || !IsNumericString(param3))
        {
            return 1;
        }
        Life_OfferLogisticsContract(playerid, targetid, Life_GetLogisticsTypeFromText(param2), strval(param3));
        return 1;
    }
    if (strcmp(command, "/aceitarcontrato", true) == 0)
    {
        Life_AcceptBusinessContract(playerid);
        return 1;
    }
    if (strcmp(command, "/aceitarcarga", true) == 0 || strcmp(command, "/aceitarfrete", true) == 0)
    {
        Life_AcceptLogisticsContract(playerid);
        return 1;
    }
    if (strcmp(command, "/recuperarempresa", true) == 0)
    {
        Life_BusinessAction(playerid, 11);
        return 1;
    }
    if (strcmp(command, "/falencia", true) == 0)
    {
        Life_BusinessAction(playerid, 12);
        return 1;
    }
    if (strcmp(command, "/rankingempresas", true) == 0 || strcmp(command, "/topempresas", true) == 0)
    {
        Life_ShowBusinessRanking(playerid);
        return 1;
    }
    if (strcmp(command, "/servicospublicos", true) == 0 || strcmp(command, "/servicos", true) == 0 || strcmp(command, "/publicos", true) == 0)
    {
        Life_ShowPublicSvcDialog(playerid);
        return 1;
    }
    if (strcmp(command, "/obraspublicas", true) == 0 || strcmp(command, "/obras", true) == 0 || strcmp(command, "/obrasgov", true) == 0)
    {
        Life_ShowPublicWorks(playerid);
        return 1;
    }
    if (strcmp(command, "/energia", true) == 0 || strcmp(command, "/aguaeluz", true) == 0 || strcmp(command, "/luz", true) == 0)
    {
        Life_ShowEnergyDialog(playerid);
        return 1;
    }
    if (strcmp(command, "/instalarsolar", true) == 0 || strcmp(command, "/energiasolar", true) == 0 || strcmp(command, "/painelsolar", true) == 0)
    {
        Life_InstallHomeSolar(playerid);
        return 1;
    }
    if (strcmp(command, "/financiarobra", true) == 0 || strcmp(command, "/financiamentoobra", true) == 0 || strcmp(command, "/concluirobra", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/financiarobra [id]");
        }
        Life_FundPublicWork(playerid, strval(param));
        return 1;
    }
    if (strcmp(command, "/missaopublica", true) == 0 || strcmp(command, "/missaoPublica", true) == 0 || strcmp(command, "/ocorrencia", true) == 0 || strcmp(command, "/chamado", true) == 0 || strcmp(command, "/fogo", true) == 0)
    {
        Life_PublicMission_Start(playerid);
        return 1;
    }
    if (strcmp(command, "/cancelarmissaopublica", true) == 0 || strcmp(command, "/cancelarocorrencia", true) == 0)
    {
        Life_PublicMission_Cancel(playerid);
        return 1;
    }
    if (strcmp(command, "/constituicao", true) == 0 || strcmp(command, "/constituicaofederal", true) == 0 || strcmp(command, "/leis", true) == 0)
    {
        Life_ShowConstitutionDialog(playerid);
        return 1;
    }
    if (strcmp(command, "/impostos", true) == 0 || strcmp(command, "/taxas", true) == 0)
    {
        Life_ShowTaxesDialog(playerid);
        return 1;
    }
    if (strcmp(command, "/prefeitura", true) == 0 || strcmp(command, "/painelprefeitura", true) == 0 || strcmp(command, "/orcamento", true) == 0)
    {
        Life_ShowCityHallPanel(playerid);
        return 1;
    }
    if (strcmp(command, "/politica", true) == 0)
    {
        Life_ShowPoliticalMainMenu(playerid);
        return 1;
    }
    if (strcmp(command, "/painelpolitico", true) == 0 || strcmp(command, "/painelpolitica", true) == 0 || strcmp(command, "/governopainel", true) == 0 || strcmp(command, "/propostaspoliticas", true) == 0 || strcmp(command, "/pref", true) == 0 || strcmp(command, "/meucargo", true) == 0 || strcmp(command, "/cargopolitico", true) == 0 || strcmp(command, "/mandato", true) == 0 || strcmp(command, "/governo", true) == 0 || strcmp(command, "/governar", true) == 0)
    {
        Life_ShowPoliticalDutyPanel(playerid);
        return 1;
    }
    if (strcmp(command, "/propostapolitica", true) == 0 || strcmp(command, "/criarproposta", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)))
        {
            return SendUsage(playerid, "/propostapolitica [obra/orcamento/fiscalizar/contas/cpi] [valor/id] [categoria] [motivo]");
        }
        if (!GetNextParam(cmdtext, index, param3, sizeof(param3)))
        {
            format(param3, sizeof(param3), "admin");
        }
        if (!GetNextParam(cmdtext, index, param4, sizeof(param4)))
        {
            format(param4, sizeof(param4), "%s", param3);
        }
        Life_CreatePoliticalProposal(playerid, Life_ParsePoliticalProposalType(param), strval(param2), Life_ParseGovExpenseCategory(param3), param4);
        return 1;
    }
    if (strcmp(command, "/votarproposta", true) == 0 || strcmp(command, "/aprovarproposta", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/votarproposta [id]");
        }
        Life_VotePoliticalProposal(playerid, strval(param));
        return 1;
    }
    if (strcmp(command, "/cancelarproposta", true) == 0 || strcmp(command, "/reprovarproposta", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/cancelarproposta [id]");
        }
        Life_CancelPoliticalProposal(playerid, strval(param));
        return 1;
    }
    if (strcmp(command, "/candidatar", true) == 0 || strcmp(command, "/candidatura", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/candidatar [cargo/id]");
        }
        Life_AddPoliticalCandidate(playerid, Life_ParsePoliticalOffice(param));
        return 1;
    }
    if (strcmp(command, "/votar", true) == 0 || strcmp(command, "/votareleicao", true) == 0 || strcmp(command, "/votacao", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            Life_ShowPoliticalVoteOffices(playerid);
            return 1;
        }
        if (!GetNextParam(cmdtext, index, param2, sizeof(param2)) || !IsNumericString(param2))
        {
            return SendUsage(playerid, "/votar [cargo/id] [candidato/id]");
        }
        Life_VotePoliticalCandidate(playerid, Life_ParsePoliticalOffice(param), strval(param2) - 1);
        return 1;
    }
    if (strcmp(command, "/apurareleicao", true) == 0 || strcmp(command, "/fechareleicao", true) == 0)
    {
        Life_ClosePoliticalElection(playerid);
        return 1;
    }
    if (strcmp(command, "/admeleicao", true) == 0 || strcmp(command, "/gerireleicao", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/admeleicao [abrir/fechar/limpar/status]");
        }
        Life_AdminElectionCommand(playerid, param);
        return 1;
    }
    if (strcmp(command, "/abrireleicao", true) == 0)
    {
        Life_AdminOpenPoliticalElection(playerid);
        return 1;
    }
    if (strcmp(command, "/fechareleicaoadm", true) == 0 || strcmp(command, "/apurareleicaoadm", true) == 0)
    {
        Life_AdminCloseElection(playerid);
        return 1;
    }
    if (strcmp(command, "/limparpolitica", true) == 0 || strcmp(command, "/limparcargospoliticos", true) == 0)
    {
        Life_AdminClearPoliticalOffices(playerid);
        return 1;
    }
    if (strcmp(command, "/prioridade", true) == 0 || strcmp(command, "/prioridadeorcamento", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/prioridade [infra/saude/seguranca/social]");
        }
        Life_SetBudgetPriority(playerid, Life_ParseBudgetPriority(param));
        return 1;
    }
    if (strcmp(command, "/transparencia", true) == 0 || strcmp(command, "/centraltransparencia", true) == 0 || strcmp(command, "/cofrepublico", true) == 0 || strcmp(command, "/cofregov", true) == 0)
    {
        Life_ShowTransparencyCenter(playerid);
        return 1;
    }
    if (strcmp(command, "/addcofre", true) == 0 || strcmp(command, "/darcofre", true) == 0 || strcmp(command, "/adicionarcofre", true) == 0 || strcmp(command, "/addcofrepublico", true) == 0)
    {
        new reason[64];

        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/addcofre [valor] [motivo]");
        }
        if (!GetRemainingText(cmdtext, index, reason, sizeof(reason)))
        {
            format(reason, sizeof(reason), "admin_add_cofre");
        }
        Life_AdminAddGovernmentRevenue(playerid, strval(param), reason);
        return 1;
    }
    if (strcmp(command, "/gastopublico", true) == 0 || strcmp(command, "/pagarprefeitura", true) == 0)
    {
        new categoryText[24];
        new reason[64];
        new category;

        if (Life_GetPlayerPoliticalOffice(playerid) != -1 && !HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
        {
            Life_MarkPoliticalCorruption(playerid, "tentativa_de_gasto_publico_direto", 0);
            SendClientMessage(playerid, COLOR_RED, "Politico eleito nao pode executar gasto direto. Use /propostapolitica.");
            return 1;
        }
        if (PlayerInfo[playerid][pJob] != JOB_JUIZ && !HasAdminLevel(playerid, ADMIN_LEVEL_GAME))
        {
            return SendNoPermission(playerid);
        }
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, categoryText, sizeof(categoryText)))
        {
            return SendUsage(playerid, "/gastopublico [valor] [infra/saude/seguranca/social/admin/reserva] [motivo]");
        }
        if (!IsNumericString(param))
        {
            return SendUsage(playerid, "/gastopublico [valor] [categoria] [motivo]");
        }
        category = Life_ParseGovExpenseCategory(categoryText);
        if (category == -1)
        {
            return SendUsage(playerid, "/gastopublico [valor] [infra/saude/seguranca/social/admin/reserva] [motivo]");
        }
        if (!GetNextParam(cmdtext, index, reason, sizeof(reason)))
        {
            format(reason, sizeof(reason), "gasto_publico");
        }
        Life_AddGovernmentExpense(playerid, strval(param), category, reason);
        return 1;
    }
    if (strcmp(command, "/licitacao", true) == 0)
    {
        Life_PublicBid(playerid);
        return 1;
    }
    if (strcmp(command, "/vistoria", true) == 0)
    {
        Life_RunVehicleInspection(playerid);
        return 1;
    }
    if (strcmp(command, "/leilaoveiculo", true) == 0 || strcmp(command, "/leilao", true) == 0)
    {
        Life_ShowVehicleAuction(playerid);
        return 1;
    }
    if (strcmp(command, "/pagarimpostos", true) == 0)
    {
        Life_PayTaxItem(playerid, 4);
        return 1;
    }
    if (strcmp(command, "/boletos", true) == 0 || strcmp(command, "/boleto", true) == 0 || strcmp(command, "/contas", true) == 0 || strcmp(command, "/spc", true) == 0 || strcmp(command, "/serasa", true) == 0)
    {
        Life_ShowBillsDialog(playerid);
        return 1;
    }
    if (strcmp(command, "/limparnome", true) == 0)
    {
        Life_PayBillItem(playerid, 12);
        return 1;
    }
    if (strcmp(command, "/contratos", true) == 0 || strcmp(command, "/contrato", true) == 0 || strcmp(command, "/financiamento", true) == 0 || strcmp(command, "/finaciamento", true) == 0)
    {
        Life_ShowContractsDialog(playerid);
        return 1;
    }
    if (strcmp(command, "/cartorio", true) == 0 || strcmp(command, "/cpf", true) == 0 || strcmp(command, "/rg", true) == 0)
    {
        Life_ShowCartorioDialog(playerid);
        return 1;
    }
    return 0;
}
