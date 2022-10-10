#pragma once

#include "Brake.h"
#include "Odometer.h"
#include "Throttle.h"
#include "PID.h"
#include "Arduino.h"

namespace kart {

    class SpeedController : public Throttle, public Brake, public Odometer {
    public:
        SpeedController();
        ~SpeedController();

        void setTarget(double target);

        void setThrottle(int throttlePower);

        int setBrake(int brakePosition);

        double getSpeed();

        double getDistance();

        void eStop();

        void begin();

        int update();

        int getBrakeState();

    private:

        double target;

        PID *pid;

        double previousTime;
    };
}
