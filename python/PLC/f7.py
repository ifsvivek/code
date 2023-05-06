n=int(input('Enter a number: '))

for i in range(2,int(n/2)**2+1):

    if n%2==0:

        print(n,'is not a prime number')

    else:

        print(n,'is a prime number')
