#if defined _nova_mapobjects_included
    #endinput
#endif
#define _nova_mapobjects_included

forward MapObj_AutoCloseGate(slot);

#define MAP_GOTO_PAGE_SIZE          (35)

new gMapObjCount;
new gMapObjType[MAX_MAP_OBJECTS];
new gMapObjModel[MAX_MAP_OBJECTS];
new gMapObjId[MAX_MAP_OBJECTS];
new Text3D:gMapObjLabel[MAX_MAP_OBJECTS];
new Float:gMapObjX[MAX_MAP_OBJECTS];
new Float:gMapObjY[MAX_MAP_OBJECTS];
new Float:gMapObjZ[MAX_MAP_OBJECTS];
new Float:gMapObjRX[MAX_MAP_OBJECTS];
new Float:gMapObjRY[MAX_MAP_OBJECTS];
new Float:gMapObjRZ[MAX_MAP_OBJECTS];
new Float:gMapObjOpenX[MAX_MAP_OBJECTS];
new Float:gMapObjOpenY[MAX_MAP_OBJECTS];
new Float:gMapObjOpenZ[MAX_MAP_OBJECTS];
new Float:gMapObjOpenRX[MAX_MAP_OBJECTS];
new Float:gMapObjOpenRY[MAX_MAP_OBJECTS];
new Float:gMapObjOpenRZ[MAX_MAP_OBJECTS];
new Float:gMapObjRange[MAX_MAP_OBJECTS];
new Float:gMapObjSpeed[MAX_MAP_OBJECTS];
new gMapObjInterior[MAX_MAP_OBJECTS];
new gMapObjWorld[MAX_MAP_OBJECTS];
new gMapObjJob[MAX_MAP_OBJECTS];
new gMapObjOpen[MAX_MAP_OBJECTS];
new gMapObjCloseTimer[MAX_MAP_OBJECTS];
new gMapObjDataLine[MAX_MAP_OBJECTS];
new gMapObjName[MAX_MAP_OBJECTS][MAP_OBJECT_NAME_SIZE];
new gPlayerMapGotoPage[MAX_PLAYERS];
new gPlayerMapGotoFilter[MAX_PLAYERS];
new gPlayerMapGotoHasNext[MAX_PLAYERS];
new gPlayerMapGotoSlots[MAX_PLAYERS][MAP_GOTO_PAGE_SIZE];

#define MAP_STATIC_PRESET_COUNT     (14)
#define MAP_GATE_PRESET_COUNT       (10)
#define MAP_GATE_JOB_COUNT          (53)

new gMapStaticPresetModel[MAP_STATIC_PRESET_COUNT] =
{
    987, 970, 978, 979, 1237, 1422, 1228, 3578, 1422, 1238, 978, 966, 0, -1
};

new gMapStaticPresetName[MAP_STATIC_PRESET_COUNT][48] =
{
    "Cerca metalica",
    "Grade baixa",
    "Barreira pista A",
    "Barreira pista B",
    "Cone de transito",
    "Cavalete obra",
    "Sinalizacao obra",
    "Bloco concreto",
    "PRF Barreira fiscal",
    "PRF Cone fiscal",
    "PRF Barreira pista",
    "Pedagio base cancela",
    "KIT PRF Fiscalizacao",
    "KIT Pedagio pista dupla"
};

new gMapGatePresetModel[MAP_GATE_PRESET_COUNT] =
{
    980, 980, 980, 971, 969, 975, 976, 985, 986, 987
};

new gMapGatePresetName[MAP_GATE_PRESET_COUNT][56] =
{
    "Portao grade grande - sobe",
    "Portao grade grande - corre direita",
    "Portao grade grande - corre esquerda",
    "Portao industrial - sobe",
    "Cancela baixa - sobe",
    "Grade metalica - sobe",
    "Portao garagem - sobe",
    "Portao duplo esquerdo - sobe",
    "Portao duplo direito - sobe",
    "Cerca portao - corre direita"
};

new Float:gMapGatePresetForward[MAP_GATE_PRESET_COUNT] =
{
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

new Float:gMapGatePresetRight[MAP_GATE_PRESET_COUNT] =
{
    0.0, 5.0, -5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.0
};

new Float:gMapGatePresetUp[MAP_GATE_PRESET_COUNT] =
{
    5.0, 0.0, 0.0, 4.0, 3.0, 4.0, 3.5, 4.0, 4.0, 0.0
};

new Float:gMapGatePresetRange[MAP_GATE_PRESET_COUNT] =
{
    18.0, 18.0, 18.0, 18.0, 18.0, 18.0, 18.0, 18.0, 18.0, 18.0
};

new gPlayerMapGatePreset[MAX_PLAYERS];

new gMapGateJobIds[MAP_GATE_JOB_COUNT] =
{
    JOB_NONE,
    JOB_ENTREGADOR,
    JOB_LIXEIRO,
    JOB_MOTORISTA_ONIBUS,
    JOB_TAXISTA,
    JOB_CAMINHONEIRO,
    JOB_MECANICO,
    JOB_FRENTISTA,
    JOB_POLICIAL,
    JOB_MEDICO,
    JOB_BOMBEIRO,
    JOB_SEGURANCA,
    JOB_CARTEIRO,
    JOB_MOTOBOY,
    JOB_PESCADOR,
    JOB_AGRICULTOR,
    JOB_MINERADOR,
    JOB_PEDREIRO,
    JOB_GARCOM,
    JOB_COZINHEIRO,
    JOB_VENDEDOR,
    JOB_JORNALISTA,
    JOB_ADVOGADO,
    JOB_JUIZ,
    JOB_MOTORISTA_AMBULANCIA,
    JOB_TECNICO,
    JOB_PRF,
    JOB_POLICIA_FEDERAL,
    JOB_POLICIA_CIVIL,
    JOB_POLICIA_PENAL,
    JOB_AGENTE_DETRAN,
    JOB_FUNCIONARIO_PREFEITURA,
    JOB_BANCARIO,
    JOB_CORRETOR_IMOVEIS,
    JOB_CONTADOR,
    JOB_PROFESSOR,
    JOB_FARMACEUTICO,
    JOB_ASSISTENTE_SOCIAL,
    JOB_PERITO_CRIMINAL,
    JOB_CAIXA_REPOSITOR,
    JOB_BARTENDER,
    JOB_PADEIRO_PIZZAIOLO,
    JOB_RECEPCIONISTA_HOTEL,
    JOB_GUINCHEIRO,
    JOB_MOTORISTA_APP,
    JOB_ENCANADOR,
    JOB_JARDINEIRO,
    JOB_ZELADOR,
    JOB_OPERADOR_FABRICA,
    JOB_PROMOTOR,
    JOB_DEFENSOR_PUBLICO,
    JOB_OFICIAL_JUSTICA,
    JOB_ESCRIVAO
};

new gMapGateJobNames[MAP_GATE_JOB_COUNT][32] =
{
    "Publico",
    "Entregador",
    "Lixeiro",
    "Motorista de onibus",
    "Taxista",
    "Caminhoneiro",
    "Mecanico",
    "Frentista",
    "Policial",
    "Medico",
    "Bombeiro",
    "Seguranca",
    "Carteiro",
    "Motoboy",
    "Pescador",
    "Agricultor",
    "Minerador",
    "Pedreiro",
    "Garcom",
    "Cozinheiro",
    "Vendedor",
    "Jornalista",
    "Advogado",
    "Juiz",
    "Motorista ambulancia",
    "Tecnico",
    "PRF",
    "Policia Federal",
    "Policia Civil",
    "Policia Penal",
    "Agente DETRAN",
    "Funcionario Prefeitura",
    "Bancario",
    "Corretor de imoveis",
    "Contador",
    "Professor",
    "Farmaceutico",
    "Assistente social",
    "Perito criminal",
    "Caixa/repositor",
    "Bartender",
    "Padeiro/pizzaiolo",
    "Recepcionista hotel",
    "Guincheiro",
    "Motorista de app",
    "Encanador",
    "Jardineiro",
    "Zelador",
    "Operador fabrica",
    "Promotor",
    "Defensor publico",
    "Oficial de justica",
    "Escrivao"
};

stock MapObj_TrimToken(text[])
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

stock MapObj_GetToken(line[], &position, output[], size = sizeof(output))
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

    MapObj_TrimToken(output);
    return 1;
}

stock MapObj_IsFloat(text[])
{
    new index;
    new length = strlen(text);
    new dots;
    new digits;

    if (length == 0)
    {
        return 0;
    }

    if (text[0] == '-')
    {
        if (length == 1)
        {
            return 0;
        }
        index = 1;
    }

    while (index < length)
    {
        if (text[index] == '.')
        {
            if (dots)
            {
                return 0;
            }
            dots = 1;
        }
        else if (text[index] >= '0' && text[index] <= '9')
        {
            digits++;
        }
        else
        {
            return 0;
        }
        index++;
    }

    return (digits > 0);
}

