// Write a C Program to reverse a given word using function. 
// e.g. INDIA should be printed as  AIDNI 

#include<stdio.h>
#include<string.h>

void reverse(char[], int, int);
    int main()
    {
        char str1[20];
        scanf("%s", str1); //The string is taken as input form the test data. 
     
/* Complete the program to print the string in reverse order using the function
void reverse(char[], int, int);
Use the printf statement as
printf("The string after reversing is: %s\n", str1); 
You can use different variable also.
*/
int size;
	size = strlen(str1);
        reverse(str1, 0, size - 1);
        printf("The string after reversing is: %s", str1);  
        return 0;
    }

    void reverse(char str1[], int index, int size)
    {
        char temp;
        temp = str1[index];
        str1[index] = str1[size - index];
        str1[size - index] = temp;
        if (index == size / 2)
        {
            return;
        }
        reverse(str1, index + 1, size);
    }