#include<stdio.h>
int main(){
    int a, b;
    printf("Enter 2 numbers: ");
    scanf("%d%d",&a,&b);
    printf("%d is greater", (a>b) ? a:b);
    return 0;
}