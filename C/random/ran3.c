#include <stdio.h>
int main() {
  int n;
  int temp;
  int i;
  printf("Enter a number");
  scanf("%d", &n);
  int array[10];
  for (int i = 0; i < 10; i++) {
    array[i] = 0;
  }
  while (n > 0) {
    temp = n % 10;
    array[temp]++;
    n = n / 10;
  }
  for (int i = 0; i < 10; i++) {
    printf("%d:%d \n", i, array[i]);
  }
}