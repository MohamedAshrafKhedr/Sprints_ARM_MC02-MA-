/*
 * Speed_Sensor.c
 *
 *  Created on: Nov 3, 2022
 *      Author: 8
 */

#include "../../Car_Sensors_ECU/HAL/Inc/Speed_Sensor.h"

#include "../../Car_Sensors_ECU/MCAL/Inc/ADC.h"

uint8 Speed_Sensor_Reading(uint8 Channel){
	ADC_Init();/*Initialize ADC*/
	return ADC_Read(Channel)/*Get the Speed Sensor Reading from ADC*/;
}
