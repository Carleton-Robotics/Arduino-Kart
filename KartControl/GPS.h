#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_u-blox_GNSS_Arduino_Library.h>

class GPS{
    public:

    GPS();

    void begin();

    long getLatitudeRaw();

    long getLongitudeRaw();

    float getLatitudeMeters();

    float getLongitudeMeters();

    void update();

    private:

    SFE_UBLOX_GNSS GNSS;

    long latitude;
    long longitude;
    unsigned long previousTime;
    float earthRadius;
    float referenceLatiude;
    float degToRad;
};