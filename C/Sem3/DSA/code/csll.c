#include <stdio.h>
#include <stdlib.h>

struct CSLL {
  int data;
  struct CSLL* next;
};

typedef struct CSLL node;
node* start = NULL;

node* getCSLL(int value) {
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

void insertEnd(int value) {
  node* newNode = getCSLL(value);

  if (start == NULL) {
    start = newNode;
    newNode->next = start;
  } else {
    node* temp = start;
    while (temp->next != start) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = start;
  }
}

void deleteBegin() {
  if (start == NULL) {
    printf("List is empty\n");
  } else {
    node* temp = start;
    while (temp->next != start) {
      temp = temp->next;
    }

    if (temp == start) {
      printf("Deleted Node is %d\n", temp->data);
      free(temp);
      start = NULL;
    } else {
      temp->next = start->next;
      printf("Deleted Node is %d\n", start->data);
      free(start);
      start = temp->next;
    }
  }
}

void deleteEnd() {
  if (start == NULL) {
    printf("List is empty\n");
  } else {
    node *temp = start, *prev = NULL;
    while (temp->next != start) {
      prev = temp;
      temp = temp->next;
    }

    if (temp == start) {
      printf("Deleted Node is %d\n", temp->data);
      free(temp);
      start = NULL;
    } else {
      prev->next = start;
      printf("Deleted Node is %d\n", temp->data);
      free(temp);
    }
  }
}

void display() {
  if (start == NULL) {
    printf("List is empty\n");
  } else {
    node* temp = start;
    do {
      printf("%d -> ", temp->data);
      temp = temp->next;
    } while (temp != start);
    printf("\n");
  }
}

int countNodes() {
  int count = 0;
  if (start != NULL) {
    node* temp = start;
    do {
      count++;
      temp = temp->next;
    } while (temp != start);
  }
  return count;
}

int main() {
  int choice, value;

  while (1) {
    printf("\n\n------ Circular Singly Linked List Menu ------\n");
    printf("1. Insert at the End\n");
    printf("2. Delete from the Beginning\n");
    printf("3. Delete from the End\n");
    printf("4. Display the List\n");
    printf("5. Count Nodes\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data: ");
        scanf("%d", &value);
        insertEnd(value);
        break;
      case 2:
        deleteBegin();
        break;
      case 3:
        deleteEnd();
        break;
      case 4:
        display();
        break;
      case 5:
        printf("Number of nodes: %d\n", countNodes());
        break;
      case 0:
        printf("Exiting the program.\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}