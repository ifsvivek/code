//Calculation of simple interest : ptr/100
#include <stdio.h>

int main() {
    float p,t,r;
    printf("Enter P, T and R: ");
    scanf("%f%f%f", &p, &t,&r);
    printf("SI= %0.2f\n", (p*t*r)/100 );
    return 0;
}