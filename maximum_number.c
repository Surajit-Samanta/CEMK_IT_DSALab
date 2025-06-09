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

// Function to find the maximum element in the list
int findMaxElement(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    int max = head->data;
    struct Node *current = head->next;
    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

int main() {
    struct Node *head = NULL;
    int n, data;

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
        }
    }

    // Find the maximum element in the list
    int maxElement = findMaxElement(head);
    if (maxElement != -1) {
        printf("Maximum element in the list: %d\n", maxElement);
    }

    return 0;
}
