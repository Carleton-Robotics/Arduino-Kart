
#ifndef ARDUINO_KART_BLUETOOTH_H
#define ARDUINO_KART_BLUETOOTH_H
#include "Arduino.h"
#include "HardwareSerial.h"
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_UART.h"

#define receivedPacketSize 3

/*
 * Bluetooth() must be passesed Serial1
 * Initialization Order
 * Constrictor, begin, connect
 *
 * send takes char parameters that are sent as a char array
 *
 * getCommands return the most recent value for each device
 */

class Bluetooth{
public:
    Bluetooth(HardwareSerial &port){ //Must be passed Serial1
        ble = new Adafruit_BluefruitLE_UART(port, -1);
    };
    void begin();
    void connect();
    void updateValues();
    int getThrottle();
    int getWheel();
    int getBrake();
    void send(char a, char b, char c);
private:
    Adafruit_BluefruitLE_UART *ble;
    int packet[receivedPacketSize] = {0, 255, 90};
};

#endif //ARDUINO_KART_BLUETOOTH_H
