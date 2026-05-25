#if defined _nova_accounts_included
    #endinput
#endif
#define _nova_accounts_included

#define ACCOUNT_FORMAT_VERSION    (11)
#define DEFAULT_MONEY             (500)
#define DEFAULT_SKIN              (0)
#define ACCOUNT_REPAIR_MAX_LOAN   (500000)
#define ACCOUNT_REPAIR_MAX_BILL   (750000)
#define ACCOUNT_REPAIR_MAX_BUSDEBT (500000)

enum ePlayerInfo
{
    pAccountFormatVersion,
    pPasswordHash[PASSWORD_HASH_SIZE],
    pCharacterName[CHARACTER_NAME_SIZE],
    pMoney,
    pSkin,
    pAdminLevel,
    pVipLevel,
    pVipExpire,
    pVipLastKitDay,
    pVipTotalDays,
    pKills,
    pDeaths,
    pLastSpawn,
    pSpawnCount,
    Float:pPosX,
    Float:pPosY,
    Float:pPosZ,
    Float:pPosA,
    pInterior,
    pVirtualWorld,
    pOnlineTime,
    pExperience,
    pLevel,
    pExperienceTick,
    pDocuments,
    pDocumentsExpire,
    pJob,
    pLicenseCNH,
    pLicenseHeavy,
    pLicenseMedical,
    pLicenseOAB,
    pLicensePublic,
    pLicensePolice,
    pLicenseCNHExpire,
    pLicenseHeavyExpire,
    pLicenseMedicalExpire,
    pLicenseOABExpire,
    pLicensePublicExpire,
    pLicensePoliceExpire,
    pVehicleModel,
    pVehicleColor1,
    pVehicleColor2,
    pVehiclePlate[16],
    pVehicleFuel,
    Float:pVehicleHealth,
    Float:pVehiclePosX,
    Float:pVehiclePosY,
    Float:pVehiclePosZ,
    Float:pVehiclePosA,
    pVehicleInterior,
    pVehicleVirtualWorld,
    pVehicleParked,
    pVehicleInsurance,
    pVehicleGarage,
    pVehicleImpounded,
    pVehicleTaxDue,
    pTollTag,
    pBankMoney,
    pBankAccount,
    pBankCard,
    pBankLoan,
    pBankLoanOriginal,
    pBankLoanInstallmentValue,
    pBankLoanInstallments,
    pBankLoanNextDueDay,
    pBankScore,
    pBankGoodHistory,
    pBankBadHistory,
    pIncomeRegistered,
    pSalaryLastDay,
    pSalary,
    pSalaryWorkDay,
    pSalaryWorkTasks,
    pSalaryProductivityPaid,
    pFines,
    pTrafficPoints,
    pWanted,
    pJailTime,
    pJailCrimeId,
    pAdminJail,
    pMuteTime,
    pCriminalRecords,
    pInjury,
    pHealthPlan,
    pHealthPlanExpire,
    pMedicalSeverity,
    pMedicalTreatmentDue,
    pJusticeCases,
    pJusticeHearingDay,
    pJusticeSentence,
    pJusticeFineDue,
    pBusinessType,
    pBusinessEmployees,
    pBusinessBalance,
    pBusinessTaxDue,
    pBusinessPermitExpire,
    pBusinessEditorLoc,
    pPropertyTaxDue,
    pGovernmentTaxDue,
    pTaxLastDay,
    pBillWaterDue,
    pBillElectricDue,
    pBillInternetDue,
    pBillRentDue,
    pBillVehicleInsuranceDue,
    pBillHealthPlanDue,
    pBillLoanInstallmentDue,
    pBillBusinessPayrollDue,
    pBillDueDay,
    pBillLastGenerateDay,
    pBillLateChargeDay,
    pDirtyName,
    pCivilCPF,
    pCivilRG,
    pCivilCertificate,
    pCivilSignature,
    pCivilMarried,
    pCivilDivorces,
    pContractRent,
    pContractFinancing,
    pContractWork,
    pContractInsurance,
    pHomeSolar,
    pHouse,
    pRentedHouse,
    pHunger,
    pThirst,
    pFatigue,
    pSleep,
    pPantryFood,
    pPantryDrink,
    pNeedsTick,
    pNeedsWarningTick,
    pLogged,
    pSessionTick,
    pMissionDay,
    pMissionWork,
    pMissionMarket,
    pMissionBank,
    pMissionBill,
    pMissionDocs,
    pMissionRewarded,
    pAchievements,
    pTutorialStep,
    pIntroTutorialDone,
    pBusinessOrderDay,
    pBusinessOrders,
    pJusticeStatus,
    pJusticeDeadlineDay,
    pJusticeAppeals,
    pLoanInstallmentsPaid,
    pDailyRewardDay,
    pWeeklyRewardWeek,
    pLoginStreak,
    pLastLoginDay,
    pCityPassWeek,
    pCityPassJob,
    pCityPassEconomy,
    pCityPassPublic,
    pCityPassRewarded,
    pWeeklyWorkScore,
    pWeeklyBusinessScore,
    pWeeklyPoliceScore,
    pWeeklyCitizenScore,
    pBusinessStock,
    pBusinessContracts,
    pBusinessDebt,
    pBusinessRecoveryDay,
    pBusinessBankrupt,
    pVehicleInspectionDay,
    pMedicalShifts,
    pPoliceWarrants,
    pPoliceEvidence,
    pJusticeActiveWarrants,
    pJusticeActiveEvidence,
    pAnkleMonitor,
    pContractLimitDay,
    pContractsToday,
    pLogisticsCompleted,
    pLogisticsCanceled,
    pLogisticsLate,
    pLogisticsReputation,
    pLogisticsEarnings,
    pLogisticsGenerated,
    pAutoBusinessId,
    pAutoBusinessProfit,
    pAutoBusinessRevenue,
    pOnboardingRewarded,
    pWarZoneDay,
    pWarZoneKillsToday,
    pCrimeFaction,
    pCrimeRank,
    pCrimeRespect,
    pCrimeMissionCooldown,
    pCrimeHourlyStamp,
    pCrimeHourlyGain,
    pPoliticalOffice,
    pPoliticalTermStartDay,
    pPoliticalTermEndDay
}

new PlayerInfo[MAX_PLAYERS][ePlayerInfo];
new gPlayerConnected[MAX_PLAYERS];
new gPlayerAuthDialog[MAX_PLAYERS];
new gPlayerLoginTries[MAX_PLAYERS];
new gPasswordChangeTick[MAX_PLAYERS];
new gPasswordChangeNewHash[MAX_PLAYERS][PASSWORD_HASH_SIZE];
new gPasswordChangeMode[MAX_PLAYERS];
new gAccountCanonicalName[MAX_PLAYERS][MAX_PLAYER_NAME + 1];
new gPendingAccountName[MAX_PLAYERS][MAX_PLAYER_NAME + 1];
new gPendingAccountNameHash[MAX_PLAYERS][PASSWORD_HASH_SIZE];
new gPendingAccountNameTick[MAX_PLAYERS];
new gClassSkins[] = { 0, 7, 23, 29 };
new gAutoSaveTimer;
new gAccountSaveDirty[MAX_PLAYERS];
new gAccountSaveTick[MAX_PLAYERS];
new gAccountSaveForce;

forward AutoSaveAccounts();

stock MarkAccountDirty(playerid)
{
    if (!IsValidConnectedPlayer(playerid) || !PlayerInfo[playerid][pLogged])
    {
        return 0;
    }

    gAccountSaveDirty[playerid] = 1;
    gAccountSaveTick[playerid] = GetTickCount();
    return 1;
}

stock SaveAccountNow(playerid, updateLiveData = 1)
{
    new saved;

    gAccountSaveForce = 1;
    saved = SaveAccountData(playerid, updateLiveData);
    gAccountSaveForce = 0;
    return saved;
}

stock FlushAccountSaves(force = 0)
{
    new playerid;
    new saved;
    new tick = GetTickCount();
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (!gAccountSaveDirty[playerid] || !IsPlayerConnected(playerid) || !PlayerInfo[playerid][pLogged])
        {
            continue;
        }
        if (!force && (tick - gAccountSaveTick[playerid]) < 10000)
        {
            continue;
        }
        if (SaveAccountNow(playerid, 0))
        {
            gAccountSaveDirty[playerid] = 0;
            saved++;
        }
    }
    return saved;
}

stock Account_AppendRepair(report[], size, item[])
{
    if (size <= 1)
    {
        return 0;
    }

    if ((strlen(report) + strlen(item) + 2) >= size)
    {
        return 0;
    }

    if (strlen(report) > 0)
    {
        strcat(report, ", ", size);
    }
    strcat(report, item, size);
    return 1;
}

stock Account_RepairLegacyData(playerid, apply, report[], size)
{
    new repairs;
    new remainingInstallments;

    if (size > 0)
    {
        report[0] = 0;
    }

    if (PlayerInfo[playerid][pMoney] < 0)
    {
        repairs++;
        Account_AppendRepair(report, size, "saldo negativo");
        if (apply) PlayerInfo[playerid][pMoney] = 0;
    }
    if (PlayerInfo[playerid][pBankMoney] < 0)
    {
        repairs++;
        Account_AppendRepair(report, size, "banco negativo");
        if (apply) PlayerInfo[playerid][pBankMoney] = 0;
    }
    if (PlayerInfo[playerid][pSalary] < 0)
    {
        repairs++;
        Account_AppendRepair(report, size, "salario negativo");
        if (apply) PlayerInfo[playerid][pSalary] = 0;
    }
    if (PlayerInfo[playerid][pFines] < 0 || PlayerInfo[playerid][pFines] > MAX_PLAYER_FINE)
    {
        repairs++;
        Account_AppendRepair(report, size, "multas invalidas");
        if (apply)
        {
            if (PlayerInfo[playerid][pFines] < 0) PlayerInfo[playerid][pFines] = 0;
            if (PlayerInfo[playerid][pFines] > MAX_PLAYER_FINE) PlayerInfo[playerid][pFines] = MAX_PLAYER_FINE;
        }
    }
    if (PlayerInfo[playerid][pTrafficPoints] < 0 || PlayerInfo[playerid][pTrafficPoints] > MAX_TRAFFIC_POINTS)
    {
        repairs++;
        Account_AppendRepair(report, size, "pontos CNH invalidos");
        if (apply)
        {
            if (PlayerInfo[playerid][pTrafficPoints] < 0) PlayerInfo[playerid][pTrafficPoints] = 0;
            if (PlayerInfo[playerid][pTrafficPoints] > MAX_TRAFFIC_POINTS) PlayerInfo[playerid][pTrafficPoints] = MAX_TRAFFIC_POINTS;
        }
    }
    if (PlayerInfo[playerid][pJusticeFineDue] < 0 || PlayerInfo[playerid][pJusticeFineDue] > MAX_PLAYER_FINE)
    {
        repairs++;
        Account_AppendRepair(report, size, "sentenca invalida");
        if (apply)
        {
            if (PlayerInfo[playerid][pJusticeFineDue] < 0) PlayerInfo[playerid][pJusticeFineDue] = 0;
            if (PlayerInfo[playerid][pJusticeFineDue] > MAX_PLAYER_FINE) PlayerInfo[playerid][pJusticeFineDue] = MAX_PLAYER_FINE;
        }
    }
    if (PlayerInfo[playerid][pSkin] < 0 || PlayerInfo[playerid][pSkin] > 311)
    {
        repairs++;
        Account_AppendRepair(report, size, "skin invalida");
        if (apply) PlayerInfo[playerid][pSkin] = DEFAULT_SKIN;
    }
    if (PlayerInfo[playerid][pInterior] < 0 || PlayerInfo[playerid][pInterior] > 255 || PlayerInfo[playerid][pVirtualWorld] < 0)
    {
        repairs++;
        Account_AppendRepair(report, size, "mundo invalido");
        if (apply)
        {
            if (PlayerInfo[playerid][pInterior] < 0 || PlayerInfo[playerid][pInterior] > 255) PlayerInfo[playerid][pInterior] = 0;
            if (PlayerInfo[playerid][pVirtualWorld] < 0) PlayerInfo[playerid][pVirtualWorld] = 0;
        }
    }
    if (PlayerInfo[playerid][pJob] < JOB_NONE || PlayerInfo[playerid][pJob] > JOB_MAX_ID)
    {
        repairs++;
        Account_AppendRepair(report, size, "profissao invalida");
        if (apply) PlayerInfo[playerid][pJob] = JOB_NONE;
    }
    if (PlayerInfo[playerid][pHouse] != HOUSE_NONE && !Property_IsValid(PlayerInfo[playerid][pHouse]))
    {
        repairs++;
        Account_AppendRepair(report, size, "casa invalida");
        if (apply) PlayerInfo[playerid][pHouse] = HOUSE_NONE;
    }
    if (PlayerInfo[playerid][pRentedHouse] != HOUSE_NONE && !Property_IsValid(PlayerInfo[playerid][pRentedHouse]))
    {
        repairs++;
        Account_AppendRepair(report, size, "aluguel invalido");
        if (apply) PlayerInfo[playerid][pRentedHouse] = HOUSE_NONE;
    }
    if (PlayerInfo[playerid][pBankLoan] < 0 || PlayerInfo[playerid][pBankLoan] > ACCOUNT_REPAIR_MAX_LOAN)
    {
        repairs++;
        Account_AppendRepair(report, size, "emprestimo invalido");
        if (apply)
        {
            if (PlayerInfo[playerid][pBankLoan] < 0) PlayerInfo[playerid][pBankLoan] = 0;
            if (PlayerInfo[playerid][pBankLoan] > ACCOUNT_REPAIR_MAX_LOAN) PlayerInfo[playerid][pBankLoan] = ACCOUNT_REPAIR_MAX_LOAN;
        }
    }

    if (PlayerInfo[playerid][pBankLoan] <= 0)
    {
        if (PlayerInfo[playerid][pBankLoanOriginal] != 0 || PlayerInfo[playerid][pBankLoanInstallmentValue] != 0 || PlayerInfo[playerid][pBankLoanInstallments] != 0 || PlayerInfo[playerid][pLoanInstallmentsPaid] != 0 || PlayerInfo[playerid][pBillLoanInstallmentDue] != 0)
        {
            repairs++;
            Account_AppendRepair(report, size, "parcelas sem emprestimo");
            if (apply)
            {
                PlayerInfo[playerid][pBankLoanOriginal] = 0;
                PlayerInfo[playerid][pBankLoanInstallmentValue] = 0;
                PlayerInfo[playerid][pBankLoanInstallments] = 0;
                PlayerInfo[playerid][pBankLoanNextDueDay] = 0;
                PlayerInfo[playerid][pBillLoanInstallmentDue] = 0;
                PlayerInfo[playerid][pLoanInstallmentsPaid] = 0;
                PlayerInfo[playerid][pContractFinancing] = 0;
            }
        }
    }
    else
    {
        if (PlayerInfo[playerid][pBankLoanOriginal] <= 0 || PlayerInfo[playerid][pBankLoanOriginal] < PlayerInfo[playerid][pBankLoan])
        {
            repairs++;
            Account_AppendRepair(report, size, "emprestimo original");
            if (apply) PlayerInfo[playerid][pBankLoanOriginal] = PlayerInfo[playerid][pBankLoan];
        }
        if (PlayerInfo[playerid][pBankLoanInstallments] <= 0 || PlayerInfo[playerid][pBankLoanInstallments] > 60)
        {
            repairs++;
            Account_AppendRepair(report, size, "parcelas invalidas");
            if (apply) PlayerInfo[playerid][pBankLoanInstallments] = 4;
        }
        if (PlayerInfo[playerid][pLoanInstallmentsPaid] < 0 || PlayerInfo[playerid][pLoanInstallmentsPaid] >= PlayerInfo[playerid][pBankLoanInstallments])
        {
            repairs++;
            Account_AppendRepair(report, size, "parcelas pagas invalidas");
            if (apply)
            {
                if (PlayerInfo[playerid][pLoanInstallmentsPaid] < 0) PlayerInfo[playerid][pLoanInstallmentsPaid] = 0;
                if (PlayerInfo[playerid][pLoanInstallmentsPaid] >= PlayerInfo[playerid][pBankLoanInstallments]) PlayerInfo[playerid][pLoanInstallmentsPaid] = PlayerInfo[playerid][pBankLoanInstallments] - 1;
            }
        }
        remainingInstallments = PlayerInfo[playerid][pBankLoanInstallments] - PlayerInfo[playerid][pLoanInstallmentsPaid];
        if (remainingInstallments < 1)
        {
            remainingInstallments = 1;
        }
        if (PlayerInfo[playerid][pBankLoanInstallmentValue] <= 0 || PlayerInfo[playerid][pBankLoanInstallmentValue] > PlayerInfo[playerid][pBankLoan])
        {
            repairs++;
            Account_AppendRepair(report, size, "valor parcela");
            if (apply) PlayerInfo[playerid][pBankLoanInstallmentValue] = (PlayerInfo[playerid][pBankLoan] + remainingInstallments - 1) / remainingInstallments;
        }
        if (PlayerInfo[playerid][pBankLoanNextDueDay] <= 0)
        {
            repairs++;
            Account_AppendRepair(report, size, "vencimento emprestimo");
            if (apply) PlayerInfo[playerid][pBankLoanNextDueDay] = GetBrasiliaDayStamp() + 30;
        }
    }

    if (PlayerInfo[playerid][pBillWaterDue] < 0 || PlayerInfo[playerid][pBillElectricDue] < 0 || PlayerInfo[playerid][pBillInternetDue] < 0 || PlayerInfo[playerid][pBillRentDue] < 0 || PlayerInfo[playerid][pBillVehicleInsuranceDue] < 0 || PlayerInfo[playerid][pBillHealthPlanDue] < 0 || PlayerInfo[playerid][pBillBusinessPayrollDue] < 0)
    {
        repairs++;
        Account_AppendRepair(report, size, "boletos negativos");
        if (apply)
        {
            if (PlayerInfo[playerid][pBillWaterDue] < 0) PlayerInfo[playerid][pBillWaterDue] = 0;
            if (PlayerInfo[playerid][pBillElectricDue] < 0) PlayerInfo[playerid][pBillElectricDue] = 0;
            if (PlayerInfo[playerid][pBillInternetDue] < 0) PlayerInfo[playerid][pBillInternetDue] = 0;
            if (PlayerInfo[playerid][pBillRentDue] < 0) PlayerInfo[playerid][pBillRentDue] = 0;
            if (PlayerInfo[playerid][pBillVehicleInsuranceDue] < 0) PlayerInfo[playerid][pBillVehicleInsuranceDue] = 0;
            if (PlayerInfo[playerid][pBillHealthPlanDue] < 0) PlayerInfo[playerid][pBillHealthPlanDue] = 0;
            if (PlayerInfo[playerid][pBillBusinessPayrollDue] < 0) PlayerInfo[playerid][pBillBusinessPayrollDue] = 0;
        }
    }
    if (Life_BillTotal(playerid) > ACCOUNT_REPAIR_MAX_BILL)
    {
        repairs++;
        Account_AppendRepair(report, size, "boletos absurdos");
        if (apply)
        {
            PlayerInfo[playerid][pBillWaterDue] = 0;
            PlayerInfo[playerid][pBillElectricDue] = 0;
            PlayerInfo[playerid][pBillInternetDue] = 0;
            PlayerInfo[playerid][pBillRentDue] = 0;
            PlayerInfo[playerid][pBillVehicleInsuranceDue] = 0;
            PlayerInfo[playerid][pBillHealthPlanDue] = 0;
            PlayerInfo[playerid][pBillBusinessPayrollDue] = 0;
        }
    }

    if (PlayerInfo[playerid][pContractRent] && PlayerInfo[playerid][pRentedHouse] == HOUSE_NONE)
    {
        repairs++;
        Account_AppendRepair(report, size, "contrato aluguel");
        if (apply) PlayerInfo[playerid][pContractRent] = 0;
    }
    if (PlayerInfo[playerid][pContractWork] && PlayerInfo[playerid][pJob] == JOB_NONE)
    {
        repairs++;
        Account_AppendRepair(report, size, "contrato trabalho");
        if (apply) PlayerInfo[playerid][pContractWork] = 0;
    }
    if (PlayerInfo[playerid][pContractInsurance] && (PlayerInfo[playerid][pVehicleModel] < 400 || PlayerInfo[playerid][pVehicleModel] > 611))
    {
        repairs++;
        Account_AppendRepair(report, size, "contrato seguro");
        if (apply)
        {
            PlayerInfo[playerid][pContractInsurance] = 0;
            PlayerInfo[playerid][pVehicleInsurance] = 0;
        }
    }

    if (PlayerInfo[playerid][pBusinessType] < LIFE_BUSINESS_NONE || PlayerInfo[playerid][pBusinessType] > LIFE_BUSINESS_MAX_TYPE)
    {
        repairs++;
        Account_AppendRepair(report, size, "empresa tipo");
        if (apply) PlayerInfo[playerid][pBusinessType] = LIFE_BUSINESS_NONE;
    }
    if (PlayerInfo[playerid][pBusinessType] == LIFE_BUSINESS_NONE)
    {
        if (PlayerInfo[playerid][pBusinessEmployees] != 0 || PlayerInfo[playerid][pBusinessBalance] != 0 || PlayerInfo[playerid][pBusinessStock] != 0 || PlayerInfo[playerid][pBusinessContracts] != 0 || PlayerInfo[playerid][pBusinessDebt] != 0 || PlayerInfo[playerid][pBusinessBankrupt] != 0 || PlayerInfo[playerid][pBusinessEditorLoc] != 0)
        {
            repairs++;
            Account_AppendRepair(report, size, "empresa fantasma");
            if (apply)
            {
                PlayerInfo[playerid][pBusinessEmployees] = 0;
                PlayerInfo[playerid][pBusinessBalance] = 0;
                PlayerInfo[playerid][pBusinessStock] = 0;
                PlayerInfo[playerid][pBusinessContracts] = 0;
                PlayerInfo[playerid][pBusinessDebt] = 0;
                PlayerInfo[playerid][pBusinessBankrupt] = 0;
                PlayerInfo[playerid][pBusinessOrders] = 0;
                PlayerInfo[playerid][pBusinessEditorLoc] = 0;
            }
        }
    }
    else
    {
        if (PlayerInfo[playerid][pBusinessDebt] < 0 || PlayerInfo[playerid][pBusinessDebt] > ACCOUNT_REPAIR_MAX_BUSDEBT)
        {
            repairs++;
            Account_AppendRepair(report, size, "divida empresa");
            if (apply)
            {
                if (PlayerInfo[playerid][pBusinessDebt] < 0) PlayerInfo[playerid][pBusinessDebt] = 0;
                if (PlayerInfo[playerid][pBusinessDebt] > ACCOUNT_REPAIR_MAX_BUSDEBT) PlayerInfo[playerid][pBusinessDebt] = ACCOUNT_REPAIR_MAX_BUSDEBT;
            }
        }
        if (PlayerInfo[playerid][pBusinessBankrupt] && PlayerInfo[playerid][pBusinessDebt] <= 0)
        {
            repairs++;
            Account_AppendRepair(report, size, "falencia sem divida");
            if (apply) PlayerInfo[playerid][pBusinessDebt] = 15000;
        }
    }

    if (PlayerInfo[playerid][pHomeSolar] && PlayerInfo[playerid][pHouse] == HOUSE_NONE)
    {
        repairs++;
        Account_AppendRepair(report, size, "solar sem imovel");
        if (apply)
        {
            PlayerInfo[playerid][pHomeSolar] = 0;
        }
    }

    if (PlayerInfo[playerid][pVehicleModel] != 0 && (PlayerInfo[playerid][pVehicleModel] < 400 || PlayerInfo[playerid][pVehicleModel] > 611))
    {
        repairs++;
        Account_AppendRepair(report, size, "veiculo sem dados");
        if (apply)
        {
            PlayerInfo[playerid][pVehicleModel] = 0;
            PlayerInfo[playerid][pVehicleFuel] = FUEL_MAX_VALUE;
            PlayerInfo[playerid][pVehicleHealth] = 1000.0;
            PlayerInfo[playerid][pVehicleParked] = 0;
            PlayerInfo[playerid][pVehicleInsurance] = 0;
            PlayerInfo[playerid][pVehicleGarage] = 0;
            PlayerInfo[playerid][pVehicleImpounded] = 0;
            PlayerInfo[playerid][pVehicleTaxDue] = 0;
        }
    }

    repairs += Dlr_RepairAccountVehicles(playerid, apply, report, size);
    repairs += Inventory_RepairData(playerid, apply, report, size);
    return repairs;
}

