# Rotary Encoder Interface

## Overview

This project interfaces a KY-040 incremental rotary encoder with an Arduino Uno to track rotational position and direction, using interrupt-driven quadrature decoding. It reuses the shift-register-driven 7-segment display technique from earlier projects, this time paired with interrupt-driven encoder input for the first time. The decoded position is clamped to a single digit (0–9) and displayed on a single-digit 7-segment display driven through a 74HC595 shift register, and the encoder's built-in pushbutton resets the count to zero.

The focus of this project was understanding *how* rotary encoders actually work at the signal level — not just using a library to read one.

## Components Used

- Arduino Uno R3
- 1 × KY-040 Rotary Encoder
- 1 × SN74HC595 Shift Register
- 1 × Single-Digit 7-Segment Display
- Breadboard and Jumper Wires

## Wiring Notes

* **KY-040 CLK** → D2, **DT** → D3, **SW** → D5 (`INPUT_PULLUP`)
* **74HC595 SRCLK** (clock) → D13, **RCLK** (latch) → D7, **SER** (data) → D6

## How It Works

Incremental encoders like the KY-040 output two square-wave signals, CLK and DT, that are 90° out of phase with each other. Reading them together gives a 2-bit state, `(CLK << 1) | DT`, which takes one of four values (0–3) as the knob turns.

Before writing any decoding logic, I polled CLK and DT directly and logged the raw states while turning the knob by hand, to see the actual sequence of transitions for clockwise and counter-clockwise rotation. This confirmed the key idea behind quadrature encoding: direction is determined by the order in which states change, not by any single state on its own.

The final implementation moved from polling to interrupt-driven input. An interrupt is attached to CLK using `CHANGE`, and the interrupt service routine (ISR) is kept intentionally minimal — it only captures the current encoder state into a `volatile` variable. All of the direction decoding happens afterward in `loop()`, comparing the new state against the previous one and checking it against the known valid quadrature transitions. Transitions that don't match a valid movement are simply ignored rather than acted on.

The resulting position is clamped to a range of 0–9 and used to index a lookup table of 7-segment patterns, which is shifted out to the 74HC595 to light the display. The pushbutton is read with `INPUT_PULLUP` and resets the counter using edge detection (a HIGH → LOW transition), so holding the button down doesn't repeatedly reset the value.

## Concepts Introduced

- **Quadrature Encoding:** Direction comes from the order of transitions between two out-of-phase signals (CLK/DT), not from any single instantaneous state.
- **Interrupt-Driven Input:** Using `attachInterrupt()` with `CHANGE` to catch fast, asynchronous encoder movement without missing steps, while keeping the ISR minimal.
- **State Transition Validation:** Comparing successive states against a table of valid quadrature transitions, and ignoring transitions that fall outside it.
- **Edge Detection:** Button presses registered only on the HIGH → LOW transition, so holding it down doesn't repeatedly reset the counter.
- **Empirical Hardware Testing:** Confirming that cheap mechanical encoders can behave unreliably in ways a datasheet won't tell you, by testing across two separate units.

## Challenges

The direction logic was the hardest part of this project to get right. My first instinct was to try to read direction from a single instant of CLK/DT — it wasn't until I logged transitions over time that it clicked that direction only exists as a sequence, not a snapshot.

Moving from polling to interrupts introduced its own issues. I initially put a `Serial.print()` inside the ISR to debug it, which distorted the interrupt timing badly enough that I had to remove it and debug differently. I also ran into a `=` vs `==` bug while comparing states, which is an easy mistake to make and an easy one to miss.

I tried a simpler alternative at one point: trigger only on `RISING` and just sample DT to infer direction. It worked in principle, but testing showed the cheap KY-040 could return the wrong DT state on about 1 in 10 samples — and both of the encoders I had behaved this way, which told me it was a real characteristic of the hardware rather than one bad unit. I went back to full `CHANGE`-based quadrature decoding, which turned out to be much more reliable.

Mechanical bounce and fast rotation could still occasionally produce a transition outside the valid quadrature sequence. Rather than building a more complex debounce system, I chose to just ignore invalid transitions — a deliberate trade-off that accepts the hardware's limitations instead of over-engineering around them.

I also hit a strange 74HC595/display failure that only showed up in one project folder, even though the exact same code worked correctly after copying it into another folder. I never fully diagnosed the cause and treated it as a build/project-folder issue rather than a hardware or code problem, and moved forward using the working folder.

## Improvements

- Add an LCD or menu system for more flexible position/mode display — deliberately left out of this version to keep the project focused on the encoder itself
- Add EEPROM storage so the counter value survives a power cycle
- Extend the counter beyond a single digit so it isn't clamped to 0–9
- Add filtering for the rare invalid transitions instead of simply ignoring them
- Compare this from-scratch decoder against a standard rotary encoder library

<!-- ## Media

![Project 20 hardware setup](images/project-setup.jpg)

**Demonstration:** [Watch the project demo](video/project-demo.mp4) -->