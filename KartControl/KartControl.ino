#include <Arduino.h>
#include "Pinouts.h"
#include "Bluetooth.h"
#include "SteeringMotor.h"
#include "Brake.h"
#include "Odometer.h"
#include "Throttle.h"
#include "Compass.h"

Bluetooth bluetooth(Serial1, BluetoothModePin, BluetoothGroundPin, Serial);

SteeringMotor steeringMotor(Serial2);

Brake brake(BrakePin1, BrakePin2, BrakePotentiometerPin);

Odometer odometer(OdometerPin);

Throttle throttle(ThrottleSwitchPin);

Compass compass;

void setup() {
  pinMode(MiscPin, INPUT_PULLUP); //Control Box Switch
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  Serial.begin(115200);
  brake.begin();
  odometer.begin();
  throttle.begin();
  compass.begin();
  steeringMotor.begin();
  // bluetooth.begin(eStop);
  // bluetooth.connect();

  steeringMotor.home();
}

void loop() {
}

void eStop(){
  steeringMotor.eStop();
  brake.eStop();
}

void brakeTest(){
  Serial.println("Brake Test");
  Serial.println("255");
  while(!brake.updateCommand(255)){
    delay(1);
  }
  Serial.println("0");
  while(!brake.updateCommand(0)){
    delay(1);
  }
}

void throttleTest(){
  Serial.println("Throttle Test");
  throttle.updateCommand(64);
  while(odometer.getTicks() < 100){
    odometer.updateReading();
  }
  throttle.updateCommand(0);
}

void square(){
  for(int i = 0; i < 4; i++){
    unsigned long initialTicks = odometer.getTicks();
    throttle.updateCommand(127);
    while(odometer.getTicks() - initialTicks < 1000){
      odometer.updateReading();
    }
    double starting = compass.getHeading();
    steeringMotor.goTo(255);
    while(abs(starting - compass.getHeading()) < 90){
    }
    steeringMotor.goTo(127);
  }
}
