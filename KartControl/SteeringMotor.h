#include "RoboClaw.h"
#include <Arduino.h>

class SteeringMotor : public RoboClaw{
public:
  SteeringMotor(HardwareSerial *serial);
  void begin();
  bool goTo(uint32_t pos, uint32_t speed = DEFAULT_SPEED, uint32_t accel = DEFAULT_ACCEL, uint32_t decel = DEFAULT_DECEL);
  uint32_t getPos();
  void eStop();

private:
  static const uint32_t DEFAULT_SPEED = 1000;
  static const uint32_t DEFAULT_ACCEL = 1000;
  static const uint32_t DEFAULT_DECEL = 1000;
  
  static const int ADDRESS = 0x80;
  static const int BAUD_RATE = 38400;

  static const int ENCODER_MIN_VALUE = 0;
  static const int ENCODER_MAX_VALUE = 1000;
};