stock SetDefaultPlayerInfo(playerid)
{
    new name[MAX_PLAYER_NAME + 1];

    PlayerInfo[playerid][pAccountFormatVersion] = 0;
    PlayerInfo[playerid][pPasswordHash][0] = 0;
    PlayerInfo[playerid][pCharacterName][0] = 0;

    if (IsValidConnectedPlayer(playerid))
    {
        GetPlayerNameEx(playerid, name, sizeof(name));
        format(PlayerInfo[playerid][pCharacterName], CHARACTER_NAME_SIZE, "%s", name);
    }
    else
    {
        format(PlayerInfo[playerid][pCharacterName], CHARACTER_NAME_SIZE, "Personagem");
    }

    PlayerInfo[playerid][pMoney] = gCfgStartingMoney;
    PlayerInfo[playerid][pSkin] = DEFAULT_SKIN;
    PlayerInfo[playerid][pAdminLevel] = 0;
    PlayerInfo[playerid][pVipLevel] = 0;
    PlayerInfo[playerid][pVipExpire] = 0;
    PlayerInfo[playerid][pVipLastKitDay] = 0;
    PlayerInfo[playerid][pVipTotalDays] = 0;
    PlayerInfo[playerid][pKills] = 0;
    PlayerInfo[playerid][pDeaths] = 0;
    PlayerInfo[playerid][pLastSpawn] = LOCATION_SPAWN;
    PlayerInfo[playerid][pSpawnCount] = 0;
    PlayerInfo[playerid][pPosX] = gServerLocations[LOCATION_SPAWN][locX];
    PlayerInfo[playerid][pPosY] = gServerLocations[LOCATION_SPAWN][locY];
    PlayerInfo[playerid][pPosZ] = gServerLocations[LOCATION_SPAWN][locZ];
    PlayerInfo[playerid][pPosA] = gServerLocations[LOCATION_SPAWN][locA];
    PlayerInfo[playerid][pInterior] = gServerLocations[LOCATION_SPAWN][locInterior];
    PlayerInfo[playerid][pVirtualWorld] = gServerLocations[LOCATION_SPAWN][locVirtualWorld];
    PlayerInfo[playerid][pOnlineTime] = 0;
    PlayerInfo[playerid][pExperience] = 0;
    PlayerInfo[playerid][pLevel] = 1;
    PlayerInfo[playerid][pExperienceTick] = 0;
    PlayerInfo[playerid][pDocuments] = 0;
    PlayerInfo[playerid][pDocumentsExpire] = 0;
    PlayerInfo[playerid][pJob] = JOB_NONE;
    PlayerInfo[playerid][pLicenseCNH] = 0;
    PlayerInfo[playerid][pLicenseHeavy] = 0;
    PlayerInfo[playerid][pLicenseMedical] = 0;
    PlayerInfo[playerid][pLicenseOAB] = 0;
    PlayerInfo[playerid][pLicensePublic] = 0;
    PlayerInfo[playerid][pLicensePolice] = 0;
    PlayerInfo[playerid][pLicenseCNHExpire] = 0;
    PlayerInfo[playerid][pLicenseHeavyExpire] = 0;
    PlayerInfo[playerid][pLicenseMedicalExpire] = 0;
    PlayerInfo[playerid][pLicenseOABExpire] = 0;
    PlayerInfo[playerid][pLicensePublicExpire] = 0;
    PlayerInfo[playerid][pLicensePoliceExpire] = 0;
    PlayerInfo[playerid][pVehicleModel] = 0;
    PlayerInfo[playerid][pVehicleColor1] = 1;
    PlayerInfo[playerid][pVehicleColor2] = 1;
    format(PlayerInfo[playerid][pVehiclePlate], 16, "LS-%04d", random(10000));
    PlayerInfo[playerid][pVehicleFuel] = FUEL_MAX_VALUE;
    PlayerInfo[playerid][pVehicleHealth] = 1000.0;
    PlayerInfo[playerid][pVehiclePosX] = 0.0;
    PlayerInfo[playerid][pVehiclePosY] = 0.0;
    PlayerInfo[playerid][pVehiclePosZ] = 0.0;
    PlayerInfo[playerid][pVehiclePosA] = 0.0;
    PlayerInfo[playerid][pVehicleInterior] = 0;
    PlayerInfo[playerid][pVehicleVirtualWorld] = 0;
    PlayerInfo[playerid][pVehicleParked] = 0;
    PlayerInfo[playerid][pVehicleInsurance] = 0;
    PlayerInfo[playerid][pVehicleGarage] = 0;
    PlayerInfo[playerid][pVehicleImpounded] = 0;
    PlayerInfo[playerid][pVehicleTaxDue] = 0;
    PlayerInfo[playerid][pTollTag] = 0;
    PlayerInfo[playerid][pBankMoney] = 0;
    PlayerInfo[playerid][pBankAccount] = 0;
    PlayerInfo[playerid][pBankCard] = 0;
    PlayerInfo[playerid][pBankLoan] = 0;
    PlayerInfo[playerid][pBankLoanOriginal] = 0;
    PlayerInfo[playerid][pBankLoanInstallmentValue] = 0;
    PlayerInfo[playerid][pBankLoanInstallments] = 0;
    PlayerInfo[playerid][pBankLoanNextDueDay] = 0;
    PlayerInfo[playerid][pBankScore] = gCfgBankScoreBase;
    PlayerInfo[playerid][pBankGoodHistory] = 0;
    PlayerInfo[playerid][pBankBadHistory] = 0;
    PlayerInfo[playerid][pIncomeRegistered] = 0;
    PlayerInfo[playerid][pSalaryLastDay] = 0;
    PlayerInfo[playerid][pSalary] = 0;
    PlayerInfo[playerid][pSalaryWorkDay] = 0;
    PlayerInfo[playerid][pSalaryWorkTasks] = 0;
    PlayerInfo[playerid][pSalaryProductivityPaid] = 0;
    PlayerInfo[playerid][pFines] = 0;
    PlayerInfo[playerid][pTrafficPoints] = 0;
    PlayerInfo[playerid][pWanted] = 0;
    PlayerInfo[playerid][pJailTime] = 0;
    PlayerInfo[playerid][pJailCrimeId] = 0;
    PlayerInfo[playerid][pAdminJail] = 0;
    PlayerInfo[playerid][pMuteTime] = 0;
    PlayerInfo[playerid][pCriminalRecords] = 0;
    PlayerInfo[playerid][pInjury] = 0;
    PlayerInfo[playerid][pHealthPlan] = 0;
    PlayerInfo[playerid][pHealthPlanExpire] = 0;
    PlayerInfo[playerid][pMedicalSeverity] = 0;
    PlayerInfo[playerid][pMedicalTreatmentDue] = 0;
    PlayerInfo[playerid][pJusticeCases] = 0;
    PlayerInfo[playerid][pJusticeHearingDay] = 0;
    PlayerInfo[playerid][pJusticeSentence] = 0;
    PlayerInfo[playerid][pJusticeFineDue] = 0;
    PlayerInfo[playerid][pBusinessType] = 0;
    PlayerInfo[playerid][pBusinessEmployees] = 0;
    PlayerInfo[playerid][pBusinessBalance] = 0;
    PlayerInfo[playerid][pBusinessTaxDue] = 0;
    PlayerInfo[playerid][pBusinessPermitExpire] = 0;
    PlayerInfo[playerid][pBusinessEditorLoc] = 0;
    PlayerInfo[playerid][pPropertyTaxDue] = 0;
    PlayerInfo[playerid][pGovernmentTaxDue] = 0;
    PlayerInfo[playerid][pTaxLastDay] = 0;
    PlayerInfo[playerid][pBillWaterDue] = 0;
    PlayerInfo[playerid][pBillElectricDue] = 0;
    PlayerInfo[playerid][pBillInternetDue] = 0;
    PlayerInfo[playerid][pBillRentDue] = 0;
    PlayerInfo[playerid][pBillVehicleInsuranceDue] = 0;
    PlayerInfo[playerid][pBillHealthPlanDue] = 0;
    PlayerInfo[playerid][pBillLoanInstallmentDue] = 0;
    PlayerInfo[playerid][pBillBusinessPayrollDue] = 0;
    PlayerInfo[playerid][pBillDueDay] = 0;
    PlayerInfo[playerid][pBillLastGenerateDay] = 0;
    PlayerInfo[playerid][pBillLateChargeDay] = 0;
    PlayerInfo[playerid][pDirtyName] = 0;
    PlayerInfo[playerid][pCivilCPF] = 0;
    PlayerInfo[playerid][pCivilRG] = 0;
    PlayerInfo[playerid][pCivilCertificate] = 0;
    PlayerInfo[playerid][pCivilSignature] = 0;
    PlayerInfo[playerid][pCivilMarried] = 0;
    PlayerInfo[playerid][pCivilDivorces] = 0;
    PlayerInfo[playerid][pContractRent] = 0;
    PlayerInfo[playerid][pContractFinancing] = 0;
    PlayerInfo[playerid][pContractWork] = 0;
    PlayerInfo[playerid][pContractInsurance] = 0;
    PlayerInfo[playerid][pHomeSolar] = 0;
    PlayerInfo[playerid][pHouse] = HOUSE_NONE;
    PlayerInfo[playerid][pRentedHouse] = HOUSE_NONE;
    PlayerInfo[playerid][pHunger] = NEEDS_MAX_VALUE;
    PlayerInfo[playerid][pThirst] = NEEDS_MAX_VALUE;
    PlayerInfo[playerid][pFatigue] = 0;
    PlayerInfo[playerid][pSleep] = 0;
    PlayerInfo[playerid][pPantryFood] = 0;
    PlayerInfo[playerid][pPantryDrink] = 0;
    PlayerInfo[playerid][pNeedsTick] = 0;
    PlayerInfo[playerid][pNeedsWarningTick] = 0;
    PlayerInfo[playerid][pLogged] = 0;
    PlayerInfo[playerid][pSessionTick] = 0;
    PlayerInfo[playerid][pMissionDay] = 0;
    PlayerInfo[playerid][pMissionWork] = 0;
    PlayerInfo[playerid][pMissionMarket] = 0;
    PlayerInfo[playerid][pMissionBank] = 0;
    PlayerInfo[playerid][pMissionBill] = 0;
    PlayerInfo[playerid][pMissionDocs] = 0;
    PlayerInfo[playerid][pMissionRewarded] = 0;
    PlayerInfo[playerid][pAchievements] = 0;
    PlayerInfo[playerid][pTutorialStep] = 0;
    PlayerInfo[playerid][pIntroTutorialDone] = 0;
    PlayerInfo[playerid][pBusinessOrderDay] = 0;
    PlayerInfo[playerid][pBusinessOrders] = 0;
    PlayerInfo[playerid][pJusticeStatus] = 0;
    PlayerInfo[playerid][pJusticeDeadlineDay] = 0;
    PlayerInfo[playerid][pJusticeAppeals] = 0;
    PlayerInfo[playerid][pLoanInstallmentsPaid] = 0;
    PlayerInfo[playerid][pDailyRewardDay] = 0;
    PlayerInfo[playerid][pWeeklyRewardWeek] = 0;
    PlayerInfo[playerid][pLoginStreak] = 0;
    PlayerInfo[playerid][pLastLoginDay] = 0;
    PlayerInfo[playerid][pCityPassWeek] = 0;
    PlayerInfo[playerid][pCityPassJob] = 0;
    PlayerInfo[playerid][pCityPassEconomy] = 0;
    PlayerInfo[playerid][pCityPassPublic] = 0;
    PlayerInfo[playerid][pCityPassRewarded] = 0;
    PlayerInfo[playerid][pWeeklyWorkScore] = 0;
    PlayerInfo[playerid][pWeeklyBusinessScore] = 0;
    PlayerInfo[playerid][pWeeklyPoliceScore] = 0;
    PlayerInfo[playerid][pWeeklyCitizenScore] = 0;
    PlayerInfo[playerid][pBusinessStock] = 0;
    PlayerInfo[playerid][pBusinessContracts] = 0;
    PlayerInfo[playerid][pBusinessDebt] = 0;
    PlayerInfo[playerid][pBusinessRecoveryDay] = 0;
    PlayerInfo[playerid][pBusinessBankrupt] = 0;
    PlayerInfo[playerid][pVehicleInspectionDay] = 0;
    PlayerInfo[playerid][pMedicalShifts] = 0;
    PlayerInfo[playerid][pPoliceWarrants] = 0;
    PlayerInfo[playerid][pPoliceEvidence] = 0;
    PlayerInfo[playerid][pJusticeActiveWarrants] = 0;
    PlayerInfo[playerid][pJusticeActiveEvidence] = 0;
    PlayerInfo[playerid][pAnkleMonitor] = 0;
    PlayerInfo[playerid][pContractLimitDay] = 0;
    PlayerInfo[playerid][pContractsToday] = 0;
    PlayerInfo[playerid][pLogisticsCompleted] = 0;
    PlayerInfo[playerid][pLogisticsCanceled] = 0;
    PlayerInfo[playerid][pLogisticsLate] = 0;
    PlayerInfo[playerid][pLogisticsReputation] = 50;
    PlayerInfo[playerid][pLogisticsEarnings] = 0;
    PlayerInfo[playerid][pLogisticsGenerated] = 0;
    PlayerInfo[playerid][pAutoBusinessId] = 0;
    PlayerInfo[playerid][pAutoBusinessProfit] = 0;
    PlayerInfo[playerid][pAutoBusinessRevenue] = 0;
    PlayerInfo[playerid][pOnboardingRewarded] = 0;
    PlayerInfo[playerid][pWarZoneDay] = 0;
    PlayerInfo[playerid][pWarZoneKillsToday] = 0;
    PlayerInfo[playerid][pCrimeFaction] = 0;
    PlayerInfo[playerid][pCrimeRank] = 0;
    PlayerInfo[playerid][pCrimeRespect] = 0;
    PlayerInfo[playerid][pCrimeMissionCooldown] = 0;
    PlayerInfo[playerid][pCrimeHourlyStamp] = 0;
    PlayerInfo[playerid][pCrimeHourlyGain] = 0;
    PlayerInfo[playerid][pPoliticalOffice] = -1;
    PlayerInfo[playerid][pPoliticalTermStartDay] = 0;
    PlayerInfo[playerid][pPoliticalTermEndDay] = 0;
    ResetPlayerInventory(playerid);
    ResetPlayerJobProgress(playerid);
    return 1;
}

