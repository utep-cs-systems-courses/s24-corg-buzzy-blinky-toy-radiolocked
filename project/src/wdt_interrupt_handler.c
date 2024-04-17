#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void
__interrupt_vec(WDT_VECTOR) WDT()
{
  secondCount++;
  if(secondCount >= limit){
    secondCount = 0;
    P1OUT ^= LED_GREEN;
    P1OUT ^= LED_RED;
  }
}
