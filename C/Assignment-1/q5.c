//Swap 2 numbers
#include <stdio.h>
#define SWAP(a, b) do { (a) ^= (b); (b) ^= (a); (a) ^= (b); } while (0)
int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Before Swap\nA=%d\nB=%d",a,b);
    SWAP(a,b);
    printf("\nAfter Swap\nA=%d\nB=%d",a,b);
    return 0;
}