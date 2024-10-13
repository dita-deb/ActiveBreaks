void loop() {
    // Check for incoming serial data
    if (Serial.available() > 0) {
        // Read the data sent from the Python script
        char incomingByte = Serial.read();
        Serial.println("Received: " + String(incomingByte)); // Send acknowledgment
        // Add existing break handling logic...
    }
}
