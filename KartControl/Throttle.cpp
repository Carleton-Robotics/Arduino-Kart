#include "Throttle.h"
#include <Arduino.h>
Throttle::Throttle(int switchPin) : digiPot(0x3C), switchPin(switchPin){

}
void Throttle::begin(){
    digiPot.begin();
    digiPot.writeWiper(0);
    pinMode(switchPin, OUTPUT);
}
void Throttle::setSpeedMPS(int val){
    setSpeed(map(val, MAXSPEED, MINSPEED, 0, 255));
}
void Throttle::setSpeed(int val) { //0-255
    if(val < 0){
        val = 0;
    }
    if(val > 128){
        val = 128;
    }
    val = 255 - val;
    if (val > 0) {
        digiPot.writeWiper(val);
        digitalWrite(switchPin, HIGH);
    } else {
        digitalWrite(switchPin, LOW);
        digiPot.writeWiper(val);
    }
}
void Throttle::eStop() {
    setSpeed(0);
}