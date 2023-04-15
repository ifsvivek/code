/* Implement using functions to check whether the given number
is prime and display appropriate messages. (No built-in math function)*/
#include <stdio.h>

int main()
{

    int n, i, r = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n == 0 || n == 1)
        r = 1;

    for (i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            r = 1;
            break;
        }
    }
    if (r == 0)
        printf("%d is a prime number.", n);
    else
        printf("%d is not a prime number.", n);

    return 0;
}