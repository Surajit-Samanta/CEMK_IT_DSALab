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

// Function to convert a decimal number to binary using a stack
void decimalToBinary(int decimal) {
    struct Stack s;
    initialize(&s);
    // Push binary digits onto the stack
    while (decimal > 0) {
        push(&s, decimal % 2);
        decimal /= 2;
    }
    // Pop and print binary digits from the stack
    printf("Binary representation: ");
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    decimalToBinary(decimal);
    return 0;
}
