/* 
GIE_Program.c
created_on: 14 Feb 2023
author: Mohamed Magdi
 */


#include "BIT_OP.h"
#include "STD_types.h"
#include "GIE_Interface.h"


void Interrupt_Enable() {
    SET_BIT(SREG, 7);
}