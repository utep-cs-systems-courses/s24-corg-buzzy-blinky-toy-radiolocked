#ifndef led_included
#define led_included

#include <msp430.h>

#define LED_RED BIT6 //P1.6
#define LED_GREEN BIT0 //P1.0
#define LEDS (BIT0 | BIT6) //control both leds

void led_init();

#endif //included
