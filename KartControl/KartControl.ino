#include <Arduino.h>
#include "Pinouts.h"
#include "Bluetooth.h"
#include "SteeringMotor.h"
#include "Brake.h"
#include "Odometer.h"
#include "Throttle.h"


Bluetooth bluetooth(Serial1, BluetoothPowerPin, BluetoothModePin);

SteeringMotor wheel(&Serial2);

Brake brake(BrakePin1, BrakePin2, BrakePotentiometerPin);

Odometer odometer(OdometerPin);

Throttle throttle(ThrottleSwitchPin);

void setup() {
  // put your setup code here, to run once:
  // This space intentionally left blank
  Serial.begin(9600);

  bluetooth.begin();
  bluetooth.connect(Serial);

  wheel.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // This space intentionally left blank
  
  updateStateVariables();
  updateCommands();
  bluetooth.send(odometer.getValue(), 'A', 'B');
}

//this is where you make sure the object state variables are set to the correct values
void updateStateVariables(){
  bluetooth.updateValues();
  brake.updateReading();
  throttle.updateReading();
}

//here is where you update your demands for all of the kart peripherals.
void updateCommands(){
  brake.updateCommand(bluetooth.getBrake());
  wheel.goTo(bluetooth.getWheel());
  throttle.updateCommand(bluetooth.getThrottle());
}
