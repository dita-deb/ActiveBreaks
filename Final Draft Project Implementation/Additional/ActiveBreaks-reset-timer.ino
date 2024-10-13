//no user keyboard or mouse input just hardware

#include <Arduino.h>

const int ledPin = 13;          // Pin connected to the LED
const int buzzerPin = 12;        // Pin connected to the buzzer
const int buttonPin = 2;        // Pin connected to the button (0 key)
unsigned long timerStart = 0;   // Timer start time
unsigned long timerDuration = 120; // Timer duration in seconds (2 minutes)
bool timerActive = false;        // Timer status

void setup() {
    pinMode(ledPin, OUTPUT);     // Set LED pin as output
    pinMode(buzzerPin, OUTPUT);  // Set buzzer pin as output
    pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with pull-up resistor
    Serial.begin(9600);          // Initialize serial communication
}

void loop() {
    // Check if the button is pressed (LOW due to pull-up)
    if (digitalRead(buttonPin) == LOW) {
        if (!timerActive) {       // If timer is not active, start it
            startTimer();
        } else {
            snoozeTimer();         // If timer is active, snooze it
        }
        delay(300); // Debounce delay
    }

    // Check if the timer is active
    if (timerActive) {
        unsigned long elapsed = (millis() - timerStart) / 1000; // Calculate elapsed time in seconds
        unsigned long remaining = timerDuration - elapsed; // Calculate remaining time

        if (remaining <= 0) {
            soundBuzzer(); // Sound the buzzer when timer is up
        } else if (elapsed % 1 == 0) { // Update every second
            Serial.print("Time remaining: ");
            Serial.print(remaining);
            Serial.println(" seconds");
            delay(1000); // Delay for 1 second before the next update
        }
    }
}

void startTimer() {
    digitalWrite(ledPin, HIGH);   // Turn on LED
    timerStart = millis();         // Record start time
    timerActive = true;            // Set timer active
    Serial.println("Timer started for 2 minutes.");
}

void snoozeTimer() {
    timerActive = false;           // Deactivate the timer
    digitalWrite(ledPin, LOW);    // Turn off LED
    Serial.println("Timer snoozed.");
}

void soundBuzzer() {
    digitalWrite(buzzerPin, HIGH); // Sound the buzzer
    delay(2000);                    // Sound for 2 seconds
    digitalWrite(buzzerPin, LOW);  // Turn off the buzzer
    snoozeTimer();                 // Reset the timer and turn off the LED
}
