#include <stdio.h>
#include <stdlib.h>
void linear_search(int a[], int n)
{
    int key, i;
    printf("enter the key\n");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("key found at index:%d\n", i);
            return;
        }
    }
    printf("key not found\n");
}
void binary_search(int a[], int n)
{
    int key;
    printf("enter the key\n");
    scanf("%d", &key);
    int low = 0;
    int high = n - 1;
    int mid = (low + high) / 2;
    while (low <= high)
    {
        if (a[mid] == key)
        {
            printf("key found at%d\n", mid);
            return;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    printf("element not found\n");
}
void selection_sort(int a[], int n)
{
    int i, j;
    for (i = 0; i < (n - 1); i++)
    {
        int index = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[index])
            {
                index = j;
            }
        }
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
    printf("the sorted elements are\n");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
}
int main()
{
    int n, i, choice;
    printf("Enter the number of elements in array\n");
    scanf("%d", &n);
    int a[1000];
    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    while (1)
    {
        printf("Enter your choice:\n1. for linear search\n2. for binary search\n3. for selection sort\n4. for exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            linear_search(a, n);
            break;
        case 2:
            binary_search(a, n);
            break;
        case 3:
            selection_sort(a, n);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice\n");
        }
    }
    return 0;
}