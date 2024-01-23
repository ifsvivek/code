#include <stdio.h>

int str_len(char *str) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    count++;
  }
  return count;
}

void str_rev(char *str) {
  int i, j;

  for (i = 0, j = str_len(str) - 1; i < j; i++, j--) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

int main() {
  char str[100];

  printf("Enter a string: ");
  scanf("%s", str);

  str_rev(str);

  printf("The reversed string is: %s\n", str);

  return 0;
}