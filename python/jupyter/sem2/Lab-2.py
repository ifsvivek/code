# Converted from Lab-2.ipynb

# MARKDOWN CELL:
# 1. Obtain a root of the equation x3 − 2x − 5 = 0 between 2 and 3 by regula-falsi method.
# Perform 5 iterations.
# %%
# Regula Falsi method
from sympy import *
x= Symbol ('x')
g = input ('Enter the function ') #x**3-2*x-5
f= lambdify (x , g )
a= float ( input ('Enter a valus :') ) #2
b= float ( input ('Enter b valus :') ) # 3
N=int( input ('Enter number of iterations :') ) #5
for i in range (1 , N+1 ):
    c=( a*f ( b )-b*f ( a ) )/( f ( b )-f ( a ) )
    if (( f ( a )*f ( c )<0 ) ):
        b=c
    else :
        a=c
    print ('itration %d \t the root %0.3f \t function value %0.3f \n'%(i ,c , f ( c ) ) )

# MARKDOWN CELL:
# 2. Using tolerance value we can write the same program as follows:
# Obtain a root of the equation x3 − 2x − 5 = 0 between 2 and 3 by regula-falsi method.
# Correct to 3 decimal places.
# %%
# Regula Falsi method while loop2
from sympy import *
x= Symbol ('x')
g = input ('Enter the function ') #x**3-2*x-5
f= lambdify (x , g )
a= float ( input ('Enter a valus :') ) # 2
b= float ( input ('Enter b valus :') ) # 3
N= float ( input ('Enter tolarence :') ) # 0.001
x=a 
c=b 
i=0
while (abs( x-c )>=N ):
    x=c
    c=(( a*f ( b )-b*f ( a ) )/( f ( b )-f ( a ) ) ) 
    if (( f ( a )*f ( c )<0 ) ):
        b=c
    else :
        a=c
    i=i+1
    print ('itration %d \t the root %0.3f \t function value %0.3f \n'%(i ,c , f ( c ) ) )
print ('final value of the root is %0.5f '%c )

# MARKDOWN CELL:
# 3. Find a root of the equation 3x = cos x+ 1, near 1, by Newton Raphson method. Perform
# 5 iterations
# %%
from sympy import *
x= Symbol ('x')
g = input ('Enter the function ') #3**x-cos(x)-1
f= lambdify (x , g )
dg = diff ( g ) 
df= lambdify (x , dg )
x0= float ( input ('Enter the intial approximation ') )  # x0=1
n= int( input ('Enter the number of iterations ') )  #n=5
for i in range (1 , n+1 ):
    x1 =( x0 - ( f ( x0 )/df ( x0 ) ) )
    print ('itration %d \t the root %0.3f \t function value %0.3f \n'%(i , x1 , f ( x1 ) ) )
    x0 = x1

