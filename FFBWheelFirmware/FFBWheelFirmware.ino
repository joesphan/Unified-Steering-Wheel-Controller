/*
   Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0) (c) 2020 Joesphan Lu
*/
#include "Joystick.h"


extern int Position;
extern int32_t forces[2];
extern int motorForce;
extern int prevOverTravel;
extern int diff;
extern uint32_t stepTime;
extern int dir;


void setup() {
  Serial.begin(115200);

  ADCDriverInit();
  servoDriveInit();
  EncoderDriverInit();
  JoystickInit();
}

void loop() {
  int overTravel = CheckMaxAngle();
  JoystickRun();
  if (!overTravel) { //if not at max angle
    servoDrive(-forces[0]);
    prevOverTravel = 0;
  } else {
    endStopDrive(overTravel);
  }
  //debug
  SendSerial(Position, forces[0], motorForce, overTravel, prevOverTravel, getSpeed());
}
