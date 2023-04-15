class complex:
    def __init__(self,real=0.0,imaginary=0.0):
        self.real=real
        self.imaginary=imaginary
    def __str__(self):
        return 'Sum of complex number: ' + str(self.real) + ' + ' + str(self.imaginary) + 'i'

    def __add__(self,other):
        self.real=self.real+other.real
        self.imaginary=self.imaginary+other.imaginary
        return self
c3=complex()
n=int(input('Enter number of complex numbers to be added: '))
for i in range(n):
    c1=c3
    print('Enter Complex number: ',i+1)
    r=float(input('enter real: '))
    j=float(input('enter imaginary: '))
    c2=complex(r,j)
    c3=c1+c2
print(c3)