#include "SteeringMotor.h"

SteeringMotor::SteeringMotor(HardwareSerial *serial) : RoboClaw(serial, 10000){
  
}

void SteeringMotor::begin(){
  RoboClaw::begin(baudRate);
}
// TODO Postition values should be mapped from 0 to 255
bool SteeringMotor::goTo(uint32_t pos, uint32_t speed = defaultSpeed, uint32_t accel = defaultAccel, uint32_t decel = defaultDecel){
  return RoboClaw::SpeedAccelDeccelPositionM1(address, accel, speed, decel, pos, 0);
}
// TODO Encoder values should be mapped from 0 to 255
uint32_t SteeringMotor::getPos(){
  return RoboClaw::ReadEncM1(address);
}
