#Develop a program to read the student details like Name, USN, and Marks in three subjects. Display 
#the student details, total marks and percentage with suitable messages.

name = input("Name of the student: ")
usn = input("Your register number: ")
m1 = int(input("Marks of 1st Subject: "))
m2 = int(input("Marks of 2nd Subject: "))
m3 = int(input("Marks of 3rd Subject: "))
total = m1 + m2 + m3

print('Name: ' + name)
print('USN:',usn)
print('Total Marks: ' + str(total))
print('Percentage: ' + str(total/3))