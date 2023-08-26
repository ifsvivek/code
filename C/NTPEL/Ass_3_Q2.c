/*
Write a C program to check if a given Number is zero or Positive or Negative Using if...else statement.
[Week 3 programming assignments will not be considered for final evaluation]
*/

#include <stdio.h>
int main()
{
    double number;
    scanf("%lf", &number); 
    
	if(number == 0)
      printf("The number is 0.");
	else if(number > 0)
      printf("Positive number.");
    else
      printf("Negative number.");
    return 0;
}