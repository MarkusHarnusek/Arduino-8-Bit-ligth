# 8-Bit Light Arduino Project

This project demonstrates various LED bar animations and multi-board control using an Arduino MEGA 2560. It includes several example sketches for different scenarios:

## Files

- **simple.ino**: Basic LED bar animation, lighting up LEDs in sequence and then in reverse.
- **multibar.ino**: Controls multiple LED bars (boards) and animates them in both directions, with logic to select and activate different boards.
- **communication.ino**: Demonstrates basic communication and synchronization between two Arduinos using a digital pin and a sync button.

## Hardware Requirements
- Arduino Uno or compatible board(s)
- 8 LEDs per board, with appropriate resistors
- Jumper wires
- (Optional) Multiple Arduino boards for multi-board and communication examples

## Key Concepts
- Sequential LED control using arrays
- Board selection via digital pins
- Synchronization between multiple Arduinos
- Use of `pinMode`, `digitalWrite`, and `digitalRead`

## Usage
1. Open the desired `.ino` file in the Arduino IDE.
2. Connect the LEDs to the specified pins (see the `ledPins` array in each sketch).
3. Upload the sketch to your Arduino board.
4. For multi-board or communication examples, connect additional boards as described in the code comments.

## Notes
- Ensure all Arduinos share a common ground when communicating.
- Adjust pin numbers and delays as needed for your hardware setup.