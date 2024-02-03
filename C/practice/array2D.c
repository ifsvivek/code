#include <stdio.h>
#include <stdlib.h>

int main() {
  int rows, cols;

  // Get the number of rows and columns from the user
  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  // Dynamically allocate memory for the 2D array
  int **arr = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    arr[i] = (int *)malloc(cols * sizeof(int));
  }

  // Initialize the elements of the 2D array
  printf("Enter elements of the array:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("Enter element at position (%d, %d): ", i, j);
      scanf("%d", &arr[i][j]);
    }
  }

  // Print the elements of the 2D array
  printf("Elements of the array:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  // Free the dynamically allocated memory
  for (int i = 0; i < rows; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}