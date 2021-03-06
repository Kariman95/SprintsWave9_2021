/*
 * BTN.h
 *
 *  Created on: Jul 9, 2021
 *  Author: Kariman
 */

#ifndef ECUAL_BTN_H_
#define ECUAL_BTN_H_

/*- INCLUDES -----------------------------------------------*/
#include "../../LIB/BIT_math.h"
#include "../../LIB/BIT_math.h"
#include "../../MCAL/DIO/DIO_cfg.h"
#include "../../MCAL/DIO/DIO_init.h"

/*- ENUMS --------------------------------------------------*/
typedef enum { PRESSED, NOT_PRESSED }enuBTNStatus;

/*- FUNCTION DECLARATIONS ----------------------------------*/

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the button
*************************************************************************************************/
enuErrorStatus_t	BTN_Init(void);

/*************************************************************************************************
* Parameters (in) : u8_BtnNum(index to the button pin)
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to read the button status (pressed, not_pressed)
*************************************************************************************************/
enuErrorStatus_t	BTN_getState(uint8_t u8BtnNum, uint8_t* u8_Status);

#endif /* ECUAL_BTN_H_ */
