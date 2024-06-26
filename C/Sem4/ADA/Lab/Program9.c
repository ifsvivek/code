#include<stdio.h>
#include<stdlib.h>

int count = 0;

void SelectionSort(int arr[], int n) {
    int i, j, pos, temp;
    for (i = 0; i < n - 1; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            count++;
            if (arr[j] < arr[pos]) {
                pos = j;
            }
        }
        if (pos != i) {
            temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
    }
}

void main() {
    int* A, n, i;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    A = (int*)malloc(n * sizeof(int));
    for (i = 0;i < n;i++)
        A[i] = rand() % 1001;
    SelectionSort(A, n);
    printf("Sorted Elements are\n");
    for (i = 0;i < n;i++)
        printf("%d ", A[i]);
    printf("\nBasic Operation Count= %d\n", count);
    free(A);

}