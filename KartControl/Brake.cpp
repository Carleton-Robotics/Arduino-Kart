#include "Brake.h"

Brake::Brake(int controlPin1, int controlPin2, int potentiometerPin, int powerPin) : control1(controlPin1), control2(controlPin2), pot(potentiometerPin), powerPin(powerPin){
    //state = 100 - map(analogRead(pot), startOfTravelValue, endOfTravelValue, 0, 100);

    //updateCommand(0);

    //initialize pins for control and potentiometer, set to zero-brakes condition,
}
void Brake::begin(){
    pinMode(powerPin, OUTPUT);
    digitalWrite(powerPin, HIGH);
    pinMode(control1, OUTPUT);
    pinMode(control2, OUTPUT);
    pinMode(pot, INPUT);
}


void Brake::updateReading(){
    state = analogRead(pot);
}

void Brake::updateCommand(int target){
    updateReading();
    target = map(target, 0, 255, startOfTravelValue, endOfTravelValue);
    if (abs(target - state) < 10){
        digitalWrite(control1, LOW);
        digitalWrite(control2, LOW);

    }
    else if (target < state){ //Backwards Less Brake
        digitalWrite(control1, LOW);
        digitalWrite(control2, HIGH);
    }
    else if(target > state){ //Forwards More Brake
        digitalWrite(control1, HIGH);
        digitalWrite(control2, LOW);
    }
}
void Brake::eStop(){
    digitalWrite(control1, HIGH);
    digitalWrite(control2, HIGH);
}