#include<stdio.h>
int main(){
    int cash=233;
    if (cash/100)>=1{
        printf("100x%d",cash%100);
        }
    else if (cash/50)>=1{
        printf("\n50x%d",cash%50);
    }
    else (cash/10)>=1{
        printf("\n10x%",cash%50);
    }
    printf("\n1x%d",cash%50);
}