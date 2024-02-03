#include <stdio.h>
int main() {
  int a, b, c;
  float d;
  char o;
  printf("Select an operator (+, -, *, /): ");
  scanf("%c", &o);

  printf("Enter a: ");
  scanf("%d", &a);
  printf("Enter b: ");
  scanf("%d", &b);

  if (o == '+') {
    c = a + b;
    printf("C= %d", c);
  }

  if (o == '-') {
    c = a - b;
    printf("C= %d", c);
  }

  if (o == '*') {
    c = a * b;
    printf("C= %d", c);
  }

  if (o == '/') {
    d = a / b;
    printf("D= %f", d);
  }
}