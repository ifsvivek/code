# Converted from graph.ipynb

# %%
import matplotlib.pyplot as plt
x= [1,2,3,4,6,7,8]
y = [2,4,9,1,5,10,8]
plt.scatter(x,y)
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.title("Scatter points")
plt.show()

# %%
import matplotlib.pyplot as plt
x=[1,2,3,4,6,7,8]
y=[2,7,9,1,5,10,3]
plt.plot(x, y, 'r*--')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.title('My first graph')
plt.show()

# %%
import numpy as np
import matplotlib.pyplot as plt
x=np.arange(-10,10,0.001)
y=np.exp(x)
plt.plot(x,y)
plt.title('Exponential curve ')
plt.grid()
plt.show()

# %%
import numpy as np
import matplotlib.pyplot as plt
x=np.arange(-10,10,0.001)
y1=np.sin(x)
y2=np.cos(x)
plt.plot(x,y1,x,y2)
plt.title("sine curve and cosine curve")
plt.xlabel("Values of x")
plt.ylabel("Values of sin(x) and cos(x)")
plt.grid()
plt.show()

# %%
import numpy as np
import matplotlib.pyplot as plt
x=np.linspace(0,2,100)
plt.plot(x, x, label='Linear') 
plt.plot(x, x**2, label='quadratic')
plt.plot(x, x**3, label='cubic')
plt.xlabel('xlabel')
plt.ylabel('ylabel') 
plt.title("Sample plot")
plt.legend()
plt.show()

# %%
from sympy import *
x,y=symbols('x,y')
P1=plot_implicit(Eq(x**2+y**2,4),(x,-4,4),(y,-4,4),title='Circle:$x^2+y^2=4$')

# %%

from sympy import *
x,y=symbols('x,y')
P1=plot_implicit(Eq(y**2*(2-x),x**2*(2+x)),(x,-5,5),(y,-5,5),title='Strophid:$y^2(2-x)=x^2(2+x) a>0$')

# %%
from sympy import *
a=7
x,y=symbols('x,y')
P1=plot_implicit(Eq((y**2)*(a-x),x**3),(x,-7,7),(y,-7,7),title='cissoid:$y^2(a-x)=x^3$')

# %%
from sympy import *
a=3
x,y=symbols('x,y')
P1=plot_implicit(Eq((a**2)*(y**2),(x**2)*(a**2-x**2)),(x,-5,5),(y,-5,5),title='$Lanniseate:a^2y^2=x^2(a^2-x^2$')

# %%
from sympy import *
a=4
x,y=symbols('x,y')
P1=plot_implicit(Eq((y**3 + x**3 ) , (3*a*x*y)) , (x,-7,7),(y,-7,7), title='$folium of de-carts = y^3 + x^3 =3*a*x*y $')

