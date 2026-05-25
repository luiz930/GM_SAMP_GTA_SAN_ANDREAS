#if defined _nova_config_included
    #endinput
#endif
#define _nova_config_included

new gCfgStartingMoney = 500;
new gCfgPricePercent = 100;
new gCfgFinePercent = 100;
new gCfgJobPayPercent = 100;
new gCfgJobBonusPercent = 100;
new gCfgPropertyPricePercent = 100;
new gCfgVehiclePricePercent = 100;

new gCfgHudUpdateInterval = HUD_UPDATE_INTERVAL;
new gCfgHostnameInterval = HOSTNAME_UPDATE_INTERVAL;
new gCfgAutosaveInterval = AUTOSAVE_INTERVAL;
new gCfgCharacterXpInterval = CHARACTER_XP_INTERVAL;
new gCfgCharacterXpPerLevel = CHARACTER_XP_PER_LEVEL;

new gCfgNeedsUpdateInterval = NEEDS_UPDATE_INTERVAL;
new gCfgNeedsWarningInterval = NEEDS_WARNING_INTERVAL;
new gCfgNeedsMaxValue = NEEDS_MAX_VALUE;
new gCfgNeedsMinSafe = NEEDS_MIN_SAFE;
new gCfgNeedsLowValue = NEEDS_LOW_VALUE;
new gCfgNeedsCriticalValue = NEEDS_CRITICAL_VALUE;
new gCfgNeedsHungerLoss = NEEDS_HUNGER_LOSS;
new gCfgNeedsThirstLoss = NEEDS_THIRST_LOSS;
new Float:gCfgNeedsStarveDamage = NEEDS_STARVE_DAMAGE;

new gCfgFuelUpdateInterval = FUEL_UPDATE_INTERVAL;
new gCfgFuelLowValue = FUEL_LOW_VALUE;
new gCfgNpcRefuelPrice = FUEL_PRICE_GASOLINE;
new gCfgNpcRefuelMinCost = 50;
new gCfgFuelGasolinePrice = FUEL_PRICE_GASOLINE;
new gCfgFuelEthanolPrice = FUEL_PRICE_ETHANOL;
new gCfgFuelDieselPrice = FUEL_PRICE_DIESEL;
new gCfgFuelGlpPrice = FUEL_PRICE_GLP;

new gCfgBankTransferLimit = BANK_TRANSFER_LIMIT;
new gCfgBankOpenCost = BANK_OPEN_COST;
new gCfgBankCardCost = BANK_CARD_COST;
new gCfgBankLoanMin = BANK_LOAN_MIN;
new gCfgBankLoanInterest = BANK_LOAN_INTEREST_PERCENT;
new gCfgBankLoanMinScore = 350;
new gCfgBankScoreBase = 500;
new gCfgBankScoreFinePenalty = 1;
new gCfgBankScoreCriminalPenalty = 60;
new gCfgBankScoreGoodBonus = 45;
new gCfgBankScoreBadPenalty = 90;
new gCfgCitizenLicenseMinScore = 250;
new gCfgCitizenJobTrustedMinScore = 420;
new gCfgCitizenVehicleMinScore = 300;
new gCfgCitizenRentMinScore = 300;
new gCfgCitizenPropertyMinScore = 450;
new gCfgCitizenBusinessMinScore = 500;

new gCfgCityDocumentCost = 100;
new gCfgCityRenameCost = 500;
new gCfgLicenseCNHCost = 300;
new gCfgLicenseHeavyCost = 450;
new gCfgLicenseMedicalCost = 350;
new gCfgLicenseOABCost = 330;
new gCfgLicensePublicCost = 350;
new gCfgLicensePoliceCost = 350;
new gCfgDocumentValidDays = 365;
new gCfgLicenseValidDays = 180;

new gCfgHospitalTreatCost = 250;
new gCfgHospitalDeathCost = 500;
new gCfgHospitalPlanCost = 900;
new gCfgHospitalPlanTreatCost = 60;
new gCfgHospitalPlanDeathCost = 120;
new gCfgHealthPlanValidDays = 30;
new gCfgMedicineCost = 120;
new gCfgSurgeryCost = 1400;
new gCfgAmbulanceCost = 450;

new gCfgWorkTaskCooldown = 8000;
new gCfgWorkAbandonPenalty = 150;
new gCfgWorkFineLimit = 17608;
new gCfgJobXpPerTask = 100;
new gCfgJobXpCompleteBonus = 150;
new gCfgNpcRepairCost = 450;

new gCfgNpcTransportCost = NPC_TRANSPORT_COST;
new gCfgNpcTowCost = NPC_TOW_COST;
new gCfgPhoneRideCost = PHONE_RIDE_COST;
new gCfgPhoneDeliveryFee = PHONE_DELIVERY_FEE;

new gCfgVehicleGarageCost = VEHICLE_GARAGE_COST;
new gCfgVehicleImpoundCost = VEHICLE_IMPOUND_COST;
new gCfgVehicleInsuranceCost = VEHICLE_INSURANCE_COST;
new gCfgVehicleIpvaBase = VEHICLE_IPVA_BASE;
new gCfgVehicleIpvaPercent = VEHICLE_IPVA_PERCENT;
new gCfgVehicleRegisterCost = VEHICLE_DETRAN_REGISTER_COST;
new gCfgVehiclePlateCost = VEHICLE_DETRAN_PLATE_COST;
new gCfgVehicleTransferCost = VEHICLE_DETRAN_TRANSFER_COST;
new gCfgVehicleSellPercent = VEHICLE_SELL_PERCENT;

new gCfgRadarFineBase = RADAR_FINE_BASE;
new gCfgRadarFinePerKmh = RADAR_FINE_PER_KMH;
new gCfgTrafficFineLight = 88;
new gCfgTrafficFineMedium = 130;
new gCfgTrafficFineSerious = 195;
new gCfgTrafficFineVerySerious = 293;
new gCfgTrafficFineMax = 17608;

new gCfgMarketSellPay = 350;
new gCfgMarketDeliveryStock = 8;
new gCfgMarketLowStock = 10;

new gCfgJusticeReportCost = 80;
new gCfgJusticeHearingCost = 500;
new gCfgJusticeLawyerCost = 1500;
new gCfgJusticeSentenceBase = 1000;

new gCfgBusinessOpenCost = 2500;
new gCfgBusinessEmployeeCost = 900;
new gCfgBusinessSalaryCost = 1200;
new gCfgBusinessRevenue = 2500;
new gCfgBusinessTaxPercent = 12;
new gCfgBusinessPermitValidDays = 30;

new gCfgPropertyTaxPercent = 1;
new gCfgGovernmentMonthlyFee = 150;
new gCfgBillDueDays = 7;
new gCfgBillLateFeePercent = 5;
new gCfgDebtDirtyThreshold = 1500;
new gCfgDebtScorePenalty = 120;
new gCfgBillWaterCost = 90;
new gCfgBillElectricCost = 140;
new gCfgBillInternetCost = 110;
new gCfgBillRentExtraCost = 0;
new gCfgBillLoanPercent = 20;
new gCfgBillWaterOccupantExtra = 35;
new gCfgBillElectricOccupantExtra = 55;
new gCfgBillHydroDiscountPercent = 15;
new gCfgHomeSolarInstallCost = 12000;
new gCfgHomeSolarDiscountPercent = 60;
new gCfgSalaryPayTasks = 6;
new gCfgIncomeTaxPercent = 8;
new gCfgCartorioCpfCost = 80;
new gCfgCartorioRgCost = 80;
new gCfgCartorioCertCost = 120;
new gCfgCartorioFirmaCost = 200;
new gCfgCartorioNameCost = 900;
new gCfgContractRentCost = 250;
new gCfgContractFinanceCost = 600;
new gCfgContractWorkCost = 150;
new gCfgContractInsuranceCost = 350;
new gCfgContractCancelFine = 500;

new gCfgJobPay[JOB_MAX_ID + 1];
new gCfgJobBonus[JOB_MAX_ID + 1];

