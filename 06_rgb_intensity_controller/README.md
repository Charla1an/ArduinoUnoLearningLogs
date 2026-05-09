# RGB Intensity Controller

## Overview

This project uses an RGB LED, three buttons, and a potentiometer to let you mix custom colours by hand. Each button picks a colour channel — red, green, or blue — and the potentiometer sets how bright that channel should be. The result updates on the LED in real time, so you can dial in any colour combination you want.
It brought together several core Arduino concepts: PWM output, analog input, button handling, and managing persistent RGB state values.

## Components Used

* Arduino Uno
* RGB LED 
* 3 220 Ohm resistors
* 3 Push Buttons
* Potentiometer
* Jumper Cables
* Breadboard

## How It Works

Press a button to select which colour channel you want to adjust, then turn the potentiometer to set its brightness. The Arduino reads the potentiometer using `analogRead()` and maps that value to a PWM range. The other two channels stay saved in the background, so you're always building on what you've already set rather than starting over.
The selected colour channel updates dynamically while the other colour values remain stored, allowing custom RGB colours to be built gradually.

* Input: Button presses and potentiometer input
* Processing: The active channel is tracked, and potentiometer values are mapped to brightness levels 
* Output: RGB LED updates live as you turn the knob

## Development Notes

I started with three separate boolean variables to track which channel was selected. As the logic grew, that got messy fast, so I replaced all three with a single `selectedChannel` variable. That one change made the code significantly cleaner and easier to follow.
The trickiest part was making sure the potentiometer only affected the active channel without accidentally touching the other two. Getting that isolation right took some careful structuring of the main loop.

## What I Learned

* How to manage multiple inputs working together in one project
* How to maintain persistent RGB state values
* How PWM can dynamically control RGB intensity
* How a small structural decision (like consolidating variables) can have a big impact on code clarity

## Planned Improvements

* Smoother transitions between colours

* A reset/off button to clear the LED

* Serial Monitor output showing live RGB values

* EEPROM support to save favourite colour combinations


## Images

[Add your circuit images here]

## Code

[Code](https://github.com/Charla1an/ArduinoUnoLearningLogs/blob/main/06_rgb_intensity_controller/code.ino)
