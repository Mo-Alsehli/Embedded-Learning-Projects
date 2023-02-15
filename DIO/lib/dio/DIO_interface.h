/*
 * DIO_header.h
 *
 *  Created on: Feb 3, 2023
 *      Author: dell
 */


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

// Defining the Ports of the microcontroller and get the addresses from the data sheet.

#define PORTA *((volatile u8*)0x3B)
#define DDRA *((volatile u8*)0x3A)
#define PINA *((volatile u8*)0x39)

#define PORTB *((volatile u8*)0x38)
#define DDRB *((volatile u8*)0x37)
#define PINB *((volatile u8*)0x39)

#define PORTC *((volatile u8*)0x35)
#define DDRC *((volatile u8*)0x34)
#define PINC *((volatile u8*)0x33)

#define PORTD *((volatile u8*)0x32)
#define DDRD *((volatile u8*)0x31)
#define PIND *((volatile u8*)0x30)

// some macros

#define INPUT 0
#define OUTPUT 1
#define LOW 0
#define HIGH 1

// Enum for pins and ports

typedef enum {
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
}PINS;

typedef enum {
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}PORTS;

// Defining prototypes of some functions.

void SET_Direction(u8 port, u8 pin, u8 direction);
void SET_Value(u8 port, u8 pin, u8 value);
u8 GET_Value(u8 port, u8 pin);

// Making so for 4 Least significant bits

void SET_Direction_4LSP(u8 port, u8 direction);
void SET_Value_4LSP(u8 port, u8 value);

// Making so for 4 most significant bits

void SET_Direction_4MSP(u8 port, u8 direction);
void SET_Value_4MSP(u8 port, u8 value);






#endif /* DIO_INTERFACE_H_ */
