/*
 * main.c
 *
 *  Created on: Feb 3, 2023
 *      Author: dell
 */

#include"DIO_interface.h"
#include"BIT_OP.h"
#include"STD_types.h"
#include"DIO_program.c"

int main(){
	// connecting a push button as input on PORT_A PIN_2 and a led in the output on PORT_C PIN_7.
	SET_Direction(PORT_A, PIN_2, INPUT);
	SET_Direction(PORT_C, PIN_7, OUTPUT);
	// Activating the internal pull up resistor.
	SET_Value(PORT_A, PIN_2, HIGH);

	// We add a while loop so that the program will keep running
	while(1){
		if(GET_Value(PORT_A, PIN_2) == LOW){
			SET_Value(PORT_C, PIN_7, HIGH);
		}else if(GET_Value(PORT_A, PIN_2) == HIGH){
			SET_Value(PORT_C, PIN_7, LOW);
		}

	}
	return 0;
}


