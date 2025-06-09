#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure for stack
struct Stack {
    int top;
    int items[MAX_SIZE];
};

// Function to initialize the stack
void initialize(struct Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++s->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    struct Stack s;
    initialize(&s);
    int i, operand1, operand2, result;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(&s, postfix[i] - '0');
        } else {
            operand2 = pop(&s);
            operand1 = pop(&s);
            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(&s, result);
        }
    }
    return pop(&s);
}

int main() {
    char postfix[MAX_SIZE];
    printf("Enter the postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    postfix[strlen(postfix) - 1] = '\0'; // Remove newline character
    int result = evaluatePostfix(postfix);
    printf("Result of evaluation: %d\n", result);
    return 0;
}
