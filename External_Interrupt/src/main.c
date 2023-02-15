/* 
main.c
created on: 13 Feb 2023
author: Mohamed Magdi
 */


#include "BIT_OP.h"
#include "STD_types.h"
#include "GIE_Interface.h"
#include "EXTI_Interface.h"
#include "DIO_interface.h"
#include <util/delay.h>

int main() {
    // We can't choose any pin as the INT0 for the interrupt its the pinout of the ATmega32 which is PORT_D PIN_2
    SET_Direction(PORT_D, PIN_2, INPUT);
    SET_Direction(PORT_C, PIN_7, OUTPUT);
    SET_Value(PORT_D, PIN_2, HIGH);
    // Enabling Interrupt 0 with low level
    EXTI_Enable(0);
    Interrupt_Enable();

    u8 flag = 0;
    while (1){
        // Making a blinking logic for a led
        if(flag == 0){
            SET_Value(PORT_C, PIN_7, HIGH);
            flag = 1;
        }else if(flag == 1){
            SET_Value(PORT_C, PIN_7, LOW);
            flag = 0;
        }
        _delay_ms(500);
    }
    return 0;
}


// Calling A Function From Hardware:
// Here we add 'used' as the second parameter of __attribute__ to prevent error.
void __vector_1(void)  __attribute__((signal, used));
// Here where the interrupt will actually happen.
void __vector_1(void) {
    SET_Value(PORT_C, PIN_7, HIGH);
    _delay_ms(4000);
}