#include <Arduino.h>
#include <MCP45HVX1.h>

class Throttle {
private:
    MCP45HVX1 digiPot;
    int switchPin;

public:
    Throttle(int switchPin);
    void begin();

    void setSpeed(int val);
    void eStop();
};