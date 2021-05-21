#include "Odometer.h"

Odometer::Odometer(int pin): pin(pin){
    toothPresent = false;
    updateTime = 0;
    count = 0;
}
void Odometer::begin(){
    //pinMode(pin, INPUT_PULLUP);
    speed = 0;
}

void Odometer::updateReading() {
    // put your main code here, to run repeatedly:
    int hallValue = digitalRead(pin);
    if (toothPresent == false && hallValue == 0) {
        toothPresent = true;
        count += 1;
    }
    else if (toothPresent == true && hallValue != 0) {
        toothPresent = false;
        count += 1;
    }
    if (millis() >= updateTime) {
        updateTime += interval;
        speed = count / (interval / 1000) * 0.02511778;
        count = 0;

        //0.02511778
    }
}
double Odometer::getValue() {
    return speed;
}
