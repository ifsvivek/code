// Define the LDR pin
const int LDR_PIN = A0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the value of the LDR sensor
  int ldrValue = analogRead(LDR_PIN);

  // Print the value of the LDR sensor to the serial monitor
  Serial.println(ldrValue);

  // Delay for a short period of time to avoid reading the sensor too frequently
  delay(100);
}