# ActiveBreaks
A user-friendly tool that encourages regular breaks while effectively monitoring focus time to promote healthy work habits. Integrates software application with hardware.

- Problem:
  - Increased Sedentary Behavior: Prolonged screen time leads to health issues like eye strain (Computer Vision Syndrome), fatigue, musculoskeletal disorders, and mental burnout.
  - Productivity Loss: Without scheduled breaks, cognitive fatigue accumulates, reducing focus and performance.
  - Poor Work-Life Balance: Many individuals overwork without taking adequate breaks, especially in remote work or hybrid environments.
  - Lack of Awareness: People often underestimate how much time they spend at the computer without breaks, leading to physical and mental strain.
- Solution: ActiveBreaks provides a simple, automated reminder system to track continuous computer usage and alert users when it is time to take a break. By monitoring keyboard and mouse activity, the tool encourages users to take regular breaks to refresh and avoid burnout.
  - Pros:
    - Health Benefits: 
      - Reduces eye strain and prevents Repetitive Strain Injury (RSI).
      - Encourages physical movement, improving posture and circulation.
      - Promotes mental clarity and reduces stress.
    - Increased Productivity:
      - Breaks prevent cognitive fatigue, leading to sustained focus over time.
      - Aligns with productivity strategies like the Pomodoro Technique or 20-20-20 rule (taking a 20-second break every 20 minutes).
    - Customizable and Scalable:
      - Alerts can be tailored to suit user preferences (audio, pop-ups, LED lights).
      - Integrates well with hardware for physical reminders (e.g., buzzer or LED).
    - Real-Time Usage Data:
      - Collects and displays statistics on how much time users spend working without breaks, helping users identify areas for improvement.
  - Cons:
    - Interruptions May Distract Users:
      - If not implemented thoughtfully, break reminders could disrupt focus during deep work sessions.
      - Solution: Allow users to snooze alerts or adjust break intervals.
    - Limited Detection of Actual Breaks:
      - Simply tracking keyboard and mouse activity might not fully reflect whether users are taking meaningful breaks (e.g., someone could be browsing social media instead of resting).
    - Hardware Integration Challenges:
      - Integrating physical reminders with microcontrollers (e.g., Arduino) may require additional setup or hardware troubleshooting.
    - Adoption Resistance:
      - Users accustomed to working long hours might ignore the reminders, requiring encouragement and awareness-building for effective adoption.
- Hardware Implementation:
  - Microcontroller: Arduino Uno or ESP32 to manage physical reminders like LEDs or buzzers.
  - Sensors and Output Components:
    - Buzzer or LED: Alerts the user when it’s time for a break.
    - Button (Optional): A physical snooze button for delaying reminders.
  - Workflow:
    - Software: A Python script running on the computer tracks user activity (via pynput library).
    - Communication: The computer sends a signal to the Arduino/ESP32 via serial communication when a break reminder is triggered.
    - Hardware Response:
      - LED turns on or the buzzer beeps to indicate break time.
      - User can press a button to snooze the reminder (if implemented).
    - Optional Cloud Integration: Use an ESP32 with Wi-Fi to send break statistics to a web interface or dashboard.
--------
# NOTES:
This is part of a submission for IEEE Technothon 2024: transforming industries through automation and innovation.

## Requirements:
- What to Build
  - Participants build innovative hardware solutions using AI/ML and other automation. 

- What to Submit
  - Participants have two options to submit:

    1. Submit a 5-minute video that includes the problem you are tackling, the solution, the pros and cons, and the hardware implementation demo. The submission should be in VIDEO format and be 5 minutes max. The participants would then play this video at the judging event, where the judges would review it and ask questions, if any.

    2. Submit a presentation slide deck (5 slides max) that includes the problem you are tackling, the solution, pros and cons, and the hardware implementation demo. The demo should be a video embedded onto the slide deck (as a YouTube embed). The participants then present these slides at the judging event (5 min max) and the judges would review them and ask questions, if any.

