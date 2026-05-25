#if defined _nova_bank_included
    #endinput
#endif
#define _nova_bank_included

#define MAX_BANK_DIALOG_ACTIONS     (12)
#define BANK_ACTION_STATUS          (1)
#define BANK_ACTION_DEPOSIT         (2)
#define BANK_ACTION_WITHDRAW        (3)
#define BANK_ACTION_PIX             (4)
#define BANK_ACTION_SALARY          (5)
#define BANK_ACTION_FINES           (6)
#define BANK_ACTION_CARD            (7)
#define BANK_ACTION_MANAGER         (8)
#define BANK_ACTION_STATEMENT       (9)
#define BANK_LOAN_DUE_INTERVAL_DAYS (30)
#define BANK_LOAN_MIN_INSTALLMENTS  (4)
#define BANK_LOAN_MAX_INSTALLMENTS  (12)
#define BANK_LOAN_EARLY_DISCOUNT    (5)

new gBankPixTarget[MAX_PLAYERS];
new gBankDialogMode[MAX_PLAYERS];
new gBankDialogActions[MAX_PLAYERS][MAX_BANK_DIALOG_ACTIONS];
new gBankDialogActionCount[MAX_PLAYERS];
new gBankLastPaymentAmount[MAX_PLAYERS];
new gBankLastPaymentCash[MAX_PLAYERS];
new gBankLastPaymentBank[MAX_PLAYERS];

stock Bank_RequireAccount(playerid)
{
    if (!PlayerInfo[playerid][pBankAccount])
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao possui conta bancaria. Va ao Banco Central para abrir uma conta.");
        return 0;
    }
    return 1;
}

stock Bank_GetLoanLimit(playerid)
{
    new score = Life_GetBankScore(playerid);
    new limit = 1000 + (score * 35) + (PlayerInfo[playerid][pLevel] * 1000);

    if (PlayerInfo[playerid][pDocuments])
    {
        limit += 2500;
    }

    if (PlayerInfo[playerid][pJob] != JOB_NONE)
    {
        limit += 3000;
    }

    if (PlayerInfo[playerid][pFines] > 0)
    {
        limit -= PlayerInfo[playerid][pFines] / 3;
    }

    if (limit < gCfgBankLoanMin)
    {
        limit = gCfgBankLoanMin;
    }

    return limit;
}

stock Bank_ResetLastPayment(playerid)
{
    gBankLastPaymentAmount[playerid] = 0;
    gBankLastPaymentCash[playerid] = 0;
    gBankLastPaymentBank[playerid] = 0;
    return 1;
}

stock Bank_NormalizeBalance(playerid)
{
    if (PlayerInfo[playerid][pBankMoney] < 0)
    {
        PlayerInfo[playerid][pBankMoney] = 0;
    }
    return PlayerInfo[playerid][pBankMoney];
}

stock Bank_GetAvailablePaymentBalance(playerid)
{
    new cash = SyncPlayerCash(playerid);

    if (!PlayerInfo[playerid][pBankAccount])
    {
        return cash;
    }

    return cash + Bank_NormalizeBalance(playerid);
}

stock Bank_FormatLastPaymentSource(playerid, output[], size = sizeof(output))
{
    if (gBankLastPaymentCash[playerid] > 0 && gBankLastPaymentBank[playerid] > 0)
    {
        format(output, size, "carteira $%d + banco $%d", gBankLastPaymentCash[playerid], gBankLastPaymentBank[playerid]);
        return 1;
    }

    if (gBankLastPaymentBank[playerid] > 0)
    {
        format(output, size, "banco $%d", gBankLastPaymentBank[playerid]);
        return 1;
    }

    format(output, size, "carteira $%d", gBankLastPaymentCash[playerid]);
    return 1;
}

stock Bank_CeilDiv(value, divisor)
{
    if (value <= 0)
    {
        return 0;
    }
    if (divisor <= 1)
    {
        return value;
    }
    return (value + divisor - 1) / divisor;
}

stock Bank_GetLoanInterest(playerid, amount)
{
    new score = Life_GetBankScore(playerid);
    new interest = gCfgBankLoanInterest;
    new limit = Bank_GetLoanLimit(playerid);

    if (score < 450) interest += 12;
    else if (score < 600) interest += 7;
    else if (score >= 850) interest -= 5;
    else if (score >= 750) interest -= 3;

    if (PlayerInfo[playerid][pJob] == JOB_NONE) interest += 4;
    if (amount > ((limit * 75) / 100)) interest += 3;
    if (PlayerInfo[playerid][pBankBadHistory] > PlayerInfo[playerid][pBankGoodHistory]) interest += 3;

    if (interest < 3) interest = 3;
    return interest;
}

stock Bank_GetLoanInstallmentCount(playerid, amount)
{
    new score = Life_GetBankScore(playerid);
    new installments = BANK_LOAN_MIN_INSTALLMENTS;
    new configuredMin = Bank_CeilDiv(100, gCfgBillLoanPercent);

    if (amount > 6000) installments = 6;
    if (amount > 15000) installments = 8;
    if (score >= 700) installments += 2;
    if (score >= 850) installments += 2;
    if (configuredMin > installments) installments = configuredMin;
    if (PlayerInfo[playerid][pJob] == JOB_NONE && installments > BANK_LOAN_MIN_INSTALLMENTS)
    {
        installments -= 2;
    }

    if (installments < BANK_LOAN_MIN_INSTALLMENTS) installments = BANK_LOAN_MIN_INSTALLMENTS;
    if (installments > BANK_LOAN_MAX_INSTALLMENTS) installments = BANK_LOAN_MAX_INSTALLMENTS;
    return installments;
}

stock Bank_GetLoanRemInst(playerid)
{
    new remaining = PlayerInfo[playerid][pBankLoanInstallments] - PlayerInfo[playerid][pLoanInstallmentsPaid];

    if (remaining < 1)
    {
        remaining = 1;
    }
    return remaining;
}

