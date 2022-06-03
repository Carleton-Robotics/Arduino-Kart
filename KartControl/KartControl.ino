#include <Arduino.h>
#include "Pinouts.h"
#include "SteeringMotor.h"
#include "SpeedController.h"
#include "GPS.h"
#include "Vector.h"


SteeringMotor steeringMotor(Serial2);

SpeedController speedController;

GPS gps;

void(* resetFunc) (void) = 0; //Call to reset arduino

float path[3][2] = {{0.1, 0.8}, {0.2, 0.7}, {0.3, 0.7}}; //example path. just an array of coordinates in meters
int i = 0; //index variable for path

void setup() {
  //Control box switch
  pinMode(MiscPin, INPUT_PULLUP);

  //Set pin to be ground for bluetooth ground
  pinMode(BluetoothGroundPin, OUTPUT);
  digitalWrite(BluetoothGroundPin, LOW);

  //Interrupt to count odometer ticks
  attachInterrupt(digitalPinToInterrupt(OdometerPin), odometerInterrupt, RISING);
  Serial.begin(115200);

  //Wait for start switch
  while(digitalRead(MiscPin) != 1);

  speedController.begin();
  Serial.println("Speed Controller Begun");

  gps.begin();
  Serial.println("GPS Begun");

  steeringMotor.begin();
  Serial.println("Steering Motor Begun");

  delay(2000);
}

void loop() {
  //Stop if misc switch on control box switched off
  if(digitalRead(MiscPin) != 1){
    stop();
  }

  speedController.setBrake(0);
  speedController.update();
  
  // speedController.setThrottle(50);

  // if (gps.update()){
  //   Vector kartPos = gps.getPosVector();
  //   Vector targetPos = Vector(path[i][0], path[i][1]);
  //   Vector nextTargetPos = Vector(path[i+1][0], path[i+1][1]);
  //   float dist1 = kartPos.dist(targetPos);
  //   float dist2 = kartPos.dist(nextTargetPos);
  //   if(dist2 < dist1){ //should change to while loop...
  //     i++;
  //   }
  //   Vector kartDir = gps.getHeadingVector();
  //   int n = 5; //number of points to look ahead when computing targetDir. Increase this number to smooth out direction and anticipate turns
  //   Vector futureTargetPos = Vector(path[i+n][0], path[i+n][1]);
  //   Vector targetDir = futureTargetPos.subtract(kartPos);
  //   targetDir.normalize();
  //   Vector positionError = kartPos.subtract(targetPos);
  //   float horzError = positionError.crossProduct(targetDir);
  //   float angleError = kartDir.crossProduct(targetDir);
  //   float B = 1; //units: 1/m. Make this parameter larger for quick steering and smaller for smooth steering
  //   float A = B*B/4; //should satisfy 4A = B^2 if we want "critical damping"
  //   horzError = constrain(horzError, -B/A/2, B/A/2);
  //   float turningRate = - A*horzError - B*angleError; //units: 1/m, pos=right, neg=left
  //   float steeringEncoder = constrain(turningRate*4000, -1000, 1000) //units: encoder ticks
  //   steeringMotor.goToRaw(round(steeringEncoder));
  // }
  // delay(10);
}

void printGPSCoords(){
  if (gps.update()){
    Vector kartPos = gps.getPosVector();
    Serial.print("{ ");
    Serial.print(kartPos.getX());
    Serial.print(" , ");
    Serial.print(kartPos.getY());
    Serial.println(" } ");
  }
}

void display_freeram() {
  Serial.print(F("- SRAM left: "));
  Serial.println(freeRam());
}

int freeRam() {
  extern int __heap_start,*__brkval;
  int v;
  return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int) __brkval);  
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
