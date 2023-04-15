/*Develop a program to solve simple computational problems using arithmetic expressions and use
of each operator leading to the simulation of a commercial calculator. (No built-in math function)*/

#include <stdio.h>
int main()
{
    char opt;
    int n1, n2, n3;
    float res;
    printf("Select an operator (+, -, *, /): ");
    scanf(" %c", &opt);
    printf("Enter the first number: ");
    scanf("%d", &n1);
    printf("Enter the second number: ");
    scanf("%d", &n2);

    switch(opt) {
        case '+':
            n3 = n1 + n2;
            printf("%d + %d = %d", n1, n2, n3);
            break;
        case '-':
            n3 = n1 - n2;
            printf("%d - %d = %d", n1, n2, n3);
            break;
        case '*':
            n3 = n1 * n2;
            printf("%d * %d = %d", n1, n2, n3);
            break;
        case '/':
            if (n2 == 0) {
                printf("Divisor cannot be zero. Please enter another value");
                scanf("%d", &n2);
            }
            res = (float)n1 / n2;
            printf("%d / %d = %.2f", n1, n2, res);
            break;
        default:
            printf("Invalid operator");
    }
}