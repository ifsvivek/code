#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

int STACK[MAX_SIZE];
int top = -1;

void push(int operand) {
  if (top == MAX_SIZE - 1) {
    printf("Error: Stack overflow\n");
    exit(1);
  }
  STACK[++top] = operand;
}

int pop() {
  if (top == -1) {
    printf("Error: Stack underflow\n");
    exit(1);
  }
  return STACK[top--];
}

int evaluatePostfix(char postfix[]) {
  int i, operand, op1, op2;
  for (i = 0; postfix[i] != '\0'; i++) {
    if (isdigit(postfix[i])) {
      operand = postfix[i] - '0';  // Convert char to int
      push(operand);
    } else {
      op2 = pop();
      op1 = pop();
      switch (postfix[i]) {
        case '+':
          push(op1 + op2);
          break;
        case '-':
          push(op1 - op2);
          break;
        case '*':
          push(op1 * op2);
          break;
        case '/':
          if (op2 != 0) {
            push(op1 / op2);
          } else {
            printf("Error: Division by zero\n");
            exit(1);
          }
          break;
        case '%':
          if (op2 != 0) {
            push(op1 % op2);
          } else {
            printf("Error: Modulo by zero\n");
            exit(1);
          }
          break;
        case '^':
          push(pow(op1, op2));
          break;
        default:
          printf("Error: Invalid operator\n");
          exit(1);
      }
    }
  }
  return pop();
}

int main() {
  char postfix[30];

  printf("Enter POSTFIX expression: ");
  fgets(postfix, 30, stdin);
  postfix[strcspn(postfix, "\n")] = '\0';
  int result = evaluatePostfix(postfix);

  printf("Result: %d\n", result);

  return 0;
}
