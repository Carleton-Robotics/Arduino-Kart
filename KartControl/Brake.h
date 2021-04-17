#include <Arduino.h>

class Brake {
private:
    int control1;
    int control2;
    int pot;
    int endOfTravelValue;
    int startOfTravelValue;
public:
    int state;
    Brake(int controlPin1,int controlPin2, int potentiometerPin);

    void updateReading();
    void updateCommand(int target);
};