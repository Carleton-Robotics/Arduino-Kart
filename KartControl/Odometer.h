#include <Arduino.h>

class Odometer{
  private:
    bool toothPresent; 
    unsigned long updateTime; //NOTE: potential for overflow after ~20 days
    unsigned long count; //Note: potential for overflow after ~2billion teeth are read
    double tps;
    double rpm;
    double ipm;
    int hallValue;
    int pin;
    int powerPin;

    static const int interval = 1; //Seconds between updates
    static const double pi = 3.1415926535897932384626433832795;
    static const double ODOMETER_MIN_VALUE = 0;
    static const double ODOMETER_MAX_VALUE = 60;

  public:
    double state;
    Odometer(int pin, int powerPin);
    void begin();

    void updateReading();
    double getActualValue();
    char getValue();
};