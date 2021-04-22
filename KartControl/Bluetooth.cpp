#include "Bluetooth.h"

Bluetooth::Bluetooth(HardwareSerial serial, int modePin, int powerPin) : Adafruit_BluefruitLE_UART(serial){
  modePin = modePin;
  powerPin = powerPin;
}

void Bluetooth::begin(){
  pinMode(powerPin, OUTPUT);
  pinMode(modePin, OUTPUT);
  digitalWrite(powerPin, HIGH);
  delay(500); //Might not be needed
  Adafruit_BluefruitLE_UART::begin();
}
void Bluetooth::connect(HardwareSerial Serial){
  digitalWrite(modePin, HIGH);
  Serial.println("Waiting For Connection...");
  while(Adafruit_BluefruitLE_UART::isConnected()){
    delay(500);
  }
  Serial.println("CONNECTED");
  digitalWrite(modePin, LOW);
};
void Bluetooth::updateValues(){
  while(Adafruit_BluefruitLE_UART::available() >= RECIEVED_PACKET_SIZE){
    for(int i = 0; i < RECIEVED_PACKET_SIZE; i++){
      packet[i] = Adafruit_BluefruitLE_UART::read();
    }
  }
}
int Bluetooth::getThrottle(){
  return packet[0];
}
int Bluetooth::getWheel(){
  return packet[1];
}
int Bluetooth::getBrake(){
  return packet[2];
}
void Bluetooth::send(char a, char b, char c){ //Up to 20 parameters can be added
  char toSend[] = {a, b, c, '\0'}; //Must add new variables to array
  Adafruit_BluefruitLE_UART::write(toSend); //Phone code must know the number of variables to expect
}
