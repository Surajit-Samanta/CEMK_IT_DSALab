#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Structure for a stack node
struct StackNode {
    struct TreeNode *treeNode;
    struct StackNode *next;
};

// Function to create a new stack node
struct StackNode* createStackNode(struct TreeNode *treeNode) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(struct StackNode **top, struct TreeNode *treeNode) {
    struct StackNode* newNode = createStackNode(treeNode);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a node from the stack
struct TreeNode* pop(struct StackNode **top) {
    if (*top == NULL) {
        return NULL;
    }
    struct StackNode* temp = *top;
    *top = (*top)->next;
    struct TreeNode* poppedNode = temp->treeNode;
    free(temp);
    return poppedNode;
}

// Function to perform non-recursive pre-order traversal of the binary tree using a stack
void preOrderTraversal(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    struct StackNode *stack = NULL;
    push(&stack, root); // Push the root onto the stack
    while (stack != NULL) {
        struct TreeNode *current = pop(&stack); // Pop the top node from the stack
        printf("%d ", current->data); // Visit the popped node
        // Push right child first so that left child is processed first (LIFO)
        if (current->right != NULL) {
            push(&stack, current->right);
        }
        if (current->left != NULL) {
            push(&stack, current->left);
        }
    }
}

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

    // Performing non-recursive pre-order traversal
    printf("Non-recursive Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

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
