#include <stdio.h>

int main() {
  int number;

  printf("Enter a number: ");
  scanf("%d", &number);

  if (number > 90 || number < 100) {
    printf("Greater than 90.\n");
  } else if (number > 50) {
    printf("Greater than 50.\n");
  } else if (number > 20) {
    printf("Greater than 20.\n");
  } else {
    printf("No conditon satisfise");
  }

  return 0;
}