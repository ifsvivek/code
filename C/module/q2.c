//Compute the roots of a quadratic equation by accepting the coefficients. Print appropriate messages
#include <stdio.h>
#include <math.h>

int main() {
  double a, b, c, d, root1, root2;
  printf("Input the value of a, b & c: : ");
  scanf("%lf %lf %lf", &a, &b, &c);
  d = b * b - 4 * a * c;

  if (d > 0) {
    root1 = (-b + sqrt(d)) / (2 * a);
    root2 = (-b - sqrt(d)) / (2 * a);
    printf("The roots of the equation are %.2f and %.2f.\n", root1, root2);
  } else if (d == 0) {
    root1 = root2 = -b / (2 * a);
    printf("The roots of the equation are both equal to %.2f.\n", root1);
  } else {
    printf("The roots of the equation are complex.\n");
  }
  return 0;
}