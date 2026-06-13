# Single-Digit 7-Segment Display Counter

## Overview
This project introduces 7-segment displays and lookup tables. A single-digit display is controlled using two buttons, letting you increment or decrement the displayed value with wraparound between 0 and 9.

## Components Used
- Arduino Uno
- Common Cathode 7-Segment Display
- 7 × 220 Ω Resistors
- 2 × Push Buttons
- Breadboard
- Jumper Wires

## How It Works
Each digit is represented by a predefined pattern stored in a two-dimensional array. When a button is pressed, the current digit updates and the corresponding segment pattern gets sent to the display. Edge detection ensures the counter only steps once per press rather than running continuously while the button is held.

## Concepts Introduced
- **Lookup Tables (2D Arrays):** Digit patterns are stored as data rather than being hardcoded into chains of if-statements.
- **Abstraction:** A dedicated display function handles all segment control, so the rest of the code only ever deals with digit values — not individual LEDs.
- **State Management:** The current digit is stored as a variable and updated based on user input.
 
## Challenges
Early on, I misidentified the display type and then damaged it while probing segment pins without a resistor in the current path. It was a straightforward mistake, but a useful one — it reinforced how important it is to understand a component's behavior before applying power, and to always have current limiting in place. After replacing the display and correctly identifying it as common cathode, the wiring and segment mapping process went much more smoothly.

The other challenge was wrapping my head around how a lookup table could directly drive hardware outputs. The key realization was that the segment pin array and the digit pattern array share the same indexing scheme — which means a single loop can translate stored data straight into physical pin states.

## Improvements
* Add software debouncing for more robust button handling
* Add support for hexadecimal digits (A–F)
* Use a shift register to reduce pin usage
* Expand to a multi-digit display

---

**Circuit:** [Image]  
[**Code**](https://github.com/Charla1an/ArduinoUnoLearningLogs/blob/main/15_single_digit_7-segment%20_display_counter/code.ino)
