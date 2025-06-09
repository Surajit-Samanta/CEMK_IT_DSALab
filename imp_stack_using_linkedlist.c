#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the stack
struct Node {
    int data;
    struct Node *next;
};

// Structure for the stack
struct Stack {
    struct Node *top;
};

// Function to initialize the stack
void initialize(struct Stack *s) {
    s->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack *s, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct Node *temp = s->top;
    int poppedValue = temp->data;
    s->top = temp->next;
    free(temp);
    return poppedValue;
}

// Function to display the elements of the stack
void display(struct Stack *s) {
    struct Node *current = s->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
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
