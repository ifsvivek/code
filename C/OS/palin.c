#include <stdio.h>
#include <string.h>

int is_palindrome(char str[]) {
  int len = strlen(str);
  for (int i = 0, j = len - 1; i < j; i++, j--) {
    if (str[i] != str[j]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  if (is_palindrome(str)) {
    printf("%s is a palindrome!\n", str);
  } else {
    printf("%s is not a palindrome.\n", str);
  }
  return 0;
}
