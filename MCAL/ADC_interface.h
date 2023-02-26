/*
 *  Author: Omar Khaled
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
typedef enum{
	VREF_AREF,
	VREF_AVCC,
	VREF_256
}ADC_Vref_Type;

typedef enum{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
}ADC_Channel_Type;

typedef enum{
	ADC_SCALE_2=1,
	ADC_SCALE_4,
	ADC_SCALE_8,
	ADC_SCALE_16,
	ADC_SCALE_32,
	ADC_SCALE_64,
	ADC_SCALE_128
}ADC_Prescaler_Type;
void ADC_Init(ADC_Vref_Type vref,ADC_Prescaler_Type scaler);
void ADC_Enable(void);
void ADC_Disable(void);
void ADC_StartConversion(ADC_Channel_Type ch);
u16 ADC_GetRead(void);
u8 ADC_GetReadPeriodic(u16* pdata);
u16 ADC_ReadVolt(ADC_Channel_Type ch);
u16 ADC_ConvertToVolt(u16 adc);


#endif /* ADC_INTERFACE_H_ */