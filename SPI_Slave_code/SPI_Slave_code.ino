void setup() {
  Serial.begin(9600);        // Initialize serial communication at 9600 baud rate
}

void loop() {
  Serial.println("Hello from Master!");  // Send data to slave via TX pin
  delay(1000);                           // Wait for 1 second before sending again
}
