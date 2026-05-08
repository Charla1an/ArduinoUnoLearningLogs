# 4-bit Binary Counter (First Attempt)

## Overview

This project displays numbers from 0 to 15 in binary using 4 LEDs.

## Components Used

* Arduino Uno
* 4 LEDs
* 4 × 220Ω resistors
* Breadboard
* Jumper wires

## How It Works

* Input: Predefined logic in the code
* Processing: The program manually sets each LED HIGH or LOW to represent binary values
* Output: LEDs turn on/off in a sequence that represents numbers from 0 to 15 in binary

## What I Tried

Since I needed to repeatedly turn LEDs on and off, I created two functions that take the LED pin as input and switch it ON or OFF.
Using these functions, I manually wrote all 16 binary combinations for the 4 LEDs.

## Challenges Faced

* Managing multiple outputs at once was initially confusing
* Writing every combination manually made the code long and repetitive
* Synchronizing LED states correctly required careful checking

## What I Learned

* How binary values can be represented using physical outputs
* How to control multiple LEDs using Arduino
* How functions can reduce repetition in code
* The importance of structuring code for readability and scalability

## Improvements that could be made

* Replace repetitive manual logic with loops
* Make the program more compact and scalable
* Improve overall code structure and readability

## Images

(add images later)

## Code

(See `code.ino` in this folder)
