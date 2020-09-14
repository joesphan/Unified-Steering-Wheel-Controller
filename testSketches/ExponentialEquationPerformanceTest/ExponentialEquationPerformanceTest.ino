int a = 10;
int b = 1;
int c;
void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12, HIGH);
  digitalWrite(12, LOW);
  //c = pow(a, b);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
}
