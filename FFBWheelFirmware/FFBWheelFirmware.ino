#include "Joystick.h"
#define MAX_STEPS 15000                         //maximum number of steps one way
#define MAX_FULL_STEPS (MAX_STEPS * 2)        //max number of steps total



//extern vars
extern int Steps;
extern int32_t forces[2];

void setup() {
  Serial.begin(9600);
//inits
  JoystickInit();
  EncoderDriverInit();
}

void loop() {
  SendSerial(Steps, forces[0]);
  JoystickRun();
}
