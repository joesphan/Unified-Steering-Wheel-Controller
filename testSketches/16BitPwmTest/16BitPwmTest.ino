/*
   12 bit pwm output using timer3
*/
void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  // clear when match, up to icr3 (mode 14)
  // prescaler /1, clear at ocr3a, set at rollover
  TCCR3A = B10101010;
  TCCR3B = B10011001;
  //set to 12 bit, what the total counter counts up to
  ICR3H = B00001111;
  ICR3L = B11111111;
  //set pwm (out of 12 bits)
  OCR3AH = B00001000;
  OCR3AL = B00000000;
}

void loop() {
  if (Serial.available() == 2) {
    int recvd1 = Serial.read();
    int recvd2 = Serial.read();
    OCR3AH = recvd1;
    OCR3AL = recvd2;
  }
}
