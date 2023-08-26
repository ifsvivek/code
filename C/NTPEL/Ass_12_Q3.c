/*
Write a C program to store n elements using Dynamic Memory Allocation - calloc() and find the Largest element
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; 
    float *element;

    scanf("%d", &n); //Total number of elements
int i;
element = (float*) calloc(n, sizeof(float));
    if(element == NULL)
    {
        printf("Error!!! memory not allocated.");
        exit(0);
    }
    for(i = 0; i < n; ++i)
    {
       scanf("%f", element + i);
    }
    for(i = 1; i < n; ++i)
    {
       if(*element < *(element + i))
           *element = *(element + i);
    }
    printf("Largest element = %.2f\n", *element);
    return 0;
}