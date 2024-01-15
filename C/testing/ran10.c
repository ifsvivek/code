#include <stdio.h>
#include <string.h>

int main() {
    char str[100], pat[100], rep[100], ans[100];

    printf("Enter the original string \n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    
    printf("Enter the pattern string \n");
    fgets(pat, sizeof(pat), stdin);
    pat[strcspn(pat, "\n")] = '\0';

    printf("Enter the replacement string \n");
    fgets(rep, sizeof(rep), stdin);
    rep[strcspn(rep, "\n")] = '\0';

    int i, j, c, m, k;

    i = c = m = j = 0;

    while (str[c] != '\0') {
        if (str[c] == pat[i]) {
            i++;
            c++;
        } else {
            if (i > 0) {
                c = m + i;
                i = 0;
            } else {
                ans[j++] = str[m++];
                c = m;
            }
        }

        if (pat[i] == '\0') {
            for (k = 0; rep[k] != '\0'; k++, j++) {
                ans[j] = rep[k];
            }
            i = 0;
            m = c;
        }
    }

    ans[j] = '\0';
    printf("ANSWER: %s", ans);
}
