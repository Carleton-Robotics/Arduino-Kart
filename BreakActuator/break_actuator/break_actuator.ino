  int input_1 = 8;
  int input_2 = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(input_1, OUTPUT);
  pinMode(input_2, OUTPUT);
  retract_then_stop_actuator(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void retract_then_stop_actuator(int time_delay) {
  digitalWrite(input_1, HIGH);
  digitalWrite(input_2, LOW);
  delay(time_delay);
  stop_actuator();
}

void stop_actuator() {
  digitalWrite(input_1, HIGH);
  digitalWrite(input_2, HIGH);
}

void extend_then_stop_actuator(int time_delay) {
  digitalWrite(input_1, LOW);
  digitalWrite(input_2, HIGH);
  delay(time_delay);
  stop_actuator();
}
