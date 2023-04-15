class Complex:
    def __init__(self, real=0.0, imaginary=0.0):
        self.real = real
        self.imaginary = imaginary
        
    def __str__(self):
        return 'Sum of complex number: ' + str(self.real) + ' + ' + str(self.imaginary) + 'i'

    def __add__(self, other):
        result_real = self.real + other.real
        result_imaginary = self.imaginary + other.imaginary
        return Complex(result_real, result_imaginary)

n = int(input('Enter number of complex numbers to be added: '))
c3 = Complex()
for i in range(n):
    print('Enter Complex number', i+1)
    r = float(input('Enter real part: '))
    j = float(input('Enter imaginary part: '))
    c2 = Complex(r, j)
    c3 = c3 + c2

print(c3)