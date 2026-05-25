#if defined _nova_hospital_included
    #endinput
#endif
#define _nova_hospital_included

#define HOSPITAL_TREATMENT_COST     (250)
#define HOSPITAL_DEATH_COST         (500)
#define HOSPITAL_PLAN_COST          (900)
#define HOSPITAL_PLAN_TREAT_COST    (60)
#define HOSPITAL_PLAN_DEATH_COST    (120)

new gHospitalRespawn[MAX_PLAYERS];

stock Hospital_GetTreatmentCost(playerid)
{
    if (PlayerInfo[playerid][pHealthPlan])
    {
        return Cfg_Price(gCfgHospitalPlanTreatCost);
    }
    return Cfg_Price(gCfgHospitalTreatCost);
}

stock Hospital_GetDeathCost(playerid)
{
    if (PlayerInfo[playerid][pHealthPlan])
    {
        return Cfg_Price(gCfgHospitalPlanDeathCost);
    }
    return Cfg_Price(gCfgHospitalDeathCost);
}

stock Hospital_GetInjuryName(injury, output[], size = sizeof(output))
{
    switch (injury)
    {
        case 1: format(output, size, "ferimento leve");
        case 2: format(output, size, "fratura");
        case 3: format(output, size, "trauma grave");
        default: format(output, size, "nenhum");
    }
    return 1;
}

stock Hospital_TreatPlayer(playerid)
{
    new Float:health;
    new message[128];
    new injuryName[32];
    new cost;

    GetPlayerHealth(playerid, health);
    if (health >= 99.0 && PlayerInfo[playerid][pInjury] == 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao precisa de atendimento agora.");
        return 1;
    }

    cost = Hospital_GetTreatmentCost(playerid);
    if (!Bank_TakePayment(playerid, cost, 0))
    {
        format(message, sizeof(message), "Atendimento NPC custa $%d em dinheiro/banco.", cost);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    Hospital_GetInjuryName(PlayerInfo[playerid][pInjury], injuryName, sizeof(injuryName));
    PlayerInfo[playerid][pInjury] = 0;
    PlayerInfo[playerid][pMedicalSeverity] = 0;
    PlayerInfo[playerid][pMedicalTreatmentDue] = 0;
    SetPlayerHealth(playerid, 100.0);
    SaveAccountData(playerid, 0);

    format(message, sizeof(message), "Triagem NPC concluida. Tratado: %s | Custo: $%d.", injuryName, cost);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Hospital_OnPlayerDeath(playerid)
{
    gHospitalRespawn[playerid] = 1;
    PlayerInfo[playerid][pInjury] = 1 + random(3);
    PlayerInfo[playerid][pMedicalSeverity] = PlayerInfo[playerid][pInjury];
    PlayerInfo[playerid][pMedicalTreatmentDue] = 1;
    return 1;
}

stock Hospital_OnPlayerSpawn(playerid)
{
    new message[128];

    if (!gHospitalRespawn[playerid])
    {
        return 0;
    }

    gHospitalRespawn[playerid] = 0;
    SetPlayerToLocation(playerid, LOCATION_HOSPITAL);
    SetPlayerHealth(playerid, 100.0);
    SetPlayerArmour(playerid, 0.0);
    PlayerInfo[playerid][pLastSpawn] = LOCATION_HOSPITAL;

    if (Bank_TakePayment(playerid, Hospital_GetDeathCost(playerid), 0))
    {
        format(message, sizeof(message), "Emergencia NPC no hospital. Custo: $%d.", Hospital_GetDeathCost(playerid));
        SendClientMessage(playerid, COLOR_ORANGE, message);
    }
    else
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Voce recebeu atendimento publico de emergencia no hospital.");
    }

    SaveAccountData(playerid);
    return 1;
}

stock Hospital_BuyHealthPlan(playerid)
{
    new message[96];

    if (PlayerInfo[playerid][pHealthPlan])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce ja possui plano de saude ativo.");
        return 1;
    }

    if (!Bank_TakePayment(playerid, Cfg_Price(gCfgHospitalPlanCost), 0))
    {
        format(message, sizeof(message), "Plano de saude custa $%d em dinheiro/banco.", Cfg_Price(gCfgHospitalPlanCost));
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    Life_SetHealthPlan(playerid);
    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Plano de saude contratado com atendente NPC e validade definida.");
    return 1;
}

stock Hospital_SendStatus(playerid)
{
    new injuryName[32];
    new message[128];
    new Float:health;

    GetPlayerHealth(playerid, health);
    Hospital_GetInjuryName(PlayerInfo[playerid][pInjury], injuryName, sizeof(injuryName));
    format(message, sizeof(message), "Saude: %.0f%% | Ferimento: %s | Gravidade: %d | Plano: %s", health, injuryName, PlayerInfo[playerid][pMedicalSeverity], PlayerInfo[playerid][pHealthPlan] ? ("ativo") : ("nenhum"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}

stock HandleHospitalCommands(playerid, cmdtext[])
{
    new command[32];

    GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/saude", true) == 0 || strcmp(command, "/ferimentos", true) == 0)
    {
        Hospital_SendStatus(playerid);
        return 1;
    }

    if (strcmp(command, "/plano", true) == 0 || strcmp(command, "/planosaude", true) == 0)
    {
        if (!World_IsPlayerAtServiceInterior(playerid, LOCATION_HOSPITAL))
        {
            SendClientMessage(playerid, COLOR_GRAY, "Contrate plano no balcao do hospital.");
            return 1;
        }

        Hospital_BuyHealthPlan(playerid);
        return 1;
    }

    return 0;
}

stock Hospital_OnPlayerDisconnect(playerid)
{
    gHospitalRespawn[playerid] = 0;
    return 1;
}
