#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include "Device.h"

namespace kart {
    class Compass : public Device {
    private:
        class Impl;

        Impl *pimpl;
    public:

        Compass();

        ~Compass();

        void init();

        void preInit();

        char *getName();

        float getHeading(); //Returns degrees - North unknown

        void update(); //Must be called to get new data

        float getX(); //Accurate TODO what do they mean by accurate :(

        float getY(); //Accurate

        int getStatus();

        int getError();

        void shutdown();

        bool isEnabled();
    };
}
