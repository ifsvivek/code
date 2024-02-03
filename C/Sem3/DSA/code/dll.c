#include <stdio.h>
#include <stdlib.h>

struct Dlist {
  int data;
  struct Dlist *next;
  struct Dlist *prev;
};
typedef struct Dlist node;
node *start = NULL;

node *getNode() {
  node *newNode = (node *)malloc(sizeof(node));
  printf("Enter Data: ");
  scanf("%d", &(newNode->data));
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void insertBegin() {
  node *newNode = getNode(), *temp = start;
  if (start == NULL)
    start = newNode;
  else {
    newNode->next = start;
    start->prev = newNode;
    start = newNode;
  }
}

void insertEnd() {
  node *newNode = getNode(), *temp = start;
  if (start == NULL)
    start = newNode;
  else {
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
  }
}

void deleteBegin() {
  if (start == NULL)
    printf("List is empty\n");
  else {
    node *temp = start;
    start = start->next;
    printf("Deleted Node is %d\n", temp->data);
    if (start != NULL) start->prev = NULL;
    free(temp);
  }
}

void deleteEnd() {
  node *temp = start;
  if (start == NULL)
    printf("List is empty\n");
  else if (start->next == NULL) {
    printf("Deleted Node is %d\n", temp->data);
    start->next = NULL;
  } else {
    while (temp->next != NULL) temp = temp->next;
    (temp->prev)->next = NULL;
    printf("Deleted Node is %d\n", temp->data);
    free(temp);
  }
}

void display() {
  node *temp = start;
  if (temp == NULL)
    printf("List is empty\n");
  else {
    while (temp != NULL) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

int countNodes() {
  node *temp = start;
  int count = 0;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

node *search() {
  node *temp = start;
  int key;
  printf("Enter the key: ");
  scanf("%d", &key);
  if (temp == NULL)
    printf("List is empty\n");
  else {
    while (temp->next != NULL && temp->data != key) temp = temp->next;
    if (temp == NULL)
      printf("Key not found\n");
    else
      printf("Key found\n");
    return temp;
  }
}

void reverse() {
  node *temp = NULL, *current = start;
  while (current != NULL) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  if (temp != NULL) start = temp->prev;
}

void insertAfter() {
  node *temp, *newNode;
  temp = search();
  if (temp == NULL)
    printf("List is empty\n");
  else if (temp->next == NULL)
    insertEnd();
  else {
    newNode = getNode();
    newNode->next = temp->next;
    (temp->next)->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
  }
}

void insertBefore() {
  node *temp, *newNode;
  temp = search();
  if (temp == NULL)
    printf("List is empty\n");
  else if (temp->next == NULL)
    insertBegin();
  else {
    newNode = getNode();
    newNode->next = temp->next;
    (temp->prev)->next = newNode;
    newNode->next = temp;
  }
}

void deleteKey() {
  node *temp;
  temp = search();
  if (temp == NULL)
    printf("List is empty\n");
  else {
    (temp->prev)->next = temp->next;
    (temp->next)->prev = temp->prev;
    printf("Deleted Key is %d", temp->data);
    free(temp);
  }
}

void main() {
  int choice;

  while (1) {
    printf("\n\n------ Doubly Linked List Menu ------\n");
    printf("1. Insert at the Beginning\n");
    printf("2. Insert at the End\n");
    printf("3. Delete from the Beginning\n");
    printf("4. Delete from the End\n");
    printf("5. Display the List\n");
    printf("6. Count Nodes\n");
    printf("7. Search\n");
    printf("8. Reverse the List\n");
    printf("9. Insert After a Node\n");
    printf("10. Insert Before a Node\n");
    printf("11. Delete a Node\n");
    printf("12. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        insertBegin();
        break;
      case 2:
        insertEnd();
        break;
      case 3:
        deleteBegin();
        break;
      case 4:
        deleteEnd();
        break;
      case 5:
        display();
        break;
      case 6:
        printf("Number of nodes: %d\n", countNodes());
        break;
      case 7:
        search();
        break;
      case 8:
        reverse();
        printf("List reversed successfully.\n");
        break;
      case 9:
        insertAfter();
        break;
      case 10:
        insertBefore();
        break;
      case 11:
        deleteKey();
        break;
      case 12:
        printf("Exiting the program.\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}