#include <Arduino.h>
#include <QMC5883LCompass.h>

class Compass : QMC5883LCompass{
    public:
    Compass();
    void begin();
    int getAzimuth();
};