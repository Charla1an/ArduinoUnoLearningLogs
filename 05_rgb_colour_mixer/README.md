# RGB Colour Controller

## Overview

This project controls an RGB LED via the Serial Monitor. Users can select from a set of preloaded colours or enter custom RGB values manually. It was built as a hands-on way to explore Serial communication, PWM output, and clean code organisation on the Arduino Uno.
## Components Used

* Arduino Uno
* Bread Board
* RGB LED
* Jumper Cables
* 220 ohm resistors

## How It Works

The Arduino listens for input through the Serial Monitor. Entering a preset colour name loads its predefined RGB values; entering `custom` prompts the user for individual red, green, and blue intensities.
All LED output is handled through a dedicated `setColour()` function, which keeps the code clean and avoids scattering `analogWrite()` calls throughout the sketch.

* Input: Colour name or custom RGB values via Serial Monitor
* Processing: Values are validated and passed to `setColour()`
* Output: RGB LED displays the selected colour

## Development Notes


The first version called `analogWrite()` directly for every colour, which got repetitive quickly. Refactoring that logic into a reusable `setColour()` function made the code significantly easier to read and extend — a small but worthwhile improvement.
## Challenges Faced

Working with a common anode RGB LED was initially confusing, since brightness values need to be inverted compared to a common cathode setup. Handling Serial input reliably — particularly when switching between strings and integers — also required some experimentation before it behaved consistently.

## What I Learned

* How to use Serial input with both strings and integers
* How RGB LEDs mix colours using PWM
* How functions can reduce repeated code
* How to organize larger Arduino programs more cleanly

## Planned Improvements
* Add smoother colour transitions
* Add button or potentiometer control
* Add more preset colours
* Create a simple menu system for colour selection

## Images

[Add your circuit images here]

## Code

[code](https://github.com/Charla1an/ArduinoUnoLearningLogs/blob/main/RGBColourMixer/code.ino)
