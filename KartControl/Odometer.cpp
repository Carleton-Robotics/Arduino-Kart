#include <Arduino.h>

class Odometer
{
  public:
    bool toothPresent; //Quoc told me to create and give the variables values in seperate places
    float interval;
    long updateTime;//NOTE: potential for overflow after ~20 days
    long count;//Note: potential for overflow after ~2billion teeth are read
    float pi;
    float tps;
    float rpm;
    float ipm;
    float mph;
    int hallValue;
    
    Odometer()
    {
      // put your setup code here, to run once:
      toothPresent = false;
      interval = 1; // seconds between updates
      updateTime = 0;
      count = 0;
      pi = 3.1415926535897932384626433832795;
      mph = 0;
      //Serial.begin(9600); I think this is redundant now?
      pinMode(5, INPUT_PULLUP);
    }
    
    void pingOdometer() {
      // put your main code here, to run repeatedly:
      hallValue = digitalRead(5);
      if (toothPresent == false && hallValue == 0) {
        toothPresent = true;
        count+=1;
      }
      else if (toothPresent == true && hallValue != 0) {
        toothPresent = false;
        count+=1;
      }
      if (millis() >= updateTime) {
        updateTime += interval*1000;
        tps = count/interval/2;
        rpm = tps/45*60; //(there are 45 teeth)
        ipm = rpm*2*3.8125*pi; //(ipm stands for inches per minute. 3.8125 in is the radius of the gear)
        mph = ipm * 9.47/pow(10,4);
        count = 0;
      }
    }
    float readMPH()
    {
      return mph;
    }
};
