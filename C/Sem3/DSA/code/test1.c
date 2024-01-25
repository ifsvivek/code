#include<stdio.h>
#include<stdlib.h>

// SINGLE LINKED LIST //
// CREATE NODE //
struct SLL {
    int data;
    struct SLL *next;
};

typedef struct SLL node;
node *start = NULL;

node *createnode() {
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

// INSERT BEGIN / FRONT //
void insertBegin() {
    node *newnode = createnode();
    if (start == NULL) {
        start = newnode;
        return;
    }
    newnode->next = start;
    start = newnode;
}

// INSERT END / REAR //
void insertEnd() {
    node *temp = start;
    node *newnode = createnode();
    if (start == NULL) {
        start = newnode;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

// DELETE BEGIN //
void deleteBegin() {
    node *temp = start;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    start = temp->next;
    printf("Deleted element is %d\n", temp->data);
    free(temp);
}

// DELETE END //
void deleteEnd() {
    node *temp = start, *prev = NULL;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    } else if (start->next == NULL) {
        printf("Deleted node is %d\n", start->data);
        free(temp);
        start = NULL;
    } else {
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        printf("Deleted node is %d\n", temp->data);
        free(temp);
        prev->next = NULL;
    }
}
// DISPLAY //
void display() {
    node *temp = start;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

// SEARCH //
void search() {
    int key;
    node *temp = start;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter the key: ");
    scanf("%d", &key);
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL)
        printf("Key not found\n");
    else
        printf("Key found\n");
}

// INSERT BEFORE KEY //
void insertbeforekey() {
    node *temp = start, *prev = NULL, *newnode;
    int key;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter the key: ");
    scanf("%d", &key);
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }
    if (temp == start) {
        insertBegin();
        return;
    }
    newnode = createnode();
    prev->next = newnode;
    newnode->next = temp;
}

// INSERT AFTER KEY //
void insertafterkey() {
    node *temp = start, *newnode, *prev = NULL;
    int key;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter the key: ");
    scanf("%d", &key);
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }
    newnode = createnode();
    newnode->next = temp->next;
    temp->next = newnode;
    printf("Key inserted\n");
}

// DELETE BEFORE KEY //
void deletebeforekey() {
    node *temp = start, *prev = NULL;
    int key;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter the key: ");
    scanf("%d", &key);
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }
    if (prev == NULL || prev == start) {
        printf("Deletion is not possible as no nodes present before\n");
        return;
    }
    prev->next = temp->next;
    printf("Deleted element is %d\n", temp->data);
    free(temp);
}

// DELETE AFTER KEY //
void deleteafterkey() {
    node *temp = start, *prev = NULL;
    int key;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter the key: ");
    scanf("%d", &key);
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Deletion not possible as no key found\n");
        return;
    }
    if (temp->next == NULL) {
        printf("No node after the key to delete\n");
        return;
    }
    node *nextNode = temp->next;
    temp->next = nextNode->next;
    printf("Deleted element is %d\n", nextNode->data);
    free(nextNode);
}

// CONCATENATING LISTS //
node* concat(node* start1, node* start2) {
    node *temp;
    if (start1 == NULL && start2 == NULL) {
        printf("Concatenation is not possible because both lists are empty\n");
        return NULL;
    }
    if (start1 == NULL)
        return start2;
    if (start2 == NULL)
        return start1;
    temp = start1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = start2;
    return start1;
}

// DELETE KEY //
void deletekey() {
    node *temp = start, *prev = NULL;
    int key;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter the key: ");
    scanf("%d", &key);
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }
    if (prev == NULL) {
        deleteBegin();
        return;
    }
    prev->next = temp->next;
    printf("Deleted key is %d\n", temp->data);
    free(temp);
}

// REVERSE A LINKED LIST //
void reverse() {
    node *temp = start, *prev = NULL, *next = NULL;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    start = prev;
}

// SORT //
void sort() {
    int n = 0, tdata, i, j;
    node *temp = start;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }
    for (i = 0; i < n - 1; i++) {
        temp = start;
        for (j = 0; j < n - 1; j++) {
            if (temp->data > temp->next->data) {
                tdata = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tdata;
            }
            temp = temp->next;
        }
    }
    display();
}

// COUNTING NUMBER OF NODES //
int count() {
    int count = 0;
    node *temp = start;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void main() {
    int choice;
    while (1) {
        printf("\n\n------ Singly Linked List Menu ------\n");
        printf("1. Create node\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the end\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Display the list\n");
        printf("7. Search\n");
        printf("8. Insert before key\n");
        printf("9. Insert after key\n");
        printf("10. Delete before key\n");
        printf("11. Delete after key\n");
        printf("12. Concatenate the list\n");
        printf("13. Delete key\n");
        printf("14. Reverse the linked list\n");
        printf("15. Sort the linked list\n");
        printf("16. Count nodes\n");
        printf("17. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createnode();
                break;
            case 2:
                insertBegin();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                deleteBegin();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                display();
                break;
            case 7:
                search();
                break;
            case 8:
                insertbeforekey();
                break;
            case 9:
                insertafterkey();
                break;
            case 10:
                deletebeforekey();
                break;
            case 11:
                deleteafterkey();
                break;
            case 12:
                start = concat(start, start); 
                break;
            case 13:
                deletekey();
                break;
            case 14:
                reverse();
                break;
            case 15:
                sort();
                break;
            case 16:
                printf("Number of nodes: %d\n", count());
                break;
            case 17:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}