
void readString(char *str, const char *message) {
    printf("Enter %s: ", message);
    scanf("%s", str);
}

int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int findPattern(char *str, const char *pattern, int *start) {
    int i, j, k;
    int strLen = stringLength(str);
    int patLen = stringLength(pattern);

    for (i = 0; i <= strLen - patLen; i++) {
        k = i;
        for (j = 0; j < patLen && str[k] == pattern[j]; j++, k++);
        if (j == patLen) {
            *start = i;
            return 1;
        }
    }
    return 0;
}

void replacePattern(char *str, const char *pattern, const char *replaceStr) {
    int start = 0;
    while (findPattern(str, pattern, &start)) {

        int i, j;
        int patLen = stringLength(pattern);
        int replaceLen = stringLength(replaceStr);
        int strLen = stringLength(str);
        for (i = strLen + replaceLen - 1, j = strLen - 1; j >= start + patLen; i--, j--) {
            str[i] = str[j];
        }

        for (i = start, j = 0; j < replaceLen; i++, j++) {
            str[i] = replaceStr[j];
        }
    }
}
int main() {
    char mainStr[100], pattern[50], replaceStr[50];

    readString(mainStr, "main string");
    readString(pattern, "pattern");
    readString(replaceStr, "replace string");

    int start = 0;
    if (findPattern(mainStr, pattern, &start)) {
        replacePattern(mainStr, pattern, replaceStr);
        printf("Pattern found and replaced:\n%s\n", mainStr);
    } else {
        printf("Pattern not found in the main string.\n");
    }

    return 0;
}
