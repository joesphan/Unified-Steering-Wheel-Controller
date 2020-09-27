#include "defines.h"
/*
   USBJoystickInterface
   Interfaces with HID/PID protocols through the usb controller
*/
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK, 32, 0,
                   true, true, true,
                   false, false, false,
                   false, false, false, false, false);
Gains mygains[2];
EffectParams myeffectparams[2];
int32_t forces[2] = {0};
int32_t friction[2] = {0};


//input states
//buttons
byte PaddleHornState = 0;     //b0 right, b1 left, b2 horn
//axii
int Position;
uint16_t throttleState = 0;
uint16_t brakeState = 0;
uint16_t clutchState = 0;
uint16_t handbrakeState = 0;

/*
   initialization
*/
void JoystickInit() {
  Joystick.setFFBRange(2048);
  Joystick.setXAxisRange(-MAX_STEPS, MAX_STEPS);
  mygains[0].totalGain = 800;
  Joystick.setGains(mygains);
  Joystick.begin();
  myeffectparams[0].springMaxPosition = MAX_STEPS;
}
/*
  JoystickRun
  Sends wheel info to PC
  Buttons:
  ```0: right Paddle
    `1: left Paddle
     2: gear R
     3: gear 1
     4: gear 2
     5: gear 3
     6: gear 4
     7: gear 5
     8: gear 6
     9: gear 7
     10: gear 8
     11:
     12:
     13:
     14:
     15:
     16:
     17:
     18: Horn
*/
void JoystickRun() {
  myeffectparams[0].springPosition = Position;
  Joystick.setEffectParams(myeffectparams);
  Joystick.getForce(forces);
  Joystick.setXAxis(Position);

  Joystick.setButton(0, PaddleHornState & B00000001);
  Joystick.setButton(1, (PaddleHornState >> 1) & B00000001);
  Joystick.setButton(18, (PaddleHornState >> 2) & B00000001);
}
