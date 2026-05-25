#if defined _nova_utils_included
    #endinput
#endif
#define _nova_utils_included

#define GM_TEXT                     "LS RPG 1.5.0"
#define GM_NAME                     "Life Simulator BR"
#define GM_VERSION                  "v1.5.0 Stable"
#define GM_RELEASE_AMX              "nova_gm_1003.amx"
#define GM_DEPLOY_DATE              "2026-05-24 BRT"

#define SERVER_INFO_FILE            "server_info.txt"
#define GAME_CONFIG_FILE            "game_config.txt"
#define CHANGELOG_FILE              "changelog.txt"
#define SERVER_NAME_SIZE            (64)
#define SERVER_VERSION_SIZE         (40)
#define SERVER_MODE_SIZE            (64)
#define SERVER_LANGUAGE_SIZE        (32)

new gServerName[SERVER_NAME_SIZE] = GM_NAME;
new gServerVersion[SERVER_VERSION_SIZE] = GM_VERSION;
new gServerModeText[SERVER_MODE_SIZE] = GM_TEXT;
new gServerLanguage[SERVER_LANGUAGE_SIZE] = "Portuguese";

#define COLOR_WHITE                 0xFFFFFFFF
#define COLOR_GREEN                 0x66CC66FF
#define COLOR_BLUE                  0x80BFFFFFFF
#define COLOR_YELLOW                0xF1C40FFF
#define COLOR_RED                   0xE74C3CFF
#define COLOR_GRAY                  0xAAAAAAFF
#define COLOR_ORANGE                0xF39C12FF
#define COLOR_ADMIN                 0xFF5555FF
#define COLOR_GLOBAL                0x80BFFFFFFF
#define COLOR_LOCAL                 0xDDDDDDFF

#define MAP_ICON_VISIBLE_RANGE      (600.0)
#define PLAYER_MAP_ICON_SLOTS       (100)
#define MAP_ICON_NS_WORLD           (1)
#define MAP_ICON_NS_PROPERTY        (2)
#define MAP_ICON_NS_HOTEL           (3)
#define MAP_ICON_NS_RADAR           (4)
#define MAP_ICON_NS_TOLL            (5)

new gPlayerMapIconUsed[MAX_PLAYERS][PLAYER_MAP_ICON_SLOTS];
new gPlayerMapIconNamespace[MAX_PLAYERS][PLAYER_MAP_ICON_SLOTS];
new gPlayerMapIconSource[MAX_PLAYERS][PLAYER_MAP_ICON_SLOTS];

stock ManagedMapIcon_FindSlot(playerid, namespaceid, sourceid)
{
    new slot;

    for (slot = 0; slot < PLAYER_MAP_ICON_SLOTS; slot++)
    {
        if (gPlayerMapIconUsed[playerid][slot] && gPlayerMapIconNamespace[playerid][slot] == namespaceid && gPlayerMapIconSource[playerid][slot] == sourceid)
        {
            return slot;
        }
    }
    return -1;
}

stock ManagedMapIcon_Set(playerid, namespaceid, sourceid, Float:x, Float:y, Float:z, icon, color, style)
{
    new slot = ManagedMapIcon_FindSlot(playerid, namespaceid, sourceid);

    if (slot == -1)
    {
        for (slot = 0; slot < PLAYER_MAP_ICON_SLOTS; slot++)
        {
            if (!gPlayerMapIconUsed[playerid][slot])
            {
                gPlayerMapIconUsed[playerid][slot] = 1;
                gPlayerMapIconNamespace[playerid][slot] = namespaceid;
                gPlayerMapIconSource[playerid][slot] = sourceid;
                break;
            }
        }
    }

    if (slot < 0 || slot >= PLAYER_MAP_ICON_SLOTS)
    {
        return 0;
    }

    SetPlayerMapIcon(playerid, slot, x, y, z, icon, color, style);
    return 1;
}

stock ManagedMapIcon_Remove(playerid, namespaceid, sourceid)
{
    new slot = ManagedMapIcon_FindSlot(playerid, namespaceid, sourceid);

    if (slot == -1)
    {
        return 0;
    }

    RemovePlayerMapIcon(playerid, slot);
    gPlayerMapIconUsed[playerid][slot] = 0;
    gPlayerMapIconNamespace[playerid][slot] = 0;
    gPlayerMapIconSource[playerid][slot] = 0;
    return 1;
}

stock ManagedMapIcon_ClearNamespace(playerid, namespaceid)
{
    new slot;

    for (slot = 0; slot < PLAYER_MAP_ICON_SLOTS; slot++)
    {
        if (gPlayerMapIconUsed[playerid][slot] && gPlayerMapIconNamespace[playerid][slot] == namespaceid)
        {
            RemovePlayerMapIcon(playerid, slot);
            gPlayerMapIconUsed[playerid][slot] = 0;
            gPlayerMapIconNamespace[playerid][slot] = 0;
            gPlayerMapIconSource[playerid][slot] = 0;
        }
    }
    return 1;
}

