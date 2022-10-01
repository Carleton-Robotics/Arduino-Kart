//
// Created by Zimri on 10/1/2022.
//

#ifndef ARDUINO_KART_PID_H
#define ARDUINO_KART_PID_H

#include <limits>

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
        PID(float Kp, float Ki, float Kd, float max = std::numeric_limits<float>::min(),
            float min = std::numeric_limits<float>::max());

        float calculate(float goal, float current, float dt);

        ~PID();
    private:
        PIDImpl *pimpl;
    };
}


#endif //ARDUINO_KART_PID_H