stock MapObj_CopyName(input[], output[], size = sizeof(output))
{
    new index;
    new offset;

    while (input[index] != 0 && offset < (size - 1))
    {
        if (input[index] == '|' || input[index] == 10 || input[index] == 13)
        {
            output[offset] = ' ';
        }
        else
        {
            output[offset] = input[index];
        }
        offset++;
        index++;
    }

    output[offset] = 0;
    MapObj_TrimToken(output);
    return 1;
}

stock MapObj_GetJobName(jobid, output[], size = sizeof(output))
{
    new index;

    for (index = 0; index < MAP_GATE_JOB_COUNT; index++)
    {
        if (gMapGateJobIds[index] == jobid)
        {
            format(output, size, "%s", gMapGateJobNames[index]);
            return 1;
        }
    }

    format(output, size, "Profissao %d", jobid);
    return 1;
}

stock MapObj_ParseJob(token[])
{
    new index;

    if (IsNumericString(token, 1))
    {
        return strval(token);
    }

    for (index = 0; index < MAP_GATE_JOB_COUNT; index++)
    {
        if (strcmp(token, gMapGateJobNames[index], true) == 0)
        {
            return gMapGateJobIds[index];
        }
    }

    return JOB_NONE;
}

stock MapObj_ReadName(cmdtext[], index, firstToken[], output[], size = sizeof(output))
{
    new rest[96];

    format(output, size, "%s", firstToken);
    if (GetRemainingText(cmdtext, index, rest, sizeof(rest)))
    {
        strcat(output, " ", size);
        strcat(output, rest, size);
    }
    MapObj_CopyName(output, output, size);
    return 1;
}

stock MapObj_WriteDefaultFile()
{
    new File:file = fopen(MAP_OBJECTS_FILE, io_write);

    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Objetos e portoes carregados no mapa ao iniciar a GM.\r\n");
    fwrite(file, "# Formato:\r\n");
    fwrite(file, "# type|model|x|y|z|rx|ry|rz|open_x|open_y|open_z|open_rx|open_ry|open_rz|range|speed|interior|virtualworld|name|job\r\n");
    fwrite(file, "# type 0 = objeto fixo. type 1 = portao movel.\r\n");
    fwrite(file, "# job 0 = publico. Use IDs de profissao para restringir acesso por buzina H.\r\n");
    fwrite(file, "# Exemplo portao Policial: 1|980|1544.0|-1627.0|13.4|0.0|0.0|90.0|1544.0|-1627.0|18.4|0.0|0.0|90.0|8.0|2.0|0|0|Portao_DP|8\r\n");
    fclose(file);
    return 1;
}

stock MapObj_ResetSlot(slot)
{
    if (slot < 0 || slot >= MAX_MAP_OBJECTS)
    {
        return 0;
    }

    gMapObjType[slot] = MAP_OBJECT_TYPE_STATIC;
    gMapObjModel[slot] = 0;
    gMapObjId[slot] = INVALID_OBJECT_ID;
    gMapObjLabel[slot] = Text3D:INVALID_3DTEXT_ID;
    gMapObjX[slot] = 0.0;
    gMapObjY[slot] = 0.0;
    gMapObjZ[slot] = 0.0;
    gMapObjRX[slot] = 0.0;
    gMapObjRY[slot] = 0.0;
    gMapObjRZ[slot] = 0.0;
    gMapObjOpenX[slot] = 0.0;
    gMapObjOpenY[slot] = 0.0;
    gMapObjOpenZ[slot] = 0.0;
    gMapObjOpenRX[slot] = 0.0;
    gMapObjOpenRY[slot] = 0.0;
    gMapObjOpenRZ[slot] = 0.0;
    gMapObjRange[slot] = MAP_OBJECT_DEFAULT_RANGE;
    gMapObjSpeed[slot] = MAP_OBJECT_DEFAULT_SPEED;
    gMapObjInterior[slot] = 0;
    gMapObjWorld[slot] = 0;
    gMapObjJob[slot] = JOB_NONE;
    gMapObjOpen[slot] = 0;
    if (gMapObjCloseTimer[slot])
    {
        KillTimer(gMapObjCloseTimer[slot]);
        gMapObjCloseTimer[slot] = 0;
    }
    gMapObjDataLine[slot] = 0;
    gMapObjName[slot][0] = 0;
    return 1;
}

stock MapObj_DestroyAll()
{
    new slot;

    for (slot = 0; slot < gMapObjCount; slot++)
    {
        if (gMapObjId[slot] != INVALID_OBJECT_ID && IsValidObject(gMapObjId[slot]))
        {
            DestroyObject(gMapObjId[slot]);
        }

        if (gMapObjLabel[slot] != Text3D:INVALID_3DTEXT_ID)
        {
            Delete3DTextLabel(gMapObjLabel[slot]);
        }

        MapObj_ResetSlot(slot);
    }

    gMapObjCount = 0;
    return 1;
}

stock MapObj_CreateSlot(objType, modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, Float:openX, Float:openY, Float:openZ, Float:openRX, Float:openRY, Float:openRZ, Float:range, Float:speed, interior, world, name[], jobid)
{
    new slot;
    new objectid;
    new labelText[128];
    new cleanName[MAP_OBJECT_NAME_SIZE];
    new jobName[32];

    if (gMapObjCount >= MAX_MAP_OBJECTS)
    {
        return 0;
    }

    if (modelid <= 0 || modelid > 20000)
    {
        return 0;
    }

    if (objType != MAP_OBJECT_TYPE_STATIC && objType != MAP_OBJECT_TYPE_GATE)
    {
        return 0;
    }

    if (range < MAP_OBJECT_DEFAULT_RANGE)
    {
        range = MAP_OBJECT_DEFAULT_RANGE;
    }
    if (speed <= 0.0)
    {
        speed = MAP_OBJECT_DEFAULT_SPEED;
    }

    objectid = CreateObject(modelid, x, y, z, rx, ry, rz, 0.0);
    if (objectid == INVALID_OBJECT_ID)
    {
        return 0;
    }

    slot = gMapObjCount;
    MapObj_ResetSlot(slot);
    gMapObjType[slot] = objType;
    gMapObjModel[slot] = modelid;
    gMapObjId[slot] = objectid;
    gMapObjX[slot] = x;
    gMapObjY[slot] = y;
    gMapObjZ[slot] = z;
    gMapObjRX[slot] = rx;
    gMapObjRY[slot] = ry;
    gMapObjRZ[slot] = rz;
    gMapObjOpenX[slot] = openX;
    gMapObjOpenY[slot] = openY;
    gMapObjOpenZ[slot] = openZ;
    gMapObjOpenRX[slot] = openRX;
    gMapObjOpenRY[slot] = openRY;
    gMapObjOpenRZ[slot] = openRZ;
    gMapObjRange[slot] = range;
    gMapObjSpeed[slot] = speed;
    gMapObjInterior[slot] = interior;
    gMapObjWorld[slot] = world;
    gMapObjJob[slot] = jobid;
    gMapObjDataLine[slot] = 0;
    MapObj_CopyName(name, cleanName, sizeof(cleanName));
    if (cleanName[0] == 0)
    {
        if (objType == MAP_OBJECT_TYPE_GATE)
        {
            format(cleanName, sizeof(cleanName), "Portao");
        }
        else
        {
            format(cleanName, sizeof(cleanName), "Objeto");
        }
    }
    format(gMapObjName[slot], MAP_OBJECT_NAME_SIZE, "%s", cleanName);

    if (objType == MAP_OBJECT_TYPE_GATE)
    {
        MapObj_GetJobName(jobid, jobName, sizeof(jobName));
        if (jobid == JOB_NONE)
        {
            format(labelText, sizeof(labelText), "Portao: %s\nBuzine H dirigindo", gMapObjName[slot]);
        }
        else
        {
            format(labelText, sizeof(labelText), "Portao: %s\nBuzine H | %s", gMapObjName[slot], jobName);
        }
        gMapObjLabel[slot] = Create3DTextLabel(labelText, COLOR_YELLOW, x, y, z + 1.2, 30.0, world, 1);
    }
    else if (strfind(gMapObjName[slot], "Pedagio", true) != -1)
    {
        format(labelText, sizeof(labelText), "PEDAGIO\nCabine de atendimento\nUse /pedagio ou tag automatica");
        gMapObjLabel[slot] = Create3DTextLabel(labelText, COLOR_YELLOW, x, y, z + 1.2, 35.0, world, 1);
    }
    else if (strfind(gMapObjName[slot], "PRF", true) != -1 || strfind(gMapObjName[slot], "Fiscal", true) != -1)
    {
        format(labelText, sizeof(labelText), "POSTO PRF\nFiscalizacao rodoviaria\nPare se for solicitado");
        gMapObjLabel[slot] = Create3DTextLabel(labelText, COLOR_ADMIN, x, y, z + 1.2, 35.0, world, 1);
    }

    gMapObjCount++;
    return 1;
}

