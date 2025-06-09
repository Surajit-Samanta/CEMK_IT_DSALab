#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
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

// Function to display the circular linked list
void display(struct Node *head) {
    if (head == NULL) {
        printf("Circular linked list is empty\n");
        return;
    }
    struct Node *current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to insert a node at the end of the circular linked list
void insert(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to delete a node with the given data from the circular linked list
void deleteNode(struct Node **head, int data) {
    if (*head == NULL) {
        printf("Circular linked list is empty\n");
        return;
    }
    struct Node *current = *head;
    struct Node *prev = NULL;
    do {
        if (current->data == data) {
            if (prev == NULL) {
                struct Node *temp = *head;
                while (temp->next != *head) {
                    temp = temp->next;
                }
                temp->next = (*head)->next;
                *head = (*head)->next;
                free(current);
                return;
            } else {
                prev->next = current->next;
                free(current);
                return;
            }
        }
        prev = current;
        current = current->next;
    } while (current != *head);
    printf("Data not found in circular linked list\n");
}

// Function to search for a node with the given data in the circular linked list
void search(struct Node *head, int data) {
    if (head == NULL) {
        printf("Circular linked list is empty\n");
        return;
    }
    struct Node *current = head;
    int position = 0;
    do {
        if (current->data == data) {
            printf("%d found at position %d\n", data, position);
            return;
        }
        current = current->next;
        position++;
    } while (current != head);
    printf("%d not found in circular linked list\n", data);
}

int main() {
    struct Node *head = NULL;
    int choice, data;
    while (1) {
        printf("\nCircular Linked List Operations\n");
        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Circular linked list: ");
                display(head);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                printf("%d inserted into circular linked list\n", data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                printf("%d deleted from circular linked list\n", data);
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &data);
                search(head, data);
                break;
            case 5:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
