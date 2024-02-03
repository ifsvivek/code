#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *dayname;
  int date;
  char *activity;
} cal;

cal *create() {
  return ((cal *)malloc(
      7 * sizeof(cal)));  // Allocate memory for an array of 7 cal structures
}

void read(cal *d) {
  int i, flag;
  char temp[20];
  for (i = 0; i < 7; i++) {
    d[i].dayname = NULL;
    d[i].activity = NULL;
    d[i].date = -1;
  }
  do {
    printf("Enter the date: ");
    scanf("%d", &i);
    if (i < 0 || i > 6) {
      printf("Enter a valid number between 0 and 6.\n");
      return;
    } else {
      d[i].date = i;
      printf("\nEnter day name: ");
      scanf("%s", temp);
      d[i].dayname = strdup(temp);
      printf("\nEnter the activity: ");
      scanf("%s", temp);
      d[i].activity = strdup(temp);
    }
    printf("\n1 to continue or 0 to stop: ");
    scanf("%d", &flag);
  } while (flag == 1);
}

void display(cal *d) {
  int i;
  for (i = 0; i < 7; i++) {
    if (d[i].date != -1) {
      printf("Date=%d, Day name=%s, Activity=%s\n", d[i].date, d[i].dayname,
             d[i].activity);
    }
  }
}

void deallocate(cal *d) {
  int i;
  for (i = 0; i < 7; i++) {
    free(d[i].dayname);
    free(d[i].activity);
  }
  free(d);
}

int main() {
  cal *d = create();
  read(d);
  display(d);
  deallocate(d);
  return 0;
}
