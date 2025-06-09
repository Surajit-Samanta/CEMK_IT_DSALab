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

// Function to calculate the height of a binary tree
int treeHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    // Recursively calculate the height of the left and right subtrees
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    // Return the maximum height of the left and right subtrees, plus 1 for the current node
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    // Constructing a binary tree
    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Calculating the height of the binary tree
    int height = treeHeight(root);
    printf("Height of the binary tree: %d\n", height);

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
