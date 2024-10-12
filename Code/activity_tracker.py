# activity_tracker.py
# Script to track user activity and send break reminders to Arduino

import time
import serial
from pynput import mouse, keyboard

# Configuration
SERIAL_PORT = 'COM3'  # Update this with your Arduino COM port
BAUD_RATE = 9600
BREAK_INTERVAL = 600  # Time in seconds before a break reminder (10 minutes)
check_interval = 5  # Interval to check for activity in seconds

# Serial communication setup
ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)

# Global variables
last_activity_time = time.time()
active = True  # Tracks whether the user is active

def on_activity(x, y):
    global last_activity_time, active
    last_activity_time = time.time()
    active = True

def on_key_press(key):
    on_activity(None, None)

# Listener for mouse and keyboard activity
mouse_listener = mouse.Listener(on_click=on_activity, on_scroll=on_activity)
keyboard_listener = keyboard.Listener(on_press=on_key_press)

mouse_listener.start()
keyboard_listener.start()

try:
    while True:
        # Check if it's time for a break
        current_time = time.time()
        if current_time - last_activity_time >= BREAK_INTERVAL:
            ser.write(b'B')  # Send break signal to Arduino
            active = False
            print("Time for a break! Sent signal to Arduino.")

        # Reset active status if no activity for a while
        if not active:
            print("No activity detected. Checking again...")

        time.sleep(check_interval)  # Check for activity every few seconds

except KeyboardInterrupt:
    print("Tracking stopped.")

finally:
    mouse_listener.stop()
    keyboard_listener.stop()
    ser.close()
