# Reaction Timer Game

## Overview

This is a reaction timer game built with an Arduino Uno, an LED, and a push button. The idea is simple — the system waits for a random amount of time, then turns on the LED. Your job? Press the button as fast as you can once it lights up. Your reaction time gets displayed in the Serial Monitor.

## Features

* Randomized start delay
* Reaction time measurement
* False-start detection
* Serial Monitor feedback
* Real-time button interaction

## Components Used

* Arduino Uno R3
* LED
* Push Button
* Resistors
* Breadboard
* Jumper Wires

## Concepts Learned

* Event-driven logic
* Timing using `millis()`
* Button input handling
* Conditional statements
* Serial communication

## Challenges Faced

One of the trickier parts was handling false starts correctly without messing up the timing system. Getting the reaction timer to start at exactly the right moment — and not accidentally during the random delay phase — took a bit of figuring out, but it was a good problem to work through.

## Future Improvements

* Add multiple difficulty modes
* Add a high-score system
* Add RGB LED feedback
* Add sound effects using a buzzer
