/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "lpc21xx.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"


/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )


/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );
/*-----------------------------------------------------------*/

TaskHandle_t Task_Button_1 = NULL;
TaskHandle_t Task_Button_2 = NULL;
TaskHandle_t Task_Periodic_Trans = NULL;
TaskHandle_t Task_Uart_Rec = NULL;
TaskHandle_t Task_Load_1 = NULL;
TaskHandle_t Task_Load_2 = NULL;

char * runTimeStateBuff = "Periodic_String\n";
const char * runTimeStateBuff_1 = "Button_1_Rising_edge\n";
const char * runTimeStateBuff_2 = "Button_1_Falling_edge\n";
const char * runTimeStateBuff_3 = "Button_2_Rising_edge\n";
const char * runTimeStateBuff_4 = "Button_2_Falling_edge\n";
char * runTimeStateBuff_5 = "Periodic_String\n";
unsigned int strlen(const char *x){

	unsigned int l = 0; 
	while(*x != '\0'){
	l++;
	x++;
	}
	return l;
}	
#define Period_A  50
#define Period_B  50
#define Period_C  100
#define Period_D  20
#define Period_E  10
#define Period_F  100


/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */

 QueueHandle_t xQueue1; 


/*
-------------------------------------------------
 Hooks Implementation
-------------------------------------------------

*/

void vApplicationTickHook(void){

	/*Implementation*/
	
	GPIO_write(PORT_0, PIN0, PIN_IS_HIGH);
	
	GPIO_write(PORT_0, PIN0, PIN_IS_LOW);
	
}

/*
-------------------------------------------------
 Task Prototype
-------------------------------------------------
*/

void Button_1_Monitor(void *PvParameter){
	
	char F = 0;
	TickType_t Last_W_T = xTaskGetTickCount();
	
	for(;;){
	
		
		if((GPIO_read(PORT_0,PIN1))&&(F == 0)){
			
			 F = 1;
			 if( xQueue1 != 0 )
    {
        /* Send an unsigned long.  Wait for 10 ticks for space to become
        available if necessary. */
        if( xQueueSend( xQueue1,
                             ( void * ) &runTimeStateBuff_1,
                             ( TickType_t ) 10 ) != pdPASS )
        {
            /* Failed to post the message, even after 10 ticks. */
        }
    }
		
		}else if((!(GPIO_read(PORT_0,PIN1))) && (F == 1)){
			
			F = 0;
				 if( xQueue1 != 0 )
    {
        /* Send an unsigned long.  Wait for 10 ticks for space to become
        available if necessary. */
        if( xQueueSend( xQueue1,
                             ( void * ) &runTimeStateBuff_2,
                             ( TickType_t ) 10 ) != pdPASS )
        {
            /* Failed to post the message, even after 10 ticks. */
        }
			
		}
	}
		
		xTaskDelayUntil(& Last_W_T, Period_A);
		
	
	}
	
	
	
}
void Button_2_Monitor(void *PvParameter){
	
	char F2 = 0;
		
	TickType_t Last_W_T_1 = xTaskGetTickCount();
	
	for(;;){
	
		
		if((GPIO_read(PORT_0,PIN2))&&(F2 == 0)){
			F2 = 1;
	 if( xQueue1 != 0 )
    {
        /* Send an unsigned long.  Wait for 10 ticks for space to become
        available if necessary. */
        if( xQueueSend( xQueue1,
                             ( void * ) &runTimeStateBuff_3,
                             ( TickType_t ) 10 ) != pdPASS )
        {
            /* Failed to post the message, even after 10 ticks. */
        }
		}
		}else if(!(GPIO_read(PORT_0,PIN2))&&(F2 == 0)){
			F2 = 0;
			
			if( xQueue1 != 0 )
    {
        /* Send an unsigned long.  Wait for 10 ticks for space to become
        available if necessary. */
        if( xQueueSend( xQueue1,
                             ( void * ) &runTimeStateBuff_4,
                             ( TickType_t ) 10 ) != pdPASS )
        {
            /* Failed to post the message, even after 10 ticks. */
        }
		}
	}
		
		
		xTaskDelayUntil( &Last_W_T_1, Period_B);
			
	
}

}

	
void Periodic_Transmitter(void *PvParameter){
	
	
	TickType_t Last_W_T_2 = xTaskGetTickCount();
	for(;;){
		
		
			 if( xQueue1 != 0 )
    {
        /* Send an unsigned long.  Wait for 10 ticks for space to become
        available if necessary. */
        if( xQueueSend( xQueue1,
                             ( void * ) &runTimeStateBuff_5,
                             ( TickType_t ) 10 ) != pdPASS )
        {
            /* Failed to post the message, even after 10 ticks. */
        }
		while(txDataSizeLeftToSend != 0);
	
		xTaskDelayUntil(&Last_W_T_2, Period_C);
		

	}
	
}
	}
