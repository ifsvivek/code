#include <stdio.h>
#include <stdlib.h>

struct sll {
  int sem;
  char usn[11], name[20], branch[20], phone[11];
  struct sll* next;
};
typedef struct sll node;
node* start = NULL;

node* getnode() {
  node* newNode;
  newNode = (node*)malloc(sizeof(node));
  printf("Enter the student details USN, name, branch, sem, phone: ");
  scanf("%s %s %s %d %s", newNode->usn, newNode->name, newNode->branch,&newNode->sem, newNode->phone);
  newNode->next = NULL;
  return newNode;
}

void insertBegin() {
  node* newNode = getnode();

  if (start == NULL)
    start = newNode;
  else {
    newNode->next = start;
    start = newNode;
  }
}

void insertEnd() {
  node* newNode = getnode();
  node* temp = start;

  if (start == NULL)
    start = newNode;
  else {
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = newNode;
  }
}

void deleteBegin() {
  node* temp = start;

  if (start == NULL)
    printf("Linked list is empty.\n");
  else {
    printf("Deleted node: USN: %s\n", temp->usn);
    start = temp->next;
    free(temp);
  }
}

void deleteEnd() {
  node *temp = start, *prev;

  if (start == NULL)
    printf("List is empty.\n");
  if (start->next == NULL) {
    printf("Deleted node is %s\n", temp->usn);
    start = NULL;
    free(temp);
  } else {
    while (temp->next != NULL) {
      prev = temp;
      temp = temp->next;
    }
    prev->next = NULL;
    printf("Deleted node is %s\n", temp->usn);
    free(temp);
  }
}

void display() {
  node* temp = start;
  int count = 0;

  if (start == NULL)
    printf("List is empty.\n");
  else {
    printf("List elements are:\n");
    while (temp != NULL) {
      printf("%s\n", temp->usn);
      temp = temp->next;
      count++;
    }
    printf("Count = %d\n", count);
  }
}

void main() {
  int choice, n, i;

  while (1) {
    printf("1.  InsertBegin\n2.  InsertEnd\n3.  DeleteBegin\n4.  DeleteEnd\n5. Display\n6.  Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the no. students: ");
        scanf("%d", &n);
        for (i = 0; i < n; i++)
          insertBegin();
        break;
      case 2:insertEnd();break;
      case 3:deleteBegin();break;
      case 4:deleteEnd();break;
      case 5:display();break;
      case 6:exit(0);
      default:printf("Invalid choice.\n");
    }
  }
}