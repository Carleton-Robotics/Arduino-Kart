  int input_1 = 7;
  int input_2 = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(input_1, LOW);
  digitalWrite(input_2, HIGH);
}
