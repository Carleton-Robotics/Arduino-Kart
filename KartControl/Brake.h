#include <Arduino.h>

class Brake {
private:
    int control1;
    int control2;
    int pot;
    static const int startOfTravelValue = 145;
    static const int endOfTravelValue = 520;
    int target;
    
public:
    int state;
    Brake(int controlPin1, int controlPin2, int potentiometerPin);

    int getState();
    void begin();
    int setTarget(int target);
    int update();
    void eStop();
};