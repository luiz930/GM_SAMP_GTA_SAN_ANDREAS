#if defined _nova_traffic_fines_included
    #endinput
#endif
#define _nova_traffic_fines_included

#define TRAFFIC_FINE_ARTICLE_SIZE   (16)
#define TRAFFIC_FINE_TITLE_SIZE     (64)

enum eTrafficFineCatalog
{
    trafficFineArticle[TRAFFIC_FINE_ARTICLE_SIZE],
    trafficFineTitle[TRAFFIC_FINE_TITLE_SIZE],
    trafficFineSeverity,
    trafficFineMultiplier
}

new gTrafficFineCatalog[][eTrafficFineCatalog] =
{
    { "Art. 162 I", "Dirigir sem CNH/PPD/ACC", TRAFFIC_FINE_VERY_SERIOUS, 3 },
    { "Art. 162 II", "Dirigir com CNH suspensa/cassada", TRAFFIC_FINE_VERY_SERIOUS, 3 },
    { "Art. 162 III", "Dirigir com categoria diferente", TRAFFIC_FINE_VERY_SERIOUS, 2 },
    { "Art. 162 V", "Dirigir com CNH vencida ha mais de 30 dias", TRAFFIC_FINE_VERY_SERIOUS, 1 },
    { "Art. 162 VI", "Dirigir sem lentes/adaptacao obrigatoria", TRAFFIC_FINE_VERY_SERIOUS, 1 },
    { "Art. 163", "Entregar direcao a pessoa sem habilitacao", TRAFFIC_FINE_VERY_SERIOUS, 3 },
    { "Art. 164", "Permitir posse/direcao a pessoa irregular", TRAFFIC_FINE_VERY_SERIOUS, 3 },
    { "Art. 165", "Dirigir sob efeito de alcool/droga", TRAFFIC_FINE_VERY_SERIOUS, 10 },
    { "Art. 165-A", "Recusar teste de alcoolemia", TRAFFIC_FINE_VERY_SERIOUS, 10 },
    { "Art. 165-B", "Dirigir sem exame toxicologico obrigatorio", TRAFFIC_FINE_VERY_SERIOUS, 5 },
    { "Art. 165-C", "Dirigir com toxicologico positivo", TRAFFIC_FINE_VERY_SERIOUS, 5 },
    { "Art. 165-D", "Exame toxicologico vencido ha mais de 30 dias", TRAFFIC_FINE_VERY_SERIOUS, 5 },
    { "Art. 167", "Nao usar cinto de seguranca", TRAFFIC_FINE_SERIOUS, 1 },
    { "Art. 168", "Transportar crianca sem seguranca", TRAFFIC_FINE_VERY_SERIOUS, 1 },
    { "Art. 169", "Dirigir sem atencao/cuidados", TRAFFIC_FINE_LIGHT, 1 },
    { "Art. 170", "Ameacar pedestre ou outro veiculo", TRAFFIC_FINE_VERY_SERIOUS, 1 },
    { "Art. 172", "Atirar agua/detritos em pedestre/veiculo", TRAFFIC_FINE_MEDIUM, 1 },
    { "Art. 173", "Disputar corrida/racha", TRAFFIC_FINE_VERY_SERIOUS, 10 },
    { "Art. 174", "Competicao/evento sem autorizacao", TRAFFIC_FINE_VERY_SERIOUS, 10 },
    { "Art. 175", "Manobra perigosa/arrancada/derrapagem", TRAFFIC_FINE_VERY_SERIOUS, 10 },
    { "Art. 176", "Omitir socorro em acidente", TRAFFIC_FINE_VERY_SERIOUS, 5 },
    { "Art. 181", "Estacionar em local proibido", TRAFFIC_FINE_MEDIUM, 1 },
    { "Art. 181 XX", "Estacionar em vaga idoso/deficiente", TRAFFIC_FINE_VERY_SERIOUS, 1 },
    { "Art. 183", "Parar sobre faixa de pedestre", TRAFFIC_FINE_MEDIUM, 1 },
    { "Art. 184", "Transitar em faixa exclusiva", TRAFFIC_FINE_SERIOUS, 1 },
    { "Art. 186", "Transitar na contramao", TRAFFIC_FINE_SERIOUS, 1 },
    { "Art. 186 II", "Contramao em via sinalizada/mao unica", TRAFFIC_FINE_VERY_SERIOUS, 1 },
    { "Art. 191", "Forcar passagem entre veiculos", TRAFFIC_FINE_VERY_SERIOUS, 10 },
    { "Art. 193", "Transitar em calcada/acostamento/canteiro", TRAFFIC_FINE_VERY_SERIOUS, 3 },
    { "Art. 195", "Desobedecer ordem da autoridade", TRAFFIC_FINE_SERIOUS, 1 },
    { "Art. 196", "Nao sinalizar manobra", TRAFFIC_FINE_SERIOUS, 1 },
    { "Art. 203", "Ultrapassagem proibida", TRAFFIC_FINE_VERY_SERIOUS, 5 },
    { "Art. 208", "Avancar sinal vermelho/parada obrigatoria", TRAFFIC_FINE_VERY_SERIOUS, 1 },
    { "Art. 210", "Transpor bloqueio policial", TRAFFIC_FINE_VERY_SERIOUS, 1 },
    { "Art. 211", "Ultrapassar fila em bloqueio/sinal", TRAFFIC_FINE_SERIOUS, 1 },
    { "Art. 212", "Nao parar antes de linha ferrea", TRAFFIC_FINE_VERY_SERIOUS, 1 },
    { "Art. 214", "Nao dar preferencia a pedestre", TRAFFIC_FINE_VERY_SERIOUS, 1 },
    { "Art. 215", "Nao dar preferencia em intersecao", TRAFFIC_FINE_SERIOUS, 1 },
    { "Art. 218 I", "Excesso de velocidade ate 20%", TRAFFIC_FINE_MEDIUM, 1 },
    { "Art. 218 II", "Excesso de velocidade de 20% a 50%", TRAFFIC_FINE_SERIOUS, 1 },
    { "Art. 218 III", "Excesso de velocidade acima de 50%", TRAFFIC_FINE_VERY_SERIOUS, 3 },
    { "Art. 219", "Velocidade muito baixa obstruindo via", TRAFFIC_FINE_MEDIUM, 1 },
    { "Art. 220", "Velocidade incompativel com seguranca", TRAFFIC_FINE_SERIOUS, 1 },
    { "Art. 224", "Usar luz alta em via iluminada", TRAFFIC_FINE_LIGHT, 1 },
    { "Art. 227", "Usar buzina irregularmente", TRAFFIC_FINE_LIGHT, 1 },
    { "Art. 228", "Som/equipamento em volume irregular", TRAFFIC_FINE_SERIOUS, 1 },
    { "Art. 230 I", "Identificacao do veiculo violada/falsa", TRAFFIC_FINE_VERY_SERIOUS, 1 },
    { "Art. 230 V", "Veiculo sem registro/licenciamento", TRAFFIC_FINE_VERY_SERIOUS, 1 },
    { "Art. 230 IX", "Veiculo sem equipamento obrigatorio", TRAFFIC_FINE_SERIOUS, 1 },
    { "Art. 230 XVIII", "Veiculo em mau estado de conservacao", TRAFFIC_FINE_SERIOUS, 1 },
    { "Art. 232", "Conduzir sem documento obrigatorio", TRAFFIC_FINE_LIGHT, 1 },
    { "Art. 244", "Motocicleta sem capacete/seguranca", TRAFFIC_FINE_VERY_SERIOUS, 1 },
    { "Art. 252", "Usar/manusear celular ao volante", TRAFFIC_FINE_VERY_SERIOUS, 1 },
    { "Art. 253", "Bloquear via com veiculo", TRAFFIC_FINE_VERY_SERIOUS, 1 },
    { "Art. 253-A", "Bloqueio deliberado de via", TRAFFIC_FINE_VERY_SERIOUS, 20 },
    { "Art. 253-A", "Organizador de bloqueio de via", TRAFFIC_FINE_VERY_SERIOUS, 60 }
};

