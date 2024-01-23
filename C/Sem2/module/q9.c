/*Write functions to implement string operations such as compare, concatenate, and find string length. Use the
parameter passing techniques.  */

#include <stdio.h>
#include <string.h>

int stringLength(const char *str)
{
    return strlen(str);
}

int stringCompare(const char *str1, const char *str2)
{
    return strcmp(str1, str2);
}

void stringConcatenate(const char *str1, const char *str2, char *result)
{
    strcpy(result, str1);
    strcat(result, str2);
}

int main()
{
    char str1[100], str2[100], result[200];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    int length1 = stringLength(str1);
    int length2 = stringLength(str2);
    int compareResult = stringCompare(str1, str2);

    printf("Length of first string: %d\n", length1);
    printf("Length of second string: %d\n", length2);

    if (compareResult < 0)
    {
        printf("The first string is lexicographically smaller than the second string.\n");
    }
    else if (compareResult > 0)
    {
        printf("The first string is lexicographically larger than the second string.\n");
    }
    else
    {
        printf("The first string is lexicographically equal to the second string.\n");
    }

    stringConcatenate(str1, str2, result);
    printf("Concatenated string: %s\n", result);

    return 0;
}