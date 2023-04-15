#Read a multi-digit number (as chars) from the console. Develop a program to print the frequency of 
#each digit with suitable message.

def count_digits(number):
    dc = {}
    for i in str(number):
        dc[i] = dc.get(i,0) + 1
    for digit, count in dc.items():
        print(f"The digit {digit} appears {count} times")

number = input("Enter a multi-digit number: ")
count_digits(number)