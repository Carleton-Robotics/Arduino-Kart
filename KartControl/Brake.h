#include <Arduino.h>

class Brake {
private:
    int control1;
    int control2;
    int pot;
    int powerPin;
    static const int endOfTravelValue = 817;
    static const int startOfTravelValue = 415;
public:
    int state;
    Brake(int controlPin1,int controlPin2, int potentiometerPin, int powerPin);

    void begin();
    void updateReading();
    void updateCommand(int target);
    void eStop();
};