/*
 * Gets the rotary encoder feedback from the servo drive
 * 
 */
#define ENCODER1_PIN 2          //must support external interrupt
#define ENCODER2_PIN 3          // ""    ""       ""       ""
byte encoderState;
int Position;                 //position of rotor

/*
   EncoderDriverInit
   initilization(duh)
*/
void EncoderDriverInit() {
  pinMode(ENCODER1_PIN, INPUT);
  pinMode(ENCODER2_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCODER1_PIN), UpdateSteps, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER2_PIN), UpdateSteps, CHANGE);
  encoderState = 0;                                         //preset 0
  bitWrite(encoderState, 0, digitalRead(encoderPin2));      //initial write
  bitWrite(encoderState, 1, digitalRead(encoderPin1));      //initial write
  Position = 0;
}

/*
    UpdateSteps
    Updates CurrentStep with the current num steps from rotary encoder
    Interrupt driven
    Order:
      {Encoder1, Encoder2}
        00
        01
        11
        10
        00
        repeat
*/
void UpdateSteps() {
  byte readState;    //new position
  bitWrite(readState, 0, digitalRead(ENCODER1_PIN));
  bitWrite(readState, 1, digitalRead(ENCODER2_PIN));
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

/*
   Calibrate
   Sets current steering wheel position as angle 0
*/
void Calibrate() {
  Position = 0;
}

/*
   CheckMaxAngle
   returns: 0 if not max angle
   positive is past right full lock
   negative is past left full lock
*/
int CheckMaxAngle() {
  int pastAmount = abs(Steps) - MAX_STEPS;
  if (pastAmount >= 0 && Steps > 0) {     //past right full lock
    //no need to do anything, as steps is positive
  } else if (pastAmount >= 0 && Steps < 0) {
    pastAmount = -pastAmount;
  } else {                                //return 0 if all the checks pass, not past full lock
    pastAmount = 0;
  }
  return pastAmount;
}
