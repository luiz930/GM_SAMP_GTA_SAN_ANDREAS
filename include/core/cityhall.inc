#if defined _nova_cityhall_included
    #endinput
#endif
#define _nova_cityhall_included

#define CITYHALL_DOCUMENT_COST      (100)
#define CITYHALL_RENAME_COST        (500)
#define LICENSE_CNH_COST            (300)
#define LICENSE_HEAVY_COST          (450)
#define LICENSE_MEDICAL_COST        (350)
#define LICENSE_OAB_COST            (330)
#define LICENSE_PUBLIC_COST         (350)
#define LICENSE_POLICE_COST         (350)
#define CITYHALL_MAX_ACTIONS        (11)
#define CITYHALL_JOB_ACTIONS        (4)
#define CITYHALL_LICENSE_ACTIONS    (6)
#define CITYHALL_ACT_INFO           (1)
#define CITYHALL_ACT_JOB_PANEL      (2)
#define CITYHALL_ACT_RENAME         (3)
#define CITYHALL_ACT_DOCS           (4)
#define CITYHALL_ACT_PICK_JOB       (5)
#define CITYHALL_ACT_LICENSES       (6)
#define CITYHALL_ACT_EXIT           (7)
#define CITYHALL_ACT_TAXES          (8)
#define CITYHALL_ACT_BUDGET         (9)
#define CITYHALL_ACT_PUBLIC         (10)
#define CITYJOB_ACT_CURRENT         (1)
#define CITYJOB_ACT_REQUIREMENTS    (2)
#define CITYJOB_ACT_QUIT            (3)
#define CITYJOB_ACT_BACK            (4)

new gCityHallActions[MAX_PLAYERS][CITYHALL_MAX_ACTIONS];
new gCityHallActionCount[MAX_PLAYERS];
new gCityHallJobActions[MAX_PLAYERS][CITYHALL_JOB_ACTIONS];
new gCityHallJobActionCount[MAX_PLAYERS];
new gCityHallLicenseActions[MAX_PLAYERS][CITYHALL_LICENSE_ACTIONS];
new gCityHallLicenseActionCount[MAX_PLAYERS];

stock CityHall_AddAction(playerid, list[], size, actionid, label[])
{
    new line[96];

    if (gCityHallActionCount[playerid] >= CITYHALL_MAX_ACTIONS)
    {
        return 0;
    }

    gCityHallActions[playerid][gCityHallActionCount[playerid]] = actionid;
    gCityHallActionCount[playerid]++;
    format(line, sizeof(line), "%s\n", label);
    strcat(list, line, size);
    return 1;
}

stock CityHall_AddJobAction(playerid, list[], size, actionid, label[])
{
    new line[96];

    if (gCityHallJobActionCount[playerid] >= CITYHALL_JOB_ACTIONS)
    {
        return 0;
    }

    gCityHallJobActions[playerid][gCityHallJobActionCount[playerid]] = actionid;
    gCityHallJobActionCount[playerid]++;
    format(line, sizeof(line), "%s\n", label);
    strcat(list, line, size);
    return 1;
}

stock ShowCityHallDialog(playerid)
{
    new list[768];

    list[0] = 0;
    gCityHallActionCount[playerid] = 0;
    CityHall_AddAction(playerid, list, sizeof(list), CITYHALL_ACT_INFO, "Ver informacoes do personagem");
    CityHall_AddAction(playerid, list, sizeof(list), CITYHALL_ACT_JOB_PANEL, "Painel da profissao");
    CityHall_AddAction(playerid, list, sizeof(list), CITYHALL_ACT_RENAME, "Mudar nome RP");
    CityHall_AddAction(playerid, list, sizeof(list), CITYHALL_ACT_DOCS, "Emitir documentos");
    CityHall_AddAction(playerid, list, sizeof(list), CITYHALL_ACT_PICK_JOB, "Escolher emprego");
    CityHall_AddAction(playerid, list, sizeof(list), CITYHALL_ACT_LICENSES, "Solicitar licencas");
    CityHall_AddAction(playerid, list, sizeof(list), CITYHALL_ACT_TAXES, "Impostos e taxas");
    CityHall_AddAction(playerid, list, sizeof(list), CITYHALL_ACT_BUDGET, "Orcamento e licitacoes");
    CityHall_AddAction(playerid, list, sizeof(list), CITYHALL_ACT_PUBLIC, "Servicos publicos");
    CityHall_AddAction(playerid, list, sizeof(list), CITYHALL_ACT_EXIT, "Sair da Prefeitura");

    ShowPlayerDialog(
        playerid,
        DIALOG_CITYHALL,
        DIALOG_STYLE_LIST,
        "Prefeitura",
        list,
        "Selecionar",
        "Fechar"
    );
    return 1;
}

