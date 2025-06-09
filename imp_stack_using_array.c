#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for the stack
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

// Function to display the elements of the stack
void display(struct Stack *s) {
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack s;
    initialize(&s);
    int choice, value;
    while (1) {
        printf("\nStack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&s, value);
                printf("%d pushed to stack\n", value);
                break;
            case 2:
                if (!isEmpty(&s)) {
                    printf("Popped element: %d\n", pop(&s));
                } else {
                    printf("Stack is empty\n");
                }
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
