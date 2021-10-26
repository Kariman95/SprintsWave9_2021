/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  TM4C123GH6PM_HW.h
 *       Module:  TM4C123GH6PM_HW
 *
 *  Description:  header file for TM4C123GH6PM Hardware
 *
 *********************************************************************************************************************/
#ifndef TM4C123GH6PM_HW_H_
#define TM4C123GH6PM_HW_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*** Cortex-M4 Peripherals ***/
/** System Timer (SysTick) Registers **/
typedef struct
{
    uint32_t ENABLE :1;
    uint32_t INTEN  :1;
    uint32_t CLK_SRC:1;
    uint32_t        :13;
    uint32_t COUNT  :1;
    uint32_t        :15;
} strSTCTRL_t;
typedef union
{
    uint32_t    R;
    strSTCTRL_t B;
} uniSTCTRL_t;

typedef struct
{
    uint32_t RELOAD:24;
} strSTRELOAD_t;
typedef union
{
    uint32_t        R;
    strSTRELOAD_t   B;
} uniSTRELOAD_t;

typedef struct
{
    uint32_t CURRENT:24;
} strSTCURRENT_t;
typedef union
{
    uint32_t        R;
    strSTCURRENT_t  B;
} uniSTCURRENT_t;

/** Nested Vectored Interrupt Controller (NVIC) Registers **/
typedef struct
{
    uint32_t INT00:1;
    uint32_t INT01:1;
    uint32_t INT02:1;
    uint32_t INT03:1;
    uint32_t INT04:1;
    uint32_t INT05:1;
    uint32_t INT06:1;
    uint32_t INT07:1;
    uint32_t INT08:1;
    uint32_t INT09:1;
    uint32_t INT10:1;
    uint32_t INT11:1;
    uint32_t INT12:1;
    uint32_t INT13:1;
    uint32_t INT14:1;
    uint32_t INT15:1;
    uint32_t INT16:1;
    uint32_t INT17:1;
    uint32_t INT18:1;
    uint32_t INT19:1;
    uint32_t INT20:1;
    uint32_t INT21:1;
    uint32_t INT22:1;
    uint32_t INT23:1;
    uint32_t INT24:1;
    uint32_t INT25:1;
    uint32_t INT26:1;
    uint32_t INT27:1;
    uint32_t INT28:1;
    uint32_t INT29:1;
    uint32_t INT30:1;
    uint32_t INT31:1;
} strNVIC_t;
typedef union
{
    uint32_t    R;
    strNVIC_t   B;
} uniNVIC_t;

typedef struct
{
    uint32_t        :5;
    uint32_t INTA   :3;
    uint32_t        :5;
    uint32_t INTB   :3;
    uint32_t        :5;
    uint32_t INTC   :3;
    uint32_t        :5;
    uint32_t INTD   :3;
} strPRI_t;
typedef union
{
    uint32_t R;
    strPRI_t B;
} uniPRI_t;

typedef struct
{
    uint32_t INTID  :8;
    uint32_t        :24;
} strSWTRIG_t;
typedef union
{
    uint32_t    R;
    strSWTRIG_t B;
} uniSWTRIG_t;

/** System Control Block (SCB) Registers **/
typedef struct
{
    uint32_t DISMCYC:1;
    uint32_t DISWBUF:1;
    uint32_t DISFOLD:1;
    uint32_t        :5;
    uint32_t DISFPCA:1;
    uint32_t DISOOFP:1;
    uint32_t        :22;
} strACTLR_t;
typedef union
{
    uint32_t    R;
    strACTLR_t  B;
} uniACTLR_t;

typedef struct
{
    uint32_t REV    :4;
    uint32_t PARTNO :12;
    uint32_t CON    :4;
    uint32_t VAR    :4;
    uint32_t IMP    :8;
} strCPUID_t;
typedef union
{
    uint32_t    R;
    strCPUID_t  B;
} uniCPUID_t;

typedef struct
{
    uint32_t VECACT     :8;
    uint32_t            :3;
    uint32_t RETBASE    :1;
    uint32_t VECPEND    :8;
    uint32_t            :2;
    uint32_t ISRPEND    :1;
    uint32_t ISRPRE     :1;
    uint32_t            :1;
    uint32_t PENDSTCLR  :1;
    uint32_t PENDSTSET  :1;
    uint32_t UNPENDSV   :1;
    uint32_t PENDSV     :1;
    uint32_t            :2;
    uint32_t NMISET     :1;
} strINTCTRL_t;
typedef union
{
    uint32_t        R;
    strINTCTRL_t    B;
} uniINTCTRL_t;

