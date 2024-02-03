
#include <stdio.h>
#include <stdlib.h>

int main() {
  int size;

  printf("Enter the size of the 1D array: ");
  scanf("%d", &size);

  int *arr = (int *)malloc(size * sizeof(int));

  if (arr == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  } else {
    for (int i = 0; i < size; i++) {
      scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++) {
      printf("%d\t", arr[i]);
    }
  }
  free(arr);
  return 0;
}