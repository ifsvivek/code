/*
Write a C program to print the following Pyramid pattern upto Nth row. Where N (number of rows to be printed) is taken as input.

*****
****
***
**
*


*/

#include<stdio.h>
int main()
{
    int N;
    scanf("%d", &N);

	for(int i=N;i>0;i--){
      for(int j=i;j>0;j--){
        printf("*");
      }
      printf("\n");
	}
	return 0;
}