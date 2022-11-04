#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_u-blox_GNSS_Arduino_Library.h>
#include "Vector2.h"
#include "Device.h"

namespace kart {
    class GPS : public Device {
    private:
        class Impl;

        Impl *pimpl;
    public:
        GPS();

        ~GPS();

        void init();

        void preInit();

        int getStatus();

        int getError();

        char* getName();

        bool isEnabled();

        void shutdown();

        long getLatitudeRaw();

        long getLongitudeRaw();

        float getLatitudeMeters();

        float getLongitudeMeters();

        float getHeadingRaw();

        Vector2 getPosVector();

        Vector2 getHeadingVector();

        void update();
    };
}