void Uart_Receiver(void *PvParameter){

	
	TickType_t Last_W_T_3 = xTaskGetTickCount();
	for(;;){
		
		if(xQueueReceive(xQueue1, (void *) &runTimeStateBuff, ( TickType_t ) 10 ) != pdPASS ){

		vSerialPutString(runTimeStateBuff, strlen(runTimeStateBuff));
		
		while(txDataSizeLeftToSend != 0);
		}
		xTaskDelayUntil(& Last_W_T_3, Period_D);
		

	}
	
}
void Load_1_(void *PvParameter){

	int i;
	
	TickType_t Last_W_T_5 = xTaskGetTickCount();
	
	for(;;){
	
		for(i = 0; i < 10000 ;i++){
			
			i = i;
		}
			

		xTaskDelayUntil(&Last_W_T_5, Period_E);

	}
	
}
void Load_2_(void *PvParameter){

	int i;
	
	TickType_t Last_W_T_6 = xTaskGetTickCount();
	for(;;){
	
			for(i = 0; i < 25000;i++){
				i = i;
			}
			
			xTaskDelayUntil(&Last_W_T_6, Period_F);
			
			
	
			
	}
	
}

int main( void )
{
	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();

	
    /* Create Tasks here */
	xTaskPeriodicCreate( Button_1_Monitor, 
											"Button_1_Monitor", 
											configMINIMAL_STACK_SIZE, 
											(void * ) NULL, 
											(tskIDLE_PRIORITY | portPRIVILEGE_BIT ),
											&Task_Button_1,
											Period_A);
		xTaskPeriodicCreate( Button_2_Monitor, 
											"Button_2_Monitor", 
											configMINIMAL_STACK_SIZE, 
											(void * ) NULL, 
											(tskIDLE_PRIORITY | portPRIVILEGE_BIT ),
											&Task_Button_2,
											Period_A);
		xTaskPeriodicCreate( Periodic_Transmitter, 
											"Periodic_Trans", 
											configMINIMAL_STACK_SIZE, 
											(void * ) NULL, 
											(tskIDLE_PRIORITY | portPRIVILEGE_BIT ),
											&Task_Periodic_Trans,
											Period_C);
		xTaskPeriodicCreate( Uart_Receiver, 
											"Uart_Rec", 
											configMINIMAL_STACK_SIZE, 
											(void * ) NULL, 
											(tskIDLE_PRIORITY | portPRIVILEGE_BIT ),
											&Task_Uart_Rec,
											Period_D);

	xTaskPeriodicCreate( Load_1_, 
											"Load_1_", 
											configMINIMAL_STACK_SIZE, 
											(void * ) NULL, 
											(tskIDLE_PRIORITY | portPRIVILEGE_BIT ),
											&Task_Load_1,
											Period_E);
											
	xTaskPeriodicCreate( Load_2_, 
											"Load_2_", 
											configMINIMAL_STACK_SIZE, 
											(void * ) NULL, 
											(tskIDLE_PRIORITY | portPRIVILEGE_BIT ),
											&Task_Load_2,
											Period_F);
	
	xQueue1 = xQueueCreate( 10, sizeof( char * ) );

	/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	vTaskSetTaskNumber(Task_Button_1, 1);
	vTaskSetTaskNumber(Task_Button_2, 2);
	vTaskSetTaskNumber(Task_Periodic_Trans, 3);
	vTaskSetTaskNumber(Task_Uart_Rec, 4);
	vTaskSetTaskNumber(Task_Load_1, 5);
	vTaskSetTaskNumber(Task_Load_2, 6);										
	
	
											
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
	return 0;
}
/*-----------------------------------------------------------*/

/* Function to reset timer 1 */
void timer1Reset(void)
{
	T1TCR |= 0x2;
	T1TCR &= ~0x2;
}

/* Function to initialize and start timer 1 */
static void configTimer1(void)
{
	T1PR = 1000;
	T1TCR |= 0x1;
}

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();
	
	/* Config trace timer 1 and read T1TC to get current tick */
	configTimer1();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/


