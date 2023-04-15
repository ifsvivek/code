import math

def mean(numbers):
    return sum(numbers) / len(numbers)

def variance(numbers, mean):
    return sum((x - mean) ** 2 for x in numbers) / len(numbers)

def standard_deviation(variance):
    return math.sqrt(variance)

n = int(input("Enter the number of numbers: "))

numbers = []
for i in range(n):
    number = float(input(f"Enter number {i+1}: "))
    numbers.append(number)

m = mean(numbers)
v = variance(numbers, m)
sd = standard_deviation(v)

print(f"Mean of the numbers: {m}")
print(f"Variance of the numbers: {v}")
print(f"Standard deviation of the numbers: {sd}")