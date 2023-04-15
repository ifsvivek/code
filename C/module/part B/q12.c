/*Develop a program to find the square root of a given number N and executes
for all possible inputs with appropriate messages. Note: Don’t use library function sqrt(n).*/

#include <stdio.h>
#include<math.h>
int main()
{
    int n, i = 1, dr, dd, j = 1, d;
    printf("Enter the number : ");
    scanf("%d", &n);
    while (i * i < n)
    {
        i = i + 1;
    }
    i = i - 1;
    printf("%d.", i);
    dr = 2 * i;
    dd = n - (i * i);
    while (j <= 5)
    {
        dd = dd * 100;
        d = 0;
        while ((dr * 10 + d) * d < dd)
        {
            d = d + 1;
        }
        d = d - 1;

        printf("%d",d);
        dd = dd - ((dr * 10 + d) * d);
        dr = dr * 10 + 2 * d;
        j = j + 1;
    }
}