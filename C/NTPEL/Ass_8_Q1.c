/*
Write a C Program to find HCF of 4 given numbers using recursive function.
*/

#include<stdio.h>
int gcd(int, int); //You have to write this function which calculates the GCD. 
	 
int main()
{
   int a, b, c, d, result;
   scanf("%d %d %d %d", &a, &b, &c, &d); /* Takes 4 number as input from the test data */
   result = gcd(gcd(a, b), gcd(c,d));
   printf("The GCD is %d", result);
}

//Complete the rest of the program to calculate GCD
int gcd(int a, int b) 
{ 
    // Everything divides 0  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
  
    // base case 
    if (a == b) 
        return a; 
  
    // a is greater 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 