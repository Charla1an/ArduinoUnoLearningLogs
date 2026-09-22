# Ultrasonic Parking Assistant

## Overview
Project 13 turns a single ultrasonic distance reading into a multi-level warning system: an HC-SR04 sensor drives a threshold-based response across three LEDs and a buzzer, with distance also logged to the Serial Monitor. It's the first project that combines several previously separate skills — sensor measurement, threshold logic, multiple outputs, and non-blocking timing — into one continuously running system.

## Components Used
- Arduino Uno
- HC-SR04 ultrasonic sensor
- Red LED
- Yellow LED
- Green LED
- Buzzer
- 220Ω resistors (LEDs)
- Breadboard
- Jumper wires

## How It Works
The HC-SR04 is triggered with a 10 µs pulse, and the echo duration is converted into distance with `pulseIn(echoPin, HIGH) * 0.017`. That distance is split into four zones, each with its own visual and audio response:

| Distance | LED | Buzzer |
|---|---|---|
| < 100 cm | Red | Rapid beeping |
| 100–200 cm | Yellow | Medium-speed beeping |
| 200–300 cm | Green | Slow beeping |
| ≥ 300 cm | Green | Off |

The closer the object gets, the more urgent the feedback becomes — faster beeping as the danger zone is approached.

The buzzer timing is the more interesting part: instead of `delay()`, the code uses `millis()` with timestamp variables (`event1`, `event2`, `event3`) to control each zone's beep interval — around 100 ms in the danger zone, progressively slower in the warning and safe zones. That keeps the sensor readable and the system responsive instead of freezing on a blocking delay every time it beeps.

## Concepts Introduced
- **Ultrasonic distance sensing:** triggering the HC-SR04 with a pulse and converting echo duration into distance via `pulseIn()`.
- **Non-blocking timing with `millis()`:** driving timed behavior (the buzzer patterns) using timestamps instead of `delay()`, so the sensor keeps getting read continuously.
- **Threshold-based, multi-output response:** one sensor reading driving several outputs — three LEDs and a buzzer — at once, rather than a single on/off result.

## Challenges
The specific wiring issues or debugging steps from building this one weren't recorded at the time, so rather than invent them, what's clear from the code itself is the jump in complexity: this is the first project that combines a sensor, three independent status outputs, a buzzer, distance thresholds, and `millis()`-based timing into a single continuously running system — a real step up from the earlier single-component exercises.

## Improvements
The readings here aren't smoothed or averaged. A later project (Project 19) reuses this same HC-SR04 setup and adds time-windowed averaging for steadier output — this version is the raw, unfiltered starting point.