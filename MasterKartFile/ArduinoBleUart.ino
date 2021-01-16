#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_UART.h"
#define BLE_MODE_PIN 12
#define BUFFER_SIZE 128

Adafruit_BluefruitLE_UART ble(Serial1, -1);

void error(){
  Serial.println("ERROR");
  while(1);
}

void setup() {
  // put your setup code here, to run once:
  while(!Serial){
    delay(500);
  }
  Serial.begin(115200);

  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  delay(300);
  
  if(!ble.begin(true)){
    Serial.println("Could Not Find Bluefruit");
    error();
  }
  Serial.println("OK");
  ble.echo(false);

  ble.info();
  ble.verbose(false);

  Serial.println("Waiting for Connection...");
  while(!ble.isConnected()){
    delay(500);
  }

  //Serial.println("Switch to Data Mode");
  digitalWrite(12, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  char n, inputs[BUFFER_SIZE+1];

  // Send Data
  if(Serial.available()){
    n = Serial.readBytes(inputs, BUFFER_SIZE);
    inputs[n] = 0;

    // Echo
    Serial.print("Sending: ");
    Serial.println(inputs);

    // Send
    ble.print(inputs);
  }

  // Recieve Data
  while(ble.available()){
    int c = ble.read();
    Serial.println((char)c);
  }
}
