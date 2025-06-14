# Converted from Lab-9.ipynb

# MARKDOWN CELL:
# 1.  dy/dx − 2y = 3ex with y(0) = 0 using Taylor series method at x = 0.1(0.1)0.3.
# %%
from numpy import array, zeros, exp

def taylor(deriv, x, y, xStop, h):
    X = []
    Y = []
    X.append(x)
    Y.append(y)
    while x < xStop:
        D = deriv(x, y)
        H = 1.0
        for j in range(3):
            H = H * h / (j + 1)
            y = y + D[j] * H
        x = x + h
        X.append(x)
        Y.append(y)
    return array(X), array(Y)

def deriv(x, y):
    D = zeros((4, 1))
    D[0] = 2 * y[0] + 3 * exp(x)
    D[1] = 4 * y[0] + 9 * exp(x)
    D[2] = 8 * y[0] + 21 * exp(x)
    D[3] = 16 * y[0] + 45 * exp(x)
    return D

x = 0.0
xStop = 0.3
y = array([0.0])
h = 0.1
X, Y = taylor(deriv, x, y, xStop, h)

for i in range(len(X)):
    print("The required values are: at x=%0.2f, y=%0.5f" % (X[i], Y[i]))

# MARKDOWN CELL:
# Q3
# %%

from numpy import array, zeros

def taylor(deriv, x, y, xStop, h):
    X = []
    Y = []
    X.append(x)
    Y.append(y)
    while x < xStop:
        D = deriv(x, y)
        H = 1.0
        for j in range(3):
            H = H * h / (j + 1)
            y = y + D[j] * H
        x = x + h
        X.append(x)
        Y.append(y)
    return array(X), array(Y)

def deriv(x, y):
    D = zeros((4, 1))
    D[0] = x - y[0]
    D[1] = 1 - y[0]
    D[2] = -1
    D[3] = 0
    return D

x = 0.0
xStop = 0.1
y = array([1.0])
h = 0.1
X, Y = taylor(deriv, x, y, xStop, h)

for i in range(len(X)):
    print("At x = %0.2f, y = %0.5f" % (X[i], Y[i]))

# MARKDOWN CELL:
# Q4.
# %%

from numpy import array, zeros

def taylor(deriv, x, y, xStop, h):
    X = []
    Y = []
    X.append(x)
    Y.append(y)
    while x < xStop:
        D = deriv(x, y)
        H = 1.0
        for j in range(3):
            H = H * h / (j + 1)
            y = y + D[j] * H
        x = x + h
        X.append(x)
        Y.append(y)
    return array(X), array(Y)

def deriv(x, y):
    D = zeros((4, 1))
    D[0] = x + y[0]**2
    D[1] = 1 + 2*y[0]
    D[2] = 2
    D[3] = 0
    return D

x = 0.0
xStop = 0.1
y = array([1.0])
h = 0.1
X, Y = taylor(deriv, x, y, xStop, h)

for i in range(len(X)):
    print("At x = %0.2f, y = %0.5f" % (X[i], Y[i]))

# MARKDOWN CELL:
# 2. To solve the ODE of the form dy
# dx = f(x, y) with initial conditions y(x0) = y0. The iterative
# formula is given by : y(x(i+1) = y(xi) + hf(xi
# , y(xi)).
# Solve: y
# ′ = e
# −x with y(0) = −1 using Euler’s method at x = 0.2(0.2)0.6
# %%
import numpy as np
import matplotlib.pyplot as plt

# Define parameters
f = lambda x, y: np.exp(-x)
h = 0.2
y0 = -1
n = 3

# Explicit Euler Method
y = np.zeros(n + 1)
x = np.zeros(n + 1)
y[0] = y0
x[0] = 0
for i in range(0, n):
    x[i + 1] = x[i] + h
    y[i + 1] = y[i] + h * f(x[i], y[i])

print("The required values are at x = {0:0.2f}, y = {1:0.5f}, x = {2:0.2f}, y = {3:0.5f}, x = {4:0.2f}, y = {5:0.5f}, x = {6:0.2f}, y = {7:0.5f}".format(x[0], y[0], x[1], y[1], x[2], y[2], x[3], y[3]))

# Plot the results
plt.plot(x, y, 'bo--', label='Approximate')
plt.plot(x, -np.exp(-x), 'g*-', label='Exact')
plt.title('Approximate and Exact Solution')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.grid()
plt.legend(loc='best')
plt.show()


# MARKDOWN CELL:
# 3. Solve: y′ = −2y + x3e −2x with y(0) = 1 using Euler’s method at x = 0.1, 0.2.
# %%
import numpy as np
import matplotlib . pyplot as plt
# Define parameters
f = lambda x , y: -2*y+( x ** 3 )*np .exp(-2*x ) # ODE
h = 0.1 # Step size
y0 = 1 # Initial Condition
n=2
# Explicit Euler Method
y[0] = y0
x[0]=0
for i in range (0 , n ):
    x[i+1]=x[i]+h
    y[i + 1] = y[i] + h*f ( x[i], y[i])
print ("The required values are at x= %0.2f , y=%0.5f , x=%0.2f , y=%0.5f ,x=%0.2f , y=%0.5f\n\n"%( x[0],y[0],x[1],y[1],x[2],y[2]) )
plt . plot (x , y , 'bo--', label =" Approximate ( Euler 's method )")
plt . title (" Solution by Euler 's method ")
plt . xlabel ('x')
plt . ylabel ('f(x)')
plt . grid ()
plt . legend ( loc ='best')
plt . show ()


# MARKDOWN CELL:
# 9.4. Solve y
# ′ = −ky with y(0) = 100 using modified Euler’s method at x = 100, by taking
# h = 25.
# %%
import numpy as np
import matplotlib . pyplot as plt
def modified_euler (f , x0 , y0 , h , n ):
    x = np . zeros ( n+1 )
    y = np . zeros ( n+1 )
    x[0] = x0
    y[0] = y0
    for i in range ( n ):
        x[i+1] = x[i] + h
        k1 = h * f ( x[i], y[i])
        k2 = h * f ( x[i+1], y[i] + k1 )
        y[i+1] = y[i] + 0.5 * ( k1 + k2 )
    return x , y
def f (x , y ):
    return -0.01 * y # ODE dy/dx = -ky
x0 = 0.0
y0 = 100.0
h = 25
n = 4
x , y = modified_euler (f , x0 , y0 , h , n )
print ("The required value at x= %0.2f , y=%0.5f"%( x[4],y[4]) )
print ("\n\n")
# Plotting the results
plt . plot (x , y , 'bo--')
plt . xlabel ('x')
plt . ylabel ('y')
plt . title ('Solution of dy/dx = -ky using Modified Euler \'s Method ')
plt . grid ( True )
plt . show ()


