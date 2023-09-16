//Write a C Program to find HCF of 4 given numbers using recursive function
#include<stdio.h>
int HCF(int, int); //You have to write this function which calculates the HCF. 
	 
int main()
{
   int a, b, c, d, result;
   scanf("%d %d %d %d", &a, &b, &c, &d); /* Takes 4 number as input from the test data */
   result = HCF(HCF(a, b), HCF(c,d));
   printf("The HCF is %d", result);
}

//Complete the rest of the program to calculate HCF
int HCF(int n1, int n2) {
    if (n2 == 0) {
        return n1;
    } else {
        return HCF(n2, n1 % n2);
    }
}