#include <stdio.h>
#include <stdlib.h>

// Node structure for priority queue
struct Node {
    int data;
    int priority;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to display the priority queue
void display(struct Node *front) {
    if (front == NULL) {
        printf("Priority queue is empty\n");
        return;
    }
    printf("Priority queue: ");
    while (front != NULL) {
        printf("(%d, %d) ", front->data, front->priority);
        front = front->next;
    }
    printf("\n");
}

// Function to insert an element into the priority queue based on priority
void enqueue(struct Node **front, int data, int priority) {
    struct Node *newNode = createNode(data, priority);
    if (*front == NULL || priority < (*front)->priority) {
        newNode->next = *front;
        *front = newNode;
    } else {
        struct Node *current = *front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    printf("Element (%d, %d) inserted into the priority queue\n", data, priority);
}

// Function to delete the highest priority element from the priority queue
void dequeue(struct Node **front) {
    if (*front == NULL) {
        printf("Priority queue is empty. Cannot dequeue\n");
        return;
    }
    struct Node *temp = *front;
    *front = (*front)->next;
    free(temp);
    printf("Highest priority element deleted from the priority queue\n");
}

int main() {
    struct Node *front = NULL;
    int choice, data, priority;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display the priority queue\n");
        printf("2. Insert an element into the priority queue\n");
        printf("3. Delete an element from the priority queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(front);
                break;
            case 2:
                printf("Enter the data and priority of the element to insert: ");
                scanf("%d %d", &data, &priority);
                enqueue(&front, data, priority);
                break;
            case 3:
                dequeue(&front);
                break;
            case 4:
                printf("Exiting the program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
