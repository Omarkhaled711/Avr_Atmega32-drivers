/*
 *  Author: Omar Khaled
 */
#include "StdTypes.h"
#include "Utils.h"
#include "Stepper_interface.h"
#include "Stepper_cfg.h"
#include "DIO_interface.h"
#define F_CPU 8000000
#include <util/delay.h>

void STEPPER_Init(void){}
void STEPPER_Bipolar_Cw(void){
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
}
void STEPPER_Bipolar_CCw(void){
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);

	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);

	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
}
void STEPPER_Unipolar_Cw(void){
		DIO_WritePin(COIL1A,LOW);
		DIO_WritePin(COIL1B,LOW);
		DIO_WritePin(COIL2B,LOW);
		DIO_WritePin(COIL2A,HIGH);
		_delay_ms(DELAY);
		
		DIO_WritePin(COIL1A,LOW);
		DIO_WritePin(COIL1B,LOW);
		DIO_WritePin(COIL2B,HIGH);
		DIO_WritePin(COIL2A,LOW);
		_delay_ms(DELAY);
		
		DIO_WritePin(COIL1A,LOW);
		DIO_WritePin(COIL1B,HIGH);
		DIO_WritePin(COIL2B,LOW);
		DIO_WritePin(COIL2A,LOW);
		_delay_ms(DELAY);
		
		DIO_WritePin(COIL1A,HIGH);
		DIO_WritePin(COIL1B,LOW);
		DIO_WritePin(COIL2A,LOW);
		DIO_WritePin(COIL2B,LOW);
		_delay_ms(DELAY);
}
void STEPPER_Unipolar_CCw(void){
		DIO_WritePin(COIL1A,HIGH);
		DIO_WritePin(COIL1B,LOW);
		DIO_WritePin(COIL2B,LOW);
		DIO_WritePin(COIL2A,LOW);
		_delay_ms(DELAY);
		
		DIO_WritePin(COIL1A,LOW);
		DIO_WritePin(COIL1B,HIGH);
		DIO_WritePin(COIL2B,LOW);
		DIO_WritePin(COIL2A,LOW);
		_delay_ms(DELAY);
		
		DIO_WritePin(COIL1A,LOW);
		DIO_WritePin(COIL1B,LOW);
		DIO_WritePin(COIL2B,HIGH);
		DIO_WritePin(COIL2A,LOW);
		_delay_ms(DELAY);
		
		DIO_WritePin(COIL1A,LOW);
		DIO_WritePin(COIL1B,LOW);
		DIO_WritePin(COIL2B,LOW);
		DIO_WritePin(COIL2A,HIGH);		
		_delay_ms(DELAY);
}
void STEPPER_Bipolar_Cw_HalfStep(void){
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
		
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);

	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);	
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
}
void STEPPER_Bipolar_CCw_HalfStep(void){
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);

	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
		
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);

	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);

	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);

	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
}
void STEPPER_Unipolar_Cw_HalfStep(void){
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	_delay_ms(DELAY);

	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,HIGH);
	DIO_WritePin(COIL2A,HIGH);
	_delay_ms(DELAY);
		
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	_delay_ms(DELAY);

	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	_delay_ms(DELAY);	
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2B,LOW);
	DIO_WritePin(COIL2A,LOW);
	_delay_ms(DELAY);

	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2B,LOW);
	DIO_WritePin(COIL2A,LOW);
	_delay_ms(DELAY);
		
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
}
void STEPPER_Unipolar_CCw_HalfStep(void){
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,LOW);
	DIO_WritePin(COIL2A,LOW);
	_delay_ms(DELAY);

	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2B,LOW);
	DIO_WritePin(COIL2A,LOW);
	_delay_ms(DELAY);
		
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2B,LOW);
	DIO_WritePin(COIL2A,LOW);
	_delay_ms(DELAY);

	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	_delay_ms(DELAY);
		
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	_delay_ms(DELAY);

	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,HIGH);
	DIO_WritePin(COIL2A,HIGH);
	_delay_ms(DELAY);	
	
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	_delay_ms(DELAY);
	
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	_delay_ms(DELAY);
}
void STEPPER_ByRotations_Unipolar(u8 rotations){
	for(u8 i=0;i<rotations*(STEPS_NUM/4);i++){
		STEPPER_Unipolar_Cw();
	}
}