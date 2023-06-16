//Convert temperature in degree to Fahrenheit
#include <stdio.h>

int main() {
    float c;
    printf("Enter the celsius: ");
    scanf("%f", &c);
    printf("Fahrenheit: %0.2f\n",c*9/5+32);
    return 0;
}