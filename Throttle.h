/*
  Throttle.h - Library for controlling the kart throttle
  Created by CARS
  Pins 20 and 21 are hardcoded into Wire library as I2C pins (sda, sca)
*/
#ifndef Morse_h
#define Morse_h

#include <Arduino.h>
#include "MCP45HVX1.h"
class Throttle
{
  public:
    Throttle(int address);
    void throttleWrite(int val);
    int throttleRead();
    void throttleEStop();
    
  private:
    int _address;
};
#endif
