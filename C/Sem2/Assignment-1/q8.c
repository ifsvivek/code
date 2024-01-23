//To check a number is odd or even
#include <stdio.h>

int main() {
    int a;
    printf("Enter the Number: ");
    scanf("%d", &a);

    printf("%d is %s", a, (a % 2 == 0) ? "Even" : "Odd");
    return 0;
}