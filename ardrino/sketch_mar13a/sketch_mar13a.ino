int ldrPin = 2; // LDR connected to pin D2
int ldrValue = 0; // variable to store the LDR value

void setup() {
  Serial.begin(9600); // start serial communication at 9600 baud
}

void loop() {
  ldrValue = analogRead(ldrPin); // read the analog value of the LDR
  Serial.println(ldrValue); // send the value to the serial port
  delay(500); // wait for half a second
}
