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
  Bluetooth(HardwareSerial serial, int powerPin, int modePin);
  void begin();
  void connect(HardwareSerial Serial);
  void updateValues();
  int getThrottle();
  int getWheel();
  int getBrake();
  void send(char a, char b, char c);
private:
  static const int ThrottleDefaultValue = 0;
  static const int WheelDefaultValue = 0;
  static const int BrakeDefaultValue = 0;
  static const int ReceivedPacketSize = 3;
  int packet[ReceivedPacketSize] = {ThrottleDefaultValue, WheelDefaultValue, BrakeDefaultValue};
  int modePin;
  int powerPin;
};
