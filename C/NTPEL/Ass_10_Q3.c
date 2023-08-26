/*
Write a C program to sort a given 1D array using pointer in ascending order.
*/

#include <stdio.h>
int main()
{
    int a[100],i, n;
    scanf("%d",&n);  //Number of elements of the array is taken from the test case data 
   
   for (i=0; i<n; i++)
    {
        scanf("%d",a+i); // Input the array elements
    }

int* b;
int j,temp; 
b = &a[0];
for(i=0;i<n;i++)
   {
    for(j=i+1;j<n;j++)
    {
       if( *(a+i) > *(a+j))
       {
      temp = *(a+i);
      *(a+i) = *(a+j);
      *(a+j) = temp;
       }
    }
   }
    
    for (i=0; i<n; i++)
    {
        printf("%d\n",*(a+i));
    }
    return 0;
}