typedef struct
{
    uint32_t        :10;
    uint32_t OFFSET :22;
} strVTABLE_t;
typedef union
{
    uint32_t    R;
    strVTABLE_t B;
} uniVTABLE_t;

typedef struct
{
    uint32_t VECTRESET  :1;
    uint32_t VECTCLRACT :1;
    uint32_t SYSRESREQ  :1;
    uint32_t            :5;
    uint32_t PRIGROUP   :3;
    uint32_t            :4;
    uint32_t ENDIANESS  :1;
    uint32_t VECTKEY    :16;
} strAPINT_t;
typedef union
{
    uint32_t    R;
    strAPINT_t  B;
} uniAPINT_t;

typedef struct
{
    uint32_t            :1;
    uint32_t SLEEPEXIT  :1;
    uint32_t SLEEPDEEP  :1;
    uint32_t            :1;
    uint32_t SEVONPEND  :1;
    uint32_t            :27;
} strSYSCTRL_t;
typedef union
{
    uint32_t        R;
    strSYSCTRL_t    B;
} uniSYSCTRL_t;

typedef struct
{
    uint32_t BASETHR    :1;
    uint32_t MAINPEND   :1;
    uint32_t            :1;
    uint32_t UNALIGNED  :1;
    uint32_t DIV0       :1;
    uint32_t            :3;
    uint32_t BFHFNMIGN  :1;
    uint32_t STKALIGN   :1;
    uint32_t            :22;
} strCFGCTRL_t;
typedef union
{
    uint32_t        R;
    strCFGCTRL_t    B;
} uniCFGCTRL_t;

typedef struct
{
    uint32_t        :5;
    uint32_t MEM    :3;
    uint32_t        :5;
    uint32_t BUS    :3;
    uint32_t        :5;
    uint32_t USAGE  :3;
    uint32_t        :8;
} strSYSPRI1_t;
typedef union
{
    uint32_t        R;
    strSYSPRI1_t    B;
} uniSYSPRI1_t;

typedef struct
{
    uint32_t    :29;
    uint32_t SVC:3;
} strSYSPRI2_t;
typedef union
{
    uint32_t        R;
    strSYSPRI2_t    B;
} uniSYSPRI2_t;

typedef struct
{
    uint32_t        :5;
    uint32_t DEBUG  :3;
    uint32_t        :13;
    uint32_t PENDSV :3;
    uint32_t        :5;
    uint32_t TICK   :3;
} strSYSPRI3_t;
typedef union
{
    uint32_t        R;
    strSYSPRI3_t    B;
} uniSYSPRI3_t;

typedef struct
{
    uint32_t MEMA   :1;
    uint32_t BUSA   :1;
    uint32_t        :1;
    uint32_t USGA   :1;
    uint32_t        :3;
    uint32_t SVCA   :1;
    uint32_t MON    :1;
    uint32_t        :1;
    uint32_t PNDSV  :1;
    uint32_t TICK   :1;
    uint32_t USAGEP :1;
    uint32_t MEMP   :1;
    uint32_t BUSP   :1;
    uint32_t SVC    :1;
    uint32_t MEM    :1;
    uint32_t BUS    :1;
    uint32_t USAGE  :1;
    uint32_t        :13;
} strSYSHNDCTRL_t;
typedef union
{
    uint32_t        R;
    strSYSHNDCTRL_t B;
} uniSYSHNDCTRL_t;

typedef struct
{
    uint32_t IERR   :1;
    uint32_t DERR   :1;
    uint32_t        :1;
    uint32_t MUSTKE :1;
    uint32_t MSTKE  :1;
    uint32_t MLSPERR:1;
    uint32_t        :1;
    uint32_t MMARV  :1;
    uint32_t IBUS   :1;
    uint32_t PRECISE:1;
    uint32_t IMPRE  :1;
    uint32_t BUSTKE :1;
    uint32_t BSTKE  :1;
    uint32_t BLSPERR:1;
    uint32_t        :1;
    uint32_t BFARV  :1;
    uint32_t UNDEF  :1;
    uint32_t INVSTAT:1;
    uint32_t INVPC  :1;
    uint32_t NOCP   :1;
    uint32_t        :4;
    uint32_t UNALIGN:1;
    uint32_t DIV0   :1;
    uint32_t        :6;
} strFAULTSTAT_t;
typedef union
{
    uint32_t        R;
    strFAULTSTAT_t  B;
} uniFAULTSTAT_t;