stock Bank_NormalizeLoanData(playerid)
{
    new remainingInstallments;

    if (PlayerInfo[playerid][pBankLoan] <= 0)
    {
        PlayerInfo[playerid][pBankLoan] = 0;
        PlayerInfo[playerid][pBankLoanOriginal] = 0;
        PlayerInfo[playerid][pBankLoanInstallmentValue] = 0;
        PlayerInfo[playerid][pBankLoanInstallments] = 0;
        PlayerInfo[playerid][pBankLoanNextDueDay] = 0;
        PlayerInfo[playerid][pBillLoanInstallmentDue] = 0;
        PlayerInfo[playerid][pLoanInstallmentsPaid] = 0;
        return 1;
    }

    if (PlayerInfo[playerid][pBankLoanOriginal] <= 0)
    {
        PlayerInfo[playerid][pBankLoanOriginal] = PlayerInfo[playerid][pBankLoan];
    }
    if (PlayerInfo[playerid][pBankLoanInstallments] <= 0)
    {
        PlayerInfo[playerid][pBankLoanInstallments] = BANK_LOAN_MIN_INSTALLMENTS;
    }
    if (PlayerInfo[playerid][pLoanInstallmentsPaid] < 0)
    {
        PlayerInfo[playerid][pLoanInstallmentsPaid] = 0;
    }
    if (PlayerInfo[playerid][pLoanInstallmentsPaid] >= PlayerInfo[playerid][pBankLoanInstallments])
    {
        PlayerInfo[playerid][pLoanInstallmentsPaid] = PlayerInfo[playerid][pBankLoanInstallments] - 1;
    }

    remainingInstallments = Bank_GetLoanRemInst(playerid);
    if (PlayerInfo[playerid][pBankLoanInstallmentValue] <= 0)
    {
        PlayerInfo[playerid][pBankLoanInstallmentValue] = Bank_CeilDiv(PlayerInfo[playerid][pBankLoan], remainingInstallments);
    }
    if (PlayerInfo[playerid][pBankLoanNextDueDay] <= 0)
    {
        PlayerInfo[playerid][pBankLoanNextDueDay] = GetBrasiliaDayStamp() + BANK_LOAN_DUE_INTERVAL_DAYS;
    }
    return 1;
}

stock Bank_GenerateLoanInstallment(playerid, today = 0, notify = 0)
{
    new amount;
    new message[144];
    new logLine[128];

    if (today <= 0)
    {
        today = GetBrasiliaDayStamp();
    }

    Bank_NormalizeLoanData(playerid);
    if (PlayerInfo[playerid][pBankLoan] <= 0)
    {
        return 0;
    }

    if (PlayerInfo[playerid][pBillLoanInstallmentDue] > 0)
    {
        return 0;
    }

    if (today < PlayerInfo[playerid][pBankLoanNextDueDay])
    {
        return 0;
    }

    amount = PlayerInfo[playerid][pBankLoanInstallmentValue];
    if (amount <= 0)
    {
        amount = Bank_CeilDiv(PlayerInfo[playerid][pBankLoan], Bank_GetLoanRemInst(playerid));
    }
    if (amount > PlayerInfo[playerid][pBankLoan])
    {
        amount = PlayerInfo[playerid][pBankLoan];
    }

    PlayerInfo[playerid][pBillLoanInstallmentDue] = amount;
    PlayerInfo[playerid][pBankLoanNextDueDay] = today + BANK_LOAN_DUE_INTERVAL_DAYS;
    PlayerInfo[playerid][pBillDueDay] = today + gCfgBillDueDays;
    PlayerInfo[playerid][pBillLateChargeDay] = 0;

    format(logLine, sizeof(logLine), "loan_installment_due amount=%d remaining_debt=%d paid=%d/%d next=%d", amount, PlayerInfo[playerid][pBankLoan], PlayerInfo[playerid][pLoanInstallmentsPaid], PlayerInfo[playerid][pBankLoanInstallments], PlayerInfo[playerid][pBankLoanNextDueDay]);
    WritePlayerLog(LOG_MONEY_FILE, "BANK_LOAN", playerid, logLine);

    if (notify)
    {
        format(message, sizeof(message), "Banco: nova parcela de emprestimo gerada: $%d. Vencimento em %d dia(s).", amount, gCfgBillDueDays);
        SendClientMessage(playerid, COLOR_ORANGE, message);
    }
    return amount;
}

stock Bank_RegisterLoanPay(playerid, amount)
{
    new reduction;
    new logLine[128];

    if (amount <= 0)
    {
        return 0;
    }

    Bank_NormalizeLoanData(playerid);
    if (PlayerInfo[playerid][pBankLoan] <= 0)
    {
        return 0;
    }

    reduction = amount;
    if (reduction > PlayerInfo[playerid][pBankLoan])
    {
        reduction = PlayerInfo[playerid][pBankLoan];
    }

    PlayerInfo[playerid][pBankLoan] -= reduction;
    PlayerInfo[playerid][pLoanInstallmentsPaid]++;
    if (PlayerInfo[playerid][pLoanInstallmentsPaid] > PlayerInfo[playerid][pBankLoanInstallments])
    {
        PlayerInfo[playerid][pLoanInstallmentsPaid] = PlayerInfo[playerid][pBankLoanInstallments];
    }

    if (PlayerInfo[playerid][pBankLoan] <= 0)
    {
        PlayerInfo[playerid][pBankGoodHistory] += 2;
        PlayerInfo[playerid][pBankLoan] = 0;
        PlayerInfo[playerid][pBankLoanOriginal] = 0;
        PlayerInfo[playerid][pBankLoanInstallmentValue] = 0;
        PlayerInfo[playerid][pBankLoanInstallments] = 0;
        PlayerInfo[playerid][pBankLoanNextDueDay] = 0;
        PlayerInfo[playerid][pBillLoanInstallmentDue] = 0;
    }
    else
    {
        PlayerInfo[playerid][pBankGoodHistory]++;
    }

    Life_GetBankScore(playerid);
    format(logLine, sizeof(logLine), "loan_installment_paid amount=%d reduction=%d debt=%d paid=%d/%d", amount, reduction, PlayerInfo[playerid][pBankLoan], PlayerInfo[playerid][pLoanInstallmentsPaid], PlayerInfo[playerid][pBankLoanInstallments]);
    WritePlayerLog(LOG_MONEY_FILE, "BANK_LOAN", playerid, logLine);
    return 1;
}

