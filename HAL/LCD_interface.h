/*
 *  Author: Omar Khaled
 */ 
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include "StdTypes.h"
void LCD_Init(void);
void LCD_WriteNumber(s32 num);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(char *str);
void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u8 num);
void LCD_Write4Digits(u16 num);
void LCD_SetCursor(u8 line, u8 cell);
void LCD_Clear();
void LCD_ClearCell(u8 line,u8 cell, u8 num);


#endif /* LCD_INTERFACE_H_ */