typedef struct
{
    uint32_t        :1;
    uint32_t VECT   :1;
    uint32_t        :28;
    uint32_t FORCED :1;
    uint32_t DBG    :1;
} strHFAULTSTAT_t;
typedef union
{
    uint32_t        R;
    strHFAULTSTAT_t B;
} uniHFAULTSTAT_t;

typedef struct
{
    uint32_t ADDR:32;
} strADDR_t;
typedef union
{
    uint32_t    R;
    strADDR_t   B;
} uniADDR_t;

typedef struct
{
    uint32_t SEPARATE   :1;
    uint32_t            :7;
    uint32_t DREGION    :8;
    uint32_t IREGION    :8;
    uint32_t            :8;
} strMPUTYPE_t;
typedef union
{
    uint32_t        R;
    strMPUTYPE_t    B;
} uniMPUTYPE_t;

typedef struct
{
    uint32_t ENABLE     :1;
    uint32_t HFNMIENA   :1;
    uint32_t PRIVDEFEN  :1;
    uint32_t            :29;
} strMPUCTRL_t;
typedef union
{
    uint32_t        R;
    strMPUCTRL_t    B;
} uniMPUCTRL_t;

typedef struct
{
    uint32_t NUMBER :3;
    uint32_t        :29;
} strMPUNUMBER_t;
typedef union
{
    uint32_t        R;
    strMPUNUMBER_t  B;
} uniMPUNUMBER_t;

typedef struct
{
    uint32_t REGION :3;
    uint32_t        :1;
    uint32_t VALID  :1;
    uint32_t ADDR   :27;
} strMPUBASE_t;
typedef union
{
    uint32_t        R;
    strMPUBASE_t    B;
} uniMPUBASE_t;

typedef struct
{
    uint32_t ENABLE :1;
    uint32_t SIZE   :5;
    uint32_t        :2;
    uint32_t SRD    :8;
    uint32_t B      :1;
    uint32_t C      :1;
    uint32_t S      :1;
    uint32_t TEX    :3;
    uint32_t        :2;
    uint32_t AP     :3;
    uint32_t        :1;
    uint32_t XN     :1;
    uint32_t        :3;
} strMPUATTR_t;
typedef union
{
    uint32_t        R;
    strMPUATTR_t    B;
} uniMPUATTR_t;

typedef struct
{
    uint32_t        :20;
    uint32_t CP10   :2;
    uint32_t CP11   :2;
    uint32_t        :8;
} strCPAC_t;
typedef union
{
    uint32_t    R;
    strCPAC_t   B;
} uniCPAC_t;

typedef struct
{
    uint32_t LSPACT :1;
    uint32_t USER   :1;
    uint32_t        :1;
    uint32_t THREAD :1;
    uint32_t HFRDY  :1;
    uint32_t MMRDY  :1;
    uint32_t BFRDY  :1;
    uint32_t        :1;
    uint32_t MONRDY :1;
    uint32_t        :21;
    uint32_t LSPEN  :1;
    uint32_t ASPEN  :1;
} strFPCC_t;
typedef union
{
    uint32_t    R;
    strFPCC_t   B;
} uniFPCC_t;

typedef struct
{
    uint32_t        :3;
    uint32_t ADDRESS:29;
} strFPCA_t;
typedef union
{
    uint32_t    R;
    strFPCA_t   B;
} uniFPCA_t;

typedef struct
{
    uint32_t        :22;
    uint32_t RMODE  :2;
    uint32_t FZ     :1;
    uint32_t DN     :1;
    uint32_t AHP    :1;
    uint32_t        :5;
} strFPDSC_t;
typedef union
{
    uint32_t    R;
    strFPDSC_t  B;
} uniFPDSC_t;


/*** System Control ***/
/** System Control Registers **/
typedef struct
{
    uint32_t EXT        :1;
    uint32_t POR        :1;
    uint32_t BOR        :1;
    uint32_t WDT0       :1;
    uint32_t SW         :1;
    uint32_t WDT1       :1;
    uint32_t            :10;
    uint32_t MOSCFAIL   :1;
    uint32_t            :15;
} strRESC_t;
typedef union
{
    uint32_t    R;
    strRESC_t   B;
} uniRESC_t;

typedef struct
{
    uint32_t LOCK   :1;
    uint32_t        :31;
} strPLLSTAT_t;
typedef union
{
    uint32_t        R;
    strPLLSTAT_t    B;
} uniPLLSTAT_t;

