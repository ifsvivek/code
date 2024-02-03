#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to display the value of the last but one node in CSLL
void display(Node* head) {
  if (head == NULL || head->next == NULL) {
    printf("List is empty.\n");
    return;
  }
  Node* current = head;
  while (current->next->next != head) current = current->next;
  printf("Value of the last but one node: %d\n", current->data);
}

void main() {
  Node* head = createNode(1);
  head->next = createNode(2);
  head->next->next = createNode(3);
  head->next->next->next = head;

  display(head);
}