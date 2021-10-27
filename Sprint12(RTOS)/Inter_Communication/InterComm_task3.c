
#include "InterComm_task3.h"

/* Tasks Handlers */
TaskHandle_t BTN1Task_Handler = NULL;
TaskHandle_t BTN2Task_Handler = NULL;
TaskHandle_t CTask_Handler = NULL;
TaskHandle_t SSTask_Handler = NULL;

/* Global Variables */ 




/* create a Queue */
QueueHandle_t xUARTQueue;

void COM_Task3create(void)
{
	xUARTQueue = xQueueCreate( 10, 20 * sizeof( unsigned char ) ); // 10 locations, string of 20 chars
	xTaskCreate(BTN1_task, BTN1TASK_NAME, BTN1TASK_STACK_SIZE, NULL, BTN1TASK_PRIORITY, &BTN1Task_Handler );
	xTaskCreate(BTN2_task, BTN2TASK_NAME, BTN2TASK_STACK_SIZE, NULL, BTN2TASK_PRIORITY, &BTN2Task_Handler );
	xTaskCreate(Consumer_task, CTASK_NAME, CTASK_STACK_SIZE, NULL, CTASK_PRIORITY, &CTask_Handler );
	xTaskCreate(SendString_task, SSTASK_NAME, SSTASK_STACK_SIZE, NULL, SSTASK_PRIORITY, &SSTask_Handler );
}

void BTN1_task( void * pvParameters )
{
		pinState_t BTN1OldState = PIN_IS_LOW;
		pinState_t BTN1NewState;
    for( ;; )
    {
				BTN1NewState = GPIO_read(BTN1_PORT, BTN1_PIN);
			  /* Case Rising Edge */
				if(BTN1OldState == PIN_IS_LOW && BTN1NewState == PIN_IS_HIGH)
				{
						xQueueSend( xUARTQueue, ( unsigned char * )"RE on BTN1" , portMAX_DELAY );
				}
				/* Case Falling Edge */
				else if(BTN1OldState == PIN_IS_HIGH && BTN1NewState == PIN_IS_LOW)
				{
						xQueueSend( xUARTQueue, ( unsigned char * )"FE on BTN1" , portMAX_DELAY );
				}
				BTN1OldState = BTN1NewState;
				vTaskDelay(100);
    }
}

void BTN2_task( void * pvParameters )
{
	  pinState_t BTN2OldState = PIN_IS_LOW;
    pinState_t BTN2NewState;
    for( ;; )
    {
				BTN2NewState = GPIO_read(BTN2_PORT, BTN2_PIN);
			  /* Case Rising Edge */
				if(BTN2OldState == PIN_IS_LOW && BTN2NewState == PIN_IS_HIGH)
				{
						xQueueSend( xUARTQueue, ( unsigned char * )"RE on BTN2" , portMAX_DELAY );
				}
				/* Case Falling Edge */
				else if(BTN2OldState == PIN_IS_HIGH && BTN2NewState == PIN_IS_LOW)
				{
						xQueueSend( xUARTQueue, ( unsigned char * )"FE on BTN2" , portMAX_DELAY );
				}
				BTN2OldState = BTN2NewState;
				vTaskDelay(100);
		}
}

void Consumer_task( void * pvParameters )
{
		uint8_t UART_str[10];
    for( ;; )
    {
				xQueueReceive(xUARTQueue, UART_str, portMAX_DELAY);
			  vSerialPutString(UART_str, 10);
				vTaskDelay(100);
				xSerialPutChar('\n');
		}
}

void SendString_task( void * pvParameters )
{
    for( ;; )
    {
				xQueueSend( xUARTQueue, ( unsigned char * )"SendString_task" , portMAX_DELAY );
				vTaskDelay(100);
		}
}