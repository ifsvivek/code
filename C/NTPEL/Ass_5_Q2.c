/*
Write a C program to count total number of digits of an Integer number (N).
*/

#include <stdio.h>
 int main()
{
    int N; 
    scanf("%d",&N);
    
    int count=0;
    for(int i=N; i>0;i=i/10){
        count++;
    }
    printf("The number %d contains %d digits.",N,count);
    return 0;
}
