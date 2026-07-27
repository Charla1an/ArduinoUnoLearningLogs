# Project 18: Bidirectional DC Motor Control with L293D H-Bridge

## Overview
Controls the speed and direction of a DC motor (with a fan attached) using an L293D H-bridge driver. A potentiometer sets speed via PWM; three push buttons select direction — forward, reverse, or stop.

## Hardware Used
- Arduino Uno R3
- L293D motor driver
- DC motor with fan
- Potentiometer
- 3× push buttons (Forward, Reverse, Stop)
- External 4×AA battery pack for motor power

## How It Works
The L293D's logic supply (VCC1) runs off the Arduino's 5V rail; the motor supply (VCC2) is powered separately by the 4×AA battery pack (~6V), with all grounds tied together.

Speed comes from reading the potentiometer with `analogRead()` and mapping it to a PWM range written to the L293D's enable pin. The usable PWM range (175–255) was determined experimentally — lower values weren't enough to start the motor with the fan attached.

Direction is represented by an enum (FORWARD, REVERSE, STOP) rather than directly manipulating the H-bridge pins throughout the program. A setDirection() helper function abstracts the hardware control by translating each state into the appropriate logic levels using a switch statement.

## Concepts Introduced
- L293D H-bridge operation for bidirectional motor control
- PWM-based speed control
- Separating logic and motor power supplies
- Common ground across multiple power sources
- Button edge detection
- `enum` as a custom data type
- Helper functions and `switch` statements for state handling

## Challenges
Running the motor off the Arduino's USB supply caused intermittent resets and corrupted Serial output whenever the motor stalled or ran at low PWM. Moving the motor to its own battery supply fixed it, and demonstrated why embedded systems often power motors and logic from separate supplies.

Separately, the battery ground wasn't tied to the Arduino ground. This showed up as incorrect potentiometer readings, and took some debugging to trace back to the missing common ground.

Testing also exposed a gap between startup and running behavior: with the fan attached, the motor needed roughly PWM 200 to start from rest, but could keep running down to about PWM 170 once already spinning. Manually pushing past the initial static friction let it start at even lower PWM. This made the difference between startup and running torque — and the effect of mechanical load on starting current — something observed firsthand rather than just read about.