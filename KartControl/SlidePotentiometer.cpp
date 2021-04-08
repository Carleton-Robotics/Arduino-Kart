#include "SlidePotentiometer.h"

SlidePotentiometer::SlidePotentiometer() {
    //pinMode(6, INPUT_PULLUP);
    pinMode(A1, INPUT);
    brakeMin = 0;
    brakeMax = 1024;
    goal = 50;
}

int SlidePotentiometer::getValue() {
    // put your main code here, to run repeatedly:
    sensorValue = analogRead(A1);
    Serial.println(sensorValue);
    currentPrecentage = (sensorValue - brakeMin) / (brakeMax - brakeMin);
    if (currentPrecentage < goal) {
        Serial.println("Under our goal");
    } else if (currentPrecentage > goal) {
        Serial.println("Over our goal");
    } else if (currentPrecentage = goal) {
        Serial.println("At our goal");
    }
    return currentPrecentage;
}
