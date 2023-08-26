#include <stdio.h>

int main() {
    int N, count = 0;
    scanf("%d", &N); /*The number is accepted from the test case data*/

    while (N != 0) {
        N /= 10;
        count++;
    }

    printf("The number %d contains %d digits.", N, count);

    return 0;
}