stock Cfg_ResetDefaults()
{
    new jobid;

    gCfgStartingMoney = 500;
    gCfgPricePercent = 100;
    gCfgFinePercent = 100;
    gCfgJobPayPercent = 100;
    gCfgJobBonusPercent = 100;
    gCfgPropertyPricePercent = 100;
    gCfgVehiclePricePercent = 100;

    gCfgHudUpdateInterval = HUD_UPDATE_INTERVAL;
    gCfgHostnameInterval = HOSTNAME_UPDATE_INTERVAL;
    gCfgAutosaveInterval = AUTOSAVE_INTERVAL;
    gCfgCharacterXpInterval = CHARACTER_XP_INTERVAL;
    gCfgCharacterXpPerLevel = CHARACTER_XP_PER_LEVEL;

    gCfgNeedsUpdateInterval = NEEDS_UPDATE_INTERVAL;
    gCfgNeedsWarningInterval = NEEDS_WARNING_INTERVAL;
    gCfgNeedsMaxValue = NEEDS_MAX_VALUE;
    gCfgNeedsMinSafe = NEEDS_MIN_SAFE;
    gCfgNeedsLowValue = NEEDS_LOW_VALUE;
    gCfgNeedsCriticalValue = NEEDS_CRITICAL_VALUE;
    gCfgNeedsHungerLoss = NEEDS_HUNGER_LOSS;
    gCfgNeedsThirstLoss = NEEDS_THIRST_LOSS;
    gCfgNeedsStarveDamage = NEEDS_STARVE_DAMAGE;

    gCfgFuelUpdateInterval = FUEL_UPDATE_INTERVAL;
    gCfgFuelLowValue = FUEL_LOW_VALUE;
    gCfgNpcRefuelPrice = FUEL_PRICE_GASOLINE;
    gCfgNpcRefuelMinCost = 50;
    gCfgFuelGasolinePrice = FUEL_PRICE_GASOLINE;
    gCfgFuelEthanolPrice = FUEL_PRICE_ETHANOL;
    gCfgFuelDieselPrice = FUEL_PRICE_DIESEL;
    gCfgFuelGlpPrice = FUEL_PRICE_GLP;

    gCfgBankTransferLimit = BANK_TRANSFER_LIMIT;
    gCfgBankOpenCost = BANK_OPEN_COST;
    gCfgBankCardCost = BANK_CARD_COST;
    gCfgBankLoanMin = BANK_LOAN_MIN;
    gCfgBankLoanInterest = BANK_LOAN_INTEREST_PERCENT;
    gCfgBankLoanMinScore = 350;
    gCfgBankScoreBase = 500;
    gCfgBankScoreFinePenalty = 1;
    gCfgBankScoreCriminalPenalty = 60;
    gCfgBankScoreGoodBonus = 45;
    gCfgBankScoreBadPenalty = 90;
    gCfgCitizenLicenseMinScore = 250;
    gCfgCitizenJobTrustedMinScore = 420;
    gCfgCitizenVehicleMinScore = 300;
    gCfgCitizenRentMinScore = 300;
    gCfgCitizenPropertyMinScore = 450;
    gCfgCitizenBusinessMinScore = 500;

    gCfgCityDocumentCost = 100;
    gCfgCityRenameCost = 500;
    gCfgLicenseCNHCost = 300;
    gCfgLicenseHeavyCost = 450;
    gCfgLicenseMedicalCost = 350;
    gCfgLicenseOABCost = 330;
    gCfgLicensePublicCost = 350;
    gCfgLicensePoliceCost = 350;
    gCfgDocumentValidDays = 365;
    gCfgLicenseValidDays = 180;

    gCfgHospitalTreatCost = 250;
    gCfgHospitalDeathCost = 500;
    gCfgHospitalPlanCost = 900;
    gCfgHospitalPlanTreatCost = 60;
    gCfgHospitalPlanDeathCost = 120;
    gCfgHealthPlanValidDays = 30;
    gCfgMedicineCost = 120;
    gCfgSurgeryCost = 1400;
    gCfgAmbulanceCost = 450;

    gCfgWorkTaskCooldown = 8000;
    gCfgWorkAbandonPenalty = 150;
    gCfgWorkFineLimit = 17608;
    gCfgJobXpPerTask = 100;
    gCfgJobXpCompleteBonus = 150;
    gCfgNpcRepairCost = 450;

    gCfgNpcTransportCost = NPC_TRANSPORT_COST;
    gCfgNpcTowCost = NPC_TOW_COST;
    gCfgPhoneRideCost = PHONE_RIDE_COST;
    gCfgPhoneDeliveryFee = PHONE_DELIVERY_FEE;

    gCfgVehicleGarageCost = VEHICLE_GARAGE_COST;
    gCfgVehicleImpoundCost = VEHICLE_IMPOUND_COST;
    gCfgVehicleInsuranceCost = VEHICLE_INSURANCE_COST;
    gCfgVehicleIpvaBase = VEHICLE_IPVA_BASE;
    gCfgVehicleIpvaPercent = VEHICLE_IPVA_PERCENT;
    gCfgVehicleRegisterCost = VEHICLE_DETRAN_REGISTER_COST;
    gCfgVehiclePlateCost = VEHICLE_DETRAN_PLATE_COST;
    gCfgVehicleTransferCost = VEHICLE_DETRAN_TRANSFER_COST;
    gCfgVehicleSellPercent = VEHICLE_SELL_PERCENT;

    gCfgRadarFineBase = RADAR_FINE_BASE;
    gCfgRadarFinePerKmh = RADAR_FINE_PER_KMH;
    gCfgTrafficFineLight = 88;
    gCfgTrafficFineMedium = 130;
    gCfgTrafficFineSerious = 195;
    gCfgTrafficFineVerySerious = 293;
    gCfgTrafficFineMax = 17608;

    gCfgMarketSellPay = 350;
    gCfgMarketDeliveryStock = 8;
    gCfgMarketLowStock = 10;

    gCfgJusticeReportCost = 80;
    gCfgJusticeHearingCost = 500;
    gCfgJusticeLawyerCost = 1500;
    gCfgJusticeSentenceBase = 1000;

    gCfgBusinessOpenCost = 2500;
    gCfgBusinessEmployeeCost = 900;
    gCfgBusinessSalaryCost = 1200;
    gCfgBusinessRevenue = 2500;
    gCfgBusinessTaxPercent = 12;
    gCfgBusinessPermitValidDays = 30;

    gCfgPropertyTaxPercent = 1;
    gCfgGovernmentMonthlyFee = 150;
    gCfgBillDueDays = 7;
    gCfgBillLateFeePercent = 5;
    gCfgDebtDirtyThreshold = 1500;
    gCfgDebtScorePenalty = 120;
    gCfgBillWaterCost = 90;
    gCfgBillElectricCost = 140;
    gCfgBillInternetCost = 110;
    gCfgBillRentExtraCost = 0;
    gCfgBillLoanPercent = 20;
    gCfgBillWaterOccupantExtra = 35;
    gCfgBillElectricOccupantExtra = 55;
    gCfgBillHydroDiscountPercent = 15;
    gCfgHomeSolarInstallCost = 12000;
    gCfgHomeSolarDiscountPercent = 60;
    gCfgSalaryPayTasks = 6;
    gCfgIncomeTaxPercent = 8;
    gCfgCartorioCpfCost = 80;
    gCfgCartorioRgCost = 80;
    gCfgCartorioCertCost = 120;
    gCfgCartorioFirmaCost = 200;
    gCfgCartorioNameCost = 900;
    gCfgContractRentCost = 250;
    gCfgContractFinanceCost = 600;
    gCfgContractWorkCost = 150;
    gCfgContractInsuranceCost = 350;
    gCfgContractCancelFine = 500;

    for (jobid = 0; jobid <= JOB_MAX_ID; jobid++)
    {
        gCfgJobPay[jobid] = 0;
        gCfgJobBonus[jobid] = 0;
    }
    return 1;
}

