import serial
import time
from pynput import mouse, keyboard

# Define constants for serial port and baud rate
SERIAL_PORT = 'COM6'  # Change this to the correct port for your setup
BAUD_RATE = 9600

# Initialize the serial connection
try:
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
except serial.SerialException as e:
    print(f"Error opening serial port: {e}")
    ser = None

# Function to handle mouse activity
def on_activity(x, y):
    print(f"Mouse activity detected at ({x}, {y})")
    if ser:
        ser.write(b'A')  # Send an activity signal to the serial port

# Function to handle keyboard activity
def on_key_press(key):
    print(f"Keyboard activity detected: {key}")
    if ser:
        ser.write(b'A')  # Send an activity signal to the serial port

# Set up mouse and keyboard listeners
mouse_listener = mouse.Listener(on_click=on_activity)
keyboard_listener = keyboard.Listener(on_press=on_key_press)

# Start listeners
mouse_listener.start()
keyboard_listener.start()

# Break timer setup
break_interval = 300  # 5 minutes in seconds
last_activity_time = time.time()

try:
    while True:
        time.sleep(1)
        # Check if break interval has elapsed
        if time.time() - last_activity_time > break_interval:
            if ser:
                ser.write(b'B')  # Send a break signal to the serial port
                print("Break signal sent.")
            last_activity_time = time.time()  # Reset the timer

except KeyboardInterrupt:
    print("Exiting the activity tracker...")
finally:
    mouse_listener.stop()
    keyboard_listener.stop()
    if ser:
        ser.close()
