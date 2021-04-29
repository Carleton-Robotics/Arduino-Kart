#include <Arduino.h>

class Odometer{
  private:
    bool toothPresent; 
    float interval;
    unsigned long updateTime; //NOTE: potential for overflow after ~20 days
    unsigned long count; //Note: potential for overflow after ~2billion teeth are read
    float tps;
    float rpm;
    float ipm;
    int hallValue;
    int pin;
    int powerPin;

    static const int interval = 1; //Seconds between updates
    static const float pi = 3.1415926535897932384626433832795;
    static const float ODOMETER_MIN_VALUE = 0;
    static const float ODOMETER_MAX_VALUE = 500;

  public:
    float state;
    Odometer(int pin, int powerPin);
    void begin();

    void updateReading();
    float getFloatValue();
    char getValue();
};