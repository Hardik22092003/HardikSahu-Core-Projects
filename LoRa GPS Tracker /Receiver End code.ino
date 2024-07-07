#include <RH_RF95.h>  // Include the RadioHead library
// SX1278 (RA02) LoRa configuration
#define RFM95_CS 15
#define RFM95_RST 16
#define RFM95_INT 4
#define RF95_FREQ 433.0 // Frequency in MHz for SX1278
RH_RF95 rf95(RFM95_CS, RFM95_INT);
void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  // Initialize SX1278 LoRa module
  if (!rf95.init()) {
    Serial.println("LoRa init failed!");
    while (1);
  }
  Serial.println("LoRa init OK!");
  // Setup LoRa frequency
  rf95.setFrequency(RF95_FREQ);
  Serial.print("Frequency set to: ");
  Serial.print(RF95_FREQ);
  Serial.println(" MHz");
}
void loop() {
  if (rf95.available()) {
    // Buffer to store received message
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    // Check if a message was received
    if (rf95.recv(buf, &len)) {
      // Message received successfully, print it
      Serial.print("Received packet: ");
      Serial.println((char*)buf);
    } else {
      // Receive failed
      Serial.println("Receive failed");
    }
  }
}

