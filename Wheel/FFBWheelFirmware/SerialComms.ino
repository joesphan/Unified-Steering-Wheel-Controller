#include "defines.h"
/*
   sends MCU data over to serial, for debug or other purposes
*/
void SendSerial(int Position, int FFBInput, int MotorForce, int OverTravel, int prevOverTravel, uint32_t rpm) {
  Serial.println("  ");
  Serial.print("Angle_in_steps: ");
  Serial.print(Position);
  Serial.print(" FFB_data: ");
  Serial.print(FFBInput);
  Serial.print(" Motor_drive_signal: ");
  Serial.print(MotorForce);
  Serial.print(" OverTravel: ");
  Serial.print(OverTravel);
  //Serial.print(" prevOverTravel: ");
  //Serial.print(prevOverTravel);
  Serial.print(" rpm: ");
  Serial.print(rpm);
}
