#include <stdio.h>

int main() {
    float time = 2.3;
    int hour = 0;
    while (time >= 1) {
        time--;
        hour++;
    }
    printf("%d:%.0f\n", hour, time * 60);
    return 0;
}