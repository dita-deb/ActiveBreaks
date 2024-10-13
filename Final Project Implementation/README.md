# Final Project Implementation Guide

This guide outlines the steps to set up and run the **ActiveBreaks** project using the finalized code files: **`ActiveBreaks_202020.ino`** for the Arduino and **`activity_tracker.py`** for the Python application.

## Prerequisites

### Hardware Requirements

- An Arduino board (e.g., Arduino Mega 2560)
- An LED
- A buzzer
- A push button
- Jumper wires
- A breadboard (optional)

### Software Requirements

- Arduino IDE (latest version)
- Python (version 3.x)
- Libraries: 
  - `pynput` (for monitoring keyboard/mouse activity)
  - `pyserial` (for serial communication with Arduino)

## Step-by-Step Implementation

### Step 1: Set Up the Hardware

1. **Connect Components**:
   - Connect the LED to digital pin 13.
   - Connect the buzzer to digital pin 12.
   - Connect the push button to digital pin 2 (using a pull-up resistor configuration).

   ![Circuit Diagram](path_to_your_circuit_diagram.png)  
   *(Replace with the actual path to your circuit diagram image.)*

### Step 2: Upload Arduino Code

1. **Open Arduino IDE**:
   - Launch the Arduino IDE on your computer.

2. **Load the Code**:
   - Open the **`ActiveBreaks_202020.ino`** file in the Arduino IDE.

3. **Select the Correct Board**:
   - Go to `Tools` > `Board` and select your Arduino model (e.g., Arduino Mega 2560).

4. **Select the Correct Port**:
   - Go to `Tools` > `Port` and choose the port where your Arduino is connected.

5. **Upload the Code**:
   - Click the upload button (right arrow icon) to compile and upload the sketch to the Arduino.

### Step 3: Set Up the Python Application

1. **Install Required Libraries**:
   - Open a terminal or command prompt and run the following commands:
     ```bash
     pip install pynput pyserial
     ```

2. **Load the Python Code**:
   - Open the **`activity_tracker.py`** file in a text editor or IDE.

3. **Configure Serial Port**:
   - In the Python script, ensure that the serial port matches the one used by the Arduino. You may need to adjust the following line in `activity_tracker.py`:
     ```python
     ser = serial.Serial('COM_PORT', 9600)  # Replace 'COM_PORT' with your Arduino port
     ```

### Step 4: Run the Python Application

1. **Run the Script**:
   - In your terminal or command prompt, navigate to the directory containing `activity_tracker.py`.
   - Execute the script with the following command:
     ```bash
     python activity_tracker.py
     ```

2. **Monitor Activity**:
   - The Python application will start monitoring your keyboard and mouse activity. It will send signals to the Arduino to activate the LED and buzzer when it's time for a break.

### Step 5: Use the System

1. **Interact with the Application**:
   - Use your computer normally. The application will track your activity and prompt you to take breaks at the specified intervals.
   - Press the connected button to snooze break reminders if necessary.

## Conclusion

Following these steps, you should successfully recreate and run the **ActiveBreaks** project. Feel free to modify the code and hardware setup as per your requirements to enhance the user experience further.

For more detailed information, refer to the individual file descriptions in the **README.md**.
