#include "Compass.h"

Compass::Compass() : Adafruit_HMC5883_Unified(12345){

};
void Compass::begin(){
    Adafruit_HMC5883_Unified::begin();
};
float Compass::getHeading(){
    sensors_event_t event;
    Adafruit_HMC5883_Unified::getEvent(&event);
    float heading = atan2(event.magnetic.y, event.magnetic.x);
    heading += declinationAngle;

    if(heading < 0 ) heading += 2*PI;
    if(heading > 2*PI) heading -= 2*PI;

    float headingDegrees = heading * 180/PI;

    return headingDegrees;
};