#define DIALOG_LOGIN                (1000)
#define DIALOG_REGISTER             (1001)
#define DIALOG_LOGIN_MENU           (1124)
#define DIALOG_RENAME_ACCOUNT_NAME  (1125)
#define DIALOG_RENAME_ACCOUNT_PASS  (1126)
#define DIALOG_DELIVERY_RANKING     (1127)
#define DIALOG_TAXI_RANKING         (1128)
#define DIALOG_MECHANIC_RANKING     (1129)
#define DIALOG_RP_NAME              (1002)
#define DIALOG_GPS                  (1003)
#define DIALOG_CITYHALL             (1004)
#define DIALOG_CITYHALL_RENAME      (1005)
#define DIALOG_DEALERSHIP           (1006)
#define DIALOG_JOB_WORK             (1007)
#define DIALOG_CITYHALL_JOBS        (1008)
#define DIALOG_CITYHALL_LICENSES    (1009)
#define DIALOG_CITYHALL_JOB_PANEL   (1010)
#define DIALOG_CONVENIENCE          (1011)
#define DIALOG_WEAPON_SHOP          (1132)
#define DIALOG_INVENTORY            (1012)
#define DIALOG_RESTAURANT           (1013)
#define DIALOG_NPC_TRANSPORT        (1014)
#define DIALOG_BANK_MENU            (1015)
#define DIALOG_BANK_DEPOSIT         (1016)
#define DIALOG_BANK_WITHDRAW        (1017)
#define DIALOG_BANK_PIX_TARGET      (1018)
#define DIALOG_BANK_PIX_AMOUNT      (1019)
#define DIALOG_BANK_MANAGER         (1020)
#define DIALOG_BANK_LOAN            (1021)
#define DIALOG_PHONE_HOME           (1022)
#define DIALOG_PHONE_GOV            (1023)
#define DIALOG_PHONE_PROPERTIES     (1024)
#define DIALOG_PHONE_PROPERTY       (1025)
#define DIALOG_PHONE_DELIVERY       (1026)
#define DIALOG_PHONE_RIDE           (1027)
#define DIALOG_HELP_MAIN            (22080)
#define DIALOG_HELP_CATEGORY        (22081)
#define DIALOG_MENU_MAIN            (1030)
#define DIALOG_MENU_CATEGORY        (1031)
#define DIALOG_TUTORIAL             (1032)
#define DIALOG_ADMIN_ACTION_INPUT   (1033)
#define DIALOG_ADMINS_ONLINE        (1034)
#define DIALOG_ADMIN_HELP           (1058)
#define DIALOG_BUG_REPORT_INPUT     (1035)
#define DIALOG_BUG_REPORT_LIST      (1036)
#define DIALOG_BUG_REPORT_DETAIL    (1037)
#define DIALOG_SERVER_CHECK         (1038)
#define DIALOG_SERVER_STATUS        (1039)
#define DIALOG_WHITELIST_LIST       (1040)
#define DIALOG_SECURITY_PANEL       (1041)
#define DIALOG_BAN_LIST             (1042)
#define DIALOG_RADIO_LIST           (1043)
#define DIALOG_DETRAN_MENU          (1044)
#define DIALOG_DETRAN_PLATE         (1045)
#define DIALOG_DETRAN_TRANSFER      (1046)
#define DIALOG_GARAGE_LIST          (1047)
#define DIALOG_BLITZ_MENU           (1048)
#define DIALOG_BLITZ_FINE           (1049)
#define DIALOG_VIP_MENU             (1050)
#define DIALOG_VIP_PLANS            (1051)
#define DIALOG_CLIMATE_INFO         (1052)
#define DIALOG_MAP_OBJECT_LIST      (1053)
#define DIALOG_MAP_GATE_LIST        (1054)
#define DIALOG_MAP_GATE_JOB         (1055)
#define DIALOG_CONFIG_STATUS        (1062)
#define DIALOG_LIFE_DOCS            (1063)
#define DIALOG_LIFE_TAXES           (1064)
#define DIALOG_LIFE_JUSTICE         (1065)
#define DIALOG_LIFE_HEALTH          (1066)
#define DIALOG_LIFE_BUSINESS        (1067)
#define DIALOG_LIFE_MARKET          (1068)
#define DIALOG_LIFE_BILLS           (1069)
#define DIALOG_LIFE_CONTRACTS       (1070)
#define DIALOG_LIFE_CARTORIO        (1071)
#define DIALOG_ACTIVITY_CENTER      (1072)
#define DIALOG_CITY_EVENTS          (1073)
#define DIALOG_CITY_PASS            (1074)
#define DIALOG_WEEKLY_RANKING       (1075)
#define DIALOG_PERSON_HISTORY       (1076)
#define DIALOG_CITY_NEWS            (1077)
#define DIALOG_CHANGELOG            (1078)
#define DIALOG_GM_VERSION           (1079)
#define DIALOG_GM_HEALTH            (1080)
#define DIALOG_PLAYER_DEBUG         (1081)
#define DIALOG_WAR_ZONE             (1082)
#define DIALOG_CHANGELOG_MENU       (1083)
#define DIALOG_GM_SELFTEST          (1084)
#define DIALOG_LIFE_AUCTION         (1085)
#define DIALOG_GM_RELEASE           (1086)
#define DIALOG_LIFE_ECONOMY         (1087)
#define DIALOG_COMMAND_NOTFOUNDS    (1134)
#define DIALOG_COMMAND_NOTFOUND_PICK (1135)
#define DIALOG_COMMAND_NOTFOUND_TARGET (1136)
#define DIALOG_COMMAND_NOTFOUND_MANUAL (1137)
#define DIALOG_COMMAND_NOTFOUND_HISTORY (1138)
#define DIALOG_POST_DEPLOY          (1139)
#define DIALOG_CMD_HOTFIX_PROMOTE   (1140)
#define DIALOG_POLICE_CENTRAL       (1141)
#define DIALOG_COMMAND_MODULES      (1142)
#define DIALOG_BALANCE_GM           (1143)
#define DIALOG_DAILY_JOURNEY        (1144)
#define DIALOG_WEEKLY_AGENDA        (1145)
#define DIALOG_NEIGHBORHOOD_EVENTS  (1146)
#define DIALOG_URBAN_PROGRESS       (1147)
#define DIALOG_PROFESSIONS          (1148)
#define DIALOG_FIRST_JOURNEY        (1088)
#define DIALOG_NEXT_STEP            (1089)
#define DIALOG_PUBLIC_SERVICES      (1090)
#define DIALOG_PUBLIC_CONSTITUTION  (1091)
#define DIALOG_GM_INTEGRITY         (1133)
#define DIALOG_PUBLIC_WORKS         (1100)
#define DIALOG_POLITICS_PANEL       (1101)
#define DIALOG_CITYHALL_PANEL       (1102)
#define DIALOG_EDIT_MAP_PANEL       (1103)
#define DIALOG_TOLL_GOTO_LIST       (1104)
#define DIALOG_MAP_GOTO_LIST        (1105)
#define DIALOG_JOBVEHICLE_GOTO_LIST (1106)
#define DIALOG_TOLL_CREATE_MENU     (1107)
#define DIALOG_POLITICAL_DUTY_PANEL (1108)
#define DIALOG_POLITICAL_VOTE_OFFICE (1109)
#define DIALOG_POLITICAL_VOTE_CANDIDATE (1110)
#define DIALOG_POLITICAL_ACTION_MENU (1111)
#define DIALOG_POLITICAL_WORK_SELECT (1112)
#define DIALOG_POLITICAL_BUDGET_INPUT (1113)
#define DIALOG_POLITICAL_QUICK_REASON (1114)
#define DIALOG_POLITICAL_PROPOSAL_VOTE (1115)
#define DIALOG_POLITICAL_MAIN_MENU (1116)
#define DIALOG_POLITICAL_CANDIDATE_OFFICE (1117)
#define DIALOG_POLITICAL_ADMIN_MENU (1118)
#define DIALOG_EDIT_HOUSE_CREATE    (1119)
#define DIALOG_EDIT_BUSINESS_CREATE (1120)
#define DIALOG_CHANGE_PASS_CURRENT  (1121)
#define DIALOG_CHANGE_PASS_NEW      (1122)
#define DIALOG_CHANGE_PASS_CONFIRM  (1123)
#define DIALOG_SERVICE_CALL_CREATE  (1130)
#define DIALOG_SERVICE_CALL_LIST    (1131)
#define DIALOG_POLICE_ARREST_CRIME  (1092)
#define DIALOG_TRAFFIC_FINE         (1093)
#define DIALOG_POLICE_SEARCH        (1094)
#define DIALOG_WANTED_LIST          (1095)
#define DIALOG_TOLL_TAG            (1096)
#define DIALOG_LOGISTICS_PANEL     (1097)
#define DIALOG_ECONOMY_TABLE       (1098)
#define DIALOG_TRANSPARENCY_CENTER (1099)