stock Bank_ShowStatus(playerid)
{
    new message[144];
    new cash = SyncPlayerCash(playerid);
    new available = Bank_GetAvailablePaymentBalance(playerid);

    Bank_NormalizeLoanData(playerid);

    if (!PlayerInfo[playerid][pBankAccount])
    {
        format(message, sizeof(message), "Banco: conta fechada | Carteira: $%d | Va ao Banco Central para abrir conta.", cash);
        SendClientMessage(playerid, COLOR_BLUE, message);
        return 1;
    }

    format(message, sizeof(message), "Carteira: $%d | Banco: $%d | Disponivel p/ pagamentos: $%d", cash, PlayerInfo[playerid][pBankMoney], available);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Salario pendente: $%d | Multas: $%d | Pontos CNH: %d | Boletos/dividas: $%d", PlayerInfo[playerid][pSalary], PlayerInfo[playerid][pFines], PlayerInfo[playerid][pTrafficPoints], Life_BillTotal(playerid));
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Cartao virtual: %s | Emprestimo: $%d | Limite credito: $%d", PlayerInfo[playerid][pBankCard] ? ("ativo") : ("nao"), PlayerInfo[playerid][pBankLoan], Bank_GetLoanLimit(playerid));
    SendClientMessage(playerid, COLOR_BLUE, message);
    if (PlayerInfo[playerid][pBankLoan] > 0)
    {
        format(message, sizeof(message), "Contrato: parcela $%d | pagas %d/%d | proxima cobranca dia %d", PlayerInfo[playerid][pBankLoanInstallmentValue], PlayerInfo[playerid][pLoanInstallmentsPaid], PlayerInfo[playerid][pBankLoanInstallments], PlayerInfo[playerid][pBankLoanNextDueDay]);
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    format(message, sizeof(message), "Score: %d/1000 | Boletos/dividas: $%d | Nome: %s", PlayerInfo[playerid][pBankScore], Life_BillTotal(playerid), PlayerInfo[playerid][pDirtyName] ? ("restrito") : ("regular"));
    SendClientMessage(playerid, COLOR_BLUE, message);
    Life_AddMissionProgress(playerid, 3, 1);
    return 1;
}

stock Bank_ShowStatement(playerid)
{
    new message[144];
    new totalDebt = Life_BillTotal(playerid);
    new cash = SyncPlayerCash(playerid);

    Bank_NormalizeLoanData(playerid);
    Life_GetBankScore(playerid);
    SendClientMessage(playerid, COLOR_BLUE, "Extrato simples da conta:");
    format(message, sizeof(message), "Carteira $%d | Banco $%d | Salario pendente $%d | Emprestimo $%d", cash, PlayerInfo[playerid][pBankMoney], PlayerInfo[playerid][pSalary], PlayerInfo[playerid][pBankLoan]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    if (PlayerInfo[playerid][pBankLoan] > 0)
    {
        format(message, sizeof(message), "Emprestimo: original $%d | parcela $%d | pagas %d/%d | pendente agora $%d", PlayerInfo[playerid][pBankLoanOriginal], PlayerInfo[playerid][pBankLoanInstallmentValue], PlayerInfo[playerid][pLoanInstallmentsPaid], PlayerInfo[playerid][pBankLoanInstallments], PlayerInfo[playerid][pBillLoanInstallmentDue]);
        SendClientMessage(playerid, COLOR_BLUE, message);
    }
    format(message, sizeof(message), "Entradas: historico positivo %d | Saidas/risco: historico negativo %d | multas $%d | pontos CNH %d", PlayerInfo[playerid][pBankGoodHistory], PlayerInfo[playerid][pBankBadHistory], PlayerInfo[playerid][pFines], PlayerInfo[playerid][pTrafficPoints]);
    SendClientMessage(playerid, COLOR_BLUE, message);
    format(message, sizeof(message), "Pendencias civis $%d | Score cidadao %d/1000 | Limite credito $%d", totalDebt, PlayerInfo[playerid][pBankScore], Bank_GetLoanLimit(playerid));
    SendClientMessage(playerid, COLOR_BLUE, message);
    SendClientMessage(playerid, COLOR_GRAY, "Movimentos detalhados ficam em scriptfiles/log_money_bank.txt para a administracao.");
    Life_AddMissionProgress(playerid, 3, 1);
    return 1;
}

stock Bank_Deposit(playerid, amount)
{
    new message[96];
    new logLine[144];

    if (!Bank_RequireAccount(playerid))
    {
        return 1;
    }

    if (amount <= 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Valor invalido.");
        return 1;
    }

    if (!TakePlayerCashReason(playerid, amount, 0, "bank_deposit"))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao tem esse valor em maos.");
        return 1;
    }

    PlayerInfo[playerid][pBankMoney] += amount;
    SaveAccountNow(playerid, 0);
    format(logLine, sizeof(logLine), "deposit amount=%d bank=%d", amount, PlayerInfo[playerid][pBankMoney]);
    WritePlayerLog(LOG_MONEY_FILE, "BANK", playerid, logLine);
    format(message, sizeof(message), "Deposito feito: $%d. Saldo bancario: $%d.", amount, PlayerInfo[playerid][pBankMoney]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Bank_Withdraw(playerid, amount)
{
    new message[96];
    new logLine[96];

    if (!Bank_RequireAccount(playerid))
    {
        return 1;
    }

    if (amount <= 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Valor invalido.");
        return 1;
    }

    if (PlayerInfo[playerid][pBankMoney] < amount)
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo bancario insuficiente.");
        return 1;
    }

    PlayerInfo[playerid][pBankMoney] -= amount;
    GivePlayerCashReason(playerid, amount, 0, "bank_withdraw");
    SaveAccountNow(playerid, 0);
    format(logLine, sizeof(logLine), "withdraw amount=%d bank=%d", amount, PlayerInfo[playerid][pBankMoney]);
    WritePlayerLog(LOG_MONEY_FILE, "BANK", playerid, logLine);
    format(message, sizeof(message), "Saque feito: $%d. Saldo bancario: $%d.", amount, PlayerInfo[playerid][pBankMoney]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock Bank_Transfer(playerid, targetid, amount)
{
    new message[128];
    new logLine[128];

    if (!Bank_RequireAccount(playerid))
    {
        return 1;
    }

    if (amount <= 0 || amount > gCfgBankTransferLimit)
    {
        SendClientMessage(playerid, COLOR_RED, "Valor de PIX invalido.");
        return 1;
    }

    if (!IsValidConnectedPlayer(targetid) || !PlayerInfo[targetid][pLogged])
    {
        SendClientMessage(playerid, COLOR_RED, "Jogador destino invalido ou nao logado.");
        return 1;
    }

    if (!PlayerInfo[targetid][pBankAccount])
    {
        SendClientMessage(playerid, COLOR_RED, "O destinatario nao possui conta bancaria aberta.");
        return 1;
    }

    if (PlayerInfo[playerid][pBankMoney] < amount)
    {
        SendClientMessage(playerid, COLOR_RED, "Saldo bancario insuficiente.");
        return 1;
    }

    PlayerInfo[playerid][pBankMoney] -= amount;
    PlayerInfo[targetid][pBankMoney] += amount;
    SaveAccountNow(playerid, 0);
    SaveAccountNow(targetid, 0);
    format(logLine, sizeof(logLine), "pix_sent target=%d amount=%d bank=%d", targetid, amount, PlayerInfo[playerid][pBankMoney]);
    WritePlayerLog(LOG_MONEY_FILE, "BANK", playerid, logLine);
    format(logLine, sizeof(logLine), "pix_received from=%d amount=%d bank=%d", playerid, amount, PlayerInfo[targetid][pBankMoney]);
    WritePlayerLog(LOG_MONEY_FILE, "BANK", targetid, logLine);

    format(message, sizeof(message), "PIX enviado ao ID %d: $%d.", targetid, amount);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(message, sizeof(message), "Voce recebeu PIX do ID %d: $%d.", playerid, amount);
    SendClientMessage(targetid, COLOR_GREEN, message);
    return 1;
}

stock Bank_TakePaymentReason(playerid, amount, saveNow, reason[])
{
    new cash;
    new bankBalance;
    new available;
    new cashUsed;
    new bankUsed;
    new logLine[96];

    Bank_ResetLastPayment(playerid);

    if (amount <= 0)
    {
        return 1;
    }

    cash = SyncPlayerCash(playerid);
    bankBalance = Bank_NormalizeBalance(playerid);
    available = cash;
    if (PlayerInfo[playerid][pBankAccount])
    {
        available += bankBalance;
    }

    if (available < amount)
    {
        format(logLine, sizeof(logLine), "payment_denied amount=%d cash=%d bank=%d available=%d reason=%s", amount, cash, PlayerInfo[playerid][pBankAccount] ? (bankBalance) : (0), available, reason);
        WritePlayerLog(LOG_MONEY_FILE, "PAYMENT", playerid, logLine);
        return 0;
    }

    cashUsed = amount;
    if (cashUsed > cash)
    {
        cashUsed = cash;
    }
    bankUsed = amount - cashUsed;

    if (cashUsed > 0 && !TakePlayerCashReason(playerid, cashUsed, 0, reason))
    {
        format(logLine, sizeof(logLine), "payment_abort amount=%d cash=%d bank=%d reason=%s", amount, cash, bankBalance, reason);
        WritePlayerLog(LOG_MONEY_FILE, "PAYMENT", playerid, logLine);
        return 0;
    }

    if (bankUsed > 0)
    {
        PlayerInfo[playerid][pBankMoney] -= bankUsed;
        if (PlayerInfo[playerid][pBankMoney] < 0)
        {
            PlayerInfo[playerid][pBankMoney] = 0;
        }
    }

    gBankLastPaymentAmount[playerid] = amount;
    gBankLastPaymentCash[playerid] = cashUsed;
    gBankLastPaymentBank[playerid] = bankUsed;
    format(logLine, sizeof(logLine), "payment amount=%d cash_used=%d bank_used=%d bank=%d reason=%s", amount, cashUsed, bankUsed, PlayerInfo[playerid][pBankMoney], reason);
    WritePlayerLog(LOG_MONEY_FILE, "PAYMENT", playerid, logLine);

    if (saveNow)
    {
        SaveAccountNow(playerid, 0);
    }
    return 1;
}

stock Bank_TakePayment(playerid, amount, saveNow = 1)
{
    return Bank_TakePaymentReason(playerid, amount, saveNow, "bank_payment");
}

stock Bank_AddSalary(playerid, amount)
{
    if (amount <= 0)
    {
        return 0;
    }

    PlayerInfo[playerid][pSalary] += amount;
    PlayerInfo[playerid][pIncomeRegistered] += amount;
    return 1;
}

stock Bank_ClaimSalary(playerid)
{
    new amount = PlayerInfo[playerid][pSalary];
    new message[96];
    new logLine[96];

    if (!Bank_RequireAccount(playerid))
    {
        return 1;
    }

    if (amount <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao tem salario pendente.");
        return 1;
    }

    PlayerInfo[playerid][pSalary] = 0;
    PlayerInfo[playerid][pBankMoney] += amount;
    SaveAccountNow(playerid, 0);
    format(logLine, sizeof(logLine), "salary amount=%d bank=%d", amount, PlayerInfo[playerid][pBankMoney]);
    WritePlayerLog(LOG_MONEY_FILE, "BANK", playerid, logLine);
    format(message, sizeof(message), "Salario recebido na conta bancaria: $%d.", amount);
    SendClientMessage(playerid, COLOR_GREEN, message);
    Life_AddMissionProgress(playerid, 3, 1);
    return 1;
}

stock Bank_PayFines(playerid)
{
    new amount = PlayerInfo[playerid][pFines];
    new message[96];
    new logLine[96];
    new source[64];

    if (amount <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui multas pendentes.");
        return 1;
    }

    if (!Bank_TakePayment(playerid, amount, 0))
    {
        SendClientMessage(playerid, COLOR_RED, "Voce nao tem dinheiro suficiente para pagar as multas.");
        return 1;
    }

    PlayerInfo[playerid][pFines] = 0;
    if (PlayerInfo[playerid][pWanted] > 0)
    {
        PlayerInfo[playerid][pWanted]--;
    }
    SaveAccountNow(playerid, 0);
    Bank_FormatLastPaymentSource(playerid, source, sizeof(source));
    format(logLine, sizeof(logLine), "fines_paid amount=%d wanted=%d", amount, PlayerInfo[playerid][pWanted]);
    WritePlayerLog(LOG_MONEY_FILE, "BANK", playerid, logLine);
    format(message, sizeof(message), "Multas pagas: $%d (%s).", amount, source);
    SendClientMessage(playerid, COLOR_GREEN, message);
    Life_AddMissionProgress(playerid, 4, 1);
    Life_CheckAchievements(playerid);
    return 1;
}

stock Bank_OpenAccount(playerid)
{
    new message[128];
    new logLine[96];

    if (PlayerInfo[playerid][pBankAccount])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce ja possui conta bancaria aberta.");
        return 1;
    }

    if (!PlayerInfo[playerid][pDocuments])
    {
        SendClientMessage(playerid, COLOR_RED, "O gerente pediu seus documentos. Emita documentos na Prefeitura primeiro.");
        return 1;
    }

    if (!TakePlayerCashReason(playerid, Cfg_Price(gCfgBankOpenCost), 0, "bank_open_account"))
    {
        format(message, sizeof(message), "Abertura de conta custa $%d em dinheiro vivo.", Cfg_Price(gCfgBankOpenCost));
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    PlayerInfo[playerid][pBankAccount] = 1;
    PlayerInfo[playerid][pBankCard] = 0;
    PlayerInfo[playerid][pBankLoan] = 0;
    SaveAccountNow(playerid, 0);
    format(logLine, sizeof(logLine), "open_account cost=%d", Cfg_Price(gCfgBankOpenCost));
    WritePlayerLog(LOG_MONEY_FILE, "BANK", playerid, logLine);
    format(message, sizeof(message), "Conta aberta no Banco Central. Tarifa de abertura: $%d.", Cfg_Price(gCfgBankOpenCost));
    SendClientMessage(playerid, COLOR_GREEN, message);
    Life_TutorialAdvance(playerid, 4);
    Life_AddMissionProgress(playerid, 3, 1);
    return 1;
}

stock Bank_CloseAccount(playerid)
{
    if (!PlayerInfo[playerid][pBankAccount])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui conta bancaria aberta.");
        return 1;
    }

    if (PlayerInfo[playerid][pBankMoney] > 0 || PlayerInfo[playerid][pSalary] > 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Saque seu saldo e receba salarios pendentes antes de fechar a conta.");
        return 1;
    }

    if (PlayerInfo[playerid][pBankLoan] > 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Quite seu emprestimo antes de fechar a conta.");
        return 1;
    }

    PlayerInfo[playerid][pBankAccount] = 0;
    PlayerInfo[playerid][pBankCard] = 0;
    SaveAccountNow(playerid, 0);
    WritePlayerLog(LOG_MONEY_FILE, "BANK", playerid, "close_account");
    SendClientMessage(playerid, COLOR_GREEN, "Conta bancaria encerrada pelo gerente.");
    return 1;
}

stock Bank_RequestVirtualCard(playerid)
{
    new message[128];

    if (!Bank_RequireAccount(playerid))
    {
        return 1;
    }

    if (PlayerInfo[playerid][pBankCard])
    {
        SendClientMessage(playerid, COLOR_GRAY, "Seu cartao virtual ja esta ativo.");
        return 1;
    }

    if (!Bank_TakePayment(playerid, Cfg_Price(gCfgBankCardCost), 0))
    {
        format(message, sizeof(message), "Emissao de cartao virtual custa $%d.", Cfg_Price(gCfgBankCardCost));
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    PlayerInfo[playerid][pBankCard] = 1;
    SaveAccountNow(playerid, 0);
    WritePlayerLog(LOG_MONEY_FILE, "BANK", playerid, "virtual_card_issued");
    SendClientMessage(playerid, COLOR_GREEN, "Cartao virtual emitido. Voce pode usar banco pelo celular e PIX.");
    return 1;
}

stock Bank_RequestLoan(playerid, amount)
{
    new limit = Bank_GetLoanLimit(playerid);
    new score = PlayerInfo[playerid][pBankScore];
    new interest;
    new debt;
    new installments;
    new installmentValue;
    new message[144];
    new logLine[144];

    if (!Bank_RequireAccount(playerid))
    {
        return 1;
    }

    if (!PlayerInfo[playerid][pDocuments])
    {
        SendClientMessage(playerid, COLOR_RED, "O gerente exige documentos emitidos para liberar credito.");
        return 1;
    }

    if (PlayerInfo[playerid][pBankLoan] > 0)
    {
        SendClientMessage(playerid, COLOR_RED, "Voce ja possui emprestimo ativo. Quite antes de pedir outro.");
        return 1;
    }

    if (score < gCfgBankLoanMinScore || PlayerInfo[playerid][pWanted] > 0 || Life_IsDebtBlocked(playerid))
    {
        PlayerInfo[playerid][pBankBadHistory]++;
        Life_GetBankScore(playerid);
        SaveAccountNow(playerid, 0);
        format(message, sizeof(message), "Emprestimo negado. Score %d/%d, ficha ou restricao financeira pendente.", score, gCfgBankLoanMinScore);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    if (amount < gCfgBankLoanMin || amount > limit)
    {
        format(message, sizeof(message), "Valor invalido. Seu limite atual e de $%d e o minimo e $%d.", limit, gCfgBankLoanMin);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    interest = Bank_GetLoanInterest(playerid, amount);
    installments = Bank_GetLoanInstallmentCount(playerid, amount);
    debt = amount + ((amount * interest) / 100);
    if (debt <= amount && interest > 0)
    {
        debt = amount + 1;
    }
    installmentValue = Bank_CeilDiv(debt, installments);

    PlayerInfo[playerid][pBankMoney] += amount;
    PlayerInfo[playerid][pBankLoan] = debt;
    PlayerInfo[playerid][pBankLoanOriginal] = debt;
    PlayerInfo[playerid][pBankLoanInstallmentValue] = installmentValue;
    PlayerInfo[playerid][pBankLoanInstallments] = installments;
    PlayerInfo[playerid][pBankLoanNextDueDay] = GetBrasiliaDayStamp() + BANK_LOAN_DUE_INTERVAL_DAYS;
    PlayerInfo[playerid][pBillLoanInstallmentDue] = 0;
    PlayerInfo[playerid][pLoanInstallmentsPaid] = 0;
    Life_GetBankScore(playerid);
    SaveAccountNow(playerid, 0);
    format(logLine, sizeof(logLine), "loan_contract amount=%d debt=%d interest=%d installments=%d installment=%d next=%d bank=%d", amount, debt, interest, installments, installmentValue, PlayerInfo[playerid][pBankLoanNextDueDay], PlayerInfo[playerid][pBankMoney]);
    WritePlayerLog(LOG_MONEY_FILE, "BANK_LOAN", playerid, logLine);

    format(message, sizeof(message), "Emprestimo aprovado: $%d caiu na conta. Total financiado: $%d.", amount, debt);
    SendClientMessage(playerid, COLOR_GREEN, message);
    format(message, sizeof(message), "Contrato: juros %d%% | %d parcela(s) de $%d | primeira cobranca em 30 dias.", interest, installments, installmentValue);
    SendClientMessage(playerid, COLOR_BLUE, message);
    return 1;
}

stock Bank_PayLoan(playerid)
{
    new debt = PlayerInfo[playerid][pBankLoan];
    new discount;
    new amountToPay;
    new message[128];
    new source[64];
    new logLine[128];

    if (!Bank_RequireAccount(playerid))
    {
        return 1;
    }

    Bank_NormalizeLoanData(playerid);
    debt = PlayerInfo[playerid][pBankLoan];

    if (debt <= 0)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao possui emprestimo ativo.");
        return 1;
    }

    if (PlayerInfo[playerid][pBillLoanInstallmentDue] <= 0 && PlayerInfo[playerid][pLoanInstallmentsPaid] < PlayerInfo[playerid][pBankLoanInstallments] - 1)
    {
        discount = (debt * BANK_LOAN_EARLY_DISCOUNT) / 100;
    }
    amountToPay = debt - discount;
    if (amountToPay < 1)
    {
        amountToPay = debt;
        discount = 0;
    }

    if (!Bank_TakePayment(playerid, amountToPay, 0))
    {
        format(message, sizeof(message), "Voce precisa de $%d em dinheiro/banco para quitar o emprestimo.", amountToPay);
        SendClientMessage(playerid, COLOR_RED, message);
        return 1;
    }

    PlayerInfo[playerid][pBankLoan] = 0;
    PlayerInfo[playerid][pBankLoanOriginal] = 0;
    PlayerInfo[playerid][pBankLoanInstallmentValue] = 0;
    PlayerInfo[playerid][pBankLoanInstallments] = 0;
    PlayerInfo[playerid][pBankLoanNextDueDay] = 0;
    PlayerInfo[playerid][pBillLoanInstallmentDue] = 0;
    PlayerInfo[playerid][pLoanInstallmentsPaid]++;
    PlayerInfo[playerid][pBankGoodHistory]++;
    Life_GetBankScore(playerid);
    SaveAccountNow(playerid, 0);
    Bank_FormatLastPaymentSource(playerid, source, sizeof(source));
    format(logLine, sizeof(logLine), "loan_settled debt=%d paid=%d discount=%d source=%s", debt, amountToPay, discount, source);
    WritePlayerLog(LOG_MONEY_FILE, "BANK_LOAN", playerid, logLine);
    format(message, sizeof(message), "Emprestimo quitado: $%d (%s). Desconto: $%d.", amountToPay, source, discount);
    SendClientMessage(playerid, COLOR_GREEN, message);
    Life_CheckAchievements(playerid);
    return 1;
}

stock Bank_ResetDialogActions(playerid)
{
    new index;

    gBankDialogActionCount[playerid] = 0;
    for (index = 0; index < MAX_BANK_DIALOG_ACTIONS; index++)
    {
        gBankDialogActions[playerid][index] = 0;
    }
    return 1;
}

stock Bank_AddDialogAction(playerid, list[], listSize, line[], action)
{
    new slot = gBankDialogActionCount[playerid];

    if (slot >= MAX_BANK_DIALOG_ACTIONS)
    {
        return 0;
    }

    gBankDialogActions[playerid][slot] = action;
    gBankDialogActionCount[playerid]++;
    strcat(list, line, listSize);
    return 1;
}

stock ShowBankDialog(playerid, mode)
{
    new list[1024];
    new line[128];
    new title[48];

    Bank_ResetDialogActions(playerid);
    gBankDialogMode[playerid] = mode;

    format(list, sizeof(list), "Servico\tDetalhe\n");

    format(line, sizeof(line), "Saldo\tConta, salario e pendencias\n");
    Bank_AddDialogAction(playerid, list, sizeof(list), line, BANK_ACTION_STATUS);

    if (mode == BANK_ACCESS_ATM || mode == BANK_ACCESS_BRANCH)
    {
        format(line, sizeof(line), "Depositar\tDinheiro vivo para conta\n");
        Bank_AddDialogAction(playerid, list, sizeof(list), line, BANK_ACTION_DEPOSIT);
        format(line, sizeof(line), "Sacar\tRetirar dinheiro da conta\n");
        Bank_AddDialogAction(playerid, list, sizeof(list), line, BANK_ACTION_WITHDRAW);
    }

    format(line, sizeof(line), "PIX\tEnviar dinheiro por ID\n");
    Bank_AddDialogAction(playerid, list, sizeof(list), line, BANK_ACTION_PIX);
    format(line, sizeof(line), "Salario\tReceber salario pendente\n");
    Bank_AddDialogAction(playerid, list, sizeof(list), line, BANK_ACTION_SALARY);
    format(line, sizeof(line), "Extrato\tResumo financeiro e score\n");
    Bank_AddDialogAction(playerid, list, sizeof(list), line, BANK_ACTION_STATEMENT);
    format(line, sizeof(line), "Multas\tPagar multas salvas\n");
    Bank_AddDialogAction(playerid, list, sizeof(list), line, BANK_ACTION_FINES);
    format(line, sizeof(line), "Cartao virtual\tEmitir ou consultar cartao\n");
    Bank_AddDialogAction(playerid, list, sizeof(list), line, BANK_ACTION_CARD);

    if (mode == BANK_ACCESS_BRANCH)
    {
        format(line, sizeof(line), "Gerente\tConta, encerramento e emprestimos\n");
        Bank_AddDialogAction(playerid, list, sizeof(list), line, BANK_ACTION_MANAGER);
    }

    switch (mode)
    {
        case BANK_ACCESS_ATM: format(title, sizeof(title), "Caixa Eletronico");
        case BANK_ACCESS_BRANCH: format(title, sizeof(title), "Banco Central");
        default: format(title, sizeof(title), "LF Pay - Banco Digital");
    }

    ShowPlayerDialog(playerid, DIALOG_BANK_MENU, DIALOG_STYLE_TABLIST_HEADERS, title, list, "Abrir", "Fechar");
    return 1;
}

stock ShowBankManagerDialog(playerid)
{
    new list[1024];
    new line[128];

    Bank_NormalizeLoanData(playerid);
    format(list, sizeof(list), "Atendimento\tDetalhe\n");
    format(line, sizeof(line), "Abrir conta\tTarifa $%d e documentos\n", Cfg_Price(gCfgBankOpenCost)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Fechar conta\tSem saldo e sem emprestimo\n"); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Cartao virtual\tEmissao $%d\n", Cfg_Price(gCfgBankCardCost)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Solicitar emprestimo\tMin $%d | Limite $%d | juros por score\n", gCfgBankLoanMin, Bank_GetLoanLimit(playerid)); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Pagar parcela\tPendente agora $%d\n", PlayerInfo[playerid][pBillLoanInstallmentDue]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Quitar emprestimo\tDivida $%d | parcela $%d | %d/%d pagas\n", PlayerInfo[playerid][pBankLoan], PlayerInfo[playerid][pBankLoanInstallmentValue], PlayerInfo[playerid][pLoanInstallmentsPaid], PlayerInfo[playerid][pBankLoanInstallments]); strcat(list, line, sizeof(list));
    format(line, sizeof(line), "Status financeiro\tVer conta completa\n"); strcat(list, line, sizeof(list));

    ShowPlayerDialog(playerid, DIALOG_BANK_MANAGER, DIALOG_STYLE_TABLIST_HEADERS, "Gerente do Banco", list, "Selecionar", "Voltar");
    return 1;
}

stock HandleBankMenuDialog(playerid, response, listitem)
{
    new action;

    if (!response)
    {
        return 1;
    }

    if (listitem < 0 || listitem >= gBankDialogActionCount[playerid])
    {
        SendClientMessage(playerid, COLOR_RED, "Opcao bancaria invalida.");
        return 1;
    }

    action = gBankDialogActions[playerid][listitem];
    switch (action)
    {
        case BANK_ACTION_STATUS:
        {
            Bank_ShowStatus(playerid);
        }
        case BANK_ACTION_DEPOSIT:
        {
            ShowPlayerDialog(playerid, DIALOG_BANK_DEPOSIT, DIALOG_STYLE_INPUT, "Deposito", "Digite o valor para depositar na conta.", "Depositar", "Voltar");
        }
        case BANK_ACTION_WITHDRAW:
        {
            ShowPlayerDialog(playerid, DIALOG_BANK_WITHDRAW, DIALOG_STYLE_INPUT, "Saque", "Digite o valor para sacar da conta.", "Sacar", "Voltar");
        }
        case BANK_ACTION_PIX:
        {
            ShowPlayerDialog(playerid, DIALOG_BANK_PIX_TARGET, DIALOG_STYLE_INPUT, "PIX", "Digite o ID do jogador que vai receber o PIX.", "Continuar", "Voltar");
        }
        case BANK_ACTION_SALARY:
        {
            Bank_ClaimSalary(playerid);
        }
        case BANK_ACTION_FINES:
        {
            Bank_PayFines(playerid);
        }
        case BANK_ACTION_STATEMENT:
        {
            Bank_ShowStatement(playerid);
        }
        case BANK_ACTION_CARD:
        {
            Bank_RequestVirtualCard(playerid);
        }
        case BANK_ACTION_MANAGER:
        {
            if (gBankDialogMode[playerid] != BANK_ACCESS_BRANCH)
            {
                SendClientMessage(playerid, COLOR_GRAY, "Gerente disponivel apenas no Banco Central.");
                return 1;
            }
            ShowBankManagerDialog(playerid);
        }
    }
    return 1;
}

stock HandleBankDepositDialog(playerid, response, inputtext[])
{
    if (!response)
    {
        ShowBankDialog(playerid, gBankDialogMode[playerid]);
        return 1;
    }

    if (!IsNumericString(inputtext))
    {
        SendClientMessage(playerid, COLOR_RED, "Digite apenas numeros.");
        return 1;
    }

    Bank_Deposit(playerid, strval(inputtext));
    return 1;
}

stock HandleBankWithdrawDialog(playerid, response, inputtext[])
{
    if (!response)
    {
        ShowBankDialog(playerid, gBankDialogMode[playerid]);
        return 1;
    }

    if (!IsNumericString(inputtext))
    {
        SendClientMessage(playerid, COLOR_RED, "Digite apenas numeros.");
        return 1;
    }

    Bank_Withdraw(playerid, strval(inputtext));
    return 1;
}

stock HandleBankPixTargetDialog(playerid, response, inputtext[])
{
    new targetid;

    if (!response)
    {
        ShowBankDialog(playerid, gBankDialogMode[playerid]);
        return 1;
    }

    if (!ParseTargetPlayer(playerid, inputtext, targetid))
    {
        return 1;
    }

    gBankPixTarget[playerid] = targetid;
    ShowPlayerDialog(playerid, DIALOG_BANK_PIX_AMOUNT, DIALOG_STYLE_INPUT, "PIX", "Digite o valor do PIX.", "Enviar", "Voltar");
    return 1;
}

stock HandleBankPixAmountDialog(playerid, response, inputtext[])
{
    if (!response)
    {
        ShowBankDialog(playerid, gBankDialogMode[playerid]);
        return 1;
    }

    if (!IsNumericString(inputtext))
    {
        SendClientMessage(playerid, COLOR_RED, "Digite apenas numeros.");
        return 1;
    }

    Bank_Transfer(playerid, gBankPixTarget[playerid], strval(inputtext));
    return 1;
}

stock HandleBankManagerDialog(playerid, response, listitem)
{
    if (!response)
    {
        ShowBankDialog(playerid, BANK_ACCESS_BRANCH);
        return 1;
    }

    if (!World_IsPlayerAtBankBranch(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "O gerente atende apenas no Banco Central.");
        return 1;
    }

    if (listitem < 0 || listitem > 6)
    {
        SendClientMessage(playerid, COLOR_RED, "Opcao do gerente expirou. Abra o menu novamente.");
        return ShowBankManagerDialog(playerid);
    }

    switch (listitem)
    {
        case 0:
        {
            Bank_OpenAccount(playerid);
        }
        case 1:
        {
            Bank_CloseAccount(playerid);
        }
        case 2:
        {
            Bank_RequestVirtualCard(playerid);
        }
        case 3:
        {
            new text[192];
            format(text, sizeof(text), "Digite o valor do emprestimo.\nMinimo: $%d\nSeu limite atual: $%d\nJuros variam por score, emprego, historico e valor solicitado.", gCfgBankLoanMin, Bank_GetLoanLimit(playerid));
            ShowPlayerDialog(playerid, DIALOG_BANK_LOAN, DIALOG_STYLE_INPUT, "Gerente - Emprestimo", text, "Solicitar", "Voltar");
        }
        case 4:
        {
            if (PlayerInfo[playerid][pBillLoanInstallmentDue] <= 0)
            {
                Bank_GenerateLoanInstallment(playerid, GetBrasiliaDayStamp(), 1);
            }
            if (PlayerInfo[playerid][pBillLoanInstallmentDue] <= 0)
            {
                SendClientMessage(playerid, COLOR_GRAY, "Nenhuma parcela de emprestimo esta vencida agora.");
                return 1;
            }
            Life_PayBillItem(playerid, 8);
        }
        case 5:
        {
            Bank_PayLoan(playerid);
        }
        case 6:
        {
            Bank_ShowStatus(playerid);
        }
    }
    return 1;
}

stock HandleBankLoanDialog(playerid, response, inputtext[])
{
    if (!response)
    {
        ShowBankManagerDialog(playerid);
        return 1;
    }

    if (!World_IsPlayerAtBankBranch(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "O gerente atende apenas no Banco Central.");
        return 1;
    }

    if (!IsNumericString(inputtext))
    {
        SendClientMessage(playerid, COLOR_RED, "Digite apenas numeros.");
        return 1;
    }

    Bank_RequestLoan(playerid, strval(inputtext));
    return 1;
}

stock HandleBankCommands(playerid, cmdtext[])
{
    new command[32];
    new param[32];
    new param2[32];
    new index;
    new targetid;

    index = GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/banco", true) == 0)
    {
        if (World_IsPlayerAtBankBranch(playerid))
        {
            ShowBankDialog(playerid, BANK_ACCESS_BRANCH);
            return 1;
        }

        if (World_IsPlayerAtAtm(playerid))
        {
            ShowBankDialog(playerid, BANK_ACCESS_ATM);
            return 1;
        }

        Bank_ShowStatus(playerid);
        SendClientMessage(playerid, COLOR_GRAY, "Para operacoes completas, use um caixa eletronico, o Banco Central ou /celular.");
        return 1;
    }

    if (strcmp(command, "/saldo", true) == 0)
    {
        Bank_ShowStatus(playerid);
        return 1;
    }

    if (strcmp(command, "/extrato", true) == 0 || strcmp(command, "/extratobanco", true) == 0)
    {
        Bank_ShowStatement(playerid);
        return 1;
    }

    if (strcmp(command, "/caixa", true) == 0 || strcmp(command, "/atm", true) == 0)
    {
        if (!World_IsPlayerAtAtm(playerid))
        {
            SendClientMessage(playerid, COLOR_GRAY, "Voce precisa estar perto de um caixa eletronico marcado com $ no mapa.");
            return 1;
        }

        ShowBankDialog(playerid, BANK_ACCESS_ATM);
        return 1;
    }

    if (strcmp(command, "/depositar", true) == 0)
    {
        if (!World_IsPlayerAtBankService(playerid))
        {
            SendClientMessage(playerid, COLOR_GRAY, "Use deposito em um caixa eletronico ou no Banco Central.");
            return 1;
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/depositar [valor]");
        }

        Bank_Deposit(playerid, strval(param));
        return 1;
    }

    if (strcmp(command, "/sacar", true) == 0)
    {
        if (!World_IsPlayerAtBankService(playerid))
        {
            SendClientMessage(playerid, COLOR_GRAY, "Use saque em um caixa eletronico ou no Banco Central.");
            return 1;
        }

        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/sacar [valor]");
        }

        Bank_Withdraw(playerid, strval(param));
        return 1;
    }

    if (strcmp(command, "/transferir", true) == 0 || strcmp(command, "/pix", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !GetNextParam(cmdtext, index, param2, sizeof(param2)))
        {
            return SendUsage(playerid, "/pix [id] [valor]");
        }

        if (!ParseTargetPlayer(playerid, param, targetid) || !IsNumericString(param2))
        {
            return 1;
        }

        Bank_Transfer(playerid, targetid, strval(param2));
        return 1;
    }

    if (strcmp(command, "/salario", true) == 0)
    {
        Bank_ClaimSalary(playerid);
        return 1;
    }

    if (strcmp(command, "/pagarmultas", true) == 0 || strcmp(command, "/pagarmulta", true) == 0)
    {
        Bank_PayFines(playerid);
        return 1;
    }

    return 0;
}
