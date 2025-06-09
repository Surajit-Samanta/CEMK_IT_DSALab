#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for linear queue
struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};

// Function to create an empty queue
void createQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

// Function to check if the queue is full
int isFull(struct Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

// Function to display the queue
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

// Function to insert an element into the queue
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
    printf("Element %d inserted into the queue\n", value);
}

// Function to delete an element from the queue
void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue\n");
        return;
    }
    int deleted = q->data[q->front];
    if (q->front == q->rear) {
        // Queue becomes empty after deletion
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    printf("Element %d deleted from the queue\n", deleted);
}

// Function to search for an element in the queue
int search(struct Queue *q, int value) {
    if (isEmpty(q)) {
        printf("Queue is empty. Search failed\n");
        return -1;
    }
    for (int i = q->front; i <= q->rear; i++) {
        if (q->data[i] == value) {
            printf("Element %d found at position %d\n", value, i);
            return i;
        }
    }
    printf("Element %d not found in the queue\n", value);
    return -1;
}

int main() {
    struct Queue q;
    createQueue(&q);
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display the queue\n");
        printf("2. Insert an element into the queue\n");
        printf("3. Delete an element from the queue\n");
        printf("4. Search for an element in the queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(&q);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 3:
                dequeue(&q);
                break;
            case 4:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                search(&q, value);
                break;
            case 5:
                printf("Exiting the program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
