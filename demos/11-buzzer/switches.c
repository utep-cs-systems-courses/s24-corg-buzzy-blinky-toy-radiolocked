#include <msp430.h>
#include "switches.h"
#include "buzzer.h"

void switch_init()
{
  P1REN |= SWITCHES;/* enables resistors for switches */
  P1IE |= SWITCHES;/* enable interrupts from switches */
  P1OUT |= SWITCHES;/* pull-ups for switches */
  P1DIR &= ~SWITCHES;/* set switches' bits for input */
}

//define what the button at p1.3 does
void
switch_interrupt_handler()
{
  char p1val = P1IN; //switch is in p1

  /* update switch interrupt sense to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);/* if switch down, sense up */
  
  //up=red, down=green
  if(p1val & SW1){
    buzzer_set_period(1000); //2/1000
  }else{
    buzzer_set_period(2000); //2/2000
  }
}
