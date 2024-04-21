#ifndef buzzer_included
#define buzzer_included

//define notes for speaker
#define C4 3822    // C note
#define D4 3405    // D note
#define E4 3034    // E note
#define F4 2863    // F note
#define G4 2551    // G note
#define A4 2273    // A note
#define B4 2024    // B note

//Define the durations for each note (in milliseconds)
#define Q 500    // Quarter note
#define H 1000   // Half note
#define W 2000   // Whole note

void buzzer_init();
void buzzer_set_period(short cycles);
void delay(unsigned int milliseconds);
#endif //
