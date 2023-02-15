/* 
EXTI_Program.c
created on: 13 Feb 2023
author: mohamed magdi


 */

#include "BIT_OP.h"
#include "STD_types.h"
#include "EXTI_Interface.h"


void EXTI_Enable(u8 INT_NUM){
    switch (INT_NUM)
    {
    case 0:
#if SENSE_CONTROL == LOW_LEVEL
        CLR_BIT(MCUCR, 0);
        CLR_BIT(MCUCR, 1);
#elif SENSE_CONTROL == ANY_LOGICAL_CHANGE
        SET_BIT(MCUCR, 0);
        CLR_BIT(MCUCR, 1);
#elif SENSE_CONTROL == FALLING_EDGE
        SET_BIT(MCUCR, 1);
        CLR_BIT(MCUCR, 0);
#elif SENSE_CONTROL == RISING_EDGE
        SET_BIT(MCUCR, 1);
        SET_BIT(MCUCR, 1);
#else
#error "Wrong Sense Control"
        SET_BIT(GICR, 6);
        break;
#endif
    case 1:
#if SENSE_CONTROL == LOW_LEVEL
        CLR_BIT(MCUCR, 0);
        CLR_BIT(MCUCR, 1);
#elif SENSE_CONTROL == ANY_LOGICAL_CHANGE
        SET_BIT(MCUCR, 2);
        CLR_BIT(MCUCR, 3);
#elif SENSE_CONTROL == FALLING_EDGE
        SET_BIT(MCUCR, 3);
        CLR_BIT(MCUCR, 2);
#elif SENSE_CONTROL == RISING_EDGE
        SET_BIT(MCUCR, 2);
        SET_BIT(MCUCR, 3);
#else
#error "Wrong Sense Control"
        SET_BIT(GICR, 7);

        break;
#endif
}}