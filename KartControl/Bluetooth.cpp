#include "Arduino.h"
#include "HardwareSerial.h"
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_UART.h"

/*
 * Bluetooth() must be passesed Serial1
 * Initialization Order
 * Constrictor, begin, connect
 * 
 * send takes char parameters that are sent as a char array
 * 
 * write writes to an int array that is passes to it
 * nothing is returned - the array that was passed to it is updated
 * the array must be the same size as what the phone sends
 * 
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
  void read(int packet[], int size){
    while(ble->available() >= size){
      for(int i = 0; i < size; i++){
        packet[i] = ble->read();
      }
    }
  };
  void send(char a, char b, char c){ //Up to 20 parameters can be addes
    char toSend[] = {a, b, c, '\0'}; //Must add new variables to array
    ble->write(toSend); //Phone code must know the number of variables to expect
  }
  private:
  Adafruit_BluefruitLE_UART *ble;
};
