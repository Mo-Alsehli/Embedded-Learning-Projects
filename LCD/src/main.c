/* 
main.c
created on: 2 Feb 2023
author: Mohamed Magdi.
*/

#include "BIT_OP.h"
#include "STD_types.h"
#include "LCD_Interface.h"
#include "LCD_Program.c"

int main(){
    // Setting directions of PORT C pins directions to be OUTPUt.
    SET_Direction(PORT_C, PIN_0, OUTPUT);
    SET_Direction(PORT_C, PIN_1, OUTPUT);
    SET_Direction(PORT_C, PIN_2, OUTPUT);
    SET_Direction_4MSP(PORT_C, OUTPUT);
    // initialzie the LCD
    LCD_Init();
    LCD_SendString("Mohamed Magdi,"); 
    LCD_SendNumbers(21);
    while(1){

    }
    return 0;
}