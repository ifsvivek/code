#Read N numbers from the console and create a list. Develop a program to print mean, variance and 
#standard deviation with suitable messages.
import math

def mean(numbers):
    return sum(numbers) / len(numbers)

def variance(numbers):
    m = mean(numbers)
    return sum((x - m) ** 2 for x in numbers) / len(numbers)

def standard_deviation(variance):
    return math.sqrt(variance)

n = int(input("Enter the number of numbers: "))
numbers = [float(input(f"Enter number {i+1}: ")) for i in range(n)]

m = mean(numbers)
v = variance(numbers)
sd = standard_deviation(v)

print(f"Numbers: {numbers} ")
print(f"Mean of the numbers: {m}")
print(f"Variance of the numbers: {v}")
print(f"Standard deviation of the numbers: {sd}")