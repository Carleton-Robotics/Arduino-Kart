#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_u-blox_GNSS_Arduino_Library.h>
#include "Vector.h"

class GPS{
    public:

    GPS();

    void begin();

    long getLatitudeRaw();

    long getLongitudeRaw();

    float getLatitudeMeters();

    float getLongitudeMeters();

    float getHeadingRaw();

    Vector getPosVector();

    Vector getHeadingVector();

    bool update();

    private:

    SFE_UBLOX_GNSS GNSS;

    long latitude;
    long longitude;
    long heading;
    unsigned long previousTime;
    float earthRadius = 6371000; //meters
    //location of Northfield according to Google:
    float referenceLatitude  = 45.4583;
    float referenceLongitude = -93.1616;
};
