#ifndef PLANT_WATERING_SYSTEM_H
#define PLANT_WATERING_SYSTEM_H

#include <Adafruit_SSD1306.h>
#include "config.h"

class PlantWateringSystem {
public:
    PlantWateringSystem();
    void begin();
    void update();
    int getMoisturePercent();

private:
    void readSensors();
    void controlRelay();
    void updateDisplay();

    int moisturePercent;
    Adafruit_SSD1306 display;
};

#endif
