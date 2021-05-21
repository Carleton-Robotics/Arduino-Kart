#include <Arduino.h>
#include <MCP45HVX1.h>

class Throttle {
private:
    MCP45HVX1 digiPot;
    int switchPin;
    int state;

public:
    Throttle(int switchPin);
    void begin();

    void updateCommand(int val);
    void updateReading();
    void eStop();
};