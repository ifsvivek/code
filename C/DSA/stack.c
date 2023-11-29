#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

struct Stack {
    int items[MAX];
    int top;
};

typedef struct Stack Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

bool isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push element %d\n", value);
    } else {
        stack->items[++stack->top] = value;
        printf("Element %d pushed to the stack\n", value);
    }
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop element\n");
        return -1;
    } else {
        int popped = stack->items[stack->top--];
        printf("Element %d popped from the stack\n", popped);
        return popped;
    }
}

void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->items[i]);
        }
        printf("\n");
    }
}

bool isPalindrome(Stack *stack, int num) {
    // Check if a number is palindrome using a stack
    int original = num;
    while (num > 0) {
        int digit = num % 10;
        push(stack, digit);
        num /= 10;
    }

    int reversed = 0;
    while (!isEmpty(stack)) {
        reversed = reversed * 10 + pop(stack);
    }

    return original == reversed;
}

int main() {
    Stack stack;
    initialize(&stack);

    int choice, element;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check Palindrome\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&stack, element);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                printf("Enter a number to check palindrome: ");
                scanf("%d", &element);
                if (isPalindrome(&stack, element)) {
                    printf("%d is a palindrome\n", element);
                } else {
                    printf("%d is not a palindrome\n", element);
                }
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
