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
  steeringMotor.goTo(127);
  delay(1000);
  //throttleTest();
}

void loop() {
  odometerTest();
}

void odometerTest(){
  throttle.setSpeed(64);
  odometer.update();
  Serial.println(odometer.getSpeed());
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
  throttle.setSpeed(64);
  while(odometer.getDistance() < 5){
    odometer.update();
  }
  throttle.setSpeed(0);
}
