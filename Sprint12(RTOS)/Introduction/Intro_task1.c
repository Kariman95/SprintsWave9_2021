
#include "Intro_task1.h"


/*************************************** Task 1 *************************************/
 TaskHandle_t ToggleHandler;

void ToggleLEDTask_create(void)
{
		xTaskCreate(ToggleLEDTask, LED_TASK_NAME, LED_TASK_STACK_SIZE, NULL, LED_TASK_PRIORITY, &ToggleHandler );
}


void ToggleLEDTask( void * pvParameters )
{
    for( ;; )
    {
			GPIO_write(LED_PORT, LED_PIN, PIN_IS_HIGH);
				
			vTaskDelay(1000);
				
			GPIO_write(LED_PORT, LED_PIN, PIN_IS_LOW);
				
			vTaskDelay(1000);
    }
}