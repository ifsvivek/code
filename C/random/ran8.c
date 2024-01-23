#include <stdio.h>
#include <math.h>

// Define the function f(x)
double f(double x) {
    return x * exp(2 * x) - 3 * x * x - 5;
}

// Bisection Method
double bisection(double a, double b, double tol, int max_iterations) {
    double c;
    for (int i = 1; i <= max_iterations; i++) {
        c = (a + b) / 2;
        if (f(c) == 0 || (b - a) / 2 < tol) {
            return c;
        }
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}

int main() {
    double a = 0;    // Left endpoint of the initial interval
    double b = 3;    // Right endpoint of the initial interval
    double tol = 0.0001; // Desired tolerance (four decimal places)
    int max_iterations = 5; // Maximum number of iterations
    
    double root = bisection(a, b, tol, max_iterations);
    
    printf("Approximate root: %.4lf\n", root);
    
    return 0;
}
