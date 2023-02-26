/*
 *  Author: Omar Khaled
 */

#include "MOTOR_cfg.h"
#include "MOTOR_private.h"
#include "DIO_interface.h"
const DIO_PinVoltage_type MotorPinsArray[NUMBER_MOTORS][NUMBERS_OF_PINS_PER_MOTOR]={
										/*IN1  IN2*/
	/*Motor 1*/							{M1_IN1,M1_IN2},
	/*Motor 2*/							{M2_IN1,M2_IN2},
	/*Motor 3*/							{M3_IN1,M3_IN2},
	/*Motor 4*/							{M4_IN1,M4_IN2}
	};