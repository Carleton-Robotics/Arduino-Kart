#include "Brake.h"
#include <Arduino.h>

Brake::Brake(int controlPin1, int controlPin2, int potentiometerPin) : control1(controlPin1), control2(controlPin2), pot(potentiometerPin){
    
}
void Brake::begin(){
    pinMode(control1, OUTPUT);
    pinMode(control2, OUTPUT);
    pinMode(pot, INPUT);
}
int Brake::getState(){
    return state;
}
int Brake::update(){
    state = analogRead(pot);
    if (abs(target - state) < 10){
        digitalWrite(control1, LOW);
        digitalWrite(control2, LOW);
        return 0;
    }
    else if (target < state){ //Backwards Less Brake
        digitalWrite(control1, LOW);
        digitalWrite(control2, HIGH);
        return -1;
    }
    else if(target > state){ //Forwards More Brake
        digitalWrite(control1, HIGH);
        digitalWrite(control2, LOW);
        return 1;
    }
}
int Brake::setTarget(int setTo){
    target = map(setTo, 0, 255, startOfTravelValue, endOfTravelValue);
    return target;
}
void Brake::eStop(){
    digitalWrite(control1, HIGH);
    digitalWrite(control2, HIGH);
}