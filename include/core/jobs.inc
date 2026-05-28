#if defined _nova_jobs_included
    #endinput
#endif
#define _nova_jobs_included

#define MAX_JOBS                    (52)
#define JOB_SELECT_MAX_ROWS         (64)
#define WORK_CHECKPOINT_SIZE        (4.0)
#define WORK_START_DISTANCE         (18.0)
#define WORK_SERVICE_DISTANCE       (7.0)
#define WORK_FINE_LIMIT             (5000)
#define WORK_TASK_COOLDOWN_MS       (8000)
#define WORK_CHECKPOINT_MIN_MS      (3000)
#define WORK_ROUTE_TELEPORT_DIST    (300.0)
#define WORK_ROUTE_TELEPORT_MS      (15000)
#define WORK_ABANDON_PENALTY        (150)
#define NPC_REPAIR_COST             (450)
#define NPC_REFUEL_PRICE_PER_PERCENT (6)
#define NPC_REFUEL_MIN_COST         (80)
#define JOB_XP_PER_TASK             (100)
#define JOB_XP_COMPLETE_BONUS       (150)
#define JOB_MAX_LEVEL               (10)
#define JOB_REWARD_CASH_DAY_LIMIT   (85000)
#define JOB_REWARD_XP_DAY_LIMIT     (18000)
#define JOB_REWARD_BURST_WINDOW_MS  (60000)
#define JOB_REWARD_BURST_LIMIT      (14)
#define JOB_LEVEL_REWARD_BASE       (350)
#define JOB_SIDE_GIG_PAY_PERCENT    (25)
#define JOB_SIDE_GIG_MIN_PAY        (80)
#define JOB_SIDE_GIG_MIN_COOLDOWN   (30000)
#define JOB_WORK_DIALOG_ACTIONS     (8)
#define JOB_TRAFFIC_FINE_DIALOG_ACTIONS (64)
#define JOB_TRAFFIC_FINE_PAGE_SIZE  (20)
#define JOBVEHICLE_GOTO_PAGE_SIZE   (30)
#define JOB_TRAFFIC_FINE_NAV_PREV   (-2)
#define JOB_TRAFFIC_FINE_NAV_NEXT   (-1)
#define JOB_WORK_ACT_CONTINUE       (1)
#define JOB_WORK_ACT_CANCEL         (2)
#define JOB_WORK_ACT_INFO           (3)
#define JOB_WORK_ACT_ACCEPT         (4)
#define JOB_WORK_ACT_START          (5)
#define JOB_WORK_ACT_QUIT           (6)
#define JOB_WORK_ACT_GPS            (7)
#define JOB_WORK_ACT_SIDE_GIG       (8)
#define WORK_SPECIAL_NONE           (0)
#define WORK_SPECIAL_URGENT         (1)
#define WORK_SPECIAL_VIP            (2)
#define WORK_SPECIAL_RISK           (3)
#define WORK_STREAK_BONUS_STEP      (3)
#define WORK_STREAK_BONUS_MAX       (25)
#define WORK_SPECIAL_CHANCE         (35)
#define WORK_EVENT_CHANCE           (30)
#define WORK_ROUTE_SHORT            (1)
#define WORK_ROUTE_MEDIUM           (2)
#define WORK_ROUTE_LONG             (3)
#define WORK_DELIVERY_BASE_TIME_MS  (180000)
#define WORK_DELIVERY_STEP_TIME_MS  (90000)
#define WORK_URGENT_TIME_PERCENT    (70)
#define DELIVERY_PACKAGE_COMMON     (0)
#define DELIVERY_PACKAGE_FRAGILE    (1)
#define DELIVERY_PACKAGE_COLD       (2)
#define DELIVERY_PACKAGE_URGENT     (3)
#define DELIVERY_PACKAGE_DOC        (4)
#define DELIVERY_WRONG_ADDRESS_CHANCE (14)
#define DELIVERY_WRONG_ADDRESS_EXTRA_MS (60000)
#define TAXI_PASSENGER_NORMAL       (0)
#define TAXI_PASSENGER_VIP          (1)
#define TAXI_PASSENGER_DRUNK        (2)
#define TAXI_PASSENGER_IRRITATED    (3)
#define TAXI_PASSENGER_TOURIST      (4)
#define TAXI_BUMP_CANCEL_DAMAGE     (520.0)
#define MECHANIC_DIAG_ENGINE        (0)
#define MECHANIC_DIAG_TIRE          (1)
#define MECHANIC_DIAG_BODY          (2)
#define MECHANIC_DIAG_BATTERY       (3)
#define MECHANIC_DIAG_TOW           (4)

#define CARGO_NONE                  (0)
#define CARGO_FOOD                  (1)
#define CARGO_FUEL                  (2)
#define CARGO_PARTS                 (3)
#define CARGO_MATERIALS             (4)
#define CARGO_ILLEGAL               (5)
#define CARGO_DOC_NONE              (0)
#define CARGO_DOC_OK                (1)
#define CARGO_DOC_EXPIRED           (2)
#define CARGO_ILLEGAL_CHANCE        (10)
#define CARGO_DOC_FAIL_CHANCE       (12)

#define JOB_REQ_NONE                (0)
#define JOB_REQ_CNH                 (1)
#define JOB_REQ_HEAVY               (2)
#define JOB_REQ_MEDICAL             (4)
#define JOB_REQ_OAB                 (8)
#define JOB_REQ_PUBLIC              (16)
#define JOB_REQ_POLICE              (32)

#define ROUTE_DELIVERY              (1)
#define ROUTE_GARBAGE               (2)
#define ROUTE_BUS                   (3)
#define ROUTE_TAXI                  (4)
#define ROUTE_TRUCK                 (5)
#define ROUTE_MECHANIC              (6)
#define ROUTE_GAS                   (7)
#define ROUTE_POLICE                (8)
#define ROUTE_MEDIC                 (9)
#define ROUTE_FIRE                  (10)
#define ROUTE_SECURITY              (11)
#define ROUTE_MAIL                  (12)
#define ROUTE_MOTOBOY               (13)
#define ROUTE_FISHING               (14)
#define ROUTE_FARM                  (15)
#define ROUTE_MINE                  (16)
#define ROUTE_BUILD                 (17)
#define ROUTE_WAITER                (18)
#define ROUTE_COOK                  (19)
#define ROUTE_SELLER                (20)
#define ROUTE_NEWS                  (21)
#define ROUTE_LAWYER                (22)
#define ROUTE_JUDGE                 (23)
#define ROUTE_AMBULANCE             (24)
#define ROUTE_TECH                  (25)
#define ROUTE_PRF                   (26)
#define ROUTE_POLICIA_FEDERAL       (27)
#define ROUTE_POLICIA_CIVIL         (28)
#define ROUTE_POLICIA_PENAL         (29)
#define ROUTE_DETRAN                (30)
#define ROUTE_PREFEITURA            (31)
#define ROUTE_BANKER                (32)
#define ROUTE_REALTOR               (33)
#define ROUTE_ACCOUNTANT            (34)
#define ROUTE_TEACHER               (35)
#define ROUTE_PHARMACY              (36)
#define ROUTE_SOCIAL                (37)
#define ROUTE_FORENSIC              (38)
#define ROUTE_MARKET_STAFF          (39)
#define ROUTE_BARTENDER             (40)
#define ROUTE_BAKER_PIZZA           (41)
#define ROUTE_HOTEL_RECEPTION       (42)
#define ROUTE_TOW_DRIVER            (43)
#define ROUTE_APP_DRIVER            (44)
#define ROUTE_PLUMBER               (45)
#define ROUTE_GARDENER              (46)
#define ROUTE_CARETAKER             (47)
#define ROUTE_FACTORY               (48)
#define ROUTE_PROSECUTOR            (49)
#define ROUTE_PUBLIC_DEFENDER       (50)
#define ROUTE_COURT_OFFICER         (51)
#define ROUTE_CLERK                 (52)

enum eJobData
{
    jobId,
    jobName[32],
    jobDescription[96],
    jobLocation,
    jobVehicleModel,
    jobRequirement,
    jobSkin,
    jobPay,
    jobBonus,
    jobRoute
}

new gJobs[][eJobData] =
{
    { JOB_ENTREGADOR, "Entregador", "Coleta pacotes, dirige ate clientes e recebe por entrega concluida.", LOCATION_JOB_ENTREGADOR, 482, JOB_REQ_CNH, 155, 370, 760, ROUTE_DELIVERY },
    { JOB_LIXEIRO, "Lixeiro/Coletor", "Faz coleta urbana em pontos de lixo e encerra o turno na base.", LOCATION_JOB_LIXEIRO, 408, JOB_REQ_CNH, 16, 390, 0, ROUTE_GARBAGE },
    { JOB_MOTORISTA_ONIBUS, "Motorista de Onibus", "Cumpre linha de transporte publico com paradas marcadas.", LOCATION_JOB_MOTORISTA, 431, JOB_REQ_CNH, 255, 750, 0, ROUTE_BUS },
    { JOB_TAXISTA, "Taxista", "Atende corridas pela cidade usando taxi de servico.", LOCATION_JOB_TAXISTA, 438, JOB_REQ_CNH, 255, 620, 860, ROUTE_TAXI },
    { JOB_CAMINHONEIRO, "Caminhoneiro", "Transporta cargas entre depositos e areas industriais.", LOCATION_JOB_CAMINHONEIRO, 403, JOB_REQ_HEAVY, 260, 640, 1280, ROUTE_TRUCK },
    { JOB_MECANICO, "Mecanico", "Atende chamados, repara veiculos e reboca carros com problema.", LOCATION_JOB_MECANICO, 525, JOB_REQ_NONE, 50, 590, 980, ROUTE_MECHANIC },
    { JOB_FRENTISTA, "Frentista", "Atende bombas, lava para-brisas e abastece veiculos.", LOCATION_JOB_FRENTISTA, 0, JOB_REQ_NONE, 50, 360, 620, ROUTE_GAS },
    { JOB_POLICIAL, "Policial", "Patrulha, aplica multas e conduz suspeitos ate a delegacia.", LOCATION_JOB_POLICIAL, 596, JOB_REQ_POLICE, 280, 920, 0, ROUTE_POLICE },
    { JOB_MEDICO, "Medico/Enfermeiro", "Atende pacientes, presta primeiros socorros e trabalha no hospital.", LOCATION_JOB_MEDICO, 416, JOB_REQ_MEDICAL, 274, 1150, 0, ROUTE_MEDIC },
    { JOB_BOMBEIRO, "Bombeiro", "Responde ocorrencias, combate focos de incendio e resgata civis.", LOCATION_JOB_BOMBEIRO, 407, JOB_REQ_CNH, 277, 760, 0, ROUTE_FIRE },
    { JOB_SEGURANCA, "Seguranca", "Faz ronda preventiva em predios, bancos e areas publicas.", LOCATION_JOB_SEGURANCA, 490, JOB_REQ_NONE, 163, 520, 830, ROUTE_SECURITY },
    { JOB_CARTEIRO, "Carteiro", "Entrega cartas e encomendas leves em varios bairros.", LOCATION_JOB_CARTEIRO, 499, JOB_REQ_CNH, 71, 430, 0, ROUTE_MAIL },
    { JOB_MOTOBOY, "Motoboy", "Realiza entregas rapidas de comida e documentos.", LOCATION_JOB_MOTOBOY, 448, JOB_REQ_CNH, 155, 360, 780, ROUTE_MOTOBOY },
    { JOB_PESCADOR, "Pescador", "Trabalha no pier, coleta pescado e entrega no mercado.", LOCATION_JOB_PESCADOR, 0, JOB_REQ_NONE, 35, 430, 820, ROUTE_FISHING },
    { JOB_AGRICULTOR, "Agricultor", "Planta, colhe e transporta producao rural.", LOCATION_JOB_AGRICULTOR, 531, JOB_REQ_NONE, 158, 450, 900, ROUTE_FARM },
    { JOB_MINERADOR, "Minerador", "Extrai minerio, processa carga e entrega no deposito.", LOCATION_JOB_MINERADOR, 455, JOB_REQ_NONE, 27, 670, 1280, ROUTE_MINE },
    { JOB_PEDREIRO, "Pedreiro", "Leva materiais, executa obra e conclui etapas de construcao.", LOCATION_JOB_PEDREIRO, 498, JOB_REQ_NONE, 16, 500, 960, ROUTE_BUILD },
    { JOB_GARCOM, "Garcom", "Atende mesas, entrega pedidos e organiza o salao.", LOCATION_JOB_GARCOM, 0, JOB_REQ_NONE, 171, 330, 620, ROUTE_WAITER },
    { JOB_COZINHEIRO, "Cozinheiro", "Prepara pedidos, controla ingredientes e finaliza pratos.", LOCATION_JOB_COZINHEIRO, 0, JOB_REQ_NONE, 155, 420, 780, ROUTE_COOK },
    { JOB_VENDEDOR, "Vendedor", "Atende clientes, organiza estoque e fecha vendas.", LOCATION_JOB_VENDEDOR, 0, JOB_REQ_NONE, 29, 400, 760, ROUTE_SELLER },
    { JOB_JORNALISTA, "Jornalista", "Apura noticias, entrevista fontes e publica boletins.", LOCATION_JOB_JORNALISTA, 582, JOB_REQ_CNH, 188, 870, 1180, ROUTE_NEWS },
    { JOB_ADVOGADO, "Advogado", "Atende clientes, prepara defesa e acompanha audiencias.", LOCATION_JOB_ADVOGADO, 0, JOB_REQ_OAB, 186, 840, 1250, ROUTE_LAWYER },
    { JOB_JUIZ, "Juiz", "Conduz audiencias, analisa processos e profere decisoes.", LOCATION_JOB_JUIZ, 0, JOB_REQ_PUBLIC, 187, 1300, 0, ROUTE_JUDGE },
    { JOB_MOTORISTA_AMBULANCIA, "Motorista de Ambulancia", "Conduz ambulancia, busca pacientes e apoia o hospital.", LOCATION_JOB_AMBULANCIA, 416, JOB_REQ_CNH | JOB_REQ_MEDICAL, 275, 740, 0, ROUTE_AMBULANCE },
    { JOB_TECNICO, "Tecnico Internet/Energia", "Atende chamados de poste, caixa e residencia.", LOCATION_JOB_TECNICO, 552, JOB_REQ_CNH, 50, 540, 980, ROUTE_TECH },
    { JOB_PRF, "PRF", "Fiscaliza rodovias, faz blitz e patrulha acessos de Los Santos.", LOCATION_JOB_PRF, 599, JOB_REQ_CNH | JOB_REQ_POLICE, 288, 1050, 0, ROUTE_PRF },
    { JOB_POLICIA_FEDERAL, "Policia Federal", "Atua em investigacoes federais, mandados e operacoes especiais.", LOCATION_JOB_POLICIA_FEDERAL, 490, JOB_REQ_POLICE, 286, 1200, 0, ROUTE_POLICIA_FEDERAL },
    { JOB_POLICIA_CIVIL, "Policia Civil", "Investiga ocorrencias, coleta provas e conduz suspeitos.", LOCATION_JOB_POLICIA_CIVIL, 596, JOB_REQ_POLICE, 285, 980, 0, ROUTE_POLICIA_CIVIL },
    { JOB_POLICIA_PENAL, "Policia Penal", "Cuida da custodia, escolta presos e apoio ao sistema penal.", LOCATION_JOB_POLICIA_PENAL, 427, JOB_REQ_POLICE, 287, 900, 0, ROUTE_POLICIA_PENAL },
    { JOB_AGENTE_DETRAN, "Agente DETRAN", "Faz vistoria, apoio ao patio e blitz documental de veiculos.", LOCATION_DETRAN, 525, JOB_REQ_CNH | JOB_REQ_PUBLIC, 50, 760, 0, ROUTE_DETRAN },
    { JOB_FUNCIONARIO_PREFEITURA, "Funcionario Prefeitura", "Atende cidadaos, confere documentos e fiscaliza alvaras urbanos.", LOCATION_PREFEITURA, 0, JOB_REQ_PUBLIC, 17, 680, 0, ROUTE_PREFEITURA },
    { JOB_BANCARIO, "Bancario", "Atende contas, confere credito e organiza pendencias financeiras.", LOCATION_BANCO, 0, JOB_REQ_NONE, 187, 720, 900, ROUTE_BANKER },
    { JOB_CORRETOR_IMOVEIS, "Corretor de Imoveis", "Faz visitas, avalia imoveis e encaminha contratos de locacao e venda.", LOCATION_CONCESSIONARIA, 405, JOB_REQ_CNH, 240, 760, 1100, ROUTE_REALTOR },
    { JOB_CONTADOR, "Contador", "Confere impostos, boletos, folha e caixa de empresas.", LOCATION_BANCO, 0, JOB_REQ_NONE, 171, 760, 980, ROUTE_ACCOUNTANT },
    { JOB_PROFESSOR, "Professor", "Organiza aulas, orienta alunos e apoia projetos civicos.", LOCATION_PREFEITURA, 0, JOB_REQ_PUBLIC, 187, 720, 0, ROUTE_TEACHER },
    { JOB_FARMACEUTICO, "Farmaceutico", "Controla estoque de medicamentos, receitas e atendimento de farmacia.", LOCATION_HOSPITAL, 0, JOB_REQ_MEDICAL, 274, 700, 820, ROUTE_PHARMACY },
    { JOB_ASSISTENTE_SOCIAL, "Assistente Social", "Atende familias, encaminha beneficios e acompanha casos vulneraveis.", LOCATION_PREFEITURA, 0, JOB_REQ_PUBLIC, 141, 740, 0, ROUTE_SOCIAL },
    { JOB_PERITO_CRIMINAL, "Perito Criminal", "Coleta evidencias, registra laudos e apoia investigacoes criminais.", LOCATION_JOB_POLICIA_CIVIL, 596, JOB_REQ_POLICE, 285, 980, 0, ROUTE_FORENSIC },
    { JOB_CAIXA_REPOSITOR, "Caixa/Repositor", "Atende caixa, repoe gondolas e organiza estoque de mercado.", LOCATION_JOB_VENDEDOR, 0, JOB_REQ_NONE, 29, 390, 620, ROUTE_MARKET_STAFF },
    { JOB_BARTENDER, "Bartender", "Prepara bebidas, atende balcao e fecha pedidos de bar.", LOCATION_JOB_GARCOM, 0, JOB_REQ_NONE, 171, 400, 650, ROUTE_BARTENDER },
    { JOB_PADEIRO_PIZZAIOLO, "Padeiro/Pizzaiolo", "Prepara massas, fornadas e pedidos de padaria ou pizzaria.", LOCATION_JOB_COZINHEIRO, 0, JOB_REQ_NONE, 155, 430, 700, ROUTE_BAKER_PIZZA },
    { JOB_RECEPCIONISTA_HOTEL, "Recepcionista Hotel", "Faz check-in, reservas e apoio a hospedes.", LOCATION_PREFEITURA, 0, JOB_REQ_NONE, 141, 410, 620, ROUTE_HOTEL_RECEPTION },
    { JOB_GUINCHEIRO, "Guincheiro", "Atende reboques, remove veiculos e leva ao patio correto.", LOCATION_JOB_MECANICO, 525, JOB_REQ_CNH, 50, 520, 900, ROUTE_TOW_DRIVER },
    { JOB_MOTORISTA_APP, "Motorista de App", "Aceita corridas por aplicativo e atende passageiros pela cidade.", LOCATION_JOB_TAXISTA, 438, JOB_REQ_CNH, 255, 510, 860, ROUTE_APP_DRIVER },
    { JOB_ENCANADOR, "Encanador", "Atende vazamentos, manutencao hidraulica e reparos residenciais.", LOCATION_JOB_TECNICO, 552, JOB_REQ_NONE, 50, 520, 820, ROUTE_PLUMBER },
    { JOB_JARDINEIRO, "Jardineiro", "Cuida de pracas, jardins privados e paisagismo urbano.", LOCATION_PREFEITURA, 531, JOB_REQ_NONE, 158, 390, 620, ROUTE_GARDENER },
    { JOB_ZELADOR, "Zelador", "Faz manutencao predial, limpeza leve e controle de acesso.", LOCATION_PREFEITURA, 0, JOB_REQ_NONE, 16, 380, 600, ROUTE_CARETAKER },
    { JOB_OPERADOR_FABRICA, "Operador Fabrica", "Opera linha industrial, controla materiais e despacha lotes.", LOCATION_JOB_CAMINHONEIRO, 455, JOB_REQ_NONE, 260, 540, 900, ROUTE_FACTORY },
    { JOB_PROMOTOR, "Promotor", "Analisa acusacoes, acompanha casos e orienta a justica publica.", LOCATION_PREFEITURA, 0, JOB_REQ_PUBLIC | JOB_REQ_OAB, 187, 1250, 0, ROUTE_PROSECUTOR },
    { JOB_DEFENSOR_PUBLICO, "Defensor Publico", "Atende cidadaos, prepara defesa e acompanha audiencias publicas.", LOCATION_PREFEITURA, 0, JOB_REQ_PUBLIC | JOB_REQ_OAB, 186, 1050, 0, ROUTE_PUBLIC_DEFENDER },
    { JOB_OFICIAL_JUSTICA, "Oficial de Justica", "Cumpre intimacoes, entrega mandados e registra diligencias.", LOCATION_PREFEITURA, 0, JOB_REQ_PUBLIC, 17, 820, 0, ROUTE_COURT_OFFICER },
    { JOB_ESCRIVAO, "Escrivao", "Registra autos, organiza processos e apoia delegacia e forum.", LOCATION_JOB_POLICIA_CIVIL, 0, JOB_REQ_PUBLIC, 141, 760, 0, ROUTE_CLERK }
};

enum eWorkPoint
{
    pointRoute,
    pointName[32],
    Float:pointX,
    Float:pointY,
    Float:pointZ
}

