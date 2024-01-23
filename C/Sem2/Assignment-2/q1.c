#include <stdio.h>

int main(){
    int N;

    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int A[N], sumOdd = 0, sumEven = 0, totalSum = 0, oddCount = 0, evenCount = 0;

    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++){
        scanf("%d", &A[i]);
        totalSum += A[i];

        if (A[i] % 2 == 0){
            sumEven += A[i];
            evenCount++;
        }
        else{
            sumOdd += A[i];
            oddCount++;
        }
    }

    float average = (float)totalSum / N;
    printf("Sum of odd numbers: %d\nSum of even numbers: %d\nAverage of all numbers: %.2f\n", sumOdd, sumEven, average);
    return 0;
}