#define ACCOUNT_PATH_SIZE           (64)
#define PASSWORD_HASH_SIZE          (65)
#define CHARACTER_NAME_SIZE         (32)
#define PASSWORD_MIN_LENGTH         (4)
#define PASSWORD_CHANGE_MIN_LENGTH  (6)
#define MAX_LOGIN_TRIES             (3)

#define HUD_UPDATE_INTERVAL         (1000)
#define HOSTNAME_UPDATE_INTERVAL    (30000)
#define AUTOSAVE_INTERVAL           (600000)
#define BRASILIA_UTC_OFFSET         (-3)
#define CLIMATE_UPDATE_INTERVAL     (600000)
#define CLIMATE_NAME_SIZE           (32)
#define CHARACTER_XP_INTERVAL       (420000)
#define CHARACTER_XP_PER_LEVEL      (4)
#define JOB_VEHICLES_FILE           "job_vehicles.txt"
#define MAX_JOB_CONFIG_VEHICLES     (80)
#define JOB_VEHICLE_RESPAWN_DELAY   (900)
#define MAP_OBJECTS_FILE            "map_objects.txt"
#define MAX_MAP_OBJECTS             (120)
#define MAP_OBJECT_NAME_SIZE        (32)
#define MAP_OBJECT_TYPE_STATIC      (0)
#define MAP_OBJECT_TYPE_GATE        (1)
#define MAP_OBJECT_DEFAULT_RANGE    (18.0)
#define MAP_OBJECT_DEFAULT_SPEED    (2.0)
#define MAP_GATE_AUTO_CLOSE_MS      (7000)
#define NEEDS_UPDATE_INTERVAL       (60000)
#define NEEDS_WARNING_INTERVAL      (30000)
#define NEEDS_MAX_VALUE             (100)
#define NEEDS_MIN_SAFE              (35)
#define NEEDS_LOW_VALUE             (25)
#define NEEDS_CRITICAL_VALUE        (0)
#define NEEDS_HUNGER_LOSS           (1)
#define NEEDS_THIRST_LOSS           (2)
#define NEEDS_STARVE_DAMAGE         (10.0)
#define FUEL_UPDATE_INTERVAL        (5000)
#define FUEL_MAX_VALUE              (100)
#define FUEL_LOW_VALUE              (15)
#define FUEL_PRICE_GASOLINE         (7)
#define FUEL_PRICE_ETHANOL          (4)
#define FUEL_PRICE_DIESEL           (7)
#define FUEL_PRICE_GLP              (115)
#define BANK_TRANSFER_LIMIT         (1000000)
#define MAX_PLAYER_FINE             (500000)
#define MAX_TRAFFIC_POINTS          (999)
#define MAX_WANTED_LEVEL            (6)
#define JAIL_BAIL_COST_PER_LEVEL    (750)
#define JAIL_MIN_SECONDS            (600)
#define HOUSE_NONE                  (0)
#define NPC_TRANSPORT_COST          (150)
#define NPC_TOW_COST                (350)
#define VEHICLE_GARAGE_COST         (150)
#define VEHICLE_IMPOUND_COST        (700)
#define VEHICLE_INSURANCE_COST      (650)
#define VEHICLE_IPVA_BASE           (0)
#define VEHICLE_IPVA_PERCENT        (4)
#define VEHICLE_DETRAN_REGISTER_COST (174)
#define VEHICLE_DETRAN_PLATE_COST   (250)
#define VEHICLE_DETRAN_TRANSFER_COST (420)
#define VEHICLE_SELL_PERCENT        (60)
#define MAX_PLAYER_VEHICLES         (5)
#define MAX_VEHICLE_SHARED_KEYS     (5)
#define VEHICLE_GARAGE_NONE         (0)
#define VEHICLE_GARAGE_PUBLIC       (1)
#define VEHICLE_GARAGE_HOME         (2)
#define VEHICLE_IPVA_VALID_DAYS     (30)
#define VEHICLE_INSURANCE_VALID_DAYS (30)
#define BANK_ACCESS_ATM             (1)
#define BANK_ACCESS_BRANCH          (2)
#define BANK_ACCESS_PHONE           (3)
#define BANK_OPEN_COST              (100)
#define BANK_CARD_COST              (75)
#define BANK_LOAN_MIN               (1000)
#define BANK_LOAN_INTEREST_PERCENT  (15)
#define PHONE_RIDE_COST             (220)
#define PHONE_DELIVERY_FEE          (25)
#define RADAR_CHECK_INTERVAL        (2000)
#define RADAR_MOBILE_ROTATE_INTERVAL (900000)
#define RADAR_RANGE                 (38.0)
#define RADAR_SPEED_TOLERANCE       (5)
#define RADAR_FINE_BASE             (120)
#define RADAR_FINE_PER_KMH          (12)
#define TRAFFIC_FINE_LIGHT          (1)
#define TRAFFIC_FINE_MEDIUM         (2)
#define TRAFFIC_FINE_SERIOUS        (3)
#define TRAFFIC_FINE_VERY_SERIOUS   (4)
#define RADAR_MANUAL_FILE           "radares.txt"
#define RADAR_MIN_STREET_DISTANCE   (500.0)
#define BOT_MESSAGES_FILE           "bot_messages.txt"
#define BOT_BADWORDS_FILE           "bot_badwords.txt"
#define MARKET_STOCK_FILE           "market_stock.txt"
#define BUSINESS_ECONOMY_FILE       "business_economy.txt"
#define JUSTICE_CASES_FILE          "justice_cases.txt"
#define JUSTICE_EVIDENCE_FILE       "justice_evidence.txt"
#define JUSTICE_WARRANTS_FILE       "justice_warrants.txt"
#define CRIME_LOG_FILE              "crime_log.txt"
#define CRIME_FACTIONS_FILE         "factions.txt"
#define CRIME_SPOTS_FILE            "crime_spots.txt"
#define GOVERNMENT_REVENUE_FILE     "government_revenue.txt"
#define PUBLIC_WORKS_FILE           "public_works.txt"
#define POLITICS_STATE_FILE         "politics_state.txt"
#define POLITICAL_PROPOSALS_FILE    "political_proposals.txt"
#define TOLLS_FILE                  "tolls.txt"
#define BOT_UPDATE_INTERVAL         (120000)
#define BOT_MAX_MESSAGES            (96)
#define BOT_MAX_BADWORDS            (96)
#define BOT_MESSAGE_SIZE            (144)
#define BOT_BADWORD_SIZE            (32)
#define BOT_WARN_MUTE_SECONDS       (300)
#define BOT_WARN_JAIL_SECONDS       (600)
#define BUG_REPORT_FILE             "bug_reports.txt"
#define BUG_REPORT_MAX_DIALOG_ITEMS (24)
#define BUG_REPORT_LINE_SIZE        (512)
#define BUG_REPORT_TEXT_SIZE        (180)
#define BUG_REPORT_MIN_TEXT         (8)
#define ACCESS_CONFIG_FILE          "access_config.txt"
#define WHITELIST_FILE              "whitelist.txt"
#define ACCOUNT_INDEX_FILE          "account_index.txt"
#define ACCOUNT_ALIAS_FILE          "account_aliases.txt"
#define ACCOUNT_FOLDER_MARKER       "contas/.keep"
#define BACKUP_STATUS_FILE          "backup_status.txt"
#define RELEASE_PLAN_FILE           "release_plan.txt"
#define INTEGRITY_REPORT_FILE       "integrity_report.txt"
#define LOG_ADMIN_FILE              "log_admin_actions.txt"
#define LOG_PUNISH_FILE             "log_punishments.txt"
#define LOG_MONEY_FILE              "log_money_bank.txt"
#define LOG_DEATH_FILE              "log_deaths.txt"
#define LOG_BUG_FILE                "log_bugs.txt"
#define LOG_CHAT_FILTER_FILE        "log_chat_filter.txt"
#define LOG_VIP_FILE                "log_vip.txt"
#define LOG_CONTRACT_FILE           "log_contracts.txt"
#define LOG_COMMAND_AI_FILE         "log_command_ai.txt"
#define LOG_LAST_ACTION_FILE        "log_last_actions.txt"
#define GM_TIMER_HUD                (0)
#define GM_TIMER_FUEL               (1)
#define GM_TIMER_RADAR              (2)
#define GM_TIMER_COUNT              (3)
#define GM_TIMER_WARN_MS            (60)
#define GM_TIMER_ALERT_COOLDOWN_MS  (300000)
#define RELCHK_VERSION              (1)
#define RELCHK_CHANGELOG            (2)
#define RELCHK_HEALTH               (4)
#define RELCHK_SELFTEST             (8)
#define RELCHK_ANTIABUSE            (16)
#define RELCHK_PERF                 (32)
#define RELCHK_LOGS                 (64)
#define RELCHK_STAFF                (128)
#define RELCHK_DEBUG                (256)
#define RELCHK_REQUIRED             (511)
#define RELCHK_REQUIRED_COUNT       (9)
#define OPS_MAX_WHITELIST_CACHE     (128)
#define BANS_FILE                   "bans.txt"
#define SECURITY_ALERT_FILE         "security_alerts.txt"
#define BUG_REPORT_UPDATES_FILE     "bug_report_updates.txt"
#define RADIO_PLAYLIST_FILE         "music_playlists.txt"
#define RADIO_MAX_STATIONS          (40)
#define RADIO_NAME_SIZE             (48)
#define RADIO_CATEGORY_SIZE         (28)
#define RADIO_URL_SIZE              (160)
#define RADIO_UPDATE_INTERVAL       (5000)
#define RADIO_LOCAL_DEFAULT_RANGE   (45.0)
#define RADIO_LOCAL_MAX_RANGE       (120.0)
#define RADIO_AMBIENT_RANGE         (28.0)
#define RADIO_SOURCE_NONE           (0)
#define RADIO_SOURCE_PERSONAL       (1)
#define RADIO_SOURCE_VEHICLE        (2)
#define RADIO_SOURCE_AMBIENT        (3)
#define RADIO_SOURCE_LOCAL          (4)
#define VIP_GRANT_FOLDER            "vip_grants"
#define VIP_GRANT_MARKER            "vip_grants/.keep"
#define VIP_ORDERS_FILE             "vip_orders.txt"
#define VIP_PLANS_FILE              "vip_plans.txt"
#define VIP_CHECK_INTERVAL          (60000)
#define VIP_MAX_LEVEL               (4)
#define VIP_SECONDS_PER_DAY         (86400)
#define SECURITY_UPDATE_INTERVAL    (5000)
#define SECURITY_CHAT_MIN_INTERVAL  (800)
#define SECURITY_COMMAND_MIN_INTERVAL (600)
#define SECURITY_CHAT_FLOOD_LIMIT   (4)
#define SECURITY_COMMAND_FLOOD_LIMIT (6)
#define SECURITY_CHAT_MUTE_SECONDS  (60)
#define SECURITY_BUG_COOLDOWN       (60000)
#define SECURITY_GPS_COOLDOWN       (5000)
#define SECURITY_PHONE_COOLDOWN     (3000)
#define SECURITY_MENU_COOLDOWN      (2500)
#define SECURITY_HELP_COOLDOWN      (3000)
#define SECURITY_DIALOG_COOLDOWN    (3000)
#define SECURITY_TELEPORT_GRACE     (7000)
#define SECURITY_TELEPORT_DISTANCE  (420.0)
#define SECURITY_VEHICLE_TELEPORT_DISTANCE (900.0)
#define SECURITY_MAX_BAN_DIALOG     (48)
#define SECURITY_COOLDOWN_SLOTS     (6)
#define LAST_ACTION_NAME_SIZE       (32)
#define LAST_ACTION_DETAIL_SIZE     (96)

