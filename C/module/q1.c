// Simple Calculator
#include <stdio.h>

int main() {
    double num1, num2;
    char operator;
    
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    
    printf("Enter the second number: ");
    scanf("%lf", &num2);
    
    double result = (operator == '+') ? num1 + num2 : 
                    (operator == '-') ? num1 - num2 : 
                    (operator == '*') ? num1 * num2 : 
                    (operator == '/') ? num1 / num2 : 0.0;
    
    printf("Result: %lf\n", result);
    
    return 0;
}