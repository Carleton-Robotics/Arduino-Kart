#include "Odometer.h"
#include <Arduino.h>

Odometer::Odometer(int pin): pin(pin){
    toothPresent = false;
    count = 0;
    totalCount = 0;
    previousTime = 0;
}
void Odometer::begin(){
    pinMode(pin, INPUT_PULLUP);
    countTick();
}
void Odometer::countTick(){
    totalCount += 1;
    count += 1;
}
void Odometer::update() {
    updateSpeed(count);
    count = 0;
}
double Odometer::getDistance() {
    return totalCount * distanceConversionFactor;
}
double Odometer::getDistanceT() {
    return totalCount;
}
void Odometer::updateSpeed(int ticks) {
    unsigned long currentTime = micros();
    long deltaTime = currentTime - previousTime;
    double speedWeight = deltaTime / timeConstant;
    speed = (1 - speedWeight) * speed + speedWeight * ticks / deltaTime;
    previousTime = currentTime;
}
double Odometer::getSpeed(){
    return speed * speedConversionFactor;
}
double Odometer::getSpeedTPMS(){
    return speed;
}