#include <msp430.h>
#include "switches.h"
#include "led.h"

void
switch_init()
{
  P1REN |= SWITCHES;/* enables resistors for switches */
  P1IE |= SWITCHES;/* enable interrupts from switches */
  P1OUT |= SWITCHES;/* pull-ups for switches */
  P1DIR &= ~SWITCHES;/* set switches' bits for input */
}

void     //this is what defines what the button does
switch_interrupt_handler()
{
  char p1val = P1IN; //switch is in p1
  
  /* update switch interrupt sense to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);/* if switch down, sense up */

  /* up=red, down=green */
  if (p1val & SW1) {
    if(!(P1OUT & LEDS)){//this line checks if both leds is off
      P1OUT |= LED_GREEN;//if both lights are of (the start) only turn on the green led
    }else{//once one led is on, then the button makes them alternate
      P1OUT ^= LEDS;
    }
  }
}
