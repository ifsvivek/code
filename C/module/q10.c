/* Implement structures to read, write and compute average- marks of the students, list the students scoring above
and below the average marks for a class of N students. */

#include <stdio.h>

#define MAX_NAME_LENGTH 50

struct Student
{
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    float marks;
};

void readStudentData(struct Student *student)
{
    printf("Enter student name: ");
    scanf("%s", student->name);

    printf("Enter student roll number: ");
    scanf("%d", &student->rollNumber);

    printf("Enter student marks: ");
    scanf("%f", &student->marks);
}

void writeStudentData(const struct Student *student)
{
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNumber);
    printf("Marks: %.2f\n", student->marks);
}

float computeAverageMarks(const struct Student *students, int numStudents)
{
    float totalMarks = 0.0;

    for (int i = 0; i < numStudents; i++)
    {
        totalMarks += students[i].marks;
    }

    return totalMarks / numStudents;
}

void listStudentsAboveAverage(const struct Student *students, int numStudents, float averageMarks)
{
    printf("\nStudents scoring above average marks:\n");

    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].marks > averageMarks)
        {
            writeStudentData(&students[i]);
        }
    }
}

void listStudentsBelowAverage(const struct Student *students, int numStudents, float averageMarks)
{
    printf("\nStudents scoring below average marks:\n");

    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].marks < averageMarks)
        {
            writeStudentData(&students[i]);
        }
    }
}

int main()
{
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student students[numStudents];

    printf("\nEnter student details:\n");
    for (int i = 0; i < numStudents; i++)
    {
        printf("\nStudent %d:\n", i + 1);
        readStudentData(&students[i]);
    }

    float averageMarks = computeAverageMarks(students, numStudents);
    printf("\nAverage marks: %.2f\n", averageMarks);
    listStudentsAboveAverage(students, numStudents, averageMarks);
    listStudentsBelowAverage(students, numStudents, averageMarks);
    return 0;
}