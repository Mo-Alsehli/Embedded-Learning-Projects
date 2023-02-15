/*
 * main.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Mohamed Magdi
 */

#include"DIO_interface.h"
#include"BIT_OP.h"
#include"STD_types.h"
#include"DIO_program.c"
#include<util/delay.h>

// Assignment-1
// instead of the current code we will make a code for two 7-segment that increments automatically and counts from 00 to 99.

int main(){
	// Connecting the push button to the Port A pin 2 as input.
	SET_Direction(PORT_A, PIN_2, INPUT);

	// configuring four pins for the BCD as output.

	/* SET_Direction(PORT_C, PIN_1, OUTPUT);
	SET_Direction(PORT_C, PIN_2, OUTPUT);
	SET_Direction(PORT_C, PIN_3, OUTPUT);
	SET_Direction(PORT_C, PIN_4, OUTPUT); */
	SET_Direction_4LSP(PORT_C, OUTPUT); 
	SET_Direction_4LSP(PORT_D, OUTPUT); 

	// Initializing the PULL-UP Resistor.
	SET_Value(PORT_A, PIN_2, HIGH);

	// Making a variable to be used and incremented when pushing the button
	//u8 current_number = 0;

	u8 ones_seg = 0;
	u8 tens_seg = 0;

	// Setting a flag to handle the Debouncing Problem but it didn't worked and we will use a delay function instead.
	//u8 flag = 0;
	while(1){
		// A condition for a number to be incremented every time we push the button (pushing the button means it outputs a LOW value).
		// When we have clicked the button and realesed our hand the flag will be one and then we will continue our process.
		// Note: the flag method didn't worked and we changed the code to the delay method.
		//if(GET_Value(PORT_A, PIN_2) == LOW){
			// Outputing the value of the current number to the BCD.
			SET_Value_4LSP(PORT_C, ones_seg);
			SET_Value_4LSP(PORT_D, tens_seg);
			if(ones_seg == 9){
				ones_seg = 0;
				if(tens_seg == 9){
					tens_seg = 0;
				}else{
				tens_seg++;
				}
			}else{
			ones_seg++;
			}
		//}
		_delay_ms(300);

	}
	return 0;
}


