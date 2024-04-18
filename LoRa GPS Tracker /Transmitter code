#include <SoftwareSerial.h>
#include <RH_RF95.h>  // Include the RadioHead library
// Define the pins for software serial communication
int RXPin = 3;
int TXPin = 4;
// Create a SoftwareSerial object for GPS communication
SoftwareSerial GPS(RXPin, TXPin);
// SX1278 (RA02) LoRa configuration
#define RFM95_CS 10
#define RFM95_RST 9
#define RFM95_INT 2
#define RF95_FREQ 433.0 // Frequency in MHz for SX1278
RH_RF95 rf95(RFM95_CS, RFM95_INT);
void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  // Initialize software serial communication with GPS module
  GPS.begin(9600);
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
  // Read GPS data if available
  if (!GPS.available()){
    Serial.println("GPS not available");
  }
  // After receiving a complete NMEA sentence, parse it to extract latitude and longitude
  if (GPS.available() > 0 && GPS.find("$GPGGA")) {
     // Extract latitude and longitude
    String bad1 = GPS.readStringUntil(','); // Latitude comes first
    GPS.readStringUntil(','); // Skip other data fields until longitude
    double latitude = GPS.readStringUntil(',').toDouble()/100;
    char Buffer1[20];
    dtostrf(latitude, 6, 2, Buffer1);
    String Latitude = String(Buffer1);
    bad1 = GPS.readStringUntil(',');
    double longitude = GPS.readStringUntil(',').toDouble()/100;
    char Buffer2[20];
    dtostrf(longitude, 6, 2, Buffer2);
    String Longitude = String(Buffer2);
    // Print latitude and longitude
    Serial.print("Latitude: ");
    Serial.println(latitude);
    Serial.print("Longitude: ");
    Serial.println(longitude);
    // Create Google Maps link
    String googleMapsLink ="https://www.latlong.net/c/?lat=" + Latitude + "&long=" + Longitude ;
    // Print the Google Maps link
    Serial.println("Google Maps Link: ");
    Serial.println(googleMapsLink);
    // Convert the Google Maps link to a char array
    char packet[googleMapsLink.length() + 1];
    googleMapsLink.toCharArray(packet, googleMapsLink.length() + 1);
    // Send the packet via LoRa
    rf95.send((uint8_t *)packet, strlen(packet));
    rf95.waitPacketSent();
    Serial.println("Packet sent!");
  }
}

