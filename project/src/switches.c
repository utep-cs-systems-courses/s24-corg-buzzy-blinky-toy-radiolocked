#include <msp430.h>
#include "switches.h"
#include "libTimer.h"
#include "led.h"

//global state variables that control blinking
int blinkLimit = 0;
int blinkCount = 0;
int secondCount = 0;
int buttonPressed = -1;

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
    buttonPressed = 0;
    if(!(P1OUT & LEDS)){//this line checks if both leds is off
      P1OUT |= LED_GREEN;//if both lights are of (the start) only turn on the green led
    }else{//once one led is on, then the button makes them alternate
      P1OUT ^= LEDS;
    }
  }
  if(p2val & S2){
    buttonPressed = 1;
    blinkLimit--;
  }
}

//Pattens for leds blinking
void
__interrupt_vec(WDT_VECTOR) WDT()/* 250 interrupts/sec */
{
  if(buttonPressed == 1){
    blinkCount++;
    if(blinkCount >= blinkLimit){
      blinkCount = 0;
      P1OUT ^= LED_GREEN;
    }else{
      P1OUT ^= LED_GREEN;
    }

    //measure half a second
    secondCount++;
    if(secondCount >= 125){
      secondCount = 0;
      if(blinkLimit <= 0){//set limit to duty cycle
	blinkLimit = 5;
      }
    }
  }
}
