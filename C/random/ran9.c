#include <stdio.h>

int i = 0;

int f() {
  i++;
  return 10;
}

int main(void) {
  // add to i directly
  i = 0;
  i += f();
  printf("%d\n", i);

  // add to i indirectly
  i = 0;
  i = i + f();
  printf("%d\n", i);

  // add to i indirectly + 1
  i = 0;
  i = i + 1 + f();
  printf("%d\n", i);

  // subtract from i directly
  i = 0;
  i -= f();
  printf("%d\n", i);

  // subtract from i indirectly
  i = 0;
  i = i - f();
  printf("%d\n", i);

  // subtract from i indirectly + 1
  i = 0;
  i = i + 1 - f();
  printf("%d\n", i);

  return 0;
}