typedef struct
{
    uint32_t MOSCDIS    :1;
    uint32_t            :3;
    uint32_t OSCSRC     :2;
    uint32_t XTAL       :5;
    uint32_t BYPASS     :1;
    uint32_t            :1;
    uint32_t PWRDN      :1;
    uint32_t            :3;
    uint32_t PWMDIV     :3;
    uint32_t USEPWMDIV  :1;
    uint32_t            :1;
    uint32_t USESYSDIV  :1;
    uint32_t SYSDIV     :4;
    uint32_t ACG        :1;
    uint32_t            :4;
} strRCC_t;
typedef union
{
    uint32_t R;
    strRCC_t B;
} uniRCC_t;

typedef struct
{
    uint32_t            :4;
    uint32_t OSCSRC2    :3;
    uint32_t            :4;
    uint32_t BYPASS2    :1;
    uint32_t            :1;
    uint32_t PWRDN2     :1;
    uint32_t USBPWRDN   :1;
    uint32_t            :7;
    uint32_t SYSDIV2LSB :1;
    uint32_t SYSDIV2    :6;
    uint32_t            :1;
    uint32_t DIV400     :1;
    uint32_t USERCC2    :1;
} strRCC2_t;
typedef union
{
    uint32_t    R;
    strRCC2_t   B;
} uniRCC2_t;

typedef struct
{
    uint32_t R0 :1;
    uint32_t R1 :1;
    uint32_t    :30;
} strRCGC2R_t;
typedef union
{
    uint32_t    R;
    strRCGC2R_t B;
} uniRCGC2R_t;

typedef struct
{
    uint32_t R0 :1;
    uint32_t R1 :1;
    uint32_t R2 :1;
    uint32_t R3 :1;
    uint32_t R4 :1;
    uint32_t R5 :1;
    uint32_t    :26;
} strRCGC6R_t;
typedef union
{
    uint32_t    R;
    strRCGC6R_t B;
} uniRCGC6R_t;

typedef struct
{
    uint32_t R0 :1;
    uint32_t    :31;
} strRCGC1R_t;
typedef union
{
    uint32_t    R;
    strRCGC1R_t B;
} uniRCGC1R_t;

typedef struct
{
    uint32_t R0 :1;
    uint32_t R1 :1;
    uint32_t R2 :1;
    uint32_t R3 :1;
    uint32_t R4 :1;
    uint32_t R5 :1;
    uint32_t R6 :1;
    uint32_t R7 :1;
    uint32_t    :24;
} strRCGC8R_t;
typedef union
{
    uint32_t    R;
    strRCGC8R_t B;
} uniRCGC8R_t;

typedef struct
{
    uint32_t R0 :1;
    uint32_t R1 :1;
    uint32_t R2 :1;
    uint32_t R3 :1;
    uint32_t    :28;
} strRCGC4R_t;
typedef union
{
    uint32_t    R;
    strRCGC4R_t B;
} uniRCGC4R_t;

/*** Micro Direct Memory Access (μDMA) ***/
/** μDMA Channel Control Structure (Offset from Channel Control Table Base **/
typedef struct
{
    uint32_t XFERMODE   :3;
    uint32_t NXTUSEBURST:1;
    uint32_t XFERSIZE   :10;
    uint32_t ARBSIZE    :4;
    uint32_t            :6;
    uint32_t SRCSIZE    :2;
    uint32_t SRCINC     :2;
    uint32_t DSTSIZE    :2;
    uint32_t DSTINC     :2;
} strDMACHCTL_t;
typedef union
{
    uint32_t        R;
    strDMACHCTL_t   B;
} uniDMACHCTL_t;

/** μDMA Registers (Offset from μDMA Base Address) **/
typedef struct
{
    uint32_t MASTEN     :1;
    uint32_t            :3;
    uint32_t STATE      :4;
    uint32_t            :8;
    uint32_t DMACHANS   :5;
    uint32_t            :11;
} strDMASTAT_t;
typedef union
{
    uint32_t        R;
    strDMASTAT_t    B;
} uniDMASTAT_t;

typedef struct
{
    uint32_t MASTEN     :1;
    uint32_t            :31;
} strDMACFG_t;
typedef union
{
    uint32_t        R;
    strDMACFG_t     B;
} uniDMACFG_t;

typedef struct
{
    uint32_t        :10;
    uint32_t ADDR   :22;
} strDMACTLBASE_t;
typedef union
{
    uint32_t        R;
    strDMACTLBASE_t B;
} uniDMACTLBASE_t;

typedef struct
{
    uint32_t ERRCLR :1;
    uint32_t        :31;
} strDMAERRCLR_t;
typedef union
{
    uint32_t        R;
    strDMAERRCLR_t  B;
} uniDMAERRCLR_t;

