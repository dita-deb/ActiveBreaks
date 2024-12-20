// ActiveBreaks.ino
// Arduino sketch for the ActiveBreaks project

#include <Arduino.h>

const int ledPin = 13;         // Pin connected to the LED
const int buzzerPin = 12;      // Pin connected to the buzzer
const int buttonPin = 2;       // Pin connected to the snooze button

bool breakTime = false;         // Flag to indicate break time
unsigned long breakInterval = 600000; // Break interval (10 minutes)
unsigned long lastActivityTime; // Last recorded activity time

void setup() {
    pinMode(ledPin, OUTPUT);      // Set LED pin as output
    pinMode(buzzerPin, OUTPUT);   // Set buzzer pin as output
    pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with pull-up resistor

    Serial.begin(9600);            // Initialize serial communication
    lastActivityTime = millis();   // Initialize last activity time
}

void loop() {
    // Check for incoming serial data
    if (Serial.available() > 0) {
        // Read the data sent from the Python script
        char incomingByte = Serial.read();
        if (incomingByte == 'B') {
            breakTime = true; // Break signal received
            alertUser();      // Alert user for break
        }
    }

    // Check if it's time for a break based on the interval
    if (millis() - lastActivityTime >= breakInterval && !breakTime) {
        breakTime = true;  // Time for a break
        alertUser();       // Alert user for break
    }

    // Check if the snooze button is pressed
    if (digitalRead(buttonPin) == LOW) {
        snoozeBreak();      // Snooze the break
    }

    // Reset the breakTime flag if break is taken
    if (breakTime && !digitalRead(buttonPin)) {
        breakTime = false;
        lastActivityTime = millis(); // Reset activity time after break
    }
}

void alertUser() {
    digitalWrite(ledPin, HIGH);  // Turn on the LED
    tone(buzzerPin, 1000);       // Sound buzzer at 1000 Hz
    delay(500);                  // Alert for half a second
    noTone(buzzerPin);           // Stop sound
    digitalWrite(ledPin, LOW);   // Turn off the LED
}

void snoozeBreak() {
    breakTime = false;           // Disable break reminder
    lastActivityTime = millis(); // Reset activity timer
    delay(2000);                 // Wait for 2 seconds before resuming
}
