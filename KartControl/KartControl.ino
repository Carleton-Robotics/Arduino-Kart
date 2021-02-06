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
  myOdometer.pingOdometer(); //Must be run every loop
  //if (millis()%500 == 0) { // Prints our speed every 500 ms
  //  Serial.print("MPH: ");
  //  Serial.println(myOdometer.readMPH());
  //}
}