stock MapObj_CreateFromLine(line[])
{
    new token[64];
    new position;
    new objType;
    new modelid;
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:rx;
    new Float:ry;
    new Float:rz;
    new Float:openX;
    new Float:openY;
    new Float:openZ;
    new Float:openRX;
    new Float:openRY;
    new Float:openRZ;
    new Float:range = MAP_OBJECT_DEFAULT_RANGE;
    new Float:speed = MAP_OBJECT_DEFAULT_SPEED;
    new interior;
    new world;
    new name[MAP_OBJECT_NAME_SIZE];
    new jobid = JOB_NONE;

    if (gMapObjCount >= MAX_MAP_OBJECTS || line[0] == 0 || line[0] == '#')
    {
        return 0;
    }

    if (!MapObj_GetToken(line, position, token, sizeof(token)) || !IsNumericString(token)) return 0;
    objType = strval(token);
    if (objType != MAP_OBJECT_TYPE_STATIC && objType != MAP_OBJECT_TYPE_GATE) return 0;

    if (!MapObj_GetToken(line, position, token, sizeof(token)) || !IsNumericString(token)) return 0;
    modelid = strval(token);

    if (!MapObj_GetToken(line, position, token, sizeof(token)) || !MapObj_IsFloat(token)) return 0;
    x = floatstr(token);
    if (!MapObj_GetToken(line, position, token, sizeof(token)) || !MapObj_IsFloat(token)) return 0;
    y = floatstr(token);
    if (!MapObj_GetToken(line, position, token, sizeof(token)) || !MapObj_IsFloat(token)) return 0;
    z = floatstr(token);
    if (!MapObj_GetToken(line, position, token, sizeof(token)) || !MapObj_IsFloat(token)) return 0;
    rx = floatstr(token);
    if (!MapObj_GetToken(line, position, token, sizeof(token)) || !MapObj_IsFloat(token)) return 0;
    ry = floatstr(token);
    if (!MapObj_GetToken(line, position, token, sizeof(token)) || !MapObj_IsFloat(token)) return 0;
    rz = floatstr(token);

    if (!MapObj_GetToken(line, position, token, sizeof(token)) || !MapObj_IsFloat(token)) return 0;
    openX = floatstr(token);
    if (!MapObj_GetToken(line, position, token, sizeof(token)) || !MapObj_IsFloat(token)) return 0;
    openY = floatstr(token);
    if (!MapObj_GetToken(line, position, token, sizeof(token)) || !MapObj_IsFloat(token)) return 0;
    openZ = floatstr(token);
    if (!MapObj_GetToken(line, position, token, sizeof(token)) || !MapObj_IsFloat(token)) return 0;
    openRX = floatstr(token);
    if (!MapObj_GetToken(line, position, token, sizeof(token)) || !MapObj_IsFloat(token)) return 0;
    openRY = floatstr(token);
    if (!MapObj_GetToken(line, position, token, sizeof(token)) || !MapObj_IsFloat(token)) return 0;
    openRZ = floatstr(token);

    if (MapObj_GetToken(line, position, token, sizeof(token)) && MapObj_IsFloat(token))
    {
        range = floatstr(token);
    }
    if (MapObj_GetToken(line, position, token, sizeof(token)) && MapObj_IsFloat(token))
    {
        speed = floatstr(token);
    }
    if (MapObj_GetToken(line, position, token, sizeof(token)) && IsNumericString(token, 1))
    {
        interior = strval(token);
    }
    if (MapObj_GetToken(line, position, token, sizeof(token)) && IsNumericString(token, 1))
    {
        world = strval(token);
    }
    if (MapObj_GetToken(line, position, token, sizeof(token)))
    {
        MapObj_CopyName(token, name, sizeof(name));
    }
    if (MapObj_GetToken(line, position, token, sizeof(token)))
    {
        jobid = MapObj_ParseJob(token);
    }

    return MapObj_CreateSlot(objType, modelid, x, y, z, rx, ry, rz, openX, openY, openZ, openRX, openRY, openRZ, range, speed, interior, world, name, jobid);
}

stock MapObj_CountDataLines()
{
    new File:file;
    new line[384];
    new count;

    if (!fexist(MAP_OBJECTS_FILE))
    {
        return 0;
    }

    file = fopen(MAP_OBJECTS_FILE, io_read);
    if (!file)
    {
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (MapObj_IsDataLine(line))
        {
            count++;
        }
    }

    fclose(file);
    return count;
}

stock MapObj_LoadAll()
{
    new File:file;
    new line[384];
    new slot;
    new loaded;
    new dataLine;

    MapObj_DestroyAll();
    for (slot = 0; slot < MAX_MAP_OBJECTS; slot++)
    {
        MapObj_ResetSlot(slot);
    }

    if (!fexist(MAP_OBJECTS_FILE))
    {
        MapObj_WriteDefaultFile();
    }

    file = fopen(MAP_OBJECTS_FILE, io_read);
    if (!file)
    {
        print("[MapObjects] Nao foi possivel abrir map_objects.txt.");
        return 0;
    }

    while (ReadFileLine(file, line, sizeof(line)))
    {
        if (MapObj_IsDataLine(line))
        {
            dataLine++;
        }

        if (MapObj_CreateFromLine(line))
        {
            gMapObjDataLine[gMapObjCount - 1] = dataLine;
            loaded++;
        }
    }

    fclose(file);
    printf("[MapObjects] %d objetos/portoes carregados de scriptfiles/map_objects.txt.", loaded);
    return loaded;
}

stock MapObj_WriteSlotLine(File:file, slot)
{
    new line[384];

    if (slot < 0 || slot >= gMapObjCount || gMapObjModel[slot] <= 0)
    {
        return 0;
    }

    format(line, sizeof(line), "%d|%d|%.4f|%.4f|%.4f|%.4f|%.4f|%.4f|%.4f|%.4f|%.4f|%.4f|%.4f|%.4f|%.2f|%.2f|%d|%d|%s|%d\r\n",
        gMapObjType[slot],
        gMapObjModel[slot],
        gMapObjX[slot],
        gMapObjY[slot],
        gMapObjZ[slot],
        gMapObjRX[slot],
        gMapObjRY[slot],
        gMapObjRZ[slot],
        gMapObjOpenX[slot],
        gMapObjOpenY[slot],
        gMapObjOpenZ[slot],
        gMapObjOpenRX[slot],
        gMapObjOpenRY[slot],
        gMapObjOpenRZ[slot],
        gMapObjRange[slot],
        gMapObjSpeed[slot],
        gMapObjInterior[slot],
        gMapObjWorld[slot],
        gMapObjName[slot],
        gMapObjJob[slot]
    );
    fwrite(file, line);
    return 1;
}

stock MapObj_SaveAllExcept(skipSlot = -1)
{
    new File:file;
    new slot;

    file = fopen(MAP_OBJECTS_FILE, io_write);
    if (!file)
    {
        return 0;
    }

    fwrite(file, "# Objetos e portoes carregados no mapa ao iniciar a GM.\r\n");
    fwrite(file, "# Formato:\r\n");
    fwrite(file, "# type|model|x|y|z|rx|ry|rz|open_x|open_y|open_z|open_rx|open_ry|open_rz|range|speed|interior|virtualworld|name|job\r\n");
    fwrite(file, "# type 0 = objeto fixo. type 1 = portao movel.\r\n");
    fwrite(file, "# job 0 = publico. Use IDs de profissao para restringir acesso por buzina H.\r\n");

    for (slot = 0; slot < gMapObjCount; slot++)
    {
        if (slot == skipSlot)
        {
            continue;
        }
        MapObj_WriteSlotLine(file, slot);
    }

    fclose(file);
    return 1;
}

