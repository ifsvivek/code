// Pin number for the TX LED
const int txLedPin = 3;

void setup() {
  // Set the TX LED pin as an output
  pinMode(txLedPin, OUTPUT);
}

void loop() {
  // Turn on the TX LED
  digitalWrite(txLedPin, HIGH);
  
  // Delay for 500 milliseconds (half a second)
  delay(500);
  
  // Turn off the TX LED
  digitalWrite(txLedPin, LOW);
  
  // Delay for 500 milliseconds
  delay(500);
}
