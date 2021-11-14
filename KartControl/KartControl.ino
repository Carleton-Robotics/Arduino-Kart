#include <Arduino.h>
#include "Pinouts.h"
#include "SteeringMotor.h"
#include "Brake.h"
#include "Odometer.h"
#include "Throttle.h"
#include "Compass.h"
#include "SpeedController.h"



SteeringMotor steeringMotor(Serial2);

Brake brake(BrakePin1, BrakePin2, BrakePotentiometerPin);

Odometer odometer(OdometerPin);

Throttle throttle(ThrottleSwitchPin);

SpeedController speedController();

Compass compass;


double Kp;
double Ki;
double I;
double P;
double target;

double previousTime;

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

  speedController.update();
  speedController.setTarget(1);

  delay(10);
  if(digitalRead(MiscPin) != 1){
    switchOff();
  }
}

void commTest(){
  throttle.setSpeed(32);
  if(Serial.available() > 0){
    String incomming = Serial.readStringUntil('\n');
    if(incomming == "STOP"){
      eStop();
      while(1)

    }
  }
}

void odometerTest(){
  throttle.setSpeed(64);
  odometer.update();
  Serial.println(odometer.getSpeed());
  delay(3);
}


void eStop(){
  steeringMotor.eStop();
  brake.eStop();
  throttle.eStop();
  //speedController.eStop();
  while(1);
}

void switchOff(){
  steeringMotor.eStop();
  brake.eStop();
  throttle.eStop();
  //speedController.eStop();
  reset();
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


void odometerInterrupt(){
  odometer.countTick();
}