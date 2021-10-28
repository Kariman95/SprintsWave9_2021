
#include "Intro_task2.h"


/*************************************** Task 2 *************************************/
TaskHandle_t ToggleLED1TaskHandler = NULL;
TaskHandle_t ToggleLED2TaskHandler = NULL;
TaskHandle_t ToggleLED3TaskHandler = NULL;

void ToggleTask2_create(void)
{
	xTaskCreate(ToggleLED1Task, LED1_TASK_NAME, LED1_TASK_STACK_SIZE, NULL, LED1_TASK_PRIORITY, &ToggleLED1TaskHandler );
	xTaskCreate(ToggleLED2Task, LED2_TASK_NAME, LED2_TASK_STACK_SIZE, NULL, LED2_TASK_PRIORITY, &ToggleLED2TaskHandler );
	xTaskCreate(ToggleLED3Task, LED3_TASK_NAME, LED3_TASK_STACK_SIZE, NULL, LED3_TASK_PRIORITY, &ToggleLED3TaskHandler );
}

/* Task to be created. */
void ToggleLED1Task( void * pvParameters )
{
    for( ;; )
    {
        /* Task code goes here. */
			GPIO_write(LED1_PORT, LED1_PIN, PIN_IS_HIGH);
			
			vTaskDelay(1000);
			
			GPIO_write(LED1_PORT, LED1_PIN, PIN_IS_LOW);
			
			vTaskDelay(1000);
    }
}

/* Task to be created. */
void ToggleLED2Task( void * pvParameters )
{
    for( ;; )
    {
        /* Task code goes here. */
			GPIO_write(LED2_PORT, LED2_PIN, PIN_IS_HIGH);
			
			vTaskDelay(100);
			
			GPIO_write(LED2_PORT, LED2_PIN, PIN_IS_LOW);
			
			vTaskDelay(100);
    }
}

/* Task to be created. */
void ToggleLED3Task( void * pvParameters )
{
    for( ;; )
    {
        /* Task code goes here. */
			GPIO_write(LED3_PORT, LED3_PIN, PIN_IS_HIGH);
			
			vTaskDelay(500);
			
			GPIO_write(LED3_PORT, LED3_PIN, PIN_IS_LOW);
			
			vTaskDelay(500);
    }
}