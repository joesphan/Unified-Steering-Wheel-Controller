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
- PCB boards
- standardized enclosure

## Theory of Operation

Controller for FFB wheel and peripherals

-Atmega 32u4

-[FFB Library](https://github.com/joesphan/ArduinoJoystickWithFFBLibrary) (thanks to the original author)

-Generic Servo Drive

-cutomizable and expandable controller

-wireless perhipheral add-ons (check docs for more detail)

## Servo Drive

The unified controller board's output is a standard CNC differential +/-10V + EN signal to control the motor.

## Encoder

Run with interrupts from servo drive. Two phase bog standard signal.

## Code Documentation

under \Documentation

## DIY kits and fully assembled

Want to help me pay for my tuition? DIY kits and fully assembled controller kits will be available soon. It will include a case and everything you need to assemble/PnP yourself. Target cost is around $50.
