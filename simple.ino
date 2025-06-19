#include <Arduino.h>

#define LENGTH 8 //define the amount of leds on the board
#define DELAY 50 //define the delay time between each led

int ledpins[LENGTH] = {12,11,10,9,8,7,6,5}; //define the pins for the leds

void setup() {
  for (int i = 0; i < LENGTH; i++) {
    pinMode(ledpins[i], OUTPUT); //set the pins as output
  }
}

void loop() {
    for (int i = 0; i < LENGTH; i++) {
        digitalWrite(ledpins[i], HIGH); //turn on the led
        delay(DELAY); //wait for the defined delay time

        if (i != 0) {
            digitalWrite(ledpins[i - 1], LOW); //turn off the previous led
        }
    }

    for (int i = LENGTH - 1; i >= 0; i--) {
        digitalWrite(ledpins[i], HIGH); //turn on the led
        delay(DELAY); //wait for the defined delay time

        if (i != LENGTH - 1) {
            digitalWrite(ledpins[i + 1], LOW); //turn off the next led
        }
    }
}