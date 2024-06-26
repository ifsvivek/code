#include<stdio.h>

void warshall(int r[][10], int n) {
    for (int k = 0; k < n; k++) {
        printf("\nR(%d)\n", k);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                r[i][j] = r[i][j] || (r[i][k] && r[k][j]);
                printf("%d\t", r[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    int n, r[10][10];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &r[i][j]);
    }
    warshall(r, n);
}