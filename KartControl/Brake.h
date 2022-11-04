#pragma once

#include <Arduino.h>

namespace kart {

    class Brake : public Device {
        class Impl;

        Impl *pimpl;

    public:

        Brake(int controlPin1, int controlPin2, int potentiometerPin);

        ~Brake();

        int setTarget(int target);

        int getTarget();

        int getStatus();

        int getError();

        void init();

        void preInit();

        char *getName();

        bool isEnabled();

        void update();

        void shutdown();
    };
}
