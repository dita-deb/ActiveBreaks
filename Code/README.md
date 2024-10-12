# ActiveBreaks Code Folder

This folder contains the main code files for the **ActiveBreaks** project, a user-friendly tool designed to encourage regular breaks while monitoring focus time. Below is an explanation of each file included in this folder.

## Files Overview

### 1. ActiveBreaks.ino

**Description**:  
This is the Arduino sketch that runs on the microcontroller (e.g., Arduino Mega 2560). It controls the hardware components responsible for providing reminders to the user to take breaks. 

**Key Functions**:
- **Setup**: Initializes the serial communication and sets up the output pins for LEDs and buzzers.
- **Loop**: Continuously checks for incoming signals from the computer application. When it receives a signal indicating it’s time for a break, it activates the buzzer and lights up an LED to notify the user.
- **Snooze Functionality**: Optional feature that allows users to temporarily disable reminders if they are in the middle of an important task.

**Usage**:  
Upload this sketch to your Arduino board using the Arduino IDE. Make sure to connect the appropriate hardware components to the defined pins.

### 2. activity_tracker.py

**Description**:  
This Python script runs on the user's computer and monitors keyboard and mouse activity. It tracks how long the user has been active and sends break reminders based on the defined intervals.

**Key Functions**:
- **Activity Monitoring**: Uses the `pynput` library to listen for keyboard and mouse events, tracking user activity in real-time.
- **Break Timer**: Implements a timer that triggers break reminders when the user exceeds the defined active duration.
- **Serial Communication**: Establishes a connection with the Arduino via the `pyserial` library to send signals when it’s time for a break.

**Usage**:  
Run this script in your Python environment. Ensure that you have installed the required libraries (`pynput`, `pyserial`). Connect the Arduino to the computer and ensure that the serial port matches the one specified in the script.

### 3. test_scenarios.py

**Description**:  
This file contains unit tests for the `activity_tracker.py` script. It ensures that the activity monitoring and break reminder functionalities work as intended.

**Key Functions**:
- **Test Cases**: Includes various test cases to simulate user activity and inactivity, verifying that the appropriate responses occur.
- **Mocking**: Uses the `unittest` library along with `unittest.mock` to simulate serial communication and activity events, allowing for controlled testing environments without needing actual user input or hardware.
- **Assertions**: Validates that the break reminder signals are sent correctly and that the timer logic functions as expected.

**Usage**:  
Run this script using the command `python -m unittest test_scenarios.py`. Ensure that all dependencies are installed, and the `activity_tracker.py` file is accessible.

## Conclusion

These files work together to create a comprehensive solution that promotes healthy work habits by reminding users to take breaks. The **ActiveBreaks** tool combines software and hardware components for an effective user experience. For further development, consider adding more features such as customizable break intervals or integration with health-tracking applications.

Feel free to explore each file for a deeper understanding of how **ActiveBreaks** functions and how you can expand on its capabilities!