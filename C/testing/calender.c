#include <stdio.h>

int main() {
  int day, month, year;
  printf("Enter the date in DD/MM/YYYY format: ");
  scanf("%d/%d/%d", &day, &month, &year);

  // Calculate the day of the week
  int dayOfWeek =(year + (year / 4) - (year / 100) + (year / 400) + month * 2 + day) % 7;

  // Print the day of the week
  switch (dayOfWeek) {
    case 0:
      printf("Sunday\n");
      break;
    case 1:
      printf("Monday\n");
      break;
    case 2:
      printf("Tuesday\n");
      break;
    case 3:
      printf("Wednesday\n");
      break;
    case 4:
      printf("Thursday\n");
      break;
    case 5:
      printf("Friday\n");
      break;
    case 6:
      printf("Saturday\n");
      break;
  }

  return 0;
}
