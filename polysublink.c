#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

void insert(struct Node** head, int coefficient, int exponent) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = (*head);
    (*head) = newNode;
}

void subtract(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 && poly2) {
        if (poly1->exponent > poly2->exponent) {
            insert(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insert(&result, -poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sub = poly1->coefficient - poly2->coefficient;
            if (sub != 0)
                insert(&result, sub, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1) {
        insert(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2) {
        insert(&result, -poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    printf("Resultant Polynomial: ");
    while (result) {
        printf("%dx^%d", result->coefficient, result->exponent);
        result = result->next;
        if (result != NULL)
            printf(" + ");
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    insert(&poly1, 4, 3);
    insert(&poly1, 3, 2);
    insert(&poly1, 2, 1);
    insert(&poly1, 1, 0);
    insert(&poly2, 2, 2);
    insert(&poly2, 1, 1);
    insert(&poly2, 3, 0);
    printf("First Polynomial: ");
    while (poly1) {
        printf("%dx^%d", poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
        if (poly1 != NULL)
            printf(" + ");
    }
    printf("\nSecond Polynomial: ");
    while (poly2) {
        printf("%dx^%d", poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
        if (poly2 != NULL)
            printf(" + ");
    }
    printf("\n");
    subtract(poly1, poly2);
    return 0;
}

