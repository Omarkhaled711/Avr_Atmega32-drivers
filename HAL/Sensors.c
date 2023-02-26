/*
 *  Author: Omar Khaled
 */ 
#include "StdTypes.h"
#include "ADC_interface.h"
#include "Sensors_interface.h"
#include "Sensors_cfg.h"

/* return in celius * 10*/
u16 TEMP_Read(void){
	u16 volt=ADC_ReadVolt(LM35_CH);
	u16 temp=volt;
	return temp;
}