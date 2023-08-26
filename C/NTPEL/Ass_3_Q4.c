/*
Write a C program to check whether a given number (integer) is Even or Odd.
[Week 3 programming assignments will not be considered for final evaluation]
*/

#include <stdio.h>
int main()
{
    int number;
    scanf("%d", &number); 

	if(number%2 == 0)
      printf("%d is even.", number);
	else
      printf("%d is odd.", number);
	return 0;
}