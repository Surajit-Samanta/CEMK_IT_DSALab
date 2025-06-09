#include <stdio.h>
#include <stdlib.h>

// Node structure for queue
struct Node {
    int data;
    struct Node *next;
};

// Structure for linear queue
struct Queue {
    struct Node *front, *rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    if (q == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return (q->front == NULL && q->rear == NULL);
}

// Function to display the queue
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node *current = q->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert an element into the queue
void enqueue(struct Queue *q, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    printf("Element %d inserted into the queue\n", value);
}

// Function to delete an element from the queue
void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue\n");
        return;
    }
    struct Node *temp = q->front;
    int deleted = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    printf("Element %d deleted from the queue\n", deleted);
}

// Function to search for an element in the queue
int search(struct Queue *q, int value) {
    if (isEmpty(q)) {
        printf("Queue is empty. Search failed\n");
        return -1;
    }
    struct Node *current = q->front;
    int position = 0;
    while (current != NULL) {
        if (current->data == value) {
            printf("Element %d found at position %d\n", value, position);
            return position;
        }
        current = current->next;
        position++;
    }
    printf("Element %d not found in the queue\n", value);
    return -1;
}

int main() {
    struct Queue *q = createQueue();
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
                display(q);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 3:
                dequeue(q);
                break;
            case 4:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                search(q, value);
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
