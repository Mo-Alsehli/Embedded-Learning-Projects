#include "DIO_interface.h"
#include "STD_types.h"
#include <util/delay.h>




int main() {
  SET_Direction(PORT_C, PIN_0, OUTPUT);
  SET_Direction(PORT_C, PIN_1, OUTPUT);

  while(1){
    SET_Value(PORT_C, PIN_0, HIGH);
    SET_Value(PORT_C, PIN_1, LOW);
    _delay_ms(2000);
    SET_Value(PORT_C, PIN_0, LOW);
    SET_Value(PORT_C, PIN_1, LOW);
    _delay_ms(500);
    SET_Value(PORT_C, PIN_0, LOW);
    SET_Value(PORT_C, PIN_1, HIGH);
    _delay_ms(2000);
  }
  return 0;
}