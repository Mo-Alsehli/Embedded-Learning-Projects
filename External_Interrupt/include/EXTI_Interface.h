/* 
EXTI_Interface.h
created on: 13 Feb 2023
author: Mohamed Magdi


 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "STD_types.h"


#define LOW_LEVEL 0
#define ANY_LOGICAL_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3
#define SENSE_CONTROL LOW_LEVEL

// defining MCUCR
#define MCUCR *((volatile u8*) 0x55)
#define GICR *((volatile u8*) 0x5B)







void EXTI_Enable(u8 INT_NUM);


#endif