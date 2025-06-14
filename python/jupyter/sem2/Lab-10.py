# Converted from Lab-10.ipynb

# MARKDOWN CELL:
# 10.1 Apply the Runge Kutta method to find the solution of dy/dx = 1 + (y/x) at y(2) taking
# h = 0.2. Given that y(1) = 2.

# %%
from sympy import *
import numpy as np

def RungeKutta(g, x0, h, y0, xn):
  x, y = symbols('x, y')
  f = lambdify([x, y], g)
  xt = x0 + h
  Y = [y0]
  while xt <= xn:
    k1 = h * f(x0, y0)
    k2 = h * f(x0 + h / 2, y0 + k1 / 2)
    k3 = h * f(x0 + h / 2, y0 + k2 / 2)
    k4 = h * f(x0 + h, y0 + k3)
    y1 = y0 + (1 / 6) * (k1 + 2 * k2 + 2 * k3 + k4)
    Y.append(y1)
    x0=xt
    y0=y1
    xt = xt + h
  return np.round(Y, 2)

RungeKutta('1+(y/x)', 1,0.2,2,2)


# %%
x0=1
y0=2
y1=2.2156
y2=2.4649
y3=2.7514
h=0.1
x1=x0+h
x2=x1+h
x3=x2+h
x4=x3+h
def f(x,y):
  return x ** 2+(y/2)
y10=f(x0,y0)

y11 =f(x1 ,y1)
y12 =f(x2 ,y2)
y13 =f(x3 ,y3)
y4p =y0+(4*h/3)*(2*y11-y12+2*y13)
print ('predicted value of y4 is %3.3f '%y4p)
y14 =f(x4 ,y4p )
for i in range(1,4):
  y4=y2+(h/3)*(y14+4*y13+y12)
  print('Corrected value of y4 after \t iteration %d is \t %3.5f\t'%(i,y4))
  y14=f(x4,y4)

