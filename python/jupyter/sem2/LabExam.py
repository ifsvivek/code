# Converted from LabExam.ipynb

# MARKDOWN CELL:
# 1. To find gradient of 𝜙 = 𝑥2𝑦 + 2𝑥𝑧 − 4
# %%
#To find gradient of scalar point function.
from sympy.vector import *
from sympy import symbols
N=CoordSys3D('N')
x,y,z=symbols('x y z')
A=N.x**2*N.y+2*N.x*N.z-4
delop=Del()
display(delop(A))
gradA=gradient(A)
print(f"\n Gradient of {A} is \n")
display(gradA)


# MARKDOWN CELL:
# 2. To find curl of 𝐹⃗ = 𝑥2𝑦𝑧𝑖̂+ 𝑦2𝑧𝑥𝑗̂+ 𝑧2𝑥𝑦�
# %%
#To find curl of a vector point function
from sympy . vector import *
from sympy import symbols
N= CoordSys3D ('N')
x,y,z= symbols ('x y z')
A=N.x ** 2*N.y*N.z*N.i+N.y ** 2*N.z*N.x*N.j+N.z ** 2*N.x*N.y*N.k
delop =Del ()
curlA = delop . cross (A)
display ( curlA )
print (f"\n Curl of {A} is \n")
display ( curl (A))

# MARKDOWN CELL:
# 3. To find gradient of 𝐹⃗ = 𝑥2𝑦𝑧𝑖̂+ 𝑦2𝑧𝑥𝑗̂+ 𝑧2𝑥𝑦𝑘̂
# %%
#To find divergence of F=x^2yi+yz^2j+x^2zk
from sympy . physics . vector import *
from sympy import var
var ('x,y,z')
v= ReferenceFrame ('v')
F=v[0] ** 2*v[1]*v.x+v[1]*v[2] ** 2*v.y+v[0] ** 2*v[2]*v.z
G= divergence (F,v)
F=F. subs ([(v[0],x) ,(v[1],y) ,(v[2],z)])
print (" Given vector point function is ")
display (F)
G=G. subs ([(v[0],x) ,(v[1],y) ,(v[2],z)])
print (" Divergence of F=")
display (G)


# MARKDOWN CELL:
# 4. Obtain a root of the equation 𝑥3 − 2𝑥 − 5 = 0 between 2 and 3 by regulafalsi method. Perform 5 iterations.
# %%
# Regula Falsi method
from sympy import *
x= Symbol ('x')
g = input ('Enter the function ') #%x^3-2*x-5; % function
f= lambdify (x,g)
a= float ( input ('Enter a valus :')) #2
b= float ( input ('Enter b valus :')) # 3
N=int( input ('Enter number of iterations :')) #5
for i in range (1,N+1):
    c=(a*f(b)-b*f(a))/(f(b)-f(a))
    if ((f(a)*f(c)<0)):
        b=c
    else :
        a=c
    print ('itration %d \t the root %0.3f \t function value %0.3f \n'%(i,c,f(c)))


# MARKDOWN CELL:
# 5. Find a root of the equation 3𝑥 = cos 𝑥 + 1, near 1, by Newton Raphson method. Perform 5 iterations.
# %%
from sympy import *
x= Symbol ('x')
g = input ('Enter the function ') #%3x -cos(x)-1; % function
f= lambdify (x,g)
dg = diff (g);
df= lambdify (x,dg)
x0= float ( input ('Enter the intial approximation ')); # x0=1
n= int( input ('Enter the number of iterations ')); #n=5;
for i in range (1,n+1):
    x1 =(x0 - (f(x0)/df(x0)))
    print ('itration %d \t the root %0.3f \t function value %0.3f \n'%(i, x1 ,f(x1))); # print all iteration value
    x0 = x1


# MARKDOWN CELL:
# 6.1 Using Trapezoidal Rule Evaluate ∫11+𝑥2
# %%
# Definition of the function to integrate
def my_func(x):
    return 1 / (1 + x ** 2)

