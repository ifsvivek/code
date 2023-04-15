import numpy as np
import matplotlib.pyplot as plt
x=np.arange(-10,10,0.001)
y=np.exp(x)
plt.plot(x,y)
plt.title('Exponential curve ')
plt.grid()
plt.show()