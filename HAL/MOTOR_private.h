/*
 *  Author: Omar Khaled
 */
#ifndef MOTOR_PRIVATE_H_
#define MOTOR_PRIVATE_H_

#include "DIO_interface.h"
#define NUMBERS_OF_PINS_PER_MOTOR 2
#define IN1      0
#define IN2      1
extern const const DIO_PinVoltage_type MotorPinsArray[NUMBER_MOTORS][NUMBERS_OF_PINS_PER_MOTOR];


#endif /* MOTOR_PRIVATE_H_ */