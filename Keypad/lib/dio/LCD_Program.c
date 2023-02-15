/* 
LCD_Program.c
created on: 9 Feb 2023
Auther: Mohamed Magdi

 */

#include "STD_types.h"
#include "LCD_Interface.h"
#include "DIO_interface.h"
#include <util/delay.h>


// Initializing The LCD Function.
void LCD_Init(){
    // send the function set with the function set to the 4MSP so we shift with 4 times.
    Send_Commands(Function_Set>>4);
    // then we send them again.
    Send_Commands(Function_Set>>4);
    // then we send the 4LSP as we work with 4 bits only.
    Send_Commands(Function_Set);
    // delay with 1ms(optional).
    _delay_ms(1);
    // then we send the dispaly on and off for the 4MSP and for 4LSP.
    Send_Commands(Display_On_Off>>4);
    Send_Commands(Display_On_Off);
    // then display clear
    Send_Commands(Display_Clear>>4);
    Send_Commands(Display_Clear);
    _delay_ms(2);
    // and then the Entry mode.
    Send_Commands(Entry_mode>>4);
    Send_Commands(Entry_mode);

}

// A function to send the commands.
void Send_Commands(u8 command){
    // SET RS to zero now we are in the command mode.
    SET_Value(PORT_C, PIN_0, LOW);
    // setting R/W to zero (in the writing mode).
    SET_Value(PORT_C, PIN_1, LOW);
    // setting the 4MSP to the command(data pins are connected to the 4MSP of PORT_C).
    SET_Value_4MSP(PORT_C, command);
    // Set the Enable to High.
    SET_Value(PORT_C, PIN_2, HIGH);
    // wait for 5ms.
    _delay_ms(5);
    // Set the Enable to Low
    SET_Value(PORT_C, PIN_2, LOW);
    // delay for 1ms.
    _delay_ms(1);

}

// Send the data.
void LCD_SendData(u8 data){
    SET_Value(PORT_C, PIN_0, HIGH);
    SET_Value(PORT_C, PIN_1, LOW);
    SET_Value_4MSP(PORT_C, data);
    // Set the Enable to High.
    SET_Value(PORT_C, PIN_2, HIGH);
    // wait for 5ms.
    _delay_ms(5);
    // Set the Enable to Low
    SET_Value(PORT_C, PIN_2, LOW);
    // delay for 1ms.
    _delay_ms(1);
}

// Send the data when 4-bit mode.
void LCD_SendData_4bitMode(u8 data){
    LCD_SendData(data>>4);
    LCD_SendData(data);
}

void LCD_SendNumbers(u16 number){
    // we take each digit alone and send it to the LCD.
    // LCD takes characters as ASCII code. 
    // the number here takes five bits so we create an array of length 5.
    u8 arr[5]; 
    u8 i;
    if(number == 0){
        LCD_SendData_4bitMode('0');
    }else{
    while(number != 0){
        arr[i] = number % 10;
        number /= 10;
        i++;
    }
    for(s8 j = i - 1; j >= 0; j--){
        LCD_SendData_4bitMode(arr[j] + 48);
    }
    }
}

void LCD_SendString(u8 *string){
    for(u8 i = 0; *(string + i) != '\0'; i++){
        LCD_SendData_4bitMode(*(string + i));
    }
}