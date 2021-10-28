
#if 1
#ifndef _INTRO_TASK3_H
#define _INTRO_TASK3_H

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


#define LED_TASK_PORT		       PORT_0
#define LED_TASK_PIN		       PIN5
#define LED_TASK_TASK_PRIORITY     1
#define LED_STACK_SIZE             100
#define LED_NAME				   "Toggle LED Task"

#define BUTTON_PORT		          PORT_0
#define BUTTON_PIN		          PIN4
#define BUTTON_TASK_PRIORITY      1
#define BUTTON_TASK_STACK_SIZE    100
#define BUTTON_TASK_NAME		  "Button Task"



void Task3_create(void);
void ToggleTask( void * pvParameters );
void ButtonTask( void * pvParameters );
			
#endif //_INTRO_TASK3_H
#endif