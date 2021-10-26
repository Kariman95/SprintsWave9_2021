#ifndef MCU_H_
#define MCU_H_

#include "MCU_Cfg.h"
#include "TM4C123GH6PM_HW.h"

typedef enum {UNLOCKED, LOCKED} enuMCUPLLStatusType_t;
typedef enum {MOSC, PIOSC, PIOSC_4, LFIOSC} enuMCUClockType_t;
typedef enum {FREQ_4, FREQ_4_096, FREQ_4_9152, FREQ_5, FREQ_5_12, FREQ_6, FREQ_6_144,
              FREQ_7, FREQ_7_3728, FREQ_8, FREQ_8_192, FREQ_10, FREQ_12, FREQ_12_288,
              FREQ_13_56, FREQ_14_31818, FREQ_16, FREQ_16_384, FREQ_18, FREQ_20, FREQ_24,
              FREQ_25} enuMCUCrystalValue_t;

typedef enum {EXTERNAL_RESET, POWER_ON_RESET, BROWN_OUT_RESET, WATCHDOG_TIMER_0_RESET,
              SOFTWARE_RESET, WATCHDOG_TIMER_1_RESET, MOSC_FAILURE_RESET, INVALID} enuMCURawResetType_t;
typedef enum {DISABLE, ENABLE} enuPLLModeType_t;
typedef enum {SYSCTL_SYSDIV_1, SYSCTL_SYSDIV_2, SYSCTL_SYSDIV_3, SYSCTL_SYSDIV_4,
              SYSCTL_SYSDIV_5, SYSCTL_SYSDIV_6, SYSCTL_SYSDIV_7, SYSCTL_SYSDIV_8,
              SYSCTL_SYSDIV_9, SYSCTL_SYSDIV_10, SYSCTL_SYSDIV_11, SYSCTL_SYSDIV_12,
              SYSCTL_SYSDIV_13, SYSCTL_SYSDIV_14, SYSCTL_SYSDIV_15, SYSCTL_SYSDIV_16} enuSystemDivisorType_t;

typedef struct
{
    enuMCUClockType_t enuMCUClockType;
    enuPLLModeType_t enuPLLModeType;
    enuMCUCrystalValue_t enuMCUCrystalValue;
} strMCUConfigType_t;

extern const strMCUConfigType_t astrMCUConfigParameters[MCU_GROUPS_NO];

void MCU_Init(const strMCUConfigType_t* strMCUConfigType);
enuMCURawResetType_t MCU_GetResetRawValue(void);
void MCU_PerformReset(void);
enuErrorStatus_t MCU_InitClock(enuMCUClockType_t enuMCUClockType);
enuErrorStatus_t MCU_DistributePLLClock(void);
enuMCUPLLStatusType_t MCU_GetPLLStatus(void);

#endif /* MCU_H_ */
