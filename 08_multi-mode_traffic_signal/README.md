# Multi-Mode Traffic Light System

## Overview

This project simulates a traffic light system that behaves differently depending on the time of day. During daytime hours, it runs through the normal red, yellow, and green cycle. Once it switches to nighttime, it drops into a blinking yellow caution mode — just like a real intersection late at night.
I built this to deepen my understanding of timing systems, state-based behavior, and structured control logic on Arduino.

## Features

* Simulated 24-hour traffic cycle
* Normal daytime traffic light sequence
* Nighttime blinking yellow caution mode
* Time-based behavior switching
* Real-time Serial Monitor debugging

## Components Used

* Arduino Uno R3
* Red LED
* Yellow LED
* Green LED
* Push Button
* Resistors
* Breadboard
* Jumper Wires

## Concepts Learned

* Timing with `millis()`
* State-based system behavior
* Conditional logic
* Time simulation
* Serial debugging

## Challenges Faced

The trickiest part was juggling multiple timing states while also keeping a simulated 24-hour cycle running smoothly. Making sure the system transitioned cleanly between daytime and nighttime modes — without disrupting the traffic sequence mid-cycle — took some careful thinking.

## Future Improvements

* Replace remaining delays with a fully non-blocking system
* Add pedestrian crossing controls
* Add LCD countdown timers
* Add configurable timing modes
