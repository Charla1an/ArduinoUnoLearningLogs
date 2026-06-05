# Ultrasonic Object Locator

## Overview

This project combines an HC-SR04 ultrasonic sensor with a servo motor to scan the surrounding area and identify the nearest object. It introduces the idea of combining a sensor with an actuator into a single autonomous behavior, rather than controlling each component in isolation.
## Components Used

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* SG90 Servo Motor
* Breadboard
* Jumper Wires

## How It Works

The servo sweeps from 0° to 180° and back. At each angle, the ultrasonic sensor measures the distance to the nearest object. The program tracks the smallest distance recorded during the sweep and the angle at which it occurred. Once the full sweep is complete, the servo rotates to point at that position before the next scan begins.

## Concepts Introduced

* **Sensor-Actuator Integration:** Rather than reading a sensor or driving a motor in isolation, this project combines both into a coordinated behavior — the sensor gathers environmental data, and the servo responds to it.
* **Dynamic Value Tracking:** Distance measurements are compared on the fly across the sweep to continuously update the best candidate position.

## Challenges

My original plan was considerably more ambitious: the system would scan continuously, a button press would lock onto the closest object, and the servo would then actively track that object as it moved.
While designing this, I realized the feature set had naturally evolved into a state-machine problem — multiple operating modes, concurrent timers, and target update logic all running together. I experimented with restructuring the code around `millis()` to make it non-blocking, but found I was trying to introduce several new concepts at once without a solid handle on any of them.
Rather than pushing through with something I didn't fully understand, I scaled back to a complete and reliable scan-and-locate system. The final version still introduces meaningful ideas while leaving target tracking as a future improvement for when I have more experience with event-driven architectures.

## Improvements

* Add a lock-on mode with a button input.
* Implement non-blocking scanning using `millis()`.
* Track a moving target by searching around its last known position.
* Display scan results on an LCD.

---

**Circuit:** [Image]  
**[Code](https://github.com/Charla1an/ArduinoUnoLearningLogs/blob/main/14_ultrasonic_object_locator/code.ino)** 
