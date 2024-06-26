#include<stdio.h>

int indegree[10], cost[10][10], n;
void calculate() {
    for (int i = 0;i < n;i++) {
        indegree[i] = 0;
        for (int j = 0;j < n;j++)
            indegree[i] += cost[j][i];
    }
}

void souceremoval() {
    int removed[10] = { 0 }, i;
    printf("Topological order=\n");
    for (int count = 0;count < n;count++) {
        calculate();
        for (i = 0;i < n;i++) {
            if (removed[i] == 0 && indegree[i] == 0)
                break;
        }
        if (i == n) {
            printf("Graph is cyclic\nNo solution\n");
            return;
        }
        printf("%d\t", i);
        removed[i] = 1;
        for (int k = 0;k < n;k++)
            cost[i][k] = 0;
    }
    printf("Above is the correct solution\n");
}

void main() {
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    printf("Enter the adj matrix\n");
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++)
            scanf("%d", &cost[i][j]);
    }
    souceremoval();
}