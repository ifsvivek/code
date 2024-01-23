#include <stdio.h>

int isPrime(int n){
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main(){
    int n1, n2;
    printf("Enter the first number: ");
    scanf("%d", &n1);
    printf("Enter the second number: ");
    scanf("%d", &n2);

    printf("Prime numbers between %d and %d: ", n1, n2);
    for (int i = n1; i <= n2; i++){
        if (isPrime(i))
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