new gGmTimerLastMs[GM_TIMER_COUNT];
new gGmTimerMaxMs[GM_TIMER_COUNT];
new gGmTimerScanned[GM_TIMER_COUNT];
new gGmTimerActive[GM_TIMER_COUNT];
new gGmTimerRuns[GM_TIMER_COUNT];
new gGmTimerSlowRuns[GM_TIMER_COUNT];
new gGmTimerLastAlertTick[GM_TIMER_COUNT];
new gReleaseChecklistFlags;
new gPlayerLastActionTick[MAX_PLAYERS];
new gPlayerLastAction[MAX_PLAYERS][LAST_ACTION_NAME_SIZE];
new gPlayerLastActionDetail[MAX_PLAYERS][LAST_ACTION_DETAIL_SIZE];

#define INV_ITEM_NONE               (0)
#define INV_ITEM_WATER              (1)
#define INV_ITEM_SODA               (2)
#define INV_ITEM_SNACK              (3)
#define INV_ITEM_MEAL               (4)
#define INV_ITEM_MEDKIT             (5)
#define INV_ITEM_TOOLS              (6)
#define INV_ITEM_BAIT               (7)
#define INV_ITEM_ORE                (8)
#define INV_ITEM_FISH               (9)
#define INV_ITEM_SEEDS              (10)
#define INV_ITEM_DOCUMENTS          (11)
#define INV_ITEM_ILLEGAL_SEED       (12)
#define INV_ITEM_ILLEGAL_PLANT      (13)
#define INV_ITEM_ILLEGAL_RAW        (14)
#define INV_ITEM_ILLEGAL_PACKED     (15)
#define INV_ITEM_DIRTY_MONEY        (16)
#define INV_MAX_ITEMS               (17)

