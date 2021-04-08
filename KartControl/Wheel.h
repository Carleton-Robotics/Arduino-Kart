
#ifndef ARDUINO_KART_WHEEL_H
#define ARDUINO_KART_WHEEL_H
#include <RoboClaw.h>
#include <SoftwareSerial.h>

#define address 0x80
#define baudRate 38400

#define defaultSpeed 10000
#define defaultAccel 10000
#define defaultDecel 10000

class SteeringMotor : public RoboClaw{
public:
    SteeringMotor(SoftwareSerial *serial);
    void begin();
    bool goTo(uint32_t pos, uint32_t speed = defaultSpeed, uint32_t accel = defaultAccel, uint32_t decel = defaultDecel);
    uint32_t getPos();
};

#endif //ARDUINO_KART_WHEEL_H