new gWorkPoints[][eWorkPoint] =
{
    { ROUTE_DELIVERY, "Coleta Central", 2096.5660, -1806.2340, 13.5547 },
    { ROUTE_DELIVERY, "Cliente Idlewood", 2105.1094, -1806.5630, 13.5547 },
    { ROUTE_DELIVERY, "Posto Commerce", 1929.5778, -1776.3170, 13.5469 },
    { ROUTE_DELIVERY, "Prefeitura", 1481.0690, -1771.0450, 18.7958 },
    { ROUTE_DELIVERY, "Hospital", 1172.0360, -1323.5170, 15.4030 },
    { ROUTE_DELIVERY, "Delegacia", 1554.9530, -1675.6580, 16.1953 },

    { ROUTE_GARBAGE, "Lixeira Idlewood", 2210.4450, -1890.3380, 13.5547 },
    { ROUTE_GARBAGE, "Beco Commerce", 1819.6300, -1844.5200, 13.5781 },
    { ROUTE_GARBAGE, "Praca Pershing", 1487.2010, -1715.6060, 14.0469 },
    { ROUTE_GARBAGE, "Hospital", 1187.5230, -1335.2440, 13.5580 },
    { ROUTE_GARBAGE, "Aterro", 2197.1260, -1972.3190, 13.5580 },

    { ROUTE_BUS, "Unity Station", 1808.7130, -1900.2240, 13.5748 },
    { ROUTE_BUS, "Commerce", 1672.4310, -1735.3150, 13.5469 },
    { ROUTE_BUS, "Prefeitura", 1478.4900, -1737.3720, 13.5469 },
    { ROUTE_BUS, "Hospital", 1181.0490, -1323.6420, 13.5720 },
    { ROUTE_BUS, "Idlewood", 1949.6720, -1758.5470, 13.3828 },
    { ROUTE_BUS, "Retorno Terminal", 1808.7130, -1900.2240, 13.5748 },

    { ROUTE_TAXI, "Passageiro Unity", 1774.7130, -1896.7740, 13.5625 },
    { ROUTE_TAXI, "Destino Banco", 1458.2380, -1012.9210, 26.8438 },
    { ROUTE_TAXI, "Passageiro Hospital", 1172.0360, -1323.5170, 15.4030 },
    { ROUTE_TAXI, "Destino Praia", 370.1690, -2046.7550, 7.8359 },
    { ROUTE_TAXI, "Retorno Ponto", 1774.7130, -1896.7740, 13.5625 },

    { ROUTE_TRUCK, "Deposito LS", 2451.8810, -2092.6350, 13.5469 },
    { ROUTE_TRUCK, "Docas", 2755.9210, -2454.1780, 13.6430 },
    { ROUTE_TRUCK, "Industria", 2522.8390, -1524.3250, 24.0000 },
    { ROUTE_TRUCK, "Entrega Mercado", 1368.2140, -1279.8530, 13.5469 },
    { ROUTE_TRUCK, "Base", 2451.8810, -2092.6350, 13.5469 },

    { ROUTE_MECHANIC, "Chamado Oficina", 1041.8400, -1030.7100, 32.1016 },
    { ROUTE_MECHANIC, "Cliente Commerce", 1827.3770, -1682.3420, 13.5469 },
    { ROUTE_MECHANIC, "Cliente Idlewood", 2072.7100, -1831.4430, 13.5469 },
    { ROUTE_MECHANIC, "Retorno Oficina", 1041.8400, -1030.7100, 32.1016 },

    { ROUTE_GAS, "Bomba 1", 1929.5778, -1776.3170, 13.5469 },
    { ROUTE_GAS, "Calibragem", 1942.2160, -1772.9300, 13.5469 },
    { ROUTE_GAS, "Loja Conveniencia", 1937.3510, -1768.2030, 13.5469 },
    { ROUTE_GAS, "Bomba 2", 1916.9720, -1776.7210, 13.5469 },

    { ROUTE_POLICE, "Saida Delegacia", 1569.4630, -1690.3390, 5.8906 },
    { ROUTE_POLICE, "Patrulha Commerce", 1642.0890, -1715.3920, 13.5469 },
    { ROUTE_POLICE, "Patrulha Idlewood", 1955.8470, -1768.6200, 13.5469 },
    { ROUTE_POLICE, "Ocorrencia Hospital", 1172.0360, -1323.5170, 15.4030 },
    { ROUTE_POLICE, "Retorno Delegacia", 1569.4630, -1690.3390, 5.8906 },

    { ROUTE_MEDIC, "Triagem", 1184.8060, -1326.9100, 13.5748 },
    { ROUTE_MEDIC, "Paciente Commerce", 1667.9820, -1746.3280, 13.5469 },
    { ROUTE_MEDIC, "Paciente Idlewood", 2055.5930, -1772.3290, 13.5469 },
    { ROUTE_MEDIC, "Retorno Hospital", 1184.8060, -1326.9100, 13.5748 },

    { ROUTE_FIRE, "Base Bombeiros", 1759.3640, -1454.2280, 13.5313 },
    { ROUTE_FIRE, "Foco de Incendio", 1835.1220, -1413.9110, 13.6016 },
    { ROUTE_FIRE, "Resgate Predio", 1544.1340, -1353.0070, 329.4745 },
    { ROUTE_FIRE, "Retorno Base", 1759.3640, -1454.2280, 13.5313 },

    { ROUTE_SECURITY, "Entrada Predio", 1518.4150, -1675.6200, 14.0469 },
    { ROUTE_SECURITY, "Ronda Banco", 1460.8250, -1011.4090, 26.8438 },
    { ROUTE_SECURITY, "Ronda Prefeitura", 1481.0690, -1771.0450, 18.7958 },
    { ROUTE_SECURITY, "Relatorio Base", 1518.4150, -1675.6200, 14.0469 },

    { ROUTE_MAIL, "Agencia Correios", 1117.5850, -1793.3430, 16.5938 },
    { ROUTE_MAIL, "Casa 1", 1279.9810, -1810.5170, 13.3828 },
    { ROUTE_MAIL, "Casa 2", 1514.2100, -1456.8430, 14.2031 },
    { ROUTE_MAIL, "Comercio", 1836.8150, -1682.5210, 13.3320 },
    { ROUTE_MAIL, "Retorno Agencia", 1117.5850, -1793.3430, 16.5938 },

    { ROUTE_MOTOBOY, "Pizzaria", 2122.5470, -1784.3560, 13.5547 },
    { ROUTE_MOTOBOY, "Cliente 1", 1985.3110, -1718.2740, 17.0300 },
    { ROUTE_MOTOBOY, "Cliente 2", 1695.5020, -2125.5850, 13.5469 },
    { ROUTE_MOTOBOY, "Cliente 3", 1179.7890, -1610.3810, 13.9450 },
    { ROUTE_MOTOBOY, "Retorno Pizzaria", 2122.5470, -1784.3560, 13.5547 },

    { ROUTE_FISHING, "Pier", 389.8040, -2088.7880, 7.8359 },
    { ROUTE_FISHING, "Ponto de Pesca", 347.0460, -2088.1230, 7.8359 },
    { ROUTE_FISHING, "Caixas de Gelo", 379.4830, -2055.9240, 7.8359 },
    { ROUTE_FISHING, "Entrega Mercado", 1368.2140, -1279.8530, 13.5469 },

    { ROUTE_FARM, "Celeiro", -383.2300, -1438.5440, 25.7266 },
    { ROUTE_FARM, "Plantio", -420.3790, -1412.2120, 21.9844 },
    { ROUTE_FARM, "Colheita", -469.1880, -1385.2330, 16.3750 },
    { ROUTE_FARM, "Entrega Rural", -383.2300, -1438.5440, 25.7266 },

    { ROUTE_MINE, "Entrada Mina", 587.6740, 867.0870, -42.4973 },
    { ROUTE_MINE, "Extracao", 499.4010, 884.8120, -29.1390 },
    { ROUTE_MINE, "Britagem", 593.7820, 923.9440, -38.1094 },
    { ROUTE_MINE, "Deposito Minerio", 670.4060, 826.1770, -39.0078 },

    { ROUTE_BUILD, "Canteiro", 2522.4880, -1275.5900, 34.9453 },
    { ROUTE_BUILD, "Cimento", 2496.2800, -1250.8720, 34.8516 },
    { ROUTE_BUILD, "Alvenaria", 2549.7750, -1284.2940, 50.8570 },
    { ROUTE_BUILD, "Relatorio Obra", 2522.4880, -1275.5900, 34.9453 },

    { ROUTE_WAITER, "Balcao", 1199.1260, -918.1780, 43.1230 },
    { ROUTE_WAITER, "Mesa 1", 1210.3280, -908.4720, 42.9240 },
    { ROUTE_WAITER, "Mesa 2", 1203.1100, -894.9020, 42.9200 },
    { ROUTE_WAITER, "Caixa", 1199.1260, -918.1780, 43.1230 },

    { ROUTE_COOK, "Cozinha", 928.5490, -1352.9180, 13.3438 },
    { ROUTE_COOK, "Ingredientes", 934.7100, -1360.4230, 13.3438 },
    { ROUTE_COOK, "Preparo", 944.8460, -1354.9540, 13.3438 },
    { ROUTE_COOK, "Entrega Balcao", 928.5490, -1352.9180, 13.3438 },

    { ROUTE_SELLER, "Balcao Loja", 1368.2140, -1279.8530, 13.5469 },
    { ROUTE_SELLER, "Estoque", 1352.3850, -1271.7350, 13.5469 },
    { ROUTE_SELLER, "Cliente", 1375.6200, -1292.1400, 13.5469 },
    { ROUTE_SELLER, "Caixa", 1368.2140, -1279.8530, 13.5469 },

    { ROUTE_NEWS, "Redacao", 740.4350, -1352.9400, 13.5000 },
    { ROUTE_NEWS, "Entrevista Prefeitura", 1481.0690, -1771.0450, 18.7958 },
    { ROUTE_NEWS, "Cobertura Hospital", 1172.0360, -1323.5170, 15.4030 },
    { ROUTE_NEWS, "Publicar Materia", 740.4350, -1352.9400, 13.5000 },

    { ROUTE_LAWYER, "Escritorio", 1474.6310, -1749.7340, 15.4453 },
    { ROUTE_LAWYER, "Cliente", 1455.2280, -1011.3370, 26.8438 },
    { ROUTE_LAWYER, "Audiencia", 1410.5250, -1701.1490, 13.5395 },
    { ROUTE_LAWYER, "Protocolo", 1474.6310, -1749.7340, 15.4453 },

    { ROUTE_JUDGE, "Gabinete", 1410.5250, -1701.1490, 13.5395 },
    { ROUTE_JUDGE, "Audiencia Civel", 1455.2280, -1011.3370, 26.8438 },
    { ROUTE_JUDGE, "Audiencia Criminal", 1554.9530, -1675.6580, 16.1953 },
    { ROUTE_JUDGE, "Decisao", 1410.5250, -1701.1490, 13.5395 },

    { ROUTE_AMBULANCE, "Base Ambulancia", 1177.9120, -1308.6220, 13.9688 },
    { ROUTE_AMBULANCE, "Chamado 1", 1836.8420, -1682.9120, 13.3320 },
    { ROUTE_AMBULANCE, "Chamado 2", 1954.2900, -1768.2090, 13.5469 },
    { ROUTE_AMBULANCE, "Retorno Hospital", 1177.9120, -1308.6220, 13.9688 },

    { ROUTE_TECH, "Central Tecnica", 2339.1560, -1182.0620, 27.9766 },
    { ROUTE_TECH, "Poste", 2260.4280, -1189.4820, 25.4766 },
    { ROUTE_TECH, "Caixa de Rua", 2172.6120, -1010.3270, 62.9610 },
    { ROUTE_TECH, "Cliente", 2090.8420, -1125.1270, 27.6899 },

    { ROUTE_PRF, "Posto PRF Rodovia LS", 1428.0861, -964.7896, 37.0835 },
    { ROUTE_PRF, "Aviso Posto PRF", 1422.9353, -952.1232, 36.1640 },
    { ROUTE_PRF, "Acesso Norte LS", 1296.7400, -920.4600, 39.5781 },
    { ROUTE_PRF, "Retorno Posto PRF", 1428.0861, -964.7896, 37.0835 },

    { ROUTE_POLICIA_FEDERAL, "QG Federal", 326.2891, -1515.4176, 36.0325 },
    { ROUTE_POLICIA_FEDERAL, "Operacao Banco", 1461.2980, -1011.5210, 26.8438 },
    { ROUTE_POLICIA_FEDERAL, "Mandado Prefeitura", 1481.0690, -1771.0450, 18.7958 },
    { ROUTE_POLICIA_FEDERAL, "Retorno Federal", 326.2891, -1515.4176, 36.0325 },

    { ROUTE_POLICIA_CIVIL, "Delegacia Civil", 285.8905, -1601.2700, 32.8313 },
    { ROUTE_POLICIA_CIVIL, "Pericia Commerce", 1642.0890, -1715.3920, 13.5469 },
    { ROUTE_POLICIA_CIVIL, "Investigacao Idlewood", 1955.8470, -1768.6200, 13.5469 },
    { ROUTE_POLICIA_CIVIL, "Retorno Civil", 285.8905, -1601.2700, 32.8313 },

    { ROUTE_POLICIA_PENAL, "QG Penal", 1595.8700, -1638.2200, 13.5469 },
    { ROUTE_POLICIA_PENAL, "Escolta Patio", 1591.8500, -1608.4100, 13.3828 },
    { ROUTE_POLICIA_PENAL, "Custodia Delegacia", 1554.9530, -1675.6580, 16.1953 },
    { ROUTE_POLICIA_PENAL, "Retorno Penal", 1595.8700, -1638.2200, 13.5469 },

    { ROUTE_DETRAN, "Guiche DETRAN", 1034.1500, -1027.6200, 32.1016 },
    { ROUTE_DETRAN, "Vistoria Veiculo", 1041.8400, -1030.7100, 32.1016 },
    { ROUTE_DETRAN, "Patio Municipal", 1591.8500, -1608.4100, 13.3828 },
    { ROUTE_DETRAN, "Retorno DETRAN", 1034.1500, -1027.6200, 32.1016 },

    { ROUTE_PREFEITURA, "Guiche Prefeitura", 1481.0690, -1771.0450, 18.7958 },
    { ROUTE_PREFEITURA, "Fiscalizar Alvara", 1368.2140, -1279.8530, 13.5469 },
    { ROUTE_PREFEITURA, "Protocolo Banco", 1461.2980, -1011.5210, 26.8438 },
    { ROUTE_PREFEITURA, "Retorno Prefeitura", 1481.0690, -1771.0450, 18.7958 },

    { ROUTE_BANKER, "Mesa Banco", 1461.2980, -1011.5210, 26.8438 },
    { ROUTE_BANKER, "ATM Prefeitura", 1486.5000, -1771.4000, 18.7958 },
    { ROUTE_BANKER, "ATM Hospital", 1177.0000, -1328.0000, 14.0000 },
    { ROUTE_BANKER, "Retorno Banco", 1461.2980, -1011.5210, 26.8438 },

    { ROUTE_REALTOR, "Escritorio Imobiliario", 2131.8490, -1149.3340, 24.1232 },
    { ROUTE_REALTOR, "Visita Residencial", 1985.3110, -1718.2740, 17.0300 },
    { ROUTE_REALTOR, "Contrato Prefeitura", 1474.6310, -1749.7340, 15.4453 },
    { ROUTE_REALTOR, "Retorno Imobiliaria", 2131.8490, -1149.3340, 24.1232 },

    { ROUTE_ACCOUNTANT, "Mesa Contabil", 1461.2980, -1011.5210, 26.8438 },
    { ROUTE_ACCOUNTANT, "Empresa Cliente", 1368.2140, -1279.8530, 13.5469 },
    { ROUTE_ACCOUNTANT, "Protocolo Fiscal", 1481.0690, -1771.0450, 18.7958 },
    { ROUTE_ACCOUNTANT, "Retorno Contabil", 1461.2980, -1011.5210, 26.8438 },

    { ROUTE_TEACHER, "Secretaria Escolar", 1481.0690, -1771.0450, 18.7958 },
    { ROUTE_TEACHER, "Aula Comunitaria", 1199.1260, -918.1780, 43.1230 },
    { ROUTE_TEACHER, "Projeto Civico", 1172.0360, -1323.5170, 15.4030 },
    { ROUTE_TEACHER, "Retorno Secretaria", 1481.0690, -1771.0450, 18.7958 },

    { ROUTE_PHARMACY, "Farmacia Hospitalar", 1172.0360, -1323.5170, 15.4030 },
    { ROUTE_PHARMACY, "Estoque Medicamentos", 1184.8060, -1326.9100, 13.5748 },
    { ROUTE_PHARMACY, "Entrega Conveniencia", 1836.8150, -1682.5210, 13.3320 },
    { ROUTE_PHARMACY, "Retorno Farmacia", 1172.0360, -1323.5170, 15.4030 },

    { ROUTE_SOCIAL, "Atendimento Social", 1481.0690, -1771.0450, 18.7958 },
    { ROUTE_SOCIAL, "Visita Familiar", 1985.3110, -1718.2740, 17.0300 },
    { ROUTE_SOCIAL, "Encaminhar Hospital", 1172.0360, -1323.5170, 15.4030 },
    { ROUTE_SOCIAL, "Retorno Social", 1481.0690, -1771.0450, 18.7958 },

    { ROUTE_FORENSIC, "Laboratorio Civil", 285.8905, -1601.2700, 32.8313 },
    { ROUTE_FORENSIC, "Coleta Evidencia", 1642.0890, -1715.3920, 13.5469 },
    { ROUTE_FORENSIC, "Laudo Hospital", 1172.0360, -1323.5170, 15.4030 },
    { ROUTE_FORENSIC, "Retorno Laboratorio", 285.8905, -1601.2700, 32.8313 },

    { ROUTE_MARKET_STAFF, "Balcao Mercado", 1368.2140, -1279.8530, 13.5469 },
    { ROUTE_MARKET_STAFF, "Estoque Mercado", 1379.4000, -1284.3000, 13.5469 },
    { ROUTE_MARKET_STAFF, "Gondolas", 1357.7000, -1274.8000, 13.5469 },
    { ROUTE_MARKET_STAFF, "Caixa", 1368.2140, -1279.8530, 13.5469 },

    { ROUTE_BARTENDER, "Balcao Bar", 1836.8150, -1682.5210, 13.3320 },
    { ROUTE_BARTENDER, "Mesa Cliente", 1827.3770, -1682.3420, 13.5469 },
    { ROUTE_BARTENDER, "Estoque Bebidas", 1819.6300, -1844.5200, 13.5781 },
    { ROUTE_BARTENDER, "Retorno Balcao", 1836.8150, -1682.5210, 13.3320 },

    { ROUTE_BAKER_PIZZA, "Forno", 2122.5470, -1784.3560, 13.5547 },
    { ROUTE_BAKER_PIZZA, "Entrega Pedido", 1985.3110, -1718.2740, 17.0300 },
    { ROUTE_BAKER_PIZZA, "Compra Ingrediente", 1368.2140, -1279.8530, 13.5469 },
    { ROUTE_BAKER_PIZZA, "Retorno Cozinha", 2122.5470, -1784.3560, 13.5547 },

    { ROUTE_HOTEL_RECEPTION, "Recepcao Hotel", 1481.0690, -1771.0450, 18.7958 },
    { ROUTE_HOTEL_RECEPTION, "Quarto Hospede", 1509.5160, -1710.8160, 14.0469 },
    { ROUTE_HOTEL_RECEPTION, "Taxi Hospede", 1774.7130, -1896.7740, 13.5625 },
    { ROUTE_HOTEL_RECEPTION, "Retorno Recepcao", 1481.0690, -1771.0450, 18.7958 },

    { ROUTE_TOW_DRIVER, "Base Guincho", 1041.8400, -1030.7100, 32.1016 },
    { ROUTE_TOW_DRIVER, "Veiculo Quebrado", 2072.7100, -1831.4430, 13.5469 },
    { ROUTE_TOW_DRIVER, "Patio Municipal", 1591.8500, -1608.4100, 13.3828 },
    { ROUTE_TOW_DRIVER, "Retorno Base", 1041.8400, -1030.7100, 32.1016 },

    { ROUTE_APP_DRIVER, "Chamada App", 1774.7130, -1896.7740, 13.5625 },
    { ROUTE_APP_DRIVER, "Passageiro App", 1172.0360, -1323.5170, 15.4030 },
    { ROUTE_APP_DRIVER, "Destino App", 1458.2380, -1012.9210, 26.8438 },
    { ROUTE_APP_DRIVER, "Nova Chamada", 1774.7130, -1896.7740, 13.5625 },

    { ROUTE_PLUMBER, "Central Manutencao", 2172.6120, -1010.3270, 62.9610 },
    { ROUTE_PLUMBER, "Vazamento Casa", 1985.3110, -1718.2740, 17.0300 },
    { ROUTE_PLUMBER, "Registro Agua", 1481.0690, -1771.0450, 18.7958 },
    { ROUTE_PLUMBER, "Retorno Central", 2172.6120, -1010.3270, 62.9610 },

    { ROUTE_GARDENER, "Deposito Jardim", -383.2300, -1438.5440, 25.7266 },
    { ROUTE_GARDENER, "Praca Pershing", 1487.2010, -1715.6060, 14.0469 },
    { ROUTE_GARDENER, "Jardim Residencial", 1985.3110, -1718.2740, 17.0300 },
    { ROUTE_GARDENER, "Retorno Deposito", -383.2300, -1438.5440, 25.7266 },

    { ROUTE_CARETAKER, "Portaria", 1518.4150, -1675.6200, 14.0469 },
    { ROUTE_CARETAKER, "Manutencao Predio", 1544.1340, -1353.0070, 13.5469 },
    { ROUTE_CARETAKER, "Relatorio Sindico", 1481.0690, -1771.0450, 18.7958 },
    { ROUTE_CARETAKER, "Retorno Portaria", 1518.4150, -1675.6200, 14.0469 },

    { ROUTE_FACTORY, "Linha Fabrica", 2522.8390, -1524.3250, 24.0000 },
    { ROUTE_FACTORY, "Estoque Materia", 2451.8810, -2092.6350, 13.5469 },
    { ROUTE_FACTORY, "Despacho Lote", 2755.9210, -2454.1780, 13.6430 },
    { ROUTE_FACTORY, "Retorno Fabrica", 2522.8390, -1524.3250, 24.0000 },

    { ROUTE_PROSECUTOR, "Gabinete MP", 1481.0690, -1771.0450, 18.7958 },
    { ROUTE_PROSECUTOR, "Analise Processo", 1554.9530, -1675.6580, 16.1953 },
    { ROUTE_PROSECUTOR, "Audiencia", 1474.6310, -1749.7340, 15.4453 },
    { ROUTE_PROSECUTOR, "Retorno Gabinete", 1481.0690, -1771.0450, 18.7958 },

    { ROUTE_PUBLIC_DEFENDER, "Defensoria", 1481.0690, -1771.0450, 18.7958 },
    { ROUTE_PUBLIC_DEFENDER, "Atendimento Cidadao", 1172.0360, -1323.5170, 15.4030 },
    { ROUTE_PUBLIC_DEFENDER, "Audiencia Defesa", 1474.6310, -1749.7340, 15.4453 },
    { ROUTE_PUBLIC_DEFENDER, "Retorno Defensoria", 1481.0690, -1771.0450, 18.7958 },

    { ROUTE_COURT_OFFICER, "Forum", 1481.0690, -1771.0450, 18.7958 },
    { ROUTE_COURT_OFFICER, "Entrega Intimacao", 1985.3110, -1718.2740, 17.0300 },
    { ROUTE_COURT_OFFICER, "Mandado Delegacia", 1554.9530, -1675.6580, 16.1953 },
    { ROUTE_COURT_OFFICER, "Retorno Forum", 1481.0690, -1771.0450, 18.7958 },

    { ROUTE_CLERK, "Cartorio Policial", 285.8905, -1601.2700, 32.8313 },
    { ROUTE_CLERK, "Registro BO", 1554.9530, -1675.6580, 16.1953 },
    { ROUTE_CLERK, "Arquivo Forum", 1481.0690, -1771.0450, 18.7958 },
    { ROUTE_CLERK, "Retorno Cartorio", 285.8905, -1601.2700, 32.8313 }
};

new gWorkActive[MAX_PLAYERS];
new gWorkStep[MAX_PLAYERS];
new gWorkRoute[MAX_PLAYERS];
new gWorkVehicle[MAX_PLAYERS];
new gWorkVehicleFromFleet[MAX_PLAYERS];
new gWorkOldSkin[MAX_PLAYERS];
new gWorkUniformActive[MAX_PLAYERS];
new gWorkLastTaskTick[MAX_PLAYERS];
new gWorkCheckpointTick[MAX_PLAYERS];
new gWorkRouteStreak[MAX_PLAYERS];
new gWorkStreakJob[MAX_PLAYERS];
new gWorkSpecialMode[MAX_PLAYERS];
new gWorkRouteEvent[MAX_PLAYERS];
new gWorkRouteTargetSteps[MAX_PLAYERS];
new gWorkRouteSize[MAX_PLAYERS];
new gWorkRouteStartTick[MAX_PLAYERS];
new gWorkRouteDeadlineMs[MAX_PLAYERS];
new gDeliveryPackageType[MAX_PLAYERS];
new gDeliveryWrongAddress[MAX_PLAYERS];
new gDeliveryWrongResolved[MAX_PLAYERS];
new Float:gDeliveryVehicleHealthStart[MAX_PLAYERS];
new gDeliveryDailyDay[MAX_PLAYERS];
new gDeliveryDailyCompleted[MAX_PLAYERS];
new gDeliveryDailyRatingTotal[MAX_PLAYERS];
new gDeliveryDailyBestStreak[MAX_PLAYERS];
new gTaxiPassengerType[MAX_PLAYERS];
new gTaxiPassengerCanceled[MAX_PLAYERS];
new Float:gTaxiVehicleHealthStart[MAX_PLAYERS];
new gTaxiDailyDay[MAX_PLAYERS];
new gTaxiDailyCompleted[MAX_PLAYERS];
new gTaxiDailyRatingTotal[MAX_PLAYERS];
new gTaxiDailyBestStreak[MAX_PLAYERS];
new gMechanicDiagnosis[MAX_PLAYERS];
new gMechanicPartsUsed[MAX_PLAYERS];
new gMechanicTowRequired[MAX_PLAYERS];
new gMechanicQuote[MAX_PLAYERS];
new gMechanicDailyDay[MAX_PLAYERS];
new gMechanicDailyCompleted[MAX_PLAYERS];
new gMechanicDailyRatingTotal[MAX_PLAYERS];
new gMechanicDailyBestStreak[MAX_PLAYERS];
new gCargoType[MAX_PLAYERS];
new gCargoInvoice[MAX_PLAYERS];
new gCargoDocStatus[MAX_PLAYERS];
new gCargoValue[MAX_PLAYERS];
new gCargoIllegal[MAX_PLAYERS];
new gJobQuickServiceTick[MAX_PLAYERS];
new gJobRewardDay[MAX_PLAYERS];
new gJobRewardCashToday[MAX_PLAYERS];
new gJobRewardXpToday[MAX_PLAYERS];
new gJobRewardBurstTick[MAX_PLAYERS];
new gJobRewardBurstCount[MAX_PLAYERS];
new gPlayerDialogJob[MAX_PLAYERS];
new gPlayerJobSelectIndex[MAX_PLAYERS][JOB_SELECT_MAX_ROWS];
new gPlayerJobSelectCount[MAX_PLAYERS];
new gPlayerJobWorkActions[MAX_PLAYERS][JOB_WORK_DIALOG_ACTIONS];
new gPlayerJobWorkActionCount[MAX_PLAYERS];
new gPlayerTrafficFineTarget[MAX_PLAYERS];
new gPlayerTrafficFineItems[MAX_PLAYERS][JOB_TRAFFIC_FINE_DIALOG_ACTIONS];
new gPlayerTrafficFineCount[MAX_PLAYERS];
new gPlayerTrafficFinePage[MAX_PLAYERS];
new gPlayerJobXP[MAX_PLAYERS][JOB_MAX_ID + 1];
new gPlayerJobLevel[MAX_PLAYERS][JOB_MAX_ID + 1];

new gJobVehicleCount;
new gJobVehicleId[MAX_JOB_CONFIG_VEHICLES];
new gJobVehicleJob[MAX_JOB_CONFIG_VEHICLES];
new gJobVehicleModel[MAX_JOB_CONFIG_VEHICLES];
new Float:gJobVehicleX[MAX_JOB_CONFIG_VEHICLES];
new Float:gJobVehicleY[MAX_JOB_CONFIG_VEHICLES];
new Float:gJobVehicleZ[MAX_JOB_CONFIG_VEHICLES];
new Float:gJobVehicleA[MAX_JOB_CONFIG_VEHICLES];
new gJobVehicleColor1[MAX_JOB_CONFIG_VEHICLES];
new gJobVehicleColor2[MAX_JOB_CONFIG_VEHICLES];
new gJobVehicleFuel[MAX_JOB_CONFIG_VEHICLES];
new gJobVehicleInterior[MAX_JOB_CONFIG_VEHICLES];
new gJobVehicleWorld[MAX_JOB_CONFIG_VEHICLES];
new gJobVehicleOwner[MAX_JOB_CONFIG_VEHICLES];
new gJobVehicleDataLine[MAX_JOB_CONFIG_VEHICLES];
new gPlayerJobVehicleGotoPage[MAX_PLAYERS];

stock ResetPlayerJobProgress(playerid)
{
    new jobid;

    for (jobid = 0; jobid <= JOB_MAX_ID; jobid++)
    {
        gPlayerJobXP[playerid][jobid] = 0;
        gPlayerJobLevel[playerid][jobid] = 1;
    }

    gWorkVehicleFromFleet[playerid] = 0;
    gWorkCheckpointTick[playerid] = 0;
    gWorkRouteStreak[playerid] = 0;
    gWorkStreakJob[playerid] = JOB_NONE;
    gWorkSpecialMode[playerid] = WORK_SPECIAL_NONE;
    gWorkRouteEvent[playerid] = 0;
    gWorkRouteTargetSteps[playerid] = 0;
    gWorkRouteSize[playerid] = WORK_ROUTE_MEDIUM;
    gWorkRouteStartTick[playerid] = 0;
    gWorkRouteDeadlineMs[playerid] = 0;
    gDeliveryPackageType[playerid] = DELIVERY_PACKAGE_COMMON;
    gDeliveryWrongAddress[playerid] = 0;
    gDeliveryWrongResolved[playerid] = 0;
    gDeliveryVehicleHealthStart[playerid] = 1000.0;
    gTaxiPassengerType[playerid] = TAXI_PASSENGER_NORMAL;
    gTaxiPassengerCanceled[playerid] = 0;
    gTaxiVehicleHealthStart[playerid] = 1000.0;
    gTaxiDailyDay[playerid] = 0;
    gTaxiDailyCompleted[playerid] = 0;
    gTaxiDailyRatingTotal[playerid] = 0;
    gTaxiDailyBestStreak[playerid] = 0;
    gMechanicDiagnosis[playerid] = MECHANIC_DIAG_ENGINE;
    gMechanicPartsUsed[playerid] = 0;
    gMechanicTowRequired[playerid] = 0;
    gMechanicQuote[playerid] = 0;
    gMechanicDailyDay[playerid] = 0;
    gMechanicDailyCompleted[playerid] = 0;
    gMechanicDailyRatingTotal[playerid] = 0;
    gMechanicDailyBestStreak[playerid] = 0;
    gCargoType[playerid] = CARGO_NONE;
    gCargoInvoice[playerid] = 0;
    gCargoDocStatus[playerid] = CARGO_DOC_NONE;
    gCargoValue[playerid] = 0;
    gCargoIllegal[playerid] = 0;
    gJobQuickServiceTick[playerid] = 0;
    gJobRewardDay[playerid] = 0;
    gJobRewardCashToday[playerid] = 0;
    gJobRewardXpToday[playerid] = 0;
    gJobRewardBurstTick[playerid] = 0;
    gJobRewardBurstCount[playerid] = 0;
    gPlayerJobSelectCount[playerid] = 0;
    gPlayerJobWorkActionCount[playerid] = 0;
    return 1;
}

stock Cargo_Reset(playerid)
{
    gCargoType[playerid] = CARGO_NONE;
    gCargoInvoice[playerid] = 0;
    gCargoDocStatus[playerid] = CARGO_DOC_NONE;
    gCargoValue[playerid] = 0;
    gCargoIllegal[playerid] = 0;
    return 1;
}

stock Cargo_GetName(cargoType, output[], size)
{
    switch (cargoType)
    {
        case CARGO_FOOD: format(output, size, "alimentos e mercado");
        case CARGO_FUEL: format(output, size, "combustivel regularizado");
        case CARGO_PARTS: format(output, size, "autopecas e pneus");
        case CARGO_MATERIALS: format(output, size, "material de construcao");
        case CARGO_ILLEGAL: format(output, size, "carga suspeita/ilegal");
        default: format(output, size, "sem carga fiscal");
    }
    return 1;
}

stock Cargo_GetDocName(docStatus, output[], size)
{
    switch (docStatus)
    {
        case CARGO_DOC_OK: format(output, size, "nota fiscal valida");
        case CARGO_DOC_EXPIRED: format(output, size, "nota fiscal vencida");
        default: format(output, size, "sem nota fiscal");
    }
    return 1;
}

stock Cargo_StartForTruck(playerid)
{
    new roll;
    new cargoName[40];
    new docName[32];
    new message[144];

    Cargo_Reset(playerid);
    roll = random(100);
    if (roll < CARGO_ILLEGAL_CHANCE)
    {
        gCargoType[playerid] = CARGO_ILLEGAL;
        gCargoIllegal[playerid] = 1;
        gCargoValue[playerid] = 16000 + random(26000);
        gCargoDocStatus[playerid] = random(2) ? CARGO_DOC_NONE : CARGO_DOC_EXPIRED;
    }
    else if (roll < 34)
    {
        gCargoType[playerid] = CARGO_FOOD;
        gCargoValue[playerid] = 4500 + random(6500);
    }
    else if (roll < 56)
    {
        gCargoType[playerid] = CARGO_FUEL;
        gCargoValue[playerid] = 9000 + random(9000);
    }
    else if (roll < 78)
    {
        gCargoType[playerid] = CARGO_PARTS;
        gCargoValue[playerid] = 6500 + random(8500);
    }
    else
    {
        gCargoType[playerid] = CARGO_MATERIALS;
        gCargoValue[playerid] = 5200 + random(7200);
    }

    if (!gCargoIllegal[playerid])
    {
        if (random(100) < CARGO_DOC_FAIL_CHANCE)
        {
            gCargoDocStatus[playerid] = random(2) ? CARGO_DOC_NONE : CARGO_DOC_EXPIRED;
        }
        else
        {
            gCargoDocStatus[playerid] = CARGO_DOC_OK;
        }
    }

    if (gCargoDocStatus[playerid] == CARGO_DOC_OK)
    {
        gCargoInvoice[playerid] = 100000 + random(900000);
    }

    Cargo_GetName(gCargoType[playerid], cargoName, sizeof(cargoName));
    Cargo_GetDocName(gCargoDocStatus[playerid], docName, sizeof(docName));
    format(message, sizeof(message), "Manifesto de carga: %s | valor $%d | %s. Consulte em /notafiscal.", cargoName, gCargoValue[playerid], docName);
    SendClientMessage(playerid, gCargoDocStatus[playerid] == CARGO_DOC_OK ? COLOR_GREEN : COLOR_ORANGE, message);
    if (gCargoDocStatus[playerid] != CARGO_DOC_OK)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Atencao: posto fiscal PRF pode multar/apreender cargas sem documentacao regular.");
    }
    return 1;
}

stock Cargo_IsTruckDriverCarrying(playerid)
{
    return (gWorkActive[playerid] && PlayerInfo[playerid][pJob] == JOB_CAMINHONEIRO && gCargoType[playerid] != CARGO_NONE);
}

stock Cargo_SendPlayerManifest(playerid)
{
    new cargoName[40];
    new docName[32];
    new message[144];

    if (!Cargo_IsTruckDriverCarrying(playerid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta transportando uma carga fiscal de caminhoneiro.");
        return 1;
    }

    Cargo_GetName(gCargoType[playerid], cargoName, sizeof(cargoName));
    Cargo_GetDocName(gCargoDocStatus[playerid], docName, sizeof(docName));
    format(message, sizeof(message), "Carga: %s | valor declarado $%d | documento: %s.", cargoName, gCargoValue[playerid], docName);
    SendClientMessage(playerid, COLOR_YELLOW, message);
    if (gCargoInvoice[playerid] > 0)
    {
        format(message, sizeof(message), "Nota fiscal: NF-e #%06d | apresente em posto fiscal se solicitado.", gCargoInvoice[playerid]);
        SendClientMessage(playerid, COLOR_YELLOW, message);
    }
    return 1;
}

stock Cargo_SendFiscalInfo(playerid, targetid)
{
    new cargoName[40];
    new docName[32];
    new message[144];

    if (!Cargo_IsTruckDriverCarrying(targetid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Carga fiscal: motorista sem manifesto ativo de caminhoneiro.");
        return 1;
    }

    Cargo_GetName(gCargoType[targetid], cargoName, sizeof(cargoName));
    Cargo_GetDocName(gCargoDocStatus[targetid], docName, sizeof(docName));
    format(message, sizeof(message), "Carga fiscal: %s | valor $%d | %s | NF-e #%06d.", cargoName, gCargoValue[targetid], docName, gCargoInvoice[targetid]);
    SendClientMessage(playerid, gCargoDocStatus[targetid] == CARGO_DOC_OK && !gCargoIllegal[targetid] ? COLOR_BLUE : COLOR_ORANGE, message);
    if (gCargoIllegal[targetid] || gCargoDocStatus[targetid] != CARGO_DOC_OK)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Irregularidade fiscal detectada. Use /fiscalizarcarga [id] para autuar; carga ilegal/sem NF pode ser apreendida.");
    }
    return 1;
}

stock Cargo_ApplyFiscalPenalty(playerid, targetid)
{
    new message[144];
    new cargoName[40];
    new amount;
    new points;
    new severity;
    new multiplier;
    new impoundRequired;

    if (!IsValidConnectedPlayer(targetid) || !PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador invalido.");
        return 0;
    }

    if (!Cargo_IsTruckDriverCarrying(targetid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "O motorista nao possui carga fiscal ativa de caminhoneiro.");
        return 0;
    }
    if (Account_IsNewcomerProtected(targetid))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Recem chegado protegido: apenas oriente o motorista, sem multa/apreensao ate o nivel 3.");
        SendClientMessage(targetid, COLOR_YELLOW, "Aviso educativo PRF: regularize carga e documentos. Multas liberam a partir do nivel 3.");
        return 0;
    }

    if (!gCargoIllegal[targetid] && gCargoDocStatus[targetid] == CARGO_DOC_OK)
    {
        SendClientMessage(playerid, COLOR_GREEN, "Carga regular. Nenhuma autuacao fiscal aplicada.");
        SendClientMessage(targetid, COLOR_GREEN, "PRF: carga e nota fiscal conferidas. Voce esta regular.");
        return 0;
    }

    severity = TRAFFIC_FINE_VERY_SERIOUS;
    multiplier = 1;
    if (gCargoIllegal[targetid])
    {
        multiplier = 5;
        impoundRequired = 1;
    }
    else if (gCargoDocStatus[targetid] == CARGO_DOC_NONE)
    {
        multiplier = 3;
        impoundRequired = 1;
    }
    amount = Cfg_TrafficFine(severity, multiplier);
    points = Cfg_TrafficPoints(severity);
    if (amount > gCfgWorkFineLimit)
    {
        amount = gCfgWorkFineLimit;
    }

    PlayerInfo[targetid][pFines] += amount;
    if (PlayerInfo[targetid][pFines] > MAX_PLAYER_FINE)
    {
        PlayerInfo[targetid][pFines] = MAX_PLAYER_FINE;
    }
    PlayerInfo[targetid][pTrafficPoints] += points;
    if (PlayerInfo[targetid][pTrafficPoints] > MAX_TRAFFIC_POINTS)
    {
        PlayerInfo[targetid][pTrafficPoints] = MAX_TRAFFIC_POINTS;
    }
    SaveAccountData(targetid, 0);

    Cargo_GetName(gCargoType[targetid], cargoName, sizeof(cargoName));
    format(message, sizeof(message), "Autuacao fiscal aplicada no ID %d: %s | multa $%d | %d pts.", targetid, cargoName, amount, points);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(message, sizeof(message), "PRF: carga irregular autuada (%s). Multa $%d e %d pontos na CNH.", cargoName, amount, points);
    SendClientMessage(targetid, COLOR_RED, message);
    format(message, sizeof(message), "officer=%d target=%d cargo=%d doc=%d illegal=%d amount=%d points=%d", playerid, targetid, gCargoType[targetid], gCargoDocStatus[targetid], gCargoIllegal[targetid], amount, points);
    WritePlayerLog(LOG_PUNISH_FILE, "CARGO_FISCAL_FINE", targetid, message);
    return impoundRequired ? 2 : 1;
}

stock Job_GetPlayerXP(playerid, jobid)
{
    if (jobid <= JOB_NONE || jobid > JOB_MAX_ID)
    {
        return 0;
    }
    return gPlayerJobXP[playerid][jobid];
}

stock Job_GetPlayerLevel(playerid, jobid)
{
    if (jobid <= JOB_NONE || jobid > JOB_MAX_ID)
    {
        return 0;
    }

    if (gPlayerJobLevel[playerid][jobid] < 1)
    {
        gPlayerJobLevel[playerid][jobid] = 1;
    }
    return gPlayerJobLevel[playerid][jobid];
}

stock Job_SetPlayerXP(playerid, jobid, xp)
{
    if (jobid <= JOB_NONE || jobid > JOB_MAX_ID)
    {
        return 0;
    }

    if (xp < 0)
    {
        xp = 0;
    }

    gPlayerJobXP[playerid][jobid] = xp;
    return 1;
}

stock Job_SetPlayerLevel(playerid, jobid, level)
{
    if (jobid <= JOB_NONE || jobid > JOB_MAX_ID)
    {
        return 0;
    }

    if (level < 1)
    {
        level = 1;
    }
    if (level > JOB_MAX_LEVEL)
    {
        level = JOB_MAX_LEVEL;
    }

    gPlayerJobLevel[playerid][jobid] = level;
    return 1;
}

stock Job_GetNextLevelXP(level)
{
    if (level < 1)
    {
        level = 1;
    }
    return level * 1000;
}

stock Job_GetLeveledPay(basePay, level)
{
    if (level < 1)
    {
        level = 1;
    }
    return basePay + ((basePay * (level - 1)) / 10);
}

stock Job_GetEffectivePay(jobid, basePay, level)
{
    if (!Job_IsPrivateBonusEligible(jobid))
    {
        return basePay;
    }
    return Job_GetLeveledPay(basePay, level);
}

stock Job_GetLevelBonusPercent(level)
{
    if (level < 1)
    {
        level = 1;
    }
    return (level - 1) * 10;
}

stock Job_GetXpReward(baseXp, level)
{
    if (baseXp <= 0)
    {
        return 0;
    }
    if (level < 1)
    {
        level = 1;
    }
    return baseXp + ((baseXp * (level - 1)) / 20);
}

stock Job_GetLevelRewardCash(level)
{
    if (level < 2)
    {
        return 0;
    }
    return JOB_LEVEL_REWARD_BASE + (level * 125);
}

stock Job_GetServiceCooldown(playerid)
{
    new level = Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob]);
    new cooldown = gCfgWorkTaskCooldown;

    if (level >= 4)
    {
        cooldown -= (level - 3) * 250;
    }
    if (cooldown < 5000)
    {
        cooldown = 5000;
    }
    return cooldown;
}

stock Work_IsEnhancedJob(jobid)
{
    return (jobid == JOB_ENTREGADOR || jobid == JOB_TAXISTA || jobid == JOB_MECANICO);
}

stock Job_IsPublicServiceJob(jobid)
{
    switch (jobid)
    {
        case JOB_LIXEIRO, JOB_MOTORISTA_ONIBUS, JOB_POLICIAL, JOB_MEDICO, JOB_BOMBEIRO, JOB_CARTEIRO, JOB_JUIZ, JOB_MOTORISTA_AMBULANCIA, JOB_PRF, JOB_POLICIA_FEDERAL, JOB_POLICIA_CIVIL, JOB_POLICIA_PENAL, JOB_AGENTE_DETRAN, JOB_FUNCIONARIO_PREFEITURA, JOB_PROFESSOR, JOB_ASSISTENTE_SOCIAL, JOB_PERITO_CRIMINAL, JOB_PROMOTOR, JOB_DEFENSOR_PUBLICO, JOB_OFICIAL_JUSTICA, JOB_ESCRIVAO:
        {
            return 1;
        }
    }
    return 0;
}

stock Job_IsPrivateBonusEligible(jobid)
{
    return (jobid != JOB_NONE && !Job_IsPublicServiceJob(jobid));
}