stock Cfg_Trim(text[])
{
    new start;
    new end = strlen(text) - 1;
    new index;

    while (text[start] != 0 && text[start] <= ' ')
    {
        start++;
    }

    while (end >= start && text[end] <= ' ')
    {
        text[end] = 0;
        end--;
    }

    if (start > 0)
    {
        while (text[start] != 0)
        {
            text[index++] = text[start++];
        }
        text[index] = 0;
    }
    return 1;
}

stock Cfg_Clamp(value, minValue, maxValue)
{
    if (value < minValue)
    {
        return minValue;
    }
    if (value > maxValue)
    {
        return maxValue;
    }
    return value;
}

stock Cfg_PercentValue(baseValue, percent)
{
    new result;

    if (baseValue <= 0)
    {
        return baseValue;
    }

    if (percent <= 0)
    {
        percent = 100;
    }

    result = (baseValue * percent) / 100;
    if (result < 1)
    {
        result = 1;
    }
    return result;
}

stock Cfg_Price(baseValue)
{
    return Cfg_PercentValue(baseValue, gCfgPricePercent);
}

stock Cfg_Fine(baseValue)
{
    return Cfg_PercentValue(baseValue, gCfgFinePercent);
}

stock Cfg_TrafficSeverityName(severity, output[], size = sizeof(output))
{
    switch (severity)
    {
        case TRAFFIC_FINE_LIGHT: format(output, size, "Leve");
        case TRAFFIC_FINE_MEDIUM: format(output, size, "Media");
        case TRAFFIC_FINE_SERIOUS: format(output, size, "Grave");
        case TRAFFIC_FINE_VERY_SERIOUS: format(output, size, "Gravissima");
        default: format(output, size, "Media");
    }
    return 1;
}

stock Cfg_TrafficBaseFine(severity)
{
    switch (severity)
    {
        case TRAFFIC_FINE_LIGHT: return gCfgTrafficFineLight;
        case TRAFFIC_FINE_MEDIUM: return gCfgTrafficFineMedium;
        case TRAFFIC_FINE_SERIOUS: return gCfgTrafficFineSerious;
        case TRAFFIC_FINE_VERY_SERIOUS: return gCfgTrafficFineVerySerious;
    }
    return gCfgTrafficFineMedium;
}

stock Cfg_TrafficPoints(severity)
{
    switch (severity)
    {
        case TRAFFIC_FINE_LIGHT: return 3;
        case TRAFFIC_FINE_MEDIUM: return 4;
        case TRAFFIC_FINE_SERIOUS: return 5;
        case TRAFFIC_FINE_VERY_SERIOUS: return 7;
    }
    return 4;
}

stock Cfg_TrafficMultiplierOk(multiplier)
{
    return (multiplier == 1 || multiplier == 2 || multiplier == 3 || multiplier == 5 || multiplier == 10 || multiplier == 20 || multiplier == 60);
}

stock Cfg_TrafficFine(severity, multiplier = 1)
{
    new amount;

    if (!Cfg_TrafficMultiplierOk(multiplier))
    {
        multiplier = 1;
    }

    amount = Cfg_TrafficBaseFine(severity) * multiplier;
    if (amount > gCfgTrafficFineMax)
    {
        amount = gCfgTrafficFineMax;
    }
    return Cfg_Fine(amount);
}

stock Cfg_ParseTrafficSeverity(input[])
{
    if (strcmp(input, "1", false) == 0 || strcmp(input, "leve", true) == 0)
    {
        return TRAFFIC_FINE_LIGHT;
    }
    if (strcmp(input, "2", false) == 0 || strcmp(input, "media", true) == 0 || strcmp(input, "medio", true) == 0)
    {
        return TRAFFIC_FINE_MEDIUM;
    }
    if (strcmp(input, "3", false) == 0 || strcmp(input, "grave", true) == 0)
    {
        return TRAFFIC_FINE_SERIOUS;
    }
    if (strcmp(input, "4", false) == 0 || strcmp(input, "gravissima", true) == 0 || strcmp(input, "gravissimo", true) == 0)
    {
        return TRAFFIC_FINE_VERY_SERIOUS;
    }
    return 0;
}

stock Cfg_PropertyPrice(baseValue)
{
    return Cfg_PercentValue(Cfg_Price(baseValue), gCfgPropertyPricePercent);
}

stock Cfg_VehiclePrice(baseValue)
{
    return Cfg_PercentValue(Cfg_Price(baseValue), gCfgVehiclePricePercent);
}

stock Cfg_GetJobPay(jobid, defaultPay)
{
    if (jobid > JOB_NONE && jobid <= JOB_MAX_ID && gCfgJobPay[jobid] > 0)
    {
        return gCfgJobPay[jobid];
    }
    return Cfg_PercentValue(defaultPay, gCfgJobPayPercent);
}

stock Cfg_GetJobBonus(jobid, defaultBonus)
{
    if (jobid > JOB_NONE && jobid <= JOB_MAX_ID && gCfgJobBonus[jobid] > 0)
    {
        return gCfgJobBonus[jobid];
    }
    return Cfg_PercentValue(defaultBonus, gCfgJobBonusPercent);
}

