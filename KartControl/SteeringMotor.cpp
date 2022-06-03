#include "SteeringMotor.h"

SteeringMotor::SteeringMotor(HardwareSerial& serial) : RoboClaw(&serial, 10000){
  
}
void SteeringMotor::begin(){
  RoboClaw::begin(38400);
  RoboClaw::ResetEncoders(ADDRESS);
}
// Postition values are from 0 to 255
bool SteeringMotor::goTo(uint32_t pos, uint32_t speed = DEFAULT_SPEED, uint32_t accel = DEFAULT_ACCEL, uint32_t decel = DEFAULT_DECEL){
  pos = map(pos, 0, 255, 0, encoderMax);
  return RoboClaw::SpeedAccelDeccelPositionM1(ADDRESS, accel, speed, decel, pos, 1);
}
bool SteeringMotor::goToRaw(int encoderDisp, uint32_t speed = DEFAULT_SPEED, uint32_t accel = DEFAULT_ACCEL, uint32_t decel = DEFAULT_DECEL){
  uint32_t pos = encoderDisp;
  return RoboClaw::SpeedAccelDeccelPositionM1(ADDRESS, accel, speed, decel, pos, 1);
}
uint32_t SteeringMotor::getPos(){
  return map(RoboClaw::ReadEncM1(ADDRESS), 0, encoderMax, 0, 255);
}
uint32_t SteeringMotor::getRealPos(){
  return RoboClaw::ReadEncM1(ADDRESS);
}
void SteeringMotor::eStop(){
  RoboClaw::SpeedM1(ADDRESS, 0);
}
bool SteeringMotor::forward(uint32_t speed){
  return RoboClaw::ForwardM1(ADDRESS, speed);
}
uint32_t SteeringMotor::readEncoder(){
  return RoboClaw::ReadEncM1(ADDRESS);
}
void SteeringMotor::home(){
  RoboClaw::BackwardM1(ADDRESS, HOME_SPEED);
  delay(8000);
  RoboClaw::ForwardM1(ADDRESS, 0);
  RoboClaw::ResetEncoders(ADDRESS);
  RoboClaw::ForwardM1(ADDRESS, HOME_SPEED);
  delay(8000);
  RoboClaw::ForwardM1(ADDRESS, 0);
  encoderMax = readEncoder();
}