stock MapObj_SaveLine(objType, modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, Float:openX, Float:openY, Float:openZ, Float:openRX, Float:openRY, Float:openRZ, Float:range, Float:speed, interior, world, name[], jobid, preview)
{
    new File:file;
    new line[384];
    new parseLine[384];
    new cleanName[MAP_OBJECT_NAME_SIZE];

    if (preview && gMapObjCount >= MAX_MAP_OBJECTS)
    {
        return 0;
    }

    if (!fexist(MAP_OBJECTS_FILE))
    {
        MapObj_WriteDefaultFile();
    }

    MapObj_CopyName(name, cleanName, sizeof(cleanName));

    file = fopen(MAP_OBJECTS_FILE, io_append);
    if (!file)
    {
        return 0;
    }

    format(line, sizeof(line), "%d|%d|%.4f|%.4f|%.4f|%.4f|%.4f|%.4f|%.4f|%.4f|%.4f|%.4f|%.4f|%.4f|%.2f|%.2f|%d|%d|%s|%d\r\n",
        objType, modelid, x, y, z, rx, ry, rz, openX, openY, openZ, openRX, openRY, openRZ, range, speed, interior, world, cleanName, jobid);
    fwrite(file, line);
    fclose(file);

    if (preview)
    {
        new dataLine = MapObj_CountDataLines();
        format(parseLine, sizeof(parseLine), "%s", line);
        StripLineEnd(parseLine);
        if (MapObj_CreateFromLine(parseLine))
        {
            gMapObjDataLine[gMapObjCount - 1] = dataLine;
            return 1;
        }
        return 0;
    }
    return 1;
}

stock MapObj_CanManage(playerid)
{
    if (IsAdminOwnerLevel(playerid))
    {
        return 1;
    }
    return 0;
}

stock MapObj_IsDataLine(line[])
{
    new check[384];

    format(check, sizeof(check), "%s", line);
    StripLineEnd(check);
    MapObj_TrimToken(check);
    if (check[0] == 0 || check[0] == '#')
    {
        return 0;
    }
    return 1;
}

stock MapObj_AddStatic(playerid, modelid, name[])
{
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:angle;
    new Float:forwardX;
    new Float:forwardY;
    new interior;
    new world;
    new message[144];
    new logLine[192];
    new cleanName[MAP_OBJECT_NAME_SIZE];

    if (!MapObj_CanManage(playerid))
    {
        return SendNoPermission(playerid);
    }

    if (modelid <= 0 || modelid > 20000)
    {
        SendClientMessage(playerid, COLOR_RED, "Modelo invalido. Use um ID de objeto SA-MP valido.");
        return 1;
    }

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, angle);
    forwardX = floatsin(-angle, degrees);
    forwardY = floatcos(-angle, degrees);
    x += forwardX * 2.4;
    y += forwardY * 2.4;
    interior = GetPlayerInterior(playerid);
    world = GetPlayerVirtualWorld(playerid);

    MapObj_CopyName(name, cleanName, sizeof(cleanName));
    if (cleanName[0] == 0)
    {
        format(cleanName, sizeof(cleanName), "Objeto_%d", modelid);
    }

    if (!MapObj_SaveLine(MAP_OBJECT_TYPE_STATIC, modelid, x, y, z, 0.0, 0.0, angle, x, y, z, 0.0, 0.0, angle, MAP_OBJECT_DEFAULT_RANGE, MAP_OBJECT_DEFAULT_SPEED, interior, world, cleanName, JOB_NONE, 1))
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel salvar/criar o objeto do mapa.");
        return 1;
    }

    format(message, sizeof(message), "Objeto %s salvo a sua frente: model %d em %.1f, %.1f, %.1f.", cleanName, modelid, x, y, z);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(playerid, COLOR_YELLOW, "Linha adicionada em scriptfiles/map_objects.txt.");
    format(logLine, sizeof(logLine), "type=static model=%d pos=%.2f,%.2f,%.2f name=%s", modelid, x, y, z, cleanName);
    WritePlayerLog(LOG_ADMIN_FILE, "MAP_OBJECT_ADD", playerid, logLine);
    return 1;
}

stock MapObj_AddPrfFiscalKit(playerid)
{
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:angle;
    new Float:forwardX;
    new Float:forwardY;
    new Float:rightX;
    new Float:rightY;
    new interior;
    new world;
    new created;
    new message[144];

    if (!MapObj_CanManage(playerid))
    {
        return SendNoPermission(playerid);
    }

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, angle);
    interior = GetPlayerInterior(playerid);
    world = GetPlayerVirtualWorld(playerid);

    forwardX = floatsin(-angle, degrees);
    forwardY = floatcos(-angle, degrees);
    rightX = floatcos(-angle, degrees);
    rightY = -floatsin(-angle, degrees);
    x += forwardX * 7.0;
    y += forwardY * 7.0;

    if (MapObj_SaveLine(MAP_OBJECT_TYPE_STATIC, 1422, x + (rightX * -3.4), y + (rightY * -3.4), z - 0.6, 0.0, 0.0, angle, x, y, z, 0.0, 0.0, angle, MAP_OBJECT_DEFAULT_RANGE, MAP_OBJECT_DEFAULT_SPEED, interior, world, "PRF Barreira fiscal esquerda", JOB_NONE, 1)) created++;
    if (MapObj_SaveLine(MAP_OBJECT_TYPE_STATIC, 1422, x, y, z - 0.6, 0.0, 0.0, angle, x, y, z, 0.0, 0.0, angle, MAP_OBJECT_DEFAULT_RANGE, MAP_OBJECT_DEFAULT_SPEED, interior, world, "PRF Barreira fiscal centro", JOB_NONE, 1)) created++;
    if (MapObj_SaveLine(MAP_OBJECT_TYPE_STATIC, 1422, x + (rightX * 3.4), y + (rightY * 3.4), z - 0.6, 0.0, 0.0, angle, x, y, z, 0.0, 0.0, angle, MAP_OBJECT_DEFAULT_RANGE, MAP_OBJECT_DEFAULT_SPEED, interior, world, "PRF Barreira fiscal direita", JOB_NONE, 1)) created++;
    if (MapObj_SaveLine(MAP_OBJECT_TYPE_STATIC, 1238, x + (rightX * -5.8) + (forwardX * -2.2), y + (rightY * -5.8) + (forwardY * -2.2), z - 0.7, 0.0, 0.0, angle, x, y, z, 0.0, 0.0, angle, MAP_OBJECT_DEFAULT_RANGE, MAP_OBJECT_DEFAULT_SPEED, interior, world, "PRF Cone fiscal A", JOB_NONE, 1)) created++;
    if (MapObj_SaveLine(MAP_OBJECT_TYPE_STATIC, 1238, x + (rightX * 5.8) + (forwardX * -2.2), y + (rightY * 5.8) + (forwardY * -2.2), z - 0.7, 0.0, 0.0, angle, x, y, z, 0.0, 0.0, angle, MAP_OBJECT_DEFAULT_RANGE, MAP_OBJECT_DEFAULT_SPEED, interior, world, "PRF Cone fiscal B", JOB_NONE, 1)) created++;
    if (MapObj_SaveLine(MAP_OBJECT_TYPE_STATIC, 1238, x + (forwardX * -6.0), y + (forwardY * -6.0), z - 0.7, 0.0, 0.0, angle, x, y, z, 0.0, 0.0, angle, MAP_OBJECT_DEFAULT_RANGE, MAP_OBJECT_DEFAULT_SPEED, interior, world, "PRF Cone fiscal entrada", JOB_NONE, 1)) created++;
    if (MapObj_SaveLine(MAP_OBJECT_TYPE_STATIC, 1238, x + (forwardX * 6.0), y + (forwardY * 6.0), z - 0.7, 0.0, 0.0, angle, x, y, z, 0.0, 0.0, angle, MAP_OBJECT_DEFAULT_RANGE, MAP_OBJECT_DEFAULT_SPEED, interior, world, "PRF Cone fiscal saida", JOB_NONE, 1)) created++;

    format(message, sizeof(message), "Kit PRF criado com %d objeto(s), barreiras, cones e Text3D fiscal.", created);
    SendClientMessage(playerid, created > 0 ? COLOR_GREEN : COLOR_RED, message);
    if (created > 0)
    {
        SendClientMessage(playerid, COLOR_YELLOW, "Linhas adicionadas em scriptfiles/map_objects.txt.");
        WritePlayerLog(LOG_ADMIN_FILE, "MAP_PRF_KIT_ADD", playerid, "created PRF fiscal kit from map editor");
    }
    return 1;
}

