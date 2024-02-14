// Simulate the following CPU scheduling algorithms to find turnaround time and
// waiting time a) FCFS

#include <stdio.h>
void main() {
  int p[10], at[10], bt[10], ct[10], tat[10], wt[10];
  int i, j, temp = 0, n;
  float awt = 0, atat = 0;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  printf("Enter pid of processes: ");
  for (i = 0; i < n; i++)
    scanf("%d", &p[i]);
  printf("\nEnter %d arrival time: ", n);
  for (i = 0; i < n; i++)
    scanf("%d", &at[i]);
  printf("\nEnter %d burst time: ", n);
  for (i = 0; i < n; i++)
    scanf("%d", &bt[i]);
  ct[0] = at[0] + bt[0];
  for (i = 0; i < n; i++) {
    temp = 0;
    if (ct[i - 1] < at[i])
      temp = at[i] - ct[i - 1];
    ct[i] = ct[i - 1] + bt[i] + temp;
  }
  printf("\n P\tAT\tBT\tCT\tTAT\tWT\t");
  for (i = 0; i < n; i++) {
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    atat += tat[i];
    awt += wt[i];
  }
  atat = atat / n;
  awt = awt / n;
  for (i = 0; i < n; i++)
    printf("\n%d\t %d\t %d\t %d\t %d\t %d\t ", p[i], at[i], bt[i], ct[i],
           tat[i], wt[i]);
  printf("\n ATAT=%f", atat);
  printf("\n AWT=%f", awt);
}

/*
output:
Enter the number of processes: 5
Enter pid of processes: 1 2 3 4 5
Enter 5 arrival time: 1 2 3 4 5

Enter 5 burst time: 4 5 6 7 8

P      AT      BT      CT      TAT     WT
1        1       4       5       4       0
2        2       5       10      8       3
3        3       6       16      13      7
4        4       7       23      19      12
5        5       8       31      26      18

ATAT=14.000000
AWT=8.000000
*/