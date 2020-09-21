# Custom Steering Wheel

##### Done:

- hardware done
- hardware differential centering upon power loss implemented
- firmware mostly complete
- overspeed safety implemented
- endstop damping implemented

##### Todo:

- documentation of code
- wheel damping adjustment
- flowchart
- figure out how to drop the 220v transformer
- wheel buttons, pedals, shifter
- add center wheel button

## Theory of Operation

-Atmega 32u4

-[FFB Library](https://github.com/joesphan/ArduinoJoystickWithFFBLibrary) (thanks to the original author)

-Big mige 130st

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



WIP

# deprecated:

## MadCatz xbox wheel (shredded to bits by the mige, along with a dell monitor)

|             Color/Stripe              |         Function         |
| :-----------------------------------: | :----------------------: |
|              Blue/Black              |           GND            |
|              Green/White              |            Y             |
|                 Green                 |            X             |
|             Orange/White              |            B             |
|             Yellow/Black              |            A             |
|              Blue/White               |           RSB            |
|               Red/White               |           LSB            |
|                 Blue                  | RB (Flappy paddle right) |
| [Brown](https://youtu.be/lzqCQxi3ENE) | LB (Flappy paddle left)  |
| Yellow/Orange | Back |
| Black | Start |
| Gray | Xbox Button |
| Yellow | Up |
|              Gray/White               |               Down                |
|              Brown/White              |               Left                |
|                Orange                 |         Rumble Motor Left         |
|                Purple                 |        Rumble Motor Right         |
|                  Red                  |                Vcc                |
| White | 5V |
| Orange/Black | P1 LED (active low, use resistor) |
| Red/Black | P2 LED (active low, use resistor) |
| Brown/Black | P3 LED (active low, use resistor) |
| Pink/Black | P4 LED (active low, use resistor) |

The steering wheel will carry an onboard SPI IO expander (mcp23s17), interfacing with all the buttons.

A spring cable will carry the SPI signals between the 32u4 and the wheel.
