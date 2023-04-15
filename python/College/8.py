#Write a function named DivExp which takes TWO parameters a, b and returns a value c (c=a/b). Write 
#suitable assertion for a>0 in function DivExp and raise an exception for when b=0. Develop a suitable 
#program which reads two values from the console and calls a function DivExp.

def DivExp(a, b):
    assert a > 0, "The value of 'a' should be greater than 0"
    if b == 0:
        raise Exception("The value of 'b' should not be 0")
    return a/b

a = float(input("Enter the value of a: "))
b = float(input("Enter the value of b: "))

try:
    c = DivExp(a, b)
    print(f'The result of {a}/{b} is {c}')
except Exception as e:
    print(e)