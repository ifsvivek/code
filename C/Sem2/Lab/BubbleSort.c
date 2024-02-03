#include <stdio.h>

int main() {
  int n, i, j, a[10], temp;

  printf("\nEnter the number of elements: ");
  scanf("%d", &n);

  printf("Enter the array elements:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  printf("Original elements are:\n");
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }

  printf("\nThe sorted elements are:\n");
  for (i = 0; i < n; i++) {
    printf("%d\n", a[i]);
  }

  return 0;
}