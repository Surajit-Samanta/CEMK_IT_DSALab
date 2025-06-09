#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node *prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to search for an element in the list
int searchElement(struct Node *head, int key) {
    int position = 1;
    struct Node *current = head;
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Element not found
}

int main() {
    struct Node *head = NULL;
    int n, data, key;

    // Input the number of elements in the list
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    // Input the elements of the list
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        if (head == NULL) {
            head = createNode(data);
        } else {
            struct Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            struct Node *newNode = createNode(data);
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Input the element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Search for the element in the list
    int position = searchElement(head, key);
    if (position != -1) {
        printf("Element found at position %d\n", position);
    } else {
        printf("Element not found in the list\n");
    }

    return 0;
}
