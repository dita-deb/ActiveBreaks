int ledPin = 13;       // LED pin
int buzzerPin = 12;    // Buzzer pin
int buttonPin = 2;     // Push button pin
bool snooze = false;   // Snooze state

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);  // Using internal pull-up resistor

    Serial.begin(9600);  // Initialize serial communication
}

void loop() {
    // Check if snooze button is pressed
    if (digitalRead(buttonPin) == LOW) {
        snooze = true;  // Enable snooze mode
        digitalWrite(buzzerPin, LOW); // Turn off buzzer immediately
        Serial.println("Snooze activated!");  // Debug statement
        delay(500);      // Debounce delay
    }

    // Read from serial to determine break reminder
    if (Serial.available()) {
        char command = Serial.read();  // Read incoming command

        if (command == 'B' && !snooze) {
            // Activate break reminder (LED + buzzer)
            digitalWrite(ledPin, HIGH);
            tone(buzzerPin, 1000);  // Buzzer at 1kHz
            delay(5000);            // 5-second reminder
            noTone(buzzerPin);
            digitalWrite(ledPin, LOW);
        } else if (command == 'S') {
            // Handle snooze (skip this reminder)
            snooze = false;  // Reset snooze state
            Serial.println("Snooze disabled!");  // Debug statement
        }
    }
}
