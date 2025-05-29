#include "PlantWateringSystem.h"
#include <Adafruit_GFX.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

DHT dht(dhtPin, DHT11);

PlantWateringSystem::PlantWateringSystem()
    : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET) {}

void PlantWateringSystem::begin() {
    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin, HIGH);

    dht.begin();
    display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("System Init");
    display.display();
}

void PlantWateringSystem::update() {
    readSensors();
    controlRelay();
    updateDisplay();
}

int PlantWateringSystem::getMoisturePercent() {
    return moisturePercent;
}

void PlantWateringSystem::readSensors() {
    int sensorValue = analogRead(moisturePin);
    moisturePercent = map(sensorValue, drySoilVal, wetSoilVal, 0, 100);
    moisturePercent = constrain(moisturePercent, 0, 100);
}

void PlantWateringSystem::controlRelay() {
    if (moisturePercent < moistPerLow) {
        digitalWrite(relayPin, LOW);  // turn pump on
    } else if (moisturePercent > moistPerHigh) {
        digitalWrite(relayPin, HIGH); // turn pump off
    }
}

void PlantWateringSystem::updateDisplay() {
    float t = dht.readTemperature();
    float h = dht.readHumidity();

    display.clearDisplay();
    display.setCursor(0, 0);
    display.printf("Temp: %.1f C\n", t);
    display.printf("Humi: %.1f %%\n", h);
    display.printf("Soil: %d %%\n", moisturePercent);
    display.display();
}
