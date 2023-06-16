//Greatest of 2 numbers
#include <stdio.h>

int main() {
    int a,b;
    printf("Enter Two Number: ");
    scanf("%d%d",&a,&b);
    if(a>b){
        printf("%d is Greater",a);
    }
    else{
        printf("%d is Greater",b);
    }
    return 0;
}