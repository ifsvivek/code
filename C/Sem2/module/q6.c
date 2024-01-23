// Implement Matrix multiplication and validate the rules of multiplication

#include <stdio.h>

#define MAX_SIZE 10

void mul(int m1[][MAX_SIZE], int r1, int c1, int m2[][MAX_SIZE], int r2, int c2, int res[][MAX_SIZE]){
    if (c1 != r2){
        printf("Error: Invalid matrix dimensions for multiplication.\n");
        return;
    }
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c2; j++){
            res[i][j] = 0;
            for (int k = 0; k < c1; k++){
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void display(int matrix[][MAX_SIZE], int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int m1[MAX_SIZE][MAX_SIZE], r1, c1;
    printf("Enter the number of rows and col for matrix 1: ");
    scanf("%d%d", &r1,&c1);
    printf("Enter the elements of matrix 1:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &m1[i][j]);

    int m2[MAX_SIZE][MAX_SIZE], r2, c2;
    printf("Enter the number of rows and col for matrix 2: ");
    scanf("%d%d", &r2,&c2);
    printf("Enter the elements of matrix 2:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &m2[i][j]);

    int res[MAX_SIZE][MAX_SIZE];
    mul(m1, r1, c1, m2, r2, c2, res);

    printf("\nMatrix 1:\n");
    display(m1, r1, c1);
    printf("Matrix 2:\n");
    display(m2, r2, c2);
    printf("Resultant Matrix:\n");
    display(res, r1, c2);

    return 0;
}