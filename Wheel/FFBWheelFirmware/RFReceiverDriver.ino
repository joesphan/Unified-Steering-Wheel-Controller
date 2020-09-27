#include "defines.h"
/*
   RFReceiverDriver
   receives data from the ESP8266 receiver via UART (DSUB-1)
*/

byte SerialBuffer[9];
extern byte PaddleHornState;

void RFReceiverInit() {
  Serial1.begin(115200);
}

/*
 * RFReceiver
 * Receives 9 bytes from buffer if byte 0 is capital letter
 * otherwise it only receives byte 0 (1 byte)
 */
void RFReceive() {
  if (Serial.available()) {               //if data is availble to read
    SerialBuffer[0] = Serial1.read();
    if (isUpperCase((char)SerialBuffer[0])) {      //if data Starts with a capital letter, read the rest of it
      for (int i = 1; i < 9; i++) {
        SerialBuffer[i] = Serial1.read();
      }
      parseBuffer();
    }
  }
}
/*
 * parseBuffer()
 * consult docs.docx
 */
void parseBuffer() {
  switch (SerialBuffer[0]) {
    case 'A':
      PaddleHornState = SerialBuffer[1] & B00000111;    //bit mask to prevent other errors
    break;
    case 'B':
    break;
    case 'C':
    break;
    case 'D':
    break;
  }
}