stock Work_ResetRunState(playerid)
{
    gWorkSpecialMode[playerid] = WORK_SPECIAL_NONE;
    gWorkRouteEvent[playerid] = 0;
    gWorkRouteTargetSteps[playerid] = 0;
    gWorkRouteSize[playerid] = WORK_ROUTE_MEDIUM;
    gWorkRouteStartTick[playerid] = 0;
    gWorkRouteDeadlineMs[playerid] = 0;
    gDeliveryPackageType[playerid] = DELIVERY_PACKAGE_COMMON;
    gDeliveryWrongAddress[playerid] = 0;
    gDeliveryWrongResolved[playerid] = 0;
    gDeliveryVehicleHealthStart[playerid] = 1000.0;
    gTaxiPassengerType[playerid] = TAXI_PASSENGER_NORMAL;
    gTaxiPassengerCanceled[playerid] = 0;
    gTaxiVehicleHealthStart[playerid] = 1000.0;
    gMechanicDiagnosis[playerid] = MECHANIC_DIAG_ENGINE;
    gMechanicPartsUsed[playerid] = 0;
    gMechanicTowRequired[playerid] = 0;
    gMechanicQuote[playerid] = 0;
    return 1;
}

stock Work_ResetStreak(playerid)
{
    gWorkRouteStreak[playerid] = 0;
    gWorkStreakJob[playerid] = JOB_NONE;
    return 1;
}

stock Work_GetStreakBonusPercent(playerid)
{
    new bonus = gWorkRouteStreak[playerid] * WORK_STREAK_BONUS_STEP;

    if (bonus > WORK_STREAK_BONUS_MAX)
    {
        bonus = WORK_STREAK_BONUS_MAX;
    }
    return bonus;
}

stock Work_GetSpecialBonusPercent(playerid)
{
    switch (gWorkSpecialMode[playerid])
    {
        case WORK_SPECIAL_URGENT: return 12;
        case WORK_SPECIAL_VIP: return 18;
        case WORK_SPECIAL_RISK: return 10;
    }
    return 0;
}

stock Work_FormatSpecialName(mode, output[], size = sizeof(output))
{
    switch (mode)
    {
        case WORK_SPECIAL_URGENT: format(output, size, "rota urgente");
        case WORK_SPECIAL_VIP: format(output, size, "cliente prioritario");
        case WORK_SPECIAL_RISK: format(output, size, "servico com imprevisto");
        default: format(output, size, "rota comum");
    }
    return 1;
}

stock Work_FormatRouteSizeName(sizeId, output[], size = sizeof(output))
{
    switch (sizeId)
    {
        case WORK_ROUTE_SHORT: format(output, size, "curta");
        case WORK_ROUTE_LONG: format(output, size, "longa");
        default: format(output, size, "media");
    }
    return 1;
}

stock Work_GetActiveTargetSteps(playerid)
{
    new total = Work_GetRoutePointCount(gWorkRoute[playerid]);

    if (gWorkRouteTargetSteps[playerid] <= 0 || gWorkRouteTargetSteps[playerid] > total)
    {
        return total;
    }
    return gWorkRouteTargetSteps[playerid];
}

stock Work_ChooseRouteSize(playerid, jobid, total)
{
    new roll;
    new level = Job_GetPlayerLevel(playerid, jobid);

    if (total <= 3)
    {
        gWorkRouteSize[playerid] = WORK_ROUTE_SHORT;
        return total;
    }

    gWorkRouteSize[playerid] = WORK_ROUTE_MEDIUM;
    if (jobid == JOB_TAXISTA)
    {
        roll = random(100);
        if (roll < 38)
        {
            gWorkRouteSize[playerid] = WORK_ROUTE_SHORT;
            return 2;
        }
        if (roll < 82 - (level > 5 ? 8 : 0))
        {
            gWorkRouteSize[playerid] = WORK_ROUTE_MEDIUM;
            return 4;
        }
        gWorkRouteSize[playerid] = WORK_ROUTE_LONG;
        return total;
    }

    if (jobid == JOB_MECANICO)
    {
        roll = random(100);
        if (roll < 30)
        {
            gWorkRouteSize[playerid] = WORK_ROUTE_SHORT;
            return 3;
        }
        if (roll < 76 - (level > 5 ? 8 : 0))
        {
            gWorkRouteSize[playerid] = WORK_ROUTE_MEDIUM;
            return 4;
        }
        gWorkRouteSize[playerid] = WORK_ROUTE_LONG;
        return total;
    }

    if (jobid != JOB_ENTREGADOR)
    {
        gWorkRouteTargetSteps[playerid] = total;
        gWorkRouteSize[playerid] = WORK_ROUTE_LONG;
        return total;
    }

    roll = random(100);
    if (roll < 35)
    {
        gWorkRouteSize[playerid] = WORK_ROUTE_SHORT;
        return 3;
    }
    if (roll < 78 - (level > 5 ? 8 : 0))
    {
        gWorkRouteSize[playerid] = WORK_ROUTE_MEDIUM;
        return 4;
    }

    gWorkRouteSize[playerid] = WORK_ROUTE_LONG;
    return total;
}

stock Work_GetRouteSizeBonusPercent(playerid)
{
    switch (gWorkRouteSize[playerid])
    {
        case WORK_ROUTE_MEDIUM: return 8;
        case WORK_ROUTE_LONG: return 16;
    }
    return 0;
}

stock Work_SetRouteDeadline(playerid)
{
    new deadline;

    gWorkRouteStartTick[playerid] = GetTickCount();
    gWorkRouteDeadlineMs[playerid] = 0;

    if (PlayerInfo[playerid][pJob] != JOB_ENTREGADOR)
    {
        return 1;
    }

    deadline = WORK_DELIVERY_BASE_TIME_MS + (Work_GetActiveTargetSteps(playerid) * WORK_DELIVERY_STEP_TIME_MS);
    if (gWorkSpecialMode[playerid] == WORK_SPECIAL_URGENT || gDeliveryPackageType[playerid] == DELIVERY_PACKAGE_URGENT)
    {
        deadline = (deadline * WORK_URGENT_TIME_PERCENT) / 100;
    }
    gWorkRouteDeadlineMs[playerid] = deadline;
    return 1;
}

stock Work_SendRoutePace(playerid)
{
    new routeSize[16];
    new minutes;
    new seconds;
    new message[144];

    if (PlayerInfo[playerid][pJob] != JOB_ENTREGADOR)
    {
        return 0;
    }

    Work_FormatRouteSizeName(gWorkRouteSize[playerid], routeSize, sizeof(routeSize));
    if (gWorkRouteDeadlineMs[playerid] > 0)
    {
        minutes = gWorkRouteDeadlineMs[playerid] / 60000;
        seconds = (gWorkRouteDeadlineMs[playerid] / 1000) % 60;
        format(message, sizeof(message), "Entrega %s: %d parada(s), prazo %02d:%02d. Atraso encerra a rota e quebra a sequencia.", routeSize, Work_GetActiveTargetSteps(playerid), minutes, seconds);
    }
    else
    {
        format(message, sizeof(message), "Entrega %s: %d parada(s).", routeSize, Work_GetActiveTargetSteps(playerid));
    }
    SendClientMessage(playerid, COLOR_YELLOW, message);
    return 1;
}

stock Work_IsRouteDeadlineExpired(playerid, tick)
{
    if (gWorkRouteDeadlineMs[playerid] <= 0 || gWorkRouteStartTick[playerid] <= 0)
    {
        return 0;
    }
    return ((tick - gWorkRouteStartTick[playerid]) > gWorkRouteDeadlineMs[playerid]);
}

stock Work_FailRouteDeadline(playerid)
{
    new message[144];

    if (PlayerInfo[playerid][pJob] == JOB_ENTREGADOR)
    {
        format(message, sizeof(message), "Entrega atrasada: cliente recusou o pacote. Prazo era %d segundos.", gWorkRouteDeadlineMs[playerid] / 1000);
        SendClientMessage(playerid, COLOR_RED, message);
    }
    Work_ApplyPenalty(playerid);
    if (Work_IsEnhancedJob(PlayerInfo[playerid][pJob]))
    {
        Work_ResetStreak(playerid);
        SendClientMessage(playerid, COLOR_ORANGE, "Sequencia de trabalho perdida por atraso.");
    }
    Work_Cancel(playerid, 0);
    SaveAccountData(playerid, 0);
    return 1;
}

stock Delivery_FormatPackageName(packageType, output[], size = sizeof(output))
{
    switch (packageType)
    {
        case DELIVERY_PACKAGE_FRAGILE: format(output, size, "fragil");
        case DELIVERY_PACKAGE_COLD: format(output, size, "refrigerado");
        case DELIVERY_PACKAGE_URGENT: format(output, size, "urgente");
        case DELIVERY_PACKAGE_DOC: format(output, size, "documento");
        default: format(output, size, "comum");
    }
    return 1;
}

stock Delivery_ChoosePackageType(playerid)
{
    new roll;

    if (gWorkSpecialMode[playerid] == WORK_SPECIAL_URGENT)
    {
        return DELIVERY_PACKAGE_URGENT;
    }

    roll = random(100);
    if (roll < 28) return DELIVERY_PACKAGE_COMMON;
    if (roll < 50) return DELIVERY_PACKAGE_FRAGILE;
    if (roll < 68) return DELIVERY_PACKAGE_COLD;
    if (roll < 84) return DELIVERY_PACKAGE_DOC;
    return DELIVERY_PACKAGE_URGENT;
}

stock Delivery_GetPackageBonusPercent(packageType)
{
    switch (packageType)
    {
        case DELIVERY_PACKAGE_FRAGILE: return 6;
        case DELIVERY_PACKAGE_COLD: return 10;
        case DELIVERY_PACKAGE_URGENT: return 14;
        case DELIVERY_PACKAGE_DOC: return 8;
    }
    return 0;
}

stock Delivery_GetPackageXpBonus(packageType)
{
    switch (packageType)
    {
        case DELIVERY_PACKAGE_FRAGILE: return 10;
        case DELIVERY_PACKAGE_COLD: return 16;
        case DELIVERY_PACKAGE_URGENT: return 20;
        case DELIVERY_PACKAGE_DOC: return 12;
    }
    return 0;
}

stock Delivery_GetMarketStockGain(playerid)
{
    new gain = 1;

    if (gWorkRouteSize[playerid] == WORK_ROUTE_MEDIUM)
    {
        gain++;
    }
    else if (gWorkRouteSize[playerid] == WORK_ROUTE_LONG)
    {
        gain += 2;
    }

    if (gDeliveryPackageType[playerid] == DELIVERY_PACKAGE_COLD || gDeliveryPackageType[playerid] == DELIVERY_PACKAGE_URGENT)
    {
        gain++;
    }
    return gain;
}

stock Delivery_StartRun(playerid)
{
    new packageName[24];
    new message[144];

    if (PlayerInfo[playerid][pJob] != JOB_ENTREGADOR)
    {
        return 0;
    }

    gDeliveryPackageType[playerid] = Delivery_ChoosePackageType(playerid);
    gDeliveryWrongAddress[playerid] = (random(100) < DELIVERY_WRONG_ADDRESS_CHANCE);
    gDeliveryWrongResolved[playerid] = 0;
    if (gWorkVehicle[playerid] != 0 && gWorkVehicle[playerid] != INVALID_VEHICLE_ID)
    {
        GetVehicleHealth(gWorkVehicle[playerid], gDeliveryVehicleHealthStart[playerid]);
    }
    else
    {
        gDeliveryVehicleHealthStart[playerid] = 1000.0;
    }

    Delivery_FormatPackageName(gDeliveryPackageType[playerid], packageName, sizeof(packageName));
    format(message, sizeof(message), "Coleta liberada: pacote %s. Passe na Central antes de entregar ao cliente.", packageName);
    SendClientMessage(playerid, COLOR_BLUE, message);
    if (gDeliveryWrongAddress[playerid])
    {
        SendClientMessage(playerid, COLOR_GRAY, "A central avisou que o endereco pode precisar de confirmacao no caminho.");
    }
    return 1;
}

stock Delivery_TryWrongAddress(playerid, pointLabel[])
{
    new routeTotal;
    new message[144];

    if (PlayerInfo[playerid][pJob] != JOB_ENTREGADOR || !gDeliveryWrongAddress[playerid] || gDeliveryWrongResolved[playerid])
    {
        return 0;
    }
    if (gWorkStep[playerid] <= 0)
    {
        return 0;
    }

    routeTotal = Work_GetRoutePointCount(gWorkRoute[playerid]);
    if (gWorkStep[playerid] + 1 >= routeTotal)
    {
        return 0;
    }

    gDeliveryWrongResolved[playerid] = 1;
    if (gWorkRouteTargetSteps[playerid] < routeTotal)
    {
        gWorkRouteTargetSteps[playerid]++;
    }
    if (gWorkRouteDeadlineMs[playerid] > 0)
    {
        gWorkRouteDeadlineMs[playerid] += DELIVERY_WRONG_ADDRESS_EXTRA_MS;
    }

    format(message, sizeof(message), "Endereco incorreto em %s. Cliente atualizou o destino; a central adicionou tempo extra.", pointLabel);
    SendClientMessage(playerid, COLOR_ORANGE, message);
    gWorkStep[playerid]++;
    gWorkLastTaskTick[playerid] = GetTickCount();
    Work_SetCheckpoint(playerid);
    SaveAccountData(playerid, 0);
    return 1;
}

stock Delivery_CalculateRating(playerid)
{
    new rating = 5;
    new elapsed;
    new Float:health;
    new Float:damage;

    if (gDeliveryWrongResolved[playerid])
    {
        rating--;
    }

    if (gWorkRouteDeadlineMs[playerid] > 0 && gWorkRouteStartTick[playerid] > 0)
    {
        elapsed = GetTickCount() - gWorkRouteStartTick[playerid];
        if (elapsed > (gWorkRouteDeadlineMs[playerid] * 90) / 100)
        {
            rating--;
        }
        if (gDeliveryPackageType[playerid] == DELIVERY_PACKAGE_URGENT && elapsed > (gWorkRouteDeadlineMs[playerid] * 75) / 100)
        {
            rating--;
        }
        if (gDeliveryPackageType[playerid] == DELIVERY_PACKAGE_COLD && elapsed > (gWorkRouteDeadlineMs[playerid] * 80) / 100)
        {
            rating--;
        }
    }

    if (gWorkVehicle[playerid] != 0 && gWorkVehicle[playerid] != INVALID_VEHICLE_ID)
    {
        GetVehicleHealth(gWorkVehicle[playerid], health);
        damage = gDeliveryVehicleHealthStart[playerid] - health;
        if (damage > 350.0)
        {
            rating--;
        }
        if (damage > 650.0)
        {
            rating--;
        }
        if (gDeliveryPackageType[playerid] == DELIVERY_PACKAGE_FRAGILE && damage > 180.0)
        {
            rating--;
        }
    }

    if (rating < 1) rating = 1;
    if (rating > 5) rating = 5;
    return rating;
}

stock Delivery_GetRatingBonusPercent(rating)
{
    if (rating >= 5) return 12;
    if (rating == 4) return 6;
    if (rating == 2) return -6;
    if (rating <= 1) return -12;
    return 0;
}

stock Delivery_ResetDaily(playerid)
{
    new today = GetBrasiliaDayStamp();

    if (gDeliveryDailyDay[playerid] != today)
    {
        gDeliveryDailyDay[playerid] = today;
        gDeliveryDailyCompleted[playerid] = 0;
        gDeliveryDailyRatingTotal[playerid] = 0;
        gDeliveryDailyBestStreak[playerid] = 0;
    }
    return 1;
}

stock Delivery_RecordCompletion(playerid, rating)
{
    Delivery_ResetDaily(playerid);
    gDeliveryDailyCompleted[playerid]++;
    gDeliveryDailyRatingTotal[playerid] += rating;
    if (gWorkRouteStreak[playerid] > gDeliveryDailyBestStreak[playerid])
    {
        gDeliveryDailyBestStreak[playerid] = gWorkRouteStreak[playerid];
    }
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_WORK, 1 + (rating >= 5 ? 1 : 0));
    return 1;
}

stock Delivery_ApplyMarketStock(playerid)
{
    new gain = Delivery_GetMarketStockGain(playerid);
    new i;
    new message[192];

    for (i = 0; i < gain; i++)
    {
        Life_ApplyProductionChain(playerid, JOB_ENTREGADOR);
    }

    format(message, sizeof(message), "Mercado abastecido pela entrega: +%d movimento(s) de estoque/empresa.", gain);
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}

stock Delivery_SendRanking(playerid)
{
    new list[768];
    new line[96];
    new name[MAX_PLAYER_NAME];
    new pid;
    new shown;
    new score;
    new bestScore;
    new bestPlayer;
    new used[MAX_PLAYERS];
    new maxPlayers = GetMaxPlayers();
    new avg;

    format(list, sizeof(list), "Entregador\tEntregas\tMedia\tSequencia\n");
    for (shown = 0; shown < 10; shown++)
    {
        bestScore = -1;
        bestPlayer = INVALID_PLAYER_ID;
        for (pid = 0; pid < maxPlayers; pid++)
        {
            if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged] || used[pid])
            {
                continue;
            }
            Delivery_ResetDaily(pid);
            if (gDeliveryDailyCompleted[pid] <= 0)
            {
                continue;
            }
            score = (gDeliveryDailyCompleted[pid] * 100) + gDeliveryDailyRatingTotal[pid] + gDeliveryDailyBestStreak[pid];
            if (score > bestScore)
            {
                bestScore = score;
                bestPlayer = pid;
            }
        }

        if (bestPlayer == INVALID_PLAYER_ID)
        {
            break;
        }

        used[bestPlayer] = 1;
        GetPlayerName(bestPlayer, name, sizeof(name));
        avg = (gDeliveryDailyRatingTotal[bestPlayer] * 10) / gDeliveryDailyCompleted[bestPlayer];
        format(line, sizeof(line), "%s\t%d\t%d.%d\t%d\n", name, gDeliveryDailyCompleted[bestPlayer], avg / 10, avg % 10, gDeliveryDailyBestStreak[bestPlayer]);
        strcat(list, line, sizeof(list));
    }

    if (shown == 0)
    {
        strcat(list, "-\t0\t0.0\t0\n", sizeof(list));
    }
    ShowPlayerDialog(playerid, DIALOG_DELIVERY_RANKING, DIALOG_STYLE_TABLIST_HEADERS, "Ranking diario de entregas", list, "Fechar", "");
    return 1;
}

stock Taxi_FormatPassengerName(passengerType, output[], size = sizeof(output))
{
    switch (passengerType)
    {
        case TAXI_PASSENGER_VIP: format(output, size, "VIP");
        case TAXI_PASSENGER_DRUNK: format(output, size, "alterado");
        case TAXI_PASSENGER_IRRITATED: format(output, size, "apressado");
        case TAXI_PASSENGER_TOURIST: format(output, size, "turista");
        default: format(output, size, "comum");
    }
    return 1;
}

stock Taxi_ChoosePassengerType(playerid)
{
    new roll;

    if (gWorkSpecialMode[playerid] == WORK_SPECIAL_VIP)
    {
        return TAXI_PASSENGER_VIP;
    }

    roll = random(100);
    if (roll < 42) return TAXI_PASSENGER_NORMAL;
    if (roll < 58) return TAXI_PASSENGER_VIP;
    if (roll < 74) return TAXI_PASSENGER_TOURIST;
    if (roll < 88) return TAXI_PASSENGER_IRRITATED;
    return TAXI_PASSENGER_DRUNK;
}

stock Taxi_GetPassengerBonusPercent(passengerType)
{
    switch (passengerType)
    {
        case TAXI_PASSENGER_VIP: return 18;
        case TAXI_PASSENGER_TOURIST: return 10;
        case TAXI_PASSENGER_IRRITATED: return 8;
        case TAXI_PASSENGER_DRUNK: return 12;
    }
    return 0;
}

stock Taxi_GetPassengerXpBonus(passengerType)
{
    switch (passengerType)
    {
        case TAXI_PASSENGER_VIP: return 18;
        case TAXI_PASSENGER_TOURIST: return 12;
        case TAXI_PASSENGER_IRRITATED: return 10;
        case TAXI_PASSENGER_DRUNK: return 14;
    }
    return 0;
}

stock Taxi_StartRun(playerid)
{
    new passengerName[24];
    new routeSize[16];
    new message[144];

    if (PlayerInfo[playerid][pJob] != JOB_TAXISTA)
    {
        return 0;
    }

    gTaxiPassengerType[playerid] = Taxi_ChoosePassengerType(playerid);
    gTaxiPassengerCanceled[playerid] = 0;
    if (gWorkVehicle[playerid] != 0 && gWorkVehicle[playerid] != INVALID_VEHICLE_ID)
    {
        GetVehicleHealth(gWorkVehicle[playerid], gTaxiVehicleHealthStart[playerid]);
    }
    else
    {
        gTaxiVehicleHealthStart[playerid] = 1000.0;
    }

    Taxi_FormatPassengerName(gTaxiPassengerType[playerid], passengerName, sizeof(passengerName));
    Work_FormatRouteSizeName(gWorkRouteSize[playerid], routeSize, sizeof(routeSize));
    format(message, sizeof(message), "Corrida %s iniciada com passageiro %s. Dirija sem bater para manter a avaliacao.", routeSize, passengerName);
    SendClientMessage(playerid, COLOR_BLUE, message);
    if (gTaxiPassengerType[playerid] == TAXI_PASSENGER_DRUNK)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Passageiro alterado: direcao brusca pode cancelar a corrida.");
    }
    else if (gTaxiPassengerType[playerid] == TAXI_PASSENGER_IRRITATED)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Passageiro apressado: atrasos derrubam avaliacao.");
    }
    return 1;
}

stock Taxi_CheckPassengerCancel(playerid)
{
    new Float:health;
    new Float:damage;

    if (PlayerInfo[playerid][pJob] != JOB_TAXISTA || gTaxiPassengerCanceled[playerid])
    {
        return 0;
    }
    if (gWorkVehicle[playerid] == 0 || gWorkVehicle[playerid] == INVALID_VEHICLE_ID)
    {
        return 0;
    }

    GetVehicleHealth(gWorkVehicle[playerid], health);
    damage = gTaxiVehicleHealthStart[playerid] - health;
    if ((gTaxiPassengerType[playerid] == TAXI_PASSENGER_DRUNK || gTaxiPassengerType[playerid] == TAXI_PASSENGER_IRRITATED) && damage > TAXI_BUMP_CANCEL_DAMAGE)
    {
        gTaxiPassengerCanceled[playerid] = 1;
        SendClientMessage(playerid, COLOR_RED, "O passageiro cancelou a corrida depois das batidas. Sequencia perdida.");
        Work_ApplyPenalty(playerid);
        Work_ResetStreak(playerid);
        Work_Cancel(playerid, 0);
        SaveAccountData(playerid, 0);
        return 1;
    }
    return 0;
}

stock Taxi_CalculateRating(playerid)
{
    new rating = 5;
    new Float:health;
    new Float:damage;

    if (gTaxiPassengerCanceled[playerid])
    {
        return 1;
    }

    if (gWorkVehicle[playerid] != 0 && gWorkVehicle[playerid] != INVALID_VEHICLE_ID)
    {
        GetVehicleHealth(gWorkVehicle[playerid], health);
        damage = gTaxiVehicleHealthStart[playerid] - health;
        if (damage > 220.0)
        {
            rating--;
        }
        if (damage > 480.0)
        {
            rating--;
        }
        if (gTaxiPassengerType[playerid] == TAXI_PASSENGER_VIP && damage > 120.0)
        {
            rating--;
        }
    }

    if (gTaxiPassengerType[playerid] == TAXI_PASSENGER_IRRITATED && gWorkRouteSize[playerid] == WORK_ROUTE_LONG)
    {
        rating--;
    }
    if (gTaxiPassengerType[playerid] == TAXI_PASSENGER_TOURIST && rating >= 4)
    {
        rating++;
    }

    if (rating < 1) rating = 1;
    if (rating > 5) rating = 5;
    return rating;
}

stock Taxi_GetRatingBonusPercent(rating)
{
    if (rating >= 5) return 12;
    if (rating == 4) return 6;
    if (rating == 2) return -6;
    if (rating <= 1) return -12;
    return 0;
}

stock Taxi_ResetDaily(playerid)
{
    new today = GetBrasiliaDayStamp();

    if (gTaxiDailyDay[playerid] != today)
    {
        gTaxiDailyDay[playerid] = today;
        gTaxiDailyCompleted[playerid] = 0;
        gTaxiDailyRatingTotal[playerid] = 0;
        gTaxiDailyBestStreak[playerid] = 0;
    }
    return 1;
}

stock Taxi_RecordCompletion(playerid, rating)
{
    Taxi_ResetDaily(playerid);
    gTaxiDailyCompleted[playerid]++;
    gTaxiDailyRatingTotal[playerid] += rating;
    if (gWorkRouteStreak[playerid] > gTaxiDailyBestStreak[playerid])
    {
        gTaxiDailyBestStreak[playerid] = gWorkRouteStreak[playerid];
    }
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_WORK, 1 + (rating >= 5 ? 1 : 0));
    return 1;
}

stock Taxi_SendRanking(playerid)
{
    new list[768];
    new line[96];
    new name[MAX_PLAYER_NAME];
    new pid;
    new shown;
    new score;
    new bestScore;
    new bestPlayer;
    new used[MAX_PLAYERS];
    new maxPlayers = GetMaxPlayers();
    new avg;

    format(list, sizeof(list), "Taxista\tCorridas\tMedia\tSequencia\n");
    for (shown = 0; shown < 10; shown++)
    {
        bestScore = -1;
        bestPlayer = INVALID_PLAYER_ID;
        for (pid = 0; pid < maxPlayers; pid++)
        {
            if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged] || used[pid])
            {
                continue;
            }
            Taxi_ResetDaily(pid);
            if (gTaxiDailyCompleted[pid] <= 0)
            {
                continue;
            }
            score = (gTaxiDailyCompleted[pid] * 100) + gTaxiDailyRatingTotal[pid] + gTaxiDailyBestStreak[pid];
            if (score > bestScore)
            {
                bestScore = score;
                bestPlayer = pid;
            }
        }

        if (bestPlayer == INVALID_PLAYER_ID)
        {
            break;
        }

        used[bestPlayer] = 1;
        GetPlayerName(bestPlayer, name, sizeof(name));
        avg = (gTaxiDailyRatingTotal[bestPlayer] * 10) / gTaxiDailyCompleted[bestPlayer];
        format(line, sizeof(line), "%s\t%d\t%d.%d\t%d\n", name, gTaxiDailyCompleted[bestPlayer], avg / 10, avg % 10, gTaxiDailyBestStreak[bestPlayer]);
        strcat(list, line, sizeof(list));
    }

    if (shown == 0)
    {
        strcat(list, "-\t0\t0.0\t0\n", sizeof(list));
    }
    ShowPlayerDialog(playerid, DIALOG_TAXI_RANKING, DIALOG_STYLE_TABLIST_HEADERS, "Ranking diario de taxistas", list, "Fechar", "");
    return 1;
}

stock Mechanic_FormatDiagnosisName(diagnosis, output[], size = sizeof(output))
{
    switch (diagnosis)
    {
        case MECHANIC_DIAG_TIRE: format(output, size, "pneu/suspensao");
        case MECHANIC_DIAG_BODY: format(output, size, "lataria");
        case MECHANIC_DIAG_BATTERY: format(output, size, "bateria/eletrica");
        case MECHANIC_DIAG_TOW: format(output, size, "guincho");
        default: format(output, size, "motor");
    }
    return 1;
}

stock Mechanic_ChooseDiagnosis(playerid)
{
    new roll = random(100);

    if (gWorkSpecialMode[playerid] == WORK_SPECIAL_RISK)
    {
        return MECHANIC_DIAG_TOW;
    }
    if (roll < 26) return MECHANIC_DIAG_ENGINE;
    if (roll < 48) return MECHANIC_DIAG_TIRE;
    if (roll < 68) return MECHANIC_DIAG_BODY;
    if (roll < 86) return MECHANIC_DIAG_BATTERY;
    return MECHANIC_DIAG_TOW;
}

stock Mech_GetDiagBonusPercent(diagnosis)
{
    switch (diagnosis)
    {
        case MECHANIC_DIAG_ENGINE: return 12;
        case MECHANIC_DIAG_TIRE: return 8;
        case MECHANIC_DIAG_BODY: return 10;
        case MECHANIC_DIAG_BATTERY: return 9;
        case MECHANIC_DIAG_TOW: return 18;
    }
    return 0;
}

stock Mech_GetDiagXpBonus(diagnosis)
{
    switch (diagnosis)
    {
        case MECHANIC_DIAG_ENGINE: return 16;
        case MECHANIC_DIAG_TIRE: return 10;
        case MECHANIC_DIAG_BODY: return 12;
        case MECHANIC_DIAG_BATTERY: return 12;
        case MECHANIC_DIAG_TOW: return 22;
    }
    return 0;
}

stock Mechanic_StartRun(playerid)
{
    new diagnosisName[32];
    new routeSize[16];
    new message[160];

    if (PlayerInfo[playerid][pJob] != JOB_MECANICO)
    {
        return 0;
    }

    gMechanicDiagnosis[playerid] = Mechanic_ChooseDiagnosis(playerid);
    gMechanicTowRequired[playerid] = (gMechanicDiagnosis[playerid] == MECHANIC_DIAG_TOW);
    gMechanicPartsUsed[playerid] = 1 + random(3);
    if (gMechanicDiagnosis[playerid] == MECHANIC_DIAG_ENGINE || gMechanicDiagnosis[playerid] == MECHANIC_DIAG_TOW)
    {
        gMechanicPartsUsed[playerid]++;
    }
    gMechanicQuote[playerid] = 180 + (gMechanicPartsUsed[playerid] * 90) + (gMechanicTowRequired[playerid] ? 260 : 0);

    Mechanic_FormatDiagnosisName(gMechanicDiagnosis[playerid], diagnosisName, sizeof(diagnosisName));
    Work_FormatRouteSizeName(gWorkRouteSize[playerid], routeSize, sizeof(routeSize));
    format(message, sizeof(message), "Chamado %s: diagnostico %s | pecas %d | orcamento $%d.", routeSize, diagnosisName, gMechanicPartsUsed[playerid], gMechanicQuote[playerid]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    if (gMechanicTowRequired[playerid])
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Guincho solicitado: complete o retorno para a oficina para fechar o atendimento.");
    }
    return 1;
}

stock Mechanic_CalculateRating(playerid)
{
    new rating = 5;

    if (gWorkRouteEvent[playerid])
    {
        rating--;
    }
    if (gMechanicTowRequired[playerid] && gWorkRouteSize[playerid] == WORK_ROUTE_SHORT)
    {
        rating--;
    }
    if (gMechanicPartsUsed[playerid] >= 4)
    {
        rating--;
    }
    if (gMechanicQuote[playerid] > 600)
    {
        rating--;
    }
    if (Job_GetPlayerLevel(playerid, JOB_MECANICO) >= 5 && rating < 5)
    {
        rating++;
    }

    if (rating < 1) rating = 1;
    if (rating > 5) rating = 5;
    return rating;
}

stock Mechanic_GetRatingBonusPercent(rating)
{
    if (rating >= 5) return 12;
    if (rating == 4) return 6;
    if (rating == 2) return -6;
    if (rating <= 1) return -12;
    return 0;
}

stock Mechanic_ResetDaily(playerid)
{
    new today = GetBrasiliaDayStamp();

    if (gMechanicDailyDay[playerid] != today)
    {
        gMechanicDailyDay[playerid] = today;
        gMechanicDailyCompleted[playerid] = 0;
        gMechanicDailyRatingTotal[playerid] = 0;
        gMechanicDailyBestStreak[playerid] = 0;
    }
    return 1;
}

stock Mechanic_RecordCompletion(playerid, rating)
{
    Mechanic_ResetDaily(playerid);
    gMechanicDailyCompleted[playerid]++;
    gMechanicDailyRatingTotal[playerid] += rating;
    if (gWorkRouteStreak[playerid] > gMechanicDailyBestStreak[playerid])
    {
        gMechanicDailyBestStreak[playerid] = gWorkRouteStreak[playerid];
    }
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_WORK, 1 + (rating >= 5 ? 1 : 0));
    return 1;
}

stock Mechanic_SendRanking(playerid)
{
    new list[768];
    new line[96];
    new name[MAX_PLAYER_NAME];
    new pid;
    new shown;
    new score;
    new bestScore;
    new bestPlayer;
    new used[MAX_PLAYERS];
    new maxPlayers = GetMaxPlayers();
    new avg;

    format(list, sizeof(list), "Mecanico\tAtendimentos\tMedia\tSequencia\n");
    for (shown = 0; shown < 10; shown++)
    {
        bestScore = -1;
        bestPlayer = INVALID_PLAYER_ID;
        for (pid = 0; pid < maxPlayers; pid++)
        {
            if (!IsPlayerConnected(pid) || !PlayerInfo[pid][pLogged] || used[pid])
            {
                continue;
            }
            Mechanic_ResetDaily(pid);
            if (gMechanicDailyCompleted[pid] <= 0)
            {
                continue;
            }
            score = (gMechanicDailyCompleted[pid] * 100) + gMechanicDailyRatingTotal[pid] + gMechanicDailyBestStreak[pid];
            if (score > bestScore)
            {
                bestScore = score;
                bestPlayer = pid;
            }
        }

        if (bestPlayer == INVALID_PLAYER_ID)
        {
            break;
        }

        used[bestPlayer] = 1;
        GetPlayerName(bestPlayer, name, sizeof(name));
        avg = (gMechanicDailyRatingTotal[bestPlayer] * 10) / gMechanicDailyCompleted[bestPlayer];
        format(line, sizeof(line), "%s\t%d\t%d.%d\t%d\n", name, gMechanicDailyCompleted[bestPlayer], avg / 10, avg % 10, gMechanicDailyBestStreak[bestPlayer]);
        strcat(list, line, sizeof(list));
    }

    if (shown == 0)
    {
        strcat(list, "-\t0\t0.0\t0\n", sizeof(list));
    }
    ShowPlayerDialog(playerid, DIALOG_MECHANIC_RANKING, DIALOG_STYLE_TABLIST_HEADERS, "Ranking diario de mecanicos", list, "Fechar", "");
    return 1;
}

