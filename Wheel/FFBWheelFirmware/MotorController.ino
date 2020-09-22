/*
     MotorController: controls the servo drive
*/
int motorForce;
extern int motorEN;
int prevOverTravel;

/*
   init with diff signal of 0
*/
void servoDriveInit() {
  pinMode(MOT_EN_PIN, OUTPUT);
  motorForce = BIT_DEPTH;
  ADCSend(motorForce);
}

/*
   servoDrive: communicates with the servo drive, input as a force direction
   input is an 11 bit value left/right; -2048/2048
*/
void servoDrive(int force) {
  motorForce = (force + 2048);
  ADCSend(motorForce);
  if (force && motorEN) {
    digitalWrite(MOT_EN_PIN, HIGH);
  } else {
    //disable when not intending to write
    digitalWrite(MOT_EN_PIN, LOW);
  }
}
/*
    endStopDrive:
    Over travel (OT) as input, - as left + as right
    creates a dampened force
    adjustable quadratic dampening
    adjustable rebound damping
    return spring damping implemented
*/
void endStopDrive(int overTravel) {
  int absoluteOverTravel = abs(overTravel);
  int diff = absoluteOverTravel - prevOverTravel;
  //int dir = -(overTravel / absoluteOverTravel);
  int dir = -(overTravel / absoluteOverTravel);
  if (absoluteOverTravel < MAX_OVERTRAVEL && diff > 0) {   //between 0 and MAX_OVERTRAVEL steps of OT, direction OT increasing
    //quadratic
    servoDrive(dir * (BIT_DEPTH * (pow(((float)absoluteOverTravel / MAX_OVERTRAVEL), ENDSTOP_FACTOR))));
    
  } else if (absoluteOverTravel > MAX_OVERTRAVEL && diff > 0) { //more than MAX_OVERTRAVEL steps of OT, direction OT increasing
    
    servoDrive(dir * BIT_DEPTH);                                //direction * max force
    
  } else {                             //OT direction decreasing
    //rebound
    servoDrive(-dir * (REBOUND_FORCE * getSpeed()));    //rebound force dependent on (rebound) speed of wheel
  }
  prevOverTravel = absoluteOverTravel;
}
