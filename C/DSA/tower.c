#include <stdio.h>

void tower(int n, char source, char temp, char dest) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }

    tower(n - 1, source, dest, temp);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    tower(n - 1, temp, source, dest);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Number of disks should be at least 1.\n");
        return 1; // Error exit code
    }

    printf("Tower of Hanoi solution for %d disks:\n", n);
    tower(n, 'A', 'B', 'C');

    return 0;
}