stock Work_ChooseSpecialMode(playerid, jobid)
{
    new level = Job_GetPlayerLevel(playerid, jobid);
    new chance = WORK_SPECIAL_CHANCE + (level * 3);

    if (!Work_IsEnhancedJob(jobid))
    {
        return WORK_SPECIAL_NONE;
    }
    if (chance > 70)
    {
        chance = 70;
    }
    if (random(100) >= chance)
    {
        return WORK_SPECIAL_NONE;
    }
    return 1 + random(3);
}

stock Work_SendSpecialStart(playerid)
{
    new specialName[32];
    new message[144];
    new streakBonus = Work_GetStreakBonusPercent(playerid);
    new specialBonus = Work_GetSpecialBonusPercent(playerid);

    if (!Work_IsEnhancedJob(PlayerInfo[playerid][pJob]))
    {
        return 0;
    }

    Work_FormatSpecialName(gWorkSpecialMode[playerid], specialName, sizeof(specialName));
    format(message, sizeof(message), "Turno %s iniciado. Sequencia atual: %d rota(s), bonus sequencia +%d%%.", specialName, gWorkRouteStreak[playerid], streakBonus);
    SendClientMessage(playerid, COLOR_BLUE, message);
    if (specialBonus > 0)
    {
        format(message, sizeof(message), "Rota especial ativa: +%d%% no pagamento da rota se concluir o expediente.", specialBonus);
        SendClientMessage(playerid, COLOR_YELLOW, message);
    }
    return 1;
}

stock Work_TryRouteEvent(playerid, pointLabel[])
{
    new message[160];

    if (!Work_IsEnhancedJob(PlayerInfo[playerid][pJob]) || gWorkRouteEvent[playerid])
    {
        return 0;
    }
    if (gWorkStep[playerid] <= 0 || random(100) >= WORK_EVENT_CHANCE)
    {
        return 0;
    }

    gWorkRouteEvent[playerid] = 1;
    switch (PlayerInfo[playerid][pJob])
    {
        case JOB_ENTREGADOR:
        {
            SendClientMessage(playerid, COLOR_ORANGE, "Imprevisto: pacote fragil conferido pelo cliente. Bonus pequeno aplicado pela entrega cuidadosa.");
        }
        case JOB_TAXISTA:
        {
            SendClientMessage(playerid, COLOR_ORANGE, "Imprevisto: passageiro pediu parada rapida no caminho. A corrida ganhou taxa extra.");
        }
        case JOB_MECANICO:
        {
            SendClientMessage(playerid, COLOR_ORANGE, "Imprevisto: defeito oculto encontrado. O atendimento ganhou adicional tecnico.");
        }
    }
    format(message, sizeof(message), "Evento de rota registrado em %s. Conclua o turno para manter a sequencia.", pointLabel);
    SendClientMessage(playerid, COLOR_GRAY, message);
    return 1;
}

stock Job_ResetRewardDay(playerid)
{
    new today = GetBrasiliaDayStamp();

    if (gJobRewardDay[playerid] != today)
    {
        gJobRewardDay[playerid] = today;
        gJobRewardCashToday[playerid] = 0;
        gJobRewardXpToday[playerid] = 0;
        gJobRewardBurstTick[playerid] = 0;
        gJobRewardBurstCount[playerid] = 0;
    }
    return 1;
}

stock Job_CanReward(playerid, jobid, cash, xp, source[])
{
    new tick;
    new alert[144];

    if (!PlayerInfo[playerid][pLogged] || jobid <= JOB_NONE || jobid > JOB_MAX_ID)
    {
        return 0;
    }

    if (cash < 0) cash = 0;
    if (xp < 0) xp = 0;
    Job_ResetRewardDay(playerid);

    if (gJobRewardCashToday[playerid] + cash > JOB_REWARD_CASH_DAY_LIMIT || gJobRewardXpToday[playerid] + xp > JOB_REWARD_XP_DAY_LIMIT)
    {
        format(alert, sizeof(alert), "job=%d source=%s cash_dia=%d xp_dia=%d cash=%d xp=%d", jobid, source, gJobRewardCashToday[playerid], gJobRewardXpToday[playerid], cash, xp);
        Security_AddAlert(playerid, "JOB_DAILY_LIMIT", alert);
        SendClientMessage(playerid, COLOR_RED, "Limite diario de recompensa de profissao atingido. Staff foi alertado.");
        return 0;
    }

    tick = GetTickCount();
    if (gJobRewardBurstTick[playerid] == 0 || (tick - gJobRewardBurstTick[playerid]) > JOB_REWARD_BURST_WINDOW_MS)
    {
        gJobRewardBurstTick[playerid] = tick;
        gJobRewardBurstCount[playerid] = 0;
    }
    gJobRewardBurstCount[playerid]++;

    if (gJobRewardBurstCount[playerid] > JOB_REWARD_BURST_LIMIT)
    {
        format(alert, sizeof(alert), "job=%d source=%s burst=%d cash=%d xp=%d", jobid, source, gJobRewardBurstCount[playerid], cash, xp);
        Security_AddAlert(playerid, "JOB_REWARD_BURST", alert);
        SendClientMessage(playerid, COLOR_RED, "Recompensa bloqueada por sequencia rapida demais.");
        return 0;
    }
    return 1;
}

stock Job_RegisterReward(playerid, jobid, cash, xp, source[])
{
    new trackedXp;
    new logLine[160];

    if (cash < 0) cash = 0;
    if (xp < 0) xp = 0;
    Job_ResetRewardDay(playerid);
    gJobRewardCashToday[playerid] += cash;
    gJobRewardXpToday[playerid] += xp;

    trackedXp = xp / 100;
    if (xp > 0 && trackedXp < 1)
    {
        trackedXp = 1;
    }
    Life_TrackGain(playerid, cash, trackedXp, source);
    Life_HandleJobProductivity(playerid, jobid, source);

    format(logLine, sizeof(logLine), "job=%d source=%s cash=%d xp=%d dia_cash=%d dia_xp=%d nivel=%d", jobid, source, cash, xp, gJobRewardCashToday[playerid], gJobRewardXpToday[playerid], Job_GetPlayerLevel(playerid, jobid));
    WritePlayerLog(LOG_MONEY_FILE, "JOB_REWARD", playerid, logLine);
    return 1;
}

stock Job_GiveReward(playerid, jobid, cash, xp, reason[], saveNow)
{
    if (!Job_CanReward(playerid, jobid, cash, xp, reason))
    {
        return 0;
    }

    if (cash > 0)
    {
        GivePlayerCashReason(playerid, cash, saveNow, reason);
    }
    if (xp > 0)
    {
        Job_AddProgress(playerid, jobid, xp);
    }
    Job_RegisterReward(playerid, jobid, cash, xp, reason);
    return 1;
}

stock Job_AddProgressOnly(playerid, jobid, xp)
{
    new message[128];
    new nextXP;
    new reward;

    xp = Vip_ApplyXpBonus(playerid, xp);

    if (jobid <= JOB_NONE || jobid > JOB_MAX_ID)
    {
        return 0;
    }

    if (gPlayerJobLevel[playerid][jobid] < 1)
    {
        gPlayerJobLevel[playerid][jobid] = 1;
    }

    if (gPlayerJobLevel[playerid][jobid] >= JOB_MAX_LEVEL)
    {
        gPlayerJobXP[playerid][jobid] = 0;
        return 1;
    }

    gPlayerJobXP[playerid][jobid] += xp;
    nextXP = Job_GetNextLevelXP(gPlayerJobLevel[playerid][jobid]);

    while (gPlayerJobXP[playerid][jobid] >= nextXP && gPlayerJobLevel[playerid][jobid] < JOB_MAX_LEVEL)
    {
        gPlayerJobXP[playerid][jobid] -= nextXP;
        gPlayerJobLevel[playerid][jobid]++;
        reward = 0;
        if (Job_IsPrivateBonusEligible(jobid))
        {
            reward = Vip_ApplyCashBonus(playerid, Job_GetLevelRewardCash(gPlayerJobLevel[playerid][jobid]));
        }
        if (reward > 0)
        {
            GivePlayerCashReason(playerid, reward, 0, "job_level_reward");
            GivePlayerExperience(playerid, 1, 0);
            Job_RegisterReward(playerid, jobid, reward, 0, "job_level_reward");
            Life_AddWeeklyScore(playerid, WEEKLY_SCORE_WORK, 2);
        }
        if (Job_IsPrivateBonusEligible(jobid))
        {
            format(message, sizeof(message), "Sua profissao subiu para nivel %d. Bonus atual: +%d%% pagamento e recompensa $%d.", gPlayerJobLevel[playerid][jobid], Job_GetLevelBonusPercent(gPlayerJobLevel[playerid][jobid]), reward);
        }
        else
        {
            format(message, sizeof(message), "Sua profissao publica subiu para nivel %d. Sem bonus financeiro extra.", gPlayerJobLevel[playerid][jobid]);
        }
        SendClientMessage(playerid, COLOR_GREEN, message);
        nextXP = Job_GetNextLevelXP(gPlayerJobLevel[playerid][jobid]);
    }
    return 1;
}

stock Job_AddProgress(playerid, jobid, xp)
{
    if (!Job_AddProgressOnly(playerid, jobid, xp))
    {
        return 0;
    }

    Life_AddMissionProgress(playerid, 1, 1);
    Life_TutorialAdvance(playerid, 3);
    Life_CheckAchievements(playerid);
    return 1;
}

stock SaveJobProgressData(playerid, File:account)
{
    new jobid;
    new line[64];

    for (jobid = 1; jobid <= JOB_MAX_ID; jobid++)
    {
        format(line, sizeof(line), "job_%d_xp=%d\r\n", jobid, gPlayerJobXP[playerid][jobid]); fwrite(account, line);
        format(line, sizeof(line), "job_%d_level=%d\r\n", jobid, gPlayerJobLevel[playerid][jobid]); fwrite(account, line);
    }
    return 1;
}

stock ApplyJobProgressAccountField(playerid, key[], value[])
{
    new marker;
    new jobText[8];
    new jobid;

    if (strfind(key, "job_", false) != 0)
    {
        return 0;
    }

    marker = strfind(key, "_xp", false);
    if (marker != -1)
    {
        strmid(jobText, key, 4, marker, sizeof(jobText));
        if (IsNumericString(jobText))
        {
            jobid = strval(jobText);
            if (jobid > JOB_NONE && jobid <= JOB_MAX_ID)
            {
                gPlayerJobXP[playerid][jobid] = strval(value);
                return 1;
            }
        }
    }

    marker = strfind(key, "_level", false);
    if (marker != -1)
    {
        strmid(jobText, key, 4, marker, sizeof(jobText));
        if (IsNumericString(jobText))
        {
            jobid = strval(jobText);
            if (jobid > JOB_NONE && jobid <= JOB_MAX_ID)
            {
                gPlayerJobLevel[playerid][jobid] = strval(value);
                if (gPlayerJobLevel[playerid][jobid] < 1)
                {
                    gPlayerJobLevel[playerid][jobid] = 1;
                }
                if (gPlayerJobLevel[playerid][jobid] > JOB_MAX_LEVEL)
                {
                    gPlayerJobLevel[playerid][jobid] = JOB_MAX_LEVEL;
                }
                return 1;
            }
        }
    }
    return 0;
}

stock Job_GetIndex(jobid)
{
    new index;

    for (index = 0; index < sizeof(gJobs); index++)
    {
        if (gJobs[index][jobId] == jobid)
        {
            return index;
        }
    }
    return -1;
}

stock GetJobName(jobid, output[], size = sizeof(output))
{
    new index = Job_GetIndex(jobid);

    if (index == -1)
    {
        format(output, size, "Desempregado");
        return 0;
    }

    format(output, size, "%s", gJobs[index][jobName]);
    return 1;
}

stock Job_GetLocation(jobid)
{
    new index = Job_GetIndex(jobid);

    if (index == -1)
    {
        return -1;
    }
    return gJobs[index][jobLocation];
}

stock Job_FindByLocation(locationid)
{
    new index;

    for (index = 0; index < sizeof(gJobs); index++)
    {
        if (gJobs[index][jobLocation] == locationid)
        {
            return gJobs[index][jobId];
        }
    }
    return JOB_NONE;
}

stock JobVehicle_IsValidModel(modelid)
{
    return (modelid >= 400 && modelid <= 611);
}

stock JobVehicle_ResetSlot(slot)
{
    if (slot < 0 || slot >= MAX_JOB_CONFIG_VEHICLES)
    {
        return 0;
    }

    gJobVehicleId[slot] = INVALID_VEHICLE_ID;
    gJobVehicleJob[slot] = JOB_NONE;
    gJobVehicleModel[slot] = 0;
    gJobVehicleX[slot] = 0.0;
    gJobVehicleY[slot] = 0.0;
    gJobVehicleZ[slot] = 0.0;
    gJobVehicleA[slot] = 0.0;
    gJobVehicleColor1[slot] = 1;
    gJobVehicleColor2[slot] = 1;
    gJobVehicleFuel[slot] = FUEL_MAX_VALUE;
    gJobVehicleInterior[slot] = 0;
    gJobVehicleWorld[slot] = 0;
    gJobVehicleOwner[slot] = INVALID_PLAYER_ID;
    gJobVehicleDataLine[slot] = 0;
    return 1;
}

stock JobVehicle_TrimToken(text[])
{
    new start;
    new length = strlen(text);
    new index;

    while (start < length && text[start] <= ' ')
    {
        start++;
    }

    if (start > 0)
    {
        for (index = 0; index <= (length - start); index++)
        {
            text[index] = text[index + start];
        }
    }

    length = strlen(text);
    while (length > 0 && text[length - 1] <= ' ')
    {
        text[length - 1] = 0;
        length--;
    }
    return 1;
}

stock JobVehicle_GetToken(line[], &position, output[], size = sizeof(output))
{
    new length = strlen(line);
    new offset;

    if (position >= length)
    {
        output[0] = 0;
        return 0;
    }

    offset = position;
    while (position < length && line[position] != '|' && (position - offset) < (size - 1))
    {
        output[position - offset] = line[position];
        position++;
    }
    output[position - offset] = 0;

    while (position < length && line[position] != '|')
    {
        position++;
    }
    if (position < length && line[position] == '|')
    {
        position++;
    }

    JobVehicle_TrimToken(output);
    return 1;
}

stock JobVehicle_ParseJob(token[])
{
    new index;

    if (IsNumericString(token))
    {
        return strval(token);
    }

    for (index = 0; index < sizeof(gJobs); index++)
    {
        if (strcmp(token, gJobs[index][jobName], true) == 0)
        {
            return gJobs[index][jobId];
        }
    }
    return JOB_NONE;
}

stock JobVehicle_WriteDefaultFile()
{
    new File:file = fopen(JOB_VEHICLES_FILE, io_write);

    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Veiculos de profissao carregados no mapa ao iniciar a GM.\r\n");
    fwrite(file, "# Formato: job|model|x|y|z|angle|color1|color2|fuel|interior|virtualworld\r\n");
    fwrite(file, "# Job pode ser ID ou nome exato. Exemplo: Entregador|482|2099.0|-1806.0|13.5|90.0|1|1|100|0|0\r\n");
    fwrite(file, "# IDs: 1 Entregador, 2 Lixeiro, 3 Onibus, 4 Taxista, 5 Caminhoneiro, 6 Mecanico, 8 Policial, 9 Medico, 10 Bombeiro, 11 Seguranca, 12 Carteiro, 13 Motoboy, 15 Agricultor, 16 Minerador, 17 Pedreiro, 21 Jornalista, 24 Ambulancia, 25 Tecnico, 26 PRF, 27 PF, 28 Civil, 29 Penal.\r\n");
    fwrite(file, "1|482|2100.5000|-1809.3000|13.5547|90.0000|1|1|100|0|0\r\n");
    fwrite(file, "1|482|2100.5000|-1802.9000|13.5547|90.0000|1|1|100|0|0\r\n");
    fwrite(file, "2|408|2193.7000|-1970.6000|13.7841|180.0000|26|26|100|0|0\r\n");
    fwrite(file, "3|431|1814.9000|-1902.9000|13.5748|0.0000|1|6|100|0|0\r\n");
    fwrite(file, "3|431|1803.9000|-1902.9000|13.5748|0.0000|1|6|100|0|0\r\n");
    fwrite(file, "4|438|1779.7000|-1891.3000|13.5625|0.0000|6|1|100|0|0\r\n");
    fwrite(file, "4|438|1770.2000|-1891.3000|13.5625|0.0000|6|1|100|0|0\r\n");
    fwrite(file, "5|403|2456.5000|-2096.9000|13.5469|180.0000|1|1|100|0|0\r\n");
    fwrite(file, "6|525|1038.1000|-1027.6000|32.1016|270.0000|3|1|100|0|0\r\n");
    fwrite(file, "8|596|1575.0000|-1707.5000|5.8906|180.0000|0|1|100|0|0\r\n");
    fwrite(file, "8|599|1581.0000|-1707.5000|5.8906|180.0000|0|1|100|0|0\r\n");
    fwrite(file, "9|416|1202.5000|-1307.5000|13.9688|270.0000|1|3|100|0|0\r\n");
    fwrite(file, "10|407|1765.2000|-1458.8000|13.5313|270.0000|3|1|100|0|0\r\n");
    fwrite(file, "11|490|1524.2000|-1678.5000|14.0469|90.0000|0|0|100|0|0\r\n");
    fwrite(file, "12|499|1121.8000|-1798.6000|16.5938|0.0000|1|6|100|0|0\r\n");
    fwrite(file, "13|448|2127.3000|-1788.9000|13.5547|180.0000|3|6|100|0|0\r\n");
    fwrite(file, "15|531|-388.7000|-1445.1000|25.7266|90.0000|6|6|100|0|0\r\n");
    fwrite(file, "16|455|595.2000|860.2000|-42.4973|0.0000|1|1|100|0|0\r\n");
    fwrite(file, "17|498|2528.1000|-1280.6000|34.9453|180.0000|6|6|100|0|0\r\n");
    fwrite(file, "21|582|746.2000|-1358.5000|13.5000|270.0000|1|1|100|0|0\r\n");
    fwrite(file, "24|416|1202.5000|-1314.5000|13.9688|270.0000|1|3|100|0|0\r\n");
    fwrite(file, "25|552|2344.4000|-1186.3000|27.9766|90.0000|6|1|100|0|0\r\n");
    fwrite(file, "26|599|1009.6000|-932.3000|42.1797|180.0000|0|1|100|0|0\r\n");
    fwrite(file, "26|598|1015.6000|-932.3000|42.1797|180.0000|0|1|100|0|0\r\n");
    fwrite(file, "27|490|332.8619|-1512.9320|35.8671|135.0306|0|0|100|0|0\r\n");
    fwrite(file, "27|528|325.6054|-1525.4171|35.7261|146.8502|0|0|100|0|0\r\n");
    fwrite(file, "28|596|282.8905|-1604.2700|32.8313|183.5020|0|1|100|0|0\r\n");
    fwrite(file, "28|490|288.8905|-1604.2700|32.8313|183.5020|0|0|100|0|0\r\n");
    fwrite(file, "29|427|1601.5000|-1642.5000|13.5469|180.0000|0|1|100|0|0\r\n");
    fwrite(file, "29|528|1606.5000|-1642.5000|13.5469|180.0000|0|0|100|0|0\r\n");
    fclose(file);
    return 1;
}

stock JobVehicle_CreateFromLine(line[])
{
    new token[64];
    new position;
    new jobid;
    new modelid;
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:angle;
    new color1;
    new color2;
    new fuel = FUEL_MAX_VALUE;
    new interior;
    new world;
    new vehicleid;
    new slot;

    if (gJobVehicleCount >= MAX_JOB_CONFIG_VEHICLES || line[0] == 0 || line[0] == '#')
    {
        return 0;
    }

    if (!JobVehicle_GetToken(line, position, token, sizeof(token))) return 0;
    jobid = JobVehicle_ParseJob(token);
    if (Job_GetIndex(jobid) == -1) return 0;

    if (!JobVehicle_GetToken(line, position, token, sizeof(token)) || !IsNumericString(token)) return 0;
    modelid = strval(token);
    if (!JobVehicle_IsValidModel(modelid)) return 0;

    if (!JobVehicle_GetToken(line, position, token, sizeof(token))) return 0;
    x = floatstr(token);
    if (!JobVehicle_GetToken(line, position, token, sizeof(token))) return 0;
    y = floatstr(token);
    if (!JobVehicle_GetToken(line, position, token, sizeof(token))) return 0;
    z = floatstr(token);
    if (!JobVehicle_GetToken(line, position, token, sizeof(token))) return 0;
    angle = floatstr(token);

    if (!JobVehicle_GetToken(line, position, token, sizeof(token)) || !IsNumericString(token, 1)) return 0;
    color1 = strval(token);
    if (!JobVehicle_GetToken(line, position, token, sizeof(token)) || !IsNumericString(token, 1)) return 0;
    color2 = strval(token);

    if (JobVehicle_GetToken(line, position, token, sizeof(token)) && IsNumericString(token))
    {
        fuel = strval(token);
    }
    if (JobVehicle_GetToken(line, position, token, sizeof(token)) && IsNumericString(token, 1))
    {
        interior = strval(token);
    }
    if (JobVehicle_GetToken(line, position, token, sizeof(token)) && IsNumericString(token, 1))
    {
        world = strval(token);
    }

    if (fuel < 0) fuel = 0;
    if (fuel > FUEL_MAX_VALUE) fuel = FUEL_MAX_VALUE;

    vehicleid = CreateVehicle(modelid, x, y, z, angle, color1, color2, JOB_VEHICLE_RESPAWN_DELAY);
    if (vehicleid == INVALID_VEHICLE_ID)
    {
        return 0;
    }

    LinkVehicleToInterior(vehicleid, interior);
    SetVehicleVirtualWorld(vehicleid, world);
    Fuel_InitVehicle(vehicleid, fuel, 0);

    slot = gJobVehicleCount;
    gJobVehicleId[slot] = vehicleid;
    gJobVehicleJob[slot] = jobid;
    gJobVehicleModel[slot] = modelid;
    gJobVehicleX[slot] = x;
    gJobVehicleY[slot] = y;
    gJobVehicleZ[slot] = z;
    gJobVehicleA[slot] = angle;
    gJobVehicleColor1[slot] = color1;
    gJobVehicleColor2[slot] = color2;
    gJobVehicleFuel[slot] = fuel;
    gJobVehicleInterior[slot] = interior;
    gJobVehicleWorld[slot] = world;
    gJobVehicleOwner[slot] = INVALID_PLAYER_ID;
    gJobVehicleDataLine[slot] = 0;
    gJobVehicleCount++;
    return 1;
}

stock JobVehicle_CountDataLines()
{
    new File:file;
    new line[256];
    new count;

    if (!fexist(JOB_VEHICLES_FILE))
    {
        return 0;
    }

    file = fopen(JOB_VEHICLES_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (JobVehicle_IsDataLine(line))
        {
            count++;
        }
    }

    fclose(file);
    return count;
}

stock JobVehicle_SaveLine(jobid, modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2, fuel, interior, world, preview)
{
    new File:file;
    new line[256];
    new parseLine[256];

    if (gJobVehicleCount >= MAX_JOB_CONFIG_VEHICLES)
    {
        return 0;
    }

    if (Job_GetIndex(jobid) == -1 || !JobVehicle_IsValidModel(modelid))
    {
        return 0;
    }

    if (fuel < 0) fuel = 0;
    if (fuel > FUEL_MAX_VALUE) fuel = FUEL_MAX_VALUE;

    if (!fexist(JOB_VEHICLES_FILE))
    {
        JobVehicle_WriteDefaultFile();
    }

    file = fopen(JOB_VEHICLES_FILE, io_append);
    if (!file)
    {
        return 0;
    }

    format(line, sizeof(line), "%d|%d|%.4f|%.4f|%.4f|%.4f|%d|%d|%d|%d|%d\r\n", jobid, modelid, x, y, z, angle, color1, color2, fuel, interior, world);
    fwrite(file, line);
    fclose(file);

    if (preview)
    {
        new dataLine = JobVehicle_CountDataLines();
        format(parseLine, sizeof(parseLine), "%s", line);
        StripLineEnd(parseLine);
        if (JobVehicle_CreateFromLine(parseLine))
        {
            gJobVehicleDataLine[gJobVehicleCount - 1] = dataLine;
            return 1;
        }
        return 0;
    }
    return 1;
}

stock JobVehicle_SaveAll()
{
    new File:file;
    new line[256];
    new slot;

    file = fopen(JOB_VEHICLES_FILE, io_write);
    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Veiculos de profissao carregados no mapa ao iniciar a GM.\r\n");
    fwrite(file, "# Formato: job|model|x|y|z|angle|color1|color2|fuel|interior|virtualworld\r\n");
    for (slot = 0; slot < gJobVehicleCount; slot++)
    {
        if (gJobVehicleModel[slot] < 400)
        {
            continue;
        }
        format(line, sizeof(line), "%d|%d|%.4f|%.4f|%.4f|%.4f|%d|%d|%d|%d|%d\r\n",
            gJobVehicleJob[slot],
            gJobVehicleModel[slot],
            gJobVehicleX[slot],
            gJobVehicleY[slot],
            gJobVehicleZ[slot],
            gJobVehicleA[slot],
            gJobVehicleColor1[slot],
            gJobVehicleColor2[slot],
            gJobVehicleFuel[slot],
            gJobVehicleInterior[slot],
            gJobVehicleWorld[slot]
        );
        fwrite(file, line);
    }
    fclose(file);
    return 1;
}

stock JobVehicle_SaveAllExcept(skipSlot = -1)
{
    new File:file;
    new line[256];
    new slot;

    file = fopen(JOB_VEHICLES_FILE, io_write);
    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Veiculos de profissao carregados no mapa ao iniciar a GM.\r\n");
    fwrite(file, "# Formato: job|model|x|y|z|angle|color1|color2|fuel|interior|virtualworld\r\n");
    for (slot = 0; slot < gJobVehicleCount; slot++)
    {
        if (slot == skipSlot || gJobVehicleModel[slot] < 400)
        {
            continue;
        }
        format(line, sizeof(line), "%d|%d|%.4f|%.4f|%.4f|%.4f|%d|%d|%d|%d|%d\r\n",
            gJobVehicleJob[slot],
            gJobVehicleModel[slot],
            gJobVehicleX[slot],
            gJobVehicleY[slot],
            gJobVehicleZ[slot],
            gJobVehicleA[slot],
            gJobVehicleColor1[slot],
            gJobVehicleColor2[slot],
            gJobVehicleFuel[slot],
            gJobVehicleInterior[slot],
            gJobVehicleWorld[slot]
        );
        fwrite(file, line);
    }
    fclose(file);
    return 1;
}

stock JobVehicle_FindNearest(playerid, Float:range = 20.0)
{
    new slot;
    new nearest = -1;
    new vehicleid;
    new playerInterior = GetPlayerInterior(playerid);
    new playerWorld = GetPlayerVirtualWorld(playerid);
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:distance;
    new Float:bestDistance = 999999.0;

    for (slot = 0; slot < gJobVehicleCount; slot++)
    {
        vehicleid = gJobVehicleId[slot];
        if (vehicleid == INVALID_VEHICLE_ID || GetVehicleModel(vehicleid) == 0)
        {
            continue;
        }
        if (gJobVehicleInterior[slot] != playerInterior || GetVehicleVirtualWorld(vehicleid) != playerWorld)
        {
            continue;
        }
        GetVehiclePos(vehicleid, x, y, z);
        distance = GetPlayerDistanceFromPoint(playerid, x, y, z);
        if (distance <= range && distance < bestDistance)
        {
            nearest = slot;
            bestDistance = distance;
        }
    }
    return nearest;
}

stock JobVehicle_SendNearest(playerid)
{
    new slot = JobVehicle_FindNearest(playerid, 35.0);
    new vehicleid;
    new jobLabel[32];
    new message[160];
    new Float:x;
    new Float:y;
    new Float:z;

    if (slot == -1)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Nenhum veiculo de frota encontrado perto de voce.");
        return 1;
    }

    vehicleid = gJobVehicleId[slot];
    GetVehiclePos(vehicleid, x, y, z);
    GetJobName(gJobVehicleJob[slot], jobLabel, sizeof(jobLabel));
    format(message, sizeof(message), "Veiculo mais perto: ID %d | %s | modelo %d | %.1fm.", slot + 1, jobLabel, gJobVehicleModel[slot], GetPlayerDistanceFromPoint(playerid, x, y, z));
    SendClientMessage(playerid, COLOR_YELLOW, message);
    SendClientMessage(playerid, COLOR_GRAY, "Use /moverveiculomaisperto ou /ajustarveiculo [id] para salvar na sua posicao.");
    return 1;
}

stock JobVehicle_AdjustNearest(playerid)
{
    new slot = JobVehicle_FindNearest(playerid, 35.0);

    if (slot == -1)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Nenhum veiculo de frota encontrado perto de voce.");
        return 1;
    }
    return JobVehicle_AdjustSlot(playerid, slot, 0);
}

stock JobVehicle_AdjustSlot(playerid, slot, useVehiclePosition = 0)
{
    new vehicleid;
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:a;
    new jobLabel[32];
    new message[180];

    if (!JobVehicle_CanManage(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao tem permissao para ajustar frota.");
        return 1;
    }
    if (slot < 0 || slot >= gJobVehicleCount)
    {
        return SendUsage(playerid, "/ajustarveiculo [id]");
    }

    vehicleid = gJobVehicleId[slot];
    if (vehicleid == INVALID_VEHICLE_ID || GetVehicleModel(vehicleid) == 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Veiculo de frota invalido.");
        return 1;
    }

    if (useVehiclePosition && IsPlayerInAnyVehicle(playerid))
    {
        vehicleid = GetPlayerVehicleID(playerid);
        slot = JobVehicle_FindByVehicle(vehicleid);
        if (slot == -1)
        {
            SendClientMessage(playerid, COLOR_RED, "O veiculo atual nao pertence a frota configurada.");
            return 1;
        }
        GetVehiclePos(vehicleid, x, y, z);
        GetVehicleZAngle(vehicleid, a);
    }
    else
    {
        GetPlayerPos(playerid, x, y, z);
        GetPlayerFacingAngle(playerid, a);
        vehicleid = gJobVehicleId[slot];
    }

    gJobVehicleX[slot] = x;
    gJobVehicleY[slot] = y;
    gJobVehicleZ[slot] = z;
    gJobVehicleA[slot] = a;
    gJobVehicleInterior[slot] = GetPlayerInterior(playerid);
    gJobVehicleWorld[slot] = GetPlayerVirtualWorld(playerid);

    SetVehiclePos(vehicleid, x, y, z);
    SetVehicleZAngle(vehicleid, a);
    LinkVehicleToInterior(vehicleid, gJobVehicleInterior[slot]);
    SetVehicleVirtualWorld(vehicleid, gJobVehicleWorld[slot]);
    Fuel_InitVehicle(vehicleid, gJobVehicleFuel[slot], 0);
    JobVehicle_SaveAll();

    GetJobName(gJobVehicleJob[slot], jobLabel, sizeof(jobLabel));
    format(message, sizeof(message), "Veiculo ID %d (%s/modelo %d) salvo em %.2f, %.2f, %.2f ang %.1f.", slot + 1, jobLabel, gJobVehicleModel[slot], x, y, z, a);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(playerid, COLOR_GRAY, "Arquivo atualizado: scriptfiles/job_vehicles.txt");
    return 1;
}

stock JobVehicle_RemoveSlot(playerid, slot)
{
    new jobLabel[32];
    new message[180];
    new modelid;
    new jobid;

    if (!JobVehicle_CanManage(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao tem permissao para remover frota.");
        return 1;
    }
    if (slot < 0 || slot >= gJobVehicleCount || gJobVehicleModel[slot] < 400)
    {
        return SendUsage(playerid, "/removerjobveiculo [id]");
    }

    modelid = gJobVehicleModel[slot];
    jobid = gJobVehicleJob[slot];
    GetJobName(jobid, jobLabel, sizeof(jobLabel));

    if (!JobVehicle_SaveAllExcept(slot))
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel salvar scriptfiles/job_vehicles.txt.");
        return 1;
    }

    JobVehicle_LoadAll();
    format(message, sizeof(message), "Veiculo de frota ID %d removido: %s/modelo %d. Frota recarregada e arquivo salvo.", slot + 1, jobLabel, modelid);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_ADMIN_FILE, "JOB_VEHICLE_REMOVE", playerid, message);
    return 1;
}

