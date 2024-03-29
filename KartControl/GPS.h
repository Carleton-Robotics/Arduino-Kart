#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_u-blox_GNSS_Arduino_Library.h>
#include "Vector2.h"

namespace kart {
    class GPS {
    public:
        GPS();

        void begin();

        long getLatitudeRaw();

        long getLongitudeRaw();

        float getLatitudeMeters();

        float getLongitudeMeters();

        float getHeadingRaw();

        Vector2 getPosVector();

        Vector2 getHeadingVector();

        bool update();

    private:

        SFE_UBLOX_GNSS GNSS;

        long latitude;
        long longitude;
        long heading;
        float rawLatToMeters = 0.0011119;
        float rawLonToMeters = 0.00079364;
        //location of Northfield according to Google:
        long referenceLatitude = 444583000;//units: deg*10^-7
        long referenceLongitude = -931616000;//units: deg*10^-7
    };
}

