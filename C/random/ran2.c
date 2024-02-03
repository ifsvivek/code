#include <stdio.h>
int main() {
  long n;
  int len;
  printf("Enter a number");
  scanf("%d", &n);
  while (n > 0) {
    n = n / 10;
    len++;
  }
  printf("Len:%d", len);
}