typedef struct
{
    uint32_t CH0SEL:4;
    uint32_t CH1SEL:4;
    uint32_t CH2SEL:4;
    uint32_t CH3SEL:4;
    uint32_t CH4SEL:4;
    uint32_t CH5SEL:4;
    uint32_t CH6SEL:4;
    uint32_t CH7SEL:4;
} strDMACHMAP0_t;
typedef union
{
    uint32_t        R;
    strDMACHMAP0_t  B;
} uniDMACHMAP0_t;

typedef struct
{
    uint32_t CH8SEL :4;
    uint32_t CH9SEL :4;
    uint32_t CH10SEL:4;
    uint32_t CH11SEL:4;
    uint32_t CH12SEL:4;
    uint32_t CH13SEL:4;
    uint32_t CH14SEL:4;
    uint32_t CH15SEL:4;
} strDMACHMAP1_t;
typedef union
{
    uint32_t        R;
    strDMACHMAP1_t  B;
} uniDMACHMAP1_t;

typedef struct
{
    uint32_t CH16SEL:4;
    uint32_t CH17SEL:4;
    uint32_t CH18SEL:4;
    uint32_t CH19SEL:4;
    uint32_t CH20SEL:4;
    uint32_t CH21SEL:4;
    uint32_t CH22SEL:4;
    uint32_t CH23SEL:4;
} strDMACHMAP2_t;
typedef union
{
    uint32_t        R;
    strDMACHMAP2_t  B;
} uniDMACHMAP2_t;

typedef struct
{
    uint32_t CH24SEL:4;
    uint32_t CH25SEL:4;
    uint32_t CH26SEL:4;
    uint32_t CH27SEL:4;
    uint32_t CH28SEL:4;
    uint32_t CH29SEL:4;
    uint32_t CH30SEL:4;
    uint32_t CH31SEL:4;
} strDMACHMAP3_t;
typedef union
{
    uint32_t        R;
    strDMACHMAP3_t  B;
} uniDMACHMAP3_t;

/*** General-Purpose Input/Outputs (GPIOs) ***/
typedef struct
{
    uint32_t P0 :1;
    uint32_t P1 :1;
    uint32_t P2 :1;
    uint32_t P3 :1;
    uint32_t P4 :1;
    uint32_t P5 :1;
    uint32_t P6 :1;
    uint32_t P7 :1;
    uint32_t    :24;
} strGPIO8P_t;
typedef union
{
    uint32_t    R;
    strGPIO8P_t B;
} uniGPIO8P_t;

typedef struct
{
    uint32_t GPIOAMSEL  :4;
    uint32_t            :28;
} strGPIOAMSEL_t;
typedef union
{
    uint32_t        R;
    strGPIOAMSEL_t  B;
} uniGPIOAMSEL_t;

