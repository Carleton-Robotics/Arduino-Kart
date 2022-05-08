#include "Compass.h"

Compass::Compass() : Adafruit_HMC5883_Unified(12345){

};
void Compass::begin(){
    Adafruit_HMC5883_Unified::begin();
    sensors_event_t event;
    Adafruit_HMC5883_Unified::getEvent(&event);
};
void Compass::update(){
    sensors_event_t event;
    Adafruit_HMC5883_Unified::getEvent(&event);
    xVal = event.magnetic.x;
    yVal = event.magnetic.y;
};
float Compass::getX(){
    return xVal + xOffset;
}
float Compass::getY(){
    return yVal + yOffset;
}
float Compass::getHeading(){
    return atan2(yVal, xVal) * RAD_TO_DEG;
};