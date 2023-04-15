import numpy as np
import matplotlib.pyplot as plt

plt.axis([0, 10, 0, 1])
i=0
while True:
    y = np.random.random()
    plt.scatter(i, y)
    plt.pause(0.001)
    i+=1