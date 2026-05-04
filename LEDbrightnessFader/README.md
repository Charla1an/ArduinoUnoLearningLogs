# LED Brightness Fader

This project smoothly fades an LED from completely off to full brightness and back using PWM.


## Components Used

* Arduino Uno
* Red LED
* 330 ohm resistor
* Breadboard
* Jumper cables

## How It Works

A loop gradually increases the brightness value from 0 to 255 using analogWrite(), making the LED brighter over time.
Another loop decreases the value from 255 back to 0, creating a smooth fading effect.

* Input:
* Processing: Loop changes brightness values step by step
* Output: LED brightness changes smoothly

## What I Tried

I used `for` loops to continuously change the brightness value instead of manually setting each level. This made the code shorter and easier to control.
## Challenges Faced

Understanding the syntax of `for` loops was slightly confusing at first, especially how initialization, condition, and increment work together.

## What I Learned

* PWM controls brightness by rapidly switching the signal on and off at different ratios.
* `analogWrite()` uses values from 0–255 (8-bit range).
* Loops can automate gradual changes over time.

## Improvements (Future Version)

* Allow user control of fade speed using input

## Images

## Code

[View Arduino Code] (https://github.com/Charla1an/Arduino-Uno-Captain-s-Logs-/blob/main/LEDbrightnessFader/code.ino)
