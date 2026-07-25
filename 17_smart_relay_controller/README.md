# Smart Relay Controller

## Overview
This project introduces safe control of an inductive load — a relay — using a transistor as a switch instead of driving the relay coil directly from an Arduino pin. A push button toggles the relay state, a status LED mirrors that state, and the Serial Monitor reports the relay's current state on each toggle.

## Components Used
- Arduino Uno R3
- 5V Relay (LU-5-R)
- S8050 NPN Transistor
- 1N4001 Flyback Diode
- Push Button
- LED
- 220 Ω resistor (LED)
- 1 kΩ resistor (transistor base)
- Breadboard
- Jumper wires

## How It Works
1. The button's current reading is compared against its previous reading each loop to detect the moment it's pressed (edge detection).
2. Each press toggles a software relay state variable.
3. The Arduino writes HIGH or LOW to the transistor base accordingly.
4. The transistor switches the relay coil on or off, energizing or de-energizing it accordingly.
5. The flyback diode protects the transistor from the voltage spike generated when the relay coil de-energizes.
6. The status LED updates to reflect the relay state.
7. The Serial Monitor prints `Relay: ON` or `Relay: OFF` on each toggle.

## Concepts Introduced

**Hardware**
- Relay operation — coil vs. contacts
- Common (COM), Normally Open (NO), Normally Closed (NC)

**Electronics**
- NPN transistor as a low-side switch
- Base resistor
- Current amplification
- Inductive loads and flyback voltage
- Flyback diode protection
- Safely interfacing a microcontroller with higher-current loads

**Programming**
- Edge detection
- State management
- Toggle logic with boolean variables
- Ternary operator for conditional Serial output

## Core Learning Objective
The goal wasn't just to make a relay click. It was to understand how a microcontroller safely interfaces with higher-current inductive loads — through transistor switching, flyback protection, and the electrical isolation a relay's contacts provide from its control circuit.

## Challenges
- The relay didn't fit comfortably on the breadboard, so I wired it in with female-to-male jumpers instead — which introduced enough mechanical instability to cause intermittent relay chatter during testing.
- I initially confused the relay's coil terminals with its contact terminals, mixing up the control side and the load side. Working through that forced me to actually understand the relay's control circuit (coil) and load circuit (contacts) as separate things, not just wire them correctly by luck.
- Understanding why the flyback diode is needed took more than memorizing "put a diode here." I had to reason through what happens to the energy stored in the coil's magnetic field when current is suddenly cut, and how that produces a voltage spike that can damage the transistor.

## Key Takeaways
- Arduino pins shouldn't drive relay coils directly.
- A transistor acts as the power switch instead.
- The base resistor limits the base current to a safe value for both the Arduino pin and the transistor.
- The flyback diode provides a safe path for the coil's current while the magnetic field collapses, preventing a damaging voltage spike across the transistor.
- Relay contacts are electrically isolated from the coil.
- NO and NC contacts are chosen based on the desired default state and fail-safe behavior.

## Possible Improvements
- Software debouncing
- Long-press functionality
- Auto-off timer
- Double-click activation
- Audible feedback
- External power supply for larger loads
- Switching an actual external device instead of an LED

## Repository Notes
Built with PlatformIO, written in C++. Focuses on safe interfacing between a microcontroller and an inductive load while introducing transistor switching and flyback protection.