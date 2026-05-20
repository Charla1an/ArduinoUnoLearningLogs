# Serial-Controlled RGB System

## Overview


This project lets you control an RGB LED entirely through the Arduino Serial Monitor using simple text commands. You can pick colors and adjust brightness levels interactively — all in real time, no extra hardware needed.
The focus here was on getting more comfortable with serial communication, command handling, and building a modular RGB control system.

## Features

* Serial-based color selection
* Adjustable brightness control
* Multiple RGB color presets
* Real-time LED updates
* Input validation using constrained brightness values

## Components Used

* Arduino Uno R3
* RGB LED
* Resistors
* Breadboard
* Jumper Wires

## Concepts Learned

* Serial communication
* String input handling
* PWM brightness control
* Modular programming using functions
* Input validation with `constrain()`

## Challenges Faced

Handling both string-based color input and numeric brightness input within the same program required careful serial input management. Getting the RGB intensity values to scale correctly — while keeping colors looking consistent across different brightness levels — was another problem that took some working through.

## Future Improvements

* Add support for custom RGB values
* Add animated color effects
* Improve command parsing
* Add EEPROM memory support for saved settings
