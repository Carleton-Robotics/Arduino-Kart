#include "SpeedController.h"
#include "Pinouts.h"

using namespace kart;

SpeedController::SpeedController() :
        Throttle(ThrottleSwitchPin),
        Brake(BrakePin1, BrakePin2, BrakePotentiometerPin),
        Odometer(OdometerPin){
    this->pid = new PID(0.6 * 0.7, 0.0, 0.0,100.0, 0.0);
}

void SpeedController::begin() {
    Throttle::begin();
    Odometer::begin();
    Brake::begin();
}

void SpeedController::setTarget(double target) {
    this->target = target;
}

int SpeedController::setBrake(int brakePosition) {
    return Brake::setTarget(brakePosition);
}

int SpeedController::getBrakeState() {
    return Brake::getState();
}

void SpeedController::setThrottle(int throttlePower) {
    Throttle::setSpeed(throttlePower);
}

double SpeedController::getDistance() {
    return Odometer::getDistance();
}

double SpeedController::getSpeed() {
    return Odometer::getSpeed();
}

void SpeedController::eStop() {
    Brake::eStop();
    Throttle::eStop();
}

SpeedController::~SpeedController() {
    delete pid;
}

int SpeedController::update() {

    Odometer::update();
    double current = Odometer::getSpeed();

    Serial.print(F("Speed is "));
    Serial.println(current);
    Serial.print(F("Desired speed is"));
    Serial.println(target);

    double t = millis();

    double newSpeed = this->pid->calculate(target, current, t - previousTime) * 255;
    Serial.print(F("Setting speed to "));
    Serial.println(newSpeed);
    previousTime = t;
    Throttle::setSpeed(target * 0.35 * 255);

    return Brake::update();
}