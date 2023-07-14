// Simple Calculator
#include <stdio.h>

int main() {
    double num1, num2;
    char operator;
    
    printf("Enter the Equation: ");
    scanf("%lf%c%lf",&num1,&operator,&num2);
    
    double result = (operator == '+') ? num1 + num2 : 
                    (operator == '-') ? num1 - num2 : 
                    (operator == '*') ? num1 * num2 : 
                    (operator == '/') ? num1 / num2 : 0.0;
    
    printf("Result: %.2f\n", result);
    
    return 0;
}