stock Cfg_WriteDefaultFile()
{
    new File:file;

    if (fexist(GAME_CONFIG_FILE))
    {
        return 1;
    }

    file = fopen(GAME_CONFIG_FILE, io_write);
    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Life Simulator BR - configuracao geral\r\n");
    fwrite(file, "# Altere valores e use /reloadconfig. Timers novos tambem aplicam ao reiniciar.\r\n\r\n");
    fwrite(file, "starting_money=500\r\n");
    fwrite(file, "price_percent=100\r\n");
    fwrite(file, "fine_percent=100\r\n");
    fwrite(file, "job_pay_percent=100\r\n");
    fwrite(file, "job_bonus_percent=100\r\n");
    fwrite(file, "property_price_percent=100\r\n");
    fwrite(file, "vehicle_price_percent=100\r\n\r\n");
    fwrite(file, "hud_update_ms=1000\r\n");
    fwrite(file, "hostname_update_ms=30000\r\n");
    fwrite(file, "autosave_ms=600000\r\n");
    fwrite(file, "character_xp_interval_ms=420000\r\n");
    fwrite(file, "character_xp_per_level=4\r\n\r\n");
    fwrite(file, "needs_update_ms=60000\r\n");
    fwrite(file, "needs_warning_ms=30000\r\n");
    fwrite(file, "needs_low=25\r\n");
    fwrite(file, "needs_min_safe=35\r\n");
    fwrite(file, "needs_hunger_loss=1\r\n");
    fwrite(file, "needs_thirst_loss=2\r\n");
    fwrite(file, "needs_starve_damage=10\r\n\r\n");
    fwrite(file, "fuel_update_ms=5000\r\n");
    fwrite(file, "fuel_low=15\r\n");
    fwrite(file, "npc_refuel_price_percent=7\r\n");
    fwrite(file, "npc_refuel_min_cost=50\r\n");
    fwrite(file, "fuel_price_gasoline=7\r\n");
    fwrite(file, "fuel_price_ethanol=4\r\n");
    fwrite(file, "fuel_price_diesel=7\r\n");
    fwrite(file, "fuel_price_glp=115\r\n\r\n");
    fwrite(file, "bank_open_cost=100\r\n");
    fwrite(file, "bank_card_cost=75\r\n");
    fwrite(file, "bank_transfer_limit=1000000\r\n");
    fwrite(file, "bank_loan_min=1000\r\n");
    fwrite(file, "bank_loan_interest_percent=15\r\n");
    fwrite(file, "bank_loan_min_score=350\r\n");
    fwrite(file, "bank_score_base=500\r\n");
    fwrite(file, "bank_score_fine_penalty=1\r\n");
    fwrite(file, "bank_score_criminal_penalty=60\r\n");
    fwrite(file, "bank_score_good_bonus=45\r\n");
    fwrite(file, "bank_score_bad_penalty=90\r\n\r\n");
    fwrite(file, "citizen_license_min_score=250\r\n");
    fwrite(file, "citizen_job_trusted_min_score=420\r\n");
    fwrite(file, "citizen_vehicle_min_score=300\r\n");
    fwrite(file, "citizen_rent_min_score=300\r\n");
    fwrite(file, "citizen_property_min_score=450\r\n");
    fwrite(file, "citizen_business_min_score=500\r\n\r\n");
    fwrite(file, "document_cost=100\r\n");
    fwrite(file, "rename_cost=500\r\n");
    fwrite(file, "license_cnh_cost=300\r\n");
    fwrite(file, "license_heavy_cost=450\r\n");
    fwrite(file, "license_medical_cost=350\r\n");
    fwrite(file, "license_oab_cost=330\r\n");
    fwrite(file, "license_public_cost=350\r\n");
    fwrite(file, "license_police_cost=3500\r\n");
    fwrite(file, "document_valid_days=365\r\n");
    fwrite(file, "license_valid_days=180\r\n\r\n");
    fwrite(file, "hospital_treatment_cost=250\r\n");
    fwrite(file, "hospital_death_cost=500\r\n");
    fwrite(file, "hospital_plan_cost=900\r\n");
    fwrite(file, "hospital_plan_treat_cost=60\r\n");
    fwrite(file, "hospital_plan_death_cost=120\r\n");
    fwrite(file, "health_plan_valid_days=30\r\n");
    fwrite(file, "medicine_cost=120\r\n");
    fwrite(file, "surgery_cost=1400\r\n");
    fwrite(file, "ambulance_cost=450\r\n\r\n");
    fwrite(file, "work_task_cooldown_ms=8000\r\n");
    fwrite(file, "work_abandon_penalty=150\r\n");
    fwrite(file, "work_fine_limit=17608\r\n");
    fwrite(file, "job_xp_per_task=100\r\n");
    fwrite(file, "job_xp_complete_bonus=150\r\n");
    fwrite(file, "npc_repair_cost=450\r\n\r\n");
    fwrite(file, "npc_transport_cost=150\r\n");
    fwrite(file, "npc_tow_cost=350\r\n");
    fwrite(file, "phone_ride_cost=220\r\n");
    fwrite(file, "phone_delivery_fee=25\r\n\r\n");
    fwrite(file, "vehicle_garage_cost=150\r\n");
    fwrite(file, "vehicle_impound_cost=700\r\n");
    fwrite(file, "vehicle_insurance_cost=650\r\n");
    fwrite(file, "vehicle_ipva_base=0\r\n");
    fwrite(file, "vehicle_ipva_percent=4\r\n");
    fwrite(file, "vehicle_register_cost=174\r\n");
    fwrite(file, "vehicle_plate_cost=250\r\n");
    fwrite(file, "vehicle_transfer_cost=420\r\n");
    fwrite(file, "vehicle_sell_percent=60\r\n\r\n");
    fwrite(file, "# Multas de transito baseadas na tabela CTB, arredondadas para dinheiro inteiro do servidor.\r\n");
    fwrite(file, "traffic_fine_light=88\r\n");
    fwrite(file, "traffic_fine_medium=130\r\n");
    fwrite(file, "traffic_fine_serious=195\r\n");
    fwrite(file, "traffic_fine_very_serious=293\r\n");
    fwrite(file, "traffic_fine_max=17608\r\n");
    fwrite(file, "radar_fine_base=0\r\n");
    fwrite(file, "radar_fine_per_kmh=0\r\n\r\n");
    fwrite(file, "market_sell_pay=350\r\n");
    fwrite(file, "market_delivery_stock=8\r\n");
    fwrite(file, "market_low_stock=10\r\n\r\n");
    fwrite(file, "justice_report_cost=80\r\n");
    fwrite(file, "justice_hearing_cost=500\r\n");
    fwrite(file, "justice_lawyer_cost=1500\r\n");
    fwrite(file, "justice_sentence_base=1000\r\n\r\n");
    fwrite(file, "business_open_cost=2500\r\n");
    fwrite(file, "business_employee_cost=900\r\n");
    fwrite(file, "business_salary_cost=1200\r\n");
    fwrite(file, "business_revenue=2500\r\n");
    fwrite(file, "business_tax_percent=12\r\n");
    fwrite(file, "business_permit_valid_days=30\r\n\r\n");
    fwrite(file, "property_tax_percent=1\r\n");
    fwrite(file, "government_monthly_fee=150\r\n");
    fwrite(file, "bill_due_days=7\r\n");
    fwrite(file, "bill_late_fee_percent=5\r\n");
    fwrite(file, "debt_dirty_threshold=1500\r\n");
    fwrite(file, "debt_score_penalty=120\r\n");
    fwrite(file, "bill_water_cost=90\r\n");
    fwrite(file, "bill_electric_cost=140\r\n");
    fwrite(file, "bill_internet_cost=110\r\n");
    fwrite(file, "bill_rent_extra_cost=0\r\n");
    fwrite(file, "bill_loan_percent=20\r\n");
    fwrite(file, "bill_water_occupant_extra=35\r\n");
    fwrite(file, "bill_electric_occupant_extra=55\r\n");
    fwrite(file, "bill_hydro_discount_percent=15\r\n");
    fwrite(file, "home_solar_install_cost=12000\r\n");
    fwrite(file, "home_solar_discount_percent=60\r\n");
    fwrite(file, "salary_pay_tasks=6\r\n");
    fwrite(file, "income_tax_percent=8\r\n");
    fwrite(file, "cartorio_cpf_cost=80\r\n");
    fwrite(file, "cartorio_rg_cost=80\r\n");
    fwrite(file, "cartorio_certificate_cost=120\r\n");
    fwrite(file, "cartorio_signature_cost=200\r\n");
    fwrite(file, "cartorio_name_change_cost=900\r\n");
    fwrite(file, "contract_rent_cost=250\r\n");
    fwrite(file, "contract_finance_cost=600\r\n");
    fwrite(file, "contract_work_cost=150\r\n");
    fwrite(file, "contract_insurance_cost=350\r\n");
    fwrite(file, "contract_cancel_fine=500\r\n\r\n");
    fwrite(file, "# Salarios especificos por profissao: job_ID_pay / job_ID_bonus\r\n");
    fwrite(file, "# Base calibrada por salarios brasileiros reais, reduzida para escala RP.\r\n");
    fwrite(file, "job_1_pay=370\r\njob_1_bonus=760\r\njob_2_pay=390\r\njob_2_bonus=0\r\njob_3_pay=750\r\njob_3_bonus=0\r\n");
    fwrite(file, "job_4_pay=620\r\njob_4_bonus=860\r\njob_5_pay=640\r\njob_5_bonus=1280\r\njob_6_pay=590\r\njob_6_bonus=980\r\n");
    fwrite(file, "job_7_pay=360\r\njob_7_bonus=620\r\njob_8_pay=920\r\njob_8_bonus=0\r\njob_9_pay=1150\r\njob_9_bonus=0\r\n");
    fwrite(file, "job_10_pay=760\r\njob_10_bonus=0\r\njob_11_pay=520\r\njob_11_bonus=830\r\njob_12_pay=430\r\njob_12_bonus=0\r\n");
    fwrite(file, "job_13_pay=360\r\njob_13_bonus=780\r\njob_14_pay=430\r\njob_14_bonus=820\r\njob_15_pay=450\r\njob_15_bonus=900\r\n");
    fwrite(file, "job_16_pay=670\r\njob_16_bonus=1280\r\njob_17_pay=500\r\njob_17_bonus=960\r\njob_18_pay=330\r\njob_18_bonus=620\r\n");
    fwrite(file, "job_19_pay=420\r\njob_19_bonus=780\r\njob_20_pay=400\r\njob_20_bonus=760\r\njob_21_pay=870\r\njob_21_bonus=1180\r\n");
    fwrite(file, "job_22_pay=840\r\njob_22_bonus=1250\r\njob_23_pay=1300\r\njob_23_bonus=0\r\njob_24_pay=740\r\njob_24_bonus=0\r\n");
    fwrite(file, "job_25_pay=540\r\njob_25_bonus=980\r\njob_26_pay=1050\r\njob_26_bonus=0\r\njob_27_pay=1200\r\njob_27_bonus=0\r\n");
    fwrite(file, "job_28_pay=980\r\njob_28_bonus=0\r\njob_29_pay=900\r\njob_29_bonus=0\r\n");
    fclose(file);
    return 1;
}

