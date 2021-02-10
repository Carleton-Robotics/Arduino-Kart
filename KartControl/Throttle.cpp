

#include <Arduino.h>
#include "MCP45HVX1.h"

class Throttle {
  private:
    MCP45HVX1 digiPot;
    int switchPin;
    
  public:
    int state;
    Throttle(int switchPin) : digiPot(0x3C) {
      digiPot.begin(); 
      digiPot.writeWiper(0);
      switchPin = switchPin;
      pinMode(switchPin,OUTPUT);
      state = digiPot.readWiper();
      
    }
    
    void updateCommand(int val){//0-255
      if (val>0){
        digiPot.writeWiper(val)
        digitalWrite(switchPin,HIGH);
      }
      else{
        digitalWrite(switchPin,LOW);
        digiPot.writeWiper(val)
      }
      
    }
    void updateReading(){
      state = digiPot.readWiper();
    }
    void throttleEStop(){
      throttleWrite(0);
    }
};
