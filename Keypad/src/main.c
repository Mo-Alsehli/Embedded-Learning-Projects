#include "BIT_OP.h"
#include "STD_types.h"
#include "DIO_interface.h"
#include "Keypad_Interface.h"
#include "LCD_Interface.h"


int main() {
  // Setting Directions for input and output pins
  SET_Direction_4LSP(PORT_A, OUTPUT);
  SET_Direction_4LSP(PORT_B, INPUT);
  // Activating pull up resistor for all the Input pins
  // Note: HIGH means only 1 for 1bit so we have to make it 0b00001111 or 0x0F.
  SET_Value_4LSP(PORT_B, 0x0F);
  // Setting the output pins to output high
  SET_Value_4LSP(PORT_A, 0x0F);

  // Initializing LCD PINS
  SET_Direction(PORT_C, PIN_0, OUTPUT);
  SET_Direction(PORT_C, PIN_1, OUTPUT);
  SET_Direction(PORT_C, PIN_2, OUTPUT);
  SET_Direction_4MSP(PORT_C, OUTPUT);
  LCD_Init();
  u8 key;

  while(1){
    key = Keypad_Getkey();
    if(key != 'u'){
      LCD_SendData_4bitMode(key);
    }else{
      
    }
  }
  return 0;
}