#define LOCAL_CHAT_DISTANCE         (35.0)
#define ADMIN_LEVEL_HELPER          (1)
#define ADMIN_LEVEL_GAME            (2)
#define ADMIN_LEVEL_MANAGER         (3)
#define ADMIN_LEVEL_ADMIN           (4)
#define ADMIN_LEVEL_OWNER           (5)

#define JOB_NONE                    (0)
#define JOB_ENTREGADOR              (1)
#define JOB_LIXEIRO                 (2)
#define JOB_MOTORISTA_ONIBUS        (3)
#define JOB_TAXISTA                 (4)
#define JOB_CAMINHONEIRO            (5)
#define JOB_MECANICO                (6)
#define JOB_FRENTISTA               (7)
#define JOB_POLICIAL                (8)
#define JOB_MEDICO                  (9)
#define JOB_BOMBEIRO                (10)
#define JOB_SEGURANCA               (11)
#define JOB_CARTEIRO                (12)
#define JOB_MOTOBOY                 (13)
#define JOB_PESCADOR                (14)
#define JOB_AGRICULTOR              (15)
#define JOB_MINERADOR               (16)
#define JOB_PEDREIRO                (17)
#define JOB_GARCOM                  (18)
#define JOB_COZINHEIRO              (19)
#define JOB_VENDEDOR                (20)
#define JOB_JORNALISTA              (21)
#define JOB_ADVOGADO                (22)
#define JOB_JUIZ                    (23)
#define JOB_MOTORISTA_AMBULANCIA    (24)
#define JOB_TECNICO                 (25)
#define JOB_PRF                     (26)
#define JOB_POLICIA_FEDERAL         (27)
#define JOB_POLICIA_CIVIL           (28)
#define JOB_POLICIA_PENAL           (29)
#define JOB_AGENTE_DETRAN           (30)
#define JOB_FUNCIONARIO_PREFEITURA  (31)
#define JOB_BANCARIO                (32)
#define JOB_CORRETOR_IMOVEIS        (33)
#define JOB_CONTADOR                (34)
#define JOB_PROFESSOR               (35)
#define JOB_FARMACEUTICO            (36)
#define JOB_ASSISTENTE_SOCIAL       (37)
#define JOB_PERITO_CRIMINAL         (38)
#define JOB_CAIXA_REPOSITOR         (39)
#define JOB_BARTENDER               (40)
#define JOB_PADEIRO_PIZZAIOLO       (41)
#define JOB_RECEPCIONISTA_HOTEL     (42)
#define JOB_GUINCHEIRO              (43)
#define JOB_MOTORISTA_APP           (44)
#define JOB_ENCANADOR               (45)
#define JOB_JARDINEIRO              (46)
#define JOB_ZELADOR                 (47)
#define JOB_OPERADOR_FABRICA        (48)
#define JOB_PROMOTOR                (49)
#define JOB_DEFENSOR_PUBLICO        (50)
#define JOB_OFICIAL_JUSTICA         (51)
#define JOB_ESCRIVAO                (52)
#define JOB_MAX_ID                  (52)

stock IsLawEnforcementJob(jobid)
{
    switch (jobid)
    {
        case JOB_POLICIAL, JOB_PRF, JOB_POLICIA_FEDERAL, JOB_POLICIA_CIVIL, JOB_POLICIA_PENAL:
        {
            return 1;
        }
    }
    return 0;
}

stock IsPublicSecurityJob(jobid)
{
    return (IsLawEnforcementJob(jobid) || jobid == JOB_SEGURANCA);
}

