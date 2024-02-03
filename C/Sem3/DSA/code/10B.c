#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
} Node;

Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

// Function to display the sum of the first and last node values in DLL
void display(Node* head) {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  Node* current = head;
  while (current->next != NULL) current = current->next;
  printf("Sum of first and last node values: %d\n", head->data + current->data);
}

void main() {
  Node* head = createNode(1);
  head->next = createNode(2);
  head->next->prev = head;
  head->next->next = createNode(3);
  head->next->next->prev = head->next;

  display(head);
}