#include <Arduino.h>

class Odometer{
  private:
    bool toothPresent; 
    float interval;
    unsigned long updateTime; //NOTE: potential for overflow after ~20 days
    unsigned long count; //Note: potential for overflow after ~2billion teeth are read
    float pi;
    float tps;
    float rpm;
    float ipm;
    int hallValue;
    int pin;

    static const float ODOMETER_MIN_VALUE = 0;
    static const float ODOMETER_MAX_VALUE = 500;

  public:
    float state;
    Odometer(int pin);

    void updateReading();
    float getFloatValue();
    char getValue();
};