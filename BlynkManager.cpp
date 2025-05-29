#include "BlynkManager.h"
#include <WiFi.h>

void BlynkManager::begin() {
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void BlynkManager::update() {
    Blynk.run();
}

void BlynkManager::sendSensorData(int moisture, float temp, float humi) {
    Blynk.virtualWrite(V0, moisture);
    Blynk.virtualWrite(V1, temp);
    Blynk.virtualWrite(V2, humi);
}
