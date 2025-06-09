#include <stdio.h>
#include <stdlib.h>

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

// Function to check if the stack is full
int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
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

// Function to reverse a stack using two temporary stacks
void reverseStack(struct Stack *s) {
    struct Stack temp1, temp2;
    initialize(&temp1);
    initialize(&temp2);

    // Push all elements of s into temp1
    while (!isEmpty(s)) {
        push(&temp1, pop(s));
    }

    // Push all elements of temp1 into temp2
    while (!isEmpty(&temp1)) {
        push(&temp2, pop(&temp1));
    }

    // Push all elements of temp2 back into s, which reverses the stack
    while (!isEmpty(&temp2)) {
        push(s, pop(&temp2));
    }
}

// Function to print the stack
void printStack(struct Stack *s) {
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack s;
    initialize(&s);

    // Push elements onto the stack
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    printf("Original ");
    printStack(&s);

    // Reverse the stack
    reverseStack(&s);

    printf("Reversed ");
    printStack(&s);

    return 0;
}
