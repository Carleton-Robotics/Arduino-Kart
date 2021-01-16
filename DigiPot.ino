#include <Arduino.h>
#include "MCP45HVX1.h"

MCP45HVX1 digiPot(0x3C);

void setup()
{  
  Serial.begin(9600);

  digiPot.begin();  
  digiPot.writeWiper(0);
}

void loop()
{
  while (digiPot.readWiper() < 255) {
    digiPot.incrementWiper();
    Serial.println(digiPot.readWiper());
    delay(50);
  }

  while (digiPot.readWiper() > 0) {
    digiPot.decrementWiper();
    Serial.println(digiPot.readWiper());
    delay(50);
  }
} 