stock MapObj_AddTollDoubleLaneKit(playerid)
{
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:angle;
    new Float:forwardX;
    new Float:forwardY;
    new Float:rightX;
    new Float:rightY;
    new interior;
    new world;
    new created;
    new message[160];

    if (!MapObj_CanManage(playerid))
    {
        return SendNoPermission(playerid);
    }

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, angle);
    interior = GetPlayerInterior(playerid);
    world = GetPlayerVirtualWorld(playerid);

    forwardX = floatsin(-angle, degrees);
    forwardY = floatcos(-angle, degrees);
    rightX = floatcos(-angle, degrees);
    rightY = -floatsin(-angle, degrees);
    x += forwardX * 7.0;
    y += forwardY * 7.0;

    if (MapObj_SaveLine(MAP_OBJECT_TYPE_STATIC, 966, x + (rightX * -4.2), y + (rightY * -4.2), z - 0.8, 0.0, 0.0, angle, x, y, z, 0.0, 0.0, angle, MAP_OBJECT_DEFAULT_RANGE, MAP_OBJECT_DEFAULT_SPEED, interior, world, "Pedagio base cancela ida", JOB_NONE, 1)) created++;
    if (MapObj_SaveLine(MAP_OBJECT_TYPE_STATIC, 966, x + (rightX * 4.2), y + (rightY * 4.2), z - 0.8, 0.0, 0.0, angle + 180.0, x, y, z, 0.0, 0.0, angle, MAP_OBJECT_DEFAULT_RANGE, MAP_OBJECT_DEFAULT_SPEED, interior, world, "Pedagio base cancela volta", JOB_NONE, 1)) created++;
    if (MapObj_SaveLine(MAP_OBJECT_TYPE_STATIC, 970, x + (rightX * -7.0) + (forwardX * 2.5), y + (rightY * -7.0) + (forwardY * 2.5), z - 0.5, 0.0, 0.0, angle, x, y, z, 0.0, 0.0, angle, MAP_OBJECT_DEFAULT_RANGE, MAP_OBJECT_DEFAULT_SPEED, interior, world, "Pedagio grade guia ida", JOB_NONE, 1)) created++;
    if (MapObj_SaveLine(MAP_OBJECT_TYPE_STATIC, 970, x + (rightX * 7.0) + (forwardX * -2.5), y + (rightY * 7.0) + (forwardY * -2.5), z - 0.5, 0.0, 0.0, angle, x, y, z, 0.0, 0.0, angle, MAP_OBJECT_DEFAULT_RANGE, MAP_OBJECT_DEFAULT_SPEED, interior, world, "Pedagio grade guia volta", JOB_NONE, 1)) created++;
    if (MapObj_SaveLine(MAP_OBJECT_TYPE_STATIC, 1237, x + (forwardX * -5.0), y + (forwardY * -5.0), z - 0.7, 0.0, 0.0, angle, x, y, z, 0.0, 0.0, angle, MAP_OBJECT_DEFAULT_RANGE, MAP_OBJECT_DEFAULT_SPEED, interior, world, "Pedagio cone entrada", JOB_NONE, 1)) created++;
    if (MapObj_SaveLine(MAP_OBJECT_TYPE_STATIC, 1237, x + (forwardX * 5.0), y + (forwardY * 5.0), z - 0.7, 0.0, 0.0, angle, x, y, z, 0.0, 0.0, angle, MAP_OBJECT_DEFAULT_RANGE, MAP_OBJECT_DEFAULT_SPEED, interior, world, "Pedagio cone saida", JOB_NONE, 1)) created++;

    format(message, sizeof(message), "Kit de pedagio pista dupla criado com %d objeto(s), sem cabine. Crie as cancelas reais em cada faixa.", created);
    SendClientMessage(playerid, created > 0 ? COLOR_GREEN : COLOR_RED, message);
    if (created > 0)
    {
        SendClientMessage(playerid, COLOR_YELLOW, "Dica: use /criarpedagio duas vezes, uma em cada sentido da pista.");
        WritePlayerLog(LOG_ADMIN_FILE, "MAP_TOLL_KIT_ADD", playerid, "created double lane toll visual kit from map editor");
    }
    return 1;
}

stock MapObj_AddGate(playerid, modelid, Float:dx, Float:dy, Float:dz, Float:range, name[], jobid)
{
    new Float:x;
    new Float:y;
    new Float:z;
    new Float:angle;
    new Float:forwardX;
    new Float:forwardY;
    new interior;
    new world;
    new message[160];
    new logLine[192];
    new cleanName[MAP_OBJECT_NAME_SIZE];
    new jobName[32];

    if (!MapObj_CanManage(playerid))
    {
        return SendNoPermission(playerid);
    }

    if (modelid <= 0 || modelid > 20000)
    {
        SendClientMessage(playerid, COLOR_RED, "Modelo invalido. Use um ID de objeto SA-MP valido.");
        return 1;
    }

    if (dx == 0.0 && dy == 0.0 && dz == 0.0)
    {
        dz = 4.0;
    }
    if (range < MAP_OBJECT_DEFAULT_RANGE)
    {
        range = MAP_OBJECT_DEFAULT_RANGE;
    }

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, angle);
    forwardX = floatsin(-angle, degrees);
    forwardY = floatcos(-angle, degrees);
    x += forwardX * 3.0;
    y += forwardY * 3.0;
    interior = GetPlayerInterior(playerid);
    world = GetPlayerVirtualWorld(playerid);

    MapObj_CopyName(name, cleanName, sizeof(cleanName));
    if (cleanName[0] == 0)
    {
        format(cleanName, sizeof(cleanName), "Portao_%d", modelid);
    }

    if (!MapObj_SaveLine(MAP_OBJECT_TYPE_GATE, modelid, x, y, z, 0.0, 0.0, angle, x + dx, y + dy, z + dz, 0.0, 0.0, angle, range, MAP_OBJECT_DEFAULT_SPEED, interior, world, cleanName, jobid, 1))
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel salvar/criar o portao.");
        return 1;
    }

    MapObj_GetJobName(jobid, jobName, sizeof(jobName));
    format(message, sizeof(message), "Portao %s salvo para %s: %.1f, %.1f, %.1f.", cleanName, jobName, x, y, z);
    SendClientMessage(playerid, COLOR_GREEN, message);
    SendClientMessage(playerid, COLOR_YELLOW, "Linha adicionada em scriptfiles/map_objects.txt. Use H/buzina dirigindo no local.");
    format(logLine, sizeof(logLine), "type=gate model=%d job=%d pos=%.2f,%.2f,%.2f offset=%.2f,%.2f,%.2f name=%s", modelid, jobid, x, y, z, dx, dy, dz, cleanName);
    WritePlayerLog(LOG_ADMIN_FILE, "MAP_GATE_ADD", playerid, logLine);
    return 1;
}

stock MapObj_FindNearest(playerid, Float:range = 25.0, typeFilter = -1)
{
    new slot;
    new nearest = -1;
    new Float:distance;
    new Float:bestDistance = 999999.0;
    new interior = GetPlayerInterior(playerid);
    new world = GetPlayerVirtualWorld(playerid);

    for (slot = 0; slot < gMapObjCount; slot++)
    {
        if (gMapObjId[slot] == INVALID_OBJECT_ID || gMapObjModel[slot] <= 0)
        {
            continue;
        }
        if (typeFilter != -1 && gMapObjType[slot] != typeFilter)
        {
            continue;
        }
        if (gMapObjInterior[slot] != interior || gMapObjWorld[slot] != world)
        {
            continue;
        }

        distance = GetPlayerDistanceFromPoint(playerid, gMapObjX[slot], gMapObjY[slot], gMapObjZ[slot]);
        if (distance <= range && distance < bestDistance)
        {
            nearest = slot;
            bestDistance = distance;
        }
    }
    return nearest;
}

stock MapObj_SendNearest(playerid, typeFilter = -1)
{
    new slot;
    new typeName[16];
    new message[160];

    if (!MapObj_CanManage(playerid))
    {
        return SendNoPermission(playerid);
    }

    slot = MapObj_FindNearest(playerid, 35.0, typeFilter);
    if (slot == -1)
    {
        SendClientMessage(playerid, COLOR_ORANGE, "Nenhum objeto/portao encontrado perto de voce.");
        return 1;
    }

    format(typeName, sizeof(typeName), "%s", gMapObjType[slot] == MAP_OBJECT_TYPE_GATE ? ("portao") : ("objeto"));
    format(message, sizeof(message), "Mais perto: ID %d | %s | model %d | %s | %.1fm.", slot + 1, typeName, gMapObjModel[slot], gMapObjName[slot], GetPlayerDistanceFromPoint(playerid, gMapObjX[slot], gMapObjY[slot], gMapObjZ[slot]));
    SendClientMessage(playerid, COLOR_YELLOW, message);
    SendClientMessage(playerid, COLOR_GRAY, "Use /removerobjeto [id] ou /removerportao [id] para apagar e salvar.");
    return 1;
}

