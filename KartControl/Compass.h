#include <Arduino.h>
#include <Wire.h>
//#include <Adafruit_Sensor.h>
//#include <Adafruit_HMC5883_U.h>

class Compass : Adafruit_HMC5883_Unified{
    public:

    Compass();
    void begin();

    int getHeading(); //Not Calibrated
    int getAngle(); //Not Calibrated

    void update(); //Must be called to get new data

    float getX(); //Accurate
    float getY(); //Accurate

    private:
    
    int heading;
    int previousHeading;
    int totalAngle;

    float xVal;
    float yVal;

    float xOffset = 3.135;
    float yOffset = 39.32;
};
