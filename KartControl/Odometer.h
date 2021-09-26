#include <Arduino.h>

class Odometer{
  private:
    bool toothPresent; 
    int pin;
    unsigned long count;


    static const int interval = 200; //Seconds between updates
    static const double pi = 3.1415926535897932384626433832795;

  public:
    Odometer(int pin);
    void begin();

    void update();
    float getDistance();
};