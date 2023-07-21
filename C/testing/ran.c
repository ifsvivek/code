#include<stdio.h>
int main() {
    int cash = 233;

    if (cash / 100 >= 1) {
        printf("100x%d", cash / 100);
        cash %= 100;
    }
    else if (cash / 50 >= 1) {
        printf("\n50x%d", cash / 50);
        cash %= 50;
    }
    else if (cash / 10 >= 1) {
        printf("\n10x%d", cash / 10);
        cash %= 10;
    }
    printf("\n1x%d", cash);
}
