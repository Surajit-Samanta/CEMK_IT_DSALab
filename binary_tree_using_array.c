#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to display the binary tree
void display(int tree[], int size) {
    printf("Binary Tree:\n");
    for (int i = 0; i < size; i++) {
        if (tree[i] != -1) {
            printf("%d ", tree[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int main() {
    int size, i, data;
    printf("Enter the size of the binary tree: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size of binary tree\n");
        return 1;
    }

    int tree[size];

    // Initializing tree elements to -1 (indicating empty nodes)
    for (i = 0; i < size; i++) {
        tree[i] = -1;
    }

    printf("Enter the elements of the binary tree (enter -1 for empty nodes):\n");
    for (i = 0; i < size; i++) {
        printf("Enter element at position %d: ", i);
        scanf("%d", &data);
        tree[i] = data;
    }

    display(tree, size);

    return 0;
}
