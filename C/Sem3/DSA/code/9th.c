#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list* next;
};

typedef struct list node;
node* start = NULL;


node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


// Function to create the initial node list
node* createList() {
    node* start = createNode(5);
    start->next = createNode(10);
    start->next->next = createNode(20);
    return start;
}

// Function to insert a node after a given value
void insertAfter(node* temp, int data) {
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to print the linked list
void printList(node* start) {
    while (start != NULL) {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
}

int main() {
    node* start = createList();

    printf("Original list: ");
    printList(start);

    insertAfter(start->next, 15);  // Insert after 10

    printf("Modified list: ");
    printList(start);

    return 0;
}
