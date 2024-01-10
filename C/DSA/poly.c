#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct polynomial
{
    int coeff, expo1, expo2, expo3;
    struct polynomial *next;
    int flag;
};
typedef struct polynomial node;
node *getnode()
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->flag = 0;
    return newnode;
}
node *insertend(node *head, int c, int x, int y, int z)
{
    node *newnode, *temp = head->next;
    newnode = getnode();
    newnode->coeff = c;
    newnode->expo1 = x;
    newnode->expo2 = y;
    newnode->expo3 = z;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newnode;
    newnode->next = head;
    return head;
}
node *readpoly(node *head)
{
    int i, n, c, x, y, z;
    printf("enter the no of terms\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the coeff expo1 expo2 expo3\n");
        scanf("%d%d%d%d", &c, &x, &y, &z);
        head = insertend(head, c, x, y, z);
    }
    return head;
}
void printpoly(node *head)
{
    node *temp = head->next;
    while (temp->next != head)
    {

        printf("%dx^%dy^%dz^%d + ", temp->coeff, temp->expo1, temp->expo2, temp->expo3);
        temp = temp->next;
    }
    printf("%dx^%dy^%dz^%d\n", temp->coeff, temp->expo1, temp->expo2, temp->expo3);
}
void evaluate(node *head)
{
    node *temp = head->next;
    int sum = 0, x, y, z;
    printf("enter the value of x y and z");
    scanf("%d%d%d", &x, &y, &z);
    while (temp != head)
    {
        sum = sum + temp->coeff * pow(x, temp->expo1) * pow(y, temp->expo2) * pow(z, temp->expo3);
        temp = temp->next;
    }
    printf("the evlauated result of a polynomial is %d\n", sum);
}
node *addpoly(node *h1, node *h2, node *h3)
{
    node *p1, *p2;
    int c;
    p1 = h1->next;
    while (p1 != h1)
    {
        p2 = h2->next;
        while (p2 != h2)
        {
            if (p1->expo1 == p2->expo1 && p1->expo2 == p2->expo2 && p1->expo3 == p2->expo3)
            {
                c = p1->coeff + p2->coeff;
                h3 = insertend(h3, c, p1->expo1, p1->expo2, p1->expo3);
                p1->flag = 1;
                p2->flag = 1;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    // code for adding remaining terms
    p1 = h1->next;
    p2 = h2->next;
    while (p1 != h1)
    {
        if (p1->flag == 0)
        {
            h3 = insertend(h3, p1->coeff, p1->expo1, p1->expo2, p1->expo3);
        }
        p1 = p1->next;
    }

    while (p2 != h2)
    {
        if (p2->flag == 0)
        {
            h3 = insertend(h3, p2->coeff, p2->expo1, p2->expo2, p2->expo3);
        }
        p2 = p2->next;
    }

    return h3;
}
int main()
{
    node *h1 = (node *)malloc(sizeof(node));
    h1->next = h1;
    node *h2 = (node *)malloc(sizeof(node));
    h2->next = h2;
    node *h3 = (node *)malloc(sizeof(node));
    h3->next = h3;
    printf("read 1st polynomial\n");
    h1 = readpoly(h1);
    printf("read 2nd polynomial\n");
    h2 = readpoly(h2);
    printf("1st polynomial is\n");
    printpoly(h1);
    printf("2nd polynomial is\n");
    printpoly(h2);
    h3 = addpoly(h1, h2, h3);
    printf("resultant polynomial is\n");
    printpoly(h3);
    evaluate(h1);
}
