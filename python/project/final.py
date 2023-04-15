from serial import Serial
import matplotlib.pyplot as plt

ser = Serial('COM4', 9600)
plt.ion()
fig, ax = plt.subplots()
x, y = [], []
line, = ax.plot(x, y)
while True:
    try:
        data = ser.readline().decode().strip()
        x.append(len(x))
        y.append(float(data))
        line.set_data(x, y)
        ax.relim()
        ax.autoscale_view(True,True,True)
        fig.canvas.draw()
        fig.canvas.flush_events()
    except KeyboardInterrupt:
        ser.close()
        break