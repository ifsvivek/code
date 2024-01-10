#include <stdio.h>
#include <stdlib.h>

struct sll
{
    int sem;
    char usn[11], name[20], branch[20], phone[11];
    struct sll *next;
};

typedef struct sll node;

node *start = NULL;

node *getnode()
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    printf("Enter the student details USN, name, branch, sem, phone: ");
    scanf("%s %s %s %d %s", newNode->usn, newNode->name, newNode->branch, &newNode->sem, newNode->phone);
    newNode->next = NULL;
    return newNode;
}

void insertBegin()
{
    node *newNode = getnode();

    if (start == NULL)
    {
        start = newNode;
    }
    else
    {
        newNode->next = start;
        start = newNode;
    }
}

void insertEnd()
{
    node *newNode = getnode();
    node *temp = start;

    if (start == NULL)
    {
        start = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void deleteBegin()
{
    node *temp;

    if (start == NULL)
    {
        printf("Linked list is empty.\n");
    }
    else
    {
        temp = start;
        start = temp->next;
        printf("Deleted node: USN: %s\n", temp->usn);
        free(temp);
    }
}

void deleteEnd()
{
    node *temp, *prev;

    if (start == NULL)
    {
        printf("Linked list is empty.\n");
    }
    else
    {
        temp = start;
        prev = NULL;

        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        printf("Deleted node: USN: %s\n", temp->usn);

        if (prev != NULL)
        {
            prev->next = NULL;
        }
        else
        {
            start = NULL; // If the list had only one node
        }

        free(temp);
    }
}

void displayAndCount()
{
    node *temp = start;
    int count = 0;

    if (start == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        printf("List elements are:\n");
        while (temp != NULL)
        {
            printf("USN: %s, Name: %s, Branch: %s, Sem: %d, Phone: %s\n",
                   temp->usn, temp->name, temp->branch, temp->sem, temp->phone);
            temp = temp->next;
            count++;
        }
        printf("Count = %d\n", count);
    }
}

int main()
{
    int choice, n, i;

    while (1)
    {
        printf("\n***** Singly Linked List Operations *****\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display and Count\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of students to insert at the beginning: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                insertBegin();
            }
            break;

        case 2:
            printf("Enter the number of students to insert at the end: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                insertEnd();
            }
            break;

        case 3:
            deleteBegin();
            break;

        case 4:
            deleteEnd();
            break;

        case 5:
            displayAndCount();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
