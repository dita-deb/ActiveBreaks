#include <Arduino.h>

const int ledPin = 13;          // Pin connected to the LED
const int buzzerPin = 12;       // Pin connected to the buzzer
unsigned long timerStart = 0;   // Timer start time
unsigned long timerDuration = 1200; // Timer duration in seconds (20 minutes)
bool timerActive = false;        // Timer status

void setup() {
    pinMode(ledPin, OUTPUT);     // Set LED pin as output
    pinMode(buzzerPin, OUTPUT);  // Set buzzer pin as output
    Serial.begin(9600);          // Initialize serial communication
}

void loop() {
    // Check if data is available on the serial port
    if (Serial.available() > 0) {
        char input = Serial.read(); // Read the incoming byte

        if (input == 's' || input == 'S') { // Start timer
            if (!timerActive) {
                startTimer();
            }
        } else if (input == 'z' || input == 'Z') { // Snooze timer
            if (timerActive) {
                snoozeTimer();
            }
        }
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
    Serial.println("Timer started for 20 minutes.");
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
