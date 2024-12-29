#define RECEIVER_PIN 11 // Data pin of the 433 MHz receiver

void setup() {
  pinMode(RECEIVER_PIN, INPUT); // Set RECEIVER_PIN as input
  Serial.begin(9600);          // Initialize serial communication at 9600 baud
}

void loop() {
  int signal = digitalRead(RECEIVER_PIN); // Read the signal from the receiver
  Serial.println(signal);                // Print the signal (HIGH or LOW) to the serial monitor
  delay(10);                             // Small delay to make output readable
}
