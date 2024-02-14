// Hash Table contents

#include <stdio.h>
#include <stdlib.h>
#define m 5
int a[m];

void display() {
  int i;
  printf("Hash Table contents\n");
  printf("Key\tValue\n");
  for (i = 0; i < m; i++) {
    printf("%d\t%d\n", i, a[i]);
  }
  printf("\n");
}

void linear_probing(int key, int index) {
    int i;
    if(a[index] ==1) {
        a[index] = key;
        return;
    }
    printf("Collision\n");
    i=index;
    do{
        i=(i+1)%m;
        if(a[i] == -1) {
            printf("It is Resolved by Linear Probing\n");
            a[i] = key;
            return;
        }
    }while (i!=index);
    printf("Hash Table is Full\n");
}

int main() {
    int i,key,index,input;
    for(i=0;i<m;i++)
    a[i] = -1;
    do{
        printf("Enter the key\n");
        scanf("%d",&key);
        index = key%m;
        linear_probing(key,index);
        display();
        printf("Enter 1 to continue\n");
        scanf("%d",&input);
    }while(input==1);
    return 0;
}



/*
output:
Enter the key
2
Collision
It is Resolved by Linear Probing
Hash Table contents
Key	Value
0	-1
1	-1
2	2
3	-1
4	-1

Enter 1 to continue
1
Enter the key
3
Collision
It is Resolved by Linear Probing
Hash Table contents
Key	Value
0	-1
1	-1
2	2
3	3
4	-1

Enter 1 to continue
0

*/