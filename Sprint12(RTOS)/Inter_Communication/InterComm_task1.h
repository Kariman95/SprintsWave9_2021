

#ifndef _INTERCOMM_TASK1_H
#define _INTERCOMM_TASK1_H

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"
#include "semphr.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"


#define COM_LED_PORT		       					PORT_0
#define COM_LED_PIN		       						PIN7
#define COM_LED_TASK_PRIORITY 					1
#define COM_LED_TASK_STACK_SIZE         100
#define COM_LED_TASK_NAME				       "Toggle LED Task"

#define BTN_PORT		          					PORT_0
#define BTN_PIN		          						PIN6
#define BTN_TASK_PRIORITY    						1
#define BTN_TASK_STACK_SIZE  						100
#define BTN_TASK_NAME										"Button Task"



void COM_Task1create(void);
void COM_ToggleTask( void * pvParameters );
void COM_ButtonTask( void * pvParameters );
			
#endif //_INTERCOMM_TASK1_H
