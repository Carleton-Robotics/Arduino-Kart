#pragma once

#include <Arduino.h>

namespace kart {

    class Brake : public Device {
        class Impl;
        Impl *pimpl;

    public:
        Brake(int controlPin1, int controlPin2, int potentiometerPin);

        ~Brake();

        void begin();

        int setTarget(int target);

        int getTarget();

        void eStop();

        int getStatus();

        void preInit();

        void postInit();

        char *getName();

        bool isEnabled();

        void handleTick();
    };
}
