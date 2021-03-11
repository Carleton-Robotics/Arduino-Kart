#include <RoboClaw.h>
#include <SoftwareSerial.h>

#define address 0x80
#define baudRate 38400

#define defaultSpeed 10000
#define defaultAccel 10000
#define defaultDecel 10000

class SteeringMotor : public RoboClaw{
  public:
  SteeringMotor(SoftwareSerial *serial) : RoboClaw(serial, 10000){

  }
  void begin(){
    RoboClaw::begin(baudRate);
  }
  bool goTo(uint32_t pos, uint32_t speed = defaultSpeed, uint32_t accel = defaultAccel, uint32_t decel = defaultDecel){
    return RoboClaw::SpeedAccelDeccelPositionM1(address, accel, speed, decel, pos, 0);
  }
  uint32_t getPos(){
    return RoboClaw::ReadEncM1(address);
  }
  
};
