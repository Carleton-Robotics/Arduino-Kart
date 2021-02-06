#import "Bluetooth.cpp"
#import "Odometer.cpp"
#import "Throttle.cpp"
#import "Brake.cpp"
#import "Wheel.cpp"
Odometer myOdometer;

void setup() {
  // put your setup code here, to run once:
  // This space intentionally left blank
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // This space intentionally left blank
  myOdometer.pingOdometer(); //update odometer
  //if (millis()%500 == 0) { // Prints our speed every 500 ms
  //  Serial.print("MPH: ");
  //  Serial.println(myOdometer.readMPH());
  //}
}

//void update_kart_

/*
 * Every Loop we should
 * update kart values
 * read new commands
 * send new variable vals
 */
