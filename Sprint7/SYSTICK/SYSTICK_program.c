/*
 * SYSTICK_program.c
 *
 *  Created on: Mar 21, 2021
 *      Author: Kariman
 */
#include "STD_TYPES.h"
#include "BIT_MANIPULATE.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

/*	Define CallBack Global Variable			*/
static void (*SYSTICK_PfCallBack)(void) = NULLPTR;

/*	Define Interval Mode Global Variable	*/
static uint8_t SYSTICK_u8IntervalMode = SYSTICK_SINGLE_INTERVAL;

enuErrorStatus_t SYSTICK_Init(void)
{
	enuErrorStatus_t enuErrorStatus = E_ERROR;
#if		SYSTICK_CLK_SOURCE	== SYSTICK_AHB_8
		/*Systick disabled, Interrupt disabled, CLK = AHB/8*/
		SYSTICK -> CTRL = 0x00000000;
		enuErrorStatus = E_OK;

#elif	SYSTICK_CLK_SOURCE	== SYSTICK_AHB
		SYSTICK -> CTRL = 0x00000004;
		enuErrorStatus = E_OK;

#else
		#error("Wrong Systick Initialization");
		enuErrorStatus = E_ERROR;
#endif

	return enuErrorStatus;
}//end SYSTICK_voidInit

//delay with micro sec
enuErrorStatus_t SYSTICK_SetBusyWait(uint32_t Copy_u32Ticks)
{
	enuErrorStatus_t enuErrorStatus = E_ERROR;
	/*	1-Load Ticks to Load Register	*/
	SYSTICK -> LOAD = Copy_u32Ticks;
	/*	2-Start Timer					*/
	SET_BIT(SYSTICK -> CTRL, 0);
	/*	3-Wait till Flag raised			*/
	while((GET_BIT(SYSTICK -> CTRL, 16)) == 0)
	{
		//for dibugger
		asm("NOP");
	}
	/*	4-Stop Timer					*/
	CLEAR_BIT(SYSTICK -> CTRL, 0);
	SYSTICK -> LOAD = 0;
	SYSTICK -> VAL = 0;
	enuErrorStatus = E_OK;
	
	return enuErrorStatus;
}//end SYSTICK_voidSetBusyWait

enuErrorStatus_t SYSTICK_SetIntervalSingle(uint32_t Copy_u32Ticks, void(*Copy_Pf)(void))
{
	enuErrorStatus_t enuErrorStatus = E_ERROR;

	/*	1-Stop Timer					*/
	CLEAR_BIT(SYSTICK -> CTRL, 0);
	SYSTICK -> VAL = 0;
	/*	2-Load Ticks to Load Register	*/
	SYSTICK -> LOAD = Copy_u32Ticks;
	/*	3-Start Timer					*/
	SET_BIT(SYSTICK -> CTRL, 0);
	/*	4-Set CllBack					*/
	if(Copy_Pf != NULLPTR)
	{
		SYSTICK_PfCallBack = Copy_Pf;
		enuErrorStatus = E_OK;
	}//end if
	/*	5-Set Interval Mode for Single Interval	*/
	SYSTICK_u8IntervalMode = SYSTICK_SINGLE_INTERVAL;
	/*	6-Enable Systick Interrupt		*/
	SET_BIT(SYSTICK -> CTRL, 1);
	
	return enuErrorStatus;
}//end SYSTICK_voidSetIntervalSingle

enuErrorStatus_t SYSTICK_SetIntervalPeriodick(uint32_t Copy_u32Ticks, void(*Copy_Pf)(void))
{
	enuErrorStatus_t enuErrorStatus = E_ERROR;
	
	/*	1-Load Ticks to Load Register	*/
	SYSTICK -> LOAD = Copy_u32Ticks;
	/*	2-Start Timer					*/
	SET_BIT(SYSTICK -> CTRL, 0);
	/*	3-Set CllBack					*/
	if(Copy_Pf != NULLPTR)
	{
		SYSTICK_PfCallBack = Copy_Pf;
		enuErrorStatus = E_OK;
	}//end if
	/*	4-Set Interval Mode for Periodic Interval		*/
	SYSTICK_u8IntervalMode = SYSTICK_PERIODIC_INTERVAL;
	/*	5-Enable Systick Interrupt		*/
	SET_BIT(SYSTICK -> CTRL, 1);
	
	return enuErrorStatus;
}//end SYSTICK_voidSetIntervalPeriodick

enuErrorStatus_t SYSTICK_StopInterval(uint32_t Copy_u32Ticks)
{
	enuErrorStatus_t enuErrorStatus = E_ERROR;
	/*	1-Disable Systick Interrupt		*/
	CLEAR_BIT(SYSTICK -> CTRL, 1);
	/*	2-Stop Timer					*/
	CLEAR_BIT(SYSTICK -> CTRL, 0);
	SYSTICK -> LOAD = 0;
	SYSTICK -> VAL = 0;
	enuErrorStatus = E_OK;
	
	return enuErrorStatus;
}//end SYSTICK_voidStopInterval

enuErrorStatus_t SYSTICK_GetElapsedTime(uint32_t* Local_u32ElapsedTime)
{
	enuErrorStatus_t enuErrorStatus = E_ERROR;
	*Local_u32ElapsedTime = SYSTICK -> LOAD - SYSTICK -> VAL;
	enuErrorStatus = E_OK;
	
	return enuErrorStatus;
}//end SYSTICK_u32GetElapsedTime

enuErrorStatus_t SYSTICK_GetRemainingTime(uint32_t* Local_u32RemainingTime)
{
	enuErrorStatus_t enuErrorStatus = E_ERROR;
	*Local_u32RemainingTime = SYSTICK -> VAL;
	enuErrorStatus = E_OK;
	
	return enuErrorStatus;
}//end SYSTICK_u32GetRemainingTime

//Core Peripheral -> _Handler
//anything else -> _IRQHandler
void Systick_Handler(void)
{
	uint8_t Local_u8Temp;
	/*	Check if Single Interval			*/
	if(SYSTICK_u8IntervalMode == SYSTICK_SINGLE_INTERVAL)
	{
		/*	1-Disable Systick Interrupt		*/
		CLEAR_BIT(SYSTICK -> CTRL, 1);
		/*	2-Stop Timer					*/
		CLEAR_BIT(SYSTICK -> CTRL, 0);
		SYSTICK -> LOAD = 0;
		SYSTICK -> VAL = 0;
	}//end if
	/*	CallBack Notification				*/
	SYSTICK_PfCallBack();
	/*	Clear Interrupt flag by reading it	*/
	Local_u8Temp = GET_BIT(SYSTICK -> CTRL, 16);
}//end ISR
