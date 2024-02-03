// Area and perimeter of a circle
#include <stdio.h>

int main() {
  int rad;
  printf("Enter the radius: ");
  scanf("%d", &rad);
  printf("Area: %0.2f\n", 3.14 * rad * rad);
  printf("Perimeter: %0.2f", 2 * 3.14 * rad);
  return 0;
}