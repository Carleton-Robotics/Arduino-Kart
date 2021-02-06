  int input_1 = 8;
  int input_2 = 9;
  int slide_pot = A15;
  int pot_val;

//retracting the break actuator will increase the pot value
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(input_1, OUTPUT);
  pinMode(input_2, OUTPUT);
  pinMode(slide_pot, INPUT);
  pot_val = analogRead(slide_pot);
  while (pot_val > 300) {
    extend(10);
    pot_val = analogRead(slide_pot);
    Serial.println("Slide pot value: ");
    Serial.println(pot_val);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

void stop_actuator() {
  digitalWrite(input_1, HIGH);
  digitalWrite(input_2, HIGH);
}

// input percentage as an integer value e.g. 100
void extend_by_percentage_then_stop(int percent) {
  float percent_to_decimal = percent / 100;
  float time_delay = percent_to_decimal * 2200;
  digitalWrite(input_1, LOW);
  digitalWrite(input_2, HIGH);
  delay(time_delay);
  stop_actuator();
}

void extend(int time_delay) {
  digitalWrite(input_1, LOW);
  digitalWrite(input_2, HIGH);
  delay(time_delay);
  stop_actuator();
}

void retract(int time_delay) {
  digitalWrite(input_1, HIGH);
  digitalWrite(input_2, LOW);
  delay(time_delay);
  stop_actuator();
}

// input percentage as an integer value e.g. 100
void retract_by_percentage_then_stop(int percent) {
  float percent_to_decimal = percent / 100;
  float time_delay = percent_to_decimal * 2200;
  digitalWrite(input_1, HIGH);
  digitalWrite(input_2, LOW);
  delay(time_delay);
  stop_actuator();
}
