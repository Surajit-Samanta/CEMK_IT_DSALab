#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void display(struct Node *head) {
    struct Node *current = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to insert a node after a given location in the list
struct Node* insertAfterLocation(struct Node *head, int data, int position) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node *current = head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Invalid position\n");
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete a node from the beginning of the list
struct Node* deleteFromBeginning(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end of the list
struct Node* deleteFromEnd(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

// Function to delete a node from a given location in the list
struct Node* deleteFromLocation(struct Node *head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node *temp, *current = head;
    if (position == 1) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Invalid position\n");
        return head;
    }
    temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

int main() {
    struct Node *head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n1. Creation of a linked list\n");
        printf("2. Insertion at the beginning\n");
        printf("3. Insertion at end\n");
        printf("4. Insertion after a given location\n");
        printf("5. Deletion from beginning\n");
        printf("6. Deletion from end\n");
        printf("7. Deletion from a given location\n");
        printf("8. Display the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data for the first node: ");
                scanf("%d", &data);
                head = createNode(data);
                printf("Linked list created successfully\n");
                break;
            case 2:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                printf("Data inserted at the beginning successfully\n");
                break;
            case 3:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printf("Data inserted at the end successfully\n");
                break;
            case 4:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert after: ");
                scanf("%d", &position);
                head = insertAfterLocation(head, data, position);
                printf("Data inserted after position %d successfully\n", position);
                break;
            case 5:
                head = deleteFromBeginning(head);
                printf("Node deleted from the beginning successfully\n");
                break;
            case 6:
                head = deleteFromEnd(head);
                printf("Node deleted from the end successfully\n");
                break;
            case 7:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deleteFromLocation(head, position);
                printf("Node deleted from location %d successfully\n", position);
                break;
            case 8:
                display(head);
                break;
            case 9:
                printf("Exiting the program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
