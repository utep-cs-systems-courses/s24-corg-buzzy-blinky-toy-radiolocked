#include <msp430.h>
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT()
{
  extern unsigned int secondCount; //declare external variables
  extern unsigned int limit;

  secondCount++;
  if(secondCount >= limit){
    secondCount = 0;
    P1OUT ^= LED_GREEN;
    P1OUT ^= LED_RED;
}
