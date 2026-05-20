# Multi-Pattern LED Animation System

## Overview

This is an interactive LED animation system built with 8 LEDs and 3 push buttons. Each button triggers a different animation pattern, letting you switch between visual behaviors on the fly in real time.
The focus for this one was on getting more comfortable with arrays, reusable functions, pattern generation, and bitwise operations in Arduino programming.

## Features

* Multiple LED animation modes
* Button-triggered pattern selection
* Sequential LED sweep animation
* Alternating even/odd LED animation
* Binary counting visualization using bit manipulation
* Reusable helper functions for cleaner logic

## Components Used

* Arduino Uno R3
* 8 LEDs
* 3 Push Buttons
* Resistors
* Breadboard
* Jumper Wires

## Concepts Learned

* Arrays
* For loops
* Bitwise operations using `bitRead()`
* Modular programming with functions
* Button state detection
* Pattern sequencing

## Challenges Faced

One of the bigger challenges was organizing multiple animation patterns without ending up with a mess of repetitive code. Keeping LED indexing and button state handling clean — so each animation behaved exactly as intended — required some careful structuring.
Understanding how binary values could directly drive LED states through bitwise operations was also a new concept that took a bit of time to click, but ended up being one of the more satisfying parts of the project.

## Future Improvements

* Replace delays with `millis()` for smoother multitasking
* Add adjustable animation speed
* Add RGB animation support
* Add custom animation pattern selection through Serial Monitor
