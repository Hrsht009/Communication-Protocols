#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;   // Structure to hold CAN message

MCP2515 mcp2515(10);       // MCP2515 uses SPI for communication, SS on pin 10

void setup() {
  Serial.begin(9600);                     // Initialize serial communication for debugging
  mcp2515.reset();                        // Reset the MCP2515 CAN controller
  mcp2515.setBitrate(CAN_500KBPS);        // Set CAN bus speed to 500 kbps
  mcp2515.setNormalMode();                // Put MCP2515 in normal operating mode
}

void loop() {
  canMsg.can_id = 0x036;                  // Set message ID
  canMsg.can_dlc = 1;                     // Set data length code to 1 byte
  canMsg.data[0] = 'H';                   // Set the data to be sent ('H')

  mcp2515.sendMessage(&canMsg);           // Send CAN message
  Serial.println("Message sent!");        // Notify that message was sent
  delay(1000);                            // Wait 1 second before sending again
}
