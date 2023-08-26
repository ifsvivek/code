/*
Write a C program to print Largest and Smallest Word from a given sentence.
If there are two or more words of same length then the first one is considered.
*/

#include<stdio.h>
#include<string.h>
int main()
{
    char str[100]={0},substr[100][100]={0};  
    scanf("%[^\n]s", str); 
    int i=0,j=0,k=0,a,minIndex=0,maxIndex=0,max=0,min=0;
    while(str[k]!='\0'){
        j=0;
        while(str[k]!=' '&&str[k]!='\0')
        {
            substr[i][j]=str[k];
            k++;
            j++;
        }
        substr[i][j]='\0';
        i++;
        if(str[k]!='\0')
        {
            k++;
        }        
    }
    int len=i;
    max=strlen(substr[0]);
    min=strlen(substr[0]);
    for(i=0;i<len;i++)
    {
       a=strlen(substr[i]);
       if(a>max)
        {
            max=a;
            maxIndex=i;
        }
        if(a<min)
        {
            min=a;
            minIndex=i;
        }
    }    
    printf("Largest Word is: %s\nSmallest word is: %s\n",substr[maxIndex],substr[minIndex]);
    return 0; 
}