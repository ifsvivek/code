/*
Write a C Program to find Largest Element of an Integer Array. 
Here the number of elements in the array  (n) and the elements of the array is read from the test data. 
Use the printf statement given below to print the largest element.
*/
#include <stdio.h>

int main()
{
    int i, n, largest;
    int arr[100];

    scanf("%d", &n); /*Accepts total number of elements from the test data */

 for(i = 0; i < n; ++i)
    {
       scanf("%d", &arr[i]); /* Accepts the array element from test data */
    }
largest = arr[0];
for(i = 1; i < n; ++i)
    {
           if(largest < arr[i])
           largest = arr[i];
    }
    printf("Largest element = %d", largest);

    return 0;
}