stock CityHall_SendCharacterInfo(playerid)
{
    new message[144];
    new jobLabel[32];
    new minutes;

    UpdatePlayerLiveData(playerid);
    GetJobName(PlayerInfo[playerid][pJob], jobLabel, sizeof(jobLabel));
    minutes = PlayerInfo[playerid][pOnlineTime] / 60;

    format(message, sizeof(message), "Personagem: %s | Emprego: %s | Nivel: %d", PlayerInfo[playerid][pCharacterName], jobLabel, Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob]));
    SendClientMessage(playerid, COLOR_BLUE, message);

    if (PlayerInfo[playerid][pDocuments])
    {
        SendClientMessage(playerid, COLOR_BLUE, "Documentos: emitidos.");
    }
    else
    {
        SendClientMessage(playerid, COLOR_GRAY, "Documentos: pendentes. Emita seus documentos na Prefeitura.");
    }

    format(message, sizeof(message), "Dinheiro: $%d | Tempo online: %d min | XP: %d | Veiculo salvo: %d", PlayerInfo[playerid][pMoney], minutes, Job_GetPlayerXP(playerid, PlayerInfo[playerid][pJob]), PlayerInfo[playerid][pVehicleModel]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "CNH: %d | Pesada: %d | Medica: %d | OAB: %d | Publico: %d | Porte arma: %d", PlayerInfo[playerid][pLicenseCNH], PlayerInfo[playerid][pLicenseHeavy], PlayerInfo[playerid][pLicenseMedical], PlayerInfo[playerid][pLicenseOAB], PlayerInfo[playerid][pLicensePublic], PlayerInfo[playerid][pLicensePolice]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}

