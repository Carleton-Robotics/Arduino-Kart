
#ifndef ARDUINO_KART_ODOMETER_H
#define ARDUINO_KART_ODOMETER_H
#include <Arduino.h>

class Odometer
{
  
  private:
    bool toothPresent; 
    float interval;
    long updateTime;//NOTE: potential for overflow after ~20 days
    long count;//Note: potential for overflow after ~2billion teeth are read
    float pi;
    float tps;
    float rpm;
    float ipm;
    int hallValue;
    int pin;
  public:
    float state;
    Odometer(int pin);

    void updateReading();
};

#endif //ARDUINO_KART_ODOMETER_H
