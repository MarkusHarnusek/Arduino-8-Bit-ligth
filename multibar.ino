#include <Arduino.h>

#define DELAY 50 // Delay between LED changes in milliseconds
#define LEDLENGTH 8 // Number of LEDs per board
#define BOARDS 4 // Number of boards

int ledPins[LEDLENGTH] = { 12, 11, 10, 9, 8, 7, 6, 5 }; // LED pin assignments

void setup() {
  // Set all LED pins as outputs
  for (int i = 0; i < LEDLENGTH; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Set board select pins as inputs initially
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
}

void loop() {
  // Forward animation for each board
  for (int j = 0; j < BOARDS; j++) {
    for (int i = 0; i < LEDLENGTH; i++) {
      digitalWrite(ledPins[i], HIGH); // Turn on current LED

      if (i != 0) {
        digitalWrite(ledPins[i - 1], LOW); // Turn off previous LED
      }

      delay(DELAY); // Wait for the defined delay
    }

    digitalWrite(ledPins[LEDLENGTH - 1], LOW); // Turn off last LED
    setBoard(j + 1); // Select the next board
  }

  // Reverse animation for each board
  for (int j = BOARDS - 1; j >= 0; j--) {
    for (int i = LEDLENGTH - 1; i >= 0; i--) {
      digitalWrite(ledPins[i], HIGH); // Turn on current LED

      if (i != LEDLENGTH - 1) {
        digitalWrite(ledPins[i + 1], LOW); // Turn off next LED
      }

      delay(DELAY); // Wait for the defined delay
    }

    digitalWrite(ledPins[0], LOW); // Turn off first LED
    setBoard(j + 2); // Select the next board
  }
}

// Function to select which board is active
void setBoard(int board) {
  for (int i = 2; i < BOARDS + 2; i++) {
    if (board == i) {
      pinMode(i, OUTPUT); // Set pin as output for selected board
      digitalWrite(i, LOW); // Activate selected board
    } else {
      digitalWrite(i, HIGH); // Deactivate other boards
      pinMode(i, INPUT); // Set pin as input for unselected boards
    }
  }
}