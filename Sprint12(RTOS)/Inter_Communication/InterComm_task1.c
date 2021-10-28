
#include "InterComm_task1.h"


TaskHandle_t COM_ButtonTaskHandler = NULL;
TaskHandle_t COM_ToggleTaskHandler = NULL;

/* create a semaphore */
SemaphoreHandle_t xSemaphore = NULL;

void COM_Task1create(void)
{
	xSemaphore = xSemaphoreCreateBinary();
	xTaskCreate(COM_ToggleTask, COM_LED_TASK_NAME, COM_LED_TASK_STACK_SIZE, NULL, COM_LED_TASK_PRIORITY, &COM_ToggleTaskHandler );
	xTaskCreate(COM_ButtonTask, BTN_TASK_NAME, BTN_TASK_STACK_SIZE, NULL, BTN_TASK_PRIORITY, &COM_ButtonTaskHandler );
}

void COM_ToggleTask( void * pvParameters )
{
		pinState_t LEDState = PIN_IS_LOW;
	
    for( ;; )
    {
				if( xSemaphoreTake( xSemaphore, ( TickType_t ) 10 ) == pdTRUE )
				{
						if(LEDState == PIN_IS_LOW)
						{
								LEDState = PIN_IS_HIGH;
						}
						else if(LEDState == PIN_IS_HIGH)
						{
								LEDState = PIN_IS_LOW;
						}
						GPIO_write(COM_LED_PORT, COM_LED_PIN, LEDState);
				}
				vTaskDelay(50);
    }
}


void COM_ButtonTask( void * pvParameters )
{
	pinState_t ButtonState;
	uint8_t u8Flag=0;
	
    for( ;; )
    {
			ButtonState = GPIO_read(BTN_PORT, BTN_PIN);
			if(ButtonState==PIN_IS_HIGH && u8Flag==0)
			{
				u8Flag = 1;
			}
			else if(ButtonState==PIN_IS_LOW && u8Flag==1)
			{
				u8Flag = 0;
				xSemaphoreGive( xSemaphore );
			}
			vTaskDelay(50);
		}

}
