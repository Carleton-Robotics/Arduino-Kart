#include <Arduino.h>
#include "Pinouts.h"
#include "SteeringMotor.h"
#include "Compass.h"
#include "SpeedController.h"
#include "GPS.h"


SteeringMotor steeringMotor(Serial2);

// Brake = brake(BrakePin1, BrakePin2, BrakePotentiometerPin);
// Throttle = throttle(ThrottleSwitchPin);
// Odometer = odometer(OdometerPin);

SpeedController speedController;

Compass compass;

GPS gps;

void(* resetFunc) (void) = 0; //Call to reset arduino

void setup() {
  pinMode(MiscPin, INPUT_PULLUP); //Control Box Switch
  pinMode(BluetoothGroundPin, OUTPUT);
  digitalWrite(BluetoothGroundPin, LOW);
  attachInterrupt(digitalPinToInterrupt(OdometerPin), odometerInterrupt, RISING);
  Serial.begin(115200);

  //Wait for start switch
  while(digitalRead(MiscPin) != 1);

  speedController.begin();

  gps.begin();

  //compass.begin();
  //steeringMotor.begin();

  //steeringMotor.home();
  //steeringMotor.goTo(127);
  delay(2000);



}

void loop() {
  //Stop if start switch switched off
  if(digitalRead(MiscPin) != 1){
    stop();
  }

  gps.update();
  speedController.update();
  speedController.setTarget(1);

  delay(10);
}

// void commTest(){
//   throttle.setSpeed(32);
//   if(Serial.available() > 0){
//     String incomming = Serial.readStringUntil('\n');
//     if(incomming == "STOP"){
//       eStop();
//       while(1)

//     }
//   }
// }


void eStop(){
  steeringMotor.eStop();
  speedController.eStop();
  while(1);
}

void stop(){
  steeringMotor.eStop();
  speedController.eStop();
  resetFunc();
}

void odometerInterrupt(){
  speedController.Odometer::countTick();
}