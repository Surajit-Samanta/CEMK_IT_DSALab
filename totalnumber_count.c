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

// Function to count the total number of elements in the list
int countElements(struct Node *head) {
    int count = 0;
    struct Node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
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

    // Count the total number of elements in the list
    int totalCount = countElements(head);
    printf("Total number of elements in the list: %d\n", totalCount);

    return 0;
}
