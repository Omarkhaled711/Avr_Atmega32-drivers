/*
 *  Author: Omar Khaled
 */ 

#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#include "LCD_private.h"

#define		LCD_MODE				_4_BIT			

//******************************if 8 bit mode**********************//
#define		LCD_PORT				PA
#define		INITIAL_CONF_8BIT	0x38 // 2 lines 8 bit mode (5x7 font)
//*****************************if 4 bit mode**********************//
#define		D7						PINC3
#define		D6						PINC2
#define		D5						PINC1
#define		D4						PINC0
#define		INITIAL_CONF_4BIT	0x28

//****************************General*****************************//

#define		RS						PINC6
#define		ENABLE					PINC7	
#define		CURSOR_OP			0x0c //(cursor off,, for cursor on: 0x0e,, for cursor blinking: 0x0f)
#define		CLEAR_SCREEN		0x01 //(clear screen)
#define		WRITING_STYLE		0x06 //(increase DDRam address, no shift)
#define		INITIAL_ADDRESS		0x80
#define		SECOND_LINE_ADDRESS	0x40

#endif /* LCD_CFG_H_ */