/*
   encoderTest
   sketch meant to test out if MCU is fast enough to trigger on rotary encoder
   position byte: 0, 0, 0, 0, 0, 0,    b1     ,    b0 LSB
                                   encoderPin1, encoderPin2
*/
#define encoderPin1 2         //must be interrupt
#define encoderPin2 3         //must be interrupt
byte encoderState;
int Position;                 //position of rotor
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  initEncoder();
}
void initEncoder() {
  pinMode(encoderPin1, INPUT);
  pinMode(encoderPin2, INPUT);
  attachInterrupt(digitalPinToInterrupt(encoderPin1), updatePosition, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPin2), updatePosition, CHANGE);
  encoderState = 0;                                         //preset 0
  bitWrite(encoderState, 0, digitalRead(encoderPin2));      //initial write
  bitWrite(encoderState, 1, digitalRead(encoderPin1));      //initial write
  Position = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(Position);
}

void updatePosition() {
  byte readState;    //new position
  bitWrite(readState, 0, digitalRead(encoderPin2));
  bitWrite(readState, 1, digitalRead(encoderPin1));
  switch (encoderState) {
    case B00000000:
      switch (readState) {
        case B00000001:
          Position++;
          break;
        case B00000010:
          Position--;
          break;
      }
      break;
    case B00000001:
      switch (readState) {
        case B00000011:
          Position++;
          break;
        case B00000000:
          Position--;
          break;
      }
      break;
    case B00000011:
      switch (readState) {
        case B00000010:
          Position++;
          break;
        case B00000001:
          Position--;
          break;
      }
      break;
    case B00000010:
      switch (readState) {
        case B00000000:
          Position++;
          break;
        case B00000011:
          Position--;
          break;
      }
      break;
  }
  encoderState = readState;
}
