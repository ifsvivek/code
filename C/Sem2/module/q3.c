/* An electricity board charges the following rates for the use of electricity:
for the first 200 units 80 paise per unit: for the next 100 units 90 paise per
unit: beyond 300 units Rs 1 per unit. All users are charged a minimum of Rs. 100
as meter charge. If the total amount is more than Rs 400, then an additional
surcharge of 15% of total amount is charged. Write a program to read the name of
the user, number of units consumed and print out the charges*/

#include <stdio.h>

int main() {
  char name[100];
  int units;
  float charge;

  printf("Enter the name of the user: ");
  gets(name);
  printf("Enter the number of units consumed: ");
  scanf("%d", &units);

  if (units <= 200) {
    charge = units * 0.80;
  } else if (units <= 300) {
    charge = 200 * 0.80 + (units - 200) * 0.90;
  } else {
    charge = 200 * 0.80 + 100 * 0.90 + (units - 300) * 1.00;
  }

  charge += 100;
  if (charge > 400) {
    charge = charge + (charge * 0.15);
  }
  printf("The charges for %s are Rs %.2f\n", name, charge);
  return 0;
}