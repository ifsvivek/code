# Converted from Matlabexam.ipynb

# %%
# 1[i]  [Write a Python program to plot exponential (𝑒^𝑥), Sine and Cosine curves]

import numpy as np
import matplotlib.pyplot as plt

x = np.arange(-10, 10, 0.001) 
y = np.exp(x) 

plt.plot(x, y) 
plt.title("Exponential curve") 
plt.grid() 
plt.show() 


# %%
# 1[ii] [sine and cosine curves]

import numpy as np
import matplotlib.pyplot as plt

x = np.arange(-10, 10, 0.001)
y1 = np.sin(x)
y2 = np.cos(x)

plt.plot(x, y1, label='sin(x)')
plt.plot(x, y2, label='cos(x)')
plt.title("Sine Curve and Cosine Curve")
plt.xlabel("Values of x")
plt.ylabel("Values of sin(x) and cos(x)")
plt.grid()
plt.legend()
plt.show()


# %%
# 2 [Write a Python program to plot Strophoid : 𝑦^2(a − x) = 𝑥^2(a + x) a>0]

from sympy import *
x,y=symbols('x,y')
a=int(input('Enter a number:')) 
p2=plot_implicit(Eq(y**2*(a-x),x**2*(a+x)),(x,-5,5),(y,-5,5),title='Strophoid:$ y^2(a-x)=x^2(a+x) a>0$')


# %%
# 3 [Write a Python program to plot Four leaved Rose: 𝑟 = 2|𝑐𝑜𝑠2𝜃|.]

from pylab import*
theta = linspace(0, 2*np.pi, 1000)
r1 = 2 * abs(cos(2*theta))
polar(theta, r1,'b.')
show()

# %%
# 4 [Write a Python program to plot Circle: 𝑥 = 𝑎 𝑐𝑜𝑠(𝜃); 𝑦 = 𝑎 𝑠𝑖𝑛(𝜃).]

import numpy as np
import matplotlib . pyplot as plt
def circle ( r ):
  x = []
  y = [] 
  for theta in np . linspace (-2*np .pi , 2*np .pi , 100 ):

    x.append ( r*np .cos( theta ) )
    y.append ( r*np .sin( theta ) )

  plt . plot (x , y )
  plt . show () 
circle ( 5 ) 

# %%
# 5 [Write a Python program to find the radius of curvature for polar curves 𝑟 = 𝑎𝑠𝑖𝑛(𝑛𝑡) 𝑎𝑡 𝑡 = 𝑝𝑖/2 𝑎𝑛𝑑 𝑛 = 1.]

from sympy import *
t, r, a, n = symbols('t r a n')
r = a * sin(n*t)
r1 = Derivative(r, t).doit()
r2 = Derivative(r1, t).doit()
rho = (r**2 + r1**2)**(1.5) / (r**2 + 2*r1**2 - r*r2)
rho1 = rho.subs(t, pi/2)
rho1 = rho1.subs(n, 1)
print("The radius of curvature is:")
display(simplify(rho1))



# %%
# 6  [ Write a Python program to find the radius of curvature of 𝑥 = 𝑎𝑐𝑜𝑠(𝑡) ; 𝑦 = 𝑎 𝑠𝑖𝑛(𝑡). ]
from sympy import *
from sympy.abc import rho, x, y, r, K, t, a, b, c, alpha

x = a*cos(t)
y = a*sin(t)

dydx = simplify(Derivative(y, t).doit() / Derivative(x, t).doit()) 
rho = simplify((1 + dydx**2)**(3/2) / (Derivative(dydx, t).doit() / Derivative(x, t).doit()))

print('Radius of curvature is:')
display(ratsimp(rho))

t1 = pi/2
r1 = 5

rho1 = rho.subs(t, t1)
rho2 = rho1.subs(a, r1)

print('\nRadius of curvature at r=5 and t=pi/2 is:', simplify(rho2))

curvature = 1 / rho2
print('\n\nCurvature at (5, pi/2) is:', float(curvature))


# %%
# 7 [Prove that if 𝑢 = 𝑒𝑥(𝑥𝑐𝑜𝑠(𝑦) − 𝑦 𝑠𝑖𝑛(𝑦)) then 𝑢𝑥𝑥 + 𝑢𝑦𝑦 = 0 by using Python program.]

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
print('Ans:', float(w1))


# %%
# 8  [If 𝑢 = 𝑥 + 3𝑦2 − 𝑧^3, 𝑣 = 4𝑥^2𝑦𝑧, 𝑤 = 2𝑧^2 − 𝑥𝑦 then write Python program to prove that the Jacobean 𝐽 = 𝜕(𝑢, 𝑣, 𝑤)/𝜕(𝑥, 𝑦, 𝑧) at (1,−1, 0), is 20.]

from sympy import *

x, y, z = symbols('x y z')

u = x + 3*y**2 - z**3
v = 4*x**2*y*z
w = 2*z*z**2 - x*y

dux = diff(u, x)
duy = diff(u, y)
duz = diff(u, z)
dvx = diff(v, x)
dvy = diff(v, y)
dvz = diff(v, z)
dwx = diff(w, x)
dwy = diff(w, y)
dwz = diff(w, z)

J = Matrix([[dux, duy, duz], [dvx, dvy, dvz], [dwx, dwy, dwz]])

print("The Jacobian matrix is:")
display(J)

Jac = det(J).doit()
print("\n\nJ =")
display(Jac)

J1 = J.subs([(x, 1), (y, -1), (z, 0)])
print("\n\nJ at (1, -1, 0):\n")
display(J1)


# %%
# 9  [Write a Python program to find the Maclaurin series expansion of 𝑠𝑖𝑛(𝑥) + 𝑐𝑜𝑠(𝑥) up to 3rd degree term. Also Calculate 𝑠𝑖𝑛 (10) + 𝑐𝑜𝑠 (10).]

import numpy as np
from matplotlib import pyplot as plt
from sympy import *

x = Symbol('x')
y = sin(x) + cos(x)

# format
x0 = float(0)
dy = diff(y, x)
d2y = diff(y, x, 2)
d3y = diff(y, x, 3)

yat = lambdify(x, y)
dyat = lambdify(x, dy)
d2yat = lambdify(x, d2y)
d3yat = lambdify(x, d3y)

y = yat(x0) + ((x - x0) / 2) * dyat(x0) + ((x - x0) ** 2 / 6) * d2yat(x0) + ((x - x0) ** 3 / 24) * d3yat(x0)

print(simplify(y))

yat = lambdify(x, y)
print("%.3f" % yat(10*(pi/180)))

def f(x):
    return np.sin(1*x) + np.cos(x)

x = np.linspace(-10, 10)
plt.plot(x, yat(x), color='red')
plt.plot(x, f(x), color='green')
plt.ylim([-3, 3])
plt.grid()
plt.show()


# %%
# 10 [Prove that 𝑙𝑖𝑚 𝑥→∞(1 +1𝑥)𝑥= 𝑒 by using Python program.]

from sympy import *
from math import inf
x= Symbol ('x')
l= Limit (( 1+1/x ) ** x ,x , inf ) . doit ()
display ( l )

# %%
import numpy as np

def normalize(x):
    fac = abs(x).max()
    x_n = x / x.max()
    return fac, x_n

x = np.array([1, 1, 1])
a = np.array([[1, 1, 3],
              [1, 5, 1],
              [3, 1, 1]])

for i in range(10):
    x = np.dot(a, x)
    lambda_1, x = normalize(x)
    print('Eigenvalue:', lambda_1)
    print('Eigenvector:', x)

