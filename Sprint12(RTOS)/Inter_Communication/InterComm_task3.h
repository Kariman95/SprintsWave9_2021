

#ifndef _INTERCOMM_TASK2_H
#define _INTERCOMM_TASK2_H

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

#define BTN1_PORT												PORT_0
#define BTN1_PIN 												PIN4
#define BTN1TASK_PRIORITY 							4
#define BTN1TASK_STACK_SIZE         		100
#define BTN1TASK_NAME				       			"Detecting Rising Edge Task"

#define BTN2_PORT												PORT_0
#define BTN2_PIN 												PIN6
#define BTN2TASK_PRIORITY 							3
#define BTN2TASK_STACK_SIZE         		100
#define BTN2TASK_NAME				       			"Detecting Falling Edge Task"

#define CTASK_PRIORITY 								  1
#define CTASK_STACK_SIZE         			  100
#define CTASK_NAME				       			  "Consumer Task"

#define SSTASK_PRIORITY 								2
#define SSTASK_STACK_SIZE         			100
#define SSTASK_NAME				       			  "Send string Task"


void COM_Task3create(void);
void BTN1_task( void * pvParameters );
void BTN2_task( void * pvParameters );
void Consumer_task( void * pvParameters );
void SendString_task( void * pvParameters );
			
#endif //_INTERCOMM_TASK2_H
