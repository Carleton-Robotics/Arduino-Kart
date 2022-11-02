#include "Bluetooth.h"
#include <Arduino.h>

using namespace kart;

class Bluetooth::Impl {
public:

    Adafruit_BluefruitLE_UART *bluefruitLeUart;

    int packet[RECIEVED_PACKET_SIZE] = {THROTTLE_DEFAULT_VALUE, WHEEL_DEFAULT_VALUE, BRAKE_DEFAULT_VALUE};

    int modePin;
    int powerPin;
    int groundPin;

    HardwareSerial serial;

    Status status = Status::INITIALIZING;

    Impl();

    ~Impl();
};

Bluetooth::Impl::Impl(HardwareSerial bleSerial, int modePin, int groundPin, HardwareSerial Serial)
        : bluefruitLeUart(new Adafruit_BluefruitLE_UART(bleSerial)),
          modePin(modePin),
          groundPin(groundPin),
          serial(Serial) {
}

Bluetooth::Impl::~Impl() {
    delete bluefruitLeUart;
}

Bluetooth::Bluetooth(HardwareSerial bleSerial, int modePin, int groundPin, HardwareSerial Serial) : Device(), pimpl(
        new Bluetooth::Impl(bleSerial, modePin, groundPin, Serial)) {
}

void Bluetooth::preInit() {
    pinMode(pimpl->modePin, OUTPUT);
    pinMode(pimpl->groundPin, OUTPUT);
    digitalWrite(pimpl->groundPin, LOW);
    delay(500); //Might not be needed
    pimpl->bluefruitLeUart->begin();
}

void Bluetooth::postInit() {
}

bool Bluetooth::isEnabled() {
    return false; // TODO get bluetooth working again
}

char* Bluetooth::getName() {
    static char[] name = "Bluetooth";
    return name;
}

void Bluetooth::attemptConnect() {
    pimpl->status = Status::CONNECTING;
    digitalWrite(pimpl->modePin, HIGH);
    serial.println("Waiting For Connection...");
    while (!pimpl->bluefruitLeUart->isConnected()) {
        delay(50);
    }
    pimpl->status = Status::CONNECTED;
    serial.println("CONNECTED");
    digitalWrite(pimpl->modePin, LOW);
}

void Bluetooth::handleTick() {
    if (pimpl->bluefruitLeUart->isConnected()) {
        pimpl->status = Status::CONNECTED;
        while (pimpl->bluefruitLeUart->available() >= RECIEVED_PACKET_SIZE) {
            for (int i = 0; i < RECIEVED_PACKET_SIZE; i++) {
                packet[i] = pimpl->bluefruitLeUart->read();
            }
        }
    } else {
        attemptConnect();
    }
}

int Bluetooth::getThrottle() {
    return packet[Bluetooth::THROTTLE_INDEX];
}

int Bluetooth::getWheel() {
    return packet[Bluetooth::WHEEL_INDEX];
}

int Bluetooth::getBrake() {
    return packet[Bluetooth::BRAKE_INDEX];
}

void Bluetooth::send(char a, char b, char c) { //Up to 20 parameters can be added
    char toSend[] = {a, b, c, '\0'}; //Must add new variables to array
    pimpl->bluefruitLeUart->write(toSend); //Phone code must know the number of variables to expect
}

Bluetooth::Status Bluetooth::getStatus() {
    return pimpl->status;
}