typedef struct
{
    uint32_t PMC0:4;
    uint32_t PMC1:4;
    uint32_t PMC2:4;
    uint32_t PMC3:4;
    uint32_t PMC4:4;
    uint32_t PMC5:4;
    uint32_t PMC6:4;
    uint32_t PMC7:4;
} strGPIOPCTL_t;
typedef union
{
    uint32_t        R;
    strGPIOPCTL_t   B;
} uniGPIOPCTL_t;
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*** Cortex-M4 Peripherals ***/
#define CORTEX_M4_PERIPHERALS_BASE_ADDRESS      0xE000E000
/** System Timer (SysTick) Registers **/
#define STCTRL                                  (*((volatile uniSTCTRL_t*)      (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0x010)))
#define STRELOAD                                (*((volatile uniSTRELOAD_t*)    (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0x014)))
#define STCURRENT                               (*((volatile uniSTCURRENT_t*)   (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0x018)))
/** Nested Vectored Interrupt Controller (NVIC) Registers **/
#define EN_BASE_ADDRESS                         0x100
#define EN(REG_NO)                              (*((volatile uniNVIC_t*)        (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + EN_BASE_ADDRESS + (REG_NO * 4))))
#define DIS_BASE_ADDRESS                        0x180
#define DIS(REG_NO)                             (*((volatile uniNVIC_t*)        (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + DIS_BASE_ADDRESS + (REG_NO * 4))))
#define PEND_BASE_ADDRESS                       0x200
#define PEND(REG_NO)                            (*((volatile uniNVIC_t*)        (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + PEND_BASE_ADDRESS + (REG_NO * 4))))
#define UNPEND_BASE_ADDRESS                     0x280
#define UNPEND(REG_NO)                          (*((volatile uniNVIC_t*)        (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + UNPEND_BASE_ADDRESS + (REG_NO * 4))))
#define ACTIVE_BASE_ADDRESS                     0x300
#define ACTIVE(REG_NO)                          (*((volatile uniNVIC_t*)        (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + ACTIVE_BASE_ADDRESS + (REG_NO * 4))))
#define PRI_BASE_ADDRESS                        0x400
#define PRI(REG_NO)                             (*((volatile uniPRI_t*)         (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + PRI_BASE_ADDRESS + (REG_NO * 4))))
#define SWTRIG                                  (*((volatile uniSWTRIG_t*)      (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xF00)))
/** System Control Block (SCB) Registers **/
#define ACTLR                                   (*((volatile uniACTLR_t*)       (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0x008)))
#define CPUID                                   (*((volatile uniCPUID_t*)       (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD00)))
#define INTCTRL                                 (*((volatile uniINTCTRL_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD04)))
#define VTABLE                                  (*((volatile uniVTABLE_t*)      (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD08)))
#define APINT                                   (*((volatile uniAPINT_t*)       (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD0C)))
#define SYSCTRL                                 (*((volatile uniSYSCTRL_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD10)))
#define CFGCTRL                                 (*((volatile uniCFGCTRL_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD14)))
#define SYSPRI1                                 (*((volatile uniSYSPRI1_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD18)))
#define SYSPRI2                                 (*((volatile uniSYSPRI2_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD1C)))
#define SYSPRI3                                 (*((volatile uniSYSPRI3_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD20)))
#define SYSHNDCTRL                              (*((volatile uniSYSHNDCTRL_t*)  (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD24)))
#define FAULTSTAT                               (*((volatile uniFAULTSTAT_t*)   (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD28)))
#define HFAULTSTAT                              (*((volatile uniHFAULTSTAT_t*)  (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD2C)))
#define MMADDR                                  (*((volatile uniADDR_t*)        (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD34)))
#define FAULTADDR                               (*((volatile uniADDR_t*)        (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD38)))
/** Memory Protection Unit (MPU) Registers **/
#define MPUTYPE                                 (*((volatile uniMPUTYPE_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD90)))
#define MPUCTRL                                 (*((volatile uniMPUCTRL_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD94)))
#define MPUNUMBER                               (*((volatile uniMPUNUMBER_t*)   (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD98)))
#define MPUBASE                                 (*((volatile uniMPUBASE_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD9C)))
#define MPUATTR                                 (*((volatile uniMPUATTR_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xDA0)))
#define MPUBASE1                                (*((volatile uniMPUBASE_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xDA4)))
#define MPUATTR1                                (*((volatile uniMPUATTR_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xDA8)))
#define MPUBASE2                                (*((volatile uniMPUBASE_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xDAC)))
#define MPUATTR2                                (*((volatile uniMPUATTR_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xDB0)))
#define MPUBASE3                                (*((volatile uniMPUBASE_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xDB4)))
#define MPUATTR3                                (*((volatile uniMPUATTR_t*)     (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xDB8)))
/** Floating-Point Unit (FPU) Registers **/
#define CPAC                                    (*((volatile uniCPAC_t*)        (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xD88)))
#define FPCC                                    (*((volatile uniFPCC_t*)        (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xF34)))
#define FPCA                                    (*((volatile uniFPCA_t*)        (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xF38)))
#define FPDSC                                   (*((volatile uniFPDSC_t*)       (CORTEX_M4_PERIPHERALS_BASE_ADDRESS + 0xF3C)))

/*** System Control ***/
#define SYSTEM_CONTROL_BASE_ADDRESS             0x400FE000
/** System Control Registers **/
#define RESC                                    (*((volatile uniRESC_t*)    (SYSTEM_CONTROL_BASE_ADDRESS + 0x05C)))
#define PLLSTAT                                 (*((volatile uniPLLSTAT_t*) (SYSTEM_CONTROL_BASE_ADDRESS + 0x168)))

