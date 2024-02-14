// dfs and bfs

#include <stdio.h>
int a[10][10], n, visited[10];
void dfs(int s) {
  int i;
  visited[s] = 1;
  printf("%d ", s);
  for (i = 1; i <= n; i++) {
    if (a[s][i] == 1 && visited[i] == 0) {
      dfs(i);
    }
  }
}

void bfs(int s) {
  int i, f = 0, r = -1, q[n];
  visited[s] = 1;
  while (1) {
    printf("%d->", s);
    for (i = 1; i <= n; i++) {
      if (a[s][i] == 1 && visited[i] == 0) {
        q[++r] = i;
        visited[i] = 1;
      }
    }
    if (f > r)
      return;
    s = q[f++];
  }
}

void main() {
  int i, j, s;
  printf("Enter the no of nodes\n");
  scanf("%d", &n);
  printf("Enter the adjacency matrix\n");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  printf("Enter the source node\n");
  scanf("%d", &s);
  printf("DFS\n");
  dfs(s);
  printf("\nBFS\n");
  bfs(s);
}

/*
output:
Enter the no of nodes
5
Enter the adjacency matrix
0 1 0 0 0
1 0 1 1 0
0 1 0 0 1
0 1 0 0 1
0 0 1 1 0
Enter the source node
1
DFS
1 2 3 4 5
BFS
1->2->3->4->5->


*/