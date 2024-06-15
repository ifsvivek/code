#include <stdio.h>

int main() {
    long long x = 0x79756F6C6C6548LL;

    while (x) {
        putchar(32 + ((0x3E6E69080A0201LL >> ((x & 15) * 4)) & 0x7F));
        x >>= 1;
    }

    return 0;
}