/*
 * Door_Sensor.c
 *
 *  Created on: Nov 3, 2022
 *      Author: 8
 */
#include "../../Car_Sensors_ECU/HAL/Inc/Door_Sensor.h"

#include "../../Car_Sensors_ECU/MCAL/Inc/DIO.h"
uint8 Door_Status(uint8 Port, uint8 Pin){
	Dio_Init();/*Initialize the Dio Peripheral*/

	return Dio_Read(Port, Pin);/*Read the Pin status connected to the Door Sensor*/
}