stock TrafficFine_Count()
{
    return sizeof(gTrafficFineCatalog);
}

stock TrafficFine_IsValid(fineid)
{
    return (fineid >= 0 && fineid < sizeof(gTrafficFineCatalog));
}

stock TrafficFine_GetArticle(fineid, output[], size = sizeof(output))
{
    if (!TrafficFine_IsValid(fineid))
    {
        format(output, size, "CTB");
        return 0;
    }
    format(output, size, "%s", gTrafficFineCatalog[fineid][trafficFineArticle]);
    return 1;
}

stock TrafficFine_GetTitle(fineid, output[], size = sizeof(output))
{
    if (!TrafficFine_IsValid(fineid))
    {
        format(output, size, "Infracao de transito");
        return 0;
    }
    format(output, size, "%s", gTrafficFineCatalog[fineid][trafficFineTitle]);
    return 1;
}

stock TrafficFine_GetSeverity(fineid)
{
    if (!TrafficFine_IsValid(fineid))
    {
        return TRAFFIC_FINE_MEDIUM;
    }
    return gTrafficFineCatalog[fineid][trafficFineSeverity];
}

stock TrafficFine_GetMultiplier(fineid)
{
    if (!TrafficFine_IsValid(fineid))
    {
        return 1;
    }
    return gTrafficFineCatalog[fineid][trafficFineMultiplier];
}

stock TrafficFine_GetAmount(fineid)
{
    return Cfg_TrafficFine(TrafficFine_GetSeverity(fineid), TrafficFine_GetMultiplier(fineid));
}

stock TrafficFine_GetPoints(fineid)
{
    return Cfg_TrafficPoints(TrafficFine_GetSeverity(fineid));
}

stock TrafficFine_BuildDialogLine(fineid, output[], size = sizeof(output))
{
    new severityName[16];

    if (!TrafficFine_IsValid(fineid))
    {
        format(output, size, "CTB\tInfracao invalida\t$0 / 0 pts\n");
        return 0;
    }

    Cfg_TrafficSeverityName(TrafficFine_GetSeverity(fineid), severityName, sizeof(severityName));
    format(output, size, "%s\t%s\t%s x%d | $%d | %d pts\n",
        gTrafficFineCatalog[fineid][trafficFineArticle],
        gTrafficFineCatalog[fineid][trafficFineTitle],
        severityName,
        TrafficFine_GetMultiplier(fineid),
        TrafficFine_GetAmount(fineid),
        TrafficFine_GetPoints(fineid)
    );
    return 1;
}
