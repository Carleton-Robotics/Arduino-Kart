#include "Compass.h"

using namespace kart;

class Compass::Impl {
public:
    Adafruit_HMC5883_Unified *adafruitHmc5883Unified;

    float xVal;
    float yVal;

    float xOffset = 3.135;
    float yOffset = 39.32;

    Impl();

    ~Impl();
};

Compass::Impl::Impl() : adafruitHmc5883Unified(
        new Adafruit_HMC5883_Unified(12345)) { // TODO find out why they put 12345 here
}

Compass::Impl::~Impl() {
    delete adafruitHmc5883Unified;
}

Compass::Compass() : pimpl(new Impl()) {
}

Compass::~Compass() {
    delete pimpl;
}

void Compass::init() {
    pimpl->adafruitHmc5883Unified->begin();
    sensors_event_t event;
    pimpl->adafruitHmc5883Unified->getEvent(&event);
    // todo why did they call this here? it's not being used
}

void Compass::preInit() {
}

char* Compass::getName() {
    static const char name[] = "Compass";
    return name;
}

void Compass::update() {
    sensors_event_t event;
    pimpl->adafruitHmc5883Unified->getEvent(&event);
    pimpl->xVal = event.magnetic.x;
    pimpl->yVal = event.magnetic.y;
}

float Compass::getX() {
    return xVal + xOffset;
}

float Compass::getY() {
    return yVal + yOffset;
}

float Compass::getHeading() {
    return atan2(yVal, xVal) * RAD_TO_DEG;
}

int Compass::getStatus() {
    return Status::OK;
}

int Compass::getError() {
    return Error::NONE;
}

void Compass::shutdown() {
    pimpl->adafruitHmc5883Unified->end();
}

bool Compass::isEnabled() {
    return true;
}