//Area and perimeter [2*(l+b)] of a rectangle
#include <stdio.h>

int main() {
    float l,b;
    printf("Enter L and B: ");
    scanf("%f %f", &l, &b);
    printf("Area: %0.2f\n", l*b );
    printf("Perimeter: %0.2f", 2*(l+b) );
    return 0;
}