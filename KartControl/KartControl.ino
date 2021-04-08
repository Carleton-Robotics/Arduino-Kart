#include "Bluetooth.h"
#include "Odometer.h"
#include "Throttle.h"
#include "Brake.h"
#include "Wheel.h"

#define ODOMETER_PIN 5
#define THROTTLE_SWITCH_PIN 6
#define WHEEL_CONTROL_PIN 7
//this code is basically a switching yard for information between the kart and the phone
Odometer odometer(ODOMETER_PIN);
Throttle throttle(THROTTLE_SWITCH_PIN);//note the I2C pins are hardcoded into the library we are extending for the digipot
//SteeringMotor wheel(WHEEL_CONTROL_PIN);
//Brake brake(controlPin1 = ,controlPin2 = ,potentiometerPin = ,endOfTravelValue = );

void setup() {
  // put your setup code here, to run once:
  // This space intentionally left blank
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // This space intentionally left blank
  updateStateVariables();
  updateCommands();
}

//this is where you make sure the object state variables are set to the correct values
void updateStateVariables(){
  
  odometer.updateReading();
  throttle.updateReading();
//  wheel.updateReading();
//  brake.updateReading();
}

//here is where you update your demands for all of the kart peripherals. Each function takes a 0-1000 which is mapped to required range in classes integer input
void updateCommands(){
  throttle.updateCommand(100);
//  wheel.updateCommand(100);
//  brake.updateCommand(500);
}
  
  


/*
 * Every Loop we should
 * update kart values
 * read new commands
 * send new variable vals
 */