stock Cfg_ApplyJobKey(key[], value[])
{
    new pos;
    new idText[8];
    new jobid;
    new amount;

    if (strfind(key, "job_", true) != 0)
    {
        return 0;
    }

    pos = strfind(key, "_pay", true);
    if (pos > 4)
    {
        strmid(idText, key, 4, pos, sizeof(idText));
        if (!IsNumericString(idText))
        {
            return 0;
        }

        jobid = strval(idText);
        amount = strval(value);
        if (jobid > JOB_NONE && jobid <= JOB_MAX_ID && amount > 0)
        {
            gCfgJobPay[jobid] = amount;
        }
        return 1;
    }

    pos = strfind(key, "_bonus", true);
    if (pos > 4)
    {
        strmid(idText, key, 4, pos, sizeof(idText));
        if (!IsNumericString(idText))
        {
            return 0;
        }

        jobid = strval(idText);
        amount = strval(value);
        if (jobid > JOB_NONE && jobid <= JOB_MAX_ID && amount > 0)
        {
            gCfgJobBonus[jobid] = amount;
        }
        return 1;
    }

    return 0;
}

stock Cfg_ApplyField(key[], value[])
{
    if (Cfg_ApplyJobKey(key, value))
    {
        return 1;
    }

    if (strcmp(key, "starting_money", false) == 0) gCfgStartingMoney = strval(value);
    else if (strcmp(key, "price_percent", false) == 0) gCfgPricePercent = Cfg_Clamp(strval(value), 1, 1000);
    else if (strcmp(key, "fine_percent", false) == 0) gCfgFinePercent = Cfg_Clamp(strval(value), 1, 1000);
    else if (strcmp(key, "job_pay_percent", false) == 0) gCfgJobPayPercent = Cfg_Clamp(strval(value), 1, 1000);
    else if (strcmp(key, "job_bonus_percent", false) == 0) gCfgJobBonusPercent = Cfg_Clamp(strval(value), 1, 1000);
    else if (strcmp(key, "property_price_percent", false) == 0) gCfgPropertyPricePercent = Cfg_Clamp(strval(value), 1, 1000);
    else if (strcmp(key, "vehicle_price_percent", false) == 0) gCfgVehiclePricePercent = Cfg_Clamp(strval(value), 1, 1000);
    else if (strcmp(key, "hud_update_ms", false) == 0) gCfgHudUpdateInterval = Cfg_Clamp(strval(value), 500, 10000);
    else if (strcmp(key, "hostname_update_ms", false) == 0) gCfgHostnameInterval = Cfg_Clamp(strval(value), 10000, 300000);
    else if (strcmp(key, "autosave_ms", false) == 0) gCfgAutosaveInterval = Cfg_Clamp(strval(value), 60000, 3600000);
    else if (strcmp(key, "character_xp_interval_ms", false) == 0) gCfgCharacterXpInterval = Cfg_Clamp(strval(value), 60000, 3600000);
    else if (strcmp(key, "character_xp_per_level", false) == 0) gCfgCharacterXpPerLevel = Cfg_Clamp(strval(value), 1, 1000);
    else if (strcmp(key, "needs_update_ms", false) == 0) gCfgNeedsUpdateInterval = Cfg_Clamp(strval(value), 10000, 600000);
    else if (strcmp(key, "needs_warning_ms", false) == 0) gCfgNeedsWarningInterval = Cfg_Clamp(strval(value), 5000, 300000);
    else if (strcmp(key, "needs_low", false) == 0) gCfgNeedsLowValue = Cfg_Clamp(strval(value), 1, 100);
    else if (strcmp(key, "needs_min_safe", false) == 0) gCfgNeedsMinSafe = Cfg_Clamp(strval(value), 1, 100);
    else if (strcmp(key, "needs_hunger_loss", false) == 0) gCfgNeedsHungerLoss = Cfg_Clamp(strval(value), 0, 25);
    else if (strcmp(key, "needs_thirst_loss", false) == 0) gCfgNeedsThirstLoss = Cfg_Clamp(strval(value), 0, 25);
    else if (strcmp(key, "needs_starve_damage", false) == 0) gCfgNeedsStarveDamage = floatstr(value);
    else if (strcmp(key, "fuel_update_ms", false) == 0) gCfgFuelUpdateInterval = Cfg_Clamp(strval(value), 1000, 60000);
    else if (strcmp(key, "fuel_low", false) == 0) gCfgFuelLowValue = Cfg_Clamp(strval(value), 1, 100);
    else if (strcmp(key, "npc_refuel_price_percent", false) == 0) gCfgNpcRefuelPrice = Cfg_Clamp(strval(value), 1, 1000);
    else if (strcmp(key, "npc_refuel_min_cost", false) == 0) gCfgNpcRefuelMinCost = Cfg_Clamp(strval(value), 1, 100000);
    else if (strcmp(key, "fuel_price_gasoline", false) == 0) gCfgFuelGasolinePrice = Cfg_Clamp(strval(value), 1, 1000);
    else if (strcmp(key, "fuel_price_ethanol", false) == 0) gCfgFuelEthanolPrice = Cfg_Clamp(strval(value), 1, 1000);
    else if (strcmp(key, "fuel_price_diesel", false) == 0) gCfgFuelDieselPrice = Cfg_Clamp(strval(value), 1, 1000);
    else if (strcmp(key, "fuel_price_glp", false) == 0) gCfgFuelGlpPrice = Cfg_Clamp(strval(value), 1, 10000);
    else if (strcmp(key, "bank_open_cost", false) == 0) gCfgBankOpenCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "bank_card_cost", false) == 0) gCfgBankCardCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "bank_transfer_limit", false) == 0) gCfgBankTransferLimit = Cfg_Clamp(strval(value), 1, 2000000000);
    else if (strcmp(key, "bank_loan_min", false) == 0) gCfgBankLoanMin = Cfg_Clamp(strval(value), 1, 100000000);
    else if (strcmp(key, "bank_loan_interest_percent", false) == 0) gCfgBankLoanInterest = Cfg_Clamp(strval(value), 0, 500);
    else if (strcmp(key, "bank_loan_min_score", false) == 0) gCfgBankLoanMinScore = Cfg_Clamp(strval(value), 0, 1000);
    else if (strcmp(key, "bank_score_base", false) == 0) gCfgBankScoreBase = Cfg_Clamp(strval(value), 0, 1000);
    else if (strcmp(key, "bank_score_fine_penalty", false) == 0) gCfgBankScoreFinePenalty = Cfg_Clamp(strval(value), 0, 100);
    else if (strcmp(key, "bank_score_criminal_penalty", false) == 0) gCfgBankScoreCriminalPenalty = Cfg_Clamp(strval(value), 0, 1000);
    else if (strcmp(key, "bank_score_good_bonus", false) == 0) gCfgBankScoreGoodBonus = Cfg_Clamp(strval(value), 0, 1000);
    else if (strcmp(key, "bank_score_bad_penalty", false) == 0) gCfgBankScoreBadPenalty = Cfg_Clamp(strval(value), 0, 1000);
    else if (strcmp(key, "citizen_license_min_score", false) == 0) gCfgCitizenLicenseMinScore = Cfg_Clamp(strval(value), 0, 1000);
    else if (strcmp(key, "citizen_job_trusted_min_score", false) == 0) gCfgCitizenJobTrustedMinScore = Cfg_Clamp(strval(value), 0, 1000);
    else if (strcmp(key, "citizen_vehicle_min_score", false) == 0) gCfgCitizenVehicleMinScore = Cfg_Clamp(strval(value), 0, 1000);
    else if (strcmp(key, "citizen_rent_min_score", false) == 0) gCfgCitizenRentMinScore = Cfg_Clamp(strval(value), 0, 1000);
    else if (strcmp(key, "citizen_property_min_score", false) == 0) gCfgCitizenPropertyMinScore = Cfg_Clamp(strval(value), 0, 1000);
    else if (strcmp(key, "citizen_business_min_score", false) == 0) gCfgCitizenBusinessMinScore = Cfg_Clamp(strval(value), 0, 1000);
    else if (strcmp(key, "document_cost", false) == 0) gCfgCityDocumentCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "rename_cost", false) == 0) gCfgCityRenameCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "license_cnh_cost", false) == 0) gCfgLicenseCNHCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "license_heavy_cost", false) == 0) gCfgLicenseHeavyCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "license_medical_cost", false) == 0) gCfgLicenseMedicalCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "license_oab_cost", false) == 0) gCfgLicenseOABCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "license_public_cost", false) == 0) gCfgLicensePublicCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "license_police_cost", false) == 0) gCfgLicensePoliceCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "document_valid_days", false) == 0) gCfgDocumentValidDays = Cfg_Clamp(strval(value), 1, 3650);
    else if (strcmp(key, "license_valid_days", false) == 0) gCfgLicenseValidDays = Cfg_Clamp(strval(value), 1, 3650);
    else if (strcmp(key, "hospital_treatment_cost", false) == 0) gCfgHospitalTreatCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "hospital_death_cost", false) == 0) gCfgHospitalDeathCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "hospital_plan_cost", false) == 0) gCfgHospitalPlanCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "hospital_plan_treat_cost", false) == 0) gCfgHospitalPlanTreatCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "hospital_plan_death_cost", false) == 0) gCfgHospitalPlanDeathCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "health_plan_valid_days", false) == 0) gCfgHealthPlanValidDays = Cfg_Clamp(strval(value), 1, 3650);
    else if (strcmp(key, "medicine_cost", false) == 0) gCfgMedicineCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "surgery_cost", false) == 0) gCfgSurgeryCost = Cfg_Clamp(strval(value), 0, 10000000);
    else if (strcmp(key, "ambulance_cost", false) == 0) gCfgAmbulanceCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "work_task_cooldown_ms", false) == 0) gCfgWorkTaskCooldown = Cfg_Clamp(strval(value), 0, 300000);
    else if (strcmp(key, "work_abandon_penalty", false) == 0) gCfgWorkAbandonPenalty = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "work_fine_limit", false) == 0) gCfgWorkFineLimit = Cfg_Clamp(strval(value), 1, MAX_PLAYER_FINE);
    else if (strcmp(key, "job_xp_per_task", false) == 0) gCfgJobXpPerTask = Cfg_Clamp(strval(value), 1, 100000);
    else if (strcmp(key, "job_xp_complete_bonus", false) == 0) gCfgJobXpCompleteBonus = Cfg_Clamp(strval(value), 1, 100000);
    else if (strcmp(key, "npc_repair_cost", false) == 0) gCfgNpcRepairCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "npc_transport_cost", false) == 0) gCfgNpcTransportCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "npc_tow_cost", false) == 0) gCfgNpcTowCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "phone_ride_cost", false) == 0) gCfgPhoneRideCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "phone_delivery_fee", false) == 0) gCfgPhoneDeliveryFee = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "vehicle_garage_cost", false) == 0) gCfgVehicleGarageCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "vehicle_impound_cost", false) == 0) gCfgVehicleImpoundCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "vehicle_insurance_cost", false) == 0) gCfgVehicleInsuranceCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "vehicle_ipva_base", false) == 0) gCfgVehicleIpvaBase = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "vehicle_ipva_percent", false) == 0) gCfgVehicleIpvaPercent = Cfg_Clamp(strval(value), 0, 100);
    else if (strcmp(key, "vehicle_register_cost", false) == 0) gCfgVehicleRegisterCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "vehicle_plate_cost", false) == 0) gCfgVehiclePlateCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "vehicle_transfer_cost", false) == 0) gCfgVehicleTransferCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "vehicle_sell_percent", false) == 0) gCfgVehicleSellPercent = Cfg_Clamp(strval(value), 1, 100);
    else if (strcmp(key, "radar_fine_base", false) == 0) gCfgRadarFineBase = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "radar_fine_per_kmh", false) == 0) gCfgRadarFinePerKmh = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "traffic_fine_light", false) == 0) gCfgTrafficFineLight = Cfg_Clamp(strval(value), 1, 1000000);
    else if (strcmp(key, "traffic_fine_medium", false) == 0) gCfgTrafficFineMedium = Cfg_Clamp(strval(value), 1, 1000000);
    else if (strcmp(key, "traffic_fine_serious", false) == 0) gCfgTrafficFineSerious = Cfg_Clamp(strval(value), 1, 1000000);
    else if (strcmp(key, "traffic_fine_very_serious", false) == 0) gCfgTrafficFineVerySerious = Cfg_Clamp(strval(value), 1, 1000000);
    else if (strcmp(key, "traffic_fine_max", false) == 0) gCfgTrafficFineMax = Cfg_Clamp(strval(value), 1, MAX_PLAYER_FINE);
    else if (strcmp(key, "market_sell_pay", false) == 0) gCfgMarketSellPay = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "market_delivery_stock", false) == 0) gCfgMarketDeliveryStock = Cfg_Clamp(strval(value), 1, 10000);
    else if (strcmp(key, "market_low_stock", false) == 0) gCfgMarketLowStock = Cfg_Clamp(strval(value), 0, 10000);
    else if (strcmp(key, "justice_report_cost", false) == 0) gCfgJusticeReportCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "justice_hearing_cost", false) == 0) gCfgJusticeHearingCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "justice_lawyer_cost", false) == 0) gCfgJusticeLawyerCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "justice_sentence_base", false) == 0) gCfgJusticeSentenceBase = Cfg_Clamp(strval(value), 0, 10000000);
    else if (strcmp(key, "business_open_cost", false) == 0) gCfgBusinessOpenCost = Cfg_Clamp(strval(value), 0, 10000000);
    else if (strcmp(key, "business_employee_cost", false) == 0) gCfgBusinessEmployeeCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "business_salary_cost", false) == 0) gCfgBusinessSalaryCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "business_revenue", false) == 0) gCfgBusinessRevenue = Cfg_Clamp(strval(value), 0, 10000000);
    else if (strcmp(key, "business_tax_percent", false) == 0) gCfgBusinessTaxPercent = Cfg_Clamp(strval(value), 0, 100);
    else if (strcmp(key, "business_permit_valid_days", false) == 0) gCfgBusinessPermitValidDays = Cfg_Clamp(strval(value), 1, 3650);
    else if (strcmp(key, "property_tax_percent", false) == 0) gCfgPropertyTaxPercent = Cfg_Clamp(strval(value), 0, 100);
    else if (strcmp(key, "government_monthly_fee", false) == 0) gCfgGovernmentMonthlyFee = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "bill_due_days", false) == 0) gCfgBillDueDays = Cfg_Clamp(strval(value), 1, 60);
    else if (strcmp(key, "bill_late_fee_percent", false) == 0) gCfgBillLateFeePercent = Cfg_Clamp(strval(value), 0, 100);
    else if (strcmp(key, "debt_dirty_threshold", false) == 0) gCfgDebtDirtyThreshold = Cfg_Clamp(strval(value), 0, 100000000);
    else if (strcmp(key, "debt_score_penalty", false) == 0) gCfgDebtScorePenalty = Cfg_Clamp(strval(value), 0, 1000);
    else if (strcmp(key, "bill_water_cost", false) == 0) gCfgBillWaterCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "bill_electric_cost", false) == 0) gCfgBillElectricCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "bill_internet_cost", false) == 0) gCfgBillInternetCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "bill_rent_extra_cost", false) == 0) gCfgBillRentExtraCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "bill_loan_percent", false) == 0) gCfgBillLoanPercent = Cfg_Clamp(strval(value), 1, 100);
    else if (strcmp(key, "bill_water_occupant_extra", false) == 0) gCfgBillWaterOccupantExtra = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "bill_electric_occupant_extra", false) == 0) gCfgBillElectricOccupantExtra = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "bill_hydro_discount_percent", false) == 0) gCfgBillHydroDiscountPercent = Cfg_Clamp(strval(value), 0, 100);
    else if (strcmp(key, "home_solar_install_cost", false) == 0) gCfgHomeSolarInstallCost = Cfg_Clamp(strval(value), 0, 10000000);
    else if (strcmp(key, "home_solar_discount_percent", false) == 0) gCfgHomeSolarDiscountPercent = Cfg_Clamp(strval(value), 0, 100);
    else if (strcmp(key, "salary_pay_tasks", false) == 0) gCfgSalaryPayTasks = Cfg_Clamp(strval(value), 1, 100);
    else if (strcmp(key, "income_tax_percent", false) == 0) gCfgIncomeTaxPercent = Cfg_Clamp(strval(value), 0, 100);
    else if (strcmp(key, "cartorio_cpf_cost", false) == 0) gCfgCartorioCpfCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "cartorio_rg_cost", false) == 0) gCfgCartorioRgCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "cartorio_certificate_cost", false) == 0) gCfgCartorioCertCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "cartorio_signature_cost", false) == 0) gCfgCartorioFirmaCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "cartorio_name_change_cost", false) == 0) gCfgCartorioNameCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "contract_rent_cost", false) == 0) gCfgContractRentCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "contract_finance_cost", false) == 0) gCfgContractFinanceCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "contract_work_cost", false) == 0) gCfgContractWorkCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "contract_insurance_cost", false) == 0) gCfgContractInsuranceCost = Cfg_Clamp(strval(value), 0, 1000000);
    else if (strcmp(key, "contract_cancel_fine", false) == 0) gCfgContractCancelFine = Cfg_Clamp(strval(value), 0, 1000000);
    else return 0;

    return 1;
}

