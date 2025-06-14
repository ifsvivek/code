# Converted from polarcurves.ipynb

# %%
import numpy as np
import matplotlib.pyplot as plt
plt.axes(projection='polar')
r=3
rads=np.arange(0,(2*np.pi),0.01)
for i in rads:
    plt.polar(i,r,'g')
plt.show()

# %%
from pylab import *
theta=linspace(0,2*np.pi,1000)
r=5+5*cos(theta)
polar(theta,r,'r')
show()

# %%
from pylab import *
theta=linspace(0,2*np.pi,1000)
r=2*abs(cos(2*theta))
polar(theta,r,'r')
show()

# %%
from pylab import *
a=3
theta=linspace(0,2*np.pi,1000)
r1=a+a*cos(theta)
r2=a-a*cos(theta)
polar(theta,r1,'r')
polar(theta,r2,'g')
show()

# %%
from pylab import *
theta=linspace(0,2*np.pi,1000)
r=cos((np.pi*theta)/2)
polar(theta,r,'r')
show()

# %%
from pylab import *
theta=linspace(0,2*np.pi,1000)
r=1+sin(theta+(np.pi/4))
polar(theta,r,'r')
show()

# %%
from pylab import *
a=2
b=3
theta=linspace(0,2*np.pi,1000)
r=a+b*theta
polar(theta,r,'r')
show()

# %%
from pylab import *
a=2
b=4
theta=linspace(0,2*np.pi,1000)
r=a+b*theta
polar(theta,r,'r')
show()

# %%
from pylab import *
a=2
b=4
theta=linspace(0,2*np.pi,1000)
r=a+b*cos(theta)
polar(theta,r,'r')
show()

