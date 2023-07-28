/*Compute sin(x)/cos(x) using Taylor series approximation. Compare your result with the built-in library function.
Print both the results with appropriate inferences. */

#include <stdio.h>
#include <math.h>

double taylorApproximation(double x, int terms)
{
    double result = 0.0;
    double numerator = x;
    double denominator = 1.0;
    double term = numerator / denominator;
    int sign = 1;

    for (int i = 1; i <= terms; i++)
    {
        result += sign * term;
        numerator *= x * x;
        denominator *= (2 * i) * (2 * i + 1);
        term = numerator / denominator;
        sign *= -1;
    }

    return result;
}

int main()
{
    double x;
    int terms;

    printf("Enter the value of x : ");
    scanf("%lf", &x);

    printf("Enter the number of terms to compute in the Taylor series: ");
    scanf("%d", &terms);
    x=(x*3.14)/180;
    double taylorResult = taylorApproximation(x, terms);
    double libraryResult = tan(x);

    printf("Approximation using Taylor series: %.6f\n", taylorResult);
    printf("Result using library function (tan(x)): %.6f\n", libraryResult);

    printf("\nComparison:\n");

    if (fabs(taylorResult - libraryResult) < 0.000001)
    {
        printf("The results are approximately equal.\n");
    }
    else
    {
        printf("The results are not equal.\n");
    }
    return 0;
}