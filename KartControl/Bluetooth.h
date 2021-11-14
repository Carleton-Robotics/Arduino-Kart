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
  // bleSerial is the serial connected to the bluetooth module -> Serial1
  // Serial is the main serial used for debugging -> Serial
  Bluetooth(HardwareSerial bleSerial, int modePin, int groundPin, HardwareSerial Serial);

  // eStop should be the main emergency stop function
  // eStop will be called if the connection to the phone is lost
  void begin(void (*eStop) (void));
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

  static const int THROTTLE_INDEX = 0;
  static const int WHEEL_INDEX = 1;
  static const int BRAKE_INDEX = 2;

  static const int RECIEVED_PACKET_SIZE = 3;
  int packet[RECIEVED_PACKET_SIZE] = {THROTTLE_DEFAULT_VALUE, WHEEL_DEFAULT_VALUE, BRAKE_DEFAULT_VALUE};

  void (*eStop)(void);
  int modePin;
  int powerPin;
  int groundPin;

  HardwareSerial serial;
};
