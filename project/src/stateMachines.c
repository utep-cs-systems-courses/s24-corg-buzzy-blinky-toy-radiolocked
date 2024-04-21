#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "libTimer.h"
#include "buzzer.h"

void song1(){
  buzzer_set_period(G4); delay(Q);
  buzzer_set_period(G4); delay(Q);
  buzzer_set_period(A4); delay(Q);
  buzzer_set_period(A4); delay(Q);
  buzzer_set_period(B4); delay(Q);
  buzzer_set_period(B4); delay(Q);
  buzzer_set_period(A4); delay(Q);
  buzzer_set_period(F4); delay(Q);
  buzzer_set_period(F4); delay(Q);
  buzzer_set_period(F4); delay(Q);
  buzzer_set_period(E4); delay(Q);
  buzzer_set_period(E4); delay(Q);
  buzzer_set_period(D4); delay(Q);
  buzzer_set_period(D4); delay(Q);
  buzzer_set_period(C4); delay(Q);
  //small delay before ending
  delay(Q);

  //turn off the sound;
  buzzer_set_period(0);
}

void state(int n){
  switch(n){//if S buttons are pressed
  case 1:
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
    limit = -1;
    song1();
    break;

  case 2:
    P1OUT |= LED_RED;
    P1OUT &= ~LED_GREEN;
    limit = -1;
    break;
    
  case 3:
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
    limit = 125; //leds will XOR all the time to simulate a siren
    break;

  case 4: // button to do nothing
    P1OUT &= ~LEDS;
    limit = -1; //leds will be off all the time and no sound will play
    break;

  default:
    break;
    }
}
