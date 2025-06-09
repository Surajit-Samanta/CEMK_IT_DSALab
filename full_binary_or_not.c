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

// Function to check if a binary tree is a full binary tree
int isFullBinaryTree(struct TreeNode* root) {
    if (root == NULL) {
        // An empty tree is considered as a full binary tree
        return 1;
    }
    if (root->left == NULL && root->right == NULL) {
        // A node with no children is considered as a full binary tree
        return 1;
    }
    if (root->left != NULL && root->right != NULL) {
        // Recursively check if both left and right subtrees are full binary trees
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
    }
    // If none of the above conditions are satisfied, the tree is not a full binary tree
    return 0;
}

int main() {
    // Creating a full binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Checking if the binary tree is a full binary tree
    if (isFullBinaryTree(root)) {
        printf("The binary tree is a full binary tree\n");
    } else {
        printf("The binary tree is not a full binary tree\n");
    }

    // Freeing allocated memory
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