stock MapObj_RemoveSlot(playerid, slot)
{
    new message[180];
    new typeName[16];
    new objectName[MAP_OBJECT_NAME_SIZE];
    new modelid;

    if (!MapObj_CanManage(playerid))
    {
        return SendNoPermission(playerid);
    }
    if (slot < 0 || slot >= gMapObjCount || gMapObjModel[slot] <= 0)
    {
        return SendUsage(playerid, "/removerobjeto [id]");
    }

    format(typeName, sizeof(typeName), "%s", gMapObjType[slot] == MAP_OBJECT_TYPE_GATE ? ("portao") : ("objeto"));
    format(objectName, sizeof(objectName), "%s", gMapObjName[slot]);
    modelid = gMapObjModel[slot];

    if (!MapObj_SaveAllExcept(slot))
    {
        SendClientMessage(playerid, COLOR_RED, "Nao foi possivel salvar scriptfiles/map_objects.txt.");
        return 1;
    }

    MapObj_LoadAll();
    format(message, sizeof(message), "%s ID %d removido: model %d | %s. Arquivo salvo e mapa recarregado.", typeName, slot + 1, modelid, objectName);
    SendClientMessage(playerid, COLOR_GREEN, message);
    WritePlayerLog(LOG_ADMIN_FILE, "MAP_OBJECT_REMOVE", playerid, message);
    return 1;
}

stock MapObj_GotoSlot(playerid, slot)
{
    new message[180];
    new typeName[16];
    new Float:x;
    new Float:y;
    new Float:z;

    if (!MapObj_CanManage(playerid))
    {
        return SendNoPermission(playerid);
    }
    if (slot < 0 || slot >= gMapObjCount || gMapObjModel[slot] <= 0)
    {
        return SendUsage(playerid, "/irobjeto [id]");
    }

    x = gMapObjX[slot] + 2.0;
    y = gMapObjY[slot] + 2.0;
    z = gMapObjZ[slot] + 1.0;
    if (IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        SetVehiclePos(GetPlayerVehicleID(playerid), x, y, z);
        SetVehicleZAngle(GetPlayerVehicleID(playerid), gMapObjRZ[slot]);
        LinkVehicleToInterior(GetPlayerVehicleID(playerid), gMapObjInterior[slot]);
        SetVehicleVirtualWorld(GetPlayerVehicleID(playerid), gMapObjWorld[slot]);
    }
    SetPlayerInterior(playerid, gMapObjInterior[slot]);
    SetPlayerVirtualWorld(playerid, gMapObjWorld[slot]);
    SetPlayerPos(playerid, x, y, z);
    SetPlayerFacingAngle(playerid, gMapObjRZ[slot]);
    Security_GrantTeleportGrace(playerid);
    SetCameraBehindPlayer(playerid);

    format(typeName, sizeof(typeName), "%s", gMapObjType[slot] == MAP_OBJECT_TYPE_GATE ? ("portao") : ("objeto"));
    format(message, sizeof(message), "Teleportado para %s ID %d: model %d | %s.", typeName, slot + 1, gMapObjModel[slot], gMapObjName[slot]);
    SendClientMessage(playerid, COLOR_GREEN, message);
    return 1;
}

stock MapObj_ShowGotoDialog(playerid, typeFilter = -1, page = 0)
{
    new list[3600];
    new line[128];
    new slot;
    new skipped;
    new shown;
    new title[64];
    new typeName[16];
    new index;

    if (!MapObj_CanManage(playerid))
    {
        return SendNoPermission(playerid);
    }
    if (page < 0)
    {
        page = 0;
    }

    gPlayerMapGotoPage[playerid] = page;
    gPlayerMapGotoFilter[playerid] = typeFilter;
    gPlayerMapGotoHasNext[playerid] = 0;
    for (index = 0; index < MAP_GOTO_PAGE_SIZE; index++)
    {
        gPlayerMapGotoSlots[playerid][index] = -1;
    }
    format(list, sizeof(list), "ID\tTipo\tNome\n");

    for (slot = 0; slot < gMapObjCount; slot++)
    {
        if (gMapObjModel[slot] <= 0 || (typeFilter != -1 && gMapObjType[slot] != typeFilter))
        {
            continue;
        }
        if (skipped < page * MAP_GOTO_PAGE_SIZE)
        {
            skipped++;
            continue;
        }
        if (shown >= MAP_GOTO_PAGE_SIZE)
        {
            break;
        }

        gPlayerMapGotoSlots[playerid][shown] = slot;
        format(typeName, sizeof(typeName), "%s", gMapObjType[slot] == MAP_OBJECT_TYPE_GATE ? ("portao") : ("objeto"));
        format(line, sizeof(line), "%d\t%s\t%s\n", slot + 1, typeName, gMapObjName[slot]);
        strcat(list, line, sizeof(list));
        shown++;
    }

    if (slot < gMapObjCount)
    {
        gPlayerMapGotoHasNext[playerid] = 1;
        strcat(list, ">>\tProxima pagina\t\n", sizeof(list));
    }
    if (page > 0)
    {
        strcat(list, "<<\tPagina anterior\t\n", sizeof(list));
    }
    if (shown == 0)
    {
        strcat(list, "-\tNenhum item\t\n", sizeof(list));
    }

    if (typeFilter == MAP_OBJECT_TYPE_GATE)
    {
        format(title, sizeof(title), "Ir ate portao - Pagina %d", page + 1);
    }
    else if (typeFilter == MAP_OBJECT_TYPE_STATIC)
    {
        format(title, sizeof(title), "Ir ate objeto - Pagina %d", page + 1);
    }
    else
    {
        format(title, sizeof(title), "Ir ate objeto/portao - Pagina %d", page + 1);
    }
    ShowPlayerDialog(playerid, DIALOG_MAP_GOTO_LIST, DIALOG_STYLE_TABLIST_HEADERS, title, list, "Ir", "Fechar");
    return 1;
}

stock MapObj_HandleGotoDialog(playerid, response, listitem)
{
    new shown;
    new slot;

    if (!response)
    {
        return 1;
    }

    for (shown = 0; shown < MAP_GOTO_PAGE_SIZE; shown++)
    {
        slot = gPlayerMapGotoSlots[playerid][shown];
        if (slot >= 0 && slot < gMapObjCount && gMapObjModel[slot] > 0)
        {
            if (listitem == shown)
            {
                return MapObj_GotoSlot(playerid, slot);
            }
        }
        else
        {
            break;
        }
    }
    if (listitem == shown && gPlayerMapGotoHasNext[playerid])
    {
        return MapObj_ShowGotoDialog(playerid, gPlayerMapGotoFilter[playerid], gPlayerMapGotoPage[playerid] + 1);
    }
    if (listitem == shown + gPlayerMapGotoHasNext[playerid] && gPlayerMapGotoPage[playerid] > 0)
    {
        return MapObj_ShowGotoDialog(playerid, gPlayerMapGotoFilter[playerid], gPlayerMapGotoPage[playerid] - 1);
    }
    return 1;
}

stock MapObj_AddGatePreset(playerid, presetid, jobid)
{
    new Float:angle;
    new Float:forwardX;
    new Float:forwardY;
    new Float:rightX;
    new Float:rightY;
    new Float:dx;
    new Float:dy;

    if (presetid < 0 || presetid >= MAP_GATE_PRESET_COUNT)
    {
        SendClientMessage(playerid, COLOR_RED, "Modelo de portao invalido.");
        return 1;
    }

    GetPlayerFacingAngle(playerid, angle);
    forwardX = floatsin(-angle, degrees);
    forwardY = floatcos(-angle, degrees);
    rightX = floatcos(-angle, degrees);
    rightY = -floatsin(-angle, degrees);

    dx = (forwardX * gMapGatePresetForward[presetid]) + (rightX * gMapGatePresetRight[presetid]);
    dy = (forwardY * gMapGatePresetForward[presetid]) + (rightY * gMapGatePresetRight[presetid]);

    return MapObj_AddGate(
        playerid,
        gMapGatePresetModel[presetid],
        dx,
        dy,
        gMapGatePresetUp[presetid],
        gMapGatePresetRange[presetid],
        gMapGatePresetName[presetid],
        jobid
    );
}

