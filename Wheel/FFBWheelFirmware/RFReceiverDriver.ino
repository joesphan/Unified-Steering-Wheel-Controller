/*
   RFReceiverDriver
   receives data from the ESP8266 receiver via UART (DSUB-1)
*/

byte SerialBuffer[9];
extern byte PaddleState;

void RFReceiverInit() {
  Serial1.begin(115200);
}
void RFReceive() {
  if (Serial.available()) {               //if data is availble to read
    SerialBuffer[0] = Serial1.read();
    if (SerialBuffer[0].isupper()) {      //if data Starts with a capital letter, read the rest of it
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
      PaddleState = SerialBuffer[1] & B00000011;    //bit mask to prevent other errors
    break;
    case 'B':
    break;
    case 'C':
    break;
    case 'D':
    break;
  }
}
