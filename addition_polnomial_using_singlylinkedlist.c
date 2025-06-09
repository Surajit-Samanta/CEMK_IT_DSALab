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

// Function to add two polynomials
struct Node* addPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    // Append remaining terms of poly1, if any
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    // Append remaining terms of poly2, if any
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Node *poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%d", poly->coeff);
        if (poly->exp != 0) {
            printf("x^%d", poly->exp);
        }
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
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *result = NULL;

    // Insert terms into the first polynomial
    insertTerm(&poly1, 5, 2);
    insertTerm(&poly1, -3, 1);
    insertTerm(&poly1, 2, 0);

    // Insert terms into the second polynomial
    insertTerm(&poly2, 3, 2);
    insertTerm(&poly2, 4, 1);
    insertTerm(&poly2, -2, 0);

    printf("First polynomial: ");
    displayPolynomial(poly1);
    printf("Second polynomial: ");
    displayPolynomial(poly2);

    // Add the two polynomials
    result = addPolynomials(poly1, poly2);

    printf("Sum of the polynomials: ");
    displayPolynomial(result);

    // Free memory allocated for the polynomials
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