#define LIFE_BUSINESS_NONE          (0)
#define LIFE_BUSINESS_COMMERCE      (1)
#define LIFE_BUSINESS_WORKSHOP      (2)
#define LIFE_BUSINESS_TRANSPORT     (3)
#define LIFE_BUSINESS_RESTAURANT    (4)
#define LIFE_BUSINESS_HOTEL         (5)
#define LIFE_BUSINESS_FACTORY       (6)
#define LIFE_BUSINESS_REAL_ESTATE   (7)
#define LIFE_BUSINESS_ACCOUNTING    (8)
#define LIFE_BUSINESS_MAX_TYPE      (8)
#define CITY_PASS_KIND_JOB          (1)
#define CITY_PASS_KIND_ECONOMY      (2)
#define CITY_PASS_KIND_PUBLIC       (3)
#define WEEKLY_SCORE_WORK           (1)
#define WEEKLY_SCORE_BUSINESS       (2)
#define WEEKLY_SCORE_POLICE         (3)
#define WEEKLY_SCORE_CITIZEN        (4)

stock SendWelcomeMessages(playerid)
{
    new message[128];

    format(message, sizeof(message), "Bem-vindo ao %s.", gServerName);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(playerid, COLOR_WHITE, "Use /ajuda para ver os comandos iniciais.");
    return 1;
}

stock IsNumericString(text[], allowNegative = 0)
{
    new index;
    new length = strlen(text);

    if (length == 0)
    {
        return 0;
    }

    if (allowNegative && text[0] == '-')
    {
        if (length == 1)
        {
            return 0;
        }
        index = 1;
    }

    while (index < length)
    {
        if (text[index] < '0' || text[index] > '9')
        {
            return 0;
        }
        index++;
    }

    return 1;
}

stock SkipSpaces(const text[], index)
{
    new length = strlen(text);

    while (index < length && text[index] <= ' ')
    {
        index++;
    }

    return index;
}

stock GetCommandName(const text[], command[], size = sizeof(command))
{
    new index;
    new offset;
    new length = strlen(text);

    index = SkipSpaces(text, 0);
    offset = index;

    while (index < length && text[index] > ' ' && (index - offset) < (size - 1))
    {
        command[index - offset] = text[index];
        index++;
    }

    command[index - offset] = 0;
    return index;
}

stock GetNextParam(const text[], &index, output[], size = sizeof(output))
{
    new offset;
    new length = strlen(text);

    index = SkipSpaces(text, index);
    if (index >= length)
    {
        output[0] = 0;
        return 0;
    }

    offset = index;
    while (index < length && text[index] > ' ' && (index - offset) < (size - 1))
    {
        output[index - offset] = text[index];
        index++;
    }

    output[index - offset] = 0;
    return 1;
}

stock GetRemainingText(const text[], index, output[], size = sizeof(output))
{
    new offset;
    new length = strlen(text);

    index = SkipSpaces(text, index);
    if (index >= length)
    {
        output[0] = 0;
        return 0;
    }

    offset = index;
    while (index < length && (index - offset) < (size - 1))
    {
        output[index - offset] = text[index];
        index++;
    }

    output[index - offset] = 0;
    return 1;
}

stock IsValidConnectedPlayer(playerid)
{
    if (playerid < 0 || playerid >= GetMaxPlayers())
    {
        return 0;
    }

    return IsPlayerConnected(playerid);
}

stock GetPlayerNameEx(playerid, name[], size = sizeof(name))
{
    if (!IsValidConnectedPlayer(playerid))
    {
        format(name, size, "Desconhecido");
        return 0;
    }

    if (!GetPlayerName(playerid, name, size))
    {
        format(name, size, "ID_%d", playerid);
        return 0;
    }
    return 1;
}

stock SendUsage(playerid, usage[])
{
    new message[144];

    format(message, sizeof(message), "Uso: %s", usage);
    SendClientMessage(playerid, COLOR_GRAY, message);
    return 1;
}

stock StripLineEnd(text[])
{
    new length = strlen(text);

    while (length > 0 && (text[length - 1] == 10 || text[length - 1] == 13))
    {
        text[length - 1] = 0;
        length--;
    }
    return 1;
}

stock ReadFileLine(File:handle, output[], size = sizeof(output))
{
    if (fread(handle, output, size) <= 0)
    {
        return 0;
    }

    StripLineEnd(output);
    return 1;
}

stock SetDefaultServerInfo()
{
    format(gServerName, SERVER_NAME_SIZE, "%s", GM_NAME);
    format(gServerVersion, SERVER_VERSION_SIZE, "%s", GM_VERSION);
    format(gServerModeText, SERVER_MODE_SIZE, "%s", GM_TEXT);
    format(gServerLanguage, SERVER_LANGUAGE_SIZE, "Portuguese");
    return 1;
}

stock CreateDefaultServerInfoFile()
{
    new line[128];
    new File:file = fopen(SERVER_INFO_FILE, io_write);

    if (!file)
    {
        return 0;
    }

    format(line, sizeof(line), "server_name=%s\r\n", gServerName); fwrite(file, line);
    format(line, sizeof(line), "server_version=%s\r\n", gServerVersion); fwrite(file, line);
    format(line, sizeof(line), "gamemode_text=%s\r\n", gServerModeText); fwrite(file, line);
    format(line, sizeof(line), "server_language=%s\r\n", gServerLanguage); fwrite(file, line);
    fclose(file);
    return 1;
}

stock ApplyServerInfoField(key[], value[])
{
    if (strcmp(key, "server_name", false) == 0)
    {
        format(gServerName, SERVER_NAME_SIZE, "%s", value);
    }
    else if (strcmp(key, "server_version", false) == 0)
    {
        format(gServerVersion, SERVER_VERSION_SIZE, "%s", value);
    }
    else if (strcmp(key, "gamemode_text", false) == 0)
    {
        format(gServerModeText, SERVER_MODE_SIZE, "%s", value);
    }
    else if (strcmp(key, "server_language", false) == 0)
    {
        format(gServerLanguage, SERVER_LANGUAGE_SIZE, "%s", value);
    }
    return 1;
}

