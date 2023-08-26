// Write a C Program to find the Largest Number (integer)  among Three Numbers (integers) using IF and Logical && operator.
// [Week 3 programming assignments will not be considered for final evaluation]

#include <stdio.h>
int main()
{
    int n1, n2, n3;

    scanf("%d %d %d", &n1, &n2, &n3); 

	if(n1>n2 && n1>n3)
      printf("%d is the largest number.", n1);
	else if(n2>n1 && n2>n3)
      printf("%d is the largest number.", n2);
    else
      printf("%d is the largest number.", n3);
    return 0;
}