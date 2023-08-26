/*
Write a C program to print a triangle of prime numbers upto given number of lines of the triangle.
e.g If number of lines is 3 the triangle will be 
2
3      5      
7      11      13  
*/

#include<stdio.h>
 
int prime(int num); //Function to find whether the number is prime or not.
int main() 
{
    int lines;
    scanf("%d", &lines); //Number of lines of the triangle is taken from test data.
    int counter=2;
    for (int i = 1; i <= lines; i++) {
        for (int j = 1; j <= i; j++) {
            while(!prime(counter)){
                counter++;
            }
            printf("%d\t", counter);
            counter++;
        }
        printf("\n");
    }
   return(0);
}
  
int prime(int num) {
   int i, isPrime = 1;
   for (i = 2; i <= (num/2); i++) {
      if (num % i == 0){
         isPrime = 0;
         break;
      }
   }
   if (isPrime==1 || num==2)
      return 1;
   else
      return 0;
}