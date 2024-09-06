#include <SPI.h>

volatile byte receivedValue;  // Stores the received byte from master

void setup() {
  pinMode(MISO, OUTPUT);      // Set MISO pin as output for data sent to master
  SPI.begin();                // Initialize SPI in slave mode
  SPI.attachInterrupt();      // Enable SPI interrupt to handle incoming data
  Serial.begin(9600);         // Initialize serial communication for debugging
}

ISR(SPI_STC_vect) {           // SPI interrupt service routine (ISR)
  receivedValue = SPDR;       // SPDR holds the byte sent from the master
}

void loop() {
  Serial.print("Received: ");
  Serial.println((char)receivedValue);  // Print the received byte from the master
  delay(500);                           // Short delay for readability
}
