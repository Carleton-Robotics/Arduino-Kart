#pragma once

#include <Arduino.h>

namespace kart {

    class Odometer {
    private:
        bool toothPresent;
        int pin;
        unsigned long totalCount;
        unsigned long count;

        unsigned long previousTime;

        double timeConstant = 150000;

        double speed;

        const double distanceConversionFactor = 0.0248;
        const double speedConversionFactor = 24800; //tick per ms to m per s

        void updateSpeed(int ticks);

    public:
        Odometer(int pin);

        void begin();

        void countTick();

        void update();

        double getDistanceT();

        double getDistance();

        double getSpeedTPMS();

        double getSpeed();
    };
}
