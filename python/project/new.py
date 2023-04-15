from serial import Serial
import matplotlib.pyplot as plt
ser = Serial('COM4', 9600)
plt.ion()
fig, ax = plt.subplots()
x, y1, y2 = [], [], []
line1, = ax.plot(x, y1, label='LDR')
ax.legend()
while True:
    try:
        data = ser.readline().decode().strip()
        ldrValue, potValue = data.split()
        x.append(len(x))
        y1.append(float(ldrValue))
        ax.relim()
        ax.autoscale_view(True,True,True)
        fig.canvas.draw()
        fig.canvas.flush_events()
    except KeyboardInterrupt:
        ser.close()
        break
