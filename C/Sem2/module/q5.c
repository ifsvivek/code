// Binary Search function

#include <stdio.h>

int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array in sorted order:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);

    int index = binarySearch(arr, size, target);

    if (index != -1)
        printf("Element %d found at position %d.\n", target, index+1);
    else
        printf("Element %d not found in the array.\n", target);

    return 0;
}