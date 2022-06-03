#pragma once

#include <Arduino.h>
#include <MCP45HVX1.h>

class Throttle {
private:
    MCP45HVX1 digiPot;
    int switchPin;

    int MINSPEED = 0;
    int MAXSPEED = 0;

public:
    Throttle(int switchPin);
    void begin();

    void setSpeed(int val);
    void setSpeedMPS(int val);
    void eStop();
};