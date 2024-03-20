// code to find sum of digits in a number
// but if sum of digits is greater than 9 then again find sum of digits of that number
// eg: 5883 => 5+8=13 => 1+3=4 4+8=12 => 1+2=3 3+3=6 => 6

#include <stdio.h>

int main() {
    int n, sum = 0, rem;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n > 0) {
        rem = n % 10;
        sum += rem;
        n = n / 10;
        if (n == 0 && sum > 9) {
            n = sum;
            sum = 0;
        }
    }
    printf("Sum of digits is: %d", sum);
    return 0;
}