#Develop a program to generate Fibonacci sequence of length (N). Read N from the console.
def fibonacci(n):
    a, b = 0, 1
    fib = []
    for i in range(n):
        fib.append(a)
        a, b = b, a + b
    return fib

n = int(input("Enter the length of the Fibonacci sequence: "))
print(fibonacci(n))