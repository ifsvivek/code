#include<stdio.h>
#include <stdlib.h>

struct Dlist {
    int data;
    struct Dlist* next;
    struct Dlist* prev;
};
typedef struct Dlist node;
node *start= NULL;

node* getnode(){
    node *newnode= (node*)malloc(sizeof(node));
    printf("Enter Data");
    scanf("%d",newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void insertBegin() {
    node* newNode,*temp=start;
    if (start == NULL)
        start = newNode;
    else {
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }
}