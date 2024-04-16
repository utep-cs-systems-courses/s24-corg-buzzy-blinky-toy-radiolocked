#ifndef switches_included
#define switches_included

#define S1 BIT0 //switch is p2.0
#define S2 BIT1 //switch is in p2.1
#define S3 BIT2 //switch is in p2.2
#define S4 BIT3 //switch is in p2.3
#define SWITCHES (S1 | S2 | S3 | S4)//only 1 switch on this board

extern int limit;
extern int secondCount;

void switch_init();
void switch_interrupt_handler();
void wdt_init();

#endif //included
