/*
 *  Author: Omar Khaled
 */ 
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "ADC_interface.h"
#include "ADC_cfg.h"

static u16 voltRef;
static u8 ADC_Flag=1; //this flag will make sure that the adc won't start a new reading operation until the prev one is done.
void ADC_Init(ADC_Vref_Type vref,ADC_Prescaler_Type scaler){
	/*clock*/
	scaler=scaler&0x07; //00000111
	ADCSRA=ADCSRA&0xf8; //11111000
	ADCSRA=ADCSRA|scaler;
	/*volt reference*/
	switch(vref){
		case VREF_AREF:
			CLEAR_BIT(ADMUX,REFS0);
			CLEAR_BIT(ADMUX,REFS1);
			voltRef=AREF;
			break;
		case VREF_AVCC:
			SET_BIT(ADMUX,REFS0);
			CLEAR_BIT(ADMUX,REFS1);
			voltRef=5000;
			break;		
		case VREF_256:
			SET_BIT(ADMUX,REFS0);
			SET_BIT(ADMUX,REFS1);
			voltRef=2560;
			break;	
	}
	/* reading from adc registers mod*/
	CLEAR_BIT(ADMUX,ADLAR);
}
void ADC_Enable(void){
	SET_BIT(ADCSRA,ADEN);
}
void ADC_Disable(void){
	CLEAR_BIT(ADCSRA,ADEN);
}
void ADC_StartConversion(ADC_Channel_Type ch){
	if(ADC_Flag==1){
		/*Select channel*/
		ADMUX=ADMUX&0xE0; //11100000
		ADMUX=ADMUX|ch;
		/* start conversion*/
		SET_BIT(ADCSRA,ADSC);
		ADC_Flag=0;
	}
	/*this function will start converting the analog signal into a digital one, 
	but it won't return a reading, to read from adc use either ADC_GetRead(), or ADC_GetReadPeriodic()*/
}
u16 ADC_GetRead(void){
	/*wait until it finishes*/
	while(READ_BIT(ADCSRA,ADSC));//busy wait
	ADC_Flag=1;
	/*get read*/
	return ADC;	
	//advantages: u will get the reading of the adc instantaneously when it's finished.
	//disadvantages: This function uses busy wait, so the processor will wait until the operation is finished
}
u8 ADC_GetReadPeriodic(u16* pdata){
	if(READ_BIT(ADCSRA,ADSC)){
		*pdata=ADC;
		ADC_Flag=1;
		return 1;
	}
	else{
		return 0;
	}
	//advantages: the function doesn't use busy wait, so the processor will be free to do some other operations.
	//disadvantages: u may not get the reading of the adc instantaneously.
}
u16 ADC_ReadVolt(ADC_Channel_Type ch){
	//use this function if u don't have the adc reading and want to get the volt directly.
	//advantages: no need to call any prior function first, as this is done implicitly.
	//dis: the adc_read uses busy wait to implement this logic.
	ADC_StartConversion(ch);
	u16 adc=ADC_GetRead();
	u16 volt=(adc*(u32)voltRef)/1024; //return in mv
	return volt;
}
u16 ADC_ConvertToVolt(u16 adc){
	//use this function if u have the adc reading and want to convert it to volts.
	//advantages: u can calculate the adc reading by using the adc_GetReadingPeriodic (so u won't waste the processor in a busy wait function)
	//dis: u will have to get the adc reading by your self before using this function.
	u16 volt=(adc*(u32)voltRef)/1024; //return in mv
	return volt;	
}