stock JobVehicle_GotoSlot(playerid, slot)
{
    new jobLabel[32];
    new message[180];
    new Float:x;
    new Float:y;
    new Float:z;

    if (!JobVehicle_CanManage(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao tem permissao para teleportar ate a frota.");
        return 1;
    }
    if (slot < 0 || slot >= gJobVehicleCount || gJobVehicleModel[slot] < 400)
    {
        return SendUsage(playerid, "/irveiculo [id]");
    }

    GetVehiclePos(gJobVehicleId[slot], x, y, z);
    x += 2.0;
    y += 2.0;
    z += 1.0;
    if (IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        SetVehiclePos(GetPlayerVehicleID(playerid), x, y, z);
        SetVehicleZAngle(GetPlayerVehicleID(playerid), gJobVehicleA[slot]);
        LinkVehicleToInterior(GetPlayerVehicleID(playerid), gJobVehicleInterior[slot]);
        SetVehicleVirtualWorld(GetPlayerVehicleID(playerid), gJobVehicleWorld[slot]);
    }
    SetPlayerInterior(playerid, gJobVehicleInterior[slot]);
    SetPlayerVirtualWorld(playerid, gJobVehicleWorld[slot]);
    SetPlayerPos(playerid, x, y, z);
    SetPlayerFacingAngle(playerid, gJobVehicleA[slot]);
    Security_GrantTeleportGrace(playerid);
    SetCameraBehindPlayer(playerid);

    GetJobName(gJobVehicleJob[slot], jobLabel, sizeof(jobLabel));
    format(message, sizeof(message), "Teleportado para veiculo de frota ID %d: %s/modelo %d.", slot + 1, jobLabel, gJobVehicleModel[slot]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock JobVehicle_ShowGotoDialog(playerid, page = 0)
{
    new list[3000];
    new line[128];
    new slot;
    new shown;
    new start;
    new title[64];
    new jobLabel[32];

    if (!JobVehicle_CanManage(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao tem permissao para consultar frota.");
        return 1;
    }
    if (page < 0)
    {
        page = 0;
    }

    start = page * JOBVEHICLE_GOTO_PAGE_SIZE;
    if (start >= gJobVehicleCount && page > 0)
    {
        page--;
        start = page * JOBVEHICLE_GOTO_PAGE_SIZE;
    }

    gPlayerJobVehicleGotoPage[playerid] = page;
    format(list, sizeof(list), "ID\tProfissao\tModelo\n");
    for (slot = start; slot < gJobVehicleCount && shown < JOBVEHICLE_GOTO_PAGE_SIZE; slot++)
    {
        GetJobName(gJobVehicleJob[slot], jobLabel, sizeof(jobLabel));
        format(line, sizeof(line), "%d\t%s\t%d\n", slot + 1, jobLabel, gJobVehicleModel[slot]);
        strcat(list, line, sizeof(list));
        shown++;
    }
    if (start + shown < gJobVehicleCount)
    {
        strcat(list, ">>\tProxima pagina\t\n", sizeof(list));
    }
    if (page > 0)
    {
        strcat(list, "<<\tPagina anterior\t\n", sizeof(list));
    }
    if (shown == 0)
    {
        strcat(list, "-\tNenhum veiculo\t\n", sizeof(list));
    }

    format(title, sizeof(title), "Ir ate veiculo - Pagina %d", page + 1);
    ShowPlayerDialog(playerid, DIALOG_JOBVEHICLE_GOTO_LIST, DIALOG_STYLE_TABLIST_HEADERS, title, list, "Ir", "Fechar");
    return 1;
}

stock JobVehicle_HandleGotoDialog(playerid, response, listitem)
{
    new page = gPlayerJobVehicleGotoPage[playerid];
    new start = page * JOBVEHICLE_GOTO_PAGE_SIZE;
    new shown = gJobVehicleCount - start;

    if (!response)
    {
        return 1;
    }
    if (shown > JOBVEHICLE_GOTO_PAGE_SIZE)
    {
        shown = JOBVEHICLE_GOTO_PAGE_SIZE;
    }
    if (listitem >= 0 && listitem < shown)
    {
        return JobVehicle_GotoSlot(playerid, start + listitem);
    }
    if (listitem == shown && start + shown < gJobVehicleCount)
    {
        return JobVehicle_ShowGotoDialog(playerid, page + 1);
    }
    if ((listitem == shown || listitem == shown + 1) && page > 0)
    {
        return JobVehicle_ShowGotoDialog(playerid, page - 1);
    }
    return 1;
}

stock JobVehicle_AddCommand(playerid, jobid, modelid, color1, color2, fuel, useCurrentVehicle)
{
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:angle;
    new vehicleid;
    new interior;
    new world;
    new jobLabel[32];
    new message[160];
    new logLine[192];

    if (!IsAdminOwnerLevel(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas admin nivel 5 DONO pode criar veiculos de profissao.");
        return 1;
    }

    if (Job_GetIndex(jobid) == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Profissao invalida. Use o ID da profissao em /jobveiculos.");
        return 1;
    }

    if (useCurrentVehicle)
    {
        if (!IsPlayerInAnyVehicle(playerid))
        {
            SendClientMessage(playerid, COLOR_RED, "Entre no veiculo que deseja salvar ou informe um modelo.");
            return 1;
        }

        vehicleid = GetPlayerVehicleID(playerid);
        modelid = GetVehicleModel(vehicleid);
        GetVehiclePos(vehicleid, x, y, z);
        GetVehicleZAngle(vehicleid, angle);
        interior = GetPlayerInterior(playerid);
        world = GetVehicleVirtualWorld(vehicleid);
    }
    else
    {
        if (!JobVehicle_IsValidModel(modelid))
        {
            SendClientMessage(playerid, COLOR_RED, "Modelo invalido. Use ID de veiculo SA-MP entre 400 e 611.");
            return 1;
        }

        if (IsPlayerInAnyVehicle(playerid))
        {
            vehicleid = GetPlayerVehicleID(playerid);
            GetVehiclePos(vehicleid, x, y, z);
            GetVehicleZAngle(vehicleid, angle);
            interior = GetPlayerInterior(playerid);
            world = GetVehicleVirtualWorld(vehicleid);
        }
        else
        {
            GetPlayerPos(playerid, x, y, z);
            GetPlayerFacingAngle(playerid, angle);
            interior = GetPlayerInterior(playerid);
            world = GetPlayerVirtualWorld(playerid);
        }
    }

    if (!JobVehicle_SaveLine(jobid, modelid, x, y, z, angle, color1, color2, fuel, interior, world, 1))
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel salvar/criar o veiculo de profissao.");
        return 1;
    }

    GetJobName(jobid, jobLabel, sizeof(jobLabel));
    format(message, sizeof(message), "Veiculo salvo para %s: model %d em %.1f, %.1f, %.1f.", jobLabel, modelid, x, y, z);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(playerid, COLOR_YELLOW, "Linha adicionada em scriptfiles/job_vehicles.txt e veiculo criado no mapa.");
    format(logLine, sizeof(logLine), "job=%d model=%d pos=%.2f,%.2f,%.2f fuel=%d colors=%d/%d", jobid, modelid, x, y, z, fuel, color1, color2);
    WritePlayerLog(LOG_ADMIN_FILE, "JOB_VEHICLE_ADD", playerid, logLine);
    return 1;
}

stock JobVehicle_FindByVehicle(vehicleid)
{
    new slot;

    for (slot = 0; slot < gJobVehicleCount; slot++)
    {
        if (gJobVehicleId[slot] == vehicleid)
        {
            return slot;
        }
    }
    return -1;
}

stock JobVehicle_DestroyAll()
{
    new slot;
    new playerid;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && gWorkVehicleFromFleet[playerid])
        {
            SendClientMessage(playerid, COLOR_ORANGE, "Frota de trabalho recarregada. Seu expediente foi encerrado.");
            gWorkVehicle[playerid] = 0;
            gWorkVehicleFromFleet[playerid] = 0;
            Work_Cancel(playerid, 0);
        }
    }

    for (slot = 0; slot < gJobVehicleCount; slot++)
    {
        if (gJobVehicleId[slot] != INVALID_VEHICLE_ID && GetVehicleModel(gJobVehicleId[slot]) != 0)
        {
            DestroyVehicle(gJobVehicleId[slot]);
        }
        JobVehicle_ResetSlot(slot);
    }
    gJobVehicleCount = 0;
    return 1;
}

stock JobVehicle_LoadAll()
{
    new File:file;
    new line[256];
    new loaded;
    new slot;
    new dataLine;

    JobVehicle_DestroyAll();

    for (slot = 0; slot < MAX_JOB_CONFIG_VEHICLES; slot++)
    {
        JobVehicle_ResetSlot(slot);
    }

    if (!fexist(JOB_VEHICLES_FILE))
    {
        JobVehicle_WriteDefaultFile();
    }

    file = fopen(JOB_VEHICLES_FILE, io_read);
    if (!file)
    {
        print("[JobVehicles] Nao foi possivel abrir job_vehicles.txt.");
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (JobVehicle_IsDataLine(line))
        {
            dataLine++;
        }

        if (JobVehicle_CreateFromLine(line))
        {
            gJobVehicleDataLine[gJobVehicleCount - 1] = dataLine;
            loaded++;
        }
    }

    fclose(file);
    printf("[JobVehicles] %d veiculos de profissao carregados de scriptfiles/job_vehicles.txt.", loaded);
    return loaded;
}

stock JobVehicle_CanManage(playerid)
{
    if (IsAdminOwnerLevel(playerid))
    {
        return 1;
    }
    return 0;
}

stock JobVehicle_IsDataLine(line[])
{
    new check[256];

    format(check, sizeof(check), "%s", line);
    StripLineEnd(check);
    JobVehicle_TrimToken(check);
    if (check[0] == 0 || check[0] == '#')
    {
        return 0;
    }
    return 1;
}

stock JobVehicle_FindFreeForPlayer(playerid, jobid)
{
    new slot;
    new bestSlot = -1;
    new Float:distance;
    new Float:bestDistance = 999999.0;

    for (slot = 0; slot < gJobVehicleCount; slot++)
    {
        if (gJobVehicleJob[slot] != jobid || gJobVehicleOwner[slot] != INVALID_PLAYER_ID)
        {
            continue;
        }

        if (gJobVehicleId[slot] == INVALID_VEHICLE_ID || GetVehicleModel(gJobVehicleId[slot]) == 0)
        {
            continue;
        }

        distance = GetPlayerDistanceFromPoint(playerid, gJobVehicleX[slot], gJobVehicleY[slot], gJobVehicleZ[slot]);
        if (distance < bestDistance)
        {
            bestDistance = distance;
            bestSlot = slot;
        }
    }
    return bestSlot;
}

stock JobVehicle_AssignPlayer(playerid, jobid, &vehicleid)
{
    new slot = JobVehicle_FindFreeForPlayer(playerid, jobid);
    new jobLabel[32];
    new message[128];

    if (slot == -1)
    {
        return 0;
    }

    vehicleid = gJobVehicleId[slot];
    gJobVehicleOwner[slot] = playerid;
    gWorkVehicle[playerid] = vehicleid;
    gWorkVehicleFromFleet[playerid] = 1;

    LinkVehicleToInterior(vehicleid, gJobVehicleInterior[slot]);
    SetVehicleVirtualWorld(vehicleid, gJobVehicleWorld[slot]);
    Fuel_InitVehicle(vehicleid, gJobVehicleFuel[slot], 0);
    PutPlayerInVehicle(playerid, vehicleid, 0);

    GetJobName(jobid, jobLabel, sizeof(jobLabel));
    format(message, sizeof(message), "Veiculo da frota liberado para %s. Use /motor para ligar.", jobLabel);
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}

stock JobVehicle_ReleasePlayer(playerid, respawn)
{
    new slot;
    new vehicleid;

    for (slot = 0; slot < gJobVehicleCount; slot++)
    {
        if (gJobVehicleOwner[slot] == playerid)
        {
            vehicleid = gJobVehicleId[slot];
            gJobVehicleOwner[slot] = INVALID_PLAYER_ID;

            if (vehicleid != INVALID_VEHICLE_ID && GetVehicleModel(vehicleid) != 0)
            {
                Fuel_InitVehicle(vehicleid, gJobVehicleFuel[slot], 0);
                if (respawn)
                {
                    SetVehicleToRespawn(vehicleid);
                }
            }
        }
    }

    gWorkVehicle[playerid] = 0;
    gWorkVehicleFromFleet[playerid] = 0;
    return 1;
}

stock JobVehicle_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    new slot = JobVehicle_FindByVehicle(vehicleid);
    new jobLabel[32];
    new message[128];

    if (slot == -1 || ispassenger)
    {
        return 0;
    }

    GetJobName(gJobVehicleJob[slot], jobLabel, sizeof(jobLabel));
    if (IsAdminOwnerLevel(playerid))
    {
        format(message, sizeof(message), "Admin nivel 5: veiculo de trabalho %s liberado para uso.", jobLabel);
        SendClientMessage(playerid, COLOR_YELLOW, message);
        return 1;
    }

    format(message, sizeof(message), "Veiculo de trabalho: %s. Bata ponto no emprego para usar.", jobLabel);
    SendClientMessage(playerid, COLOR_YELLOW, message);
    return 1;
}

stock JobVehicle_OnPlayerStateChange(playerid, newstate, oldstate)
{
    new vehicleid;
    new slot;
    new jobLabel[32];
    new message[144];

    if (newstate != PLAYER_STATE_DRIVER)
    {
        return 0;
    }

    vehicleid = GetPlayerVehicleID(playerid);
    slot = JobVehicle_FindByVehicle(vehicleid);
    if (slot == -1)
    {
        return 0;
    }

    if (IsAdminOwnerLevel(playerid))
    {
        return 0;
    }

    if (gJobVehicleOwner[slot] == playerid)
    {
        return 0;
    }

    if (gJobVehicleOwner[slot] != INVALID_PLAYER_ID)
    {
        SendClientMessage(playerid, COLOR_RED, "Este veiculo de trabalho ja esta reservado para outro funcionario.");
        RemovePlayerFromVehicle(playerid);
        return 1;
    }

    if (PlayerInfo[playerid][pJob] != gJobVehicleJob[slot] || !gWorkActive[playerid])
    {
        GetJobName(gJobVehicleJob[slot], jobLabel, sizeof(jobLabel));
        format(message, sizeof(message), "Este veiculo pertence ao emprego %s. Use o ponto de servico para iniciar expediente.", jobLabel);
        SendClientMessage(playerid, COLOR_RED, message);
        RemovePlayerFromVehicle(playerid);
        return 1;
    }

    gJobVehicleOwner[slot] = playerid;
    gWorkVehicle[playerid] = vehicleid;
    gWorkVehicleFromFleet[playerid] = 1;
    return 0;
}

stock JobVehicle_OnVehicleDeath(vehicleid)
{
    new slot = JobVehicle_FindByVehicle(vehicleid);
    new ownerid;

    if (slot == -1)
    {
        return 0;
    }

    ownerid = gJobVehicleOwner[slot];
    if (ownerid != INVALID_PLAYER_ID && IsPlayerConnected(ownerid))
    {
        gWorkVehicle[ownerid] = 0;
        gWorkVehicleFromFleet[ownerid] = 0;
        Work_Cancel(ownerid, 1);
        SendClientMessage(ownerid, COLOR_RED, "O veiculo de trabalho foi destruido. Expediente encerrado.");
    }

    gJobVehicleOwner[slot] = INVALID_PLAYER_ID;
    Fuel_InitVehicle(vehicleid, gJobVehicleFuel[slot], 0);
    return 1;
}

stock Work_InitVehicles()
{
    return JobVehicle_LoadAll();
}

stock Work_DestroyConfigVehicles()
{
    return JobVehicle_DestroyAll();
}

stock Work_CountConfigVehicles()
{
    return gJobVehicleCount;
}

stock Work_IsActive(playerid)
{
    return gWorkActive[playerid];
}

stock Job_IsPublicServant(jobid)
{
    switch (jobid)
    {
        case JOB_MOTORISTA_ONIBUS, JOB_POLICIAL, JOB_MEDICO, JOB_BOMBEIRO, JOB_SEGURANCA, JOB_CARTEIRO, JOB_JUIZ, JOB_MOTORISTA_AMBULANCIA, JOB_TECNICO, JOB_PRF, JOB_POLICIA_FEDERAL, JOB_POLICIA_CIVIL, JOB_POLICIA_PENAL, JOB_AGENTE_DETRAN, JOB_FUNCIONARIO_PREFEITURA, JOB_PROFESSOR, JOB_ASSISTENTE_SOCIAL, JOB_PERITO_CRIMINAL, JOB_PROMOTOR, JOB_DEFENSOR_PUBLICO, JOB_OFICIAL_JUSTICA, JOB_ESCRIVAO:
        {
            return 1;
        }
    }
    return 0;
}

stock Job_IsPublicServantOnDuty(playerid)
{
    return (PlayerInfo[playerid][pLogged] && Work_IsActive(playerid) && Job_IsPublicServant(PlayerInfo[playerid][pJob]));
}

stock Job_GetLevelVehicle(jobid, level, baseModel)
{
    if (level < 5)
    {
        return baseModel;
    }

    switch (jobid)
    {
        case JOB_ENTREGADOR: return 498;
        case JOB_TAXISTA: return 420;
        case JOB_CAMINHONEIRO: return 514;
        case JOB_POLICIAL: return 597;
        case JOB_PRF: return 598;
        case JOB_POLICIA_FEDERAL: return 528;
        case JOB_POLICIA_CIVIL: return 490;
        case JOB_POLICIA_PENAL: return 528;
        case JOB_JORNALISTA: return 582;
        case JOB_TECNICO: return 552;
    }
    return baseModel;
}

stock Job_FormatUnlocks(jobid, level, output[], size = sizeof(output))
{
    if (jobid == JOB_BOMBEIRO)
    {
        if (level >= 10) format(output, size, "N10: comandante, maior XP em 193 e prioridade nos grandes incendios");
        else if (level >= 7) format(output, size, "N7: resgate avancado e ocorrencias com risco de propagacao");
        else if (level >= 5) format(output, size, "N5: posto/oficina/deposito em chamas liberados");
        else if (level >= 3) format(output, size, "N3: casa/apartamento pegando fogo liberado");
        else format(output, size, "Proximo: N3 casas, N5 empresas, N7 resgate avancado");
        return 1;
    }
    if (jobid == JOB_POLICIAL || jobid == JOB_PRF || jobid == JOB_POLICIA_FEDERAL || jobid == JOB_POLICIA_CIVIL || jobid == JOB_POLICIA_PENAL)
    {
        if (level >= 10) format(output, size, "N10: operacoes especiais, maior reputacao e prioridade em chamados 190");
        else if (level >= 7) format(output, size, "N7: investigacao/operacao e chamados de maior risco");
        else if (level >= 5) format(output, size, "N5: viatura melhor e mandados/fiscalizacao reforcada");
        else if (level >= 3) format(output, size, "N3: blitz, abordagem e prova com bonus de XP");
        else format(output, size, "Proximo: N3 blitz, N5 viatura, N7 operacao");
        return 1;
    }
    if (jobid == JOB_MEDICO || jobid == JOB_MOTORISTA_AMBULANCIA)
    {
        if (level >= 10) format(output, size, "N10: chefe de plantao, cirurgia e maior prioridade 192");
        else if (level >= 7) format(output, size, "N7: transferencia e ocorrencia grave");
        else if (level >= 5) format(output, size, "N5: ambulancia/atendimento avancado");
        else if (level >= 3) format(output, size, "N3: triagem rapida e internacao com bonus");
        else format(output, size, "Proximo: N3 triagem, N5 ambulancia, N7 transferencia");
        return 1;
    }
    if (jobid == JOB_CAMINHONEIRO)
    {
        if (level >= 10) format(output, size, "N10: mestre logistico, carga perigosa e contratos maiores");
        else if (level >= 7) format(output, size, "N7: frete estadual e prioridade no estoque da cidade");
        else if (level >= 5) format(output, size, "N5: caminhoes melhores e frete industrial");
        else if (level >= 3) format(output, size, "N3: frete local com manifesto e bonus");
        else format(output, size, "Proximo: N3 frete local, N5 industrial, N7 estadual");
        return 1;
    }
    if (level >= 10)
    {
        format(output, size, "N10: mestre, XP extra, score e maior pagamento de carreira");
        return 1;
    }
    if (level >= 7)
    {
        format(output, size, "N7: prioridade em evento/horario e cadeia produtiva");
        return 1;
    }
    if (level >= 5)
    {
        if (Job_GetLevelVehicle(jobid, level, 0) > 0)
        {
            format(output, size, "N5: veiculo de servico melhor quando nao houver frota fixa");
            return 1;
        }
        format(output, size, "N5: reputacao profissional reforcada");
        return 1;
    }
    if (level >= 3)
    {
        format(output, size, "N3: bonus de produtividade em rota completa e conquista");
        return 1;
    }
    format(output, size, "Proximo: N3 bonus, N5 veiculo, N7 prioridade, N10 mestre");
    return 1;
}

stock Job_GetRequirementText(requirement, output[], size = sizeof(output))
{
    output[0] = 0;

    if (requirement == JOB_REQ_NONE)
    {
        format(output, size, "Nenhum");
        return 1;
    }

    if (requirement & JOB_REQ_CNH)
    {
        strcat(output, "CNH ", size);
    }
    if (requirement & JOB_REQ_HEAVY)
    {
        strcat(output, "Licenca Pesada ", size);
    }
    if (requirement & JOB_REQ_MEDICAL)
    {
        strcat(output, "Diploma Medico ", size);
    }
    if (requirement & JOB_REQ_OAB)
    {
        strcat(output, "OAB ", size);
    }
    if (requirement & JOB_REQ_PUBLIC)
    {
        strcat(output, "Cargo Publico ", size);
    }
    if (requirement & JOB_REQ_POLICE)
    {
        strcat(output, "Porte/Aprovacao Policial ", size);
    }
    return 1;
}

stock Job_PlayerMeetsRequirement(playerid, requirement, showError = 1)
{
    new requiredText[96];
    new trustedMask = JOB_REQ_MEDICAL | JOB_REQ_OAB | JOB_REQ_PUBLIC | JOB_REQ_POLICE;

    if (requirement == JOB_REQ_NONE)
    {
        return 1;
    }

    if ((requirement & trustedMask) && !Life_CheckScoreGate(playerid, gCfgCitizenJobTrustedMinScore, "Emprego sensivel"))
    {
        return 0;
    }

    if ((requirement & trustedMask) && Life_HasOpenJusticeRisk(playerid))
    {
        if (showError) SendClientMessage(playerid, COLOR_RED, "Emprego sensivel bloqueado enquanto houver caso judicial aberto ou audiencia pendente.");
        return 0;
    }

    if ((requirement & JOB_REQ_CNH) && !PlayerInfo[playerid][pLicenseCNH])
    {
        Job_GetRequirementText(requirement, requiredText, sizeof(requiredText));
        if (showError) SendClientMessage(playerid, COLOR_RED, "Voce nao atende aos requisitos de licenca para este emprego.");
        if (showError) SendClientMessage(playerid, COLOR_GRAY, requiredText);
        return 0;
    }

    if ((requirement & JOB_REQ_HEAVY) && !PlayerInfo[playerid][pLicenseHeavy])
    {
        Job_GetRequirementText(requirement, requiredText, sizeof(requiredText));
        if (showError) SendClientMessage(playerid, COLOR_RED, "Voce precisa de licenca pesada para este emprego.");
        if (showError) SendClientMessage(playerid, COLOR_GRAY, requiredText);
        return 0;
    }

    if ((requirement & JOB_REQ_MEDICAL) && !PlayerInfo[playerid][pLicenseMedical])
    {
        if (showError) SendClientMessage(playerid, COLOR_RED, "Voce precisa de diploma/licenca medica.");
        return 0;
    }

    if ((requirement & JOB_REQ_OAB) && !PlayerInfo[playerid][pLicenseOAB])
    {
        if (showError) SendClientMessage(playerid, COLOR_RED, "Voce precisa de OAB.");
        return 0;
    }

    if ((requirement & JOB_REQ_PUBLIC) && !PlayerInfo[playerid][pLicensePublic])
    {
        if (showError) SendClientMessage(playerid, COLOR_RED, "Voce precisa de cargo publico aprovado.");
        return 0;
    }

    if ((requirement & JOB_REQ_POLICE) && !PlayerInfo[playerid][pLicensePolice] && !HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        if (showError) SendClientMessage(playerid, COLOR_RED, "Voce precisa de aprovacao policial ou permissao staff.");
        return 0;
    }

    return 1;
}

stock Job_GetAccessLevelRequirement(jobid)
{
    switch (jobid)
    {
        case JOB_FRENTISTA, JOB_GARCOM, JOB_VENDEDOR, JOB_PESCADOR, JOB_CAIXA_REPOSITOR, JOB_BARTENDER:
        {
            return 1;
        }
        case JOB_ENTREGADOR, JOB_MOTOBOY, JOB_AGRICULTOR, JOB_PADEIRO_PIZZAIOLO, JOB_RECEPCIONISTA_HOTEL:
        {
            return 5;
        }
        case JOB_TAXISTA, JOB_MECANICO, JOB_PEDREIRO, JOB_TECNICO, JOB_SEGURANCA, JOB_FARMACEUTICO, JOB_MOTORISTA_APP, JOB_ENCANADOR, JOB_JARDINEIRO, JOB_ZELADOR:
        {
            return 10;
        }
        case JOB_CAMINHONEIRO, JOB_MINERADOR, JOB_COZINHEIRO, JOB_JORNALISTA, JOB_ADVOGADO, JOB_BANCARIO, JOB_CORRETOR_IMOVEIS, JOB_CONTADOR, JOB_GUINCHEIRO, JOB_OPERADOR_FABRICA:
        {
            return 15;
        }
        case JOB_LIXEIRO, JOB_CARTEIRO, JOB_AGENTE_DETRAN:
        {
            return 20;
        }
        case JOB_MOTORISTA_ONIBUS, JOB_FUNCIONARIO_PREFEITURA:
        {
            return 25;
        }
        case JOB_MOTORISTA_AMBULANCIA, JOB_PROFESSOR:
        {
            return 30;
        }
        case JOB_BOMBEIRO, JOB_ASSISTENTE_SOCIAL:
        {
            return 35;
        }
        case JOB_MEDICO, JOB_ESCRIVAO:
        {
            return 40;
        }
        case JOB_POLICIAL, JOB_OFICIAL_JUSTICA:
        {
            return 45;
        }
        case JOB_PRF, JOB_PERITO_CRIMINAL, JOB_DEFENSOR_PUBLICO:
        {
            return 50;
        }
        case JOB_POLICIA_CIVIL, JOB_POLICIA_PENAL, JOB_PROMOTOR:
        {
            return 55;
        }
        case JOB_POLICIA_FEDERAL:
        {
            return 60;
        }
        case JOB_JUIZ:
        {
            return 65;
        }
    }
    return 1;
}

stock Job_GetAccessTypeText(jobid, output[], size = sizeof(output))
{
    if (Job_IsPublicServiceJob(jobid))
    {
        format(output, size, "Publico");
    }
    else
    {
        format(output, size, "Privado");
    }
    return 1;
}

stock Job_GetMonthlySalary(jobid)
{
    switch (jobid)
    {
        case JOB_ENTREGADOR: return 2400;
        case JOB_LIXEIRO: return 1900;
        case JOB_MOTORISTA_ONIBUS: return 2850;
        case JOB_TAXISTA: return 2500;
        case JOB_CAMINHONEIRO: return 2660;
        case JOB_MECANICO: return 2460;
        case JOB_FRENTISTA: return 1800;
        case JOB_POLICIAL: return 5000;
        case JOB_MEDICO: return 4800;
        case JOB_BOMBEIRO: return 4560;
        case JOB_SEGURANCA: return 2200;
        case JOB_CARTEIRO: return 2200;
        case JOB_MOTOBOY: return 2400;
        case JOB_PESCADOR: return 2210;
        case JOB_AGRICULTOR: return 2210;
        case JOB_MINERADOR: return 3000;
        case JOB_PEDREIRO: return 2550;
        case JOB_GARCOM: return 1970;
        case JOB_COZINHEIRO: return 2100;
        case JOB_VENDEDOR: return 2090;
        case JOB_JORNALISTA: return 5220;
        case JOB_ADVOGADO: return 4800;
        case JOB_JUIZ: return 30000;
        case JOB_MOTORISTA_AMBULANCIA: return 2530;
        case JOB_TECNICO: return 2290;
        case JOB_PRF: return 12250;
        case JOB_POLICIA_FEDERAL: return 14165;
        case JOB_POLICIA_CIVIL: return 6290;
        case JOB_POLICIA_PENAL: return 4700;
        case JOB_AGENTE_DETRAN: return 3200;
        case JOB_FUNCIONARIO_PREFEITURA: return 2800;
        case JOB_BANCARIO: return 3900;
        case JOB_CORRETOR_IMOVEIS: return 3200;
        case JOB_CONTADOR: return 4500;
        case JOB_PROFESSOR: return 4200;
        case JOB_FARMACEUTICO: return 4100;
        case JOB_ASSISTENTE_SOCIAL: return 3600;
        case JOB_PERITO_CRIMINAL: return 8500;
        case JOB_CAIXA_REPOSITOR: return 1900;
        case JOB_BARTENDER: return 2100;
        case JOB_PADEIRO_PIZZAIOLO: return 2200;
        case JOB_RECEPCIONISTA_HOTEL: return 2100;
        case JOB_GUINCHEIRO: return 2600;
        case JOB_MOTORISTA_APP: return 2600;
        case JOB_ENCANADOR: return 2800;
        case JOB_JARDINEIRO: return 2100;
        case JOB_ZELADOR: return 2000;
        case JOB_OPERADOR_FABRICA: return 2700;
        case JOB_PROMOTOR: return 16000;
        case JOB_DEFENSOR_PUBLICO: return 12000;
        case JOB_OFICIAL_JUSTICA: return 6500;
        case JOB_ESCRIVAO: return 5200;
    }
    return 2350;
}

stock Job_FormatSelectionPay(jobid, output[], size = sizeof(output))
{
    new salary = Job_GetMonthlySalary(jobid);

    if (Job_IsPublicServiceJob(jobid))
    {
        format(output, size, "Salario $%d", salary);
    }
    else
    {
        format(output, size, "Salario $%d + bonus", salary);
    }
    return 1;
}

stock Job_GetSideGigPay(jobid)
{
    new dailySalary = Job_GetMonthlySalary(jobid) / 30;
    new pay = (dailySalary * JOB_SIDE_GIG_PAY_PERCENT) / 100;

    if (pay < JOB_SIDE_GIG_MIN_PAY)
    {
        pay = JOB_SIDE_GIG_MIN_PAY;
    }
    return pay;
}

stock Job_PlayerMeetsAccessLevel(playerid, jobid, showError = 1)
{
    new minLevel;
    new jobLabel[32];
    new message[144];

    if (jobid == JOB_NONE || HasAdminLevel(playerid, ADMIN_LEVEL_HELPER))
    {
        return 1;
    }

    minLevel = Job_GetAccessLevelRequirement(jobid);
    if (PlayerInfo[playerid][pLevel] >= minLevel)
    {
        return 1;
    }

    if (showError)
    {
        GetJobName(jobid, jobLabel, sizeof(jobLabel));
        format(message, sizeof(message), "%s exige nivel %d. Seu nivel atual: %d.", jobLabel, minLevel, PlayerInfo[playerid][pLevel]);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        SendClientMessage(playerid, COLOR_GRAY, "Evolua o level geral do personagem para liberar novas profissoes.");
    }
    return 0;
}

stock Job_ArePlayersClose(playerid, targetid)
{
    new Float:x;
    new Float:y;
    new Float:z;

    if (!IsValidConnectedPlayer(targetid) || GetPlayerInterior(playerid) != GetPlayerInterior(targetid) || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(targetid))
    {
        return 0;
    }

    GetPlayerPos(targetid, x, y, z);
    return IsPlayerInRangeOfPoint(playerid, WORK_SERVICE_DISTANCE, x, y, z);
}

stock Job_IsPlayerNearWorkplace(playerid, jobid)
{
    new locationid = Job_GetLocation(jobid);

    if (Prop_EditorAtJobBusiness(playerid, jobid))
    {
        return 1;
    }

    if (locationid < 0)
    {
        return 0;
    }

    if (World_IsPlayerAtServiceInterior(playerid, locationid))
    {
        return 1;
    }

    if (GetPlayerInterior(playerid) != gServerLocations[locationid][locInterior] || GetPlayerVirtualWorld(playerid) != gServerLocations[locationid][locVirtualWorld])
    {
        return 0;
    }

    return IsPlayerInRangeOfPoint(playerid, WORK_START_DISTANCE, gServerLocations[locationid][locX], gServerLocations[locationid][locY], gServerLocations[locationid][locZ]);
}

stock Work_GetRoutePointCount(routeid)
{
    new index;
    new total;

    for (index = 0; index < sizeof(gWorkPoints); index++)
    {
        if (gWorkPoints[index][pointRoute] == routeid)
        {
            total++;
        }
    }
    return total;
}

stock Work_GetRoutePoint(routeid, step, name[], size = sizeof(name), &Float:x, &Float:y, &Float:z)
{
    new index;
    new current;

    for (index = 0; index < sizeof(gWorkPoints); index++)
    {
        if (gWorkPoints[index][pointRoute] != routeid)
        {
            continue;
        }

        if (current == step)
        {
            format(name, size, "%s", gWorkPoints[index][pointName]);
            x = gWorkPoints[index][pointX];
            y = gWorkPoints[index][pointY];
            z = gWorkPoints[index][pointZ];
            return 1;
        }
        current++;
    }
    return 0;
}

stock Work_DestroyVehicle(playerid)
{
    if (gWorkVehicleFromFleet[playerid])
    {
        JobVehicle_ReleasePlayer(playerid, 1);
        return 1;
    }

    if (gWorkVehicle[playerid] != 0 && gWorkVehicle[playerid] != INVALID_VEHICLE_ID)
    {
        DestroyVehicle(gWorkVehicle[playerid]);
    }

    gWorkVehicle[playerid] = 0;
    gWorkVehicleFromFleet[playerid] = 0;
    return 1;
}

stock Work_ApplyUniform(playerid, jobIndex)
{
    if (jobIndex == -1 || gJobs[jobIndex][jobSkin] < 0)
    {
        return 0;
    }

    gWorkOldSkin[playerid] = PlayerInfo[playerid][pSkin];
    gWorkUniformActive[playerid] = 1;
    SetPlayerSkin(playerid, gJobs[jobIndex][jobSkin]);
    return 1;
}

stock Work_RestoreUniform(playerid)
{
    if (!gWorkUniformActive[playerid])
    {
        return 0;
    }

    SetPlayerSkin(playerid, gWorkOldSkin[playerid]);
    PlayerInfo[playerid][pSkin] = gWorkOldSkin[playerid];
    gWorkUniformActive[playerid] = 0;
    return 1;
}

stock Work_GiveDutyArmour(playerid, Float:amount)
{
    new Float:currentArmour;

    GetPlayerArmour(playerid, currentArmour);
    if (currentArmour < amount)
    {
        SetPlayerArmour(playerid, amount);
    }
    return 1;
}

stock Work_GiveEquipment(playerid, jobid)
{
    if (IsLawEnforcementJob(jobid))
    {
        GivePlayerWeapon(playerid, WEAPON_COLT45, 120);
        if (jobid == JOB_PRF || jobid == JOB_POLICIA_FEDERAL)
        {
            GivePlayerWeapon(playerid, WEAPON_MP5, 180);
            GivePlayerWeapon(playerid, WEAPON_M4, 120);
            Work_GiveDutyArmour(playerid, 85.0);
        }
        else
        {
            GivePlayerWeapon(playerid, WEAPON_SHOTGUN, 48);
            GivePlayerWeapon(playerid, WEAPON_MP5, 150);
            Work_GiveDutyArmour(playerid, 75.0);
        }
        SendClientMessage(playerid, COLOR_BLUE, "Seguranca publica: pistola pessoal + duas armas de servico e colete recebidos.");
        return 1;
    }

    switch (jobid)
    {
        case JOB_SEGURANCA:
        {
            GivePlayerWeapon(playerid, WEAPON_COLT45, 100);
            GivePlayerWeapon(playerid, WEAPON_SHOTGUN, 36);
            GivePlayerWeapon(playerid, WEAPON_MP5, 120);
            Work_GiveDutyArmour(playerid, 50.0);
            SendClientMessage(playerid, COLOR_BLUE, "Seguranca: pistola pessoal + duas armas de servico e colete recebidos.");
        }
        case JOB_BOMBEIRO:
        {
            GivePlayerWeapon(playerid, WEAPON_FIREEXTINGUISHER, 500);
            SendClientMessage(playerid, COLOR_BLUE, "Equipamento recebido: extintor.");
        }
        case JOB_MEDICO, JOB_MOTORISTA_AMBULANCIA:
        {
            GivePlayerWeapon(playerid, WEAPON_SPRAYCAN, 200);
            SendClientMessage(playerid, COLOR_BLUE, "Kit medico recebido. Use /curar [id] perto do paciente.");
        }
        case JOB_MECANICO, JOB_TECNICO:
        {
            GivePlayerWeapon(playerid, WEAPON_SPRAYCAN, 200);
            SendClientMessage(playerid, COLOR_BLUE, "Ferramentas de servico recebidas.");
        }
        case JOB_JORNALISTA:
        {
            GivePlayerWeapon(playerid, WEAPON_CAMERA, 60);
            SendClientMessage(playerid, COLOR_BLUE, "Camera de reportagem recebida.");
        }
    }
    return 1;
}

stock Work_ClearEquipment(playerid, jobid)
{
    if (
        IsPublicSecurityJob(jobid) ||
        jobid == JOB_BOMBEIRO ||
        jobid == JOB_MEDICO ||
        jobid == JOB_MOTORISTA_AMBULANCIA ||
        jobid == JOB_MECANICO ||
        jobid == JOB_TECNICO ||
        jobid == JOB_JORNALISTA
    )
    {
        ResetPlayerWeapons(playerid);
        SetPlayerArmour(playerid, 0.0);
    }
    return 1;
}

stock Work_ApplyPenalty(playerid)
{
    new message[96];

    if (Bank_TakePayment(playerid, Cfg_Price(gCfgWorkAbandonPenalty), 0))
    {
        format(message, sizeof(message), "Penalidade por abandonar expediente: $%d.", Cfg_Price(gCfgWorkAbandonPenalty));
        SendClientMessage(playerid, COLOR_ORANGE, message);
        SaveAccountData(playerid, 0);
    }
    return 1;
}

stock Work_SetCheckpoint(playerid)
{
    new jobIndex = Job_GetIndex(PlayerInfo[playerid][pJob]);
    new pointLabel[32];
    new jobLabel[32];
    new message[128];
    new Float:x;
    new Float:y;
    new Float:z;
    new total;

    if (!gWorkActive[playerid] || jobIndex == -1)
    {
        return 0;
    }

    total = Work_GetActiveTargetSteps(playerid);
    if (!Work_GetRoutePoint(gWorkRoute[playerid], gWorkStep[playerid], pointLabel, sizeof(pointLabel), x, y, z))
    {
        return 0;
    }

    GetJobName(PlayerInfo[playerid][pJob], jobLabel, sizeof(jobLabel));
    SetPlayerCheckpoint(playerid, x, y, z, WORK_CHECKPOINT_SIZE);
    gWorkCheckpointTick[playerid] = GetTickCount();
    format(message, sizeof(message), "%s: tarefa %d/%d marcada - %s.", jobLabel, gWorkStep[playerid] + 1, total, pointLabel);
    SendClientMessage(playerid, COLOR_YELLOW, message);
    return 1;
}

stock Work_Cancel(playerid, notify = 1)
{
    if (!gWorkActive[playerid])
    {
        return 0;
    }

    if (notify && gWorkStep[playerid] > 0)
    {
        Work_ApplyPenalty(playerid);
        if (Work_IsEnhancedJob(PlayerInfo[playerid][pJob]))
        {
            Work_ResetStreak(playerid);
            SendClientMessage(playerid, COLOR_ORANGE, "Sequencia de trabalho perdida por abandonar o expediente.");
        }
    }

    gWorkActive[playerid] = 0;
    gWorkStep[playerid] = 0;
    gWorkRoute[playerid] = 0;
    gWorkCheckpointTick[playerid] = 0;
    Work_ResetRunState(playerid);
    Cargo_Reset(playerid);
    Work_DestroyVehicle(playerid);
    Work_RestoreUniform(playerid);
    Work_ClearEquipment(playerid, PlayerInfo[playerid][pJob]);
    DisablePlayerCheckpoint(playerid);

    if (notify)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Expediente encerrado.");
    }
    return 1;
}

