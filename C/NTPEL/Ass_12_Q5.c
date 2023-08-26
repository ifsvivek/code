/*
Write a C program to find the sum of two 1D integer arrays ‘A’  and ‘B’ of same size and store the result in another array ‘C’, where the size of the array and the elements of the array are taken as input.
In the Test case the input is given as follows
5
10
20
30
40
50

1
2
3
4
5

So the output will be displayed as

Invalid HTML tag: tag name o:p is not allowed

Result is
11
22
33
44
55
*/

#include<stdio.h>
#include<stdlib.h>

void main()
{
 int i,n;
 
//The number of elements in each array is taken from test case data 

 scanf("%d", &n);
int *a, *b, *c;
a = (int *)malloc(n * sizeof(int));
b = (int *)malloc(n * sizeof(int));
c = (int *)malloc(n * sizeof(int));
for (i = 0; i < n; i++){
  	scanf("%d", a + i);
}
for (i = 0; i < n; i++){
 	scanf("%d", b + i);
}
for (i = 0; i < n; i++){
	*(c + i) = *(a + i) + *(b + i);
}
printf("Result is\n");

 for(i=0; i<n; i++)
 {
  printf("%d\n",*(c+i));
 }

}