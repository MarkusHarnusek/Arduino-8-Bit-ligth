#include <Arduino.h>

#define LENGTH 8 //define the amount of leds on the board
#define DELAY 50 //define the delay time between each led
#define SYNC_PIN 4 //define the pin for the sync button
#define SYNC_DELAY 25 //define the delay time for the sync 

int ledpins[LENGTH] = {12,11,10,9,8,7,6,5}; //define the pins for the leds

void setup() {
  for (int i = 0; i < LENGTH; i++) {
    pinMode(ledpins[i], OUTPUT); //set the pins as output
  }

    pinMode(SYNC_PIN, INPUT_PULLUP); //set the sync pin as input pullup for now
}

void loop() {
    for (int i = 0; i < LENGTH; i++) {
        digitalWrite(ledpins[i], HIGH); //turn on the led
        delay(DELAY); //wait for the defined delay time

        if (i != 0) {
            digitalWrite(ledpins[i - 1], LOW); //turn off the previous led
        }
    }

    sync(); //call the sync function to handle the sync button

    while (digitalRead(SYNC_PIN) == HIGH) {
        // Wait for the sync button to be released
    }

    for (int i = LENGTH - 1; i >= 0; i--) {
        digitalWrite(ledpins[i], HIGH); //turn on the led
        delay(DELAY); //wait for the defined delay time

        if (i != LENGTH - 1) {
            digitalWrite(ledpins[i + 1], LOW); //turn off the next led
        }
    }
}

void sync() {
    pinMode(SYNC_PIN, OUTPUT); //set the sync pin as output
    digitalWrite(SYNC_PIN, HIGH); //set the sync pin to high
    delay(SYNC_DELAY); //wait for the defined sync delay time
    digitalWrite(SYNC_PIN, LOW); //set the sync pin to low
    pinMode(SYNC_PIN, INPUT_PULLUP); //set the sync pin back to input pullup
}