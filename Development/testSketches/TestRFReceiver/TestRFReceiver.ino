/*
   RFReceiverDriver
   receives data from the 433mhz receiver via J6
   uses radiohead library
   bit structure:
   2 bits per transmission
        x               x
   Left paddle;   right paddle
   active high
*/
#include <RH_ASK.h>
#include <SPI.h>
#define RF_RX_PIN 2

byte paddleState = 0;

RH_ASK driver(2000, RF_RX_PIN, -1, 0);

void setup() {
  Serial.begin(9600);
  driver.init();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)) // Non-blocking
  {
    int i;
  driver.printBuffer("Got:", buf, buflen);

    Serial.println("  ");
    Serial.write(buf[0]);
    Serial.print("  ");
    Serial.print(buf[0], BIN);
    Serial.print("  ");
    Serial.write(buf[1]);
    Serial.print("  ");
    Serial.print(buf[1], BIN);
    Serial.print("  ");
  }
  //for delay across rf test
  if (buf[0] == '2') {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }


}