stock ApplyServerInfoLine(line[])
{
    new equalPos;
    new key[32];
    new value[96];

    if (line[0] == 0 || line[0] == '#')
    {
        return 0;
    }

    equalPos = strfind(line, "=", false);
    if (equalPos == -1)
    {
        return 0;
    }

    strmid(key, line, 0, equalPos, sizeof(key));
    strmid(value, line, equalPos + 1, strlen(line), sizeof(value));
    ApplyServerInfoField(key, value);
    return 1;
}

stock LoadServerInfo()
{
    new line[128];
    new File:file;

    SetDefaultServerInfo();

    if (!fexist(SERVER_INFO_FILE))
    {
        CreateDefaultServerInfoFile();
    }

    file = fopen(SERVER_INFO_FILE, io_read);
    if (!file)
    {
        print("[ServerInfo] Nao foi possivel abrir server_info.txt. Usando padrao da GM.");
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        ApplyServerInfoLine(line);
    }

    fclose(file);
    print("[ServerInfo] Configuracoes carregadas de scriptfiles/server_info.txt.");
    return 1;
}

stock ApplyServerInfo()
{
    new command[96];

    SetGameModeText(gServerModeText);
    format(command, sizeof(command), "language %s", gServerLanguage);
    SendRconCommand(command);
    return 1;
}

stock IsLeapYear(year)
{
    if ((year % 400) == 0)
    {
        return 1;
    }

    if ((year % 100) == 0)
    {
        return 0;
    }

    return ((year % 4) == 0);
}

stock GetDaysInMonth(year, month)
{
    switch (month)
    {
        case 1, 3, 5, 7, 8, 10, 12:
        {
            return 31;
        }
        case 2:
        {
            if (IsLeapYear(year))
            {
                return 29;
            }
            return 28;
        }
    }

    return 30;
}

stock GetBrasiliaDateTime(&year, &month, &day, &hour, &minute, &second)
{
    new timestamp;
    new daySeconds;
    new days;
    new daysInYear;
    new daysInMonth;

    timestamp = gettime() + (BRASILIA_UTC_OFFSET * 3600);
    days = timestamp / 86400;
    daySeconds = timestamp % 86400;

    if (daySeconds < 0)
    {
        daySeconds += 86400;
        days--;
    }

    hour = daySeconds / 3600;
    minute = (daySeconds % 3600) / 60;
    second = daySeconds % 60;

    year = 1970;
    daysInYear = 365;
    if (IsLeapYear(year))
    {
        daysInYear = 366;
    }

    while (days >= daysInYear)
    {
        days -= daysInYear;
        year++;

        daysInYear = 365;
        if (IsLeapYear(year))
        {
            daysInYear = 366;
        }
    }

    month = 1;
    daysInMonth = GetDaysInMonth(year, month);

    while (days >= daysInMonth)
    {
        days -= daysInMonth;
        month++;
        daysInMonth = GetDaysInMonth(year, month);
    }

    day = days + 1;
    return 1;
}

stock GetBrasiliaDayStamp()
{
    new timestamp = gettime() + (BRASILIA_UTC_OFFSET * 3600);
    new days = timestamp / 86400;

    if (timestamp < 0 && (timestamp % 86400) != 0)
    {
        days--;
    }
    return days;
}

stock CountConnectedPlayers()
{
    new playerid;
    new total;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && !IsPlayerNPC(playerid))
        {
            total++;
        }
    }

    return total;
}

stock SanitizeLogText(source[], output[], size)
{
    new index;
    new offset;
    new length = strlen(source);

    while (index < length && offset < (size - 1))
    {
        if (source[index] == 10 || source[index] == 13 || source[index] == '|')
        {
            output[offset] = ' ';
        }
        else
        {
            output[offset] = source[index];
        }

        offset++;
        index++;
    }

    output[offset] = 0;
    return 1;
}

stock WriteServerLog(fileName[], category[], details[])
{
    new File:file;
    new clean[256];
    new line[384];
    new year;
    new month;
    new day;
    new hour;
    new minute;
    new second;

    SanitizeLogText(details, clean, sizeof(clean));
    GetBrasiliaDateTime(year, month, day, hour, minute, second);

    file = fopen(fileName, io_append);
    if (!file)
    {
        return 0;
    }

    format(line, sizeof(line), "%04d-%02d-%02d %02d:%02d:%02d|%s|%s\r\n", year, month, day, hour, minute, second, category, clean);
    fwrite(file, line);
    fclose(file);
    return 1;
}

stock WritePlayerLog(fileName[], category[], playerid, details[])
{
    new name[MAX_PLAYER_NAME + 1];
    new clean[192];
    new line[256];

    GetPlayerNameEx(playerid, name, sizeof(name));
    SanitizeLogText(details, clean, sizeof(clean));
    format(line, sizeof(line), "player=%s id=%d %s", name, playerid, clean);
    return WriteServerLog(fileName, category, line);
}

stock Gm_RecordPlayerAction(playerid, action[], details[] = "")
{
    new cleanAction[LAST_ACTION_NAME_SIZE];
    new cleanDetails[LAST_ACTION_DETAIL_SIZE];
    new logLine[160];

    if (!IsValidConnectedPlayer(playerid) || IsPlayerNPC(playerid))
    {
        return 0;
    }

    SanitizeLogText(action, cleanAction, sizeof(cleanAction));
    SanitizeLogText(details, cleanDetails, sizeof(cleanDetails));
    format(gPlayerLastAction[playerid], LAST_ACTION_NAME_SIZE, "%s", cleanAction);
    format(gPlayerLastActionDetail[playerid], LAST_ACTION_DETAIL_SIZE, "%s", cleanDetails);
    gPlayerLastActionTick[playerid] = GetTickCount();

    format(logLine, sizeof(logLine), "action=%s detail=%s", cleanAction, cleanDetails);
    return WritePlayerLog(LOG_LAST_ACTION_FILE, "LAST_ACTION", playerid, logLine);
}

stock Gm_ClearPlayerLastAction(playerid)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
    {
        return 0;
    }

    gPlayerLastActionTick[playerid] = 0;
    gPlayerLastAction[playerid][0] = 0;
    gPlayerLastActionDetail[playerid][0] = 0;
    return 1;
}

