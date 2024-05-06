//To find the array elements are unique or not

#include <stdio.h>

int unique(int n, int A[]) {
    for (int i = 0;i <= n - 2;i++) {
        for (int j = i + 1;j <= n - 1;j++) {
            if (A[i] == A[j])
                return 0;
        }
    }
    return 1;
}

void main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements: ");
    for (int i = 0;i < n;i++)
        scanf("%d", &A[i]);
    int flag = unique(n, A);
    if (flag == 1)
        printf("The elements are unique\n");
    else
        printf("The elements are not unique\n");
}