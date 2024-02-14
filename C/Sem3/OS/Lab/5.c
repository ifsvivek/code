// Bankers Algorithm
#include <stdio.h>
int main() {
  int n = 5, r = 4, i, j, k;
  int alloc[5][4] = {{0, 0, 1, 2},
                     {1, 0, 0, 0}, 
                     {1, 3, 5, 4}, 
                     {0, 6, 3, 2}, 
                     {0, 0, 1, 4}};
  int max[5][4] = { {0, 0, 1, 2}, 
                    {1, 7, 5, 0}, 
                    {2, 3, 5, 6}, 
                    {0, 6, 5, 2}, 
                    {0, 6, 5, 6}};
  int avail[4] = {1, 5, 2, 0};
  int f[n], ans[n], ind = 0;
  for (k = 0; k < n; k++) {
    f[k] = 0;
  }
  int need[n][r];
  for (i = 0; i < n; i++) {
    for (j = 0; j < r; j++) {
      need[i][j] = max[i][j] - alloc[i][j];
    }
  }
  int y = 0;
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      if (f[i] == 0) {
        int flag = 0;
        for (j = 0; j < r; j++) {
          if (need[i][j] > avail[j]) {
            flag = 1;
            break;
          }
        }
        if (flag == 0) {
          ans[ind++] = i;
          for (y = 0; y < r; y++) {
            avail[y] = avail[y] + alloc[i][y];
            f[i] = 1;
          }
        }
      }
    }
  }
  printf("The safe sequence is:");
  for (i = 0; i < n - 1; i++)
    printf("P%d->", ans[i]);
  printf("P%d", ans[n - 1]);
  return 0;
}

/*
output:
The safe sequence is:P0->P2->P3->P4->P1
*/