stock MapObj_ShowStaticDialog(playerid)
{
    new list[1024];
    new line[128];
    new index;

    if (!MapObj_CanManage(playerid))
    {
        return SendNoPermission(playerid);
    }

    format(list, sizeof(list), "Objeto\tModelo\n");
    for (index = 0; index < MAP_STATIC_PRESET_COUNT; index++)
    {
        format(line, sizeof(line), "%s\tID %d\n", gMapStaticPresetName[index], gMapStaticPresetModel[index]);
        strcat(list, line, sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_MAP_OBJECT_LIST, DIALOG_STYLE_TABLIST_HEADERS, "Criar objeto fixo", list, "Criar", "Fechar");
    SendClientMessage(playerid, COLOR_GRAY, "Selecione o objeto. A posicao atual sera capturada automaticamente.");
    return 1;
}

stock MapObj_ShowGateDialog(playerid)
{
    new list[1536];
    new line[144];
    new index;

    if (!MapObj_CanManage(playerid))
    {
        return SendNoPermission(playerid);
    }

    format(list, sizeof(list), "Portao\tAbertura\n");
    for (index = 0; index < MAP_GATE_PRESET_COUNT; index++)
    {
        format(
            line,
            sizeof(line),
            "%s\tID %d | %.1fm %.1fm %.1fm\n",
            gMapGatePresetName[index],
            gMapGatePresetModel[index],
            gMapGatePresetForward[index],
            gMapGatePresetRight[index],
            gMapGatePresetUp[index]
        );
        strcat(list, line, sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_MAP_GATE_LIST, DIALOG_STYLE_TABLIST_HEADERS, "Criar portao", list, "Criar", "Fechar");
    SendClientMessage(playerid, COLOR_GRAY, "Selecione o portao. Posicao, angulo, interior e VW serao capturados agora.");
    return 1;
}

stock MapObj_ShowGateJobDialog(playerid, presetid)
{
    new list[1536];
    new line[96];
    new index;

    if (!MapObj_CanManage(playerid))
    {
        return SendNoPermission(playerid);
    }

    if (presetid < 0 || presetid >= MAP_GATE_PRESET_COUNT)
    {
        return MapObj_ShowGateDialog(playerid);
    }

    gPlayerMapGatePreset[playerid] = presetid;
    format(list, sizeof(list), "Profissao\tAcesso\n");
    for (index = 0; index < MAP_GATE_JOB_COUNT; index++)
    {
        if (gMapGateJobIds[index] == JOB_NONE)
        {
            format(line, sizeof(line), "%s\tqualquer motorista\n", gMapGateJobNames[index]);
        }
        else
        {
            format(line, sizeof(line), "%s\tjob %d\n", gMapGateJobNames[index], gMapGateJobIds[index]);
        }
        strcat(list, line, sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_MAP_GATE_JOB, DIALOG_STYLE_TABLIST_HEADERS, "Profissao do portao", list, "Salvar", "Voltar");
    SendClientMessage(playerid, COLOR_GRAY, "Escolha a profissao dona. Depois o portao abrira so com H/buzina dessa profissao.");
    return 1;
}

stock MapObj_HandleStaticDialog(playerid, response, listitem)
{
    if (!response)
    {
        return 1;
    }

    if (!MapObj_CanManage(playerid))
    {
        return SendNoPermission(playerid);
    }

    if (listitem < 0 || listitem >= MAP_STATIC_PRESET_COUNT)
    {
        return MapObj_ShowStaticDialog(playerid);
    }
    if (gMapStaticPresetModel[listitem] == 0)
    {
        return MapObj_AddPrfFiscalKit(playerid);
    }
    if (gMapStaticPresetModel[listitem] == -1)
    {
        return MapObj_AddTollDoubleLaneKit(playerid);
    }

    return MapObj_AddStatic(playerid, gMapStaticPresetModel[listitem], gMapStaticPresetName[listitem]);
}

stock MapObj_HandleGateDialog(playerid, response, listitem)
{
    if (!response)
    {
        return 1;
    }

    if (!MapObj_CanManage(playerid))
    {
        return SendNoPermission(playerid);
    }

    if (listitem < 0 || listitem >= MAP_GATE_PRESET_COUNT)
    {
        return MapObj_ShowGateDialog(playerid);
    }

    return MapObj_ShowGateJobDialog(playerid, listitem);
}

stock MapObj_HandleGateJobDialog(playerid, response, listitem)
{
    new presetid;
    new jobid;

    if (!response)
    {
        return MapObj_ShowGateDialog(playerid);
    }

    if (!MapObj_CanManage(playerid))
    {
        return SendNoPermission(playerid);
    }

    if (listitem < 0 || listitem >= MAP_GATE_JOB_COUNT)
    {
        return MapObj_ShowGateJobDialog(playerid, gPlayerMapGatePreset[playerid]);
    }

    presetid = gPlayerMapGatePreset[playerid];
    if (presetid < 0 || presetid >= MAP_GATE_PRESET_COUNT)
    {
        return MapObj_ShowGateDialog(playerid);
    }

    jobid = gMapGateJobIds[listitem];
    return MapObj_AddGatePreset(playerid, presetid, jobid);
}

stock MapObj_FindGate(playerid)
{
    new slot;
    new bestSlot = -1;
    new Float:bestDistance = 999999.0;
    new Float:distance;
    new interior = GetPlayerInterior(playerid);
    new world = GetPlayerVirtualWorld(playerid);

    for (slot = 0; slot < gMapObjCount; slot++)
    {
        if (gMapObjType[slot] != MAP_OBJECT_TYPE_GATE)
        {
            continue;
        }

        if (gMapObjInterior[slot] != interior || gMapObjWorld[slot] != world)
        {
            continue;
        }

        if (!IsPlayerInRangeOfPoint(playerid, gMapObjRange[slot], gMapObjX[slot], gMapObjY[slot], gMapObjZ[slot]))
        {
            continue;
        }

        distance = GetPlayerDistanceFromPoint(playerid, gMapObjX[slot], gMapObjY[slot], gMapObjZ[slot]);
        if (distance < bestDistance)
        {
            bestDistance = distance;
            bestSlot = slot;
        }
    }
    return bestSlot;
}

stock MapObj_CanUseGate(playerid, slot)
{
    new jobName[32];

    if (slot < 0 || slot >= gMapObjCount)
    {
        return 0;
    }

    if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Portoes e cancelas abrem pela buzina H enquanto voce dirige.");
        return 0;
    }

    if (gMapObjJob[slot] != JOB_NONE && PlayerInfo[playerid][pJob] != gMapObjJob[slot])
    {
        MapObj_GetJobName(gMapObjJob[slot], jobName, sizeof(jobName));
        SendClientMessage(playerid, COLOR_RED, "Voce nao tem a profissao autorizada para este portao.");
        SendClientMessage(playerid, COLOR_GRAY, jobName);
        return 0;
    }

    return 1;
}

stock MapObj_IsGateNearPlayer(playerid, slot)
{
    if (slot < 0 || slot >= gMapObjCount)
    {
        return 0;
    }

    if (gMapObjType[slot] != MAP_OBJECT_TYPE_GATE)
    {
        return 0;
    }

    if (gMapObjInterior[slot] != GetPlayerInterior(playerid) || gMapObjWorld[slot] != GetPlayerVirtualWorld(playerid))
    {
        return 0;
    }

    return IsPlayerInRangeOfPoint(playerid, gMapObjRange[slot], gMapObjX[slot], gMapObjY[slot], gMapObjZ[slot]);
}

stock MapObj_HasGateAccess(playerid, slot)
{
    if (slot < 0 || slot >= gMapObjCount)
    {
        return 0;
    }

    if (gMapObjJob[slot] == JOB_NONE || PlayerInfo[playerid][pJob] == gMapObjJob[slot])
    {
        return 1;
    }
    return 0;
}

stock MapObj_CloseGateSlot(slot)
{
    if (slot < 0 || slot >= gMapObjCount || gMapObjType[slot] != MAP_OBJECT_TYPE_GATE)
    {
        return 0;
    }

    if (gMapObjCloseTimer[slot])
    {
        KillTimer(gMapObjCloseTimer[slot]);
        gMapObjCloseTimer[slot] = 0;
    }

    if (!gMapObjOpen[slot])
    {
        return 1;
    }

    MoveObject(gMapObjId[slot], gMapObjX[slot], gMapObjY[slot], gMapObjZ[slot], gMapObjSpeed[slot], gMapObjRX[slot], gMapObjRY[slot], gMapObjRZ[slot]);
    gMapObjOpen[slot] = 0;
    return 1;
}

stock MapObj_OpenGateSlot(slot)
{
    if (slot < 0 || slot >= gMapObjCount || gMapObjType[slot] != MAP_OBJECT_TYPE_GATE)
    {
        return 0;
    }

    if (gMapObjCloseTimer[slot])
    {
        KillTimer(gMapObjCloseTimer[slot]);
        gMapObjCloseTimer[slot] = 0;
    }

    MoveObject(gMapObjId[slot], gMapObjOpenX[slot], gMapObjOpenY[slot], gMapObjOpenZ[slot], gMapObjSpeed[slot], gMapObjOpenRX[slot], gMapObjOpenRY[slot], gMapObjOpenRZ[slot]);
    gMapObjOpen[slot] = 1;
    gMapObjCloseTimer[slot] = SetTimerEx("MapObj_AutoCloseGate", MAP_GATE_AUTO_CLOSE_MS, false, "d", slot);
    return 1;
}

public MapObj_AutoCloseGate(slot)
{
    if (slot < 0 || slot >= gMapObjCount)
    {
        return 1;
    }

    gMapObjCloseTimer[slot] = 0;
    if (gMapObjType[slot] == MAP_OBJECT_TYPE_GATE && gMapObjOpen[slot])
    {
        MoveObject(gMapObjId[slot], gMapObjX[slot], gMapObjY[slot], gMapObjZ[slot], gMapObjSpeed[slot], gMapObjRX[slot], gMapObjRY[slot], gMapObjRZ[slot]);
        gMapObjOpen[slot] = 0;
    }
    return 1;
}

stock MapObj_ToggleGate(playerid, fromHorn)
{
    new slot = MapObj_FindGate(playerid);
    new message[96];
    new index;
    new gateCount;
    new shouldOpen;

    if (slot == -1)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Voce nao esta perto de um portao interativo.");
        return 1;
    }

    if (!fromHorn)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Use H/buzina dirigindo para abrir ou fechar portoes e cancelas.");
        return 1;
    }

    if (!IsPlayerInAnyVehicle(playerid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
    {
        SendClientMessage(playerid, COLOR_GRAY, "Portoes e cancelas abrem pela buzina H enquanto voce dirige.");
        return 1;
    }

    for (index = 0; index < gMapObjCount; index++)
    {
        if (!MapObj_IsGateNearPlayer(playerid, index) || !MapObj_HasGateAccess(playerid, index))
        {
            continue;
        }

        gateCount++;
        if (!gMapObjOpen[index])
        {
            shouldOpen = 1;
        }
    }

    if (gateCount == 0)
    {
        MapObj_CanUseGate(playerid, slot);
        return 1;
    }

    for (index = 0; index < gMapObjCount; index++)
    {
        if (!MapObj_IsGateNearPlayer(playerid, index) || !MapObj_HasGateAccess(playerid, index))
        {
            continue;
        }

        if (shouldOpen)
        {
            MapObj_OpenGateSlot(index);
        }
        else
        {
            MapObj_CloseGateSlot(index);
        }
    }

    format(message, sizeof(message), "%d portao(s) %s.", gateCount, shouldOpen ? ("abrindo") : ("fechando"));
    SendClientMessage(playerid, COLOR_YELLOW, message);
    return 1;
}

stock MapObj_ShowStatus(playerid)
{
    new message[144];

    if (!MapObj_CanManage(playerid))
    {
        return SendNoPermission(playerid);
    }

    format(message, sizeof(message), "Objetos do mapa carregados: %d/%d. Arquivo: %s.", gMapObjCount, MAX_MAP_OBJECTS, MAP_OBJECTS_FILE);
    SendClientMessage(playerid, COLOR_YELLOW, message);
    SendClientMessage(playerid, COLOR_GRAY, "Criar objeto por dialog: /addobjeto");
    SendClientMessage(playerid, COLOR_GRAY, "Criar portao por dialog: /addportao");
    SendClientMessage(playerid, COLOR_GRAY, "Remover: /objetomaisperto, /removerobjeto [id] ou /removerportao [id].");
    return 1;
}

stock MapObjects_Init()
{
    return MapObj_LoadAll();
}

stock MapObjects_Exit()
{
    return MapObj_DestroyAll();
}

stock MapObjects_Count()
{
    return gMapObjCount;
}

stock MapObj_OnKeyStateChange(playerid, newkeys, oldkeys)
{
    if (((newkeys & KEY_CROUCH) && !(oldkeys & KEY_CROUCH)) || ((newkeys & KEY_SUBMISSION) && !(oldkeys & KEY_SUBMISSION)))
    {
        if (MapObj_FindGate(playerid) != -1)
        {
            return MapObj_ToggleGate(playerid, 1);
        }
    }
    return 0;
}

stock MapObjects_HandleCommands(playerid, cmdtext[])
{
    new command[32];
    new index;
    new param[64];
    new firstName[64];
    new name[MAP_OBJECT_NAME_SIZE];
    new modelid;
    new Float:dx;
    new Float:dy;
    new Float:dz = 4.0;
    new Float:range = MAP_OBJECT_DEFAULT_RANGE;

    index = GetCommandName(cmdtext, command, sizeof(command));

    if (strcmp(command, "/portao", true) == 0 || strcmp(command, "/gate", true) == 0)
    {
        return MapObj_ToggleGate(playerid, 0);
    }

    if (strcmp(command, "/objetosmapa", true) == 0 || strcmp(command, "/mapobjects", true) == 0)
    {
        return MapObj_ShowStatus(playerid);
    }

    if (strcmp(command, "/objetomaisperto", true) == 0 || strcmp(command, "/mapobjmaisperto", true) == 0 || strcmp(command, "/portaomaisperto", true) == 0)
    {
        return MapObj_SendNearest(playerid, -1);
    }

    if (strcmp(command, "/removerobjeto", true) == 0 || strcmp(command, "/delobjeto", true) == 0 || strcmp(command, "/deleteobjeto", true) == 0 || strcmp(command, "/removerportao", true) == 0 || strcmp(command, "/delportao", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return SendUsage(playerid, "/removerobjeto [id]");
        }
        return MapObj_RemoveSlot(playerid, strval(param) - 1);
    }

    if (strcmp(command, "/irobjeto", true) == 0 || strcmp(command, "/gotoobjeto", true) == 0 || strcmp(command, "/tpobjeto", true) == 0 || strcmp(command, "/irportao", true) == 0 || strcmp(command, "/gotoportao", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)))
        {
            if (strcmp(command, "/irportao", true) == 0 || strcmp(command, "/gotoportao", true) == 0)
            {
                return MapObj_ShowGotoDialog(playerid, MAP_OBJECT_TYPE_GATE, 0);
            }
            return MapObj_ShowGotoDialog(playerid, MAP_OBJECT_TYPE_STATIC, 0);
        }
        if (!IsNumericString(param))
        {
            return SendUsage(playerid, "/irobjeto [id]");
        }
        return MapObj_GotoSlot(playerid, strval(param) - 1);
    }

    if (strcmp(command, "/reloadobjetos", true) == 0 || strcmp(command, "/reloadmapobjects", true) == 0)
    {
        if (!MapObj_CanManage(playerid))
        {
            return SendNoPermission(playerid);
        }

        MapObj_LoadAll();
        format(param, sizeof(param), "Objetos do mapa recarregados: %d.", gMapObjCount);
        SendClientMessage(playerid, COLOR_GREEN, param);
        WritePlayerLog(LOG_ADMIN_FILE, "MAP_OBJECT_RELOAD", playerid, "reload map_objects.txt");
        return 1;
    }

    if (strcmp(command, "/addobjeto", true) == 0 || strcmp(command, "/criarobjeto", true) == 0 || strcmp(command, "/salvarobjeto", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return MapObj_ShowStaticDialog(playerid);
        }

        modelid = strval(param);
        if (GetRemainingText(cmdtext, index, name, sizeof(name)))
        {
            MapObj_CopyName(name, name, sizeof(name));
        }
        else
        {
            name[0] = 0;
        }
        return MapObj_AddStatic(playerid, modelid, name);
    }

    if (strcmp(command, "/addportao", true) == 0 || strcmp(command, "/criarportao", true) == 0 || strcmp(command, "/salvarportao", true) == 0)
    {
        if (!GetNextParam(cmdtext, index, param, sizeof(param)) || !IsNumericString(param))
        {
            return MapObj_ShowGateDialog(playerid);
        }

        modelid = strval(param);

        if (GetNextParam(cmdtext, index, firstName, sizeof(firstName)))
        {
            if (MapObj_IsFloat(firstName))
            {
                dx = floatstr(firstName);
                if (GetNextParam(cmdtext, index, firstName, sizeof(firstName)))
                {
                    if (MapObj_IsFloat(firstName))
                    {
                        dy = floatstr(firstName);
                        if (GetNextParam(cmdtext, index, firstName, sizeof(firstName)))
                        {
                            if (MapObj_IsFloat(firstName))
                            {
                                dz = floatstr(firstName);
                                if (GetNextParam(cmdtext, index, firstName, sizeof(firstName)))
                                {
                                    if (MapObj_IsFloat(firstName))
                                    {
                                        range = floatstr(firstName);
                                        if (GetRemainingText(cmdtext, index, name, sizeof(name)))
                                        {
                                            MapObj_CopyName(name, name, sizeof(name));
                                        }
                                    }
                                    else
                                    {
                                        MapObj_ReadName(cmdtext, index, firstName, name, sizeof(name));
                                    }
                                }
                            }
                            else
                            {
                                MapObj_ReadName(cmdtext, index, firstName, name, sizeof(name));
                            }
                        }
                    }
                    else
                    {
                        MapObj_ReadName(cmdtext, index, firstName, name, sizeof(name));
                    }
                }
            }
            else
            {
                MapObj_ReadName(cmdtext, index, firstName, name, sizeof(name));
            }
        }

        return MapObj_AddGate(playerid, modelid, dx, dy, dz, range, name, PlayerInfo[playerid][pJob]);
    }

    return 0;
}
