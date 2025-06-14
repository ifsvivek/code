# Converted from Lhospitol.ipynb

# %%
from sympy import *
init_printing ()
t , r = symbols ('t,r') # Define the symbols
P = Function ('P') ( t ) # define function
C1 = Symbol ('C1 ')
print ("\nDifferential Equation ")
DE1 = Derivative (P , t , 1 )-r # define the differeentail equation
display ( DE1 )
# General solution
print ("\nGeneral Solution ")
GS1 = dsolve ( DE1 ) # Solve the differentail equation
display ( GS1 ) # Display the solution
print ("\nParticular Solution ")
PS1 =GS1 . subs ({C1:2}) # substitute the value of the conastant
display ( PS1 )

# %%
from sympy import *
x , y= symbols ('x,y') 
y= Function ("y") ( x )
y1= Derivative (y , x )
z1= dsolve( Eq(y1+y*tan( x )-y**3*sec( x ) ), y)
display ( z1 )

# %%
import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt
# Function returns dy/dt
def model (y , t ):
    k=0.3
# dydt = -k*y
    return -k*y # initial condition
y0=5 # values for time
t=np . linspace (0 , 20 )
# solve ODE
y= odeint ( model , y0 , t )
plt . plot (t , y )
plt . title ('Solution of dy/dt= -ky; k=0.3, y(0)=5')
plt . xlabel ('time ')
plt . ylabel ('y(t)')
plt . show ()

# %%
import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint
Kp=3
taup =2 # Differential Equation :
def model (y , t ):
    u = 1
    return (-y + Kp * u )/ taup
t3 = np . linspace (0 , 14 , 100 )
# ODE integrator
y3 = odeint ( model ,0 , t3 )
plt . plot ( t3 , y3 ,'r-', linewidth =1 , label ='ODE Integrator ')
plt . xlabel ('Time ')
plt . ylabel ('Response (y)')
plt . show ()

# %%
from pylab import * 
t= arange (0 , 10 , 0.5 ) # Define the range where we want solution
P0=20
y=20*exp( 0.405465108108164 *t )
plot (t , y )
xlabel ('Time ')
ylabel ('no of bacteria ')
title ('Law of Natural Growth ')
show ()

# %%
import numpy as np
from sympy import *
from matplotlib import pyplot as plt
t2=20 # surrounding temp
t1=100 # inital temp
# one reading t=1 minute temp is 75 degree
t=10
T=75
k1=( 1/t )*log(( t1-t2 )/( T-t2 ) )# k calculation
print ('k= ', k1 )
k= Symbol ('k') 
t= Symbol ('t') 
T= Function ('T') ( t )
T=t2+( t1-t2 )*exp(-k*t ) # solution
print ('T=',T )
# ploting the solution curve
T=T . subs (k , k1 )
T= lambdify (t , T )
t = np . linspace (0 , 70 )
plt . plot (t,T( t ),color ='red')
plt . grid ()
plt . show ()
# When time t=30 minute T is
print ('When time t=30 minute T is ,',T ( 30 ) ,'o C')

