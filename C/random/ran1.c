#include <stdio.h>
#include <string.h>
#include<ctype.h>

void replaceConstants(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            if (str[i] == 'a' || str[i] == 'A' || str[i] == 'z' || str[i] == 'Z')
                continue;

            str[i] = str[i] + 1;
            if (str[i] == 'z' + 1 || str[i] == 'Z' + 1)
                str[i] = str[i] + 1;
        }
    }
}

int main() {
    char str[] = "programming in C is fun";
    replaceConstants(str);
    printf("%s\n", str);
    return 0;
}