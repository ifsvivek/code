import subprocess
import time
import matplotlib.pyplot as plt
plt.ion()
fig, ax = plt.subplots()

x, y = [], []
line, = ax.plot(x, y)

while True:
    try:
        process = subprocess.Popen(['ping', '-n', '1', '1.1.1.1'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        out, err = process.communicate()
        out = out.decode('utf-8')
        response_time = out.split('time=')[1].split(' ')[0]

        try:
            response_time = float(response_time)
        except ValueError:
            continue

        x.append(len(x))
        y.append(response_time)
        line.set_data(x, y)
        ax.relim()
        ax.autoscale_view(True,True,True)
        fig.canvas.draw()
        fig.canvas.flush_events()

        time.sleep(1)
    except KeyboardInterrupt:
        break
