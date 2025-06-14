# Converted from partialdervativs.ipynb

# %%
from sympy import * 
x,y=symbols('x y')
u= exp(x)*(x*cos(y)-y*sin (y))
dux=diff (u,x)
duy=diff (u,y)
duxy=diff (dux, y)
duyx=diff(duy,x) 
if duxy==duyx:
    print('Mixed partial derivatives are equal') 
else:
    print('Mixed partial derivatives are not equal')

# %%
from sympy import *
x,y=symbols('x y')
u=exp(x)*(x*cos(y)-y*sin(y))
display(u)
dux=diff (u,x)
duy=diff(u,y)
uxx=diff(dux, x)
uyy=diff (duy,y)
w = uxx + uyy
w1=simplify(w)
print ('Ans:',float (w1))

