//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

#define SW1 BIT3       //bit3 is the button at p1.3
#define SWITCHES SW1   //to control all the switches used by the board

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */

  P1REN |= SWITCHES;/* enables resistors for switches */
  P1IE |= SWITCHES;/* enable interrupts from switches */
  P1OUT |= SWITCHES;/* pull-ups for switches */
  P1DIR &= ~SWITCHES;/* set switches' bits for input */
  
  or_sr(0x18);			/* CPU off, GIE on */
}

// global state var to count time
int secondCount = 0;
//global state var to set the limit on the time
int limit = 250;

void
switch_interrupt_handler()
{
  char p1val = P1IN; //switch is in P1

  /* update switch interrupt sense to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);/* if switch down, sense up */

  //Button to increase speed
  if (p1val & SW1) {
    if(limit > 50){
      limit = limit / 2;
    }else{
      limit = 250;
    }
  }
}

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  secondCount ++;
  if (secondCount >= limit) { 	/* once each half sec... */
    secondCount = 0;
    P1OUT ^= LED_GREEN; //both leds will alternate in turning on
    P1OUT ^= LED_RED; //red start on, green starts off
  }
}

/*1 (S2) */
void
__interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & SWITCHES) {      /* did a button cause this interrupt? */
    P1IFG &= ~SWITCHES;      /* clear pending sw interrupts */
    switch_interrupt_handler();/* single handler for all switches */
  }
 }
