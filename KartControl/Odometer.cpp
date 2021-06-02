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
        count += 1;
    }
    else if (toothPresent == true && hallValue == 1) {
        toothPresent = false;
    }
}
float Odometer::getDistance() {
    return count*2/100;
}
