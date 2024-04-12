#ifndef switches_included
#define switches_included

#define S1 BIT0 //switch is p1.3
#define SWITCHES S1 //only 1 switch on this board

void switch_init();
void switch_interrupt_handler();

#endif //included
