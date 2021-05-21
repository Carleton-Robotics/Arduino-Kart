#include <Arduino.h>
#include "Compass.h"

Compass::Compass() : QMC5883LCompass(){

};

void Compass::begin(){
    QMC5883LCompass::init();
}

int Compass::getAzimuth(){
    QMC5883LCompass::read();
    return QMC5883LCompass::getAzimuth();
}