#define RCC                                     (*((volatile uniRCC_t*)     (SYSTEM_CONTROL_BASE_ADDRESS + 0x060)))
#define RCC2                                    (*((volatile uniRCC2_t*)    (SYSTEM_CONTROL_BASE_ADDRESS + 0x070)))
#define RCGCWD                                  (*((volatile uniRCGC2R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x600)))
#define RCGCTIMER                               (*((volatile uniRCGC6R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x604)))
#define RCGCGPIO                                (*((volatile uniRCGC6R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x608)))
#define RCGCDMA                                 (*((volatile uniRCGC1R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x60C)))
#define RCGCHIB                                 (*((volatile uniRCGC1R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x614)))
#define RCGCUART                                (*((volatile uniRCGC8R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x618)))
#define RCGCSSI                                 (*((volatile uniRCGC4R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x61C)))
#define RCGCI2C                                 (*((volatile uniRCGC4R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x620)))
#define RCGCUSB                                 (*((volatile uniRCGC1R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x628)))
#define RCGCCAN                                 (*((volatile uniRCGC2R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x634)))
#define RCGCADC                                 (*((volatile uniRCGC2R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x638)))
#define RCGCACCMP                               (*((volatile uniRCGC1R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x63C)))
#define RCGCPWM                                 (*((volatile uniRCGC2R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x640)))
#define RCGCQEI                                 (*((volatile uniRCGC2R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x644)))
#define RCGCEEPROM                              (*((volatile uniRCGC1R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x658)))
#define RCGCWTIMER                              (*((volatile uniRCGC6R_t*)  (SYSTEM_CONTROL_BASE_ADDRESS + 0x65C)))

/*** Micro Direct Memory Access (μDMA) ***/
/** μDMA Channel Control Structure (Offset from Channel Control Table Base **/
#define DMASRCENDP_OFFSET                       0x000
#define DMASRCENDP(CHANNEL_ID, MASK)            (*((volatile uint32_t*)     (DMASRCENDP_OFFSET + &ControlTable[(16 * CHANNEL_ID) + MASK]))
#define DMADSTENDP_OFFSET                       0x004
#define DMADSTENDP(CHANNEL_ID, MASK)            (*((volatile uint32_t*)     (DMADSTENDP_OFFSET + &ControlTable[(16 * CHANNEL_ID) + MASK]))
#define DMACHCTL_OFFSET                         0x008
#define DMACHCTL(CHANNEL_ID, MASK)              (*((volatile uniDMACHCTL_t*)(DMACHCTL_OFFSET + &ControlTable[(16 * CHANNEL_ID) + MASK]))
/** μDMA Registers (Offset from μDMA Base Address) **/
#define DMA_BASE_ADDRESS                        0x400FF000
#define DMASTAT                                 (*((volatile uniDMASTAT_t*)     (DMA_BASE_ADDRESS + 0x000)))
#define DMACFG                                  (*((volatile uniDMACFG_t*)      (DMA_BASE_ADDRESS + 0x004)))
#define DMACTLBASE                              (*((volatile uniDMACTLBASE_t*)  (DMA_BASE_ADDRESS + 0x008)))
#define DMAALTBASE                              (*((volatile uint32_t*)         (DMA_BASE_ADDRESS + 0x00C)))
#define DMAWAITSTAT                             (*((volatile uint32_t*)         (DMA_BASE_ADDRESS + 0x010)))
#define DMASWREQ                                (*((volatile uint32_t*)         (DMA_BASE_ADDRESS + 0x014)))
#define DMAUSEBURSTSET                          (*((volatile uint32_t*)         (DMA_BASE_ADDRESS + 0x018)))
#define DMAUSEBURSTCLR                          (*((volatile uint32_t*)         (DMA_BASE_ADDRESS + 0x01C)))
#define DMAREQMASKSET                           (*((volatile uint32_t*)         (DMA_BASE_ADDRESS + 0x020)))
#define DMAREQMASKCLR                           (*((volatile uint32_t*)         (DMA_BASE_ADDRESS + 0x024)))
#define DMAENASET                               (*((volatile uint32_t*)         (DMA_BASE_ADDRESS + 0x028)))
#define DMAENACLR                               (*((volatile uint32_t*)         (DMA_BASE_ADDRESS + 0x02C)))
#define DMAALTSET                               (*((volatile uint32_t*)         (DMA_BASE_ADDRESS + 0x030)))
#define DMAALTCLR                               (*((volatile uint32_t*)         (DMA_BASE_ADDRESS + 0x034)))
#define DMAPRIOSET                              (*((volatile uint32_t*)         (DMA_BASE_ADDRESS + 0x038)))
#define DMAPRIOCLR                              (*((volatile uint32_t*)         (DMA_BASE_ADDRESS + 0x03C)))
#define DMAERRCLR                               (*((volatile uniDMAERRCLR_t*)   (DMA_BASE_ADDRESS + 0x04C)))
#define DMACHASGN                               (*((volatile uint32_t*)         (DMA_BASE_ADDRESS + 0x500)))
#define DMACHIS                                 (*((volatile uint32_t*)         (DMA_BASE_ADDRESS + 0x504)))
#define DMACHMAP0                               (*((volatile uniDMACHMAP0_t*)   (DMA_BASE_ADDRESS + 0x510)))
#define DMACHMAP1                               (*((volatile uniDMACHMAP1_t*)   (DMA_BASE_ADDRESS + 0x514)))
#define DMACHMAP2                               (*((volatile uniDMACHMAP2_t*)   (DMA_BASE_ADDRESS + 0x518)))
#define DMACHMAP3                               (*((volatile uniDMACHMAP3_t*)   (DMA_BASE_ADDRESS + 0x51C)))

