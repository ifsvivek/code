# Converted from minima-maxima.ipynb

# %%
import sympy
from sympy import Symbol , solve , Derivative , pprint
x= Symbol ('x')
y= Symbol ('y')
f=x ** 2+x*y+y ** 2+3*x-3*y+4
d1= Derivative (f , x ) . doit ()
d2= Derivative (f , y ) . doit ()
criticalpoints1 = solve ( d1 )
criticalpoints2 = solve ( d2 )
s1= Derivative (f ,x , 2 ) . doit ()
s2= Derivative (f ,y , 2 ) . doit ()
s3= Derivative ( Derivative (f , y ) ,x ) . doit ()
print ('function value is ')
q1=s1 . subs ({y: criticalpoints1 , x: criticalpoints2 }) . evalf ()
q2=s2 . subs ({y: criticalpoints1 , x: criticalpoints2 }) . evalf ()
q3=s3 . subs ({y: criticalpoints1 , x: criticalpoints2 }) . evalf ()
delta =s1*s2-s3 ** 2
print ( delta , q1 )
if( delta >0 and s1<0 ):
    print (" f takes maximum ")
elif ( delta >0 and s1>0 ):
    print (" f takes minimum ")
if ( delta <0 ):
    print ("The point is a saddle point ")
if ( delta ==0 ):
    print (" further tests required ")


# %%
import numpy as np
from matplotlib import pyplot as plt
from sympy import *
x= Symbol ('x')
y=sin( 1*x )
x0= float (pi/2 )
dy= diff (y , x )
d2y = diff (y ,x , 2 )
d3y = diff (y ,x , 3 )
yat = lambdify (x , y )
dyat = lambdify (x , dy )
d2yat = lambdify (x , d2y )
d3yat = lambdify (x , d3y )
y=yat ( x0 )+(( x-x0 )/2 )* dyat ( x0 )+(( x-x0 ) ** 2/6 )* d2yat ( x0 )+(( x-x0 ) ** 3/24 )*d3yat ( x0 )
print ( simplify ( y ) )
yat = lambdify (x , y )
print ("%.3f" % yat (pi/2+10*(pi/180 ) ) )
def f ( x ):
    return np .sin ( 1*x )
x = np . linspace (-10 , 10 )
plt . plot (x , yat ( x ) , color ='red ')
plt . plot (x , f ( x ) , color ='green ')
plt . ylim ([-3 , 3])
plt . grid ()
plt . show ()


# %%
import numpy as np
from matplotlib import pyplot as plt
from sympy import *
x = Symbol('x')
y = sin(1*x)
x0 = float(np.pi/2)
dy = diff(y, x)
d2y = diff(y, x, 2)
d3y = diff(y, x, 3)
yat = lambdify(x, y)
dyat = lambdify(x, dy)
d2yat = lambdify(x, d2y)
d3yat = lambdify(x, d3y)
y = yat(x0) + ((x - x0)/2) * dyat(x0) + ((x - x0)**2/6) * d2yat(x0) + ((x - x0)**3/24) * d3yat(x0)
print(simplify(y))
yat = lambdify(x, y)
print("%.3f" % yat(np.pi/2 + 10*(np.pi/180)))

def f(x):
    return np.sin(1*x)

x = np.linspace(-10, 10)
plt.plot(x, yat(x), color='red')
plt.plot(x, f(x), color='green')
plt.ylim([-3, 3])
plt.grid()
plt.show()


