#include<stdio.h>

int max(int a, int b) {return a > b ? a : b;}

void DPknapsack(int n, int m, int w[], int p[]) {
    int i, j, V[n + 1][m + 1];
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                V[i][j] = 0;
            } else if (j < w[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + p[i]);
            printf("%d\t", V[i][j]);
        }
        printf("\n");
    }
    printf("Optimal profit: %d\n", V[n][m]);
    printf("Items selected: \n");
    while (m) {
        if (V[n][m] != V[n - 1][m]) {
            printf("%d\t", n);
            m -= w[n];
        }
    }
}

void main() {
    int n, m, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int w[n + 1], p[n + 1];
    printf("Enter the weights of the items: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("Enter the profits of the items: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &m);
    DPknapsack(n, m, w, p);
}