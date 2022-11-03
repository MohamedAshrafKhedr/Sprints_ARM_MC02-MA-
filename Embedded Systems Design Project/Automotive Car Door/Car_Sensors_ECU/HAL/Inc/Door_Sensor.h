/*
 * Buzzer.h
 *
 *  Created on: Nov 3, 2022
 *      Author: 8
 */
#include "../../../Car_Sensors_ECU/Service_Layer/Std_Types.h"


#ifndef CAR_ACTUATORS_ECU_HAL_INC_DOOR_SENSOR_H_
#define CAR_ACTUATORS_ECU_HAL_INC_DOOR_SENSOR_H_

#define DOOR_OPEN 1
#define DOOR_CLOSED 0

extern uint8 Door_Status(uint8 Port, uint8 Pin);
#endif /* CAR_ACTUATORS_ECU_HAL_INC_DOOR_SENSOR_H_ */
