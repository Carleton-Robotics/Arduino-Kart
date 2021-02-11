#import "Bluetooth.cpp"
#import "Odometer.cpp"
#import "Throttle.cpp"
#import "Brake.cpp"
#import "Wheel.cpp"

//this code is basically a switching yard for information between the kart and the phone
Odometer odometer(pin=5);
Throttle throttle(switchPin = );//note the I2C pins are hardcoded into the library we are extending for the digipot
Wheel wheel(controlPin = )
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
  wheel.updateReading();
  brake.updateReading();
}

//here is where you update your demands for all of the kart peripherals. Each function takes a 0-1000 which is mapped to required range in classes integer input
void updateCommands(){
  throttle.updateCommand(100);
  wheel.updateCommand(100);
  brake.updateCommand(500);
}
  
  


/*
 * Every Loop we should
 * update kart values
 * read new commands
 * send new variable vals
 */
