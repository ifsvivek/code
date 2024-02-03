#include <stdio.h>
#include <stdlib.h>

int main() {
  int a[10][10], b[10][10], c[10][10];
  int m, n, p, q, i, j, k;

  printf("Enter the order of the matrix A\n");
  scanf("%d %d", &m, &n);

  printf("Enter the order of the matrix B\n");
  scanf("%d %d", &p, &q);

  if (n != p) {
    printf("\nMultiplication not possible\n");
    exit(0);
  } else {
    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
      }
    }

    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < p; i++) {
      for (j = 0; j < q; j++) {
        scanf("%d", &b[i][j]);
      }
    }

    printf("\nMatrix A:\n");
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        printf("%d\t", a[i][j]);
      }
      printf("\n");
    }

    printf("\nMatrix B:\n");
    for (i = 0; i < p; i++) {
      for (j = 0; j < q; j++) {
        printf("%d\t", b[i][j]);
      }
      printf("\n");
    }

    for (i = 0; i < m; i++) {
      for (j = 0; j < q; j++) {
        c[i][j] = 0;
        for (k = 0; k < n; k++) {
          c[i][j] += a[i][k] * b[k][j];
        }
      }
    }

    printf("\nProduct of A and B matrices: MATRIX C\n");
    for (i = 0; i < m; i++) {
      for (j = 0; j < q; j++) {
        printf("%d\t", c[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}