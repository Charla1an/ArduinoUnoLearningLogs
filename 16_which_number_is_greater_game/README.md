# Which Number Is Greater? (Shift Register Display Controller)
## Overview 
This project introduces the 74HC595 shift register and demonstrates how multiple outputs can be controlled using just a few Arduino pins. Two daisy-chained shift registers drive two 7-segment displays, which are used in a simple comparison game as a way to put the hardware through its paces.
## Components Used 
- Arduino Uno 
- 2 × SN74HC595 Shift Registers
- 2 × Common Cathode 7-Segment Displays
- 14 × 220 Ω Resistors
- 2 × Push Buttons
- 2 × LEDs (Correct / Incorrect Indicators)
- Breadboard
- Jumper Wires

## How It Works 
Two random digits are generated and displayed on separate 7-segment displays. The player picks the larger number by pressing the corresponding button. A green LED confirms a correct answer; a red LED signals an incorrect one. A new round then begins automatically.
The displays are driven through two daisy-chained 74HC595 shift registers. Rather than controlling each segment directly from Arduino pins, digit patterns are stored in a lookup table and transmitted serially to the shift registers using the `shiftOut()` function.

## Concepts Introduced 
- **74HC595 Shift Registers:** Multiple outputs controlled using only three Arduino pins through serial-to-parallel conversion.
- **Daisy Chaining:** Two shift registers linked together, allowing sixteen output bits to be driven through a single data line.
- **Lookup Tables:** Segment patterns stored as data in an array rather than hardcoded into conditional statements.
- **Hardware Abstraction:** Display patterns treated as data to be sent to hardware, rather than manually toggling individual segments.
- **Edge Detection:** Button presses registered only on the transition from released to pressed.
- **Random Number Generation:** New rounds generated using randomly selected digit pairs.


# Challenges 
The trickiest part was wiring and debugging the shift registers. Initially, only one display worked correctly — the second either stayed blank or showed wrong segments. Understanding how data actually propagates through daisy-chained devices required some experimentation. The key realization was that the first byte shifted out travels all the way to the far register, while the second byte stays in the nearer one. Once that clicked, the rest of the debugging became much more manageable.
Verifying wiring, segment mappings, and common cathode connections also took careful, methodical checking before everything behaved consistently.
One more subtle issue: several logic bugs turned out to be caused by accidentally using assignment (`=`) where comparison (`==`) was needed. A small distinction, but a reminder of how much a single character can matter.
## Improvements 
- Add an LCD interface for instructions and score tracking
- Track player score across multiple rounds
- Prevent repeated digit combinations
- Add difficulty levels with larger numerical ranges
- Refactor display handling into dedicated functions
- Add software debouncing for more reliable button input


---
**Circuit:** [Image] [**Code**](https://github.com/Charla1an/ArduinoUnoLearningLogs/blob/main/16_which_number_is_greater_game/code.ino)
