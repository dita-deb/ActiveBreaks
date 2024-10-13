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

# Timer settings
activity_duration = 1200  # 20 minutes in seconds
last_activity_time = None  # Time of the last keyboard or mouse activity
timer_running = False  # Indicates if the timer is running

# Function to handle mouse activity
def on_activity(x, y, button, pressed):
    global last_activity_time, timer_running
    if pressed:  # Only log when the mouse button is pressed
        print(f"Mouse activity detected at ({x}, {y}) with button {button}")
        last_activity_time = time.time()  # Reset the timer
        timer_running = True  # Start the timer
        if ser:
            ser.write(b'A')  # Send an activity signal to the serial port

# Function to handle keyboard activity
def on_key_press(key):
    global last_activity_time, timer_running
    print(f"Keyboard activity detected: {key}")
    last_activity_time = time.time()  # Reset the timer
    timer_running = True  # Start the timer
    if ser:
        ser.write(b'K')  # Send an activity signal to the serial port

# Set up mouse and keyboard listeners
mouse_listener = mouse.Listener(on_click=on_activity)
keyboard_listener = keyboard.Listener(on_press=on_key_press)

# Start listeners
mouse_listener.start()
keyboard_listener.start()

try:
    while True:
        time.sleep(1)
        # Check if the timer is running and if the activity duration has elapsed
        if timer_running and last_activity_time:
            elapsed_time = time.time() - last_activity_time
            if elapsed_time >= activity_duration:
                if ser:
                    ser.write(b'B')  # Send a break signal to the serial port
                    print("Break signal sent.")
                # Reset the timer and activity tracking
                last_activity_time = None  # Reset the last activity time
                timer_running = False  # Stop the timer

except KeyboardInterrupt:
    print("Exiting the activity tracker...")
finally:
    mouse_listener.stop()
    keyboard_listener.stop()
    if ser:
        ser.close()
