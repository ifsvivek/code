//Greatest of 3 numbers
#include <stdio.h>

int main() {
    int a,b,c;
    printf("Enter Two Number: ");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b && a>c){
        printf("%d is Greatest",a);
    }
    else if(b>c) {
        printf("%d is Greatest",b);
    }
    else{
        printf("%d is Greatest",c);
    }
    return 0;
}