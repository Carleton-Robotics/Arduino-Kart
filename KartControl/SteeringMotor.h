#include "RoboClaw.h"


class SteeringMotor : public RoboClaw{
public:
  SteeringMotor(HardwareSerial *serial);
  void begin();
  bool goTo(uint32_t pos, uint32_t speed = defaultSpeed, uint32_t accel = defaultAccel, uint32_t decel = defaultDecel);
  uint32_t getPos();
private:
  static const uint32_t defaultSpeed = 1000;
  static const uint32_t defaultAccel = 1000;
  static const uint32_t defaultDecel = 1000;
  static const int address = 0x80;
  static const int baudRate = 38400;
};