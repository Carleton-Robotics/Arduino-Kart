#include "Brake.h"

Brake::Brake(int controlPin1, int controlPin2, int potentiometerPin) : control1(controlPin1), control2(controlPin2), pot(potentiometerPin){
    //state = 100 - map(analogRead(pot), startOfTravelValue, endOfTravelValue, 0, 100);

    //updateCommand(0);

    //initialize pins for control and potentiometer, set to zero-brakes condition,
}
void Brake::begin(){
    pinMode(control1, OUTPUT);
    pinMode(control2, OUTPUT);
    pinMode(pot, INPUT);
}

bool Brake::updateCommand(int target){
    state = analogRead(pot);
    target = map(target, 0, 255, startOfTravelValue, endOfTravelValue);
    if (abs(target - state) < 10){
        digitalWrite(control1, LOW);
        digitalWrite(control2, LOW);
        return true;
    }
    else if (target < state){ //Backwards Less Brake
        digitalWrite(control1, LOW);
        digitalWrite(control2, HIGH);
        return false;
    }
    else if(target > state){ //Forwards More Brake
        digitalWrite(control1, HIGH);
        digitalWrite(control2, LOW);
        return false;
    }
}

void Brake::eStop(){
    digitalWrite(control1, HIGH);
    digitalWrite(control2, HIGH);
}