
#ifndef ARDUINO_KART_SLIDEPOTENTIOMETER_H
#define ARDUINO_KART_SLIDEPOTENTIOMETER_H
#include <Arduino.h>

class SlidePotentiometer
{
public:
    int sensorValue;
    int brakeMin;
    int brakeMax;
    int currentPrecentage;
    int goal;

    SlidePotentiometer();

    int getValue();
};

#endif //ARDUINO_KART_SLIDEPOTENTIOMETER_H
