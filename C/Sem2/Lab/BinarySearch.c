#include <stdio.h>
#include <string.h>

int main() {
  int a[10], key;
  int n, i, low, high, mid, found = 0;

  printf("Enter the number of numbers to read: ");
  scanf("%d", &n);

  printf("Enter the numbers in ascending order:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  printf("Enter the number to search: ");
  scanf("%d", &key);

  low = 0;
  high = n - 1;

  while (low <= high && found != 1) {
    mid = (low + high) / 2;

    if (a[mid] == key)
      found = 1;
    else if (a[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }

  if (found == 1)
    printf("\nNumber found at position: %d\n", mid + 1);
  else
    printf("\nNumber not found\n");

  return 0;
}
