

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
    void throttleWrite(int val)//0-255
    {

      if (val>throttleRead()) {
        while (throttleRead() < val) {
          digiPot.incrementWiper();
        }
      }
      else if(val< throttleRead()) {
        while (throttleRead() > val) {
          digiPot.decrementWiper();
        }
      }
    }
    void updateCommand(int on){
      if (on){
        digitalWrite(switchPin,HIGH);
      }
      else{
        digitalWrite(switchPin,LOW);
      }
      
    }
    void updateReading(){
      state = digiPot.readWiper();
    }
    void throttleEStop(){
      throttleWrite(0);
    }
};
