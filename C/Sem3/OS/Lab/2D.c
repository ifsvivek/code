// Simulate the following CPU scheduling algorithms to find turnaround time and
// waiting time d) Priority.

#include <stdio.h>

void main() {
  int p[20], bt[20], pri[20], wt[20], tat[20], i, k, n, temp;
  float wtavg, tatavg;

  printf("Enter the number of processes ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    p[i] = i;
    printf("Enter the Burst Time & Priority of Process %d ", i);
    scanf("%d %d", &bt[i], &pri[i]);
  }

  for (i = 0; i < n; i++) {
    for (k = i + 1; k < n; k++) {
      if (pri[i] > pri[k]) {
        temp = p[i];
        p[i] = p[k];
        p[k] = temp;
        temp = bt[i];
        bt[i] = bt[k];
        bt[k] = temp;
        temp = pri[i];
        pri[i] = pri[k];
        pri[k] = temp;
      }
    }
  }

  wtavg = wt[0] = 0;
  tatavg = tat[0] = bt[0];

  for (i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1];
    tat[i] = tat[i - 1] + bt[i];
    wtavg = wtavg + wt[i];
    tatavg = tatavg + tat[i];
  }

  printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
  for (i = 0; i < n; i++)
    printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ", p[i], pri[i], bt[i], wt[i],
           tat[i]);
  printf("\nAverage Waiting Time is --- %f", wtavg / n);
  printf("\nAverage Turnaround Time is %f", tatavg / n);
}

/*
output:
Enter the number of processes 5
Enter the Burst Time & Priority of Process 0 5 2
Enter the Burst Time & Priority of Process 1 7 3
Enter the Burst Time & Priority of Process 2 4 1
Enter the Burst Time & Priority of Process 3 5 7
Enter the Burst Time & Priority of Process 4 3 0

PROCESS         PRIORITY        BURST TIME      WAITING TIME    TURNAROUND TIME
4                0               3               0               3
2                1               4               3               7
0                2               5               7               12
1                3               7               12              19
3                7               5               19              24
Average Waiting Time is --- 8.200000
Average Turnaround Time is 13.000000
*/