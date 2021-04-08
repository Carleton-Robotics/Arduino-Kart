
#ifndef ARDUINO_KART_THROTTLE_H
#define ARDUINO_KART_THROTTLE_H

#include <Arduino.h>
#include "MCP45HVX1.h"

class Throttle {
private:
    MCP45HVX1 digiPot;
    int switchPin;

public:
    int state;
    Throttle(int switchPin);

    void updateCommand(int val);
    void updateReading();
    void throttleEStop();
};
#endif //ARDUINO_KART_THROTTLE_H
