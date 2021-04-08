#include "Wheel.h"

SteeringMotor::SteeringMotor(SoftwareSerial *serial) : RoboClaw(serial, 10000) {

}

void SteeringMotor::begin() {
    RoboClaw::begin(baudRate);
}

bool SteeringMotor::goTo(uint32_t pos, uint32_t speed = defaultSpeed, uint32_t accel = defaultAccel,
                         uint32_t decel = defaultDecel) {
    return RoboClaw::SpeedAccelDeccelPositionM1(address, accel, speed, decel, pos, 0);
}

uint32_t SteeringMotor::getPos() {
    return RoboClaw::ReadEncM1(address);
}
