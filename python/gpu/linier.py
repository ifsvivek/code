import numpy as np
import matplotlib.pyplot as plt

# Generate some sample data
x = np.array([0, 1, 2, 3, 4, 5])
y = np.array([1, 3, 5, 7, 9, 11])

# Plot the sample data
plt.scatter(x, y)
plt.xlabel('X')
plt.ylabel('Y')
plt.show()

# Define the linear regression function
def linear_regression(x, y):
    n = np.size(x)
    m_x, m_y = np.mean(x), np.mean(y)
    SS_xy = np.sum(y*x - n*m_y*m_x)
    SS_xx = np.sum(x*x - n*m_x*m_x)
    slope = SS_xy / SS_xx
    intercept = m_y - slope*m_x
    return (slope, intercept)

# Compute the slope and intercept for the linear regression line
slope, intercept = linear_regression(x, y)

# Plot the linear regression line
plt.scatter(x, y)
plt.plot(x, intercept + slope*x, 'r')
plt.xlabel('X')
plt.ylabel('Y')
plt.show()
