//
// Created by Zimri on 10/1/2022.
//

#include "Arduino.h"
#include "PID.h"

namespace kart {
    class PIDImpl {
    public:
        PIDImpl(float Kp, float Ki, float Kd, float maxVal, float minVal);

        float calculate(float goal, float current, float dt);

    private:
        float Kp, Ki, Kd, maxVal, minVal, lastErr, integral;
    };
}

kart::PIDImpl::PIDImpl(float Kp, float Ki, float Kd, float maxVal, float minVal) : Kp(Kp), Ki(Ki), Kd(Kd), maxVal(maxVal),
                                                                                   minVal(minVal), lastErr(0.0f), integral(0.0f) {
}


void printPID(float p, float i, float d) {
    Serial.print(F("P: "));
    Serial.print(p);
    Serial.print(F(", I: "));
    Serial.print(i);
    Serial.print(F(", D: "));
    Serial.println(d);
}

float kart::PIDImpl::calculate(float goal, float current, float dt) {
    float err = goal - current;
    float p = err * Kp;
    integral += err * dt;
    float i = integral * Ki;
    float d = (err - lastErr) / dt * Kd;
    float out = p + i + d;
    if (out > maxVal) {
        out = maxVal;
    } else if (out < minVal) {
        out = minVal;
    }
    lastErr = err;
    printPID(p, i, d);
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
