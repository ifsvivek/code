#include <stdio.h>
#define MAX 25
void main() {
  int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp, highest = 0;
  static int bf[MAX], ff[MAX];
  printf("\n\tMemory Management Scheme - Worst Fit");
  printf("\nEnter the number of blocks:");
  scanf("%d", &nb);
  printf("Enter the number of files:");
  scanf("%d", &nf);
  printf("\nEnter the size of the blocks:-\n");
  for (i = 1; i <= nb; i++) {
    printf("Block %d:", i);
    scanf("%d", &b[i]);
  }
  printf("Enter the size of the files :-\n");
  for (i = 1; i <= nf; i++) {
    printf("File %d:", i);
    scanf("%d", &f[i]);
  }
  for (i = 1; i <= nf; i++) {
    for (j = 1; j <= nb; j++) {
      if (bf[j] != 1)  // if bf[j] is not allocated
      {
        temp = b[j] - f[i];
        if (temp >= 0)
          if (highest < temp) {
            ff[i] = j;
            highest = temp;
          }
      }
    }
    frag[i] = highest;
    bf[ff[i]] = 1;
    highest = 0;
  }
  printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragments");
  for (i = 1; i <= nf; i++)
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
}

/*
output:

Memory Management Scheme - Worst Fit
Enter the number of blocks:5
Enter the number of files:3

Enter the size of the blocks:-
Block 1:20
Block 2:40
Block 3:60
Block 4:80
Block 5:100
Enter the size of the files :-
File 1:10
File 2:30
File 3:50

File_no:        File_size :     Block_no:       Block_size:     Fragments
1               10              5               100             90
2               30              4               80              50
3               50              3               60              10

*/