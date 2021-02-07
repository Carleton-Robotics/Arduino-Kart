#import "Bluetooth.cpp"
#import "Odometer.cpp"
#import "Throttle.cpp"
#import "Brake.cpp"
#import "Wheel.cpp"

//this code is basically a switching yard for information between the kart and the phone
Odometer odometer(pin=5);
Throttle throttle(switchPin = );//note the I2C pins are hardcoded into the library we are extending for the digipot
//Brake brake(controlPin1 = ,controlPin2 = ,potentiometerPin = ,endOfTravelValue = );

void setup() {
  // put your setup code here, to run once:
  // This space intentionally left blank
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // This space intentionally left blank
  updateSensorVals();
  updateCommands();
}

void updateSensorVals(){
  //update sensor vals
  odometer.updateReading();
  throttle.updateReading();
  //brake.updateReading();
}
void updateCommands(){
  //update command states
  throttle.updateCommand(0);//input 0 or 1 based on if the throttle should be engaged or not (this is an artifact of the analog controller)
  //brake.updateCommand(input value from bluetooth);
}
  
  


/*
 * Every Loop we should
 * update kart values
 * read new commands
 * send new variable vals
 */
