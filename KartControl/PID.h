#pragma once

#include <float.h>

namespace kart {
    class PIDImpl;
    /**
     * PID controller.
     *
     * Kp is the proportional constant, which scales how the output varies wrt error.
     * Ki is the integral constant, which scales how the output varies wrt the integral of the error.
     * Kd is the derivative constant, which scales how the output varies wrt the derivative of the error.
     */
    class PID {
    public:
        PID(float Kp, float Ki, float Kd, float maxVal = 1e40,
            float minVal = -1e40);

        float calculate(float goal, float current, float dt);

        ~PID();
    private:
        PIDImpl *pimpl;
    };
}