stock Gm_FormatPlayerLastAction(playerid, output[], size = sizeof(output))
{
    new ageSeconds;

    if (playerid < 0 || playerid >= MAX_PLAYERS || gPlayerLastActionTick[playerid] <= 0)
    {
        format(output, size, "sem acao registrada");
        return 0;
    }

    ageSeconds = (GetTickCount() - gPlayerLastActionTick[playerid]) / 1000;
    format(output, size, "%s ha %ds | %s", gPlayerLastAction[playerid], ageSeconds, gPlayerLastActionDetail[playerid]);
    return 1;
}

stock Gm_GetTimerName(timerid, output[], size = sizeof(output))
{
    switch (timerid)
    {
        case GM_TIMER_HUD: format(output, size, "HUD");
        case GM_TIMER_FUEL: format(output, size, "Fuel");
        case GM_TIMER_RADAR: format(output, size, "Radar");
        default: format(output, size, "Timer");
    }
    return 1;
}

stock Gm_RecordTimerMetric(timerid, elapsedMs, scanned, active)
{
    new tick;
    new name[16];
    new detail[128];

    if (timerid < 0 || timerid >= GM_TIMER_COUNT)
    {
        return 0;
    }
    if (elapsedMs < 0)
    {
        elapsedMs = 0;
    }

    gGmTimerLastMs[timerid] = elapsedMs;
    gGmTimerScanned[timerid] = scanned;
    gGmTimerActive[timerid] = active;
    gGmTimerRuns[timerid]++;
    if (elapsedMs > gGmTimerMaxMs[timerid])
    {
        gGmTimerMaxMs[timerid] = elapsedMs;
    }

    if (elapsedMs >= GM_TIMER_WARN_MS)
    {
        gGmTimerSlowRuns[timerid]++;
        tick = GetTickCount();
        if (!gGmTimerLastAlertTick[timerid] || tick - gGmTimerLastAlertTick[timerid] >= GM_TIMER_ALERT_COOLDOWN_MS)
        {
            gGmTimerLastAlertTick[timerid] = tick;
            Gm_GetTimerName(timerid, name, sizeof(name));
            format(detail, sizeof(detail), "timer=%s ms=%d scanned=%d active=%d runs=%d slow=%d", name, elapsedMs, scanned, active, gGmTimerRuns[timerid], gGmTimerSlowRuns[timerid]);
            WriteServerLog(LOG_ADMIN_FILE, "PERF_TIMER", detail);
        }
    }
    return 1;
}

stock Gm_CountTimerRisks()
{
    new timerid;
    new risks;

    for (timerid = 0; timerid < GM_TIMER_COUNT; timerid++)
    {
        if (gGmTimerRuns[timerid] <= 0 || gGmTimerLastMs[timerid] >= GM_TIMER_WARN_MS || gGmTimerSlowRuns[timerid] >= 3)
        {
            risks++;
        }
    }
    return risks;
}

stock Gm_MarkReleaseChecklist(flag)
{
    gReleaseChecklistFlags = gReleaseChecklistFlags | flag;
    return 1;
}

stock Gm_CountReleaseChecklist()
{
    new count;

    if (gReleaseChecklistFlags & RELCHK_VERSION) count++;
    if (gReleaseChecklistFlags & RELCHK_CHANGELOG) count++;
    if (gReleaseChecklistFlags & RELCHK_HEALTH) count++;
    if (gReleaseChecklistFlags & RELCHK_SELFTEST) count++;
    if (gReleaseChecklistFlags & RELCHK_ANTIABUSE) count++;
    if (gReleaseChecklistFlags & RELCHK_PERF) count++;
    if (gReleaseChecklistFlags & RELCHK_LOGS) count++;
    if (gReleaseChecklistFlags & RELCHK_STAFF) count++;
    if (gReleaseChecklistFlags & RELCHK_DEBUG) count++;
    return count;
}

stock Gm_ReleaseChecklistReady()
{
    return ((gReleaseChecklistFlags & RELCHK_REQUIRED) == RELCHK_REQUIRED);
}

stock Gm_AddReleaseMissing(output[], size, flag, label[])
{
    if (gReleaseChecklistFlags & flag)
    {
        return 0;
    }
    if (output[0] != 0)
    {
        strcat(output, ",", size);
    }
    strcat(output, label, size);
    return 1;
}

stock Gm_FormatReleaseMissing(output[], size)
{
    output[0] = 0;
    Gm_AddReleaseMissing(output, size, RELCHK_VERSION, "versao");
    Gm_AddReleaseMissing(output, size, RELCHK_CHANGELOG, "atualizacao");
    Gm_AddReleaseMissing(output, size, RELCHK_HEALTH, "saudegm");
    Gm_AddReleaseMissing(output, size, RELCHK_SELFTEST, "selftest");
    Gm_AddReleaseMissing(output, size, RELCHK_ANTIABUSE, "antiabuso");
    Gm_AddReleaseMissing(output, size, RELCHK_PERF, "perf");
    Gm_AddReleaseMissing(output, size, RELCHK_LOGS, "logs");
    Gm_AddReleaseMissing(output, size, RELCHK_STAFF, "staff");
    Gm_AddReleaseMissing(output, size, RELCHK_DEBUG, "debug");
    if (output[0] == 0)
    {
        format(output, size, "OK");
    }
    return 1;
}

stock ParseTargetPlayer(playerid, param[], &targetid)
{
    if (!IsNumericString(param))
    {
        SendClientMessage(playerid, COLOR_RED, "ID de jogador invalido.");
        return 0;
    }

    targetid = strval(param);
    if (!IsValidConnectedPlayer(targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador nao conectado.");
        return 0;
    }

    return 1;
}

stock IsValidCharacterName(name[])
{
    new index;
    new underscore;
    new length = strlen(name);

    if (length < 5 || length >= CHARACTER_NAME_SIZE)
    {
        return 0;
    }

    if (name[0] < 'A' || name[0] > 'Z')
    {
        return 0;
    }

    while (index < length)
    {
        if (name[index] == '_')
        {
            if (underscore || index < 2 || index >= (length - 2))
            {
                return 0;
            }

            underscore = 1;
            if (name[index + 1] < 'A' || name[index + 1] > 'Z')
            {
                return 0;
            }
        }
        else if (!((name[index] >= 'A' && name[index] <= 'Z') || (name[index] >= 'a' && name[index] <= 'z')))
        {
            return 0;
        }

        index++;
    }

    return underscore;
}
