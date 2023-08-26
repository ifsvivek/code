// Write a C Program to reverse a given word using function. 
// e.g. INDIA should be printed as  AIDNI 

#include<stdio.h>
#include<string.h>

void reverse(char[], int, int);
int main()
{
    char str1[20];
    scanf("%s", str1); //The string is taken as input form the test data.
	reverse(str1, 0, strlen(str1)-1);
	printf("The string after reversing is: %s", str1); 
 
   return 0;
}
 
void reverse(char *x, int begin, int end)
{
   char c;
   if (begin >= end)
      return;
   c=*(x+begin);
   *(x+begin)= *(x+end);
   *(x+end)= c;
   reverse(x, ++begin, --end);
}