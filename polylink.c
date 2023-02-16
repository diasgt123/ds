#include <stdio.h>
#include <stdlib.h>

// Define a node of the linked list
struct node {
    int coefficient;
    int power;
    struct node* next;
};

// Function to create a new node and return a pointer to it
struct node* create_node(int coefficient, int power) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->coefficient = coefficient;
    new_node->power = power;
    new_node->next = NULL;
    return new_node;
}

// Function to add two polynomials
struct node* add_polynomials(struct node* poly1, struct node* poly2) {
    // Create a dummy node and a pointer to it
    struct node* dummy = create_node(0, 0);
    struct node* current = dummy;

    while(poly1 && poly2) {
        if(poly1->power > poly2->power) {
            current->next = create_node(poly1->coefficient, poly1->power);
            poly1 = poly1->next;
        }
        else if(poly1->power < poly2->power) {
            current->next = create_node(poly2->coefficient, poly2->power);
            poly2 = poly2->next;
        }
        else {
            current->next = create_node(poly1->coefficient + poly2->coefficient, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        current = current->next;
    }

    // Add any remaining terms in either polynomial
    while(poly1) {
        current->next = create_node(poly1->coefficient, poly1->power);
        poly1 = poly1->next;
        current = current->next;
    }

    while(poly2) {
        current->next = create_node(poly2->coefficient, poly2->power);
        poly2 = poly2->next;
        current = current->next;
    }

    return dummy->next;
}

// Function to print a polynomial
void print_polynomial(struct node* polynomial) {
    while(polynomial) {
        printf("%dx^%d ", polynomial->coefficient, polynomial->power);
        polynomial = polynomial->next;
        if(polynomial) {
            printf("+ ");
        }
    }
    printf("\n");
}

// Test the add_polynomials function
int main() {
    struct node* poly1 = create_node(5, 2);
    poly1->next = create_node(4, 1);
    poly1->next->next = create_node(9, 0);

    struct node* poly2 = create_node(5, 2);
    poly2->next = create_node(7, 1);
    poly2->next->next = create_node(5, 0);

    printf("Polynomial 1: ");
    print_polynomial(poly1);

    printf("Polynomial 2: ");
    print_polynomial(poly2);

    struct node* sum = add_polynomials(poly1, poly2);

    printf("Sum: ");
    print_polynomial(sum);

    return 0;
}

