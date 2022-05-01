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

  float[] path = {{0.1, 0.8}, {0.2, 0.7}, {0.3, 0.7}} //example path. just an array of coordinates in meters
  int i = 0; //index variable for path
}

void loop() {
  //Stop if misc switch on control box switched off
  if(digitalRead(MiscPin) != 1){
    stop();
  }

  
  speedController.setThrottle(50); //should this go in setup instead of loop?
  gps.update();
  float kartPos[] = {gps.getLatitudeMeteres(), gps.getLongitudeMeters()};
  float targetPos[] = path[i];
  float nextTargetPos[] = path[i + 1];
  float dist1 = sqrt(pow(kartPos[0] - targetPos[0], 2) + pow(kartPos[1] - targetPos[1], 2)); //would like to do this with a vector class
  float dist2 = sqrt(pow(kartPos[0] - nextTargetPos[0], 2) + pow(kartPos[1] - nextTargetPos[1], 2));
  if(dist2 < dist1){
    i++;
  }
  float kartDir[] = {0, 0}; //get kart direction from compass and store it as a unit vector
  int lookAhead = 3;
  float futureTargetPos[] = path[i + lookAhead];
  float targetDir[] = {futureTargetPos[0] - kartPos[0], futureTargetPos[0] - kartPos[0]} //this could be vector subtraction
  targetDir 
  

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
