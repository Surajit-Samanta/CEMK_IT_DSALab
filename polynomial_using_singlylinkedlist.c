#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list representing a term of the polynomial
struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial
void insertTerm(struct Node **poly, int coeff, int exp) {
    struct Node *newNode = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node *temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display a polynomial
void displayPolynomial(struct Node *poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next != NULL) {
            printf(" + ");
        }
        poly = poly->next;
    }
    printf("\n");
}

// Function to free memory allocated for a polynomial
void freePolynomial(struct Node *poly) {
    struct Node *temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Node *poly = NULL;

    // Insert terms into the polynomial
    insertTerm(&poly, 5, 2);
    insertTerm(&poly, -3, 1);
    insertTerm(&poly, 2, 0);

    printf("Polynomial: ");
    displayPolynomial(poly);

    // Free memory allocated for the polynomial
    freePolynomial(poly);

    return 0;
}
