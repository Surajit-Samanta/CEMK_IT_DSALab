#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for circular queue
struct CircularQueue {
    int data[MAX_SIZE];
    int front, rear;
};

// Function to create an empty circular queue
void createQueue(struct CircularQueue *cq) {
    cq->front = -1;
    cq->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue *cq) {
    return (cq->front == -1 && cq->rear == -1);
}

// Function to check if the queue is full
int isFull(struct CircularQueue *cq) {
    return ((cq->rear + 1) % MAX_SIZE == cq->front);
}

// Function to display the queue
void display(struct CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = cq->front;
    do {
        printf("%d ", cq->data[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (cq->rear + 1) % MAX_SIZE);
    printf("\n");
}

// Function to insert an element into the queue
void enqueue(struct CircularQueue *cq, int value) {
    if (isFull(cq)) {
        printf("Queue is full. Cannot enqueue\n");
        return;
    }
    if (isEmpty(cq)) {
        cq->front = 0;
        cq->rear = 0;
    } else {
        cq->rear = (cq->rear + 1) % MAX_SIZE;
    }
    cq->data[cq->rear] = value;
    printf("Element %d inserted into the queue\n", value);
}

// Function to delete an element from the queue
void dequeue(struct CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty. Cannot dequeue\n");
        return;
    }
    int deleted = cq->data[cq->front];
    if (cq->front == cq->rear) {
        cq->front = -1;
        cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % MAX_SIZE;
    }
    printf("Element %d deleted from the queue\n", deleted);
}

// Function to search for an element in the queue
int search(struct CircularQueue *cq, int value) {
    if (isEmpty(cq)) {
        printf("Queue is empty. Search failed\n");
        return -1;
    }
    int i = cq->front;
    int position = 0;
    do {
        if (cq->data[i] == value) {
            printf("Element %d found at position %d\n", value, position);
            return position;
        }
        i = (i + 1) % MAX_SIZE;
        position++;
    } while (i != (cq->rear + 1) % MAX_SIZE);
    printf("Element %d not found in the queue\n", value);
    return -1;
}

int main() {
    struct CircularQueue cq;
    createQueue(&cq);
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
                display(&cq);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(&cq, value);
                break;
            case 3:
                dequeue(&cq);
                break;
            case 4:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                search(&cq, value);
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
