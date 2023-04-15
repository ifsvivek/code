#Define a function which takes TWO objects representing complex numbers and returns new complex 
#number with a addition of two complex numbers. Define a suitable class ‘Complex’ to represent the 
#complex number. Develop a program to read N (N >=2) complex numbers and to compute the addition 
#of N complex numbers.
class Complex:
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag
        
    def add(self, other):
        real = self.real + other.real
        imag = self.imag + other.imag
        return Complex(real, imag)
    
    def __str__(self):
        return f"{self.real} + {self.imag}i"

def addComplex(numbers):
    result = numbers[0]
    for i in range(1, len(numbers)):
        result = result.add(numbers[i])
    return result

n = int(input("Enter the number of complex numbers: "))
numbers = []
for i in range(n):
    real = float(input(f"Enter the real part of complex number {i+1}: "))
    imag = float(input(f"Enter the imaginary part of complex number {i+1}: "))
    numbers.append(Complex(real, imag))

result = addComplex(numbers)
print("The addition of the complex numbers is:", result)