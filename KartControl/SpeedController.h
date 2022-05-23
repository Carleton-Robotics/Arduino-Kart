#include "Brake.h"
#include "Odometer.h"
#include "Throttle.h"
#include "Arduino.h"

class SpeedController : public Throttle, public Brake, public Odometer{
    public:
        SpeedController();
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

        const double Kp = 0.1;
        double P;
        const double Ki = 0;
        double I;

        double previousTime;
};