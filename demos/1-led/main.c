//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include <stdio.h>

int main(void) {
  P1DIR |= LEDS; //sets the direction of port 1 to LEDS
  //original demo code
  //P1OUT &= ~LED_GREEN; //&=~ will always set all bits to 0 (so LED is being turned off)
  //P1OUT |= LED_RED; //LED is being turned on

  //modified code to turn both leds on
  P1OUT |= LED_GREEN;
  P1OUT |= LED_RED;
  or_sr(0x18);		/* CPU off, GIE on */
}
