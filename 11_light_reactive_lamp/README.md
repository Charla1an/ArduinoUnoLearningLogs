# Light-Reactive Smart Lamp

## Overview

This is a smart RGB lighting system that automatically adapts its behavior based on the ambient light around it. Using a photoresistor, the system detects whether conditions are daytime, evening, or nighttime and adjusts its lighting mode accordingly — with a potentiometer letting you fine-tune brightness on top of that.
The focus here was on sensor-driven systems, RGB control, and building something that responds dynamically to its environment.

## Features

* Automatic ambient light detection
* Multiple lighting modes based on brightness levels
* Adjustable brightness using a potentiometer
* Dynamic RGB color transitions
* Responsive mode switching during animation cycles

## Components Used

* Arduino Uno R3
* RGB LED
* Photoresistor
* Potentiometer
* Resistors
* Breadboard
* Jumper Wires

## Concepts Learned

* Analog sensor input
* RGB color mixing
* PWM brightness control
* Environmental state detection
* Function-based code organization
* Dynamic behavior control

## Challenges Faced

Getting smooth RGB transitions while still allowing the system to react quickly to changing light conditions was a tricky balance to strike. On top of that, scaling brightness correctly so colors stayed consistent across the full range of potentiometer values needed careful tuning.
Structuring multiple environmental modes cleanly — without RGB control logic bleeding all over the place — was another thing that pushed me to think more carefully about code organization.

## Future Improvements

* Replace delays with a non-blocking `millis()` system
* Add smoother color interpolation
* Add LCD status display
* Add customizable lighting presets
