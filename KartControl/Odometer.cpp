#include "Odometer.h"



Odometer::Odometer(int pin): pin(pin){
    toothPresent = false;
    interval = 1; // seconds between updates
    updateTime = 0;
    count = 0;
    state = 0;
}
void Odometer::begin(){
    pinMode(pin, INPUT_PULLUP);
}

void Odometer::updateReading() {
    // put your main code here, to run repeatedly:
    hallValue = digitalRead(5);
    if (toothPresent == false && hallValue == 0) {
        toothPresent = true;
        count += 1;
    }
    else if (toothPresent == true && hallValue != 0) {
        toothPresent = false;
        count += 1;
    }
    if (millis() >= updateTime) {
        updateTime += interval * 1000;
        tps = count / interval / 2;
        rpm = tps / 45 * 60; //(there are 45 teeth)
        ipm = rpm * 2 * 3.8125 * pi; //(ipm stands for inches per minute. 3.8125 in is the radius of the gear)
        state = ipm * 9.47 / pow(10,4);
        count = 0;
    }
}
float Odometer::getFloatValue() {
    return state;
}
char Odometer::getValue() {
    //should map state to a char
    return map(state, ODOMETER_MIN_VALUE, ODOMETER_MAX_VALUE, 0, 255);
}