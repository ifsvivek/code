#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[50];
int top = -1;

void push(char sym) {
    stack[++top] = sym;
}

char pop() {
    return stack[top--];
}

int preec(char symb) {
    switch (symb) {
    case '^':
    case '$':
        return 4;
    case '%':
    case '/':
    case '*':
        return 3;
    case '+':
    case '-':
        return 2;
    case '(':
    case ')':
    case '#':
        return 1;
    default: return 0;
    }
}

void convertip(char infix[], char postfix[]) {
    char symbol;
    int i = 0, j = 0;
    push('#');
    for (i = 0;i < strlen(infix);i++) {
        symbol = infix[i];
        switch (symbol) {
        case '(':push(symbol);
            break;
        case ')':while (stack[top] != '(')
            postfix[j++] = pop();
            pop();
            break;
        case '^':
        case '$':
        case '%':
        case '/':
        case '*':
        case '+':
        case '-':
            while (preec(symbol) <= preec(stack[top])) {
                postfix[j++] = pop();
            }
            push(symbol);
            break;
        default: postfix[j++] = symbol;
        }
    }
    while (stack[top] != '#')
        postfix[j++] = pop();
    postfix[j] = '\0';
}

void main() {
    char infix[50], postfix[50];
    printf("Enter infix value : ");
    scanf("%s", infix);
    convertip(infix, postfix);
    printf("Result : %s ", postfix);
}