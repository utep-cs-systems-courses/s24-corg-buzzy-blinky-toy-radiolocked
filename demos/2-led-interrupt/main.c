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
  static int toggle = 0; //keep track of led state

  if(toggle == 0){
    P1OUT |= LED_GREEN; //turn on led
    toggle = 1; //update LED state
  }else{
    P1OUT &= ~LED_GREEN; //turn off led
    toggle = 0; //update LED state
  }
}

