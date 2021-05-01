#include "Bluetooth.h"
#include <Arduino.h>

Bluetooth::Bluetooth(HardwareSerial bleSerial, int modePin, int powerPin, int groundPin, HardwareSerial Serial):
  Adafruit_BluefruitLE_UART(bleSerial), 
  modePin(modePin), 
  powerPin(powerPin),
  groundPin(groundPin),
  serial(Serial){
}

void Bluetooth::begin(void (*eStop)(void)){
  eStop = eStop;
  pinMode(powerPin, OUTPUT);
  pinMode(modePin, OUTPUT);
  pinMode(groundPin, OUTPUT);
  digitalWrite(groundPin, LOW);
  digitalWrite(powerPin, HIGH);
  delay(500); //Might not be needed
  Adafruit_BluefruitLE_UART::begin();
}
void Bluetooth::connect(){
  digitalWrite(modePin, HIGH);
  serial.println("Waiting For Connection...");
  while(!Adafruit_BluefruitLE_UART::isConnected()){
    delay(50);
  }
  serial.println("CONNECTED");
  digitalWrite(modePin, LOW);
}
void Bluetooth::updateValues(){
  if(Adafruit_BluefruitLE_UART::isConnected()){
    while(Adafruit_BluefruitLE_UART::available() >= RECIEVED_PACKET_SIZE){
      for(int i = 0; i < RECIEVED_PACKET_SIZE; i++){
        packet[i] = Adafruit_BluefruitLE_UART::read();
      }
    }
  } else {
    eStop();
    connect();
  }
}
int Bluetooth::getThrottle(){
  return packet[THROTTLE_INDEX];
}
int Bluetooth::getWheel(){
  return packet[WHEEL_INDEX];
}
int Bluetooth::getBrake(){
  return packet[BRAKE_INDEX];
}
void Bluetooth::send(char a, char b, char c){ //Up to 20 parameters can be added
  char toSend[] = {a, b, c, '\0'}; //Must add new variables to array
  Adafruit_BluefruitLE_UART::write(toSend); //Phone code must know the number of variables to expect
}
