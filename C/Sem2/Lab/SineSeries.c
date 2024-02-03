#include <math.h>
#include <stdio.h>

#define PI 3.142

int main() {
  int i, degree;
  float x, sum = 0, term, nume, deno;

  printf("Enter the value of degree: ");
  scanf("%d", &degree);

  x = degree * (PI / 180);
  nume = x;
  deno = 1;
  i = 2;

  do {
    term = nume / deno;
    nume = -nume * x * x;
    deno = deno * i * (i + 1);
    sum = sum + term;
    i = i + 2;
  } while (fabs(term) >= 0.00001);

  printf("\nThe sine of %d is %f", degree, sum);
  printf("\nThe sine function of %d is %f using library function", degree,
         sin(x));

  return 0;
}