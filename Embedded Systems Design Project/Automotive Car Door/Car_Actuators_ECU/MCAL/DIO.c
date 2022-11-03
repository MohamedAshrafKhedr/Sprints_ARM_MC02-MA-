/*
 * DIO.c
 *
 *  Created on: Nov 3, 2022
 *      Author: 8
 */
#include "../../Car_Actuators_ECU/MCAL/Inc/DIO.h"

void Dio_Init(void){
	/*Here we are going to initialize first the status Register*/
	/*Here we are going to initialize the control Register*/
	/*Here we are going to decide our pins direction either inputs or outputs*/
}
unsigned char Dio_Read(unsigned char Port, unsigned char Pin){
	/*Here we are going to return the value of the pin we would like to read*/
	return 0/*(Value required)*/;
}
Bool Dio_Write(unsigned char Port, unsigned char Pin){
	/*Here we are going to write the value of the pin we would like to as an output*/
	return 0/*(The return is of boolean type to give an indication the pin has been written successfully or not)*/;
}
Bool Dio_Toggle(unsigned char Port, unsigned char Pin){
	/*Here we are going to Toggle the value of the pin we would like to as an output*/
	return 0/*(The return is of boolean type to give an indication the pin has been Toggled successfully or not)*/;
}
