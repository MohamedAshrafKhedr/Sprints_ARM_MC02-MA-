/*
 * CAN.c
 *
 *  Created on: Nov 3, 2022
 *      Author: 8
 */
#include "../../Car_Sensors_ECU/MCAL/Inc/CAN.h"

void CAN_Init(void){
	/*Initialize CAN status Register*/
	/*Initialize CAN Control Register*/
	/*Initialize set CAN Speed */
}
uint8 CAN_Send(uint8 *Buffer, uint8 Size, uint8 CRC){

	/*Here you are going to send the data in a loop until it hits the given size*/
	return 0 /*return the Boolean Value of the process sent successfully or not*/;
}


uint8* CAN_Receive(uint8 *Buffer, uint8 Size, uint8 CRC){

	return Buffer/*return the delivered message in the given buffer  */;
}
