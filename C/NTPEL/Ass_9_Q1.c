/*
Write a program to print all the locations at which a particular element(taken as input) is found in a list and also print the total number of times it occurs in the list. The location starts from 1.

For example if there are 4 elements in the array
5
6
5
7
*/

#include <stdio.h>
int main()
{
   int array[100], search, n, count = 0;
   //"search" is the key element to search and 'n' is the total number of element of the array
   // "count" is to store total number of elements

 scanf("%d", &n); //Number of elements is taken from test case

 int c;
   for (c = 0; c < n; c++)
      scanf("%d", &array[c]);

   scanf("%d", &search); // The element to search is taken from test case


    for(int i=0;i<n;i++){
      if(array[i] == search){
        printf("%d is present at location %d.\n",search,i+1);
        count++;
      }
    }
    if(count ==0){
      printf("%d is not present in the array.\n",search);
    }
    if(count > 0){
      printf("%d is present %d times in the array.\n",search,count);
    }
    return 0;
}