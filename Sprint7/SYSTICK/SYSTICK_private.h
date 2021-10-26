/*
 * SYSTICK_private.h
 *
 *  Created on: Mar 21, 2021
 *      Author: Kariman
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

typedef struct
{
	volatile uint32_t	CTRL;
	volatile uint32_t	LOAD;
	volatile uint32_t	VAL;
//	volatile uint32_t	CTRL;

}SYSTICK_Type;

#define 	SYSTICK						((SYSTICK_Type*)0xE000E010)

#define 	SYSTICK_AHB_8				0
#define 	SYSTICK_AHB					1

#define 	SYSTICK_SINGLE_INTERVAL		5
#define 	SYSTICK_PERIODIC_INTERVAL	7

#endif /* SYSTICK_PRIVATE_H_ */