stock CityHall_IssueDocuments(playerid)
{
    new message[128];

    if (!Bank_TakePayment(playerid, Cfg_Price(gCfgCityDocumentCost), 0))
    {
        format(message, sizeof(message), "Voce precisa de $%d em dinheiro/banco para emitir documentos.", Cfg_Price(gCfgCityDocumentCost));
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    Life_SetPersonalDocuments(playerid);
    PlayerInfo[playerid][pCivilCPF] = 1;
    PlayerInfo[playerid][pCivilRG] = 1;
    PlayerInfo[playerid][pCivilCertificate] = 1;
    SaveAccountData(playerid, 0);

    format(message, sizeof(message), "Documentos emitidos com sucesso. Taxa paga: $%d.", Cfg_Price(gCfgCityDocumentCost));
    SendClientMessage(playerid, COLOR_GREEN, message);
    Life_TutorialAdvance(playerid, 1);
    Life_AddMissionProgress(playerid, 5, 1);
    Life_CheckAchievements(playerid);
    return 1;
}

stock CityHall_AssignDeliveryJob(playerid)
{
    if (!PlayerInfo[playerid][pDocuments])
    {
        SendClientMessage(playerid, COLOR_RED, "Voce precisa emitir seus documentos antes de escolher um emprego.");
        return 1;
    }

    ShowJobSelectionDialog(playerid);
    return 1;
}

stock ShowCityHallJobPanelDialog(playerid)
{
    new list[256];

    list[0] = 0;
    gCityHallJobActionCount[playerid] = 0;
    CityHall_AddJobAction(playerid, list, sizeof(list), CITYJOB_ACT_CURRENT, "Ver profissao atual");
    CityHall_AddJobAction(playerid, list, sizeof(list), CITYJOB_ACT_REQUIREMENTS, "Ver requisitos da profissao");
    CityHall_AddJobAction(playerid, list, sizeof(list), CITYJOB_ACT_QUIT, "Pedir demissao");
    CityHall_AddJobAction(playerid, list, sizeof(list), CITYJOB_ACT_BACK, "Voltar");
    ShowPlayerDialog(playerid, DIALOG_CITYHALL_JOB_PANEL, DIALOG_STYLE_LIST, "Prefeitura - Profissao", list, "Selecionar", "Fechar");
    return 1;
}

stock ShowCityHallLicenseDialog(playerid)
{
    new list[512];
    new line[96];

    list[0] = 0;
    gCityHallLicenseActionCount[playerid] = 0;
    gCityHallLicenseActions[playerid][gCityHallLicenseActionCount[playerid]++] = 0;
    format(line, sizeof(line), "CNH\t$%d\t%d\n", Cfg_Price(gCfgLicenseCNHCost), PlayerInfo[playerid][pLicenseCNH]); strcat(list, line, sizeof(list));
    gCityHallLicenseActions[playerid][gCityHallLicenseActionCount[playerid]++] = 1;
    format(line, sizeof(line), "Licenca Pesada\t$%d\t%d\n", Cfg_Price(gCfgLicenseHeavyCost), PlayerInfo[playerid][pLicenseHeavy]); strcat(list, line, sizeof(list));
    gCityHallLicenseActions[playerid][gCityHallLicenseActionCount[playerid]++] = 2;
    format(line, sizeof(line), "Diploma Medico\t$%d\t%d\n", Cfg_Price(gCfgLicenseMedicalCost), PlayerInfo[playerid][pLicenseMedical]); strcat(list, line, sizeof(list));
    gCityHallLicenseActions[playerid][gCityHallLicenseActionCount[playerid]++] = 3;
    format(line, sizeof(line), "OAB\t$%d\t%d\n", Cfg_Price(gCfgLicenseOABCost), PlayerInfo[playerid][pLicenseOAB]); strcat(list, line, sizeof(list));
    gCityHallLicenseActions[playerid][gCityHallLicenseActionCount[playerid]++] = 4;
    format(line, sizeof(line), "Cargo Publico\t$%d\t%d\n", Cfg_Price(gCfgLicensePublicCost), PlayerInfo[playerid][pLicensePublic]); strcat(list, line, sizeof(list));
    gCityHallLicenseActions[playerid][gCityHallLicenseActionCount[playerid]++] = 5;
    format(line, sizeof(line), "Porte de Arma\t$%d\t%d\n", Cfg_Price(gCfgLicensePoliceCost), PlayerInfo[playerid][pLicensePolice]); strcat(list, line, sizeof(list));

    ShowPlayerDialog(playerid, DIALOG_CITYHALL_LICENSES, DIALOG_STYLE_TABLIST, "Prefeitura - Licencas", list, "Emitir", "Voltar");
    return 1;
}

stock CityHall_BuyLicense(playerid, listitem)
{
    new cost;
    new message[128];
    new minScore = gCfgCitizenLicenseMinScore;

    switch (listitem)
    {
        case 0:
        {
            if (PlayerInfo[playerid][pLicenseCNH]) return SendClientMessage(playerid, COLOR_GRAY, "Voce ja possui CNH.");
            cost = gCfgLicenseCNHCost;
        }
        case 1:
        {
            if (PlayerInfo[playerid][pLicenseHeavy]) return SendClientMessage(playerid, COLOR_GRAY, "Voce ja possui licenca pesada.");
            cost = gCfgLicenseHeavyCost;
        }
        case 2:
        {
            if (PlayerInfo[playerid][pLicenseMedical]) return SendClientMessage(playerid, COLOR_GRAY, "Voce ja possui diploma medico.");
            cost = gCfgLicenseMedicalCost;
            minScore = gCfgCitizenJobTrustedMinScore;
        }
        case 3:
        {
            if (PlayerInfo[playerid][pLicenseOAB]) return SendClientMessage(playerid, COLOR_GRAY, "Voce ja possui OAB.");
            cost = gCfgLicenseOABCost;
            minScore = gCfgCitizenJobTrustedMinScore;
        }
        case 4:
        {
            if (PlayerInfo[playerid][pLicensePublic]) return SendClientMessage(playerid, COLOR_GRAY, "Voce ja possui cargo publico.");
            cost = gCfgLicensePublicCost;
            minScore = gCfgCitizenJobTrustedMinScore;
        }
        case 5:
        {
            if (PlayerInfo[playerid][pLicensePolice]) return SendClientMessage(playerid, COLOR_GRAY, "Voce ja possui Porte de Arma.");
            cost = gCfgLicensePoliceCost;
            minScore = gCfgCitizenJobTrustedMinScore;
        }
        default:
        {
            SendClientMessage(playerid, COLOR_RED, "Licenca invalida.");
            return 1;
        }
    }

    if (!Life_CheckScoreGate(playerid, minScore, "Emissao de licenca"))
    {
        return 1;
    }

    if (listitem == 5 && (PlayerInfo[playerid][pWanted] > 0 || PlayerInfo[playerid][pJailTime] > 0))
    {
        SendClientMessage(playerid, COLOR_RED, "Porte de Arma negado para jogador procurado ou preso.");
        return 1;
    }

    cost = Cfg_Price(cost);
    if (!Bank_TakePayment(playerid, cost, 0))
    {
        format(message, sizeof(message), "Voce precisa de $%d em dinheiro/banco para emitir esta licenca.", cost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    switch (listitem)
    {
        case 0: Life_SetLicenseExpiry(playerid, 0);
        case 1: Life_SetLicenseExpiry(playerid, 1);
        case 2: Life_SetLicenseExpiry(playerid, 2);
        case 3: Life_SetLicenseExpiry(playerid, 3);
        case 4: Life_SetLicenseExpiry(playerid, 4);
        case 5: Life_SetLicenseExpiry(playerid, 5);
    }

    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Licenca emitida com sucesso.");
    format(message, sizeof(message), "license item=%d cost=%d score=%d", listitem, cost, PlayerInfo[playerid][pBankScore]);
    WritePlayerLog(LOG_CONTRACT_FILE, "LICENSE", playerid, message);
    return 1;
}

stock HandleCityHallLicenseDialog(playerid, response, listitem)
{
    new licenseid;

    if (!response)
    {
        ShowCityHallDialog(playerid);
        return 1;
    }

    if (listitem < 0 || listitem >= gCityHallLicenseActionCount[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Opcao de licenca expirou. Abra novamente.");
        return ShowCityHallLicenseDialog(playerid);
    }

    licenseid = gCityHallLicenseActions[playerid][listitem];
    CityHall_BuyLicense(playerid, licenseid);
    return 1;
}

stock HandleCityHallJobPanelDialog(playerid, response, listitem)
{
    new actionid;

    if (!response)
    {
        return 1;
    }

    if (listitem < 0 || listitem >= gCityHallJobActionCount[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Opcao de profissao expirou. Abra novamente.");
        return ShowCityHallJobPanelDialog(playerid);
    }

    actionid = gCityHallJobActions[playerid][listitem];
    switch (actionid)
    {
        case CITYJOB_ACT_CURRENT:
        {
            Job_SendCurrentInfo(playerid);
        }
        case CITYJOB_ACT_REQUIREMENTS:
        {
            if (PlayerInfo[playerid][pJob] == JOB_NONE)
            {
                SendClientMessage(playerid, COLOR_GRAY, "Voce nao tem profissao atual.");
            }
            else
            {
                Job_SendInfo(playerid, PlayerInfo[playerid][pJob]);
            }
        }
        case CITYJOB_ACT_QUIT:
        {
            Work_Cancel(playerid, 0);
            SetPlayerJob(playerid, JOB_NONE);
            SendClientMessage(playerid, COLOR_ORANGE, "Voce pediu demissao na Prefeitura.");
        }
        case CITYJOB_ACT_BACK:
        {
            ShowCityHallDialog(playerid);
        }
    }
    return 1;
}

stock ShowCityHallRenameDialog(playerid)
{
    new message[192];

    format(message, sizeof(message), "Digite o novo nome RP no formato Nome_Sobrenome.\n\nTaxa de alteracao: $%d.", Cfg_Price(gCfgCityRenameCost));
    ShowPlayerDialog(playerid, DIALOG_CITYHALL_RENAME, DIALOG_STYLE_INPUT, "Prefeitura - Mudar nome RP", message, "Alterar", "Voltar");
    return 1;
}

stock HandleCityHallDialog(playerid, response, listitem)
{
    new actionid;

    if (!response)
    {
        return 1;
    }

    if (listitem < 0 || listitem >= gCityHallActionCount[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Opcao da Prefeitura expirou. Abra novamente.");
        return ShowCityHallDialog(playerid);
    }

    actionid = gCityHallActions[playerid][listitem];
    switch (actionid)
    {
        case CITYHALL_ACT_INFO:
        {
            CityHall_SendCharacterInfo(playerid);
        }
        case CITYHALL_ACT_JOB_PANEL:
        {
            ShowCityHallJobPanelDialog(playerid);
        }
        case CITYHALL_ACT_RENAME:
        {
            ShowCityHallRenameDialog(playerid);
        }
        case CITYHALL_ACT_DOCS:
        {
            CityHall_IssueDocuments(playerid);
        }
        case CITYHALL_ACT_PICK_JOB:
        {
            CityHall_AssignDeliveryJob(playerid);
        }
        case CITYHALL_ACT_LICENSES:
        {
            ShowCityHallLicenseDialog(playerid);
        }
        case CITYHALL_ACT_TAXES:
        {
            Life_ShowTaxesDialog(playerid);
        }
        case CITYHALL_ACT_BUDGET:
        {
            Life_ShowCityBudget(playerid);
            SendClientMessage(playerid, COLOR_GRAY, "Use /licitacao para participar de contratos publicos com empresa ativa.");
        }
        case CITYHALL_ACT_PUBLIC:
        {
            Life_ShowPublicSvcDialog(playerid);
        }
        case CITYHALL_ACT_EXIT:
        {
            SetPlayerToLocation(playerid, LOCATION_PREFEITURA);
            SendClientMessage(playerid, COLOR_GREEN, "Voce saiu da Prefeitura.");
        }
    }
    return 1;
}

stock HandleCityHallRenameDialog(playerid, response, inputtext[])
{
    new message[128];

    if (!response)
    {
        ShowCityHallDialog(playerid);
        return 1;
    }

    if (!IsValidCharacterName(inputtext))
    {
        SendClientMessage(playerid, COLOR_RED, "Nome invalido. Use o formato Nome_Sobrenome, apenas letras.");
        ShowCityHallRenameDialog(playerid);
        return 1;
    }

    if (!Bank_TakePayment(playerid, Cfg_Price(gCfgCityRenameCost), 0))
    {
        format(message, sizeof(message), "Voce precisa de $%d em dinheiro/banco para mudar o nome RP.", Cfg_Price(gCfgCityRenameCost));
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    format(PlayerInfo[playerid][pCharacterName], CHARACTER_NAME_SIZE, "%s", inputtext);
    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Nome RP alterado com sucesso na Prefeitura.");
    return 1;
}
