# Unified Sim Controller

##### Done:

- hardware done
- hardware differential centering upon power loss implemented
- firmware mostly complete
- overspeed safety implemented
- endstop damping implemented
- flowchart
- Wireless perhipherals: wheel buttons, pedals, shifter

##### Todo:

- documentation of code
- wheel damping adjustment
- figure out how to drop the 220v transformer
- add calibrate wheel button, gain adjustment potentiomter, etc.

## Theory of Operation

Controller for FFB wheel and peripherals

-Atmega 32u4

-[FFB Library](https://github.com/joesphan/ArduinoJoystickWithFFBLibrary) (thanks to the original author)

-Generic Servo Drive

-cutomizable and expandable controller

-wireless perhipheral add-ons



## Servo Drive

All servo drives available are similar, but different. They have a universal CNC interface (although not the same port shape and pinout). There is a datasheet on the servo drives that goes into detail.



The interface board's output is a differential +/-10V signal to control the motor. This interface is available and is backwards compatible with some of the earliest servo drives. The servo runs on 220V, for now I have it on an ACME 600-120-120 750VA transformer. Putting it on 120V causes an undervoltage, although the rails read 165V. Theoretically this servo should be able to run on 220VDC. A voltage doubler circuit might be a future improvement.

## Encoder

I've tested using interrupts, and they work mighty fine with the 10,000ppr encoder. Through the servo's communication interface, there is two pins that output an encoder signal.

## Shifter Paddles
- 433mhz wireless
- 6 bolt pattern mount
- attiny13 uC

## Code Documentation

under \Documentation
