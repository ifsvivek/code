/*Develop a Program to compute Sin(x) using Taylor series approximation.
Compare your result with the built-in Library function.
Print both the results with appropriate messages.*/

#include <stdio.h>
#include <math.h>
#define PI 3.142
int main()
{

    int n, i;
    float deg, x, sum = 0, term = 0;
    printf("Enter number of terms\n");
    scanf("%d", &n);
    printf("Enter the degree\n");
    scanf("%f", &deg);
    x = (deg * PI) / 180;
    printf("In radians = %f \n", x);
    term = x;
    sum = term;
    for (i = 3; i <= n; i++)
    {
        term = (-term * x * x) / (i * (i - 1));
        sum = sum + term;
    }
    printf("sin(%f)=%f\n", deg, sum);
    printf("Inbuild funtion sin(%f) =%f\n", deg, sin(x));
    printf("User function sin(%f) = %f", deg, sum);
}