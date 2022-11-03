/*
 * DIO.h
 *
 *  Created on: Nov 3, 2022
 *      Author: 8
 */

#ifndef CAR_SENSORS_ECU_MCAL_INC_DIO_H_
#define CAR_SENSORS_ECU_MCAL_INC_DIO_H_

typedef unsigned char Bool;
enum state{
	Lo = 0,
	Hi = 1
};
void Dio_Init(void);
unsigned char Dio_Read(unsigned char Port, unsigned char Pin);
Bool Dio_Write(unsigned char Port, unsigned char Pin);
Bool Dio_Toggle(unsigned char Port, unsigned char Pin);
#endif /* CAR_SENSORS_ECU_MCAL_INC_DIO_H_ */