stock Work_Start(playerid)
{
    new jobIndex = Job_GetIndex(PlayerInfo[playerid][pJob]);
    new locationid;
    new vehicleid;
    new message[144];
    new jobLabel[32];
    new workModel;
    new routeTotal;

    if (!PlayerInfo[playerid][pDocuments])
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa emitir documentos na Prefeitura antes de trabalhar.");
        return 1;
    }

    if (jobIndex == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao tem emprego. Escolha um na Prefeitura.");
        return 1;
    }

    if (!Job_PlayerMeetsAccessLevel(playerid, PlayerInfo[playerid][pJob]))
    {
        return 1;
    }

    if (!Job_PlayerMeetsRequirement(playerid, gJobs[jobIndex][jobRequirement]))
    {
        return 1;
    }

    if (PlayerInfo[playerid][pJob] == JOB_CAMINHONEIRO && !Life_CanStartTruckLogistics(playerid))
    {
        return 1;
    }

    if (gWorkActive[playerid])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce ja esta em expediente.");
        Work_SetCheckpoint(playerid);
        return 1;
    }

    if (!Job_IsPlayerNearWorkplace(playerid, PlayerInfo[playerid][pJob]))
    {
        locationid = gJobs[jobIndex][jobLocation];
        format(message, sizeof(message), "Va ate %s para bater ponto.", gServerLocations[locationid][locName]);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        SetPlayerGps(playerid, locationid);
        return 1;
    }

    routeTotal = Work_GetRoutePointCount(gJobs[jobIndex][jobRoute]);
    if (routeTotal <= 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Este emprego ainda nao possui rota configurada.");
        return 1;
    }

    locationid = gJobs[jobIndex][jobLocation];
    if (World_IsPlayerAtServiceInterior(playerid, locationid))
    {
        World_ExitAutoInterior(playerid, 0);
    }

    workModel = Job_GetLevelVehicle(PlayerInfo[playerid][pJob], Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob]), gJobs[jobIndex][jobVehicleModel]);
    if (workModel > 0)
    {
        if (!JobVehicle_AssignPlayer(playerid, PlayerInfo[playerid][pJob], vehicleid))
        {
            vehicleid = CreateVehicle(workModel, gServerLocations[locationid][locX] + 3.0, gServerLocations[locationid][locY], gServerLocations[locationid][locZ], gServerLocations[locationid][locA], 1, 1, -1);
            if (vehicleid == INVALID_VEHICLE_ID)
            {
                SendClientMessage(playerid, COLOR_RED, "Nao foi possivel criar o veiculo de trabalho.");
                return 1;
            }

            LinkVehicleToInterior(vehicleid, gServerLocations[locationid][locInterior]);
            SetVehicleVirtualWorld(vehicleid, gServerLocations[locationid][locVirtualWorld]);
            Fuel_InitVehicle(vehicleid, FUEL_MAX_VALUE, 0);
            PutPlayerInVehicle(playerid, vehicleid, 0);
            gWorkVehicle[playerid] = vehicleid;
            gWorkVehicleFromFleet[playerid] = 0;
        }
    }

    gWorkActive[playerid] = 1;
    gWorkStep[playerid] = 0;
    gWorkRoute[playerid] = gJobs[jobIndex][jobRoute];
    gWorkLastTaskTick[playerid] = 0;
    gWorkCheckpointTick[playerid] = 0;
    Work_ResetRunState(playerid);
    if (gWorkStreakJob[playerid] != PlayerInfo[playerid][pJob])
    {
        gWorkRouteStreak[playerid] = 0;
        gWorkStreakJob[playerid] = PlayerInfo[playerid][pJob];
    }
    gWorkSpecialMode[playerid] = Work_ChooseSpecialMode(playerid, PlayerInfo[playerid][pJob]);
    gWorkRouteTargetSteps[playerid] = Work_ChooseRouteSize(playerid, PlayerInfo[playerid][pJob], routeTotal);
    Delivery_StartRun(playerid);
    Taxi_StartRun(playerid);
    Mechanic_StartRun(playerid);
    Work_SetRouteDeadline(playerid);
    Work_ApplyUniform(playerid, jobIndex);
    Work_GiveEquipment(playerid, PlayerInfo[playerid][pJob]);
    if (PlayerInfo[playerid][pJob] == JOB_CAMINHONEIRO)
    {
        Cargo_StartForTruck(playerid);
    }

    GetJobName(PlayerInfo[playerid][pJob], jobLabel, sizeof(jobLabel));
    format(message, sizeof(message), "Expediente iniciado: %s. Siga os checkpoints e conclua as tarefas.", jobLabel);
    SendClientMessage(playerid, COLOR_GREEN, message);
    Work_SetCheckpoint(playerid);
    Work_SendRouteHint(playerid);
    Work_SendSpecialStart(playerid);
    Work_SendRoutePace(playerid);
    return 1;
}

stock Work_SendRouteHint(playerid)
{
    switch (gWorkRoute[playerid])
    {
        case ROUTE_DELIVERY:
        {
            SendClientMessage(playerid, COLOR_YELLOW, "Entregador: rotas curtas, medias e longas podem virar expressas/fragueis. Prazo, sequencia e tamanho alteram bonus.");
        }
        case ROUTE_TAXI:
        {
            SendClientMessage(playerid, COLOR_YELLOW, "Taxista: corridas curtas, medias e longas usam taximetro automatico, avaliacao e bonus por direcao limpa.");
        }
        case ROUTE_MECHANIC:
        {
            SendClientMessage(playerid, COLOR_YELLOW, "Mecanico: chamados tem diagnostico, pecas, orcamento, avaliacao e bonus por sequencia.");
        }
        case ROUTE_TRUCK:
        {
            SendClientMessage(playerid, COLOR_YELLOW, "Caminhoneiro: sua carga tem manifesto/nota fiscal. Use /notafiscal e pare em postos PRF quando solicitado.");
        }
        case ROUTE_DETRAN, ROUTE_PREFEITURA, ROUTE_BANKER, ROUTE_REALTOR, ROUTE_ACCOUNTANT, ROUTE_TEACHER, ROUTE_PHARMACY, ROUTE_SOCIAL, ROUTE_FORENSIC, ROUTE_MARKET_STAFF, ROUTE_BARTENDER, ROUTE_BAKER_PIZZA, ROUTE_HOTEL_RECEPTION, ROUTE_TOW_DRIVER, ROUTE_APP_DRIVER, ROUTE_PLUMBER, ROUTE_GARDENER, ROUTE_CARETAKER, ROUTE_FACTORY, ROUTE_PROSECUTOR, ROUTE_PUBLIC_DEFENDER, ROUTE_COURT_OFFICER, ROUTE_CLERK:
        {
            SendClientMessage(playerid, COLOR_YELLOW, "Tarefa automatica: siga os checkpoints do atendimento, conclua o protocolo e retorne a base.");
        }
    }
    return 1;
}

stock Work_FinishStep(playerid)
{
    new jobIndex = Job_GetIndex(PlayerInfo[playerid][pJob]);
    new message[128];
    new pointLabel[32];
    new Float:x;
    new Float:y;
    new Float:z;
    new total;
    new level;
    new payment;
    new bonus;
    new bonusPercent;
    new xpReward;
    new xpBonusReward;
    new streakBonus;
    new specialBonus;
    new routeSizeBonus;
    new packageBonus;
    new deliveryRating;
    new deliveryRatingBonus;
    new passengerBonus;
    new taxiRating;
    new taxiRatingBonus;
    new mechanicBonus;
    new mechanicRating;
    new mechanicRatingBonus;
    new eventApplied;

    if (!gWorkActive[playerid])
    {
        Security_AddAlert(playerid, "JOB_EXPLOIT", "tentou receber pagamento sem expediente");
        return 1;
    }

    if (jobIndex == -1)
    {
        Work_Cancel(playerid, 0);
        return 1;
    }

    level = Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob]);
    bonusPercent = Life_GetJobPayBonusPercent(playerid, PlayerInfo[playerid][pJob]);
    payment = Job_GetEffectivePay(PlayerInfo[playerid][pJob], Cfg_GetJobPay(PlayerInfo[playerid][pJob], gJobs[jobIndex][jobPay]), level);
    if (Job_IsPrivateBonusEligible(PlayerInfo[playerid][pJob]) && bonusPercent > 0)
    {
        payment += (payment * bonusPercent) / 100;
    }
    payment = Vip_ApplyCashBonus(playerid, payment);
    xpReward = Job_GetXpReward(gCfgJobXpPerTask, level);
    Work_GetRoutePoint(gWorkRoute[playerid], gWorkStep[playerid], pointLabel, sizeof(pointLabel), x, y, z);
    if (Delivery_TryWrongAddress(playerid, pointLabel))
    {
        return 1;
    }
    eventApplied = Work_TryRouteEvent(playerid, pointLabel);
    if (eventApplied)
    {
        payment += payment / 10;
        xpReward += 25;
    }
    if (PlayerInfo[playerid][pJob] == JOB_ENTREGADOR)
    {
        packageBonus = Delivery_GetPackageBonusPercent(gDeliveryPackageType[playerid]);
        if (packageBonus > 0)
        {
            payment += (payment * packageBonus) / 100;
        }
        xpReward += Delivery_GetPackageXpBonus(gDeliveryPackageType[playerid]);
    }
    else if (PlayerInfo[playerid][pJob] == JOB_TAXISTA)
    {
        passengerBonus = Taxi_GetPassengerBonusPercent(gTaxiPassengerType[playerid]);
        if (passengerBonus > 0)
        {
            payment += (payment * passengerBonus) / 100;
        }
        xpReward += Taxi_GetPassengerXpBonus(gTaxiPassengerType[playerid]);
    }
    else if (PlayerInfo[playerid][pJob] == JOB_MECANICO)
    {
        mechanicBonus = Mech_GetDiagBonusPercent(gMechanicDiagnosis[playerid]);
        if (mechanicBonus > 0)
        {
            payment += (payment * mechanicBonus) / 100;
        }
        xpReward += Mech_GetDiagXpBonus(gMechanicDiagnosis[playerid]);
    }
    if (!Job_GiveReward(playerid, PlayerInfo[playerid][pJob], payment, xpReward, "job_route_step", 0))
    {
        Work_SetCheckpoint(playerid);
        return 1;
    }
    gWorkStep[playerid]++;
    gWorkLastTaskTick[playerid] = GetTickCount();

    if (Job_IsPrivateBonusEligible(PlayerInfo[playerid][pJob]))
    {
        format(message, sizeof(message), "Servico privado concluido: %s. Salario/bonus: $%d | XP +%d | bonus nivel %d%% + evento cidade %d%%.", pointLabel, payment, xpReward, Job_GetLevelBonusPercent(level), bonusPercent);
    }
    else
    {
        format(message, sizeof(message), "Servico publico concluido: %s. Salario: $%d | XP +%d.", pointLabel, payment, xpReward);
    }
    SendClientMessage(playerid, COLOR_GREEN, message);

    total = Work_GetActiveTargetSteps(playerid);
    if (gWorkStep[playerid] >= total)
    {
        if (Job_IsPrivateBonusEligible(PlayerInfo[playerid][pJob]))
        {
            bonus = Job_GetEffectivePay(PlayerInfo[playerid][pJob], Cfg_GetJobBonus(PlayerInfo[playerid][pJob], gJobs[jobIndex][jobBonus]), level);
        }
        else
        {
            bonus = 0;
        }
        streakBonus = Work_GetStreakBonusPercent(playerid);
        specialBonus = Work_GetSpecialBonusPercent(playerid);
        routeSizeBonus = Work_GetRouteSizeBonusPercent(playerid);
        if (PlayerInfo[playerid][pJob] == JOB_ENTREGADOR)
        {
            deliveryRating = Delivery_CalculateRating(playerid);
            deliveryRatingBonus = Delivery_GetRatingBonusPercent(deliveryRating);
        }
        else if (PlayerInfo[playerid][pJob] == JOB_TAXISTA)
        {
            taxiRating = Taxi_CalculateRating(playerid);
            taxiRatingBonus = Taxi_GetRatingBonusPercent(taxiRating);
        }
        else if (PlayerInfo[playerid][pJob] == JOB_MECANICO)
        {
            mechanicRating = Mechanic_CalculateRating(playerid);
            mechanicRatingBonus = Mechanic_GetRatingBonusPercent(mechanicRating);
        }
        if (bonus > 0 && level >= 3)
        {
            bonus += bonus / 10;
        }
        if (bonus > 0 && bonusPercent > 0)
        {
            bonus += (bonus * bonusPercent) / 100;
        }
        if (bonus > 0 && streakBonus > 0)
        {
            bonus += (bonus * streakBonus) / 100;
        }
        if (bonus > 0 && specialBonus > 0)
        {
            bonus += (bonus * specialBonus) / 100;
        }
        if (bonus > 0 && routeSizeBonus > 0)
        {
            bonus += (bonus * routeSizeBonus) / 100;
        }
        if (bonus > 0 && deliveryRatingBonus != 0)
        {
            bonus += (bonus * deliveryRatingBonus) / 100;
            if (bonus < 0)
            {
                bonus = 0;
            }
        }
        if (bonus > 0 && taxiRatingBonus != 0)
        {
            bonus += (bonus * taxiRatingBonus) / 100;
            if (bonus < 0)
            {
                bonus = 0;
            }
        }
        if (bonus > 0 && mechanicRatingBonus != 0)
        {
            bonus += (bonus * mechanicRatingBonus) / 100;
            if (bonus < 0)
            {
                bonus = 0;
            }
        }
        bonus = Vip_ApplyCashBonus(playerid, bonus);
        xpBonusReward = Job_GetXpReward(gCfgJobXpCompleteBonus, level);
        if (routeSizeBonus > 0)
        {
            xpBonusReward += routeSizeBonus * 2;
        }
        if (gWorkRouteEvent[playerid])
        {
            xpBonusReward += 50;
        }
        if (deliveryRating >= 4)
        {
            xpBonusReward += deliveryRating * 5;
        }
        if (taxiRating >= 4)
        {
            xpBonusReward += taxiRating * 5;
        }
        if (mechanicRating >= 4)
        {
            xpBonusReward += mechanicRating * 5;
        }
        if (Job_GiveReward(playerid, PlayerInfo[playerid][pJob], bonus, xpBonusReward, "job_route_complete", 1))
        {
            if (!Job_IsPrivateBonusEligible(PlayerInfo[playerid][pJob]))
            {
                if (Work_IsEnhancedJob(PlayerInfo[playerid][pJob]))
                {
                    gWorkRouteStreak[playerid]++;
                    gWorkStreakJob[playerid] = PlayerInfo[playerid][pJob];
                    format(message, sizeof(message), "Expediente publico completo. Salario fixo mantido | XP +%d | sequencia %d.", xpBonusReward, gWorkRouteStreak[playerid]);
                }
                else
                {
                    format(message, sizeof(message), "Expediente publico completo. Salario fixo mantido | XP +%d.", xpBonusReward);
                }
            }
            else if (Work_IsEnhancedJob(PlayerInfo[playerid][pJob]))
            {
                gWorkRouteStreak[playerid]++;
                gWorkStreakJob[playerid] = PlayerInfo[playerid][pJob];
                format(message, sizeof(message), "Expediente completo. Bonus: $%d | XP +%d | sequencia %d (+%d%%) | rota +%d%%.", bonus, xpBonusReward, gWorkRouteStreak[playerid], Work_GetStreakBonusPercent(playerid), routeSizeBonus);
            }
            else
            {
                format(message, sizeof(message), "Expediente completo. Bonus: $%d | XP +%d.", bonus, xpBonusReward);
            }
            SendClientMessage(playerid, COLOR_GREEN, message);
            if (PlayerInfo[playerid][pJob] == JOB_ENTREGADOR)
            {
                format(message, sizeof(message), "Avaliacao do cliente: %d/5 | ajuste bonus %+d%%.", deliveryRating, deliveryRatingBonus);
                SendClientMessage(playerid, deliveryRating >= 4 ? COLOR_GREEN : COLOR_ORANGE, message);
                Delivery_RecordCompletion(playerid, deliveryRating);
                Delivery_ApplyMarketStock(playerid);
            }
            else if (PlayerInfo[playerid][pJob] == JOB_TAXISTA)
            {
                format(message, sizeof(message), "Avaliacao do passageiro: %d/5 | ajuste bonus %+d%%.", taxiRating, taxiRatingBonus);
                SendClientMessage(playerid, taxiRating >= 4 ? COLOR_GREEN : COLOR_ORANGE, message);
                Taxi_RecordCompletion(playerid, taxiRating);
            }
            else if (PlayerInfo[playerid][pJob] == JOB_MECANICO)
            {
                format(message, sizeof(message), "Avaliacao do cliente: %d/5 | pecas %d | ajuste bonus %+d%%.", mechanicRating, gMechanicPartsUsed[playerid], mechanicRatingBonus);
                SendClientMessage(playerid, mechanicRating >= 4 ? COLOR_GREEN : COLOR_ORANGE, message);
                Mechanic_RecordCompletion(playerid, mechanicRating);
            }
        }
        else
        {
            SendClientMessage(playerid, COLOR_ORANGE, "Expediente completo, mas o bonus foi bloqueado pelo anti-farm.");
        }
        if (PlayerInfo[playerid][pJob] != JOB_ENTREGADOR)
        {
            Life_ApplyProductionChain(playerid, PlayerInfo[playerid][pJob]);
        }
        Cargo_Reset(playerid);
        Work_Cancel(playerid, 0);
        if (PlayerInfo[playerid][pJob] == JOB_CAMINHONEIRO)
        {
            Life_MarkLogisticsReadyUnload(playerid);
        }
        SaveAccountData(playerid, 0);
        return 1;
    }

    Work_SetCheckpoint(playerid);
    SaveAccountData(playerid, 0);
    return 1;
}

stock Work_OnCheckpoint(playerid)
{
    new pointLabel[32];
    new alert[144];
    new jobIndex = Job_GetIndex(PlayerInfo[playerid][pJob]);
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:lastX;
    new Float:lastY;
    new Float:lastZ;
    new Float:distance;
    new tick;
    new elapsed;
    new workModel;
    new vehicleModel;

    if (!gWorkActive[playerid])
    {
        return 0;
    }

    if (jobIndex == -1 || !Work_GetRoutePoint(gWorkRoute[playerid], gWorkStep[playerid], pointLabel, sizeof(pointLabel), x, y, z))
    {
        Work_Cancel(playerid, 0);
        return 1;
    }

    if (!IsPlayerInRangeOfPoint(playerid, WORK_CHECKPOINT_SIZE + 5.0, x, y, z))
    {
        return 0;
    }

    tick = GetTickCount();

    if (Work_IsRouteDeadlineExpired(playerid, tick))
    {
        return Work_FailRouteDeadline(playerid);
    }

    if (Taxi_CheckPassengerCancel(playerid))
    {
        return 1;
    }

    if (GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
    {
        format(alert, sizeof(alert), "job=%d step=%d interior=%d vw=%d", PlayerInfo[playerid][pJob], gWorkStep[playerid], GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid));
        Security_AddAlert(playerid, "JOB_WORLD", alert);
        SendClientMessage(playerid, COLOR_RED, "Checkpoint de trabalho bloqueado fora do mundo/interior correto.");
        Work_SetCheckpoint(playerid);
        return 1;
    }

    if (gWorkStep[playerid] > 0 && gWorkCheckpointTick[playerid] > 0 && (tick - gWorkCheckpointTick[playerid]) < WORK_CHECKPOINT_MIN_MS)
    {
        format(alert, sizeof(alert), "job=%d step=%d fast_checkpoint=%dms", PlayerInfo[playerid][pJob], gWorkStep[playerid], tick - gWorkCheckpointTick[playerid]);
        Security_AddAlert(playerid, "JOB_FAST_CP", alert);
        SendClientMessage(playerid, COLOR_RED, "Checkpoint concluido rapido demais. A rota foi remarcada.");
        Work_SetCheckpoint(playerid);
        return 1;
    }

    if (gWorkLastTaskTick[playerid] > 0 && (tick - gWorkLastTaskTick[playerid]) < gCfgWorkTaskCooldown)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Aguarde alguns segundos antes de concluir a proxima tarefa.");
        Work_SetCheckpoint(playerid);
        return 1;
    }

    if (gWorkStep[playerid] > 0 && gWorkLastTaskTick[playerid] > 0 && Work_GetRoutePoint(gWorkRoute[playerid], gWorkStep[playerid] - 1, pointLabel, sizeof(pointLabel), lastX, lastY, lastZ))
    {
        elapsed = tick - gWorkLastTaskTick[playerid];
        distance = World_Dist2D(lastX, lastY, x, y);
        if (distance > WORK_ROUTE_TELEPORT_DIST && elapsed < WORK_ROUTE_TELEPORT_MS)
        {
            format(alert, sizeof(alert), "job=%d step=%d dist=%.1f elapsed=%d", PlayerInfo[playerid][pJob], gWorkStep[playerid], distance, elapsed);
            Security_AddAlert(playerid, "JOB_TP_ROUTE", alert);
            SendClientMessage(playerid, COLOR_RED, "Rota bloqueada por deslocamento rapido demais. Volte ao fluxo normal.");
            Work_SetCheckpoint(playerid);
            return 1;
        }
    }

    if (gJobs[jobIndex][jobVehicleModel] > 0)
    {
        if (!IsPlayerInVehicle(playerid, gWorkVehicle[playerid]))
        {
            SendClientMessage(playerid, COLOR_RED, "Voce precisa estar no veiculo de trabalho para concluir esta tarefa.");
            Work_SetCheckpoint(playerid);
            return 1;
        }
        if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        {
            SendClientMessage(playerid, COLOR_RED, "Voce precisa estar dirigindo o veiculo de trabalho.");
            Work_SetCheckpoint(playerid);
            return 1;
        }
        workModel = Job_GetLevelVehicle(PlayerInfo[playerid][pJob], Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob]), gJobs[jobIndex][jobVehicleModel]);
        vehicleModel = GetVehicleModel(gWorkVehicle[playerid]);
        if (vehicleModel != gJobs[jobIndex][jobVehicleModel] && vehicleModel != workModel)
        {
            format(alert, sizeof(alert), "job=%d vehicle=%d expected=%d/%d", PlayerInfo[playerid][pJob], vehicleModel, gJobs[jobIndex][jobVehicleModel], workModel);
            Security_AddAlert(playerid, "JOB_WRONG_VEH", alert);
            SendClientMessage(playerid, COLOR_RED, "Veiculo de trabalho invalido para esta profissao.");
            Work_SetCheckpoint(playerid);
            return 1;
        }
    }

    Work_FinishStep(playerid);
    return 1;
}

stock Work_OnPlayerDisconnect(playerid)
{
    Work_Cancel(playerid, 0);
    Work_ResetStreak(playerid);
    Work_ResetRunState(playerid);
    gPlayerDialogJob[playerid] = JOB_NONE;
    gJobQuickServiceTick[playerid] = 0;
    gPlayerJobSelectCount[playerid] = 0;
    gPlayerJobWorkActionCount[playerid] = 0;
    return 1;
}

stock Work_OnPlayerDeath(playerid)
{
    if (gWorkActive[playerid])
    {
        Work_Cancel(playerid, 1);
        SendClientMessage(playerid, COLOR_ORANGE, "Voce perdeu o expediente ao morrer.");
    }
    return 1;
}

stock Job_SendInfo(playerid, jobid)
{
    new index = Job_GetIndex(jobid);
    new message[144];
    new vehicleText[32];
    new requirementText[96];
    new unlockText[96];
    new level;
    new nextXP;
    new bonusPercent;
    new payBonus;
    new monthlySalary;

    if (index == -1)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Emprego invalido.");
        return 0;
    }

    if (gJobs[index][jobVehicleModel] > 0)
    {
        format(vehicleText, sizeof(vehicleText), "veiculo %d", gJobs[index][jobVehicleModel]);
    }
    else
    {
        format(vehicleText, sizeof(vehicleText), "sem veiculo");
    }

    level = Job_GetPlayerLevel(playerid, jobid);
    nextXP = Job_GetNextLevelXP(level);
    bonusPercent = Life_GetJobPayBonusPercent(playerid, jobid);
    payBonus = Job_IsPrivateBonusEligible(jobid) ? Job_GetLevelBonusPercent(level) : 0;
    monthlySalary = Job_GetMonthlySalary(jobid);
    Job_GetRequirementText(gJobs[index][jobRequirement], requirementText, sizeof(requirementText));
    Job_FormatUnlocks(jobid, level, unlockText, sizeof(unlockText));
    Job_ResetRewardDay(playerid);

    format(message, sizeof(message), "%s: %s", gJobs[index][jobName], gJobs[index][jobDescription]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Acesso: nivel %d+ | Nivel job: %d | XP: %d/%d", Job_GetAccessLevelRequirement(jobid), level, Job_GetPlayerXP(playerid, jobid), nextXP);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Requisitos: %s", requirementText);
    SendClientMessage(playerid, COLOR_BLUE, message);
    if (Job_IsPrivateBonusEligible(jobid))
    {
        format(message, sizeof(message), "Local: %s | %s | Salario mensal: $%d + bonus.", gServerLocations[gJobs[index][jobLocation]][locName], vehicleText, monthlySalary);
        SendClientMessage(playerid, COLOR_BLUE, message);
        format(message, sizeof(message), "Desbloqueios: %s | bonus dinamico agora: %d%%.", unlockText, bonusPercent);
        SendClientMessage(playerid, COLOR_BLUE, message);
        format(message, sizeof(message), "v0.6: bonus nivel +%d%% | recompensas hoje $%d/%d | XP job %d/%d.", payBonus, gJobRewardCashToday[playerid], JOB_REWARD_CASH_DAY_LIMIT, gJobRewardXpToday[playerid], JOB_REWARD_XP_DAY_LIMIT);
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    else
    {
        format(message, sizeof(message), "Local: %s | %s | Salario mensal: $%d.", gServerLocations[gJobs[index][jobLocation]][locName], vehicleText, monthlySalary);
        SendClientMessage(playerid, COLOR_BLUE, message);
        format(message, sizeof(message), "Desbloqueios: %s | servico publico sem bonus financeiro.", unlockText);
        SendClientMessage(playerid, COLOR_BLUE, message);
        format(message, sizeof(message), "Recompensas hoje $%d/%d | XP job %d/%d.", gJobRewardCashToday[playerid], JOB_REWARD_CASH_DAY_LIMIT, gJobRewardXpToday[playerid], JOB_REWARD_XP_DAY_LIMIT);
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    format(message, sizeof(message), "Anti-farm: cooldown servico rapido %d ms | burst %d/%d.", Job_GetServiceCooldown(playerid), gJobRewardBurstCount[playerid], JOB_REWARD_BURST_LIMIT);
    SendClientMessage(playerid, COLOR_GRAY, message);
    return 1;
}

stock Job_SendCurrentInfo(playerid)
{
    new jobLabel[32];

    GetJobName(PlayerInfo[playerid][pJob], jobLabel, sizeof(jobLabel));
    if (PlayerInfo[playerid][pJob] == JOB_NONE)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce esta desempregado. Va ate a Prefeitura para escolher um emprego.");
        return 1;
    }

    Job_SendInfo(playerid, PlayerInfo[playerid][pJob]);
    return 1;
}

