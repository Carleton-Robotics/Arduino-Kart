#include <Arduino.h>
#include "Pinouts.h"
#include "Bluetooth.h"
#include "SteeringMotor.h"
#include "Brake.h"
#include "Odometer.h"
#include "Throttle.h"


Bluetooth bluetooth(Serial1, BluetoothModePin, BluetoothPowerPin);

SteeringMotor steeringMotor(&Serial2);

Brake brake(BrakePin1, BrakePin2, BrakePotentiometerPin);

Odometer odometer(OdometerPin);

Throttle throttle(ThrottleSwitchPin);

void setup() {
  Serial.begin(9600);
  while(!Serial){
    delay(10);
  }
  bluetooth.begin();
  brake.begin();
  odometer.begin();
  throttle.begin();


  bluetooth.connect(Serial);

  //steeringMotor.begin();
}

void loop() {
  //updateStateVariables();
  //updateCommands();
}

//this is where you make sure the object state variables are set to the correct values
void updateStateVariables(){
  //Update each thing
  bluetooth.updateValues();
  // brake.updateReading();
  // throttle.updateReading();
  
  //Print Values for Debugging
  printValues();

  //Send updated values to phone
  //bluetooth.send(odometer.getValue(), steeringMotor.getPos(), 'A');
}

//here is where you update your demands for all of the kart peripherals.
void updateCommands(){
  // brake.updateCommand(bluetooth.getBrake());
  // steeringMotor.goTo(bluetooth.getWheel());
  // throttle.updateCommand(bluetooth.getThrottle());
}

void printValues(){
  // Serial.print("Odometer: ");
  // Serial.print(odometer.getValue());
  // Serial.print(" Steering Motor: ");
  // Serial.println(steeringMotor.getPos());
}
