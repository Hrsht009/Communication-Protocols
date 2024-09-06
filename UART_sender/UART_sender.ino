void setup() {
  Serial.begin(9600);        // Initialize serial communication at 9600 baud rate
}

void loop() {
  if (Serial.available() > 0) {           // Check if data is available from master
    String receivedData = Serial.readString();  // Read the incoming data as a string
    Serial.print("Received: ");
    Serial.println(receivedData);              // Print the received data
  }
}
