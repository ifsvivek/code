#include <stdio.h>
#include <limits.h>

#define N 4

void optimalBST(float P[], float Q[]) {
    float C[N+1][N+1];
    float W[N+1][N+1];
    int R[N+1][N+1];
    int i, j, k, l;

    for (i = 0; i <= N; i++) {
        W[i][i] = Q[i];
        C[i][i] = 0;
        R[i][i] = 0;
    }

    for (l = 1; l <= N; l++) {
        for (i = 0; i <= N - l; i++) {
            j = i + l;
            C[i][j] = INT_MAX;
            W[i][j] = W[i][j-1] + P[j-1] + Q[j];
            for (k = i+1; k <= j; k++) {
                float temp = C[i][k-1] + C[k][j] + W[i][j];
                if (temp < C[i][j]) {
                    C[i][j] = temp;
                    R[i][j] = k;
                }
            }
        }
    }

    printf("C table:\n");
    for (i = 0; i <= N; i++) {
        for (j = 0; j <= N; j++) {
            printf("%.2f\t", C[i][j]);
        }
        printf("\n");
    }

    printf("\nR table:\n");
    for (i = 0; i <= N; i++) {
        for (j = 0; j <= N; j++) {
            printf("%d\t", R[i][j]);
        }
        printf("\n");
    }

    printf("\nW table:\n");
    for (i = 0; i <= N; i++) {
        for (j = 0; j <= N; j++) {
            printf("%.2f\t", W[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float P[N] = {0.05, 0.2, 0.1, 0.05};
    float Q[N+1] = {0.2, 0.1, 0.2, 0.05, 0.05};

    optimalBST(P, Q);

    return 0;
}


/*
output:
C table:

0.00	0.35	1.10	1.60	1.95	

0.00	0.00	0.50	1.00	1.35	

0.00	0.00	0.00	0.35	0.60	

0.00	0.00	0.00	0.00	0.15	

0.00	0.00	0.00	0.00	0.00	



R table:

0	1	2	2	2	

0	0	2	2	2	

0	0	0	3	3	

0	0	0	0	4	

0	0	0	0	0	



W table:

0.20	0.35	0.75	0.90	1.00	

0.00	0.10	0.50	0.65	0.75	

0.00	0.00	0.20	0.35	0.45	

0.00	0.00	0.00	0.05	0.15	

0.00	0.00	0.00	0.00	0.05	


*/
