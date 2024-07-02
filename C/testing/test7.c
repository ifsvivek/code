// apparently we dont need to use flower brackets in the for loop 
// but it is a good practice to use them
// the code below is a good example of how to use for loop without flower brackets

// >~<

#include<stdio.h>

void main() {
    int n, a[10][10];
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    printf("Enter the elements of the matrix: ");
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            scanf("%d", &a[i][j]);


    printf("The matrix is: \n");
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            printf("%d ", a[i][j]);
    printf("\n");

}