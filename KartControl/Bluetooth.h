#pragma once

#include <Arduino.h>
#include <HardwareSerial.h>
#include <Adafruit_BluefruitLE_UART.h>
#include <Device.h>

namespace kart {

/*
 * Bluetooth() must be passesed Serial1
 * Initialization Order
 * Constrictor, begin, connect
 * 
 * send takes char parameters that are sent as a char array
 * 
 * getCommands return the most recent value for each device
 */

    class Bluetooth : public Device {
    private:
        Impl *pimpl;

        class Impl;

    public:
        // Default Values for each thing controlled over bluetooth
        // Will be returned if no data has yet been sent from the phone
        static const int THROTTLE_DEFAULT_VALUE;
        static const int WHEEL_DEFAULT_VALUE;
        static const int BRAKE_DEFAULT_VALUE;
        static const int THROTTLE_INDEX;

        static const int WHEEL_INDEX = 1;
        static const int BRAKE_INDEX = 2;
        static const int RECIEVED_PACKET_SIZE = 3;

        enum Status {
            INITIALIZING, CONNECTING, CONNECTED;
        };

        // bleSerial is the serial connected to the bluetooth module -> Serial1
        // Serial is the main serial used for debugging -> Serial
        Bluetooth(HardwareSerial bleSerial, int modePin, int groundPin, HardwareSerial Serial);

        void attemptConnect();

        void update();

        int getThrottle();

        int getWheel();

        int getBrake();

        void send(char a, char b, char c);

        int getStatus();

        void init();

        void preInit();

        char *getName();

        bool isEnabled();

        void shutdown();

        int getError();
    };
}
