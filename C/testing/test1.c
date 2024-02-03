/*Consider the following 100 keys!

Perform separate chaining and list out the elements of each cell. Each element
should be separated by a space, and each list should end with NULL.

Use the hash function:
Hash(x) = x % 10

NOTE: Ordering is important and the elements are inserted at the start of the
linked list! Duplicates are allowed.

Keys List (in order of insertion separated by space):

7 21 144 51 105 146 108 184 57 44 96 29 151 123 106 147 118 204 62 49 103 42 153
131 108 152 120 25 90 6 118 44 157 167 111 153 141 28 13 9 146 47 177 45 122 186
161 41 15 10 125 68 188 56 132 51 164 46 16 15 157 101 40 67 137 54 167 47 21 17
18 124 46 88 140 70 169 48 27 19 40 134 49 101 143 75 176 49 32 22 51 142 50 103
144 106 180 55 37 23
*/

#include <stdio.h>
#include <stdlib.h>

#define cap 10

struct Node {
  int data;
  struct Node *next;
};

struct llist {
  struct Node *head;
};

struct hashTable {
  struct llist *hash[cap];
};

int getHash(int key) { return key % 10; }

struct hashTable *in() {
  struct hashTable *ht = (struct hashTable *)malloc(sizeof(struct hashTable));
  for (int i = 0; i < cap; i++) {
    ht->hash[i] = (struct llist *)malloc(sizeof(struct llist));
    ht->hash[i]->head = NULL;
  }
  return ht;
}

void printList(struct llist *l) {
  struct Node *temp = l->head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void printTable(struct hashTable *ht) {
  printf("Printing the table:\n");
  for (int i = 0; i < cap; i++) {
    printf("[%i] --> ", i);
    printList(ht->hash[i]);
  }
}

struct Node *getNode(int data) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

insertList(struct llist *l, int data) {
  struct Node *node = getNode(data);
  node->next = l->head;
  l->head = node;
}

void insert(struct hashTable *ht, int key) {
  int i = getHash(key);
  insertList(ht->hash[i], key);
}

int main() {
  struct hashTable *h = in();

  int arr[100] = {
      7,   21,  144, 51,  105, 146, 108, 184, 57,  44,  96,  29,  151, 123, 106,
      147, 118, 204, 62,  49,  103, 42,  153, 131, 108, 152, 120, 25,  90,  6,
      118, 44,  157, 167, 111, 153, 141, 28,  13,  9,   146, 47,  177, 45,  122,
      186, 161, 41,  15,  10,  125, 68,  188, 56,  132, 51,  164, 46,  16,  15,
      157, 101, 40,  67,  137, 54,  167, 47,  21,  17,  18,  124, 46,  88,  140,
      70,  169, 48,  27,  19,  40,  134, 49,  101, 143, 75,  176, 49,  32,  22,
      51,  142, 50,  103, 144, 106, 180, 55,  37,  23};
  for (int i = 0; i < 100; i++) {
    insert(h, arr[i]);
  }
  printTable(h);
}