#include "Odometer.h"
#include <Arduino.h>

Odometer::Odometer(int pin): pin(pin){
    toothPresent = false;
    count = 0;
}

void Odometer::begin(){
    pinMode(pin, INPUT_PULLUP);
}

void Odometer::update() {
    int hallValue = digitalRead(pin);
    if (toothPresent == false && hallValue == 0) {
        toothPresent = true;
        updateSpeed(1);
        count += 1;
    }
    else if (toothPresent == true && hallValue == 1) {
        toothPresent = false;
        updateSpeed(0);
    }
    else{
        updateSpeed(0);
    }
}

float Odometer::getDistance() {
    return count * 2 / 100;
}

void Odometer::updateSpeed(int ticks) {
    unsigned long currentTime = millis();
    long deltaTime = currentTime - previousTime;
    double speedWeight = deltaTime / timeConstant;
    speed = (1 - speedWeight) * speed + speedWeight * ticks;
    previousTime = currentTime;
}

double Odometer::getSpeed(){
    return speed;
}