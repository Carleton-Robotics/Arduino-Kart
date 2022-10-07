//
// Created by Zimri on 10/1/2022.
//

#include "PID.h"

namespace kart {
    class PIDImpl {
    public:
        PIDImpl(float Kp, float Ki, float Kd, float max, float min);

        float calculate(float goal, float current, float dt);
    private:
        float Kp, Ki, Kd, max, min, lastErr, integral;
    };
}

kart::PIDImpl::PIDImpl(float Kp, float Ki, float Kd, float max, float min) : Kp(Kp), Ki(Ki), Kd(Kd), max(max),
                                                                             min(min), lastErr(0.0f), integral(0.0f) {
}

float kart::PIDImpl::calculate(float goal, float current, float dt) {
    float err = goal - current;
    float p = err * Kp;
    integral += err * dt;
    float i = integral * Ki;
    float d = (err - lastErr) / dt * Kd;
    float out = p + i + d;
    if(out > max) {
        out = max;
    } else if(out < min) {
        out = min;
    }
    lastErr = err;
    return out;
}

kart::PID::PID(float Kp, float Ki, float Kd, float max, float min) {
    pimpl = new kart::PIDImpl(Kp, Ki, Kd, max, min);
}

float kart::PID::calculate(float goal, float current, float dt) {
    return pimpl->calculate(goal, current, dt);
}

kart::PID::~PID() {
    delete pimpl;
}