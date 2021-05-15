#include <Arduino.h>
#include "Pinouts.h"
#include "Bluetooth.h"
#include "SteeringMotor.h"
#include "Brake.h"
#include "Odometer.h"
#include "Throttle.h"
#include <SoftwareSerial.h>
//Bluetooth bluetooth(Serial1, BluetoothModePin, BluetoothPowerPin, BluetoothGroundPin, Serial);

SteeringMotor steeringMotor(Serial2);

//Brake brake(BrakePin1, BrakePin2, BrakePotentiometerPin, BrakePowerPin);

// Odometer odometer(OdometerPin, OdometerPowerPin);

//Throttle throttle(ThrottleSwitchPin, ThrottlePowerPin);

void setup() {
  // Serial.begin(9600);
  //digitalWrite(13,HIGH);
  //brake.begin();
  // odometer.begin();
  //throttle.begin();
  steeringMotor.begin();
  //bluetooth.begin(eStop);
  //bluetooth.connect();
  //delay(2000);
  //brakeTest();
  // digitalWrite(BrakePin1, HIGH);
  // digitalWrite(BrakePin2, LOW);
  steeringTest();
}

void loop() {
  //updateStateVariables();
  //updateCommands();

  // Serial.println(analogRead(A1));
  //brake.updateCommand(0);
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


void steeringTest(){
  steeringMotor.goTo(2000, 1000);
  delay(1000);

  steeringMotor.goTo(0, 1000);
  delay(1000);
  // Serial.println("-3000");
  // steeringMotor.goTo(-3000);
}

