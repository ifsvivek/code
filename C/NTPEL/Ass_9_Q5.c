/*
Write a C program to marge two given sorted arrays (sorted in ascending order).
The code for input and output is already written. You have to write the merge function so that the merged array is displayed in ascending order.
*/

#include <stdio.h>
void merge(int a[], int m, int b[], int n, int sorted[]);
int main() 
{
int a[100], b[100], m, n, c, sorted[200];

scanf("%d", &m); //Number of elements in the first array

  for (c = 0; c < m; c++) {
    scanf("%d", &a[c]); //Elements of first array is read
    }
    scanf("%d", &n); //Number of elements in second array

  for (c = 0; c < n; c++) {
    scanf("%d", &b[c]); //Elements of second array is read
  }

    merge(a, m, b, n, sorted); 
  printf("Sorted array:\n");

  for (c = 0; c < m + n; c++) {
    printf("%d\n", sorted[c]);
  }

  return 0;
}

void merge(int a[],int m,int b[],int n,int sorted[]){
 int i, j, k;
 
  j = k = 0;
 
  for (i = 0; i < m + n;) {
    if (j < m && k < n) {
      if (a[j] < b[k]) {
        sorted[i] = a[j];
        j++;
      }
      else {
        sorted[i] = b[k];
        k++;
      }
      i++;
    }
    else if (j == m) {
      for (; i < m + n;) {
        sorted[i] = b[k];
        k++;
        i++;
      }
    }
    else {
      for (; i < m + n;) {
        sorted[i] = a[j];
        j++;
        i++;
      }
    }
  }
}