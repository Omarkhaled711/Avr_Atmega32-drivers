/*
 *  Author: Omar Khaled
 */
#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#include "StdTypes.h"
typedef enum{
	M1,
	M2,
	M3,
	M4
	}MOTOR_type;
void MOTOR_Init(void);
void MOTOR_Stop(MOTOR_type motor);
void MOTOR_CW(MOTOR_type motor);
void MOTOR_CCW(MOTOR_type motor);
// speed from 0% to 100% of the max speed of the motor 
void MOTOR_SPEED(MOTOR_type motor, u8 speed);


#endif /* MOTOR_INTERFACE_H_ */