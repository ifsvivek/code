// Simulate the following CPU scheduling algorithms to find turnaround time and
// waiting time b) SJF

#include <stdio.h>

void main() {
  int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
  float wtavg, tatavg;

  printf("\nEnter the number of processes -- ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    p[i] = i;
    printf("Enter Burst Time for Process %d : ", i);
    scanf("%d", &bt[i]);
  }
  for (i = 0; i < n - 1; i++) {
    for (k = 0; k < n - i - 1; k++) {
      if (bt[k] > bt[k + 1]) {
        temp = bt[k];
        bt[k] = bt[k + 1];
        bt[k + 1] = temp;

        temp = p[k];
        p[k] = p[k + 1];
        p[k + 1] = temp;
      }
    }
  }

  wt[0] = 0;
  tat[0] = wt[0] + bt[0];
  wtavg = wt[0];
  tatavg = tat[0];

  for (i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1];
    tat[i] = wt[i] + bt[i];
    wtavg += wt[i];
    tatavg += tat[i];
  }
  printf("\n\t PROCESS  \t BURST TIME \t WAITING TIME \t TURNAROUND TIME\n");

  for (i = 0; i < n; i++)
    printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);
  printf("\nAverage Waiting Time -- %f", wtavg / n);
  printf("\nAverage Turnaround Time -- %f", tatavg / n);
}

/*
output:

Enter the number of processes -- 5
Enter Burst Time for Process 0 : 1
Enter Burst Time for Process 1 : 2
Enter Burst Time for Process 2 : 4
Enter Burst Time for Process 3 : 5
Enter Burst Time for Process 4 : 6

 PROCESS         BURST TIME      WAITING TIME    TURNAROUND TIME

P0              1               0               1
P1              2               1               3
P2              4               3               7
P3              5               7               12
P4              6               12              18
Average Waiting Time -- 4.600000
Average Turnaround Time -- 8.200000

*/