stock Cfg_ApplyLine(line[])
{
    new equalPos = -1;
    new index;
    new key[48];
    new value[80];

    StripLineEnd(line);
    Cfg_Trim(line);

    if (line[0] == 0 || line[0] == '#' || line[0] == ';')
    {
        return 0;
    }

    while (line[index] != 0)
    {
        if (line[index] == '=')
        {
            equalPos = index;
            break;
        }
        index++;
    }

    if (equalPos <= 0)
    {
        return 0;
    }

    strmid(key, line, 0, equalPos, sizeof(key));
    strmid(value, line, equalPos + 1, strlen(line), sizeof(value));
    Cfg_Trim(key);
    Cfg_Trim(value);
    return Cfg_ApplyField(key, value);
}

stock LoadGameConfig()
{
    new File:file;
    new line[160];
    new loaded;

    Cfg_ResetDefaults();
    Cfg_WriteDefaultFile();

    file = fopen(GAME_CONFIG_FILE, io_read);
    if (!file)
    {
        print("[GameConfig] Nao foi possivel abrir game_config.txt. Usando padrao da GM.");
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (Cfg_ApplyLine(line))
        {
            loaded++;
        }
    }

    fclose(file);
    printf("[GameConfig] %d configuracoes carregadas de scriptfiles/game_config.txt.", loaded);
    return loaded;
}