/*** General-Purpose Input/Outputs (GPIOs) ***/
#define GPIO_PORTS_NO                           6
#define GPIO_PORT_A_BASE_ADDRESS                0x40004000
#define GPIO_PORT_B_BASE_ADDRESS                0x40005000
#define GPIO_PORT_C_BASE_ADDRESS                0x40006000
#define GPIO_PORT_D_BASE_ADDRESS                0x40007000
#define GPIO_PORT_E_BASE_ADDRESS                0x40024000
#define GPIO_PORT_F_BASE_ADDRESS                0x40025000
#define GPIO_REG_ADDRESS(PORT_NO, REG_OFFSET)   (gau32PortsBaseAddressLookupTable[PORT_NO] + REG_OFFSET)
#define GPIODATA(PORT_NO, MASK)                 (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x000) + (MASK << 2))))

#define GPIODIR(PORT_NO)                        (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x400))))
#define GPIOIS(PORT_NO)                         (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x404))))
#define GPIOIBE(PORT_NO)                        (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x408))))
#define GPIOIEV(PORT_NO)                        (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x40C))))
#define GPIOIM(PORT_NO)                         (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x410))))
#define GPIORIS(PORT_NO)                        (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x414))))
#define GPIOMIS(PORT_NO)                        (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x418))))
#define GPIOICR(PORT_NO)                        (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x41C))))
#define GPIOAFSEL(PORT_NO)                      (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x420))))
#define GPIODR2R(PORT_NO)                       (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x500))))
#define GPIODR4R(PORT_NO)                       (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x504))))
#define GPIODR8R(PORT_NO)                       (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x508))))
#define GPIOODR(PORT_NO)                        (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x50C))))
#define GPIOPUR(PORT_NO)                        (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x510))))
#define GPIOPDR(PORT_NO)                        (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x514))))
#define GPIOSLR(PORT_NO)                        (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x518))))
#define GPIODEN(PORT_NO)                        (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x51C))))
#define GPIOLOCK(PORT_NO)                       (*((volatile uint32_t*)         (GPIO_REG_ADDRESS(PORT_NO, 0x520))))
#define GPIOCR(PORT_NO)                         (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x524))))
#define GPIOAMSEL(PORT_NO)                      (*((volatile uniGPIOAMSEL_t*)   (GPIO_REG_ADDRESS(PORT_NO, 0x528))))
#define GPIOPCTL(PORT_NO)                       (*((volatile uniGPIOPCTL_t*)    (GPIO_REG_ADDRESS(PORT_NO, 0x52C))))
#define GPIOADCCTL(PORT_NO)                     (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x530))))
#define GPIODMACTL(PORT_NO)                     (*((volatile uniGPIO8P_t*)      (GPIO_REG_ADDRESS(PORT_NO, 0x534))))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/*** Micro Direct Memory Access (μDMA) ***/
/** μDMA Channel Control Structure (Offset from Channel Control Table Base **/
/* DMA Control Table Base Address in Data Memory */
#pragma DATA_ALIGN(ControlTable, 1024)
static uint8_t ControlTable[1024];

/*** General-Purpose Input/Outputs (GPIOs) ***/
static const uint32_t gau32PortsBaseAddressLookupTable[GPIO_PORTS_NO] =
{
    GPIO_PORT_A_BASE_ADDRESS,
    GPIO_PORT_B_BASE_ADDRESS,
    GPIO_PORT_C_BASE_ADDRESS,
    GPIO_PORT_D_BASE_ADDRESS,
    GPIO_PORT_E_BASE_ADDRESS,
    GPIO_PORT_F_BASE_ADDRESS
};

#endif /* TM4C123GH6PM_HW_H_ */

/**********************************************************************************************************************
 *  END OF FILE: TM4C123GH6PM_HW.h
 *********************************************************************************************************************/
