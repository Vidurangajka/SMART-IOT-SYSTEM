#include "PlantWateringSystem.h"
#include "BlynkManager.h"

PlantWateringSystem system;
BlynkManager blynk;

void setup() {
    system.begin();
    blynk.begin();
}

void loop() {
    system.update();
    blynk.update();

    static unsigned long lastSend = 0;
    if (millis() - lastSend > 5000) {
        float temp = 0, humi = 0;
        int moist = system.getMoisturePercent();
        blynk.sendSensorData(moist, temp, humi);
        lastSend = millis();
    }
}
