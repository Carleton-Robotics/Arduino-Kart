#include <Arduino.h>
#include "Pinouts.h"
#include "SteeringMotor.h"
#include "Compass.h"
#include "SpeedController.h"



SteeringMotor steeringMotor(Serial2);

// Brake = brake(BrakePin1, BrakePin2, BrakePotentiometerPin);
// Throttle = throttle(ThrottleSwitchPin);
// Odometer = odometer(OdometerPin);

SpeedController speedController;

Compass compass;

void(* resetFunc) (void) = 0;

void setup() {
  pinMode(MiscPin, INPUT_PULLUP); //Control Box Switch
  pinMode(BluetoothGroundPin, OUTPUT);
  digitalWrite(BluetoothGroundPin, LOW);
  attachInterrupt(digitalPinToInterrupt(OdometerPin), odometerInterrupt, RISING);
  Serial.begin(115200);

  while(digitalRead(MiscPin) != 1);

  speedController.begin();

  // brake.begin();
  // odometer.begin();
  // throttle.begin();
  //compass.begin();
  //steeringMotor.begin();

  //steeringMotor.home();
  //steeringMotor.goTo(127);
  delay(2000);

  // Kp = 0.1;

  // Ki = 0;
  
  // I = 0;

  // P = 0;

  // target = 1;

  // previousTime = millis()/1000;
  //Serial.println("HI");

}

void loop() {
  // odometer.update();
  // double current = odometer.getSpeed();
  // P = target - current;
  // I += P * (millis()/1000 - previousTime);
  // previousTime = millis()/1000;

  // throttle.setSpeed(((Ki * I) + (Kp * P)) * 255);
  // Serial.print(current*100);
  // Serial.print("\t");
  // Serial.print(Kp*P*100);
  // Serial.print("\t");
  // Serial.print(Ki*I*100);
  // Serial.print("\t");
  // Serial.println(100);
  //Serial.println(((Ki * I) + (Kp * P)) * 255);

  if(digitalRead(MiscPin) != 1){
    stop();
  }

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