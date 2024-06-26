// prime Number in a given range n

#include <stdio.h>
#include <math.h>

int prime(int n) {
    int A[n+1];
    for (int p = 2;p <= n;p++)
        A[p] = p;
    for (int p = 2;p <= floor(sqrt(n));p++) {
        if (A[p] != 0) {
            int j = p * p;
            while (j <= n) {
                A[j] = 0;
                j = j + p;
            }
        }
    }
    int i = 0;
    for (int p = 2;p <= n;p++) {
        if (A[p] != 0) {
            printf("%d ", A[p]);
            i++;
        }
    }
}

int main() {
    int n;
    printf("Enter the range: ");
    scanf("%d", &n);
    if (n < 2)
        printf("No prime numbers in the given range\n");
    prime(n);
    return 0;
}