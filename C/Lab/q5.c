//simple calculator
#include<stdio.h>
int main(){
    float a,b,result;
    char o;
    printf("Enter 2 numbers: ");
    scanf("%f%f",&a,&b);
    printf("Enter an option (+, -, *, /): ");
    scanf(" %c", &o);
    result =(o == '+') ? a + b :
            (o == '-') ? a - b :
            (o == '*') ? a * b :
            (o == '/') ? a / b : 0.0;
    printf("Result: %0.2f\n", result);
}