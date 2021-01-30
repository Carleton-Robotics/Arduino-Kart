
#include <Arduino.h>
#include "MCP45HVX1.h"

class Throttle
{
  public:
    Throttle()
    {
      MCP45HVX1 digiPot(0x3C);
      digiPot.begin(); 
      digiPot.writeWiper(0);
    }
    void throttleWrite(int val)//0-255
    {

      else if val>throttleRead()
      {
        while (throttleRead() < val)
        {
          digiPot.incrementWiper();
        }
      }
      else if(val< throttleRead())
      {
      while (throttleRead() > val)
        {
          digiPot.decrementWiper();
        }
      }
    }
  
    int throttleRead()
    {
      return digiPot.readWiper()
    }
    void throttleEStop()
    {
      throttleWrite(0);
    }
};
