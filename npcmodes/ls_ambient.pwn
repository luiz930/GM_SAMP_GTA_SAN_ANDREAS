#include <a_npc>

#if defined AMBIENT_RECORDING_TYPE
new gPlaybackType = AMBIENT_RECORDING_TYPE;
#else
new gPlaybackType = PLAYER_RECORDING_TYPE_ONFOOT;
#endif

#if defined AMBIENT_RECORDING_NAME
new gRecording[32] = AMBIENT_RECORDING_NAME;
#else
new gRecording[32] = "ls_ped_cityhall";
#endif

new gPlaybackActive;
new gPlaybackPaused;
new gStopUntil;
new gResumeTimer;

main()
{
}

forward Ambient_CheckResume();

stock Ambient_UseRecording(type, recordName[])
{
    gPlaybackType = type;
    format(gRecording, sizeof(gRecording), "%s", recordName);
    return 1;
}

stock Ambient_SetRecording(name[])
{
    #if defined AMBIENT_RECORDING_NAME
    #pragma unused name
    return 1;
    #else
    if (strfind(name, "NPC_CARRO_01", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_DRIVER, "ls_car_cityhall");
    }
    if (strfind(name, "NPC_CARRO_02", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_DRIVER, "ls_car_hospital");
    }
    if (strfind(name, "NPC_CARRO_03", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_DRIVER, "ls_car_idlewood");
    }
    if (strfind(name, "NPC_CARRO_04", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_DRIVER, "ls_car_prf");
    }
    if (strfind(name, "NPC_CIVIL_02", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_hospital");
    }
    if (strfind(name, "NPC_CIVIL_03", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_idlewood");
    }
    if (strfind(name, "NPC_CIVIL_04", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_prf");
    }
    if (strfind(name, "NPC_CIVIL_05", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_cityhall_2");
    }
    if (strfind(name, "NPC_CIVIL_06", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_bank");
    }
    if (strfind(name, "NPC_CIVIL_07", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_detran");
    }
    if (strfind(name, "NPC_CIVIL_08", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_police_civil");
    }
    if (strfind(name, "NPC_CIVIL_09", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_pf");
    }
    if (strfind(name, "NPC_CIVIL_10", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_penal");
    }
    if (strfind(name, "NPC_CIVIL_11", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_fire");
    }
    if (strfind(name, "NPC_CIVIL_12", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_terminal");
    }
    if (strfind(name, "NPC_CIVIL_13", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_pier");
    }
    if (strfind(name, "NPC_CIVIL_14", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_mechanic");
    }
    if (strfind(name, "NPC_CIVIL_15", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_gas");
    }
    if (strfind(name, "NPC_CIVIL_16", true) != -1)
    {
        return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_store");
    }

    return Ambient_UseRecording(PLAYER_RECORDING_TYPE_ONFOOT, "ls_ped_cityhall");
    #endif
}

stock Ambient_StartPlayback()
{
    if (gPlaybackPaused)
    {
        return 1;
    }

    StartRecordingPlayback(gPlaybackType, gRecording);
    gPlaybackActive = 1;
    return 1;
}

stock Ambient_PausePlayback()
{
    gStopUntil = GetTickCount() + 30000;
    if (!gPlaybackPaused)
    {
        PauseRecordingPlayback();
        gPlaybackPaused = 1;
    }
    return 1;
}

stock Ambient_PausePlaybackIndefinite()
{
    gStopUntil = 0;
    if (!gPlaybackPaused)
    {
        PauseRecordingPlayback();
        gPlaybackPaused = 1;
    }
    return 1;
}

stock Ambient_ResumePlayback()
{
    if (!gPlaybackPaused)
    {
        return 1;
    }

    gPlaybackPaused = 0;
    gStopUntil = 0;
    ResumeRecordingPlayback();
    if (!gPlaybackActive)
    {
        Ambient_StartPlayback();
    }
    return 1;
}

public OnNPCModeInit()
{
    gResumeTimer = SetTimer("Ambient_CheckResume", 1000, 1);
    return 1;
}

public OnNPCModeExit()
{
    if (gResumeTimer)
    {
        KillTimer(gResumeTimer);
    }
    return 1;
}

public OnNPCConnect(myplayerid)
{
    new name[MAX_PLAYER_NAME + 1];

    GetPlayerName(myplayerid, name, sizeof(name));
    Ambient_SetRecording(name);
    return 1;
}

public OnClientMessage(color, text[])
{
    #pragma unused color

    if (strcmp(text, "NPC_CMD_STOP", true) == 0)
    {
        Ambient_PausePlayback();
        return 1;
    }

    if (strcmp(text, "NPC_CMD_CUFF", true) == 0)
    {
        Ambient_PausePlaybackIndefinite();
        return 1;
    }

    if (strcmp(text, "NPC_CMD_IDLE", true) == 0)
    {
        Ambient_PausePlaybackIndefinite();
        return 1;
    }

    if (strcmp(text, "NPC_CMD_JAIL", true) == 0)
    {
        if (gPlaybackActive)
        {
            StopRecordingPlayback();
            gPlaybackActive = 0;
        }
        gPlaybackPaused = 1;
        gStopUntil = 0;
        return 1;
    }

    if (strcmp(text, "NPC_CMD_DRIVER_RESET", true) == 0)
    {
        if (gPlaybackActive)
        {
            StopRecordingPlayback();
            gPlaybackActive = 0;
        }
        gPlaybackPaused = 1;
        gStopUntil = 0;
        return 1;
    }

    if (strcmp(text, "NPC_CMD_RESUME", true) == 0)
    {
        Ambient_ResumePlayback();
        return 1;
    }

    if (strcmp(text, "NPC_CMD_RESTART", true) == 0)
    {
        if (gPlaybackActive)
        {
            StopRecordingPlayback();
            gPlaybackActive = 0;
        }
        gPlaybackPaused = 0;
        gStopUntil = 0;
        Ambient_StartPlayback();
        return 1;
    }

    return 1;
}

public OnNPCSpawn()
{
    if (gPlaybackType == PLAYER_RECORDING_TYPE_ONFOOT)
    {
        Ambient_StartPlayback();
    }
    return 1;
}

public OnNPCEnterVehicle(vehicleid, seatid)
{
    if (gPlaybackType == PLAYER_RECORDING_TYPE_DRIVER)
    {
        Ambient_StartPlayback();
    }
    return 1;
}

public OnNPCExitVehicle()
{
    if (gPlaybackActive)
    {
        StopRecordingPlayback();
        gPlaybackActive = 0;
    }
    return 1;
}

public OnRecordingPlaybackEnd()
{
    gPlaybackActive = 0;
    if (!gPlaybackPaused)
    {
        Ambient_StartPlayback();
    }
    return 1;
}

public Ambient_CheckResume()
{
    if (gPlaybackPaused && gStopUntil > 0 && GetTickCount() >= gStopUntil)
    {
        Ambient_ResumePlayback();
    }
    return 1;
}
