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
  delay(W);

  //turn off the sound;
  buzzer_set_period(0);
}

void song2(){
  buzzer_set_period(C4); delay(Q);
  buzzer_set_period(D4); delay(Q);
  buzzer_set_period(D4); delay(Q);
  buzzer_set_period(E4); delay(Q);
  buzzer_set_period(E4); delay(Q);
  buzzer_set_period(F4); delay(Q);
  buzzer_set_period(F4); delay(Q);
  buzzer_set_period(F4); delay(Q);
  buzzer_set_period(A4); delay(Q);
  buzzer_set_period(B4); delay(Q);
  buzzer_set_period(B4); delay(Q);
  buzzer_set_period(A4); delay(Q);
  buzzer_set_period(A4); delay(Q);
  buzzer_set_period(G4); delay(Q);
  buzzer_set_period(G4); delay(Q);
  //small delay before ending
  delay(W);

  //turn off the sound;
  buzzer_set_period(0);
}

void siren(){
  buzzer_set_period(G4);
  delay(W);
  P1OUT ^= LEDS;
  //siren being silly
  buzzer_set_period(C4);
  delay(W);
  P1OUT ^= LEDS;
}

void silly(){
  buzzer_set_period(A4);
  P1OUT ^= LEDS;
  delay(W);
  delay(W);
  buzzer_set_period(0);
  P1OUT ^= LEDS;
  delay(W);
  delay(W);
  buzzer_set_period(A4);
  P1OUT ^= LEDS;
  delay(W);
  delay(W);
  buzzer_set_period(0);
  P1OUT ^= LEDS;
}

void state(int n){
  switch(n){//if S buttons are pressed
  case 1://button for song forwards
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
    limit = -1;
    song1();
    break;

  case 2://button for song backwards
    P1OUT |= LED_RED;
    P1OUT &= ~LED_GREEN;
    limit = -1;
    song2();
    break;
    
  case 3://button for siren
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
    int i = 0;
    while(i < 6){
      siren();
      i = i + 1;
    }
    delay(W);
    buzzer_set_period(0);
    break;

  case 4: // button to do silly noise
    silly();
    break;

  default:
    break;
    }
}
