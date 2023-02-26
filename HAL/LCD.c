/*
 *  Author: Omar Khaled
 */ 

#include "LCD_interface.h"
#include "DIO_interface.h"
#include "Utils.h"
#include "LCD_cfg.h"
#define F_CPU 8000000
#include <util/delay.h>

#if LCD_MODE==_4_BIT

static void writeInstruction(u8 instruction){
	DIO_WritePin(RS,LOW);
	
	DIO_WritePin(D7,READ_BIT(instruction,7));
	DIO_WritePin(D6,READ_BIT(instruction,6));
	DIO_WritePin(D5,READ_BIT(instruction,5));
	DIO_WritePin(D4,READ_BIT(instruction,4));
	DIO_WritePin(ENABLE,HIGH);
	_delay_ms(1);
	DIO_WritePin(ENABLE,LOW);
	_delay_ms(1);
	
	DIO_WritePin(D7,READ_BIT(instruction,3));
	DIO_WritePin(D6,READ_BIT(instruction,2));
	DIO_WritePin(D5,READ_BIT(instruction,1));
	DIO_WritePin(D4,READ_BIT(instruction,0));
	DIO_WritePin(ENABLE,HIGH);
	_delay_ms(1);
	DIO_WritePin(ENABLE,LOW);
	_delay_ms(1);
}
static void writeData(u8 data){
	DIO_WritePin(RS,HIGH);
	
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(ENABLE,HIGH);
	_delay_ms(1);
	DIO_WritePin(ENABLE,LOW);
	_delay_ms(1);
	
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(ENABLE,HIGH);
	_delay_ms(1);
	DIO_WritePin(ENABLE,LOW);
	_delay_ms(1);
}
void LCD_Init(void){
	_delay_ms(50);
	writeInstruction(USE_4BIT_CONF);
	writeInstruction(INITIAL_CONF_4BIT);
	writeInstruction(CURSOR_OP);
	writeInstruction(CLEAR_SCREEN);
	_delay_ms(1);
	writeInstruction(WRITING_STYLE);
}
#elif	LCD_MODE==_8_BIT

static void writeInstruction(u8 instruction){
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,instruction);
	DIO_WritePin(ENABLE,HIGH);
	_delay_ms(1);
	DIO_WritePin(ENABLE,LOW);
	_delay_ms(1);
}
static void writeData(u8 data){
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(ENABLE,HIGH);
	_delay_ms(1);
	DIO_WritePin(ENABLE,LOW);
	_delay_ms(1);
}
void LCD_Init(void){
	_delay_ms(50);
	
	writeInstruction(INITIAL_CONF_8BIT);
	writeInstruction(CURSOR_OP);
	writeInstruction(CLEAR_SCREEN);
	_delay_ms(1);
	writeInstruction(WRITING_STYLE);
}

#endif

void LCD_Clear(){
	writeInstruction(CLEAR_SCREEN);
}

void LCD_WriteChar(u8 ch){
	writeData(ch);
}
void LCD_WriteNumber(s32 num){
	u8 i=0, str[13];
	if(num==0){
		LCD_WriteChar('0');
	}
	else{
		if(num<0){
			LCD_WriteChar('-');
			num=num*-1;
		}
		while(num){
			str[i]=num%10 +'0';
			num=num/10;
			i++;
		}
		str[i]=0;
		for(s8 j=i-1;j>=0;j--){
			LCD_WriteChar(str[j]);
		}
	}
}
void LCD_WriteString(char *str){
	for(u8 i=0;str[i];i++){
		LCD_WriteChar(str[i]);
	}
}
void LCD_WriteBinary(u8 num){
	s8 i;
	for(i=7;i>=0;i--){
		if(READ_BIT(num,i)){
			LCD_WriteChar('1');
		}
		else{
			LCD_WriteChar('0');
		}
	}
}
void LCD_WriteHex(u8 num){
	if(num==0){
		LCD_WriteChar('0');
		return;
	}
	u8 str[3],i=0,n=0;
	while(num){
		n=num%16;
		num=num/16;
		if(n>=10){str[i]='A'+n-10;}
		else{
			str[i]=n+'0';
		}
		i++;
	}
	str[i]=0;
	for(s8 j=i-1;j>=0;j--){
		LCD_WriteChar(str[j]);
	}
}
void LCD_SetCursor(u8 line, u8 cell){
	if(line==0){
		writeInstruction(INITIAL_ADDRESS|cell);
	}
	else if(line==1){
		writeInstruction(INITIAL_ADDRESS|SECOND_LINE_ADDRESS|cell);
	}
	
}
void LCD_Write4Digits(u16 num){
	u8 str[5], i=0;
	while(i<4){
		str[i]=num%10+'0';
		num=num/10;
		i++;
	}
	str[i]=0;
	for(s8 j=3;j>=0;j--){
		LCD_WriteChar(str[j]);
	}
	
}
void LCD_ClearCell(u8 line,u8 cell, u8 num){
	LCD_SetCursor(line,cell);
	for(int i=0;i<num;i++){
		LCD_WriteChar(' ');
	}
}