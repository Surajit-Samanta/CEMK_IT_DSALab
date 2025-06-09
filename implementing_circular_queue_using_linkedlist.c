#include <stdio.h>
#include <stdlib.h>

// Node structure for circular queue
struct Node {
    int data;
    struct Node *next;
};

// Structure for circular queue
struct CircularQueue {
    struct Node *rear;
};

// Function to create an empty circular queue
struct CircularQueue* createQueue() {
    struct CircularQueue *cq = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    if (cq == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    cq->rear = NULL;
    return cq;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue *cq) {
    return (cq->rear == NULL);
}

// Function to display the queue
void display(struct CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node *current = cq->rear->next;
    printf("Queue: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != cq->rear->next);
    printf("\n");
}

// Function to insert an element into the queue
void enqueue(struct CircularQueue *cq, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    if (isEmpty(cq)) {
        cq->rear = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = cq->rear->next;
        cq->rear->next = newNode;
        cq->rear = newNode;
    }
    printf("Element %d inserted into the queue\n", value);
}

// Function to delete an element from the queue
void dequeue(struct CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty. Cannot dequeue\n");
        return;
    }
    struct Node *temp = cq->rear->next;
    int deleted = temp->data;
    if (temp == cq->rear) {
        cq->rear = NULL;
    } else {
        cq->rear->next = temp->next;
    }
    free(temp);
    printf("Element %d deleted from the queue\n", deleted);
}

// Function to search for an element in the queue
int search(struct CircularQueue *cq, int value) {
    if (isEmpty(cq)) {
        printf("Queue is empty. Search failed\n");
        return -1;
    }
    struct Node *current = cq->rear->next;
    int position = 0;
    do {
        if (current->data == value) {
            printf("Element %d found at position %d\n", value, position);
            return position;
        }
        current = current->next;
        position++;
    } while (current != cq->rear->next);
    printf("Element %d not found in the queue\n", value);
    return -1;
}

int main() {
    struct CircularQueue *cq = createQueue();
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
                display(cq);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(cq, value);
                break;
            case 3:
                dequeue(cq);
                break;
            case 4:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                search(cq, value);
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
