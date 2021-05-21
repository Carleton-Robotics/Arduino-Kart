#include <Arduino.h>
#include "Pinouts.h"
#include "Bluetooth.h"
#include "SteeringMotor.h"
#include "Brake.h"
#include "Odometer.h"
#include "Throttle.h"
#include <SoftwareSerial.h>

Bluetooth bluetooth(Serial1, BluetoothModePin, BluetoothGroundPin, Serial);

SteeringMotor steeringMotor(Serial2);

Brake brake(BrakePin1, BrakePin2, BrakePotentiometerPin);

Odometer odometer(OdometerPin);

Throttle throttle(ThrottleSwitchPin);

void setup() {
  pinMode(MiscPin, INPUT_PULLUP); //Control Box Switch
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  Serial.begin(9600);
  Serial.println("beforebegin");
  // brake.begin();
  odometer.begin();
  Serial.println("before throttle");
  throttle.begin();
  // steeringMotor.begin();
  // bluetooth.begin(eStop);
  //bluetooth.connect();

  //steeringMotor.home();
  //steeringTest();
  //brakeTest();
  Serial.println("HI");
  throttleTest();
}

void loop() {
  //updateStateVariables();
  //updateCommands();
  
}

//this is where you make sure the object state variables are set to the correct values
// void updateStateVariables(){
//   //Update each thing
//   bluetooth.updateValues();
//   brake.updateReading();
//   throttle.updateReading();
  
//   //Print Values for Debugging
//   printValues();

//   //Send updated values to phone
//   bluetooth.send(odometer.getValue(), steeringMotor.getPos(), 'A');
// }

// //here is where you update your demands for all of the kart peripherals.
// void updateCommands(){
//   brake.updateCommand(bluetooth.getBrake());
//   steeringMotor.goTo(bluetooth.getWheel());
//   throttle.updateCommand(bluetooth.getThrottle());
// }

void printValues(){
  Serial.print("Odometer: ");
  Serial.print(odometer.getValue());
  Serial.print(" Steering Motor: ");
  Serial.println(steeringMotor.getPos());
}
void eStop(){
  throttle.eStop();
  steeringMotor.eStop();
  brake.eStop();
}

void brakeTest(){
  Serial.println();
  Serial.println("BrakeTest");
  Serial.println("255");
  while(!brake.updateCommand(255)){
    delay(1);
  }
  Serial.println("0");
  while(!brake.updateCommand(0)){
    delay(1);
  }
}

void steeringTest(){
  Serial.println();
  Serial.println("SteeringTest");
  steeringMotor.goTo(30000);
  delay(2000);
  steeringMotor.goTo(0);
}

void throttleTest(){
  Serial.println();
  Serial.println("Throttle Test");
  double startTime = millis();
  while(millis() - startTime < 10000){
    throttle.updateCommand(127);
    odometer.updateReading();
    Serial.println(odometer.getValue());
  }
  startTime = millis();
  while(millis() - startTime < 2000){
    throttle.updateCommand(0);
    odometer.updateReading();
    Serial.println(odometer.getValue());
  }
}
