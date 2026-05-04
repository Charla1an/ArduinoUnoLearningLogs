# Potentiometer Brightness Control

## Overview

This project controls the brightness of an LED using a potentiometer. Turning the knob changes the brightness in real time.

## Components Used

* Arduino Uno
* Potentiometer
* 330 ohm resistor
* Red LED
* Breadboard
* Jumper Cables

## How It Works

The Arduino reads the value from the potentiometer using `analogRead()`, which gives a value between 0 and 1023.
This value is scaled down to a range of 0 to 255 and sent to the LED using `analogWrite()` to control its brightness.
* Input: Potentiometer Position
* Processing: Scale input value from 0–1023 to 0–255
* Output: LED brightness changes based on input

## What I Tried

Initially, I connected the potentiometer directly to the LED, but that only changed the voltage manually.
Then I used the Arduino to read the potentiometer value, process it, and control the LED brightness using PWM.
I also added Serial output to see how the values changes.

## Challenges Faced

I initially struggled with setting up and using the Serial Monitor correctly, especially understanding how to read and interpret the incoming values.

## What I Learned

* How to read analog values using `analogRead()`
* How to scale values between different ranges.
* How `analogWrite()` controls brightness using PWM

## Improvements 

* Add filtering to reduce noise or flickering

## Images

[Add your circuit images here]

## Code

[View Arduino Code]
(https://github.com/Charla1an/Arduino-Uno-Captain-s-Logs-/blob/main/PotentiometerBrightnessController/code.ino)
