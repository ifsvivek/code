from serial import Serial
import matplotlib.pyplot as plt
import time
from collections import deque

# Set backend
import matplotlib
matplotlib.use("TkAgg")  # or "Qt5Agg"

# Set up the serial connection
ser = Serial("/dev/ttyUSB0", 9600)

# Set up real-time plot
plt.ion()  # Enable interactive mode
fig, ax = plt.subplots()
ax.set_title("Light Sensor - 60 Second Window")
ax.set_xlabel("Time (seconds)")
ax.set_ylabel("Light Intensity")

# Store the last 60 seconds of data
max_time_window = 60  # 60 seconds
x = deque(maxlen=600)  # Store time points, 600 points for 60 seconds at 0.1s interval
y = deque(maxlen=600)  # Store light intensity values

(line,) = ax.plot(x, y)

# Start time for x-axis
start_time = time.time()

while True:
    try:
        # Read data from the serial connection
        data = ser.readline().decode("latin-1", errors="ignore").strip()

        # Append the current time and sensor data
        current_time = time.time() - start_time
        x.append(current_time)
        ligma = 1000 - float(data)
        y.append(ligma)

        # Update the plot with new data
        line.set_xdata(x)
        line.set_ydata(y)

        # Adjust the X and Y limits to ensure the plot is updated properly
        ax.set_xlim(max(0, current_time - max_time_window), current_time)
        ax.set_ylim(min(y) - 10, max(y) + 10)  # Add padding for readability

        # Add grid lines for better visualization
        ax.grid(True)

        # Redraw the figure
        fig.canvas.draw()
        fig.canvas.flush_events()

        # Small pause for UI to update (10Hz refresh rate)
        time.sleep(0.1)

    except KeyboardInterrupt:
        ser.close()  # Close the serial connection when interrupted
        break
    except ValueError:
        # Handle the case where the data cannot be converted to float
        continue
