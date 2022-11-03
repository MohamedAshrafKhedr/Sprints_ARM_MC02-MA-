/*
 * CAN.h
 *
 *  Created on: Nov 3, 2022
 *      Author: 8
 */
#include "../../../Car_Sensors_ECU/Service_Layer/Std_Types.h"

#ifndef CAR_ACTUATORS_ECU_MCAL_INC_CAN_H_
#define CAR_ACTUATORS_ECU_MCAL_INC_CAN_H_

extern void CAN_Init(void);

extern uint8 CAN_Send(uint8 *Buffer, uint8 Size, uint8 CRC);

extern uint8* CAN_Receive(uint8 *Buffer, uint8 Size, uint8 CRC);

#endif /* CAR_ACTUATORS_ECU_MCAL_INC_CAN_H_ */
