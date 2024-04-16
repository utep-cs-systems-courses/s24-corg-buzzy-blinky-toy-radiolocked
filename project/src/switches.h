#ifndef switches_included
#define switches_included

#define S1 BIT0 //switch is p2.0
#define S2 BIT1 //switch is in p2.1
#define SWITCHES (S1 | S2)//only 1 switch on this board

void switch_init();
void switch_interrupt_handler();

#endif //included
