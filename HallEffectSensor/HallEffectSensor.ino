bool toothPresent = false;
int n = 1000; // ms between updates
int updateTime = n;
int count = 0;
float pi = 3.1415926535897932384626433832795;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(5, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int hallValue = digitalRead(5);
  //Serial.print("Hall value: ");
  //Serial.println(hallValue);
  //Serial.println(analogRead(5));
  //Serial.print("Count: ");
  //Serial.println(count);
  if (toothPresent == false && hallValue != 0) {// assuming we dont have it backwards
    //Serial.println("called");
    toothPresent = true;
    count+=1;
  }
  else if (toothPresent == true && hallValue == 0) {
    //Serial.println("also called");
    toothPresent = false;
    count+=1;
  }
  if (millis() >= updateTime) {
    //Serial.println(count);
    //Serial.print (millis());
    updateTime += n;
    float tpns = count/2/(n/1000);
    float rpm = tpns/45*60; //(there are 45 teeth)
    Serial.println(rpm);
    float ipm = rpm*2*3.8125*pi; //(ipm stands for inches per minute. 3.8125 in is the radius of the gear)
    float mph = ipm * 9.47/pow(10,4);
    count = 0;
    //Serial.println(tpns);
    //Serial.print("the current speed in mph is:");
    //Serial.println(mph);
  }
}

void 
