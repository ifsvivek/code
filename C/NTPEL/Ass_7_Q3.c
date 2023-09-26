/*
Write a C program to find subtraction of two matrices i.e. matrix_A - matrix_B=matrix_C.
*/

#include <stdio.h>
int main()
{
    int matrix_A[20][20], matrix_B[20][20], matrix_C[20][20];
    int i,j,row,col;
    scanf("%d",&row); //Accepts number of rows
    scanf("%d",&col); //Accepts number of columns 
 
    /* Elements of first matrix are accepted from test data */
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            scanf("%d", &matrix_A[i][j]);
        }
    }

     /* Elements of second matrix are accepted from test data */
    
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            scanf("%d", &matrix_B[i][j]);
        }
    }

/* Complete the program to get the desired output. Use printf() statement as below
    printf("%d ", matrix_C[i][j]); You can declare your own variables if required. 
*/
/* 
    Subtract both matrices and store the result in matrix C
  */
   for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
    
            matrix_C[i][j] = matrix_A[i][j] - matrix_B[i][j];
        }
    }

     for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%d ", matrix_C[i][j]);
        }
        printf("\n");
    }

    return 0;
}