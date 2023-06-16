//To check a number is odd or even
#include <stdio.h>

int main() {
    int a;
    printf("Enter the Number: ");
    scanf("%d",&a);

    if(a%2==0){
        printf("%d is Even",a);
    }
    else{
        printf("%d is Odd",a);
    }
    return 0;
}