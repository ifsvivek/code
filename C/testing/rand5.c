#include <stdio.h>

int main() {
  int n;
  long int fact;
  scanf("%d", &n);

  if (n < 0) {
    printf("Factorial is not defined for negative numbers.");
  } else {
    fact = 1;
    int i = 2;
    while (i <= n) {
      fact *= i;
      i++;
    }
    printf("The factorial of %d is: %ld\n", n, fact);
  }

  return 0;
}