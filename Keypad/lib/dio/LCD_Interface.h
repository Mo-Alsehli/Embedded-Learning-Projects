/* 
LCD_Interface.h
created on: 9 Feb 2023
Auther: Mohamed Magdi

 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include"STD_types.h"

// defining the function set (we set the binary value 0010 then we make 1 for N to display two lines and 1 for the font to increase the font size).
#define Function_Set 0b00101000
// defining DCB (display and cursor and blink).
#define Display_On_Off 0b00001111
// defining display clear
#define Display_Clear 0b00000001
// defining the entry mode(increment mode with 1 value because we write in English and No display shift operation with 0).
#define Entry_mode 0b00000110

// Initializing The LCD.
void LCD_Init();

// A function to send the commands.
void Send_Commands(u8 command);

// Send the data.
void LCD_SendData(u8 data);

// Send the data when 4-bit mode.
void LCD_SendData_4bitMode(u8 data);

void LCD_SendNumbers(u16 number);

void LCD_SendString(u8 *string);









#endif