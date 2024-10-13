import serial
import time
from pynput import keyboard

# Initialize serial communication with the Arduino
ser = serial.Serial('COM6', 9600)  # Change 'COMX' to your Arduino's COM port
time.sleep(2)  # Allow time for the serial connection to establish

# Callback function to handle keyboard activity
def on_activity(key):
    try:
        # Send a signal to Arduino when any key is pressed
        ser.write(b'K')  # Sending 'K' for Key activity
        print(f"Key {key} pressed.")
    except Exception as e:
        print(f"Error: {e}")

# Start listening for keyboard activity
with keyboard.Listener(on_press=on_activity) as listener:
    print("Listening for keyboard activity... Press ESC to stop.")
    listener.join()  # Keep the listener running
