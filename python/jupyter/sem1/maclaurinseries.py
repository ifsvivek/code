# Converted from maclaurinseries.ipynb

# %%
import numpy as np
from matplotlib import pyplot as plt
from sympy import *
x= Symbol ('x')
y=sin(x)+cos(x)
format
x0= float (0)
dy= diff (y,x)
d2y = diff (y,x,2)
d3y = diff (y,x,3)
yat = lambdify (x,y)
dyat = lambdify (x,dy)
d2yat = lambdify (x,d2y)
d3yat = lambdify (x,d3y)
y=yat(x0)+((x-x0)/2)* dyat (x0)+((x-x0)**2/6)* d2yat (x0)+((x-x0)**3/24)*d3yat (x0)
print ( simplify (y))
yat = lambdify (x,y)
print ("%.3f" % yat(10*(pi/180)))
def f(x):
  return np.sin (1*x)+np.cos (x)

x = np. linspace (-10 , 10)


plt . plot (x, yat (x), color ='red')
plt . plot (x, f(x), color ='green')
plt . ylim ([-3, 3])
plt . grid ()
plt . show ()

