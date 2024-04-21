#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"

short sound = 1000; //start the sound to play
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  secondCount++;
  if(secondCount >= limit){
    secondCount = 0; //will be XORing the leds until limit is reached
    P1OUT ^= LEDS;
  }
}
