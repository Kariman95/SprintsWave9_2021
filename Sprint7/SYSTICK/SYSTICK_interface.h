/*
 * SYSTICK_interface.h
 *
 *  Created on: Mar 21, 2021
 *      Author: Kariman
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

enuErrorStatus_t SYSTICK_Init(void);
enuErrorStatus_t SYSTICK_SetBusyWait(uint32_t Copy_u32Ticks);
enuErrorStatus_t SYSTICK_SetIntervalSingle(uint32_t Copy_u32Ticks, void(*Copy_Pf)(void));
enuErrorStatus_t SYSTICK_SetIntervalPeriodick(uint32_t Copy_u32Ticks, void(*Copy_Pf)(void));
enuErrorStatus_t SYSTICK_StopInterval(uint32_t Copy_u32Ticks);
enuErrorStatus_t SYSTICK_GetElapsedTime(uint32_t* u32Time);
enuErrorStatus_t SYSTICK_GetRemainingTime(uint32_t* u32Time);

#endif /* SYSTICK_INTERFACE_H_ */
