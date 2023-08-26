/*
write a programe to find the root of the equation using bisection methods for differernt values of allowable error of roots
    f(x)= 2*x^3 - 3*x - 5
*/

#include<stdio.h>
float fun (float x); //Function fun returns the function value of f(x)
void bisection (float *x, float a, float b, int *itr); // This function computes the root of f(x) using bisection method

int main ()
{
    int itr = 0, maxmitr=10;
    float x, a=1.0, b=2.0, allerr, x1; 
      
    scanf("%f", &allerr);  // allerr is the allowable error taken from test case data 
    bisection (&x, a, b, &itr);

    #include<math.h>    
	do
    {
        if (fun(a)*fun(x) < 0)
            b=x;
        else
            a=x;
        bisection (&x1, a, b, &itr);
        if (fabs(x1-x) < allerr)
        {
          printf("Root = %1.4f\n", x1);
            return 0;
        }
        x=x1;
    }
    while (itr < maxmitr);
    return 1;
}
float fun (float x)
{
    return (2*x*x*x - 3*x - 5);
}
void bisection (float *x, float a, float b, int *itr)
{
    *x=(a+b)/2;
    ++(*itr);
}