stock ResetPlayerData(playerid)
{
    gPlayerConnected[playerid] = 0;
    gPlayerAuthDialog[playerid] = 0;
    gPlayerLoginTries[playerid] = 0;
    Account_ClearPasswordChange(playerid);
    gAccountCanonicalName[playerid][0] = 0;
    gPendingAccountName[playerid][0] = 0;
    gPendingAccountNameHash[playerid][0] = 0;
    gPendingAccountNameTick[playerid] = 0;
    gAccountSaveDirty[playerid] = 0;
    gAccountSaveTick[playerid] = 0;
    ResetPlayerWorldData(playerid);
    SetDefaultPlayerInfo(playerid);
    return 1;
}

stock Account_FormatPathForName(name[], path[], size = sizeof(path))
{
    format(path, size, "contas/%s.ini", name);
    return 1;
}

stock Account_ResolveAlias(name[], output[], size = sizeof(output))
{
    new File:file;
    new line[96];
    new source[MAX_PLAYER_NAME + 1];
    new target[MAX_PLAYER_NAME + 1];
    new pos;
    new depth;
    new found;

    format(output, size, "%s", name);

    while (depth < 4)
    {
        if (!fexist(ACCOUNT_ALIAS_FILE))
        {
            return 1;
        }

        file = fopen(ACCOUNT_ALIAS_FILE, io_read);
        if (!file)
        {
            return 1;
        }

        found = 0;
        while (ReadFileLine(file, line, sizeof(line)))
        {
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
            strmid(source, line, 0, pos, sizeof(source));
            strmid(target, line, pos + 1, strlen(line), sizeof(target));
            Cfg_Trim(source);
            Cfg_Trim(target);
            if (strcmp(output, source, true) == 0)
            {
                format(output, size, "%s", target);
                found = 1;
                break;
            }
        }
        fclose(file);

        if (!found)
        {
            return 1;
        }
        depth++;
    }
    return 1;
}