# Function to implement trapezoidal method
def trapezoidal(x0, xn, n):
    h = (xn - x0) / n  # Calculating step size

    # Finding sum
    integration = my_func(x0) + my_func(xn)  # Adding first and last terms

    for i in range(1, n):
        k = x0 + i * h  # i-th step value
        integration = integration + 2 * my_func(k)  # Adding areas of the trapezoids

    # Proportioning sum of trapezoid areas
    integration = integration * h / 2
    return integration
a = 0  # lower limit
b = 6  # upper limit
n = 6  # number of sub intervals
result = trapezoidal(a, b, n)
print('%3.5f' % result)



# MARKDOWN CELL:
# 6.2 simpson's 1/3 Evaluate ∫11+𝑥2
# %%
# Function to implement the Simpson's one-third rule
def simpson13(x0, xn, n):
    h = (xn - x0) / n  # calculating step size

    # Finding sum
    integration = (my_func(x0) + my_func(xn))
    k = x0
    for i in range(1, n):
        if i % 2 == 0:
            integration = integration + 4 * my_func(k)
        else:
            integration = integration + 2 * my_func(k)
        k += h

    # Finding final integration value
    integration = integration * h * (1 / 3)
    return integration

# Input section
lower_limit = float(input("Enter lower limit of integration: "))
upper_limit = float(input("Enter upper limit of integration: "))
sub_interval = int(input("Enter number of sub intervals: "))

result = simpson13(lower_limit, upper_limit, sub_interval)
print("Integration result by Simpson's 1/3 method is: %0.6f" % result)

# MARKDOWN CELL:
# 6.3 simpson's 3/8 Evaluate ∫11+𝑥2
# %%
def simpsons_3_8_rule(f, a, b, n):
    h = (b - a) / n
    s = f(a) + f(b)

    for i in range(1, n, 3):
        s += 3 * f(a + i * h)

    for i in range(3, n - 1, 3):
        s += 3 * f(a + i * h)

    for i in range(2, n - 2, 3):
        s += 2 * f(a + i * h)

    return s * 3 * h / 8

def f(x):
    return 1 / (1 + x ** 2)  # function here

a = 0  # lower limit
b = 6  # upper limit
n = 6  # number of sub intervals
result = simpsons_3_8_rule(f, a, b, n)
print('%3.5f' % result)

# MARKDOWN CELL:
# 7. Runge-Kutta methodApply the Runge Kutta method to find the solution of dy/dx = 1 + (y/x) at y(2) taking h = 0.2. Given that y(1) = 2.
# %%
from sympy import *
import numpy as np

def RungeKutta(g, x0, h, y0, xn):
    x, y = symbols('x y')
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
        x0 = xt
        y0 = y1
        xt = xt + h
    return np.round(Y, 2)

RungeKutta('1+(y/x)', 1, 0.2, 2, 2)

# MARKDOWN CELL:
# 8. Apply Milne’s predictor and corrector method to solve dy/dx = x2 + (y/2) at y(1.4).Given that y(1)=2, y(1.1)=2.2156, y(1.2)=2.4649, y(1.3)=27514. Use corrector formula thrice.
# %%
# Milne's method to solve first-order DE
# Use corrector formula thrice

x0 = 1
y0 = 2
y1 = 2.2156
y2 = 2.4649
y3 = 2.7514
h = 0.1
x1 = x0 + h
x2 = x1 + h
x3 = x2 + h
x4 = x3 + h

def f(x, y):
    return x ** 2 + (y / 2)

y10 = f(x0, y0)
y11 = f(x1, y1)
y12 = f(x2, y2)
y13 = f(x3, y3)
y4p = y0 + (4 * h / 3) * (2 * y11 - y12 + 2 * y13)
print('Predicted value of y4 is %3.3f' % y4p)

y14 = f(x4, y4p)
for i in range(1, 4):
    y4 = y2 + (h / 3) * (y14 + 4 * y13 + y12)
    print('Corrected value of y4 after iteration %d is %3.5f' % (i, y4))
    y14 = f(x4, y4)


