#include "Brake.h"
#include <Arduino.h>

using namespace kart;

class Brake::Impl {
public:
    const int START_OF_TRAVEL_VALUE = 145;
    const int END_OF_TRAVEL_VALUE = 520;
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

void Brake::init() {
    pinMode(pimpl->control1, OUTPUT);
    pinMode(pimpl->control2, OUTPUT);
    pinMode(pimpl->pot, INPUT);
}

void Brake::preInit() {
}

void Brake::update() {
    pimpl->state = analogRead(pimpl->pot);
    if (abs(target - state) < 10) {
        digitalWrite(pimpl->control1, LOW);
        digitalWrite(pimpl->control2, LOW);
    } else if (pimpl->target < pimpl->state) { //Backwards Less Brake
        digitalWrite(pimpl->control1, LOW);
        digitalWrite(pimpl->control2, HIGH);
    } else if (pimpl->target > pimpl->state) { //Forwards More Brake
        digitalWrite(pimpl->control1, HIGH);
        digitalWrite(pimpl->control2, LOW);
    }
}

int Brake::setTarget(int target) {
    pimpl->target = map(target, 0, 255, Impl::START_OF_TRAVEL_VALUE, Impl::END_OF_TRAVEL_VALUE);
    return pimpl->target;
}

int Brake::getTarget() {
    return pimpl->target;
}

int Brake::getStatus() {
    return Status::OK;
}

void Brake::shutdown() {
    digitalWrite(pimpl->control1, HIGH);
    digitalWrite(pimpl->control2, HIGH);
}

int Brake::getError() {
    return Error::NONE;
}

bool Brake::isEnabled() {
    return true;
}

char *Brake::getName() {
    static char name[] = "Brake";
    return name;
}
