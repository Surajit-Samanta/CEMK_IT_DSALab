#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check if a binary tree is a complete binary tree
int isCompleteBinaryTree(struct TreeNode* root) {
    // If the tree is empty, it is a complete binary tree
    if (root == NULL) {
        return 1;
    }

    // Flag to indicate whether encountered a null node
    int nullEncountered = 0;

    // Queue for level-order traversal
    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* current = queue[front++];

        // If encountered a null node after a non-null node
        if (current == NULL) {
            nullEncountered = 1;
        } else {
            // If encountered a non-null node after a null node
            if (nullEncountered) {
                return 0;
            }

            // Enqueue the left and right child of the current node
            queue[rear++] = current->left;
            queue[rear++] = current->right;
        }
    }

    // If no violation is found, it is a complete binary tree
    return 1;
}

int main() {
    struct TreeNode *root = NULL;

    // Creating the binary tree
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Checking if the binary tree is a complete binary tree
    if (isCompleteBinaryTree(root)) {
        printf("The binary tree is a complete binary tree\n");
    } else {
        printf("The binary tree is not a complete binary tree\n");
    }

    // Freeing allocated memory (optional)
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
