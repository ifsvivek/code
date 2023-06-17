//Greatest of 2 numbers
#include <stdio.h>

int main() {
    int a, b;
    printf("Enter Two Numbers: ");
    scanf("%d%d", &a, &b);
    printf("%d is Greater", (a > b) ? a : b);
    return 0;
}