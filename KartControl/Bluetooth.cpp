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
  Bluetooth(HardwareSerial &port){ //Must be passes Serial Port Serial1
    ble = new Adafruit_BluefruitLE_UART(port, -1);
  };
  void begin(){
    pinMode(12, OUTPUT);
    ble->begin();
    ble->info();
  };
  void connect(){
    digitalWrite(12, HIGH);
    while(!ble->isConnected()){
      delay(500);
    }
    digitalWrite(12, LOW);
  };
  void updateValues(){
    while(ble->available() >= receivedPacketSize){
      for(int i = 0; i < receivedPacketSize; i++){
        packet[i] = ble->read();
      }
    }
  };
  int getThrottle(){
    return packet[0];
  }
  int getWheel(){
    return packet[1];
  }
  int getBrake(){
    return packet[2];
  }
  void send(char a, char b, char c){ //Up to 20 parameters can be addes
    char toSend[] = {a, b, c, '\0'}; //Must add new variables to array
    ble->write(toSend); //Phone code must know the number of variables to expect
  }
  private:
  Adafruit_BluefruitLE_UART *ble;
  int packet[receivedPacketSize] = {0, 255, 90};
};
