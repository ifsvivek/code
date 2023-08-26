/*
Write a programe to find the roots of the equation using Newtons Raphson method.
f(x)= x^3 - 2x - 3
The max number of steps are taken as input.
*/

#include<stdio.h>
float f(float x);
float df (float x);

int main()
{
    int itr, maxmitr; // itr is the iteration number and maxitr is the maximum allowable iteration 
    float x0=1.0, x1; // x0 is the initial value and x1 is result 
    scanf("%d", &maxmitr); // Taken from the test cases 
#include<math.h>
itr = 1;
float h,root,err=0;
while(itr<=maxmitr)
    {
        h=f(x0)/df(x0);
        x1=x0-h;
        if(fabs(h)<err)
        {
            root=x1;
            break;
        }
        else
        x0=x1;
        itr++;
    }
        printf("Root = %8.6f\n", x1);
   return 0;
}
float f(float x)
{//our function
    return (x*x*x - 2*x - 3);
}
float df(float x)
{//function's differentiation
    return (3*x*x - 2);
}