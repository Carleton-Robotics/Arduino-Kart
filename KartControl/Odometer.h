#include <Arduino.h>

class Odometer{
  private:
    bool toothPresent; 
    unsigned long updateTime;
    int pin;
    int count;

    double speed;

    static const int interval = 200; //Seconds between updates
    static const double pi = 3.1415926535897932384626433832795;

  public:
    Odometer(int pin);
    void begin();

    void updateReading();
    double getValue();
};