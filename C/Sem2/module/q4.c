/*Write a C Program to display the following by reading the number of rows as
 input,
          1
       1  2  1
    1  2  3  2  1
 1  2  3  4  3  2  1
 ---------------------------
 nth row*/

#include <stdio.h>

int main() {
  int rows, i, j, k;

  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  for (i = 1; i <= rows; i++) {
    for (j = i; j < rows; j++) {
      printf("   ");
    }
    for (j = 1; j <= i; j++) {
      printf("%2d ", j);
    }
    for (k = i - 1; k >= 1; k--) {
      printf("%2d ", k);
    }
    printf("\n");
  }
  return 0;
}