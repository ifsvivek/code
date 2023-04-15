/*	Develop a program to find the reverse of a positive integer and check for palindrome or not. Display appropriate messages.*/

#include <stdio.h>
int main()
{
    int n, reversed = 0, r, orignal;
    printf("Enter an integer: ");
    scanf("%d", &n);
    orignal = n;
    while (n != 0)
    {
        r = n % 10;
        reversed = reversed * 10 + r;
        n /= 10;
    }
    printf("Reversed number = %d\n", reversed);

    if (orignal == reversed)

        printf("%d is a palindome.", orignal);

    else
        printf("%d is not a palindome.", orignal);
}