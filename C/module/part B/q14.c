/*Develop a program using pointers to compute the sum, mean and
standard deviation of all elements stored in an array of n real numbers.*/

#include <stdio.h>
#include <conio.h>
void main()
{
    int arr[10], n, i, sum = 0, mean;

    int *ptr = arr;
    printf("Enter the number of elements you want to use: ");
    scanf("%d", &n);
    printf("\nEnter %d Elements:", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n; i++)
    {
        sum += *ptr;
        *ptr++;
    }

    mean = sum / n;
    printf("\nSum = %d\nmean = %d", sum, mean);
}