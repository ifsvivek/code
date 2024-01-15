#include <stdio.h>

int main()
{
    char str[100], pat[100], rep[100], ans[100];

    printf("Enter the original string \n");
    fgets(str, sizeof(str), stdin);
    printf("Enter the pattern string \n");
    fgets(pat, sizeof(str), stdin);
    printf("Enter the replacement string \n");
    fgets(rep, sizeof(str), stdin);

    int i, j, c, m, k;
    i, c, m, j = 0;
    while (str[c] != '\0')
    {
        if (str[m] == pat[i])
        {
            i++;
            m++;
        }
        if (pat[i] == '\0')
        {
            for (k = 0; rep[k] != '\0'; k++, j++)
            {
                ans[j] = rep[k];
            }
            i++;
            c = m;
        }

        else
        {
            ans[j] = str[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }

    ans[j] = '\0';
    printf("ANSWER: %s", ans);
}
