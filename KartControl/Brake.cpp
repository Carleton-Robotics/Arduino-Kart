#include "Brake.h"
#include <Arduino.h>

using namespace kart;

class Brake::Impl {
public:
    const int startOfTravelValue = 145;
    const int endOfTravelValue = 520;
    int control1;
    int control2;
    int pot;
    int target;
    int state = 0;

    BrakeImpl(int control1, int control2, int pot, int target) : control1(control1), control2(control2), pot(pot),
                                                                 target(target) {
    }
};

Brake::Brake(int controlPin1, int controlPin2, int potentiometerPin) : pimpl(
        new BrakeImpl(controlPin1, controlPin2, potentiometerPin, 0)) {
}

Brake::~Brake() {
    delete pimpl;
}

void Brake::begin() {
    pinMode(pimpl->control1, OUTPUT);
    pinMode(pimpl->control2, OUTPUT);
    pinMode(pimpl->pot, INPUT);
}

int Brake::handleTick() {
    pimpl->state = analogRead(pimpl->pot);
    if (abs(target - state) < 10) {
        digitalWrite(pimpl->control1, LOW);
        digitalWrite(pimpl->control2, LOW);
        return 0;
    } else if (pimpl->target < pimpl->state) { //Backwards Less Brake
        digitalWrite(pimpl->control1, LOW);
        digitalWrite(pimpl->control2, HIGH);
        return -1;
    } else if (pimpl->target > pimpl->state) { //Forwards More Brake
        digitalWrite(pimpl->control1, HIGH);
        digitalWrite(pimpl->control2, LOW);
        return 1;
    }
}

int Brake::setTarget(int target) {
    pimpl->target = map(target, 0, 255, pimpl->startOfTravelValue, pimpl->endOfTravelValue);
    return pimpl->target;
}

void Brake::eStop() {
    digitalWrite(pimpl->control1, HIGH);
    digitalWrite(pimpl->control2, HIGH);
}