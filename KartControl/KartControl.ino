#include <Arduino.h>
#include "Pinouts.h"
#include "SteeringMotor.h"
#include "Compass.h"
#include "SpeedController.h"
#include "GPS.h"


SteeringMotor steeringMotor(Serial2);

// These should be accessed through Speed Controller
// Brake = brake(BrakePin1, BrakePin2, BrakePotentiometerPin);
// Throttle = throttle(ThrottleSwitchPin);
// Odometer = odometer(OdometerPin);

SpeedController speedController;

//Compass compass;

//GPS gps;

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
  Serial.println("Begun");

  //gps.begin();

  //compass.begin();
  steeringMotor.begin();

  delay(2000);

  // float[][] path = {{0.1, 0.8}, {0.2, 0.7}, {0.3, 0.7}} //example path. just an array of coordinates in meters
  // int i = 0; //index variable for path
}

void loop() {
  //Stop if misc switch on control box switched off
  if(digitalRead(MiscPin) != 1){
    stop();
  }
  speedController.setBrake(0);
  speedController.update();
  
  speedController.setThrottle(50); //should this go in setup instead of loop?
  if (gps.update()){
    Vector kartPos = Vector(gps.getLatitudeMeteres(), gps.getLongitudeMeters());
    Vector targetPos = Vector(path[i][0], path[i][1]);
    Vector nextTargetPos = Vector(path[i+1][0], path[i+1][1]);
    float dist1 = kartPos.dist(targetPos);
    float dist2 = kartPos.dist(nextTargetPos);
    if(dist2 < dist1){
      i++;
    }
    Vector kartDir(1, 0); //get kart direction from past GPS points and store it as a unit vector
    int n = 3; //distance to look ahead when computing targetDir. Increase this number to smooth out direction and anticipate turns
    Vector futureTargetPos = Vector(path[i+n][0], path[i+n][1]);
    Vector targetDir = futureTargetPos.subtract(kartPos);
    targetDir.normalize();
    float angleError = targetDir.crossProduct(kartDir);
    Vector positionError = targetPos.subtract(kartPos);
    float horzError = positionError.crossProduct(kartDir);
    float A = 0.25;
    float B = 1; //should satisfy 4A = B^2 if we want "critical damping" 
    float turningRate = - A*horzError - B*angleError;
    steeringMotor.goTo(128 + round(turningRate*10));
  }
  delay(10);
}



void eStop(){
  //steeringMotor.eStop();
  speedController.eStop();
  while(1);
}

void stop(){
  //steeringMotor.eStop();
  speedController.eStop();
  resetFunc();
}

void odometerInterrupt(){
  speedController.Odometer::countTick();
}
