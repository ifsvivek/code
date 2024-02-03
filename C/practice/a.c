#include <stdio.h>
int ls(int *p, int n, int ele) {
  for (int i = 0; i < n; i++) {
    if (p[i] == ele) {
      printf("Element found at %d", i + 1);
      return 0;
    }
  }
  printf("Element not found");
}
int main() {
  int n, ele;
  printf("enter the number of elements");
  scanf("%d", &n);
  int a[n];
  printf("Enter the element");
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  printf("Enter the element ");
  scanf("%d", &ele);
  ls(a, n, ele);
}