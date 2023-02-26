/*
 *  Author: Omar Khaled
 */


#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

void STEPPER_Init(void);
void STEPPER_Bipolar_Cw(void);
void STEPPER_Bipolar_CCw(void);
void STEPPER_Unipolar_Cw(void);
void STEPPER_Unipolar_CCw(void);
void STEPPER_Bipolar_Cw_HalfStep(void);
void STEPPER_Bipolar_CCw_HalfStep(void);
void STEPPER_Unipolar_Cw_HalfStep(void);
void STEPPER_Unipolar_CCw_HalfStep(void);

void STEPPER_ByRotations_Unipolar(u8 rotations);

#endif /* STEPPER_INTERFACE_H_ */