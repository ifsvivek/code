#Develop a program that uses class Student which prompts the user to enter marks in three subjects and 
#calculates total marks, percentage and displays the score card details. [Hint: Use list to store the marks 
#in three subjects and total marks. Use __init__() method to initialize name, USN and the lists to store 
#marks and total, Use getMarks() method to read marks into the list, and display() method to display the score card details.

class Student:
    def __init__(self, name, USN):
        self.name = name
        self.USN = USN
        self.marks = []
        self.total = 0

    def getMarks(self):
        print("Enter marks in three subjects:")
        for i in range(3):
            marks = float(input(f"Subject {i+1}: "))
            self.marks.append(marks)
            self.total += marks

    def display(self):
        percentage = self.total / 3
        print("Score Card:")
        print(f"Name: {self.name.upper()}")
        print(f"USN: {self.USN.upper()}")
        print(f"Marks: {self.marks}")
        print(f"Total: {self.total}")
        print(f"Percentage: {percentage}")

name = input("Enter the name of the student: ")
USN = input("Enter the USN of the student: ")

student = Student(name, USN)
student.getMarks()
student.display()