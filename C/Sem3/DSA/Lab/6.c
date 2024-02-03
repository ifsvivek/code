#include <stdio.h>
#include <stdlib.h>
#define MAX 5

char q[MAX];
int rear = -1, front = 0, count = 0;

void Enqueue() {
  char ele;
  if (count == MAX)
    printf("Queue overflow\n");
  else {
    printf("Enter the element to be inserted: ");
    scanf(" %c", &ele);
    rear = (rear + 1) % MAX;
    q[rear] = ele;
    count++;
  }
}

void Dequeue() {
  if (count == 0)
    printf("Queue underflow\n");
  else {
    printf("Deleted item is %c\n", q[front]);
    front = (front + 1) % MAX;
    count--;
  }
}

void Display() {
  int i, j;
  if (count == 0)
    printf("Queue is Empty\n");
  else {
    i = front;
    for (j = 0; j < count; j++) {
      printf("%c ", q[i]);
      i = (i + 1) % MAX;
    }
    printf("\n");
  }
}

int main() {
  int choice;
  while (1) {
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        Enqueue();
        break;
      case 2:
        Dequeue();
        break;
      case 3:
        Display();
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid Input\n");
        break;
    }
  }
  return 0;
}