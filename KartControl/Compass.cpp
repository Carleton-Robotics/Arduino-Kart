#include "Compass.h"

Compass::Compass() : Adafruit_HMC5883_Unified(12345){
    totalAngle = 0;
};
void Compass::begin(){
    Adafruit_HMC5883_Unified::begin();
    sensors_event_t event;
    Adafruit_HMC5883_Unified::getEvent(&event);
    previousHeading = atan2(event.magnetic.y, event.magnetic.x) * 180/PI;
};
void Compass::update(){
    sensors_event_t event;
    Adafruit_HMC5883_Unified::getEvent(&event);
    heading = atan2(event.magnetic.y, event.magnetic.x) * 180/PI;

    totalAngle += getDifference(heading, previousHeading);

    previousHeading = heading;
};
int Compass::getHeading(){
    return heading;
};
int Compass::getAngle(){
    return totalAngle;
};
int Compass::getDifference(int current, int previous){
    if(previous - current > 180){
        return current + 360 - previous;
    }
    else if(current - previous > 180){
        return previous + 360 - current;
    }
    else{
        return current - previous;
    }
}