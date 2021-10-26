#include "MCU.h"


#define MCU_REGISTER_KEY                    0x05FA

const strMCUConfigType_t* gstrMCUConfigType;


void MCU_Init(const strMCUConfigType_t* strMCUConfigType)
{
    gstrMCUConfigType = strMCUConfigType;
}

enuMCURawResetType_t MCU_GetResetRawValue(void)
{
    enuMCURawResetType_t enuMCURawResetType;

    if(RESC.B.EXT == HIGH)
    {
        enuMCURawResetType = EXTERNAL_RESET;
    }
    else if(RESC.B.POR == HIGH)
    {
        enuMCURawResetType = POWER_ON_RESET;
    }
    else if(RESC.B.BOR == HIGH)
    {
        enuMCURawResetType = BROWN_OUT_RESET;
    }
    else if(RESC.B.WDT0 == HIGH)
    {
        enuMCURawResetType = WATCHDOG_TIMER_0_RESET;
    }
    else if(RESC.B.SW == HIGH)
    {
        enuMCURawResetType = SOFTWARE_RESET;
    }
    else if(RESC.B.WDT1 == HIGH)
    {
        enuMCURawResetType = WATCHDOG_TIMER_1_RESET;
    }
    else if(RESC.B.MOSCFAIL == HIGH)
    {
        enuMCURawResetType = MOSC_FAILURE_RESET;
    }
    else
    {
        enuMCURawResetType = INVALID;
    }
    return enuMCURawResetType;
}

void MCU_PerformReset(void)
{
    APINT.B.VECTKEY = MCU_REGISTER_KEY;
    APINT.B.SYSRESREQ = HIGH;
    APINT.B.VECTRESET = LOW;
}

enuErrorStatus_t MCU_InitClock(enuMCUClockType_t enuMCUClockType)
{
    enuErrorStatus_t enuErrorStatus;

    if(((gstrMCUConfigType->enuMCUClockType >= 0)       && (gstrMCUConfigType->enuMCUClockType <= 3))   &&
       ((gstrMCUConfigType->enuPLLModeType >= 0)        && (gstrMCUConfigType->enuPLLModeType <= 1))    &&
       ((gstrMCUConfigType->enuMCUCrystalValue >= 0)    && (gstrMCUConfigType->enuMCUCrystalValue <= 21)))
    {
        RCC.B.OSCSRC = gstrMCUConfigType->enuMCUClockType;
        RCC.B.PWRDN = gstrMCUConfigType->enuPLLModeType;
        RCC.B.XTAL = gstrMCUConfigType->enuMCUCrystalValue;
        RCC.B.MOSCDIS = LOW;
        enuErrorStatus = E_OK;
    }
    else
    {
        enuErrorStatus = E_ERROR;
    }
    return enuErrorStatus;
}

enuErrorStatus_t MCU_DistributePLLClock(void)
{
    enuErrorStatus_t enuErrorStatus;

    if((MCU_SYSCTL_SISDIV >= 0) && (MCU_SYSCTL_SISDIV <= 15))
    {
        RCC.B.SYSDIV = MCU_SYSCTL_SISDIV;
        RCC.B.BYPASS = LOW;
        enuErrorStatus = E_OK;
    }
    else
    {
        enuErrorStatus = E_ERROR;
    }
    return enuErrorStatus;
}

enuMCUPLLStatusType_t MCU_GetPLLStatus(void)
{
    enuMCUPLLStatusType_t enuMCUPLLStatusType;

    enuMCUPLLStatusType = (enuMCUPLLStatusType_t)PLLSTAT.B.LOCK;
    return enuMCUPLLStatusType;
}
