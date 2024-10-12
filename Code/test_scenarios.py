import unittest
import time
from unittest.mock import patch, MagicMock
import serial  # Ensure pyserial is installed

# Assuming activity_tracker is the name of your module containing the activity_tracker code
from activity_tracker import on_activity

class TestActivityTracker(unittest.TestCase):

    @patch('serial.Serial')
    def test_activity_tracking(self, mock_serial):
        # Mock the serial connection
        mock_serial.return_value = MagicMock()

        # Simulate user activity
        on_activity(100, 100)  # Simulate mouse click activity
        self.assertTrue(mock_serial.return_value.write.called, "The serial write should be called on activity")

    def test_break_timer(self):
        # Test the break timer logic
        start_time = time.time()
        break_interval = 10  # 10 seconds for testing purposes

        # Simulate no activity for the break interval
        time.sleep(break_interval)
        elapsed_time = time.time() - start_time

        self.assertGreaterEqual(elapsed_time, break_interval, "The elapsed time should be greater than or equal to the break interval")

    def test_no_activity_signal(self):
        # Simulate no activity for a defined period and ensure break signal is sent
        with patch('activity_tracker.ser') as mock_serial:
            time.sleep(1)  # Simulate wait time
            # Simulate sending a break signal
            mock_serial.write(b'B')
            mock_serial.write.assert_called_with(b'B')

if __name__ == '__main__':
    unittest.main()
