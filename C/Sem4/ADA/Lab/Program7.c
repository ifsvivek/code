#include<stdio.h>
#include<stdlib.h>

void greedy_ks(int n, int m, float p[], float w[]) {
    float profit = 0, max;
    int i, k, count;
    for (count = 0; count < n; count++) {
        max = 0;
        for (i = 0; i < n; i++) {
            if (((p[i] / w[i]) >= max)) {
                k = i;
                max = p[i] / w[i];
            }
        }
        if (w[k] <= m) {
            printf("item %d with profit %f is selected\n", k, p[k]);
            profit += p[k];
            m -= w[k];
            p[k] = 0;
        } else
            break;
    }
    printf("Discrete knapsack profit= %f\n", profit);
    float x = m / w[k];
    profit += p[k] * x;
    printf("Continuos knapsack profit= %f", profit);
}

void main() {
    int n, m;
    printf("Enter the no. of objects: ");
    scanf("%d", &n);
    float* p, * w;

    p = (float*)malloc(n * sizeof(float));
    w = (float*)malloc(n * sizeof(float));

    printf("Enter the capacity: ");
    scanf("%d", &m);

    printf("Enter the profit of %d items: ", n);
    for (int i = 0;i < n;i++)
        scanf("%f", &p[i]);

    printf("Enter the weight of %d items: ", n);
    for (int i = 0;i < n;i++)
        scanf("%f", &w[i]);

    greedy_ks(n, m, p, w);
}