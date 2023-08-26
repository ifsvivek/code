/*
Write a C program to check whether the given number(N) can be expressed as Power of Two (2) or not.
For example 8 can be expressed as 2^3. 
*/

#include <stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    
	int count=0;
	for(int i=N;i>0;i=i/2){
      if(i%2==0){
        count++;
      }
    }
	int new=1;
	for(int i=1;i<=count;i++){
      new = new*2;
	}
	if(N == new)
      printf("%d is a number that can be expressed as power of 2.",N);
	else
      printf("%d cannot be expressed as power of 2.",N);
	return 0;
}