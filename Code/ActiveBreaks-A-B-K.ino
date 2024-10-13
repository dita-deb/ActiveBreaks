//This is tested inside the Arduino IDE using the serial monitor

// Pin definitions
const int ledPin = 13;      // Pin for LED (change as needed)
const int buzzerPin = 12;    // Pin for Buzzer (change as needed)

// Initialize the LED and Buzzer
void setup() {
    Serial.begin(9600);       // Start serial communication at 9600 baud rate
    pinMode(ledPin, OUTPUT);  // Set the LED pin as output
    pinMode(buzzerPin, OUTPUT); // Set the Buzzer pin as output
}

// Main loop
void loop() {
    if (Serial.available() > 0) {  // Check if data is available
        char receivedChar = Serial.read();  // Read the incoming character

        // Respond based on the received character
        switch (receivedChar) {
            case 'A':
                // Activity detected: turn on the LED
                Serial.println("Activity detected!");
                digitalWrite(ledPin, HIGH);  // Turn on LED
                delay(100);                   // Keep it on for 100 ms
                digitalWrite(ledPin, LOW);   // Turn off LED
                break;

            case 'K':
                // Keyboard activity detected
                Serial.println("Keyboard activity detected!");
                // Additional action for keyboard activity can be added here
                break;

            case 'B':
                // Break signal: activate buzzer
                Serial.println("Break signal received!");
                tone(buzzerPin, 1000); // Send a tone to the buzzer at 1000 Hz
                delay(1000);            // Keep the buzzer on for 1 second
                noTone(buzzerPin);      // Turn off the buzzer
                break;

            default:
                Serial.println("Unknown command received.");
                break;
        }
    }
}
