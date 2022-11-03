/*
 * Speed_Sensor.h
 *
 *  Created on: Nov 3, 2022
 *      Author: 8
 */
#include "../../../Car_Sensors_ECU/Service_Layer/Std_Types.h"

#ifndef CAR_ACTUATORS_ECU_HAL_INC_SPEED_SENSOR_H_
#define CAR_ACTUATORS_ECU_HAL_INC_SPEED_SENSOR_H_

#define CAR_MOVING 1
#define CAR_STOPPED 0


extern uint8 Speed_Sensor_Reading(uint8 Channel);
#endif /* CAR_ACTUATORS_ECU_HAL_INC_SPEED_SENSOR_H_ */
