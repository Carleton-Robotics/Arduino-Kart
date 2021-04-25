#include "Throttle.h"
#include <Arduino.h>
Throttle::Throttle(int switchPin) : digiPot(0x3C), switchPin(switchPin) {
}
void Throttle::begin(){
    digiPot.begin();
    digiPot.writeWiper(0);
    pinMode(switchPin, OUTPUT);
    state = digiPot.readWiper();
}

void Throttle::updateCommand(int val) { //0-255
    if (val > 0) {
        digiPot.writeWiper(val);
        digitalWrite(switchPin, HIGH);
    } else {
        digitalWrite(switchPin, LOW);
        digiPot.writeWiper(val);
    }
}

void Throttle::updateReading() {
    state = digiPot.readWiper();
}

void Throttle::throttleEStop() {
    updateCommand(0);
}