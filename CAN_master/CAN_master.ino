#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;   // Structure to hold received CAN message

MCP2515 mcp2515(10);       // MCP2515 uses SPI for communication, SS on pin 10

void setup() {
  Serial.begin(9600);                     // Initialize serial communication for debugging
  mcp2515.reset();                        // Reset the MCP2515 CAN controller
  mcp2515.setBitrate(CAN_500KBPS);        // Set CAN bus speed to 500 kbps
  mcp2515.setNormalMode();                // Put MCP2515 in normal operating mode
}

void loop() {
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {  // Check if message is received
    Serial.print("Received: ");
    Serial.println((char)canMsg.data[0]);                   // Print received data
  }
}
