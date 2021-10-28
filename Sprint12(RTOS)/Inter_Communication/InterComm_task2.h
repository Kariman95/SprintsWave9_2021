

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


#define TASK100_PRIORITY 								2
#define TASK100_STACK_SIZE         			100
#define TASK100_NAME				       			"UART Task100"

#define TASK500_PRIORITY    						1
#define TASK500_STACK_SIZE  						100
#define TASK500_NAME										"UART Task500"



void COM_UARTTask2create(void);
void COM_UARTTask100( void * pvParameters );
void COM_UARTTask500( void * pvParameters );
			
#endif //_INTERCOMM_TASK2_H
