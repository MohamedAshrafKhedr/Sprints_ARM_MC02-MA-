/*
 * ADC.h
 *
 *  Created on: Nov 3, 2022
 *      Author: 8
 */

#ifndef CAR_SENSORS_ECU_MCAL_INC_ADC_H_
#define CAR_SENSORS_ECU_MCAL_INC_ADC_H_

void ADC_Init(void);

unsigned char ADC_Read(unsigned char Channel);

#endif /* CAR_SENSORS_ECU_MCAL_INC_ADC_H_ */
