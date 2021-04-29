#include <Arduino.h>
#include <HardwareSerial.h>
#include <Adafruit_BluefruitLE_UART.h>

/*
 * Bluetooth() must be passesed Serial1
 * Initialization Order
 * Constrictor, begin, connect
 * 
 * send takes char parameters that are sent as a char array
 * 
 * getCommands return the most recent value for each device
 */

class Bluetooth : public Adafruit_BluefruitLE_UART{
public:
  Bluetooth(HardwareSerial serial, int powerPin, int modePin, int groundPin, void (*E_STOP)(void), HardwareSerial &Serial);
  void begin();
  void connect();
  void updateValues();
  int getThrottle();
  int getWheel();
  int getBrake();
  void send(char a, char b, char c);
private:
  // Default Values for each thing controlled over bluetooth
  // Will be returned if no data has yet been sent from the phone
  static const int THROTTLE_DEFAULT_VALUE = 0;
  static const int WHEEL_DEFAULT_VALUE = 0;
  static const int BRAKE_DEFAULT_VALUE = 0;
  static const int RECIEVED_PACKET_SIZE = 3;
  int packet[RECIEVED_PACKET_SIZE] = {THROTTLE_DEFAULT_VALUE, WHEEL_DEFAULT_VALUE, BRAKE_DEFAULT_VALUE};

  int modePin;
  int powerPin;
  int groundPin;

  HardwareSerial serial;
  void (*STOP)(void);
};
