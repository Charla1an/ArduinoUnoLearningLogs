# Temperature Warning System

## Overview

This is a temperature monitoring and warning system built with a thermistor, an RGB LED, and a buzzer. The system keeps a continuous eye on temperature levels and adjusts both its visual and audio behavior depending on what range it detects.The focus for this one was on analog sensors, event-driven alerts, and building a properly non-blocking timing system using `millis()`.
## Features

* Continuous temperature monitoring
* Multiple temperature status zones
* RGB LED status indication
* Flashing warning mode for high temperatures
* Audio alert system using a buzzer
* Non-blocking flashing behavior using `millis()`

## Components Used

* Arduino Uno R3
* Thermistor
* RGB LED
* Active Buzzer
* Resistors
* Breadboard
* Jumper Wires

## Concepts Learned

* Analog sensor reading
* Event-based system behavior
* Non-blocking timing using `millis()`
* PWM RGB control
* Alert state management
* Conditional system transitions

## Challenges Faced

The main challenge was building a flashing alert system that didn't freeze the rest of the program. Using `millis()` instead of blocking delays was the solution, but getting it to feel truly responsive took some iteration.
Managing multiple temperature states cleanly — while keeping the warning system stable and not glitchy — also required careful thinking about how transitions were handled.
One more specific challenge: the RGB LED in this project was a common-anode type, which means PWM values behave in reverse compared to a common-cathode LED. That was a bit of a head-scratcher at first, but an interesting hardware detail to work through.

## Future Improvements

* Add LCD temperature display
* Add adjustable temperature thresholds
* Add temperature averaging for more stable readings
* Add data logging through the Serial Plotter
