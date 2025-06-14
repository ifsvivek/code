# Converted from Lab-1.ipynb

# MARKDOWN CELL:
# 1. Evaluate the integral ∫01 ∫0x(x2 + y2)dydx
# %%
from sympy import *
x,y,z=symbols('x y z')
w1=integrate(x**2+y**2,(y,0,x),(x,0,1))
print(w1)

# MARKDOWN CELL:
# 2. Evaluate the integral ∫03 ∫03−x ∫03−x−y(xyz)dzdydx
# %%
from sympy import *
x,y,z=symbols('x y z')
w2=integrate((x*y*z),(z,0,3-x-y),(y,0,3-x),(x,0,3))
print(w2)

# MARKDOWN CELL:
# 3. Prove that ∫ ∫ (x2 + y2)dydx = ∫ ∫ (x2 + y2)dxdy
# %%
from sympy import *
x,y,z=symbols('x y z')
w3=integrate(x**2+y**2,y,x)
pprint(w3)
w4=integrate(x**2+y**2,x,y)
pprint(w4)

# MARKDOWN CELL:
# 4. Find the area of an ellipse by double integration. A=4 ∫0a ∫0(b/a)√a2−x2dydx
# %%
from sympy import *
x=Symbol('x')
y=Symbol('y')
a=4
b=6
w3=4*integrate(1,(y,0,(b/a)*sqrt(a**2-x**2)),(x,0,a))
print(w3)

# MARKDOWN CELL:
# 5. Find the area of the cardioid r = a(1 + cosθ) by double intgration.
# %%
from sympy import *
r=Symbol('r')
t=Symbol('t')
a=Symbol('a')
w3=2*integrate(r,(r,0,a*(1+cos(t))),(t,0,pi))
pprint(w3)

# MARKDOWN CELL:
# 6. Find the volume of the tetrahedron bounded by the planes and , x/a+y/b+z/c=1
# %%
from sympy import *
x,y,z,a,b,c=symbols('x y z a b c')
w2=integrate(1,(z,0,c*(1-x/a-y/b)),(y,0,b*(1-x/a)),(x,0,a))
print(w2)

# MARKDOWN CELL:
# 7. Find the center of gravity of cardioid . Plot the graph of cardioid and mark the center of gravity
# %%
import numpy as np
import matplotlib.pyplot as plt
import math
from sympy import *
r = Symbol('r')
t = Symbol('t')
a = Symbol('a')
I1 = integrate(cos(t)*r**2, (r, 0, a*(1+cos(t))), (t, -pi, pi))
I2 = integrate(r, (r, 0, a*(1+cos(t))), (t, -pi, pi))
I = I1/I2
print(I)
I = I.subs(a, 5)
plt.axes(projection='polar')
a = 5
rad = np.arange(0, (2 * np.pi), 0.01)
# plotting the cardioid
for i in rad:
    r = a + (a*np.cos(i))
    plt.polar(i, r, 'g.')
plt.polar(0, I, 'r.')
plt.show()

# MARKDOWN CELL:
# E1. evaluate ∫₀¹ ∫₀ˣ (x + y) dy dx
# %%
from sympy import symbols, integrate
x, y = symbols('x y')
integral_result = integrate(x + y, (y, 0, x), (x, 0, 1))
print(integral_result)

# MARKDOWN CELL:
# E2. ∫₀ˡᵒᵍ(2) ∫₀ˣ ∫₀ˣ⁺ˡᵒᵍ(y) eˣ⁺ʸ⁺ᶻ dz dy dx
# %%
from sympy import *
x,y,z=symbols('x y z')
w2=integrate(exp(x*y*z),(z,0,log(y)),(y,0,x),(x,0,log(2)))
print(w2)

# MARKDOWN CELL:
# E3. Find the area of positive quadrant of the circle x2 + y2 = 16
# %%
from sympy import *
x = Symbol('x')
y = Symbol('y')
A = integrate(1, (y, 0, sqrt(16 - x**2)), (x, 0, 4))
print(A)

# MARKDOWN CELL:
# E4. Find the volume of the tetrahedron bounded by the planes x=0, y=0 and z =0,  x/2+y/3 +z/4= 1
# %%
from sympy import *
x, y, z = symbols('x y z')
V = integrate(1, (z, 0, 4*(1 - x/2 - y/3)), (y, 0, 3*(1 - x/2)), (x, 0, 2))
print(V)

