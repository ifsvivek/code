# Converted from Lab-3.ipynb

# MARKDOWN CELL:
# 1. To find gradient of ϕ = x2y + 2xz − 4
# %%
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
# 2. To find divercence of F→ = x2yz^i + 2zx^j + z2xy^k
# %%
from sympy.vector import *
from sympy import symbols
N=CoordSys3D('N')
x,y,z=symbols('x y z')
A=N.x**2*N.y*N.z*N.i+N.y**2*N.z*N.x*N.j+N.z**2*N.x*N.y*N.k
delop=Del()
divA=delop.dot(A)
display(divA)
print(f"\n Divergence of {A} is \n")
display(divergence(A))

# MARKDOWN CELL:
# 3. To find curl of F→ = x2yz^i + y2zx^j + z2xy^k
# %%
from sympy.vector import *
from sympy import symbols
N=CoordSys3D('N')
x,y,z=symbols('x y z')
A=N.x**2*N.y*N.z*N.i+N.y**2*N.z*N.x*N.j+N.z**2*N.x*N.y*N.k
delop=Del()
curlA=delop.cross(A)
display(curlA)
print(f"\n Curl of {A} is \n")
display(curl(A))

# MARKDOWN CELL:
# 4. To find gradient of x2yz
# %%
from sympy.physics.vector import *
from sympy import var,pprint
var('x,y,z')
v=ReferenceFrame('v')
F=v[0]**2*v[1]*v[2]
G=gradient(F,v)
F=F.subs([(v[0],x),(v[1],y),(v[2],z)])
print("Given scalar function F=")
display(F)
G=G.subs([(v[0],x),(v[1],y),(v[2],z)])
print("\n Gradient of F=")
display(G)

# MARKDOWN CELL:
# 5. To find divergence of F→ = x2y^i + yz2^j + x2zk
# %%
from sympy.physics.vector import *
from sympy import var
var('x,y,z')
v=ReferenceFrame('v')
F=v[0]**2*v[1]*v.x+v[1]*v[2]**2*v.y+v[0]**2*v[2]*v.z
G=divergence(F,v)
F=F.subs([(v[0],x),(v[1],y),(v[2],z)])
print("Given vector point function is ")
display(F)
G=G.subs([(v[0],x),(v[1],y),(v[2],z)])
print("Divergence of F=")
display(G)


# MARKDOWN CELL:
# 6. To find curl of F→ = xy2^i + 2x2yz^j − 3yz2k^
# %%
from sympy.physics.vector import *
from sympy import var
var('x,y,z')
v=ReferenceFrame('v')
F=v[0]*v[1]**2*v.x+2*v[0]**2*v[1]*v[2]*v.y-3*v[1]*v[2]**2*v.z
G=curl(F,v)
F=F.subs([(v[0],x),(v[1],y),(v[2],z)])
print("Given vector point function is ")
display(F)
G=G.subs([(v[0],x),(v[1],y),(v[2],z)])
print("curl of F=")
display(G)

# MARKDOWN CELL:
# 7. Using Green's theorem, evaluate ∮c[(x + 2y)dx + (x − 2y)dy] , where is the region
# bounded by coordinate axes and the line x = 1 y = 1
# %%
from sympy import *
var('x,y')
p=x+2*y
q=x-2*y
f=diff(q,x)-diff(p,y)
soln=integrate(f,[x,0,1],[y,0,1])
print("I=",soln)

# MARKDOWN CELL:
# 8. Using Green's theorem, evaluate ∮c[(xy + y2)dx + x2dy] where c is the closed curve
# bounded by y = x and y = x2
# %%
from sympy import *
var('x,y')
p=x*y+y**2
q=x**2
f=diff(q,x)-diff(p,y)
soln=integrate(f,[y,x**2,x],[x,0,1])
print("I=",soln)

# MARKDOWN CELL:
# 9. Using Green,s theorem, evaluate ∮c[(3x + 4y)dx + (2x − 3y)dy] where c is the
# boundary of the circel x2 + y2 = 4
# %%
from sympy import *
var('x,y')
p=3*x+4*y
q=2*x-3*y
f=diff(q,x)-diff(p,y)
soln=integrate(f,[y,-sqrt(4-x**2),sqrt(4-x**2)],[x,-2,2])
print("I=",soln)

