#include <stdio.h>

int main() {
  int time, bt[10], at[10], sbt = 0, smallest, n, i;
  float sum_tat = 0, sum_wt = 0;

  printf("Enter the no. of processes: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("The AT of Process P%d: ", i + 1);
    scanf("%d", &at[i]);
    printf("The BT of Process P%d: ", i + 1);
    scanf("%d", &bt[i]);
    sbt += bt[i];
  }

  for (time = 0; time < sbt;) {
    smallest = 9;
    for (i = 0; i < n; i++) {
      if (at[i] <= time && bt[i] > 0 && bt[i] < bt[smallest]) {
        smallest = i;
      }
    }

    printf("P[%d]\t|\t%d\t|\t%d\n", smallest + 1, time + bt[smallest] - at[smallest], time - at[smallest]);
    sum_tat += time + bt[smallest] - at[smallest];
    sum_wt += time - at[smallest];
    time += bt[smallest];
    bt[smallest] = 0;
  }

  printf("\n\nAWT = %f\n", sum_wt * 1.0 / n);
  printf("\n\nATAT = %f\n", sum_tat * 1.0 / n);

  return 0;
}
