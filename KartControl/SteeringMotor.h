#include "RoboClaw.h"
#include <Arduino.h>

class SteeringMotor : public RoboClaw{
public:
  SteeringMotor(HardwareSerial& serial);
  void begin();
  bool goTo(uint32_t pos, uint32_t speed = DEFAULT_SPEED, uint32_t accel = DEFAULT_ACCEL, uint32_t decel = DEFAULT_DECEL);
  uint32_t getPos();
  uint32_t getRealPos();
  bool forward(uint32_t speed);
  void eStop();
  uint32_t readEncoder();
  void home();
  
private:
  int limitSwitchPin;
  int encoderMax;

  static const uint32_t DEFAULT_SPEED = 100000;
  static const uint32_t DEFAULT_ACCEL = 100000;
  static const uint32_t DEFAULT_DECEL = 100000;
  
  static const int ADDRESS = 0x80;
  static const int BAUD_RATE = 38400;

  static const int HOME_SPEED = 40;
};
