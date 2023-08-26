/*
The length of three sides are taken as input. Write a C program to find whether a triangle can be formed or not. If not display “This Triangle is NOT possible.”
 If the triangle can be formed then check whether the triangle formed is equilateral, isosceles, scalene or a right-angled triangle. 
(If it is a right-angled triangle then only print that it is a Right-angle triangle do not print it as scalene triangle). 
*/

#include<stdio.h>
int main()
{
    int a,b,c; 
    scanf("%d %d %d",&a, &b, &c); 

	if(a+b>c && b+c>a && c+a>b){
      if(a==b && b==c && c==a)
        printf("Equilateral Triangle");
      else if(a==b || b==c || c==a)
        printf("Isosceles Triangle");
      else{
        if( (a*a)+(b*b)==(c*c) || (a*a)+(c*c)==(b*b) || (c*c)+(b*b)==(a*a) )
          printf("Right-angle Triangle");
        else
          printf("Scalene Triangle");
      } 
	}
	else
      printf("Triangle is not possible");
	return 0;
}