//Greatest of 3 numbers
#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter Three Numbers: ");
    scanf("%d%d%d", &a, &b, &c);
    int greatest = (a > b && a > c) ? a : (b > c) ? b : c;
    printf("%d is the Greatest", greatest);
    return 0;
}