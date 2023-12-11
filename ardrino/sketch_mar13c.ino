// Define the LDR and potentiometer pins
const int LDR_PIN = A0;
const int POT_PIN = A1;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the values of the LDR and potentiometer
  int ldrValue = analogRead(LDR_PIN);
  int potValue = analogRead(POT_PIN);

  // Send the values to the serial monitor as a single string separated by a comma
  Serial.print(ldrValue);
  Serial.print(",");
  Serial.println(potValue);

  // Delay for a short period of time to avoid reading the sensors too frequently
  delay(100);
}
