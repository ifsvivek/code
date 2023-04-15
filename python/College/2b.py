# Write a function to calculate factorial of a number. Develop a program to compute binomial 
#coefficient (Given N and R)

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

def binomial_coefficient(n, r):
    return factorial(n) / (factorial(r) * factorial(n-r))

n = int(input("Enter the value of n: "))
r = int(input("Enter the value of r: "))
print(binomial_coefficient(n, r))