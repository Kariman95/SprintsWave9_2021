

#ifndef _INTRO_TASK1_H
#define _INTRO_TASK1_H

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"


#define LED_PORT		      PORT_0
#define LED_PIN		          PIN0
#define LED_TASK_PRIORITY     1
#define LED_TASK_STACK_SIZE   100
#define LED_TASK_NAME		  "Toggle LED Task"

void ToggleLEDTask_create(void);

void ToggleLEDTask( void * pvParameters );
			
#endif //_INTRO_TASK1_H
