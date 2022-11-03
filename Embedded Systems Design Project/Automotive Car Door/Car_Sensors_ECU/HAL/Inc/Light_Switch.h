/*
 * Light_Switch.h
 *
 *  Created on: Nov 3, 2022
 *      Author: 8
 */
#include "../../../Car_Sensors_ECU/Service_Layer/Std_Types.h"

#ifndef CAR_ACTUATORS_ECU_HAL_INC_LIGHT_SWITCH_H_
#define CAR_ACTUATORS_ECU_HAL_INC_LIGHT_SWITCH_H_

#define LIGHT_ON  1
#define LIGHT_OFF 0

extern uint8 Light_Status(uint8 Port, uint8 Pin);
#endif /* CAR_ACTUATORS_ECU_HAL_INC_LIGHT_SWITCH_H_ */
