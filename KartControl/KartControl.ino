#include <Arduino.h>
#include "Pinouts.h"
#include "Bluetooth.h"
#include "SteeringMotor.h"
#include "Brake.h"
#include "Odometer.h"
#include "Throttle.h"


//Bluetooth bluetooth(Serial1, BluetoothModePin, BluetoothPowerPin, BluetoothGroundPin, Serial);

SteeringMotor steeringMotor(Serial2, LimitSwitchPin);

// Brake brake(BrakePin1, BrakePin2, BrakePotentiometerPin, BrakePowerPin);

// Odometer odometer(OdometerPin, OdometerPowerPin);

// Throttle throttle(ThrottleSwitchPin, ThrottlePowerPin);

void setup() {
  //Serial.begin(9600);
  // while(!Serial){
  //   delay(10);
  // }
  // brake.begin();
  // odometer.begin();
  // throttle.begin();
  steeringMotor.begin();
  //bluetooth.begin(eStop);
  //bluetooth.connect();
  delay(1000);
  steeringMotor.forward(128);
  //test();
  //steeringTest();
}

void loop() {
  //updateStateVariables();
  //updateCommands();
  while(true){}
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

// void printValues(){
//   Serial.print("Odometer: ");
//   Serial.print(odometer.getValue());
//   Serial.print(" Steering Motor: ");
//   Serial.println(steeringMotor.getPos());
// }
// void eStop(){
//   throttle.eStop();
//   steeringMotor.eStop();
//   brake.eStop();
// }








/* -------TESTS--------*/
// void test(){
//   delay(1000);
//   throttleTest();
//   // delay(2000);
//   // steeringTest();
//   // delay(2000);
//   // brakeTest();
// }

// void throttleTest(){
//   Serial.println("Throttle Test");
//   throttle.updateCommand(0);

//   delay(1000);

//   for(int i = 0; i <= 127; i++){
//     throttle.updateCommand(i);
//     delay(25);
//   }
//   delay(200);
//   for(int i = 127; i >= 0; i--){
//     throttle.updateCommand(i);
//     delay(25);
//   }
// }

void steeringTest(){
  Serial.println("Steering Test");
  Serial.println("2000");
  steeringMotor.goTo(2000);
  delay(1000);
}

// void brakeTest(){
//   Serial.println("Brake Test");
//   Serial.println("0");
//   double start = millis();
//   while(millis() - start < 10000){
//     brake.updateCommand(0);
//   }
//   Serial.println(255);
//   start = millis();
//   while(millis() - start < 10000){
//     brake.updateCommand(255);
//   }
// }
