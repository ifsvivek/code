#include <stdio.h>

int main() {
    char operator;
    float num1, num2, result = 0;

    printf("Choose an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero is not allowed.\n");
                return 1;
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
            return 1;
    }

    printf("%0.2f%c%0.2f = %.2f\n", num1, operator, num2, result);
    return 0;
}