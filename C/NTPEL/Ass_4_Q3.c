/*
Write a program to find the factorial of a given number using while loop
*/

#include<stdio.h>
void main()
{
    int n;
    long int fact; 
    scanf("%d",&n); 
	fact= 1;
	int i=n;
	while(i)
    {
      fact= fact*i;
      i--;
    }
	printf("The Factorial of %d is : %ld",n,fact);
}


/*
by for loop

for(i=1;i<=n;i++){
    fact=fact*i;
}
*/