stock Account_NameIsReserved(name[])
{
    new File:file;
    new line[96];
    new source[MAX_PLAYER_NAME + 1];
    new target[MAX_PLAYER_NAME + 1];
    new path[ACCOUNT_PATH_SIZE];
    new pos;

    Account_FormatPathForName(name, path, sizeof(path));
    if (fexist(path))
    {
        return 1;
    }

    if (!fexist(ACCOUNT_ALIAS_FILE))
    {
        return 0;
    }
    file = fopen(ACCOUNT_ALIAS_FILE, io_read);
    if (!file)
    {
        return 0;
    }
    while (ReadFileLine(file, line, sizeof(line)))
    {
        Cfg_Trim(line);
        pos = strfind(line, "=", false);
        if (pos <= 0)
        {
            continue;
        }
        strmid(source, line, 0, pos, sizeof(source));
        strmid(target, line, pos + 1, strlen(line), sizeof(target));
        Cfg_Trim(source);
        Cfg_Trim(target);
        if (strcmp(name, source, true) == 0 || strcmp(name, target, true) == 0)
        {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

stock Account_AddAlias(oldName[], newName[])
{
    new File:file = fopen(ACCOUNT_ALIAS_FILE, io_append);
    new line[96];

    if (!file)
    {
        return 0;
    }
    format(line, sizeof(line), "%s=%s\r\n", oldName, newName);
    fwrite(file, line);
    fclose(file);
    return 1;
}

stock Account_GetCanonicalName(playerid, output[], size = sizeof(output))
{
    new name[MAX_PLAYER_NAME + 1];

    if (gAccountCanonicalName[playerid][0])
    {
        format(output, size, "%s", gAccountCanonicalName[playerid]);
        return 1;
    }

    GetPlayerNameEx(playerid, name, sizeof(name));
    Account_ResolveAlias(name, output, size);
    format(gAccountCanonicalName[playerid], sizeof(gAccountCanonicalName[]), "%s", output);
    return 1;
}

stock GetPlayerAccountPath(playerid, path[], size = sizeof(path))
{
    new name[MAX_PLAYER_NAME + 1];

    Account_GetCanonicalName(playerid, name, sizeof(name));
    Account_FormatPathForName(name, path, size);
    return 1;
}

stock HashPlayerPassword(playerid, password[], hash[], size = sizeof(hash))
{
    new name[MAX_PLAYER_NAME + 1];

    Account_GetCanonicalName(playerid, name, sizeof(name));
    SHA256_PassHash(password, name, hash, size);
    return 1;
}

stock HashPasswordWithName(name[], password[], hash[], size = sizeof(hash))
{
    SHA256_PassHash(password, name, hash, size);
    return 1;
}

stock ApplyAccountField(playerid, key[], value[])
{
    if (strcmp(key, "format_version", false) == 0)
    {
        PlayerInfo[playerid][pAccountFormatVersion] = strval(value);
    }
    else if (strcmp(key, "password_hash", false) == 0)
    {
        format(PlayerInfo[playerid][pPasswordHash], PASSWORD_HASH_SIZE, "%s", value);
    }
    else if (strcmp(key, "admin", false) == 0)
    {
        PlayerInfo[playerid][pAdminLevel] = strval(value);
    }
    else if (strcmp(key, "vip_level", false) == 0)
    {
        PlayerInfo[playerid][pVipLevel] = strval(value);
        if (PlayerInfo[playerid][pVipLevel] < 0) PlayerInfo[playerid][pVipLevel] = 0;
        if (PlayerInfo[playerid][pVipLevel] > VIP_MAX_LEVEL) PlayerInfo[playerid][pVipLevel] = VIP_MAX_LEVEL;
    }
    else if (strcmp(key, "vip_expire", false) == 0)
    {
        PlayerInfo[playerid][pVipExpire] = strval(value);
    }
    else if (strcmp(key, "vip_last_kit_day", false) == 0)
    {
        PlayerInfo[playerid][pVipLastKitDay] = strval(value);
    }
    else if (strcmp(key, "vip_total_days", false) == 0)
    {
        PlayerInfo[playerid][pVipTotalDays] = strval(value);
    }
    else if (strcmp(key, "character_name", false) == 0)
    {
        format(PlayerInfo[playerid][pCharacterName], CHARACTER_NAME_SIZE, "%s", value);
    }
    else if (strcmp(key, "money", false) == 0)
    {
        PlayerInfo[playerid][pMoney] = strval(value);
    }
    else if (strcmp(key, "skin", false) == 0)
    {
        PlayerInfo[playerid][pSkin] = strval(value);
    }
    else if (strcmp(key, "kills", false) == 0)
    {
        PlayerInfo[playerid][pKills] = strval(value);
    }
    else if (strcmp(key, "deaths", false) == 0)
    {
        PlayerInfo[playerid][pDeaths] = strval(value);
    }
    else if (strcmp(key, "last_spawn", false) == 0)
    {
        PlayerInfo[playerid][pLastSpawn] = strval(value);
    }
    else if (strcmp(key, "spawn_count", false) == 0)
    {
        PlayerInfo[playerid][pSpawnCount] = strval(value);
    }
    else if (strcmp(key, "pos_x", false) == 0)
    {
        PlayerInfo[playerid][pPosX] = floatstr(value);
    }
    else if (strcmp(key, "pos_y", false) == 0)
    {
        PlayerInfo[playerid][pPosY] = floatstr(value);
    }
    else if (strcmp(key, "pos_z", false) == 0)
    {
        PlayerInfo[playerid][pPosZ] = floatstr(value);
    }
    else if (strcmp(key, "pos_a", false) == 0)
    {
        PlayerInfo[playerid][pPosA] = floatstr(value);
    }
    else if (strcmp(key, "interior", false) == 0)
    {
        PlayerInfo[playerid][pInterior] = strval(value);
    }
    else if (strcmp(key, "virtual_world", false) == 0)
    {
        PlayerInfo[playerid][pVirtualWorld] = strval(value);
    }
    else if (strcmp(key, "online_time", false) == 0)
    {
        PlayerInfo[playerid][pOnlineTime] = strval(value);
    }
    else if (strcmp(key, "experience", false) == 0)
    {
        PlayerInfo[playerid][pExperience] = strval(value);
    }
    else if (strcmp(key, "level", false) == 0)
    {
        PlayerInfo[playerid][pLevel] = strval(value);
        if (PlayerInfo[playerid][pLevel] < 1)
        {
            PlayerInfo[playerid][pLevel] = 1;
        }
    }
    else if (strcmp(key, "documents", false) == 0)
    {
        PlayerInfo[playerid][pDocuments] = strval(value);
    }
    else if (strcmp(key, "documents_expire", false) == 0)
    {
        PlayerInfo[playerid][pDocumentsExpire] = strval(value);
    }
    else if (strcmp(key, "job", false) == 0)
    {
        PlayerInfo[playerid][pJob] = strval(value);
    }
    else if (strcmp(key, "job_xp", false) == 0)
    {
        Job_SetPlayerXP(playerid, PlayerInfo[playerid][pJob], strval(value));
    }
    else if (strcmp(key, "job_level", false) == 0)
    {
        Job_SetPlayerLevel(playerid, PlayerInfo[playerid][pJob], strval(value));
    }
    else if (strcmp(key, "license_cnh", false) == 0)
    {
        PlayerInfo[playerid][pLicenseCNH] = strval(value);
    }
    else if (strcmp(key, "license_heavy", false) == 0)
    {
        PlayerInfo[playerid][pLicenseHeavy] = strval(value);
    }
    else if (strcmp(key, "license_medical", false) == 0)
    {
        PlayerInfo[playerid][pLicenseMedical] = strval(value);
    }
    else if (strcmp(key, "license_oab", false) == 0)
    {
        PlayerInfo[playerid][pLicenseOAB] = strval(value);
    }
    else if (strcmp(key, "license_public", false) == 0)
    {
        PlayerInfo[playerid][pLicensePublic] = strval(value);
    }
    else if (strcmp(key, "license_police", false) == 0)
    {
        PlayerInfo[playerid][pLicensePolice] = strval(value);
    }
    else if (strcmp(key, "license_cnh_expire", false) == 0)
    {
        PlayerInfo[playerid][pLicenseCNHExpire] = strval(value);
    }
    else if (strcmp(key, "license_heavy_expire", false) == 0)
    {
        PlayerInfo[playerid][pLicenseHeavyExpire] = strval(value);
    }
    else if (strcmp(key, "license_medical_expire", false) == 0)
    {
        PlayerInfo[playerid][pLicenseMedicalExpire] = strval(value);
    }
    else if (strcmp(key, "license_oab_expire", false) == 0)
    {
        PlayerInfo[playerid][pLicenseOABExpire] = strval(value);
    }
    else if (strcmp(key, "license_public_expire", false) == 0)
    {
        PlayerInfo[playerid][pLicensePublicExpire] = strval(value);
    }
    else if (strcmp(key, "license_police_expire", false) == 0)
    {
        PlayerInfo[playerid][pLicensePoliceExpire] = strval(value);
    }
    else if (strcmp(key, "vehicle_model", false) == 0)
    {
        PlayerInfo[playerid][pVehicleModel] = strval(value);
    }
    else if (strcmp(key, "vehicle_color1", false) == 0)
    {
        PlayerInfo[playerid][pVehicleColor1] = strval(value);
    }
    else if (strcmp(key, "vehicle_color2", false) == 0)
    {
        PlayerInfo[playerid][pVehicleColor2] = strval(value);
    }
    else if (strcmp(key, "vehicle_plate", false) == 0)
    {
        format(PlayerInfo[playerid][pVehiclePlate], 16, "%s", value);
    }
    else if (strcmp(key, "vehicle_fuel", false) == 0)
    {
        PlayerInfo[playerid][pVehicleFuel] = strval(value);
        if (PlayerInfo[playerid][pVehicleFuel] < 0) PlayerInfo[playerid][pVehicleFuel] = 0;
        if (PlayerInfo[playerid][pVehicleFuel] > FUEL_MAX_VALUE) PlayerInfo[playerid][pVehicleFuel] = FUEL_MAX_VALUE;
    }
    else if (strcmp(key, "vehicle_health", false) == 0)
    {
        PlayerInfo[playerid][pVehicleHealth] = floatstr(value);
    }
    else if (strcmp(key, "vehicle_pos_x", false) == 0)
    {
        PlayerInfo[playerid][pVehiclePosX] = floatstr(value);
    }
    else if (strcmp(key, "vehicle_pos_y", false) == 0)
    {
        PlayerInfo[playerid][pVehiclePosY] = floatstr(value);
    }
    else if (strcmp(key, "vehicle_pos_z", false) == 0)
    {
        PlayerInfo[playerid][pVehiclePosZ] = floatstr(value);
    }
    else if (strcmp(key, "vehicle_pos_a", false) == 0)
    {
        PlayerInfo[playerid][pVehiclePosA] = floatstr(value);
    }
    else if (strcmp(key, "vehicle_interior", false) == 0)
    {
        PlayerInfo[playerid][pVehicleInterior] = strval(value);
    }
    else if (strcmp(key, "vehicle_virtual_world", false) == 0)
    {
        PlayerInfo[playerid][pVehicleVirtualWorld] = strval(value);
    }
    else if (strcmp(key, "vehicle_parked", false) == 0)
    {
        PlayerInfo[playerid][pVehicleParked] = strval(value);
    }
    else if (strcmp(key, "vehicle_insurance", false) == 0)
    {
        PlayerInfo[playerid][pVehicleInsurance] = strval(value);
    }
    else if (strcmp(key, "vehicle_garage", false) == 0)
    {
        PlayerInfo[playerid][pVehicleGarage] = strval(value);
    }
    else if (strcmp(key, "vehicle_impounded", false) == 0)
    {
        PlayerInfo[playerid][pVehicleImpounded] = strval(value);
    }
    else if (strcmp(key, "vehicle_tax_due", false) == 0)
    {
        PlayerInfo[playerid][pVehicleTaxDue] = strval(value);
    }
    else if (strcmp(key, "toll_tag", false) == 0)
    {
        PlayerInfo[playerid][pTollTag] = strval(value);
    }
    else if (strcmp(key, "bank", false) == 0)
    {
        PlayerInfo[playerid][pBankMoney] = strval(value);
    }
    else if (strcmp(key, "bank_account", false) == 0)
    {
        PlayerInfo[playerid][pBankAccount] = strval(value);
    }
    else if (strcmp(key, "bank_card", false) == 0)
    {
        PlayerInfo[playerid][pBankCard] = strval(value);
    }
    else if (strcmp(key, "bank_loan", false) == 0)
    {
        PlayerInfo[playerid][pBankLoan] = strval(value);
        if (PlayerInfo[playerid][pBankLoan] < 0)
        {
            PlayerInfo[playerid][pBankLoan] = 0;
        }
    }
    else if (strcmp(key, "bank_loan_original", false) == 0)
    {
        PlayerInfo[playerid][pBankLoanOriginal] = strval(value);
    }
    else if (strcmp(key, "bank_loan_installment_value", false) == 0)
    {
        PlayerInfo[playerid][pBankLoanInstallmentValue] = strval(value);
    }
    else if (strcmp(key, "bank_loan_installments", false) == 0)
    {
        PlayerInfo[playerid][pBankLoanInstallments] = strval(value);
    }
    else if (strcmp(key, "bank_loan_next_due_day", false) == 0)
    {
        PlayerInfo[playerid][pBankLoanNextDueDay] = strval(value);
    }
    else if (strcmp(key, "bank_score", false) == 0)
    {
        PlayerInfo[playerid][pBankScore] = strval(value);
    }
    else if (strcmp(key, "bank_good_history", false) == 0)
    {
        PlayerInfo[playerid][pBankGoodHistory] = strval(value);
    }
    else if (strcmp(key, "bank_bad_history", false) == 0)
    {
        PlayerInfo[playerid][pBankBadHistory] = strval(value);
    }
    else if (strcmp(key, "income_registered", false) == 0)
    {
        PlayerInfo[playerid][pIncomeRegistered] = strval(value);
    }
    else if (strcmp(key, "salary_last_day", false) == 0)
    {
        PlayerInfo[playerid][pSalaryLastDay] = strval(value);
    }
    else if (strcmp(key, "salary", false) == 0)
    {
        PlayerInfo[playerid][pSalary] = strval(value);
    }
    else if (strcmp(key, "salary_work_day", false) == 0)
    {
        PlayerInfo[playerid][pSalaryWorkDay] = strval(value);
    }
    else if (strcmp(key, "salary_work_tasks", false) == 0)
    {
        PlayerInfo[playerid][pSalaryWorkTasks] = strval(value);
    }
    else if (strcmp(key, "salary_productivity_paid", false) == 0)
    {
        PlayerInfo[playerid][pSalaryProductivityPaid] = strval(value);
    }
    else if (strcmp(key, "fines", false) == 0)
    {
        PlayerInfo[playerid][pFines] = strval(value);
    }
    else if (strcmp(key, "traffic_points", false) == 0 || strcmp(key, "cnh_points", false) == 0)
    {
        PlayerInfo[playerid][pTrafficPoints] = strval(value);
    }
    else if (strcmp(key, "wanted", false) == 0)
    {
        PlayerInfo[playerid][pWanted] = strval(value);
    }
    else if (strcmp(key, "jail_time", false) == 0)
    {
        PlayerInfo[playerid][pJailTime] = strval(value);
    }
    else if (strcmp(key, "jail_crime_id", false) == 0)
    {
        PlayerInfo[playerid][pJailCrimeId] = strval(value);
    }
    else if (strcmp(key, "admin_jail", false) == 0)
    {
        PlayerInfo[playerid][pAdminJail] = strval(value);
    }
    else if (strcmp(key, "mute_time", false) == 0)
    {
        PlayerInfo[playerid][pMuteTime] = strval(value);
    }
    else if (strcmp(key, "criminal_records", false) == 0)
    {
        PlayerInfo[playerid][pCriminalRecords] = strval(value);
    }
    else if (strcmp(key, "injury", false) == 0)
    {
        PlayerInfo[playerid][pInjury] = strval(value);
    }
    else if (strcmp(key, "health_plan", false) == 0)
    {
        PlayerInfo[playerid][pHealthPlan] = strval(value);
    }
    else if (strcmp(key, "health_plan_expire", false) == 0)
    {
        PlayerInfo[playerid][pHealthPlanExpire] = strval(value);
    }
    else if (strcmp(key, "medical_severity", false) == 0)
    {
        PlayerInfo[playerid][pMedicalSeverity] = strval(value);
    }
    else if (strcmp(key, "medical_treatment_due", false) == 0)
    {
        PlayerInfo[playerid][pMedicalTreatmentDue] = strval(value);
    }
    else if (strcmp(key, "justice_cases", false) == 0)
    {
        PlayerInfo[playerid][pJusticeCases] = strval(value);
    }
    else if (strcmp(key, "justice_hearing_day", false) == 0)
    {
        PlayerInfo[playerid][pJusticeHearingDay] = strval(value);
    }
    else if (strcmp(key, "justice_sentence", false) == 0)
    {
        PlayerInfo[playerid][pJusticeSentence] = strval(value);
    }
    else if (strcmp(key, "justice_fine_due", false) == 0)
    {
        PlayerInfo[playerid][pJusticeFineDue] = strval(value);
    }
    else if (strcmp(key, "business_type", false) == 0)
    {
        PlayerInfo[playerid][pBusinessType] = strval(value);
    }
    else if (strcmp(key, "business_employees", false) == 0)
    {
        PlayerInfo[playerid][pBusinessEmployees] = strval(value);
    }
    else if (strcmp(key, "business_balance", false) == 0)
    {
        PlayerInfo[playerid][pBusinessBalance] = strval(value);
    }
    else if (strcmp(key, "business_tax_due", false) == 0)
    {
        PlayerInfo[playerid][pBusinessTaxDue] = strval(value);
    }
    else if (strcmp(key, "business_permit_expire", false) == 0)
    {
        PlayerInfo[playerid][pBusinessPermitExpire] = strval(value);
    }
    else if (strcmp(key, "business_editor_loc", false) == 0)
    {
        PlayerInfo[playerid][pBusinessEditorLoc] = strval(value);
    }
    else if (strcmp(key, "property_tax_due", false) == 0)
    {
        PlayerInfo[playerid][pPropertyTaxDue] = strval(value);
    }
    else if (strcmp(key, "government_tax_due", false) == 0)
    {
        PlayerInfo[playerid][pGovernmentTaxDue] = strval(value);
    }
    else if (strcmp(key, "tax_last_day", false) == 0)
    {
        PlayerInfo[playerid][pTaxLastDay] = strval(value);
    }
    else if (strcmp(key, "bill_water_due", false) == 0)
    {
        PlayerInfo[playerid][pBillWaterDue] = strval(value);
    }
    else if (strcmp(key, "bill_electric_due", false) == 0)
    {
        PlayerInfo[playerid][pBillElectricDue] = strval(value);
    }
    else if (strcmp(key, "bill_internet_due", false) == 0)
    {
        PlayerInfo[playerid][pBillInternetDue] = strval(value);
    }
    else if (strcmp(key, "bill_rent_due", false) == 0)
    {
        PlayerInfo[playerid][pBillRentDue] = strval(value);
    }
    else if (strcmp(key, "bill_vehicle_insurance_due", false) == 0)
    {
        PlayerInfo[playerid][pBillVehicleInsuranceDue] = strval(value);
    }
    else if (strcmp(key, "bill_health_plan_due", false) == 0)
    {
        PlayerInfo[playerid][pBillHealthPlanDue] = strval(value);
    }
    else if (strcmp(key, "bill_loan_installment_due", false) == 0)
    {
        PlayerInfo[playerid][pBillLoanInstallmentDue] = strval(value);
    }
    else if (strcmp(key, "bill_business_payroll_due", false) == 0)
    {
        PlayerInfo[playerid][pBillBusinessPayrollDue] = strval(value);
    }
    else if (strcmp(key, "bill_due_day", false) == 0)
    {
        PlayerInfo[playerid][pBillDueDay] = strval(value);
    }
    else if (strcmp(key, "bill_last_generate_day", false) == 0)
    {
        PlayerInfo[playerid][pBillLastGenerateDay] = strval(value);
    }
    else if (strcmp(key, "bill_late_charge_day", false) == 0)
    {
        PlayerInfo[playerid][pBillLateChargeDay] = strval(value);
    }
    else if (strcmp(key, "dirty_name", false) == 0)
    {
        PlayerInfo[playerid][pDirtyName] = strval(value);
    }
    else if (strcmp(key, "civil_cpf", false) == 0)
    {
        PlayerInfo[playerid][pCivilCPF] = strval(value);
    }
    else if (strcmp(key, "civil_rg", false) == 0)
    {
        PlayerInfo[playerid][pCivilRG] = strval(value);
    }
    else if (strcmp(key, "civil_certificate", false) == 0)
    {
        PlayerInfo[playerid][pCivilCertificate] = strval(value);
    }
    else if (strcmp(key, "civil_signature", false) == 0)
    {
        PlayerInfo[playerid][pCivilSignature] = strval(value);
    }
    else if (strcmp(key, "civil_married", false) == 0)
    {
        PlayerInfo[playerid][pCivilMarried] = strval(value);
    }
    else if (strcmp(key, "civil_divorces", false) == 0)
    {
        PlayerInfo[playerid][pCivilDivorces] = strval(value);
    }
    else if (strcmp(key, "contract_rent", false) == 0)
    {
        PlayerInfo[playerid][pContractRent] = strval(value);
    }
    else if (strcmp(key, "contract_financing", false) == 0)
    {
        PlayerInfo[playerid][pContractFinancing] = strval(value);
    }
    else if (strcmp(key, "contract_work", false) == 0)
    {
        PlayerInfo[playerid][pContractWork] = strval(value);
    }
    else if (strcmp(key, "contract_insurance", false) == 0)
    {
        PlayerInfo[playerid][pContractInsurance] = strval(value);
    }
    else if (strcmp(key, "home_solar", false) == 0)
    {
        PlayerInfo[playerid][pHomeSolar] = strval(value);
    }
    else if (strcmp(key, "mission_day", false) == 0)
    {
        PlayerInfo[playerid][pMissionDay] = strval(value);
    }
    else if (strcmp(key, "mission_work", false) == 0)
    {
        PlayerInfo[playerid][pMissionWork] = strval(value);
    }
    else if (strcmp(key, "mission_market", false) == 0)
    {
        PlayerInfo[playerid][pMissionMarket] = strval(value);
    }
    else if (strcmp(key, "mission_bank", false) == 0)
    {
        PlayerInfo[playerid][pMissionBank] = strval(value);
    }
    else if (strcmp(key, "mission_bill", false) == 0)
    {
        PlayerInfo[playerid][pMissionBill] = strval(value);
    }
    else if (strcmp(key, "mission_docs", false) == 0)
    {
        PlayerInfo[playerid][pMissionDocs] = strval(value);
    }
    else if (strcmp(key, "mission_rewarded", false) == 0)
    {
        PlayerInfo[playerid][pMissionRewarded] = strval(value);
    }
    else if (strcmp(key, "achievements", false) == 0)
    {
        PlayerInfo[playerid][pAchievements] = strval(value);
    }
    else if (strcmp(key, "tutorial_step", false) == 0)
    {
        PlayerInfo[playerid][pTutorialStep] = strval(value);
    }
    else if (strcmp(key, "tutorial_completed", false) == 0 || strcmp(key, "intro_tutorial_done", false) == 0)
    {
        PlayerInfo[playerid][pIntroTutorialDone] = strval(value);
    }
    else if (strcmp(key, "business_order_day", false) == 0)
    {
        PlayerInfo[playerid][pBusinessOrderDay] = strval(value);
    }
    else if (strcmp(key, "business_orders", false) == 0)
    {
        PlayerInfo[playerid][pBusinessOrders] = strval(value);
    }
    else if (strcmp(key, "justice_status", false) == 0)
    {
        PlayerInfo[playerid][pJusticeStatus] = strval(value);
    }
    else if (strcmp(key, "justice_deadline_day", false) == 0)
    {
        PlayerInfo[playerid][pJusticeDeadlineDay] = strval(value);
    }
    else if (strcmp(key, "justice_appeals", false) == 0)
    {
        PlayerInfo[playerid][pJusticeAppeals] = strval(value);
    }
    else if (strcmp(key, "loan_installments_paid", false) == 0)
    {
        PlayerInfo[playerid][pLoanInstallmentsPaid] = strval(value);
    }
    else if (strcmp(key, "daily_reward_day", false) == 0)
    {
        PlayerInfo[playerid][pDailyRewardDay] = strval(value);
    }
    else if (strcmp(key, "weekly_reward_week", false) == 0)
    {
        PlayerInfo[playerid][pWeeklyRewardWeek] = strval(value);
    }
    else if (strcmp(key, "login_streak", false) == 0)
    {
        PlayerInfo[playerid][pLoginStreak] = strval(value);
    }
    else if (strcmp(key, "last_login_day", false) == 0)
    {
        PlayerInfo[playerid][pLastLoginDay] = strval(value);
    }
    else if (strcmp(key, "political_office", false) == 0)
    {
        PlayerInfo[playerid][pPoliticalOffice] = strval(value);
    }
    else if (strcmp(key, "political_term_start", false) == 0)
    {
        PlayerInfo[playerid][pPoliticalTermStartDay] = strval(value);
    }
    else if (strcmp(key, "political_term_end", false) == 0)
    {
        PlayerInfo[playerid][pPoliticalTermEndDay] = strval(value);
    }
    else if (strcmp(key, "city_pass_week", false) == 0)
    {
        PlayerInfo[playerid][pCityPassWeek] = strval(value);
    }
    else if (strcmp(key, "city_pass_job", false) == 0)
    {
        PlayerInfo[playerid][pCityPassJob] = strval(value);
    }
    else if (strcmp(key, "city_pass_economy", false) == 0)
    {
        PlayerInfo[playerid][pCityPassEconomy] = strval(value);
    }
    else if (strcmp(key, "city_pass_public", false) == 0)
    {
        PlayerInfo[playerid][pCityPassPublic] = strval(value);
    }
    else if (strcmp(key, "city_pass_rewarded", false) == 0)
    {
        PlayerInfo[playerid][pCityPassRewarded] = strval(value);
    }
    else if (strcmp(key, "weekly_work_score", false) == 0)
    {
        PlayerInfo[playerid][pWeeklyWorkScore] = strval(value);
    }
    else if (strcmp(key, "weekly_business_score", false) == 0)
    {
        PlayerInfo[playerid][pWeeklyBusinessScore] = strval(value);
    }
    else if (strcmp(key, "weekly_police_score", false) == 0)
    {
        PlayerInfo[playerid][pWeeklyPoliceScore] = strval(value);
    }
    else if (strcmp(key, "weekly_citizen_score", false) == 0)
    {
        PlayerInfo[playerid][pWeeklyCitizenScore] = strval(value);
    }
    else if (strcmp(key, "business_stock", false) == 0)
    {
        PlayerInfo[playerid][pBusinessStock] = strval(value);
    }
    else if (strcmp(key, "business_contracts", false) == 0)
    {
        PlayerInfo[playerid][pBusinessContracts] = strval(value);
    }
    else if (strcmp(key, "business_debt", false) == 0)
    {
        PlayerInfo[playerid][pBusinessDebt] = strval(value);
    }
    else if (strcmp(key, "business_recovery_day", false) == 0)
    {
        PlayerInfo[playerid][pBusinessRecoveryDay] = strval(value);
    }
    else if (strcmp(key, "business_bankrupt", false) == 0)
    {
        PlayerInfo[playerid][pBusinessBankrupt] = strval(value);
    }
    else if (strcmp(key, "vehicle_inspection_day", false) == 0)
    {
        PlayerInfo[playerid][pVehicleInspectionDay] = strval(value);
    }
    else if (strcmp(key, "medical_shifts", false) == 0)
    {
        PlayerInfo[playerid][pMedicalShifts] = strval(value);
    }
    else if (strcmp(key, "police_warrants", false) == 0)
    {
        PlayerInfo[playerid][pPoliceWarrants] = strval(value);
    }
    else if (strcmp(key, "police_evidence", false) == 0)
    {
        PlayerInfo[playerid][pPoliceEvidence] = strval(value);
    }
    else if (strcmp(key, "justice_active_warrants", false) == 0)
    {
        PlayerInfo[playerid][pJusticeActiveWarrants] = strval(value);
    }
    else if (strcmp(key, "justice_active_evidence", false) == 0)
    {
        PlayerInfo[playerid][pJusticeActiveEvidence] = strval(value);
    }
    else if (strcmp(key, "ankle_monitor", false) == 0)
    {
        PlayerInfo[playerid][pAnkleMonitor] = strval(value);
    }
    else if (strcmp(key, "contract_limit_day", false) == 0)
    {
        PlayerInfo[playerid][pContractLimitDay] = strval(value);
    }
    else if (strcmp(key, "contracts_today", false) == 0)
    {
        PlayerInfo[playerid][pContractsToday] = strval(value);
    }
    else if (strcmp(key, "logistics_completed", false) == 0)
    {
        PlayerInfo[playerid][pLogisticsCompleted] = strval(value);
    }
    else if (strcmp(key, "logistics_canceled", false) == 0)
    {
        PlayerInfo[playerid][pLogisticsCanceled] = strval(value);
    }
    else if (strcmp(key, "logistics_late", false) == 0)
    {
        PlayerInfo[playerid][pLogisticsLate] = strval(value);
    }
    else if (strcmp(key, "logistics_reputation", false) == 0)
    {
        PlayerInfo[playerid][pLogisticsReputation] = strval(value);
        if (PlayerInfo[playerid][pLogisticsReputation] < 0) PlayerInfo[playerid][pLogisticsReputation] = 0;
        if (PlayerInfo[playerid][pLogisticsReputation] > 100) PlayerInfo[playerid][pLogisticsReputation] = 100;
    }
    else if (strcmp(key, "logistics_earnings", false) == 0)
    {
        PlayerInfo[playerid][pLogisticsEarnings] = strval(value);
    }
    else if (strcmp(key, "logistics_generated", false) == 0)
    {
        PlayerInfo[playerid][pLogisticsGenerated] = strval(value);
    }
    else if (strcmp(key, "auto_business_id", false) == 0)
    {
        PlayerInfo[playerid][pAutoBusinessId] = strval(value);
    }
    else if (strcmp(key, "auto_business_profit", false) == 0)
    {
        PlayerInfo[playerid][pAutoBusinessProfit] = strval(value);
    }
    else if (strcmp(key, "auto_business_revenue", false) == 0)
    {
        PlayerInfo[playerid][pAutoBusinessRevenue] = strval(value);
    }
    else if (strcmp(key, "onboarding_rewarded", false) == 0)
    {
        PlayerInfo[playerid][pOnboardingRewarded] = strval(value);
    }
    else if (strcmp(key, "warzone_day", false) == 0)
    {
        PlayerInfo[playerid][pWarZoneDay] = strval(value);
    }
    else if (strcmp(key, "warzone_kills_today", false) == 0)
    {
        PlayerInfo[playerid][pWarZoneKillsToday] = strval(value);
    }
    else if (strcmp(key, "crime_faction", false) == 0)
    {
        PlayerInfo[playerid][pCrimeFaction] = strval(value);
    }
    else if (strcmp(key, "crime_rank", false) == 0)
    {
        PlayerInfo[playerid][pCrimeRank] = strval(value);
    }
    else if (strcmp(key, "crime_respect", false) == 0)
    {
        PlayerInfo[playerid][pCrimeRespect] = strval(value);
    }
    else if (strcmp(key, "crime_mission_cooldown", false) == 0)
    {
        PlayerInfo[playerid][pCrimeMissionCooldown] = strval(value);
    }
    else if (strcmp(key, "crime_hourly_stamp", false) == 0)
    {
        PlayerInfo[playerid][pCrimeHourlyStamp] = strval(value);
    }
    else if (strcmp(key, "crime_hourly_gain", false) == 0)
    {
        PlayerInfo[playerid][pCrimeHourlyGain] = strval(value);
    }
    else if (strcmp(key, "house", false) == 0)
    {
        PlayerInfo[playerid][pHouse] = strval(value);
    }
    else if (strcmp(key, "rented_house", false) == 0)
    {
        PlayerInfo[playerid][pRentedHouse] = strval(value);
    }
    else if (strcmp(key, "hunger", false) == 0)
    {
        PlayerInfo[playerid][pHunger] = strval(value);
        if (PlayerInfo[playerid][pHunger] < 0)
        {
            PlayerInfo[playerid][pHunger] = 0;
        }
        if (PlayerInfo[playerid][pHunger] > NEEDS_MAX_VALUE)
        {
            PlayerInfo[playerid][pHunger] = NEEDS_MAX_VALUE;
        }
    }
    else if (strcmp(key, "thirst", false) == 0)
    {
        PlayerInfo[playerid][pThirst] = strval(value);
        if (PlayerInfo[playerid][pThirst] < 0)
        {
            PlayerInfo[playerid][pThirst] = 0;
        }
        if (PlayerInfo[playerid][pThirst] > NEEDS_MAX_VALUE)
        {
            PlayerInfo[playerid][pThirst] = NEEDS_MAX_VALUE;
        }
    }
    else if (strcmp(key, "fatigue", false) == 0)
    {
        PlayerInfo[playerid][pFatigue] = strval(value);
        if (PlayerInfo[playerid][pFatigue] < 0) PlayerInfo[playerid][pFatigue] = 0;
        if (PlayerInfo[playerid][pFatigue] > NEEDS_MAX_VALUE) PlayerInfo[playerid][pFatigue] = NEEDS_MAX_VALUE;
    }
    else if (strcmp(key, "sleep", false) == 0)
    {
        PlayerInfo[playerid][pSleep] = strval(value);
        if (PlayerInfo[playerid][pSleep] < 0) PlayerInfo[playerid][pSleep] = 0;
        if (PlayerInfo[playerid][pSleep] > NEEDS_MAX_VALUE) PlayerInfo[playerid][pSleep] = NEEDS_MAX_VALUE;
    }
    else if (strcmp(key, "pantry_food", false) == 0)
    {
        PlayerInfo[playerid][pPantryFood] = strval(value);
        if (PlayerInfo[playerid][pPantryFood] < 0) PlayerInfo[playerid][pPantryFood] = 0;
    }
    else if (strcmp(key, "pantry_drink", false) == 0)
    {
        PlayerInfo[playerid][pPantryDrink] = strval(value);
        if (PlayerInfo[playerid][pPantryDrink] < 0) PlayerInfo[playerid][pPantryDrink] = 0;
    }
    else if (strcmp(key, "logged", false) == 0)
    {
        PlayerInfo[playerid][pLogged] = strval(value);
    }
    else
    {
        if (!ApplyVehicleAccountField(playerid, key, value))
        {
            if (!ApplyInventoryAccountField(playerid, key, value))
            {
                ApplyJobProgressAccountField(playerid, key, value);
            }
        }
    }

    return 1;
}

stock ApplyAccountLine(playerid, line[])
{
    new equalPos;
    new key[32];
    new value[96];
    new length = strlen(line);

    equalPos = strfind(line, "=", false);
    if (equalPos == -1)
    {
        return 0;
    }

    strmid(key, line, 0, equalPos, sizeof(key));
    strmid(value, line, equalPos + 1, length, sizeof(value));
    ApplyAccountField(playerid, key, value);
    return 1;
}

stock ApplyLegacyAccountField(playerid, index, value[])
{
    switch (index)
    {
        case 0: format(PlayerInfo[playerid][pPasswordHash], PASSWORD_HASH_SIZE, "%s", value);
        case 1: PlayerInfo[playerid][pMoney] = strval(value);
        case 2: PlayerInfo[playerid][pSkin] = strval(value);
        case 3: PlayerInfo[playerid][pAdminLevel] = strval(value);
        case 4: PlayerInfo[playerid][pKills] = strval(value);
        case 5: PlayerInfo[playerid][pDeaths] = strval(value);
        case 6: PlayerInfo[playerid][pLastSpawn] = strval(value);
        case 7: PlayerInfo[playerid][pSpawnCount] = strval(value);
        case 8: PlayerInfo[playerid][pPosX] = floatstr(value);
        case 9: PlayerInfo[playerid][pPosY] = floatstr(value);
        case 10: PlayerInfo[playerid][pPosZ] = floatstr(value);
        case 11: PlayerInfo[playerid][pPosA] = floatstr(value);
        case 12: PlayerInfo[playerid][pInterior] = strval(value);
        case 13: PlayerInfo[playerid][pVirtualWorld] = strval(value);
        case 14: PlayerInfo[playerid][pOnlineTime] = strval(value);
        case 15: PlayerInfo[playerid][pLogged] = strval(value);
    }
    return 1;
}

stock Account_CopyFile(sourcePath[], destPath[])
{
    new File:source;
    new File:dest;
    new line[256];

    source = fopen(sourcePath, io_read);
    if (!source)
    {
        return 0;
    }

    dest = fopen(destPath, io_write);
    if (!dest)
    {
        fclose(source);
        return 0;
    }

    while (fread(source, line, sizeof(line)) > 0)
    {
        fwrite(dest, line);
    }

    fclose(dest);
    fclose(source);
    return 1;
}

stock Account_ValidateSavedFile(path[])
{
    new File:file;
    new line[256];
    new value[96];
    new lines;
    new hasFormat;
    new hasHash;
    new hasLogged;

    file = fopen(path, io_read);
    if (!file)
    {
        return 0;
    }

    while (fread(file, line, sizeof(line)) > 0)
    {
        lines++;
        if (strfind(line, "format_version=", false) == 0)
        {
            hasFormat = 1;
        }
        else if (strfind(line, "password_hash=", false) == 0)
        {
            strmid(value, line, 14, strlen(line), sizeof(value));
            StripLineEnd(value);
            if (strlen(value) == 64)
            {
                hasHash = 1;
            }
        }
        else if (strfind(line, "logged=", false) == 0)
        {
            hasLogged = 1;
        }
    }

    fclose(file);
    return (lines >= 40 && hasFormat && hasHash && hasLogged);
}

stock LoadAccount(playerid)
{
    new path[ACCOUNT_PATH_SIZE];
    new line[128];
    new lineIndex;
    new repairReport[256];
    new repairs;
    new File:account;

    SetDefaultPlayerInfo(playerid);
    GetPlayerAccountPath(playerid, path, sizeof(path));
    account = fopen(path, io_read);

    if (!account)
    {
        return 0;
    }

    while (ReadFileLine(account, line, sizeof(line)))
    {
        if (!ApplyAccountLine(playerid, line))
        {
            ApplyLegacyAccountField(playerid, lineIndex, line);
        }
        lineIndex++;
    }

    fclose(account);
    Dealership_FinalizeAccountLoad(playerid);

    if (strlen(PlayerInfo[playerid][pPasswordHash]) != 64)
    {
        return 0;
    }

    if (PlayerInfo[playerid][pAccountFormatVersion] < 8 && !PlayerInfo[playerid][pIntroTutorialDone])
    {
        PlayerInfo[playerid][pIntroTutorialDone] = 1;
    }

    repairs = Account_RepairLegacyData(playerid, 1, repairReport, sizeof(repairReport));
    if (repairs > 0)
    {
        Dealership_FinalizeAccountLoad(playerid);
        format(line, sizeof(line), "repaired=%d items=%s", repairs, repairReport);
        WritePlayerLog(LOG_ADMIN_FILE, "ACCOUNT_REPAIR", playerid, line);
        SaveAccountData(playerid, 0);
    }

    if (PlayerInfo[playerid][pMoney] < 0) PlayerInfo[playerid][pMoney] = 0;
    if (PlayerInfo[playerid][pBankMoney] < 0) PlayerInfo[playerid][pBankMoney] = 0;
    if (PlayerInfo[playerid][pSalary] < 0) PlayerInfo[playerid][pSalary] = 0;
    if (PlayerInfo[playerid][pFines] < 0) PlayerInfo[playerid][pFines] = 0;
    if (PlayerInfo[playerid][pTrafficPoints] < 0) PlayerInfo[playerid][pTrafficPoints] = 0;
    if (PlayerInfo[playerid][pTrafficPoints] > MAX_TRAFFIC_POINTS) PlayerInfo[playerid][pTrafficPoints] = MAX_TRAFFIC_POINTS;
    if (PlayerInfo[playerid][pBankLoan] < 0) PlayerInfo[playerid][pBankLoan] = 0;
    if (PlayerInfo[playerid][pJusticeFineDue] < 0) PlayerInfo[playerid][pJusticeFineDue] = 0;
    if (PlayerInfo[playerid][pBankLoanOriginal] < 0) PlayerInfo[playerid][pBankLoanOriginal] = 0;
    if (PlayerInfo[playerid][pBankLoanInstallmentValue] < 0) PlayerInfo[playerid][pBankLoanInstallmentValue] = 0;
    if (PlayerInfo[playerid][pBankLoanInstallments] < 0) PlayerInfo[playerid][pBankLoanInstallments] = 0;
    if (PlayerInfo[playerid][pLoanInstallmentsPaid] < 0) PlayerInfo[playerid][pLoanInstallmentsPaid] = 0;

    if (PlayerInfo[playerid][pBankLoan] <= 0)
    {
        PlayerInfo[playerid][pBankLoanOriginal] = 0;
        PlayerInfo[playerid][pBankLoanInstallmentValue] = 0;
        PlayerInfo[playerid][pBankLoanInstallments] = 0;
        PlayerInfo[playerid][pBankLoanNextDueDay] = 0;
        PlayerInfo[playerid][pBillLoanInstallmentDue] = 0;
        PlayerInfo[playerid][pLoanInstallmentsPaid] = 0;
    }
    else
    {
        new remainingInstallments;

        if (PlayerInfo[playerid][pBankLoanOriginal] <= 0)
        {
            PlayerInfo[playerid][pBankLoanOriginal] = PlayerInfo[playerid][pBankLoan];
        }
        if (PlayerInfo[playerid][pBankLoanInstallments] <= 0)
        {
            PlayerInfo[playerid][pBankLoanInstallments] = 4;
        }
        if (PlayerInfo[playerid][pLoanInstallmentsPaid] >= PlayerInfo[playerid][pBankLoanInstallments])
        {
            PlayerInfo[playerid][pLoanInstallmentsPaid] = PlayerInfo[playerid][pBankLoanInstallments] - 1;
        }

        remainingInstallments = PlayerInfo[playerid][pBankLoanInstallments] - PlayerInfo[playerid][pLoanInstallmentsPaid];
        if (remainingInstallments < 1)
        {
            remainingInstallments = 1;
        }
        if (PlayerInfo[playerid][pBankLoanInstallmentValue] <= 0)
        {
            PlayerInfo[playerid][pBankLoanInstallmentValue] = (PlayerInfo[playerid][pBankLoan] + remainingInstallments - 1) / remainingInstallments;
        }
        if (PlayerInfo[playerid][pBankLoanNextDueDay] <= 0)
        {
            PlayerInfo[playerid][pBankLoanNextDueDay] = GetBrasiliaDayStamp() + 30;
        }
    }

    if (!PlayerInfo[playerid][pBankAccount] && (PlayerInfo[playerid][pBankMoney] > 0 || PlayerInfo[playerid][pSalary] > 0 || PlayerInfo[playerid][pBankCard] || PlayerInfo[playerid][pBankLoan] > 0))
    {
        PlayerInfo[playerid][pBankAccount] = 1;
    }
    if (PlayerInfo[playerid][pAccountFormatVersion] < 8 && !PlayerInfo[playerid][pIntroTutorialDone])
    {
        PlayerInfo[playerid][pIntroTutorialDone] = 1;
    }
    return 1;
}

stock LoadAccountHash(playerid, hash[], size = sizeof(hash))
{
    new path[ACCOUNT_PATH_SIZE];
    new line[128];
    new equalPos;
    new key[32];
    new value[96];
    new File:account;

    GetPlayerAccountPath(playerid, path, sizeof(path));
    account = fopen(path, io_read);

    if (!account)
    {
        return 0;
    }

    while (ReadFileLine(account, line, sizeof(line)))
    {
        equalPos = strfind(line, "=", false);
        if (equalPos == -1)
        {
            if (strlen(line) == 64)
            {
                format(hash, size, "%s", line);
                fclose(account);
                return 1;
            }
            continue;
        }

        strmid(key, line, 0, equalPos, sizeof(key));
        if (strcmp(key, "password_hash", false) == 0)
        {
            strmid(value, line, equalPos + 1, strlen(line), sizeof(value));
            format(hash, size, "%s", value);
            fclose(account);
            return (strlen(hash) == 64);
        }
    }

    fclose(account);
    return 0;
}

stock UpdatePlayerLiveData(playerid)
{
    new elapsed;
    new tick;

    if (!PlayerInfo[playerid][pLogged])
    {
        return 1;
    }

    SyncPlayerCash(playerid);
    if (!Work_IsActive(playerid))
    {
        PlayerInfo[playerid][pSkin] = GetPlayerSkin(playerid);
    }
    PlayerInfo[playerid][pInterior] = GetPlayerInterior(playerid);
    PlayerInfo[playerid][pVirtualWorld] = GetPlayerVirtualWorld(playerid);
    GetPlayerPos(playerid, PlayerInfo[playerid][pPosX], PlayerInfo[playerid][pPosY], PlayerInfo[playerid][pPosZ]);
    GetPlayerFacingAngle(playerid, PlayerInfo[playerid][pPosA]);

    tick = GetTickCount();
    if (PlayerInfo[playerid][pSessionTick] > 0)
    {
        elapsed = (tick - PlayerInfo[playerid][pSessionTick]) / 1000;
        if (elapsed > 0)
        {
            PlayerInfo[playerid][pOnlineTime] += elapsed;
        }
    }

    PlayerInfo[playerid][pSessionTick] = tick;
    return 1;
}

stock GivePlayerExperience(playerid, points, saveNow = 1)
{
    new message[128];

    if (!PlayerInfo[playerid][pLogged] || points <= 0)
    {
        return 0;
    }

    if (PlayerInfo[playerid][pLevel] < 1)
    {
        PlayerInfo[playerid][pLevel] = 1;
    }

    PlayerInfo[playerid][pExperience] += points;

    while (PlayerInfo[playerid][pExperience] >= gCfgCharacterXpPerLevel)
    {
        PlayerInfo[playerid][pExperience] -= gCfgCharacterXpPerLevel;
        PlayerInfo[playerid][pLevel]++;
        format(message, sizeof(message), "Voce subiu para o nivel %d.", PlayerInfo[playerid][pLevel]);
        SendClientMessage(playerid, COLOR_GREEN, message);
    }

    if (saveNow)
    {
        SaveAccountData(playerid, 0);
    }
    return 1;
}

stock UpdateTimedPlayerExperience(playerid)
{
    new tick;
    new awarded;

    if (!PlayerInfo[playerid][pLogged])
    {
        return 0;
    }

    tick = GetTickCount();
    if (PlayerInfo[playerid][pExperienceTick] == 0)
    {
        PlayerInfo[playerid][pExperienceTick] = tick;
        return 0;
    }

    while ((tick - PlayerInfo[playerid][pExperienceTick]) >= gCfgCharacterXpInterval)
    {
        PlayerInfo[playerid][pExperienceTick] += gCfgCharacterXpInterval;
        awarded++;
    }

    if (awarded > 0)
    {
        GivePlayerExperience(playerid, awarded, 1);
    }
    return awarded;
}

stock SaveAccountData(playerid, updateLiveData = 1)
{
    new path[ACCOUNT_PATH_SIZE];
    new tempPath[ACCOUNT_PATH_SIZE + 5];
    new backupPath[ACCOUNT_PATH_SIZE + 5];
    new detail[160];
    new line[128];
    new File:account;

    if (!gAccountSaveForce && updateLiveData == 0 && IsValidConnectedPlayer(playerid) && PlayerInfo[playerid][pLogged])
    {
        return MarkAccountDirty(playerid);
    }

    if (updateLiveData)
    {
        UpdatePlayerLiveData(playerid);
    }
    Dealership_SaveActiveVehState(playerid);

    if (strlen(PlayerInfo[playerid][pPasswordHash]) != 64)
    {
        return 0;
    }

    GetPlayerAccountPath(playerid, path, sizeof(path));
    format(tempPath, sizeof(tempPath), "%s.tmp", path);
    format(backupPath, sizeof(backupPath), "%s.bak", path);

    account = fopen(tempPath, io_write);
    if (!account)
    {
        return 0;
    }

    format(line, sizeof(line), "format_version=%d\r\n", ACCOUNT_FORMAT_VERSION); fwrite(account, line);
    format(line, sizeof(line), "password_hash=%s\r\n", PlayerInfo[playerid][pPasswordHash]); fwrite(account, line);
    format(line, sizeof(line), "admin=%d\r\n", PlayerInfo[playerid][pAdminLevel]); fwrite(account, line);
    format(line, sizeof(line), "vip_level=%d\r\n", PlayerInfo[playerid][pVipLevel]); fwrite(account, line);
    format(line, sizeof(line), "vip_expire=%d\r\n", PlayerInfo[playerid][pVipExpire]); fwrite(account, line);
    format(line, sizeof(line), "vip_last_kit_day=%d\r\n", PlayerInfo[playerid][pVipLastKitDay]); fwrite(account, line);
    format(line, sizeof(line), "vip_total_days=%d\r\n", PlayerInfo[playerid][pVipTotalDays]); fwrite(account, line);
    format(line, sizeof(line), "character_name=%s\r\n", PlayerInfo[playerid][pCharacterName]); fwrite(account, line);
    format(line, sizeof(line), "money=%d\r\n", PlayerInfo[playerid][pMoney]); fwrite(account, line);
    format(line, sizeof(line), "skin=%d\r\n", PlayerInfo[playerid][pSkin]); fwrite(account, line);
    format(line, sizeof(line), "kills=%d\r\n", PlayerInfo[playerid][pKills]); fwrite(account, line);
    format(line, sizeof(line), "deaths=%d\r\n", PlayerInfo[playerid][pDeaths]); fwrite(account, line);
    format(line, sizeof(line), "last_spawn=%d\r\n", PlayerInfo[playerid][pLastSpawn]); fwrite(account, line);
    format(line, sizeof(line), "spawn_count=%d\r\n", PlayerInfo[playerid][pSpawnCount]); fwrite(account, line);
    format(line, sizeof(line), "pos_x=%.4f\r\n", PlayerInfo[playerid][pPosX]); fwrite(account, line);
    format(line, sizeof(line), "pos_y=%.4f\r\n", PlayerInfo[playerid][pPosY]); fwrite(account, line);
    format(line, sizeof(line), "pos_z=%.4f\r\n", PlayerInfo[playerid][pPosZ]); fwrite(account, line);
    format(line, sizeof(line), "pos_a=%.4f\r\n", PlayerInfo[playerid][pPosA]); fwrite(account, line);
    format(line, sizeof(line), "interior=%d\r\n", PlayerInfo[playerid][pInterior]); fwrite(account, line);
    format(line, sizeof(line), "virtual_world=%d\r\n", PlayerInfo[playerid][pVirtualWorld]); fwrite(account, line);
    format(line, sizeof(line), "online_time=%d\r\n", PlayerInfo[playerid][pOnlineTime]); fwrite(account, line);
    format(line, sizeof(line), "experience=%d\r\n", PlayerInfo[playerid][pExperience]); fwrite(account, line);
    format(line, sizeof(line), "level=%d\r\n", PlayerInfo[playerid][pLevel]); fwrite(account, line);
    format(line, sizeof(line), "documents=%d\r\n", PlayerInfo[playerid][pDocuments]); fwrite(account, line);
    format(line, sizeof(line), "documents_expire=%d\r\n", PlayerInfo[playerid][pDocumentsExpire]); fwrite(account, line);
    format(line, sizeof(line), "job=%d\r\n", PlayerInfo[playerid][pJob]); fwrite(account, line);
    format(line, sizeof(line), "job_xp=%d\r\n", Job_GetPlayerXP(playerid, PlayerInfo[playerid][pJob])); fwrite(account, line);
    format(line, sizeof(line), "job_level=%d\r\n", Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob])); fwrite(account, line);
    format(line, sizeof(line), "license_cnh=%d\r\n", PlayerInfo[playerid][pLicenseCNH]); fwrite(account, line);
    format(line, sizeof(line), "license_heavy=%d\r\n", PlayerInfo[playerid][pLicenseHeavy]); fwrite(account, line);
    format(line, sizeof(line), "license_medical=%d\r\n", PlayerInfo[playerid][pLicenseMedical]); fwrite(account, line);
    format(line, sizeof(line), "license_oab=%d\r\n", PlayerInfo[playerid][pLicenseOAB]); fwrite(account, line);
    format(line, sizeof(line), "license_public=%d\r\n", PlayerInfo[playerid][pLicensePublic]); fwrite(account, line);
    format(line, sizeof(line), "license_police=%d\r\n", PlayerInfo[playerid][pLicensePolice]); fwrite(account, line);
    format(line, sizeof(line), "license_cnh_expire=%d\r\n", PlayerInfo[playerid][pLicenseCNHExpire]); fwrite(account, line);
    format(line, sizeof(line), "license_heavy_expire=%d\r\n", PlayerInfo[playerid][pLicenseHeavyExpire]); fwrite(account, line);
    format(line, sizeof(line), "license_medical_expire=%d\r\n", PlayerInfo[playerid][pLicenseMedicalExpire]); fwrite(account, line);
    format(line, sizeof(line), "license_oab_expire=%d\r\n", PlayerInfo[playerid][pLicenseOABExpire]); fwrite(account, line);
    format(line, sizeof(line), "license_public_expire=%d\r\n", PlayerInfo[playerid][pLicensePublicExpire]); fwrite(account, line);
    format(line, sizeof(line), "license_police_expire=%d\r\n", PlayerInfo[playerid][pLicensePoliceExpire]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_model=%d\r\n", PlayerInfo[playerid][pVehicleModel]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_color1=%d\r\n", PlayerInfo[playerid][pVehicleColor1]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_color2=%d\r\n", PlayerInfo[playerid][pVehicleColor2]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_plate=%s\r\n", PlayerInfo[playerid][pVehiclePlate]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_fuel=%d\r\n", PlayerInfo[playerid][pVehicleFuel]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_health=%.2f\r\n", PlayerInfo[playerid][pVehicleHealth]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_pos_x=%.4f\r\n", PlayerInfo[playerid][pVehiclePosX]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_pos_y=%.4f\r\n", PlayerInfo[playerid][pVehiclePosY]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_pos_z=%.4f\r\n", PlayerInfo[playerid][pVehiclePosZ]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_pos_a=%.4f\r\n", PlayerInfo[playerid][pVehiclePosA]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_interior=%d\r\n", PlayerInfo[playerid][pVehicleInterior]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_virtual_world=%d\r\n", PlayerInfo[playerid][pVehicleVirtualWorld]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_parked=%d\r\n", PlayerInfo[playerid][pVehicleParked]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_insurance=%d\r\n", PlayerInfo[playerid][pVehicleInsurance]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_garage=%d\r\n", PlayerInfo[playerid][pVehicleGarage]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_impounded=%d\r\n", PlayerInfo[playerid][pVehicleImpounded]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_tax_due=%d\r\n", PlayerInfo[playerid][pVehicleTaxDue]); fwrite(account, line);
    format(line, sizeof(line), "toll_tag=%d\r\n", PlayerInfo[playerid][pTollTag]); fwrite(account, line);
    SaveVehicleData(playerid, account);
    format(line, sizeof(line), "bank=%d\r\n", PlayerInfo[playerid][pBankMoney]); fwrite(account, line);
    format(line, sizeof(line), "bank_account=%d\r\n", PlayerInfo[playerid][pBankAccount]); fwrite(account, line);
    format(line, sizeof(line), "bank_card=%d\r\n", PlayerInfo[playerid][pBankCard]); fwrite(account, line);
    format(line, sizeof(line), "bank_loan=%d\r\n", PlayerInfo[playerid][pBankLoan]); fwrite(account, line);
    format(line, sizeof(line), "bank_loan_original=%d\r\n", PlayerInfo[playerid][pBankLoanOriginal]); fwrite(account, line);
    format(line, sizeof(line), "bank_loan_installment_value=%d\r\n", PlayerInfo[playerid][pBankLoanInstallmentValue]); fwrite(account, line);
    format(line, sizeof(line), "bank_loan_installments=%d\r\n", PlayerInfo[playerid][pBankLoanInstallments]); fwrite(account, line);
    format(line, sizeof(line), "bank_loan_next_due_day=%d\r\n", PlayerInfo[playerid][pBankLoanNextDueDay]); fwrite(account, line);
    format(line, sizeof(line), "bank_score=%d\r\n", PlayerInfo[playerid][pBankScore]); fwrite(account, line);
    format(line, sizeof(line), "bank_good_history=%d\r\n", PlayerInfo[playerid][pBankGoodHistory]); fwrite(account, line);
    format(line, sizeof(line), "bank_bad_history=%d\r\n", PlayerInfo[playerid][pBankBadHistory]); fwrite(account, line);
    format(line, sizeof(line), "income_registered=%d\r\n", PlayerInfo[playerid][pIncomeRegistered]); fwrite(account, line);
    format(line, sizeof(line), "salary_last_day=%d\r\n", PlayerInfo[playerid][pSalaryLastDay]); fwrite(account, line);
    format(line, sizeof(line), "salary=%d\r\n", PlayerInfo[playerid][pSalary]); fwrite(account, line);
    format(line, sizeof(line), "salary_work_day=%d\r\n", PlayerInfo[playerid][pSalaryWorkDay]); fwrite(account, line);
    format(line, sizeof(line), "salary_work_tasks=%d\r\n", PlayerInfo[playerid][pSalaryWorkTasks]); fwrite(account, line);
    format(line, sizeof(line), "salary_productivity_paid=%d\r\n", PlayerInfo[playerid][pSalaryProductivityPaid]); fwrite(account, line);
    format(line, sizeof(line), "fines=%d\r\n", PlayerInfo[playerid][pFines]); fwrite(account, line);
    format(line, sizeof(line), "traffic_points=%d\r\n", PlayerInfo[playerid][pTrafficPoints]); fwrite(account, line);
    format(line, sizeof(line), "wanted=%d\r\n", PlayerInfo[playerid][pWanted]); fwrite(account, line);
    format(line, sizeof(line), "jail_time=%d\r\n", PlayerInfo[playerid][pJailTime]); fwrite(account, line);
    format(line, sizeof(line), "jail_crime_id=%d\r\n", PlayerInfo[playerid][pJailCrimeId]); fwrite(account, line);
    format(line, sizeof(line), "admin_jail=%d\r\n", PlayerInfo[playerid][pAdminJail]); fwrite(account, line);
    format(line, sizeof(line), "mute_time=%d\r\n", PlayerInfo[playerid][pMuteTime]); fwrite(account, line);
    format(line, sizeof(line), "criminal_records=%d\r\n", PlayerInfo[playerid][pCriminalRecords]); fwrite(account, line);
    format(line, sizeof(line), "injury=%d\r\n", PlayerInfo[playerid][pInjury]); fwrite(account, line);
    format(line, sizeof(line), "health_plan=%d\r\n", PlayerInfo[playerid][pHealthPlan]); fwrite(account, line);
    format(line, sizeof(line), "health_plan_expire=%d\r\n", PlayerInfo[playerid][pHealthPlanExpire]); fwrite(account, line);
    format(line, sizeof(line), "medical_severity=%d\r\n", PlayerInfo[playerid][pMedicalSeverity]); fwrite(account, line);
    format(line, sizeof(line), "medical_treatment_due=%d\r\n", PlayerInfo[playerid][pMedicalTreatmentDue]); fwrite(account, line);
    format(line, sizeof(line), "justice_cases=%d\r\n", PlayerInfo[playerid][pJusticeCases]); fwrite(account, line);
    format(line, sizeof(line), "justice_hearing_day=%d\r\n", PlayerInfo[playerid][pJusticeHearingDay]); fwrite(account, line);
    format(line, sizeof(line), "justice_sentence=%d\r\n", PlayerInfo[playerid][pJusticeSentence]); fwrite(account, line);
    format(line, sizeof(line), "justice_fine_due=%d\r\n", PlayerInfo[playerid][pJusticeFineDue]); fwrite(account, line);
    format(line, sizeof(line), "business_type=%d\r\n", PlayerInfo[playerid][pBusinessType]); fwrite(account, line);
    format(line, sizeof(line), "business_employees=%d\r\n", PlayerInfo[playerid][pBusinessEmployees]); fwrite(account, line);
    format(line, sizeof(line), "business_balance=%d\r\n", PlayerInfo[playerid][pBusinessBalance]); fwrite(account, line);
    format(line, sizeof(line), "business_tax_due=%d\r\n", PlayerInfo[playerid][pBusinessTaxDue]); fwrite(account, line);
    format(line, sizeof(line), "business_permit_expire=%d\r\n", PlayerInfo[playerid][pBusinessPermitExpire]); fwrite(account, line);
    format(line, sizeof(line), "business_editor_loc=%d\r\n", PlayerInfo[playerid][pBusinessEditorLoc]); fwrite(account, line);
    format(line, sizeof(line), "property_tax_due=%d\r\n", PlayerInfo[playerid][pPropertyTaxDue]); fwrite(account, line);
    format(line, sizeof(line), "government_tax_due=%d\r\n", PlayerInfo[playerid][pGovernmentTaxDue]); fwrite(account, line);
    format(line, sizeof(line), "tax_last_day=%d\r\n", PlayerInfo[playerid][pTaxLastDay]); fwrite(account, line);
    format(line, sizeof(line), "bill_water_due=%d\r\n", PlayerInfo[playerid][pBillWaterDue]); fwrite(account, line);
    format(line, sizeof(line), "bill_electric_due=%d\r\n", PlayerInfo[playerid][pBillElectricDue]); fwrite(account, line);
    format(line, sizeof(line), "bill_internet_due=%d\r\n", PlayerInfo[playerid][pBillInternetDue]); fwrite(account, line);
    format(line, sizeof(line), "bill_rent_due=%d\r\n", PlayerInfo[playerid][pBillRentDue]); fwrite(account, line);
    format(line, sizeof(line), "bill_vehicle_insurance_due=%d\r\n", PlayerInfo[playerid][pBillVehicleInsuranceDue]); fwrite(account, line);
    format(line, sizeof(line), "bill_health_plan_due=%d\r\n", PlayerInfo[playerid][pBillHealthPlanDue]); fwrite(account, line);
    format(line, sizeof(line), "bill_loan_installment_due=%d\r\n", PlayerInfo[playerid][pBillLoanInstallmentDue]); fwrite(account, line);
    format(line, sizeof(line), "bill_business_payroll_due=%d\r\n", PlayerInfo[playerid][pBillBusinessPayrollDue]); fwrite(account, line);
    format(line, sizeof(line), "bill_due_day=%d\r\n", PlayerInfo[playerid][pBillDueDay]); fwrite(account, line);
    format(line, sizeof(line), "bill_last_generate_day=%d\r\n", PlayerInfo[playerid][pBillLastGenerateDay]); fwrite(account, line);
    format(line, sizeof(line), "bill_late_charge_day=%d\r\n", PlayerInfo[playerid][pBillLateChargeDay]); fwrite(account, line);
    format(line, sizeof(line), "dirty_name=%d\r\n", PlayerInfo[playerid][pDirtyName]); fwrite(account, line);
    format(line, sizeof(line), "civil_cpf=%d\r\n", PlayerInfo[playerid][pCivilCPF]); fwrite(account, line);
    format(line, sizeof(line), "civil_rg=%d\r\n", PlayerInfo[playerid][pCivilRG]); fwrite(account, line);
    format(line, sizeof(line), "civil_certificate=%d\r\n", PlayerInfo[playerid][pCivilCertificate]); fwrite(account, line);
    format(line, sizeof(line), "civil_signature=%d\r\n", PlayerInfo[playerid][pCivilSignature]); fwrite(account, line);
    format(line, sizeof(line), "civil_married=%d\r\n", PlayerInfo[playerid][pCivilMarried]); fwrite(account, line);
    format(line, sizeof(line), "civil_divorces=%d\r\n", PlayerInfo[playerid][pCivilDivorces]); fwrite(account, line);
    format(line, sizeof(line), "contract_rent=%d\r\n", PlayerInfo[playerid][pContractRent]); fwrite(account, line);
    format(line, sizeof(line), "contract_financing=%d\r\n", PlayerInfo[playerid][pContractFinancing]); fwrite(account, line);
    format(line, sizeof(line), "contract_work=%d\r\n", PlayerInfo[playerid][pContractWork]); fwrite(account, line);
    format(line, sizeof(line), "contract_insurance=%d\r\n", PlayerInfo[playerid][pContractInsurance]); fwrite(account, line);
    format(line, sizeof(line), "home_solar=%d\r\n", PlayerInfo[playerid][pHomeSolar]); fwrite(account, line);
    format(line, sizeof(line), "mission_day=%d\r\n", PlayerInfo[playerid][pMissionDay]); fwrite(account, line);
    format(line, sizeof(line), "mission_work=%d\r\n", PlayerInfo[playerid][pMissionWork]); fwrite(account, line);
    format(line, sizeof(line), "mission_market=%d\r\n", PlayerInfo[playerid][pMissionMarket]); fwrite(account, line);
    format(line, sizeof(line), "mission_bank=%d\r\n", PlayerInfo[playerid][pMissionBank]); fwrite(account, line);
    format(line, sizeof(line), "mission_bill=%d\r\n", PlayerInfo[playerid][pMissionBill]); fwrite(account, line);
    format(line, sizeof(line), "mission_docs=%d\r\n", PlayerInfo[playerid][pMissionDocs]); fwrite(account, line);
    format(line, sizeof(line), "mission_rewarded=%d\r\n", PlayerInfo[playerid][pMissionRewarded]); fwrite(account, line);
    format(line, sizeof(line), "achievements=%d\r\n", PlayerInfo[playerid][pAchievements]); fwrite(account, line);
    format(line, sizeof(line), "tutorial_step=%d\r\n", PlayerInfo[playerid][pTutorialStep]); fwrite(account, line);
    format(line, sizeof(line), "tutorial_completed=%d\r\n", PlayerInfo[playerid][pIntroTutorialDone]); fwrite(account, line);
    format(line, sizeof(line), "business_order_day=%d\r\n", PlayerInfo[playerid][pBusinessOrderDay]); fwrite(account, line);
    format(line, sizeof(line), "business_orders=%d\r\n", PlayerInfo[playerid][pBusinessOrders]); fwrite(account, line);
    format(line, sizeof(line), "justice_status=%d\r\n", PlayerInfo[playerid][pJusticeStatus]); fwrite(account, line);
    format(line, sizeof(line), "justice_deadline_day=%d\r\n", PlayerInfo[playerid][pJusticeDeadlineDay]); fwrite(account, line);
    format(line, sizeof(line), "justice_appeals=%d\r\n", PlayerInfo[playerid][pJusticeAppeals]); fwrite(account, line);
    format(line, sizeof(line), "loan_installments_paid=%d\r\n", PlayerInfo[playerid][pLoanInstallmentsPaid]); fwrite(account, line);
    format(line, sizeof(line), "daily_reward_day=%d\r\n", PlayerInfo[playerid][pDailyRewardDay]); fwrite(account, line);
    format(line, sizeof(line), "weekly_reward_week=%d\r\n", PlayerInfo[playerid][pWeeklyRewardWeek]); fwrite(account, line);
    format(line, sizeof(line), "login_streak=%d\r\n", PlayerInfo[playerid][pLoginStreak]); fwrite(account, line);
    format(line, sizeof(line), "last_login_day=%d\r\n", PlayerInfo[playerid][pLastLoginDay]); fwrite(account, line);
    format(line, sizeof(line), "political_office=%d\r\n", PlayerInfo[playerid][pPoliticalOffice]); fwrite(account, line);
    format(line, sizeof(line), "political_term_start=%d\r\n", PlayerInfo[playerid][pPoliticalTermStartDay]); fwrite(account, line);
    format(line, sizeof(line), "political_term_end=%d\r\n", PlayerInfo[playerid][pPoliticalTermEndDay]); fwrite(account, line);
    format(line, sizeof(line), "city_pass_week=%d\r\n", PlayerInfo[playerid][pCityPassWeek]); fwrite(account, line);
    format(line, sizeof(line), "city_pass_job=%d\r\n", PlayerInfo[playerid][pCityPassJob]); fwrite(account, line);
    format(line, sizeof(line), "city_pass_economy=%d\r\n", PlayerInfo[playerid][pCityPassEconomy]); fwrite(account, line);
    format(line, sizeof(line), "city_pass_public=%d\r\n", PlayerInfo[playerid][pCityPassPublic]); fwrite(account, line);
    format(line, sizeof(line), "city_pass_rewarded=%d\r\n", PlayerInfo[playerid][pCityPassRewarded]); fwrite(account, line);
    format(line, sizeof(line), "weekly_work_score=%d\r\n", PlayerInfo[playerid][pWeeklyWorkScore]); fwrite(account, line);
    format(line, sizeof(line), "weekly_business_score=%d\r\n", PlayerInfo[playerid][pWeeklyBusinessScore]); fwrite(account, line);
    format(line, sizeof(line), "weekly_police_score=%d\r\n", PlayerInfo[playerid][pWeeklyPoliceScore]); fwrite(account, line);
    format(line, sizeof(line), "weekly_citizen_score=%d\r\n", PlayerInfo[playerid][pWeeklyCitizenScore]); fwrite(account, line);
    format(line, sizeof(line), "business_stock=%d\r\n", PlayerInfo[playerid][pBusinessStock]); fwrite(account, line);
    format(line, sizeof(line), "business_contracts=%d\r\n", PlayerInfo[playerid][pBusinessContracts]); fwrite(account, line);
    format(line, sizeof(line), "business_debt=%d\r\n", PlayerInfo[playerid][pBusinessDebt]); fwrite(account, line);
    format(line, sizeof(line), "business_recovery_day=%d\r\n", PlayerInfo[playerid][pBusinessRecoveryDay]); fwrite(account, line);
    format(line, sizeof(line), "business_bankrupt=%d\r\n", PlayerInfo[playerid][pBusinessBankrupt]); fwrite(account, line);
    format(line, sizeof(line), "vehicle_inspection_day=%d\r\n", PlayerInfo[playerid][pVehicleInspectionDay]); fwrite(account, line);
    format(line, sizeof(line), "medical_shifts=%d\r\n", PlayerInfo[playerid][pMedicalShifts]); fwrite(account, line);
    format(line, sizeof(line), "police_warrants=%d\r\n", PlayerInfo[playerid][pPoliceWarrants]); fwrite(account, line);
    format(line, sizeof(line), "police_evidence=%d\r\n", PlayerInfo[playerid][pPoliceEvidence]); fwrite(account, line);
    format(line, sizeof(line), "justice_active_warrants=%d\r\n", PlayerInfo[playerid][pJusticeActiveWarrants]); fwrite(account, line);
    format(line, sizeof(line), "justice_active_evidence=%d\r\n", PlayerInfo[playerid][pJusticeActiveEvidence]); fwrite(account, line);
    format(line, sizeof(line), "ankle_monitor=%d\r\n", PlayerInfo[playerid][pAnkleMonitor]); fwrite(account, line);
    format(line, sizeof(line), "contract_limit_day=%d\r\n", PlayerInfo[playerid][pContractLimitDay]); fwrite(account, line);
    format(line, sizeof(line), "contracts_today=%d\r\n", PlayerInfo[playerid][pContractsToday]); fwrite(account, line);
    format(line, sizeof(line), "logistics_completed=%d\r\n", PlayerInfo[playerid][pLogisticsCompleted]); fwrite(account, line);
    format(line, sizeof(line), "logistics_canceled=%d\r\n", PlayerInfo[playerid][pLogisticsCanceled]); fwrite(account, line);
    format(line, sizeof(line), "logistics_late=%d\r\n", PlayerInfo[playerid][pLogisticsLate]); fwrite(account, line);
    format(line, sizeof(line), "logistics_reputation=%d\r\n", PlayerInfo[playerid][pLogisticsReputation]); fwrite(account, line);
    format(line, sizeof(line), "logistics_earnings=%d\r\n", PlayerInfo[playerid][pLogisticsEarnings]); fwrite(account, line);
    format(line, sizeof(line), "logistics_generated=%d\r\n", PlayerInfo[playerid][pLogisticsGenerated]); fwrite(account, line);
    format(line, sizeof(line), "auto_business_id=%d\r\n", PlayerInfo[playerid][pAutoBusinessId]); fwrite(account, line);
    format(line, sizeof(line), "auto_business_profit=%d\r\n", PlayerInfo[playerid][pAutoBusinessProfit]); fwrite(account, line);
    format(line, sizeof(line), "auto_business_revenue=%d\r\n", PlayerInfo[playerid][pAutoBusinessRevenue]); fwrite(account, line);
    format(line, sizeof(line), "onboarding_rewarded=%d\r\n", PlayerInfo[playerid][pOnboardingRewarded]); fwrite(account, line);
    format(line, sizeof(line), "warzone_day=%d\r\n", PlayerInfo[playerid][pWarZoneDay]); fwrite(account, line);
    format(line, sizeof(line), "warzone_kills_today=%d\r\n", PlayerInfo[playerid][pWarZoneKillsToday]); fwrite(account, line);
    format(line, sizeof(line), "crime_faction=%d\r\n", PlayerInfo[playerid][pCrimeFaction]); fwrite(account, line);
    format(line, sizeof(line), "crime_rank=%d\r\n", PlayerInfo[playerid][pCrimeRank]); fwrite(account, line);
    format(line, sizeof(line), "crime_respect=%d\r\n", PlayerInfo[playerid][pCrimeRespect]); fwrite(account, line);
    format(line, sizeof(line), "crime_mission_cooldown=%d\r\n", PlayerInfo[playerid][pCrimeMissionCooldown]); fwrite(account, line);
    format(line, sizeof(line), "crime_hourly_stamp=%d\r\n", PlayerInfo[playerid][pCrimeHourlyStamp]); fwrite(account, line);
    format(line, sizeof(line), "crime_hourly_gain=%d\r\n", PlayerInfo[playerid][pCrimeHourlyGain]); fwrite(account, line);
    format(line, sizeof(line), "house=%d\r\n", PlayerInfo[playerid][pHouse]); fwrite(account, line);
    format(line, sizeof(line), "rented_house=%d\r\n", PlayerInfo[playerid][pRentedHouse]); fwrite(account, line);
    format(line, sizeof(line), "hunger=%d\r\n", PlayerInfo[playerid][pHunger]); fwrite(account, line);
    format(line, sizeof(line), "thirst=%d\r\n", PlayerInfo[playerid][pThirst]); fwrite(account, line);
    format(line, sizeof(line), "fatigue=%d\r\n", PlayerInfo[playerid][pFatigue]); fwrite(account, line);
    format(line, sizeof(line), "sleep=%d\r\n", PlayerInfo[playerid][pSleep]); fwrite(account, line);
    format(line, sizeof(line), "pantry_food=%d\r\n", PlayerInfo[playerid][pPantryFood]); fwrite(account, line);
    format(line, sizeof(line), "pantry_drink=%d\r\n", PlayerInfo[playerid][pPantryDrink]); fwrite(account, line);
    SaveInventoryData(playerid, account);
    SaveJobProgressData(playerid, account);
    format(line, sizeof(line), "logged=%d\r\n", PlayerInfo[playerid][pLogged]); fwrite(account, line);
    fclose(account);

    if (!Account_ValidateSavedFile(tempPath))
    {
        format(detail, sizeof(detail), "temp_invalid path=%s", tempPath);
        WritePlayerLog(LOG_ADMIN_FILE, "SAVE_FAIL", playerid, detail);
        fremove(tempPath);
        return 0;
    }

    if (fexist(path))
    {
        Account_CopyFile(path, backupPath);
    }

    if (!Account_CopyFile(tempPath, path) || !Account_ValidateSavedFile(path))
    {
        format(detail, sizeof(detail), "replace_failed path=%s backup=%s", path, backupPath);
        WritePlayerLog(LOG_ADMIN_FILE, "SAVE_FAIL", playerid, detail);
        if (fexist(backupPath))
        {
            Account_CopyFile(backupPath, path);
        }
        fremove(tempPath);
        return 0;
    }

    fremove(tempPath);
    return 1;
}

stock SaveAllLoggedAccounts()
{
    new playerid;
    new saved;
    new maxPlayers = GetMaxPlayers();

    for (playerid = 0; playerid < maxPlayers; playerid++)
    {
        if (IsPlayerConnected(playerid) && PlayerInfo[playerid][pLogged])
        {
            if (SaveAccountNow(playerid))
            {
                gAccountSaveDirty[playerid] = 0;
                saved++;
            }
        }
    }

    return saved;
}

public AutoSaveAccounts()
{
    new dirtySaved;
    new fullSaved;
    new message[96];

    dirtySaved = FlushAccountSaves(1);
    fullSaved = SaveAllLoggedAccounts();

    if (dirtySaved > 0 || fullSaved > 0)
    {
        format(message, sizeof(message), "[AutoSave] %d pendente(s), %d conta(s) online salva(s).", dirtySaved, fullSaved);
        print(message);
    }
    return 1;
}

stock CreateAccount(playerid, password[])
{
    new selectedSkin = PlayerInfo[playerid][pSkin];
    new saved;
    new name[MAX_PLAYER_NAME + 1];

    GetPlayerNameEx(playerid, name, sizeof(name));
    if (Account_NameIsReserved(name))
    {
        return 0;
    }

    SetDefaultPlayerInfo(playerid);
    PlayerInfo[playerid][pSkin] = selectedSkin;
    HashPlayerPassword(playerid, password, PlayerInfo[playerid][pPasswordHash], PASSWORD_HASH_SIZE);
    saved = SaveAccountData(playerid, 0);
    if (saved)
    {
        Ops_AddAccountName(playerid);
    }
    return saved;
}

stock VerifyAccountPassword(playerid, password[])
{
    new savedHash[PASSWORD_HASH_SIZE];
    new typedHash[PASSWORD_HASH_SIZE];

    if (!LoadAccountHash(playerid, savedHash, sizeof(savedHash)))
    {
        return 0;
    }

    HashPlayerPassword(playerid, password, typedHash, sizeof(typedHash));
    return (strcmp(savedHash, typedHash, false) == 0);
}

stock Account_ClearPasswordChange(playerid)
{
    gPasswordChangeTick[playerid] = 0;
    gPasswordChangeMode[playerid] = 0;
    gPasswordChangeNewHash[playerid][0] = 0;
    return 1;
}

stock Account_IsPasswordStrong(playerid, password[])
{
    new name[MAX_PLAYER_NAME + 1];

    if (strlen(password) < PASSWORD_CHANGE_MIN_LENGTH)
    {
        return 0;
    }
    if (IsNumericString(password))
    {
        return 0;
    }

    GetPlayerNameEx(playerid, name, sizeof(name));
    if (strcmp(password, name, true) == 0)
    {
        return 0;
    }
    if (strcmp(password, PlayerInfo[playerid][pCharacterName], true) == 0)
    {
        return 0;
    }
    return 1;
}

stock Account_ShowPassCurrentDlg(playerid)
{
    Account_ClearPasswordChange(playerid);
    ShowPlayerDialog(
        playerid,
        DIALOG_CHANGE_PASS_CURRENT,
        DIALOG_STYLE_PASSWORD,
        "Trocar senha - confirmacao",
        "Digite sua senha atual para confirmar que a conta e sua.",
        "Continuar",
        "Cancelar"
    );
    return 1;
}

stock Account_ShowLoginPassChangeDlg(playerid)
{
    Account_ClearPasswordChange(playerid);
    gPasswordChangeMode[playerid] = 1;
    ShowPlayerDialog(
        playerid,
        DIALOG_CHANGE_PASS_CURRENT,
        DIALOG_STYLE_PASSWORD,
        "Login - trocar senha",
        "Digite sua senha atual para continuar a troca de senha.",
        "Continuar",
        "Voltar"
    );
    return 1;
}

stock Account_ShowPassNewDlg(playerid)
{
    ShowPlayerDialog(
        playerid,
        DIALOG_CHANGE_PASS_NEW,
        DIALOG_STYLE_PASSWORD,
        "Trocar senha - nova senha",
        "Digite a nova senha.\n\nRegras: minimo 6 caracteres, nao pode ser so numeros e nao pode ser igual ao seu nome.",
        "Continuar",
        "Cancelar"
    );
    return 1;
}

stock Account_ShowPassConfirmDlg(playerid)
{
    ShowPlayerDialog(
        playerid,
        DIALOG_CHANGE_PASS_CONFIRM,
        DIALOG_STYLE_PASSWORD,
        "Trocar senha - confirmar",
        "Digite a nova senha novamente para confirmar.",
        "Salvar",
        "Cancelar"
    );
    return 1;
}

stock Account_HandlePassChangeDlg(playerid, dialogid, response, inputtext[])
{
    new typedHash[PASSWORD_HASH_SIZE];
    new mode = gPasswordChangeMode[playerid];

    if (!PlayerInfo[playerid][pLogged] && mode != 1)
    {
        Account_ClearPasswordChange(playerid);
        return 1;
    }

    if (!response)
    {
        Account_ClearPasswordChange(playerid);
        SendClientMessage(playerid, COLOR_GRAY, "Troca de senha cancelada.");
        if (mode == 1 && !PlayerInfo[playerid][pLogged])
        {
            return ShowAuthDialog(playerid);
        }
        return 1;
    }

    if (dialogid == DIALOG_CHANGE_PASS_CURRENT)
    {
        if (!VerifyAccountPassword(playerid, inputtext))
        {
            Account_ClearPasswordChange(playerid);
            SendClientMessage(playerid, COLOR_RED, "Senha atual incorreta. Troca cancelada.");
            WritePlayerLog(LOG_ADMIN_FILE, "PASSWORD_CHANGE_FAIL", playerid, "current_password_invalid");
            if (mode == 1)
            {
                ShowAuthDialog(playerid);
            }
            return 1;
        }

        gPasswordChangeTick[playerid] = GetTickCount();
        gPasswordChangeMode[playerid] = mode;
        Account_ShowPassNewDlg(playerid);
        return 1;
    }

    if (!gPasswordChangeTick[playerid] || (GetTickCount() - gPasswordChangeTick[playerid]) > 120000)
    {
        Account_ClearPasswordChange(playerid);
        SendClientMessage(playerid, COLOR_RED, "Confirmacao de senha expirou. Use /trocarsenha novamente.");
        if (mode == 1 && !PlayerInfo[playerid][pLogged])
        {
            ShowAuthDialog(playerid);
        }
        return 1;
    }

    if (dialogid == DIALOG_CHANGE_PASS_NEW)
    {
        if (!Account_IsPasswordStrong(playerid, inputtext))
        {
            SendClientMessage(playerid, COLOR_RED, "Senha fraca: use 6+ caracteres, misture letras/numeros e evite seu nome.");
            return Account_ShowPassNewDlg(playerid);
        }

        HashPlayerPassword(playerid, inputtext, typedHash, sizeof(typedHash));
        if (strcmp(typedHash, PlayerInfo[playerid][pPasswordHash], false) == 0)
        {
            SendClientMessage(playerid, COLOR_RED, "A nova senha nao pode ser igual a senha atual.");
            return Account_ShowPassNewDlg(playerid);
        }

        format(gPasswordChangeNewHash[playerid], PASSWORD_HASH_SIZE, "%s", typedHash);
        Account_ShowPassConfirmDlg(playerid);
        return 1;
    }

    if (dialogid == DIALOG_CHANGE_PASS_CONFIRM)
    {
        HashPlayerPassword(playerid, inputtext, typedHash, sizeof(typedHash));
        if (strcmp(typedHash, gPasswordChangeNewHash[playerid], false) != 0)
        {
            Account_ClearPasswordChange(playerid);
            SendClientMessage(playerid, COLOR_RED, "Confirmacao diferente. Troca cancelada por seguranca.");
            if (mode == 1)
            {
                ShowAuthDialog(playerid);
            }
            return 1;
        }

        if (mode == 1 && !LoadAccount(playerid))
        {
            Account_ClearPasswordChange(playerid);
            SendClientMessage(playerid, COLOR_RED, "Nao foi possivel carregar a conta para trocar a senha.");
            ShowAuthDialog(playerid);
            return 1;
        }

        format(PlayerInfo[playerid][pPasswordHash], PASSWORD_HASH_SIZE, "%s", typedHash);
        Account_ClearPasswordChange(playerid);
        if (mode == 1)
        {
            PlayerInfo[playerid][pLogged] = 0;
        }
        SaveAccountNow(playerid, 0);
        WritePlayerLog(LOG_ADMIN_FILE, "PASSWORD_CHANGE", playerid, "changed=1");
        SendClientMessage(playerid, COLOR_GREEN, "Senha alterada com seguranca.");
        if (mode == 1)
        {
            ShowAuthDialog(playerid);
        }
        return 1;
    }
    return 0;
}

stock Account_IsValidLoginName(name[])
{
    new index;
    new length = strlen(name);

    if (length < 3 || length > MAX_PLAYER_NAME)
    {
        return 0;
    }
    while (index < length)
    {
        if ((name[index] >= 'A' && name[index] <= 'Z')
            || (name[index] >= 'a' && name[index] <= 'z')
            || (name[index] >= '0' && name[index] <= '9')
            || name[index] == '_')
        {
            index++;
            continue;
        }
        return 0;
    }
    return 1;
}

stock Account_ShowRenameNameDlg(playerid)
{
    ShowPlayerDialog(
        playerid,
        DIALOG_RENAME_ACCOUNT_NAME,
        DIALOG_STYLE_INPUT,
        "Trocar nome da conta",
        "Digite o novo nome de login.\n\nUse apenas letras, numeros e underline. Minimo 3 caracteres.",
        "Continuar",
        "Cancelar"
    );
    return 1;
}

stock Account_ShowRenamePassDlg(playerid)
{
    ShowPlayerDialog(
        playerid,
        DIALOG_RENAME_ACCOUNT_PASS,
        DIALOG_STYLE_PASSWORD,
        "Trocar nome - senha",
        "Digite sua senha atual para confirmar a troca do nome da conta.",
        "Alterar",
        "Cancelar"
    );
    return 1;
}

stock Account_HandleRenameNameDlg(playerid, response, inputtext[])
{
    new current[MAX_PLAYER_NAME + 1];

    if (!PlayerInfo[playerid][pLogged])
    {
        return 1;
    }
    if (!response)
    {
        gPendingAccountName[playerid][0] = 0;
        SendClientMessage(playerid, COLOR_GRAY, "Troca de nome cancelada.");
        return 1;
    }
    if (!Account_IsValidLoginName(inputtext))
    {
        SendClientMessage(playerid, COLOR_RED, "Nome invalido. Use 3-24 caracteres: letras, numeros e underline.");
        return Account_ShowRenameNameDlg(playerid);
    }

    Account_GetCanonicalName(playerid, current, sizeof(current));
    if (strcmp(inputtext, current, true) == 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Este ja e o nome atual da sua conta.");
        return 1;
    }
    if (Account_NameIsReserved(inputtext))
    {
        SendClientMessage(playerid, COLOR_RED, "Este nome ja esta reservado por uma conta ou alias antigo.");
        return Account_ShowRenameNameDlg(playerid);
    }

    format(gPendingAccountName[playerid], sizeof(gPendingAccountName[]), "%s", inputtext);
    return Account_ShowRenamePassDlg(playerid);
}

stock Account_HandleRenamePassDlg(playerid, response, inputtext[])
{
    new newName[MAX_PLAYER_NAME + 1];
    new logLine[144];
    new adminid;
    new maxPlayers = GetMaxPlayers();

    if (!PlayerInfo[playerid][pLogged])
    {
        return 1;
    }
    if (!response)
    {
        gPendingAccountName[playerid][0] = 0;
        SendClientMessage(playerid, COLOR_GRAY, "Troca de nome cancelada.");
        return 1;
    }
    if (!gPendingAccountName[playerid][0])
    {
        SendClientMessage(playerid, COLOR_RED, "Pedido de troca expirou. Use /trocarnome novamente.");
        return 1;
    }
    if (!VerifyAccountPassword(playerid, inputtext))
    {
        gPendingAccountName[playerid][0] = 0;
        SendClientMessage(playerid, COLOR_RED, "Senha incorreta. Troca de nome cancelada.");
        WritePlayerLog(LOG_ADMIN_FILE, "ACCOUNT_RENAME_FAIL", playerid, "password_invalid");
        return 1;
    }

    format(newName, sizeof(newName), "%s", gPendingAccountName[playerid]);
    if (Account_NameIsReserved(newName))
    {
        gPendingAccountName[playerid][0] = 0;
        gPendingAccountNameTick[playerid] = 0;
        SendClientMessage(playerid, COLOR_RED, "Este nome ficou indisponivel. Tente outro.");
        return 1;
    }

    gPendingAccountNameTick[playerid] = GetTickCount();
    HashPasswordWithName(newName, inputtext, gPendingAccountNameHash[playerid], PASSWORD_HASH_SIZE);
    format(logLine, sizeof(logLine), "requested_new=%s", newName);
    WritePlayerLog(LOG_ADMIN_FILE, "ACCOUNT_RENAME_REQUEST", playerid, logLine);
    format(logLine, sizeof(logLine), "Solicitacao de troca de nome: ID %d -> %s. Use /autorizarnome %d ou /negarnome %d.", playerid, newName, playerid, playerid);

    for (adminid = 0; adminid < maxPlayers; adminid++)
    {
        if (IsPlayerConnected(adminid) && PlayerInfo[adminid][pLogged] && HasAdminLevel(adminid, ADMIN_LEVEL_ADMIN))
        {
            SendClientMessage(adminid, COLOR_ORANGE, logLine);
        }
    }

    SendClientMessage(playerid, COLOR_GREEN, "Solicitacao enviada. Um admin nivel 4+ precisa autorizar a troca do nome.");
    return 1;
}

stock Account_ApproveRename(playerid, adminid)
{
    new oldName[MAX_PLAYER_NAME + 1];
    new newName[MAX_PLAYER_NAME + 1];
    new oldPath[ACCOUNT_PATH_SIZE];
    new logLine[160];

    if (!IsValidConnectedPlayer(playerid) || !PlayerInfo[playerid][pLogged])
    {
        SendClientMessage(adminid, COLOR_RED, "Jogador invalido ou offline.");
        return 1;
    }
    if (!gPendingAccountName[playerid][0])
    {
        SendClientMessage(adminid, COLOR_RED, "Este jogador nao possui troca de nome pendente.");
        return 1;
    }
    if (strlen(gPendingAccountNameHash[playerid]) != 64)
    {
        gPendingAccountName[playerid][0] = 0;
        gPendingAccountNameHash[playerid][0] = 0;
        gPendingAccountNameTick[playerid] = 0;
        SendClientMessage(adminid, COLOR_RED, "Solicitacao sem confirmacao de senha valida.");
        SendClientMessage(playerid, COLOR_RED, "Sua solicitacao perdeu a confirmacao de senha. Envie novamente.");
        return 1;
    }
    if (!gPendingAccountNameTick[playerid] || (GetTickCount() - gPendingAccountNameTick[playerid]) > 900000)
    {
        gPendingAccountName[playerid][0] = 0;
        gPendingAccountNameHash[playerid][0] = 0;
        gPendingAccountNameTick[playerid] = 0;
        SendClientMessage(adminid, COLOR_RED, "Solicitacao de troca de nome expirada.");
        SendClientMessage(playerid, COLOR_RED, "Sua solicitacao de troca de nome expirou. Envie novamente se ainda quiser trocar.");
        return 1;
    }

    Account_GetCanonicalName(playerid, oldName, sizeof(oldName));
    format(newName, sizeof(newName), "%s", gPendingAccountName[playerid]);
    if (Account_NameIsReserved(newName))
    {
        gPendingAccountName[playerid][0] = 0;
        gPendingAccountNameHash[playerid][0] = 0;
        gPendingAccountNameTick[playerid] = 0;
        SendClientMessage(adminid, COLOR_RED, "Nome solicitado ficou indisponivel.");
        SendClientMessage(playerid, COLOR_RED, "O nome solicitado ficou indisponivel. Solicite outro.");
        return 1;
    }
    if (SetPlayerName(playerid, newName) <= 0)
    {
        SendClientMessage(adminid, COLOR_RED, "Nao foi possivel aplicar este nome agora.");
        return 1;
    }

    Account_FormatPathForName(oldName, oldPath, sizeof(oldPath));
    if (!Account_AddAlias(oldName, newName))
    {
        SetPlayerName(playerid, oldName);
        SendClientMessage(adminid, COLOR_RED, "Nao foi possivel salvar o alias da conta. Troca cancelada.");
        SendClientMessage(playerid, COLOR_RED, "Troca de nome cancelada: falha ao salvar alias da conta.");
        return 1;
    }
    format(PlayerInfo[playerid][pPasswordHash], PASSWORD_HASH_SIZE, "%s", gPendingAccountNameHash[playerid]);
    format(gAccountCanonicalName[playerid], sizeof(gAccountCanonicalName[]), "%s", newName);
    gPendingAccountName[playerid][0] = 0;
    gPendingAccountNameHash[playerid][0] = 0;
    gPendingAccountNameTick[playerid] = 0;

    SaveAccountNow(playerid, 0);
    Ops_AddAccountName(playerid);
    if (fexist(oldPath))
    {
        fremove(oldPath);
    }

    format(logLine, sizeof(logLine), "old=%s new=%s", oldName, newName);
    WritePlayerLog(LOG_ADMIN_FILE, "ACCOUNT_RENAME", playerid, logLine);
    WritePlayerLog(LOG_ADMIN_FILE, "ACCOUNT_RENAME_APPROVE", adminid, logLine);
    SendClientMessage(playerid, COLOR_GREEN, "Troca de nome aprovada. O nome antigo agora redireciona para o novo.");
    SendClientMessage(adminid, COLOR_GREEN, "Troca de nome aprovada com sucesso.");
    return 1;
}

stock Account_DenyRename(playerid, adminid)
{
    new logLine[128];

    if (!IsValidConnectedPlayer(playerid) || !PlayerInfo[playerid][pLogged])
    {
        SendClientMessage(adminid, COLOR_RED, "Jogador invalido ou offline.");
        return 1;
    }
    if (!gPendingAccountName[playerid][0])
    {
        SendClientMessage(adminid, COLOR_RED, "Este jogador nao possui troca de nome pendente.");
        return 1;
    }

    format(logLine, sizeof(logLine), "denied_new=%s", gPendingAccountName[playerid]);
    WritePlayerLog(LOG_ADMIN_FILE, "ACCOUNT_RENAME_DENY", adminid, logLine);
    gPendingAccountName[playerid][0] = 0;
    gPendingAccountNameHash[playerid][0] = 0;
    gPendingAccountNameTick[playerid] = 0;
    SendClientMessage(playerid, COLOR_RED, "Sua troca de nome foi negada pela administracao.");
    SendClientMessage(adminid, COLOR_GREEN, "Troca de nome negada.");
    return 1;
}

stock HasAdminLevel(playerid, level)
{
    return (PlayerInfo[playerid][pAdminLevel] >= level);
}

stock IsAdminOwnerLevel(playerid)
{
    return (PlayerInfo[playerid][pAdminLevel] >= ADMIN_LEVEL_OWNER);
}

stock Account_GetRankNameByLevel(level, output[], size = sizeof(output))
{
    if (level <= 2)
    {
        format(output, size, "Recem chegado");
        return 1;
    }
    if (level <= 5)
    {
        format(output, size, "Novato");
        return 1;
    }
    if (level <= 10)
    {
        format(output, size, "Aprendiz");
        return 1;
    }
    if (level <= 20)
    {
        format(output, size, "Morador");
        return 1;
    }
    if (level <= 35)
    {
        format(output, size, "Experiente");
        return 1;
    }
    if (level <= 50)
    {
        format(output, size, "Veterano");
        return 1;
    }
    format(output, size, "Lenda da cidade");
    return 1;
}

stock Account_GetPlayerRankName(playerid, output[], size = sizeof(output))
{
    return Account_GetRankNameByLevel(PlayerInfo[playerid][pLevel], output, size);
}

stock Account_IsNewcomerProtected(playerid)
{
    return (IsValidConnectedPlayer(playerid) && PlayerInfo[playerid][pLogged] && PlayerInfo[playerid][pLevel] <= 2);
}

stock Account_ApplyNewcomerProtection(playerid)
{
    if (!Account_IsNewcomerProtected(playerid))
    {
        return 0;
    }

    PlayerInfo[playerid][pWanted] = 0;
    PlayerInfo[playerid][pJailTime] = 0;
    PlayerInfo[playerid][pJailCrimeId] = 0;
    PlayerInfo[playerid][pAdminJail] = 0;
    PlayerInfo[playerid][pFines] = 0;
    PlayerInfo[playerid][pTrafficPoints] = 0;
    return 1;
}

stock GetAdminLevelName(level, output[], size = sizeof(output))
{
    switch (level)
    {
        case 0:
        {
            format(output, size, "Jogador");
        }
        case ADMIN_LEVEL_HELPER:
        {
            format(output, size, "Helper Nivel 1");
        }
        case ADMIN_LEVEL_GAME:
        {
            format(output, size, "Helper Nivel 2");
        }
        case ADMIN_LEVEL_MANAGER:
        {
            format(output, size, "Administrador Nivel 1");
        }
        case ADMIN_LEVEL_ADMIN:
        {
            format(output, size, "Administrador Nivel 2");
        }
        case ADMIN_LEVEL_OWNER:
        {
            format(output, size, "DONO");
        }
        default:
        {
            format(output, size, "Nivel invalido");
        }
    }
    return 1;
}

stock GetPlayerAdminRankName(playerid, output[], size = sizeof(output))
{
    return GetAdminLevelName(PlayerInfo[playerid][pAdminLevel], output, size);
}

stock SendNoPermission(playerid)
{
    SendClientMessage(playerid, COLOR_RED, "Voce nao tem permissao para usar este comando.");
    return 1;
}

stock ShowAuthDialog(playerid)
{
    new path[ACCOUNT_PATH_SIZE];
    new name[MAX_PLAYER_NAME + 1];
    new title[64];
    new message[256];

    Account_GetCanonicalName(playerid, name, sizeof(name));
    GetPlayerAccountPath(playerid, path, sizeof(path));

    if (fexist(path))
    {
        format(title, sizeof(title), "Login - %s", name);
        format(message, sizeof(message), "Entrar\nTrocar senha\nSair");
        gPlayerAuthDialog[playerid] = DIALOG_LOGIN_MENU;
        ShowPlayerDialog(playerid, DIALOG_LOGIN_MENU, DIALOG_STYLE_LIST, title, message, "Selecionar", "");
    }
    else
    {
        GetPlayerNameEx(playerid, name, sizeof(name));
        if (Account_NameIsReserved(name))
        {
            SendClientMessage(playerid, COLOR_RED, "Este nome esta reservado por troca de conta. Use o nome novo para entrar.");
            Kick(playerid);
            return 1;
        }
        format(message, sizeof(message), "Conta nova: %s\n\nDigite uma senha para cadastrar sua conta.", name);
        gPlayerAuthDialog[playerid] = DIALOG_REGISTER;
        ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Cadastro", message, "Cadastrar", "Sair");
    }
    return 1;
}

stock ShowLoginPasswordDialog(playerid)
{
    new name[MAX_PLAYER_NAME + 1];
    new message[192];

    Account_GetCanonicalName(playerid, name, sizeof(name));
    format(message, sizeof(message), "Conta encontrada: %s\n\nDigite sua senha para entrar.", name);
    gPlayerAuthDialog[playerid] = DIALOG_LOGIN;
    ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Login", message, "Entrar", "Voltar");
    return 1;
}

stock ShowCharacterNameDialog(playerid)
{
    ShowPlayerDialog(
        playerid,
        DIALOG_RP_NAME,
        DIALOG_STYLE_INPUT,
        "Identidade RP",
        "Digite o nome do seu personagem no formato Nome_Sobrenome.\n\nExemplo: Lucas_Santos",
        "Confirmar",
        ""
    );
    return 1;
}

stock HandleCharacterNameDialog(playerid, response, inputtext[])
{
    if (!PlayerInfo[playerid][pLogged])
    {
        return 1;
    }

    if (!response || !IsValidCharacterName(inputtext))
    {
        SendClientMessage(playerid, COLOR_RED, "Nome invalido. Use o formato Nome_Sobrenome, apenas letras.");
        ShowCharacterNameDialog(playerid);
        return 1;
    }

    format(PlayerInfo[playerid][pCharacterName], CHARACTER_NAME_SIZE, "%s", inputtext);
    SaveAccountData(playerid, 0);
    SendClientMessage(playerid, COLOR_GREEN, "Identidade RP criada com sucesso.");
    SpawnPlayer(playerid);
    return 1;
}

stock FinishPlayerAuth(playerid)
{
    PlayerInfo[playerid][pLogged] = 1;
    PlayerInfo[playerid][pSessionTick] = GetTickCount();
    PlayerInfo[playerid][pExperienceTick] = GetTickCount();
    gPlayerAuthDialog[playerid] = 0;
    gPlayerLoginTries[playerid] = 0;
    Vip_OnPlayerAuth(playerid);
    Life_OnPlayerAuth(playerid);

    SetSpawnInfo(playerid, NO_TEAM, PlayerInfo[playerid][pSkin], gServerLocations[LOCATION_SPAWN][locX], gServerLocations[LOCATION_SPAWN][locY], gServerLocations[LOCATION_SPAWN][locZ], gServerLocations[LOCATION_SPAWN][locA], 0, 0, 0, 0, 0, 0);
    SendWelcomeMessages(playerid);

    if (!IsValidCharacterName(PlayerInfo[playerid][pCharacterName]))
    {
        ShowCharacterNameDialog(playerid);
        return 1;
    }

    SpawnPlayer(playerid);
    return 1;
}

stock SetupPlayerForSpawn(playerid)
{
    SetPlayerToLocation(playerid, LOCATION_SPAWN);

    ResetPlayerWeapons(playerid);
    ResetPlayerMoney(playerid);
    GivePlayerMoney(playerid, PlayerInfo[playerid][pMoney]);
    SetPlayerSkin(playerid, PlayerInfo[playerid][pSkin]);
    SetPlayerHealth(playerid, 100.0);
    SetPlayerArmour(playerid, 0.0);
    TogglePlayerClock(playerid, 0);

    PlayerInfo[playerid][pLastSpawn] = LOCATION_SPAWN;
    PlayerInfo[playerid][pSpawnCount]++;
    return 1;
}

stock SendPlayerStatsMessage(playerid)
{
    new message[128];
    new jobLabel[32];
    new docsText[8];
    new adminRank[32];
    new vipName[24];
    new vipRemaining[48];
    new minutes;

    UpdatePlayerLiveData(playerid);
    GetJobName(PlayerInfo[playerid][pJob], jobLabel, sizeof(jobLabel));
    GetPlayerAdminRankName(playerid, adminRank, sizeof(adminRank));
    Vip_GetPlayerName(playerid, vipName, sizeof(vipName));
    Vip_FormatRemaining(playerid, vipRemaining, sizeof(vipRemaining));
    if (PlayerInfo[playerid][pDocuments])
    {
        format(docsText, sizeof(docsText), "sim");
    }
    else
    {
        format(docsText, sizeof(docsText), "nao");
    }
    minutes = PlayerInfo[playerid][pOnlineTime] / 60;

    format(message, sizeof(message), "ID: %d | Admin: %s (%d) | Dinheiro: $%d | Skin: %d", playerid, adminRank, PlayerInfo[playerid][pAdminLevel], PlayerInfo[playerid][pMoney], PlayerInfo[playerid][pSkin]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "VIP: %s | Validade: %s", vipName, vipRemaining);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Kills: %d | Mortes: %d | Spawns: %d | Tempo online: %d min", PlayerInfo[playerid][pKills], PlayerInfo[playerid][pDeaths], PlayerInfo[playerid][pSpawnCount], minutes);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Nivel geral: %d | XP geral: %d/%d", PlayerInfo[playerid][pLevel], PlayerInfo[playerid][pExperience], gCfgCharacterXpPerLevel);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Fome: %d%% | Sede: %d%%", PlayerInfo[playerid][pHunger], PlayerInfo[playerid][pThirst]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Cansaco: %d%% | Sono: %d%%", PlayerInfo[playerid][pFatigue], PlayerInfo[playerid][pSleep]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Emprego: %s | Nivel: %d | XP: %d", jobLabel, Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob]), Job_GetPlayerXP(playerid, PlayerInfo[playerid][pJob]));
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Documentos: %s | CNH: %d | Pesada: %d | Medico: %d | OAB: %d", docsText, PlayerInfo[playerid][pLicenseCNH], PlayerInfo[playerid][pLicenseHeavy], PlayerInfo[playerid][pLicenseMedical], PlayerInfo[playerid][pLicenseOAB]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}

stock SendPlayerPositionMessage(playerid)
{
    new message[144];
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:angle;

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, angle);
    format(message, sizeof(message), "Posicao: %.4f, %.4f, %.4f | Angulo: %.4f", x, y, z, angle);
    SendClientMessage(playerid, COLOR_YELLOW, message);
    return 1;
}

stock SendPlayerAccountMessage(playerid)
{
    new message[144];
    new name[MAX_PLAYER_NAME + 1];
    new jobLabel[32];
    new vehicleName[32];
    new docsText[8];
    new adminRank[32];
    new vipName[24];
    new vipRemaining[48];
    new minutes;

    UpdatePlayerLiveData(playerid);
    GetPlayerNameEx(playerid, name, sizeof(name));
    GetJobName(PlayerInfo[playerid][pJob], jobLabel, sizeof(jobLabel));
    GetPlayerAdminRankName(playerid, adminRank, sizeof(adminRank));
    Vip_GetPlayerName(playerid, vipName, sizeof(vipName));
    Vip_FormatRemaining(playerid, vipRemaining, sizeof(vipRemaining));
    if (PlayerInfo[playerid][pDocuments])
    {
        format(docsText, sizeof(docsText), "sim");
    }
    else
    {
        format(docsText, sizeof(docsText), "nao");
    }

    if (PlayerInfo[playerid][pVehicleModel] >= 400 && PlayerInfo[playerid][pVehicleModel] <= 611)
    {
        GetDealerVehicleNameByModel(PlayerInfo[playerid][pVehicleModel], vehicleName, sizeof(vehicleName));
    }
    else
    {
        format(vehicleName, sizeof(vehicleName), "Nenhum");
    }

    minutes = PlayerInfo[playerid][pOnlineTime] / 60;

    format(message, sizeof(message), "Conta: %s | Personagem: %s | Admin: %s (%d)", name, PlayerInfo[playerid][pCharacterName], adminRank, PlayerInfo[playerid][pAdminLevel]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "VIP: %s | Validade: %s | Dias comprados: %d", vipName, vipRemaining, PlayerInfo[playerid][pVipTotalDays]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Dinheiro: $%d | Skin: %d | Kills: %d | Mortes: %d", PlayerInfo[playerid][pMoney], PlayerInfo[playerid][pSkin], PlayerInfo[playerid][pKills], PlayerInfo[playerid][pDeaths]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Spawns: %d | Tempo online: %d min | Nivel: %d | XP: %d/%d", PlayerInfo[playerid][pSpawnCount], minutes, PlayerInfo[playerid][pLevel], PlayerInfo[playerid][pExperience], gCfgCharacterXpPerLevel);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Fome: %d%% | Sede: %d%%", PlayerInfo[playerid][pHunger], PlayerInfo[playerid][pThirst]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Cansaco: %d%% | Sono: %d%%", PlayerInfo[playerid][pFatigue], PlayerInfo[playerid][pSleep]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Documentos: %s", docsText);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Banco: %s | Saldo: $%d | Cartao virtual: %s | Emprestimo: $%d", PlayerInfo[playerid][pBankAccount] ? ("aberta") : ("fechada"), PlayerInfo[playerid][pBankMoney], PlayerInfo[playerid][pBankCard] ? ("ativo") : ("nao"), PlayerInfo[playerid][pBankLoan]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Emprego: %s | Nivel: %d | XP: %d", jobLabel, Job_GetPlayerLevel(playerid, PlayerInfo[playerid][pJob]), Job_GetPlayerXP(playerid, PlayerInfo[playerid][pJob]));
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Veiculo: %s | Placa: %s | Seguro: %s | IPVA: $%d", vehicleName, PlayerInfo[playerid][pVehiclePlate], PlayerInfo[playerid][pVehicleInsurance] ? ("ativo") : ("nao"), PlayerInfo[playerid][pVehicleTaxDue]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Garagem: %s | Patio: %s | CNH: %d | Pesada: %d", PlayerInfo[playerid][pVehicleGarage] ? ("guardado") : ("fora"), PlayerInfo[playerid][pVehicleImpounded] ? ("sim") : ("nao"), PlayerInfo[playerid][pLicenseCNH], PlayerInfo[playerid][pLicenseHeavy]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}
