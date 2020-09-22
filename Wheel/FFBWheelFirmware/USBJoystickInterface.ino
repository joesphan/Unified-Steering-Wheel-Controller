//X-axis & Y-axis REQUIRED
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK, 2, 0,
                   true, true, true,
                   false, false, false,
                   false, false, false, false, false);
Gains mygains[2];
EffectParams myeffectparams[2];
int32_t forces[2] = {0};
int32_t friction[2] = {0};


//input states
//buttons
byte PaddleState = 0;

//axii
int Position;
uint16_t throttleState = 0;
uint16_t brakeState = 0;
uint16_t clutchState = 0;
uint16_t handbrakeState = 0;


void JoystickInit() {
  Joystick.setFFBRange(2048);
  Joystick.setXAxisRange(-MAX_STEPS, MAX_STEPS);
  mygains[0].totalGain = 800;
  Joystick.setGains(mygains);
  Joystick.begin();
  myeffectparams[0].springMaxPosition = MAX_STEPS;
}

void JoystickRun() {
  myeffectparams[0].springPosition = Position;
  Joystick.setEffectParams(myeffectparams);
  Joystick.getForce(forces);
  Joystick.setXAxis(Position);
  /*
   * 0: right Paddle
   * 1: left Paddle
   * 2: gear R
   * 3: gear 1
   * 4: gear 2
   * 5: gear 3
   * 6: gear 4
   * 7: gear 5
   * 8: gear 6
   * 9: gear 7
   * 10: gear 8
   * 11:
   */
  Joystick.setButton(0, PaddleState & B00000001);
  Joystick.setButton(1, PaddleState >> 1);
}
