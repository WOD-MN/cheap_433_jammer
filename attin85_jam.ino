#include <avr/io.h>
#include <avr/interrupt.h>

#define BUZZER_PIN PB0 // Define buzzer pin on ATtiny85

void setup() {
  // Set BUZZER_PIN as output
  DDRB |= (1 << BUZZER_PIN);
  
  // Configure Timer1 for generating tone at 500 Hz
  TCCR1 = 0;                        // Clear control register
  GTCCR = 0;                        // Clear GTCCR register
  TCCR1 |= (1 << CTC1);             // Enable Clear Timer on Compare Match
  TCCR1 |= (1 << CS12) | (1 << CS11); // Set prescaler to 64
  OCR1C = 249;                      // Set compare match value for 500 Hz
  TIMSK |= (1 << OCIE1A);           // Enable compare match interrupt
  sei();                            // Enable global interrupts
}

ISR(TIMER1_COMPA_vect) {
  // Toggle buzzer pin
  PINB |= (1 << BUZZER_PIN);
}

void loop() {
  // Main loop does nothing; frequency is managed by Timer1
}
