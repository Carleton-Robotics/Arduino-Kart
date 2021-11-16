#include "SpeedController.h"
#include "Pinouts.h"



SpeedController::SpeedController():
    Throttle(ThrottleSwitchPin),
    Brake(BrakePin1, BrakePin2, BrakePotentiometerPin),
    Odometer(OdometerPin){

}

void SpeedController::begin(){
    Throttle::begin();
    Odometer::begin();
    Brake::begin();
}

void SpeedController::setTarget(double target){
    target = target;
}

void SpeedController::setBrake(int brakePosition){
    Brake::setTarget(brakePosition);
}

void SpeedController::setThrottle(int throttlePower){
    Throttle::setSpeed(throttlePower);
}

double SpeedController::getDistance(){
    return Odometer::getDistance();
}
double SpeedController::getSpeed(){
    return Odometer::getSpeed();
}

void SpeedController::eStop(){
    Brake::eStop();
    Throttle::eStop();
}

void SpeedController::update(){
    Brake::update();

    double current = Odometer::getSpeed();
    P = target - current;
    I += P * (millis()/1000 - previousTime);
    previousTime = millis()/1000;

    Throttle::setSpeed(((Ki * I) + (Kp * P)) * 255);
}