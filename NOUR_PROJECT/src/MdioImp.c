/*
title: DIO Driver implementaion
author:M.Nour
version: 0
date:12/11/2022
*/

#include "MdioHeader.h"
#include "MdioPrivate.h"

void SetPortDir(u8 ARGPortNameU8, u8 ARGPortDir) // input 0x00 /output 0xff
{
    switch (ARGPortNameU8)
    {
    case PORTA:
        PA->ddr= ARGPortDir; 
        break;
    case PORTB:
        PB->ddr= ARGPortDir; 
        break;
    case PORTC:
        PC->ddr= ARGPortDir; 
        break;
    case PORTD:
        PD->ddr= ARGPortDir; 
        break;
    default:
        break;
    }
}
void SetPortVal(u8 ARGPortNameU8, u8 ARGPortValueU8)
{
    switch (ARGPortNameU8)
    {
    case PORTA:
        PA->port= ARGPortValueU8 ; 
        break;
    case PORTB:
        PB->port= ARGPortValueU8; 
        break;
    case PORTC:
        PC->port= ARGPortValueU8; 
        break;
    case PORTD:
        PD->port= ARGPortValueU8; 
        break;
    default:
        break;
    }
}
u8 ReadPortVal(u8 ARGPortNameU8)
{
    switch (ARGPortNameU8)
    {
    case PORTA:
        return PA->pin; 
        break;
    case PORTB:
        return PB->pin; 
        break;
    case PORTC:
        return PC->pin; 
        break;
    case PORTD:
        return PD->pin;
        break;
    default:
        break;
    }
}
void SetPinDir(u8 ARGPortNameU8, u8 ARGPinNumU8, u8 ARGPinDirU8)
{
    switch (ARGPinDirU8)
    {
    case INPUT:
        switch (ARGPortNameU8)  
        {
        case PORTA:
            CLEAR_BIT(PA->ddr, ARGPinNumU8);
            break;
        case PORTB:
            CLEAR_BIT(PB->ddr, ARGPinNumU8); 
            break;
        case PORTC:
            CLEAR_BIT(PC->ddr, ARGPinNumU8); 
            break;
        case PORTD:
            CLEAR_BIT(PD->ddr, ARGPinNumU8); 
            break;
        default:
            break;
        }
        break;
    case OUTPUT:
        switch (ARGPortNameU8)  
        {
        case PORTA:
            SET_BIT(PA->ddr, ARGPinNumU8);
            break;
        case PORTB:
            SET_BIT(PB->ddr, ARGPinNumU8); 
            break;
        case PORTC:
            SET_BIT(PC->ddr, ARGPinNumU8); 
            break;
        case PORTD:
            SET_BIT(PD->ddr, ARGPinNumU8); 
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
void SetPinValue(u8 ARGPortNameU8 ,u8 ARGPinNumU8, u8 ARGPinValueU8)
{
    switch (ARGPinValueU8)
    {
    case LOW:
        switch (ARGPortNameU8)  
        {
        case PORTA:
            CLEAR_BIT(PA->port, ARGPinNumU8);
            break;
        case PORTB:
            CLEAR_BIT(PB->port, ARGPinNumU8); 
            break;
        case PORTC:
            CLEAR_BIT(PC->port, ARGPinNumU8); 
            break;
        case PORTD:
            CLEAR_BIT(PD->port, ARGPinNumU8); 
            break;
        default:
            break;
        }
        break;
    case HIGH:
        switch (ARGPortNameU8)  
        {
        case PORTA:
            SET_BIT(PA->port, ARGPinNumU8);
            break;
        case PORTB:
            SET_BIT(PB->port, ARGPinNumU8); 
            break;
        case PORTC:
            SET_BIT(PC->port, ARGPinNumU8); 
            break;
        case PORTD:
            SET_BIT(PD->port, ARGPinNumU8); 
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
u8 ReadPinValue(u8 ARGPortNameU8, u8 ARGPinNumU8)
{
    switch (ARGPortNameU8)
    {
    case PA:
        return GET_BIT(PA->pin,ARGPinNumU8);
        break;
    case PB:
        return GET_BIT(PB->pin,ARGPinNumU8);
        break;
    case PC:
       return GET_BIT(PC->pin,ARGPinNumU8);
        break;
    case PD:
       return GET_BIT(PD->pin,ARGPinNumU8);
        break;
    default:
        break;
    }
    return 0;
}