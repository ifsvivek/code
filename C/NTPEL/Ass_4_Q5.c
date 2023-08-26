/*
Write a program to find whether a given character is a Vowel or consonant. 
A character is taken as input. 
The character may be in Upper Case or in Lower Case.  
*/


#include <stdio.h>
int main()
{
    char ch;
    scanf("%c",&ch);  

    int Lower_case, Upper_case;
    Lower_case = (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    Upper_case = (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');

    if (Lower_case|| Upper_case)
        printf("%c is a vowel.", ch);
    else
        printf("%c is a consonant.", ch);
    return 0;
}
