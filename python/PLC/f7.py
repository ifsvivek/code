n=int(input('Enter a number: '))

for i in range(2,int(n**0.5)+1):

    if n%i==0:

        print(n,'is not a prime number')

    else:

        print(n,'is a prime number')





