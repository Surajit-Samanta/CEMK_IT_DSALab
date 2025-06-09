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

// Function to swap the data of two nodes
void swap(struct Node *a, struct Node *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to sort the singly linked list using Bubble Sort
void bubbleSort(struct Node *head) {
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    // Checking for empty list
    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
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

    // Display the unsorted list
    printf("Unsorted ");
    display(head);

    // Sort the list using Bubble Sort
    bubbleSort(head);

    // Display the sorted list
    printf("Sorted ");
    display(head);

    return 0;
}
