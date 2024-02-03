#include <stdio.h>

int main() {
  char input[100] = "programming in C is fun", output[100];
  int i = 0;
  while (input[i] != '\0') {
    char c = input[i];

    if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z')) {
      output[i] = c + 1;
    } else if (c == 'z' || c == 'Z') {
      output[i] = c - 25;
    } else {
      output[i] = c;
    }
    i++;
  }

  output[i] = '\0';
  printf("Modified string: %s\n", output);
  return 0;
}
