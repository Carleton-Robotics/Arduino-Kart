#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

class Compass : Adafruit_HMC5883_Unified{
    public:

    Compass();
    void begin();
    int getHeading();
    int getAngle();
    void update();

    private:
    
    int heading;
    int previousHeading;
    int totalAngle;

    int getDifference(int current, int previous);
};