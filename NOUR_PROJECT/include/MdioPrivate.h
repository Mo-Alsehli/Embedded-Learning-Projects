/*
title: DIO Driver private
author:M.Nour
version: 0
date:12/11/2022
*/

#ifndef _MDIO_PRIVATE_H
#define _MDIO_PRIVATE_H

#include "L_bitmath.h"
#include "L_stdu.h"

typedef struct Port_type
{
    u8 pin; 
    u8 ddr; 
    u8 port;      
}PortType;

#define PA ((volatile PortType*)0x39) 
#define PB ((volatile PortType*)0x36) 
#define PC ((volatile PortType*)0x33)
#define PD ((volatile PortType*)0x30)

#endif
