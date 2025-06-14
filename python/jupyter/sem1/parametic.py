# Converted from parametic.ipynb

# %%
import numpy as np
import matplotlib.pyplot as plt
def circle(r):
    x=[]
    y=[]
    for theta in np.linspace(-2*np.pi,2*np.pi,1000):
        x.append(r*np.cos(theta))
        y.append(r*np.sin(theta))
    plt.plot(x,y)
    plt.show()
circle(5)

# %%
def cycloid(r):
    x=[]
    y=[]
    for theta in np.linspace(-2*np.pi,2*np.pi,100):
     x.append(r*(theta-np.sin(theta)))
     y.append(r*(1-np.cos(theta)))
    plt.plot(x,y)
    plt.show()
cycloid(2)

# %%
from sympy import *
r,t=symbols('r,t')
r1=4*(1+cos(t))
r2=5*(1-cos(t))
dr1=diff(r1,t)
dr2=diff(r2,t)
t1=r1/dr1
t2=r2/dr2
q=solve(r1-r2,t)
w1=t1.subs({t:float(q[1])})
w2=t2.subs({t:float(q[1])})
y1=atan(w1)
y2=atan(w2)
w=abs(y1-y2)
print('Angle between curves in radians is %0.3f'%(w))

# %%
from sympy import *
t,r=symbols('t,r')
r=4*(1+cos(t))
r1=Derivative(r,t).doit()
r2=Derivative(r1,t).doit()
rho=(r**2+r1**2)**(1.5)/(r**2+2*r1**2-r*r2)
rho1=rho.subs(t,pi/2)
print('The Radius of curvature is %3.4f units'%rho1)



# %%
from sympy import *
from sympy.abc import rho,x,y,r,k,t,a,b,c,alpha
y=(sqrt(x)-4)**2
y=a*sin(t)
x=a*cos(t)
dydx=simplify(Derivative(y,t).doit())/simplify(Derivative(x,t).doit())
rho=simplify((1+dydx**2)**1.5/(Derivative(dydx,t).doit()/(Derivative(x,t).doit())))
print('Radius of curvature is')
display(ratsimp(rho))
t1=pi/2
r1=5
rho1=rho.subs(t,t1)
rho2=rho1.subs(a,r1)
print('\n\n Radius of curvature at r=5 and t=pi/2 is',simplify(rho2))
curvature=1/rho2
print('\n\n Curvature at (5,pi/2) is',float(curvature))

# %%
from sympy import *
from sympy.abc import rho,x,y,r,K,t,a,b,c,alpha

y=(a*sin(t))**(3/2)
x=(a*cos(t))**(3/2)
dydx=simplify(Derivative(y,t).doit())/simplify(Derivative(x,t).doit())
rho=simplify((1+dydx**2)**1.5/(Derivative(dydx,t).doit()/(Derivative(x,t).doit())))
print('radius of curvature is')
display(ratsimp(rho))
t1=pi/4
r1=1
rho1=rho.subs(t,t1)
rho2=rho1.subs(a,r1)
display('Radius of curvature at r=1 7 t=pi/4 is',simplify(rho2))
curvature=1/rho2
print('\n\ Curvature at (1,pi/4) is',float(curvature))

