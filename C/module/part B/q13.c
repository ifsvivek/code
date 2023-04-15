/*Implement structures to read, write, and compute average-marks and the students
scoring above and below the average marks for a class of N students*/
#include <stdio.h>
struct student
{
    int marks;
} st[10];
void main()
{
    int i, n;
    float total = 0, avgmarks;
    printf("\nEnter the number of students in class:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter student %d marks :", i + 1);
        scanf("%d", &st[i].marks);
    }
    for (i = 0; i < n; i++)
    {
        total = total + st[i].marks;
    }
    avgmarks = total / n;
    printf("\nAverage marks = %.2f", avgmarks);
    for (i = 0; i < n; i++)
    {
        if (st[i].marks >= avgmarks)
        {
            printf("\n student %d marks = %d above average", i + 1, st[i].marks);
        }
        else
        {
            printf("\n student %d marks = %d below average", i + 1, st[i].marks);
        }
    }
}