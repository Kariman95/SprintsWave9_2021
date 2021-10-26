
#include "InterComm_task2.h"


TaskHandle_t Task100Handler = NULL;
TaskHandle_t Task500Handler = NULL;

/* create a semaphore */
SemaphoreHandle_t xMutex;

void COM_UARTTask2create(void)
{
	xMutex = xSemaphoreCreateMutex();
	xTaskCreate(COM_UARTTask100, TASK100_NAME, TASK100_STACK_SIZE, NULL, TASK100_PRIORITY, &Task100Handler );
	xTaskCreate(COM_UARTTask500, TASK500_NAME, TASK500_STACK_SIZE, NULL, TASK500_PRIORITY, &Task500Handler );
}

void COM_UARTTask100( void * pvParameters )
{
	uint8_t u8Indx = 0;
    for( ;; )
    {
			if( xSemaphoreTake( xMutex, ( TickType_t ) 10 ) == pdTRUE )
			{
				for(u8Indx=0; u8Indx<10; u8Indx++)
				{
						vSerialPutString("RTOS", 5);
				}
				xSemaphoreGive( xMutex );
			}
			vTaskDelay(100);
    }
}


void COM_UARTTask500( void * pvParameters )
{
		uint8_t u8Indx1 = 0;
		uint32_t u32Indx2 = 0;
    for( ;; )
    {
			if( xSemaphoreTake( xMutex, ( TickType_t ) 10 ) == pdTRUE )
			{
				for(u8Indx1=0; u8Indx1<10; u8Indx1++)
				{
						vSerialPutString("Hello", 6);
						for(u32Indx2=0; u32Indx2<100000; u32Indx2++);
				}
				xSemaphoreGive( xMutex );
			}
			vTaskDelay(500);
		}
}
