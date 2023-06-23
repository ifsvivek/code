//area and perimeter of circle
#include<stdio.h>
int main(){
    int rad;
    printf("Enter the radius of circle: ");
    scanf("%d",&rad);
    printf("Area = %f", 3.14*rad*rad);
    printf("\nPerimeter = %f", 2*3.14*rad);
}