// Code to find the sum of digits in a number.
// If the sum of digits is greater than 9, the sum of the digits of the sum is calculated.
// This process is repeated until the sum is less than 10.
// For example, for the number 5883, the sum of the digits is calculated as follows:
// 5 + 8 + 8 + 3 = 24 => 2 + 4 = 6

#include <stdio.h>

int main() {
    int n, sum = 0, rem;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n > 0 || sum > 9) {
        if (n == 0) {
            n = sum;
            sum = 0;
        }
        rem = n % 10;
        sum += rem;
        n = n / 10;
    }
    printf("Sum of digits is: %d", sum);
    return 0;
}