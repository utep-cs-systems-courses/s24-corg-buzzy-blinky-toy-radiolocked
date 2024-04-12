#include <msp430.h>
#include "switches.h"
#include "led.h"

void
switch_init()
{
  P2REN |= SWITCHES;/* enables resistors for switches */
  P2IE |= SWITCHES;/* enable interrupts from switches */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */
}

void     //this is what defines what the button does
switch_interrupt_handler()
{
  char p2val = P2IN; //switch is in p2
  
  /* update switch interrupt sense to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */

  /* up=red, down=green */
  if (p2val & S1) {
    if(!(P1OUT & LEDS)){//this line checks if both leds is off
      P1OUT |= LED_GREEN;//if both lights are of (the start) only turn on the green led
    }else{//once one led is on, then the button makes them alternate
      P1OUT ^= LEDS;
    }
  }
}
