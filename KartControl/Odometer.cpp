#include "Odometer.h"
#include <Arduino.h>

using namespace kart;

class Odometer::Impl {
public:
    bool toothPresent;
    int pin;
    unsigned long totalCount;
    unsigned long count;

    unsigned long previousTime;

    double timeConstant = 150000;

    double speed;

    const double distanceConversionFactor = 0.0248;
    const double speedConversionFactor = 24800; //tick per ms to m per s

    void updateSpeed(int ticks);

    Impl(int pin);

    ~Impl();
};

Odometer::Impl::Impl(int pin) : pin(pin) {
    toothPresent = false;
    count = 0;
    totalCount = 0;
    previousTime = 0;
}

Odometer::Impl::~Impl() {
}

Odometer::Odometer(int pin) : pimpl(new Impl(pin)) {
}

Odometer::~Odometer() {
    delete pimpl;
}

void Odometer::begin() {
    pinMode(pin, INPUT_PULLUP);
    countTick();
}

void Odometer::countTick() {
    pimpl->totalCount += 1;
    pimpl->count += 1;
}

void Odometer::update(){
        updateSpeed(pimpl->count);
        pimpl->count = 0;
}

double Odometer::getDistance() {
    return pimpl->totalCount * pimpl->distanceConversionFactor;
}

double Odometer::getDistanceT() {
    return pimpl->totalCount;
}

void Odometer::updateSpeed(int ticks) {
    unsigned long currentTime = micros();
    long deltaTime = currentTime - pimpl->previousTime;
    double speedWeight = deltaTime / pimpl->timeConstant;
    pimpl->speed = (1 - speedWeight) * pimpl->speed + speedWeight * ticks / deltaTime;
    pimpl->previousTime = currentTime;
}

double Odometer::getSpeed() {
    return pimpl->speed * pimpl->speedConversionFactor;
}

double Odometer::getSpeedTPMS() {
    return pimpl->speed;
}

char *getName() {
    static const char name[] = "Odometer";
    return name;
}

int getStatus() {
    return Device::Status::OK;
}

int getError() {
    return Device::Error::NONE;
}

bool isEnabled() {
    return true;
}

void shutdown() {
}