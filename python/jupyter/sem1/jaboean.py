# Converted from jaboean.ipynb

# %%
from sympy import *
x,y,z=symbols('x,y,z')
u=x*y/z
v=y*z/x
w=z*x/y
duy=diff(u,y)
dux=diff(u,x)
duz=diff(u,z)
dvx=diff(v,x)
dvy=diff(v,y)
dvz=diff(v,z)
dwx=diff(w,x)
dwy=diff(w,y)
dwz=diff(w,z)
J=Matrix([[dux,duy,duz],[dvx,dvy,dvz],[dwx,dwy,dwz]]);
print('The jacobian matrix is \n')
display(J)
Jac=det(J).doit()
print('\n\n  J= ',Jac)

# %%
from sympy import *
x ,y , z= symbols ('x,y,z')
u=x+3*y ** 2-z ** 3
v=4*x ** 2*y*z
w=2*z*z ** 2-x*y
dux = diff (u , x )
duy = diff (u , y )
duz = diff (u , z )
dvx = diff (v , x )
dvy = diff (v , y )
dvz = diff (v , z )
dwx = diff (w , x )
dwy = diff (w , y )
dwz = diff (w , z )
J= Matrix ([[dux , duy , duz],[dvx , dvy , dvz],[dwx , dwy , dwz]]) ;
print ("The Jacobian matrix is ")
display ( J )
Jac = Determinant ( J ) . doit ()
print ('\n\n J = \n')
display ( Jac )
J1=J . subs ([(x , 1 ) , (y , -1 ) , (z , 0 )])
print ('\n\n J at (1, -1,0):\n')
Jac1 = Determinant ( J1 ) . doit ()
display ( Jac1 )

# %%
from sympy import *
from sympy.abc import rho , phi , theta
X=rho*cos( phi )*sin( theta ) 
Y=rho*cos( phi )*cos( theta ) 
Z=rho*sin( phi ) 
dx= Derivative (X , rho ) . doit ()
dy= Derivative (Y , rho ) . doit ()
dz= Derivative (Z , rho ) . doit ()
dx1 = Derivative (X , phi ) . doit () 
dy1 = Derivative (Y , phi ) . doit () 
dz1 = Derivative (Z , phi ) . doit ()
dx2 = Derivative (X , theta ) . doit ()
dy2 = Derivative (Y , theta ) . doit () 
dz2 = Derivative (Z , theta ) . doit () 
J= Matrix ([[dx , dy , dz],[dx1 , dy1 , dz1],[dx2 , dy2 , dz2]]) 
print ('The Jacobian matrix is ')
display ( J )
print ('\n\n J = \n')
display ( simplify ( Determinant ( J ) . doit () ) )

