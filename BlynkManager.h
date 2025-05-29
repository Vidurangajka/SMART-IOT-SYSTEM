#ifndef BLYNK_MANAGER_H
#define BLYNK_MANAGER_H

#include <BlynkSimpleEsp32.h>
#include "config.h"

class BlynkManager {
public:
    void begin();
    void update();
    void sendSensorData(int moisture, float temp, float humi);
};

#endif
