
#include <Arduino.h>
#include "MCP45HVX1.h"

class Throttle {
  private:
    MCP45HVX1 digiPot;
  public:
    state;
    Throttle() : digiPot(0x3C) {
      digiPot.begin(); 
      digiPot.writeWiper(0);
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
  
    int updateReading(){
      state = digiPot.readWiper();
    }
    void throttleEStop(){
      throttleWrite(0);
    }
};