stock Job_DoSideGig(playerid)
{
    new jobid = PlayerInfo[playerid][pJob];
    new jobIndex = Job_GetIndex(jobid);
    new tick = GetTickCount();
    new cooldown = Job_GetServiceCooldown(playerid);
    new elapsed;
    new level;
    new payment;
    new xpReward;
    new message[144];
    new alert[128];

    if (!PlayerInfo[playerid][pDocuments])
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa emitir documentos na Prefeitura antes de fazer bico.");
        return 1;
    }

    if (jobIndex == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa ter uma profissao para fazer bico.");
        return 1;
    }

    if (!Job_PlayerMeetsAccessLevel(playerid, jobid))
    {
        return 1;
    }

    if (!Job_PlayerMeetsRequirement(playerid, gJobs[jobIndex][jobRequirement]))
    {
        return 1;
    }

    if (gWorkActive[playerid])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Encerre o expediente atual antes de pegar um bico.");
        return 1;
    }

    if (!Job_IsPlayerNearWorkplace(playerid, jobid))
    {
        format(message, sizeof(message), "Va ate %s para pegar bico da profissao.", gServerLocations[gJobs[jobIndex][jobLocation]][locName]);
        SendClientMessage(playerid, COLOR_ORANGE, message);
        SetPlayerGps(playerid, gJobs[jobIndex][jobLocation]);
        return 1;
    }

    if (cooldown < JOB_SIDE_GIG_MIN_COOLDOWN)
    {
        cooldown = JOB_SIDE_GIG_MIN_COOLDOWN;
    }

    elapsed = tick - gJobQuickServiceTick[playerid];
    if (gJobQuickServiceTick[playerid] > 0 && elapsed < cooldown)
    {
        format(alert, sizeof(alert), "job=%d side_gig=%dms", jobid, elapsed);
        Security_AddAlert(playerid, "JOB_SIDE_GIG_FAST", alert);
        SendClientMessage(playerid, COLOR_GRAY, "Aguarde alguns segundos antes de pegar outro bico.");
        return 1;
    }

    level = Job_GetPlayerLevel(playerid, jobid);
    payment = Job_GetSideGigPay(jobid);
    if (Job_IsPrivateBonusEligible(jobid))
    {
        payment = Job_GetEffectivePay(jobid, payment, level);
    }
    payment = Vip_ApplyCashBonus(playerid, payment);
    xpReward = Job_GetXpReward(40, level);

    if (!Job_GiveReward(playerid, jobid, payment, xpReward, "job_side_gig", 1))
    {
        return 1;
    }

    gJobQuickServiceTick[playerid] = tick;
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_WORK, 1);
    format(message, sizeof(message), "Bico concluido como %s. Extra: $%d | XP +%d.", gJobs[jobIndex][jobName], payment, xpReward);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(playerid, COLOR_GRAY, "Seu salario principal continua sendo pago uma vez por dia no banco.");
    return 1;
}

stock Job_AddWorkAction(playerid, list[], size, actionid, label[])
{
    new line[96];

    if (gPlayerJobWorkActionCount[playerid] >= JOB_WORK_DIALOG_ACTIONS)
    {
        return 0;
    }

    gPlayerJobWorkActions[playerid][gPlayerJobWorkActionCount[playerid]] = actionid;
    gPlayerJobWorkActionCount[playerid]++;
    format(line, sizeof(line), "%s\n", label);
    strcat(list, line, size);
    return 1;
}

stock Job_AddSelectionHeader(playerid, list[], size, label[])
{
    new line[96];

    if (gPlayerJobSelectCount[playerid] >= JOB_SELECT_MAX_ROWS)
    {
        return 0;
    }

    gPlayerJobSelectIndex[playerid][gPlayerJobSelectCount[playerid]] = -1;
    gPlayerJobSelectCount[playerid]++;
    format(line, sizeof(line), "%s\t\n", label);
    strcat(list, line, size);
    return 1;
}

stock Job_AddSelectionRow(playerid, list[], size, index)
{
    new line[96];
    new jobid;
    new salary;

    if (index < 0 || index >= sizeof(gJobs) || gPlayerJobSelectCount[playerid] >= JOB_SELECT_MAX_ROWS)
    {
        return 0;
    }

    jobid = gJobs[index][jobId];
    salary = Job_GetMonthlySalary(jobid);
    gPlayerJobSelectIndex[playerid][gPlayerJobSelectCount[playerid]] = index;
    gPlayerJobSelectCount[playerid]++;
    if (Job_IsPublicServiceJob(jobid))
    {
        format(line, sizeof(line), "%s\tN%d+ | $%d\n", gJobs[index][jobName], Job_GetAccessLevelRequirement(jobid), salary);
    }
    else
    {
        format(line, sizeof(line), "%s\tN%d+ | $%d + bonus\n", gJobs[index][jobName], Job_GetAccessLevelRequirement(jobid), salary);
    }
    strcat(list, line, size);
    return 1;
}

stock Job_AddSelectionById(playerid, list[], size, jobid)
{
    return Job_AddSelectionRow(playerid, list, size, Job_GetIndex(jobid));
}

stock Job_GetShortRequirementText(requirement, output[], size = sizeof(output))
{
    output[0] = 0;
    if (requirement == JOB_REQ_NONE)
    {
        format(output, size, "Nenhum");
        return 1;
    }
    if (requirement & JOB_REQ_CNH) strcat(output, "CNH ", size);
    if (requirement & JOB_REQ_HEAVY) strcat(output, "Pesada ", size);
    if (requirement & JOB_REQ_MEDICAL) strcat(output, "Med ", size);
    if (requirement & JOB_REQ_OAB) strcat(output, "OAB ", size);
    if (requirement & JOB_REQ_PUBLIC) strcat(output, "Publico ", size);
    if (requirement & JOB_REQ_POLICE) strcat(output, "Policia ", size);
    return 1;
}

stock Job_ShowProfessionsPanel(playerid)
{
    new list[3072];
    new line[112];
    new typeText[16];
    new jobid;
    new dailySalary;

    #define ADD_PROF_PANEL_ROW(%0) \
        jobid = %0; \
        Job_GetAccessTypeText(jobid, typeText, sizeof(typeText)); \
        dailySalary = Job_GetMonthlySalary(jobid) / 30; \
        GetJobName(jobid, line, sizeof(line)); \
        format(line, sizeof(line), "%s\t%s\tN%d+\t$%d\n", line, typeText, Job_GetAccessLevelRequirement(jobid), dailySalary); \
        strcat(list, line, sizeof(list))

    format(list, sizeof(list), "Profissao\tTipo\tNivel\tSalario dia\n");
    strcat(list, "=== EMPREGOS PRIVADOS A-Z ===\t\t\t\n", sizeof(list));
    ADD_PROF_PANEL_ROW(JOB_ADVOGADO);
    ADD_PROF_PANEL_ROW(JOB_AGRICULTOR);
    ADD_PROF_PANEL_ROW(JOB_BANCARIO);
    ADD_PROF_PANEL_ROW(JOB_BARTENDER);
    ADD_PROF_PANEL_ROW(JOB_CAIXA_REPOSITOR);
    ADD_PROF_PANEL_ROW(JOB_CAMINHONEIRO);
    ADD_PROF_PANEL_ROW(JOB_CONTADOR);
    ADD_PROF_PANEL_ROW(JOB_CORRETOR_IMOVEIS);
    ADD_PROF_PANEL_ROW(JOB_COZINHEIRO);
    ADD_PROF_PANEL_ROW(JOB_ENCANADOR);
    ADD_PROF_PANEL_ROW(JOB_ENTREGADOR);
    ADD_PROF_PANEL_ROW(JOB_FARMACEUTICO);
    ADD_PROF_PANEL_ROW(JOB_FRENTISTA);
    ADD_PROF_PANEL_ROW(JOB_GARCOM);
    ADD_PROF_PANEL_ROW(JOB_GUINCHEIRO);
    ADD_PROF_PANEL_ROW(JOB_JARDINEIRO);
    ADD_PROF_PANEL_ROW(JOB_JORNALISTA);
    ADD_PROF_PANEL_ROW(JOB_MECANICO);
    ADD_PROF_PANEL_ROW(JOB_MINERADOR);
    ADD_PROF_PANEL_ROW(JOB_MOTORISTA_APP);
    ADD_PROF_PANEL_ROW(JOB_MOTOBOY);
    ADD_PROF_PANEL_ROW(JOB_OPERADOR_FABRICA);
    ADD_PROF_PANEL_ROW(JOB_PADEIRO_PIZZAIOLO);
    ADD_PROF_PANEL_ROW(JOB_PEDREIRO);
    ADD_PROF_PANEL_ROW(JOB_PESCADOR);
    ADD_PROF_PANEL_ROW(JOB_RECEPCIONISTA_HOTEL);
    ADD_PROF_PANEL_ROW(JOB_SEGURANCA);
    ADD_PROF_PANEL_ROW(JOB_TAXISTA);
    ADD_PROF_PANEL_ROW(JOB_TECNICO);
    ADD_PROF_PANEL_ROW(JOB_VENDEDOR);
    ADD_PROF_PANEL_ROW(JOB_ZELADOR);

    strcat(list, "=== EMPREGOS PUBLICOS A-Z ===\t\t\t\n", sizeof(list));
    ADD_PROF_PANEL_ROW(JOB_AGENTE_DETRAN);
    ADD_PROF_PANEL_ROW(JOB_ASSISTENTE_SOCIAL);
    ADD_PROF_PANEL_ROW(JOB_BOMBEIRO);
    ADD_PROF_PANEL_ROW(JOB_CARTEIRO);
    ADD_PROF_PANEL_ROW(JOB_DEFENSOR_PUBLICO);
    ADD_PROF_PANEL_ROW(JOB_ESCRIVAO);
    ADD_PROF_PANEL_ROW(JOB_FUNCIONARIO_PREFEITURA);
    ADD_PROF_PANEL_ROW(JOB_JUIZ);
    ADD_PROF_PANEL_ROW(JOB_LIXEIRO);
    ADD_PROF_PANEL_ROW(JOB_MEDICO);
    ADD_PROF_PANEL_ROW(JOB_MOTORISTA_AMBULANCIA);
    ADD_PROF_PANEL_ROW(JOB_MOTORISTA_ONIBUS);
    ADD_PROF_PANEL_ROW(JOB_OFICIAL_JUSTICA);
    ADD_PROF_PANEL_ROW(JOB_PERITO_CRIMINAL);
    ADD_PROF_PANEL_ROW(JOB_POLICIAL);
    ADD_PROF_PANEL_ROW(JOB_POLICIA_CIVIL);
    ADD_PROF_PANEL_ROW(JOB_POLICIA_FEDERAL);
    ADD_PROF_PANEL_ROW(JOB_POLICIA_PENAL);
    ADD_PROF_PANEL_ROW(JOB_PRF);
    ADD_PROF_PANEL_ROW(JOB_PROFESSOR);
    ADD_PROF_PANEL_ROW(JOB_PROMOTOR);

    #undef ADD_PROF_PANEL_ROW

    ShowPlayerDialog(playerid, DIALOG_PROFESSIONS, DIALOG_STYLE_TABLIST_HEADERS, "Profissoes 2.1", list, "Fechar", "");
    SendClientMessage(playerid, COLOR_GRAY, "Publico: salario diario e permissao. Privado: salario, bonus e produtividade.");
    SendClientMessage(playerid, COLOR_GRAY, "Faccoes ficam fora da Prefeitura: use /faccoes e /ocupacoesilegais.");
    return 1;
}

stock ShowJobSelectionDialog(playerid)
{
    new list[3072];

    list[0] = 0;
    gPlayerJobSelectCount[playerid] = 0;

    Job_AddSelectionHeader(playerid, list, sizeof(list), "=== EMPREGOS PRIVADOS A-Z ===");
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_ADVOGADO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_AGRICULTOR);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_BANCARIO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_BARTENDER);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_CAIXA_REPOSITOR);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_CAMINHONEIRO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_CONTADOR);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_CORRETOR_IMOVEIS);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_COZINHEIRO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_ENCANADOR);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_ENTREGADOR);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_FARMACEUTICO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_FRENTISTA);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_GARCOM);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_GUINCHEIRO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_JARDINEIRO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_JORNALISTA);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_MECANICO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_MINERADOR);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_MOTORISTA_APP);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_MOTOBOY);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_OPERADOR_FABRICA);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_PADEIRO_PIZZAIOLO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_PEDREIRO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_PESCADOR);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_RECEPCIONISTA_HOTEL);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_SEGURANCA);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_TAXISTA);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_TECNICO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_VENDEDOR);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_ZELADOR);

    Job_AddSelectionHeader(playerid, list, sizeof(list), "=== EMPREGOS PUBLICOS A-Z ===");
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_AGENTE_DETRAN);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_ASSISTENTE_SOCIAL);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_BOMBEIRO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_CARTEIRO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_DEFENSOR_PUBLICO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_ESCRIVAO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_FUNCIONARIO_PREFEITURA);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_JUIZ);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_LIXEIRO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_MEDICO);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_MOTORISTA_AMBULANCIA);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_MOTORISTA_ONIBUS);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_OFICIAL_JUSTICA);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_PERITO_CRIMINAL);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_POLICIAL);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_POLICIA_CIVIL);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_POLICIA_FEDERAL);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_POLICIA_PENAL);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_PRF);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_PROFESSOR);
    Job_AddSelectionById(playerid, list, sizeof(list), JOB_PROMOTOR);

    ShowPlayerDialog(playerid, DIALOG_CITYHALL_JOBS, DIALOG_STYLE_TABLIST, "Prefeitura - Escolher emprego", list, "Escolher", "Voltar");
    return 1;
}

stock HandleJobSelectionDialog(playerid, response, listitem)
{
    new jobid;
    new jobIndex;
    new message[144];

    if (!response)
    {
        ShowCityHallDialog(playerid);
        return 1;
    }

    if (listitem < 0 || listitem >= gPlayerJobSelectCount[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Emprego invalido.");
        return 1;
    }
    jobIndex = gPlayerJobSelectIndex[playerid][listitem];
    if (jobIndex < 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Selecione uma profissao dentro da categoria.");
        return ShowJobSelectionDialog(playerid);
    }

    if (!PlayerInfo[playerid][pDocuments])
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa emitir documentos antes de escolher emprego.");
        return 1;
    }

    jobid = gJobs[jobIndex][jobId];
    if (!Job_PlayerMeetsAccessLevel(playerid, jobid))
    {
        return 1;
    }
    if (!Job_PlayerMeetsRequirement(playerid, gJobs[jobIndex][jobRequirement]))
    {
        return 1;
    }

    if (!SetPlayerJob(playerid, jobid))
    {
        return 1;
    }
    format(message, sizeof(message), "Emprego escolhido: %s. Use /trabalhar no local de trabalho para iniciar.", gJobs[jobIndex][jobName]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SetPlayerGps(playerid, gJobs[jobIndex][jobLocation]);
    return 1;
}

stock ShowJobWorkDialog(playerid, jobid)
{
    new list[256];
    new title[64];
    new jobLabel[32];

    gPlayerDialogJob[playerid] = jobid;
    gPlayerJobWorkActionCount[playerid] = 0;
    list[0] = 0;
    GetJobName(jobid, jobLabel, sizeof(jobLabel));
    format(title, sizeof(title), "Emprego - %s", jobLabel);

    if (gWorkActive[playerid] && PlayerInfo[playerid][pJob] == jobid)
    {
        Job_AddWorkAction(playerid, list, sizeof(list), JOB_WORK_ACT_CONTINUE, "Continuar expediente");
        Job_AddWorkAction(playerid, list, sizeof(list), JOB_WORK_ACT_CANCEL, "Encerrar expediente");
        Job_AddWorkAction(playerid, list, sizeof(list), JOB_WORK_ACT_INFO, "Informacoes");
        ShowPlayerDialog(playerid, DIALOG_JOB_WORK, DIALOG_STYLE_LIST, title, list, "Selecionar", "Fechar");
        return 1;
    }

    if (PlayerInfo[playerid][pJob] != jobid)
    {
        Job_AddWorkAction(playerid, list, sizeof(list), JOB_WORK_ACT_ACCEPT, "Aceitar emprego");
        Job_AddWorkAction(playerid, list, sizeof(list), JOB_WORK_ACT_INFO, "Informacoes");
        Job_AddWorkAction(playerid, list, sizeof(list), JOB_WORK_ACT_GPS, "Marcar no GPS");
        ShowPlayerDialog(playerid, DIALOG_JOB_WORK, DIALOG_STYLE_LIST, title, list, "Selecionar", "Fechar");
        return 1;
    }

    Job_AddWorkAction(playerid, list, sizeof(list), JOB_WORK_ACT_START, "Bater ponto");
    Job_AddWorkAction(playerid, list, sizeof(list), JOB_WORK_ACT_SIDE_GIG, "Fazer bico");
    Job_AddWorkAction(playerid, list, sizeof(list), JOB_WORK_ACT_QUIT, "Sair do emprego");
    Job_AddWorkAction(playerid, list, sizeof(list), JOB_WORK_ACT_INFO, "Informacoes");
    Job_AddWorkAction(playerid, list, sizeof(list), JOB_WORK_ACT_GPS, "Marcar no GPS");
    ShowPlayerDialog(playerid, DIALOG_JOB_WORK, DIALOG_STYLE_LIST, title, list, "Selecionar", "Fechar");
    return 1;
}

stock ShowJobLocationDialog(playerid, locationid)
{
    new jobid = Job_FindByLocation(locationid);

    if (jobid == JOB_NONE)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Este local ainda nao possui expediente configurado.");
        return 0;
    }

    ShowJobWorkDialog(playerid, jobid);
    return 1;
}

stock HandleJobWorkDialog(playerid, response, listitem)
{
    new jobid = gPlayerDialogJob[playerid];
    new jobIndex = Job_GetIndex(jobid);
    new actionid;
    new message[144];

    if (!response || jobIndex == -1)
    {
        return 1;
    }

    if (listitem < 0 || listitem >= gPlayerJobWorkActionCount[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Opcao de emprego expirou. Abra novamente.");
        return ShowJobWorkDialog(playerid, jobid);
    }

    actionid = gPlayerJobWorkActions[playerid][listitem];
    if (gWorkActive[playerid] && PlayerInfo[playerid][pJob] == jobid)
    {
        switch (actionid)
        {
            case JOB_WORK_ACT_CONTINUE: Work_SetCheckpoint(playerid);
            case JOB_WORK_ACT_CANCEL: Work_Cancel(playerid);
            case JOB_WORK_ACT_INFO: Job_SendInfo(playerid, jobid);
        }
        return 1;
    }

    if (PlayerInfo[playerid][pJob] != jobid)
    {
        switch (actionid)
        {
            case JOB_WORK_ACT_ACCEPT:
            {
                if (!PlayerInfo[playerid][pDocuments])
                {
                    SendClientMessage(playerid, COLOR_RED, "Voce precisa emitir documentos na Prefeitura antes de aceitar emprego.");
                    return 1;
                }

                if (!Job_PlayerMeetsAccessLevel(playerid, jobid))
                {
                    return 1;
                }
                if (!Job_PlayerMeetsRequirement(playerid, gJobs[jobIndex][jobRequirement]))
                {
                    return 1;
                }

                if (!SetPlayerJob(playerid, jobid))
                {
                    return 1;
                }
                format(message, sizeof(message), "Voce agora trabalha como %s.", gJobs[jobIndex][jobName]);
                SendClientMessage(playerid, COLOR_GREEN, message);
                Work_Start(playerid);
            }
            case JOB_WORK_ACT_INFO: Job_SendInfo(playerid, jobid);
            case JOB_WORK_ACT_GPS: SetPlayerGps(playerid, gJobs[jobIndex][jobLocation]);
        }
        return 1;
    }

    switch (actionid)
    {
        case JOB_WORK_ACT_START: Work_Start(playerid);
        case JOB_WORK_ACT_SIDE_GIG: Job_DoSideGig(playerid);
        case JOB_WORK_ACT_QUIT:
        {
            Work_Cancel(playerid, 0);
            SetPlayerJob(playerid, JOB_NONE);
            SendClientMessage(playerid, COLOR_ORANGE, "Voce saiu do emprego.");
        }
        case JOB_WORK_ACT_INFO: Job_SendInfo(playerid, jobid);
        case JOB_WORK_ACT_GPS: SetPlayerGps(playerid, gJobs[jobIndex][jobLocation]);
    }
    return 1;
}

stock Job_HealCommand(playerid, targetid)
{
    new level;
    new reward;
    new xpReward;

    if (PlayerInfo[playerid][pJob] != JOB_MEDICO && PlayerInfo[playerid][pJob] != JOB_MOTORISTA_AMBULANCIA)
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas Medico/Enfermeiro ou Motorista de Ambulancia pode usar este servico.");
        return 1;
    }

    if (!Job_ArePlayersClose(playerid, targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "O paciente precisa estar perto de voce.");
        return 1;
    }

    SetPlayerHealth(targetid, 100.0);
    PlayerInfo[targetid][pInjury] = 0;
    SaveAccountData(targetid, 0);
    level = Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob]);
    reward = Vip_ApplyCashBonus(playerid, Job_GetEffectivePay(PlayerInfo[playerid][pJob], 300, level));
    xpReward = Job_GetXpReward(80, level);
    if (!Job_GiveReward(playerid, PlayerInfo[playerid][pJob], reward, xpReward, "job_medical_service", 1))
    {
        return 1;
    }
    Life_AddBusinessDemand(LIFE_BUSINESS_TRANSPORT, 1, "atendimento hospitalar");
    SendClientMessage(playerid, COLOR_GREEN, "Atendimento medico concluido. Pagamento e XP recebidos.");
    SendClientMessage(targetid, COLOR_GREEN, "Voce recebeu atendimento medico.");
    return 1;
}

stock Job_RepairCommand(playerid)
{
    new level;
    new reward;
    new xpReward;

    if (PlayerInfo[playerid][pJob] != JOB_MECANICO)
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas mecanicos podem usar /repararcarro.");
        return 1;
    }

    if (!IsPlayerInAnyVehicle(playerid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Entre no veiculo que deseja reparar.");
        return 1;
    }

    Fuel_RefuelVehicle(GetPlayerVehicleID(playerid), FUEL_MAX_VALUE);
    RepairVehicle(GetPlayerVehicleID(playerid));
    level = Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob]);
    reward = Vip_ApplyCashBonus(playerid, Job_GetEffectivePay(PlayerInfo[playerid][pJob], 350, level));
    xpReward = Job_GetXpReward(80, level);
    if (!Job_GiveReward(playerid, PlayerInfo[playerid][pJob], reward, xpReward, "job_mechanic_repair", 1))
    {
        return 1;
    }
    Life_AddBusinessDemand(LIFE_BUSINESS_WORKSHOP, 1, "reparo de veiculo");
    SendClientMessage(playerid, COLOR_GREEN, "Veiculo reparado. Pagamento e XP recebidos.");
    return 1;
}

stock NpcWorkshopRepair(playerid)
{
    new repairCost;
    new message[128];

    if (!Job_IsPlayerNearWorkplace(playerid, JOB_MECANICO))
    {
        SendClientMessage(playerid, COLOR_RED, "Leve o veiculo ate a oficina mecanica.");
        return 1;
    }

    if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Entre dirigindo o veiculo que deseja reparar.");
        return 1;
    }

    repairCost = Vip_ApplyDiscount(playerid, Cfg_Price(gCfgNpcRepairCost));

    if (!Bank_TakePayment(playerid, repairCost, 0))
    {
        format(message, sizeof(message), "Atendimento da oficina NPC custa $%d em dinheiro/banco.", repairCost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    RepairVehicle(GetPlayerVehicleID(playerid));
    SavePlayerOwnedVehicleState(playerid);
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Mecanico NPC reparou seu veiculo. Custo: $%d.", repairCost);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Job_FuelCommand(playerid)
{
    new level;
    new reward;
    new xpReward;
    new vehicleid;

    if (PlayerInfo[playerid][pJob] != JOB_FRENTISTA)
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas frentistas podem usar /abastecer.");
        return 1;
    }

    if (!Job_IsPlayerNearWorkplace(playerid, JOB_FRENTISTA) && !World_IsPlayerAtGasStation(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa estar no posto de combustivel.");
        return 1;
    }

    if (!IsPlayerInAnyVehicle(playerid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Entre no veiculo que sera abastecido.");
        return 1;
    }

    vehicleid = GetPlayerVehicleID(playerid);
    if (Fuel_IsElectricVehicle(vehicleid))
    {
        return Fuel_ChargePlayerVehicle(playerid);
    }

    Fuel_RefuelVehicle(vehicleid, FUEL_MAX_VALUE);
    RepairVehicle(vehicleid);
    level = Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob]);
    reward = Vip_ApplyCashBonus(playerid, Job_GetEffectivePay(PlayerInfo[playerid][pJob], 220, level));
    xpReward = Job_GetXpReward(60, level);
    if (!Job_GiveReward(playerid, PlayerInfo[playerid][pJob], reward, xpReward, "job_fuel_service", 1))
    {
        return 1;
    }
    Life_AddBusinessDemand(LIFE_BUSINESS_WORKSHOP, 1, "abastecimento de frota");
    SendClientMessage(playerid, COLOR_GREEN, "Veiculo abastecido e revisado. Pagamento e XP recebidos.");
    return 1;
}

stock NpcFuelRefuel(playerid)
{
    new vehicleid;
    new currentFuel;
    new neededFuel;
    new cost;
    new unitPrice;
    new fuelPricePercent;
    new fuelName[16];
    new message[128];

    if (!World_IsPlayerAtGasStation(playerid) && !Job_IsPlayerNearWorkplace(playerid, JOB_FRENTISTA) && !Prop_EditorAtFuel(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "Leve o veiculo ate um posto de combustivel.");
        return 1;
    }

    if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Entre dirigindo o veiculo que sera abastecido.");
        return 1;
    }

    vehicleid = GetPlayerVehicleID(playerid);
    if (!Fuel_IsMotorizedVehicle(vehicleid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Bicicletas nao usam combustivel.");
        return 1;
    }

    if (Fuel_IsElectricVehicle(vehicleid))
    {
        return Fuel_ChargePlayerVehicle(playerid);
    }

    currentFuel = Fuel_GetVehicleFuel(vehicleid);
    if (currentFuel >= FUEL_MAX_VALUE)
    {
        SendClientMessage(playerid, COLOR_GRAY, "O tanque ja esta cheio.");
        return 1;
    }

    neededFuel = FUEL_MAX_VALUE - currentFuel;
    unitPrice = Fuel_GetDefaultUnitPrice(vehicleid);
    Fuel_GetDefaultFuelName(vehicleid, fuelName, sizeof(fuelName));
    cost = neededFuel * Cfg_Price(unitPrice);
    fuelPricePercent = Life_GetFuelPricePercent();
    cost = (cost * fuelPricePercent) / 100;
    if (cost < Cfg_Price(gCfgNpcRefuelMinCost))
    {
        cost = Cfg_Price(gCfgNpcRefuelMinCost);
    }
    cost = Vip_ApplyDiscount(playerid, cost);

    if (!Bank_TakePayment(playerid, cost, 0))
    {
        format(message, sizeof(message), "Abastecimento NPC custa $%d em dinheiro/banco.", cost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    Fuel_RefuelVehicle(vehicleid, neededFuel);
    SavePlayerOwnedVehicleState(playerid);
    SaveAccountData(playerid, 0);
    format(message, sizeof(message), "Frentista NPC abasteceu %d%% com %s. Custo: $%d | mercado combustivel %d%%.", neededFuel, fuelName, cost, fuelPricePercent);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Job_PaintVehicleCommand(playerid, color1, color2)
{
    new level;
    new reward;
    new xpReward;

    if (PlayerInfo[playerid][pJob] != JOB_MECANICO)
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas mecanicos podem pintar veiculos.");
        return 1;
    }

    if (!IsPlayerInAnyVehicle(playerid))
    {
        SendClientMessage(playerid, COLOR_GRAY, "Entre no veiculo que deseja pintar.");
        return 1;
    }

    if (color1 < 0 || color1 > 255 || color2 < 0 || color2 > 255)
    {
        SendClientMessage(playerid, COLOR_RED, "Cores validas: 0 a 255.");
        return 1;
    }

    ChangeVehicleColor(GetPlayerVehicleID(playerid), color1, color2);
    level = Job_GetPlayerLevel(playerid, JOB_MECANICO);
    reward = Vip_ApplyCashBonus(playerid, Job_GetEffectivePay(JOB_MECANICO, 250, level));
    xpReward = Job_GetXpReward(60, level);
    if (!Job_GiveReward(playerid, JOB_MECANICO, reward, xpReward, "job_mechanic_paint", 1))
    {
        return 1;
    }
    SendClientMessage(playerid, COLOR_GREEN, "Pintura concluida. Pagamento e XP recebidos.");
    return 1;
}

stock Job_TaxiFareCommand(playerid, targetid, amount)
{
    new message[144];
    new level;
    new xpReward;

    if (PlayerInfo[playerid][pJob] != JOB_TAXISTA)
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas taxistas podem usar taximetro.");
        return 1;
    }

    if (amount <= 0 || amount > 3000)
    {
        SendClientMessage(playerid, COLOR_RED, "Valor permitido: 1 a 3000.");
        return 1;
    }

    if (!Job_ArePlayersClose(playerid, targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "O passageiro precisa estar perto de voce.");
        return 1;
    }

    level = Job_GetPlayerLevel(playerid, JOB_TAXISTA);
    xpReward = Job_GetXpReward(80, level);
    if (!Job_CanReward(playerid, JOB_TAXISTA, amount, xpReward, "taxi_fare_received"))
    {
        return 1;
    }

    if (!TakePlayerCashReason(targetid, amount, 1, "taxi_fare_paid"))
    {
        SendClientMessage(playerid, COLOR_RED, "O passageiro nao tem dinheiro suficiente.");
        return 1;
    }

    GivePlayerCashReason(playerid, amount, 1, "taxi_fare_received");
    Job_AddProgress(playerid, JOB_TAXISTA, xpReward);
    Job_RegisterReward(playerid, JOB_TAXISTA, amount, xpReward, "taxi_fare_received");
    Life_AddBusinessDemand(LIFE_BUSINESS_TRANSPORT, 1, "corrida de taxi real");
    format(message, sizeof(message), "Corrida cobrada do ID %d: $%d.", targetid, amount);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(message, sizeof(message), "Voce pagou uma corrida de taxi: $%d.", amount);
    SendClientMessage(targetid, COLOR_YELLOW, message);
    return 1;
}

stock Job_FineCommandEx(playerid, targetid, severity, multiplier, article[], reason[])
{
    new message[144];
    new amount;
    new points;
    new reward;
    new xpReward;
    new severityName[16];
    new fineLabel[96];

    if (!IsLawEnforcementJob(PlayerInfo[playerid][pJob]))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas forcas policiais podem aplicar multas.");
        return 1;
    }

    if (severity < TRAFFIC_FINE_LIGHT || severity > TRAFFIC_FINE_VERY_SERIOUS || !Cfg_TrafficMultiplierOk(multiplier))
    {
        SendClientMessage(playerid, COLOR_RED, "Gravidade/multiplicador invalido. Use leve, media, grave ou gravissima; multiplicador 2,3,5,10,20,60.");
        return 1;
    }

    if (!Job_ArePlayersClose(playerid, targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "O jogador precisa estar perto de voce.");
        return 1;
    }
    if (Account_IsNewcomerProtected(targetid))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Recem chegado protegido: use abordagem educativa, sem multa ate o nivel 3.");
        SendClientMessage(targetid, COLOR_YELLOW, "Aviso educativo: voce ainda esta protegido como recem chegado. Multas liberam a partir do nivel 3.");
        return 1;
    }

    amount = Cfg_TrafficFine(severity, multiplier);
    points = Cfg_TrafficPoints(severity);
    Cfg_TrafficSeverityName(severity, severityName, sizeof(severityName));
    if (strlen(reason) > 0)
    {
        format(fineLabel, sizeof(fineLabel), "%s - %s", article, reason);
    }
    else
    {
        format(fineLabel, sizeof(fineLabel), "Multa manual CTB");
    }

    if (amount <= 0 || amount > gCfgWorkFineLimit)
    {
        SendClientMessage(playerid, COLOR_RED, "Valor de multa fora do limite operacional configurado.");
        return 1;
    }

    PlayerInfo[targetid][pFines] += amount;
    if (PlayerInfo[targetid][pFines] > MAX_PLAYER_FINE)
    {
        PlayerInfo[targetid][pFines] = MAX_PLAYER_FINE;
    }
    PlayerInfo[targetid][pTrafficPoints] += points;
    if (PlayerInfo[targetid][pTrafficPoints] > MAX_TRAFFIC_POINTS)
    {
        PlayerInfo[targetid][pTrafficPoints] = MAX_TRAFFIC_POINTS;
    }

    reward = amount / 20;
    if (reward > 150)
    {
        reward = 150;
    }
    xpReward = Job_GetXpReward(25, Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob]));
    if (Job_CanReward(playerid, PlayerInfo[playerid][pJob], reward, xpReward, "police_fine_bonus"))
    {
        GivePlayerCashReason(playerid, reward, 1, "police_fine_bonus");
        Job_AddProgress(playerid, PlayerInfo[playerid][pJob], xpReward);
        Job_RegisterReward(playerid, PlayerInfo[playerid][pJob], reward, xpReward, "police_fine_bonus");
    }
    else
    {
        reward = 0;
    }
    SaveAccountData(targetid, 0);
    Life_AddCityPassProgress(playerid, CITY_PASS_KIND_PUBLIC, 1);
    Life_AddWeeklyScore(playerid, WEEKLY_SCORE_POLICE, 2);
    format(message, sizeof(message), "Multa ID %d: %s | %s x%d | $%d | %d pts. Bonus: $%d.", targetid, fineLabel, severityName, multiplier, amount, points, reward);
    WritePlayerLog(LOG_MONEY_FILE, "POLICE_FINE", playerid, message);
    format(message, sizeof(message), "fine_received officer=%d article=%s severity=%d mult=%d amount=%d points=%d fines=%d cnh_points=%d", playerid, article, severity, multiplier, amount, points, PlayerInfo[targetid][pFines], PlayerInfo[targetid][pTrafficPoints]);
    WritePlayerLog(LOG_MONEY_FILE, "POLICE_FINE", targetid, message);
    format(message, sizeof(message), "Multa registrada no ID %d: %s | %s x%d | $%d | %d pts.", targetid, fineLabel, severityName, multiplier, amount, points);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(message, sizeof(message), "Voce recebeu multa %s: $%d e %d pontos na CNH. Pague em /pagarmultas.", fineLabel, amount, points);
    SendClientMessage(targetid, COLOR_RED, message);
    return 1;
}

