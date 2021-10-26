#ifndef MCU_HW_H
#define MCU_HW_H


/* Memory Mapped Registers */
#define APINT_VECTKEY						   0x05FA
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32_t* const)(CORTEXM4_PERI_BASE_ADDRESS + 0xD0C))
#define INTCTRL                                *((volatile uint32_t* const)(CORTEXM4_PERI_BASE_ADDRESS + 0xD04))
#define EN0_R 								   *((volatile uint32_t* const)(CORTEXM4_PERI_BASE_ADDRESS + 0x100))
#define EN1_R 								   *((volatile uint32_t* const)(CORTEXM4_PERI_BASE_ADDRESS + 0x104))
#define EN2_R   							   *((volatile uint32_t* const)(CORTEXM4_PERI_BASE_ADDRESS + 0x108))
#define EN3_R 								   *((volatile uint32_t* const)(CORTEXM4_PERI_BASE_ADDRESS + 0x10C))
#define EN4_R 								   *((volatile uint32_t* const)(CORTEXM4_PERI_BASE_ADDRESS + 0x110))
#define SYSHNDCTRL_R 						   *((volatile uint32_t* const)(CORTEXM4_PERI_BASE_ADDRESS + 0xD24))

#define DIS0_R 								   *((volatile uint32_t* const)(CORTEXM4_PERI_BASE_ADDRESS + 0x180))
#define DIS1_R 								   *((volatile uint32_t* const)(CORTEXM4_PERI_BASE_ADDRESS + 0x184))
#define DIS2_R   							   *((volatile uint32_t* const)(CORTEXM4_PERI_BASE_ADDRESS + 0x188))
#define DIS3_R 								   *((volatile uint32_t* const)(CORTEXM4_PERI_BASE_ADDRESS + 0x18C))
#define DIS4_R 								   *((volatile uint32_t* const)(CORTEXM4_PERI_BASE_ADDRESS + 0x190))

#define IPRx                  					((volatile uint8_t* const)(CORTEXM4_PERI_BASE_ADDRESS + 0x400))



typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :3;
    uint32 VECPEND  :4;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}strINTCTRL_BF;

typedef union 
{
    uint32     R_INTCTRL;
    INTCTRL_BF B_INTCTRL;
}INTCTRL_Tag;

typedef struct
{
	uint32 VECTRESET :1;
	uint32 VECTCLRACT:1;
	uint32 SYSRESREQ :1;
	uint32 			 :5;
	uint32 PRIGROUP  :3;
	uint32           :4;
	uint32 ENDIANESS :1;
	uint32 VECTKEY	 :16;
}strAPINT_BF;

typedef union 
{
    uint32   R_APINT;
    APINT_BF B_APINT;
}APINT_Tag;


#endif  /* MCU_HW_H */