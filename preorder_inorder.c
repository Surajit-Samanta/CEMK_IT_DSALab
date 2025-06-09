#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in the binary tree
struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(char data) {
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

// Function to find the index of a character in a string
int findIndex(char arr[], int start, int end, char value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Function to construct a binary tree using pre-order and in-order traversals
struct TreeNode* buildTree(char preOrder[], char inOrder[], int inStart, int inEnd) {
    static int preIndex = 0;
    if (inStart > inEnd) {
        return NULL;
    }
    // Create a new node with the current element from pre-order traversal
    struct TreeNode* newNode = createNode(preOrder[preIndex++]);
    // If the current subtree has only one node, return the node
    if (inStart == inEnd) {
        return newNode;
    }
    // Find the index of the current element in the in-order traversal
    int inIndex = findIndex(inOrder, inStart, inEnd, newNode->data);
    // Recursively build left and right subtrees
    newNode->left = buildTree(preOrder, inOrder, inStart, inIndex - 1);
    newNode->right = buildTree(preOrder, inOrder, inIndex + 1, inEnd);
    return newNode;
}

// Function to perform in-order traversal of the binary tree
void inOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%c ", root->data);
    inOrderTraversal(root->right);
}

int main() {
    char preOrder[] = "ABDECF";
    char inOrder[] = "DBEAFC";
    int len = strlen(preOrder);
    // Construct the binary tree
    struct TreeNode* root = buildTree(preOrder, inOrder, 0, len - 1);
    // Perform in-order traversal to verify the construction
    printf("In-order traversal of constructed tree: ");
    inOrderTraversal(root);
    printf("\n");

    // Freeing allocated memory (optional)
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
