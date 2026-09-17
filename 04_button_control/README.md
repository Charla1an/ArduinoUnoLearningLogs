# Project 4 — Button Control

## Overview
Project 4 is the first digital-input project: two small programs where a pushbutton controls an LED. Version 4A is a direct ON/OFF switch, version 4B is a toggle where each press flips the LED's state. It's the point where the Arduino moves from just running outputs to reacting to something happening in the real world.

## Components Used
- Arduino Uno
- Push button
- LED
- 220Ω resistor (LED)
- Breadboard
- Jumper wires

## How It Works
**4A — Basic ON/OFF**
The button (pin 10) is read with `digitalRead()` using `INPUT_PULLUP`, so the pin sits HIGH by default and goes LOW while the button is pressed — inverted compared to a typical pull-down setup. A simple `if/else` drives the LED (pin 6) straight off that reading: pressed = on, released = off.

**4B — Toggle**
Same wiring, different logic. Instead of mirroring the button state, the LED gets its own `ledState` variable, and `prevButtonState` is used to catch the exact moment the button goes from released to pressed — the HIGH → LOW edge. Each time that transition is detected, `ledState` flips with `ledState = !ledState`, so the LED changes once per press instead of re-triggering on every loop while the button is held down.

## Concepts Introduced
- **Digital input (`digitalRead`, `INPUT_PULLUP`):** reading a button's state, and understanding that with the internal pull-up enabled, the button reads LOW when pressed and HIGH when released — the opposite of what feels intuitive at first.
- **Edge detection:** comparing the current reading against the previous one to catch a single press event, rather than reacting continuously while the button is held.

## Challenges
- Button wiring was confusing at first, before the pull-up behavior made sense.
- `INPUT_PULLUP`'s inverted logic (LOW = pressed) took some getting used to.
- Checking `buttonState == LOW` alone wasn't enough to build a toggle — done every loop, that just keeps re-toggling while the button is held, rather than reacting once per press.
- Worked through how to detect a single press event instead of a continuous reaction, which led to introducing `prevButtonState` and moving from the straightforward implementation to an edge-detection one.

## Improvements
Debouncing wasn't implemented at this stage — mechanical buttons can produce several rapid HIGH/LOW transitions on a single physical press, and this version doesn't filter that out. That's the logical next step for a more reliable version.

---

**Code:** [`Basic On-Off`](./basic_on-off.ino) · [`Toggle Button`](./toggle_button.ino)