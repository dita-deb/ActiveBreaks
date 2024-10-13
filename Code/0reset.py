import time
from pynput import mouse, keyboard
import serial

# Set up serial communication with Arduino
arduino = serial.Serial('COM6', 9600)  # Update 'COMX' to your Arduino port

activity_duration = 0  # Total activity time in seconds
activity_limit = 20 * 60  # 20 minutes in seconds
last_activity_time = time.time()

def on_activity(x=None, y=None):
    global last_activity_time
    last_activity_time = time.time()  # Update last activity time

# Setup listeners for mouse and keyboard activity
mouse_listener = mouse.Listener(on_move=on_activity, on_click=on_activity)
keyboard_listener = keyboard.Listener(on_press=on_activity)

# Start listeners
mouse_listener.start()
keyboard_listener.start()

print("Starting activity tracker...")

try:
    while True:
        # Check if there's activity
        current_time = time.time()
        if current_time - last_activity_time < 2:  # Reset the timer if activity is detected
            activity_duration += 1
        else:
            activity_duration = 0  # Reset if no activity

        # Check if the activity limit has been reached
        if activity_duration >= activity_limit:
            print("20 minutes of activity reached! Sending alert to Arduino.")
            arduino.write(b'1')  # Send signal to Arduino
            activity_duration = 0  # Reset duration after alert

        time.sleep(1)  # Check every second

except KeyboardInterrupt:
    print("Program terminated.")
finally:
    mouse_listener.stop()
    keyboard_listener.stop()
    arduino.close()
