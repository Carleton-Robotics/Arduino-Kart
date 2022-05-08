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
    xVal = event.magnetic.x;
    yVal = event.magnetic.y;

    totalAngle += getDifference(heading, previousHeading);

    previousHeading = heading;
};
float Compass::getX(){
    return xVal + xOffset;
}
float Compass::getY(){
    return yVal + yOffset;
}
int Compass::getHeading(){
    return heading;
};
int Compass::getAngle(){
    return totalAngle;
};