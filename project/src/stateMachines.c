#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "libTimer.h"
#include "buzzer.h"

void state(int n){
  switch(n){
  case 1:
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
    break;

  case 2:
    P1OUT &= ~LEDS;
    break;
    
  case 3:
    if(limit < 125){
      limit = limit + 25;
    }
    break;

  case 4:
    if(limit > 25){
    limit = limit - 25;
    }
    break;

  default:
    break;
    }
}