stock Config_ShowStatus(playerid)
{
    new text[1800];
    new line[160];

    format(text, sizeof(text), "Grupo\tValor\n");
    format(line, sizeof(line), "Economia\tDinheiro inicial $%d | precos %d%% | multas %d%%\n", gCfgStartingMoney, gCfgPricePercent, gCfgFinePercent); strcat(text, line, sizeof(text));
    format(line, sizeof(line), "XP\tgeral a cada %d ms | level a cada %d ponto(s)\n", gCfgCharacterXpInterval, gCfgCharacterXpPerLevel); strcat(text, line, sizeof(text));
    format(line, sizeof(line), "Necessidades\tupdate %d ms | fome -%d | sede -%d | baixo %d\n", gCfgNeedsUpdateInterval, gCfgNeedsHungerLoss, gCfgNeedsThirstLoss, gCfgNeedsLowValue); strcat(text, line, sizeof(text));
    format(line, sizeof(line), "Trabalho\tpay %d%% | bonus %d%% | cooldown %d ms | multa max $%d | XP %d/%d\n", gCfgJobPayPercent, gCfgJobBonusPercent, gCfgWorkTaskCooldown, gCfgWorkFineLimit, gCfgJobXpPerTask, gCfgJobXpCompleteBonus); strcat(text, line, sizeof(text));
    format(line, sizeof(line), "Banco\tabrir $%d | cartao $%d | juros %d%% | PIX max $%d\n", gCfgBankOpenCost, gCfgBankCardCost, gCfgBankLoanInterest, gCfgBankTransferLimit); strcat(text, line, sizeof(text));
    format(line, sizeof(line), "Score cidadao\tlic %d | emp sensivel %d | veic %d | aluguel %d | imovel %d | empresa %d\n", gCfgCitizenLicenseMinScore, gCfgCitizenJobTrustedMinScore, gCfgCitizenVehicleMinScore, gCfgCitizenRentMinScore, gCfgCitizenPropertyMinScore, gCfgCitizenBusinessMinScore); strcat(text, line, sizeof(text));
    format(line, sizeof(line), "Boletos\tvence em %d dia(s) | juros %d%% | negativacao $%d\n", gCfgBillDueDays, gCfgBillLateFeePercent, gCfgDebtDirtyThreshold); strcat(text, line, sizeof(text));
    format(line, sizeof(line), "Cartorio\tCPF $%d | RG $%d | nome ref. $%d\n", gCfgCartorioCpfCost, gCfgCartorioRgCost, gCfgCartorioNameCost); strcat(text, line, sizeof(text));
    format(line, sizeof(line), "Veiculos\tIPVA carro %d%% | seguro $%d | patio $%d\n", gCfgVehicleIpvaPercent, gCfgVehicleInsuranceCost, gCfgVehicleImpoundCost); strcat(text, line, sizeof(text));
    format(line, sizeof(line), "Combustivel\tgasolina $%d | alcool $%d | diesel $%d | GLP $%d\n", gCfgFuelGasolinePrice, gCfgFuelEthanolPrice, gCfgFuelDieselPrice, gCfgFuelGlpPrice); strcat(text, line, sizeof(text));
    format(line, sizeof(line), "Multas CTB\tleve $%d | media $%d | grave $%d | gravissima $%d | max $%d\n", gCfgTrafficFineLight, gCfgTrafficFineMedium, gCfgTrafficFineSerious, gCfgTrafficFineVerySerious, gCfgTrafficFineMax); strcat(text, line, sizeof(text));
    format(line, sizeof(line), "Radar legado\tbase $%d | km/h $%d | formula CTB ativa\n", gCfgRadarFineBase, gCfgRadarFinePerKmh); strcat(text, line, sizeof(text));
    format(line, sizeof(line), "Hospital\ttratamento $%d | morte $%d | plano $%d\n", gCfgHospitalTreatCost, gCfgHospitalDeathCost, gCfgHospitalPlanCost); strcat(text, line, sizeof(text));
    format(line, sizeof(line), "Arquivo\t%s\n", GAME_CONFIG_FILE); strcat(text, line, sizeof(text));

    ShowPlayerDialog(playerid, DIALOG_CONFIG_STATUS, DIALOG_STYLE_TABLIST_HEADERS, "Configuracao TXT", text, "Fechar", "");
    return 1;
}

stock Config_AddEconomyLine(list[], size, category[], item[], value[], reference[], scale[])
{
    new line[192];

    format(line, sizeof(line), "%s\t%s\t%s\t%s\t%s\n", category, item, value, reference, scale);
    strcat(list, line, size);
    return 1;
}

