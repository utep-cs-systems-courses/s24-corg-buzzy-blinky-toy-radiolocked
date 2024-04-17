#include <msp430.h>
#include "switches.h"
#include "libTimer.h"
#include "led.h"
#include "stateMachines.h"

unsigned int secondCount;//seclare external global variables
unsigned int limit;
unsigned int buttonPressed;

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
  char p2val = P2IN;/* switch is in P2 */

  char sw_1 = (p2val & S1) ? 0 : S1;
  char sw_2 = (p2val & S2) ? 0 : S2;
  char sw_3 = (p2val & S3) ? 0 : S3;
  char sw_4 = (p2val & S4) ? 0 : S4;

  if(sw_1){
    state(1);
    buttonPressed = 1;
  }
  else if(sw_2){
    state(2);
    buttonPressed = 2;
  }
  else if(sw_3){
    state(3);
    buttonPressed = 3;
  }
  else if(sw_4){
    state(4);
    buttonPressed = 4;
  }
}
  
void wdt_init(){
  configureClocks();
  enableWDTInterrupts();
}

