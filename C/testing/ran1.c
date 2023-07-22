#include<stdio.h>
int main (){
    float time=2.3;
    int hour;
    while (time>=1)
    {
        time--;
        hour++;/* code */
    }
    printf("%d:%0.1f",hour,time);
}