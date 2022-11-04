#pragma once

#include <Arduino.h>
#include "Device.h"

namespace kart {

    class Odometer : public Device {
    private:

        class Impl;

        Impl *pimpl;
    public:
        Odometer(int pin);

        void init();

        void preInit();

        void countTick();

        void update();

        char *getName();

        int getStatus();

        int getError();

        bool isEnabled();

        void shutdown();

        double getDistanceT();

        double getDistance();

        double getSpeedTPMS();

        double getSpeed();
    };
}
