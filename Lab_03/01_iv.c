#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
struct Node {
    int data;
    struct Node *next;
};

/* Recursive function to print in reverse order */
void printReverse(struct Node *head) {

    if (head == NULL) {
        return;
    }

    printReverse(head->next);

    printf("%d ", head->data);
}

int main() {
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    second->data = 20;
    third->data = 30;

    head->next = second;
    second->next = third;
    third->next = NULL;

    printf("Linked List in Reverse Order:\n");

    printReverse(head);

    printf("\n");

    return 0;
}