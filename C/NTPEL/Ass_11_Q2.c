/*
Write a programe to find intergation of x^2 form a to b  using Trapezoidal rule with 10 segement between a to b.
*/

#include<stdio.h>
float func(float x);
int main()
{
  int n=10; //Taking n=10 sub intervals
  float a,b,integral; //integral is the integration result
  scanf("%f",&a); // initial limit taken from test case 
  scanf("%f",&b); // Final limit taken from test case

#include<math.h>
/*Begin Simpson's 1/3rd Procedure: */
float h,sum=0,x;  
h=fabs(b-a)/10;
  for(int i=1;i<10;i++){
    x=a+i*h;
    sum=sum+func(x);
  }
  integral=(h/2)*(func(a)+func(b)+2*sum);
printf("The integral is: %0.6f\n",integral);
return 0;
}
float func(float x)
{
  return x*x;
}