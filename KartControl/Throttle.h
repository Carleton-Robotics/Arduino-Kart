#include <Arduino.h>
#include <MCP45HVX1.h>

class Throttle {
private:
    MCP45HVX1 digiPot;
    int switchPin;
    int powerPin;
    int state;

public:
    Throttle(int switchPin, int powerPin);
    void begin();

    void updateCommand(int val);
    void updateReading();
    void eStop();
};