stock Config_ShowEconomyTable(playerid)
{
    new list[4096];
    new value[48];

    format(list, sizeof(list), "Categoria\tItem\tValor RP\tReferencia real\tEscala/observacao\n");

    format(value, sizeof(value), "$%d", Cfg_Price(gCfgFuelGasolinePrice));
    Config_AddEconomyLine(list, sizeof(list), "Combustivel", "Gasolina comum", value, "ANP Brasil 2026 aprox. R$ 6,65/L", "1%% tanque = 1 litro RP");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgFuelEthanolPrice));
    Config_AddEconomyLine(list, sizeof(list), "Combustivel", "Alcool/etanol", value, "ANP Brasil 2026 aprox. R$ 4,44/L", "base para flex futuro");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgFuelDieselPrice));
    Config_AddEconomyLine(list, sizeof(list), "Combustivel", "Diesel", value, "ANP Brasil 2026 aprox. R$ 7/L", "pesados usam diesel");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgFuelGlpPrice));
    Config_AddEconomyLine(list, sizeof(list), "Combustivel", "GLP botijao", value, "ANP Brasil 2026 aprox. R$ 114,94", "referencia casa/mercado");

    format(value, sizeof(value), "$%d", Cfg_Price(gCfgTrafficFineLight));
    Config_AddEconomyLine(list, sizeof(list), "Multas CTB", "Leve", value, "CTB R$ 88,38", "arredondado");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgTrafficFineMedium));
    Config_AddEconomyLine(list, sizeof(list), "Multas CTB", "Media", value, "CTB R$ 130,16", "arredondado");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgTrafficFineSerious));
    Config_AddEconomyLine(list, sizeof(list), "Multas CTB", "Grave", value, "CTB R$ 195,23", "arredondado");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgTrafficFineVerySerious));
    Config_AddEconomyLine(list, sizeof(list), "Multas CTB", "Gravissima", value, "CTB R$ 293,47", "arredondado");

    format(value, sizeof(value), "carro %d%% | moto 2%% | pesado 1.5%%", gCfgVehicleIpvaPercent);
    Config_AddEconomyLine(list, sizeof(list), "Veiculos", "IPVA", value, "Sefaz-SP 2026", "percentual por categoria");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgVehicleRegisterCost));
    Config_AddEconomyLine(list, sizeof(list), "Veiculos", "Registro/licenciamento", value, "Detran-SP 2026 R$ 174,08", "arredondado");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgVehicleTransferCost));
    Config_AddEconomyLine(list, sizeof(list), "Veiculos", "Transferencia", value, "Detran-SP aprox. R$ 419", "arredondado");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgVehiclePlateCost));
    Config_AddEconomyLine(list, sizeof(list), "Veiculos", "Placa", value, "servico variavel", "escala RP acessivel");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgVehicleInsuranceCost));
    Config_AddEconomyLine(list, sizeof(list), "Veiculos", "Seguro mensal", value, "mercado variavel", "mensal RP reduzido");

    format(value, sizeof(value), "$%d", Cfg_Price(gCfgLicenseCNHCost));
    Config_AddEconomyLine(list, sizeof(list), "Licencas", "CNH", value, "Detran-SP exames/emissao", "escala RP");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgLicenseHeavyCost));
    Config_AddEconomyLine(list, sizeof(list), "Licencas", "Categoria pesada", value, "adicao categoria", "escala RP");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgLicenseMedicalCost));
    Config_AddEconomyLine(list, sizeof(list), "Licencas", "Diploma medico", value, "curso/licenca RP", "barreira de cargo");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgLicenseOABCost));
    Config_AddEconomyLine(list, sizeof(list), "Licencas", "OAB", value, "taxas OAB variam", "escala RP");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgLicensePublicCost));
    Config_AddEconomyLine(list, sizeof(list), "Licencas", "Cargo publico", value, "concurso/alvara RP", "nivel 3+");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgLicensePoliceCost));
    Config_AddEconomyLine(list, sizeof(list), "Licencas", "Porte de arma", value, "Ammu-Nation e trabalho policial", "nivel 3+");

    format(value, sizeof(value), "$%d", Cfg_Price(gCfgHospitalPlanCost));
    Config_AddEconomyLine(list, sizeof(list), "Saude", "Plano mensal", value, "ANS/reajustes reais", "mensal RP reduzido");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgHospitalTreatCost));
    Config_AddEconomyLine(list, sizeof(list), "Saude", "Tratamento", value, "consulta particular BR", "escala RP");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgMedicineCost));
    Config_AddEconomyLine(list, sizeof(list), "Saude", "Remedio", value, "farmacia BR", "cesta media RP");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgSurgeryCost));
    Config_AddEconomyLine(list, sizeof(list), "Saude", "Cirurgia", value, "procedimento privado", "bem reduzido para jogabilidade");

    format(value, sizeof(value), "$%d", Cfg_Price(gCfgBankOpenCost));
    Config_AddEconomyLine(list, sizeof(list), "Banco", "Abrir conta", value, "banco digital baixo custo", "taxa RP");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgBankCardCost));
    Config_AddEconomyLine(list, sizeof(list), "Banco", "Cartao virtual", value, "emissao/cartao", "taxa RP");
    format(value, sizeof(value), "%d%%", gCfgBankLoanInterest);
    Config_AddEconomyLine(list, sizeof(list), "Banco", "Juros emprestimo", value, "credito pessoal BR", "mensal/contrato RP");

    format(value, sizeof(value), "$%d", Cfg_Price(gCfgBillWaterCost));
    Config_AddEconomyLine(list, sizeof(list), "Contas", "Agua", value, "conta residencial BR", "mensal RP");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgBillElectricCost));
    Config_AddEconomyLine(list, sizeof(list), "Contas", "Energia", value, "conta residencial BR", "mensal RP");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgHomeSolarInstallCost));
    Config_AddEconomyLine(list, sizeof(list), "Contas", "Energia solar", value, "instalacao residencial", "desconto na luz");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgBillInternetCost));
    Config_AddEconomyLine(list, sizeof(list), "Contas", "Internet", value, "plano banda larga BR", "mensal RP");

    format(value, sizeof(value), "$%d", Cfg_Price(gCfgBusinessOpenCost));
    Config_AddEconomyLine(list, sizeof(list), "Empresas", "Abrir empresa", value, "MEI/alvara/registro", "escala RP");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgBusinessEmployeeCost));
    Config_AddEconomyLine(list, sizeof(list), "Empresas", "Contratar funcionario", value, "admissao/treino", "custo inicial RP");
    format(value, sizeof(value), "$%d", Cfg_Price(gCfgBusinessSalaryCost));
    Config_AddEconomyLine(list, sizeof(list), "Empresas", "Salario funcionario", value, "folha mensal", "mensal RP");

    ShowPlayerDialog(playerid, DIALOG_ECONOMY_TABLE, DIALOG_STYLE_TABLIST_HEADERS, "Tabela economica central", list, "Fechar", "");
    return 1;
}

stock Config_HandleCommands(playerid, cmdtext[])
{
    new command[32];
    new loaded;
    new message[128];

    GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/configserver", true) == 0 || strcmp(command, "/cfgserver", true) == 0)
    {
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
        {
            return SendNoPermission(playerid);
        }

        return Config_ShowStatus(playerid);
    }

    if (strcmp(command, "/tabelaeconomia", true) == 0 || strcmp(command, "/precos", true) == 0 || strcmp(command, "/economiabase", true) == 0 || strcmp(command, "/economia", true) == 0)
    {
        return Config_ShowEconomyTable(playerid);
    }

    if (strcmp(command, "/reloadconfig", true) == 0 || strcmp(command, "/reloadcfg", true) == 0)
    {
        if (!HasAdminLevel(playerid, ADMIN_LEVEL_OWNER))
        {
            return SendNoPermission(playerid);
        }

        loaded = LoadGameConfig();
        format(message, sizeof(message), "Configuracao recarregada: %d chave(s). Timers novos tambem aplicam ao reiniciar.", loaded);
        SendClientMessage(playerid, COLOR_GREEN, message);
        WritePlayerLog(LOG_ADMIN_FILE, "CONFIG_RELOAD", playerid, message);
        return 1;
    }

    return 0;
}
