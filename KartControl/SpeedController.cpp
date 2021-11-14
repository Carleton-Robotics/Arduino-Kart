#include "SpeedController.h"
#include "Pinouts.h"

SpeedController::SpeedController(){
    brake = Brake(BrakePin1, BrakePin2, BrakePotentiometerPin);
    throttle = Throttle(ThrottleSwitchPin);
    odometer = Odometer(OdometerPin);
}

SpeedController::begin(){
    throttle.begin();
    odometer.begin();
    brake.begin();
}

SpeedController::setTarget(double target){
    target = target;
}

SpeedController::setBrake(int brakePosition){
    brake.updateCommand(brakePosition);
}

SpeedController::setThrottle(int throttlePower){
    throttle.setSpeed(throttlePower);
}

SpeedController::getDistance(){
    return odometer.getDistance();
}
SpeedController::getSpeed(){
    return odometer.getSpeed();
}

SpeedController::update(){
    odometer.updateReading();
    brake.update();

    double current = odometer.getSpeed();
    P = target - current;
    I += P * (millis()/1000 - previousTime);
    previousTime = millis()/1000;

    throttle.setSpeed(((Ki * I) + (Kp * P)) * 255);
}