stock Job_FineCommand(playerid, targetid, severity, multiplier = 1)
{
    return Job_FineCommandEx(playerid, targetid, severity, multiplier, "CTB", "Multa manual");
}

stock Job_SendFineCatalogPreview(playerid)
{
    new fineid;
    new limit = TrafficFine_Count();
    new line[144];
    new article[TRAFFIC_FINE_ARTICLE_SIZE];
    new title[TRAFFIC_FINE_TITLE_SIZE];

    if (limit > 12)
    {
        limit = 12;
    }

    SendClientMessage(playerid, COLOR_YELLOW, "Use: /multa [id do player] [numero da multa]. Principais codigos CTB:");
    for (fineid = 0; fineid < limit; fineid++)
    {
        TrafficFine_GetArticle(fineid, article, sizeof(article));
        TrafficFine_GetTitle(fineid, title, sizeof(title));
        format(line, sizeof(line), "%d - %s | %s | $%d | %d pts", fineid, article, title, TrafficFine_GetAmount(fineid), TrafficFine_GetPoints(fineid));
        SendClientMessage(playerid, COLOR_GRAY, line);
    }

    format(line, sizeof(line), "Codigos disponiveis: 0 a %d. Exemplo: /multa 0 0", TrafficFine_Count() - 1);
    SendClientMessage(playerid, COLOR_YELLOW, line);
    return 1;
}

stock Job_FineCatalogCommand(playerid, targetid, fineid)
{
    new article[TRAFFIC_FINE_ARTICLE_SIZE];
    new title[TRAFFIC_FINE_TITLE_SIZE];

    if (!TrafficFine_IsValid(fineid))
    {
        SendClientMessage(playerid, COLOR_RED, "Numero de multa invalido.");
        return Job_SendFineCatalogPreview(playerid);
    }

    TrafficFine_GetArticle(fineid, article, sizeof(article));
    TrafficFine_GetTitle(fineid, title, sizeof(title));
    return Job_FineCommandEx(playerid, targetid, TrafficFine_GetSeverity(fineid), TrafficFine_GetMultiplier(fineid), article, title);
}

stock Job_ShowTrafficFineDialog(playerid, targetid, page = 0)
{
    new list[4096];
    new line[144];
    new fineid;
    new count;
    new total = TrafficFine_Count();
    new maxPage;
    new first;
    new last;
    new title[64];

    if (!IsLawEnforcementJob(PlayerInfo[playerid][pJob]))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas forcas policiais podem aplicar multas.");
        return 1;
    }

    if (!Job_ArePlayersClose(playerid, targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "O jogador precisa estar perto de voce.");
        return 1;
    }

    maxPage = (total - 1) / JOB_TRAFFIC_FINE_PAGE_SIZE;
    if (page < 0)
    {
        page = 0;
    }
    if (page > maxPage)
    {
        page = maxPage;
    }
    first = page * JOB_TRAFFIC_FINE_PAGE_SIZE;
    last = first + JOB_TRAFFIC_FINE_PAGE_SIZE;
    if (last > total)
    {
        last = total;
    }

    gPlayerTrafficFineTarget[playerid] = targetid;
    gPlayerTrafficFineCount[playerid] = 0;
    gPlayerTrafficFinePage[playerid] = page;

    format(list, sizeof(list), "Artigo\tInfracao CTB\tGravidade/valor\n");
    if (page > 0)
    {
        strcat(list, "Voltar\tPagina anterior\t-\n", sizeof(list));
        gPlayerTrafficFineItems[playerid][count] = JOB_TRAFFIC_FINE_NAV_PREV;
        count++;
    }

    for (fineid = first; fineid < last; fineid++)
    {
        if (count >= JOB_TRAFFIC_FINE_DIALOG_ACTIONS)
        {
            break;
        }

        TrafficFine_BuildDialogLine(fineid, line, sizeof(line));
        strcat(list, line, sizeof(list));
        gPlayerTrafficFineItems[playerid][count] = fineid;
        count++;
    }

    if (page < maxPage && count < JOB_TRAFFIC_FINE_DIALOG_ACTIONS)
    {
        strcat(list, "Mais\tProxima pagina\t-\n", sizeof(list));
        gPlayerTrafficFineItems[playerid][count] = JOB_TRAFFIC_FINE_NAV_NEXT;
        count++;
    }

    gPlayerTrafficFineCount[playerid] = count;
    format(title, sizeof(title), "CTB - escolher multa (%d/%d)", page + 1, maxPage + 1);
    ShowPlayerDialog(playerid, DIALOG_TRAFFIC_FINE, DIALOG_STYLE_TABLIST_HEADERS, title, list, "Selecionar", "Fechar");
    return 1;
}

stock Job_HandleTrafficFineDialog(playerid, response, listitem)
{
    new targetid = gPlayerTrafficFineTarget[playerid];
    new fineid;
    new article[TRAFFIC_FINE_ARTICLE_SIZE];
    new title[TRAFFIC_FINE_TITLE_SIZE];

    if (!response)
    {
        gPlayerTrafficFineTarget[playerid] = INVALID_PLAYER_ID;
        gPlayerTrafficFineCount[playerid] = 0;
        return 1;
    }

    if (listitem < 0 || listitem >= gPlayerTrafficFineCount[playerid])
    {
        return 1;
    }

    if (!IsValidConnectedPlayer(targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "Alvo da multa saiu ou ficou invalido.");
        return 1;
    }

    fineid = gPlayerTrafficFineItems[playerid][listitem];
    if (fineid == JOB_TRAFFIC_FINE_NAV_NEXT)
    {
        return Job_ShowTrafficFineDialog(playerid, targetid, gPlayerTrafficFinePage[playerid] + 1);
    }
    if (fineid == JOB_TRAFFIC_FINE_NAV_PREV)
    {
        return Job_ShowTrafficFineDialog(playerid, targetid, gPlayerTrafficFinePage[playerid] - 1);
    }

    TrafficFine_GetArticle(fineid, article, sizeof(article));
    TrafficFine_GetTitle(fineid, title, sizeof(title));
    return Job_FineCommandEx(playerid, targetid, TrafficFine_GetSeverity(fineid), TrafficFine_GetMultiplier(fineid), article, title);
}

stock Job_ArrestCommand(playerid, targetid)
{
    if (!IsLawEnforcementJob(PlayerInfo[playerid][pJob]))
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas forcas policiais podem prender jogadores.");
        return 1;
    }

    if (!Job_ArePlayersClose(playerid, targetid))
    {
        SendClientMessage(playerid, COLOR_RED, "O jogador precisa estar perto de voce.");
        return 1;
    }

    return Police_CommandArrest(playerid, targetid, 0);
}

stock Job_ReleaseCommand(playerid, targetid)
{
    new logLine[96];

    if (!IsLawEnforcementJob(PlayerInfo[playerid][pJob]) && PlayerInfo[playerid][pJob] != JOB_JUIZ)
    {
        SendClientMessage(playerid, COLOR_RED, "Apenas forcas policiais ou juizes podem liberar jogadores.");
        return 1;
    }

    Police_ReleasePlayer(targetid);
    format(logLine, sizeof(logLine), "target=%d liberou jogador da custodia", targetid);
    WritePlayerLog(LOG_PUNISH_FILE, "POLICE_RELEASE", playerid, logLine);
    SendClientMessage(playerid, COLOR_GREEN, "Jogador liberado.");
    SendClientMessage(targetid, COLOR_GREEN, "Voce foi liberado.");
    return 1;
}

stock Job_GenericService(playerid)
{
    new jobIndex = Job_GetIndex(PlayerInfo[playerid][pJob]);
    new payment;
    new message[128];
    new tick = GetTickCount();
    new alert[128];
    new cooldown;
    new level;
    new xpReward;
    new serviceText[96];

    if (jobIndex == -1)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao tem emprego.");
        return 1;
    }

    switch (PlayerInfo[playerid][pJob])
    {
        case JOB_MECANICO:
        {
            return Job_RepairCommand(playerid);
        }
        case JOB_FRENTISTA:
        {
            return Job_FuelCommand(playerid);
        }
        case JOB_POLICIAL, JOB_PRF, JOB_POLICIA_FEDERAL, JOB_POLICIA_CIVIL, JOB_POLICIA_PENAL:
        {
            SendClientMessage(playerid, COLOR_BLUE, "Seguranca publica: /abordagem [id], /revistar [id], /algemar [id], /prender [id] [crime_id], /soltar [id] e /crimes.");
            return 1;
        }
        case JOB_SEGURANCA:
        {
            SendClientMessage(playerid, COLOR_BLUE, "Seguranca privada: use /abordagem [id] para abordagem basica. Revista, ficha e drogas ficam restritas a policia.");
            return 1;
        }
        case JOB_TAXISTA:
        {
            SendClientMessage(playerid, COLOR_BLUE, "Taxista: use /taximetro [id] [valor] perto do passageiro ou /trabalhar para corridas.");
            return 1;
        }
        case JOB_MEDICO, JOB_MOTORISTA_AMBULANCIA:
        {
            SendClientMessage(playerid, COLOR_BLUE, "Saude: use /curar [id] perto do paciente ou /trabalhar para chamados.");
            return 1;
        }
    }

    if (!Job_IsPlayerNearWorkplace(playerid, PlayerInfo[playerid][pJob]))
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Para servico rapido, fique no local do seu emprego. Use /trabalhar para rotas externas.");
        return 1;
    }

    cooldown = Job_GetServiceCooldown(playerid);
    if (gJobQuickServiceTick[playerid] > 0 && (tick - gJobQuickServiceTick[playerid]) < cooldown)
    {
        format(alert, sizeof(alert), "job=%d quick_service=%dms", PlayerInfo[playerid][pJob], tick - gJobQuickServiceTick[playerid]);
        Security_AddAlert(playerid, "JOB_FAST_SERVICE", alert);
        SendClientMessage(playerid, COLOR_GRAY, "Aguarde alguns segundos antes de fazer outro servico rapido.");
        return 1;
    }

    level = Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob]);
    payment = Cfg_GetJobPay(PlayerInfo[playerid][pJob], gJobs[jobIndex][jobPay]) / 2;
    payment = Job_GetEffectivePay(PlayerInfo[playerid][pJob], payment, level);
    payment = Vip_ApplyCashBonus(playerid, payment);
    xpReward = Job_GetXpReward(50, level);
    switch (PlayerInfo[playerid][pJob])
    {
        case JOB_AGENTE_DETRAN: format(serviceText, sizeof(serviceText), "Vistoria documental concluida como Agente DETRAN.");
        case JOB_BANCARIO: format(serviceText, sizeof(serviceText), "Analise de credito concluida como Bancario. Dono pode usar /creditoempresa.");
        case JOB_CONTADOR: format(serviceText, sizeof(serviceText), "Apuracao fiscal conferida como Contador. Use /regularizarempresa.");
        case JOB_CORRETOR_IMOVEIS: format(serviceText, sizeof(serviceText), "Visita e contrato imobiliario registrados como Corretor.");
        case JOB_PERITO_CRIMINAL: format(serviceText, sizeof(serviceText), "Laudo pericial e prova registrados como Perito Criminal.");
        case JOB_PROMOTOR: format(serviceText, sizeof(serviceText), "Parecer de acusacao registrado como Promotor.");
        case JOB_DEFENSOR_PUBLICO: format(serviceText, sizeof(serviceText), "Atendimento juridico publico registrado como Defensor.");
        case JOB_OFICIAL_JUSTICA: format(serviceText, sizeof(serviceText), "Diligencia e intimacao cumpridas como Oficial de Justica.");
        case JOB_ESCRIVAO: format(serviceText, sizeof(serviceText), "Auto e processo registrados como Escrivao.");
        default: format(serviceText, sizeof(serviceText), "Servico rapido concluido como %s.", gJobs[jobIndex][jobName]);
    }
    if (!Job_GiveReward(playerid, PlayerInfo[playerid][pJob], payment, xpReward, "job_quick_service", 1))
    {
        return 1;
    }
    gJobQuickServiceTick[playerid] = tick;
    format(message, sizeof(message), "%s Pagamento: $%d | XP +%d.", serviceText, payment, xpReward);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock InteriorSpot_GiveJobReward(playerid, jobid, basePay, xp, message[])
{
    new pay;
    new jobLabel[32];
    new needMessage[64];
    new level;
    new xpReward;

    if (jobid == JOB_NONE)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Este ponto ainda nao tem profissao vinculada.");
        return 1;
    }

    if (PlayerInfo[playerid][pJob] != jobid)
    {
        GetJobName(jobid, jobLabel, sizeof(jobLabel));
        SendClientMessage(playerid, COLOR_ORANGE, "Este ponto e reservado para a profissao deste local.");
        format(needMessage, sizeof(needMessage), "Profissao necessaria: %s.", jobLabel);
        SendClientMessage(playerid, COLOR_GRAY, needMessage);
        return 1;
    }

    if (!InteriorSpot_CanReward(playerid))
    {
        return 1;
    }

    level = Job_GetPlayerLevel(playerid, jobid);
    pay = Job_GetEffectivePay(jobid, basePay, level);
    pay = Vip_ApplyCashBonus(playerid, pay);
    xpReward = Job_GetXpReward(xp, level);
    if (!Job_GiveReward(playerid, jobid, pay, xpReward, "job_interior_spot", 1))
    {
        return 1;
    }
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock InteriorSpot_HandleHospital(playerid)
{
    if (PlayerInfo[playerid][pJob] == JOB_MEDICO || PlayerInfo[playerid][pJob] == JOB_MOTORISTA_AMBULANCIA)
    {
        return InteriorSpot_GiveJobReward(playerid, PlayerInfo[playerid][pJob], 180, 60, "Atendimento interno concluido. Pagamento e XP recebidos.");
    }

    Hospital_TreatPlayer(playerid);
    return 1;
}

stock InteriorSpot_HandlePoliceReport(playerid, spotid)
{
    new jobid = Job_FindByLocation(gInteriorSpots[spotid][spotLocation]);

    if (IsPublicSecurityJob(PlayerInfo[playerid][pJob]) || PlayerInfo[playerid][pJob] == JOB_BOMBEIRO)
    {
        return InteriorSpot_GiveJobReward(playerid, PlayerInfo[playerid][pJob], 160, 55, "Ocorrencia interna registrada. Pagamento e XP recebidos.");
    }

    if (IsLawEnforcementJob(jobid))
    {
        SendClientMessage(playerid, COLOR_BLUE, "Escrivao NPC registrou sua ocorrencia na Delegacia.");
        SendClientMessage(playerid, COLOR_GRAY, "Policiais em servico podem assumir o caso depois; o protocolo ja ficou aberto.");
        return 1;
    }

    SendClientMessage(playerid, COLOR_GRAY, "Este setor e reservado para equipes de servico.");
    return 1;
}

stock InteriorSpot_HandlePoliceCell(playerid)
{
    if (gPlayerInPoliceCell[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Voce esta detido. Aguarde um policial ou juiz usar /soltar.");
        return 1;
    }

    if (IsLawEnforcementJob(PlayerInfo[playerid][pJob]) || PlayerInfo[playerid][pJob] == JOB_JUIZ)
    {
        SendClientMessage(playerid, COLOR_BLUE, "Cela funcional: use /prender [id] perto do suspeito para conduzir ate aqui.");
        SendClientMessage(playerid, COLOR_BLUE, "Use /soltar [id] para liberar um detido.");
        return 1;
    }

    SendClientMessage(playerid, COLOR_GRAY, "Area de custodia. Acesso operacional restrito.");
    return 1;
}

stock InteriorSpot_HandleStore(playerid, spotid)
{
    new locationid = gInteriorSpots[spotid][spotLocation];
    new jobid = Job_FindByLocation(locationid);
    new spotName[72];

    format(spotName, sizeof(spotName), "%s", gInteriorSpots[spotid][spotText]);

    if (World_IsWeaponShopLocation(locationid) && (strfind(spotName, "Balcao", true) != -1 || strfind(spotName, "Vitrine", true) != -1))
    {
        ShowWeaponShopDialog(playerid);
        return 1;
    }

    if (World_IsStoreLocation(locationid) && strfind(spotName, "Estoque", true) == -1)
    {
        ShowConvenienceStoreDialog(playerid);
        return 1;
    }

    if (PlayerInfo[playerid][pJob] == JOB_VENDEDOR || PlayerInfo[playerid][pJob] == JOB_FRENTISTA)
    {
        return InteriorSpot_GiveJobReward(playerid, PlayerInfo[playerid][pJob], 140, 50, "Estoque conferido e atendimento registrado. Pagamento e XP recebidos.");
    }

    if (jobid != JOB_NONE)
    {
        return InteriorSpot_GiveJobReward(playerid, jobid, 120, 40, "Ponto de estoque conferido. Pagamento e XP recebidos.");
    }

    ShowConvenienceStoreDialog(playerid);
    return 1;
}

stock InteriorSpot_HandleKitchen(playerid)
{
    if (PlayerInfo[playerid][pJob] == JOB_COZINHEIRO || PlayerInfo[playerid][pJob] == JOB_MOTOBOY)
    {
        Needs_AddPlayerValues(playerid, 18, 6, 0);
        return InteriorSpot_GiveJobReward(playerid, PlayerInfo[playerid][pJob], 150, 55, "Pedido preparado. Voce tambem comeu algo rapido.");
    }

    if (World_IsPlayerAtRestaurant(playerid))
    {
        ShowRestaurantDialog(playerid);
        return 1;
    }

    SendClientMessage(playerid, COLOR_ORANGE, "A cozinha e area de trabalho. Clientes devem comprar no balcao NPC.");
    return 1;
}

stock InteriorSpot_HandleTableService(playerid)
{
    if (PlayerInfo[playerid][pJob] == JOB_GARCOM)
    {
        return InteriorSpot_GiveJobReward(playerid, JOB_GARCOM, 130, 50, "Mesa atendida. Pagamento e XP recebidos.");
    }

    ShowRestaurantDialog(playerid);
    return 1;
}

stock HandleInteriorSpotServiceAction(playerid, action, spotid)
{
    new locationid = gInteriorSpots[spotid][spotLocation];
    new jobid;

    switch (action)
    {
        case SPOT_ACTION_CITYHALL:
        {
            ShowCityHallDialog(playerid);
        }
        case SPOT_ACTION_HOSPITAL:
        {
            InteriorSpot_HandleHospital(playerid);
        }
        case SPOT_ACTION_POLICE_REPORT:
        {
            InteriorSpot_HandlePoliceReport(playerid, spotid);
        }
        case SPOT_ACTION_POLICE_CELL:
        {
            InteriorSpot_HandlePoliceCell(playerid);
        }
        case SPOT_ACTION_DEALERSHIP:
        {
            ShowDealershipDialog(playerid);
        }
        case SPOT_ACTION_MECHANIC:
        {
            if (PlayerInfo[playerid][pJob] == JOB_MECANICO)
            {
                InteriorSpot_GiveJobReward(playerid, JOB_MECANICO, 180, 60, "Ordem de reparo concluida no box. Pagamento e XP recebidos.");
            }
            else
            {
                SendClientMessage(playerid, COLOR_GRAY, "Atendente NPC da oficina: traga o veiculo ao patio e use /oficina.");
            }
        }
        case SPOT_ACTION_STORE:
        {
            InteriorSpot_HandleStore(playerid, spotid);
        }
        case SPOT_ACTION_KITCHEN:
        {
            InteriorSpot_HandleKitchen(playerid);
        }
        case SPOT_ACTION_TABLE_SERVICE:
        {
            InteriorSpot_HandleTableService(playerid);
        }
        default:
        {
            jobid = Job_FindByLocation(locationid);
            if (jobid == JOB_NONE)
            {
                SendClientMessage(playerid, COLOR_GRAY, "Ponto interno informativo.");
            }
            else
            {
                InteriorSpot_GiveJobReward(playerid, jobid, 120, 45, "Servico interno concluido. Pagamento e XP recebidos.");
            }
        }
    }

    return 1;
}

stock HandleJobCommands(playerid, cmdtext[])
{
    new command[32];
    new param[64];
    new param2[64];
    new param3[64];
    new index;
    new targetid;
    new severity;
    new multiplier;
    new fineid;
    new message[128];

    index = GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/emprego", true) == 0)
    {
        Job_SendCurrentInfo(playerid);
        return 1;
    }

    if (strcmp(command, "/profissoes", true) == 0 || strcmp(command, "/profissao", true) == 0 || strcmp(command, "/empregos", true) == 0)
    {
        Job_ShowProfessionsPanel(playerid);
        return 1;
    }

    if (strcmp(command, "/progresso", true) == 0 || strcmp(command, "/progressao", true) == 0)
    {
        Job_SendCurrentInfo(playerid);
        Life_ShowActivityCenter(playerid);
        return 1;
    }

    if (strcmp(command, "/rankingentregas", true) == 0 || strcmp(command, "/topentregas", true) == 0 || strcmp(command, "/rankentregador", true) == 0)
    {
        Delivery_SendRanking(playerid);
        return 1;
    }

    if (strcmp(command, "/rankingtaxi", true) == 0 || strcmp(command, "/toptaxi", true) == 0 || strcmp(command, "/ranktaxista", true) == 0)
    {
        Taxi_SendRanking(playerid);
        return 1;
    }

    if (strcmp(command, "/rankingmecanico", true) == 0 || strcmp(command, "/topmecanico", true) == 0 || strcmp(command, "/rankmecanico", true) == 0)
    {
        Mechanic_SendRanking(playerid);
        return 1;
    }

    if (strcmp(command, "/trabalhar", true) == 0 || strcmp(command, "/baterponto", true) == 0 || strcmp(command, "/plantao", true) == 0)
    {
        Work_Start(playerid);
        return 1;
    }

    if (strcmp(command, "/bico", true) == 0 || strcmp(command, "/freela", true) == 0)
    {
        Job_DoSideGig(playerid);
        return 1;
    }

    if (strcmp(command, "/cancelartrabalho", true) == 0 || strcmp(command, "/cancelarentrega", true) == 0)
    {
        if (!Work_Cancel(playerid))
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta em expediente.");
        }
        return 1;
    }

    if (strcmp(command, "/notafiscal", true) == 0 || strcmp(command, "/carga", true) == 0 || strcmp(command, "/manifesto", true) == 0)
    {
        Cargo_SendPlayerManifest(playerid);
        return 1;
    }

    if (strcmp(command, "/jobveiculos", true) == 0 || strcmp(command, "/veiculostrabalho", true) == 0)
    {
        format(message, sizeof(message), "Veiculos de profissao carregados: %d/%d. Arquivo: %s.", gJobVehicleCount, MAX_JOB_CONFIG_VEHICLES, JOB_VEHICLES_FILE);
        SendClientMessage(playerid, COLOR_YELLOW, message);
        SendClientMessage(playerid, COLOR_GRAY, "Criar: /addjobveiculo [job] [modelo/atual] [cor1] [cor2] [fuel]");
        SendClientMessage(playerid, COLOR_GRAY, "Ajustar: /veiculomaisperto, /moverveiculomaisperto, /ajustarveiculo [id] ou /salvarveiculoatual.");
        SendClientMessage(playerid, COLOR_GRAY, "Remover: /removerjobveiculo [id] ou /removerveiculo [id].");
        return 1;
    }

    if (strcmp(command, "/veiculomaisperto", true) == 0 || strcmp(command, "/carromaisperto", true) == 0 || strcmp(command, "/jobveiculomaisperto", true) == 0)
    {
        if (!JobVehicle_CanManage(playerid))
        {
            SendClientMessage(playerid, COLOR_RED, "Voce nao tem permissao para consultar frota.");
            return 1;
        }
        return JobVehicle_SendNearest(playerid);
    }

    if (strcmp(command, "/moverveiculomaisperto", true) == 0 || strcmp(command, "/ajustarveiculomaisperto", true) == 0 || strcmp(command, "/reposicionarveiculomaisperto", true) == 0 || strcmp(command, "/setveiculomaisperto", true) == 0)
    {
        return JobVehicle_AdjustNearest(playerid);
    }

    if (strcmp(command, "/ajustarveiculo", true) == 0 || strcmp(command, "/reposicionarveiculo", true) == 0 || strcmp(command, "/setveiculo", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/ajustarveiculo [id]");
        }
        return JobVehicle_AdjustSlot(playerid, strval(param) - 1, 0);
    }

    if (strcmp(command, "/salvarveiculoatual", true) == 0 || strcmp(command, "/ajustarveiculoatual", true) == 0 || strcmp(command, "/salvarcarroatual", true) == 0)
    {
        if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        {
            SendClientMessage(playerid, COLOR_RED, "Entre dirigindo um veiculo de frota para salvar a posicao dele.");
            return 1;
        }
        return JobVehicle_AdjustSlot(playerid, 0, 1);
    }

    if (strcmp(command, "/removerjobveiculo", true) == 0 || strcmp(command, "/removerveiculo", true) == 0 || strcmp(command, "/deljobveiculo", true) == 0 || strcmp(command, "/delveiculo", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/removerjobveiculo [id]");
        }
        return JobVehicle_RemoveSlot(playerid, strval(param) - 1);
    }

    if (strcmp(command, "/irveiculo", true) == 0 || strcmp(command, "/irjobveiculo", true) == 0 || strcmp(command, "/gotoveiculo", true) == 0 || strcmp(command, "/tpveiculo", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return JobVehicle_ShowGotoDialog(playerid, 0);
        }
        if (!IsNumericString(param))
        {
            return SendUsage(playerid, "/irveiculo [id]");
        }
        return JobVehicle_GotoSlot(playerid, strval(param) - 1);
    }

    if (strcmp(command, "/addjobveiculo", true) == 0 || strcmp(command, "/criarjobveiculo", true) == 0 || strcmp(command, "/salvarjobveiculo", true) == 0)
    {
        new jobid;
        new modelid;
        new color1 = 1;
        new color2 = 1;
        new fuel = FUEL_MAX_VALUE;
        new useCurrentVehicle;

        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)))
        {
            return SendUsage(playerid, "/addjobveiculo [job] [modelo/atual] [cor1] [cor2] [fuel]");
        }

        jobid = JobVehicle_ParseJob(param);
        if (strcmp(param2, "atual", true) == 0 || strcmp(param2, "current", true) == 0)
        {
            useCurrentVehicle = 1;
        }
        else
        {
            if (!IsNumericString(param2))
            {
                return SendUsage(playerid, "/addjobveiculo [job] [modelo/atual] [cor1] [cor2] [fuel]");
            }
            modelid = strval(param2);
        }

        if (GetNextParam(cmdtext, index, param, sizeof(param)) && IsNumericString(param, 1))
        {
            color1 = strval(param);
        }
        if (GetNextParam(cmdtext, index, param, sizeof(param)) && IsNumericString(param, 1))
        {
            color2 = strval(param);
        }
        if (GetNextParam(cmdtext, index, param, sizeof(param)) && IsNumericString(param))
        {
            fuel = strval(param);
        }

        return JobVehicle_AddCommand(playerid, jobid, modelid, color1, color2, fuel, useCurrentVehicle);
    }

    if (strcmp(command, "/reloadjobveiculos", true) == 0 || strcmp(command, "/recarregarjobveiculos", true) == 0)
    {
        if (!IsAdminOwnerLevel(playerid))
        {
            SendClientMessage(playerid, COLOR_RED, "Voce nao tem permissao para usar este comando.");
            return 1;
        }

        JobVehicle_LoadAll();
        format(message, sizeof(message), "Frota de profissoes recarregada: %d veiculos.", gJobVehicleCount);
        SendClientMessage(playerid, COLOR_GREEN, message);
        return 1;
    }

    if (strcmp(command, "/demitir", true) == 0)
    {
        Work_Cancel(playerid, 0);
        SetPlayerJob(playerid, JOB_NONE);
        SendClientMessage(playerid, COLOR_ORANGE, "Voce saiu do seu emprego atual.");
        return 1;
    }

    if (strcmp(command, "/servico", true) == 0)
    {
        Job_GenericService(playerid);
        return 1;
    }

    if (strcmp(command, "/curar", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/curar [id]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid))
        {
            return 1;
        }

        Job_HealCommand(playerid, targetid);
        return 1;
    }

    if (strcmp(command, "/repararcarro", true) == 0)
    {
        Job_RepairCommand(playerid);
        return 1;
    }

    if (strcmp(command, "/pintarcarro", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)))
        {
            return SendUsage(playerid, "/pintarcarro [cor1] [cor2]");
        }

        if (!IsNumericString(param) || !IsNumericString(param2))
        {
            return 1;
        }

        Job_PaintVehicleCommand(playerid, strval(param), strval(param2));
        return 1;
    }

    if (strcmp(command, "/abastecer", true) == 0)
    {
        if (PlayerInfo[playerid][pJob] == JOB_FRENTISTA && (Job_IsPlayerNearWorkplace(playerid, JOB_FRENTISTA) || World_IsPlayerAtGasStation(playerid)))
        {
            Job_FuelCommand(playerid);
        }
        else
        {
            NpcFuelRefuel(playerid);
        }
        return 1;
    }

    if (strcmp(command, "/oficina", true) == 0 || strcmp(command, "/repararnpc", true) == 0)
    {
        NpcWorkshopRepair(playerid);
        return 1;
    }

    if (strcmp(command, "/multa", true) == 0 || strcmp(command, "/multas", true) == 0 || strcmp(command, "/ctb", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            Job_SendFineCatalogPreview(playerid);
            return SendUsage(playerid, "/multa [id] [numero]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid))
        {
            return 1;
        }

        if (!GetNextParam(cmdtext, index, param2, sizeof(param2)) || !IsNumericString(param2))
        {
            Job_SendFineCatalogPreview(playerid);
            return SendUsage(playerid, "/multa [id] [numero]");
        }

        fineid = strval(param2);
        return Job_FineCatalogCommand(playerid, targetid, fineid);
    }

    if (strcmp(command, "/multar", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)))
        {
            return SendUsage(playerid, "/multar [id] [gravidade] [mult]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid))
        {
            return 1;
        }

        severity = Cfg_ParseTrafficSeverity(param2);
        if (severity == 0)
        {
            SendClientMessage(playerid, COLOR_RED, "Gravidade invalida. Use leve, media, grave ou gravissima.");
            return SendUsage(playerid, "/multar [id] [gravidade] [mult]");
        }

        multiplier = 1;
        if (GetNextParam(cmdtext, index, param3, sizeof(param3)))
        {
            if (!IsNumericString(param3) || !Cfg_TrafficMultiplierOk(strval(param3)))
            {
                SendClientMessage(playerid, COLOR_RED, "Multiplicador invalido. Permitidos: 2, 3, 5, 10, 20 ou 60.");
                return 1;
            }
            multiplier = strval(param3);
        }

        Job_FineCommand(playerid, targetid, severity, multiplier);
        return 1;
    }

    if (strcmp(command, "/taximetro", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)))
        {
            return SendUsage(playerid, "/taximetro [id] [valor]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid) || !IsNumericString(param2))
        {
            return 1;
        }

        Job_TaxiFareCommand(playerid, targetid, strval(param2));
        return 1;
    }

    if (strcmp(command, "/prender", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/prender [id] [crime_id opcional]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid))
        {
            return 1;
        }

        Job_ArrestCommand(playerid, targetid);
        return 1;
    }

    if (strcmp(command, "/soltar", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            return SendUsage(playerid, "/soltar [id]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid))
        {
            return 1;
        }

        Job_ReleaseCommand(playerid, targetid);
        return 1;
    }

    return 0;
}

stock SetPlayerJob(playerid, jobid, saveNow = 1)
{
    if (!PlayerInfo[playerid][pLogged])
    {
        return 0;
    }

    if (jobid != JOB_NONE && Job_GetIndex(jobid) == -1)
    {
        return 0;
    }

    if (!Job_PlayerMeetsAccessLevel(playerid, jobid))
    {
        return 0;
    }

    if (gWorkActive[playerid])
    {
        Work_Cancel(playerid, 0);
    }

    if (PlayerInfo[playerid][pJob] != jobid)
    {
        Work_ResetStreak(playerid);
        Work_ResetRunState(playerid);
    }

    PlayerInfo[playerid][pJob] = jobid;
    if (jobid != JOB_NONE)
    {
        Life_TutorialAdvance(playerid, 2);
    }

    if (saveNow)
    {
        SaveAccountData(playerid, 0);
    }
    return 1;
}
