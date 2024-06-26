#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void main(void) 
{
  buzzer_init();
  wdt_init();
  switch_init();
  led_init();
  
  or_sr(0x18);  // CPU off, GIE on
} 
