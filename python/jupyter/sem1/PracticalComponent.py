# Converted from PracticalComponent.ipynb

# MARKDOWN CELL:
# 1. Using modern mathematical tool write a program/code to plot the sine and cosine 
# curve.
# %%

import numpy as np
import matplotlib.pyplot as plt

x = np.arange(-10, 10, 0.001)
y1 = np.sin(x)
y2 = np.cos(x)

plt.plot(x, y1, x, y2) # plotting sine and cosine function together with same values of x
plt.title("Sine curve and cosine curve")
plt.xlabel("Values of x")
plt.ylabel("Values of sin(x) and cos(x)")
plt.grid()
plt.show()

# MARKDOWN CELL:
# 2. Using modern mathematical tool write a program/code to evaluate lim
# 𝑥→∞
# (1 + 𝑥1)?
# %%
from sympy import *
from math import inf

x = Symbol('x')
l = Limit((1 + 1/x) ** x, x, inf).doit()
display(l)

# MARKDOWN CELL:
# 3. Using modern mathematical tool write a program/code to test the consistency of the 
# equations, x+2y-z=1, 2x+y+4z=2, 3x+3y+4z=1.
# %%
import numpy as np

A = np.matrix([[1, 2, -1], [2, 1, 4], [3, 3, 4]])
B = np.matrix([[1], [2], [1]])
AB = np.concatenate((A, B), axis=1)

rA = np.linalg.matrix_rank(A)
rAB = np.linalg.matrix_rank(AB)
n = A.shape[1]

if rA == rAB:
    if rA == n:
        print("The system has a unique solution:")
        print(np.linalg.solve(A, B))
    else:
        print("The system has infinitely many solutions.")
else:
    print("The system of equations is inconsistent.")

# MARKDOWN CELL:
# 4. Using modern mathematical tool write a program/code to plot the curve 𝑟 = 2|𝑐𝑜𝑠2𝜃|
# %%
import matplotlib.pyplot as plt
import numpy as np

theta = np.linspace(0, 2*np.pi, 1000)
r = 2*np.abs(np.cos(2*theta))
plt.polar(theta, r, 'r')
plt.show()

# MARKDOWN CELL:
# 5. Using modern mathematical tool write a program/code to show that
# 𝑢𝑥𝑥 + 𝑢𝑦𝑦 = 0 𝑔𝑖𝑣𝑒𝑛 𝑢 = 𝑒𝑥(𝑥 𝑐𝑜𝑠(𝑦) − 𝑦 𝑠𝑖𝑛(𝑦)).
# %%
from sympy import *

x, y = symbols('x y')
u = exp(x)*(x*cos(y) - y*sin(y))
display(u)

dux = diff(u, x)
duy = diff(u, y)
uxx = diff(dux, x)
uyy = diff(duy, y)

w = uxx + uyy
w1 = simplify(w)

print('The Laplacian of u(x,y) is:', w1)

# MARKDOWN CELL:
# 6. Using modern mathematical tool write a program/code to find the largest eigen value 
# of 𝐴 = [
# 1
# 1
# 3
# 1
# 5
# 1
# 3
# 1
# 1] by power method.
# %%
import numpy as np

def normalize(x):
    fac = abs(x).max()
    x_n = x / x.max()
    return fac, x_n

x = np.array([1, 1, 1])
A = np.array([[1, 1, 3],
              [1, 5, 1],
              [3, 1, 1]])

for i in range(10):
    x = np.dot(A, x)
    lambda_1, x = normalize(x)

print('Dominant eigenvalue:', lambda_1)
print('Eigenvector:', x)

