#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the polynomial
struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int coeff, int exp) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial
void insertTerm(struct Node **poly, int coeff, int exp) {
    struct Node *temp = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = temp;
    } else {
        struct Node *lastNode = *poly;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = temp;
    }
}

// Function to display the polynomial
void display(struct Node *poly) {
    struct Node *current = poly;
    while (current != NULL) {
        printf("%dx^%d ", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf("+ ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to multiply two polynomials
struct Node *multiplyPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;
    struct Node *temp1 = poly1;
    while (temp1 != NULL) {
        struct Node *temp2 = poly2;
        while (temp2 != NULL) {
            int coeff = temp1->coefficient * temp2->coefficient;
            int exp = temp1->exponent + temp2->exponent;
            insertTerm(&result, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return result;
}

// Function to free memory allocated for the polynomial
void freePoly(struct Node *poly) {
    struct Node *temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;

    // Insert terms into polynomial 1
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 5, 0);
    printf("Polynomial 1: ");
    display(poly1);

    // Insert terms into polynomial 2
    insertTerm(&poly2, 2, 1);
    insertTerm(&poly2, 1, 0);
    printf("Polynomial 2: ");
    display(poly2);

    // Multiply polynomials
    struct Node *result = multiplyPolynomials(poly1, poly2);
    printf("Result of multiplication: ");
    display(result);

    // Free memory allocated for polynomials
    freePoly(poly1);
    freePoly(poly2);
    freePoly(result);

    return 0;
}
