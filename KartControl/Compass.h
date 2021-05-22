#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

class Compass : Adafruit_HMC5883_Unified{
    public:

    Compass();
    void begin();
    float getHeading();

    private:
    
    static const float declinationAngle = 0.00116355;
};