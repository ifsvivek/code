/*Develop a program to compute the roots of a quadratic equation by accepting the coefficients. Print appropriate messages.*/

#include <stdio.h>
#include <math.h>

int main()
{
    float x1, x2, a, b, c, d;
    printf("Input the value of a, b & c: ");
    scanf("%f%f%f", &a, &b, &c);
    d = (b * b) - (4 * a * c);
    if (d == 0)
    {
        printf("Both roots are equal.\n");
        x1 = -b / (2.0 * a);
        x2 = x1;
        printf("First Root = %f", x1);
        printf("second Root = %f", x2);
    }
    else if (d > 0)
    {
        printf("Both Roots are real and diffent \n");
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("First Root= %f \n", x1);
        printf("Second Root= %f", x2);
    }
    else
    {
        printf("Roots are imaginary \n");
    }
}