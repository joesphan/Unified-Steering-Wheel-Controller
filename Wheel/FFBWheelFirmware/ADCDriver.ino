#include "defines.h"
/*
   ADCDriver: 12 bit adc driver for the atmega32u4
*/
void ADCDriverInit() {
  pinMode(ADC_PIN, OUTPUT);
  // clear when match, up to icr3 (mode 14)
  // prescaler /1, clear at ocr3a, set at rollover
  TCCR3A = B10101010;
  TCCR3B = B10011001;
  //set to 12 bit, what the total counter counts up to
  ICR3H = B00001111;
  ICR3L = B11111111;
  
  //set to 2048 (0 on diff signal)
  //OCR3AH = B00001000;     //right shift for high 8 bits
  //OCR3AL = B00000000;   //bit mask, probably not neccassary
}
/*
 * ADC: 0-4096 input
 */
void ADCSend(int pulseWidth) {
  OCR3AH = pulseWidth >> 8;     //right shift for high 8 bits
  OCR3AL = pulseWidth & 0xFF;   //bit mask, probably not neccassary
}
