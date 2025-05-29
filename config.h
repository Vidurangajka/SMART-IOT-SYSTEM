#ifndef CONFIG_H
#define CONFIG_H

// Blynk Template and Auth
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

// WiFi credentials
const char* ssid = ""; // WiFi SSID
const char* pass = ""; // WiFi Password

// Moisture sensor calibration values
const int wetSoilVal = 930;   // Min value when soil is wet
const int drySoilVal = 3000;  // Max value when soil is dry

// Ideal moisture range percentage
const int moistPerLow = 20;
const int moistPerHigh = 80;

// Pin definitions
const int relayPin = 5;
const int moisturePin = 34;
const int dhtPin = 4;

#endif
