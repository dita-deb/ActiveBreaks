
# Limiting Implications of Initial Files: ActiveBreaks_202020.ino and activity_tracker.py

## 1. User Input Mechanism
- **Initial Approach:** The `ActiveBreaks_202020.ino` relied on a physical button press to start or snooze the timer. This limited flexibility in user interaction, requiring direct physical engagement.
- **Preference Limitation:** Later expressed desire for keyboard input was not accommodated, highlighting the need for versatile input methods.

## 2. Timer Functionality
- **Basic Timer Logic:** Basic countdown functionality existed but lacked advanced features such as countdown displays or periodic updates.
- **Limitation of Feedback:** The absence of real-time countdowns made it difficult for users to gauge remaining time, indicating a need for more informative feedback mechanisms.

## 3. Integration and Synchronization
- **Disconnected Systems:** The `activity_tracker.py` and Arduino code operated independently, limiting data sharing and synchronization (e.g., triggering buzzer based on activity).
- **Preference for Unified Control:** Integrating functionalities could provide a more cohesive user experience, allowing for synchronized activity tracking and alerting.

## 4. Code Complexity and Modularity
- **Initial Complexity:** Original implementations may have been complex and challenging to modify for timer duration or user input changes.
- **Desire for Simplicity:** The importance of clean, modular code became clear as you moved towards complex features, essential for future updates based on evolving preferences.

## Conclusion
The original files had limitations in user interaction, timer functionality, integration, and code complexity. Addressing these issues by incorporating keyboard input, enhancing timer features, and integrating functionalities would better align with your evolving preferences for a more interactive and responsive system.

# Additonal Files Note

These additional files show a very rudimentary version of the alarm system. 'ActiveBreaks_reset_timer.ino' file works.The integration to the Python script is in the works.
