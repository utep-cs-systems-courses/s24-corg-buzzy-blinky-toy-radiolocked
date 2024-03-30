//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;           //set port 1 direction to LEDS
  P1OUT |= LED_GREEN;     //turn on green led
  P1OUT &= ~LED_RED;        //turn off red led

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);		/* CPU off, GIE on */
}


void __interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{//will turn green led on and off (will appear dimmer)
  P1OUT ^= LED_GREEN;
}
