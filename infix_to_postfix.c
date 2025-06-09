#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for stack
struct Stack {
    int top;
    char items[MAX_SIZE];
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
void push(struct Stack *s, char value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++s->top] = value;
}

// Function to pop an element from the stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

// Function to return the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack s;
    initialize(&s);
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] >= 'a' && infix[i] <= 'z') {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&s) && s.items[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            if (!isEmpty(&s) && s.items[s.top] != '(') {
                printf("Invalid expression\n");
                exit(1);
            } else {
                pop(&s);
            }
        } else {
            while (!isEmpty(&s) && precedence(infix[i]) <= precedence(s.items[s.top])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove newline character
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
