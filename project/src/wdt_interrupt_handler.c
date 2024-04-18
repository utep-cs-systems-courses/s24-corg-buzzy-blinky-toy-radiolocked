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
    secondCount = 0;
    P1OUT ^= LED_GREEN;
    P1OUT ^= LED_RED;
  }

  //speaker's behavior depends on leds
  if(P1OUT & LED_GREEN){
    sound = sound * 3;
  }else{
    sound = sound / 3;
  }

  if(P1OUT & LED_RED){
    sound = sound / 2;
  }else{
    sound = sound * 2;
  }

  buzzer_set_period(sound); //sound that plays depends on leds
}
