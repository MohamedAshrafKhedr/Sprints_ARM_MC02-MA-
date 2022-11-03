/*
 * ADC.c
 *
 *  Created on: Nov 3, 2022
 *      Author: 8
 */


#include "../../Car_Sensors_ECU/MCAL/Inc/ADC.h"

#include "../../Car_Sensors_ECU/MCAL/Inc/DIO.h"

void ADC_Init(void){
	/*Here we are going to Initialize the ADC pins Direction using the API's of DIO.h*/
}

unsigned char ADC_Read(unsigned char Channel){
	/*Here we are going to mask the required pins we want to use along with the input channel given*/
	/*Here we are going to read the value from the input channel given and multiply it by the resolution to get the corresponding value*/
	return 0/*return the value of the pin you wish to read*/;
}
