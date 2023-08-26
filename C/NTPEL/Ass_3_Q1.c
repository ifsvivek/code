/*
Write a C Program to calculates the area (floating point number with two decimal places) of a Circle given it’s radius (integer value).  The value of Pi is 3.14.
[Marks for Week 3 Programming assignments will not be evaluated finally. This is for users to get familiar with programming in google course builder platform] 
*/

#include <stdio.h>
#define PI 3.14
int main()
{
    int radius;
    float area;
   
    scanf("%d", &radius);

    area = PI * radius * radius;
    printf("Area of a circle = %5.2f\n", area);
    return 0;
}
