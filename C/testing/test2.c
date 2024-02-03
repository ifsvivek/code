#include <stdio.h>
void main() {
  char name[20];
  float unit, cost, extra;
  printf("Enter your name: ");
  gets(name);
  printf("Enter the unit you used: ");
  scanf("%f", &unit);

  if (unit <= 200) {
    cost = 0.8 * unit + 100;
    puts(name);
    printf("unit used: %f\nbill = %f", unit, cost);
  } else if (unit > 200 && unit <= 300) {
    int a = unit - 200;
    cost = 0.8 * 200 + a * 0.9 + 100;
    puts(name);
    printf("unit used: %f\nbill = %f", unit, cost);
  } else if (unit > 300 && unit <= 400) {
    cost = unit + 100;
    puts(name);
    printf("unit used: %f\nbill = %f", unit, cost);
  } else {
    cost = unit + 100 + (unit * 0.15);
    puts(name);
    printf("unit used: %f\nbill = %f", unit, cost);
  }
}