/*7. Develop a C program to simulate page replacement algorithms:
a) FIFO
*/
#include <stdio.h>
int main() {
    int i, j, n, a[50], frame[10], no, k, avail, count = 0;
    printf("\nENTER THE NUMBER OF PAGES: ");
    scanf("%d", &n);
    printf("\nENTER THE PAGE NUMBER : ");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("\nENTER THE NUMBER OF FRAMES: ");
    scanf("%d", &no);
    for (i = 0; i < no; i++)
        frame[i] = -1;
    j = 0;
    printf("\tref string\t page frames\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t\t", a[i]);
        avail = 0;
        for (k = 0; k < no; k++)
            if (frame[k] == a[i])
                avail = 1;
        if (avail == 0) {
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;
            for (k = 0; k < no; k++)
                printf("%d\t", frame[k]);
        }
        printf("\n");
    }
    printf("Page Fault Is %d", count);
    return 0;
}

/*
output:
ENTER THE NUMBER OF PAGES: 20

ENTER THE PAGE NUMBER : 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

ENTER THE NUMBER OF FRAMES: 3
        ref string       page frames
7               7       -1      -1
0               7       0       -1
1               7       0       1
2               2       0       1
0
3               2       3       1
0               2       3       0
4               4       3       0
2               4       2       0
3               4       2       3
0               0       2       3
3
2
1               0       1       3
2               0       1       2
0
1
7               7       1       2
0               7       0       2
1               7       0       1
Page Fault Is 15
*/