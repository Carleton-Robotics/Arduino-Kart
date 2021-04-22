#include "SteeringMotor.h"

SteeringMotor::SteeringMotor(HardwareSerial *serial) : RoboClaw(serial, 10000){
  
}

void SteeringMotor::begin(){
  RoboClaw::begin(BAUD_RATE);
}
// TODO Postition values should be mapped from 0 to 255
bool SteeringMotor::goTo(uint32_t pos, uint32_t speed = DEFAULT_SPEED, uint32_t accel = DEFAULT_ACCEL, uint32_t decel = DEFAULT_DECEL){
  return RoboClaw::SpeedAccelDeccelPositionM1(ADDRESS, accel, speed, decel, pos, 0);
}
// TODO Encoder values should be mapped from 0 to 255
uint32_t SteeringMotor::getPos(){
  //return RoboClaw::ReadEncM1(address);
  return map(RoboClaw::ReadEncM1(ADDRESS), ENCODER_MIN_VALUE, ENCODER_MAX_VALUE, 0, 255);
}
