import numpy as np
import matplotlib.pyplot as plt

plt.axis([0, 10, 0, 1])
x_values = []
y_values = []

while True:
    y = np.random.random()
    x_values.append(len(x_values))
    y_values.append(y)
    plt.plot(x_values, y_values, color='blue')
    plt.text(len(x_values)-0.8, y+0.05, f"{y:.2f}", color='black', fontsize=10)
    plt.pause(0.01)
