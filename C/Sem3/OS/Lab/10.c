// 10) Develop a C program to simulate SCAN disk scheduling algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 10
#define disk_size 200
int comp(const void* l, const void* n) {
  return (*(int*)l - *(int*)n);
}
void SCAN(int arr[], int head, char* dn) {
  int seek_num = 0;
  int dt, cur_track;
  int leftside[size], rightside[size];
  int seek_seq[size + 3];
  int m_scan = 0, s_scan = 0;
  if (strcmp(dn, "leftside") == 0)
    leftside[m_scan++] = 0;
  else if (strcmp(dn, "rightside") == 0)
    rightside[s_scan++] = disk_size - 1;
  for (int p_s = 0; p_s < size; p_s++) {
    if (arr[p_s] < head)
      leftside[m_scan++] = arr[p_s];
    if (arr[p_s] > head)
      rightside[s_scan++] = arr[p_s];
  }
  qsort(leftside, m_scan, sizeof(int), comp);
  qsort(rightside, s_scan, sizeof(int), comp);
  int go = 2;
  int ind = 0;
  while (go--) {
    if (strcmp(dn, "leftside") == 0) {
      for (int p_s = m_scan - 1; p_s >= 0; p_s--) {
        cur_track = leftside[p_s];
        seek_seq[ind++] = cur_track;
        dt = abs(cur_track - head);
        seek_num += dt;
        head = cur_track;
      }
      dn = "rightside";
    } else if (strcmp(dn, "rightside") == 0) {
      for (int p_s = 0; p_s < s_scan; p_s++) {
        cur_track = rightside[p_s];
        seek_seq[ind++] = cur_track;
        dt = abs(cur_track - head);
        seek_num += dt;
        head = cur_track;
      }
      dn = "leftside";
    }
  }
  printf("Num of seek process = %d\n", seek_num);
  printf("Sequence is\n");
  for (int p_s = 0; p_s < ind; p_s++) {
    printf("%d\n", seek_seq[p_s]);
  }
}
int main() {
  int arr[size] = {126, 90, 14, 50, 25, 42, 51, 78, 102, 100};
  int head = 42;
  char dn[] = "leftside";
  SCAN(arr, head, dn);
  return 0;
}